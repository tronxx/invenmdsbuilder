//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_nuevasseries.h"
#include "Frme_datosrencanxcam.h"
#include "Frm_selserie.h"
#include "dmod.h"
#include "dialg_busartic.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datosrencanxcam *Frame_datosrencanxcam;
//---------------------------------------------------------------------------
__fastcall TFrame_datosrencanxcam::TFrame_datosrencanxcam(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  cmb_entosal->ItemIndex = 0;
  cmb_statcan->ItemIndex = 0;
  cmb_status->ItemIndex = 0;
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
  qry_folsel->Close();
  qry_folsel->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosrencanxcam::edt_codigoExit(TObject *Sender)
{
  Tdlg_busartic *dlg_busartic;
  String codigo_z;
  codigo_z = edt_codigo->Text.Trim();
  if(!busca_cod(codigo_z)) {
    // No Existe el código, habrá que buscarlo
    Tdlg_busartic *dlg_busartic = new Tdlg_busartic (this);
    dlg_busartic->busca_artic(codigo_z + "%", "-1");
    if(dlg_busartic->ShowModal() == mrOk) {
      codigo_z = dlg_busartic->qry_inven->FieldByName("codigo")->AsString;
      if(!busca_cod(codigo_z)) {
        Application->MessageBox("No existe el artículo", "Artículo Inexistente", MB_ICONEXCLAMATION);
      }
      if( qry_inven->IsEmpty()) { delete dlg_busartic; return; }
    } else {
      delete dlg_busartic; return;
    }
    edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
    //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
    edt_canti->SetFocus();
  } else {
    cmb_entosal->SetFocus();
    cmb_entosal->DroppedDown = true;
  }
}
//---------------------------------------------------------------------------

bool __fastcall TFrame_datosrencanxcam::busca_cod(String codigo_z)
{
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(!qry_inven->IsEmpty()) {
    if(cmb_status->Text == "S")
      edt_costo->Value = qry_inven->FieldByName("costos")->AsFloat;
    else
      edt_costo->Value = qry_inven->FieldByName("coston")->AsFloat;
  }
  return(!qry_inven->IsEmpty());
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrencanxcam::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) edt_codigoExit(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrencanxcam::edt_cantiExit(TObject *Sender)
{
  int prfol_z = 0, ultfol_z=0, dispo_z=0;
  String folios_z = "", codigo_z, tipo_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  tipo_z =  qry_inven->FieldByName("tipo")->AsString;
  if(cmb_entosal->Text.SubString(1,1) == "E") {
    prfol_z = dm->ultimo_folio_disp(alm_z, codigo_z, fecha_z, fechaabierta_z) + 1;
    if(tipo_z == "ALF" ) pide_series();
    if (edt_canti->Value != 1) {
       ultfol_z = prfol_z + (int)edt_canti->Value - 1;
    }
  } else {
    pide_series();
    qry_folsel->First();
    prfol_z = qry_folsel->FieldByName("folio")->AsInteger;
    if (edt_canti->Value != 1) {
      qry_folsel->Last();
      ultfol_z = qry_folsel->FieldByName("folio")->AsInteger;
    }
  }
  edt_folios->Text = IntToStr(prfol_z);
  if (edt_canti->Value != 1) {
     edt_folios->Text += " - " + IntToStr(ultfol_z);
  }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrencanxcam::pide_series()
{
    String campo_z, entosal_z, codigo_z, tipo_z;
    codigo_z = qry_inven->FieldByName("codigo")->AsString;
    tipo_z = qry_inven->FieldByName("tipo")->AsString;
    Tdlg_okcancel *Dlg_analipol;
    Dlg_analipol = new Tdlg_okcancel (this);
    Dlg_analipol->AutoSize = false;
    int ancho_z=0, alto_z=0, canti_z;
    entosal_z = cmb_entosal->Text.SubString(1,1);
    canti_z = edt_canti->Value;
    if(entosal_z == "E") {
      TFrame_nuevasseries *Frame_nuevasseries;
      Frame_nuevasseries = new TFrame_nuevasseries (Dlg_analipol);
      ancho_z = Frame_nuevasseries->Width + 20;
      alto_z = Frame_nuevasseries->Height + Dlg_analipol->Panel2->Height + 80;
      Frame_nuevasseries->Parent = Dlg_analipol->Panel1;
      Dlg_analipol->Width = ancho_z;
      Dlg_analipol->Height = alto_z;
      Dlg_analipol->Caption = "Captura de Series";
      Dlg_analipol->Position = poScreenCenter;
      Frame_nuevasseries->numseries_z = canti_z;
      Frame_nuevasseries->lst_series->Items->Text = lst_series->Items->Text;
      Frame_nuevasseries->codigo_z = edt_codigo->Text.Trim();
      Frame_nuevasseries->ptovta_z = lkcmb_ptovta->Text;
      Frame_nuevasseries->grp_seriesvendidas->Visible = true;
      Frame_nuevasseries->Align = alClient;
      Frame_nuevasseries->cargar_series_vendidas_x_anu("ACTUAL");
      if( Dlg_analipol->ShowModal() == mrOk) {
        edt_nombre->Text = Frame_nuevasseries->nomcli_z;
        lst_series->Items->Text = Frame_nuevasseries->lst_series->Items->Text;
        lst_series->ItemIndex = 0;
        //lst_series->DroppedDown = true;
      }
      delete Frame_nuevasseries;
      delete Dlg_analipol;
    }
    if(entosal_z == "S") {
      TForm_selserie *Form_selserie = new TForm_selserie (this);
      Form_selserie->busca_series(codigo_z, alm_z, canti_z, fecha_z);
      Form_selserie->sel_primeros_folios(canti_z);
      Form_selserie->permitir_seleccionar(tipo_z == "ALF" || dm->foliosalf_z);
      if(Form_selserie->ShowModal() == mrOk) {
         qry_folsel->Close();
         qry_folsel->Open();
         lst_series->Items->Clear();
         for(Form_selserie->qry_folsel->First(); !Form_selserie->qry_folsel->Eof; Form_selserie->qry_folsel->Next()) {
           lst_series->Items->Add(Form_selserie->qry_folsel->FieldByName("serie")->AsString);
           qry_folsel->Append();
           for(int ii_z = 0; ii_z < Form_selserie->qry_folsel->FieldCount; ii_z++) {
             campo_z = Form_selserie->qry_folsel->Fields->Fields[ii_z]->FieldName;
             qry_folsel->FieldByName(campo_z)->Value = Form_selserie->qry_folsel->Fields->Fields[ii_z]->Value;
           }
           qry_folsel->Post();
         }
      }
      delete Form_selserie;
    }
    lst_series->ItemIndex = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrencanxcam::Button1Click(TObject *Sender)
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

