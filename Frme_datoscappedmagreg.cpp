#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "dmod.h"
#include "numapal.h"
#include "situaciones.h"
#include "imprigra.h"
#include "impre.h"
#include "Frme_datoscappedmagrega.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datoscappedmagrega *Frame_datoscappedmagrega;
//---------------------------------------------------------------------------
__fastcall TFrame_datoscappedmagrega::TFrame_datoscappedmagrega(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datoscappedmagrega::edt_codigoKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{

    if(Key == VK_RETURN) {
         if(edt_codigo->Text.UpperCase() != "AUXILIAR") {
           busca_cod(edt_codigo->Text.Trim());
           if(qry_inven->IsEmpty()) {
             qry_buscod->Close();
             qry_buscod->ParamByName("codigo")->AsString = edt_codigo->Text.Trim() + "%%";
             qry_buscod->ParamByName("cia")->AsInteger = cia_z;
             qry_buscod->Open();
             if(qry_buscod->IsEmpty())
                Application->MessageBox("No existe ningun registro", "C�digo Inexistente", MB_ICONQUESTION);
             else {
                 lkcmb_codigos->Left=edt_codigo->Left;
                 lkcmb_codigos->Top=edt_codigo->Top;
                 lkcmb_codigos->Width=edt_codigo->Width;
                 lkcmb_codigos->Visible=true;
                 lkcmb_codigos->KeyValue=qry_buscod->FieldByName("codigo")->AsString;
                 edt_codigo->Visible=false;
                 lkcmb_codigos->DropDown();
                 //ActiveControl=lkcmb_codigos;
               }
           }
         }
      }
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datoscappedmagrega::lkcmb_codigosExit(
      TObject *Sender)
{
  lkcmb_codigos->Visible=false;
  edt_codigo->Visible=true;
  busca_cod(qry_buscod->FieldByName("codigo")->AsString);
  edt_descri->Text = qry_buscod->FieldByName("descri")->AsString;
  edt_descri->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datoscappedmagrega::lkcmb_codigosKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
   if (Key == VK_RETURN){
      edt_codigo->Text = lkcmb_codigos->Text.Trim();
      lkcmb_codigos->Visible=false;
    }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscappedmagrega::busca_cod(String codigo_z)
{
  edt_codigo->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(!qry_inven->IsEmpty()) {
    edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
    edt_costou->Value = calcu_prvta();
  }
}
//---------------------------------------------------------------------------

double __fastcall TFrame_datoscappedmagrega::calcu_prvta()
{
  double mubmds_z=0, costo_z=0, preciou_z=0, costos_z=0, piva_z =0;
  String codigo_z="";
  if(qry_inven->State == dsInactive) return(0);
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  preciou_z = qry_inven->FieldByName("precio")->AsFloat;
  piva_z = (qry_inven->FieldByName("piva")->AsFloat / 100) + 1;
  costos_z = qry_inven->FieldByName("costos")->AsFloat;
  if(qry_inven->FieldByName("situacion")->AsString == "SUNTUARIO") {
    preciou_z=preciou_z / (0.6) * (0.64);
  } else {
    if (preciou_z != 0)
      mubmds_z =  (1 - ( costos_z * piva_z / preciou_z ) ) * 100;
    if (mubmds_z >= 47) preciou_z=preciou_z * 0.60 * piva_z;
    else if (mubmds_z >= 45) preciou_z=preciou_z * 0.61 * piva_z;
    else if (mubmds_z >= 43) preciou_z=preciou_z * 0.62 * piva_z;
    else if (mubmds_z >= 41) preciou_z=preciou_z * 0.63 * piva_z;
    else if (mubmds_z >= 39) preciou_z=preciou_z * 0.64 * piva_z;
    else preciou_z = costos_z / 0.94;
  }
  return(Redondea(preciou_z, 100));
}
//---------------------------------------------------------------------------
