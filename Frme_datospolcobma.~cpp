//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datospolcobma.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datospolcobma *Frame_datospolcobma;
//---------------------------------------------------------------------------
__fastcall TFrame_datospolcobma::TFrame_datospolcobma(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  edt_usuario->Text = dm->login_z;
  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_almacen->Open();
  TLocateOptions Opts;
  Opts.Clear();
  if(!qry_almacen->Locate("clave", "AL", Opts)) qry_almacen->First();
  if(!qry_almacen->IsEmpty())
    lkcmb_almacen->KeyValue = qry_almacen->FieldByName("clave")->AsString;
  date_fecha->Date = dm->ahora();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datospolcobma::lkcmb_almacenExit(TObject *Sender)
{
  String sql_z, alm_z;
  int folio_z;
  alm_z = qry_almacen->FieldByName("clave")->AsString;
  sql_z = "select max(folio) as folio from polcob where alm = :ALM and cia = :CIA";
  dm->qry_sigid->Close();
  dm->qry_sigid->SQL->Text = sql_z;
  dm->qry_sigid->ParamByName("alm")->AsString = alm_z;
  dm->qry_sigid->ParamByName("cia")->AsInteger = cia_z;
  dm->qry_sigid->Open();
  if(!dm->qry_sigid->IsEmpty())
    folio_z = dm->qry_sigid->FieldByName("folio")->AsInteger;
  folio_z +=1;
  edt_folio->Value = folio_z;


}
//---------------------------------------------------------------------------

