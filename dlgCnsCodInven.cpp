//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgCnsCodInven.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
TfrmDlgCnsCodInven *frmDlgCnsCodInven;
//---------------------------------------------------------------------------
String __fastcall ConsultaCodInventario(TForm *Padre)
{
    AnsiString sResult = "";
    try
    {
        frmDlgCnsCodInven = new TfrmDlgCnsCodInven(Padre);
        frmDlgCnsCodInven->ShowModal();
        if (frmDlgCnsCodInven->bOk)
           sResult = frmDlgCnsCodInven->qsCodigo->FieldByName("Codigo")->AsString;
        delete frmDlgCnsCodInven;
    }
    catch(...)
    {  sResult = "";
       delete frmDlgCnsCodInven;
    }
    return sResult;
}
//---------------------------------------------------------------------------
__fastcall TfrmDlgCnsCodInven::TfrmDlgCnsCodInven(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsCodInven::btnEjecutarClick(TObject *Sender)
{
    qsCodigo->Close();
    if (!edtClave->Text.Trim().IsEmpty() ) {
        qsCodigo->ParamByName("Codigo")->AsString = edtClave->Text.Trim() + "%";
        qsCodigo->ParamByName("Descri")->AsString = "";
    }else if (!edtDescri->Text.Trim().IsEmpty() ) {
        qsCodigo->ParamByName("Codigo")->AsString = "";
        qsCodigo->ParamByName("Descri")->AsString = edtDescri->Text.Trim() + "%";
    }
    qsCodigo->ParamByName("Cia")->AsInteger = dm->cia_z;
    qsCodigo->Open();
    if (!qsCodigo->IsEmpty() ) dbgrdCodigo->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsCodInven::edtClaveKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
          TfrmDlgCnsCodInven::btnEjecutarClick(this);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsCodInven::edtDescriKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
          TfrmDlgCnsCodInven::btnEjecutarClick(this);
    }    
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsCodInven::btnCerrarClick(TObject *Sender)
{
    bOk = false;
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsCodInven::dbgrdCodigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       bOk = true;
       Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsCodInven::dbgrdCodigoDblClick(TObject *Sender)
{
    bOk = true;
    Close();
}
//---------------------------------------------------------------------------
