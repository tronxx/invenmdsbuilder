//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dlgFiltroConsFacMay.h"
#include "dmod.h"
#include "dlgCnsMayorista.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TdlgFilConsufacma *dlgFilConsufacma;
//---------------------------------------------------------------------------
AnsiString __fastcall FiltroBusquedaFacMay(TForm *Padre)
{
    AnsiString sResult = "";
    try
    {
        dlgFilConsufacma = new TdlgFilConsufacma(Padre);
        dlgFilConsufacma->ShowModal();
        if (dlgFilConsufacma->bOk ) {
            sResult = dlgFilConsufacma->sql;
        }else sResult = "";
        delete dlgFilConsufacma;
    }
    catch(...)
    {
    }
    return sResult;

}
//---------------------------------------------------------------------------
__fastcall TdlgFilConsufacma::TdlgFilConsufacma(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TdlgFilConsufacma::btnCerrarClick(TObject *Sender)
{
    bOk = false;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TdlgFilConsufacma::btnAceptarClick(TObject *Sender)
{
    sql = "";
    sql = "select a.*,";
    sql += " cast((case TIPAGO when 'I' then 'INTERES' when 'M' then 'MERCANCIA' else 'OTRO TIPO' end) as varchar(15) ) sTipago,";
    sql += " cast((case MAYOMEN when 'Y' then 'MAYOREO' when 'M' then 'MENUDEO' else 'OTROS' end) as varchar(15) ) sMayomen,";
    sql += " cast((case STATUS when 'A' then 'ABIERTO' when 'C' then 'CERRADO' end) as varchar(10) ) as sStatus";
    sql += " from FacturMa a";
    sql += " where cia = " + IntToStr(dm->cia_z);
    if (edtPriFac->Text.Trim().ToIntDef(0) > 0 && edtUltFac->Text.Trim().ToIntDef(0) > 0)
       sql += " and num between " + edtPriFac->Text.Trim() + " and " + edtUltFac->Text.Trim();

    if (chkRangoFecha->Checked)
       sql += " and fecha between '" + dtFechaIni->Date.FormatString("yyyy-mm-dd") + "' and '" + dtFechaFin->Date.FormatString("yyyy-mm-dd") + "'";

    if (!edtProve->Text.Trim().IsEmpty() )
       sql += " and Mayoris = '" + edtProve->Text.Trim() + "'";

    if (chkMayoreo->Checked && !chklMenudeo->Checked)
       sql += " and Mayomen = 'Y'";
    else if (!chkMayoreo->Checked && chklMenudeo->Checked)
       sql += " and Mayomen = 'M'";
    else sql += " and (Mayomen = 'Y' or Mayomen = 'M')";

    if (chkMercancia->Checked && !chkInteres->Checked && !chkOtros->Checked)
        sql += " and Tipago = 'M'";
    else if (!chkMercancia->Checked && chkInteres->Checked && !chkOtros->Checked)
        sql += " and Tipago = 'I'";
    else if (!chkMercancia->Checked && !chkInteres->Checked && chkOtros->Checked)
        sql += " and (Tipago != 'M' and Tipago != 'I')";
    else if (chkMercancia->Checked && chkInteres->Checked && !chkOtros->Checked)
        sql += " and (Tipago = 'M' or Tipago = 'I')";
    else if (!chkMercancia->Checked && chkInteres->Checked && chkOtros->Checked)
        sql += " and Tipago != 'M'";
    else if (chkMercancia->Checked && !chkInteres->Checked && chkOtros->Checked)
        sql += " and Tipago != 'I'";
    if (chkAbierto->Checked && !chkCerrado)
        sql += " and Status = 'A'";
    else if (!chkAbierto->Checked && chkCerrado)
        sql += " and Status = 'C'";
    if (edtPrimPlazo->Value >0 && edtUltPlazo->Value > 0)
        sql += " and Plazo between " + edtPrimPlazo->Text.Trim() + " and " + edtUltPlazo->Text.Trim();
    sql += " order by a.Num";
    bOk = true;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TdlgFilConsufacma::FormShow(TObject *Sender)
{
    dtFechaIni->Date = TDateTime::CurrentDate();
    dtFechaFin->Date = TDateTime::CurrentDate();    
}
//---------------------------------------------------------------------------

void __fastcall TdlgFilConsufacma::edtProveKeyDown(TObject *Sender,
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
bool __fastcall TdlgFilConsufacma::BuscarProveedor(String sClave)
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
void __fastcall TdlgFilConsufacma::edtProveAltBtnClick(TObject *Sender)
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


