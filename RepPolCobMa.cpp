//----------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "RepPolCobMa.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
TqrRepPolCobMay *qrRepPolCobMay;
//----------------------------------------------------------------------------
void __fastcall ReporteCobranzaMayoristas(int iCia, String Almac, TDateTime dtFecha)
{
    qrRepPolCobMay->qsCias->Close();
    qrRepPolCobMay->qsCias->ParamByName("Cia")->AsInteger = iCia;
    qrRepPolCobMay->qsCias->Open();
    qrRepPolCobMay->qrlblEmpresa->Caption = qrRepPolCobMay->qsCias->FieldByName("NomFis")->AsString;
    AnsiString sCadena = "";
    sCadena = qrRepPolCobMay->qsCias->FieldByName("Dir")->AsString + " " + qrRepPolCobMay->qsCias->FieldByName("dir2")->AsString;
    sCadena += " RFC: " + qrRepPolCobMay->qsCias->FieldByName("RFC")->AsString + "   Tels.: " + qrRepPolCobMay->qsCias->FieldByName("Tel")->AsString + " Fax:" + qrRepPolCobMay->qsCias->FieldByName("Fax")->AsString;
    qrRepPolCobMay->qrlblDirecc->Caption = sCadena;

    qrRepPolCobMay->qsPoliza->Close();
    qrRepPolCobMay->qsPoliza->ParamByName("Alm"  )->AsString   = Almac;
    qrRepPolCobMay->qsPoliza->ParamByName("Fecha")->AsDateTime = dtFecha;
    qrRepPolCobMay->qsPoliza->ParamByName("Cia"  )->AsInteger  = iCia;
    qrRepPolCobMay->qsPoliza->Open();

    qrRepPolCobMay->qsClientes->Close();
    qrRepPolCobMay->qsClientes->ParamByName("Almac")->AsString   = Almac;
    qrRepPolCobMay->qsClientes->ParamByName("Fecha")->AsDateTime = dtFecha;
    qrRepPolCobMay->qsClientes->ParamByName("Cia"  )->AsInteger  = iCia;
    qrRepPolCobMay->qsClientes->Open();
    if (!qrRepPolCobMay->qsClientes->IsEmpty() ) {
        qrRepPolCobMay->qsRenPol->Close();
        qrRepPolCobMay->qsRenPol->Open();
    }

    qrRepPolCobMay->Preview();

}
//----------------------------------------------------------------------------
__fastcall TqrRepPolCobMay::TqrRepPolCobMay(TComponent* Owner)
    : TQuickRep(Owner)
{
}
//----------------------------------------------------------------------------