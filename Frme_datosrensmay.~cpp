//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Frme_datosrensmay.h"
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
TFrame_datosrensmay *Frame_datosrensmay;
//---------------------------------------------------------------------------
__fastcall TFrame_datosrensmay::TFrame_datosrensmay(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  modoframe_z = "REN_SAL_MAY";
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrensmay::inicializa(String tipoini_z)
{
  modoframe_z = tipoini_z;
  if(modoframe_z == "SERVICIO") {
    lbl_canti->Caption = "Servicio";
    lbl_folio->Visible = false;
    edt_folios->Visible = false;
    lbl_serie->Visible = false;
    lst_series->Visible = false;
    edt_canti->DecimalPlaces = 2;
    edt_canti->DisplayFormat = "$,0.00;-$,0.00";
    //edt_canti->Width = lst_series->Width;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrensmay::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) edt_codigoExit(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrensmay::edt_cantiExit(TObject *Sender)
{
  int prfol_z = 0, dispo_z=0;
  String folios_z = "", codigo_z,tipo_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  tipo_z = qry_inven->FieldByName("tipo")->AsString;
  if(modoframe_z == "REN_SAL_MAY" ) {
     pide_series();
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrensmay::pide_series()
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

void __fastcall TFrame_datosrensmay::edt_codigoExit(TObject *Sender)
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
      delete dlg_busartic;
    }
    //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
  }
  if(!qry_inven->IsEmpty()) edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
  if(modoframe_z == "REN_SAL_MAY" ) edt_canti->SetFocus();

}
//---------------------------------------------------------------------------

