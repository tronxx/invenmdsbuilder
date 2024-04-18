//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "Frm_dlgcriterio.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_dlgcriterio *Form_dlgcriterio;
//---------------------------------------------------------------------------
__fastcall TForm_dlgcriterio::TForm_dlgcriterio(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_dlgcriterio::FormCreate(TObject *Sender)
{
  String config_z;
  TIniFile *ini;
  int busxlin_z=0, busxgpo_z=0, busxprove_z=0, busxprecio_z=0,
      busxexis_z=0;
  bool criteriobusxexis_z=true;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  busxlin_z = ini->ReadInteger("BUSQUEDAS", "BUSXLIN", 0);
  busxgpo_z = ini->ReadInteger("BUSQUEDAS", "BUSXGPO", 0);
  busxprove_z = ini->ReadInteger("BUSQUEDAS", "BUSXPROVE", 0);
  busxprecio_z = ini->ReadInteger("BUSQUEDAS", "BUSXPRECIO", 0);
  busxexis_z = ini->ReadInteger("BUSQUEDAS", "BUSXEXIS", 0);
  criteriobusxexis_z = ini->ReadBool("BUSQUEDAS", "HABILITADO", 0);
  cmb_linea->ItemIndex = busxlin_z;
  cmb_grupo->ItemIndex = busxgpo_z;
  cmb_prove->ItemIndex = busxprove_z;
  cmb_precio->ItemIndex = busxprecio_z;
  cmb_conexistencia->ItemIndex = busxexis_z;
  chk_existencia->Checked = criteriobusxexis_z;
  delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm_dlgcriterio::btn_okClick(TObject *Sender)
{
  String config_z;
  TIniFile *ini;
  int busxlin_z=0, busxgpo_z=0, busxprove_z=0, busxprecio_z=0, busxexis_z=0;
  bool criteriobusxexis_z=true;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  busxlin_z    = cmb_linea->ItemIndex;
  busxgpo_z    = cmb_grupo->ItemIndex;
  busxprove_z  = cmb_prove->ItemIndex;
  busxprecio_z = cmb_precio->ItemIndex;
  busxexis_z   = cmb_conexistencia->ItemIndex;
  criteriobusxexis_z = chk_existencia->Checked;
  ini->WriteInteger("BUSQUEDAS", "BUSXLIN", busxlin_z);
  ini->WriteInteger("BUSQUEDAS", "BUSXGPO", busxgpo_z);
  ini->WriteInteger("BUSQUEDAS", "BUSXPROVE", busxprove_z);
  ini->WriteInteger("BUSQUEDAS", "BUSXPRECIO", busxprecio_z);
  ini->WriteInteger("BUSQUEDAS", "BUSXEXIS", busxexis_z);
  ini->WriteBool("BUSQUEDAS", "HABILITADO", criteriobusxexis_z);
  delete ini;
}
//---------------------------------------------------------------------------

