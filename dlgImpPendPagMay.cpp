//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgImpPendPagMay.h"
#include "dlgCnsMayorista.h"
#include "dmod.h"
#include "RepEdoCtaMayoris.h"
#include "RepCarAboMay.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TfrmDlgImpPenPag *frmDlgImpPenPag;
//---------------------------------------------------------------------------
void __fastcall ImpresionPendientesMayoristas(TForm *Padre, bool bTipo)
{
    try
    {
        frmDlgImpPenPag = new TfrmDlgImpPenPag(Padre, bTipo);
        if (bTipo) {
            frmDlgImpPenPag->lblAnio->Visible = false;
            frmDlgImpPenPag->spinAnio->Visible = false;
            frmDlgImpPenPag->rlblLetrero->Visible = true;
        }else {
            frmDlgImpPenPag->lblAnio->Visible = true;
            frmDlgImpPenPag->spinAnio->Visible = true;
            frmDlgImpPenPag->rlblLetrero->Visible = false;            
            frmDlgImpPenPag->Caption = "Movimientos de Cargos y Abonos";
        }
        frmDlgImpPenPag->ShowModal();
        delete frmDlgImpPenPag;
    }
    catch(...)
    {   delete frmDlgImpPenPag;
    }

}
//---------------------------------------------------------------------------
__fastcall TfrmDlgImpPenPag::TfrmDlgImpPenPag(TComponent* Owner, bool bTipop)
    : TForm(Owner)
{
    bTIPO = bTipop;
    spinAnio->Value = TDateTime::CurrentDate().FormatString("yyyy").ToIntDef(2005);
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgImpPenPag::btnCerrarClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
bool __fastcall TfrmDlgImpPenPag::BuscarMayorista(String sCodigo)
{
    bool bResult = false;
    qsMayoris->Close();
    qsMayoris->ParamByName("Codigo")->AsString  = sCodigo;
    qsMayoris->ParamByName("Cia"   )->AsInteger = dm->cia_z;
    qsMayoris->Open();
    if (!qsMayoris->IsEmpty() ) {
       edtCveMay   ->Text = qsMayoris->FieldByName("codigo")->AsString;
       edtMayorista->Text = qsMayoris->FieldByName("Nombre")->AsString;
       edtDirecc   ->Text = qsMayoris->FieldByName("Direc" )->AsString;
       bResult = true;
    }else {
       edtCveMay   ->Text = "";
       edtMayorista->Text = "";
       edtDirecc   ->Text = "";
    }
    return bResult;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgImpPenPag::edtCveMayKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarMayorista(edtCveMay->Text.Trim() )) {
          Application->MessageBox("NO EXISTE LA CLAVE DEL MAYORISTA SOLICITADO !!", "Clave", MB_OK | MB_ICONQUESTION);
          return;
       }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgImpPenPag::edtCveMayAltBtnClick(TObject *Sender)
{
    AnsiString sMayor="";
    sMayor = BusquedaMayoristas(this);
    if (sMayor != "") {
        edtCveMay->Text = sMayor;
        if (!BuscarMayorista(sMayor) ) {
           Application->MessageBox("NO EXISTE LA CLAVE DEL MAYORISTA !!", "Mayorista", MB_OK | MB_ICONWARNING);
           return;
        }                                 
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgImpPenPag::btnImpEdoCtaClick(TObject *Sender)
{
    if (bTIPO) //Pendientes de pago true
          ImpRepEdoCtaMayoris(edtCveMay->Text.Trim(), dm->cia_z);
    else //Estado de cuenta false
         ImpresionCargosAbonosMay(edtCveMay->Text.Trim(), dm->cia_z, spinAnio->Value);
}
//---------------------------------------------------------------------------
