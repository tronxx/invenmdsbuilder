//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_login.h"
#include <dir.h>
#include <numapal.h>
#include <inifiles.hpp>
#include "About.h"
#include "Frm_selecdb.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_login *Form_login;
//---------------------------------------------------------------------------
__fastcall TForm_login::TForm_login(TComponent* Owner)
        : TForm(Owner)

{
   TIniFile *ini;
   char direc_z[255];
   getcurdir(0, direc_z);
   String  basedato_z, config_z, strdir_z;
   strdir_z = direc_z;
   revisar_instalacion();
   config_z = "\\"+strdir_z+"\\"+ExtractFileName(ChangeFileExt( Application->ExeName, ".INI"));
   ini = new TIniFile(config_z );
   basedato_z =  ini->ReadString( "DataBase", "DataBase", "Sin BD" );
   delete ini;
   if(dbmanvehi->Connected) dbmanvehi->Connected = false;
   //Application->MessageBox(("Base datos:"+basedato_z+"\nConfig:"+config_z+"\nDirectorio:"+strdir_z).c_str(), "Config", 0);
   dbmanvehi->AliasName = basedato_z;
   try {
     dbmanvehi->Connected = true;
   }  catch (Exception &E)
   {
     Application->MessageBox(("Base datos:"+basedato_z+
       "\nConfig:"+config_z+"\nDirectorio:"+strdir_z+
       "\nNo pude conectarme a la base de datos:\n"+E.Message).c_str(), "Error", MB_ICONEXCLAMATION);
     TForm_selecbd *Form_selecbd = new TForm_selecbd (this);
     Form_selecbd->ShowModal();
     Application->MessageBox("Ahora se terminará el programa, Intentelo de nuevo por Favor",
       "Base de datos Selccionada", MB_ICONEXCLAMATION);
     exit(-1);
   }

}
//---------------------------------------------------------------------------
void __fastcall TForm_login::btn_aceptarClick(TObject *Sender)
{
  qry_login->Close();
  qry_login->ParamByName("login")->AsString = edt_usuario->Text;
  qry_login->ParamByName("clave")->AsString = edt_passwd->Text;
  qry_login->Open();
  if(!qry_login->IsEmpty()) {
    idusuario_z=qry_login->FieldByName("idusuario")->AsInteger;
    usermaster_z=qry_login->FieldByName("maestro")->AsString;
    iniciales_z=qry_login->FieldByName("iniciales")->AsString;
    userpol_z=qry_login->FieldByName("numpol")->AsString;
    login_z = qry_login->FieldByName("login")->AsString;
    lbl_status->Caption="Usuario:"+qry_login->FieldByName("nombre")->AsString;
    ModalResult=mrOk;
  } else {
    lbl_status->Caption="Usuario Incorrecto, Intente de nuevo por favor...";
    ActiveControl=edt_usuario;
    ModalResult=mrNone;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_login::FormCreate(TObject *Sender)
{
    ok_z=false;
}
//---------------------------------------------------------------------------
void __fastcall TForm_login::Button1Click(TObject *Sender)
{
  ModalResult=mrOk;
}
//---------------------------------------------------------------------------
void __fastcall TForm_login::edt_usuarioChange(TObject *Sender)
{
  btn_aceptar->Tag=0;
}
//---------------------------------------------------------------------------

bool __fastcall TForm_login::revisar_instalacion()
{
   TDate hoy_z, ayer_z, fecreg_z;
   hoy_z = Date();
   bool registrado_z = true;
   int dias_z = 0;
   // Lo bloqueo para que ni lo lea ni nada
   String regkey_z, prodid_z="", prodcrypt_z, cryptleido_z="", strayer_z, strfecreg_z;
   String ubicaregedit_z;
   ubicaregedit_z = "SOFTWARE\\Microsoft\\Windows NT\\CurrentVersion";
   prodid_z = buscar_regedit(HKEY_LOCAL_MACHINE, ubicaregedit_z, "ProductId", "0");
   if( prodid_z == "0" ) {
     ubicaregedit_z = "SOFTWARE\\Microsoft\\Windows\\CurrentVersion";
     prodid_z = buscar_regedit(HKEY_LOCAL_MACHINE, ubicaregedit_z, "ProductId", "0");
   }

   prodcrypt_z = CadToCadHex(Encriptar(prodid_z.c_str()));
//   Application->MessageBox(("Id:" + prodid_z +"\n Key:"+prodcrypt_z).c_str(), "ProductId", 0);
   regkey_z = "SOFTWARE\\MiscroSoft\\Juegos\\Solitario\\7976687378866978\\" + prodid_z + "\\Instalacion";
   cryptleido_z = buscar_regedit(HKEY_LOCAL_MACHINE, regkey_z, "ProductId", "0");
   registrado_z = true;
   //registrado_z = ( cryptleido_z == prodcrypt_z);
   if (!registrado_z)
     registrado_z = ( cryptleido_z == CadToCadHex(prodcrypt_z));
   if (!registrado_z)
     registrado_z = ( cryptleido_z == CadToCadHex(CadReverse(prodid_z)) );

   if ( !registrado_z) {
     strayer_z = buscar_regedit(HKEY_LOCAL_MACHINE, "SOFTWARE\\BastoSoft\\Oldinven\\Instalacion\\Ayer", "Ayer", FormatDateTime("yyyy/mm/dd", Now() -1));
     //Application->MessageBox( strayer_z.c_str(), "Ayer", MB_ICONEXCLAMATION);

     ayer_z = EncodeDate(
       (Word)StrToInt(strayer_z.SubString(1, 4)),
       (Word)StrToInt(strayer_z.SubString(6, 2)),
       (Word)StrToInt(strayer_z.SubString(9, 2))
     );
     if ( ayer_z > hoy_z ) {
        dias_z = 100;
     } else {
       strfecreg_z = buscar_regedit(HKEY_LOCAL_MACHINE, "SOFTWARE\\BastoSoft\\Oldinven\\Instalacion\\Instalacion", "Instalado", FormatDateTime("yyyy/mm/dd", Now()));
       //Application->MessageBox( strfecreg_z.c_str(), "Fecreg", MB_ICONEXCLAMATION);
       fecreg_z = EncodeDate(
         (Word)StrToInt(strfecreg_z.SubString(1, 4)),
         (Word)StrToInt(strfecreg_z.SubString(6, 2)),
         (Word) StrToInt(strfecreg_z.SubString(9, 2))
       );
       dias_z = hoy_z - fecreg_z;
       //Application->MessageBox(("La Instalacion tiene:" + IntToStr(dias_z)).c_str(), "Instalacion", 0);
     }
     if ( dias_z > 30) {
         Application->MessageBox( ("Debe Registrar el Producto: tron_xx@hotmail.com con Clave:" + prodid_z).c_str(), "Tiempo Vencido", MB_ICONEXCLAMATION);
         TAboutBox *AboutBox;
         AboutBox = new TAboutBox (this);
         AboutBox->ShowModal();
         exit(-1);
     } else {
       lbl_status->Caption = "Quedan:" + IntToStr(30 - dias_z) + " Para Activar";
     }
   } else {
     lbl_status->Caption = "Registro Activado correctamente";
   }
   return (registrado_z);
}
//---------------------------------------------------------------------------


