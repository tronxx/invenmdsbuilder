//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datospedimento.h"
#include "dmod.h"
#include "situaciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TFrame_datospedimento *Frame_datospedimento;
//---------------------------------------------------------------------------
__fastcall TFrame_datospedimento::TFrame_datospedimento(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  date_fecha->Date = dm->ahora();
  entrada_z = 0;
  tipo_z = "";
  alm_z = "";
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datospedimento::solo_serie()
{
  lbl_seriemot->Visible = false;
  edt_seriemot->Visible = false;
  lbl_pedimento->Visible = false;
  edt_pedimento->Visible = false;
  lbl_aduana->Visible = false;
  edt_aduana->Visible = false;
  lbl_fechaped->Visible = false;
  date_fecha->Visible = false;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datospedimento::agrega_datosped()
{
  String serie_z, codigo_z, seriemot_z="", pedimen_z="", aduana_z="";
  int iddatosent_z, idart_z, idseriemot_z=0, idpedimen_z=0, idaduana_z=0;
  bool nvatrans_z = false;
  TDateTime fecha_z;
  codigo_z     = edt_codigo->Text;
  serie_z      = edt_serie->Text;
  seriemot_z   = edt_seriemot->Text;
  pedimen_z    = edt_pedimento->Text;
  aduana_z     = edt_aduana->Text;
  fecha_z      = date_fecha->Date;
  idseriemot_z = dm->busca_iddato(seriemot_z, INVCONCEPTO);
  idpedimen_z  = dm->busca_iddato(pedimen_z, INVCONCEPTO);
  idaduana_z   = dm->busca_iddato(aduana_z, INVCONCEPTO);
  qry_idart->Close();
  qry_idart->ParamByName("codigo")->AsString = codigo_z;
  qry_idart->ParamByName("cia")->AsInteger = cia_z;
  qry_idart->Open();
  if(qry_idart->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe el idart de este codigo", "Codigo Inexistente", MB_ICONEXCLAMATION);
      return;
  }
  idart_z =   qry_idart->FieldByName("idart")->AsInteger;

  if(qry_datosped->State == dsInactive) {
    qry_datosped->Close();
    qry_datosped->ParamByName("idart")->AsInteger = idart_z;
    qry_datosped->ParamByName("serie")->AsString = serie_z;
    qry_datosped->Open();
  }
  if(qry_datosped->IsEmpty()) {
    iddatosent_z = dm->busca_sigid(IDDATOSENT);
    qry_datosped->Append();
    qry_datosped->FieldByName("IDDATOSENT")->AsInteger = iddatosent_z;
    qry_datosped->FieldByName("IDENTRADA")->AsInteger = 0;
    qry_datosped->FieldByName("TIPO")->AsString = tipo_z;
    qry_datosped->FieldByName("ALM")->AsString = alm_z;
    qry_datosped->FieldByName("NUMERO")->AsInteger = entrada_z;
    qry_datosped->FieldByName("idart")->AsInteger = idart_z;
    qry_datosped->FieldByName("serie")->AsString = serie_z;
  } else {
    qry_datosped->Edit();
  }
  qry_datosped->FieldByName("IDSERIEMOT")->AsInteger = idseriemot_z;
  qry_datosped->FieldByName("IDPEDTO")->AsInteger = idpedimen_z;
  qry_datosped->FieldByName("IDADUANA")->AsInteger = idaduana_z;
  qry_datosped->FieldByName("FECHAPED")->AsDateTime = fecha_z;
  qry_datosped->Post();
  try {
    nvatrans_z = !dm->manvehi->InTransaction;
    if(nvatrans_z) dm->manvehi->StartTransaction();
    qry_datosped->ApplyUpdates();
    if(nvatrans_z) dm->manvehi->Commit();
  } catch (Exception &E) {
    if(nvatrans_z) dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datospedimento::agrega_datosped_sin_close()
{
  String serie_z, codigo_z, seriemot_z="", pedimen_z="", aduana_z="";
  int idart_z, idseriemot_z=0, idpedimen_z=0, idaduana_z=0;
  bool nvatrans_z = false;
  TDateTime fecha_z;
  codigo_z     = edt_codigo->Text;
  serie_z      = edt_serie->Text;
  seriemot_z   = edt_seriemot->Text;
  pedimen_z    = edt_pedimento->Text;
  aduana_z     = edt_aduana->Text;
  fecha_z      = date_fecha->Date;
  idseriemot_z = dm->busca_iddato(seriemot_z, INVCONCEPTO);
  idpedimen_z  = dm->busca_iddato(pedimen_z, INVCONCEPTO);
  idaduana_z   = dm->busca_iddato(aduana_z, INVCONCEPTO);
  qry_idart->Close();
  qry_idart->ParamByName("codigo")->AsString = codigo_z;
  qry_idart->ParamByName("cia")->AsInteger = cia_z;
  qry_idart->Open();
  if(qry_idart->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe el idart de este codigo", "Codigo Inexistente", MB_ICONEXCLAMATION);
      return;
  }
  idart_z =   qry_idart->FieldByName("idart")->AsInteger;

  if(qry_datosped->State == dsInactive) {
    qry_datosped->Close();
    qry_datosped->ParamByName("idart")->AsInteger = idart_z;
    qry_datosped->ParamByName("serie")->AsString = serie_z;
    qry_datosped->Open();
    iddatosent_z = dm->busca_sigid(IDDATOSENT);
  }
  qry_datosped->Append();
  qry_datosped->FieldByName("IDDATOSENT")->AsInteger = iddatosent_z;
  qry_datosped->FieldByName("IDENTRADA")->AsInteger = 0;
  qry_datosped->FieldByName("TIPO")->AsString = tipo_z;
  qry_datosped->FieldByName("ALM")->AsString = alm_z;
  qry_datosped->FieldByName("NUMERO")->AsInteger = entrada_z;
  qry_datosped->FieldByName("idart")->AsInteger = idart_z;
  qry_datosped->FieldByName("serie")->AsString = serie_z;
  qry_datosped->FieldByName("IDSERIEMOT")->AsInteger = idseriemot_z;
  qry_datosped->FieldByName("IDPEDTO")->AsInteger = idpedimen_z;
  qry_datosped->FieldByName("IDADUANA")->AsInteger = idaduana_z;
  qry_datosped->FieldByName("FECHAPED")->AsDateTime = fecha_z;
  qry_datosped->Post();
  iddatosent_z++;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datospedimento::busca_datosped(String codigo_z, String serie_z, String almac_z)
{
  String seriemot_z="", pedimen_z="", aduana_z="";
  int idseriemot_z=0, idpedimen_z=0, idaduana_z=0, idart_z = 0;
  TDateTime fecha_z = dm->ahora();
  qry_idart->Close();
  qry_idart->ParamByName("codigo")->AsString = codigo_z;
  qry_idart->ParamByName("cia")->AsInteger = cia_z;
  qry_idart->Open();
  if(qry_idart->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe el idart de este codigo", "Codigo Inexistente", MB_ICONEXCLAMATION);
      return;
  }
  idart_z =   qry_idart->FieldByName("idart")->AsInteger;
  qry_datosped->Close();
  qry_datosped->ParamByName("idart")->AsInteger = idart_z;
  qry_datosped->ParamByName("serie")->AsString = serie_z;
  qry_datosped->Open();
  if(!qry_datosped->IsEmpty()) {
    idseriemot_z = qry_datosped->FieldByName("IDSERIEMOT")->AsInteger;
    idpedimen_z  = qry_datosped->FieldByName("IDPEDTO")->AsInteger;
    idaduana_z   = qry_datosped->FieldByName("IDADUANA")->AsInteger;
    fecha_z      = qry_datosped->FieldByName("FECHAPED")->AsDateTime;
  }
  seriemot_z = dm->busca_dato(idseriemot_z, INVCONCEPTO);
  pedimen_z  = dm->busca_dato(idpedimen_z, INVCONCEPTO);
  aduana_z   = dm->busca_dato(idaduana_z, INVCONCEPTO);
  edt_codigo->Text = codigo_z;
  edt_serie->Text = serie_z;
  edt_seriemot->Text = seriemot_z;
  edt_pedimento->Text = pedimen_z;
  edt_aduana->Text = aduana_z;
  date_fecha->Date = fecha_z;
  alm_z = almac_z;
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datospedimento::borra_datosped(String codigo_z, String serie_z, String almac_z)
{
  String seriemot_z="", pedimen_z="", aduana_z="";
  int idseriemot_z=0, idpedimen_z=0, idaduana_z=0, idart_z = 0;
  TDateTime fecha_z = dm->ahora();
  qry_idart->Close();
  qry_idart->ParamByName("codigo")->AsString = codigo_z;
  qry_idart->ParamByName("cia")->AsInteger = cia_z;
  qry_idart->Open();
  if(qry_idart->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe el idart de este codigo", "Codigo Inexistente", MB_ICONEXCLAMATION);
      return;
  }
  idart_z =   qry_idart->FieldByName("idart")->AsInteger;
  qry_datosped->Close();
  qry_datosped->ParamByName("idart")->AsInteger = idart_z;
  qry_datosped->ParamByName("serie")->AsString = serie_z;
  qry_datosped->Open();
  if(!qry_datosped->IsEmpty()) {
    qry_datosped->Delete();
  }
}
//---------------------------------------------------------------------------

