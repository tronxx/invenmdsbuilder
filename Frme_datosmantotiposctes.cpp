//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Frme_datosmantotiposctes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma resource "*.dfm"
TFrame_datosmantotiposctes *Frame_datosmantotiposctes;
//---------------------------------------------------------------------------
__fastcall TFrame_datosmantotiposctes::TFrame_datosmantotiposctes(TComponent* Owner)
        : TFrame(Owner)
{
        qry_tipocar->Close();
        qry_tipocar->Open();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosmantotiposctes::asigna_tipo(String tipo_z)
{
  if(tipo_z == "CAT_PRODSAT") {
    lbl_tipocartera->Visible = false;
    lbl_remate->Visible = false;
    lkcmb_ptovta->Visible = false;
    cmb_remate->Visible = false;
    edt_ptovta->Width = edt_nombre->Width / 2;
    edt_ptovta->MaxLength = 20;
    lbl_nombre->Left = edt_ptovta->Left + edt_ptovta->Width + 4;
    lbl_nombre->Caption = "Descripción";
    edt_nombre->Left = lbl_nombre->Left  + lbl_nombre->Width + 4;
  }
  if(tipo_z == "CAT_USOCFDI") {
    lbl_tipocartera->Visible = false;
    lbl_remate->Visible = false;
    lkcmb_ptovta->Visible = false;
    cmb_remate->Visible = false;
    edt_ptovta->Width = edt_nombre->Width / 2;
    edt_ptovta->MaxLength = 20;
    lbl_nombre->Left = edt_ptovta->Left + edt_ptovta->Width + 4;
    lbl_nombre->Caption = "Descripción";
    edt_nombre->Left = lbl_nombre->Left  + lbl_nombre->Width + 4;
  }
  if(tipo_z == "CAT_REGIMEN") {
    lbl_tipocartera->Visible = false;
    lbl_remate->Visible = false;
    lkcmb_ptovta->Visible = false;
    cmb_remate->Visible = false;
    edt_ptovta->Width = edt_nombre->Width / 2;
    edt_ptovta->MaxLength = 20;
    lbl_nombre->Left = edt_ptovta->Left + edt_ptovta->Width + 4;
    lbl_nombre->Caption = "Descripción";
    edt_nombre->Left = lbl_nombre->Left  + lbl_nombre->Width + 4;
  }
}
//---------------------------------------------------------------------------

