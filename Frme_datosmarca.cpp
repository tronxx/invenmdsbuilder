//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosmarca.h"
#include "situaciones.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma resource "*.dfm"
TFrame_datosmarca *Frame_datosmarca;
//---------------------------------------------------------------------------
__fastcall TFrame_datosmarca::TFrame_datosmarca(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosmarca::inicializa(String tipo_z)
{
  if(tipo_z == "CIUDAD") {
    // Cuando son ciudades voy a agrega la lista de los estados
    qry_estados->Close();
    qry_estados->SQL->Text = "select * from car_estados where tipo=:TIPO order by nombre";
    qry_estados->ParamByName("tipo")->AsInteger = TIPO_ESTADO_INV;
    qry_estados->Open();
    lbl_estado->Visible = true;
    lbl_estado->Caption = "Estado";
    lkcmb_estados->Visible = true;
    lkcmb_estados->KeyField = "idestado";
    lkcmb_estados->ListField = "nombre";
    lkcmb_estados->KeyValue = qry_estados->FieldByName("idestado")->AsInteger;
  }
  if(tipo_z == "ESTADO") {
    // Cuando son Estado voy a agregar la lista de los Paises
    qry_estados->Close();
    qry_estados->SQL->Text = "select * from car_estados where tipo=:TIPO order by nombre";
    qry_estados->ParamByName("tipo")->AsInteger = TIPO_PAIS_INV;
    qry_estados->Open();
    lbl_estado->Visible = true;
    lbl_estado->Caption = "Pais";
    lkcmb_estados->Visible = true;
    lkcmb_estados->KeyField = "idestado";
    lkcmb_estados->ListField = "nombre";
    lkcmb_estados->KeyValue = qry_estados->FieldByName("idestado")->AsInteger;
  }
  if(tipo_z == "TIPO_POLIZA") {
    // Cuando son Estado voy a agregar la lista de los Paises
    lkcmb_estados->Visible = false;
    lkcmb_estados->Visible = false;
  }
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosmarca::cmb_statusChange(TObject *Sender)
{
  bool visible_z = false;
  if (cmb_status->ItemIndex == 0 ) {
    visible_z = false;
  } else {
    visible_z = true;
  }
  lbl_fecbaj->Visible = visible_z;
  date_fecbaj->Visible = visible_z;
        
}
//---------------------------------------------------------------------------

