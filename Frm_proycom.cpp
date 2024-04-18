//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Frm_proycom.h"
#include "numapal.h"
#include "situaciones.h"
#include "dmod.h"
#include "imprigra.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
const int LINEAS_X_PAG = 60;
TForm_proycom *Form_proycom;
//---------------------------------------------------------------------------
__fastcall TForm_proycom::TForm_proycom(TComponent* Owner)
        : TForm(Owner)
{
   date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
   date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
   cia_z = dm->cia_z;
   qry_proycom->Close();
   qry_proycom->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_proycom::genera_reporte()
{

  String arch_z,tipoent_z,status_z, suboglo_z,
  zona_z,subzona_z,tipo_z,zonaacu_z,ptvta_z;

  int idtipocar_z;

  arch_z="proycom.txt";
  if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
  }
  lineas_z = 0;
  pagina_z = 1;
  real_z = 0;
  costreal_z=0;
  salto_z = false;
  tip_z = false;

  if(rbtn_fona->Checked){
       fona_z = "F";
   }else if (rbtn_ime->Checked){
       imevi_z = "V";
   }else if (rbtn_menu->Checked){
       menudeo_z = "M";
   }else if (rbtn_fide->Checked){
       fide_z = "I";
   }else if (rbtn_total->Checked){
       total_z = "T";
   }

   for(qry_proycom->First(); !qry_proycom->Eof; qry_proycom->Next()) {
      zonapy_z   = qry_proycom->FieldByName("zona")->AsString;
      nombrezon_z = qry_proycom->FieldByName("nombre")->AsString;
      subzonpy_z = qry_proycom->FieldByName("subzona")->AsString;
      descripy_z = qry_proycom->FieldByName("descri")->AsString;
      suboglo_z  = qry_proycom->FieldByName("suboglo")->AsString;
      porcon_z = qry_proycom->FieldByName("porcon")->AsFloat;
      porcrd_z = qry_proycom->FieldByName("porcrd")->AsFloat;
      porfon_z = qry_proycom->FieldByName("porfon")->AsFloat;
      porfid_z = qry_proycom->FieldByName("porfid")->AsFloat;
      porcel_z = qry_proycom->FieldByName("porcel")->AsFloat;
      porime_z = qry_proycom->FieldByName("porime")->AsFloat;

      if(lineas_z == 0){
         antzona_z = zonapy_z;
         antsubzona_z = subzonpy_z;
         antdescri_z = nombrezon_z;
         antdescrisub_z = descripy_z;
         report_encab();
         //report_zona(antzona_z,nombrezon_z);--
         //report_subzona(subzonpy_z,descripy_z);
         //encab1();
      }

      if( antsubzona_z != subzonpy_z  ){
        if (antzona_z != zonapy_z){


          checa_saltopag(12);

           report_subtotalzona(antzona_z,antdescri_z);
           subtotal_ventas(subtotconta_z, subtotcred_z,subfona_z,subfide_z,subreal_z);
           //report_zona(zonapy_z, nombrezon_z);
           subtotconta_z = subproycon_z = subtotcred_z = subproycrd_z = 0;
           subfona_z = subproyfon_z = subfide_z = subproyfid_z = subrelcont_z = 0;
           subrelcyc_z = subrelfon_z = subrelfide_z = 0;
        }
        antzona_z = zonapy_z;
        antsubzona_z = subzonpy_z;
        antdescri_z = nombrezon_z;
        antdescrisub_z = descripy_z;
        realcont_z = realcred_z = realfon_z = realfide_z = 0;
        //report_subzona(subzonpy_z,descripy_z);

      }

       qry_subproycom->Close();
       qry_subproycom->ParamByName("ZONA"  )->AsString  =  zonapy_z;
       qry_subproycom->ParamByName("SUBZON")->AsString =  subzonpy_z;
       qry_subproycom->ParamByName("CIA"  )->AsInteger  = cia_z;
       qry_subproycom->Open();

       for(qry_subproycom->First(); !qry_subproycom->Eof; qry_subproycom->Next()) {
          zona_z    =  qry_subproycom->FieldByName("zona")->AsString;
          subzona_z =  qry_subproycom->FieldByName("subzona")->AsString;
          tipo_z    =  qry_subproycom->FieldByName("tipo")->AsString;
          zonaacu_z =  qry_subproycom->FieldByName("zonaacu")->AsString;
          ptvta_z   =  qry_subproycom->FieldByName("ptvta")->AsString;

           if (menudeo_z == "M" || total_z == "T"){

              if (tipo_z == "C"){
                if(total_z == "T"){
                  menudeo_z = "M";
                }
                tipoent_z = "V";  //contado
                tip_z = true;
                suma_anual(tipoent_z,suboglo_z,menudeo_z, zona_z, ptvta_z,tip_z );
                //tip_z = 0;
                //tipoent_z = "V";  //creditoo
                //suma_anual(tipoent_z,suboglo_z,menudeo_z, zona_z, ptvta_z,tip_z );
              }

              if (tipo_z == "V"){
                 if(suboglo_z == "S"){
                    idtipocar_z = 1;
                    if (ptvta_z == "CA"){
                       //Creditoo
                       qry_tipocredi->Close();
                       qry_tipocredi->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                       qry_tipocredi->ParamByName("FECINI")->AsDateTime =  fecini_z;
                       qry_tipocredi->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                       qry_tipocredi->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                       qry_tipocredi->Open();
                       vtacredito_z =+ qry_tipocredi->FieldByName("credito")->AsFloat;

                       //Contado
                       qry_tipocont->Close();
                       qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                       qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                       qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                       qry_tipocont->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                       qry_tipocont->Open();
                       vtacontado_z =+ qry_tipocont->FieldByName("contado")->AsFloat;

                    }else{
                        //Creditoo
                       qry_tipocardet1->Close();
                       qry_tipocardet1->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                       qry_tipocardet1->ParamByName("SUBZON"  )->AsString  =  subzonpy_z;
                       qry_tipocardet1->ParamByName("FECINI")->AsDateTime =  fecini_z;
                       qry_tipocardet1->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                       qry_tipocardet1->ParamByName("IDETIP"  )->AsInteger  = idtipocar_z;
                       qry_tipocardet1->Open();
                       vtacredito_z =+ qry_tipocardet1->FieldByName("credito")->AsFloat;

                       //Contado
                       qry_tipocardet2->Close();
                       qry_tipocardet2->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                       qry_tipocardet2->ParamByName("SUBZON"  )->AsString  =  subzonpy_z;
                       qry_tipocardet2->ParamByName("FECINI")->AsDateTime =  fecini_z;
                       qry_tipocardet2->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                       qry_tipocardet2->ParamByName("IDETIP"  )->AsInteger  = idtipocar_z;
                       qry_tipocardet2->Open();
                       vtacontado_z =+ qry_tipocardet2->FieldByName("contado")->AsFloat;

                    }

                 }else{
                   //Creditoo
                   qry_tipocredi->Close();
                   qry_tipocredi->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                   qry_tipocredi->ParamByName("FECINI")->AsDateTime =  fecini_z;
                   qry_tipocredi->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                   qry_tipocredi->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                   qry_tipocredi->Open();
                   vtacredito_z =+ qry_tipocredi->FieldByName("credito")->AsFloat;

                   //Contado
                   qry_tipocont->Close();
                   qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                   qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                   qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                   qry_tipocont->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                   qry_tipocont->Open();
                   vtacontado_z =+ qry_tipocont->FieldByName("contado")->AsFloat;

                 }

              }

           }//fin M y T

           if (fona_z == "F" || total_z == "T"){

              if (tipo_z == "F"){
                if(total_z == "T"){
                  fona_z = "F";
                  tipoent_z = "F";
                  suma_anual(tipoent_z,suboglo_z,fona_z, zona_z, ptvta_z,tip_z);
                  tipoent_z = "O";
                  suma_anual(tipoent_z,suboglo_z,fona_z, zona_z, ptvta_z
                  ,tip_z);
                }

              }

              if (tipo_z == "E"){

                 if(suboglo_z == "S"){
                    idtipocar_z = 2;
                    if (ptvta_z == "CA"){
                      //Contado
                      qry_tipocont->Close();
                      qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                      qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                      qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                      qry_tipocont->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                      qry_tipocont->Open();
                      foncontado_z = qry_tipocont->FieldByName("contado")->AsFloat;
                      vtafon_z =+ foncontado_z;

                    }else{
                       //Contado
                       qry_tipocardet2->Close();
                       qry_tipocardet2->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                       qry_tipocardet2->ParamByName("SUBZON"  )->AsString  =  subzonpy_z;
                       qry_tipocardet2->ParamByName("FECINI")->AsDateTime =  fecini_z;
                       qry_tipocardet2->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                       qry_tipocardet2->ParamByName("IDETIP"  )->AsInteger  = idtipocar_z;
                       qry_tipocardet2->Open();
                       foncontado_z = qry_tipocardet2->FieldByName("contado")->AsFloat;
                       vtafon_z =+ foncontado_z;

                    }

                 }else{
                   //Contado
                   qry_tipocont->Close();
                   qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                   qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                   qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                   qry_tipocont->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                   qry_tipocont->Open();
                   foncontado_z = qry_tipocont->FieldByName("contado")->AsFloat;
                   vtafon_z =+ foncontado_z;


                 }
              }
           }//fin F y T

           if (imevi_z == "V" || total_z == "T"){

             if (tipo_z == "M"){
               if(total_z == "T"){
                  imevi_z = "V";
               }
               tipoent_z = "1";
               suma_anual(tipoent_z,suboglo_z,imevi_z, zona_z, ptvta_z,tip_z);
             }

             if (tipo_z == "N"){

                if(suboglo_z == "S"){
                   idtipocar_z = 5;
                   if (ptvta_z == "CA"){
                     //Contado
                     qry_tipocont->Close();
                     qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                     qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                     qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                     qry_tipocont->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                     qry_tipocont->Open();
                     imecontado_z = qry_tipocont->FieldByName("contado")->AsFloat;
                     vtaime_z =+ imecontado_z;
                   }else{
                      //Contado
                      qry_tipocardet2->Close();
                      qry_tipocardet2->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                      qry_tipocardet2->ParamByName("SUBZON"  )->AsString  =  subzonpy_z;
                      qry_tipocardet2->ParamByName("FECINI")->AsDateTime =  fecini_z;
                      qry_tipocardet2->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                      qry_tipocardet2->ParamByName("IDETIP"  )->AsInteger  = idtipocar_z;
                      qry_tipocardet2->Open();
                      imecontado_z = qry_tipocardet2->FieldByName("contado")->AsFloat;
                      vtaime_z =+ imecontado_z;
                  }


               }else{
                  //Contado
                  qry_tipocont->Close();
                  qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                  qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                  qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                  qry_tipocont->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                  qry_tipocont->Open();
                  imecontado_z = qry_tipocont->FieldByName("contado")->AsFloat;
                  vtaime_z =+ imecontado_z;

               }
             }
           }//fin V y T

           if (fide_z == "I" || total_z == "T"){

             if (tipo_z == "I"){
               if(total_z == "T"){
                  fide_z = "I";
               }
               tipoent_z = "H";
               suma_anual(tipoent_z,suboglo_z,fide_z, zona_z, ptvta_z,tip_z);
             }

             if (tipo_z == "D"){

                if(suboglo_z == "S"){
                   idtipocar_z = 3;
                   if (ptvta_z == "CA"){
                     //Contado
                     qry_tipocont->Close();
                     qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                     qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                     qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                     qry_tipocont->ParamByName("IDECAR"  )->AsInteger = idtipocar_z;
                     qry_tipocont->Open();
                     fidecontado_z = qry_tipocont->FieldByName("contado")->AsFloat;
                     vtafid_z =+ fidecontado_z;

                   }else{
                      //Contado
                      qry_tipocardet2->Close();
                      qry_tipocardet2->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                      qry_tipocardet2->ParamByName("SUBZON"  )->AsString  =  subzonpy_z;
                      qry_tipocardet2->ParamByName("FECINI")->AsDateTime =  fecini_z;
                      qry_tipocardet2->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                      qry_tipocardet2->ParamByName("IDETIP"  )->AsInteger  = idtipocar_z;
                      qry_tipocardet2->Open();
                      fidecontado_z = qry_tipocardet2->FieldByName("contado")->AsFloat;
                      vtafid_z =+ fidecontado_z;

                  }

               }else{
                  //Contado
                  qry_tipocont->Close();
                  qry_tipocont->ParamByName("ZONA"  )->AsString  =  zonapy_z;
                  qry_tipocont->ParamByName("FECINI")->AsDateTime =  fecini_z;
                  qry_tipocont->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
                  qry_tipocont->ParamByName("IDECAR"  )->AsInteger  = idtipocar_z;
                  qry_tipocont->Open();
                  fidecontado_z = qry_tipocont->FieldByName("contado")->AsFloat;
                  vtafid_z =+ fidecontado_z;

               }
             }
           }//fin I y T

       }//segundo for

       proycon_z = vtacontado_z * (porcon_z /100);
       proycrd_z = vtacredito_z * (porcrd_z /100);
       proyfon_z = vtafon_z * (porfon_z /100);
       proyfid_z = vtafid_z * (porfid_z /100);
       proyime_z = vtaime_z * (porime_z /100);

       if ( vtacredito_z > 0 || vtacontado_z > 0 || vtafon_z > 0 || vtaime_z > 0 || vtafid_z > 0  ){
            report_subzona(antsubzona_z,antdescrisub_z ); //subzonpy_z,descripy_z
            encab1();

           //report_subzona(subzonpy_z,descripy_z);--
           //encab1(); --
           if (menudeo_z == "M" || total_z == "T" ){

             if ( vtacontado_z > 0 ){
               realcont_z = (costrealcont_z / vtacontado_z) * 100;
               fprintf(archout, "%s", ljust(" ",7));
               fprintf(archout, "%s", ljust("Ventas al Contado:",20));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", vtacontado_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", porcon_z), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  proycon_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", realcont_z), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", costrealcont_z), 13));
               subtotconta_z += vtacontado_z;
               subrelcont_z += costrealcont_z;
               subproycon_z += proycon_z;
               salta_linea();
               realcont_z =0;

             }
             if (vtacredito_z > 0 ){
               realcred_z = (costrealcyc_z / vtacredito_z) * 100;
               fprintf(archout, "%s", ljust(" ",7));
               fprintf(archout, "%s", ljust("Ventas a Credito:",20));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", vtacredito_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", porcrd_z ), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  proycrd_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", realcred_z), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", costrealcyc_z), 13));
                salta_linea();
               subtotcred_z +=  vtacredito_z;
               subrelcyc_z += costrealcyc_z;
               subproycrd_z += proycrd_z;
               realcred_z = 0;

             }

           }

           if (fona_z == "F" || total_z == "T" ){
             if(vtafon_z > 0){
               realfon_z =   (costrealfon_z / vtafon_z ) * 100;
               fprintf(archout, "%s", ljust(" ",7));
               fprintf(archout, "%s", ljust("Ventas FONACOT:",20));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", vtafon_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", porfon_z ), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  proyfon_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", realfon_z), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", costrealfon_z), 13));
               salta_linea();
               subfona_z +=  vtafon_z;
               subrelfon_z += costrealfon_z;
               subproyfon_z += proyfon_z;
               realfon_z = 0;
             }
           }

           if (fide_z == "I" || total_z == "T"){
             if(vtafid_z > 0 ){
               realfide_z =   (costrealfide_z / vtafid_z ) * 100;
               fprintf(archout, "%s", ljust(" ",7));
               fprintf(archout, "%s", ljust("Ventas FIDE:",20));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", vtafid_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", porfid_z), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  proyfid_z), 13));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", realfide_z), 6));
               fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", costrealfide_z), 13));
               salta_linea();
               subfide_z += vtafid_z;
               subrelfide_z += costrealfide_z;
               realfide_z = 0;
               subproyfid_z += proyfid_z;
             }
           }

     //

           salto_z = true;
           checa_saltopag(10);

           subreal_z =+  costreal_z;
           totimporte_z = vtacontado_z + vtacredito_z + vtafon_z + vtafid_z;
           totcostos_z = proycon_z + proycrd_z + proyfon_z + proyfid_z;
           totcostoreal_z = costrealcont_z + costrealcyc_z +costrealfon_z + costrealfide_z;
           mub_z = ((totimporte_z - costreal_z) / totimporte_z) * 100;
           costrealcont_z = costrealcyc_z = costrealfon_z = costrealfide_z = 0 ;
           total_ventas(totimporte_z,totcostos_z,mub_z, totcostoreal_z);
           proycon_z=proycrd_z=proyfon_z=proyfid_z=proyime_z= 0;

           vtacontado_z = vtacredito_z = vtafon_z = vtafid_z = costrealcont_z = 0;

       }

   }//primnere For
    report_subtotalzona(antzona_z,antdescri_z);
    subtotal_ventas(subtotconta_z, subtotcred_z,subfona_z,subfide_z,subreal_z);
    total_generales();
    fclose(archout);
    dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------
void __fastcall TForm_proycom::subtotal_ventas(double subtotconta_z, double subtotcred_z,
 double subfona_z,double subfide_z, double subreal_z)
{

   double submubsrel_z;

   //subproyime_z += subreal_z;


   if ( subtotconta_z > 0 && subproycon_z > 0 && subrelcont_z > 0 ){
     fprintf(archout, "%s", ljust(" ",7));
     fprintf(archout, "%s", ljust("Ventas al Contado:",20));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subtotconta_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  subproycon_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subrelcont_z), 13));
     salta_linea();
   }

   if ( subtotcred_z > 0 && subproycrd_z > 0 && subrelcyc_z > 0 ){
     fprintf(archout, "%s", ljust(" ",7));
     fprintf(archout, "%s", ljust("Ventas a Credito:",20));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subtotcred_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  subproycrd_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subrelcyc_z), 13));
     salta_linea();
   }

   if ( subfona_z > 0 && subproyfon_z > 0 && subrelfon_z > 0 ){
     fprintf(archout, "%s", ljust(" ",7));
     fprintf(archout, "%s", ljust("Ventas FONACOT:",20));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subfona_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  subproyfon_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subrelfon_z), 13));
     salta_linea();
   }

   if ( subfide_z > 0 && subproyfid_z > 0 && subrelfide_z > 0 ){
     fprintf(archout, "%s", ljust(" ",7));
     fprintf(archout, "%s", ljust("Ventas FIDE:",20));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subfide_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",   subproyfid_z), 13));
     fprintf(archout, "%s", cjust(" ",6));
     fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subrelfide_z), 13));
     salta_linea();
   }

   subtotimporte_z = subtotconta_z + subtotcred_z + subfona_z + subfide_z;
   subtotcostos_z = subproycon_z + subproycrd_z + subproyfon_z + subproyfid_z;
   subtotreal_z = subrelfon_z + subrelfide_z + subrelcyc_z + subrelcont_z;



   salta_linea();
   fprintf(archout, "%s", cjust(" ",11 ));
   fprintf(archout, "%s", rjust("Total de Ventas:",16));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subtotimporte_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subtotcostos_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout,"%s", rjust(FormatFloat("###,##0.00", subtotreal_z), 13));
   salta_linea();
   salta_linea();

   submub_z = ( subtotreal_z / subtotimporte_z  ) * 100;
   subresultados_z = subtotimporte_z - subtotreal_z;
   submubsrel_z = 100 - submub_z;
   fprintf(archout, "%s", cjust(" ",10 ));
   fprintf(archout, "%s", rjust("Costo de Ventas Real:",22));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subtotreal_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", submub_z) + "%", 13));
   salta_linea();

   fprintf(archout, "%s", cjust(" ",10 ));fprintf(archout, "%s", rjust("Ventas Brutas:",22));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subtotimporte_z), 13));
   salta_linea();
   salta_linea();


   fprintf(archout, "%s", cjust(" ",11 ));
   fprintf(archout, "%s", rjust("Resultados:",12));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", subresultados_z), 13));
   fprintf(archout, "%s", rjust("Igual a Un ",12));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", submubsrel_z) + "%", 7));
   fprintf(archout, "%s", rjust(" M.U.B",6));
   salta_linea();
   salta_linea();

   totgenconta_z   += subtotconta_z;
   totgenproycon_z += subproycon_z;
   totgencred_z    += subtotcred_z;
   totgenproycrd_z += subproycrd_z;
   totgenfona_z    += subfona_z;
   totgenproyfon_z += subproyfon_z;
   totgenfide_z    += subfide_z;
   totgenproyfid_z += subproyfid_z;

   totgenrelconta_z += subrelcont_z;
   totgenrelcred_z += subrelcyc_z;
   totgenrelfona_z += subrelfon_z;
   totgenrelfide_z += subrelfide_z;

   subtotconta_z = subproycon_z = subtotcred_z = subproycrd_z = 0;
   subfona_z = subproyfon_z = subfide_z = subproyfid_z = subrelcont_z = 0;
   subrelcyc_z = subrelfon_z = subrelfide_z = 0;
   report_zona(zonapy_z,nombrezon_z);  //antdescrii


}
//---------------------------------------------------------------------------
void __fastcall TForm_proycom::total_ventas(double totimporte_z, double totcostos_z, double mub_z, double totcostoreal_z)
{

   real_z = (totcostoreal_z / totimporte_z) * 100;
   mub_z = 100 - real_z ;
   resultado_z = totimporte_z - totcostoreal_z;


   salta_linea();
   fprintf(archout, "%s", cjust(" ",11 ));
   fprintf(archout, "%s", rjust("Total de Ventas:",16));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totimporte_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totcostos_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout,"%s", rjust(FormatFloat("###,##0.00", totcostoreal_z), 13));
   salta_linea();
   salta_linea();
   fprintf(archout, "%s", cjust(" ",10 ));
   fprintf(archout, "%s", rjust("Costo de Ventas Real:",22));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totcostoreal_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", real_z) + "%", 13));
   salta_linea();
   fprintf(archout, "%s", cjust(" ",10 ));fprintf(archout, "%s", rjust("Ventas Brutas:",22));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totimporte_z), 13));
   salta_linea();
   salta_linea();
   fprintf(archout, "%s", cjust(" ",11 ));
   fprintf(archout, "%s", rjust("Resultados:",12));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", resultado_z), 13));
   fprintf(archout, "%s", rjust("Igual a Un ",12));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", mub_z) + "%", 7));
   fprintf(archout, "%s", rjust(" M.U.B",6));
   salta_linea();
   salta_linea();


}
//---------------------------------------------------------------------------
void __fastcall TForm_proycom::report_encab()
{
  String tit1_z,inf_z,nombre_z,numero_z,opc_z,cod_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );

  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_proycom " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s\n",cjust("INFORME DE DIRECCION",45));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s\n", cjust("DEL " +
  FormatDateTime("dd/mm/yyyy",
  date_fecini->Date) + "  " + " Al " +
  FormatDateTime("dd/mm/yyyy",date_fecfin->Date ),45));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout, "%s\n",cjust("PROYECCION DE COSTOS Y COMPARACION CON LOS REALES",100));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
   if(rbtn_fona->Checked){
      fprintf(archout, "%s\n",cjust("FONACOT",30));
       fona_z = "F";
   }else if (rbtn_ime->Checked){
      fprintf(archout, "%s\n",cjust("IMEVI",30));
       imevi_z = "V";
   }else if (rbtn_menu->Checked){
      fprintf(archout, "%s\n",cjust("MENUDEO",30));
       menudeo_z = "M";
   }else if (rbtn_fide->Checked){
      fprintf(archout, "%s\n",cjust("FIDE",30));
       fide_z = "I";
   }else if (rbtn_total->Checked){
      fprintf(archout, "%s\n",cjust("FONACOT  IMEVI  Y  MENUDEO",45));
      fide_z = "T";
   }
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
   salta_linea();
   report_zona(antzona_z,nombrezon_z);
   //report_subzona(subzonpy_z,descripy_z);
   //encab1();
   lineas_z = 6;

}
//---------------------------------------------------------------------------

void __fastcall TForm_proycom::report_zona(String zonapy_z, String nombrezon_z)
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s",ljust("ZONA:" + zonapy_z + " " + nombrezon_z ,30));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  salta_linea();

}
//---------------------------------------------------------------------------

void __fastcall TForm_proycom::report_subzona(String subzonpy_z, String descripy_z)
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s",ljust(subzonpy_z + " " + descripy_z,40));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_proycom::report_subtotalzona(String zonapy_z, String nombrezon_z)
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s",ljust("Subtotal de Zona:" + zonapy_z + " " + nombrezon_z ,40));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  salta_linea();

}
//---------------------------------------------------------------------------
void __fastcall TForm_proycom::encab1()
{

   fprintf(archout, "%s|", cjust(" ",25 ));
   fprintf(archout, "%s|", cjust("Impor.Ventas",13));
   fprintf(archout, "%s|", cjust("%Proy", 5 ));
   fprintf(archout, "%s|", cjust("Costos  Proy.",13));
   fprintf(archout, "%s|", cjust("%Real",5));
   fprintf(archout, "%s|", cjust("Costo Real",13));
   salta_linea();


}
//---------------------------------------------------------------------------
void __fastcall TForm_proycom::total_generales()
{

   salto_z = true;
   checa_saltopag(12);


   subreal_z = 0;
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
   fprintf(archout, "%s",ljust("Total General de Zonas",30));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
   salta_linea();
   salta_linea();

   fprintf(archout, "%s", ljust(" ",7));
   fprintf(archout, "%s", ljust("Ventas al Contado:",20));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenconta_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  totgenproycon_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenrelconta_z), 13));
   salta_linea();

   fprintf(archout, "%s", ljust(" ",7));
   fprintf(archout, "%s", ljust("Ventas a Credito:",20));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgencred_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  totgenproycrd_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenrelcred_z), 13));
   salta_linea();

   fprintf(archout, "%s", ljust(" ",7));
   fprintf(archout, "%s", ljust("Ventas FONACOT:",20));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenfona_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",  totgenproyfon_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenrelfona_z), 13));
   salta_linea();

   fprintf(archout, "%s", ljust(" ",7));
   fprintf(archout, "%s", ljust("Ventas FIDE:",20));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenfide_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",   totgenproyfid_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00",totgenrelfide_z), 13));
   salta_linea();

   totgenventan_z = totgenfide_z + totgenfona_z + totgenconta_z + totgencred_z;
   totgencostos_z = totgenproycon_z + totgenproycrd_z +totgenproyfon_z + totgenproyfid_z;
   togentsubmub_z = ((totgenventan_z - subreal_z) / totgenventan_z) * 100;
   totgenreal2_z =  totgenrelconta_z+totgenrelcred_z+totgenrelfona_z+totgenrelfide_z;

   totreal3_z = (totgenreal2_z / totgenventan_z ) * 100;
   togentsubmub_z = 100 - totreal3_z;

   salta_linea();
   fprintf(archout, "%s", cjust(" ",11 ));
   fprintf(archout, "%s", rjust("Total de Ventas:",16));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenventan_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgencostos_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout,"%s", rjust(FormatFloat("###,##0.00", totgenreal2_z), 13));
   salta_linea();
   salta_linea();


   fprintf(archout, "%s", cjust(" ",10 ));
   fprintf(archout, "%s", rjust("Costo de Ventas Real:",22));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenreal2_z), 13));
   fprintf(archout, "%s", cjust(" ",6));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totreal3_z) + "%", 13));
   salta_linea();

   fprintf(archout, "%s", cjust(" ",10 ));fprintf(archout, "%s", rjust("Ventas Brutas:",22));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenventan_z), 13));
   salta_linea();
   salta_linea();

   lineas_z += 1;
   fprintf(archout, "%s", cjust(" ",11 ));
   fprintf(archout, "%s", rjust("Resultados:",12));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", totgenventan_z), 13));
   fprintf(archout, "%s", rjust("Igual a Un ",12));
   fprintf(archout, "%s", rjust(FormatFloat("###,##0.00", togentsubmub_z) + "%", 7));
   fprintf(archout, "%s", rjust(" M.U.B",6));
   salta_linea();
   salta_linea();



}
//---------------------------------------------------------------------------
void __fastcall TForm_proycom::suma_anual(String tipoent_z,String suboglo_z, String menudeo_z,String zona_z, String ptvta_z, bool tip_z)
{

 String almadx_z;
 int idtipocar_z,iva_z;
 double contado_z,credito_z,credycont_z;
 fecini_z = date_fecini->Date;
 fecfin_z = date_fecfin->Date;

 qry_ubivtas->Close();
 qry_ubivtas->ParamByName("PTVA"  )->AsString  = ptvta_z;
 qry_ubivtas->ParamByName("ZONA")->AsString =  zona_z;
 qry_ubivtas->Open();
 iva_z = 16;

   for(qry_ubivtas->First(); !qry_ubivtas->Eof; qry_ubivtas->Next()) {

      almadx_z =  qry_ubivtas->FieldByName("alm")->AsString;
      ptvtaa_z =  qry_ubivtas->FieldByName("pvta")->AsString;

         if(suboglo_z == "S"){
             qry_tabcvta->Close();
             qry_tabcvta->ParamByName("IVA")->AsInteger = iva_z;
             qry_tabcvta->ParamByName("ALM"  )->AsString  =  almadx_z;
             qry_tabcvta->ParamByName("PTVA" )->AsString  = ptvtaa_z;
             qry_tabcvta->ParamByName("FECINI")->AsDateTime =  fecini_z;
             qry_tabcvta->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
             qry_tabcvta->ParamByName("CIA" )->AsInteger  = cia_z;
             qry_tabcvta->ParamByName("TIPOENT"  )->AsString  = tipoent_z;
             qry_tabcvta->Open();


             contado_z = qry_tabcvta->FieldByName("contado")->AsFloat;
             credito_z = qry_tabcvta->FieldByName("credito")->AsFloat;
             credycont_z = qry_tabcvta->FieldByName("sumas")->AsFloat;

             if (menudeo_z == "M" && tipoent_z =="V" ){
               if( tip_z == true){
                 costrealcont_z += contado_z ;
                 costrealcyc_z +=  credito_z;
               }else{
                 costrealcyc_z +=  credito_z;
               }

             }else if ( menudeo_z == "F" ){
                costrealfon_z += credycont_z ;
             }else if ( menudeo_z == "I" ){
                costrealfide_z += credycont_z ;
             }

             costreal_z += costrealcont_z + costrealcyc_z + costrealfon_z + costrealfide_z;

         }else{
             qry_tabcvta2->Close();
             qry_tabcvta2->ParamByName("IVA")->AsInteger = iva_z;
             qry_tabcvta2->ParamByName("ALM"  )->AsString  =  almadx_z;
             qry_tabcvta2->ParamByName("FECINI")->AsDateTime =  fecini_z;
             qry_tabcvta2->ParamByName("FECFIN"  )->AsDateTime  = fecfin_z;
             qry_tabcvta2->ParamByName("CIA" )->AsInteger  = cia_z;
             qry_tabcvta2->ParamByName("TIPOENT"  )->AsString  = tipoent_z;
             qry_tabcvta2->Open();

             contado_z = qry_tabcvta2->FieldByName("contado")->AsFloat;
             credito_z = qry_tabcvta2->FieldByName("credito")->AsFloat;
             credycont_z = qry_tabcvta2->FieldByName("sumas")->AsFloat;

            if (menudeo_z == "M" && tipoent_z =="V" ){
               if( tip_z == true){
                 costrealcont_z += contado_z ;
                 costrealcyc_z +=  credito_z;
               }else{
                 costrealcyc_z +=  credito_z;
               }

             }else if ( menudeo_z == "F" ){
                costrealfon_z +=  credycont_z;
             }else if ( menudeo_z == "I" ){
                costrealfide_z +=  credycont_z;
             }

             costreal_z += costrealcont_z + costrealcyc_z + costrealfon_z + costrealfide_z;

         }
   }
   tip_z = false;
 }

//---------------------------------------------------------------------------
void __fastcall TForm_proycom::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_proycom::date_feciniExit(TObject *Sender)
{
   date_fecfin->Date = UltimoDiaMes(date_fecini->Date);

}
//---------------------------------------------------------------------------

void __fastcall TForm_proycom::salta_linea()
{
  fprintf(archout, "\n");
  lineas_z++;
}
//---------------------------------------------------------------------------

bool __fastcall TForm_proycom::checa_saltopag(int numero_de_lineas)
{
  bool haysalto_z = false;
  if(lineas_z > ( LINEAS_X_PAG - numero_de_lineas) ) {
    fprintf(archout, "%c", 12); pagina_z++;

    report_encab();
    //report_zona(antzona_z,antdescri_z);
    if (salto_z == true){
     //report_subzona(subzonpy_z,descripy_z);
     //encab1();
    }

    
    haysalto_z = true;
    salto_z = false;
  }
  return(haysalto_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_proycom::reporte_proycomExecute(TObject *Sender)
{
 genera_reporte();
}
//---------------------------------------------------------------------------

