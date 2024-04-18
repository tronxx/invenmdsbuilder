//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "dialg_foliosdisp.h"
#include "dmod.h"
//---------------------------------------------------------------------
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
Tdlg_foliosdisp *dlg_foliosdisp;
//---------------------------------------------------------------------
__fastcall Tdlg_foliosdisp::Tdlg_foliosdisp(TComponent* AOwner)
	: TForm(AOwner)
{
}
//---------------------------------------------------------------------


void __fastcall Tdlg_foliosdisp::busca_dispo(String codigo_z, int cia_z)
{
  qry_disponibles->Close();
  qry_disponibles->ParamByName("codigo")->AsString=codigo_z;
  qry_disponibles->ParamByName("cia")->AsInteger = cia_z;
  qry_disponibles->Open();
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_foliosdisp::btn_okClick(TObject *Sender)
{
  alm_z   = qry_disponibles->FieldByName("alm")->AsString;
  folio_z = qry_disponibles->FieldByName("folio")->AsInteger;
  precioventa_z = edt_preciovta->Value;
}
//---------------------------------------------------------------------------

