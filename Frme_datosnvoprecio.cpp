//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosnvoprecio.h"
#include "dmod.h"
#include "numapal.h"
#include "situaciones.h"
#include "Frm_consuinv.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
TFrame_datosnvoprecio *Frame_datosnvoprecio;
//---------------------------------------------------------------------------
__fastcall TFrame_datosnvoprecio::TFrame_datosnvoprecio(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosnvoprecio::despliega_cambio_precio(String codigo_z)
{
  double precioact_z, precionvo_z, costoact_z, costonvo_z, mubact_z, mubnvo_z,
    preciomayact_z, preciomaynvo_z, preciofilact_z, preciofilnvo_z,
    mubmayact_z=0, mubmaynvo_z, piva_z=0, comboact_z=0, combonvo_z=0;
  String sql_z, linea_z, grupo_z, sqlxtensa_z, sitact_z, sitnva_z,
     miconcep_z, datoact_z, datonvo_z;
  TDateTime hoy_z;
  int plazoant_z, plazonvo_z;
  hoy_z = dm->ahora();
  cia_z = dm->cia_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  sql_z = "select a.fecha, a.fecini, b.precmds, b.nvoempaq, e.situacion as nvasit, \
          b.precioext, antprmds,  b.antempaq, f.situacion as antsit, c.linea, c.cod2 \
          from inv_polcampre a \
          join inv_renpolcampre b on a.idpolcampre = b.idpolcampre \
          join inv_invhist d on b.idart = d.idart and a.cia = d.cia \
          join inv_situaciones e on b.nvoempaq = e.idsituac \
          join inv_situaciones f on b.antempaq = f.idsituac \
          join inven c on d.codigo = c.codigo and a.cia = c.cia \
          where a.fecha <= :FECHA and a.fecini >= :FECHA and a.cia = :CIA and \
          a.status = :STATUS_CAMBIOPRECIO and \
          c.codigo = :CODIGO ";
  sqlxtensa_z = " select idextensa, a.idart, precioext, costoext \
    from inv_invhist a join inv_extensa b on a.idart = b.idart \
    where a.codigo = :CODIGO and a.cia = :CIA";


  TQuery *qry_consprecios = new TQuery (this);
  qry_consprecios->DatabaseName = qry_inven->DatabaseName;
  TQuery *qry_extensa = new TQuery (this);
  qry_extensa->DatabaseName = qry_inven->DatabaseName;
  qry_extensa->SQL->Text = sqlxtensa_z;
  qry_consprecios->Close();
  qry_consprecios->SQL->Text = sql_z;
  qry_consprecios->ParamByName("fecha")->AsDateTime = hoy_z;
  qry_consprecios->ParamByName("codigo")->AsString  = codigo_z;
  qry_consprecios->ParamByName("STATUS_CAMBIOPRECIO")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
  qry_consprecios->ParamByName("cia")->AsInteger    = cia_z;
  qry_consprecios->Open();
//  precioact_z = qry_inven->FieldByName("precio")->AsFloat;
//  sitact_z = qry_inven->FieldByName("empaqe")->AsString;
  precioact_z = qry_consprecios->FieldByName("antprmds")->AsFloat;
  sitact_z = qry_consprecios->FieldByName("antsit")->AsString;
  linea_z = qry_consprecios->FieldByName("linea")->AsString;
  grupo_z = qry_consprecios->FieldByName("cod2")->AsString;
  costoact_z = qry_inven->FieldByName("coston")->AsFloat;
  piva_z = qry_inven->FieldByName("piva")->AsFloat;
  preciomayact_z = calcu_prmay(codigo_z, TIPO_MAYORISTA, precioact_z);
  preciomayact_z = preciomayact_z * (piva_z / 100 + 1);
  preciofilact_z = calcu_prmay(codigo_z, TIPO_FILIAL, precioact_z);
  preciofilact_z = preciofilact_z * (piva_z / 100 + 1);

  if( precioact_z ) {
    mubact_z = 100 * (1 -(costoact_z / precioact_z));
  }

  precionvo_z = qry_consprecios->FieldByName("precmds")->AsFloat;
  sitnva_z = qry_consprecios->FieldByName("nvasit")->AsString;
  costonvo_z = costoact_z;
  preciomaynvo_z = calcu_prmay(codigo_z, TIPO_MAYORISTA, precionvo_z);
  preciomaynvo_z = preciomaynvo_z * (piva_z / 100 + 1);
  preciofilnvo_z = calcu_prmay(codigo_z, TIPO_FILIAL, precionvo_z);
  preciofilnvo_z = preciofilnvo_z * (piva_z / 100 + 1);
  mubnvo_z = 100 * (1 -(costoact_z / precionvo_z));
  edt_fecha->Text = FormatDateTime("dd/mm/yyyy", qry_consprecios->FieldByName("fecha")->AsDateTime);
  edt_vigencia->Text = FormatDateTime("dd/mm/yyyy", qry_consprecios->FieldByName("fecini")->AsDateTime);
  qry_extensa->Close();
  qry_extensa->ParamByName("codigo")->AsString = codigo_z;
  qry_extensa->ParamByName("cia")->AsInteger = cia_z;
  qry_extensa->Open();
  comboact_z = 0;
  if(!qry_extensa->IsEmpty()) {
    comboact_z = precioact_z + qry_extensa->FieldByName("precioext")->AsFloat;
  }
  combonvo_z = precionvo_z + qry_consprecios->FieldByName("precioext")->AsFloat;
  plazonvo_z = Form_consuinv->busca_plazo(codigo_z, linea_z, grupo_z, combonvo_z);
  plazonvo_z = plazonvo_z * 2;
  delete qry_consprecios;
  delete qry_extensa;

  qry_cambios->Close();
  qry_cambios->Open();
  for (int ii_z = 0; ii_z < 9; ii_z++) {
    if(ii_z == 0) {
      miconcep_z = "Precio";
      datoact_z = FormatFloat("###,##0.00", precioact_z);
      datonvo_z = FormatFloat("###,##0.00", precionvo_z);
      edt_pract->Text = datoact_z;
      edt_prnvo->Text = datonvo_z;
    }
    if(ii_z == 1) {
      miconcep_z = "Costo Neto";
      datoact_z = FormatFloat("###,##0.00", costoact_z);
      datonvo_z = FormatFloat("###,##0.00", costoact_z);
      edt_coston->Text = datoact_z;
      //edt_pract->Text = datoact_z;
      //edt_prnvo->Text = datonvo_z;
    }
    if(ii_z == 2) {
      miconcep_z = "MUB";
      datoact_z = FormatFloat("###,##0.00", mubact_z);
      datonvo_z = FormatFloat("###,##0.00", mubnvo_z);
      edt_mubact->Text = datoact_z;
      edt_mubnvo->Text = datonvo_z;

    }
    if(ii_z == 3) {
      miconcep_z = "Precio Mayoreo";
      datoact_z = FormatFloat("###,##0.00", preciomayact_z);
      datonvo_z = FormatFloat("###,##0.00", preciomaynvo_z);
      edt_mayact->Text = datoact_z;
      edt_maynvo->Text = datonvo_z;
    }
    if(ii_z == 4) {
      miconcep_z = "Precio Filial";
      datoact_z = FormatFloat("###,##0.00", preciofilact_z);
      datonvo_z = FormatFloat("###,##0.00", preciofilnvo_z);
      edt_filact->Text = datoact_z;
      edt_filnvo->Text = datonvo_z;
    }
    if(ii_z == 5) {
      miconcep_z = "Situación";
      datoact_z = sitact_z;
      datonvo_z = sitnva_z;
      edt_sitact->Text = datoact_z;
      edt_sitnvo->Text = datonvo_z;
    }
    if(ii_z == 6 ){
      mubmayact_z = 100 * (1 -(costoact_z / preciomayact_z));
      mubmaynvo_z = 100 * (1 -(costoact_z / preciomaynvo_z));
      edt_mubmayact->Text = FormatFloat("###,##0.00", mubmayact_z);
      edt_mubmaynvo->Text = FormatFloat("###,##0.00", mubmaynvo_z);
    }
    if(ii_z == 7) {
      miconcep_z = "Precio";
      datoact_z = FormatFloat("###,##0.00", comboact_z);
      datonvo_z = FormatFloat("###,##0.00", combonvo_z);
      edt_comboact->Text = datoact_z;
      edt_combonvo->Text = datonvo_z;
    }
    if(ii_z == 8) {
      miconcep_z = "Plazo";
      edt_plazo->Text = Form_consuinv->edt_plazo->Text;
      edt_plazonvo->Text =   IntToStr(plazonvo_z) + " Q";
    }
    //qry_cambios->Append();
    //qry_cambios->FieldByName("idcambio")->AsInteger = ii_z;
    //qry_cambios->FieldByName("concep")->AsString = miconcep_z;
    //qry_cambios->FieldByName("precioant")->AsString = datoact_z;
    //qry_cambios->FieldByName("precionvo")->AsString = datonvo_z;
    //qry_cambios->Post();
  }

}
//---------------------------------------------------------------------------

double __fastcall TFrame_datosnvoprecio::calcu_prmay(String codigo_z, int tipomayoris_z, double preciomen_z)
{
  double mubmds_z=0, costo_z=0, preciou_z=0, costos_z=0,
    piva_z =0, factorprecio_z=0;
  String gpoesp_z="", empaqe_z = "", prove_z,
         sqlgpoesp_z, sqlinven_z, sqlpreciomaypro_z;
  int mitipomay_z;
//  TQuery *qry_inven              = new TQuery (this);
  TQuery *qry_preciomaypro       = new TQuery (this);
  TQuery *qry_grupoesp           = new TQuery (this);
//  qry_inven->DatabaseName        = qry_permis->DatabaseName;
  qry_preciomaypro->DatabaseName = qry_inven->DatabaseName;
  qry_grupoesp->DatabaseName     = qry_inven->DatabaseName;
  sqlgpoesp_z = " select a.codigo, b.codigo as grupo, c.* ";
  sqlgpoesp_z += " from inv_invhist a join inv_relinv d on a.idart = d.idart";
  sqlgpoesp_z += " and d.idrel = :TIPOREL join inv_grupos b on d.iddato = b.idgrupo ";
  sqlgpoesp_z += " join inv_gpomayprecio c on b.idgrupo = c.idgrupo ";
  sqlgpoesp_z += " where a.codigo = :CODIGO and a.cia = :CIA and c.tipo = :TIPOMAY";
//  sqlinven_z  = "select * from inven where codigo = :CODIGO and cia = :CIA";

  sqlpreciomaypro_z = "select idplazocrd, a.linea as prove, a.idlinea, plistamax as factorprecio, a.tipo, a.cia";
  sqlpreciomaypro_z += " from plazoscrd a";
  sqlpreciomaypro_z += " where a.linea = :PROVE and a.cia = :CIA and  a.tipo = :TIPO";

  qry_grupoesp->SQL->Text     = sqlgpoesp_z;
  qry_preciomaypro->SQL->Text = sqlpreciomaypro_z;

  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsString = cia_z;
  qry_inven->Open();
  if(!qry_inven->IsEmpty()) {
    codigo_z = qry_inven->FieldByName("codigo")->AsString;
    preciou_z = preciomen_z;
    piva_z = qry_inven->FieldByName("piva")->AsFloat;
    costo_z = qry_inven->FieldByName("costos")->AsFloat;
    empaqe_z = qry_inven->FieldByName("empaqe")->AsString;
    prove_z =  qry_inven->FieldByName("prove")->AsString;
    qry_preciomaypro->Close();
    qry_preciomaypro->ParamByName("prove")->AsString = prove_z;
    qry_preciomaypro->ParamByName("cia")->AsInteger = cia_z;
    qry_preciomaypro->ParamByName("tipo")->AsInteger = TIPO_FACTOR_PRECIOMAYPRO;
    qry_preciomaypro->Open();
    if(!qry_preciomaypro->IsEmpty()) {
       gpoesp_z = "G";
       factorprecio_z = qry_preciomaypro->FieldByName("factorprecio")->AsFloat;
       qry_preciomaypro->Close();
       if(factorprecio_z == 0) factorprecio_z = 1;
       preciou_z = Redondea( costo_z / factorprecio_z, 100);
    } else {
      qry_grupoesp->Close();
      qry_grupoesp->ParamByName("codigo")->AsString = codigo_z;
      qry_grupoesp->ParamByName("cia")->AsInteger = cia_z;
      qry_grupoesp->ParamByName("tiporel")->AsInteger = REL_INVEN_ARTDESP;
      qry_grupoesp->ParamByName("TIPOMAY")->AsInteger = tipomayoris_z;
      qry_grupoesp->Open();
      if(qry_grupoesp->IsEmpty()) {
        gpoesp_z = "N"; factorprecio_z = 0;
      } else {
        mitipomay_z = qry_grupoesp->FieldByName("tipo")->AsInteger;
        if(tipomayoris_z == mitipomay_z) {
           if(tipomayoris_z == TIPO_FILIAL)          gpoesp_z = "S";
           if(tipomayoris_z == TIPO_MAYORISTA)       gpoesp_z = "S";
           factorprecio_z = qry_grupoesp->FieldByName("factorprecio")->AsFloat;
        } else {
          gpoesp_z = "N"; factorprecio_z = 0;
        }
      }
    }
    preciou_z = Redondea(calcu_preciomay(empaqe_z, costo_z, preciou_z, piva_z, gpoesp_z, factorprecio_z), 100);

  }
  delete qry_grupoesp;
  delete qry_preciomaypro;

  return(preciou_z);
}
//---------------------------------------------------------------------------

