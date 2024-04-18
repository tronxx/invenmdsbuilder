//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosmantmayo.h"
#include "dmod.h"
#include "situaciones.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxTL"
#pragma resource "*.dfm"
TFrame_datosmantmayo *Frame_datosmantmayo;
//---------------------------------------------------------------------------
__fastcall TFrame_datosmantmayo::TFrame_datosmantmayo(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  qry_ciudades->Close();
  qry_ciudades->Open();
  qry_tipostel->Close();
  qry_tipostel->Open();
  qry_mediospago->Close();
  qry_mediospago->ParamByName("ACTIVO")->AsInteger = TIPO_PAGO_ACTIVO;
  qry_mediospago->Open();
  qry_mediopago2->Close();
  qry_mediopago2->ParamByName("ACTIVO")->AsInteger = TIPO_PAGO_ACTIVO;
  qry_mediopago2->Open();
  qry_regimen->Close();
  qry_regimen->ParamByName("ACTIVO")->AsString = "A";
  qry_regimen->Open();
  qry_invtipomay->Close();
  qry_invtipomay->ParamByName("cia")->AsInteger = cia_z;
  qry_invtipomay->Open();
  lkcmb_tipomay->KeyValue = qry_invtipomay->FieldByName("idtipomay")->AsInteger;

  //cmb_tipotel->Items->Clear();
  //for ( qry_tipostel->First(); !qry_tipostel->Eof; qry_tipostel->Next())
  //  cmb_tipotel->Items->Add( qry_tipostel->FieldByName("descri")->AsString);
  idrelmay_z = dm->busca_sigid(MAY_RELAC) + 10;
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosmantmayo::edt_codvndKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) busca_vnd(edt_codvnd->Text.Trim());
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosmantmayo::busca_vnd(String vnd_z)
{
    qry_mayoris->Close();
    qry_mayoris->ParamByName("codigo")->AsString = vnd_z;
    qry_mayoris->ParamByName("cia")->AsInteger = cia_z;
    qry_mayoris->Open();
    qry_telefonos->Close();
    qry_telefonos->ParamByName("mayoris")->AsString = vnd_z;
    qry_telefonos->ParamByName("cia")->AsInteger = cia_z;
    qry_telefonos->ParamByName("idtiporel")->AsInteger = RELTELFAX;
    qry_telefonos->Open();
    qry_emailes->Close();
    qry_emailes->ParamByName("mayoris")->AsString = vnd_z;
    qry_emailes->ParamByName("cia")->AsInteger = cia_z;
    qry_emailes->ParamByName("idtiporel")->AsInteger = REL_MAYORIS_EMAIL2;
    qry_emailes->Open();
    if(!qry_mayoris->IsEmpty()) {
      desp_vnd(); grabar->Tag = 0; //botones_onoff(VISIBLES);
    }
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosmantmayo::desp_vnd()
{
   String mediopago_z="", numcta_z="", numcta2_z="", regimen_z,
     codigo_z="", ciu_z;
   int idmedipago_z=0, idmedipago2_z=0, idregimen_z=0, nciu_z=0;
   TLocateOptions Opts;
   Opts.Clear();
   codigo_z = qry_mayoris->FieldByName("codigo")->AsString;
   edt_nombre->Text=qry_mayoris->FieldByName("nombre")->AsString;
   edt_nombre2->Text=qry_mayoris->FieldByName("nombre2")->AsString;
   ciu_z = qry_mayoris->FieldByName("ciu")->AsString;
   if(ciu_z.Pos(",")) ciu_z = "";
   if(qry_ciudades->Locate("nombre", ciu_z, Opts)) {
     nciu_z = qry_ciudades->FieldByName("numero")->AsInteger;
     lkcmb_ciudad->KeyValue = nciu_z;
   }
   edt_direc->Text= obten_datospago(codigo_z, "CALLE");
   edt_numpred->Text= obten_datospago(codigo_z, "NUMPRED");
   edt_codpost->Text= obten_datospago(codigo_z, "CODPOST");
   edt_colonia->Text= obten_datospago(codigo_z, "COLONIA");
   edt_email->Text= obten_datospago(codigo_z, "EMAIL");
   //edt_email2->Text= obten_datospago(codigo_z, "EMAIL2");
   edt_tel->Text=qry_mayoris->FieldByName("tel")->AsString;
   edt_codvnd->Text=qry_mayoris->FieldByName("codigo")->AsString;
   edt_rfc->Text=qry_mayoris->FieldByName("rfc")->AsString;
   edt_pdsc->Text=qry_mayoris->FieldByName("pdsc")->AsFloat;
   lkcmb_ciudad2->KeyValue=qry_mayoris->FieldByName("ciupag")->AsString;
   edt_dirpag2->Text=qry_mayoris->FieldByName("dirpag2")->AsString;
   edt_nompag->Text=qry_mayoris->FieldByName("nompag1")->AsString;
   edt_dirpag->Text=qry_mayoris->FieldByName("dirpag1")->AsString;
   lkcmb_tipomay->KeyValue  = qry_mayoris->FieldByName("tipo")->AsInteger;
   if(qry_mayoris->FieldByName("status")->AsString == "A")
      cmb_status->ItemIndex = 0;
   else
      cmb_status->ItemIndex = 1;

   qry_telefonos->Close();
   qry_telefonos->ParamByName("mayoris")->AsString = codigo_z;
   qry_telefonos->ParamByName("cia")->AsInteger = cia_z;
   qry_telefonos->ParamByName("idtiporel")->AsInteger = RELTELFAX;
   qry_telefonos->Open();
   qry_emailes->Close();
   qry_emailes->ParamByName("mayoris")->AsString = codigo_z;
   qry_emailes->ParamByName("cia")->AsInteger = cia_z;
   qry_emailes->ParamByName("idtiporel")->AsInteger = REL_MAYORIS_EMAIL2;
   qry_emailes->Open();
   mediopago_z = obten_datospago(codigo_z, "TIPOPAGO");
   numcta_z    = obten_datospago(codigo_z, "NUMCTA");
   lkcmb_metodopago->KeyValue = mediopago_z.ToIntDef(0);
   edt_numcta->Text=numcta_z;
   mediopago_z = obten_datospago(codigo_z, "TIPOPAGO2");
   numcta2_z    = obten_datospago(codigo_z, "NUMCTA2");
   edt_numcta2->Text=numcta2_z;
   regimen_z = obten_datospago(codigo_z, "REGIMEN");
   lkcmb_regimen->KeyValue = regimen_z.ToIntDef(0);
}
//---------------------------------------------------------------------------

String __fastcall TFrame_datosmantmayo::obten_datospago(
  String codigomay_z, String tipodato_z)
{
   String midato_z="", campo_z;
   int tiporel_z;
   qry_datospago->Close();
   qry_datospago->ParamByName("mayoris")->AsString = codigomay_z;
   qry_datospago->ParamByName("cia")->AsInteger = cia_z;
   if(tipodato_z == "TIPOPAGO" || tipodato_z == "NUMCTA") {
     tiporel_z = REL_MAYORIS_TIPOPAGO;
   }
   if(tipodato_z == "TIPOPAGO2" || tipodato_z == "NUMCTA2") {
     tiporel_z = REL_MAYORIS_TIPOPAGO2;
   }
   if(tipodato_z == "CALLE") {
     tiporel_z = REL_MAYORIS_CALLE;
   }
   if(tipodato_z == "NUMPRED") {
     tiporel_z = REL_MAYORIS_NUMPRED;
   }
   if(tipodato_z == "CODPOST") {
     tiporel_z = REL_MAYORIS_CODPOST;
   }
   if(tipodato_z == "COLONIA") {
     tiporel_z = REL_MAYORIS_COLONIA;
   }
   if(tipodato_z == "EMAIL") {
     tiporel_z = REL_MAYORIS_EMAIL;
   }
   if(tipodato_z == "EMAIL2") {
     tiporel_z = REL_MAYORIS_EMAIL2;
   }
   if(tipodato_z == "REGIMEN") {
     tiporel_z = REL_MAYORIS_REGIMEN;
   }
   qry_datospago->ParamByName("idtiporel")->AsInteger = tiporel_z;
   qry_datospago->Open();
   if(!qry_datospago->IsEmpty()) {
     if(tipodato_z == "NUMCTA") {
       campo_z = "numcta";
     } else {
       campo_z = "tipopago";
     // Fin de if
     }
     midato_z = qry_datospago->FieldByName(campo_z)->AsString;
   }
   return (midato_z);
}
//---------------------------------------------------------------------------

String TFrame_datosmantmayo::pide_email_o_tel(String tipodato_z)
{
  String misdatos_z, leyenda_z, leyend2_z;
  TQuery *qry_midato;
  TEdit *edt_tipo;
  TEdit *edt_minum;
  TLabel *lbl_tipodato;
  TLabel *lbl_emailotel;
  Tdlg_okcancel *Dlg_emailotel;
  if(pagina_z == "TBS_TELEFONOS") {
    leyenda_z = "de donde es (Casa, Ofi, etc):";
    leyend2_z = "Teléfono";
  }
  if(pagina_z == "TBS_EMAILES") {
    leyenda_z = "de quien (Contador, Secretaria, etc):";
    leyend2_z = "Correo";
  }

  Dlg_emailotel = new Tdlg_okcancel (this);
  Dlg_emailotel->AutoSize = false;
  Dlg_emailotel->Width = 500;
  Dlg_emailotel->Caption = "Datos de " + leyend2_z;
  edt_tipo = new TEdit (Dlg_emailotel);
  edt_tipo->Top = 10;
  edt_tipo->Left = 200;
  edt_tipo->Width = 200;
  edt_tipo->CharCase = ecUpperCase;
  edt_tipo->Parent = Dlg_emailotel->Panel1;
  lbl_tipodato = new TLabel(Dlg_emailotel);
  lbl_tipodato->Caption = leyenda_z;
  lbl_tipodato->Parent = Dlg_emailotel->Panel1;
  lbl_tipodato->Top = edt_tipo->Top + 2;
  lbl_tipodato->Left = edt_tipo->Left - lbl_tipodato->Width - 3;

  edt_minum = new TEdit (Dlg_emailotel);
  edt_minum->Top = edt_tipo->Top + edt_tipo->Height + 4;
  edt_minum->Left = 200;
  edt_minum->Width = 200;
  //edt_tipo->CharCase = ecUpperCase;
  edt_minum->Parent = Dlg_emailotel->Panel1;
  lbl_emailotel = new TLabel(Dlg_emailotel);
  lbl_emailotel->Caption = leyend2_z;
  lbl_emailotel->Parent = Dlg_emailotel->Panel1;
  lbl_emailotel->Top = edt_minum->Top + 2;
  lbl_emailotel->Left = edt_minum->Left - lbl_emailotel->Width - 3;
  if(Dlg_emailotel->ShowModal() == mrOk) {
    misdatos_z = edt_tipo->Text.Trim() + ":" + edt_minum->Text.Trim();
  } else {
    misdatos_z = "-1";
  }
  delete Dlg_emailotel;
  return (misdatos_z);
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosmantmayo::agregar_telExecute(TObject *Sender)
{
  String tipotel_z, numtel_z, mayoris_z, misdatos_z;
  int posini_z, nvoidrel_z, tiporelmay_z;
  TQuery *qry_midato;
  misdatos_z = pide_email_o_tel(pagina_z);
  if(misdatos_z == "-1") return;
  posini_z = misdatos_z.Pos(':');
  numtel_z = misdatos_z.SubString(posini_z+1, 300);
  tipotel_z = misdatos_z.SubString(1, posini_z -1);

  nvoidrel_z = dm->busca_sigid(MAY_RELAC);
  mayoris_z = edt_codvnd->Text.Trim();
  if(idrelmay_z < nvoidrel_z) idrelmay_z = nvoidrel_z;
  if(pagina_z == "TBS_TELEFONOS") {
    tiporelmay_z = RELTELFAX;
    qry_midato = qry_telefonos;
  }
  if(pagina_z == "TBS_EMAILES") {
    tiporelmay_z = REL_MAYORIS_EMAIL2;
    qry_midato = qry_emailes;
  }
  qry_midato->Append();
  qry_midato->FieldByName("idrelac")->AsInteger = ++idrelmay_z;
  qry_midato->FieldByName("idmayoris")->AsInteger = -1;
  qry_midato->FieldByName("mayoris")->AsString = mayoris_z;
  qry_midato->FieldByName("idtiporel")->AsInteger = tiporelmay_z;
  qry_midato->FieldByName("iddato1")->AsInteger = dm->busca_iddato(tipotel_z, MAY_TIPOSTEL);
  qry_midato->FieldByName("iddato2")->AsInteger = dm->busca_iddato(numtel_z, TELEFONO);
  qry_midato->FieldByName("tipotel")->AsString = tipotel_z;
  qry_midato->FieldByName("telfax")->AsString = numtel_z;
  qry_midato->FieldByName("cia")->AsInteger = cia_z;
  qry_midato->Post();
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosmantmayo::elimina_telExecute(TObject *Sender)
{
  if (pagina_z == "TBS_TELEFONOS") {
    if (qry_telefonos->State == dsInactive) return;
    if (qry_telefonos->IsEmpty() ) return;
    if(Application->MessageBox("Esta Seguro de Eliminar este Telefono?", "Eliminar Telefono", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
      qry_telefonos->Delete();
    }
  }
  if(pagina_z == "TBS_EMAILES") {
    if (qry_emailes->State == dsInactive) return;
    if (qry_emailes->IsEmpty() ) return;
    if(Application->MessageBox("Esta Seguro de Eliminar este Correo ?", "Eliminar Correo", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
      qry_emailes->Delete();
    }
  }

}
//---------------------------------------------------------------------------



void __fastcall TFrame_datosmantmayo::pge_telefonosChange(TObject *Sender)
{
  pagina_z = pagina_z;
  TTabSheet *pPC = pge_telefonos->ActivePage;
  //TTabSheet *pPC = dynamic_cast<TTabSheet *>(Sender);
  pagina_z = pPC->Name;
  pagina_z = pagina_z.UpperCase();
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosmantmayo::dbgrd_telefonosKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) {
    agregar_telExecute(this);
  }
  if(Key == VK_DELETE) {
    elimina_telExecute(this);
  }
}
//---------------------------------------------------------------------------

