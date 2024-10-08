//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_analimvm.h"
#include "numapal.h"
#include "situaciones.h"
#include "dmod.h"
#include "imprigra.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const int LINEAS_X_PAG = 60;
TForm_analimvm *Form_analimvm;
//---------------------------------------------------------------------------
__fastcall TForm_analimvm::TForm_analimvm(TComponent* Owner)
        : TForm(Owner)
{
   date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
   calcula_vigencia();
   cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::reporte_vigtes_may()
{
  String alm_z, status1_z="x", status2_z="x",
    prmay_z, ulmay_z;
  int minexi_z, numlin_z = 0;
  TDateTime fecorte_z;
  alm_z = edt_almini->Text.Trim();

  int maximo_z = 0;
  alm_z = edt_almini->Text.Trim();
  prmay_z = edt_mayoini->Text.Trim();
  ulmay_z = edt_mayofin->Text.Trim();
  fecorte_z = date_corte->Date;
  if (rbtn_exisi->Checked ) status1_z = "S";
  if (rbtn_exino->Checked ) status2_z = "N";
  if (rbtn_exitot->Checked ) {
     status1_z = "S"; status2_z = "N";
  }
  qry_mayoristas->Close();
  qry_mayoristas->ParamByName("prmayo")->AsString = prmay_z;
  qry_mayoristas->ParamByName("ulmayo")->AsString = ulmay_z;
  qry_mayoristas->ParamByName("fecorte")->AsDateTime = fecorte_z;
  qry_mayoristas->ParamByName("cia")->AsInteger = cia_z;
  qry_mayoristas->Open();
  subenc_z = "VIG_X_MAYORIS_X_MESES";

  antmayoris_z = "-1";
  for( qry_mayoristas->First(); !qry_mayoristas->Eof; qry_mayoristas->Next()) {
    genera_reporte_vigtes();
  }
  imprime_totalmay();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::genera_reporte_vigtes()
{
  mayoris_z = qry_mayoristas->FieldByName("mayoris")->AsString;
  qry_perioxmay->Close();
  qry_perioxmay->ParamByName("mayoris")->AsString = mayoris_z;
  qry_perioxmay->ParamByName("fecorte")->AsDateTime = date_corte->Date;
  qry_perioxmay->ParamByName("cia")->AsInteger = cia_z;
  qry_perioxmay->Open();
  qry_doctospend->Close();
  qry_doctospend->ParamByName("mayoris")->AsString = mayoris_z;
  qry_doctospend->ParamByName("fecorte")->AsDateTime = date_corte->Date;
  qry_doctospend->ParamByName("cia")->AsInteger = cia_z;
  qry_doctospend->Open();
  if(antmayoris_z == "-1") {
    antmayoris_z = mayoris_z;
    if (!checa_iniciopag()) report_encab();

  } else {
    antmayoris_z = mayoris_z;
    if( !checa_saltopag(5)) {
       encab_mayoris("", "");
    }
  }
  for (qry_doctospend->First(); !qry_doctospend->Eof; qry_doctospend->Next()) {
    imprime_doctopend();
  }
  imprime_subtotmay();

}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_doctopend()
{
  String mayoris_z, perioven_z, doctven_z;
  TDateTime vence_z, fecha_z;
  double importe_z, saldo_z=0, saldohor_z = 0, saldomay_z = 0;
  int docto_z;
  checa_saltopag(4);
  docto_z   = qry_doctospend->FieldByName("docto")->AsInteger;
  fecha_z   = qry_doctospend->FieldByName("fecha")->AsDateTime;
  vence_z   = qry_doctospend->FieldByName("vence")->AsDateTime;
  doctven_z = FormatDateTime("yyyymm", vence_z);
  importe_z = qry_doctospend->FieldByName("importe")->AsFloat;
  saldo_z   = importe_z - qry_doctospend->FieldByName("abonos")->AsFloat;
  saldohor_z = 0;

  //fprintf(archout, "%s|", ljust(codigo_z, 13));
  fprintf(archout, "%s   |", rjust(FormatFloat("0", docto_z), 6));
  fprintf(archout, "%s|", FormatDateTime("dd/mm/yyyy", fecha_z));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", importe_z), 12));
  for( qry_perioxmay->First(); !qry_perioxmay->Eof; qry_perioxmay->Next()) {
    perioven_z = FormatFloat("0000", qry_perioxmay->FieldByName("anu")->AsInteger);
    perioven_z += FormatFloat("00", qry_perioxmay->FieldByName("mes")->AsInteger);
    if(perioven_z == doctven_z) {
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", saldo_z), 12));
      qry_perioxmay->Edit();
      qry_perioxmay->FieldByName("saldo")->AsFloat += saldo_z;
      qry_perioxmay->Post();
      saldohor_z += saldo_z;
    } else {
      fprintf(archout, "%s|", rjust("", 12));
    }
  }
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", saldohor_z), 12));
  fprintf(archout, "\n");
  lineas_z += 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_subtotmay()
{
  String mayoris_z, perioven_z, doctven_z;
  TDateTime vence_z, fecha_z;
  double saldohor_z = 0,saldo_z=0, saldomay_z = 0;
  checa_saltopag(4);
  saldohor_z = 0;

  //fprintf(archout, "%s|", ljust(codigo_z, 13));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total Vigente este Cliente ", 33));
  for( qry_perioxmay->First(); !qry_perioxmay->Eof; qry_perioxmay->Next()) {
    saldo_z = qry_perioxmay->FieldByName("saldo")->AsFloat;
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", saldo_z), 12));
    saldohor_z += saldo_z;
  }
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", saldohor_z), 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n\n");
  lineas_z += 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_totalmay()
{
  String mayoris_z, perioven_z, doctven_z, mimes_z, sql_z;
  TDateTime vence_z, fecha_z;
  int anu_z, mes_z;
  double saldohor_z = 0,saldo_z=0, saldomay_z = 0;
  sql_z = "delete from entpagtmp";
  dm->qry_iddato->Close();
  dm->qry_iddato->SQL->Text = sql_z;
  dm->qry_iddato->ExecSQL();


  sql_z = "insert into entpagtmp ( prove, numero, plazo, importe, fecprp, planp, cia, ctofinent) ";
  sql_z += " select a.mayoris, a.docto, a.pagare, a.importe, a.vence, a.tipofac, a.cia,";
  sql_z += " ( ";
  sql_z += "  select sum(b.importe) from movmay2 b where b.mayoris = a.mayoris and b.docto = a.docto and b.tipofac = a.tipofac ";
  sql_z += "  and b.pagare = a.pagare and b.cia = a.cia and b.coa = 'A' and b.fecha <= :FECORTE";
  sql_z += " ) as abonos from movmay2 a where ";
  sql_z += " a.coa = 'C' ";
  sql_z += " and a.fecha <= :FECORTE ";
  sql_z += " and ( a.saldo > 0.5 or ( a.saldo < 0.5 and a.fecsal > :FECORTE ) )";
  sql_z += " and a.cia = :CIA group by a.mayoris, a.docto, a.pagare,";
  sql_z += " a.importe, a.concep, a.tipago, a.vence, a.fecha, a.tipofac, a.cia ";
  dm->qry_iddato->Close();
  dm->qry_iddato->SQL->Text = sql_z;
  dm->qry_iddato->ParamByName("fecorte")->AsDateTime = date_corte->Date;
  dm->qry_iddato->ParamByName("cia")->AsInteger = cia_z;
  dm->qry_iddato->ExecSQL();

  sql_z  = " update entpagtmp set  ctofinent = 0 where ctofinent is null";
  dm->qry_iddato->Close();
  dm->qry_iddato->SQL->Text = sql_z;
  dm->qry_iddato->ExecSQL();

  sql_z  = " select ";
  sql_z += " extract(YEAR  from fecprp) as anu,";
  sql_z += " extract(month from fecprp) as mes,";
  sql_z += " sum(a.importe - ctofinent) as saldo";
  sql_z += " from entpagtmp a group by anu, mes";
  dm->qry_iddato->Close();
  dm->qry_iddato->SQL->Text = sql_z;
  dm->qry_iddato->Open();
  subenc_z = "TOTAL_X_MESES";

  if (! checa_saltopag(4)) {
    encab_total_vigentes_x_meses();
  }
  saldohor_z = 0;

  //fprintf(archout, "%s|", ljust(codigo_z, 13));
  for( dm->qry_iddato->First(); !dm->qry_iddato->Eof; dm->qry_iddato->Next()) {
    checa_saltopag(2);
    mes_z = dm->qry_iddato->FieldByName("mes")->AsInteger;
    anu_z = dm->qry_iddato->FieldByName("anu")->AsInteger;
    mimes_z = nommes( mes_z);
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
    fprintf(archout, "%s|", ljust(mimes_z, 12)  + " " + IntToStr(anu_z));
    saldo_z = dm->qry_iddato->FieldByName("saldo")->AsFloat;
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", saldo_z), 13));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
    fprintf(archout, "\n");
    lineas_z ++;
    saldohor_z += saldo_z;
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Saldo Total", 17));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", saldohor_z), 13));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------



void __fastcall TForm_analimvm::genera_reporte()
{

}
//---------------------------------------------------------------------------

int  __fastcall TForm_analimvm::calcula_maximo()
{
  return(0);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_renglon()
{

}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::report_encab()
{
  String ll_z;
  fprintf(archout, "\n");
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );

  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_analimvm " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );
  ll_z = " Reporte de Facturas Vgentes de Mayoristas AL " + FormatDateTime("dd/mm/yyyy", date_corte->Date);

  fprintf(archout, "%s\n", cjust( ll_z,70));
  fprintf(archout, "\n");
  lineas_z = 5;
  if ( subenc_z == "VIG_X_MAYORIS_X_MESES") encab_mayoris("", "");
  if ( subenc_z == "TOTAL_X_MESES")         encab_total_vigentes_x_meses();
  if ( subenc_z == "EDO_RES_MAYOREO")       encab_edo_may();
  if ( subenc_z == "MUB_MAYOREO_1")         encab_mub_may();
  if ( subenc_z == "MUB_MAYOREO_2")         encab_mub_may();
  if ( subenc_z == "ANALI_ABONOS")          subenc_analiabonos();
  if ( subenc_z == "ANALI_CARGOS")          subenc_analicargos();

}
//---------------------------------------------------------------------------


void __fastcall TForm_analimvm::encab_mayoris( String antmay_z, String antnomb_z )
{
  String nombre_z = "", mimes_z;
  int mes_z, anu_z;
  nombre_z = dm->obten_nombre("MAY", antmayoris_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  fprintf(archout, "%s", ljust("Cliente :" + antmayoris_z + " " + nombre_z , 50));
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Documento", 10));
  fprintf(archout, "%s|", cjust("Fecha", 10));
  fprintf(archout, "%s|", rjust("Importe", 12));
  for(qry_perioxmay->First(); !qry_perioxmay->Eof; qry_perioxmay->Next()) {
    mes_z = qry_perioxmay->FieldByName("mes")->AsInteger;
    anu_z = qry_perioxmay->FieldByName("anu")->AsInteger;
    mimes_z = nommes( mes_z);
    fprintf(archout, "%s|", cjust(mimes_z, 7)  + " " + IntToStr(anu_z));
  }
  fprintf(archout, "%s|", rjust("Saldo", 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::encab_total_vigentes_x_meses()
{
  fprintf(archout, "%s", cjust("Total Vigentes", 33));
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Periodo", 17));
  fprintf(archout, "%s|", cjust("Saldo", 13));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::total_linea()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "PRECIOS MAS IVA SUJETOS A CAMBIOS SIN PREVIO AVISO");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  fprintf(archout, "SURTIDO SUJETO A DISPONIBILIDAD\n");
  fprintf(archout, "ESTE REPORTE ES INFORMATIVO PARA SU COMPRA Y REQUERIMIENTO\n");
  lineas_z += 3;

}
//---------------------------------------------------------------------------
///--------- Area Edo de Resultados Mayoreo ------------------

void __fastcall TForm_analimvm::edo_res_mayoreo()
{
  // Primero voy a Agregar aquellos que tengan saldo el mes anterior
  // pero posiblemente este mes no tuvieron movimientos
  String sql_z;
  TDateTime corteant_z, fecorte_z;
  fecorte_z = date_corte->Date;
  corteant_z = UltimoDiaMes(IncMonth(fecorte_z, -1));
  sql_z = FormatDateTime("yyyymmdd", corteant_z);

  sql_z = " insert into edomay ( mayoris, sdofin, fecha ) ";
  sql_z += " select a.mayoris, a.sdofin, :FECORTE ";
  sql_z += " from edomay a where a.fecha = :CORTEANTER and a.cia = :CIA";
  sql_z += " and a.sdofin > 0.5 and a.mayoris not in ";
  sql_z += " ( select b.mayoris from edomay b where ";
  sql_z += "    b.fecha = :FECORTE and b.cia = :CIA ) ";

  dm->qry_iddato->Close();
  dm->qry_iddato->SQL->Text = sql_z;
  dm->qry_iddato->ParamByName("fecorte")->AsDateTime = fecorte_z;
  dm->qry_iddato->ParamByName("corteanter")->AsDateTime = corteant_z;
  dm->qry_iddato->ParamByName("cia")->AsInteger = cia_z;
  dm->qry_iddato->ExecSQL();

  qry_edomay->Close();
  qry_edomay->ParamByName("fecorte")->AsDateTime = fecorte_z;
  qry_edomay->ParamByName("corteanter")->AsDateTime = corteant_z;
  qry_edomay->ParamByName("cia")->AsInteger = cia_z;
  qry_edomay->Open();
  subenc_z = "EDO_RES_MAYOREO";
  if (!checa_iniciopag()) {
    if (!checa_saltopag(qry_edomay->RecordCount+4)) {
      fprintf(archout, "\n"); lineas_z++; encab_edo_may();
    }
  }


  for( qry_edomay->First(); !qry_edomay->Eof; qry_edomay->Next() ) {
    imprime_ren_edoresmay();
  }
  imprime_ulin_edoresmay();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::encab_edo_may()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", cjust("Cuadro de Estado Resultados Mayoreo", 40));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Mayo", 4));
  fprintf(archout, "%s|", ljust("Nombre", 30));
  fprintf(archout, "%s|", rjust("Saldo Ant.", 12));
  fprintf(archout, "%s|", rjust("Compras", 12));
  fprintf(archout, "%s|", rjust("Disponible", 12));
  fprintf(archout, "%s|", rjust("Abonos", 12));
  fprintf(archout, "%s|", rjust("Bonificacion", 12));
  fprintf(archout, "%s|", rjust("Devoluciones", 12));
  fprintf(archout, "%s|", rjust("Saldo", 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z +=2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_ren_edoresmay()
{
  String nombre_z = "", mimes_z;
  double sdoant_z=0, compras_z, abonos_z, bonif_z, devols_z, saldo_z;
  int mes_z, anu_z;
  mayoris_z = qry_edomay->FieldByName("mayoris")->AsString;
  nombre_z = dm->obten_nombre("MAY", mayoris_z);
  sdoant_z  = qry_edomay->FieldByName("sdoant")->AsFloat;
  compras_z = qry_edomay->FieldByName("comp")->AsFloat;
  abonos_z  = qry_edomay->FieldByName("abon")->AsFloat;
  devols_z  = qry_edomay->FieldByName("devs")->AsFloat;
  bonif_z   = qry_edomay->FieldByName("bon")->AsFloat;
  saldo_z   = sdoant_z + compras_z - abonos_z - devols_z - bonif_z;
  checa_saltopag(2);
  fprintf(archout, "%s|", ljust(mayoris_z, 4));
  fprintf(archout, "%s|", ljust(nombre_z, 30));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", sdoant_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", compras_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", sdoant_z + compras_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", abonos_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", bonif_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", devols_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", saldo_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
  graba_edomay(mayoris_z, saldo_z, 0, 0, "SALDO");

}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_ulin_edoresmay()
{
  String nombre_z = "", mimes_z;
  double sdoant_z=0, compras_z=0, abonos_z=0, bonif_z=0, devols_z=0, saldo_z=0;
  for(qry_edomay->First(); !qry_edomay->Eof; qry_edomay->Next()) {
    sdoant_z  += qry_edomay->FieldByName("sdoant")->AsFloat;
    compras_z += qry_edomay->FieldByName("comp")->AsFloat;
    abonos_z  += qry_edomay->FieldByName("abon")->AsFloat;
    devols_z  += qry_edomay->FieldByName("devs")->AsFloat;
    bonif_z   += qry_edomay->FieldByName("bon")->AsFloat;
  }
  saldo_z   = sdoant_z + compras_z - abonos_z - devols_z - bonif_z;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("", 4));
  fprintf(archout, "%s|", ljust("Total General", 30));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", sdoant_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", compras_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", sdoant_z + compras_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", abonos_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", bonif_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", devols_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", saldo_z), 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------


void __fastcall TForm_analimvm::mub_mayoreo()
{
  String sql_z;
  bool haysal_z;
  double salmay_z=0, facmay_z=0, notcred_z=0;
  TDateTime iniperio_z, fecorte_z;
  fecorte_z = UltimoDiaMes(date_corte->Date);
  iniperio_z = PrimerDiaMes(fecorte_z);
  sql_z = FormatDateTime("yyyymmdd", iniperio_z);
  qry_mubmay->Close();
  qry_mubmay->ParamByName("cia")->AsInteger = cia_z;
  qry_mubmay->ParamByName("fecini")->AsDateTime = iniperio_z;
  qry_mubmay->ParamByName("fecfin")->AsDateTime = fecorte_z;
  qry_mubmay->ParamByName("TIPO_FAC_MAY")->AsInteger = TIPO_FAC_MAY;
  qry_mubmay->Open();
  subenc_z = "MUB_MAYOREO_1";
  // Forzando un salto de p�gina
  haysal_z = checa_iniciopag();
  if (!haysal_z) report_encab();
  for(qry_mubmay->First(); !qry_mubmay->Eof; qry_mubmay->Next()) {
    salmay_z += qry_mubmay->FieldByName("salmay")->AsFloat;
    facmay_z += qry_mubmay->FieldByName("totfac")->AsFloat;
    notcred_z += qry_mubmay->FieldByName("ncredsiniva")->AsFloat;
    imprime_ren_mubmay("SIN NCRED");
  }
  imprime_ulin_mubmay("SIN CRED", salmay_z, facmay_z, notcred_z);
  salmay_z = facmay_z = notcred_z = 0;
  subenc_z = "MUB_MAYOREO_2";
  // Checo si hay Espacio para todo el MUB
  if( !checa_saltopag(qry_mubmay->RecordCount * 2 + 3)) {
    fprintf(archout, "\n", 12); lineas_z++;
    encab_mub_may();
  }
  for(qry_mubmay->First(); !qry_mubmay->Eof; qry_mubmay->Next()) {
    salmay_z += qry_mubmay->FieldByName("salmay")->AsFloat;
    facmay_z += qry_mubmay->FieldByName("totfac")->AsFloat;
    notcred_z += qry_mubmay->FieldByName("ncredsiniva")->AsFloat;
    imprime_ren_mubmay("AJUSTADO");
  }
  imprime_ulin_mubmay("AJUSTADO", salmay_z, facmay_z, notcred_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_ren_mubmay(String modo_z)
{
  String nombre_z;
  double salmay_z=0, facmay_z=0, notcred_z=0, porc1_z = -1;
  checa_saltopag(3);
  mayoris_z  = qry_mubmay->FieldByName("mayoris")->AsString;
  nombre_z = dm->obten_nombre("MAY", mayoris_z);
  salmay_z  = qry_mubmay->FieldByName("salmay")->AsFloat;
  facmay_z  = qry_mubmay->FieldByName("totfac")->AsFloat;
  notcred_z = qry_mubmay->FieldByName("ncredsiniva")->AsFloat;
  if(modo_z == "AJUSTADO") {
    facmay_z -= notcred_z;
  }
  if(facmay_z) porc1_z = salmay_z / facmay_z * 100;
  fprintf(archout, "%s ", ljust(mayoris_z,4));
  fprintf(archout, "%s ", ljust(nombre_z,50));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", salmay_z), 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, " = %s \% ", rjust(FormatFloat("0.00", porc1_z), 12));
  fprintf(archout, "\n");
  fprintf(archout, "%s", ljust("",46));
  fprintf(archout, "%s ", rjust("Ventas :",12));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", facmay_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_ulin_mubmay(String modo_z,
  double salmay_z, double facmay_z, double notcred_z)
{
  String nombre_z="";
  double resultados_z=0, porc1_z = -1;
  checa_saltopag(3);
  if(modo_z == "AJUSTADO") {
    facmay_z -= notcred_z;
  }
  if(facmay_z) porc1_z = salmay_z / facmay_z * 100;
  fprintf(archout, "%s\n", nombre_z.StringOfChar('=', 80));
  lineas_z++;
  fprintf(archout, "%s ", ljust(nombre_z,56));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", salmay_z), 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, " = %s \% ", rjust(FormatFloat("0.00", porc1_z), 12));
  fprintf(archout, "\n");
  fprintf(archout, "%s", ljust("",46));
  fprintf(archout, "%s ", rjust("Ventas :",12));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", facmay_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
  resultados_z = facmay_z - salmay_z;
  if(facmay_z) porc1_z = resultados_z / facmay_z * 100;
  fprintf(archout, " Resultados $");
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", resultados_z), 12));
  fprintf(archout, " IGUAL A UN  %s \% M.U.B", rjust(FormatFloat("0.00", porc1_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
  fprintf(archout, "%s ", ljust("Importes Antes de Iva",56));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------


void __fastcall TForm_analimvm::encab_mub_may()
{
  String titul_z;
  if (subenc_z == "MUB_MAYOREO_1") {
    titul_z = "Reporte MUB Mayoreo";
  }
  if (subenc_z == "MUB_MAYOREO_2") {
    titul_z = "Reporte MUB Mayoreo Ajustado";
  }

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", cjust(titul_z, 40));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::analitico_abonos()
{
  String tipo_z, sql_z, prmay_z, ulmay_z;
  prmay_z = edt_mayoini->Text.Trim();
  ulmay_z = edt_mayofin->Text.Trim();
  double importe_z =0, efectivo_z=0, bonifi_z = 0, devol_z = 0,
    totefectivo_z=0, totbonifi_z = 0, totdevol_z = 0;
  TDateTime iniperio_z, fecorte_z;
  fecorte_z = UltimoDiaMes(date_corte->Date);
  iniperio_z = PrimerDiaMes(fecorte_z);
  sql_z = FormatDateTime("yyyymmdd", iniperio_z);
  qry_abonos->Close();
  qry_abonos->ParamByName("cia")->AsInteger = cia_z;
  qry_abonos->ParamByName("fecini")->AsDateTime = iniperio_z;
  qry_abonos->ParamByName("fecfin")->AsDateTime = fecorte_z;
  qry_abonos->ParamByName("prmayo")->AsString = prmay_z;
  qry_abonos->ParamByName("ulmayo")->AsString = ulmay_z;
  qry_abonos->Open();
  subenc_z = "ANALI_ABONOS";
  antmayoris_z = "-1";
  // Forzando un salto de p�gina
  for(qry_abonos->First(); !qry_abonos->Eof; qry_abonos->Next()) {
    importe_z = qry_abonos->FieldByName("importe")->AsFloat;
    tipo_z    = qry_abonos->FieldByName("tipago")->AsString;
    mayoris_z  = qry_abonos->FieldByName("mayoris")->AsString;
    if(antmayoris_z == "-1") {
      antmayoris_z = mayoris_z;
      if (!checa_iniciopag()) report_encab();
    }
    if( antmayoris_z != mayoris_z) {
      subtotal_abonos_mayoreo(antmayoris_z, efectivo_z, bonifi_z, devol_z);
      graba_edomay(antmayoris_z, efectivo_z, bonifi_z, devol_z, "ABONOS");
      efectivo_z = bonifi_z = devol_z = 0;
      antmayoris_z = mayoris_z;
      fprintf(archout, "\n");
      lineas_z ++;
      if (!checa_saltopag(5) ) subenc_analiabonos();
    }
    checa_saltopag(3);
    if(tipo_z == "E") {
      efectivo_z    += importe_z;
      totefectivo_z += importe_z;
    }
    if(tipo_z == "B" || tipo_z == "N") {
      bonifi_z    += importe_z;
      totbonifi_z += importe_z;
    }
    if(tipo_z == "D") {
      devol_z    += importe_z;
      totdevol_z += importe_z;
    }
    imprime_ren_analiabonos();
  }
  subtotal_abonos_mayoreo(mayoris_z, efectivo_z, bonifi_z, devol_z);
  subtotal_abonos_mayoreo("TOTAL", totefectivo_z, totbonifi_z, totdevol_z);
  efectivo_z = bonifi_z = devol_z = 0;
  totefectivo_z = totbonifi_z = totdevol_z = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::graba_edomay(String mayoris_z,
  double efectivo_z, double bonifi_z, double devol_z, String modo_z)
{
  qry_updtedomay->Close();
  qry_updtedomay->ParamByName("mayoris")->AsString = mayoris_z;
  qry_updtedomay->ParamByName("cia")->AsInteger = cia_z;
  qry_updtedomay->ParamByName("fecha")->AsDateTime = date_corte->Date;
  qry_updtedomay->Open();
  if ( qry_updtedomay->IsEmpty() ) {
    qry_updtedomay->Append();
    qry_updtedomay->FieldByName("mayoris")->AsString = mayoris_z;
    qry_updtedomay->FieldByName("cia")->AsInteger = cia_z;
    qry_updtedomay->FieldByName("fecha")->AsDateTime = date_corte->Date;
  } else {
    qry_updtedomay->Edit();
  }
  if (modo_z == "ABONOS") {
    qry_updtedomay->FieldByName("abonos")->AsFloat = efectivo_z;
    qry_updtedomay->FieldByName("devols")->AsFloat = devol_z;
    qry_updtedomay->FieldByName("bonif")->AsFloat  = bonifi_z;
  }
  if (modo_z == "CARGOS") {
    qry_updtedomay->FieldByName("compras")->AsFloat = efectivo_z;
  }
  if (modo_z == "SALDO") {
    qry_updtedomay->FieldByName("sdofin")->AsFloat = efectivo_z;
  }
  qry_updtedomay->Post();
  try {
     dm->manvehi->StartTransaction();
     qry_updtedomay->ApplyUpdates();
     dm->manvehi->Commit();
  } catch (Exception &E)
  {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}

void __fastcall TForm_analimvm::imprime_ren_analiabonos()
{
  int docto_z, pagare_z;
  double importe_z;
  String concep_z, fechafac_z, fecha_z, vence_z;
  importe_z  = qry_abonos->FieldByName("importe")->AsFloat;
  docto_z    = qry_abonos->FieldByName("docto")->AsInteger;
  pagare_z   = qry_abonos->FieldByName("pagare")->AsInteger;
  fecha_z    = FormatDateTime("dd/mm/yyyy", qry_abonos->FieldByName("fecha")->AsDateTime);
  fechafac_z = FormatDateTime("dd/mm/yyyy", qry_abonos->FieldByName("fechafac")->AsDateTime);
  vence_z    = FormatDateTime("dd/mm/yyyy", qry_abonos->FieldByName("vence")->AsDateTime);
  concep_z   = qry_abonos->FieldByName("concep")->AsString;

  fprintf(archout, "%s/", rjust( FormatFloat("0", docto_z),6));
  fprintf(archout, "%s|", ljust( FormatFloat("0", pagare_z),2));
  fprintf(archout, "%s|", rjust(fechafac_z, 10));
  fprintf(archout, "%s|", ljust(concep_z, 30));
  fprintf(archout, "%s|", rjust(fecha_z, 10));
  fprintf(archout, "%s|", rjust(vence_z, 10));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", importe_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::subenc_analiabonos()
{
  String nombre_z = "";
  nombre_z = dm->obten_nombre("MAY", antmayoris_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  fprintf(archout, "%s", ljust("Cliente :" + antmayoris_z + " " + nombre_z , 50));
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Fact./Lta", 9));
  fprintf(archout, "%s|", cjust("Fecha.Fac", 10));
  fprintf(archout, "%s|", cjust("Concepto", 30));
  fprintf(archout, "%s|", cjust("Fecha Pago", 10));
  fprintf(archout, "%s|", cjust("Vencimiento", 10));
  fprintf(archout, "%s|", rjust("Importe", 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::subtotal_abonos_mayoreo(String mayoris_z,
     double efectivo_z, double bonifi_z, double devol_z
)
{
  int docto_z, pagare_z;
  double importe_z;
  String concep_z;
  importe_z  = efectivo_z + bonifi_z + devol_z;
  if(mayoris_z == "TOTAL") {
    concep_z = "Total General :";
  } else {
    concep_z = " Totales de " + dm->obten_nombre("MAY", antmayoris_z);
  }
  fprintf(archout, "%s|", ljust(concep_z, 73));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", importe_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
  fprintf(archout, "Efectivo: %s ", ljust(FormatFloat("##,###,##0.00", efectivo_z), 12));
  fprintf(archout, "Bonificaciones : %s", ljust(FormatFloat("##,###,##0.00", bonifi_z), 12));
  fprintf(archout, "Devoluciones : %s", ljust(FormatFloat("##,###,##0.00", devol_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::analitico_cargos()
{
  String tipo_z, sql_z, prmay_z, ulmay_z;
  prmay_z = edt_mayoini->Text.Trim();
  ulmay_z = edt_mayofin->Text.Trim();
  double importe_z =0, efectivo_z=0, bonifi_z = 0, devol_z = 0,
    totefectivo_z=0, totbonifi_z = 0, totdevol_z = 0;
  TDateTime iniperio_z, fecorte_z;
  fecorte_z = UltimoDiaMes(date_corte->Date);
  iniperio_z = PrimerDiaMes(fecorte_z);
  sql_z = FormatDateTime("yyyymmdd", iniperio_z);
  qry_cargos->Close();
  qry_cargos->ParamByName("cia")->AsInteger = cia_z;
  qry_cargos->ParamByName("fecini")->AsDateTime = iniperio_z;
  qry_cargos->ParamByName("fecfin")->AsDateTime = fecorte_z;
  qry_cargos->ParamByName("prmayo")->AsString = prmay_z;
  qry_cargos->ParamByName("ulmayo")->AsString = ulmay_z;
  qry_cargos->Open();
  subenc_z = "ANALI_CARGOS";
  antmayoris_z = "-1";
  // Forzando un salto de p�gina
  for(qry_cargos->First(); !qry_cargos->Eof; qry_cargos->Next()) {
    importe_z = qry_cargos->FieldByName("importe")->AsFloat;
    tipo_z    = qry_cargos->FieldByName("tipago")->AsString;
    mayoris_z  = qry_cargos->FieldByName("mayoris")->AsString;
    if(antmayoris_z == "-1") {
      antmayoris_z = mayoris_z;
      if (!checa_iniciopag()) report_encab();
    }
    if( antmayoris_z != mayoris_z) {
      subtotal_cargos_mayoreo(antmayoris_z, efectivo_z, bonifi_z, devol_z);
      graba_edomay(antmayoris_z, efectivo_z, bonifi_z, devol_z, "CARGOS");
      efectivo_z = bonifi_z = devol_z = 0;
      antmayoris_z = mayoris_z;
      fprintf(archout, "\n");
      lineas_z ++;
      if (!checa_saltopag(5) ) subenc_analicargos();
    }
    checa_saltopag(3);
    efectivo_z    += importe_z;
    totefectivo_z += importe_z;
    imprime_ren_analicargos();
  }
  subtotal_cargos_mayoreo(mayoris_z, efectivo_z, bonifi_z, devol_z);
  subtotal_cargos_mayoreo("TOTAL", totefectivo_z, totbonifi_z, totdevol_z);
  efectivo_z = bonifi_z = devol_z = 0;
  totefectivo_z = totbonifi_z = totdevol_z = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::subenc_analicargos()
{
  String nombre_z = "";
  nombre_z = dm->obten_nombre("MAY", antmayoris_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  fprintf(archout, "%s", ljust("Cliente :" + antmayoris_z + " " + nombre_z , 50));
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Fact./Lta", 9));
  fprintf(archout, "%s|", cjust("Fecha.Fac", 10));
  fprintf(archout, "%s|", cjust("Concepto", 30));
  fprintf(archout, "%s|", cjust("Vencimiento", 10));
  fprintf(archout, "%s|", rjust("Importe", 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprime_ren_analicargos()
{
  int docto_z, pagare_z;
  double importe_z;
  String concep_z, fechafac_z, fecha_z, vence_z;
  importe_z  = qry_cargos->FieldByName("importe")->AsFloat;
  docto_z    = qry_cargos->FieldByName("docto")->AsInteger;
  pagare_z   = qry_cargos->FieldByName("pagare")->AsInteger;
  fecha_z    = FormatDateTime("dd/mm/yyyy", qry_cargos->FieldByName("fecha")->AsDateTime);
  vence_z    = FormatDateTime("dd/mm/yyyy", qry_cargos->FieldByName("vence")->AsDateTime);
  concep_z   = qry_cargos->FieldByName("concep")->AsString;

  fprintf(archout, "%s/", rjust( FormatFloat("0", docto_z),6));
  fprintf(archout, "%s|", ljust( FormatFloat("0", pagare_z),2));
  fprintf(archout, "%s|", rjust(fecha_z, 10));
  fprintf(archout, "%s|", ljust(concep_z, 30));
  fprintf(archout, "%s|", rjust(vence_z, 10));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", importe_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::subtotal_cargos_mayoreo(String mayoris_z,
     double efectivo_z, double bonifi_z, double devol_z
)
{
  int docto_z, pagare_z;
  double importe_z;
  String concep_z;
  importe_z  = efectivo_z + bonifi_z + devol_z;
  if(mayoris_z == "TOTAL") {
    concep_z = "Total General :";
  } else {
    concep_z = " Totales de " + dm->obten_nombre("MAY", antmayoris_z);
  }
  fprintf(archout, "%s|", ljust(concep_z, 62));
  fprintf(archout, "%s", rjust(FormatFloat("##,###,##0.00", importe_z), 12));
  fprintf(archout, "\n");
  lineas_z ++;
}
//---------------------------------------------------------------------------


bool __fastcall TForm_analimvm::checa_saltopag(int numero_de_lineas)
{
  bool haysalto_z = false;

  if(lineas_z > ( LINEAS_X_PAG - numero_de_lineas) ) {
    fprintf(archout, "%c", 12); pagina_z++;
    report_encab();
    haysalto_z = true;
  }

  return(haysalto_z);
}
//---------------------------------------------------------------------------

bool __fastcall TForm_analimvm::checa_iniciopag()
{
  bool haysalto_z = false;
  if( pagina_z ) {
    salto_pagina(); haysalto_z = true;
  }
  return(haysalto_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::salto_pagina()
{
    fprintf(archout, "%c", 12); pagina_z++;
    report_encab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::total_zona()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analimvm::total_genzona()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analimvm::tabla_lineas()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analimvm::tabla_lineas_final()
{
}

//---------------------------------------------------------------------------
void __fastcall TForm_analimvm::Subtotales_porc(String tlinea_z)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analimvm::total_linea_tabla()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::tabla_linea_global()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::desglose_total_gen()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analimvm::total_global_tabla()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analimvm::FormCreate(TObject *Sender)
{
  date_corte->Date = UltimoDiaMes(IncMonth(dm->ahora(), -1));
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::imprimir_reporteExecute(TObject *Sender)
{

  String arch_z;
  if(Application->MessageBox("Seguro imprimir Reporte ?", "Impresi�n Reporte", MB_OKCANCEL) != IDOK ) return;
  arch_z = "frm_analimvm.txt";
  if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
  }
  if (chk_relvigtes->Checked)   reporte_vigtes_may();
  if (chk_edores->Checked)      edo_res_mayoreo();
  if (chk_mubmay->Checked)      mub_mayoreo();
  if (chk_analiabonos->Checked) analitico_abonos();
  if (chk_analicargos->Checked) analitico_cargos();
  fclose(archout);
  pagina_z = 0;
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_analimvm::calcula_vigencia()
{

  date_corte->Date = UltimoDiaMes(date_fecini->Date);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analimvm::date_feciniExit(TObject *Sender)
{
  calcula_vigencia();

}
//---------------------------------------------------------------------------


