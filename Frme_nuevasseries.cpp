//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_nuevasseries.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "AdvGrid"
#pragma resource "*.dfm"
TFrame_nuevasseries *Frame_nuevasseries;
//---------------------------------------------------------------------------
__fastcall TFrame_nuevasseries::TFrame_nuevasseries(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrame_nuevasseries::lst_seriesKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) agrega_serieExecute(Sender);
  if(Key == VK_DELETE) elimnar_serieExecute(Sender);
  if(Key == VK_F2)     modificar_serieExecute(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TFrame_nuevasseries::agrega_serieExecute(TObject *Sender)
{
  String serie_z, mensaje_z, titmsg_z;
  int item_z;
  serie_z = edt_serie->Text.Trim();
  mensaje_z = "Ya tiene " + IntToStr(numseries_z) + " Seguro de agregar otra serie ?";
  titmsg_z = "Número de Series completo";
  if(lst_series->Items->Count >= numseries_z) {
    if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) != IDYES)
       return;
  }
  item_z = lst_series->Items->IndexOf(serie_z);
  if(item_z != -1) {
     mensaje_z = "Ya existe la serie: " + serie_z + " Seguro de agregar ?";
     titmsg_z = "Series Duplicada";
     if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) != IDYES)
        return;
  }
  lst_series->Items->Add(serie_z);
}
//---------------------------------------------------------------------------
void __fastcall TFrame_nuevasseries::elimnar_serieExecute(TObject *Sender)
{
  String serie_z, mensaje_z, titmsg_z;
  int item_z;
  if(lst_series->Items->Count) {
    item_z = lst_series->ItemIndex;
    serie_z = lst_series->Items->Strings[item_z];
    mensaje_z = " Seguro de eliminar esta serie:" + serie_z + " ?";
    titmsg_z = "Eliminar Serie";

    if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES)
      lst_series->Items->Delete(item_z);
  }

}
//---------------------------------------------------------------------------


void __fastcall TFrame_nuevasseries::modificar_serieExecute(
      TObject *Sender)
{
  String antserie_z, serie_z, mensaje_z, titmsg_z;
  int item_z;
  if(lst_series->Items->Count) {
    serie_z = edt_serie->Text.Trim();
    item_z = lst_series->ItemIndex;
    antserie_z = lst_series->Items->Strings[item_z];
    mensaje_z = "Seguro de Cambiar la serie" + antserie_z + " por esta otra \nserie:" + serie_z;
    titmsg_z = "Cambio de Serie";
    if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES)
      lst_series->Items->Strings[item_z] = serie_z;
  }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_nuevasseries::edt_serieKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) agrega_serieExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_nuevasseries::cargar_series_vendidas()
{
  cargar_series_vendidas_x_anu("ACTUAL");
}
//---------------------------------------------------------------------------

void __fastcall TFrame_nuevasseries::cargar_series_vendidas_x_anu(String queanu_z)
{
  String nombreparam_z, sql_z;
  int renglones_z,
  COL_ALM               = 1,
  COL_PTVTA             = 2,
  COL_FOLIO             = 3,
  COL_SERIE             = 4,
  COL_FECHASAL          = 5,
  COL_CLIENTE           = 6,
  paso_z, jj_z, ii_z, tope_z;
  sql_z = "select codigo, almac, folio, serie, compro, concepto, fechasal, ptvta \
        from movart a join conceps b on a.compro = b.ncon \
        where a.codigo = :CODIGO and salio = 'S' and salepor = 20 \
        and ptvta = :PTOVTA order by fechasal";
  TQuery *qry_seriesvendidas = new TQuery (this);
  qry_seriesvendidas->Close();
  qry_seriesvendidas->SQL->Text = sql_z;
  sgrd_series->RowCount = 2;
  sgrd_series->ClearRows(1,2);
  ii_z = 1;
  tope_z = 2;
  // Solo voy a checar anuanter si la BD es diferente
  //if (dm->bdanuanter_z != dm->basedato_z) tope_z = 2;
  qry_seriesvendidas->Close();
  if( queanu_z == "ACTUAL") {
    qry_seriesvendidas->DatabaseName = dm->manvehi->Name;
  }
  if( queanu_z == "ANTER") {
    if (dm->bdanuanter_z == dm->basedato_z) {
      Application->MessageBox("No ha definido la Base de datos anu anterior", "No definido Anu anter", MB_ICONEXCLAMATION);
      return;
    }
    dm->conecta_db_anuanter();
    qry_seriesvendidas = qry_seriesanuanter;
    //qry_seriesvendidas->DatabaseName = dm->db_anuanter->Name;
  }
  for(jj_z=0; jj_z < qry_seriesvendidas->Params->Count; jj_z++) {
    nombreparam_z = qry_seriesvendidas->Params->Items[jj_z]->Name.UpperCase();
    if( nombreparam_z == "CODIGO") {
      qry_seriesvendidas->Params->Items[jj_z]->AsString = codigo_z;
    }
    if( nombreparam_z == "PTOVTA") {
      qry_seriesvendidas->Params->Items[jj_z]->AsString = ptovta_z;
    }
  }
  qry_seriesvendidas->Open();
  renglones_z = qry_seriesvendidas->RecordCount;
  sgrd_series->RowCount += renglones_z;
  for(qry_seriesvendidas->First(); !qry_seriesvendidas->Eof; qry_seriesvendidas->Next()) {
    sgrd_series->Cells[COL_ALM][ii_z] = qry_seriesvendidas->FieldByName("almac")->AsString;
    sgrd_series->Cells[COL_PTVTA][ii_z] = qry_seriesvendidas->FieldByName("ptvta")->AsString;
    sgrd_series->Cells[COL_FOLIO][ii_z] = FormatFloat("0", qry_seriesvendidas->FieldByName("folio")->AsFloat);
    sgrd_series->Cells[COL_SERIE][ii_z] = qry_seriesvendidas->FieldByName("serie")->AsString;
    sgrd_series->Cells[COL_FECHASAL][ii_z] = FormatDateTime("dd/mm/yyyy", qry_seriesvendidas->FieldByName("fechasal")->AsDateTime);
    sgrd_series->Cells[COL_CLIENTE][ii_z] = qry_seriesvendidas->FieldByName("concepto")->AsString;
    ii_z++;
  }
  if( queanu_z == "ANTER") {
    dm->desconecta_db_anuanter();
  }
}



void __fastcall TFrame_nuevasseries::sgrd_seriesSelectCell(TObject *Sender,
      int ACol, int ARow, bool &CanSelect)
{
  String serie_z;
  int renglones_z,
  COL_ALM               = 1,
  COL_PTVTA             = 2,
  COL_FOLIO             = 3,
  COL_SERIE             = 4,
  COL_FECHASAL          = 5,
  COL_CLIENTE           = 6,
  ii_z=0;
  ii_z = ARow;
  serie_z = sgrd_series->Cells[COL_SERIE][ii_z];
  edt_serie->Text = serie_z;
  nomcli_z = sgrd_series->Cells[COL_CLIENTE][ii_z];

}
//---------------------------------------------------------------------------


void __fastcall TFrame_nuevasseries::cargar_series_anuantExecute(
      TObject *Sender)
{
  cargar_series_vendidas_x_anu("ANTER");
}
//---------------------------------------------------------------------------

void __fastcall TFrame_nuevasseries::cargar_series_actualesExecute(
      TObject *Sender)
{
  cargar_series_vendidas_x_anu("ACTUAL");
}
//---------------------------------------------------------------------------



void __fastcall TFrame_nuevasseries::sgrd_seriesDblClickCell(
      TObject *Sender, int aRow, int aCol)
{
  String serie_z;
  int renglones_z,
  COL_ALM               = 1,
  COL_PTVTA             = 2,
  COL_FOLIO             = 3,
  COL_SERIE             = 4,
  COL_FECHASAL          = 5,
  COL_CLIENTE           = 6,
  ii_z=0;
  ii_z = aRow;
  serie_z = sgrd_series->Cells[COL_SERIE][ii_z];
  edt_serie->Text = serie_z;
  lst_series->Items->Clear();
  lst_series->Items->Add(serie_z);
  nomcli_z = sgrd_series->Cells[COL_CLIENTE][ii_z];
}
//---------------------------------------------------------------------------

