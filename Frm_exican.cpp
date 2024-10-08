//---------------------------------------------------------------------------
   
#include <vcl.h>
#pragma hdrstop

#include "Frm_exican.h"
#include "numapal.h"
#include "situaciones.h"
#include "dmod.h"
#include "imprigra.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const int LINEAS_X_PAG = 60;
TForm_exican *Form_exican;
//---------------------------------------------------------------------------
__fastcall TForm_exican::TForm_exican(TComponent* Owner)
        : TForm(Owner)
{
   date_ini->Date = PrimerDiaMes(dm->ahora());
   cia_z = dm->cia_z;
   qry_zonas->Close();
   qry_zonas->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::report_encab()
{

  almini_z = edt_almini->Text;
  almfin_z = edt_almfin->Text;
  fprintf(archout, "\n");
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );

  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_exican " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );

  fprintf(archout, "%s\n", cjust( " Del Almacen "  + almini_z + " Al Almacen "  + almfin_z +
  " AL " + FormatDateTime("dd/mm/yyyy", date_ini->Date),70));
  fprintf(archout, "\n");
  lineas_z = 9;

}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::encab_linea( String antzona_z, String antnomzon_z )
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust("Zona:" + antzona_z + " " + antnomzon_z, 50));
  fprintf(archout, "%s\n\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  lineas_z += 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::encab2()
{

   //fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Alamacen",30));
   fprintf(archout, "%s|", cjust("Existencias SI",12));
   fprintf(archout, "%s|", cjust("Existencias NO", 12));
   fprintf(archout, "%s|", cjust("Total Tienda", 12));
   fprintf(archout, "%s|", cjust("Exstncia Total", 12));
   fprintf(archout, "%s|", cjust("%%%", 5));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 2;

}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::encab3_tabla3()
{

   fprintf(archout, "%s|", ljust("", 12));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Linea",5));
   fprintf(archout, "%s|", cjust("Existencias SI",15));
   fprintf(archout, "%s|", cjust("%%", 5));
   fprintf(archout, "%s|", cjust("Existencias NO", 15));
   fprintf(archout, "%s|", cjust("%%", 5));
   fprintf(archout, "%s|", cjust("Exstncia Global", 15));
   fprintf(archout, "%s|", cjust("%%", 5));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 2;

}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::encab_tabla3()
{

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust("DESGLOSE DE EXISTENCIAS MERCANCIA CANCELADA X LINEAS", 80));
  fprintf(archout, "%s\n\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  lineas_z += 1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::encab_alm(String zona_z)
{

   String clavel_z,nombrel_z;
   puntt_z = 0;
   qry_armzon->Close();
   qry_armzon->ParamByName("ALMINI")->AsString = almaini_z;
   qry_armzon->ParamByName("ALMFIN")->AsString = almafin_z;
   qry_armzon->ParamByName("ZONA")->AsString = zona_z;
   qry_armzon->ParamByName("CIA")->AsInteger = cia_z;
   qry_armzon->Open();

   fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Linea",6));

   for(qry_armzon->First(); !qry_armzon->Eof; qry_armzon->Next()) {
     clavel_z = qry_armzon->FieldByName("clave")->AsString;
     nombrel_z = qry_armzon->FieldByName("nombre")->AsString;
     fprintf(archout, "%s|", cjust(clavel_z + "  " + nombrel_z , 12));
     fprintf(archout, "%s|", cjust("%%", 5));
     puntt_z++;
   }

     fprintf(archout, "%s|", cjust("Total", 12));
     fprintf(archout, "%s|", cjust("%%", 5));
     fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
     lineas_z += 2;

}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::encab_alm_tabla2()
{

   String clavel_z,nombrel_z,tipo_z ;
   puntt_z = 0;
   qry_zonas->Close();
   qry_zonas->Open();

   fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Linea",5));

   for(qry_zonas->First(); !qry_zonas->Eof; qry_zonas->Next()) {
     clavel_z = qry_zonas->FieldByName("zona")->AsString;
     nombrel_z = qry_zonas->FieldByName("nombre")->AsString;
     tipo_z =  qry_zonas->FieldByName("tipo")->AsString;
     puntt_z++;

     if ( tipo_z == "2"){
        fprintf(archout, "%s|", cjust("Subtotal",13));
        fprintf(archout, "%s|", cjust("%%", 5));

     }else{
        sub_z = puntt_z;
     }


     fprintf(archout, "%s|", cjust(clavel_z + " " + nombrel_z , 13));
     fprintf(archout, "%s|", cjust("%%", 5));

   }

     fprintf(archout, "%s|", cjust("T o t a l", 14));
     fprintf(archout, "%s|", cjust("%%", 5));
     fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
     lineas_z += 2;


}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::tabla_almacen()
{

  String clave_z,nombre_z,nomzon_z;

  almaini_z = edt_almini->Text;
  almafin_z = edt_almfin->Text;
  cuant_z = 0;
  fecha_z = date_ini->Date;
  lineas_z = 0;
  pagina_z = 1;


  qry_almacen->Close();
  qry_almacen->ParamByName("ALMINI")->AsString = almaini_z;
  qry_almacen->ParamByName("ALMFIN")->AsString = almafin_z;
  qry_almacen->ParamByName("CIA")->AsInteger = cia_z;
  qry_almacen->Open();


  for(qry_almacen->First(); !qry_almacen->Eof; qry_almacen->Next()) {

     clave_z = qry_almacen->FieldByName("clave")->AsString;
     nombre_z = qry_almacen->FieldByName("nombre")->AsString;
     zona_z =  qry_almacen->FieldByName("zona")->AsString;
     nomzon_z = qry_almacen->FieldByName("nomzon")->AsString;
         
     if(lineas_z == 0){
         antzona_z = zona_z;
         antnomzon_z = nomzon_z;
         report_encab();
         encab_linea(antzona_z,antnomzon_z);
         encab2();
      }

     if (antzona_z != zona_z){
        antzona_z = zona_z;
        antnomzon_z = nomzon_z;
        total_zona();
        checa_saltopag(12);
        encab_linea(antzona_z,antnomzon_z);
        encab2();


     }

     qry_exisi->Close();
     qry_exisi->ParamByName("FECHA")->AsDateTime = fecha_z;
     qry_exisi->ParamByName("ALM")->AsString = clave_z;
     qry_exisi->ParamByName("ENTCAN")->AsString = entcan_z;
     qry_exisi->ParamByName("NOCAN")->AsString = nocan_z;
     qry_exisi->ParamByName("CIA")->AsInteger = cia_z;
     qry_exisi->Open();

     for(qry_exisi->First(); !qry_exisi->Eof; qry_exisi->Next()) {
         costosi_z = qry_exisi->FieldByName("costosi")->AsFloat;
         costono_z = qry_exisi->FieldByName("costono")->AsFloat;
     }

     porc_z = 100;
     sumcostos_z = costosi_z + costono_z;

     fprintf(archout, "%s|", ljust(clave_z + "  " + nombre_z  , 30));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",costosi_z), 12));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",costono_z ),12 ));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",sumcostos_z), 12));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",sumcostos_z ),12 ));
     fprintf(archout, "%s|\n", rjust(FormatFloat("0.00",porc_z ),5 ));

     lineas_z += 1;
     cuant_z = 0;

     totsumcostos_z += costosi_z;
     totconstono_z += costono_z;
     totienda_z += sumcostos_z;
     totexisten_z += sumcostos_z;
     sumcostos_z = 0;
     checa_saltopag(12);



  }
    total_zona();
    total_genzona();
    tabla1_z = false;
    checa_saltopag(300);
}
//---------------------------------------------------------------------------

bool __fastcall TForm_exican::checa_saltopag(int numero_de_lineas)
{
  bool haysalto_z = false;

  if(lineas_z > ( LINEAS_X_PAG - numero_de_lineas) ) {
    fprintf(archout, "%c", 12); pagina_z++;

        
    report_encab();

    if (tabla1_z == true){
       encab_linea(antzona_z,antnomzon_z);
       encab2();
    }

    if (tabla2_z == true){
        encab_linea(zonalin_z ,nombrelin_z);
        encab_alm(zonalin_z);

    }

    if (tabla3_z == true){
        encab_tabla3();
    }

    haysalto_z = true;
    
  }

  return(haysalto_z);
}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::total_zona()
{
  int sumas_z;
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total de Esta Zona:", 30));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totsumcostos_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totconstono_z ),12 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totienda_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totexisten_z ),12 ));
  fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc_z ),5 ));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  fprintf(archout, "\n");
  lineas_z += 1;
  
  gtotsumcostos_z += totsumcostos_z;
  gtotconstono_z  += totconstono_z;
  gtotienda_z     += totienda_z;
  gtotexisten_z   += totexisten_z;

  totsumcostos_z = totconstono_z = totienda_z  = totexisten_z = 0;

}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::total_genzona()
{
  int sumas_z;
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total General:", 30));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotsumcostos_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotconstono_z ),12 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotienda_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtotexisten_z ),12 ));
  fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc_z ),5 ));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n\n");
  
  lineas_z += 1;
  gtotsumcostos_z = gtotconstono_z = gtotienda_z = gtotexisten_z= 0;

}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::tabla_lineas()
{

  String  linea_z,descrilin_z,clave_z,nombrealm_z,num_z;
  double total_z,totzona_z,porc_z;
  tabla2_z = true;

  sum = new TStringList();

  for(qry_zonas->First(); !qry_zonas->Eof; qry_zonas->Next()) {

    zonalin_z = qry_zonas->FieldByName("zona")->AsString;
    nombrelin_z = qry_zonas->FieldByName("nombre")->AsString;
    puntt_z = 0;
    encab_linea(zonalin_z,nombrelin_z);
    encab_alm(zonalin_z);

    qry_lineas->Close();
    qry_lineas->ParamByName("FECHA")->AsDateTime = fecha_z;
    qry_lineas->ParamByName("ENTCAN")->AsString = entcan_z;
    qry_lineas->ParamByName("NOCAN")->AsString = nocan_z;
    qry_lineas->ParamByName("CIA")->AsInteger = cia_z;
    qry_lineas->Open();

    for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {

      linea_z = qry_lineas->FieldByName("linea")->AsString;
      descrilin_z = qry_lineas->FieldByName("descri")->AsString;

      qry_almzona->Close();
      qry_almzona->ParamByName("ALMINI")->AsString = almaini_z;
      qry_almzona->ParamByName("ALMFIN")->AsString = almafin_z;
      qry_almzona->ParamByName("ZONA")->AsString = zonalin_z;
      qry_almzona->ParamByName("CIA")->AsInteger = cia_z;
      qry_almzona->Open();

      fprintf(archout, "%s|", ljust(linea_z, 6));

      for(qry_almzona->First(); !qry_almzona->Eof; qry_almzona->Next()) {

         clave_z = qry_almzona->FieldByName("clave")->AsString;
         nombrealm_z = qry_almzona->FieldByName("nombre")->AsString;


         qry_costlinea->Close();
         qry_costlinea->ParamByName("FECHA")->AsDateTime = fecha_z;
         qry_costlinea->ParamByName("ALM")->AsString = clave_z;
         qry_costlinea->ParamByName("ZONA")->AsString = zonalin_z;
         qry_costlinea->ParamByName("ENTCAN")->AsString = entcan_z;
         qry_costlinea->ParamByName("NOCAN")->AsString = nocan_z;
         qry_costlinea->ParamByName("LINEA")->AsString = linea_z;
         qry_costlinea->ParamByName("CIA")->AsInteger = cia_z;
         qry_costlinea->Open();


         for(qry_costlinea->First(); !qry_costlinea->Eof; qry_costlinea->Next()) {

            total_z = qry_costlinea->FieldByName("total")->AsFloat;
            totzona_z = qry_costlinea->FieldByName("totzona")->AsFloat;

         }
           if(totzona_z > 0){

           porc_z = (total_z / totzona_z) * 100;

           }

           sum->Append("0");
           fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",total_z), 12));
           fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc_z ), 5));

           totallinea_z += total_z;

           misuma_z = StrToFloat(sum->Strings[cuant_z]);
           misuma_z += total_z;
           sum->Strings[cuant_z] = misuma_z;

           cuant_z++;
           total_z = 0;
           porc_z = 0;

      }

         cuant_z = 0;
         fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totzona_z), 12));
         fprintf(archout, "%s|\n", cjust("100.00", 5));
         lineas_z += 1;
         checa_saltopag(12);

    }
    total_linea();

  }
    puntt_z = 0;
    tabla2_z = false;

}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::total_linea()
{
  int sumas_z;
  double porc2_z;
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total:", 6));
  for( int ii_z=0; ii_z < puntt_z; ii_z++) {
     sumas_z = StrToFloat(sum->Strings[ii_z]);

     porc2_z = (sumas_z / totallinea_z) * 100;
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", sumas_z), 12));
     fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc2_z ), 5));
  }
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totallinea_z), 12));
     fprintf(archout, "%s|\n\n", cjust("100.00", 5));

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z += 1;
  puntt_z = 0;
  totallinea_z = 0;
  sum->Clear();
  sum = new TStringList();

}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::tabla_lineas_final()
{

   String tnombre_z;
   double ttotzona_z,porc3_z,tot2_z,porc4_z;
   encab_alm_tabla2();
   desglose_total_gen();
   tot2_z = 0;
   for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {


      tlinea_z = qry_lineas->FieldByName("linea")->AsString;
      //Subtotales
      Subtotales_porc(tlinea_z);

      fprintf(archout, "%s|", ljust(tlinea_z, 5));

       for(qry_zonas->First(); !qry_zonas->Eof; qry_zonas->Next()){

         tzona_z = qry_zonas->FieldByName("zona")->AsString;
         tnombre_z = qry_zonas->FieldByName("nombre")->AsString;
         ttipo_z = qry_zonas->FieldByName("tipo")->AsString;


         qry_costzon->Close();
         qry_costzon->ParamByName("FECHA")->AsDateTime = fecha_z;
         qry_costzon->ParamByName("ZON")->AsString = tzona_z;
         qry_costzon->ParamByName("ENTCAN")->AsString = entcan_z;
         qry_costzon->ParamByName("NOCAN")->AsString = nocan_z;
         qry_costzon->ParamByName("LINEA")->AsString = tlinea_z;
         qry_costzon->ParamByName("CIA")->AsInteger = cia_z;
         qry_costzon->Open();

         for(qry_costzon->First(); !qry_costzon->Eof; qry_costzon->Next()) {

            ttotal_z = qry_costzon->FieldByName("tot1")->AsFloat;
            ttotzona_z = qry_costzon->FieldByName("tot2")->AsFloat;

         }



         if (ttipo_z == "1"){

          if(ttotzona_z > 0){
           porc_z = (ttotal_z / subtotporc_z) * 100;
          }

          tot2_z += ttotal_z;

         }

         if (ttipo_z == "2"){

           porc_z = (ttotal_z / ttotzona_z) * 100;
           porc3_z = ( subtotporc_z / ttotzona_z) * 100;
           fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",tot2_z), 13));
           fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc3_z ), 5));
           porctot_z= 0;
           porc3_z = 0;
           tot2_z = 0;

         }

           totallinea_z += ttotal_z;
           porctot_z += ttotal_z;


           fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",ttotal_z), 13));
           fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc_z ), 5));

           sum->Append("0");
           misuma_z = StrToFloat(sum->Strings[cuant_z]);
           misuma_z += ttotal_z;
           sum->Strings[cuant_z] = misuma_z;

           cuant_z++;

           ttotal_z = 0;
           //porc_z = 0;

       }

         cuant_z = 0;
         porc4_z = ( ttotzona_z  / gtcostos_z) * 100;
         fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",ttotzona_z), 13));
         fprintf(archout, "%s|\n", rjust(FormatFloat("0.00",porc4_z ), 5));
         lineas_z += 1;
         checa_saltopag(12);
         subtotporc_z = 0;
         totporc4_z += porc4_z;

    }
    total_linea_tabla();
}

//---------------------------------------------------------------------------
void __fastcall TForm_exican::Subtotales_porc(String tlinea_z)  
{

    for(qry_zonas->First(); !qry_zonas->Eof; qry_zonas->Next()){

         tzona_z = qry_zonas->FieldByName("zona")->AsString;
         ttipo_z = qry_zonas->FieldByName("tipo")->AsString;


         qry_costzon->Close();
         qry_costzon->ParamByName("FECHA")->AsDateTime = fecha_z;
         qry_costzon->ParamByName("ZON")->AsString = tzona_z;
         qry_costzon->ParamByName("ENTCAN")->AsString = entcan_z;
         qry_costzon->ParamByName("NOCAN")->AsString = nocan_z;
         qry_costzon->ParamByName("LINEA")->AsString = tlinea_z;
         qry_costzon->ParamByName("CIA")->AsInteger = cia_z;
         qry_costzon->Open();

         for(qry_costzon->First(); !qry_costzon->Eof; qry_costzon->Next()) {

            ttotal_z = qry_costzon->FieldByName("tot1")->AsFloat;

         }

         if (ttipo_z == "1"){

           subtotporc_z += ttotal_z;

         }

    }

}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::total_linea_tabla()
{
  int sumas_z;
  double porc2_z,porc3_z,totsumas_z;
  totsumas_z = 0;
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total", 5));
  for( int ii_z=0; ii_z < puntt_z; ii_z++) {
     sumas_z = StrToFloat(sum->Strings[ii_z]);

     porc2_z = (sumas_z / totallinea_z) * 100;
     porc3_z = (totsumas_z / totallinea_z) * 100;

     if (ii_z == sub_z){
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", totsumas_z), 13));
       fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc3_z ), 5));
     }else{
       totsumas_z += sumas_z;
     }

     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", sumas_z), 13));
     fprintf(archout, "%s|", rjust(FormatFloat("0.00",porc2_z ), 5));
  }

  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totallinea_z), 13));
  fprintf(archout, "%s|", rjust(FormatFloat("0.00",totporc4_z ), 5));

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z += 1;
  puntt_z = 0;
  totporc4_z = 0;
  totallinea_z = 0;
  totsumas_z = 0;
  sum->Clear();
  sum = new TStringList();

}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::tabla_linea_global()
{
   encab3_tabla3();
   String dlinea_z;
   double dcostosi_z,dcostono_z,dporcsi_z,dporcno_z,dporctot_z,sumcotos_z;

   desglose_total_gen();
   for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {

       dlinea_z = qry_lineas->FieldByName("linea")->AsString;

       qry_desglose->Close();
       qry_desglose->ParamByName("FECHA")->AsDateTime = fecha_z;
       qry_desglose->ParamByName("ENTCAN")->AsString = entcan_z;
       qry_desglose->ParamByName("NOCAN")->AsString = nocan_z;
       qry_desglose->ParamByName("LINEA")->AsString = dlinea_z;
       qry_desglose->ParamByName("CIA")->AsInteger = cia_z;
       qry_desglose->Open();


       for(qry_desglose->First(); !qry_desglose->Eof; qry_desglose->Next()) {

          dcostosi_z = qry_desglose->FieldByName("costosi")->AsFloat;
          dcostono_z = qry_desglose->FieldByName("costono")->AsFloat;

       }

         dporcsi_z = (dcostosi_z /  gtcostosi_z) * 100;
         dporcno_z =  (dcostono_z/  gtcostosi_z) * 100;

         sumcotos_z = dcostosi_z + dcostono_z;


         dtotsi_z += dcostosi_z;
         dtotno_z += dcostono_z;
         gtsumcostos_z  += sumcotos_z;

         gtporc1_z += dporcsi_z;
         gtporc2_z += dporcno_z;

         dporctot_z = (sumcotos_z / gtcostos_z) * 100;
         gtporc3_z += dporctot_z;

         fprintf(archout, "%s|", ljust("", 12));
         fprintf(archout, "%s|", ljust(dlinea_z, 5));
         fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",dcostosi_z), 15));
         fprintf(archout, "%s|", rjust(FormatFloat("0.00",dporcsi_z ), 5));

         fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",dcostono_z), 15));
         fprintf(archout, "%s|", rjust(FormatFloat("0.00",dporcno_z ), 5));

         fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",sumcotos_z), 15));
         fprintf(archout, "%s|\n", rjust(FormatFloat("0.00", dporctot_z  ), 5));

         lineas_z += 1;
         checa_saltopag(12);

    }

    total_global_tabla();


}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::desglose_total_gen()
{

   qry_gendesg->Close();
   qry_gendesg->ParamByName("FECHA")->AsDateTime = fecha_z;
   qry_gendesg->ParamByName("ENTCAN")->AsString = entcan_z;
   qry_gendesg->ParamByName("NOCAN")->AsString = nocan_z;
   qry_gendesg->ParamByName("CIA")->AsInteger = cia_z;
   qry_gendesg->Open();


   for(qry_gendesg->First(); !qry_gendesg->Eof; qry_gendesg->Next()) {

      gtcostosi_z = qry_gendesg->FieldByName("costosi")->AsFloat;
      gtcostono_z = qry_gendesg->FieldByName("costono")->AsFloat;

   }

   gtcostos_z = gtcostosi_z + gtcostono_z;


}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::total_global_tabla()
{
  int sumas_z;
  double porc2_z,porc3_z,totsumas_z;
  fprintf(archout, "\n");

  fprintf(archout, "%s|", ljust("", 12));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total", 5));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",dtotsi_z), 15));
  fprintf(archout, "%s|", rjust(FormatFloat("0.00",gtporc1_z  ), 5));

  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",dtotno_z ), 15));
  fprintf(archout, "%s|", rjust(FormatFloat("0.00",gtporc2_z ), 5));

  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",gtsumcostos_z), 15));
  fprintf(archout, "%s|\n", rjust(FormatFloat("0.00",gtporc3_z  ), 5));

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z += 1;
  
  gtporc1_z = gtporc1_z = gtporc1_z = 0;
  dtotsi_z = dtotno_z  = gtsumcostos_z = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm_exican::FormCreate(TObject *Sender)
{
  date_ini->Date = UltimoDiaMes(IncMonth(dm->ahora(), -1));        
}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::imprimir_reporteExecute(TObject *Sender)
{


  double costodat_z ,totaldat_z,costotot_z,costunid_z;
  int unidat_z,folent_z,puntos_z,totalsem_z;
  tabla3_z = false;


    if(rbtn_cancelados->Checked || rbtn_todos->Checked ){
      entcan_z = "S";
   }

    if(rbtn_nocancel->Checked || rbtn_todos->Checked ){
      nocan_z = "N";
   }



   if(Application->MessageBox("Seguro imprimir Reporte ?", "Impresión Reporte", MB_OKCANCEL) != IDOK ) return;
   arch_z = "frm_exican.txt";
   if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
   }

   if(rbtn_lasi->Checked){
      tabla1_z = true;
      tabla_almacen();
   }

   if( rbtn_lzsi->Checked){
      tabla_lineas();
      checa_saltopag(300);
      tabla_lineas_final();

   }

   if( rbtn_lgsi->Checked){
      tabla3_z = true;
      checa_saltopag(300);
      tabla_linea_global();

   }


        
}
//---------------------------------------------------------------------------

void __fastcall TForm_exican::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------

