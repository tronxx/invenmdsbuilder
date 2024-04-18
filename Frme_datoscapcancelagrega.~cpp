//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datoscapcancelagrega.h"
#include "Frm_capcancel.h"
#include "dmod.h"
#include "dialg_busartic.h"
#include "Frm_selserie.h"
#include "dialg_okcancel.h"
#include "Frme_nuevasseries.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datoscapcancelagrega *Frame_datoscapcancelagrega;
//---------------------------------------------------------------------------
__fastcall TFrame_datoscapcancelagrega::TFrame_datoscapcancelagrega(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  qry_puntovta->Close();
  qry_puntovta->ParamByName("cia")->AsInteger = cia_z;
  qry_puntovta->Open();
  lkcmb_ptovta->KeyValue = qry_puntovta->FieldByName("clave")->AsString;
  qry_vendedor->Close();
  qry_vendedor->Open();
  lkcmb_vendedr->KeyValue = qry_vendedor->FieldByName("codigo")->AsString;
  qry_poblacion->Close();
  qry_poblacion->Open();
  lkcmb_poblac->KeyValue = qry_poblacion->FieldByName("numero")->AsInteger;
  cmb_status->ItemIndex = 0;
  cmb_entcan->ItemIndex = 0;
  cmb_credcont->ItemIndex = 1;
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datoscapcancelagrega::edt_codigoKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_RETURN) edt_codigoExit(this);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapcancelagrega::edt_cantiExit(TObject *Sender)
{
  int prfol_z = 0, dispo_z=0;
  String folios_z = "", codigo_z,tipo_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  tipo_z =  qry_inven->FieldByName("tipo")->AsString;
  prfol_z = dm->folio_siguiente(alm_z, codigo_z);
  edt_folios->Text = IntToStr(prfol_z);
  if (edt_canti->Value != 1) {
     edt_folios->Text += " - " + IntToStr(prfol_z + (int)edt_canti->Value - 1);
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapcancelagrega::pide_series()
{
    Tdlg_okcancel *Dlg_analipol;
    Dlg_analipol = new Tdlg_okcancel (this);
    Dlg_analipol->AutoSize = false;
    int ancho_z=0, alto_z=0;
    TFrame_nuevasseries *Frame_nuevasseries;
    Frame_nuevasseries = new TFrame_nuevasseries (Dlg_analipol);
    ancho_z = Frame_nuevasseries->Width + 20;
    alto_z = Frame_nuevasseries->Height + Dlg_analipol->Panel2->Height + 80;
    Frame_nuevasseries->Parent = Dlg_analipol->Panel1;
    Dlg_analipol->Width = ancho_z;
    Dlg_analipol->Height = alto_z;
    Dlg_analipol->Caption = "Captura de Series";
    Dlg_analipol->Position = poScreenCenter;
    Frame_nuevasseries->numseries_z = edt_canti->Value;
    Frame_nuevasseries->codigo_z= edt_codigo->Text.Trim();
    Frame_nuevasseries->grp_seriesvendidas->Visible = true;
    Frame_nuevasseries->ptovta_z = qry_puntovta->FieldByName("clave")->AsString;
    Frame_nuevasseries->cargar_series_vendidas();
    Frame_nuevasseries->lst_series->Items->Text = lst_series->Items->Text;
    Frame_nuevasseries->Align = alClient;
    if( Dlg_analipol->ShowModal() == mrOk) {
      lst_series->Items->Text = Frame_nuevasseries->lst_series->Items->Text;
      lst_series->ItemIndex = 0;
      edt_nombre->Text = Frame_nuevasseries->nomcli_z;
      //lst_series->DroppedDown = true;
    }
    delete Frame_nuevasseries;
    delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapcancelagrega::cmb_statusExit(
      TObject *Sender)
{
 if(cmb_status->Text == "S")
    edt_costou->Value = qry_inven->FieldByName("costos")->AsFloat;
  else
    edt_costou->Value = qry_inven->FieldByName("coston")->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapcancelagrega::busca_cod(String codigo_z)
{
  edt_codigo->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapcancelagrega::edt_codigoExit(
      TObject *Sender)
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
      if( qry_inven->IsEmpty()) { delete dlg_busartic; return; }
    } else {
      delete dlg_busartic; return;
    }
    edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
    //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
    edt_canti->SetFocus();
  } else {
    edt_canti->SetFocus();
  }

}
//---------------------------------------------------------------------------


void __fastcall TFrame_datoscapcancelagrega::Button1Click(TObject *Sender)
{
  String tipo_z;
  if(qry_inven->State == dsInactive) return;
  if(qry_inven->IsEmpty()) return;
  tipo_z =  qry_inven->FieldByName("tipo")->AsString;
  if(tipo_z == "ALF" ) {
    pide_series();
  }

}
//---------------------------------------------------------------------------


