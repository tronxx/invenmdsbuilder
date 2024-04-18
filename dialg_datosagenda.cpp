//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "dialg_datosagenda.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBELib"
#pragma resource "*.dfm"
#include "dmod.h"
Tdlg_datosagenda *dlg_datosagenda;
//---------------------------------------------------------------------------
__fastcall Tdlg_datosagenda::Tdlg_datosagenda(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosagenda::FormCreate(TObject *Sender)
{
  TIniFile *ini;
  String  ubica_z, config_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z );
  ubica_z =  ini->ReadString( "Agenda_Embarques", "Ubica", "EMB" );
  delete ini;

  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = dm->cia_z;
  qry_almacen->Open();
  if (!qry_almacen->IsEmpty()) {
    lkcmb_ubica->KeyValue = ubica_z;
  }
  date_fecha->Date = dm->ahora();
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosagenda::BitBtn1Click(TObject *Sender)
{
  TIniFile *ini;
  String  ubica_z, config_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z );
  ubica_z = qry_almacen->FieldByName("ubica")->AsString;
  ini->WriteString( "Agenda_Embarques", "Ubica", ubica_z );
  delete ini;
}
//---------------------------------------------------------------------------

