//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_consuinv.h"
#include "dmod.h"
#include "Frm_detmovart.h"
#include "Frm_estadis.h"
#include "Frm_dlgcriterio.h"
#include "Frm_exists.h"
#include "numapal.h"
#include "dialg_okcancel.h"
#include "situaciones.h"
#include <inifiles.hpp>
#include "Frm_CapturaObsPed.h"
#include "dialg_busartic.h"
#include "Frm_polcampre.h"
#include "Frme_datosnvoprecio.h"
#include "Frme_datosarticulo.h"
#include "Frme_datosrenpolcampre.h"
#include "dir.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "AdvGrid"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
#pragma link "dxLayout"
#pragma link "Frme_imginven"
#pragma link "Frme_datosinternet"
#pragma resource "*.dfm"
const int COL_ETIQUE      = 0;
const int COL_INICIA      = 1;
const int COL_COMPRA      = 2;
const int COL_CANCEL      = 3;
const int COL_ENTESP      = 4;
const int COL_TOTENT      = 5;
const int COL_SALVTA      = 6;
const int COL_SALFON      = 7;
const int COL_SALESP      = 8;
const int COL_SALMAY      = 9;
const int COL_EXISTE      = 10;
const int REN_SI          = 1;
const int REN_NO          = 2;

const int MUB_MIN_MAY     = 38;

//const int COL_EXICOD = 0;
const int COL_EXIDES = 0;

const int EXI_GRUPO         = 0;
const int EXI_MARCA         = 1;
const int EXI_PROVE         = 2;
const int EXI_SITUAC        = 3;
const int EXI_CODIGO        = 4;
const int EXI_DIARY         = 5;

const int TBS_KARDEX            = 0;
const int TBS_ESTADIS           = 1;
const int TBS_EXIST             = 2;
const int TBS_OBSERVS           = 3;
const int TBS_DISPONI           = 4;
const int TBS_BUSSERIE          = 5;
const int TBS_OBSERVSNEG        = 7;
const int TBS_OBSERVSCOM        = 9;
const int TBS_DATOSINTERNET     = 10;

const int CMB_SAL_ESP           = 0;
const int CMB_SAL_VTA           = 1;
const int CMB_ENT_CAN           = 2;
const int CMB_ENT_ESP           = 3;
const int CMB_SAL_MAY           = 4;
const int CMB_ENT_COM           = 5;

TForm_consuinv *Form_consuinv;
//---------------------------------------------------------------------------
__fastcall TForm_consuinv::TForm_consuinv(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::busca_cod(AnsiString codigo_z)
{
  String linea_z, antlin_z, caption1_z, caption2_z, caption3_z,
    empaqe_z, gtia_z, gpoesp_z = "N", prove_z, alm_z;
  double preciou_z, costo_z, piva_z, factorprecio_z=0,
    mubmay_z = 0, mubfil_z = 0, muboferta_z = 0, preciomay_z=0, preciofil_z=0,
    ctorep_z=0, preciomay2_z;
  int plazo_z = 0, tipomay_z=0;
  bool esvisible_z;
  edt_codigo->Text = codigo_z;
  edt_codestad->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  if(qry_inven->IsEmpty()) return;

  qry_diary->Close();
  qry_diary->ParamByName("codigo")->AsString=codigo_z;
  qry_diary->ParamByName("tiporel")->AsInteger = REL_INVEN_GPODIARY;
  qry_diary->ParamByName("cia")->AsInteger = cia_z;
  qry_diary->Open();
  qry_invulpre->Close();
  qry_invulpre->ParamByName("codigo")->AsString=codigo_z;
  qry_invulpre->ParamByName("cia")->AsInteger = cia_z;
  qry_invulpre->Open();
  qry_marca->Close();
  qry_marca->ParamByName("codigo")->AsString=codigo_z;
  qry_marca->ParamByName("tiporel")->AsInteger = REL_INVEN_MARCAS;
  qry_marca->ParamByName("cia")->AsInteger = cia_z;
  qry_marca->Open();
  qry_catprodsat->Close();
  qry_catprodsat->ParamByName("codigo")->AsString=codigo_z;
  qry_catprodsat->ParamByName("tiporelcod")->AsInteger = REL_INVEN_CATPRODSAT;
  qry_catprodsat->ParamByName("cia")->AsInteger = cia_z;
  qry_catprodsat->Open();
  if( qry_catprodsat->IsEmpty()) {
    qry_catprodsatgpo->Close();
    qry_catprodsatgpo->ParamByName("codigo")->AsString=codigo_z;
    qry_catprodsatgpo->ParamByName("tiporel")->AsInteger    = REL_INVEN_ARTDESP;
    qry_catprodsatgpo->ParamByName("cia")->AsInteger = cia_z;
    qry_catprodsatgpo->Open();
    dts_catprodsat->DataSet = qry_catprodsatgpo;
  } else {
    dts_catprodsat->DataSet = qry_catprodsat;
  }
  qry_descri2->Close();
  qry_descri2->ParamByName("codigo")->AsString = codigo_z;
  qry_descri2->ParamByName("cia")->AsInteger = cia_z;
  qry_descri2->ParamByName("idrel")->AsInteger = REL_INVEN_DESCRILAR;
  qry_descri2->Open();
  sgrd_tarjeta->ClearRows(1,2);
  if(qry_inven->IsEmpty()) return;
  int inicials_z = qry_inven->FieldByName("inicials")->AsInteger;
  int entcoms_z = qry_inven->FieldByName("entcoms")->AsInteger;
  int entcans_z = qry_inven->FieldByName("entcans")->AsInteger;
  int entesps_z = qry_inven->FieldByName("entesps")->AsInteger;
  int totents_z = entcoms_z + entcans_z + entesps_z;
  int salvtas_z = qry_inven->FieldByName("salvtas")->AsInteger;
  int salfons_z = qry_inven->FieldByName("salfons")->AsInteger;
  int salesps_z = qry_inven->FieldByName("salesps")->AsInteger;
  int salmays_z = qry_inven->FieldByName("salmays")->AsInteger;
  int existes_z = totents_z - salvtas_z - salfons_z - salesps_z - salmays_z + inicials_z;

  int inicialn_z = qry_inven->FieldByName("inicialn")->AsInteger;
  int entcomn_z = qry_inven->FieldByName("entcomn")->AsInteger;
  int entcann_z = qry_inven->FieldByName("entcann")->AsInteger;
  int entespn_z = qry_inven->FieldByName("entespn")->AsInteger;
  int totentn_z = entcomn_z + entcann_z + entespn_z;
  int salvtan_z = qry_inven->FieldByName("salvtan")->AsInteger;
  int salfonn_z = qry_inven->FieldByName("salfonn")->AsInteger;
  int salespn_z = qry_inven->FieldByName("salespn")->AsInteger;
  int salmayn_z = qry_inven->FieldByName("salmayn")->AsInteger;
  int existen_z = totentn_z - salvtan_z - salfonn_z - salespn_z - salmayn_z + inicialn_z;
  linea_z = qry_inven->FieldByName("linea")->AsString;
  empaqe_z = qry_inven->FieldByName("empaqe")->AsString;
  prove_z = qry_inven->FieldByName("prove")->AsString;
  costo_z = qry_inven->FieldByName("costos")->AsFloat;
  preciou_z = qry_inven->FieldByName("precio")->AsFloat;
  piva_z = qry_inven->FieldByName("piva")->AsFloat;
  caption1_z = lbl_preciomds->Caption;
  caption2_z = lbl_preciofide->Caption;
  //caption3_z = lbl_preciocxtensa->Caption;
  //if( linea_z == "ANTE" || linea_z == "VIDE" || linea_z == "BLCA" || linea_z == "MOTO" || linea_z == "AUDI") {
  //  esvisible_z = true;
  //  if ( caption3_z != "Precio c/Cmb") {
  //    lbl_preciocxtensa->Caption = "Precio c/Cmb";
  //    lbl_prxtensa->Caption = "Pr.Combo";
  //    lbl_cosxtensa->Caption = "Costo Combo";
  //  }
  //} else {
  //  esvisible_z = false;
  //}
  //if(lbl_preciocxtensa->Visible != esvisible_z) {
  //  lbl_preciocxtensa->Visible = esvisible_z;
  //  lbl_prxtensa->Visible = esvisible_z;
  //  lbl_cosxtensa->Visible = esvisible_z;
  //  edt_precioext->Visible = esvisible_z;
  //  edt_costoext->Visible = esvisible_z;
  //  edt_prvtacext->Visible = esvisible_z;
  //}

  if(linea_z == "CEL") {
    if(caption2_z != "Precio Movi") {
      lbl_preciofide->Caption = "Precio Movi";
      //dbedt_preciomds->Top = dbedt_coston->Top;
      //dbedt_preciofide->Top = dbedt_costos->Top;
    }
  } else {
    if(caption2_z != "Precio SUBS") {
      lbl_preciofide->Caption = "Precio SUBS";
      //dbedt_preciomds->Top = dbedt_costos->Top;
      //dbedt_preciofide->Top = dbedt_coston->Top;
    }
  }

  sgrd_tarjeta->Cells[COL_ETIQUE][REN_SI] = "Si";
  sgrd_tarjeta->Cells[COL_ETIQUE][REN_NO] = "No";
  sgrd_tarjeta->Cells[COL_INICIA][REN_SI] = inicials_z;
  sgrd_tarjeta->Cells[COL_COMPRA][REN_SI] = entcoms_z;
  sgrd_tarjeta->Cells[COL_CANCEL][REN_SI] = entcans_z;
  sgrd_tarjeta->Cells[COL_ENTESP][REN_SI] = entesps_z;
  sgrd_tarjeta->Cells[COL_TOTENT][REN_SI] = totents_z;
  sgrd_tarjeta->Cells[COL_SALVTA][REN_SI] = salvtas_z;
  sgrd_tarjeta->Cells[COL_SALFON][REN_SI] = salfons_z;
  sgrd_tarjeta->Cells[COL_SALESP][REN_SI] = salesps_z;
  sgrd_tarjeta->Cells[COL_SALMAY][REN_SI] = salmays_z;
  sgrd_tarjeta->Cells[COL_EXISTE][REN_SI] = existes_z;

  sgrd_tarjeta->Cells[COL_INICIA][REN_NO] = inicialn_z;
  sgrd_tarjeta->Cells[COL_COMPRA][REN_NO] = entcomn_z;
  sgrd_tarjeta->Cells[COL_CANCEL][REN_NO] = entcann_z;
  sgrd_tarjeta->Cells[COL_ENTESP][REN_NO] = entespn_z;
  sgrd_tarjeta->Cells[COL_TOTENT][REN_NO] = totentn_z;
  sgrd_tarjeta->Cells[COL_SALVTA][REN_NO] = salvtan_z;
  sgrd_tarjeta->Cells[COL_SALFON][REN_NO] = salfonn_z;
  sgrd_tarjeta->Cells[COL_SALESP][REN_NO] = salespn_z;
  sgrd_tarjeta->Cells[COL_SALMAY][REN_NO] = salmayn_z;
  sgrd_tarjeta->Cells[COL_EXISTE][REN_NO] = existen_z;

  qry_exist->Close();
  qry_exist->ParamByName("codigo")->AsString=codigo_z;
  qry_exist->ParamByName("cia")->AsInteger = cia_z;
  qry_exist->Open();
  qry_observs->Close();
  qry_observnegxcod->Close();
  qry_observnegxpro->Close();
  qry_observnegxmca->Close();
  qry_obscomlin->Close();
  qry_obscommca->Close();
  qry_obscomgpo->Close();
  page_detallesChange(this);

  sgrd_exist->ClearRows(1,1);

  int ii_z=0, totexi_z=0;
  for(qry_exist->First(); !qry_exist->Eof; qry_exist->Next()) {
    if(qry_exist->FieldByName("exis")->AsInteger) {
      alm_z = qry_exist->FieldByName("alm")->AsString;
      ii_z = sgrd_exist->ColumnHeaders->IndexOf(alm_z);
      sgrd_exist->Cells[ii_z][1]=qry_exist->FieldByName("exis")->AsInteger;
      totexi_z += qry_exist->FieldByName("exis")->AsInteger;
    }
  }
  sgrd_exist->Cells[sgrd_exist->ColCount - 2][1]=totexi_z;
  busca_movarts();
  qry_estadis->Close();
  sel_tipoexi();
  qry_seriebus->Close();
  qry_mvartdisp->Close();
  if(page_detalles->ActivePageIndex == TBS_DISPONI) {
    qry_mvartdisp->ParamByName("codigo")->AsString = codigo_z;
    qry_mvartdisp->ParamByName("cia")->AsInteger = cia_z;
    qry_mvartdisp->Open();
    dbgrd_dispo->GotoFirst();
  }
  preciomay_z = dm->calcu_prmay(codigo_z, TIPO_MAYORISTA);
  preciofil_z = dm->calcu_prmay(codigo_z, TIPO_FILIAL);
  edt_prfilial->Value = preciofil_z;
  edt_prfilialneto->Value = Round(preciofil_z * ( piva_z / 100 + 1), 100);
  //edt_prvtacext->Value = preciou_z;
  edt_costocext->Value = costo_z * ( piva_z / 100 + 1);
  edt_precioext->Value = 0;
  edt_costoext->Value = 0;
  edt_mubcext->Value = 0;
  gtia_z = "";

  qry_garantias->Close();
  qry_garantias->ParamByName("codigo")->AsString = codigo_z;
  qry_garantias->ParamByName("idrel")->AsInteger = REL_INVEN_GARANTIA;
  qry_garantias->ParamByName("cia")->AsInteger = cia_z;
  qry_garantias->Open();
  if(!qry_garantias->IsEmpty() && empaqe_z != "REMATE" ) {
    gtia_z = qry_garantias->FieldByName("clave")->AsString;
  }
  edt_garantia->Text = gtia_z;
  ctorep_z = 0;

  qry_extensa->Close();
  qry_extensa->ParamByName("codigo")->AsString = codigo_z;
  qry_extensa->ParamByName("cia")->AsInteger = cia_z;
  qry_extensa->Open();
  if(!qry_extensa->IsEmpty()) {
    ctorep_z = qry_extensa->FieldByName("costoext")->AsFloat;
  }
  if( ctorep_z == 0) {
    ctorep_z = qry_inven->FieldByName("costos")->AsFloat;
  }
  actictorep_z = "INACTIVO";
  edt_costoext->Color  = clWindow;
  edt_costocext->Color = clWindow;
  //edt_prvtacext->Color = clWindow;
  edt_mubcext->Color   = clWindow;
  edt_preciomay->Color = clWindow;
  edt_costoext->Value = 0;
  if(ctorep_z != costo_z ) {
    preciomay2_z = Redondea(ctorep_z / margenrepo_z, 100);
    actictorep_z = "ACTIVO";
    if(preciomay2_z > preciomay_z) {
      preciomay_z = preciomay2_z;
   }
    edt_costoext->Value = qry_extensa->FieldByName("costoext")->AsFloat;
  }
  // ---> Voy a Buscar Ofertas ------------
  busca_oferta(codigo_z);
  busca_outlet(codigo_z);
  busca_servicio(codigo_z);
  activar_timer();
  //edt_prvtacext->Value = preciomay_z;
  edt_costoext->Value = qry_extensa->FieldByName("costoext")->AsFloat;
  edt_costocext->Value = edt_costoext->Value;
  if (preciou_z) {
    edt_mubcext->Value = ( 1 - (ctorep_z * (piva_z /100 + 1) / preciou_z) ) * 100;
  } else {
    edt_mubcext->Value = 0;
  }
  edt_preciomay->Value = preciomay_z;
  edt_mayneto->Value = Round(preciomay_z * ( piva_z / 100 + 1), 100);
  if(ctorep_z > qry_inven->FieldByName("costos")->AsFloat) {
      // Me aseguro de evitar division entre cero
      if (preciomay_z)         mubmay_z  = ( 1 - (ctorep_z / preciomay_z) ) * 100;
      if (edt_prfilial->Value) mubfil_z  = ( 1 - (ctorep_z / edt_prfilial->Value ) ) * 100;
  } else {
      if(edt_mayneto->Value)   mubmay_z = ( 1 - (qry_inven->FieldByName("coston")->AsFloat / edt_mayneto->Value) ) * 100;
      if (edt_prfilial->Value) mubfil_z = ( 1 - (qry_inven->FieldByName("costos")->AsFloat / edt_prfilial->Value ) ) * 100;
  }
  edt_mubmay->Value = mubmay_z;
  edt_mubfilial->Value = mubfil_z;

  plazo_z =     busca_plazo(codigo_z,
      qry_inven->FieldByName("linea")->AsString,
      qry_inven->FieldByName("cod2")->AsString,
      preciou_z
  );
  plazo_z = plazo_z * 2;

  edt_plazo->Text = IntToStr(plazo_z) + " Q";
  // Area de Mostrar Observaciones de Lineas
  if(qry_obslin->Active == dsInactive) {
    antlin_z == "-1";
  } else {
    antlin_z = qry_obslin->FieldByName("linea")->AsString;
  }
  if(linea_z != antlin_z) {
    qry_obslin->Close();
    qry_obslin->ParamByName("linea")->AsString = linea_z;
    qry_obslin->ParamByName("cia")->AsInteger = cia_z;
    qry_obslin->Open();
    dbgrd_obslin->FullExpand();
  }
  dbedt_preciomds->Color = clWindow;
  acticamprecio_z = "INACTIVO";
  if(checa_si_hay_cambio_precios_articulo(codigo_z)) {
    btn_vercambiosprecio->Visible = true;
    acticamprecio_z = "ACTIVO";
  }
  activar_timer();
  pagina_z = page_detalles->ActivePage->Name;
  pagina_z = pagina_z.UpperCase();
  if(pagina_z == "TBS_IMAGENES" ) {
    Desplegar_imagen();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::activar_timer()
{
  if( actioferta_z == "ACTIVO" || actioutlet_z == "ACTIVO" || acticamprecio_z == "ACTIVO" || actictorep_z == "ACTIVO" )  {
     timer_cambioprecio->Enabled = true;
  } else {
     timer_cambioprecio->Enabled = false;
  }


}
//---------------------------------------------------------------------------

int __fastcall TForm_consuinv::busca_oferta(String codigo_z)
{
   String sql_z, fecini_z, fecfin_z, fechoy_z;
   bool detente_z, afuturo_z=false;
   int opt_z=0;
   double costou_z, piva_z, profert_z, fechamin_z;
   fechamin_z = IncMonth(hoy_z, -12);
   fechoy_z = FormatDateTime("yyyymmdd", hoy_z);
   qry_ofertas->Close();
   //qry_oferta->SQL->Text = sql_z;
   qry_ofertas->ParamByName("fechamin")->AsDateTime = fechamin_z;
   qry_ofertas->ParamByName("fecha")->AsDateTime = hoy_z;
   qry_ofertas->ParamByName("CODIGO")->AsString = codigo_z;
   qry_ofertas->ParamByName("TIPO_OFERTA")->AsString = "O";
   qry_ofertas->ParamByName("STATUS_CAMBIOPRECIO")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
   qry_ofertas->ParamByName("cia")->AsInteger = cia_z;
   qry_ofertas->Open();
   actioferta_z = "INACTIVO";
   detente_z = false;
   if(qry_ofertas->IsEmpty()) {
     edt_proferta->Visible = false;
     btn_ofertas->Visible = false;
   } else {
       btn_ofertas->Visible = true;
       while(!qry_ofertas->Eof) {
         fecini_z = FormatDateTime("yyyymmdd", qry_ofertas->FieldByName("fecini")->AsDateTime );
         fecfin_z = FormatDateTime("yyyymmdd", qry_ofertas->FieldByName("fecfin")->AsDateTime );
         profert_z = qry_ofertas->FieldByName("precmds")->AsFloat;
         if(fechoy_z >= fecini_z && fechoy_z <= fecfin_z) {
           detente_z = true;
           profert_z = qry_ofertas->FieldByName("precmds")->AsFloat;
           afuturo_z = false;
           break;
         } else {
           afuturo_z = true;
           profert_z = qry_ofertas->FieldByName("precmds")->AsFloat;
           break;
           //if(qry_ofertas->Eof) detente_z = true;
         }
         qry_ofertas->Next();

       }

     //profert_z = qry_ofertas->FieldByName("precmds")->AsFloat;
     costou_z = qry_inven->FieldByName("costos")->AsFloat;
     // Si el CostoReposicion es activo, tomo el costo de reposicion
     if( actictorep_z == "ACTIVO" ) {
       if(edt_costoext->Value > costou_z ) {
          costou_z = edt_costoext->Value;
       }
     }
     piva_z = qry_inven->FieldByName("piva")->AsFloat;
     edt_proferta->Visible = true;
     btn_ofertas->Visible = true;
     edt_inioferta->Text = FormatDateTime("dd/mm/yyyy", qry_ofertas->FieldByName("fecini")->AsDateTime);
     edt_finoferta->Text = FormatDateTime("dd/mm/yyyy", qry_ofertas->FieldByName("fecfin")->AsDateTime);
     edt_proferta->Text = FormatFloat("$###,##0.00", profert_z);
     if (profert_z) edt_mubofert->Value  = ( 1 - (costou_z * (piva_z /100 + 1) / profert_z) ) * 100;
     // 30 de Nov 2020. Según que siempre si debo mostrar el precio de Oferta Vigente
     if (afuturo_z == true) edt_proferta->Text = "PROXIMO";
     if (qry_ofertas->RecordCount > 1 || afuturo_z == true) {
       actioferta_z = "ACTIVO";
       btn_ofertas->Visible = true;
       desplegar_ofertas->Visible = true;
     } else {
       edt_proferta->Color = clWindow;
       edt_inioferta->Color = edt_proferta->Color;
       edt_finoferta->Color = edt_proferta->Color;
       edt_mubofert->Color = edt_proferta->Color;
       btn_ofertas->Visible = false;
     }
   }

   activar_timer();
   lbl_oferta->Visible = edt_proferta->Visible;
   lbl_inivig->Visible = edt_proferta->Visible;
   edt_inioferta->Visible = edt_proferta->Visible;
   lbl_finvig->Visible = edt_proferta->Visible;
   edt_finoferta->Visible = edt_proferta->Visible;
   edt_mubofert->Visible = edt_proferta->Visible;
   lbl_mubofer->Visible = edt_proferta->Visible;
   return(0);
}
//---------------------------------------------------------------------------

int __fastcall TForm_consuinv::busca_oferta_historico(String codigo_z)
{
   String sql_z, fecini_z, fecfin_z, fechoy_z;
   bool detente_z;
   int opt_z=0;
   double costou_z, piva_z, profert_z, fechamin_z;
   fechamin_z = IncMonth(hoy_z, -12);
   fechoy_z = FormatDateTime("yyyymmdd", hoy_z);
   qry_historialofertas->Close();
   qry_historialofertas->ParamByName("CODIGO")->AsString = codigo_z;
   qry_historialofertas->ParamByName("TIPO_OFERTA")->AsString = "O";
   qry_historialofertas->ParamByName("cia")->AsInteger = cia_z;
   qry_historialofertas->Open();
   if(desplegarofertas_z == "SI") {
      Tdlg_okcancel* Dlg_datos;
      Dlg_datos = new Tdlg_okcancel (this);
      Dlg_datos->Caption = "Historial de las Ofertas";
      Dlg_datos->AutoSize = false;
      TDataSource *dts_ofertas = new TDataSource (this);
      dts_ofertas->DataSet = qry_historialofertas;
      TdxDBGrid *dbgrd_ofertas = new TdxDBGrid (this);
      dbgrd_ofertas->Parent = Dlg_datos->Panel1;
      dbgrd_ofertas->Align = alClient;
      dbgrd_ofertas->DataSource = dts_ofertas;
      dbgrd_ofertas->CreateDefaultColumns(qry_historialofertas, dbgrd_ofertas);
      opt_z = edgoRowSelect;
      opt_z = edgoAutoWidth;
      dbgrd_ofertas->OptionsView = dbgrd_ofertas->OptionsView << edgoRowSelect << edgoAutoWidth;
      TdxDBGridCurrencyColumn *colprecio;
      TdxDBTreeListColumn *antcolprecio;
      antcolprecio = dbgrd_ofertas->ColumnByFieldName("PRECMDS");
      delete antcolprecio;
      antcolprecio = dbgrd_ofertas->ColumnByFieldName("FECINI");
      antcolprecio->Caption = "Inicia";
      antcolprecio = dbgrd_ofertas->ColumnByFieldName("FECFIN");
      antcolprecio->Caption = "Termina";

      colprecio = new TdxDBGridCurrencyColumn (Dlg_datos);
      colprecio->ATreeList = dbgrd_ofertas;
      colprecio->FieldName = "PRECMDS";
      colprecio->Caption = "Precio Vta";
//      dbgrd_ofertas->OptionsView = dbgrd_kardex->OptionsView;
      Dlg_datos->ShowModal();
      delete colprecio;
      //delete dbgrd_ofertas;
      delete dts_ofertas;
      delete Dlg_datos;
      desplegarofertas_z = "NO";
   }
   return(0);
}
//---------------------------------------------------------------------------

int __fastcall TForm_consuinv::busca_outlet(String codigo_z)
{

   String sql_z;
   int opt_z=0;
   double costou_z, piva_z, profert_z, fechamin_z;
   fechamin_z = IncMonth(hoy_z, -12);

   qry_ofertas->Close();
   qry_ofertas->ParamByName("fechamin")->AsDateTime = fechamin_z;
   qry_ofertas->ParamByName("fecha")->AsDateTime = hoy_z;
   qry_ofertas->ParamByName("CODIGO")->AsString = codigo_z;
   qry_ofertas->ParamByName("TIPO_OFERTA")->AsString = "T";
   qry_ofertas->ParamByName("STATUS_CAMBIOPRECIO")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
   qry_ofertas->ParamByName("cia")->AsInteger = cia_z;
   qry_ofertas->Open();
   //actioferta_z = "INACTIVO";
   actioutlet_z = "INACTIVO";
   if(qry_ofertas->IsEmpty()) {
     edt_proutlet->Visible = false;
     btn_ofertas->Visible  = false;
   } else {
     actioutlet_z = "ACTIVO";
     profert_z = qry_ofertas->FieldByName("precmds")->AsFloat;
     costou_z = qry_inven->FieldByName("costos")->AsFloat;
     // Si el CostoReposicion es activo, tomo el costo de reposicion
     if( actictorep_z == "ACTIVO" ) {
       if(edt_costoext->Value > costou_z ) {
          costou_z = edt_costoext->Value;
       }
     }
     piva_z = qry_inven->FieldByName("piva")->AsFloat;
     edt_proutlet->Visible = true;
     edt_inioutlet->Text = FormatDateTime("dd/mm/yyyy", qry_ofertas->FieldByName("fecini")->AsDateTime);
     edt_finoutlet->Text = FormatDateTime("dd/mm/yyyy", qry_ofertas->FieldByName("fecfin")->AsDateTime);
     edt_proutlet->Value = profert_z;
     if (profert_z) edt_muboutlet->Value  = ( 1 - (costou_z * (piva_z /100 + 1) / profert_z) ) * 100;
     if (qry_ofertas->RecordCount > 1 ) {
       actioutlet_z = "ACTIVO";
       btn_ofertas->Visible = true;
     } else {
       edt_proutlet->Color = clWindow;
       edt_inioutlet->Color = edt_proutlet->Color;
       edt_finoutlet->Color = edt_proutlet->Color;
       edt_muboutlet->Color = edt_proutlet->Color;
       btn_ofertas->Visible = false;
     }
   }
   activar_timer();
   lbl_outlet->Visible    = edt_proutlet->Visible;
   lbl_inioutlet->Visible = edt_proutlet->Visible;
   edt_inioutlet->Visible = edt_proutlet->Visible;
   lbl_finoutlet->Visible = edt_proutlet->Visible;
   edt_finoutlet->Visible = edt_proutlet->Visible;
   edt_muboutlet->Visible = edt_proutlet->Visible;
   lbl_muboutlet->Visible = edt_proutlet->Visible;
   if(desplegarofertas_z == "SI") {
      Tdlg_okcancel* Dlg_datos;
      Dlg_datos = new Tdlg_okcancel (this);
      Dlg_datos->Caption = "Datos de Outlet";
      Dlg_datos->AutoSize = false;
      TDataSource *dts_ofertas = new TDataSource (this);
      dts_ofertas->DataSet = qry_ofertas;
      TdxDBGrid *dbgrd_ofertas = new TdxDBGrid (this);
      dbgrd_ofertas->Parent = Dlg_datos->Panel1;
      dbgrd_ofertas->Align = alClient;
      dbgrd_ofertas->DataSource = dts_ofertas;
      dbgrd_ofertas->CreateDefaultColumns(qry_ofertas, dbgrd_ofertas);
      opt_z = edgoRowSelect;
      opt_z = edgoAutoWidth;
      dbgrd_ofertas->OptionsView = dbgrd_ofertas->OptionsView << edgoRowSelect << edgoAutoWidth;
      TdxDBGridCurrencyColumn *colprecio;
      TdxDBTreeListColumn *antcolprecio;
      antcolprecio = dbgrd_ofertas->ColumnByFieldName("PRECMDS");
      delete antcolprecio;
      antcolprecio = dbgrd_ofertas->ColumnByFieldName("FECINI");
      antcolprecio->Caption = "Inicia";
      antcolprecio = dbgrd_ofertas->ColumnByFieldName("FECFIN");
      antcolprecio->Caption = "Termina";

      colprecio = new TdxDBGridCurrencyColumn (Dlg_datos);
      colprecio->ATreeList = dbgrd_ofertas;
      colprecio->FieldName = "PRECMDS";
      colprecio->Caption = "Precio Vta";
//      dbgrd_ofertas->OptionsView = dbgrd_kardex->OptionsView;
      Dlg_datos->ShowModal();
      delete colprecio;
      //delete dbgrd_ofertas;
      delete dts_ofertas;
      delete Dlg_datos;
      desplegarofertas_z = "NO";
   }
   return(0);
}
//---------------------------------------------------------------------------


int __fastcall TForm_consuinv::busca_plazo(String codigo_z, String linea_z, String grupo_z, double precio_z)
{
  int plazo_z=0, tipopzo_z=0, plazolin_z=0;
  bool buscaotro_z = true;
  qry_plazoxarticulo->Close();
  qry_plazoxarticulo->ParamByName("codigo")->AsString = codigo_z;
  qry_plazoxarticulo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_ARTICULO;
  qry_plazoxarticulo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxarticulo->Open();
  if(!qry_plazoxarticulo->IsEmpty()) {
    plazo_z = qry_plazoxarticulo->FieldByName("plazomax")->AsInteger;
    return (plazo_z);
  }
  qry_plazoxgrupo->Close();
  qry_plazoxgrupo->ParamByName("codigo")->AsString = grupo_z;
  qry_plazoxgrupo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_GRUPO_PRIORIDAD;
  qry_plazoxgrupo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxgrupo->Open();
  if(!qry_plazoxgrupo->IsEmpty()) {
    plazo_z = qry_plazoxgrupo->FieldByName("plazomax")->AsInteger;
    return (plazo_z);
  }
  qry_plazoxlin->Close();
  qry_plazoxlin->ParamByName("linea")->AsString = linea_z;
  qry_plazoxlin->ParamByName("tipo")->AsInteger = TIPO_PLAZO_LINEA_PRIORIDAD;
  qry_plazoxlin->ParamByName("tipo4")->AsInteger = TIPO_PLAZO_LINEA_X_TABLA;
  qry_plazoxlin->ParamByName("tipo2")->AsInteger = TIPO_PLAZO_LINEA_X_GRUPO;
  qry_plazoxlin->ParamByName("tipo3")->AsInteger = TIPO_PLAZO_X_GRUPOX_TABLA;
  qry_plazoxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxlin->Open();
  if(!qry_plazoxlin->IsEmpty()) {
    plazo_z = qry_plazoxlin->FieldByName("plazomax")->AsInteger;
    tipopzo_z = qry_plazoxlin->FieldByName("tipo")->AsInteger;
    plazolin_z = plazo_z;
    if(tipopzo_z == TIPO_PLAZO_LINEA_PRIORIDAD) return (plazo_z);
  }
  qry_plazoxprecio->Close();
  qry_plazoxprecio->ParamByName("precio")->AsFloat = precio_z;
  qry_plazoxprecio->ParamByName("tipo")->AsInteger = TIPO_PLAZO_PRECIO;
  qry_plazoxprecio->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxprecio->Open();
  if(plazo_z > qry_plazoxprecio->FieldByName("plazomax")->AsInteger) {
    plazo_z = qry_plazoxprecio->FieldByName("plazomax")->AsInteger;
  } // Esto para que no me confunda de IF. o;o
  qry_plazoxgrupo->Close();
  qry_plazoxgrupo->ParamByName("codigo")->AsString = grupo_z;
  qry_plazoxgrupo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_GRUPO;
  qry_plazoxgrupo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxgrupo->Open();
  if(!qry_plazoxgrupo->IsEmpty() && plazo_z > qry_plazoxgrupo->FieldByName("plazomax")->AsInteger) {
    plazo_z = qry_plazoxgrupo->FieldByName("plazomax")->AsInteger;
  } // Esto para que no me confunda de IF. o;o
  return (plazo_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
     busca_cod(edt_codigo->Text.Trim());
     if(qry_inven->IsEmpty()) {
       qry_buscod->Close();
       qry_buscod->ParamByName("codigo")->AsString = edt_codigo->Text.Trim() + "%%";
       qry_buscod->ParamByName("eximin")->AsInteger = eximin_z;
       qry_buscod->ParamByName("eximax")->AsInteger = eximax_z;
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
           ActiveControl=lkcmb_codigos;
         }
      }
   }
}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  if(orden_z) delete orden_z;
  Action = caFree;
  String config_z, alm_z, codigo_z;
  if(qry_almreps->State != dsInactive) {
    config_z = dm->busca_inifile();
    dbgrd_kardex->SaveToIniFile(config_z);
    dbgrd_estadis->SaveToIniFile(config_z);
    dbgrd_exist->SaveToIniFile(config_z);
    dbgrd_dispo->SaveToIniFile(config_z);
    dbgrd_busserie->SaveToIniFile(config_z);
    alm_z = qry_almreps->FieldByName("alm")->AsString;
    codigo_z = qry_inven->FieldByName("codigo")->AsString;
    TIniFile *ini;
    ini = new TIniFile(config_z);
    ini->WriteString( "Form_consuinv", "ALMACEN", alm_z );
    ini->WriteString( "Form_consuinv", "CODIGO", codigo_z);
    delete ini;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::qry_invenCalcFields(TDataSet *DataSet)
{
  String strfec_z, msg_z, codigo_z;
  int maximo_z=0, maximomay_z=0, maximoant_z=0, anuant_z,
    univtasmen_z=0, univtasmay_z=0, univta_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  if(qry_inven->FieldByName("precio")->AsFloat)
    qry_inven->FieldByName("mubmds")->AsFloat = 100 * (1 -(qry_inven->FieldByName("coston")->AsFloat / qry_inven->FieldByName("precio")->AsFloat));
  if (qry_inven->FieldByName("precelec")->AsFloat)
    qry_inven->FieldByName("mubelec")->AsFloat = (1 - (qry_inven->FieldByName("coston")->AsFloat / qry_inven->FieldByName("precelec")->AsFloat)) * 100;

  univta_z = qry_inven->FieldByName("salvtas")->AsFloat +
    qry_inven->FieldByName("salvtan")->AsFloat +
    qry_inven->FieldByName("salfons")->AsFloat +
    qry_inven->FieldByName("salfonn")->AsFloat;
  univtasmen_z = busca_unidades_vendidas(codigo_z, "VENTAS_MENUDEO");

  maximo_z = inv_maximo(
    qry_inven->FieldByName("fecalta")->AsFloat, univta_z, hoy_z, inianu_z,
    maxdiasglo_z, maxdiasmen_z, univtasmen_z
  );
  univta_z = qry_inven->FieldByName("salmays")->AsFloat +
    qry_inven->FieldByName("salmayn")->AsFloat;
  univtasmay_z = busca_unidades_vendidas(codigo_z, "VENTAS_MAYOREO");

  maximomay_z = inv_maximo(
    qry_inven->FieldByName("fecalta")->AsFloat, univta_z, hoy_z, inianu_z,
    maxdiasglo_z, maxdiasmay_z, univtasmay_z
  );

  maximoant_z = busca_maximoant(codigo_z);
  msg_z = "";
  if(maximoant_z)
    msg_z = "Max Ant:" + IntToStr(maximoant_z) + " Max Act:" + IntToStr(maximo_z);
  if(maximoant_z > maximo_z) maximo_z = maximoant_z;
  lbl_maximo->Caption = msg_z;

  edt_minimo->Value = qry_inven->FieldByName("minimo")->AsInteger;
  edt_maxmen->Value = maximo_z;
  edt_maxmay->Value = maximomay_z;

  lbl_maximo->Caption = msg_z;
  qry_inven->FieldByName("maxi")->AsFloat = maximo_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::lkcmb_codigosExit(TObject *Sender)
{
  lkcmb_codigos->Visible=false;
  edt_codigo->Visible=true;
  busca_cod(qry_buscod->FieldByName("codigo")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::lkcmb_codigosKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_RETURN){
    edt_codigo->Text = lkcmb_codigos->Text.Trim();
    lkcmb_codigos->Visible=false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::FormCreate(TObject *Sender)
{
  int busxexis_z=0, ii_z=0, essuma_z=0;
  String alm_z, status_z, config_z, codigo_z, permisalta_z,
    activos_z, inactivos_z;
  itemsub_z = 0, estado_z = 0;
  cia_z = dm->cia_z;
  permis_z=dm->busca_permision(CONSULTA_INVEN);
  permisalta_z = dm->busca_permision(MANTOINV);
  nuevo_articulo->Visible = false;
  modif_articulo->Visible = false;
  if(permisalta_z == "T" || permisalta_z == "A" || dm->usermaster_z == "S" ) nuevo_articulo->Visible = true;
  if(permisalta_z == "T" || permisalta_z == "M" || dm->usermaster_z == "S" ) modif_articulo->Visible = true;
  if(permisalta_z == "T" || permisalta_z == "M" || dm->usermaster_z == "S" ) modif_ctorep->Visible = true;
  cmb_estadi2->Enabled = chk_estadis2->Checked;
  edt_codestadi2->Enabled = chk_estadis2->Checked;

  // Alinea edt_proferta a la derecha
  HWND h = edt_proferta->Handle;
  SetWindowLong(h, GWL_STYLE, GetWindowLong(h, GWL_STYLE) | ES_RIGHT);

  //if(permis_z == "N") {
  //  dm->MensajeError("No puede acceder a este módulo", "Permisión Incorrecta");
  //  Close();
  ////}

  hoy_z = StrToDate(DateToStr(dm->ahora()));
  inianu_z = dm->inianuestadis();
  config_z = dm->config_z;
  String sqlexigrd_z;
  if(qry_alms->State == dsInactive) {
    qry_alms->Close();
    qry_alms->ParamByName("cia")->AsInteger = cia_z;
    qry_alms->Open();
  }
  sqlexigrd_z = "select codigo, descri as descripcion, precio, coston, 0.00 as mub, ";
  for(qry_alms->First(); !qry_alms->Eof; qry_alms->Next()) {
    if(qry_alms->FieldByName("status")->AsString == "A") {
      sqlexigrd_z += " 0 as xx"+qry_alms->FieldByName("alm")->AsString + ",";
    }
  }
  sqlexigrd_z += "maximo, maximo as maximay, ";
  sqlexigrd_z += "0  as oferta, ";
  sqlexigrd_z += "0 as total from inven where codigo = '-1' ";
  qry_exigrid->Close();
  qry_exigrid->SQL->Text = sqlexigrd_z;
  qry_exigrid->Open();

  dbgrd_exist->CreateDefaultColumns(dbgrd_exist->DataSource->DataSet, dbgrd_exist);
  TdxDBGridCurrencyColumn *colcosto;
  TdxDBGridMaskColumn *colmax;
  TdxDBGridMaskColumn *colmaxmay;
  TdxDBTreeListColumn *antcolcosto;
  TdxDBGridMaskColumn *colmub;
  TdxDBGridCurrencyColumn *colofert;

  antcolcosto = dbgrd_exist->ColumnByFieldName("COSTON");
  delete antcolcosto;
  colcosto = new TdxDBGridCurrencyColumn (this);
  colcosto->ATreeList = dbgrd_exist;
  colcosto->FieldName = "COSTON";
  colcosto->Caption = "Costo U.";

  antcolcosto = dbgrd_exist->ColumnByFieldName("PRECIO");
  delete antcolcosto;
  colcosto = new TdxDBGridCurrencyColumn (this);
  colcosto->ATreeList = dbgrd_exist;
  colcosto->FieldName = "PRECIO";
  colcosto->Caption = "Precio Lista";

  antcolcosto = dbgrd_exist->ColumnByFieldName("OFERTA");
  delete antcolcosto;
  colofert = new TdxDBGridCurrencyColumn (this);
  colofert->ATreeList = dbgrd_exist;
  colofert->FieldName = "oferta";
  colofert->Caption = "Oferta";
  colofert->ColIndex = dbgrd_exist->ColumnCount-1;
  //delete colofert;
  

  antcolcosto = dbgrd_exist->ColumnByFieldName("MAXIMO");
  delete antcolcosto;
  colmax = new TdxDBGridMaskColumn (this);
  colmax->ATreeList = dbgrd_exist;
  colmax->FieldName = "MAXIMO";
  colmax->Caption = "MxMen";

  antcolcosto = dbgrd_exist->ColumnByFieldName("MAXIMAY");
  delete antcolcosto;
  colmaxmay = new TdxDBGridMaskColumn (this);
  colmaxmay->ATreeList = dbgrd_exist;
  colmaxmay->FieldName = "MAXIMAY";
  colmaxmay->Caption = "MxMay";

  colmub = new TdxDBGridMaskColumn (this);
  colmub->ATreeList = dbgrd_exist;
  colmub->FieldName = "MUB";
  colmub->Caption = "Mub";
  delete colmub;


  antcolcosto = dbgrd_exist->ColumnByFieldName("CODIGO");
  antcolcosto->Caption = "Código";

  ii_z = dbgrd_exist->ColumnCount - 2;
//  dbgrd_exist->Columns[ii_z]->DecimalPlaces = 2;
//  dbgrd_exist->Columns[ii_z]->FieldName("COSTO");
//  (*TdxDBGridCurrencyColumn)(dbgrd_exist->Columns[ii_z])->Properties->DisplayFormat("$,0.00;-$,0.00");
  for(ii_z=0; ii_z < dbgrd_exist->ColumnCount; ii_z++) {
    essuma_z=0;
    alm_z = dbgrd_exist->Columns[ii_z]->Caption;
    if(alm_z.SubString(1, 2).UpperCase() == "XX") {
      alm_z = alm_z.SubString(3, alm_z.Length() -2 );
      essuma_z = 1;
      dbgrd_exist->Columns[ii_z]->Width = dbgrd_exist->Columns[ii_z]->MinWidth;
    }
    if(alm_z == "TOTAL" || alm_z == "VENTAS" ) essuma_z = 1;
    if(essuma_z) {
      dbgrd_exist->Columns[ii_z]->SummaryFooterField = dbgrd_exist->Columns[ii_z]->FieldName;  //Set the field which values will be summarized in the footer cell
      dbgrd_exist->Columns[ii_z]->SummaryFooterType = cstSum;  //Set the summary type (SUM)
      dbgrd_exist->Columns[ii_z]->SummaryFooterFormat = "0";  //Set the summary format
    }
    if(alm_z.Length() > 2) alm_z = alm_z.SubString(1, 1) + alm_z.SubString(2, alm_z.Length() -1).LowerCase();
    dbgrd_exist->Columns[ii_z]->Caption = alm_z;
  }
  //dbgrd_exist->ColumnByFieldName("CODIGO")->Width = dbgrd_exist->Canvas->TextWidth("O") * 13;
  //dbgrd_exist->ColumnByFieldName("DESCRIPCION")->Width = dbgrd_exist->Canvas->TextWidth("O") * 25;
  //dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("VENTAS"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("COSTON"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("MAXIMO"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("MAXIMAY"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("TOTAL"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("PRECIO"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("MUB"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("OFERTA"));

  sgrd_exist->ColumnHeaders->Clear();
  sgrd_exist->ColCount = qry_alms->RecordCount + 2;
  ii_z = 0;
  for(qry_alms->First(); !qry_alms->Eof; qry_alms->Next() ) {
    alm_z = qry_alms->FieldByName("alm")->AsString;
    status_z = qry_alms->FieldByName("status")->AsString;
    if(status_z == "A") {
      ii_z++;
      sgrd_exist->ColumnHeaders->Add(alm_z);
    }
  }
  sgrd_exist->ColumnHeaders->Add("Tot");
  sgrd_exist->ColCount = ii_z + 2;
  sgrd_exist->DefaultColWidth = (Width - 2) / sgrd_exist->ColCount;
  cmb_tipoestadi->ItemIndex = CMB_SAL_VTA;
  cmb_tipoexis->ItemIndex = EXI_GRUPO;
  cmb_gpoestadis->ItemIndex = EXI_CODIGO;
  TDateTime fecha_z = Now();
  Word anu_z, mes_z, dia_z;
  DecodeDate(fecha_z, anu_z, mes_z, dia_z);
  edt_anuestadis->IntValue=anu_z;
  //TODO: PONGO LA DESCRIPCION AL ULTIMO DEL GRID - FRB - 2005-10-17
  dbgrd_exist->Columns[1]->ColIndex = dbgrd_exist->ColumnCount;
  //dbgrd_exist->Columns[1]->Visible = false;
  dbgrd_exist->Columns[1]->ColIndex = dbgrd_exist->ColumnCount-2;

  Form_dlgcriterio = NULL;
  orden_z = new TStringList ();
  orden_z->Clear();
  WindowState = wsMaximized;
  dbgrd_kardex->LoadFromIniFile(config_z);
  dbgrd_estadis->LoadFromIniFile(config_z);
  dbgrd_exist->LoadFromIniFile(config_z);
  dbgrd_dispo->LoadFromIniFile(config_z);
  dbgrd_busserie->LoadFromIniFile(config_z);
  TIniFile *ini;
  ini = new TIniFile(config_z);
  alm_z      =  ini->ReadString( "Form_consuinv", "ALMACEN", alm_z );
  codigo_z   =  ini->ReadString( "Form_consuinv", "CODIGO", codigo_z );
  busxexis_z = ini->ReadInteger("BUSQUEDAS", "BUSXEXIS", 0);
  activos_z = ini->ReadString( "Form_consuinv", "ALMACENES_ACTIVOS", "A");
  inactivos_z = ini->ReadString( "Form_consuinv", "ALMACENES_INACTIVOS", "B");
  margenrepo_z = ini->ReadFloat( "Form_consuinv", "MARGEN_CTOREP", 0.92);
  maxdiasglo_z = ini->ReadInteger("MAXIMOS", "DIAS_GLOBAL",  30);
  maxdiasmen_z = ini->ReadInteger("MAXIMOS", "DIAS_MENUDEO", 90);
  maxdiasmay_z = ini->ReadInteger("MAXIMOS", "DIAS_MAYOREO", 60);
  if(busxexis_z == 0) { eximin_z = 0; eximax_z = -1; }
  if(busxexis_z == 1) { eximin_z = -1; eximax_z = -1; }
  if(busxexis_z == 2) { eximin_z = 10000; eximax_z = 0; }
  status_z = "\\\\melvin\\Documents\\html\\fotos";
  directorioimgs_z =  ini->ReadString( "Form_consuinv", "DIRECTORIO_IMAGENES", "-1");
  if( directorioimgs_z == "-1") {
    directorioimgs_z = status_z;
    ini->WriteString( "Form_consuinv", "DIRECTORIO_IMAGENES", directorioimgs_z);
  }
  qry_almreps->Close();
  qry_almreps->ParamByName("cia")->AsInteger     = cia_z;
  qry_almreps->ParamByName("activo")->AsString   = activos_z;
  qry_almreps->ParamByName("inactivo")->AsString = inactivos_z;
  qry_almreps->Open();
  lkcmb_alm->KeyValue = qry_almreps->FieldByName("alm")->AsString;
  delete ini;
  lkcmb_alm->KeyValue = alm_z;
  busca_cod(codigo_z);
  checa_cambios_precios();

}

//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::borraExecute(TObject *Sender)
{
/*
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  qry_vendedr->Close();
  qry_vendedr->ParamByName("codigo")->AsString=edt_codvnd->Text.Trim();
  qry_vendedr->ParamByName("cia")->AsInteger=cia_z;
  qry_vendedr->Open();
  if(qry_vendedr->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Vendedor ?", "Eliminar Vendedor", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->cartera->StartTransaction();
      qry_vendedr->Delete();
      qry_vendedr->ApplyUpdates();
      dm->cartera->Commit();
    } catch (Exception &E)
    {
      dm->cartera->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
*/
}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::cancelarExecute(TObject *Sender)
{
//  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::grabarExecute(TObject *Sender)
{
/*
  botones_onoff(VISIBLES);
  switch(btn_aceptar->Tag) {
    case ALTAS: alta_vnd(); break;
    case MODIF: modif_vnd(); break;
  }
*/
}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::modificaExecute(TObject *Sender)
{
/*
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  busca_vnd(edt_codvnd->Text.Trim());
  if(qry_vendedr->IsEmpty()) return;
*/
}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::nuevoExecute(TObject *Sender)
{
/*
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  btn_aceptar->Tag = NUEVO;
  botones_onoff(INVISIBLES);
*/
}
//---------------------------------------------------------------------------
String  __fastcall TForm_consuinv::toma_criterios(String criterios_z)
{
  int campo_z=-1, operador_z=-1;
  campo_z=StrToIntDef(criterios_z.SubString(1, 2), 0);
  String result_z, linea_z, grupo_z, prove_z, precio_z, tmp_z;
  if(qry_inven->State != dsInactive) {
    linea_z = qry_inven->FieldByName("linea")->AsString;
    grupo_z = qry_inven->FieldByName("cod2")->AsString;
    prove_z = qry_inven->FieldByName("prove")->AsString;
    precio_z = FormatFloat("0.00", qry_inven->FieldByName("precio")->AsFloat);
  }
  if(campo_z) {
    switch (campo_z) {
      case 1: result_z=" linea ";   tmp_z="'" + linea_z + "'"; break;
      case 2: result_z=" cod2 ";   tmp_z="'" + grupo_z + "'"; break;
      case 3: result_z=" prove ";  tmp_z="'" + prove_z + "'"; break;
      case 4: result_z=" precio "; tmp_z =    precio_z; break;
    }
    operador_z=StrToIntDef(criterios_z.SubString(4, 1), 0);
    switch (operador_z) {
      case 0: result_z +=" = "; break;
      case 1: result_z +=" >= "; break;
      case 2: result_z +=" > "; break;
      case 3: result_z +=" < "; break;
      case 4: result_z +=" <= "; break;
      case 5: result_z +=" <> "; break;
    }
    result_z += tmp_z;
  }
  return (result_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::primeroExecute(TObject *Sender)
{
  mueve_hacia("PRIMERO");
}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::anteriorExecute(TObject *Sender)
{
  mueve_hacia("ANTERIOR");
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::siguienteExecute(TObject *Sender)
{
  mueve_hacia("SIGUIENTE");
}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::ultimoExecute(TObject *Sender)
{
  mueve_hacia("ULTIMO");
}
//-------------------------------------------------------------------------

void __fastcall TForm_consuinv::mueve_hacia(String hacia_z)
{
  int jj_z=0;
  String misql_z;
  misql_z= "select ";
  if( hacia_z == "PRIMERO")   { misql_z += "min (codigo)"; }
  if( hacia_z == "ANTERIOR")  { misql_z += "max (codigo)"; }
  if( hacia_z == "SIGUIENTE") { misql_z += "min (codigo)"; }
  if( hacia_z == "ULTIMO")    { misql_z += "max (codigo)"; }
  misql_z += " as codigo from inven where ";
  if( hacia_z == "PRIMERO")   { misql_z += " codigo > ''"; }
  if( hacia_z == "ANTERIOR")  { misql_z += " codigo < '"+edt_codigo->Text.Trim()+"'"; }
  if( hacia_z == "SIGUIENTE") { misql_z += " codigo > '"+edt_codigo->Text.Trim()+"'"; }
  if( hacia_z == "ULTIMO")    { misql_z += " codigo > ''"; }
  misql_z += " and ";

  for(jj_z=0; jj_z < orden_z->Count; ++jj_z) {
    misql_z += toma_criterios(orden_z->Strings[jj_z]);
    misql_z += " and ";
  }
  misql_z += " cia="+IntToStr(cia_z);
  //Memo1->Text = sql_z;
  qry_haciainv->Close();
  qry_haciainv->SQL->Clear();
  qry_haciainv->SQL->Add(misql_z);
  qry_haciainv->Open();
  if(qry_haciainv->IsEmpty()) return;
  if(qry_haciainv->FieldByName("codigo")->AsString.IsEmpty()) return;
  busca_cod(qry_haciainv->FieldByName("codigo")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::busca_movarts()
{
  String codigo_z, alm_z;
  if(qry_inven->State == dsInactive) return;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  alm_z = qry_almreps->FieldByName("alm")->AsString;
  if(qry_movart->State != dsInactive) {
    if(qry_movart->FieldByName("alm")->AsString == alm_z &&
       qry_movart->FieldByName("codigo")->AsString == codigo_z) return;
  }
  qry_movart->Close();
  qry_movart->ParamByName("codigo")->AsString = codigo_z;
  qry_movart->ParamByName("alm")->AsString = alm_z;
  qry_movart->ParamByName("cia")->AsInteger = cia_z;
  qry_movart->Open();

}
//---------------------------------------------------------------------------
void __fastcall TForm_consuinv::btn_estadisClick(TObject *Sender)
{
  String sql_z, estadialm_z,
     strmes_z, almac_z, sqlwhere2_z="", sqlestadi2_z = "", sqlestadialm2_z = "",
     codestadi2_z;
  int tipo1_z= -1, tipo2_z = -1, tipo3_z = -1, tipo4_z = -1, tipo5_z = -1,
    tipoestadi_z=0, nummes_z=0, anuestadis_z=0, esteanu_z=0;
  TLocateOptions Opts;
  Opts.Clear();

  tipoestadi_z = cmb_tipoestadi->ItemIndex;
  anuestadis_z = edt_anuestadis->Value;
  esteanu_z = FormatDateTime("yyyy", inianu_z).ToInt();
  switch (tipoestadi_z) {
    case CMB_SAL_ESP   : tipo1_z = EST_X_SAL_ESP; break;
    case CMB_SAL_VTA   :
      tipo1_z = EST_X_VTA_TRAD;
      tipo2_z = EST_X_VTA_FON;
      tipo3_z = EST_X_VTA_FID;
      tipo4_z = EST_X_VTA_CEL;
      tipo5_z = EST_X_VTA_IMEVI;
      break;
    case CMB_ENT_CAN   :
       tipo1_z = EST_X_CAN_TRAD; tipo2_z = EST_X_CAN_FON;
       tipo3_z = EST_X_CAN_FID; tipo4_z = EST_X_CAN_CEL;
      break;
    case CMB_ENT_ESP   : tipo1_z = EST_X_ENT_ESP; break;
    case CMB_SAL_MAY   : tipo1_z = EST_X_SAL_MAY; break;
    case CMB_ENT_COM   : tipo1_z = EST_X_ENT_COM; break;
  }
  sql_z = "select alm, 0 as Ene, 0 as Feb, 0 as Mar, 0 as Abr, 0 as May, 0 as Jun, ";
  sql_z += " 0 as Jul, 0 as Ago, 0 as Sep, 0 as Oct, 0 as Nov, 0 as Dic, 0 as Tot, d.nombre ";
  if ( chk_estadis2->Checked && cmb_gpoestadis->ItemIndex != cmb_estadi2->ItemIndex ) {
    // Quieren un Segundo criterio de estadísticas
    codestadi2_z = "'" + edt_codestadi2->Text.Trim() + "'";
    switch (cmb_estadi2->ItemIndex){
      case EXI_DIARY:
        sqlestadi2_z = " join inv_relinv nn on m.idart = nn.idart and nn.idrel = " + IntToStr(REL_INVEN_GPODIARY) +
                 " join gpodiary ee on nn.iddato = ee.idgpodiary ";
        sqlwhere2_z = " and ee.grupo like " + codestadi2_z;
        break;
    case EXI_GRUPO:
        sqlestadi2_z = " join inv_relinv nn on m.idart = nn.idart and nn.idrel = " + IntToStr(REL_INVEN_ARTDESP) +
                 " join inv_grupos ee on nn.iddato = ee.idgrupo ";
        sqlwhere2_z = " and ee.codigo like " + codestadi2_z;
        break;
    case EXI_MARCA:
        sqlestadi2_z = " join inv_relinv nn on m.idart = nn.idart and nn.idrel = " + IntToStr(REL_INVEN_MARCAS) +
                 " join inv_marcas ee on nn.iddato = ee.idmarcainv ";
        sqlwhere2_z = " and ee.codigo like " + codestadi2_z;
        break;
    case EXI_PROVE:
        sqlestadi2_z = "";
        sqlwhere2_z = " and b.prove like " + codestadi2_z;
        break;
    case EXI_SITUAC:
        sqlestadi2_z = " join inv_relinv nn on m.idart = nn.idart and nn.idrel = " + IntToStr(REL_INVEN_SITUACION) +
                 " join inv_situaciones ee on nn.iddato = ee.idsituac ";
        sqlwhere2_z = " and ee.situacion like " + codestadi2_z;
        break;
    case EXI_CODIGO:
        sqlestadi2_z = "";
        sqlwhere2_z = " and b.codigo like " + codestadi2_z;
        break;
    }
  }
  switch (cmb_gpoestadis->ItemIndex) {
    case EXI_DIARY:
       sql_z += " from estadis a join inven b on a.codigo = b.codigo and a.cia = b.cia ";
       sql_z += "join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia ";
       sql_z += " join inv_relinv n on m.idart = n.idart and n.idrel = " + IntToStr(REL_INVEN_GPODIARY) + " " +
         " join gpodiary e on n.iddato = e.idgpodiary " +
         sqlestadi2_z + busnomjoin(tipoestadi_z) +
         " where (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU and grupo like :CODIGO and a.cia = :CIA" +
         sqlwhere2_z;

      estadialm_z = "select alm, a.codigo as codigo, mes, sum(unidades) as unids ";
      estadialm_z += " from estadis a join inven b on a.codigo = b.codigo and a.cia = b.cia ";
      estadialm_z += " join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia ";
      estadialm_z += " join inv_relinv n on m.idart = n.idart and n.idrel = "+IntToStr(REL_INVEN_GPODIARY)+
         sqlestadi2_z +
         " join gpodiary e on n.iddato = e.idgpodiary " +
         " where (a.tipo = :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU and " +
         " grupo like :CODIGO " + sqlwhere2_z + " and a.cia=:CIA group by alm, a.codigo, mes";
      break;
    case EXI_GRUPO:
       sql_z += "from estadis a ";
       if(anuestadis_z == esteanu_z) {
         sql_z += " join inven b on a.codigo = b.codigo and a.cia = b.cia ";
       } else {
         sql_z += " join inv_invhist b on a.codigo = b.codigo and a.cia = b.cia ";
       }
       sql_z += " join inv_invhist m on a.codigo=m.codigo and a.cia = m.cia ";
       sql_z += " join inv_relinv n on m.idart = n.idart and n.idrel = " + IntToStr(REL_INVEN_ARTDESP) + " " +
        " join inv_grupos e on n.iddato = e.idgrupo " +
       sqlestadi2_z + busnomjoin(tipoestadi_z) +
       " where (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU and e.codigo like :CODIGO and a.cia = :CIA" +
       sqlwhere2_z;

      estadialm_z = "select alm, a.codigo as codigo, mes, sum(unidades) as unids from estadis a ";
      if(anuestadis_z == esteanu_z) {
        estadialm_z += " join inven b on a.codigo = b.codigo and a.cia = b.cia ";
      } else {
        estadialm_z += " join inv_invhist b on a.codigo = b.codigo and a.cia = b.cia ";
      }
      estadialm_z += " join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia ";
      estadialm_z += " join inv_relinv n on m.idart = n.idart and n.idrel = " + IntToStr(REL_INVEN_ARTDESP) + " ";
      estadialm_z += " join inv_grupos e on n.iddato = e.idgrupo ";
      estadialm_z += sqlestadi2_z;
      estadialm_z +=" where (a.tipo = :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU " +
       sqlwhere2_z + " and e.codigo like :CODIGO and a.cia=:CIA " +
       " group by alm, a.codigo, mes";
      break;
    case EXI_MARCA:
      sql_z += "from estadis a ";
       if(anuestadis_z == esteanu_z) {
         sql_z += " join inven b on a.codigo = b.codigo and a.cia = b.cia ";
       } else {
         sql_z += " join inv_invhist b on a.codigo = b.codigo and a.cia = b.cia ";
       }
       sql_z += " join inv_invhist m on a.codigo=m.codigo and a.cia = m.cia ";
       sql_z += " join inv_relinv e on m.idart = e.idart and e.idrel = "+IntToStr(REL_INVEN_MARCAS)+
       " join inv_marcas c on e.iddato = c.idmarcainv " +
       sqlestadi2_z + busnomjoin(tipoestadi_z) +
       " where (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) " +
       sqlwhere2_z + " and anu = :ANU and c.codigo like :CODIGO and a.cia = :CIA";

      estadialm_z = "select alm, a.codigo as codigo, mes, sum(unidades) as unids \
          from estadis a ";
      if(anuestadis_z == esteanu_z) {
         sql_z += " join inven b on a.codigo = b.codigo and a.cia = b.cia ";
      } else {
         sql_z += " join inv_invhist b on a.codigo = b.codigo and a.cia = b.cia ";
      }
      sql_z += " join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia \
       join inv_relinv e on m.idart = e.idart and e.idrel = "+IntToStr(REL_INVEN_MARCAS)+
       " join inv_marcas c on e.iddato = c.idmarcainv " + sqlestadi2_z +
       " where (a.tipo = :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU " +
       sqlwhere2_z + " and c.codigo like :CODIGO and a.cia=:CIA group by alm, a.codigo, mes";
      break;
    case EXI_PROVE:
      sql_z +="from estadis a join inven b on a.codigo=b.codigo and a.cia = b.cia ";
      sql_z += " join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia " +
        sqlestadi2_z + busnomjoin(tipoestadi_z) +
        " where (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU and b.prove like :CODIGO and a.cia = :CIA " +
      sqlwhere2_z;

      estadialm_z = "select alm, a.codigo as codigo, mes, sum(unidades) as unids \
         from estadis a join inven b on a.codigo = b.codigo and a.cia = b.cia ";
      estadialm_z += " join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia ";
      estadialm_z += sqlestadi2_z;
      estadialm_z += " where (a.tipo = :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU ";
      estadialm_z += " and b.prove like :CODIGO and a.cia=:CIA ";
      estadialm_z += sqlwhere2_z;
      estadialm_z += " group by alm, a.codigo, mes";
      break;
    case EXI_SITUAC:
      sql_z += "from estadis a join inven b on a.codigo = b.codigo and a.cia = b.cia ";
      sql_z += " join inv_invhist m on a.codigo=m.codigo and a.cia = m.cia ";
      sql_z += " join inv_relinv e on m.idart = e.idart and e.idrel = "+IntToStr(REL_INVEN_SITUACION);
      sql_z += " join inv_situaciones c on e.iddato = c.idsituac ";
      sql_z += sqlestadi2_z + busnomjoin(tipoestadi_z);
      sql_z += " where (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) ";
      sql_z += " and anu = :ANU and c.situacion like :CODIGO and a.cia = :CIA";
      sql_z += sqlwhere2_z;

      estadialm_z = "select alm, a.codigo as codigo, mes, sum(unidades) as unids \
      from estadis a join inven b on a.codigo = b.codigo and a.cia = b.cia \
       join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia \
       join inv_relinv e on m.idart = e.idart and e.idrel = "+IntToStr(REL_INVEN_SITUACION)+
       " join inv_situaciones c on e.iddato = c.idsituac ";
       estadialm_z += sqlestadi2_z;
       estadialm_z += " where (a.tipo = :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5)";
       estadialm_z += " and anu = :ANU and c.situacion like :CODIGO and a.cia=:CIA ";
       estadialm_z += sqlwhere2_z + "group by alm, a.codigo, mes";
      break;
    case EXI_CODIGO:
        sql_z += "from estadis a join inven b on a.codigo = b.codigo and a.cia = b.cia ";
        sql_z += " join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia ";
        sql_z +=  sqlestadi2_z + busnomjoin(tipoestadi_z);
        sql_z += " where (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU and a.codigo like :CODIGO and a.cia = :CIA";
        sql_z += sqlwhere2_z;

        estadialm_z = "select alm, a.codigo as codigo, mes,sum(unidades) as unids ";
        estadialm_z += " from estadis a join inven b on a.codigo = b.codigo and a.cia = b.cia ";
        estadialm_z += " join inv_invhist m on a.codigo = m.codigo and a.cia = m.cia ";
        estadialm_z += sqlestadi2_z;
        estadialm_z += "  where (a.tipo = :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU ";
        estadialm_z += " and a.codigo like :CODIGO and a.cia=:CIA ";
        estadialm_z += sqlwhere2_z;
        estadialm_z += " group by alm, a.codigo, mes";
      break;
  }
  //mmo_sql->Text = sql_z + "\n" + estadialm_z;
  //sql_z += " group by alm, Ene, Feb, Mar, Abr, May, Jun, Jul, Ago, Sep, Oct, Nov, Dic, Tot, nombre";
  sql_z += " and a.alm = '-1' group by alm, nombre";
  if(edt_anuestadis->Tag) muestrasqls(sql_z, estadialm_z);

  qry_estadis->DisableControls();
  qry_estadis->Tag = mrCancel;
  qry_estadis->Close();
  qry_estadis->SQL->Text = sql_z;
  qry_estadis->ParamByName("anu")->AsInteger = edt_anuestadis->IntValue;
  qry_estadis->ParamByName("cia")->AsInteger = cia_z;
  qry_estadis->ParamByName("tipo1")->AsInteger = tipo1_z;
  qry_estadis->ParamByName("tipo2")->AsInteger = tipo2_z;
  qry_estadis->ParamByName("tipo3")->AsInteger = tipo3_z;
  qry_estadis->ParamByName("tipo4")->AsInteger = tipo4_z;
  qry_estadis->ParamByName("tipo5")->AsInteger = tipo5_z;
  qry_estadis->ParamByName("codigo")->AsString = edt_codestad->Text.Trim();
  qry_estadis->Open();
  qry_estadialm->Close();
  qry_estadialm->SQL->Text = estadialm_z;
  qry_estadialm->ParamByName("anu")->AsInteger = edt_anuestadis->IntValue;
  qry_estadialm->ParamByName("cia")->AsInteger = cia_z;
  qry_estadialm->ParamByName("tipo1")->AsInteger = tipo1_z;
  qry_estadialm->ParamByName("tipo2")->AsInteger = tipo2_z;
  qry_estadialm->ParamByName("tipo3")->AsInteger = tipo3_z;
  qry_estadialm->ParamByName("tipo4")->AsInteger = tipo4_z;
  qry_estadialm->ParamByName("tipo5")->AsInteger = tipo5_z;
  qry_estadialm->ParamByName("codigo")->AsString = edt_codestad->Text.Trim();
  qry_estadialm->Open();
//  Variant locvalues[1];

  for(qry_estadialm->First(); !qry_estadialm->Eof; qry_estadialm->Next()) {
//    locvalues[0] = Variant(qry_estadialm->FieldByName("alm")->AsString);
//    locvalues[1] = Variant(qry_estadialm->FieldByName("codigo")->AsString);
    nummes_z = qry_estadialm->FieldByName("mes")->AsInteger;
    strmes_z = nommes(nummes_z).UpperCase().SubString(1, 3);
    almac_z = qry_estadialm->FieldByName("alm")->AsString;
    if(qry_estadis->Locate("alm", almac_z, Opts)) {
      qry_estadis->Edit();
    } else {
      qry_estadis->Append();
      qry_estadis->FieldByName("alm")->AsString = almac_z;
      qry_estadis->FieldByName("nombre")->AsString = busnombre(tipoestadi_z, almac_z);
    }
    qry_estadis->FieldByName(strmes_z)->AsInteger += qry_estadialm->FieldByName("unids")->AsInteger;
    qry_estadis->FieldByName("tot")->AsInteger += qry_estadialm->FieldByName("unids")->AsInteger;
    qry_estadis->Post();
  }
  qry_estadis->Tag = mrOk;

  qry_estadis->EnableControls();
  //dbgrdlaylst->Items[0]->AssignTo(dbgrd_estadis);
}
//---------------------------------------------------------------------------

String __fastcall TForm_consuinv::busnomjoin(int tipoestadi_z)
{
  String sql_z;
  switch (tipoestadi_z) {
    case CMB_ENT_COM   :
    case CMB_ENT_ESP   :
    case CMB_SAL_ESP   : sql_z="join almacen d on a.alm = d.clave and a.cia = d.cia"; break;
    case CMB_SAL_VTA   :
    case CMB_ENT_CAN   : sql_z="join ptovta d on a.alm = d.clave and a.cia = d.cia"; break;
    case CMB_SAL_MAY   : sql_z="join mayoris d on a.alm = d.codigo and a.cia = d.cia"; break;
  }
  return (sql_z);
}
//---------------------------------------------------------------------------

String __fastcall TForm_consuinv::busnombre(int tipoestadi_z, String codigo_z)
{
  String sql_z, nombre_z;
  switch (tipoestadi_z) {
    case CMB_ENT_COM   :
    case CMB_ENT_ESP   :
    case CMB_SAL_ESP   : sql_z="select clave as codigo, nombre from almacen where clave = :CODIGO and cia = :CIA"; break;
    case CMB_SAL_VTA   :
    case CMB_ENT_CAN   : sql_z="select clave as codigo, nombre from ptovta where clave = :CODIGO and cia = :CIA"; break;
    case CMB_SAL_MAY   : sql_z="select codigo, nombre from mayoris where codigo = :CODIGO and cia = :CIA"; break;
  }
  TQuery *qry_nombre;
  qry_nombre = new TQuery (this);
  qry_nombre->DatabaseName=qry_estadis->DatabaseName;
  qry_nombre->SQL->Text = sql_z;
  qry_nombre->ParamByName("codigo")->AsString = codigo_z;
  qry_nombre->ParamByName("cia")->AsInteger = cia_z;
  qry_nombre->Open();
  if(qry_nombre->IsEmpty())
    nombre_z = "INEXISTENTE";
  else
    nombre_z = qry_nombre->FieldByName("nombre")->AsString;
  return (nombre_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::btn_okxisClick(TObject *Sender)
{
  String sql_z="", antcod_z="-1",
    strfec_z, codigo_z="", sqlexigrd_z="", alm_z="";
  double proferta_z, fechamin_z;
  int univtasmen_z=0, univtasmay_z = 0, essuma_z, maximay_z=0,
      maximo_z=0, maximoant_z=0;
  TLocateOptions Opts;
  hoy_z = dm->ahora();
  fechamin_z = IncMonth(hoy_z, -12);

  switch (cmb_tipoexis->ItemIndex) {
    case EXI_GRUPO:
      sql_z = "select a.codigo, b.precio,\
      b.fecalta, b.costos, b.coston, b.salvtas+ b.salvtan+ b.salfons+ b.salfonn as univtas, \
      b.salmays + b.salmayn as univtamay, \
      a.alm, b.descri, (a.existes + a.existen) as exis\
      from exist a join inven b on a.codigo = b.codigo and a.cia = b.cia \
      where cod2 = :GRUPO and a.cia = :CIA and (a.existes + a.existen) <> 0 \
      order by a.codigo, alm";
      break;
    case EXI_MARCA:
      sql_z = "select a.codigo, a.alm, b.descri, b.precio, (a.existes + a.existen) as exis, \
        b.fecalta, b.costos, b.coston, b.salvtas+ b.salvtan+ b.salfons+ b.salfonn as univtas, \
        b.salmays + b.salmayn as univtamay \
        from exist a join inven b on a.codigo = b.codigo and a.cia = b.cia \
        join inv_invhist d on b.codigo = d.codigo and b.cia = d.cia \
        join inv_relinv e on d.idart = e.idart and e.idrel = "+IntToStr(REL_INVEN_MARCAS)+
        " join inv_marcas c on e.iddato = c.idmarcainv \
        where c.codigo = :GRUPO and a.cia = :CIA and (a.existes + a.existen) <> 0 \
        order by a.codigo, alm";
      break;
    case EXI_PROVE:
      sql_z = "select a.codigo, a.alm, b.descri, b.precio, (a.existes + a.existen) as exis, \
        b.fecalta, b.costos, b.coston, b.salvtas+ b.salvtan+ b.salfons+ b.salfonn as univtas, \
        b.salmays+ b.salmayn as univtamay \
        from exist a join inven b on a.codigo = b.codigo and a.cia = b.cia \
        where prove = :GRUPO and a.cia = :CIA and (a.existes + a.existen) <> 0 \
        order by a.codigo, alm";
      break;
    case EXI_SITUAC:
      sql_z = "select a.codigo, a.alm, b.descri, b.precio, (a.existes + a.existen) as exis,\
        b.fecalta, b.salmays+ b.salmayn as univtamay, \
        b.costos, b.coston, b.salvtas+ b.salvtan+ b.salfons+ b.salfonn as univtas \
        from exist a join inven b on a.codigo = b.codigo and a.cia = b.cia \
        where empaqe = :GRUPO and a.cia = :CIA and (a.existes + a.existen) <> 0 \
        order by a.codigo, alm";
      break;
    case EXI_CODIGO:
      sql_z = "select a.codigo, a.alm, b.descri, b.precio, (a.existes + a.existen) as exis, \
        b.fecalta, b.costos, b.coston, b.salmays+ b.salmayn as univtamay, \
        b.salvtas+ b.salvtan+ b.salfons+ b.salfonn as univtas \
        from exist a join inven b on a.codigo = b.codigo and a.cia = b.cia \
        where a.codigo like :GRUPO and a.cia = :CIA and (a.existes + a.existen) <> 0 \
        order by a.codigo, alm";
      break;
  }
  if(dbedt_linea->Tag) {
    muestrasqls(sql_z, sqlexigrd_z);
  }

  qry_exigrid->DisableControls();
  qry_exigrid->Close();
  qry_exigrid->Open();

  qry_exisgpo->Close();
  qry_exisgpo->SQL->Clear(); //Agregado frb - 1-Nov-2005
  qry_exisgpo->SQL->Add(sql_z); //Agregado FRB - 1-Nov-2005
  //qry_exisgpo->SQL->Text = sql_z; //Eliminado - frb - 1-Nov-2005
  qry_exisgpo->ParamByName("grupo")->AsString = edt_gpoexi->Text.Trim();
  qry_exisgpo->ParamByName("cia"  )->AsInteger = cia_z;
  qry_exisgpo->Open();

  for(qry_exisgpo->First(); !qry_exisgpo->Eof; qry_exisgpo->Next()) {
    antcod_z = qry_exisgpo->FieldByName("codigo")->AsString;
    if(!qry_exigrid->Locate("codigo", antcod_z, Opts)) {
      qry_exigrid->Append();
      qry_exigrid->FieldByName("codigo")->AsString = antcod_z;
      qry_exigrid->FieldByName("coston")->AsFloat = qry_exisgpo->FieldByName("coston")->AsFloat;
      qry_exigrid->FieldByName("precio")->AsFloat = qry_exisgpo->FieldByName("precio")->AsFloat;
      qry_exigrid->FieldByName("descripcion")->AsString = qry_exisgpo->FieldByName("descri")->AsString;
      // Voy a Buscar las Ofertas DRBR 01/Oct/2019
      qry_ofertas->Close();
         //qry_oferta->SQL->Text = sql_z;
      qry_ofertas->ParamByName("fechamin")->AsDateTime = fechamin_z;
      qry_ofertas->ParamByName("fecha")->AsDateTime = hoy_z;
      qry_ofertas->ParamByName("CODIGO")->AsString = antcod_z;
      qry_ofertas->ParamByName("TIPO_OFERTA")->AsString = "O";
      qry_ofertas->ParamByName("STATUS_CAMBIOPRECIO")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
      qry_ofertas->ParamByName("cia")->AsInteger = cia_z;
      qry_ofertas->Open();
      proferta_z = -1;
      if(!qry_ofertas->IsEmpty()) proferta_z = qry_ofertas->FieldByName("precmds")->AsFloat;
      if(proferta_z != -1) qry_exigrid->FieldByName("oferta")->AsFloat = proferta_z;

      if(qry_exisgpo->FieldByName("precio")->AsFloat)
        qry_exigrid->FieldByName("mub")->AsFloat =
        Redondea( (100 * (1 - (qry_exisgpo->FieldByName("coston")->AsFloat / qry_exisgpo->FieldByName("precio")->AsFloat))), 100);

      univtasmen_z = busca_unidades_vendidas(codigo_z, "VENTAS_MENUDEO");
      maximo_z = inv_maximo(
        qry_exisgpo->FieldByName("fecalta")->AsFloat,
        qry_exisgpo->FieldByName("univtas")->AsInteger,
        hoy_z, inianu_z, maxdiasglo_z, maxdiasmen_z, univtasmen_z
      );
      univtasmay_z = busca_unidades_vendidas(codigo_z, "VENTAS_MAYOREO");
      maximay_z = inv_maximo(
        qry_exisgpo->FieldByName("fecalta")->AsFloat,
        qry_exisgpo->FieldByName("univtamay")->AsInteger,
        hoy_z, inianu_z, maxdiasglo_z, maxdiasmay_z, univtasmay_z
      );
      maximoant_z = busca_maximoant(antcod_z);
      if(maximoant_z > maximo_z) maximo_z = maximoant_z;
      qry_exigrid->FieldByName("maximo")->AsInteger = maximo_z;
      qry_exigrid->FieldByName("maximay")->AsInteger = maximay_z;

    } else {
      qry_exigrid->Edit();
    }
    qry_exigrid->FieldByName("XX"+qry_exisgpo->FieldByName("alm")->AsString)->AsInteger += qry_exisgpo->FieldByName("exis")->AsInteger;
    qry_exigrid->FieldByName("total")->AsInteger += qry_exisgpo->FieldByName("exis")->AsInteger;
    qry_exigrid->Post();
  }
  // Ahora Aplico los detalles al grid
  int ARowsNumber, ii_z, AHeight;
  dbgrd_exist->Align = alClient;
  dbgrd_exist->Align = alNone;
  ARowsNumber = qry_exigrid->RecordCount;
  AHeight = 0;
  AHeight = dbgrd_exist->RowHeight * ARowsNumber +
    dbgrd_exist->RowSeparatorLineWidth * (ARowsNumber + 2);
  AHeight += dbgrd_exist->GroupPanelHeight + dbgrd_exist->FooterPanelHeight +
   + dbgrd_exist->HeaderHeight * 2;
  if(AHeight < dbgrd_exist->Height) dbgrd_exist->Height = AHeight;
  qry_exigrid->EnableControls();

}
//---------------------------------------------------------------------------

int __fastcall TForm_consuinv::busca_maximoant(String codigo_z)
{

  int anuant_z=0, maximoant_z=0;
  String strfec_z;
  strfec_z = FormatDateTime("mmdd", hoy_z);
  anuant_z = FormatDateTime("yyyy", hoy_z).ToInt();
  anuant_z = anuant_z - 1;

  if(strfec_z < "0301") {
    qry_haciainv->Close();
    qry_haciainv->SQL->Clear();
    qry_haciainv->SQL->Add("select unidades as maximo from estadis where codigo = :CODIGO and anu = :ANU and tipo=:TIPO and cia=:CIA");
    qry_haciainv->ParamByName("codigo")->AsString = codigo_z;
    qry_haciainv->ParamByName("anu")->AsInteger = anuant_z;
    qry_haciainv->ParamByName("cia")->AsInteger = cia_z;
    qry_haciainv->ParamByName("tipo")->AsInteger = EST_TIPO_MAXIMO;
    qry_haciainv->Open();
    if(!qry_haciainv->IsEmpty()) {
      maximoant_z = qry_haciainv->FieldByName("maximo")->AsInteger;
    }
  }
  return (maximoant_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::cmb_tipoexisChange(TObject *Sender)
{
  sel_tipoexi();
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::sel_tipoexi()
{
  if(qry_inven->State == dsInactive) return;
  switch (cmb_tipoexis->ItemIndex) {
    case EXI_GRUPO:
      edt_gpoexi->Text = qry_inven->FieldByName("cod2")->AsString;
      lbl_exisgpo->Caption = "Grupo";
      break;
    case EXI_MARCA:
      if(qry_marca->State == dsInactive) return;
      edt_gpoexi->Text = qry_marca->FieldByName("codigo")->AsString;
      lbl_exisgpo->Caption = "Marca";
      break;
    case EXI_PROVE:
      edt_gpoexi->Text = qry_inven->FieldByName("prove")->AsString;
      lbl_exisgpo->Caption = "Proveedor";
      break;
    case EXI_SITUAC:
      edt_gpoexi->Text = qry_inven->FieldByName("empaqe")->AsString;
      lbl_exisgpo->Caption = "Situación";
      break;
    case EXI_CODIGO:
      edt_gpoexi->Text = qry_inven->FieldByName("codigo")->AsString;
      lbl_exisgpo->Caption = "Código";
      break;
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::dbgrd_kardexDblClick(TObject *Sender)
{
  
  desp_detmovart(qry_movart->FieldByName("codigo")->AsString,
    qry_movart->FieldByName("alm")->AsString,
    qry_movart->FieldByName("folio")->AsInteger
  );
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::cmb_gpoestadisChange(TObject *Sender)
{
  if(qry_inven->State == dsInactive) return;
  switch (cmb_gpoestadis->ItemIndex) {
    case EXI_GRUPO:
      edt_codestad->Text = qry_inven->FieldByName("cod2")->AsString;
      lbl_estdiscod->Caption = "Grupo";
      break;
    case EXI_DIARY:
      edt_codestad->Text = qry_diary->FieldByName("grupo")->AsString;
      lbl_estdiscod->Caption = "Diary";
      break;
    case EXI_MARCA:
      if(qry_marca->State == dsInactive) return;
      edt_codestad->Text = qry_marca->FieldByName("codigo")->AsString;
      lbl_estdiscod->Caption = "Marca";
      break;
    case EXI_PROVE:
      edt_codestad->Text = qry_inven->FieldByName("prove")->AsString;
      lbl_estdiscod->Caption = "Proveedor";
      break;
    case EXI_SITUAC:
      edt_codestad->Text = qry_inven->FieldByName("empaqe")->AsString;
      lbl_estdiscod->Caption = "Situación";
      break;
    case EXI_CODIGO:
      edt_codestad->Text = qry_inven->FieldByName("codigo")->AsString;
      lbl_estdiscod->Caption = "Código";
      break;
  }

}
//---------------------------------------------------------------------------



void __fastcall TForm_consuinv::btn_estadiexpClick(TObject *Sender)
{
  TForm_estadis *Form_estadis = new TForm_estadis (this->Owner);
  Form_estadis->edt_prcod->Text = edt_codigo->Text.Trim();
  Form_estadis->edt_diary->Text = qry_diary->FieldByName("grupo")->AsString;
  Form_estadis->edt_prgrp->Text = qry_inven->FieldByName("cod2")->AsString;
  if(qry_marca->State != dsInactive)
    Form_estadis->edt_prmarca->Text = qry_marca->FieldByName("codigo")->AsString;
  Form_estadis->edt_prsit->Text = qry_inven->FieldByName("empaqe")->AsString;
  Form_estadis->edt_prprove->Text = qry_inven->FieldByName("prove")->AsString;
  Form_estadis->edt_prlin->Text = qry_inven->FieldByName("linea")->AsString;
  Form_estadis->cia_z = cia_z;
  Form_estadis->cmb_tipoestadi->ItemIndex = CMB_SAL_VTA;
  Form_estadis->Show();
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::dbgrd_dispoDblClick(TObject *Sender)
{
  desp_detmovart(
    qry_mvartdisp->FieldByName("codigo")->AsString,
    qry_mvartdisp->FieldByName("alm")->AsString,
    qry_mvartdisp->FieldByName("folio")->AsInteger
  );

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::desp_detmovart(String codigo_z, String alm_z, int folio_z)
{
  TForm_detmovart *Form_detmovart = new TForm_detmovart (this);
  Form_detmovart->cia_z = cia_z;
  Form_detmovart->qry_movart->Close();
  Form_detmovart->qry_movart->ParamByName("codigo")->AsString = codigo_z;
  Form_detmovart->qry_movart->ParamByName("alm")->AsString = alm_z;
  Form_detmovart->qry_movart->ParamByName("folio")->AsInteger = folio_z;
  Form_detmovart->qry_movart->ParamByName("cia")->AsInteger = cia_z;
  Form_detmovart->qry_movart->Open();
  Form_detmovart->ShowModal();
  delete Form_detmovart;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::exporta_dbgrdExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  switch (page_detalles->ActivePageIndex) {
    case TBS_KARDEX     : midbgrd_z = dbgrd_kardex;    tipogrd_z="DBG"; break;
    case TBS_ESTADIS    : midbgrd_z = dbgrd_estadis;   tipogrd_z="DBG"; break;
    case TBS_OBSERVS    : midbgrd_z = dbgrd_observs;   tipogrd_z="DBG"; break;
    case TBS_DISPONI    : midbgrd_z = dbgrd_dispo;     tipogrd_z="DBG"; break;
    case TBS_BUSSERIE   : midbgrd_z = dbgrd_busserie;  tipogrd_z="DBG"; break;
    case TBS_EXIST      : midbgrd_z = dbgrd_exist;     tipogrd_z="DBG"; break;
  }
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = "*.xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    if(tipogrd_z == "DBG") {
      switch( SaveDialog->FilterIndex) {
        case 1: midbgrd_z->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
        case 2: midbgrd_z->SaveToXLS(SaveDialog->FileName, true); break;
        case 3: midbgrd_z->SaveToHTML(SaveDialog->FileName, true); break;
      }
    }
    else if (tipogrd_z == "ADV") {
      switch( SaveDialog->FilterIndex) {
        case 1: misgrd_z->SaveToCSV(SaveDialog->FileName); break;
        case 2: misgrd_z->SaveToXLS(SaveDialog->FileName); break;
        case 3: misgrd_z->SaveToHTML(SaveDialog->FileName); break;
      }
    }
  }
  delete SaveDialog;
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::selec_ordenExecute(TObject *Sender)
{
  int selprecio_z=0;
  if(Form_dlgcriterio == NULL)
    Form_dlgcriterio = new TForm_dlgcriterio (this);
  if(Form_dlgcriterio->ShowModal() == mrOk) {
    if(orden_z) {
      orden_z->Clear();
    } else {
      orden_z = new TStringList ();
    }
    // El Campo del criterio es 01-Linea, 02-Grupo 03-Prove 04-Precio
    if(Form_dlgcriterio->chk_linea->Checked)
      orden_z->Add("01:" + IntToStr(Form_dlgcriterio->cmb_linea->ItemIndex));
    if(Form_dlgcriterio->chk_grupo->Checked)
      orden_z->Add("02:" + IntToStr(Form_dlgcriterio->cmb_grupo->ItemIndex));
    if(Form_dlgcriterio->chk_prove->Checked)
      orden_z->Add("03:" + IntToStr(Form_dlgcriterio->cmb_prove->ItemIndex));
    if(Form_dlgcriterio->chk_precio->Checked)
      orden_z->Add("04:" + IntToStr(Form_dlgcriterio->cmb_precio->ItemIndex));
    if(Form_dlgcriterio->chk_existencia->Checked) {
      selprecio_z = Form_dlgcriterio->cmb_conexistencia->ItemIndex;
      if(selprecio_z == 0) { eximin_z = 0;     eximax_z = -1; }
      if(selprecio_z == 1) { eximin_z = -1;    eximax_z = -1; }
      if(selprecio_z == 2) { eximin_z = 10000; eximax_z =  0; }
    }
  };
  //delete (Form_dlgcriterio);
  //Memo1->Lines = orden_z;
}
//---------------------------------------------------------------------------



void __fastcall TForm_consuinv::tbs_disponibleShow(TObject *Sender)
{
  if (qry_mvartdisp->State == dsInactive) {
    qry_mvartdisp->ParamByName("codigo")->AsString = qry_inven->FieldByName("codigo")->AsString;
    qry_mvartdisp->ParamByName("cia")->AsInteger = cia_z;
    qry_mvartdisp->Open();
    dbgrd_dispo->GotoFirst();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::lkcmb_almKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  busca_movarts();
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::edt_busserieKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
    qry_seriebus->Close();
    qry_seriebus->ParamByName("codigo")->AsString = qry_inven->FieldByName("codigo")->AsString;
    qry_seriebus->ParamByName("seriebus")->AsString = edt_busserie->Text.Trim();
    qry_seriebus->ParamByName("cia")->AsInteger = cia_z;
    qry_seriebus->Open();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::dbgrd_kardexKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_SPACE) dbgrd_kardexDblClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::dbgrd_dispoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_SPACE) dbgrd_dispoDblClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::dbgrd_busserieDblClick(TObject *Sender)
{
  desp_detmovart(qry_seriebus->FieldByName("codigo")->AsString,
    qry_seriebus->FieldByName("alm")->AsString,
    qry_seriebus->FieldByName("folio")->AsInteger
  );

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::dbgrd_busserieKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) dbgrd_busserieDblClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::muestrasqls(String sql1_z, String sql2_z)
{
    TForm *Form1 = new TForm(this);
    TMemo *mmo_tiempos = new TMemo (Form1);
    mmo_tiempos->Parent = Form1;
    mmo_tiempos->Align = alClient;
    mmo_tiempos->Lines->Add(sql1_z);
    mmo_tiempos->Lines->Add("");
    mmo_tiempos->Lines->Add(sql2_z);
    Form1->ShowModal();
    delete Form1;

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::dbedt_lineaDblClick(TObject *Sender)
{
  if(dbedt_linea->Tag) dbedt_linea->Tag = 0; else dbedt_linea->Tag = 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::btn_exiexpertClick(TObject *Sender)
{
  TForm_exists *Form_exists = new TForm_exists (this->Owner);
  Form_exists->edt_prcod->Text = edt_codigo->Text.Trim();
  Form_exists->edt_diary->Text = qry_diary->FieldByName("grupo")->AsString;
  Form_exists->edt_prgrp->Text = qry_inven->FieldByName("cod2")->AsString;
  if(qry_marca->State != dsInactive)
    Form_exists->edt_prmarca->Text = qry_marca->FieldByName("codigo")->AsString;
  Form_exists->edt_prsit->Text = qry_inven->FieldByName("empaqe")->AsString;
  Form_exists->edt_prprove->Text = qry_inven->FieldByName("prove")->AsString;
  Form_exists->edt_prlin->Text = qry_inven->FieldByName("linea")->AsString;
  Form_exists->cia_z = cia_z;
  Form_exists->Show();

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::dbgrd_kardexCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::dbgrd_existDblClick(TObject *Sender)
{
  String codigo_z;
  codigo_z = qry_exigrid->FieldByName("codigo")->AsString;
  busca_cod(codigo_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::dbgrd_existKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  String codigo_z;
  if(Key == VK_SPACE){
    codigo_z = qry_exigrid->FieldByName("codigo")->AsString;
    busca_cod(codigo_z);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::edt_anuestadisDblClick(TObject *Sender)
{
  if (edt_anuestadis->Tag) edt_anuestadis->Tag = 0; else edt_anuestadis->Tag = 1;
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::DBEdit12DblClick(TObject *Sender)
{
  int ii_z=0;
  Tdlg_okcancel* Dlg_datos;
  TQuery *qry_exialm = new TQuery(this);
  Dlg_datos = new Tdlg_okcancel (this);
  Dlg_datos->Caption = "Datos de la Permision";
  Dlg_datos->AutoSize = false;
  TAdvStringGrid *sgrd_existalm = new TAdvStringGrid(Dlg_datos);
  sgrd_existalm->Height = 100;
  sgrd_existalm->Width = 300;
  Dlg_datos->Width = sgrd_existalm->Width + 20;
  Dlg_datos->Height = sgrd_existalm->Height + 80;
  sgrd_existalm->Parent = Dlg_datos->Panel1;
  sgrd_existalm->Align = alClient;
  qry_exialm->DatabaseName = qry_exist->DatabaseName;
  qry_exialm->SQL->Text = "select * from exist where codigo = :CODIGO and alm = :ALM and cia = :CIA";
  qry_exialm->ParamByName("codigo")->AsString = edt_codigo->Text;
  qry_exialm->ParamByName("alm")->AsString = qry_almreps->FieldByName("alm")->AsString;
  qry_exialm->ParamByName("cia")->AsInteger = dm->cia_z;
  qry_exialm->Open();
  sgrd_existalm->ColCount=2;
  sgrd_existalm->FixedCols=0;
  ii_z = qry_exialm->FieldCount + 1;
  sgrd_existalm->RowCount= ii_z;
  sgrd_existalm->Options << goColSizing;
  sgrd_existalm->Cells[0][0] = "Campo";
  sgrd_existalm->Cells[1][0] = "Contenido";
  for(int ii_z = 0; ii_z < qry_exialm->FieldCount; ii_z++) {
    sgrd_existalm->Cells[0][ii_z+1] = qry_exialm->Fields->Fields[ii_z]->FieldName;
    sgrd_existalm->Cells[1][ii_z+1] = qry_exialm->Fields->Fields[ii_z]->AsString;
  }
  sgrd_existalm->ColumnSize->Stretch = true;
  if(Dlg_datos->ShowModal() == mrOk) {
  }
  delete dbgrd_exist;
  delete qry_exialm;
  delete sgrd_existalm;
  delete Dlg_datos;
}
//---------------------------------------------------------------------------



void __fastcall TForm_consuinv::graba_estadis_anualExecute(TObject *Sender)
{
  int ii_z=0;
  Tdlg_okcancel* Dlg_datos;
  String codigo_z;
  Dlg_datos = new Tdlg_okcancel (this);
  Dlg_datos->Caption = "Fecha de Corte Anual";
  Dlg_datos->AutoSize = false;
  TDateTimePicker *date_fechacorte = new TDateTimePicker (Dlg_datos);
  date_fechacorte->Date = dm->ahora();
  TDateTime fechacorte_z, mihoy_z, miinianu_z, fechaalta_z;
  int maximo_z=0, maximoant_z=0, univta_z;
  unsigned short int anu_z, mes_z, dia_z;
  TdxDBGrid *dbgrd_existalm = new TdxDBGrid (Dlg_datos);
  TQuery *qry_exialm = new TQuery(Dlg_datos);
  TDataSource *tds_exialm = new TDataSource (Dlg_datos);
  dbgrd_existalm->Parent = Dlg_datos->Panel1;
  dbgrd_existalm->Visible = false;
  dbgrd_existalm->Height = 100;
  dbgrd_existalm->Width = 300;
  Dlg_datos->Width = dbgrd_existalm->Width + 20;
  Dlg_datos->Height = dbgrd_existalm->Height + 80;
  dbgrd_existalm->Parent = Dlg_datos->Panel1;
  dbgrd_existalm->KeyField = "codigo";

  date_fechacorte->Parent = Dlg_datos->Panel1;
  date_fechacorte->Top = 20;
  date_fechacorte->Left = 20;
  if(Dlg_datos->ShowModal() == IDOK) {
    fechacorte_z = date_fechacorte->Date;
    mihoy_z = fechacorte_z;
    mihoy_z.DecodeDate(&anu_z, &mes_z, &dia_z);
    miinianu_z =   EncodeDate((Word)anu_z, 1, 1);
    qry_exialm->DatabaseName = qry_exist->DatabaseName;
    qry_exialm->SQL->Text = "select codigo, descri, fecalta, (salvtas + salvtan + salfons + salfonn) as ventas from inven where cia = :CIA order by codigo";
    qry_exialm->ParamByName("cia")->AsInteger = cia_z;
    qry_exialm->Open();
    ii_z = qry_exialm->FieldCount + 1;
    qry_grabaestadis->Close();
    qry_grabaestadis->ParamByName("anu")->AsInteger = anu_z;
    qry_grabaestadis->ParamByName("cia")->AsInteger = cia_z;
    qry_grabaestadis->ParamByName("tipo")->AsInteger = EST_TIPO_MAXIMO;
    qry_grabaestadis->ParamByName("codigo")->AsString = "-1";
    qry_grabaestadis->Open();
    tds_exialm->DataSet = qry_grabaestadis;
    qry_grabaestadis->DisableControls();
    for(qry_exialm->First(); !qry_exialm->Eof; qry_exialm->Next()) {
      fechaalta_z = qry_exialm->FieldByName("fecalta")->AsDateTime;
      univta_z = qry_exialm->FieldByName("ventas")->AsFloat;
      codigo_z = qry_exialm->FieldByName("codigo")->AsString;
      maximo_z = inv_maximo(fechaalta_z, univta_z, mihoy_z, miinianu_z,
        maxdiasglo_z, maxdiasmen_z, 0
      );
      qry_grabaestadis->Append();
      qry_grabaestadis->FieldByName("tipo")->AsInteger = EST_TIPO_MAXIMO;
      qry_grabaestadis->FieldByName("codigo")->AsString = codigo_z;
      qry_grabaestadis->FieldByName("alm")->AsString = "";
      qry_grabaestadis->FieldByName("anu")->AsInteger = anu_z;
      qry_grabaestadis->FieldByName("mes")->AsInteger = 0;
      qry_grabaestadis->FieldByName("unidades")->AsInteger = maximo_z;
      qry_grabaestadis->FieldByName("importe")->AsInteger = 0;
      qry_grabaestadis->FieldByName("cia")->AsInteger = cia_z;
      qry_grabaestadis->Post();
    }
    qry_grabaestadis->EnableControls();
    dbgrd_existalm->Align = alClient;
    dbgrd_existalm->KeyField = "codigo";
    dbgrd_existalm->DataSource = tds_exialm;
    dbgrd_existalm->CreateDefaultColumns(qry_grabaestadis, dbgrd_existalm);
    dbgrd_existalm->Visible = true;
    date_fechacorte->Visible = false;
    if(Dlg_datos->ShowModal() == IDOK) {
      try {
        dm->manvehi->StartTransaction();
        qry_grabaestadis->Delete();
        qry_grabaestadis->ApplyUpdates();
        dm->manvehi->Commit();
      } catch (Exception &E) {
        dm->manvehi->Rollback();
        Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
      }
      Application->MessageBox("Se ha Grabado el Máximo", "Maximo Grabado", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::cambia_serieExecute(TObject *Sender)
{
  int ii_z=0;
  String nvaserie_z, antserie_z, codigo_z;
  Tdlg_okcancel* Dlg_datos;
  if (qry_movart->State == dsInactive) return;
  if (qry_movart->IsEmpty() ) return;
  antserie_z = qry_movart->FieldByName("serie")->AsString;
  if(antserie_z.IsEmpty()) {
    if(Application->MessageBox("Serie vacía, posible afectación de muchos datos, seguro de continuar ?", "Serie Vacía", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) != IDYES) {
      return;
    }
  }
  codigo_z   = qry_movart->FieldByName("codigo")->AsString;
  Dlg_datos = new Tdlg_okcancel (this);
  Dlg_datos->Caption = "Cambio de Serie";
  Dlg_datos->AutoSize = false;
  TQuery *qry_cambiamovart = new TQuery(Dlg_datos);
  TQuery *qry_cambiarenentra = new TQuery(Dlg_datos);
  TEdit *edt_nvaserie = new TEdit(Dlg_datos);
  edt_nvaserie->Parent = Dlg_datos->Panel1;
  edt_nvaserie->Text = antserie_z;
  TLabel *lbl_nuevaserie = new TLabel (Dlg_datos);
  lbl_nuevaserie->Parent = Dlg_datos->Panel1;
  lbl_nuevaserie->Caption = "Nueva Serie";
  lbl_nuevaserie->Left = 20;
  lbl_nuevaserie->Top = 30;
  edt_nvaserie->Left = lbl_nuevaserie->Left + lbl_nuevaserie->Width + 20;
  edt_nvaserie->Top = 25;
  if(Dlg_datos->ShowModal() == IDOK) {
    nvaserie_z = edt_nvaserie->Text;
    qry_cambiamovart->DatabaseName = qry_exist->DatabaseName;
    qry_cambiamovart->SQL->Text = "update movart set serie = :NVASERIE where codigo = :CODIGO and serie = :ANTSERIE and cia = :CIA";
    qry_cambiamovart->ParamByName("nvaserie")->AsString = nvaserie_z;
    qry_cambiamovart->ParamByName("antserie")->AsString = antserie_z;
    qry_cambiamovart->ParamByName("codigo")->AsString = antserie_z;
    qry_cambiamovart->ParamByName("cia")->AsInteger = cia_z;
    qry_cambiamovart->DatabaseName = qry_exist->DatabaseName;
    qry_cambiarenentra->SQL->Text = "update renentra set serie = :NVASERIE where codinv = :CODIGO and serie = :ANTSERIE and cia = :CIA";
    qry_cambiarenentra->ParamByName("nvaserie")->AsString = nvaserie_z;
    qry_cambiarenentra->ParamByName("antserie")->AsString = antserie_z;
    qry_cambiarenentra->ParamByName("codigo")->AsString = antserie_z;
    qry_cambiarenentra->ParamByName("cia")->AsInteger = cia_z;
    try {
      dm->manvehi->StartTransaction();
      qry_cambiamovart->ExecSQL();
      qry_cambiarenentra->ExecSQL();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    Application->MessageBox("Se ha Cambiado la Serie", "Serie Cambiada", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::page_detallesChange(TObject *Sender)
{
  int numpag_z;
  String anterpag_z;
  numpag_z = page_detalles->ActivePageIndex;
  switch (numpag_z ) {
      case TBS_OBSERVS    :    DesplegarObservs();            break;
      case TBS_OBSERVSNEG :    DesplegarObservs();            break;
      case TBS_OBSERVSCOM :    DesplegarObservs();            break;
  }
  anterpag_z = pagina_z;
  //TTabSheet *pPC = dynamic_cast<TTabSheet *>(Sender);
  TTabSheet *pPC = page_detalles->ActivePage;
  pagina_z = pPC->Name;
  pagina_z = pagina_z.UpperCase();
  if(pagina_z == "TBS_IMAGENES" && pagina_z != anterpag_z ) {
    Desplegar_imagen();
  }
  if(page_detalles->ActivePageIndex == TBS_DATOSINTERNET) {
    muestra_datos_internet();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::Desplegar_imagen()
{
  String nomarch_z, codigo_z, linea_z;
  if(qry_inven->IsEmpty()) return;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  linea_z = qry_inven->FieldByName("linea")->AsString;
  Frame_imginven1->codigo_z = codigo_z;
  Frame_imginven1->linea_z  = linea_z;
  Frame_imginven1->directorioimgs_z = directorioimgs_z;
  Frame_imginven1->carga_imagen();
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::DesplegarObservs()
{
  String codigo_z, prove_z, marca_z, linea_z, grupo_z;
  int numpag_z;
  numpag_z = page_detalles->ActivePageIndex;
  if(qry_inven->State == dsInactive) return;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  prove_z = qry_inven->FieldByName("prove")->AsString;
  marca_z = qry_marca->FieldByName("codigo")->AsString;
  grupo_z = qry_inven->FieldByName("cod2")->AsString;
  linea_z = qry_inven->FieldByName("linea")->AsString;
  if (qry_observnegxpro->State == dsInactive) antprove_z = "-1";
  if (qry_observnegxmca->State == dsInactive) antmarca_z = "-1";
  if (qry_obscomgpo->State == dsInactive) antgpo_z = "-1";
  if (qry_obscomlin->State == dsInactive) antlin_z = "-1";

  switch (numpag_z) {
      case TBS_OBSERVS    :
        qry_observs->Close();
        qry_observs->ParamByName("codigo")->AsString=codigo_z;
        qry_observs->ParamByName("tipoobs")->AsString="I";
        qry_observs->ParamByName("alm")->AsString="";
        qry_observs->ParamByName("numero")->AsInteger = 0;
        qry_observs->ParamByName("cia")->AsInteger = cia_z;
        qry_observs->Open();
      break;
      case TBS_OBSERVSNEG :
        qry_observnegxcod->Close();
        qry_observnegxcod->ParamByName("codigo")->AsString=codigo_z;
        qry_observnegxcod->ParamByName("tipoobs")->AsString="N";
        qry_observnegxcod->ParamByName("alm")->AsString="N";
        qry_observnegxcod->ParamByName("numero")->AsInteger = 0;
        qry_observnegxcod->ParamByName("cia")->AsInteger = cia_z;
        qry_observnegxcod->Open();
        if(marca_z != antmarca_z) {
          qry_observnegxmca->Close();
          qry_observnegxmca->ParamByName("codigo")->AsString=marca_z;
          qry_observnegxmca->ParamByName("tipoobs")->AsString="M";
          qry_observnegxmca->ParamByName("alm")->AsString="M";
          qry_observnegxmca->ParamByName("numero")->AsInteger = 0;
          qry_observnegxmca->ParamByName("cia")->AsInteger = cia_z;
          qry_observnegxmca->Open();
          antmarca_z = marca_z;
        }
        if(prove_z != antprove_z) {
          qry_observnegxpro->Close();
          qry_observnegxpro->ParamByName("codigo")->AsString=prove_z;
          qry_observnegxpro->ParamByName("tipoobs")->AsString="P";
          qry_observnegxpro->ParamByName("alm")->AsString="P";
          qry_observnegxpro->ParamByName("numero")->AsInteger = 0;
          qry_observnegxpro->ParamByName("cia")->AsInteger = cia_z;
          qry_observnegxpro->Open();
          antprove_z = prove_z;
        }
      break;
      case TBS_OBSERVSCOM :
        if(marca_z != antmarca_z) {
          qry_obscommca->Close();
          qry_obscommca->ParamByName("codigo")->AsString=marca_z;
          qry_obscommca->ParamByName("tipoobs")->AsString="C";
          qry_obscommca->ParamByName("alm")->AsString="C";
          qry_obscommca->ParamByName("numero")->AsInteger = 0;
          qry_obscommca->ParamByName("cia")->AsInteger = cia_z;
          qry_obscommca->Open();
          antmarca_z = marca_z;
        }
        if(grupo_z != antgpo_z) {
          qry_obscomgpo->Close();
          qry_obscomgpo->ParamByName("codigo")->AsString=grupo_z;
          qry_obscomgpo->ParamByName("tipoobs")->AsString="D";
          qry_obscomgpo->ParamByName("alm")->AsString="D";
          qry_obscomgpo->ParamByName("numero")->AsInteger = 0;
          qry_obscomgpo->ParamByName("cia")->AsInteger = cia_z;
          qry_obscomgpo->Open();
          antgpo_z = grupo_z;
        }
        if(linea_z != antlin_z) {
          qry_obscomlin->Close();
          qry_obscomlin->ParamByName("codigo")->AsString=linea_z;
          qry_obscomlin->ParamByName("tipoobs")->AsString="A";
          qry_obscomlin->ParamByName("alm")->AsString="A";
          qry_obscomlin->ParamByName("numero")->AsInteger = 0;
          qry_obscomlin->ParamByName("cia")->AsInteger = cia_z;
          qry_obscomlin->Open();
          antprove_z = prove_z;
        }
      break;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::btn_obsnegmarcaClick(TObject *Sender)
{
  const int MARCA = 1;
  const int PROVE = 2;
  const int ARTIC = 3;
  const int COMER_MARCA = 4;
  const int COMER_LINEA = 5;
  const int COMER_GRUPO = 6;
  int miboton_z;
  String permisobs_z, codigo_z, prove_z, marca_z, cod_z,
  linea_z, grupo_z, quiensoy_z, alm_z, tipo_z;
  if(qry_inven->State == dsInactive) return;
  miboton_z = ((TComponent *)Sender)->Tag;
  quiensoy_z  = ((TComponent *)Sender)->Name;
  if(miboton_z == COMER_MARCA || miboton_z == COMER_LINEA || miboton_z == COMER_GRUPO) {
    permisobs_z=dm->busca_permistr("OBSERV_COMER");
  } else {
    permisobs_z=dm->busca_permision(INV_PERMI_OBSNEG);
  }
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  prove_z = qry_inven->FieldByName("prove")->AsString;
  marca_z = qry_marca->FieldByName("codigo")->AsString;
  linea_z = qry_inven->FieldByName("linea")->AsString;
  grupo_z = qry_inven->FieldByName("cod2")->AsString;
  alm_z = "";
  if(miboton_z == MARCA) {
    cod_z = marca_z; antmarca_z = "-1";
    tipo_z = "M";
    alm_z = tipo_z;
  }
  if(miboton_z == PROVE) {
    cod_z = prove_z; antprove_z = "-1";
    tipo_z = "P";
    alm_z = tipo_z;
  }
  if(miboton_z == ARTIC) {
    cod_z = codigo_z;
    tipo_z = "N"; alm_z = tipo_z;
  }
  if(miboton_z == COMER_MARCA) {
    cod_z = marca_z; antmarca_z = "-1";
    tipo_z = "C"; alm_z = tipo_z;
  }
  if(miboton_z == COMER_LINEA) {
    cod_z = linea_z; antlin_z = "-1";
    tipo_z = "A"; alm_z = tipo_z;
  }
  if(miboton_z == COMER_GRUPO) {
    cod_z = grupo_z; antgpo_z = "-1";
    tipo_z = "D"; alm_z = tipo_z;
  }
  CapturaObservaPedido(this, tipo_z, alm_z, 0, cia_z, cod_z, permisobs_z);
  DesplegarObservs();

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::checa_cambios_precios()
{
   int alto_z, ancho_z, cuantos_z;
   String permiscampre_z, antmaster_z, sql_z, strfec_z;
   // Un puqueño truco, Necesito que se lea aunque sea MASTER
   // por tanto lo asigno a una variable, le pongo NO y luego le regreso su valor
   antmaster_z = dm->usermaster_z;
   dm->usermaster_z = "N";
   permiscampre_z=dm->busca_permision(INV_PERMI_CAMBIOPRECIOS);
   dm->usermaster_z = antmaster_z;
   // Aqui usermaster_z tiene lo que tenía antes
   if(permiscampre_z == "T") {
     sql_z = "select count(*) as cuantos \
          from inv_polcampre a \
          join inv_renpolcampre b on a.idpolcampre = b.idpolcampre \
          join inv_invhist d on b.idart = d.idart and a.cia = d.cia \
          join inven c on d.codigo = c.codigo and a.cia = c.cia \
          where a.fecha <= :FECHA and \
          a.status = :STATUS_CAMBIOPRECIO and a.tipo = 'P' \
          and a.fecini >= :FECHA and a.cia = :CIA ";
     TQuery *qry_consprecios = new TQuery (this);
     strfec_z = FormatDateTime("dd/mm/yyyy", hoy_z);
     qry_consprecios->Close();
     qry_consprecios->DatabaseName = qry_almreps->DatabaseName;
     qry_consprecios->SQL->Text = sql_z;
     qry_consprecios->ParamByName("fecha")->AsDateTime = hoy_z;
     qry_consprecios->ParamByName("STATUS_CAMBIOPRECIO")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
     qry_consprecios->ParamByName("cia")->AsInteger = cia_z;
     qry_consprecios->Open();
     if(qry_consprecios->FieldByName("cuantos")->AsInteger) {
       Tdlg_busartic *Dlg_consultaprecios = new Tdlg_busartic (this);
       Dlg_consultaprecios->despliega_cambios_precios();
       Dlg_consultaprecios->ShowModal();
       delete Dlg_consultaprecios;
     }
     // --> ahora voy a buscar los precios que se aplican HOY
     sql_z = "select count(*) as cuantos \
          from inv_polcampre a \
          join inv_renpolcampre b on a.idpolcampre = b.idpolcampre \
          join inv_invhist d on b.idart = d.idart and a.cia = d.cia \
          join inven c on d.codigo = c.codigo and a.cia = c.cia \
          where a.fecha <= :FECHA and \
          a.status = :STATUS_CAMBIOPRECIO and a.tipo = 'P' \
          and a.fecini <= :FECHA and a.cia = :CIA ";
     qry_consprecios->SQL->Text = sql_z;
     qry_consprecios->ParamByName("fecha")->AsDateTime = hoy_z;
     qry_consprecios->ParamByName("STATUS_CAMBIOPRECIO")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
     qry_consprecios->ParamByName("cia")->AsInteger = cia_z;
     qry_consprecios->Open();
     cuantos_z = qry_consprecios->FieldByName("cuantos")->AsInteger;
     if(cuantos_z) {
       TForm_polcampre *Form_polcampre = new TForm_polcampre (this);
       Form_polcampre->busca_cambios_x_aplicar();
       delete Form_polcampre;
     }
     delete qry_consprecios;
   }
}
//---------------------------------------------------------------------------

bool __fastcall TForm_consuinv::checa_si_hay_cambio_precios_articulo(String codigo_z)
{
   int alto_z, ancho_z;
   String permiscampre_z, antmaster_z, sql_z;
   bool pendiente_z = false;
   sql_z = "select count(*) as cuantos \
          from inv_polcampre a \
          join inv_renpolcampre b on a.idpolcampre = b.idpolcampre \
          join inv_invhist d on b.idart = d.idart and a.cia = d.cia \
          join inven c on d.codigo = c.codigo and a.cia = c.cia \
          where a.fecha <= :FECHA and a.fecini >= :FECHA and a.cia = :CIA and \
          a.status = :STATUS_CAMBIOPRECIO and a.tipo = 'P' \
          and c.codigo = :CODIGO ";
     TQuery *qry_consprecios = new TQuery (this);
     qry_consprecios->Close();
     qry_consprecios->DatabaseName = qry_almreps->DatabaseName;
     qry_consprecios->SQL->Text = sql_z;
     qry_consprecios->ParamByName("fecha")->AsDateTime = hoy_z;
     qry_consprecios->ParamByName("codigo")->AsString  = codigo_z;
     qry_consprecios->ParamByName("STATUS_CAMBIOPRECIO")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
     qry_consprecios->ParamByName("cia")->AsInteger    = cia_z;
     qry_consprecios->Open();
     if(qry_consprecios->FieldByName("cuantos")->AsInteger) {
       pendiente_z = true;
     }
     delete qry_consprecios;
     return (pendiente_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::timer_cambioprecioTimer(TObject *Sender)
{
  int color_z;
  color_z = dbedt_preciomds->Color;
  if(actictorep_z == "ACTIVO") {
    if( edt_costoext->Color == clRed ) {
      edt_costoext->Color   = clWindow;
      edt_costocext->Color  = clWindow;
      //edt_prvtacext->Color  = clWindow;
      edt_mubcext->Color    = clWindow;
      edt_preciomay->Color  = clWindow;
    } else {
      edt_costoext->Color   = clRed;
      edt_costocext->Color  = clRed;
      //edt_prvtacext->Color  = clRed;
      edt_mubcext->Color    = clRed;
      edt_preciomay->Color  = clRed;
    }
  }

  if(acticamprecio_z == "ACTIVO") {
    if( dbedt_preciomds->Color == clRed ) {
      dbedt_preciomds->Color = clWindow;
    } else {
      dbedt_preciomds->Color = clRed;
    }
  }

  if(actioferta_z == "ACTIVO") {
    if( edt_proferta->Color == clRed ) {
      edt_proferta->Color = clWindow;
    } else {
      edt_proferta->Color = clRed;
    }
    edt_inioferta->Color = edt_proferta->Color;
    edt_finoferta->Color = edt_proferta->Color;
    edt_mubofert->Color = edt_proferta->Color;
  }
  if(actioutlet_z == "ACTIVO") {
    if( edt_proutlet->Color == clRed ) {
      edt_proutlet->Color = clWindow;
    } else {
      edt_proutlet->Color = clRed;
    }
    edt_inioutlet->Color = edt_proutlet->Color;
    edt_finoutlet->Color = edt_proutlet->Color;
    edt_muboutlet->Color = edt_proutlet->Color;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::muestra_cambios(String codigo_z)
{
  int ancho_z, alto_z;
  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TFrame_datosnvoprecio *Frame_datosnvoprecio;
  Frame_datosnvoprecio = new TFrame_datosnvoprecio (Dlg_analipol);
  Frame_datosnvoprecio->Form_consuinv = this;
  //Frame_datosnvoprecio->Width= 480;
  //Frame_datosnvoprecio->Height = 300;
  ancho_z = Frame_datosnvoprecio->Width + 20;
  alto_z = Frame_datosnvoprecio->Height + Dlg_analipol->Panel2->Height + 80;
  Frame_datosnvoprecio->Parent = Dlg_analipol->Panel1;
  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;
  Dlg_analipol->Caption = "Datos de Próximo Cambio de Precios";
  Frame_datosnvoprecio->despliega_cambio_precio(codigo_z);
  Dlg_analipol->btn_cancel->Visible = false;
  Dlg_analipol->btn_cancel->Width = 0;
  Dlg_analipol->ShowModal();
  delete Frame_datosnvoprecio;
  delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::despliega_cambios_precioExecute(
      TObject *Sender)
{
  String codigo_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  muestra_cambios(codigo_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::nuevo_articuloExecute(TObject *Sender)
{
  int modo_z=0;
  modo_z = NUEVO;
  alta_modif_articulo(NUEVO);

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::modif_articuloExecute(TObject *Sender)
{
  int modo_z=0;
  modo_z = MODIF;
  alta_modif_articulo(MODIF);

}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::alta_modif_articulo(int modo_z)
{
  int ancho_z, alto_z;
  String codigo_z;
  Tdlg_okcancel *Dlg_analipol;
  TFrame_datosarticulo *Frame_datosarticulo;
  if(modo_z == MODIF) {
    qry_buscod->Close();
    qry_buscod->ParamByName("codigo")->AsString = edt_codigo->Text.Trim() + "%%";
    qry_buscod->ParamByName("eximin")->AsInteger = -1;
    qry_buscod->ParamByName("eximax")->AsInteger = eximax_z;
    qry_buscod->ParamByName("cia")->AsInteger = cia_z;
    qry_buscod->Open();
    if (qry_buscod->IsEmpty()) {
       Application->MessageBox(("No existe este codigo:"+edt_codigo->Text).c_str(), "ERROR", MB_ICONEXCLAMATION);
       return;
    }
  }
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  Frame_datosarticulo = new TFrame_datosarticulo (Dlg_analipol);
  //Frame_datosnvoprecio->Width= 480;
  //Frame_datosnvoprecio->Height = 300;
  ancho_z = Frame_datosarticulo->Width + 20;
  alto_z = Frame_datosarticulo->Height + Dlg_analipol->Panel2->Height + 80;
  Frame_datosarticulo->Parent = Dlg_analipol->Panel1;
  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;
  Dlg_analipol->Caption = "Datos del Artículo";
  Frame_datosarticulo->Form_consuinv = this;
  Frame_datosarticulo->inicializa(edt_codigo->Text, modo_z);
  if(modo_z == MODIF) {
    Frame_datosarticulo->edt_codigo->Enabled = false;
    Frame_datosarticulo->edt_costosi->Enabled = false;
    Frame_datosarticulo->edt_costono->Enabled = false;
    Frame_datosarticulo->edt_preciomds->Enabled = false;
    Frame_datosarticulo->edt_plazo->Enabled = false;
  }
  //Dlg_analipol->btn_cancel->Visible = false;
  //Dlg_analipol->btn_cancel->Width = 0;
  if(Dlg_analipol->ShowModal() == mrOk) {
    Frame_datosarticulo->graba_articulo(modo_z);
    if(modo_z == NUEVO) {
      codigo_z = Frame_datosarticulo->edt_codigo->Text.Trim();
      busca_cod(codigo_z);
      ModificaDatosInternetExecute(this);
    }
  }
  delete Frame_datosarticulo;
  delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::chk_estadis2Click(TObject *Sender)
{
  cmb_estadi2->Enabled = chk_estadis2->Checked;
  edt_codestadi2->Enabled = chk_estadis2->Checked;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::cmb_estadi2Change(TObject *Sender)
{
  if(qry_inven->State == dsInactive) return;
  switch (cmb_estadi2->ItemIndex) {
    case EXI_GRUPO:
      edt_codestadi2->Text = qry_inven->FieldByName("cod2")->AsString;
      lbl_estadi2->Caption = "Grupo";
      break;
    case EXI_DIARY:
      edt_codestadi2->Text = qry_diary->FieldByName("grupo")->AsString;
      lbl_estadi2->Caption = "Diary";
      break;
    case EXI_MARCA:
      if(qry_marca->State == dsInactive) return;
      edt_codestadi2->Text = qry_marca->FieldByName("codigo")->AsString;
      lbl_estadi2->Caption = "Marca";
      break;
    case EXI_PROVE:
      edt_codestadi2->Text = qry_inven->FieldByName("prove")->AsString;
      lbl_estadi2->Caption = "Proveedor";
      break;
    case EXI_SITUAC:
      edt_codestadi2->Text = qry_inven->FieldByName("empaqe")->AsString;
      lbl_estadi2->Caption = "Situación";
      break;
    case EXI_CODIGO:
      edt_codestadi2->Text = qry_inven->FieldByName("codigo")->AsString;
      lbl_estadi2->Caption = "Código";
      break;
  }


}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::ver_imagen_completaExecute(TObject *Sender)
{
   TForm *Frm_imagen = new TForm (this);
   Frm_imagen->Height = Frame_imginven1->img_principal->Height + 50;
   Frm_imagen->Width  = Frame_imginven1->img_principal->Width  + 50;
   Frm_imagen->Left = Left + 50;
   Frm_imagen->Top = Top + 50;
   TFrame_imginven *Frame_imginven2 = new TFrame_imginven (Frm_imagen);
   Frame_imginven2->Parent = Frm_imagen;
   Frame_imginven2->Align = alClient;
   Frm_imagen->Caption = Frame_imginven1->codigo_z;
   Frame_imginven2->codigo_z = Frame_imginven1->codigo_z;
   Frame_imginven2->linea_z  = Frame_imginven1->linea_z;
   Frame_imginven2->directorioimgs_z = Frame_imginven1->directorioimgs_z;
   Frame_imginven2->carga_imagen();
   Frame_imginven2->carga_interactivo();
   Frame_imginven2->chk_ajustaimg->Checked = true;
   Frame_imginven2->ajusta_imagenExecute(Sender);
   Frm_imagen->ShowModal();
   delete Frm_imagen;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::ver_permisionExecute(TObject *Sender)
{
  String mispermisiones_z;
  mispermisiones_z = "Consulta: CONSULTA_INVEN :" + IntToStr(CONSULTA_INVEN);
  mispermisiones_z += "\nManteniiento: MANTOINV :" + IntToStr(MANTOINV);
  mispermisiones_z += "\nObservs Comercializacion: OBSERV_COMER";
  mispermisiones_z += "\nManteniiento: INV_PERMI_OBSNEG :" + IntToStr(INV_PERMI_OBSNEG);
  dm->MensajeError(mispermisiones_z, "Permisiones");
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::ver_almacenesExecute(TObject *Sender)
{
  int ii_z=0, topini_z;
  String alm_z, activos_z, inactivos_z, config_z;
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  Dlg_datos->Caption = "Seleccione Status de Almacenes";
  Dlg_datos->AutoSize = false;
  TRadioButton *rbtn_activos = new TRadioButton (Dlg_datos);
  rbtn_activos->Parent = Dlg_datos->Panel1;
  rbtn_activos->Top = 10;
  rbtn_activos->Caption = "Activos";
  rbtn_activos->Checked = true;
  //-----
  TRadioButton *rbtn_inactivos = new TRadioButton (Dlg_datos);
  rbtn_inactivos->Parent = Dlg_datos->Panel1;
  rbtn_inactivos->Top = 30;
  rbtn_inactivos->Caption = "Inactivos";
  rbtn_inactivos->Checked = false;
  //-----
  TRadioButton *rbtn_todos = new TRadioButton (Dlg_datos);
  rbtn_todos->Parent = Dlg_datos->Panel1;
  rbtn_todos->Top = 50;
  rbtn_todos->Caption = "Activos e Inactivos";
  rbtn_todos->Checked = false;

  if(Dlg_datos->ShowModal() == IDOK) {
    alm_z = lkcmb_alm->KeyValue;
    if (rbtn_todos->Checked) { activos_z = "A"; inactivos_z = "B"; }
    if (rbtn_activos->Checked) { activos_z = "A"; inactivos_z = "x"; }
    if (rbtn_inactivos->Checked) { activos_z = "x"; inactivos_z = "B"; }
    qry_almreps->Close();
    qry_almreps->ParamByName("cia")->AsInteger     = cia_z;
    qry_almreps->ParamByName("activo")->AsString   = activos_z;
    qry_almreps->ParamByName("inactivo")->AsString = inactivos_z;
    qry_almreps->Open();
    if(!qry_almreps->IsEmpty()) {
      if(alm_z != qry_almreps->FieldByName("alm")->AsString ) {
        alm_z = qry_almreps->FieldByName("alm")->AsString;
        lkcmb_alm->KeyValue = alm_z;
      }
    }
    config_z = dm->busca_inifile();
    TIniFile *ini;
    ini = new TIniFile(config_z);
    ini->WriteString( "Form_consuinv", "ALMACENES_ACTIVOS", activos_z);
    ini->WriteString( "Form_consuinv", "ALMACENES_INACTIVOS", inactivos_z);
    delete ini;
  }
  delete Dlg_datos->Panel1;
}
//---------------------------------------------------------------------------



void __fastcall TForm_consuinv::modif_ctorepExecute(TObject *Sender)
{
  int ancho_z, alto_z;
  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TFrame_datosrenpolcampre *Frame_datosrenpolcampre;
  Frame_datosrenpolcampre = new TFrame_datosrenpolcampre (Dlg_analipol);
  Frame_datosrenpolcampre->Parent = Dlg_analipol->Panel1;
  Frame_datosrenpolcampre->edt_codigo->Text = edt_codigo->Text;
  Dlg_analipol->Caption = "Costo Reposición";
  Frame_datosrenpolcampre->solo_reposicion();
  Frame_datosrenpolcampre->busca_inven();
  if( Dlg_analipol->ShowModal() == mrOk) {
    Frame_datosrenpolcampre->graba_reposicion();
  }
  delete Frame_datosrenpolcampre;
  delete Dlg_analipol;

}
//---------------------------------------------------------------------------

int __fastcall TForm_consuinv::busca_unidades_vendidas(
  String codigo_z, String tiposalida_z
)
{
  int unidades_z=0, dias_z, ancho_z, alto_z;
  String dd1_z, tipovta_z, sql_z;
  TDateTime fecini_z;
  sql_z = "select sum(unids) as unids from entradas a join renentra b on ";
  sql_z += " a.tipo = b.tipo and a.numero = b.numero and a.alm = b.alm ";
  sql_z += " and a.cia = b.cia where a.tipo = :TIPOVTA ";
  sql_z += " and a.fecha between :FECINI and :FECFIN and a.status = 'C' ";
  sql_z += " and a.cia = :CIA ";
  sql_z += " and b.codinv  = :CODIGO ";

  if(tiposalida_z == "VENTAS_MENUDEO") {
    tipovta_z = "V";
    dias_z = maxdiasmen_z;
  }
  if(tiposalida_z == "VENTAS_MAYOREO") {
    tipovta_z = "M";
    dias_z = maxdiasmay_z;
  }
  fecini_z = hoy_z - dias_z;
  dd1_z = DateToStr(fecini_z) + " - " + DateToStr(inianu_z);

  if( (int) fecini_z > (int)inianu_z) {
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Text = sql_z;
    dm->qry_maxidvnd->ParamByName("fecini")->AsDateTime = fecini_z;
    dm->qry_maxidvnd->ParamByName("fecfin")->AsDateTime = hoy_z;
    dm->qry_maxidvnd->ParamByName("codigo")->AsString = codigo_z;
    dm->qry_maxidvnd->ParamByName("tipovta")->AsString = tipovta_z;
    dm->qry_maxidvnd->ParamByName("cia")->AsInteger = cia_z;
    dm->qry_maxidvnd->Open();
    if(!dm->qry_maxidvnd->IsEmpty()) {
      unidades_z = dm->qry_maxidvnd->FieldByName("unids")->AsInteger;
    }
  }
  return (unidades_z);
}

void __fastcall TForm_consuinv::desplegar_ofertasExecute(TObject *Sender)
{
  desplegarofertas_z = "SI";
  busca_oferta_historico(qry_inven->FieldByName("codigo")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consuinv::despliega_historico_costo_repoExecute(
      TObject *Sender)
{
  String codigo_z;
  codigo_z  = edt_codigo->Text;
  TForm_CapturaObsPed *Form_CapturaObsPed = new TForm_CapturaObsPed (this, "R", "R", 0, cia_z, codigo_z, "T");
  Form_CapturaObsPed->Panel1->Visible = false;
  Form_CapturaObsPed->ShowModal();
  delete Form_CapturaObsPed;
}
//---------------------------------------------------------------------------

int __fastcall TForm_consuinv::busca_servicio(String codigo_z)
{

   double servicio_z = 0;
   qry_servicio->Close();
   qry_servicio->ParamByName("codigo")->AsString = codigo_z;
   qry_servicio->ParamByName("cia")->AsInteger = cia_z;
   qry_servicio->ParamByName("tipo")->AsInteger = SERVICIO_ARTICULO;
   qry_servicio->Open();
   if(qry_servicio->IsEmpty()) {
     qry_servxgpo->Close();
     qry_servxgpo->ParamByName("codigo")->AsString = codigo_z;
     qry_servxgpo->ParamByName("cia")->AsInteger = cia_z;
     qry_servxgpo->ParamByName("REL_GRUPO")->AsInteger = REL_INVEN_ARTDESP;
     qry_servxgpo->ParamByName("tipo")->AsInteger = SERVICIO_GRUPO;
     qry_servxgpo->Open();
     if(!qry_servxgpo->IsEmpty()) {
       servicio_z = qry_servxgpo->FieldByName("impservicio")->AsFloat;
     }
   } else {
     servicio_z = qry_servicio->FieldByName("impservicio")->AsFloat;
   }

   edt_servicio->Value = servicio_z;
}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::ModificaDatosInternetExecute(
      TObject *Sender)
{
  int ancho_z, alto_z;
  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TFrame_datosinternet *Frame_datosinternetnvo;
  Frame_datosinternetnvo = new TFrame_datosinternet(this);
  ancho_z = Frame_datosinternetnvo->Width + 20;
  alto_z = Frame_datosinternetnvo->Height + Dlg_analipol->Panel2->Height + 80;
  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;
  Frame_datosinternetnvo->Parent = Dlg_analipol->Panel1;
  Frame_datosinternetnvo->codigo_z = edt_codigo->Text;
  Frame_datosinternetnvo->cia_z = cia_z;
  Dlg_analipol->Caption = "Datos para venta Internet";
  Frame_datosinternetnvo->inicializa();
  if( Dlg_analipol->ShowModal() == mrOk) {
    Frame_datosinternetnvo->graba_datos_internet();
    muestra_datos_internet();
  }
  delete Frame_datosinternetnvo;
  delete Dlg_analipol;

}
//---------------------------------------------------------------------------


void __fastcall TForm_consuinv::muestra_datos_internet()
{
    Frame_datosinternet1->codigo_z = edt_codigo->Text;
    Frame_datosinternet1->cia_z = cia_z;
    Frame_datosinternet1->edt_titulo->ReadOnly = true;
    Frame_datosinternet1->mmo_descripcion->ReadOnly = true;
    Frame_datosinternet1->btn_cambiagrp->Visible = false;
    Frame_datosinternet1->inicializa();
}
//---------------------------------------------------------------------------

