//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_impriarch.h"
#include <inifiles.hpp>
#include "Main.h"
#include "dmod.h"
#include "dlg_seltipoimp.h"
#include "situaciones.h"
#include "imprigra.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_impriarch *Form_impriarch;
//---------------------------------------------------------------------------
__fastcall TForm_impriarch::TForm_impriarch(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_impriarch::btn_explorarClick(TObject *Sender)
{
  MainForm->OpenDialog->DefaultExt = "Archivos de texto p/Impresion";
  MainForm->OpenDialog->FileName = "*.tex; *.txt";
  if (MainForm->OpenDialog->Execute())
    edt_nomarch->Text = MainForm->OpenDialog->FileName;
}
//---------------------------------------------------------------------------
void __fastcall TForm_impriarch::btn_propiedadesClick(TObject *Sender)
{
  Tdialg_seltipoimp *dialg_seltipoimp = new Tdialg_seltipoimp (this);
  dialg_seltipoimp->ShowModal();
  String tipoimp_z="";
   TIniFile *ini;
   ini = new TIniFile(dm->config_z );
   tipoimp_z =  ini->ReadString( "Impresora", "Tipo", "Matriz" );
   dm->rutaimp_z =  ini->ReadString( "Impresora", "Ruta", "lpt" );
   delete ini;
   if(tipoimp_z == "Matriz")
     dm->tipoimp_z = IMPRESORA_MATRIZ;
   else
     dm->tipoimp_z = IMPRESORA_GRAFICA;
}
//---------------------------------------------------------------------------

void __fastcall TForm_impriarch::btn_imprimirClick(TObject *Sender)
{
  dm->manda_impresion(edt_nomarch->Text);
}
//---------------------------------------------------------------------------


void __fastcall TForm_impriarch::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

