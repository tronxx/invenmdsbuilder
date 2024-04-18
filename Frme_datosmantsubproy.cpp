//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosmantsubproy.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma resource "*.dfm"
TFrame_datosmantsubproy *Frame_datosmantsubproy;
//---------------------------------------------------------------------------
__fastcall TFrame_datosmantsubproy::TFrame_datosmantsubproy(TComponent* Owner)
        : TFrame(Owner)
{
  cmb_tipo->ItemIndex = 0;
}
//---------------------------------------------------------------------------



int __fastcall TFrame_datosmantsubproy::busca_idtipo(String tipo_z)
{
  int iditem_z = 0;
  if(tipo_z == "C") iditem_z = 0;
  if(tipo_z == "V") iditem_z = 1;
  if(tipo_z == "F") iditem_z = 2;
  if(tipo_z == "E") iditem_z = 3;
  if(tipo_z == "I") iditem_z = 4;
  if(tipo_z == "D") iditem_z = 5;
  if(tipo_z == "L") iditem_z = 6;
  if(tipo_z == "M") iditem_z = 7;
  if(tipo_z == "N") iditem_z = 8;
  return (iditem_z);
}
//---------------------------------------------------------------------------

