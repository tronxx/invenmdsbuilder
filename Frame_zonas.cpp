//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frame_zonas.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrme_zonas *Frme_zonas;
//---------------------------------------------------------------------------
__fastcall TFrme_zonas::TFrme_zonas(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
