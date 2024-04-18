//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Login.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TfrmdlgLogin *frmdlgLogin;
//---------------------------------------------------------------------------
bool __fastcall RegistroClave(TForm *Padre, String &sInicialesp)
{
    bool bResult = false;
    try
    {
        frmdlgLogin = new TfrmdlgLogin(Padre);
        frmdlgLogin->ShowModal();
        if (frmdlgLogin->bOk ) {
           bResult = true;
           sInicialesp = frmdlgLogin->sIniciales;
        }
        delete frmdlgLogin;
    }
    catch(...)
    {
       delete frmdlgLogin;
    }
    return bResult;

}
//---------------------------------------------------------------------------
__fastcall TfrmdlgLogin::TfrmdlgLogin(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmdlgLogin::btnAceptarClick(TObject *Sender)
{

    int iPermiso=0;
    qsUsarios->Close();
    qsUsarios->ParamByName("Nombre"  )->AsString  = edtLogin->Text.Trim();
    qsUsarios->ParamByName("Password")->AsString  = edtPassword->Text.Trim();
    qsUsarios->ParamByName("Cia"     )->AsInteger = dm->cia_z;
    qsUsarios->Open();
    if (!qsUsarios->IsEmpty() ) {
        sIniciales = qsUsarios->FieldByName("Iniciales")->AsString;

        if (qsUsarios->FieldByName("Maestro")->AsString == "S")
           iPermiso = 99;
        else {
            qsPermiUsar->Close();
            qsPermiUsar->ParamByName("IdUse")->AsInteger = qsUsarios->FieldByName("IdUse")->AsInteger;
            qsPermiUsar->ParamByName("Cia"  )->AsInteger = qsUsarios->FieldByName("Cia"  )->AsInteger;
            qsPermiUsar->Open();
            if (!qsPermiUsar->IsEmpty() )
                 iPermiso = qsPermiUsar->FieldByName("IdPermis")->AsInteger;
            else iPermiso = 0;
        }
        if (iPermiso == 0) {
           AnsiString sMsg="";
           sMsg = "LO SIENTO " + edtLogin->Text.Trim() + " NO TIENE ACCESO !!";
           Application->MessageBox(sMsg.c_str(), "Mensaje", MB_OK | MB_ICONWARNING);
           edtLogin->SetFocus();
           return;
        }

    }else {
       Application->MessageBox("NO EXISTE EL USUARIO !!", "Usuario", MB_OK | MB_ICONQUESTION);
       edtLogin->SetFocus();
       return;
    }
    bOk = true;
    Close();
}
//---------------------------------------------------------------------------
void __fastcall TfrmdlgLogin::btnCancelarClick(TObject *Sender)
{
    bOk = false;
    Close();    
}
//---------------------------------------------------------------------------
void __fastcall TfrmdlgLogin::edtPasswordKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       TfrmdlgLogin::btnAceptarClick(this);
    }
}
//---------------------------------------------------------------------------
