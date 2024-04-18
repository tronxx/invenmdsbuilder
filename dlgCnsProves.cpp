//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgCnsProves.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
TfrmDlgConsProve *frmDlgConsProve;
//---------------------------------------------------------------------------
String __fastcall ConsultaProveedores(TForm *Padre)
{
    String sResult = "";
    try
    {
        frmDlgConsProve = new TfrmDlgConsProve(Padre);
        frmDlgConsProve->ShowModal();
        if (frmDlgConsProve->bOk)
            sResult = frmDlgConsProve->qsNombre->FieldByName("codigo")->AsString;
        delete frmDlgConsProve;
    }
    catch(...)
    {
       delete frmDlgConsProve;
    }
    return sResult;
}
//---------------------------------------------------------------------------
__fastcall TfrmDlgConsProve::TfrmDlgConsProve(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConsProve::btnEjecutarClick(TObject *Sender)
{
      qsNombre->Close();
      qsNombre->ParamByName("CIA")->AsInteger = dm->cia_z;
      if (!edtNombre->Text.Trim().IsEmpty() )
           qsNombre->ParamByName("Nombre")->AsString  = edtNombre->Text.Trim() + "%";
      else qsNombre->ParamByName("Nombre")->AsString  = "";
      if (!edtClave->Text.Trim().IsEmpty() )
           qsNombre->ParamByName("Codigo")->AsString = edtClave->Text.Trim() + "%";
      else qsNombre->ParamByName("Codigo")->AsString = "";
      qsNombre->Open();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConsProve::chkColumnasClick(TObject *Sender)
{
    MostrarColumnas(chkColumnas->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConsProve::MostrarColumnas(bool bb)
{
    dxDBGrid1DIREC->Visible = bb;
    dxDBGrid1CIU  ->Visible = bb;
    dxDBGrid1RFC  ->Visible = bb;
    dxDBGrid1TEL  ->Visible = bb;
    dxDBGrid1CARGOS->Visible = bb;
    dxDBGrid1ABONOS->Visible = bb;
    dxDBGrid1COMPRAANU->Visible = bb;
    dxDBGrid1COMPRAMES->Visible = bb;
    dxDBGrid1ULTMOV->Visible = bb;
    dxDBGrid1STATUS->Visible = bb;
    dxDBGrid1CIA->Visible = bb;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConsProve::dxDBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       bOk = true;
       Close();
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConsProve::edtNombreKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
        TfrmDlgConsProve::btnEjecutarClick(this);
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgConsProve::btnCerrarClick(TObject *Sender)
{
    bOk = false;
    Close();
}
//---------------------------------------------------------------------------
