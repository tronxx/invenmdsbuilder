//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datossabanavta.h"
#include "dmod.h"
#include "situaciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datossabanavta *Frame_datossabanavta;
//---------------------------------------------------------------------------
__fastcall TFrame_datossabanavta::TFrame_datossabanavta(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datossabanavta::inicializa(String mitipo_z)
{
  int idpermis_z=0;
  tipo_z = mitipo_z;
  cia_z = dm->cia_z;
  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_almacen->Open();
  lkcmb_almacen->KeyValue = qry_almacen->FieldByName("clave")->AsString;
  date_fecha->Date    = dm->ahora();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datossabanavta::nuevo()
{
  String alm_z;
  int nument_z=0;
  alm_z = qry_almacen->FieldByName("clave")->AsString;
  nument_z = dm->sigte_entrada(alm_z, tipo_z, nument_z, ULTIMO);
  nument_z++;
  edt_numero->Value= nument_z;
  date_fecha->Date = dm->ahora();
  date_fecha->MaxDate = date_fecha->Date;
  date_fecha->MinDate = date_fecha->Date - 20;
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datossabanavta::lkcmb_almacenExit(TObject *Sender)
{
  if(accion_z == NUEVO) nuevo();
}
//---------------------------------------------------------------------------
