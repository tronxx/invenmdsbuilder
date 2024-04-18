//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "dmod.h"
#include "numapal.h"
#include "situaciones.h"
#include "imprigra.h"
#include "impre.h"
#include "dialg_busartic.h"

#include "Frme_datoscappedmagrnuevo.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datoscappedmagrnuevo *Frame_datoscappedmagrnuevo;
//---------------------------------------------------------------------------
__fastcall TFrame_datoscappedmagrnuevo::TFrame_datoscappedmagrnuevo(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscappedmagrnuevo::busca_cod(String codigo_z)
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

double __fastcall TFrame_datoscappedmagrnuevo::calcu_prvta()
{
  double mubmds_z=0, costo_z=0, preciou_z=0, costos_z=0,
    piva_z =0, factorprecio_z=0;
  String codigo_z="", gpoesp_z="", empaqe_z = "", prove_z;
  if(qry_inven->State == dsInactive) return(0);
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  preciou_z = dm->calcu_prmay(codigo_z, tipomayoris_z);
  return(preciou_z);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscappedmagrnuevo::edt_codigoKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
    if(Key == VK_RETURN) edt_codigoExit(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TFrame_datoscappedmagrnuevo::edt_codigoExit(
      TObject *Sender)
{
  String codigo_z;
  codigo_z = edt_codigo->Text;
  if(codigo_z == "AUXILIAR") return;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(qry_inven->IsEmpty()) {
    // No Existe el código, habrá que buscarlo
    Tdlg_busartic *dlg_busartic = new Tdlg_busartic (this);
    dlg_busartic->busca_artic(codigo_z + "%", "-1");
    if(dlg_busartic->ShowModal() == mrOk) {
      qry_inven->Close();
      qry_inven->ParamByName("codigo")->AsString = dlg_busartic->qry_inven->FieldByName("codigo")->AsString;
      qry_inven->ParamByName("cia")->AsInteger = cia_z;
      qry_inven->Open();
    }
    delete dlg_busartic;
    //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
  }
  if(!qry_inven->IsEmpty()) {
    edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
    edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
    edt_costou->Value = calcu_prvta();
  }
  edt_canti->SetFocus();
}
//---------------------------------------------------------------------------

