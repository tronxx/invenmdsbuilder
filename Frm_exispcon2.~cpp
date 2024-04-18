//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_exispcon2.h"
#include "numapal.h"
#include "situaciones.h"
#include "dmod.h"
#include "imprigra.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const int LINEAS_X_PAG = 60;
TForm_exispcon2 *Form_exispcon2;
//---------------------------------------------------------------------------
__fastcall TForm_exispcon2::TForm_exispcon2(TComponent* Owner)
        : TForm(Owner)
{
   date_ini->Date = dm->ahora();
   calcula_vigencia();
   cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::genera_reporte()
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
    maximo_z = calcula_maximo();
    minexi_z = maximo_z / 2 + 1;
    if( qry_exisi->FieldByName("unidexis")->AsInteger > minexi_z) {
      imprime_renglon();
    }
  }
  total_linea(); 
}
//---------------------------------------------------------------------------

int  __fastcall TForm_exispcon2::calcula_maximo()
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

void __fastcall TForm_exispcon2::imprime_renglon()
{
  String codigo_z;
  double preciomay_z = 0;
  int exist_z;
  if(antlinea_z == "-1") {
    linea_z = qry_exisi->FieldByName("linea")->AsString;
    antlinea_z = linea_z;
    report_encab();
  }
  if( linea_z != antlinea_z) {
    total_linea(); antlinea_z = linea_z;
    if( !checa_saltopag(4)) {
       encab_linea("", "");
    }

  }
  exist_z  = qry_exisi->FieldByName("unidexis")->AsInteger;
  codigo_z = qry_exisi->FieldByName("codigo")->AsString;

  //fprintf(archout, "%s|", ljust(codigo_z, 13));
  fprintf(archout, "%s|", ljust(qry_exisi->FieldByName("descri")->AsString, 30));
  fprintf(archout, "%s|", rjust(FormatFloat("0", exist_z), 4));
  fprintf(archout, "___________|");
  fprintf(archout, "___________|");
  if (rbtn_sipreciomay->Checked) {
    if(rbtn_mayoristas->Checked) {
      preciomay_z = dm->calcu_prmay(codigo_z, TIPO_MAYORISTA);
    } else {
      preciomay_z = dm->calcu_prmay(codigo_z, TIPO_FILIAL);
    }
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", preciomay_z), 12));
  }
  fprintf(archout, "\n");
  lineas_z += 1;

}

void __fastcall TForm_exispcon2::report_encab()
{

  almini_z = edt_almini->Text;
  String tit_z;
  fprintf(archout, "\n");
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );

  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_exispcon2 " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );

  fprintf(archout, "%s\n", cjust( " Existencia Del Almacen "  + almini_z +
    " AL " + FormatDateTime("dd/mm/yyyy", date_ini->Date) +
    " Precios Vigentes al " + FormatDateTime("dd/mm/yyyy", date_vigencia->Date)
  ,70));
  fprintf(archout, "\n");
  tit_z = "Reporte para ";
  if(rbtn_mayoristas->Checked) {
    tit_z += " Mayoristas";
  } else {
    tit_z += " Filiales";
  }
  lineas_z = 10;
  encab_linea("", "");

}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::encab_linea( String antzona_z, String antnomzon_z )
{
  String tit_z = "", nombrelin_z = "";
  if(rbtn_mayoristas->Checked) {
    tit_z = "Pre.Mayoreo";
  } else {
    tit_z = "Pre.Filiales";
  }

  qry_lineas->Close();
  qry_lineas->ParamByName("linea")->AsString = antlinea_z;
  qry_lineas->ParamByName("cia")->AsInteger = cia_z,
  qry_lineas->Open();
  if ( !qry_lineas->IsEmpty()) {
    nombrelin_z = qry_lineas->FieldByName("descri")->AsString;
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust("Linea:" + antlinea_z + " " + nombrelin_z , 50));
  fprintf(archout, "%s\n\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  //fprintf(archout, "%s|", ljust("Codigo", 13));
  fprintf(archout, "%s|", ljust("Descripcion", 30));
  fprintf(archout, "%s|", ljust("Exis", 4));
  fprintf(archout, "%s|", ljust("Mcia.Recibid", 12));
  fprintf(archout, "%s|", ljust("Mcia.Enviada", 12));
  fprintf(archout, "%s|", ljust(tit_z, 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::total_linea()
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

void __fastcall TForm_exispcon2::encab2()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::encab3_tabla3()
{

}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::encab_tabla3()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::encab_alm(String zona_z)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::encab_alm_tabla2()
{

}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::tabla_almacen()
{
}
//---------------------------------------------------------------------------

bool __fastcall TForm_exispcon2::checa_saltopag(int numero_de_lineas)
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
void __fastcall TForm_exispcon2::total_zona()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::total_genzona()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::tabla_lineas()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::tabla_lineas_final()
{
}

//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::Subtotales_porc(String tlinea_z)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::total_linea_tabla()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::tabla_linea_global()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::desglose_total_gen()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::total_global_tabla()
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exispcon2::FormCreate(TObject *Sender)
{
  date_ini->Date = dm->ahora();
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::imprimir_reporteExecute(TObject *Sender)
{


  if(Application->MessageBox("Seguro imprimir Reporte ?", "Impresión Reporte", MB_OKCANCEL) != IDOK ) return;
  arch_z = "frm_exican.txt";
  if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
  }
  genera_reporte();
  fclose(archout);
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::date_iniExit(TObject *Sender)
{
   calcula_vigencia();
}
//---------------------------------------------------------------------------

void __fastcall TForm_exispcon2::calcula_vigencia()
{

  int dias_z = 5;
  dias_z = DayOfWeek(date_ini->Date);
  if (dias_z < 7) dias_z = 7 - dias_z;
  date_vigencia->Date = date_ini->Date + dias_z;
}
//---------------------------------------------------------------------------

