//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>

#include "Frm_listpre2.h"
#include "imprigra.h"
#include "numapal.h"
#include "dmod.h"
#include "situaciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
const int MAX_LINEAS = 60;
TForm_listpre2 *Form_listpre2;
//---------------------------------------------------------------------------
__fastcall TForm_listpre2::TForm_listpre2(TComponent* Owner)
        : TForm(Owner)
{
   qry_linea->Close();
   qry_linea->Open(); 
   qry_remates->Close();
   qry_remates->Open();
   date_vigencia->Date = PrimerDiaMes(dm->ahora());
   date_corte->Date = PrimerDiaMes(dm->ahora());


}
//---------------------------------------------------------------------------

void __fastcall TForm_listpre2::report_encab()
{

  String tit1_z;
  fprintf(archout, "\n");
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_listpre2 " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );
   tit1_z = "Lista de Precios Iva Incluidos ";
   fprintf(archout, "%s", ljust( tit1_z,31));
   fprintf(archout, "%s\n", ljust( " Vigentes a Partir del "  + FormatDateTime("dd/mm/yyyy",
   date_vigencia->Date),60));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
   fprintf(archout, "%s", cjust( "LISTA UNICA",40));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
   dm->font_impre(dm->impre_z, CONDENSADO_ON),
   fprintf(archout, "\n");
   lineas_z = 5;
}
//---------------------------------------------------------------------------

void __fastcall TForm_listpre2::encab_linea(String antlineatmp_z, String antnombrelinea_z)
{
  fprintf(archout, "\n");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust("Linea:" + antlineatmp_z + " " + antnombrelinea_z, 50));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  lineas_z += 1;
}
//---------------------------------------------------------------------------
void __fastcall TForm_listpre2::encab_obser()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust("Observaciones:", 30));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", cjust("LISTA UNICA:", 40));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));

  lineas_z += 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm_listpre2::FormCreate(TObject *Sender)
{
   cia_z = dm->cia_z;
   leer_o_grabar_ini("LEER");

}
//---------------------------------------------------------------------------

void __fastcall TForm_listpre2::agregar_datos()
{
    String lineafin_z,situaini_z,situafin_z,codini_z,codfin_z,
    codigo_z,cod2_z,descri_z,linea_z,empaqe_z,tipo_z,empaqetmp_z,sqll_z;
    double costos_z,piva_z,precelec_z,precio_z;
    int ciatmp_z,dato_z;
    TDateTime fechacort_z;
    //Eliminamos inventmp
    qry_delete->Close();
    qry_delete->ExecSQL();
    sqll_z = " select * from inventmp ";
    qry_inventmp->SQL->Text = sqll_z;
    qry_inventmp->Close();
    qry_inventmp->Open();

    /////
    lineaini_z = lkcmb_lineaini->KeyValue;
    lineafin_z = lkcmb_lineafin->KeyValue;
    situaini_z = lkcmb_rematini->KeyValue;
    situafin_z = lkcmb_rematfin->KeyValue;
    codini_z = edt_codini->Text;
    codfin_z = edt_codfin->Text;


    sql_z = " select a.codigo,cod2,a.descri,a.tipo,a.costos,a.linea,a.piva, ";
    sql_z += " a.precio,a.precelec,a.empaqe,b.orden,e.codigo as grupo ";
    sql_z += " from inven a join lineas b on a.linea=b.numero and a.cia=b.cia ";
    sql_z += " join inv_invhist c on a.codigo = c.codigo and a.cia = c.cia ";
    sql_z += " join inv_relinv d on c.idart = d.idart and idrel = 1 ";
    sql_z += " join inv_grupos e on d.iddato = e.idgrupo where ";
    sql_z += " a.linea between :LINEAINI and :LINEAFIN ";
    if(rbtn_mesta->Checked){
       sql_z += " and a.empaqe not between :SITUAINI and :SITUAFIN ";
    }else if (rbtn_estas->Checked){
       sql_z += " and a.empaqe  between :SITUAINI and :SITUAFIN ";
    }
    sql_z += " and a.codigo between :CODINI and :CODFIN and a.cia= 1 ";
    qry_inven->SQL->Text = sql_z;
     //Agregos los campos datos en inventmp
    qry_inven->Close();
    qry_inven->ParamByName("lineaini")->AsString = lineaini_z;
    qry_inven->ParamByName("lineafin")->AsString = lineafin_z;
    qry_inven->ParamByName("situaini")->AsString = situaini_z ;
    qry_inven->ParamByName("situafin")->AsString = situafin_z;
    qry_inven->ParamByName("codini")->AsString = codini_z;
    qry_inven->ParamByName("codfin")->AsString = codfin_z ;
    qry_inven->Open();
    qry_inven->DisableControls();
    TProgressBar *ProgressBar1 = new TProgressBar (this);
    ProgressBar1->Parent = pnl_datos;
    ProgressBar1->Step = 1;
    ProgressBar1->Height = 18;
    ProgressBar1->Align = alBottom;
    ProgressBar1->Min = 0;
    ProgressBar1->Max = qry_inven->RecordCount;


    for(qry_inven->First(); !qry_inven->Eof; qry_inven->Next()) {

      ProgressBar1->StepIt();
      codigo_z = qry_inven->FieldByName("codigo")->AsString;
      cod2_z = qry_inven->FieldByName("cod2")->AsString;
      descri_z = qry_inven->FieldByName("descri")->AsString;
      costos_z = qry_inven->FieldByName("costos")->AsFloat;
      linea_z = qry_inven->FieldByName("linea")->AsString;
      piva_z = qry_inven->FieldByName("piva")->AsFloat;
      precio_z = qry_inven->FieldByName("precio")->AsFloat;
      precelec_z = qry_inven->FieldByName("precelec")->AsFloat;
      empaqe_z = qry_inven->FieldByName("empaqe")->AsString;
      tipo_z = qry_inven->FieldByName("tipo")->AsString;


      qry_inventmp->Append();
      qry_inventmp->FieldByName("CODIGO")->AsString = codigo_z;
      qry_inventmp->FieldByName("DESCRI")->AsString = descri_z;
      qry_inventmp->FieldByName("TIPO")->AsString = tipo_z;
      qry_inventmp->FieldByName("COSTOS")->AsFloat = costos_z;
      qry_inventmp->FieldByName("LINEA")->AsString = linea_z;
      qry_inventmp->FieldByName("PIVA")->AsFloat = piva_z;
      qry_inventmp->FieldByName("PRECIO")->AsFloat = precio_z;
      qry_inventmp->FieldByName("PRECELEC")->AsFloat = precelec_z;
      qry_inventmp->FieldByName("EMPAQE")->AsString = empaqe_z;
      qry_inventmp->FieldByName("COD2")->AsString = cod2_z;
      qry_inventmp->FieldByName("CIA")->AsString = cia_z;
      qry_inventmp->Post();
      try
      {
         dm->manvehi->StartTransaction();
         qry_inventmp->ApplyUpdates();
         dm->manvehi->Commit();
      }
      catch(...)
      {
         dm->manvehi->Rollback();
         Application->MessageBox("NO FUE POSIBLE AGREGAR REGISTRO", "Error", MB_OK | MB_ICONERROR);
      }
    }
    sql_z = "";
    qry_inven->EnableControls();
    delete ProgressBar1;
  //Datos Agragados

}
//---------------------------------------------------------------------------
void __fastcall TForm_listpre2::encab2()
{
   if(rbtn_cost->Checked){
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   } else {
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
   }
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("--------Descripcion--------",28 ));
   fprintf(archout, "%s|", cjust("Gtia",4));
   if(antlineatmp_z != "xBLCA" || antlineatmp_z != "xVIDE" || antlineatmp_z != "xANTE" ) {
     if(rbtn_cprec->Checked){
       fprintf(archout, "%s|", cjust("P.LISTA",10 ));
       fprintf(archout, "%s|", cjust("Max", 4));
       fprintf(archout, "%s|", cjust("P.CONTADO", 10));
     }else{
       fprintf(archout, "%s|", cjust("P.LISTA",10 ));
       fprintf(archout, "%s|", cjust("Max", 4));
     }
   }else{
     fprintf(archout, "%s|", cjust("P.LISTA",10 ));
     fprintf(archout, "%s|", cjust("Max", 4));
   }
   fprintf(archout, "%s|", cjust("Condicion", 10));
    if(rbtn_cost->Checked){
       fprintf(archout, "%s|", cjust("Costo Neto", 10));
       fprintf(archout, "%s|", cjust("M.U.B", 5));
    }
   if(!rbtn_cost->Checked){
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   }
   fprintf(archout, "%s|",cjust("------Caracteristicas-----", 25));

   if(!rbtn_cost->Checked){
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
   }
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));

   lineas_z += 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm_listpre2::imprimir_renglon(String descritmp_z, String clavegrt_z,
                double preciolta_z, int plazoxpr_z, String empaqetmp,
                double costoneto_z, double mub_z, String caractetist_z,
                double preciotmp_z, String conext_z)
{
   if(rbtn_cost->Checked){
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   } else {
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
   }
   fprintf(archout, "|");
   fprintf(archout, "%s|", ljust(descritmp_z, 27));
   fprintf(archout, "%s%s|", ljust(clavegrt_z, 3), ljust(conext_z,1));
   if(antlineatmp_z != "xBLCA" || antlineatmp_z != "xVIDE" || antlineatmp_z != "xANTE"){
     if(rbtn_cprec->Checked){
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",preciolta_z ),10 ));
       fprintf(archout, "%s|", rjust(FormatFloat("0",plazoxpr_z*2), 2)+ " Q");
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",preciotmp_z ),10 ));
     }else{
      fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",preciolta_z ),10 ));
      fprintf(archout, "%s|", rjust(FormatFloat("0",plazoxpr_z*2), 2)+ " Q");
     }
   } else {
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",preciolta_z ),10 ));
     fprintf(archout, "%s|", rjust(FormatFloat("0",plazoxpr_z*2), 2)+ " Q");
   }
   fprintf(archout, "%s|", ljust(empaqetmp ,10 ));
   if(rbtn_cost->Checked){
      fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",costoneto_z), 10));
      fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",mub_z), 5));
   }
   if(!rbtn_cost->Checked){
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   }
   fprintf(archout, "%s|", ljust(caractetist_z, 25));
   if(!rbtn_cost->Checked){
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
   }
   fprintf(archout, "\n");
   lineas_z += 1;
}
//---------------------------------------------------------------------------

int __fastcall TForm_listpre2::busca_plazo(String codigo_z, String linea_z, String grupo_z, double precio_z)
{
  int plazo_z=0, tipopzo_z=0, plazolin_z=0;
  bool buscaotro_z = true;
  qry_plazoxarticulo->Close();
  qry_plazoxarticulo->ParamByName("codigo")->AsString = codigo_z;
  qry_plazoxarticulo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_ARTICULO;
  qry_plazoxarticulo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxarticulo->Open();
  if(!qry_plazoxarticulo->IsEmpty()) {
    plazo_z = qry_plazoxarticulo->FieldByName("plazomax")->AsInteger;
    return (plazo_z);
  }
  qry_plazoxgrupo->Close();
  qry_plazoxgrupo->ParamByName("codigo")->AsString = grupo_z;
  qry_plazoxgrupo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_GRUPO_PRIORIDAD;
  qry_plazoxgrupo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxgrupo->Open();
  if(!qry_plazoxgrupo->IsEmpty()) {
    plazo_z = qry_plazoxgrupo->FieldByName("plazomax")->AsInteger;
    return (plazo_z);
  }
  qry_plazoxlin->Close();
  qry_plazoxlin->ParamByName("linea")->AsString = linea_z;
  qry_plazoxlin->ParamByName("tipo")->AsInteger = TIPO_PLAZO_LINEA_PRIORIDAD;
  qry_plazoxlin->ParamByName("tipo4")->AsInteger = TIPO_PLAZO_LINEA_X_TABLA;
  qry_plazoxlin->ParamByName("tipo2")->AsInteger = TIPO_PLAZO_LINEA_X_GRUPO;
  qry_plazoxlin->ParamByName("tipo3")->AsInteger = TIPO_PLAZO_X_GRUPOX_TABLA;
  qry_plazoxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxlin->Open();
  if(!qry_plazoxlin->IsEmpty()) {
    plazo_z = qry_plazoxlin->FieldByName("plazomax")->AsInteger;
    tipopzo_z = qry_plazoxlin->FieldByName("tipo")->AsInteger;
    plazolin_z = plazo_z;
    if(tipopzo_z == TIPO_PLAZO_LINEA_PRIORIDAD) return (plazo_z);
  }
  qry_plazoxprecio->Close();
  qry_plazoxprecio->ParamByName("precio")->AsFloat = precio_z;
  qry_plazoxprecio->ParamByName("tipo")->AsInteger = TIPO_PLAZO_PRECIO;
  qry_plazoxprecio->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxprecio->Open();
  if(plazo_z > qry_plazoxprecio->FieldByName("plazomax")->AsInteger) {
    plazo_z = qry_plazoxprecio->FieldByName("plazomax")->AsInteger;
  } // Esto para que no me confunda de IF. o;o
  qry_plazoxgrupo->Close();
  qry_plazoxgrupo->ParamByName("codigo")->AsString = grupo_z;
  qry_plazoxgrupo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_GRUPO;
  qry_plazoxgrupo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxgrupo->Open();
  if(!qry_plazoxgrupo->IsEmpty() && plazo_z > qry_plazoxgrupo->FieldByName("plazomax")->AsInteger) {
    plazo_z = qry_plazoxgrupo->FieldByName("plazomax")->AsInteger;
  } // Esto para que no me confunda de IF. o;o
  return (plazo_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_listpre2::impri_obs(String antlineatmp_z)
{
  if(rbtn_cost->Checked || rbtn_scost->Checked){
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
   }
  int ii_z = 0;
  String obss_z;
  for(ii_z=0;ii_z<= 7;ii_z++){
    fprintf(archout, "%s\n", ljust("-------------------------------------------------", 50));
    lineas_z += 1;
  }
   encab_obser();
   lineaini_z = lkcmb_lineaini->KeyValue;
   if(rbtn_mds->Checked){
      moe_z = "M";
   }else if(rbtn_ambos->Checked){
      moe_z = "M";
   }else if (rbtn_electro->Checked){
      moe_z = "E";
   }

   qry_obs->Close();
   qry_obs->ParamByName("linea")->AsString = antlineatmp_z;
   qry_obs->ParamByName("moe")->AsString = moe_z;
   qry_obs->Open();

   for(qry_obs->First(); !qry_obs->Eof; qry_obs->Next()) {
     obss_z = qry_obs->FieldByName("obser")->AsString;
     fprintf(archout, "%s\n", ljust(obss_z, 75));
     lineas_z += 1;
     checa_salto_pag(3);
   }

}
//---------------------------------------------------------------------------
bool __fastcall TForm_listpre2::checa_salto_pag(int margen_z)
{
  bool haysalto_z = false;
  if(lineas_z > (MAX_LINEAS - margen_z)) {
     fprintf(archout, "%c", 12);
     pagina_z++;
     report_encab();
     encab_linea(antlineatmp_z,antnombrelinea_z);
     encab2();
     haysalto_z = true;
  }
  return (haysalto_z);
}

//---------------------------------------------------------------------------


void __fastcall TForm_listpre2::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------


void __fastcall TForm_listpre2::imprimir_listaExecute(TObject *Sender)
{
   String sql3_z,sql2_z,sql1_z,codigotmp_z,empaqetmp_z, lineatmp_z,descritmp_z,
     caractetist_z,clavegrt_z,arch_z,nombrelinea_z, grupotmp_z, conext_z;
   int dato_z,tipopre_z,plazoxln_z,plazoxlng_z,plazomax_z,iddato_z,idart_z,real_z,
   tipoxpre_z,realgarant_z,linea_z;
   double preciotmp_z,costostmp_z,pivatmp_z,preciolta_z,costoneto_z,precioext_z,
   mub_z;
   TDateTime fechacort_z;
   pagina_z = 1;
   linea_z = 0;
   preciolta_z = 0;
   sql3_z = sql2_z = sql1_z = sql_z = "";
   //Agregamos la Informacion en Inventmp

   if( rbtn_mesta->Checked == false && rbtn_estas->Checked == false){
       Application->MessageBox("Seleccione Todas o Solo Esta \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_cost->Checked == false && rbtn_scost->Checked == false ){
       Application->MessageBox("Seleccione Con o Sin Costo \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_mds->Checked == false && rbtn_electro->Checked == false && rbtn_ambos->Checked == false ){
       Application->MessageBox("Seleccione MDS,Electrohogar o Ambos \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (rbtn_cprec->Checked == false && rbtn_sprec->Checked == false){
       Application->MessageBox("Seleccione Con o Sin Precio Xtensa \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }else if (lkcmb_lineaini->Text == "" && lkcmb_lineafin->Text == ""){
       Application->MessageBox("Seleccione Linea \n y  hacer click en el boton OK", "Datos Incompletos", MB_ICONQUESTION);
       return;
   }
   arch_z = "frm_listpre2.txt";
   if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
   }

   agregar_datos();

   //recorro tmpinven
   sql1_z = " select a.codigo,a.descri,costos,linea,b.descri as nomlinea,piva,precio,precelec, ";
   sql1_z += " empaqe, c.idart, cod2 from inventmp a join lineas b on a.linea = b.numero ";
   sql1_z += " join inv_invhist c on a.codigo = c.codigo and a.cia = c.cia";
   sql1_z += " order by linea,tipo,cod2,precio,codigo ";
   qry_inventmp->SQL->Text = sql1_z;
   qry_inventmp->Close();
   qry_inventmp->DisableControls();
   qry_inven->DisableControls();
   // qry_inventmp->ParamByName("cia")->AsInteger = cia_z;
   qry_inventmp->Open();
   TProgressBar *ProgressBar1 = new TProgressBar (this);
   ProgressBar1->Parent = pnl_datos;
   ProgressBar1->Step = 1;
   ProgressBar1->Height = 18;
   ProgressBar1->Align = alBottom;
   ProgressBar1->Min = 0;
   ProgressBar1->Max = qry_inventmp->RecordCount;


   for(qry_inventmp->First(); !qry_inventmp->Eof; qry_inventmp->Next()) {
      ProgressBar1->StepIt();

      codigotmp_z = qry_inventmp->FieldByName("codigo")->AsString;
      descritmp_z = qry_inventmp->FieldByName("descri")->AsString;
      grupotmp_z = qry_inventmp->FieldByName("cod2")->AsString;
      preciotmp_z = qry_inventmp->FieldByName("precio")->AsFloat;
      costostmp_z = qry_inventmp->FieldByName("costos")->AsFloat;
      pivatmp_z = qry_inventmp->FieldByName("piva")->AsFloat;
      fechacort_z = date_corte->DateTime;
      empaqetmp_z = qry_inventmp->FieldByName("empaqe")->AsString;
      lineatmp_z = qry_inventmp->FieldByName("linea")->AsString;
      nombrelinea_z = qry_inventmp->FieldByName("nomlinea")->AsString;
      idart_z = qry_inventmp->FieldByName("idart")->AsInteger;

      if(linea_z == 0){
        antlineatmp_z = lineatmp_z;
        antnombrelinea_z = nombrelinea_z;
        report_encab();
        encab_linea(antlineatmp_z,antnombrelinea_z);
        encab2();
        linea_z = 1;
      }

      if (empaqetmp_z == "REMATE"){
        sql2_z = "select count(*) as dato from movart where codigo= :CODIGO ";
        sql2_z += "and (salio<>'S' or (salio='S' and fechasal > :FECORT)) ";
        sql2_z += "and fecha <= :FECORT  and cia= :CIA ";
      } else {
        sql2_z = "select count(*) as dato from movart where codigo = :CODIGO ";
        sql2_z += "and almac not in ('IB','ME','BO','SE','MB', 'SB', 'UB', 'TB', 'OB') and ";
        sql2_z += "(salio<>'S' or (salio='S' and fechasal > :FECORT)) ";
        sql2_z += "and fecha <= :FECORT  and cia= :CIA ";
      }
      qry_exist->SQL->Text = sql2_z;
      qry_exist->Close();
      qry_exist->ParamByName("codigo")->AsString = codigotmp_z;
      qry_exist->ParamByName("fecort")->AsDateTime = fechacort_z;
      qry_exist->ParamByName("cia")->AsInteger = cia_z;
      qry_exist->Open();

      dato_z = qry_exist->FieldByName("dato")->AsInteger;

      if (dato_z > 0) {
          //Tomo el Plazo Maximo de la Linea
          tipopre_z = TIPO_PLAZO_LINEA;
          sql3_z = "select plazomax from plazoscrd ";
          sql3_z += "where linea= :LINEA and tipo= :TIPO and cia= :CIA ";
          qry_plazmax->SQL->Text = sql3_z;
          qry_plazmax->Close();
          qry_plazmax->ParamByName("linea")->AsString = lineatmp_z;
          qry_plazmax->ParamByName("tipo")->AsInteger = tipopre_z;
          qry_plazmax->ParamByName("cia")->AsInteger = cia_z;
          qry_plazmax->Open();

          plazoxln_z = qry_plazmax->FieldByName("plazomax")->AsInteger;

          //Plazo x Linea Obligado
          tipopre_z = TIPO_PLAZO_LINEA_PRIORIDAD;
          qry_plazmax->Close();
          qry_plazmax->ParamByName("linea")->AsString = lineatmp_z;
          qry_plazmax->ParamByName("tipo")->AsInteger = tipopre_z;
          qry_plazmax->ParamByName("cia")->AsInteger = cia_z;
          qry_plazmax->Open();

          plazomax_z = qry_plazmax->FieldByName("plazomax")->AsInteger;

          if(plazomax_z == 0){
            plazoxlng_z = -1;
          }else{
            plazoxlng_z = plazomax_z;
          }
          tipoxpre_z = TIPO_PLAZO_PRECIO;
          real_z = REL_INVEN_DESCRILAR;
          sql3_z = "select iddato from inv_relinv ";
          sql3_z += "where idart = :ID and idrel = :IDREL ";
          qry_idart->SQL->Text = sql3_z;
          qry_idart->Close();
          qry_idart->ParamByName("id")->AsInteger = idart_z;
          qry_idart->ParamByName("idrel")->AsInteger = real_z ;
          qry_idart->Open();
          iddato_z = qry_idart->FieldByName("iddato")->AsInteger;

          costoneto_z = ((costostmp_z  * pivatmp_z) / 100) + costostmp_z ;
          conext_z = "";

          if(rbtn_mds->Checked || rbtn_ambos->Checked ){
            if (rbtn_cprec->Checked) { // Con Precio Xtensa
               qry_xtensa->Close();
               qry_xtensa->ParamByName("cod")->AsString = codigotmp_z;
               qry_xtensa->ParamByName("cia")->AsInteger = cia_z;
               qry_xtensa->Open();
               precioext_z = qry_xtensa->FieldByName("precioext")->AsFloat;
               if (precioext_z) {
                 if(lineatmp_z == "ANTE" || lineatmp_z == "VIDE") {
                   conext_z = "C";
                 } else {
                   conext_z = "X";
                 }
               }
               preciolta_z = preciotmp_z + precioext_z;
            }else if (rbtn_sprec->Checked){  // Sin Precio Xtensa
               preciolta_z = preciotmp_z;
            }
          }

          if(preciolta_z) mub_z = 100 - ( (costoneto_z / preciolta_z) * 100 );
          //Garantia////
          realgarant_z = REL_INVEN_GARANTIA;
          qry_garantia->Close();
          qry_garantia->ParamByName("cod")->AsString = codigotmp_z;
          qry_garantia->ParamByName("cia")->AsInteger = cia_z;
          qry_garantia->ParamByName("idrel")->AsInteger = realgarant_z;
          qry_garantia->Open();

          clavegrt_z = qry_garantia->FieldByName("clave")->AsString;
          ////////////////

          //-----caracteristicas--------
          qry_caracteristicas->Close();
          qry_caracteristicas->ParamByName("cod")->AsString = codigotmp_z;
          qry_caracteristicas->ParamByName("idrel")->AsInteger = real_z;
          qry_caracteristicas->Open();

          caractetist_z = qry_caracteristicas->FieldByName("concep")->AsString;

          //buscar plazo reallll
          plazoxpr_z =  busca_plazo(codigotmp_z, lineatmp_z,
            grupotmp_z, preciolta_z);


          //busca_plazo_real(idart_z,tipoxpre_z,plazomax_z,preciolta_z);

          /////////////////////
          if(antlineatmp_z != lineatmp_z){
            impri_obs(antlineatmp_z);
             if(ckb_salto->Checked){
               antlineatmp_z = lineatmp_z;
               antnombrelinea_z = nombrelinea_z;
               checa_salto_pag(300);
               //report_encab();
             }else{
              encab_linea(lineatmp_z,nombrelinea_z);
              encab2();
              antlineatmp_z = lineatmp_z;
              antnombrelinea_z = nombrelinea_z;
             }
          }

          imprimir_renglon(descritmp_z,clavegrt_z,preciolta_z,plazoxpr_z,empaqetmp_z,
                   costoneto_z,mub_z,caractetist_z, preciotmp_z, conext_z);

          checa_salto_pag(3);


      }//IF
   }//FOR

   if(ckb_obser->Checked){
     impri_obs(antlineatmp_z);
   } else{
      if(rbtn_cost->Checked || rbtn_scost->Checked){
       fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
      }
   }
   delete ProgressBar1;
   qry_inventmp->EnableControls();
   qry_inven->EnableControls();

   fclose(archout);
   dm->manda_impresion(arch_z);
   sql3_z = sql2_z = sql1_z = sql_z = "";
   leer_o_grabar_ini("GRABAR");

}
//---------------------------------------------------------------------------

void __fastcall TForm_listpre2::leer_o_grabar_ini(String accion_z)
{
   String config_z;
   config_z = dm->busca_inifile();
   TIniFile *ini;
   ini = new TIniFile(config_z);
   if( accion_z == "GRABAR") {
     ini->WriteString( "Form_listpre2", "LINEA_INI", lkcmb_lineaini->KeyValue);
     ini->WriteString( "Form_listpre2", "LINEA_FIN", lkcmb_lineafin->KeyValue);
     ini->WriteString( "Form_listpre2", "SITUAC_INI", lkcmb_rematini->KeyValue);
     ini->WriteString( "Form_listpre2", "SITUAC_FIN", lkcmb_rematfin->KeyValue);
     ini->WriteBool  ( "Form_listpre2", "rbtn_mesta", rbtn_mesta->Checked);
     ini->WriteBool  ( "Form_listpre2", "rbtn_estas", rbtn_estas->Checked);
     ini->WriteBool  ( "Form_listpre2", "rbtn_cost",  rbtn_cost->Checked);
     ini->WriteBool  ( "Form_listpre2", "rbtn_scost", rbtn_scost->Checked);
     ini->WriteBool  ( "Form_listpre2", "rbtn_cprec",  rbtn_cprec->Checked);
     ini->WriteBool  ( "Form_listpre2", "rbtn_sprec", rbtn_sprec->Checked);
     ini->WriteString( "Form_listpre2", "edt_codini", edt_codini->Text);
     ini->WriteString( "Form_listpre2", "edt_codfin", edt_codfin->Text);
     ini->WriteBool  ( "Form_listpre2", "ckb_obser",  ckb_obser->Checked);
     ini->WriteBool  ( "Form_listpre2", "ckb_salto", ckb_salto->Checked);
   }
   if( accion_z == "LEER") {
     lkcmb_lineaini->KeyValue = ini->ReadString( "Form_listpre2", "LINEA_INI", "");
     lkcmb_lineafin->KeyValue = ini->ReadString( "Form_listpre2", "LINEA_FIN", "zz");
     lkcmb_rematini->KeyValue = ini->ReadString( "Form_listpre2", "SITUAC_INI", "");
     lkcmb_rematfin->KeyValue = ini->ReadString( "Form_listpre2", "SITUAC_FIN", "zz");
     rbtn_mesta->Checked = ini->ReadBool  ( "Form_listpre2", "rbtn_mesta", true);
     rbtn_estas->Checked = ini->ReadBool  ( "Form_listpre2", "rbtn_estas", false);
     rbtn_cost->Checked = ini->ReadBool  ( "Form_listpre2", "rbtn_cost",  false);
     rbtn_scost->Checked = ini->ReadBool  ( "Form_listpre2", "rbtn_scost", true);
     rbtn_cprec->Checked = ini->ReadBool  ( "Form_listpre2", "rbtn_cprec",  true);
     rbtn_sprec->Checked = ini->ReadBool  ( "Form_listpre2", "rbtn_sprec", false);
     edt_codini->Text = ini->ReadString( "Form_listpre2", "edt_codini", "");
     edt_codfin->Text = ini->ReadString( "Form_listpre2", "edt_codfin", "zz");
     ckb_obser->Checked = ini->ReadBool  ( "Form_listpre2", "ckb_obser",  true);
     ckb_salto->Checked = ini->ReadBool  ( "Form_listpre2", "ckb_salto", true);
   }
   delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm_listpre2::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//TAdvStringGrid* misgrd_z;
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

void __fastcall TForm_listpre2::dbgrd_renglonesCustomDraw(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxDBTreeListColumn *AColumn, const AnsiString AText, TFont *AFont,
      TColor &AColor, bool ASelected, bool AFocused, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
      
}
//---------------------------------------------------------------------------






