//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma resource "*.dfm"
Tdlg_okcancel *dlg_okcancel;
//---------------------------------------------------------------------------
__fastcall Tdlg_okcancel::Tdlg_okcancel(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_okcancel::FormShow(TObject *Sender)
{
  int izq_z;
  izq_z = ( Width - ( btn_cancel->Width + btn_ok->Width + 30 )) / 2;
  btn_ok->Left = izq_z;
  btn_cancel->Left = izq_z + btn_ok->Width + 30;
}
//---------------------------------------------------------------------------


