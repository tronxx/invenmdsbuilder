//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_cvtaubi.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"
#include "numapal.h"
const int LINEAS_X_PAG = 60;
TForm_cvtaubi *Form_cvtaubi;
//---------------------------------------------------------------------------
__fastcall TForm_cvtaubi::TForm_cvtaubi(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_cvtaubi::FormCreate(TObject *Sender)
{
  cia_z = dm->cia_z;
  date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::elimina_invtmp()
{
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "delete from inv_tpvtatmp where IDTAREA = :IDTAREA";
  dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
  dm->qry_maxidvnd->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::agrega_invtpvtatmp(int idtpvtatmp_z, int idtipovta_z, int factor_z, String tipoent_z)
{
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->ParamByName("IDTPVTATMP")->AsInteger = idtpvtatmp_z;
  dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
  dm->qry_maxidvnd->ParamByName("IDTIPOVTA")->AsInteger = idtipovta_z;
  dm->qry_maxidvnd->ParamByName("FACTOR")->AsInteger = factor_z;
  dm->qry_maxidvnd->ParamByName("TIPOSAL")->AsString = tipoent_z;
  dm->qry_maxidvnd->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::exporta_dbgrdExecute(TObject *Sender)
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


void __fastcall TForm_cvtaubi::imprimir_reporteExecute(TObject *Sender)
{
  int idtpvtatmp_z=0, idtpvt_z=0, idtipovta_z, factor_z;
  String tipoent_z, siono1_z, siono2_z, entcan1_z, entcan2_z,
  codigo_z, mensaje_z, titmsg_z, arch_z, situacion_z;
  mensaje_z = "Desea imprimir este reporte?";
  titmsg_z = "Costo de Ventas x Ubicación";
  arch_z = "cvtaubi.tex";
  enc_z="ARTICULOS_X_PTOVTA";

  primero_z = 0;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  graba_invtmp();
  TProgressBar *ProgressBar1;
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = Panel1;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Width = Panel1->Width - 4;
  ProgressBar1->Left = 2;
  ProgressBar1->Top = Panel1->Height - 20;
  ProgressBar1->Min = 0;
  qry_analisma->DisableControls();
  qry_analisma->Close();
  qry_analisma->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_analisma->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_analisma->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_analisma->ParamByName("cia")->AsInteger = cia_z;
  qry_analisma->Open();
  ProgressBar1->Max = qry_analisma->RecordCount;
  antlin_z = "-1"; pagina_z = 1;
  for(qry_analisma->First(); !qry_analisma->Eof; qry_analisma->Next()) {
    linea_z = qry_analisma->FieldByName("linea")->AsString;
    codigo_z = qry_analisma->FieldByName("codigo")->AsString;
    situacion_z  = qry_analisma->FieldByName("empaqe")->AsString;
    if(antlin_z == "-1") {
      busca_ubicaciones_x_linea(linea_z);
      antlin_z = linea_z;
    }
    if(!primero_z) {
      report_encab(); primero_z = 1;
    }
    if(antlin_z != linea_z) {
      report_subtotxlinea();
      antlin_z = linea_z;
      busca_ubicaciones_x_linea(linea_z);
      if(!checa_saltopag(8))  report_subencab();
    }
    checa_saltopag(3);
    impri_renglon(codigo_z, situacion_z);
    ProgressBar1->StepIt();
  }
  if(!primero_z) {
    report_encab(); primero_z = 1;
  }
  report_subtotxlinea();
  reporte_datos_x_sit();
  delete ProgressBar1;
  elimina_invtmp();
  fclose(archout);
  dm->manda_impresion(arch_z);
  dbgrd_renglones->FullExpand();
  qry_analisma->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::busca_ubicaciones_x_linea(String linea_z)
{
   qry_analixalm->Close();
   qry_analixalm->ParamByName("idtarea")->AsInteger = idtarea_z;
   qry_analixalm->ParamByName("fecini")->AsDateTime = date_fecini->Date;
   qry_analixalm->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
   qry_analixalm->ParamByName("cia")->AsInteger = cia_z;
   qry_analixalm->ParamByName("linea")->AsString = linea_z;
   qry_analixalm->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::graba_invtmp()
{
  int idtipovta_z, factor_z, idtpvtatmp_z, idtpvt_z;
  String tipoent_z;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "select max(IDTAREA) as idtarea, max(IDTPVTATMP) as idtpvtatmp from inv_tpvtatmp";
  dm->qry_maxidvnd->Open();
  idtarea_z = dm->qry_maxidvnd->FieldByName("idtarea")->AsInteger + 1;
  idtpvtatmp_z = dm->qry_maxidvnd->FieldByName("idtpvtatmp")->AsInteger + 1;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "insert into inv_tpvtatmp (IDTPVTATMP, IDTAREA, IDTIPOVTA, FACTOR, TIPOSAL) values ( :IDTPVTATMP, :IDTAREA, :IDTIPOVTA, :FACTOR, :TIPOSAL )";
  // Hago un for 1 = Venta 2 = Cancelacion
  idtipovta_z = 1; // El query, en 1 es el tipo de sábana
  for(int jj_z = 0; jj_z < 4; jj_z++) {
    idtpvt_z = jj_z;
    if(grp_netobru->ItemIndex == 0 || grp_netobru->ItemIndex == 1) {
        // De acuerdo a ii 1 = Venta 2 = Cancelacion
      factor_z = 1;
      switch (idtpvt_z) {
        case 0: tipoent_z = "V"; break;
        case 1: tipoent_z = "F"; break;
        case 2: tipoent_z = "H"; break;
        case 3: tipoent_z = "Q"; break;
      }
      agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
    }
    if(grp_netobru->ItemIndex == 1 || grp_netobru->ItemIndex == 2) {
      // De acuerdo a ii 1 = Venta 2 = Cancelacion
      factor_z = -1;
      switch (idtpvt_z) {
        case 0: tipoent_z = "C"; break;
        case 1: tipoent_z = "O"; break;
        case 2: tipoent_z = "J"; break;
        case 3: tipoent_z = "U"; break;
      }
      agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
    }
  }
  idtipovta_z = 2; // El query, en 2 es el tipo Si o No
  if(grp_statsino->ItemIndex == 0 || grp_statsino->ItemIndex == 1)
     agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, "S");
  if(grp_statsino->ItemIndex == 0 || grp_statsino->ItemIndex == 2)
     agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, "N");

  idtipovta_z = 3; // El query, en 3 es Status de  Cancelación
  if(grp_statcan->ItemIndex == 0 || grp_statcan->ItemIndex == 1)
     agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, "S");
  if(grp_statcan->ItemIndex == 0 || grp_statcan->ItemIndex == 2)
     agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, "N");
}
//---------------------------------------------------------------------------


void __fastcall TForm_cvtaubi::impri_renglon(String codigo_z, String situacion_z)
{
  String descri_z, alm_z, strunids_z;
  int unids_z, totuni_z=0;
  float costo_z, totcos_z=0;
  TLocateOptions Opts;
  Opts.Clear();

  descri_z = qry_analisma->FieldByName("descri")->AsString;
  qry_analixart->Close();
  qry_analixart->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_analixart->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_analixart->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_analixart->ParamByName("cia")->AsInteger = cia_z;
  qry_analixart->ParamByName("codigo")->AsString = codigo_z;
  qry_analixart->Open();
  fprintf(archout, "%s|", ljust(codigo_z, 13));
  fprintf(archout, "%s|", ljust(descri_z, 30));

  for(qry_analixalm->First(); !qry_analixalm->Eof; qry_analixalm->Next()) {
    unids_z = 0;
    costo_z = 0;
    strunids_z = "";
    alm_z = qry_analixalm->FieldByName("recemi")->AsString;
    if(qry_analixart->Locate("recemi", alm_z, Opts)) {
      unids_z = qry_analixart->FieldByName("unids")->AsInteger;
      costo_z = qry_analixart->FieldByName("costotot")->AsFloat;
    }
    if(unids_z) {
      strunids_z = FormatFloat("0", unids_z);
    }
    totuni_z += unids_z;
    totcos_z += costo_z;
    strunids_z = rjust(strunids_z, 4);
    fprintf(archout, "%s|", strunids_z);
  }
  fprintf(archout, "%s|", rjust(IntToStr(totuni_z), 4));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", totcos_z), 12));
  fprintf(archout, "%s|", ljust(situacion_z, 10));
  fprintf(archout, "\n");
  totcosxlin_z += totcos_z;
  lineas_z++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::report_subtotxlinea()
{
  String titulo_z, strunids_z;
  int unids_z=0, totuni_z=0;
  double costo_z=0, totcos_z=0;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", cjust("Totales de Esta Linea", 44));
  for(qry_analixalm->First(); !qry_analixalm->Eof; qry_analixalm->Next()) {
    unids_z = 0;
    costo_z = 0;
    strunids_z = "";
    unids_z = qry_analixalm->FieldByName("unids")->AsInteger;
    costo_z = qry_analixalm->FieldByName("costotot")->AsFloat;
    if(unids_z) {
      strunids_z = FormatFloat("0", unids_z);
    }
    totuni_z += unids_z;
    totcos_z += costo_z;
    strunids_z = rjust(strunids_z, 4);
    fprintf(archout, "%s|", strunids_z);
  }
  fprintf(archout, "%s|", rjust(FormatFloat("0", totuni_z), 4));
  fprintf(archout, "%s|", rjust(FormatFloat("##,###,##0.00", totcos_z), 12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::salta_linea()
{
  fprintf(archout, "\n");
  lineas_z++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::report_encab()
{
  String titulo_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s cvtaubi %s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    cjust("INFORME DE DIRECCION", 40),
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  titulo_z = "DEL " + FormatDateTime( "dd/mm/yyyy", date_fecini->Date) +
   " AL " + FormatDateTime( "dd/mm/yyyy", date_fecfin->Date);
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    cjust(titulo_z, 40),
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    cjust("INFORME DE INVENTARIOS", 40),
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  titulo_z = "Analisis de Costo de ";
  if(grp_netobru->ItemIndex == 0) titulo_z += "Ventas Brutas ";
  if(grp_netobru->ItemIndex == 1) titulo_z += "Ventas Netas";
  if(grp_netobru->ItemIndex == 2) titulo_z += "Cancelaciones";
  titulo_z += " Tradicional-FONACOT-FIDE";
  fprintf(archout, "%s\n", titulo_z);

  titulo_z = "Mercancia ";
  if(grp_netobru->ItemIndex == 0) titulo_z += "Sin importar Status Cancelacion";
  if(grp_netobru->ItemIndex == 1) titulo_z += "Solo de Cancelacion";
  if(grp_netobru->ItemIndex == 2) titulo_z += "Solo No Cancelacion";
  fprintf(archout, "%s\n", titulo_z);

  titulo_z = "Validacion de Costos por Zonas y Lineas";
  fprintf(archout, "%s\n", titulo_z);
  lineas_z = 8;
  if(enc_z == "ARTICULOS_X_PTOVTA")  report_subencab();
  if(enc_z == "DATOS_X_SITUACION")   report_subencab_sit();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::report_subencab()
{
  String titulo_z;
  int ancho_z;
  qry_lineas->Close();
  qry_lineas->ParamByName("linea")->AsString = linea_z;
  qry_lineas->ParamByName("cia")->AsInteger = cia_z;
  qry_lineas->Open();
  titulo_z = qry_lineas->FieldByName("descri")->AsString;
  fprintf(archout, "%sLinea:%s%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    antlin_z + " " + titulo_z,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  salta_linea();
  ancho_z = (qry_analixalm->RecordCount + 1) * 5 + 14 + 31 + 13 + 10;
  if(ancho_z > 132) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  } else if(ancho_z > 90) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  } else if(ancho_z > 80) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  } else {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Codigo",13));
  fprintf(archout, "%s|", ljust("Descripcion",30));
  for(qry_analixalm->First(); !qry_analixalm->Eof; qry_analixalm->Next()) {
    fprintf(archout, "%s|", ljust(qry_analixalm->FieldByName("recemi")->AsString,4));
  }
  fprintf(archout, "%s|", ljust("Tot.",4));
  fprintf(archout, "%s|", ljust("Costo Total",12));
  fprintf(archout, "%s|", ljust("Situacion",10));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

bool __fastcall TForm_cvtaubi::checa_saltopag(int numero_de_lineas)
{
  bool haysalto_z = false;
  if(lineas_z > ( LINEAS_X_PAG - numero_de_lineas) ) {
    fprintf(archout, "%c", 12); pagina_z++; report_encab();
    haysalto_z = true;
  }
  return(haysalto_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::reporte_datos_x_sit()
{
  bool listo_z = false;
  int maxren_z = 0, ii_z=0;
  double ctoxsit_z=0, ctoxlin_z=0, ctoxpvt_z=0,
         costo1_z=0,  costo2_z=0,  costo3_z=0;
  String strcos1_z, strcos2_z, strcos3_z, situac_z, lin_z, pvt_z;

  enc_z="DATOS_X_SITUACION";
  qry_acumxsit->Close();
  qry_acumxsit->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxsit->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_acumxsit->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_acumxsit->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxsit->Open();
  qry_acumxlin->Close();
  qry_acumxlin->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxlin->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_acumxlin->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_acumxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxlin->Open();
  qry_acumxpvt->Close();
  qry_acumxpvt->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxpvt->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_acumxpvt->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_acumxpvt->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxpvt->Open();
  maxren_z = qry_acumxpvt->RecordCount;
  if(qry_acumxlin->RecordCount > maxren_z) maxren_z = qry_acumxlin->RecordCount;
  if(qry_acumxsit->RecordCount > maxren_z) maxren_z = qry_acumxsit->RecordCount;
  salta_linea();
  if( !checa_saltopag(maxren_z+4)) report_subencab_sit();
  ctoxsit_z=0; ctoxlin_z=0; ctoxpvt_z=0;
  for(; !listo_z; ) {
    ii_z++;
    checa_saltopag(3);
    costo1_z=0; costo2_z=0; costo3_z=0;
    strcos1_z = "";
    strcos2_z = "";
    strcos3_z = "";
    situac_z  = "";
    lin_z     = "";
    pvt_z     = "";
    if(!qry_acumxsit->Eof) {
      costo1_z = qry_acumxsit->FieldByName("costotot")->AsFloat;
      situac_z = qry_acumxsit->FieldByName("situacion")->AsString;
      ctoxsit_z += costo1_z;
      qry_acumxsit->Next();
    }
    if(!qry_acumxlin->Eof) {
      costo2_z = qry_acumxlin->FieldByName("costotot")->AsFloat;
      lin_z = qry_acumxlin->FieldByName("linea")->AsString;
      ctoxlin_z += costo2_z;
      qry_acumxlin->Next();
    }
    if(!qry_acumxpvt->Eof) {
      costo3_z = qry_acumxpvt->FieldByName("costotot")->AsFloat;
      pvt_z = qry_acumxpvt->FieldByName("pvta")->AsString;
      ctoxpvt_z += costo3_z;
      qry_acumxpvt->Next();
    }
    listo_z = qry_acumxpvt->Eof && qry_acumxsit->Eof &&  qry_acumxlin->Eof;
    if(costo1_z) strcos1_z = FormatFloat("###,###,##0.00", costo1_z);
    if(costo2_z) strcos2_z = FormatFloat("###,###,##0.00", costo2_z);
    if(costo3_z) strcos3_z = FormatFloat("###,###,##0.00", costo3_z);
    fprintf(archout, "%s", ljust("",10));
    if(ii_z == maxren_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
    fprintf(archout, "%s|", ljust(situac_z, 10));
    fprintf(archout, "%s|", rjust(strcos1_z, 13));
    fprintf(archout, "%s|", ljust(lin_z, 5));
    fprintf(archout, "%s|", rjust(strcos2_z, 13));
    fprintf(archout, "%s|", ljust(pvt_z, 4));
    fprintf(archout, "%s|", rjust(strcos3_z, 13));
    if(ii_z == maxren_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
    salta_linea();
  }
  if(ctoxsit_z) strcos1_z = FormatFloat("###,###,##0.00", ctoxsit_z);
  if(ctoxlin_z) strcos2_z = FormatFloat("###,###,##0.00", ctoxlin_z);
  if(ctoxpvt_z) strcos3_z = FormatFloat("###,###,##0.00", ctoxpvt_z);
  fprintf(archout, "%s", ljust("",10));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("", 10));
  fprintf(archout, "%s|", rjust(strcos1_z, 13));
  fprintf(archout, "%s|", ljust("", 5));
  fprintf(archout, "%s|", rjust(strcos2_z, 13));
  fprintf(archout, "%s|", ljust("", 4));
  fprintf(archout, "%s|", rjust(strcos3_z, 13));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cvtaubi::report_subencab_sit()
{
  String titulo_z;
  int ancho_z;
  titulo_z = "Total de Costo de Ventas por Tipo de Mercancia";
  fprintf(archout, "%s%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF),
    cjust(titulo_z, 80)
  );
  salta_linea();
  fprintf(archout, "%s", ljust("",10));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Situacion",10));
  fprintf(archout, "%s|", rjust("Costo",13));
  fprintf(archout, "%s|", ljust("Linea",5));
  fprintf(archout, "%s|", rjust("Costo",13));
  fprintf(archout, "%s|", ljust("Pvta",4));
  fprintf(archout, "%s|", rjust("Costo",13));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();

}
//---------------------------------------------------------------------------

