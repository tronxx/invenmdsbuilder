//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosrenfacma.h"
#include "dialg_busartic.h"
#include "dmod.h"
#include "situaciones.h"
#include "numapal.h"
#include "Frme_nuevasseries.h"
#include "dialg_okcancel.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datosrenfacma *Frame_datosrenfacma;
//---------------------------------------------------------------------------
__fastcall TFrame_datosrenfacma::TFrame_datosrenfacma(TComponent* Owner)
        : TFrame(Owner)
{
  String config_z;
  cia_z = dm->cia_z;
  config_z = dm->config_z;
  TIniFile *ini;
  ini = new TIniFile(config_z);
  margenrepo_z = ini->ReadFloat( "Form_consuinv", "MARGEN_CTOREP", 0.95);


}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosrenfacma::edt_codigoExit(TObject *Sender)
{
  busca_inven();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenfacma::busca_inven()
{
  String codigo_z;
  if(edt_codigo->Tag == INACTIVO) return;
  codigo_z = edt_codigo->Text.Trim();
  if(codigo_z == "AUXILIAR") {
    edt_descri->ReadOnly = false;
    edt_descri->TabStop  = true;
    lst_series->Visible = true;
    lbl_series->Visible = true;
    btn_series->Visible = true;
    lbl_piva->Visible = true;
    edt_piva->Visible = true;
    return;
  } else {
    edt_descri->ReadOnly = true;
    edt_descri->TabStop  = false;
    lbl_piva->Visible = false;
    edt_piva->Visible = false;
  }
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(qry_inven->IsEmpty()) {
    // No Existe el código, habrá que buscarlo
    Tdlg_busartic *dlg_busartic = new Tdlg_busartic (this);
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
  edt_codigo->Text = codigo_z;
  edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
  edt_piva->Value  = qry_inven->FieldByName("piva")->AsFloat;
  if(qry_inven->FieldByName("tipo")->AsString == "ALF") {
    lst_series->Visible = true;
    lbl_series->Visible = true;
    btn_series->Visible = true;
  } else {
    lst_series->Visible = false;
    lbl_series->Visible = false;
    btn_series->Visible = false;
  }
  calcu_prvta();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenfacma::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN) { busca_inven(); }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenfacma::calcu_prvta()
{
  double mubmds_z=0, costo_z=0, preciou_z=0,
         preciomay2_z=0, ctorep_z =0, costos_z=0, piva_z =0;
  String codigo_z="";
  if(qry_inven->State == dsInactive) return;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  preciou_z = qry_inven->FieldByName("precio")->AsFloat;
  piva_z = (qry_inven->FieldByName("piva")->AsFloat / 100) + 1;
  costos_z = qry_inven->FieldByName("costos")->AsFloat;
  if(tipomay_z == "FILIAL") {
    preciou_z = dm->calcu_prmay(codigo_z, TIPO_FILIAL);
  } else {
    preciou_z = dm->calcu_prmay(codigo_z, TIPO_PRECIOMAYXCOSTO);
    qry_extensa->Close();
    qry_extensa->ParamByName("codigo")->AsString = codigo_z;
    qry_extensa->ParamByName("cia")->AsInteger = cia_z;
    qry_extensa->Open();
    if(!qry_extensa->IsEmpty()) {
      ctorep_z = qry_extensa->FieldByName("costoext")->AsFloat;
      preciomay2_z = Redondea(ctorep_z / margenrepo_z, 100);
      if( preciomay2_z > preciou_z) preciou_z = preciomay2_z;
    }
  }
  edt_preciou->Value = Redondea(preciou_z, 100);
}
//---------------------------------------------------------------------------



void __fastcall TFrame_datosrenfacma::selecciona_seriesExecute(
      TObject *Sender)
{
  int alto_z, ancho_z;
  Tdlg_okcancel *Dlg_pidenombre;
  Dlg_pidenombre = new Tdlg_okcancel (this);
  Dlg_pidenombre->AutoSize = false;
  TFrame_nuevasseries *Frame_nuevasseries = new TFrame_nuevasseries (Dlg_pidenombre);
  ancho_z = Frame_nuevasseries->Width + 20;
  alto_z = Frame_nuevasseries->Height + Dlg_pidenombre->Panel2->Height + 80;
  Dlg_pidenombre->AutoSize = false;
  Dlg_pidenombre->Width = ancho_z;
  Dlg_pidenombre->Height = alto_z;
  Frame_nuevasseries->Parent = Dlg_pidenombre->Panel1;
  Frame_nuevasseries->Top = 0;
  Frame_nuevasseries->Left= 0;
  Frame_nuevasseries->Align = alClient;
  Dlg_pidenombre->Caption = "Proporcione Los datos de las Series";
  Frame_nuevasseries->numseries_z = edt_canti->Value;
  Frame_nuevasseries->lst_series->Items->Clear();
  for(int ii_z = 0; ii_z < lst_series->Items->Count; ii_z++) {
    Frame_nuevasseries->lst_series->Items->Add(lst_series->Items->Strings[ii_z]);
  }

  if( Dlg_pidenombre->ShowModal() == mrOk) {
    lst_series->Items->Clear();
    for(int ii_z = 0; ii_z < Frame_nuevasseries->lst_series->Items->Count; ii_z++) {
      lst_series->Items->Add(Frame_nuevasseries->lst_series->Items->Strings[ii_z]);
    }
    lst_series->ItemIndex = 0;
    lst_series->DroppedDown = true;
  }
  delete Frame_nuevasseries;
  delete Dlg_pidenombre;
}
//---------------------------------------------------------------------------

