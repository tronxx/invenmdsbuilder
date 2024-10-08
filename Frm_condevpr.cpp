//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_condevpr.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
#include "imprigra.h"
#include "numapal.h"
#include "dmod.h"
#include "situaciones.h"
TForm_condevpr *Form_condevpr;
const int MAX_LINEAS = 57;
//--------------------------------------------------------------------------
__fastcall TForm_condevpr::TForm_condevpr(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::report_encab()
{
  String situini_z,situfin_z,tit1_z,tit2_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_condevpr" + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );

   tit2_z = "Concentrado de Devoluciones-Proveedor x Linea del: ";
   fprintf(archout, "%s", rjust( tit2_z,50));
   fprintf(archout, "%s", ljust( FormatDateTime("dd/mm/yyyy",
   date_ini->Date) + " AL "  + FormatDateTime("dd/mm/yyyy",
   date_fin->Date),50));
   fprintf(archout,"\n");
   lineas_z = 4;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::encab1()
{

   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Codigo",13 ));
   fprintf(archout, "%s|", cjust("Descripcion",30));
   fprintf(archout, "%s|", cjust("Serie",20 ));
   fprintf(archout, "%s|", cjust("Folio",5));
   fprintf(archout, "%s|", cjust("Costo Unitar",12));
   fprintf(archout, "%s|", cjust("SN",2));
   fprintf(archout, "%s|", cjust("MC",2));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::encab2()
{

   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Codigo",13 ));
   fprintf(archout, "%s|", cjust("Descripcion",30));
   fprintf(archout, "%s|", cjust("Cant.",5 ));
   fprintf(archout, "%s|", cjust("Costo Unitar",12));
   fprintf(archout, "%s|", cjust("Importe",12));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::encab3()
{
   fprintf(archout, "%s\n", cjust("Acumulado con Costo Financiero", 76 ));
   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Alm.",4 ));
   fprintf(archout, "%s|", cjust("Numero",6));
   fprintf(archout, "%s|", cjust("Prove",4));
   fprintf(archout, "%s|", cjust("Importe",12 ));
   fprintf(archout, "%s|", cjust("Iva",12));
   fprintf(archout, "%s|", cjust("Total",12));
   fprintf(archout, "%s|", cjust("Costo.Finan.",12));
   fprintf(archout, "%s|", cjust("Gran Total",12));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::imprimi_lineas()
{
  String lineainv_z,desinv_z, codinv_z, descriinv_z;
  double cantmuve_z , costouinv_z,importinv_z,totinv_z;
  int line_z;
  line_z = 0;

  qry_lineas->Close();
  qry_lineas->ParamByName("TPDEV")->AsString =  tpdev_z ;
  qry_lineas->ParamByName("FECINI")->AsDateTime = fecini_z;
  qry_lineas->ParamByName("FECFIN")->AsDateTime = fecfin_z;
  qry_lineas->ParamByName("PINI")->AsString = provini_z;
  qry_lineas->ParamByName("PFIN")->AsString = provfin_z;
  qry_lineas->ParamByName("CIA")->AsInteger = cia_z;
  qry_lineas->Open();

  for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
     lineainv_z = qry_lineas->FieldByName("linea")->AsString;
     desinv_z = qry_lineas->FieldByName("des")->AsString;
     codinv_z = qry_lineas->FieldByName("codigo")->AsString;
     descriinv_z = qry_lineas->FieldByName("descri")->AsString;

     if(line_z == 0){
         linea(lineainv_z,desinv_z );
         encab2();
         antlineainv_z = lineainv_z;
         line_z = 1;
     }

     if(antlineainv_z != lineainv_z ){
         tot_salidas_linea();
         checa_salto_pag(6);
         linea(lineainv_z,desinv_z );
         encab2();
         antlineainv_z = lineainv_z;

     }
     checa_salto_pag(3);
     qry_cantline->Close();
     qry_cantline->ParamByName("TPDEV")->AsString =  tpdev_z ;
     qry_cantline->ParamByName("FECINI")->AsDateTime = fecini_z;
     qry_cantline->ParamByName("FECFIN")->AsDateTime = fecfin_z;
     qry_cantline->ParamByName("PINI")->AsString = provini_z;
     qry_cantline->ParamByName("PFIN")->AsString = provfin_z;
     qry_cantline->ParamByName("CODINV")->AsString = codinv_z;
     qry_cantline->ParamByName("CIA")->AsInteger = cia_z;
     qry_cantline->Open();

     cantmuve_z =  qry_cantline->FieldByName("unid")->AsFloat;
     costouinv_z =  qry_cantline->FieldByName("import")->AsFloat;
     totinv_z =   qry_cantline->FieldByName("tot")->AsFloat;

      importinv_z = cantmuve_z * costouinv_z;
      fprintf(archout, "|");
      fprintf(archout, "%s|", ljust(codinv_z, 13));
      fprintf(archout, "%s|", ljust(descriinv_z, 30));
      fprintf(archout, "%s|", rjust(FormatFloat("0",cantmuve_z), 5));
      fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",costouinv_z),12));
      fprintf(archout, "%s|\n", rjust(FormatFloat("###,##0.00",importinv_z),12));
      lineas_z += 1;
      totcostouinv_z += costouinv_z;
      totivainv_z += totinv_z;

  }
   tot_salidas_linea();
   tot_gensalidas_linea();
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::imprimi_financ()
{
  String almfinan_z,provfinan_z;
  double imporfinan_z,ctofin_z,ivafinan_z,totalfin_z,gtotfin_z;
  int numfinan_z;
  qry_financ->Close();
  qry_financ->ParamByName("TPDEV")->AsString =  tpdev_z ;
  qry_financ->ParamByName("FECINI")->AsDateTime = fecini_z;
  qry_financ->ParamByName("FECFIN")->AsDateTime = fecfin_z;
  qry_financ->ParamByName("PINI")->AsString = provini_z;
  qry_financ->ParamByName("PFIN")->AsString = provfin_z;
  qry_financ->ParamByName("CIA")->AsInteger = cia_z;
  qry_financ->Open();
  encab3();
  for(qry_financ->First(); !qry_financ->Eof; qry_financ->Next()) {
     almfinan_z = qry_financ->FieldByName("alm")->AsString;
     numfinan_z = qry_financ->FieldByName("numero")->AsInteger;
     provfinan_z = qry_financ->FieldByName("prove")->AsString;
     imporfinan_z = qry_financ->FieldByName("importe")->AsFloat;
     ivafinan_z = qry_financ->FieldByName("iva")->AsFloat;
     ctofin_z = qry_financ->FieldByName("ctofin")->AsFloat;

     totalfin_z = imporfinan_z + ivafinan_z;
     gtotfin_z = totalfin_z  + ctofin_z;

     checa_salto_pag(3);
     fprintf(archout, "|");
     fprintf(archout, "%s|", ljust(almfinan_z, 4));
     fprintf(archout, "%s|", ljust(numfinan_z, 6));
     fprintf(archout, "%s|", ljust(provfinan_z, 4));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",imporfinan_z),12));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",ivafinan_z),12));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totalfin_z ),12));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",ctofin_z),12));
     fprintf(archout, "%s|\n", rjust(FormatFloat("###,##0.00",gtotfin_z),12));
     lineas_z += 1;

     totimporfinan_z += imporfinan_z;
     totivafinan_z += ivafinan_z;
     tottotalfin_z += totalfin_z;
     totctofin_z += ctofin_z;
     totgtotfin_z += gtotfin_z;
  }
  tot_financieros();

}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::FormCreate(TObject *Sender)
{
  date_ini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fin->Date = UltimoDiaMes(date_ini->Date);
  cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::almacen(String alm_z, String nombre_z)
{
  fprintf(archout, "%s", ljust("Almacen:", 7));
  fprintf(archout, "%s\n", ljust( alm_z + " " + nombre_z, 30));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::linea(String lineainv_z, String desinv_z)
{
  fprintf(archout, "%s", ljust("Linea:",6 ));
  fprintf(archout, "%s\n", ljust( lineainv_z + " " + desinv_z, 30));
  lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::sub_alamcen( int numero_z, TDateTime fecha_z,
                 String prover_z, String nomprove_z)
{
  fprintf(archout, "%s", cjust("Numero:", 7));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",numero_z),2));
  fprintf(archout, "%s ", cjust("Fecha:",6));
  fprintf(archout, "%s ", rjust( FormatDateTime("dd/mm/yyyy",fecha_z),10));
  fprintf(archout, "%s ", cjust("Proveedor:",10));
  fprintf(archout, "%s ", rjust(prover_z,5));
  fprintf(archout, " %s ", ljust(nomprove_z,30));
  fprintf(archout, "\n");
  lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::tot_salidas()
{
  double summ_z;
  summ_z = totcostou + totiva_z;
  fprintf(archout, "%s", rjust("Salidas:", 47));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",totcostou),12));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",totiva_z),12));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",summ_z),12));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
  gtotcostou_z += totcostou;
  gtotsumm_z += summ_z;
  summ_z = totcostou = totiva_z = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::tot_salidas_linea()
{
  double summ_z;
  summ_z =  totcostouinv_z + totivainv_z;
  fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s", rjust("Salidas de Esta Linea:", 28));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",totcostouinv_z),12));
  fprintf(archout, "%s", rjust("IVA:",4));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",totivainv_z),12));
  fprintf(archout, "%s", rjust("Total:",6));
  fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",summ_z),12));
  fprintf(archout, "%s|\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
  gtotcostouinv_z += totcostouinv_z;
  gtotivainv_z += totivainv_z;
  gtotsumminv_z += summ_z;
  summ_z =  totcostouinv_z = totivainv_z = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::tot_gensalidas_linea()
{
  double summ_z;
  summ_z =  gtotcostouinv_z + gtotivainv_z;
  fprintf(archout, "%s", rjust("Salidas Totales:", 29));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",gtotcostouinv_z),12));
  fprintf(archout, "%s", rjust("IVA:",4));
  fprintf(archout, "%s ", rjust(FormatFloat("###,##0.00",gtotivainv_z),12));
  fprintf(archout, "%s", rjust("Total:",6));
  fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",gtotsumminv_z),12));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
  gtotcostouinv_z =  gtotivainv_z = gtotsumminv_z = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::tot_general()
{
  double summ_z;
  summ_z = totcostou + totiva_z;
  fprintf(archout, "%s", rjust("Total de las Devoluciones de este Almacen:",73));
  fprintf(archout, "%s\n", rjust(FormatFloat("###,##0.00",gtotsumm_z),12));
  fprintf(archout, "%s", rjust("Total General de las Devoluciones:", 73));
  fprintf(archout, "%s\n ", rjust(FormatFloat("###,##0.00",gtotsumm_z),12));
  lineas_z += 2;
  gtotcostou_z = gtotsumm_z= 0;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  checa_salto_pag(500); // forzar salto de paginaaa
}
//---------------------------------------------------------------------------
void __fastcall TForm_condevpr::tot_financieros()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|");
  fprintf(archout, "%s|", rjust("Total:", 11));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totimporfinan_z),17));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totivafinan_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",tottotalfin_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totctofin_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totgtotfin_z),12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 1;
  totimporfinan_z = totivafinan_z = tottotalfin_z = totctofin_z = totgtotfin_z = 0;
}
//---------------------------------------------------------------------------
bool __fastcall TForm_condevpr::checa_salto_pag(int margen_z)
{
  bool haysalto_z = false;
  if(lineas_z > (MAX_LINEAS - margen_z)) {
    fprintf(archout, "%c", 12);
    pagina_z++;
    report_encab();
    haysalto_z = true;
  }
  return (haysalto_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_condevpr::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_condevpr::imprimir_reporteExecute(TObject *Sender)
{
   String alm_z,nombalm_z,prove_z,nomprove_z,codinv_z,descri_z,serie_z,
   siono_z ,entcan_z,arch_z;
   TDateTime fecha_z;
   int numero_z,folsal_z,anio_z,dia_z,mes_z,line_z;
   double costou_z,tot_z;
   line_z= 0;

   if (rbtn_ralmsi->Checked == false && rbtn_ralmno->Checked == false){
       Application->MessageBox("Seleccione SI � No Quiere Reporte de Almacen y Linea\n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_rcostosi->Checked == false && rbtn_rcostono->Checked == false) {
       Application->MessageBox("Seleccione SI � No Quiere Reporte Con Costos Financieros\n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }

   arch_z = "frm_condevpr.txt";
   if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
   }

   report_encab();
   tpdev_z = "R";
   fecini_z  = date_ini->Date;
   fecfin_z  = date_fin->Date;
   provini_z = edt_pini->Text;
   provfin_z = edt_pfin->Text;

   if (rbtn_ralmsi->Checked){
     qry_almacen->Close();
     qry_almacen->ParamByName("TPDEV")->AsString =  tpdev_z ;
     qry_almacen->ParamByName("FECINI")->AsDateTime = fecini_z;
     qry_almacen->ParamByName("FECFIN")->AsDateTime = fecfin_z;
     qry_almacen->ParamByName("PINI")->AsString = provini_z;
     qry_almacen->ParamByName("PFIN")->AsString = provfin_z;
     qry_almacen->ParamByName("CIA")->AsInteger = cia_z;
     qry_almacen->Open();

     for(qry_almacen->First(); !qry_almacen->Eof; qry_almacen->Next()) {
        alm_z = qry_almacen->FieldByName("alm")->AsString;
        nombalm_z = qry_almacen->FieldByName("nombre")->AsString;
        fecha_z = qry_almacen->FieldByName("fecha")->AsDateTime;
        numero_z = qry_almacen->FieldByName("numero")->AsInteger;
        prove_z = qry_almacen->FieldByName("prove")->AsString;
        nomprove_z = qry_almacen->FieldByName("nomprove")->AsString;

         if(line_z == 0){
           almacen(alm_z,nombalm_z );
           sub_alamcen(numero_z,fecha_z,prove_z,nomprove_z);
           encab1();
           antnumero_z = numero_z;
           line_z = 1;
         }

         if(antnumero_z != numero_z ){
           sub_alamcen(numero_z,fecha_z,prove_z,nomprove_z);
           encab1();
           antnumero_z = numero_z;

         }

         qry_datos->Close();
         qry_datos->ParamByName("TPDEV")->AsString =  tpdev_z ;
         qry_datos->ParamByName("NUM")->AsInteger = numero_z;
         qry_datos->Open();



         for(qry_datos->First(); !qry_datos->Eof; qry_datos->Next()) {
            codinv_z = qry_datos->FieldByName("codinv")->AsString;
            descri_z = qry_datos->FieldByName("descri")->AsString;
            serie_z =  qry_datos->FieldByName("serie")->AsString;
            folsal_z = qry_datos->FieldByName("folsal")->AsInteger;
            costou_z = qry_datos->FieldByName("costou")->AsFloat;
            siono_z =  qry_datos->FieldByName("siono")->AsString;
            entcan_z = qry_datos->FieldByName("entcan")->AsString;
            tot_z =  qry_datos->FieldByName("tot")->AsFloat;


            fprintf(archout, "|");
            fprintf(archout, "%s|", ljust(codinv_z, 13));
            fprintf(archout, "%s|", ljust(descri_z, 30));
            fprintf(archout, "%s|", ljust(serie_z, 20));
            fprintf(archout, "%s|", rjust(FormatFloat("0",folsal_z), 5));
            fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",costou_z),12));
            fprintf(archout, "%s|", ljust(siono_z, 2));
            fprintf(archout, "%s|\n", ljust(entcan_z, 2));

            lineas_z += 1;
            checa_salto_pag(3);

            totcostou += costou_z;
            totiva_z += tot_z;

         }
          tot_salidas();

     }
     tot_general();
     imprimi_lineas();
   }
   if(rbtn_rcostosi->Checked) {
     imprimi_financ();
   }
   fclose(archout);
   dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------

