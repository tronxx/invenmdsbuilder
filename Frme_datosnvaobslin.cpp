//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosnvaobslin.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datosnvaobslin *Frame_datosnvaobslin;
//---------------------------------------------------------------------------
__fastcall TFrame_datosnvaobslin::TFrame_datosnvaobslin(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosnvaobslin::inicializa()
{
  qry_fonini->Close(); qry_fonini->Open();
  qry_fonfin->Close(); qry_fonfin->Open();
}
//---------------------------------------------------------------------------

