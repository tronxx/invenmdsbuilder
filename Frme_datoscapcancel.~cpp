//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Frme_datoscapcancel.h"
#include "situaciones.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datoscapcancel *Frame_datoscapcancel;
//---------------------------------------------------------------------------
__fastcall TFrame_datoscapcancel::TFrame_datoscapcancel(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapcancel::inicializa(String mitipo_z)
{
  int idpermis_z=0;
  tipo_z = mitipo_z;
  cia_z = dm->cia_z;
  qry_Almacen->Close();
  qry_Almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_Almacen->Open();
  lkcmb_almacen->KeyValue = qry_Almacen->FieldByName("clave")->AsString;
  date_fecha->Date    = dm->ahora();
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datoscapcancel::nuevo()
{
  TQuery *qsSigte = new TQuery (this);
  String alm_z;
  int nument_z=0;
  alm_z = qry_Almacen->FieldByName("clave")->AsString;
  qsSigte->DatabaseName = qry_Almacen->DatabaseName;
  qsSigte->SQL->Text = "select max(numero) as numero from entradas where tipo = :TIPO and alm = :ALM and cia = :cia";
  qsSigte->ParamByName("tipo")->AsString = tipo_z;
  qsSigte->ParamByName("alm")->AsString = alm_z;
  qsSigte->ParamByName("cia")->AsInteger = cia_z;
  qsSigte->Open();
  if(!qsSigte->IsEmpty()) {
    nument_z = qsSigte->FieldByName("numero")->AsInteger;
  }
  nument_z++;
  edt_numero->Value= nument_z;
  delete qsSigte;
  date_fecha->Date = dm->ahora();
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datoscapcancel::lkcmb_almacenExit(TObject *Sender)
{
  if (modo_z == NUEVO) nuevo();
}
//---------------------------------------------------------------------------
