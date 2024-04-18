//---------------------------------------------------------------------------
 
#include <vcl.h>
#pragma hdrstop

#include "Frm_infent.h"
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
TForm_infent *Form_infent;
const int MAX_LINEAS = 57;
//---------------------------------------------------------------------------
__fastcall TForm_infent::TForm_infent(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_infent::report_encab()
{
  String situini_z,situfin_z,tit1_z,tit2_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    "Frm_infent" + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );

  tit2_z = "Informe de Entradas del: ";
  fprintf(archout, "%s", rjust( tit2_z,50));
  fprintf(archout, "%s", ljust( FormatDateTime("dd/mm/yyyy",
  date_ini->Date) + " AL "  + FormatDateTime("dd/mm/yyyy",
  date_fin->Date),50));
  fprintf(archout,"\n");
  lineas_z = 4;
  if(numenc_z == 1) encab1();
  if(numenc_z == 2) encab2();
  if(numenc_z == 3) encab3();
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::encab1()
{
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s", cjust("",125 ));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Proveedor",36 ));
   fprintf(archout, "%s|", cjust("Compras SI",14));
   fprintf(archout, "%s|", cjust("Compras NO",14 ));
   fprintf(archout, "%s|", cjust("Total Mes",14));
   fprintf(archout, "%s|", cjust("POS",3));
   fprintf(archout, "%s|", cjust("Anual Compras",14));
   fprintf(archout, "%s|", cjust("POS",3));
   fprintf(archout, "%s|", cjust("Total Gral.",14));
   fprintf(archout, "%s|", cjust("POS",3));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::encab2()
{
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s", cjust("",70 ));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("LINEA",5 ));
   fprintf(archout, "%s|", cjust("Compras Mes",13));
   fprintf(archout, "%s|", cjust("%%",6 ));
   fprintf(archout, "%s|", cjust("Compras Anual",13));
   fprintf(archout, "%s|", cjust("%%",6));
   fprintf(archout, "%s|", cjust("Compras Global",13));
   fprintf(archout, "%s|", cjust("%%",6));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::encab3()
{
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s", cjust("",56 ));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Linea",5 ));
   fprintf(archout, "%s|", cjust("Compras Mes",13));
   fprintf(archout, "%s|", cjust("Devols.Mensual",13));
   fprintf(archout, "%s|", cjust("Compras Netas",13));
   fprintf(archout, "%s|", cjust("%%",6));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_infent::total_tabla1()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s", cjust("",125 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|");
  fprintf(archout, "%s|", cjust("Total General:",36));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotsi_z   ),14 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotno_z  ),14 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotm_z  ),14 ));
  fprintf(archout, "%s|", cjust("",3 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotanu_z ),14 ));
  fprintf(archout, "%s|", cjust("",3 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotgen_z  ),14 ));
  fprintf(archout, "%s|", cjust("",3 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout,"\n");
  lineas_z += 2;
  gtotsi_z = gtotno_z = gtotm_z = gtotanu_z = gtotgen_z = 0;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm_infent::total_tabla2()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s", cjust("",70 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|");
  fprintf(archout, "%s|", cjust("TOTAL",5));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotmes_z),13 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotpoc1_z),6 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtoanu_z),13 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotpoc2_z),6 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotgbal_z),13 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotpoc3_z),6 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout,"\n");
  lineas_z += 2;
  gtotmes_z = gtotpoc1_z = gtoanu_z = gtotpoc2_z = gtotgbal_z = gtotpoc3_z = 0;
  comprames_z = compranual_z = 0;

}
//---------------------------------------------------------------------------
//---------------------------------------------------------------------------
void __fastcall TForm_infent::total_tabla3()
{

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s", cjust("",56 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("TOTAL",5));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",   gtotmes_z ),13 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",  gtodev_z),13 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",  gtotgbal_z),13 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",  gtotpoc3_z),6 ));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout,"\n");
  lineas_z += 2;
  gtotmes_z = gtodev_z = gtotgbal_z = gtotpoc3_z =0;
}
//---------------------------------------------------------------------------

bool __fastcall TForm_infent::checa_salto_pag(int margen_z)
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
void __fastcall TForm_infent::crear_tabla_proveanual()
{
  int rank1_z,rank2_z,rank3_z;
  String proveedor_z,sino_z;

  qry_infent->Close();
  qry_infent->Open();


  qry_proves->Close();
  qry_proves->ParamByName("TPENT")->AsString = tpent_z;
  qry_proves->ParamByName("FECREL")->AsDateTime = fecinianu_z;
  qry_proves->ParamByName("FECFIN")->AsDateTime = fecfin_z;
  qry_proves->ParamByName("CIA")->AsInteger = cia_z;
  qry_proves->Open();
  rank1_z = rank2_z = rank3_z = 0;
  for(qry_proves->First(); !qry_proves->Eof; qry_proves->Next()) {
     proveedor_z  = qry_proves->FieldByName("prove")->AsString;

    //SI
     sino_z = "S";
     qry_compra->Close();
     qry_compra->ParamByName("TPENT")->AsString = tpent_z;
     qry_compra->ParamByName("PROVE")->AsString = proveedor_z;
     qry_compra->ParamByName("FECINI")->AsDateTime = fecini_z;
     qry_compra->ParamByName("FECFIN")->AsDateTime = fecfin_z;
     qry_compra->ParamByName("SINO")->AsString =  sino_z;
     qry_compra->ParamByName("CIA")->AsInteger = cia_z;
     qry_compra->Open();
     comprsi_z  = qry_compra->FieldByName("si")->AsFloat;

     //NO
     sino_z = "N";
     qry_compra->Close();
     qry_compra->ParamByName("TPENT")->AsString = tpent_z;
     qry_compra->ParamByName("PROVE")->AsString = proveedor_z;
     qry_compra->ParamByName("FECINI")->AsDateTime = fecini_z;
     qry_compra->ParamByName("FECFIN")->AsDateTime = fecfin_z;
     qry_compra->ParamByName("SINO")->AsString =  sino_z;
     qry_compra->ParamByName("CIA")->AsInteger = cia_z;
     qry_compra->Open();
     comprno_z  = qry_compra->FieldByName("si")->AsFloat;

     totmes_z = comprsi_z + comprno_z;

     qry_companio->Close();
     qry_companio->ParamByName("TPENT")->AsString = tpent_z;
     qry_companio->ParamByName("PROVE")->AsString = proveedor_z;
     qry_companio->ParamByName("FECINI")->AsDateTime = fecini_z;
     qry_companio->ParamByName("FECINIANU")->AsDateTime = fecinianu_z;
     qry_companio->ParamByName("CIA")->AsInteger = cia_z;
     qry_companio->Open();
     compranio_z  = qry_companio->FieldByName("anio")->AsFloat;

     tototal_z = comprsi_z + comprno_z + compranio_z;


     qry_infent->Append();
     qry_infent->FieldByName("prove")->AsString = proveedor_z;
     qry_infent->FieldByName("comprasi")->AsFloat = comprsi_z;
     qry_infent->FieldByName("comprano")->AsFloat = comprno_z ;
     qry_infent->FieldByName("comprames")->AsFloat = totmes_z;
     //qry_infent->FieldByName("rank1")->AsInteger = rank1_z;
     qry_infent->FieldByName("compranu")->AsFloat = compranio_z;
     //qry_infent->FieldByName("rank2")->AsFloat = rank2_z;
     qry_infent->FieldByName("totgral")->AsFloat = tototal_z;
     //qry_infent->FieldByName("rank3")->AsInteger = rank3_z;
     qry_infent->Post();

      try {
        dm->manvehi->StartTransaction();
        qry_infent->ApplyUpdates();
        dm->manvehi->Commit();
      } catch (Exception &E) {
        dm->manvehi->Rollback();
        Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
      }

  }
  grabar_ranking("COMPRAMES", 5);
  grabar_ranking("COMPRANU", 7);
  grabar_ranking("TOTGRAL", 7);



}
 //---------------------------------------------------------------------------

void __fastcall TForm_infent::FormCreate(TObject *Sender)
{
  date_ini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fin->Date = UltimoDiaMes(date_ini->Date);
  cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::llenar_grip()
{
  qry_llenar->Close();
  qry_llenar->Open();
}

//---------------------------------------------------------------------------
void __fastcall TForm_infent::grabar_ranking(String campo_z, int nelem_z)
{
   TStringList *ordencompra_z;
   ordencompra_z = new TStringList();
   String cadena_z, campodato_z, camporanking_z,prove_z;
   int jj_z;
   if(campo_z == "COMPRAMES") {
     camporanking_z = "RANK1"; campodato_z = "COMPRAMES";
   }
   if(campo_z == "COMPRANU") {
     camporanking_z = "RANK2"; campodato_z = "COMPRANU";
   }

   if(campo_z == "TOTGRAL") {
     camporanking_z = "RANK3"; campodato_z = "TOTGRAL";
   }

   for(qry_infent->First(); !qry_infent->Eof; qry_infent->Next()) {
      cadena_z = FormatFloat("00000000000.00", qry_infent->FieldByName(campodato_z)->AsFloat) + " " + qry_infent->FieldByName("prove")->AsString;
      ordencompra_z->Append(cadena_z);
   }
   ordencompra_z->Sorted = true;
   jj_z = 1;
   TLocateOptions Opts;
   Opts.Clear();
   for(int ii_z = ordencompra_z->Count-1; ii_z > ordencompra_z->Count - nelem_z + 1; ii_z--) {
     prove_z = ordencompra_z->Strings[ii_z].SubString(16,4);
     qry_infent->First();
     if(qry_infent->Locate("prove", prove_z, Opts)) {
       qry_infent->Edit();
       qry_infent->FieldByName(camporanking_z)->AsInteger = jj_z;
       qry_infent->Post();

         try {
          dm->manvehi->StartTransaction();
          qry_infent->ApplyUpdates();
          dm->manvehi->Commit();
        } catch (Exception &E) {
          dm->manvehi->Rollback();
          Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
        }

     }
     jj_z++;
   }
   delete ordencompra_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::imprimir_tabla1()
{
   String  proveer_z, nombre_z,strcomprasi_z,strcomprano_z,strcomprames_z,strrank1_z,
   strcompranu_z,strrank2_z,strtotgen_z,strrank3_z;
   int rank1_z,rank2_z,rank3_z;
   double comprasi_z,comprano_z,comprames_z,compranu_z,totgen_z ;
   strcomprasi_z = "";
   strcomprano_z = "";
   strcomprames_z = "";
   strrank1_z = "";
   strcompranu_z = "";
   strrank2_z = "";
   strtotgen_z = "";
   strrank3_z = "";

   for(qry_llenar->First(); !qry_llenar->Eof; qry_llenar->Next()) {
     proveer_z   = qry_llenar->FieldByName("prove")->AsString;
     nombre_z   = qry_llenar->FieldByName("nombre")->AsString;
     comprasi_z  = qry_llenar->FieldByName("comprasi")->AsFloat;
     comprano_z  = qry_llenar->FieldByName("comprano")->AsFloat;
     comprames_z = qry_llenar->FieldByName("comprames")->AsFloat;
     rank1_z     = qry_llenar->FieldByName("rank1")->AsInteger;
     compranu_z  = qry_llenar->FieldByName("compranu")->AsFloat;
     rank2_z     = qry_llenar->FieldByName("rank2")->AsInteger;
     totgen_z    = qry_llenar->FieldByName("totgral")->AsFloat;
     rank3_z     = qry_llenar->FieldByName("rank3")->AsInteger;

      if (comprasi_z) strcomprasi_z = rjust(FormatFloat("###,##0.00",comprasi_z ),14 );
      if (comprano_z) strcomprano_z = rjust(FormatFloat("###,##0.00",comprano_z ),14 );
      if (comprames_z) strcomprames_z = rjust(FormatFloat("###,##0.00",comprames_z ),14 );
      if (rank1_z) strrank1_z = rjust(FormatFloat("0",rank1_z),3 );
      if (compranu_z) strcompranu_z = rjust(FormatFloat("###,##0.00",compranu_z ),14 );
      if ( rank2_z) strrank2_z = rjust(FormatFloat("0",rank2_z ),3 );
      if (totgen_z) strtotgen_z= rjust(FormatFloat("###,##0.00",totgen_z ),14 );
      if (rank3_z) strrank3_z = rjust(FormatFloat("0",rank3_z ),3 );

     fprintf(archout, "|");
     fprintf(archout, "%s ", ljust( proveer_z, 4));
     fprintf(archout, "%s|", ljust(nombre_z, 31));
     fprintf(archout, "%s|", rjust(strcomprasi_z,14 ));
     fprintf(archout, "%s|", rjust(strcomprano_z,14 ));
     fprintf(archout, "%s|", rjust(strcomprames_z,14 ));
     fprintf(archout, "%s|", cjust(strrank1_z,3 ));
     fprintf(archout, "%s|", rjust(strcompranu_z ,14 ));
     fprintf(archout, "%s|", cjust(strrank2_z,3 ));
     fprintf(archout, "%s|", rjust(strtotgen_z,14 ));
     fprintf(archout, "%s|\n", cjust(strrank3_z,3 ));
     lineas_z += 1;
     checa_salto_pag(3);

     gtotsi_z  += comprasi_z;
     gtotno_z  += comprano_z;
     gtotm_z   += comprames_z;
     gtotanu_z += compranu_z;
     gtotgen_z += totgen_z;
     strcomprasi_z = strcomprano_z = strcomprames_z = strrank1_z = "";
     strcompranu_z = strrank2_z = strtotgen_z = strrank3_z = "";
   }
  }
//---------------------------------------------------------------------------
void __fastcall TForm_infent::crear_tabla_lineanul()
{
    String linea_z,codigo_z;
    TDateTime fecfinanu_z;
    int line_z;
    line_z = 0;
    numenc_z = 2;
    fecfinanu_z = fecini_z - 1;
    checa_salto_pag(400); //salto de paginaaaaa
    qry_lineacod->Close();
    qry_lineacod->ParamByName("FECINI")->AsDateTime = fecinianu_z;
    qry_lineacod->ParamByName("FECFIN")->AsDateTime = fecfin_z;
    qry_lineacod->ParamByName("TPENT")->AsString = tpent_z;
    qry_lineacod->ParamByName("TPDEV")->AsString = tpent_z;
    qry_lineacod->ParamByName("CIA")->AsInteger = cia_z;
    qry_lineacod->Open();
    comprames_z = compranual_z = 0;
    for(qry_lineacod->First(); !qry_lineacod->Eof; qry_lineacod->Next()) {
       linea_z = qry_lineacod->FieldByName("linea")->AsString;
       antlinea_z = linea_z;
       qry_compmes->Close();
       qry_compmes->ParamByName("FECINI")->AsDateTime = fecini_z;
       qry_compmes->ParamByName("FECFIN")->AsDateTime = fecfin_z;
       qry_compmes->ParamByName("TPENT")->AsString = tpent_z;
       qry_compmes->ParamByName("linea")->AsString = linea_z;
       qry_compmes->ParamByName("CIA")->AsInteger = cia_z;
       qry_compmes->Open();
       comprames_z = qry_compmes->FieldByName("mes")->AsFloat;

       qry_compmes->Close();
       qry_compmes->ParamByName("FECINI")->AsDateTime = fecinianu_z;
       qry_compmes->ParamByName("FECFIN")->AsDateTime = fecfinanu_z;
       qry_compmes->ParamByName("TPENT")->AsString = tpent_z;
       qry_compmes->ParamByName("linea")->AsString = linea_z;
       qry_compmes->ParamByName("CIA")->AsInteger = cia_z;
       qry_compmes->Open();
       compranual_z = qry_compmes->FieldByName("mes")->AsFloat;
       imprimir_anual();
    }
    total_tabla2();
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::imprimir_anual()
{
     double divmes_z,divanu_z,compgbla_z,divgbal_z;
     totales();
     divmes_z = 0;
     divanu_z = 0;
     divgbal_z = 0;

     if (totcprames_z) divmes_z = (comprames_z / totcprames_z) * 100;
     if (totcopeanu_z) divanu_z =  (compranual_z / totcopeanu_z) * 100;
     compgbla_z = comprames_z + compranual_z;
     if (totglobal_z) divgbal_z = (compgbla_z / totglobal_z)* 100;

     fprintf(archout, "|");
     fprintf(archout, "%s|", ljust( antlinea_z, 5));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",comprames_z ),13 ));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",divmes_z ),6));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",compranual_z ),13 ));
     fprintf(archout, "%s|", cjust(FormatFloat("###,##0.00",divanu_z), 6));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",compgbla_z ),13 ));
     fprintf(archout, "%s|\n", cjust(FormatFloat("###,##0.00", divgbal_z), 6));
     lineas_z += 1;
     checa_salto_pag(3);

     gtotmes_z  += comprames_z;
     gtotpoc1_z += divmes_z;
     gtoanu_z   += compranual_z;
     gtotpoc2_z += divanu_z;
     gtotgbal_z += compgbla_z;
     gtotpoc3_z += divgbal_z;
}
//---------------------------------------------------------------------------
void __fastcall TForm_infent::totales()
{
   TDateTime fecfinanu_z;
   fecfinanu_z = fecini_z - 1;
   qry_totmes->Close();
   qry_totmes->ParamByName("FECINI")->AsDateTime = fecini_z;
   qry_totmes->ParamByName("FECFIN")->AsDateTime = fecfin_z;
   qry_totmes->ParamByName("TPENT")->AsString = tpent_z;
   qry_totmes->ParamByName("CIA")->AsInteger = cia_z;
   qry_totmes->Open();

   totcprames_z = qry_totmes->FieldByName("totmes")->AsFloat;

   qry_totanual->Close();
   qry_totanual->ParamByName("FECINI")->AsDateTime = fecinianu_z;
   qry_totanual->ParamByName("FECFIN")->AsDateTime = fecfinanu_z;
   qry_totanual->ParamByName("TPENT")->AsString = tpent_z;
   qry_totanual->ParamByName("CIA")->AsInteger = cia_z;
   qry_totanual->Open();

   totcopeanu_z = qry_totanual->FieldByName("totanu")->AsFloat;

   totglobal_z =  totcprames_z + totcopeanu_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::crear_tabla_linedev()
{
    String linea_z,codigo_z;
    int line_z;
    line_z = 0;
    qry_lineacod->Close();
    qry_lineacod->ParamByName("FECINI")->AsDateTime = fecinianu_z;
    qry_lineacod->ParamByName("FECFIN")->AsDateTime = fecfin_z;
    qry_lineacod->ParamByName("TPENT")->AsString = tpent_z;
    qry_lineacod->ParamByName("TPDEV")->AsString = tpdev_z;
    qry_lineacod->ParamByName("CIA")->AsInteger = cia_z;
    qry_lineacod->Open();
    numenc_z = 3;
    encab3();
    totales_mensual();
    for(qry_lineacod->First(); !qry_lineacod->Eof; qry_lineacod->Next()) {
       linea_z = qry_lineacod->FieldByName("linea")->AsString;
       comprames_z = totdevmes_z = devmesual_z= 0;
       antlinea_z = linea_z;

       qry_compmes->Close();
       qry_compmes->ParamByName("FECINI")->AsDateTime = fecini_z;
       qry_compmes->ParamByName("FECFIN")->AsDateTime = fecfin_z;
       qry_compmes->ParamByName("TPENT")->AsString = tpent_z;
       qry_compmes->ParamByName("linea")->AsString = linea_z;
       qry_compmes->ParamByName("CIA")->AsInteger = cia_z;
       qry_compmes->Open();
       comprames_z = qry_compmes->FieldByName("mes")->AsFloat;

       qry_compmes->Close();
       qry_compmes->ParamByName("FECINI")->AsDateTime = fecini_z;
       qry_compmes->ParamByName("FECFIN")->AsDateTime = fecfin_z;
       qry_compmes->ParamByName("TPENT")->AsString = tpdev_z;
       qry_compmes->ParamByName("linea")->AsString = linea_z;
       qry_compmes->ParamByName("CIA")->AsInteger = cia_z;
       qry_compmes->Open();
       devmesual_z = qry_compmes->FieldByName("mes")->AsFloat;
       imprimir_mensual();
    }
    total_tabla3();
}
//---------------------------------------------------------------------------
void __fastcall TForm_infent::imprimir_mensual()
{
     double divmes_z,divanu_z,compgbla_z,divgbal_z;

     divgbal_z = 0;
     compgbla_z = comprames_z - devmesual_z;
     if (totglobal_z) divgbal_z = (compgbla_z / totglobal_z)* 100;

     fprintf(archout, "|");
     fprintf(archout, "%s|", ljust( antlinea_z, 5));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",comprames_z ),13 ));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",devmesual_z ),13 ));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",compgbla_z ),13 ));
     fprintf(archout, "%s|\n", cjust(FormatFloat("###,##0.00", divgbal_z), 6));
     lineas_z += 1;
     checa_salto_pag(3);

     gtotmes_z  += comprames_z;
     gtodev_z   += devmesual_z;
     gtotgbal_z += compgbla_z;
     gtotpoc3_z += divgbal_z;

}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::totales_mensual()
{
   qry_totmes->Close();
   qry_totmes->ParamByName("FECINI")->AsDateTime = fecini_z;
   qry_totmes->ParamByName("FECFIN")->AsDateTime = fecfin_z;
   qry_totmes->ParamByName("TPENT")->AsString = tpent_z;
   qry_totmes->ParamByName("CIA")->AsInteger = cia_z;
   qry_totmes->Open();

   totcprames_z = qry_totmes->FieldByName("totmes")->AsFloat;

   qry_totdevmes->Close();
   qry_totdevmes->ParamByName("FECINI")->AsDateTime = fecini_z;
   qry_totdevmes->ParamByName("FECFIN")->AsDateTime = fecfin_z;
   qry_totdevmes->ParamByName("TPDEV")->AsString = tpdev_z;
   qry_totdevmes->ParamByName("CIA")->AsInteger = cia_z;
   qry_totdevmes->Open();

   totdevmes_z = qry_totdevmes->FieldByName("totdevmes")->AsFloat;

   totglobal_z =  totcprames_z + totdevmes_z;
}
//---------------------------------------------------------------------------
void __fastcall TForm_infent::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TForm_infent::exportarExecute(TObject *Sender)
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

void __fastcall TForm_infent::generar_reporteExecute(TObject *Sender)
{
  String arch_z;
  int anio_z,dia_z,mes_z;
  arch_z = "frm_infent.txt";
  if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
  }
  numenc_z = 1;
  report_encab();
  qry_delete->Close();
  qry_delete->ExecSQL();

  fecini_z  = date_ini->Date;
  fecfin_z  = date_fin->Date;
  tpent_z = "E";
  tpdev_z = "R";
  dia_z = 01;
  mes_z = 01;
  anio_z = FormatDateTime("yyyy",fecfin_z).ToInt();
  fecinianu_z = EncodeDate(anio_z, mes_z, dia_z);
  //Tabla de Informe por Proveedor Anual
  crear_tabla_proveanual();
  llenar_grip();
  imprimir_tabla1();
  total_tabla1();
   // Tabla de Informe por Lineas Anual
  crear_tabla_lineanul();
  //Tabla de Informe por Lineas Mensual - DEVS a Prove
  crear_tabla_linedev();
  fclose(archout);
  dbgrd_renglones->FullExpand();
  dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------

