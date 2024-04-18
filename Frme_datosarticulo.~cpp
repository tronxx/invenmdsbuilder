//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosarticulo.h"
#include "Frm_consuinv.h"
#include "dmod.h"
#include "situaciones.h"
#include "numapal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datosarticulo *Frame_datosarticulo;
//---------------------------------------------------------------------------
__fastcall TFrame_datosarticulo::TFrame_datosarticulo(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosarticulo::inicializa(String codigo_z, int mimodo_z)
{
  TQuery *miqry_z;
  String nomqry_z;
  cia_z = dm->cia_z;
  modo_z = mimodo_z;
  int jj_z=0, ii_z=0;
  for(ii_z=0; ii_z < 8; ii_z++) {
    if(ii_z == 0) miqry_z = qry_marcas;
    if(ii_z == 1) miqry_z = qry_situaciones;
    if(ii_z == 2) miqry_z = qry_prove;
    if(ii_z == 3) miqry_z = qry_grupos;
    if(ii_z == 4) miqry_z = qry_diary;
    if(ii_z == 5) miqry_z = qry_lineas;
    if(ii_z == 6) miqry_z = qry_garantia;
    if(ii_z == 7) miqry_z = qry_catprodsat;
    nomqry_z = miqry_z->Name;

    miqry_z->Close();
    nomqry_z = miqry_z->SQL->Text;
    for(jj_z = 0; jj_z < miqry_z->ParamCount; jj_z++) {
      miqry_z->ParamByName("cia")->AsInteger = cia_z;
    }
    miqry_z->Open();
    if(ii_z == 7 ) {
      rbtn_catsatcod->Checked = miqry_z->IsEmpty();
      rbtn_catsatcodClick(this);
    }
  }
  busca_articulo(codigo_z);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosarticulo::busca_articulo(String codigo_z)
{
  double costo_z, piva_z, mubmds_z=0, mubelec_z=0;
  String situacion_z;
  int idsituac_z;
  TLocateOptions Opts;
  Opts.Clear();
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(qry_inven->IsEmpty()) return;
  costo_z = qry_inven->FieldByName("costos")->AsFloat;
  piva_z = qry_inven->FieldByName("piva")->AsFloat;
  edt_codigo->Text = codigo_z;
  edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
  edt_alta->Text = FormatDateTime("dd/mm/yyyy", qry_inven->FieldByName("fecalta")->AsDateTime);
  edt_costosi->Value = qry_inven->FieldByName("costos")->AsFloat;
  edt_costono->Value = qry_inven->FieldByName("coston")->AsFloat;
  edt_costocext->Value = Form_consuinv->edt_costocext->Value;
  edt_piva->Value = piva_z;
  edt_preciomds->Value  = qry_inven->FieldByName("precio")->AsFloat;
  edt_precelec->Value  = qry_inven->FieldByName("precelec")->AsFloat;

  edt_descri2->Text = Form_consuinv->qry_descri2->FieldByName("descri")->AsString;
  //edt_prvtacext->Value = Form_consuinv->edt_prvtacext->Value;
  edt_costocext->Value = Form_consuinv->edt_costocext->Value;
  edt_mubcext->Value = Form_consuinv->edt_mubcext->Value;
  edt_mubmds->Value = Form_consuinv->qry_inven->FieldByName("mubmds")->AsFloat;
  edt_mubelec->Value = Form_consuinv->qry_inven->FieldByName("mubelec")->AsFloat;
  edt_maximo->Value = Form_consuinv->qry_inven->FieldByName("maxi")->AsFloat;
  edt_minimo->Value  = qry_inven->FieldByName("minimo")->AsFloat;
  lkcmb_linea->KeyValue = qry_inven->FieldByName("linea")->AsString;
  lkcmb_grupo->KeyValue = qry_inven->FieldByName("cod2")->AsString;
  lkcmb_prove->KeyValue = qry_inven->FieldByName("prove")->AsString;
  lkcmb_diary->KeyValue = Form_consuinv->qry_diary->FieldByName("grupo")->AsString;
  lkcmb_marcas->KeyValue = Form_consuinv->qry_marca->FieldByName("codigo")->AsString;
  lkcmb_garantia->KeyValue = Form_consuinv->qry_garantias->FieldByName("clave")->AsString;
  lkcmb_catsat->KeyValue = Form_consuinv->qry_catprodsat->FieldByName("idprod")->AsInteger;

  qry_situaciones->First();
  idsituac_z = qry_situaciones->FieldByName("idsituac")->AsInteger;
  situacion_z = qry_inven->FieldByName("empaqe")->AsString;
  if(qry_situaciones->Locate("situacion", situacion_z, Opts)) {
    idsituac_z = qry_situaciones->FieldByName("idsituac")->AsInteger;
    lkcmb_situacion->KeyValue = idsituac_z;
  }
  cmb_tipo->ItemIndex = 0;
  if(qry_inven->FieldByName("tipo")->AsString == "GLO") cmb_tipo->ItemIndex++;
  //edt_plazo->Text = Form_consuinv->edt_plazo->Text;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosarticulo::graba_articulo(int modo_z)
{
  double costo_z, piva_z, mubmds_z=0, mubelec_z=0;
  String codigo_z, situacion_z, grupo_z, prove_z, linea_z, situac_z,
    marca_z, descri2_z, garantia_z, tipo_z, catsat_z;
  int idart_z, idsituac_z;
  TLocateOptions Opts;
  Opts.Clear();
  codigo_z = edt_codigo->Text.Trim();
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(modo_z == NUEVO && !qry_inven->IsEmpty()) {
     Application->MessageBox(("Ya existe este codigo:"+codigo_z).c_str(), "ERROR", MB_ICONEXCLAMATION);
     return;
  }
  if(modo_z == MODIF && qry_inven->IsEmpty()) {
     Application->MessageBox(("No existe este codigo:"+codigo_z).c_str(), "ERROR", MB_ICONEXCLAMATION);
     return;
  }

  qry_invhist->Close();
  qry_invhist->ParamByName("codigo")->AsString = codigo_z;
  qry_invhist->ParamByName("cia")->AsInteger = cia_z;
  qry_invhist->Open();
  if(qry_invhist->IsEmpty()) {
    idart_z = buscaid("INV_INVHIST") + 1;
    qry_invhist->Append();
    qry_invhist->FieldByName("codigo")->AsString = codigo_z;
    qry_invhist->FieldByName("cia")->AsInteger = cia_z;
    qry_invhist->FieldByName("idart")->AsInteger = idart_z;
  } else {
    qry_invhist->Edit();
  }
  if(modo_z == NUEVO) {
    qry_inven->Append();
    qry_inven->FieldByName("codigo")->AsString = codigo_z;
    qry_inven->FieldByName("fecalta")->AsDateTime = dm->ahora();
    qry_inven->FieldByName("cia")->AsInteger = cia_z;
    qry_inven->FieldByName("minimo")->AsFloat = 0;
    qry_inven->FieldByName("maximo")->AsFloat = 0;
    qry_inven->FieldByName("precio")->AsFloat = 0;
    qry_inven->FieldByName("piva")->AsFloat = 0;
    qry_inven->FieldByName("costos")->AsFloat = 0;
    qry_inven->FieldByName("coston")->AsFloat = 0;
    qry_inven->FieldByName("inicials")->AsFloat = 0;
    qry_inven->FieldByName("entcoms")->AsFloat = 0;
    qry_inven->FieldByName("entcans")->AsFloat = 0;
    qry_inven->FieldByName("entesps")->AsFloat = 0;
    qry_inven->FieldByName("salvtas")->AsFloat = 0;
    qry_inven->FieldByName("salfons")->AsFloat = 0;
    qry_inven->FieldByName("salesps")->AsFloat = 0;
    qry_inven->FieldByName("salmays")->AsFloat = 0;
    qry_inven->FieldByName("existes")->AsFloat = 0;
    qry_inven->FieldByName("inicialn")->AsFloat = 0;
    qry_inven->FieldByName("entcomn")->AsFloat = 0;
    qry_inven->FieldByName("entcann")->AsFloat = 0;
    qry_inven->FieldByName("entespn")->AsFloat = 0;
    qry_inven->FieldByName("salvtan")->AsFloat = 0;
    qry_inven->FieldByName("salfonn")->AsFloat = 0;
    qry_inven->FieldByName("salespn")->AsFloat = 0;
    qry_inven->FieldByName("salmayn")->AsFloat = 0;
    qry_inven->FieldByName("existen")->AsFloat = 0;
    qry_inven->FieldByName("cosinicials")->AsFloat = 0;
    qry_inven->FieldByName("cosentcoms")->AsFloat = 0;
    qry_inven->FieldByName("cosentcans")->AsFloat = 0;
    qry_inven->FieldByName("cosentesps")->AsFloat = 0;
    qry_inven->FieldByName("cossalvtas")->AsFloat = 0;
    qry_inven->FieldByName("cossalfons")->AsFloat = 0;
    qry_inven->FieldByName("cossalesps")->AsFloat = 0;
    qry_inven->FieldByName("cossalmays")->AsFloat = 0;
    qry_inven->FieldByName("cosexistes")->AsFloat = 0;
    qry_inven->FieldByName("cosinicialn")->AsFloat = 0;
    qry_inven->FieldByName("cosentcomn")->AsFloat = 0;
    qry_inven->FieldByName("cosentcann")->AsFloat = 0;
    qry_inven->FieldByName("cosentespn")->AsFloat = 0;
    qry_inven->FieldByName("cossalvtan")->AsFloat = 0;
    qry_inven->FieldByName("cossalfonn")->AsFloat = 0;
    qry_inven->FieldByName("cossalespn")->AsFloat = 0;
    qry_inven->FieldByName("cossalmayn")->AsFloat = 0;
    qry_inven->FieldByName("cosexisten")->AsFloat = 0;
    qry_inven->FieldByName("precelec")->AsFloat = 0;
  } else {
    qry_inven->Edit();
  }
  grupo_z = qry_grupos->FieldByName("codigo")->AsString;
  prove_z = qry_prove->FieldByName("codigo")->AsString;
  linea_z = qry_lineas->FieldByName("linea")->AsString;
  situac_z = qry_situaciones->FieldByName("situacion")->AsString;
  marca_z = qry_marcas->FieldByName("codigo")->AsString;
  catsat_z = qry_catprodsat->FieldByName("codigo")->AsString;
  descri2_z = edt_descri2->Text.Trim();
  tipo_z = cmb_tipo->Items->Strings[cmb_tipo->ItemIndex];
  qry_inven->FieldByName("cod2")->AsString = grupo_z;
  qry_inven->FieldByName("prove")->AsString = prove_z;
  qry_inven->FieldByName("tipo")->AsString = tipo_z;
  qry_inven->FieldByName("linea")->AsString = linea_z;
  qry_inven->FieldByName("descri")->AsString = edt_descri->Text.Trim();
  qry_inven->FieldByName("empaqe")->AsString = situac_z;
  qry_inven->FieldByName("precio")->AsFloat = edt_preciomds->Value;
  qry_inven->FieldByName("piva")->AsFloat = edt_piva->Value;
  qry_inven->FieldByName("costos")->AsFloat = edt_costosi->Value;
  qry_inven->FieldByName("coston")->AsFloat = edt_costono->Value;
  qry_inven->FieldByName("mds")->AsString = "N";
  qry_inven->FieldByName("elec")->AsString = "N";
  qry_inven->Post();

  agrega_relaciones_inv(grupo_z, prove_z, linea_z, situac_z, garantia_z,
    descri2_z, marca_z);
  try {
      dm->manvehi->StartTransaction();
      qry_inven->ApplyUpdates();
      qry_invhist->ApplyUpdates();
      if(qry_invrelinv->UpdatesPending) qry_invrelinv->ApplyUpdates();
      dm->manvehi->Commit();
  } catch (Exception &E)
  {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosarticulo::agrega_relaciones_inv(String grupo_z,
  String prove_z, String linea_z, String situac_z, String garantia_z,
  String  descri2_z, String marca_z)
{
  int idart_z=0, sigidrelinv_z=0, idprove_z = 0, idlinea_z=0,
    idsituac_z = 0, idgtia_z =0, iddescri_z = 0, idgrupo_z=0,
    idgpodiary_z=0, iddato_z = 0, idmarca_z=0, idreltipo_z=0,
    idprodsat_z = 0, simod_z = 0,
    antdatorel_z = 0, ii_z;
  TLocateOptions Opts;
  Opts.Clear();

  idart_z       = qry_invhist->FieldByName("idart")->AsInteger;
  iddescri_z    = dm->busca_iddato(descri2_z, INVCONCEPTO);
  idlinea_z     = qry_lineas->FieldByName("idlinea")->AsInteger;
  idsituac_z    = qry_situaciones->FieldByName("idsituac")->AsInteger;
  idgtia_z      = qry_garantia->FieldByName("idgarantia")->AsInteger;
  idgpodiary_z  = qry_diary->FieldByName("idgpodiary")->AsInteger;
  idgrupo_z     = qry_grupos->FieldByName("idgrupo")->AsInteger;
  idmarca_z     = qry_marcas->FieldByName("idmarcainv")->AsInteger;
  idprodsat_z   = qry_catprodsat->FieldByName("idprod")->AsInteger;
  sigidrelinv_z = dm->busca_sigid(IDRELINV);
  qry_invrelinv->Close();
  qry_invrelinv->ParamByName("idart")->AsInteger = idart_z;
  qry_invrelinv->Open();
  for( ii_z = 0; ii_z < 8; ii_z++) {
    if( ii_z == 0) { idreltipo_z = REL_INVEN_ARTDESP;   iddato_z = idgrupo_z;    }
    if( ii_z == 1) { idreltipo_z = REL_INVEN_LINEA;     iddato_z = idlinea_z;    }
    if( ii_z == 2) { idreltipo_z = REL_INVEN_SITUACION; iddato_z = idsituac_z;   }
    if( ii_z == 3) { idreltipo_z = REL_INVEN_GPODIARY;  iddato_z = idgpodiary_z; }
    if( ii_z == 4) { idreltipo_z = REL_INVEN_MARCAS;    iddato_z = idmarca_z;    }
    if( ii_z == 5) { idreltipo_z = REL_INVEN_DESCRILAR; iddato_z = iddescri_z;   }
    if( ii_z == 6) { idreltipo_z = REL_INVEN_GARANTIA;  iddato_z = idgtia_z;     }
    if( ii_z == 7) { idreltipo_z = REL_INVEN_CATPRODSAT; iddato_z = idprodsat_z; }
    qry_invrelinv->First();
    if( idreltipo_z == REL_INVEN_CATPRODSAT && rbtn_catsatgpo->Checked) {
      if(qry_invrelinv->Locate("idrel", idreltipo_z, Opts)) {
        qry_invrelinv->Delete();
      }
    } else {
      if(qry_invrelinv->Locate("idrel", idreltipo_z, Opts)) {
        antdatorel_z = qry_invrelinv->FieldByName("iddato")->AsInteger;
        if ( antdatorel_z != iddato_z) {
          qry_invrelinv->Edit();
          qry_invrelinv->FieldByName("iddato")->AsInteger = iddato_z;
          qry_invrelinv->Post();
        }
      } else {
        qry_invrelinv->Append();
        qry_invrelinv->FieldByName("idrelinv")->AsInteger = sigidrelinv_z;
        qry_invrelinv->FieldByName("idart")->AsInteger = idart_z;
        qry_invrelinv->FieldByName("idrel")->AsInteger = idreltipo_z;
        qry_invrelinv->FieldByName("conse")->AsInteger = 0;
        qry_invrelinv->FieldByName("iddato")->AsInteger = iddato_z;
        qry_invrelinv->Post();
        sigidrelinv_z++;
      }
    }
  }
}
//---------------------------------------------------------------------------

int TFrame_datosarticulo::buscaid(String tabla_z)
{
  int sigteid_z = 0;
  String sql_z;
  if(tabla_z == "INV_INVHIST") {
    sql_z = "select max(idart) as ultid from inv_invhist where idart > 0";
  }
  qry_buscasigid->Close();
  qry_buscasigid->SQL->Text= sql_z;
  qry_buscasigid->Open();
  sigteid_z =   qry_buscasigid->FieldByName("ultid")->AsInteger;
  return (sigteid_z);

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosarticulo::edt_costosiExit(TObject *Sender)
{
  if (edt_costono->Value == 0) {
    edt_costono->Value = Redondea(edt_costosi->Value * ( 1 + edt_piva->Value / 100), 100);
  }
}
//---------------------------------------------------------------------------





void __fastcall TFrame_datosarticulo::rbtn_catsatcodClick(TObject *Sender)
{
  lbl_codsat->Visible = rbtn_catsatcod->Checked;
  lkcmb_catsat->Visible = lbl_codsat->Visible;
  dbedt_codsat->Visible = lbl_codsat->Visible;
}
//---------------------------------------------------------------------------

