//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_analient.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"
#include "imprigra.h"
#include "numapal.h"
#include "dmod.h"
#include "situaciones.h"
TForm_analient *Form_analient;
const int MAX_LINEAS = 57;
//---------------------------------------------------------------------------
__fastcall TForm_analient::TForm_analient(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_analient::define_tiporeporte(String tiporep_z)
{
  String sql_z;
  mitiporep_z = tiporep_z;
  if(mitiporep_z == "ANALITICO_ENTRADAS") {
    sql_z = " select a.prove,d.nombre,b.codinv,c.descri,c.coston, ";
    sql_z += " a.fecha,a.numero, count(*) ";
    sql_z += " from entradas a ";
    sql_z += " join renentra b on a.tipo = b.tipo and a.alm = b.alm  ";
    sql_z += " and a.numero =b.numero and a.cia = b.cia ";
    sql_z += " join inven c on b.codinv = c.codigo and b.cia = c.cia ";
    sql_z += " join proveedor d on a.prove = d.codigo and a.cia = d.cia ";
    sql_z += " where a.fecha between :FECINI and :FECFIN ";
    sql_z += " and a.tipo= :TPENT and a.cia= :CIA ";
    sql_z += " group by a.prove,b.codinv,a.numero, c.descri, c.coston";
  }
  if(tiporep_z == "ANALITICO_PARA_MAYOREO") {
    Caption = "Reporte de Compra para Mayoreo";
    sql_z = " select b.codinv,c.descri,c.fecalta, ";
    sql_z += " ( c.salvtas + c.salvtan + salfons + salfonn) as univta, ";
    sql_z += " count(*) as unidades, sum(b.importe) ";
    sql_z += " from entradas a ";
    sql_z += " join renentra b on a.tipo = b.tipo and a.alm = b.alm ";
    sql_z += " and a.numero = b.numero and a.cia = b.cia ";
    sql_z += " join inven c on b.codinv = c.codigo and b.cia = c.cia ";
    sql_z += " where a.fecha between :FECINI and :FECFIN ";
    sql_z += " and a.tipo= :TPENT and a.cia= :CIA ";
    sql_z += " group by b.codinv,c.descri, c.fecalta, c.coston, univta";
    dbgrd_renglonesNUMERO->Visible = false;
    dbgrd_renglonesFECHA->Visible = false;
    dbgrd_renglonesCOSTON->Visible = false;
  }
  qry_datos->SQL->Text = sql_z;


}
//---------------------------------------------------------------------------

void __fastcall TForm_analient::report_encab()
{
  String situini_z,situfin_z,tit1_z,tit2_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_analient" + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );
  if(mitiporep_z == "ANALITICO_ENTRADAS") {
    tit2_z = "Reporte Concentrado de Entradas x Proveedor del ";
  }
  if(mitiporep_z == "ANALITICO_PARA_MAYOREO") {
    tit2_z = "Mercancia Recibida del ";
  }
  tit2_z += FormatDateTime("dd/mm/yyyy",  date_ini->Date);
  tit2_z += " Al " + FormatDateTime("dd/mm/yyyy",  date_fin->Date);
  fprintf(archout, "%s", cjust( tit2_z,80));
  fprintf(archout, "\n");
  if(mitiporep_z == "ANALITICO_ENTRADAS") {
    tit2_z = "Comprende de la Entrada ";
    fprintf(archout, "%s", cjust( tit2_z + min_z + " A la Entrada " + max_z ,75));
    fprintf(archout,"\n");
  }
  lineas_z = 4;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analient::encab()
{
  fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("============Articulo==========",30 ));
  if(mitiporep_z == "ANALITICO_ENTRADAS") {
     fprintf(archout, "%s|", cjust("Ent.#.",6));
     fprintf(archout, "%s|", cjust("==Fecha===",10 ));
     fprintf(archout, "%s|", cjust("Unid",4));
     fprintf(archout, "%s|", cjust("Cost_U_C/IVA",12));
     fprintf(archout, "%s|", cjust("===Importe==",12));
  }
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_analient::encab_punto(String prove_z, String nombre_z)
{
  fprintf(archout, "%s", ljust("Proveedor:", 10));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust( prove_z + " " + nombre_z, 45));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_analient::FormCreate(TObject *Sender)
{
   tpent_z = "E";
   cia_z = dm->cia_z;
   date_ini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
   date_fin->Date = UltimoDiaMes(date_ini->Date);
}
//---------------------------------------------------------------------------
void __fastcall TForm_analient::maxymin()
{

  fecini_z = date_ini->Date;
  fecfin_z = date_fin->Date;

  //Entrada MIN
  qry_min->Close();
  qry_min->ParamByName("FECINI")->AsDateTime = fecini_z ;
  qry_min->ParamByName("FECFIN")->AsDateTime = fecfin_z;
  qry_min->ParamByName("TPENT")->AsString = tpent_z;
  qry_min->ParamByName("CIA")->AsInteger = cia_z;
  qry_min->Open();
  min_z = qry_min->FieldByName("min")->AsInteger;

  //Entrada MAX
  qry_max->Close();
  qry_max->ParamByName("FECINI")->AsDateTime = fecini_z ;
  qry_max->ParamByName("FECFIN")->AsDateTime = fecfin_z;
  qry_max->ParamByName("TPENT")->AsString = tpent_z;
  qry_max->ParamByName("CIA")->AsInteger = cia_z;
  qry_max->Open();
  max_z = qry_max->FieldByName("max")->AsInteger;

}
//---------------------------------------------------------------------------
void __fastcall TForm_analient::imprimir_datos()
{

  String codinv_z,descrip_z;
  int numero_z, univta_z, unidad_z, minmay_z, linea_z, maximo_z, inianu_z;
  TDateTime fecha_z, hoy_z;
  double coston_z,import_z;
  linea_z = 0;
  pagina_z = 1;

  qry_datos->Close();
  qry_datos->ParamByName("FECINI")->AsDateTime = fecini_z ;
  qry_datos->ParamByName("FECFIN")->AsDateTime = fecfin_z;
  qry_datos->ParamByName("TPENT")->AsString = tpent_z;
  qry_datos->ParamByName("CIA")->AsInteger = cia_z;
  qry_datos->Open();
  hoy_z    = dm->ahora();
  inianu_z = dm->inianuestadis();

  for ( qry_datos->First(); !qry_datos->Eof; qry_datos->Next()) {
    if(mitiporep_z == "ANALITICO_ENTRADAS") {
       proveedor_z  = qry_datos->FieldByName("prove")->AsString;
       nombreprov_z = qry_datos->FieldByName("nombre")->AsString;
       numero_z  = qry_datos->FieldByName("numero")->AsInteger;
       fecha_z   = qry_datos->FieldByName("fecha")->AsDateTime;
       coston_z  = qry_datos->FieldByName("coston")->AsFloat;
     }
     codinv_z  = qry_datos->FieldByName("codinv")->AsString;
     descrip_z = qry_datos->FieldByName("descri")->AsString;

     if(linea_z == 0){
        antprover_z = proveedor_z;
        antnomb_z = nombreprov_z;
        report_encab();
        if(mitiporep_z == "ANALITICO_ENTRADAS") {
          encab_punto(proveedor_z,nombreprov_z);
        }
        encab();
        linea_z = 1;
    }
    if(mitiporep_z == "ANALITICO_ENTRADAS") {
      if(antprover_z != proveedor_z){
        total_punto();
        encab_punto(proveedor_z,nombreprov_z);
        encab();
        antprover_z = proveedor_z;
        antnomb_z = nombreprov_z;
      }
    }

    //Buscamos las Unidades y el Importe Total del Articulo
    if(mitiporep_z == "ANALITICO_ENTRADAS") {
      qry_unid->Close();
      qry_unid->ParamByName("TPENT")->AsString = tpent_z ;
      qry_unid->ParamByName("NUM")->AsInteger = numero_z;
      qry_unid->ParamByName("CODINV")->AsString = codinv_z ;
      qry_unid->ParamByName("CIA")->AsInteger = cia_z;
      qry_unid->Open();
      unidad_z  = qry_unid->FieldByName("unidad")->AsInteger;
      import_z  = qry_unid->FieldByName("import")->AsFloat;
    }
    univta_z = qry_datos->FieldByName("univta")->AsFloat;
    minmay_z = 0;
    if(mitiporep_z == "ANALITICO_PARA_MAYOREO") {
       unidad_z  = qry_datos->FieldByName("unidades")->AsInteger;
    }
    if(mitiporep_z == "ANALITICO_ENTRADAS" || unidad_z > 2) {
      fprintf(archout, "|");
      fprintf(archout, "%s|", ljust( descrip_z, 30));
      if(mitiporep_z == "ANALITICO_ENTRADAS") {
        fprintf(archout, "%s|", rjust(FormatFloat("0",numero_z ),6 ));
        fprintf(archout, "%s|", rjust(FormatDateTime("dd/mm/yyyy",fecha_z),10 ));
        fprintf(archout, "%s|", rjust(FormatFloat("0",unidad_z), 4));
        fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", coston_z), 12));
        fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", import_z), 12));
      }
      fprintf(archout, "\n");
      checa_salto_pag(3);
      lineas_z += 1;
      totprov_z += import_z;
    }
  }

}
//---------------------------------------------------------------------------


bool __fastcall TForm_analient::checa_salto_pag(int margen_z)
{
  bool haysalto_z = false;
  if(lineas_z > (MAX_LINEAS - margen_z)) {
    fprintf(archout, "%c", 12);
    pagina_z++;
    report_encab();
    encab_punto(proveedor_z,nombreprov_z);
    encab();
    haysalto_z = true;
  }
  return (haysalto_z);
}
//---------------------------------------------------------------------------
void __fastcall TForm_analient::total_punto()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total de Este Proveedor:",67));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",  totprov_z),12 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout,"\n");
  lineas_z += 1;
  gtotprov_z += totprov_z;
  totprov_z = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm_analient::total_todosprover()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total de Todos los Proveedores:",66));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",  gtotprov_z),12 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z += 1;
  gtotprov_z = 0;
}
//---------------------------------------------------------------------------



void __fastcall TForm_analient::BitBtn1Click(TObject *Sender)
{
  fecini_z = date_ini->Date;
  fecfin_z = date_fin->Date;
  qry_datos->Close();
  qry_datos->ParamByName("FECINI")->AsDateTime = fecini_z ;
  qry_datos->ParamByName("FECFIN")->AsDateTime = fecfin_z;
  qry_datos->ParamByName("TPENT")->AsString = tpent_z;
  qry_datos->ParamByName("CIA")->AsInteger = cia_z;
  qry_datos->Open();
  dbgrd_renglones->FullExpand();
  imprir_reporteExecute(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm_analient::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analient::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_renglones;
  tipogrd_z="DBG";
//  switch (page_detalles->ActivePageIndex) {
//    case TBS_KARDEX  : midbgrd_z = dbgrd_kardex;   tipogrd_z="DBG"; break;
//    case TBS_ESTADIS : midbgrd_z = dbgrd_estadis;  tipogrd_z="DBG"; break;
//    case TBS_OBSERVS : midbgrd_z = dbgrd_observs;  tipogrd_z="DBG"; break;
//    case TBS_DISPONI : midbgrd_z = dbgrd_dispo;    tipogrd_z="DBG"; break;
//    case TBS_BUSSERIE: midbgrd_z = dbgrd_busserie; tipogrd_z="DBG"; break;
//    case TBS_EXIST   : midbgrd_z = dbgrd_exist;    tipogrd_z="DBG"; break;
//  }
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = midbgrd_z->Name + ".xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    if(tipogrd_z == "DBG") {
      switch( SaveDialog->FilterIndex) {
        case 1: midbgrd_z->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
        case 2: midbgrd_z->SaveToXLS(SaveDialog->FileName, true); break;
        case 3: midbgrd_z->SaveToHTML(SaveDialog->FileName, true); break;
      }
    }
//    else if (tipogrd_z == "ADV") {
//      switch( SaveDialog->FilterIndex) {
//        case 1: misgrd_z->SaveToCSV(SaveDialog->FileName); break;
//        case 2: misgrd_z->SaveToXLS(SaveDialog->FileName); break;
//        case 3: misgrd_z->SaveToHTML(SaveDialog->FileName); break;
//      }
//    }
  }
  delete SaveDialog;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analient::imprir_reporteExecute(TObject *Sender)
{
   String arch_z;
   arch_z = "frm_analient.txt";
   if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
   }
   maxymin();
   imprimir_datos();
   if(mitiporep_z == "ANALITICO_ENTRADAS") {
     total_punto();
     total_todosprover();
   }
   fclose(archout);
   dbgrd_renglones->FullExpand();
   dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------


