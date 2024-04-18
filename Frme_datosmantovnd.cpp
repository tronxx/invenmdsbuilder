//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosmantovnd.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma resource "*.dfm"
TFrame_datosmantovnd *Frame_datosmantovnd;
//---------------------------------------------------------------------------
__fastcall TFrame_datosmantovnd::TFrame_datosmantovnd(TComponent* Owner)
        : TFrame(Owner)
{
  qry_ptovta->Close();
  qry_ptovta->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosmantovnd::cmb_statusChange(TObject *Sender)
{
  bool visible_z = false;
  if (cmb_status->ItemIndex == 0 ) {
    visible_z = false;
  } else {
    visible_z = true;
  }
  lbl_fecbaj->Visible = visible_z;
  date_fecbaj->Visible = visible_z;
}
//---------------------------------------------------------------------------

