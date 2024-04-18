//----------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "RepCarAboMay.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
TqrRepCarAboMay *qrRepCarAboMay;
//----------------------------------------------------------------------------
void __fastcall ImpresionCargosAbonosMay(String sClave, int icia, int iAnio)
{
    qrRepCarAboMay->qsCias->Close();
    qrRepCarAboMay->qsCias->ParamByName("cia")->AsInteger = icia;
    qrRepCarAboMay->qsCias->Open();
    AnsiString sCadena ="";
    sCadena = qrRepCarAboMay->qsCias->FieldByName("Dir")->AsString + " " ;
    sCadena += " Tels.: " + qrRepCarAboMay->qsCias->FieldByName("Tel")->AsString;
    sCadena += " Fax " + qrRepCarAboMay->qsCias->FieldByName("Fax")->AsString;
    sCadena += " RFC: " + qrRepCarAboMay->qsCias->FieldByName("RFC")->AsString;
    qrRepCarAboMay->qrlblEmpresa->Caption = qrRepCarAboMay->qsCias->FieldByName("NomFis")->AsString;
    qrRepCarAboMay->qrlblDirecc->Caption  = sCadena;

    qrRepCarAboMay->qsMayoris->Close();
    qrRepCarAboMay->qsMayoris->ParamByName("Codigo")->AsString = sClave;
    qrRepCarAboMay->qsMayoris->ParamByName("Cia"    )->AsInteger = icia;
    qrRepCarAboMay->qsMayoris->Open();
    TDateTime dtFechaIni = TDateTime(iAnio, 01, 01);
    TDateTime dtFechaFin = TDateTime(iAnio, 12, 31);

    if (!qrRepCarAboMay->qsMayoris->IsEmpty() ) {
        qrRepCarAboMay->qsMovMay2->Close();
        qrRepCarAboMay->qsMovMay2->ParamByName("FechaIni")->AsDateTime = dtFechaIni;
        qrRepCarAboMay->qsMovMay2->ParamByName("FechaFin")->AsDateTime = dtFechaFin;
        qrRepCarAboMay->qsMovMay2->Open();

        qrRepCarAboMay->Preview();
    }
}
//----------------------------------------------------------------------------
__fastcall TqrRepCarAboMay::TqrRepCarAboMay(TComponent* Owner)
    : TQuickRep(Owner)
{
}
//----------------------------------------------------------------------------