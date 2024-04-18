//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosrenpolcampre.h"
#include "dialg_busartic.h"
#include "dmod.h"
#include "situaciones.h"
#include "numapal.h"
#include "Frm_CapturaObsPed.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datosrenpolcampre *Frame_datosrenpolcampre;
//---------------------------------------------------------------------------
__fastcall TFrame_datosrenpolcampre::TFrame_datosrenpolcampre(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  qry_situaciones->Close();
  qry_situaciones->Open();
  qry_garantias->Close();
  qry_garantias->ParamByName("cia")->AsInteger = cia_z;
  qry_garantias->Open();
  if(!qry_garantias->IsEmpty())
    lkcmb_garantia->KeyValue = qry_garantias->FieldByName("idgarantia")->AsInteger;
  if(!qry_situaciones->IsEmpty())
    lkcmb_situaciones->KeyValue = qry_situaciones->FieldByName("idsituac")->AsInteger;
  TIniFile *ini;
  String  config_z, dato_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  dato_z    =  ini->ReadString( "XTENSA", "FACTOR_PRECIO", "0.66");
  factorxten_z = dato_z.ToDouble();
  delete ini;

}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosrenpolcampre::edt_codigoExit(TObject *Sender)
{
  busca_inven();
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosrenpolcampre::busca_inven()
{
  String codigo_z, antsit_z, linea_z;
  double precioext_z = 0, costoext_z = 0;
  int idgarantia_z =0, idsituac_z=0;
  TLocateOptions Opts;
  Opts.Clear();
  if(edt_codigo->Tag == INACTIVO) return;
  codigo_z = edt_codigo->Text.Trim();
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(qry_inven->IsEmpty()) {
    // No Existe el código, habrá que buscarlo
    Tdlg_busartic *dlg_busartic = new Tdlg_busartic (this);
    dlg_busartic->eximin_z = 1;
    dlg_busartic->eximax_z = 999999;
    dlg_busartic->busca_artic(codigo_z + "%", "-1");
    if(dlg_busartic->ShowModal() == mrOk) {
      qry_inven->Close();
      qry_inven->ParamByName("codigo")->AsString = dlg_busartic->qry_inven->FieldByName("codigo")->AsString;
      qry_inven->ParamByName("cia")->AsInteger = cia_z;
      qry_inven->Open();
    }
    delete dlg_busartic;
  }
  if(qry_inven->IsEmpty()) return;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  antsit_z = qry_inven->FieldByName("empaqe")->AsString;
  linea_z  = qry_inven->FieldByName("linea")->AsString;
  edt_codigo->Text = codigo_z;
  edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
  edt_precionvo->Value = qry_inven->FieldByName("precio")->AsFloat;
  edt_precioant->Value = qry_inven->FieldByName("precio")->AsFloat;
  edt_fidenvo->Value = qry_inven->FieldByName("precelec")->AsFloat;
  edt_fideant->Value = qry_inven->FieldByName("precelec")->AsFloat;
  //if(linea_z == "ANTE" || linea_z == "VIDE") {
  //  lbl_costoxtensa->Caption = "Costo Combo";
  //  lbl_precioxtensa->Caption = "Precio Combo";
  //} else {
  //  lbl_costoxtensa->Caption = "Costo Xtensa";
  //  lbl_precioxtensa->Caption = "Precio Xtensa";
  //}
  //qry_invxtensa->Close();
  //qry_invxtensa->ParamByName("codigo")->AsString = codigo_z;
  //qry_invxtensa->ParamByName("cia")->AsInteger = cia_z;
  //qry_invxtensa->Open();
  //if(!qry_invxtensa->IsEmpty()) {
  //  precioext_z = qry_invxtensa->FieldByName("precioext")->AsFloat;
  //  costoext_z  = qry_invxtensa->FieldByName("costoext")->AsFloat;
  //}
  edt_costoxten->Value  = costoext_z;
  edt_precioxten->Value = precioext_z;

  qry_invgarantia->Close();
  qry_invgarantia->ParamByName("codigo")->AsString = codigo_z;
  qry_invgarantia->ParamByName("idrel")->AsInteger = REL_INVEN_GARANTIA;
  qry_invgarantia->ParamByName("cia")->AsInteger = cia_z;
  qry_invgarantia->Open();
  if(!qry_invgarantia->IsEmpty()) {
    idgarantia_z = qry_invgarantia->FieldByName("idgarantia")->AsInteger;
  }
  lkcmb_garantia->KeyValue = idgarantia_z;
  edt_antsit->Text = antsit_z;
  qry_situaciones->First();
  if(qry_situaciones->Locate("situacion", antsit_z, Opts))
    lkcmb_situaciones->KeyValue = qry_situaciones->FieldByName("idsituac")->AsInteger;
  //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
  if(edt_precionvo->Visible) edt_precionvo->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcampre::edt_codigoKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) { busca_inven(); }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcampre::edt_costoxtenExit(
      TObject *Sender)
{
  double nvoprexten_z=0;
  // --> Se comenta 2019-Ago-15  Ya no existe extensa
  //if(edt_costoxten->Value && qry_invgarantia->FieldByName("meses")->AsInteger > 12 ) {
  //  int respuesta_z;
  //  respuesta_z = Application->MessageBox("Seguro de tener costo Xtensa ? ya tiene garantía de mas de 12 Meses", "Garantía de mas de 12 Meses", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
  //  if(respuesta_z != ID_YES) edt_costoxten->Value = 0;
  //}

  //nvoprexten_z = Redondea(edt_costoxten->Value / factorxten_z, 1);
  //edt_precioxten->Value = nvoprexten_z;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcampre::lkcmb_garantiaExit(
      TObject *Sender)
{
  int respuesta_z=0;
  // --> Se comenta 2019-Ago-15  Ya no existe extensa
  //if(edt_costoxten->Value && qry_invgarantia->FieldByName("meses")->AsInteger > 12) {
  //  respuesta_z = Application->MessageBox("Seguro de tener costo Xtensa ? ya tiene garantía de mas de 12 Meses", "Garantía de mas de 12 Meses", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
  //  if(respuesta_z != ID_YES) {
  //    edt_costoxten->Value = 0; edt_precioxten->Value = 0;
  //  }
  //}
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcampre::solo_reposicion()
{
  bool esvisible = false;
  edt_codigo->Enabled = false;
  lbl_costorepo->Top = lbl_precionvo->Top;
  lbl_costorepo->Visible = true;
  edt_costoxten->Top = edt_precionvo->Top;
  edt_costoxten->Visible = true;
  lbl_precioxtensa->Visible = esvisible;
  edt_precioxten->Visible = esvisible;
  lbl_precionvo->Visible = esvisible;
  edt_precionvo->Visible = esvisible;
  lbl_precioant->Visible = esvisible;
  edt_precioant->Visible = esvisible;
  lbl_subsidioant->Visible = esvisible;
  edt_fideant->Visible = esvisible;
  lbl_subsidionvo->Visible = esvisible;
  edt_fidenvo->Visible = esvisible;
  lbl_garantia->Visible = esvisible;
  lkcmb_garantia->Visible = esvisible;
  lbl_observs->Visible = esvisible;
  dbedt_garantia->Visible = esvisible;

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcampre::graba_reposicion()
{
  String codigo_z, usuario_z, observs_z = "";
  int idart_z = 0;
  double costoext_z = 0, precioext_z = 0;
  usuario_z = dm->usuario_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  costoext_z = edt_costoxten->Value;
  precioext_z = edt_precioxten->Value;
  observs_z += dm->login_z;
  qry_invhist->Close();
  qry_invhist->ParamByName("codigo")->AsString = codigo_z;
  qry_invhist->ParamByName("cia")->AsInteger = cia_z;
  qry_invhist->Open();
  if(qry_invhist->IsEmpty()) return;
  idart_z = qry_invhist->FieldByName("idart")->AsInteger;
  qry_invxtensa->Close();
  qry_invxtensa->ParamByName("codigo")->AsString = codigo_z;
  qry_invxtensa->ParamByName("cia")->AsInteger = cia_z;
  qry_invxtensa->Open();
  if(qry_invxtensa->IsEmpty()) {
    qry_invxtensa->Append();
    qry_invxtensa->FieldByName("idextensa")->AsInteger = dm->busca_sigid(IDEXTENSA);
    qry_invxtensa->FieldByName("idart")->AsInteger = idart_z;
    qry_invxtensa->FieldByName("cia")->AsInteger = cia_z;
    observs_z += " Anter Cto Rep: " + rjust("0.00", 12);
    // Crear Formulario Observs y Grabar
  } else {
    observs_z += " Anter Cto Rep: " + rjust(FormatFloat("###,##0.00", qry_invxtensa->FieldByName("costoext")->AsFloat), 12);
    qry_invxtensa->Edit();
  }
  observs_z += " Nuevo Cto Rep: " + rjust(FormatFloat("###,##0.00", costoext_z), 12);

  qry_invxtensa->FieldByName("precioext")->AsFloat  = precioext_z;
  qry_invxtensa->FieldByName("costoext")->AsFloat   = costoext_z;
  qry_invxtensa->Post();
  try {
    dm->manvehi->StartTransaction();
    qry_invxtensa->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  TForm_CapturaObsPed *Form_CapturaObsPed = new TForm_CapturaObsPed (this, "R", "R", 0, cia_z, codigo_z, "T");
  Form_CapturaObsPed->agrega_obs("NUEVO", observs_z, dm->ahora(), 0);
  delete Form_CapturaObsPed;

}
//---------------------------------------------------------------------------

