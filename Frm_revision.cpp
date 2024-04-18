//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_revision.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma resource "*.dfm"
TForm_revision *Form_revision;
//---------------------------------------------------------------------------
__fastcall TForm_revision::TForm_revision(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_revision::btn_revisaClick(TObject *Sender)
{
  String codigo_z, alm_z, entosal_z;
  int folio_z=0, ren_z=0, agrega_z=0;
  sgrd_pendtes->ClearRows(1,sgrd_pendtes->RowCount-1);
  sgrd_pendtes->RowCount=2;
  qry_revision->Close();
  qry_revision->ParamByName("fecini")->AsDateTime = date_fentini->Date;
  qry_revision->ParamByName("fecfin")->AsDateTime = date_fentfin->Date;
  qry_revision->Open();
  for(qry_revision->First(); !qry_revision->Eof; qry_revision->Next()) {
    entosal_z = qry_revision->FieldByName("entosal")->AsString;
    codigo_z =qry_revision->FieldByName("codinv")->AsString;
    alm_z =qry_revision->FieldByName("alm")->AsString;
    if(entosal_z == "E") {
       folio_z = qry_revision->FieldByName("folent")->AsInteger;
    } else if(entosal_z == "S") {
       folio_z = qry_revision->FieldByName("folsal")->AsInteger;
    } else {
       folio_z = qry_revision->FieldByName("folsal")->AsInteger;
       entosal_z = "S";
    }
    qry_movto->Close();
    qry_movto->ParamByName("codigo")->AsString = codigo_z;
    qry_movto->ParamByName("alm")->AsString = alm_z;
    qry_movto->ParamByName("folio")->AsInteger = folio_z;
    qry_movto->Open();
    agrega_z=0;
    if(qry_movto->IsEmpty()) {
      agrega_z = 1;
    } else {
      if(entosal_z == "S" && qry_movto->FieldByName("salio")->AsString != "S")
      agrega_z = 1;
    }
    if(agrega_z) {
      if(ren_z) sgrd_pendtes->RowCount++;
      ren_z = sgrd_pendtes->RowCount -1;
      sgrd_pendtes->Cells[0][ren_z] = qry_revision->FieldByName("tipo")->AsString;
      sgrd_pendtes->Cells[1][ren_z] = alm_z;
      sgrd_pendtes->Cells[2][ren_z] = qry_revision->FieldByName("numero")->AsInteger;
      sgrd_pendtes->Cells[3][ren_z] = codigo_z;
      sgrd_pendtes->Cells[4][ren_z] = folio_z;
      sgrd_pendtes->Cells[5][ren_z] = entosal_z;
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_revision::FormCreate(TObject *Sender)
{
  date_fentini->Date = Now();
  date_fentfin->Date = Now();
}
//---------------------------------------------------------------------------
void __fastcall TForm_revision::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------

