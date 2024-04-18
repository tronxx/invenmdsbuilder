//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosrenpolcobma.h"
#include "dmod.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
#pragma resource "*.dfm"
TFrame_datosrenpolcobma *Frame_datosrenpolcobma;
//---------------------------------------------------------------------------
__fastcall TFrame_datosrenpolcobma::TFrame_datosrenpolcobma(TComponent* Owner)
        : TFrame(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcobma::inicializa()
{
  cia_z = dm->cia_z;
  qry_mayoris->Close();
  qry_mayoris->ParamByName("cia")->AsInteger = cia_z;
  qry_mayoris->Open();
  cmb_tipopago->ItemIndex = 0;
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosrenpolcobma::lkcmb_mayorisExit(TObject *Sender)
{
  String mayoris_z;
  mayoris_z =  qry_mayoris->FieldByName("codigo")->AsString;
  qry_facturas->Close();
  qry_facturas->ParamByName("mayoris")->AsString = mayoris_z;
  qry_facturas->ParamByName("cia")->AsInteger = cia_z;
  qry_facturas->Open();
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  Dlg_datos->AutoSize = false;
  dbgrd_facturas->Parent = Dlg_datos->Panel1;
  dbgrd_facturas->Align = alClient;
  dbgrd_facturas->Visible = true;
  Dlg_datos->Caption = "Seleccione La Factura A la que abona";
  Dlg_datos->Position = poScreenCenter;
  if(Dlg_datos->ShowModal() == mrOk) {
  }
  dbgrd_facturas->Parent = this;
  dbgrd_facturas->Visible = false;
  delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcobma::qry_facturasAfterScroll(
      TDataSet *DataSet)
{
   edt_importe->Value = qry_facturas->FieldByName("saldo")->AsFloat;
   edt_concepto->Text = qry_facturas->FieldByName("concep")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcobma::edt_importeExit(TObject *Sender)
{
 if (edt_importe->Value > db_edit->Value){
   Application->MessageBox("Importe Mayor al Saldo", "Verifique", MB_ICONEXCLAMATION);
 }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcobma::dbgrd_facturasCustomDraw(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxDBTreeListColumn *AColumn,
      const AnsiString AText, TFont *AFont, TColor &AColor, bool ASelected,
      bool AFocused, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
        
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrenpolcobma::lkcmb_mayorisEnter(
      TObject *Sender)
{
  qry_facturas->Close();
}
//---------------------------------------------------------------------------

