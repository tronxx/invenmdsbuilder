//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_consufacma.h"
#include "dmod.h"
#include "dlgFiltroConsFacMay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
//#pragma link "dxmdaset"
#pragma resource "*.dfm"
TfrmConsuFactuMay *frmConsuFactuMay;
//---------------------------------------------------------------------------
void __fastcall ConsultaFacturaMayoreo(TForm *Padre)
{
    try
    {
        frmConsuFactuMay = new TfrmConsuFactuMay(Padre);
        frmConsuFactuMay->Show();
    }
    catch(...)
    {    }

}
//---------------------------------------------------------------------------
__fastcall TfrmConsuFactuMay::TfrmConsuFactuMay(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsuFactuMay::FormShow(TObject *Sender)
{
    qsFacturas->Close();
    qsFacturas->ParamByName("Fecha")->AsDateTime = TDateTime::CurrentDate();
    qsFacturas->ParamByName("Cia"  )->AsInteger  = dm->cia_z;
    qsFacturas->Open();
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsuFactuMay::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    frmConsuFactuMay = NULL;
}
//---------------------------------------------------------------------------


void __fastcall TfrmConsuFactuMay::actFiltroExecute(TObject *Sender)
{
    AnsiString sql = "";
    sql = FiltroBusquedaFacMay(this);
    if (sql != "") {
       qsFacturas->Close();
       qsFacturas->SQL->Clear();
       qsFacturas->SQL->Add(sql);
       qsFacturas->Open();

       bEstado = false;
       //mdatFactura->Active = false;
       //mdatFactura->CreateFieldsFromDataSet(qsFacturas);
       //mdatFactura->LoadFromDataSet(qsFacturas);
       //qsFacturas->Close();
       bEstado = true;
       //DesplegarRenglon();
    }
}
//---------------------------------------------------------------------------


void __fastcall TfrmConsuFactuMay::actExpandirExecute(TObject *Sender)
{
    if (dbgrdFactura->DataSource->DataSet->IsEmpty() ) return;
    dbgrdFactura->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsuFactuMay::actAgruparExecute(TObject *Sender)
{
    if (dbgrdFactura->DataSource->DataSet->IsEmpty() ) return;
    dbgrdFactura->FullCollapse();
}
//---------------------------------------------------------------------------


void __fastcall TfrmConsuFactuMay::actExcelExecute(TObject *Sender)
{
    if (dbgrdFactura->DataSource->DataSet->IsEmpty() ) return;
        dbgrdFactura->SaveToXLS("FacturasMay.xls", true);
        ShellExecute(0, "open", "FacturasMay.xls", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsuFactuMay::qsRenFacAfterScroll(TDataSet *DataSet)
{
    qsSeries->Close();
    qsSeries->ParamByName("Factur" )->AsInteger = qsRenFac->FieldByName("Factur")->AsInteger;
    qsSeries->ParamByName("Renglon")->AsInteger = qsRenFac->FieldByName("Consec")->AsInteger;
    qsSeries->ParamByName("Cia"    )->AsInteger = qsRenFac->FieldByName("Cia"   )->AsInteger;
    qsSeries->Open();
}
//---------------------------------------------------------------------------


void __fastcall TfrmConsuFactuMay::actCerrarExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmConsuFactuMay::DesplegarRenglon()
{
      qsRenFac->DisableControls();
      qsRenFac->Close();
      qsRenFac->ParamByName("Factur")->AsInteger = qsFacturas->FieldByName("Num")->AsInteger;
      qsRenFac->ParamByName("Cia"   )->AsInteger = qsFacturas->FieldByName("Cia")->AsInteger;
      qsRenFac->Open();
      //mdatRenFac->Active = false;
      //mdatRenFac->CreateFieldsFromDataSet(qsRenFac);
      //mdatRenFac->LoadFromDataSet(qsRenFac);
      qsRenFac->EnableControls();
      //qsRenFac->Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsuFactuMay::actBuscarExecute(TObject *Sender)
{
   AnsiString InputString = InputBox("Buscar", "Teclee No. Factura:", "");
   if (InputString != "") {
      TLocateOptions Opts;    Opts.Clear();
      Opts << loPartialKey;
      qsFacturas->First();
      qsFacturas->Locate("Num", InputString, Opts);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsuFactuMay::dbgrdFacturaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
   /*
    if (Shift == TShiftState() ) {
       if (Key == VK_RETURN || Key == VK_SPACE || Key == VK_UP || Key == VK_DOWN)
           DesplegarRenglon();
    }
    */
}
//---------------------------------------------------------------------------


void __fastcall TfrmConsuFactuMay::ToolButton5Click(TObject *Sender)
{
   // dxComponentPrinter1->Print(true, NULL, NULL);
}
//---------------------------------------------------------------------------

void __fastcall TfrmConsuFactuMay::actPrevioExecute(TObject *Sender)
{
    //dxComponentPrinter1->Preview(true,NULL);
}
//---------------------------------------------------------------------------



void __fastcall TfrmConsuFactuMay::mdatFacturaAfterScroll(
      TDataSet *DataSet)
{
    if (bEstado) DesplegarRenglon();
}
//---------------------------------------------------------------------------

