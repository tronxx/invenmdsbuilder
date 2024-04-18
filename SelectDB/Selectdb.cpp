//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>
#include <dir.h>
#include "Selectdb.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "RzBorder"
#pragma link "RzButton"
#pragma link "RzCmboBx"
#pragma link "RzLabel"
#pragma resource "*.dfm"
TfrmSelecciondb *frmSelecciondb;
//---------------------------------------------------------------------------
__fastcall TfrmSelecciondb::TfrmSelecciondb(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelecciondb::btnCerrarClick(TObject *Sender)
{
    exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelecciondb::btnAceptarClick(TObject *Sender)
{
   char direc_z[200];
   getcurdir(0, direc_z);
   String  config_z, strdir_z;
   strdir_z = direc_z;
   config_z = "\\"+strdir_z+"\\OLDINVEN.INI";

   TIniFile *ini;
   ini = new TIniFile(config_z);
   if (cmbBasedatos->ItemIndex == 0)
      ini->WriteString( "DataBase", "DataBase", "ibinven" );
   else if (cmbBasedatos->ItemIndex == 1)
      ini->WriteString( "DataBase", "DataBase", "inven" );
   else ini->WriteString( "DataBase", "DataBase", "sindb" );
   delete ini;
   exit(0);
}
//---------------------------------------------------------------------------
void __fastcall TfrmSelecciondb::FormShow(TObject *Sender)
{
   /*
   char direc_z[200];
   getcurdir(0, direc_z);
   String  config_z, strdir_z;
   strdir_z = direc_z;
   config_z = "\\"+strdir_z+"\\OLDINVEN.INI";

   TIniFile *ini;
   ini = new TIniFile(config_z);
   ini->ReadString( "DataBase", "Local", "Sin BD" );
   */
   

}
//---------------------------------------------------------------------------
