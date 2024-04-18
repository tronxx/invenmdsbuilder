//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgCnsConcepto.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"

TfrmDlgConcepto *frmDlgConcepto;
//---------------------------------------------------------------------------
int __fastcall BuscarConcepts(TForm *Padre)
{
    int iResult=0;
    try
    {
        frmDlgConcepto = new TfrmDlgConcepto(Padre);
        frmDlgConcepto->ShowModal();
        if (frmDlgConcepto->bOk)
           frmDlgConcepto->qsConcepto->FieldByName("nCon")->AsInteger;
        delete frmDlgConcepto;
    }
    catch(...)
    {
        delete frmDlgConcepto;
        iResult = 0;
    }
    return iResult;
}
//---------------------------------------------------------------------------
__fastcall TfrmDlgConcepto::TfrmDlgConcepto(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConcepto::btnEjecutarClick(TObject *Sender)
{
      qsConcepto->Close();
      if (!edtNombre->Text.Trim().IsEmpty() )
           qsConcepto->ParamByName("Concepto")->AsString  = edtNombre->Text.Trim() + "%";
      else qsConcepto->ParamByName("Concepto")->AsString  = "";
      if (!edtClave->Text.Trim().IsEmpty() )
           qsConcepto->ParamByName("ncon")->AsInteger = edtClave->Text.Trim().ToIntDef(0);
      else qsConcepto->ParamByName("ncon")->AsInteger = 0;
      qsConcepto->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConcepto::dxDBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       bOk = true;
       Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConcepto::dxDBGrid1DblClick(TObject *Sender)
{
    bOk = true;
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConcepto::btnCerrarClick(TObject *Sender)
{
    bOk=false;
    Close();
}
//---------------------------------------------------------------------------
