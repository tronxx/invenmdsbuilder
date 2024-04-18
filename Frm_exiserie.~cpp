//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_exiserie.h"
#include "numapal.h"
#include "situaciones.h"
#include "dmod.h"
#include "imprigra.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const int LINEAS_X_PAG = 60;
TForm_exiserie *Form_exiserie;
//---------------------------------------------------------------------------
__fastcall TForm_exiserie::TForm_exiserie(TComponent* Owner)
        : TForm(Owner)
{
   date_ini->Date = dm->ahora();
   //calcula_vigencia();
   cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::genera_reporte()
{

  String alm_z, status1_z="x", status2_z="x",
    prlinea_z, ullinea_z;
  int minexi_z, numlin_z = 0;
  TDateTime fecorte_z;
  alm_z = edt_almini->Text.Trim();

  int maximo_z = 0;
  alm_z = edt_almini->Text.Trim();
  prlinea_z = edt_lineaini->Text.Trim();
  ullinea_z = edt_lineafin->Text.Trim();
  fecorte_z = date_ini->Date;
  if (rbtn_exisi->Checked ) status1_z = "S";
  if (rbtn_exino->Checked ) status2_z = "N";
  if (rbtn_exitot->Checked ) {
     status1_z = "S"; status2_z = "N";
  }
  inianu_z = dm->inianuestadis();
  qry_exisi->Close();
  qry_exisi->ParamByName("prlinea")->AsString = prlinea_z;
  qry_exisi->ParamByName("ullinea")->AsString = ullinea_z;
  qry_exisi->ParamByName("modent1")->AsString = status1_z;
  qry_exisi->ParamByName("modent2")->AsString = status2_z;
  qry_exisi->ParamByName("alm")->AsString = alm_z;
  qry_exisi->ParamByName("fecorte")->AsDateTime = fecorte_z;
  qry_exisi->ParamByName("cia")->AsInteger = cia_z;
  qry_exisi->Open();
  antlinea_z = "-1";
  for( qry_exisi->First(); !qry_exisi->Eof; qry_exisi->Next()) {
    //maximo_z = calcula_maximo();
    imprime_renglon();
  }
  total_linea();
  total_general();
}
//---------------------------------------------------------------------------

int  __fastcall TForm_exiserie::calcula_maximo()
{
  int diasdif_z, maximo_z = 0, maxmay_z=0, univta_z=0, univtmay_z=0;
  double alta_z;
  alta_z = qry_exisi->FieldByName("fecalta")->AsDateTime;
  univta_z = qry_exisi->FieldByName("univta")->AsInteger;
  univtmay_z = qry_exisi->FieldByName("salmay")->AsInteger;
  if ( alta_z > inianu_z) {
    diasdif_z = date_ini->Date - alta_z;
  } else {
    diasdif_z = date_ini->Date - inianu_z;
  }
  if(diasdif_z) {
    maximo_z = univta_z / diasdif_z * 30;
    maxmay_z = univtmay_z / diasdif_z * 30;
  }
  return (maximo_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::imprime_renglon()
{
  String codigo_z, tipo_z, alm_z, serie_z = "",
    descri_z = "", status1_z="x", status2_z = "x";
  TDateTime fecorte_z, fechamov_z;
  double costou_z=0;
  alm_z = edt_almini->Text.Trim();
  fecorte_z = date_ini->Date;
  if (rbtn_exisi->Checked ) status1_z = "S";
  if (rbtn_exino->Checked ) status2_z = "N";
  if (rbtn_exitot->Checked ) {
     status1_z = "S"; status2_z = "N";
  }

  double preciomay_z = 0;
  int exist_z;
  linea_z = qry_exisi->FieldByName("linea")->AsString;
  if(antlinea_z == "-1") {
    antlinea_z = linea_z;
    report_encab();
  } else if( linea_z != antlinea_z) {
    total_linea(); antlinea_z = linea_z;
    if( !checa_saltopag(4)) {
      fprintf(archout, "\n"); lineas_z++;
      encab_linea("", "");
    }

  }
  exist_z  = qry_exisi->FieldByName("unidexis")->AsInteger;
  codigo_z = qry_exisi->FieldByName("codigo")->AsString;
  descri_z = qry_exisi->FieldByName("descri")->AsString;
  tipo_z   = qry_exisi->FieldByName("tipo")->AsString;

  //fprintf(archout, "%s|", ljust(codigo_z, 13));
  if(tipo_z == "GLO" || chk_impriserie->Checked ) {
    checa_saltopag(2);
    fprintf(archout, "%s|", ljust(descri_z, 30));
    fprintf(archout, "%s|", rjust(FormatFloat("0", exist_z), 4));
    qry_articulosglo->Close();
    qry_articulosglo->ParamByName("codigo")->AsString = codigo_z;
    qry_articulosglo->ParamByName("alm")->AsString = alm_z;
    qry_articulosglo->ParamByName("fecorte")->AsDateTime = fecorte_z;
    qry_articulosglo->ParamByName("modent1")->AsString = status1_z;
    qry_articulosglo->ParamByName("modent2")->AsString = status2_z;
    qry_articulosglo->ParamByName("cia")->AsInteger = cia_z;
    qry_articulosglo->Open();
    costou_z   = qry_articulosglo->FieldByName("costo")->AsFloat;
    fechamov_z = qry_articulosglo->FieldByName("fecmov")->AsDateTime;
    serie_z = "";
    if(rbtn_concosto->Checked) {
      costolin_z += costou_z;
      fprintf(archout, "%s|", rjust (FormatFloat("###,##0.00", costou_z), 12) );
    }

    fprintf(archout, "%s|", ljust (serie_z, 20) );
    fprintf(archout, "%s|", FormatDateTime("dd/mm/yyyy", fechamov_z) );
    if( chk_impriserie->Checked ) {
      fprintf(archout, "_______|___________|___________|");
    }
    fprintf(archout, "\n");
    lineas_z += 1;
  } else {
    qry_series->Close();
    qry_series->ParamByName("codigo")->AsString = codigo_z;
    qry_series->ParamByName("alm")->AsString = alm_z;
    qry_series->ParamByName("fecorte")->AsDateTime = fecorte_z;
    qry_series->ParamByName("modent1")->AsString = status1_z;
    qry_series->ParamByName("modent2")->AsString = status1_z;
    qry_series->ParamByName("cia")->AsInteger = cia_z;
    qry_series->Open();
    for( qry_series->First(); !qry_series->Eof; qry_series->Next()) {
      costou_z   = qry_series->FieldByName("costo")->AsFloat;
      fechamov_z = qry_series->FieldByName("fecmov")->AsDateTime;
      serie_z    = qry_series->FieldByName("serie")->AsString;
      checa_saltopag(2);
      fprintf(archout, "%s|", ljust(descri_z, 30));
      fprintf(archout, "%s|", rjust(FormatFloat("0", 1), 4));
      if(rbtn_concosto->Checked) {
        costolin_z += costou_z;
        fprintf(archout, "%s|", rjust (FormatFloat("###,##0.00", costou_z), 12) );
      }
      fprintf(archout, "%s|", ljust (serie_z, 20) );
      fprintf(archout, "%s|", FormatDateTime("dd/mm/yyyy", fechamov_z) );
      fprintf(archout, "___________|");
      fprintf(archout, "\n");
      lineas_z += 1;
    }
  }

}

void __fastcall TForm_exiserie::report_encab()
{

  almini_z = edt_almini->Text;
  fprintf(archout, "\n");
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );

  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_exiserie " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );

  fprintf(archout, "%s\n", cjust( " Existencia Del Almacen "  + almini_z +
    " AL " + FormatDateTime("dd/mm/yyyy", date_ini->Date)
  ,70));
  lineas_z = 8;
  if ( chk_impriserie->Checked) {
    fprintf(archout, "%s\n", cjust( " Existencias con Series Detalladas" ,70));
    lineas_z++;
  }
  encab_linea("", "");
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::encab_linea( String antzona_z, String antnomzon_z )
{
  String nombrelin_z = "";
  qry_lineas->Close();
  qry_lineas->ParamByName("linea")->AsString = antlinea_z;
  qry_lineas->ParamByName("cia")->AsInteger = cia_z,
  qry_lineas->Open();
  if ( !qry_lineas->IsEmpty()) {
    nombrelin_z = qry_lineas->FieldByName("descri")->AsString;
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust("Linea:" + antlinea_z + " " + nombrelin_z , 50));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  //fprintf(archout, "%s|", ljust("Codigo", 13));
  fprintf(archout, "%s|", ljust("Descripcion", 30));
  fprintf(archout, "%s|", ljust("Exis", 4));
  if(rbtn_concosto->Checked) {
    fprintf(archout, "%s|", rjust("Costo", 12));
  }
  if( chk_impriserie->Checked ) {
    fprintf(archout, "%s|", ljust("Exist.", 7));
    fprintf(archout, "%s|", ljust("Merc.Recib", 11));
    fprintf(archout, "%s|", ljust("Merc.Envda", 11));
  } else {
    fprintf(archout, "%s|", ljust("Serie", 20));
    fprintf(archout, "%s|", ljust("Fecha_Ent", 10));
    fprintf(archout, "%s|", ljust("Observaciones", 12));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::total_linea()
{
  if(rbtn_concosto->Checked) {
    costotot_z += costolin_z;
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
    fprintf(archout, "%s|", cjust("Costo de Esta Linea:", 35));
    fprintf(archout, "%s|", rjust (FormatFloat("###,##0.00", costolin_z), 12) );
    fprintf(archout, "\n");
    costolin_z = 0;
    lineas_z += 1;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::total_general()
{
  if(rbtn_concosto->Checked) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
    fprintf(archout, "%s|", cjust("Costo General :", 35));
    fprintf(archout, "%s|", rjust (FormatFloat("###,##0.00", costotot_z), 12) );
    fprintf(archout, "\n");
    costotot_z = 0;
    lineas_z += 1;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::encab2()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::encab3_tabla3()
{

}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::encab_tabla3()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::encab_alm(String zona_z)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::encab_alm_tabla2()
{

}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::tabla_almacen()
{
}
//---------------------------------------------------------------------------

bool __fastcall TForm_exiserie::checa_saltopag(int numero_de_lineas)
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

void __fastcall TForm_exiserie::total_zona()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::total_genzona()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::tabla_lineas()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::tabla_lineas_final()
{
}

//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::Subtotales_porc(String tlinea_z)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::total_linea_tabla()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::tabla_linea_global()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::desglose_total_gen()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::total_global_tabla()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiserie::FormCreate(TObject *Sender)
{
  date_ini->Date = dm->ahora();
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::imprimir_reporteExecute(TObject *Sender)
{


  if(Application->MessageBox("Seguro imprimir Reporte ?", "Impresión Reporte", MB_OKCANCEL) != IDOK ) return;
  arch_z = "frm_exiserie.txt";
  if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
  }
  genera_reporte();
  fclose(archout);
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::date_iniExit(TObject *Sender)
{
   calcula_vigencia();
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::calcula_vigencia()
{

  int dias_z = 5;
  dias_z = DayOfWeek(date_ini->Date);
  if (dias_z < 7) dias_z = 7 - dias_z;
  date_vigencia->Date = date_ini->Date + dias_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiserie::edt_alminiExit(TObject *Sender)
{
  if(edt_almini->Text.Trim() == "AL") {
    chk_impriserie->Checked = true;
  } else {
    chk_impriserie->Checked = false;
  }
}
//---------------------------------------------------------------------------

