//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_agregarelac.h"
#include "Frm_reltablas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
#include "dmod.h"
#include "situaciones.h"
TFrame_agregarelac *Frame_agregarelac;
//---------------------------------------------------------------------------
__fastcall TFrame_agregarelac::TFrame_agregarelac(TComponent* Owner)
        : TFrame(Owner)
{

  qry_tablas->Close();
  qry_tablas->Tag = NO_REFRESH;
  qry_tablas->Open();
  qry_tablas->Tag = SI_REFRESH;

 

}
//---------------------------------------------------------------------------
void __fastcall TFrame_agregarelac::qry_tablasAfterScroll(
      TDataSet *DataSet)
{

  if (qry_tablas->Tag == NO_REFRESH) return;

  int idtablarel_z;
  tabla_z = qry_tablas->FieldByName("tabla")->AsString;
  idtablarel_z = qry_tablas->FieldByName("idtabla")->AsInteger;
  edt_idrel->Text = idtablarel_z;

  
  lista_colum->Items->Clear();
  if( tabla_z == ""){
     Application->MessageBox("No Existe Ninguna Tabla", "Error", MB_OK | MB_ICONERROR);
     return;
  }else{

    sql_z = "select * from " + tabla_z;
    sql_z += " where rownum < 1";
    qry_columns->Close();
    qry_columns->SQL->Text = sql_z;
    ver_z = sql_z;
    qry_columns->Open();

    for(int ii_z = 0; ii_z < qry_columns->FieldCount; ii_z++) {
      columna_z = qry_columns->Fields->Fields[ii_z]->FieldName.UpperCase();
      lista_colum->Items->Add (columna_z);

    }

    sql_z = "";
  }

}
//---------------------------------------------------------------------------

