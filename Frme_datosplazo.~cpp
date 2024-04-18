//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosplazo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datosplazo *Frame_datosplazo;
//---------------------------------------------------------------------------
__fastcall TFrame_datosplazo::TFrame_datosplazo(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosplazo::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
     busca_cod(edt_codigo->Text.Trim());
     if(qry_inven->IsEmpty()) {
       qry_buscod->Close();
       qry_buscod->ParamByName("codigo")->AsString = edt_codigo->Text.Trim() + "%%";
       qry_buscod->ParamByName("cia")->AsInteger = cia_z;
       qry_buscod->Open();
       if(qry_buscod->IsEmpty())
          Application->MessageBox("No existe ningun registro", "Código Inexistente", MB_ICONQUESTION);
       else {
           lkcmb_codigos->Left=edt_codigo->Left;
           lkcmb_codigos->Top=edt_codigo->Top;
           lkcmb_codigos->Width=edt_codigo->Width;
           lkcmb_codigos->Visible=true;
           lkcmb_codigos->KeyValue=qry_buscod->FieldByName("codigo")->AsString;
           edt_codigo->Visible=false;
           lkcmb_codigos->DropDown();
           lkcmb_codigos->SetFocus();
         }
      }
   }

}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosplazo::lkcmb_codigosExit(TObject *Sender)
{
  lkcmb_codigos->Visible=false;
  edt_codigo->Visible=true;
  busca_cod(qry_buscod->FieldByName("codigo")->AsString);
  edt_codigo->SetFocus();

}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosplazo::lkcmb_codigosKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_RETURN){
    edt_codigo->Text = lkcmb_codigos->Text.Trim();
    lkcmb_codigos->Visible=false;
    edt_plazomax->SetFocus();
  }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosplazo::busca_cod(String codigo_z)
{
  edt_codigo->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(!qry_inven->IsEmpty()) edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
}
//---------------------------------------------------------------------------

