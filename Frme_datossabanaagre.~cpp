//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Frme_datossabanaagre.h"
#include "dialg_busartic.h"
#include "Frm_selserie.h"
#include "situaciones.h"
#include "dialg_okcancel.h"

#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datossabanaagre *Frame_datossabanaagre;
//---------------------------------------------------------------------------
__fastcall TFrame_datossabanaagre::TFrame_datossabanaagre(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  qry_PuntoVta->Close();
  qry_PuntoVta->ParamByName("cia")->AsInteger = cia_z;
  qry_PuntoVta->Open();
  lkcmb_ptovta->KeyValue = qry_PuntoVta->FieldByName("clave")->AsString;
  qry_vendedor->Close();
  qry_vendedor->Open();
  lkcmb_vendedr->KeyValue = qry_vendedor->FieldByName("codigo")->AsString;
  qry_Poblacion->Close();
  qry_Poblacion->Open();
  lkcmb_poblac->KeyValue = qry_Poblacion->FieldByName("numero")->AsInteger;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datossabanaagre::inicializa(String tipo_z)
{
  if(tipo_z == "S") {
    lbl_prvta->Visible = true;
    edt_prvta->Visible = true;
    lbl_tipago->Visible = true;
    cmb_tipago->Visible = true;
    lbl_crdocont->Visible = false;
    cmb_credcont->Visible = false;
    lbl_tipago->Top = lbl_crdocont->Top;
    cmb_tipago->Top = cmb_credcont->Top;
    lbl_tipago->Left = lbl_crdocont->Left;
    cmb_tipago->Left = cmb_credcont->Left;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datossabanaagre::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) edt_codigoExit(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datossabanaagre::edt_cantiExit(TObject *Sender)
{
  int prfol_z = 0, dispo_z=0;
  String folios_z = "", codigo_z,tipo_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  tipo_z = qry_inven->FieldByName("tipo")->AsString;
  pide_series();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datossabanaagre::pide_series()
{
    String campo_z, entosal_z, codigo_z, tipo_z, folios_z;
    codigo_z = qry_inven->FieldByName("codigo")->AsString;
    tipo_z = qry_inven->FieldByName("tipo")->AsString;
    Tdlg_okcancel *Dlg_analipol;
    Dlg_analipol = new Tdlg_okcancel (this);
    Dlg_analipol->AutoSize = false;
    int ancho_z=0, alto_z=0, canti_z;
    canti_z = edt_canti->Value;
    TForm_selserie *Form_selserie = new TForm_selserie (this);
    Form_selserie->fechaabierta_z = fechaabierta_z;
    Form_selserie->busca_series(codigo_z, alm_z, canti_z, fecha_z);
    Form_selserie->tipoinv_z = tipo_z;
    Form_selserie->sel_primeros_folios(canti_z);
    Form_selserie->permitir_seleccionar(tipo_z == "ALF" || dm->foliosalf_z);
    folios_z = "";
    if(Form_selserie->ShowModal() == mrOk) {
       qry_folsel->Close();
       qry_folsel->Open();
       lst_series->Items->Clear();
       for(Form_selserie->qry_folsel->First(); !Form_selserie->qry_folsel->Eof; Form_selserie->qry_folsel->Next()) {
         lst_series->Items->Add(Form_selserie->qry_folsel->FieldByName("serie")->AsString);
         if(!folios_z.IsEmpty()) folios_z += " - ";
         folios_z += Form_selserie->qry_folsel->FieldByName("folio")->AsString;
         qry_folsel->Append();
         for(int ii_z = 0; ii_z < Form_selserie->qry_folsel->FieldCount; ii_z++) {
           campo_z = Form_selserie->qry_folsel->Fields->Fields[ii_z]->FieldName;
           qry_folsel->FieldByName(campo_z)->Value = Form_selserie->qry_folsel->Fields->Fields[ii_z]->Value;
         }
         qry_folsel->Post();
       }
    }
    edt_folios->Text = folios_z;
    delete Form_selserie;
    lst_series->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datossabanaagre::edt_codigoExit(TObject *Sender)
{
  String codigo_z;
  codigo_z = edt_codigo->Text;
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
    //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
  }
  if(!qry_inven->IsEmpty()) edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
  edt_canti->SetFocus();
}
//---------------------------------------------------------------------------

