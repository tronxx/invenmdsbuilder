//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_pideseries.h"
#include "dmod.h"
#include "Frme_datosmarca.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrame_pideseries *Frame_pideseries;
//---------------------------------------------------------------------------
__fastcall TFrame_pideseries::TFrame_pideseries(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_pideseries::nueva_serieExecute(TObject *Sender)
{
   lst_series->Items->Add(edt_serie->Text.Trim());
}
//---------------------------------------------------------------------------

void __fastcall TFrame_pideseries::elimina_serieExecute(TObject *Sender)
{
   if(lst_series->Items->Count) lst_series->Items->Delete();

}
//---------------------------------------------------------------------------
