//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datoscapentpro.h"
#include "dmod.h"
#include "situaciones.h"
#include "numapal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datoscapentpro *Frame_datoscapentpro;
//---------------------------------------------------------------------------
__fastcall TFrame_datoscapentpro::TFrame_datoscapentpro(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  qry_prove->Close();
  qry_prove->ParamByName("cia")->AsInteger = cia_z;
  qry_prove->Open();
  lkcmb_prove->KeyValue = qry_prove->FieldByName("codigo")->AsString;
  qry_planesp->Close();
  qry_planesp->ParamByName("cia")->AsInteger = cia_z;
  qry_planesp->Open();
  lkcmb_planp->KeyValue = qry_planesp->FieldByName("clave")->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapentpro::inicializa(String mitipo_z)
{
  int idpermis_z=0;
  tipo_z = mitipo_z;
  cia_z = dm->cia_z;
  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_almacen->Open();
  lkcmb_almacen->KeyValue = qry_almacen->FieldByName("clave")->AsString;
  date_fecha->Date    = dm->ahora();
  accion_z = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapentpro::nuevo()
{
  TQuery *qsSigte = new TQuery (this);
  String alm_z;
  int nument_z=0;
  alm_z = qry_almacen->FieldByName("clave")->AsString;
  qsSigte->DatabaseName = qry_almacen->DatabaseName;
  qsSigte->SQL->Text = "select max(numero) as numero from entradas where tipo = :TIPO and alm = :ALM and cia = :cia";
  qsSigte->ParamByName("tipo")->AsString = tipo_z;
  qsSigte->ParamByName("alm")->AsString = alm_z;
  qsSigte->ParamByName("cia")->AsInteger = cia_z;
  qsSigte->Open();
  if(!qsSigte->IsEmpty()) {
    nument_z = qsSigte->FieldByName("numero")->AsInteger;
  }
  nument_z++;
  edt_nument->Value= nument_z;
  delete qsSigte;
  date_fecha->Date = dm->ahora();
  date_fecha->MaxDate = date_fecha->Date;
  date_fecha->MinDate = date_fecha->Date - 20;
  edt_plazoExit(this);
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datoscapentpro::edt_numentExit(TObject *Sender)
{
    if(accion_z == NUEVO) nuevo();
}
//---------------------------------------------------------------------------

bool __fastcall TFrame_datoscapentpro::BuscarEntrada(int iNumero)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapentpro::ListarRenglon()
{
}
//---------------------------------------------------------------------------



void __fastcall TFrame_datoscapentpro::lkcmb_almacenExit(TObject *Sender)
{
  if(accion_z == NUEVO) nuevo();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapentpro::edt_plazoExit(TObject *Sender)
{
  int dias_z, letras_z;
  if(accion_z == NUEVO) {
    dias_z = edt_plazo->Value;
    letras_z = edt_nulets->Value;
    if(dias_z == 30) {
      date_prpago->Date = IncMonth(date_fecha->Date, 1);
      date_ulpago->Date = IncMonth(date_fecha->Date, letras_z);
    } else {
      date_prpago->Date = date_fecha->Date +  dias_z;
      date_ulpago->Date = date_fecha->Date + (dias_z * letras_z);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapentpro::qry_planespAfterScroll(
      TDataSet *DataSet)
{
  edt_nulets->Value = qry_planesp->FieldByName("numlet")->AsInteger;
  edt_plazo->Value  = qry_planesp->FieldByName("plazo")->AsInteger;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapentpro::date_prpagoExit(TObject *Sender)
{
  if(date_ulpago->Date < date_prpago->Date)
    date_ulpago->Date = date_prpago->Date; 
}
//---------------------------------------------------------------------------

