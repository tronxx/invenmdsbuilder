//----------------------------------------------------------------------------
#include <vcl\vcl.h>
#pragma hdrstop

#include "RepEdoCtaMayoris.h"
#include "dmod.h"
//----------------------------------------------------------------------------
#pragma resource "*.dfm"
TqrRepEdoCtaMayoris *qrRepEdoCtaMayoris;
//----------------------------------------------------------------------------
void __fastcall ImpRepEdoCtaMayoris(AnsiString sCveMay, int icia)
{
    qrRepEdoCtaMayoris->qsCias->Close();
    qrRepEdoCtaMayoris->qsCias->ParamByName("cia")->AsInteger = icia;
    qrRepEdoCtaMayoris->qsCias->Open();
    AnsiString sCadena ="";
    sCadena = qrRepEdoCtaMayoris->qsCias->FieldByName("Dir")->AsString + " " ;
    sCadena += " Tels.: " + qrRepEdoCtaMayoris->qsCias->FieldByName("Tel")->AsString;
    sCadena += " Fax " + qrRepEdoCtaMayoris->qsCias->FieldByName("Fax")->AsString;
    sCadena += " RFC: " + qrRepEdoCtaMayoris->qsCias->FieldByName("RFC")->AsString;
    qrRepEdoCtaMayoris->qrlblEmpresa->Caption = qrRepEdoCtaMayoris->qsCias->FieldByName("NomFis")->AsString;
    qrRepEdoCtaMayoris->qrlblDirecc->Caption  = sCadena;

    qrRepEdoCtaMayoris->qsMayoris->Close();
    if (sCveMay == "") {
       AnsiString sql = "";
       sql = "select a.codigo as Mayoris, a.nombre, a.cia, (a.direc || ' ' || a.ciu || ' ' || a.rfc) as Direc,";
       sql += " (select sum(saldo) from movmay2 where mayoris = a.codigo and saldo > 0.05 and coa = 'C' and cia = a.cia) as Saldo";
       sql += " from mayoris a where a.cia = " + IntToStr(icia);
       sql += " and (select sum(saldo) from movmay2 where mayoris = a.codigo and saldo > 0 and coa = 'C' and cia = a.cia) > 0.05";
       qrRepEdoCtaMayoris->qsMayoris->SQL->Clear();
       qrRepEdoCtaMayoris->qsMayoris->SQL->Add(sql);
    } else {
       qrRepEdoCtaMayoris->qsMayoris->ParamByName("Codigo")->AsString = sCveMay;
       qrRepEdoCtaMayoris->qsMayoris->ParamByName("Cia"   )->AsInteger = icia;
    }
    qrRepEdoCtaMayoris->qsMayoris->Open();

    if ( !qrRepEdoCtaMayoris->qsMayoris->IsEmpty() ) {
        qrRepEdoCtaMayoris->qsPendPag->Close();
      //  qrRepEdoCtaMayoris->qsPendPag->ParamByName("Mayoris")->AsString  = qrRepEdoCtaMayoris->qsMayoris->FieldByName("Codigo")->AsString;
      //  qrRepEdoCtaMayoris->qsPendPag->ParamByName("Cia"    )->AsInteger = qrRepEdoCtaMayoris->qsMayoris->FieldByName("Cia"   )->AsInteger;
        qrRepEdoCtaMayoris->qsPendPag->Open();

        qrRepEdoCtaMayoris->Preview();
    }

}
//----------------------------------------------------------------------------
__fastcall TqrRepEdoCtaMayoris::TqrRepEdoCtaMayoris(TComponent* Owner)
    : TQuickRep(Owner)
{
}
//----------------------------------------------------------------------------