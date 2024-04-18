//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgFiltroCnsPed.h"
#include "dlgCnsMayorista.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TfrmDlgFilPedidos *frmDlgFilPedidos;
//---------------------------------------------------------------------------
String __fastcall FiltroPedidos(TForm *Padre)
{
    AnsiString sResult="";
    try
    {
        frmDlgFilPedidos = new TfrmDlgFilPedidos(Padre);
        frmDlgFilPedidos->ShowModal();
        if ( frmDlgFilPedidos->bOk)
           sResult = frmDlgFilPedidos->sql;
        delete frmDlgFilPedidos;
    }
    catch(...)
    {
        delete frmDlgFilPedidos;
    }
    return sResult;

}
//---------------------------------------------------------------------------
__fastcall TfrmDlgFilPedidos::TfrmDlgFilPedidos(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgFilPedidos::btnCerrarClick(TObject *Sender)
{
    bOk = false;
    Close();    
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgFilPedidos::btnAceptarClick(TObject *Sender)
{
    sql = "select a.tipo, a.alm, a.numero, a.prove, a.perenvrec,";
    sql += " a.status, cast((case a.status when 'A' then 'ABIERTO'  when 'C' then 'CERRADO' end) as varchar(12) )";
    sql += " as sStatus,";
    sql += " a.coniva, a.fecha, a.importe, a.iva, (a.importe+a.iva) as total,";
    sql += " b.Nombre as sNomProve, c.Nombre as sNomUsu, a.cia, d.concepto as sContacto";
    sql += " from entradas a";
    sql += " left outer join proveedor b on b.codigo = a.prove";
    sql += " left outer join usuarios c on c.iniciales = a.usuario";
    sql += " left outer join conceps d on d.ncon = a.perenvrec";
    sql += " where a.tipo = 'B'";
    if (edtPriPed->Text.Trim().ToIntDef(0) >= 0 && edtUltPed->Text.Trim().ToIntDef(0) > 0) {
        sql += " and a.numero >= " + edtPriPed->Text.Trim();
        sql += " and a.numero <= " + edtUltPed->Text.Trim();
    }
    if (chkRangoFecha->Checked) {
       sql += " and a.fecha between '" + dtFechaIni->Date.FormatString("yyyy-mm-dd") + "'";
       sql += " and '" + dtFechaFin->Date.FormatString("yyyy-mm-dd") + "'";
    }
    if (!edtProve->Text.Trim().IsEmpty() )
        sql += " and a.prove = '" + edtProve->Text.Trim() + "'";

    sql += " and Tipo = 'B'";
    if (edtPriPed->Text.Trim().ToIntDef(0) >= 0 && edtUltPed->Text.Trim().ToIntDef(0) > 0) 
        sql += " order by a.Fecha";

    bOk = true;
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmDlgFilPedidos::FormShow(TObject *Sender)
{
    dtFechaIni->Date = TDateTime::CurrentDate();
    dtFechaFin->Date = TDateTime::CurrentDate();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgFilPedidos::chkRangoFechaClick(TObject *Sender)
{
    dtFechaIni->Enabled = chkRangoFecha->Checked;
    dtFechaFin->Enabled = chkRangoFecha->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgFilPedidos::edtProveAltBtnClick(TObject *Sender)
{
        AnsiString sClave = BusquedaMayoristas(this);
    if (sClave != "") {
       if (!BuscarProveedor(sClave) ) {
          Application->MessageBox("NO EXISTE EL CODIGO DE MAYORISTA SOLICITADO !!", "Mayorista", MB_OK | MB_ICONQUESTION);
          return;
       }
    }
}
//---------------------------------------------------------------------------
void __fastcall TfrmDlgFilPedidos::edtProveKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarProveedor(edtProve->Text.Trim() ) ) {
           Application->MessageBox("NO EXISTE LA CLAVE DEL PROVEEDOR MAYORISTA !!", "Mayorista", MB_OK | MB_ICONQUESTION);
           return;
       }
    }
}
//---------------------------------------------------------------------------
bool __fastcall TfrmDlgFilPedidos::BuscarProveedor(String sClave)
{
    bool bResult=false;
    qsProve->Close();
    qsProve->ParamByName("Codigo")->AsString  = sClave;
    qsProve->ParamByName("Cia"   )->AsInteger = dm->cia_z;
    qsProve->Open();
    if (!qsProve->IsEmpty() ) {
        edtProve->Text = qsProve->FieldByName("Codigo")->AsString;
        edtNomProve->Text = qsProve->FieldByName("Nombre")->AsString;
        bResult = true;
    }else {
        edtProve->Text = "";
        edtNomProve->Text = "";
    }
    return bResult;

}
//---------------------------------------------------------------------------

