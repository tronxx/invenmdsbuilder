//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgCataAlmacen.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
TfrmDlgCataAlmacen *frmDlgCataAlmacen;
//---------------------------------------------------------------------------
AnsiString __fastcall CatalogoAlmacenes(TForm *Padre)
{
    AnsiString sResult = "";
    try
    {
        frmDlgCataAlmacen = new TfrmDlgCataAlmacen(Padre);
        frmDlgCataAlmacen->ShowModal();
        if (frmDlgCataAlmacen->bOk) {
            sResult = frmDlgCataAlmacen->qsAlmancen->FieldByName("Clave")->AsString;
        }
        delete frmDlgCataAlmacen;
    }
    catch(...)
    {
        delete frmDlgCataAlmacen;
        sResult = "";
    }
    return sResult;

}
//---------------------------------------------------------------------------
__fastcall TfrmDlgCataAlmacen::TfrmDlgCataAlmacen(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgCataAlmacen::btnAceptarClick(TObject *Sender)
{
    bOk=true;
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgCataAlmacen::btnCerrarClick(TObject *Sender)
{
    bOk = false;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgCataAlmacen::FormShow(TObject *Sender)
{
    qsAlmancen->Close();
    qsAlmancen->ParamByName("Cia")->AsInteger = dm->cia_z;
    qsAlmancen->Open();
}
//---------------------------------------------------------------------------

