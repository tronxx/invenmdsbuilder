//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>
#include <dir.h>
#include "Frm_selecdb.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_selecbd *Form_selecbd;
//---------------------------------------------------------------------------
__fastcall TForm_selecbd::TForm_selecbd(TComponent* Owner)
    : TForm(Owner)
{
  odbclocal_z = "ibinven";
  odbclinux_z = "inven";
}
//---------------------------------------------------------------------------
void __fastcall TForm_selecbd::btnCerrarClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm_selecbd::btnAceptarClick(TObject *Sender)
{
   TIniFile *ini;
   char direc_z[200];
   getcurdir(0, direc_z);
   String  basedato_z, config_z, strdir_z;
   strdir_z = direc_z;
   config_z = "\\"+strdir_z+"\\"+ExtractFileName(ChangeFileExt( Application->ExeName, ".INI"));
   ini = new TIniFile(config_z);
   if (cmbBasedatos->ItemIndex == 0)
      ini->WriteString( "DataBase", "DataBase", odbclocal_z );
   else if (cmbBasedatos->ItemIndex == 1)
      ini->WriteString( "DataBase", "DataBase", odbclinux_z );
   else ini->WriteString( "DataBase", "DataBase", "sindb" );
   delete ini;
   Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_selecbd::FormCreate(TObject *Sender)
{
   TIniFile *ini;
   char direc_z[200];
   getcurdir(0, direc_z);
   String  basedato_z, config_z, strdir_z;
   strdir_z = direc_z;
   config_z = "\\"+strdir_z+"\\"+ExtractFileName(ChangeFileExt( Application->ExeName, ".INI"));
   ini = new TIniFile(config_z);
   basedato_z = ini->ReadString( "DataBase", "DataBase", odbclinux_z );
   if(basedato_z == odbclocal_z ) cmbBasedatos->ItemIndex = 0;
   if(basedato_z == odbclinux_z ) cmbBasedatos->ItemIndex = 1;
   delete ini;
}
//---------------------------------------------------------------------------

