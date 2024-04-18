//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgCnsPenPagMay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
//#pragma link "dxmdaset"
#pragma link "dxTL"
#pragma resource "*.dfm"
TfrmDlgPendPagMay *frmDlgPendPagMay;
//---------------------------------------------------------------------------
int __fastcall ConsultaPendMayoristas(TForm *Padre, String sClave, int icia, int &iConsep, int &iPagarep)
{
    int iResult = 0;
    try
    {
        frmDlgPendPagMay = new TfrmDlgPendPagMay(Padre);
        frmDlgPendPagMay->qsMayoris->Close();
        frmDlgPendPagMay->qsMayoris->ParamByName("Clave")->AsString  = sClave;
        //frmDlgPendPagMay->qsMayoris->ParamByName("cia"  )->AsInteger = icia;
        frmDlgPendPagMay->qsMayoris->Open();
        frmDlgPendPagMay->Caption = frmDlgPendPagMay->qsMayoris->FieldByName("codigo")->AsString + " " + frmDlgPendPagMay->qsMayoris->FieldByName("Nombre")->AsString;

        frmDlgPendPagMay->qsPendPag->Close();
        frmDlgPendPagMay->qsPendPag->ParamByName("Mayoris")->AsString  = sClave;
        frmDlgPendPagMay->qsPendPag->ParamByName("Cia"    )->AsInteger = icia;
        frmDlgPendPagMay->qsPendPag->Open();

        //frmDlgPendPagMay->qsPendPag->Active = false;
        //frmDlgPendPagMay->qsPendPag->CreateFieldsFromDataSet(frmDlgPendPagMay->qsPendPag);
        //frmDlgPendPagMay->qsPendPag->LoadFromDataSet(frmDlgPendPagMay->qsPendPag);
        //frmDlgPendPagMay->qsPendPag->Close();

        frmDlgPendPagMay->dbgrdPendPag->GotoFirst();
        frmDlgPendPagMay->ShowModal();
        if (frmDlgPendPagMay->bOk) {
             iResult = frmDlgPendPagMay->qsPendPag->FieldByName("Docto")->AsInteger;
             iConsep = frmDlgPendPagMay->qsPendPag->FieldByName("Conse")->AsInteger;
             iPagarep = frmDlgPendPagMay->qsPendPag->FieldByName("Pagare")->AsInteger;
        }
        else { iResult = 0; iConsep = 0; iPagarep = 0; }

        delete frmDlgPendPagMay;
    }
    catch(...)
    { delete frmDlgPendPagMay;
    }
    return iResult;
}
//---------------------------------------------------------------------------
__fastcall TfrmDlgPendPagMay::TfrmDlgPendPagMay(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgPendPagMay::RzBitBtn1Click(TObject *Sender)
{
    bOk = true;
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgPendPagMay::btnCancelarClick(TObject *Sender)
{
    bOk = false;
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgPendPagMay::dbgrdPendPagKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       bOk = true;
       Close();
    }
}
//---------------------------------------------------------------------------

