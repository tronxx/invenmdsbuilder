//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Frm_exiubi.h"
#include "numapal.h"
#include "situaciones.h"
#include "dmod.h"
#include "imprigra.h"
#include "math.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_exiubi *Form_exiubi;
const int LINEAS_X_PAG = 60;
//---------------------------------------------------------------------------
__fastcall TForm_exiubi::TForm_exiubi(TComponent* Owner)
        : TForm(Owner)
{
   date_ini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
   cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::mensajes()
{

  if (rbtn_exisi->Checked){
   drv_z = "Mercancia SI ";
  }else if (rbtn_exino->Checked){
   drv_z = "Mercancia NO ";
  }else if (rbtn_exitot->Checked){
   drv_z = "Mercancia TOTAL ";
  }

  if (rbtn_imptod->Checked){
   dad_z = "SIN IMPORTAR EL COSTO";
  }else if (rbtn_impcostc->Checked){
   dad_z = "SOLO CON COSTO CERO";
  }

  if (rbtn_cancelados->Checked){
   can_z = "Mercancia Con Status de Cancelacion ";
  }else if (rbtn_nocancel->Checked){
   can_z = "Mercancia Sin Status de Cancelacion ";
  }else if (rbtn_todos->Checked){
   can_z = "Mercancia Global Sin importar el Status de Cancelacion ";
  }


}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::report_encab()
{

  almini_z = edt_almini->Text;
  almfin_z = edt_almfin->Text;
  mensajes();
  fprintf(archout, "\n");
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_exiubi " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );
   tit1_z = "ACUMULADO DE EXISTENCIA A ULTIMO COSTO";
   fprintf(archout, "%s\n", cjust( tit1_z, 100));
   fprintf(archout, "%s\n", cjust( " Del Almacen "  + almini_z + " Al Almacen "  + almfin_z +
   " AL " + FormatDateTime("dd/mm/yyyy", date_ini->Date) + " "  + dad_z,100));
   fprintf(archout, "%s\n", cjust(can_z,110));
   fprintf(archout, "\n");
   lineas_z = 9;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exiubi::encab2()
{
   String puntos_z,snt_z,son1_z,son2_z,cnt_z,can1_z,can2_z;
   puntt_z = 0;

   fecha_z = date_ini->Date;

   if(rbtn_exisi->Checked || rbtn_exitot->Checked ){
      son1_z = "S";
   }

   if(rbtn_exino->Checked || rbtn_exitot->Checked ){
      son2_z = "N";
   }

   if(rbtn_cancelados->Checked || rbtn_todos->Checked ){
      can1_z = "S";
   }

    if(rbtn_nocancel->Checked || rbtn_todos->Checked ){
      can2_z = "N";
   }

   qry_agrepuntos->Close();
   qry_agrepuntos->ParamByName("SON1")->AsString = son1_z;
   qry_agrepuntos->ParamByName("SON2")->AsString = son2_z ;
   qry_agrepuntos->ParamByName("CAN1")->AsString = can1_z;
   qry_agrepuntos->ParamByName("CAN2")->AsString = can2_z;
   qry_agrepuntos->ParamByName("PRALM")->AsString = almini_z;
   qry_agrepuntos->ParamByName("ULTALM")->AsString = almfin_z;
   qry_agrepuntos->ParamByName("FECCORT")->AsDateTime = fecha_z;
   qry_agrepuntos->ParamByName("FECCORT")->AsDateTime = fecha_z;
   qry_agrepuntos->ParamByName("CIA")->AsInteger =  cia_z;
   qry_agrepuntos->ExecSQL();

   qry_puntos->Close();
   qry_puntos->Open();
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Descripcion",30));

   for(qry_puntos->First(); !qry_puntos->Eof; qry_puntos->Next()) {
    puntos_z = qry_puntos->FieldByName("almkdx")->AsString;
    fprintf(archout, "%s|", cjust(puntos_z, 4));
    puntt_z++;
   }

   if (rbtn_ccosto->Checked){
     fprintf(archout, "%s|", cjust("Costo Unitario",12));
     fprintf(archout, "%s|", cjust("Total Costo", 12));
   }

   if (rbtn_sitsi->Checked){
     fprintf(archout, "%s ", cjust("Total", 5));
     fprintf(archout, "%s|", cjust("Situacion", 9));
   }else{
     fprintf(archout, "%s|", cjust("Total", 5));
   }

   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   tpunto_z = puntt_z;
   lineas_z += 2;

}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::encab_linea()
{

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust("Linea:" + antlinea_z + " " + antdescrip_z, 50));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  lineas_z += 1;

}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::btn_imprelClick(TObject *Sender)
{

  String alm_z,codigodat_z,descridat_z,lineatmp_z,codigodes_z,
  empaqe_z,proveini_z,provefin_z,lineini_z,linefin_z,situaini_z,situafin_z,
  linea_z,situa_z,descri_z,descrip_z;
  double costodat_z ,totaldat_z,costotot_z,costunid_z;
  int unidat_z,folent_z,puntos_z,totalsem_z;

  sum = new TStringList();
  total = new TStringList();
  cuant_z = 0;
  fecha_z = date_ini->Date;
  lineas_z = 0;
  pagina_z = 1;
  si_z = no_z = false;

  if( rbtn_exisi->Checked == false && rbtn_exino->Checked == false && rbtn_exitot->Checked == false){
       Application->MessageBox("Seleccione SI, No  o Total \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_ccosto->Checked == false && rbtn_scosto->Checked == false ) {
       Application->MessageBox("Seleccione Con Costo o Sin Costo \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_imptod->Checked == false && rbtn_impcostc->Checked == false ){
       Application->MessageBox("Seleccione Todos, Con Costo Cero  \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_cancelados->Checked == false && rbtn_nocancel->Checked == false && rbtn_todos->Checked == false ){
       Application->MessageBox("Seleccione Cancelados, No Cancelados o Todos  \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_sitsi->Checked == false && rbtn_sitno->Checked == false ){
       Application->MessageBox("Seleccione SI o NO \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if ( edt_almfin->Text == "" ){
       Application->MessageBox("Ingrese los Almacenes \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (edt_linefin->Text == "" ){
       Application->MessageBox("Ingrese las Lineas \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (edt_sitfin->Text == "" ){
       Application->MessageBox("Ingrese La Situacion \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (edt_provfin->Text == "" ){
       Application->MessageBox("Ingrese Los Proveedores \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }


   if(Application->MessageBox("Seguro imprimir Reporte ?", "Impresión Reporte", MB_OKCANCEL) != IDOK ) return;
   arch_z = "frm_exiubi.txt";
   if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
   }


  proveini_z = edt_provini->Text;
  provefin_z = edt_provfin->Text;
  lineini_z = edt_lineini->Text;
  linefin_z = edt_linefin->Text;
  situaini_z = edt_sitini->Text;
  situafin_z = edt_sitfin->Text;

  qry_lineas->Close();
  qry_lineas->ParamByName("PROVEINI")->AsString = proveini_z;
  qry_lineas->ParamByName("PROVEFIN")->AsString = provefin_z;
  qry_lineas->ParamByName("LINEINI")->AsString = lineini_z;
  qry_lineas->ParamByName("LINEFIN")->AsString = linefin_z;
  qry_lineas->ParamByName("CIA")->AsInteger = cia_z;
  qry_lineas->Open();

  for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {

     linea_z = qry_lineas->FieldByName("numero")->AsString;
     descrip_z = qry_lineas->FieldByName("descri")->AsString;

     if(lineas_z == 0){
         antlinea_z = linea_z;
         antdescrip_z = descrip_z;
         report_encab();
         encab_linea();
         encab2();
      }

     if (antlinea_z != linea_z){
        antlinea_z = linea_z;
        antdescrip_z = descrip_z;
        total_linea();
        checa_saltopag(12);
        encab_linea();
        encab2();


     }

     qry_inven->Close();
     qry_inven->ParamByName("LINEA")->AsString = linea_z;
     qry_inven->ParamByName("SITUAINI")->AsString = situaini_z;
     qry_inven->ParamByName("SITUAFIN")->AsString = situafin_z;
     qry_inven->ParamByName("PROVEINI")->AsString = proveini_z;
     qry_inven->ParamByName("PROVEFIN")->AsString = provefin_z;
     qry_inven->ParamByName("CIA")->AsInteger = cia_z;
     qry_inven->Open();

     for(qry_inven->First(); !qry_inven->Eof; qry_inven->Next()) {
         codigo_z = qry_inven->FieldByName("codigo")->AsString;
         descri_z = qry_inven->FieldByName("descri")->AsString;
         costunid_z = qry_inven->FieldByName("costos")->AsFloat;
         piva_z = qry_inven->FieldByName("piva")->AsFloat;
         situa_z = qry_inven->FieldByName("empaqe")->AsString;



         qry_puntos->Close();
         qry_puntos->Open();

        /////////////
         if ( rbtn_cancelados->Checked || rbtn_todos->Checked ){
           entcan_z = "S";
             if( rbtn_exisi->Checked || rbtn_exitot->Checked ){
               moden_z = "S";
               si_z = true;
               buscar_exits();
             }

             if( rbtn_exino->Checked|| rbtn_exitot->Checked ){
               moden_z = "N";
               no_z = true;
               buscar_exits();
             }

         }

         if ( rbtn_nocancel->Checked || rbtn_todos->Checked ){
           entcan_z = "N";
             if( rbtn_exisi->Checked || rbtn_exitot->Checked ){
                 moden_z = "S";
                  si_z = true;
                 buscar_exits();

             }

             if( rbtn_exino->Checked|| rbtn_exitot->Checked ){
               moden_z = "N";
                no_z = true;
               buscar_exits();
             }
         }
        ////////////

       if (exitsi_z > 0 || exitno_z > 0){
           fprintf(archout, "%s|", ljust(descri_z, 30));

           sumar_exits();
           costos_sino(codigo_z);

           totcost_z =  exitsi_z * ((costosi_z * (piva_z /100)) + costosi_z) + exitno_z * costono_z;
           costunid_z = totcost_z / totunid_z;

           fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",costunid_z), 12));
           fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",totcost_z ),12 ));
           fprintf(archout, "%s ", rjust(FormatFloat("0",totunid_z), 4));
           fprintf(archout, "%s|\n", ljust(situa_z,9));
           lineas_z += 1;
           cuant_z = 0;
           
           gtotunid_z += totunid_z;
           gtotcost_z += totcost_z;
           totunid_z = 0;
           exitsi_z = exitno_z = 0;
           checa_saltopag(12);
       }

     }

  }
  total_linea();
  total_gen();
  total->Clear();
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::sumar_exits()
{
    String strunida_z;
    strunida_z = "";

    for(qry_puntos->First(); !qry_puntos->Eof; qry_puntos->Next()) {
        ptvta_z = qry_puntos->FieldByName("almkdx")->AsString;

         if ( rbtn_cancelados->Checked || rbtn_todos->Checked ){
           entcan_z = "S";
             if( rbtn_exisi->Checked || rbtn_exitot->Checked ){
               moden_z = "S";
               armar();

             }

             if( rbtn_exino->Checked|| rbtn_exitot->Checked ){
               moden_z = "N";
               armar();

             }

         }

         if ( rbtn_nocancel->Checked || rbtn_todos->Checked ){
           entcan_z = "N";
             if( rbtn_exisi->Checked || rbtn_exitot->Checked ){
               moden_z = "S";
               armar();

             }

             if( rbtn_exino->Checked|| rbtn_exitot->Checked ){
               moden_z = "N";
               armar();

             }
         }

          if (unidades_z) strunida_z = rjust(FormatFloat("0",unidades_z ),4 );
           sum->Append("0");
           total->Append("0");
           fprintf(archout, "%s|", ljust(strunida_z, 4));
           totalunid_z += unidades_z;

           misuma_z = StrToInt(sum->Strings[cuant_z]);
           misuma2_z = StrToInt(total->Strings[cuant_z]);
           misuma_z += unidades_z;
           misuma2_z += unidades_z;

           sum->Strings[cuant_z] = FormatFloat("0", misuma_z);
           total->Strings[cuant_z] = FormatFloat("0", misuma2_z);
           totunid_z += unidades_z;
           cuant_z++;
           unidades_z = 0;

           strunida_z = "";

    }

}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::armar()
{

  qry_armar->Close();
  qry_armar->ParamByName("MODEN")->AsString = moden_z;
  qry_armar->ParamByName("COD")->AsString = codigo_z;
  qry_armar->ParamByName("FECHA")->AsDateTime = fecha_z;
  qry_armar->ParamByName("ALM")->AsString = ptvta_z;
  qry_armar->ParamByName("FECHA")->AsDateTime= fecha_z;
  qry_armar->ParamByName("ENTCAN")->AsString = entcan_z;
  qry_armar->ParamByName("CIA")->AsInteger = cia_z;
  qry_armar->Open();

  for(qry_armar->First(); !qry_armar->Eof; qry_armar->Next()) {

     unidades_z += qry_armar->FieldByName("unids")->AsFloat;
  }

}

//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::total_linea()
{
  int sumas_z;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total de Esta Linea:", 30));
  for( int ii_z=0; ii_z < puntt_z; ii_z++) {
     sumas_z = StrToFloat(sum->Strings[ii_z]);
     fprintf(archout, "%s|", rjust(FormatFloat("0", sumas_z), 4));
  }

  gtotresult_z  = gtotcost_z / gtotunid_z;

  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", gtotresult_z),12 ));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", gtotcost_z),12 ));
  fprintf(archout, "%s\n", rjust(FormatFloat("0", gtotunid_z ),4 ));
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z += 1;
  ii_z = 0;
  puntt_z = 0;
  ggtotcost_z += gtotcost_z;
  ggtotunid_z += gtotunid_z;
  gtotunid_z = gtotcost_z = gtotresult_z = 0;
  lineas_z += 2;

  sum->Clear();
  sum = new TStringList();

}
//---------------------------------------------------------------------------

bool __fastcall TForm_exiubi::checa_saltopag(int numero_de_lineas)
{
  bool haysalto_z = false;

  if(lineas_z > ( LINEAS_X_PAG - numero_de_lineas) ) {
    fprintf(archout, "%c", 12); pagina_z++;

    report_encab();
    encab_linea();
    encab2();
    haysalto_z = true;
    
  }

  return(haysalto_z);
}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::total_gen()
{
  int sumas_z;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Total General:", 30));
  for( int ii_z=0; ii_z < tpunto_z; ii_z++) {
     sumas_z = StrToFloat(total->Strings[ii_z]);
     fprintf(archout, "%s|", rjust(FormatFloat("0", sumas_z), 4));
  }

  fprintf(archout, "%s|", cjust(" ", 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", ggtotcost_z),12 ));
  fprintf(archout, "%s\n", rjust(FormatFloat("0", ggtotunid_z ),4 ));
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z += 1;
  ii_z = 0;
  puntt_z = 0;
  ggtotcost_z = ggtotunid_z  = 0;
  lineas_z += 2;

  delete total;
  total = new TStringList();


}
//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::costos_sino(String codigo)
{

  qry_invulcos->Close();
  qry_invulcos->ParamByName("CODIGO")->AsString = codigo_z;
  qry_invulcos->ParamByName("CIA")->AsInteger = cia_z;
  qry_invulcos->ParamByName("FECORTE")->AsDateTime = fecha_z;
  qry_invulcos->Open();

  for(qry_invulcos->First(); !qry_invulcos->Eof; qry_invulcos->Next()) {
     costosi_z = qry_invulcos->FieldByName("si")->AsFloat;
     costono_z = qry_invulcos->FieldByName("no")->AsFloat;
  }

}

//--------------------------------------------------------------------------
void __fastcall TForm_exiubi::buscar_exits()
{


  qry_exists->Close();
  qry_exists->ParamByName("MODEN")->AsString = moden_z;
  qry_exists->ParamByName("COD")->AsString = codigo_z;
  qry_exists->ParamByName("FECHA")->AsDateTime = fecha_z;
  qry_exists->ParamByName("ALMINI")->AsString = almini_z;
  qry_exists->ParamByName("ALMFIN")->AsString = almfin_z;
  qry_exists->ParamByName("FECHA")->AsDateTime= fecha_z;
  qry_exists->ParamByName("ENTCAN")->AsString = entcan_z;
  qry_exists->ParamByName("CIA")->AsInteger = cia_z;
  qry_exists->Open();

  for(qry_exists->First(); !qry_exists->Eof; qry_exists->Next()) {

    if (si_z == true){

       exitsi_z += qry_exists->FieldByName("unids")->AsFloat;

    }else if (no_z == true){

       exitno_z += qry_exists->FieldByName("unids")->AsFloat;
    }

  }
  
  si_z = false;
  no_z = false;
}

//---------------------------------------------------------------------------
void __fastcall TForm_exiubi::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------

