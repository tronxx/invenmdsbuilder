//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_importa.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "AdvGrid"
#pragma resource "*.dfm"
TFrame_importa *Frame_importa;
//---------------------------------------------------------------------------
__fastcall TFrame_importa::TFrame_importa(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrame_importa::buscar_archivoExecute(TObject *Sender)
{
  int ii_z=0;
  //OpenDialog1->Filter = "Archivos Delimitados por Tab(*.csv)|*.CSV|Archivos de Excel(*.xls)|*.XLS";
  OpenDialog1->Filter = "Ric Archivos Delimitados por Tab(*.csv)|*.CSV,*.TXT ";
  OpenDialog1->DefaultExt = "Archivos Delimitados por Tab";
  OpenDialog1->FileName = "*.csv; *.txt";
  OpenDialog1->FilterIndex = 1;
  if (OpenDialog1->Execute()) {
    edt_nomarch->Text = OpenDialog1->FileName;
    sgrd_datos->RowCount=2;
    sgrd_datos->ColCount=1;
    switch( OpenDialog1->FilterIndex) {
        case 1: sgrd_datos->Delimiter='\t'; sgrd_datos->LoadFromCSV(edt_nomarch->Text); break;
        case 2: sgrd_datos->LoadFromXLS(edt_nomarch->Text); break;
    }
    if(sgrd_datos->RowCount > 1) {
      sgrd_datos->FixedRows = 1;
      sgrd_datos->ColumnHeaders->Clear();
      for(ii_z = 0; ii_z < sgrd_datos->ColCount; ii_z++) {
        sgrd_datos->ColumnHeaders->Add(sgrd_datos->Cells[ii_z][0]);
      }
      //sgrd_datos->RemoveRows(0,1);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TFrame_importa::edt_nomarchKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
    sgrd_datos->RowCount=2;
    sgrd_datos->ColCount=1;
    sgrd_datos->Delimiter='\t';
    sgrd_datos->LoadFromCSV(edt_nomarch->Text);
  }
}
//---------------------------------------------------------------------------
