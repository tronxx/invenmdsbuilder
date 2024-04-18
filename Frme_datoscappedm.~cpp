//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datoscappedm.h"
#include "dmod.h"
#include "numapal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datoscappedm *Frame_datoscappedm;
//---------------------------------------------------------------------------
__fastcall TFrame_datoscappedm::TFrame_datoscappedm(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datoscappedm::inicializa(String mitipomov_z)
{
  int idpermis_z=0;
  String perio_z; 
  tipomov_z = mitipomov_z;
  tipo_z = mitipomov_z;
  cia_z = dm->cia_z;
  TLocateOptions Opts;
  Opts.Clear();
  qry_Almacen->Close();
  //qry_Almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_Almacen->Open();
  qry_mayorista->Close();
  qry_mayorista->ParamByName("cia")->AsInteger = cia_z;
  qry_mayorista->Open();
  lkcmb_vendedr->KeyValue = qry_mayorista->FieldByName("codigo")->AsString;
  perio_z = PeriodoToString(dm->ahora());
  qry_Almacen->Locate("clave", perio_z, Opts);
  lkcmb_almacen->KeyValue = qry_Almacen->FieldByName("clave")->AsString;
  date_fecha->Date    = dm->ahora();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscappedm::nuevo()
{
  String alm_z;
  int nument_z=0;
  alm_z = qry_Almacen->FieldByName("clave")->AsString;
  nument_z = dm->sigte_entrada(alm_z, tipo_z, nument_z, ULTIMO);
  nument_z++;
  edt_numero->Value= nument_z;
  date_fecha->Date = dm->ahora();
  date_fecha->MaxDate = date_fecha->Date;
  date_fecha->MinDate = date_fecha->Date - 20;
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datoscappedm::lkcmb_almacenExit(TObject *Sender)
{
  if(accion_z == NUEVO) nuevo();
}
//---------------------------------------------------------------------------

