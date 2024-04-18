//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_dircli.h"
#include "Frme_datoscapsmay.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
#include "dmod.h"
#include "situaciones.h"
TFrame_datoscapsmay *Frame_datoscapsmay;
//---------------------------------------------------------------------------
__fastcall TFrame_datoscapsmay::TFrame_datoscapsmay(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapsmay::inicializa(String mitipo_z)
{
  int idpermis_z=0;
  tipo_z = mitipo_z;
  cia_z = dm->cia_z;
  qry_Almacen->Close();
  qry_Almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_Almacen->Open();
  lkcmb_almacen->KeyValue = qry_Almacen->FieldByName("clave")->AsString;
  qry_mayorista->Close();
  qry_mayorista->ParamByName("cia")->AsInteger = cia_z;
  qry_mayorista->Open();
  lkcmb_mayoris->KeyValue = qry_mayorista->FieldByName("codigo")->AsString;
  date_fecha->Date    = dm->ahora();
  fecmin_z = dm->ahora() - 20;
  fecmax_z = dm->ahora();
  checafecha_z = ACTIVO;
  cmb_siono->ItemIndex = 0;
  qry_tipofacmay->Close();
  qry_tipofacmay->Open();
  lkcmb_facorem->KeyValue = qry_tipofacmay->FieldByName("idtipofacturma")->AsInteger;
  accion_z = 0;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapsmay::nuevo()
{
  String alm_z;
  int nument_z=0;
  alm_z = qry_Almacen->FieldByName("clave")->AsString;
  nument_z = dm->sigte_entrada(alm_z, tipo_z, nument_z, ULTIMO);
  if(nument_z < 0) nument_z = 0;
  nument_z++;
  edt_numero->Text = IntToStr(nument_z);
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datoscapsmay::lkcmb_almacenExit(TObject *Sender)
{
  if(accion_z == NUEVO) nuevo();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datoscapsmay::date_fechaExit(TObject *Sender)
{
   String strfecmin_z, strfecmax_z, strfechoy_z, strfecha_z,
   msg_z, tit_z, format_z;
   format_z = "yyyy/mm/dd";
   if(dm->usermaster_z != "S") {
     if(checafecha_z == ACTIVO) {
       strfechoy_z = FormatDateTime(format_z, dm->ahora());
       strfecmin_z = FormatDateTime(format_z, fecmin_z);
       strfecmax_z = FormatDateTime(format_z, fecmax_z);
       strfecha_z  = FormatDateTime(format_z, date_fecha->Date);
       if(strfecha_z < strfecmin_z || strfecha_z > strfecmax_z) {
         msg_z = "No puede teclear fechas menores a " + FormatDateTime("dd/mm/yyyy", fecmin_z);
         msg_z += "\n Ni mayores a " + FormatDateTime("dd/mm/yyyy", fecmax_z);
         tit_z = "Fecha Incorrecta";
         Application->MessageBox(msg_z.c_str(), tit_z.c_str(), MB_ICONEXCLAMATION);
         date_fecha->SetFocus();
       }
     }
   }

}
//---------------------------------------------------------------------------

String __fastcall TFrame_datoscapsmay::BuscarDato(String tipodato_z, String datoant_z)
{
   String cadena_z, result_z;
   Tdlg_okcancel *Dlg_pidenombre;
   Dlg_pidenombre = new Tdlg_okcancel (this);
   TFrame_dircli *Frame_dircli = new TFrame_dircli (Dlg_pidenombre);
   Frame_dircli->Top = 6;
   Frame_dircli->Left= 6;
   Frame_dircli->Parent = Dlg_pidenombre->Panel1;
   Frame_dircli->Align = alClient;
   Frame_dircli->Visible = true;
   if(tipodato_z == "MAYORISTA") {
       cadena_z = "Mayorista";
       const int MAYORISTA=31;
       Frame_dircli->selecciona_tipodato(MAYORISTA, datoant_z);
   }
   if(tipodato_z == "TIPO_FACMAY") {
       cadena_z = "Tipo Documento Mayoreo";
       const int TIPO_FACMAY=32;
       Frame_dircli->selecciona_tipodato(TIPO_FACMAY, datoant_z);
   }
   Dlg_pidenombre->Caption = cadena_z;
   if( Dlg_pidenombre->ShowModal() != mrOk) {
     result_z == "-1";
   } else {
     if(tipodato_z == "MAYORISTA") {
        result_z = Frame_dircli->qry_poblac->FieldByName("codigo")->AsString;
        result_z += ":" + Frame_dircli->qry_poblac->FieldByName("nombre")->AsString;
     }
     if(tipodato_z == "TIPO_FACNAY") {
        result_z = Frame_dircli->qry_poblac->FieldByName("clavetipofac")->AsString;
        result_z += ":" + Frame_dircli->qry_poblac->FieldByName("descri")->AsString;
        result_z += ":" + Frame_dircli->qry_poblac->FieldByName("idtipofacturma")->AsString;
     }
   }
   delete Frame_dircli;
   delete Dlg_pidenombre;
   return (result_z);
}
//---------------------------------------------------------------------------




