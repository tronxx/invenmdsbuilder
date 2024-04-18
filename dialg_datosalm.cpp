//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dialg_datosalm.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
#include "dmod.h"
Tdlg_datosalm *dlg_datosalm;
//---------------------------------------------------------------------------
__fastcall Tdlg_datosalm::Tdlg_datosalm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall Tdlg_datosalm::FormCreate(TObject *Sender)
{
  qry_zonas->Close();
  qry_zonas->Open();
  if ( !qry_zonas->IsEmpty()) {
    lkcmb_zona->KeyValue = qry_zonas->FieldByName("zona")->AsString;
  }
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosalm::asigna_tipo(String tipo_z)
{
   if(tipo_z == "ALMACEN") {
     lbl_relubivta->Visible = false;
     lkcmb_relubivta->Visible = false;
     dbedt_ubivta->Visible = false;
   }
   if(tipo_z == "PTOVTA") {
     lbl_relubivta->Visible = true;
     lkcmb_relubivta->Visible = true;
     dbedt_ubivta->Visible = true;
     qry_relubivta->Close();
     qry_relubivta->ParamByName("cia")->AsInteger = dm->cia_z;
     qry_relubivta->Open();
   }
}
//---------------------------------------------------------------------------

