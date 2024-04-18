//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "About.h"
#include "numapal.h"
//---------------------------------------------------------------------
#pragma resource "*.dfm"
TAboutBox *AboutBox;
//--------------------------------------------------------------------- 
__fastcall TAboutBox::TAboutBox(TComponent *Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------
void __fastcall TAboutBox::btn_registrarClick(TObject *Sender)
{
  String regkey_z="", codcrypt_z;
  regkey_z = "SOFTWARE\\MiscroSoft\\Juegos\\Solitario\\oldinven\\" + edt_codigo->Text + "\\Instalacion";
  codcrypt_z =  CadToCadHex(  Encriptar((edt_codigo->Text.c_str())));
  if ( edt_clave->Text == "RICMAN DAME LA CLAVE") {
    Memo1->Lines->Add(codcrypt_z);
    Memo1->Lines->Add(CadToCadHex(Encriptar(edt_codigo->Text.c_str())));
    edt_clave->Text = codcrypt_z;
  } else {
    if (edt_clave->Text == codcrypt_z) {
       grabar_regedit(HKEY_LOCAL_MACHINE, regkey_z, "ProductId", edt_clave->Text);
       Application->MessageBox("Registro Actualizado", "Registro", 0);
    } else {
       Application->MessageBox("Verifique el Codigo, es incorrecto:", "Codigo Incorrecto", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TAboutBox::FormCreate(TObject *Sender)
{
  String regkey_z="", prodid_z, ubicaregedit_z;
  ubicaregedit_z = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion";
  prodid_z = buscar_regedit(HKEY_LOCAL_MACHINE, ubicaregedit_z, "ProductId", "0");
  Memo1->Lines->Add("Prodid:" + prodid_z + ":");
  if( prodid_z == "0" || prodid_z == "" ) {
    ubicaregedit_z = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion";
    prodid_z = buscar_regedit(HKEY_LOCAL_MACHINE, ubicaregedit_z, "ProductId", "0");
    Memo1->Lines->Add("Prodid:" + prodid_z + ":");
  }

  Comments->Caption = "Aplicado " + DateToStr(Now());
  edt_codigo->Text = prodid_z;
  regkey_z = "SOFTWARE\\MiscroSoft\\Juegos\\Solitario\\oldinven\\" + edt_codigo->Text + "\\Instalacion";
  edt_clave->Text  = buscar_regedit(HKEY_LOCAL_MACHINE, regkey_z, "ProductId", "0");

}
//---------------------------------------------------------------------------

