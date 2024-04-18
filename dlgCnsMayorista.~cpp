//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgCnsMayorista.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
TfrmDlgCnsMayoris *frmDlgCnsMayoris;
//---------------------------------------------------------------------------
String __fastcall BusquedaMayoristas(TForm *Padre)
{
    AnsiString sResult="";
    try
    {
         frmDlgCnsMayoris = new TfrmDlgCnsMayoris(Padre);
         frmDlgCnsMayoris->ShowModal();
         if (frmDlgCnsMayoris->bOk)
             sResult = frmDlgCnsMayoris->qsNombre->FieldByName("codigo")->AsString;
         delete frmDlgCnsMayoris;

    }
    catch(...)
    {   delete frmDlgCnsMayoris;
    }
    return sResult;
}
//---------------------------------------------------------------------------
__fastcall TfrmDlgCnsMayoris::TfrmDlgCnsMayoris(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsMayoris::btnEjecutarClick(TObject *Sender)
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
void __fastcall TfrmDlgCnsMayoris::dxDBGrid1DblClick(TObject *Sender)
{
    bOk = true;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsMayoris::btnCerrarClick(TObject *Sender)
{
    bOk = false;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgCnsMayoris::chkColumnasClick(TObject *Sender)
{
    MostrarColumnas(chkColumnas->Checked);
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCnsMayoris::MostrarColumnas(bool bb)
{
    dxDBGrid1DIREC->Visible = bb;
    dxDBGrid1CIU  ->Visible = bb;
    dxDBGrid1RFC  ->Visible = bb;
    dxDBGrid1TEL  ->Visible = bb;
    dxDBGrid1CARGOS->Visible = bb;
    dxDBGrid1ABONOS->Visible = bb;
    dxDBGrid1COMPRAANU->Visible = bb;
    dxDBGrid1COMPRAMES->Visible = bb;
    dxDBGrid1PDSC ->Visible = bb;
    dxDBGrid1ULTMOV->Visible = bb;
    dxDBGrid1STATUS->Visible = bb;
    dxDBGrid1CIA->Visible = bb;
    dxDBGrid1NOMPAG1->Visible = bb;
    dxDBGrid1NOMPAG2->Visible = bb;
    dxDBGrid1DIRPAG1->Visible = bb;
    dxDBGrid1DIRPAG2->Visible = bb;
    dxDBGrid1CIUPAG ->Visible = bb;
    dxDBGrid1NOMBRE2->Visible = bb;
}
void __fastcall TfrmDlgCnsMayoris::dxDBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       bOk = true;
       Close();
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgCnsMayoris::edtNombreKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
        TfrmDlgCnsMayoris::btnEjecutarClick(this);
    }
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgCnsMayoris::edtClaveKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
        TfrmDlgCnsMayoris::btnEjecutarClick(this);
    }    
}
//---------------------------------------------------------------------------

