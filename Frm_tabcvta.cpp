//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_tabcvta.h"
#include "math.h"
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
const int CREDITO = 2;
const int CONTADO = 1;
const int CRED_Y_CONT = 3;

TForm_tabcvta *Form_tabcvta;
//---------------------------------------------------------------------------
__fastcall TForm_tabcvta::TForm_tabcvta(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_tabcvta::FormCreate(TObject *Sender)
{
  cia_z = dm->cia_z;
  date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
  date_feciniExit(Sender);
}
//---------------------------------------------------------------------------
void __fastcall TForm_tabcvta::BitBtn1Click(TObject *Sender)
{
  int idtpvtatmp_z=0, idtpvt_z=0, idtipovta_z, factor_z;
  String tipoent_z, siono1_z, siono2_z, entcan1_z, entcan2_z;
  graba_invtmp("NETO");
  qry_analisma->Close();
  qry_analisma->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_analisma->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_analisma->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_analisma->ParamByName("cia")->AsInteger = cia_z;
  qry_analisma->Open();
  elimina_invtmp();
  dbgrd_renglones->FullExpand();
  imprimir_reporteExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::elimina_invtmp()
{
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "delete from inv_tpvtatmp where IDTAREA = :IDTAREA";
  dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
  dm->qry_maxidvnd->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::agrega_invtpvtatmp(int idtpvtatmp_z, int idtipovta_z, int factor_z, String tipoent_z)
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

void __fastcall TForm_tabcvta::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::exporta_dbgrdExecute(TObject *Sender)
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



void __fastcall TForm_tabcvta::busca_ubicaciones_x_linea(String linea_z)
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

void __fastcall TForm_tabcvta::graba_invtmp(String modo_z)
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
  idtipovta_z = 1;
  idtpvt_z = grp_tiporep->ItemIndex; // El query, en 1 es el tipo de sábana
  if(modo_z == "SOLO_VENTAS_TRADICIONALES_BRUTAS") {
     factor_z = 1; tipoent_z = "V";
     agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
  } else {
    if(idtpvt_z == 0 || idtpvt_z == 1) {
       if(modo_z == "BRUTO" || modo_z == "NETO") {
         factor_z = 1; tipoent_z = "V";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
       if(modo_z == "CANCEL" || modo_z == "NETO") {
         factor_z = -1; tipoent_z = "C";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
    }
    if(idtpvt_z == 0 || idtpvt_z == 2) {
       if(modo_z == "BRUTO" || modo_z == "NETO") {
         factor_z = 1; tipoent_z = "F";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
       if(modo_z == "CANCEL" || modo_z == "NETO") {
         factor_z = -1; tipoent_z = "O";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
    }
    if(idtpvt_z == 0 || idtpvt_z == 3) {
       if(modo_z == "BRUTO" || modo_z == "NETO") {
         factor_z = 1; tipoent_z = "H";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
       if(modo_z == "CANCEL" || modo_z == "NETO") {
         factor_z = -1; tipoent_z = "J";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
    }
    if(idtpvt_z == 0 || idtpvt_z == 4) {
       if(modo_z == "BRUTO" || modo_z == "NETO") {
         factor_z = 1; tipoent_z = "1";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
       if(modo_z == "CANCEL" || modo_z == "NETO") {
         factor_z = -1; tipoent_z = "2";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
    }
    if(idtpvt_z == 0 || idtpvt_z == 5) {
       if(modo_z == "BRUTO" || modo_z == "NETO") {
         factor_z = 1; tipoent_z = "Q";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
       if(modo_z == "CANCEL" || modo_z == "NETO") {
         factor_z = -1; tipoent_z = "U";
         agrega_invtpvtatmp(idtpvtatmp_z++, idtipovta_z, factor_z, tipoent_z);
       }
    }
  }
  if(chk_reacumular->Checked) {
     acumular_datos();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::acumular_datos()
{
  int idtipovta_z, factor_z, idtpvtatmp_z, idtpvt_z;
  String tipoent_z, alm_z, pvta_z, linea_z, siono_z, tipozon_z;
  double contado_z=0, credito_z=0, costo_z, iva_z;
  fecini_z = date_fecini->Date;
  fecfin_z = date_fecfin->Date;
  TProgressBar *ProgressBar1;
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = Panel1;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Width = Panel1->Width - 4;
  ProgressBar1->Left = 2;
  ProgressBar1->Top = Panel1->Height - 20;
  ProgressBar1->Min = 0;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "select tiposal from inv_tpvtatmp where idtarea = :IDTAREA";
  dm->qry_maxidvnd->ParamByName("idtarea")->AsInteger = idtarea_z;
  dm->qry_maxidvnd->Open();
  for(dm->qry_maxidvnd->First(); !dm->qry_maxidvnd->Eof; dm->qry_maxidvnd->Next()) {
    tipoent_z = dm->qry_maxidvnd->FieldByName("tiposal")->AsString;
    qry_eliminaacuant->Close();
    qry_eliminaacuant->ParamByName("fecini")->AsDateTime = fecini_z;
    qry_eliminaacuant->ParamByName("fecfin")->AsDateTime = fecfin_z;
    qry_eliminaacuant->ParamByName("tipoent")->AsString = tipoent_z;
    qry_eliminaacuant->ParamByName("cia")->AsInteger = cia_z;
    qry_eliminaacuant->ExecSQL();
  }
  qry_acumulados->Close();
  qry_acumulados->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumulados->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumulados->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumulados->ParamByName("cia")->AsInteger = cia_z;
  qry_acumulados->Open();
  ProgressBar1->Max = qry_acumulados->RecordCount;
  for(qry_acumulados->First(); !qry_acumulados->Eof; qry_acumulados->Next()) {
    tipoent_z  = qry_acumulados->FieldByName("tipo")->AsString;
    alm_z      = qry_acumulados->FieldByName("alm")->AsString;
    pvta_z     = qry_acumulados->FieldByName("ptvta")->AsString;
    linea_z    = qry_acumulados->FieldByName("linea")->AsString;
    siono_z    = qry_acumulados->FieldByName("siono")->AsString;
    costo_z    = Redondea(qry_acumulados->FieldByName("costo")->AsFloat, 100);
    iva_z      = Redondea(qry_acumulados->FieldByName("iva")->AsFloat, 100);
    qry_ubivta->Close();
    qry_ubivta->ParamByName("alm")->AsString = alm_z;
    qry_ubivta->ParamByName("pvta")->AsString = pvta_z;
    qry_ubivta->Open();
    if(!qry_ubivta->IsEmpty()) {
      zona_z = qry_ubivta->FieldByName("zonainv")->AsString;
      tipozon_z = qry_ubivta->FieldByName("voc")->AsString;
    }

    if(tipoent_z == "V") {
      // Busco los acumulados de Ventas Credito y Contado
      credito_z = busca_credito_o_contado(tipoent_z, alm_z, pvta_z, linea_z, CREDITO);
      contado_z = busca_credito_o_contado(tipoent_z, alm_z, pvta_z, linea_z, CONTADO);
    } else if(tipoent_z == "C") {
      // Busco los acumulados de Ventas Credito y Contado
      credito_z = busca_credito_o_contado_cancel(tipoent_z, alm_z, pvta_z, linea_z, CREDITO);
      contado_z = busca_credito_o_contado_cancel(tipoent_z, alm_z, pvta_z, linea_z, CONTADO);
    } else {
      contado_z = costo_z;
      credito_z = 0;
    }
    contado_z = Redondea(contado_z,100);
    credito_z = Redondea(credito_z,100);
    qry_tabcvta->Close();
    qry_tabcvta->ParamByName("fecini")->AsDateTime = fecini_z;
    qry_tabcvta->ParamByName("fecfin")->AsDateTime = fecfin_z;
    qry_tabcvta->ParamByName("zona")->AsString = zona_z;
    qry_tabcvta->ParamByName("almkdx")->AsString = alm_z;
    qry_tabcvta->ParamByName("ptvta")->AsString = pvta_z;
    qry_tabcvta->ParamByName("linea")->AsString = linea_z;
    qry_tabcvta->ParamByName("cia")->AsInteger = cia_z;
    qry_tabcvta->Open();
    if(qry_tabcvta->IsEmpty()) {
      qry_tabcvta->Append();
      qry_tabcvta->FieldByName("fecini")->AsDateTime = fecini_z;
      qry_tabcvta->FieldByName("fecfin")->AsDateTime = fecfin_z;
      qry_tabcvta->FieldByName("zona")->AsString = zona_z;
      qry_tabcvta->FieldByName("almkdx")->AsString = alm_z;
      qry_tabcvta->FieldByName("ptvta")->AsString = pvta_z;
      qry_tabcvta->FieldByName("tipo")->AsString = tipozon_z;
      qry_tabcvta->FieldByName("tipoent")->AsString = tipoent_z;
      qry_tabcvta->FieldByName("linea")->AsString = linea_z;
      qry_tabcvta->FieldByName("cia")->AsInteger = cia_z;
      qry_tabcvta->FieldByName("ctocont")->AsFloat = contado_z;
      qry_tabcvta->FieldByName("ctocred")->AsFloat = credito_z;
      qry_tabcvta->FieldByName("ctovtasi")->AsFloat = 0;
      qry_tabcvta->FieldByName("ivasi")->AsFloat = 0;
      qry_tabcvta->FieldByName("ctovtano")->AsFloat = 0;
    } else {
      qry_tabcvta->Edit();
    }
    if(siono_z == "S") {
      qry_tabcvta->FieldByName("ctovtasi")->AsFloat += costo_z;
      qry_tabcvta->FieldByName("ivasi")->AsFloat += iva_z;
    } else {
      qry_tabcvta->FieldByName("ctovtano")->AsFloat += costo_z;
    }
    qry_tabcvta->Post();
    try {
      dm->manvehi->StartTransaction();
      qry_tabcvta->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    ProgressBar1->StepIt();
  }
  delete ProgressBar1;
}
//---------------------------------------------------------------------------

double __fastcall TForm_tabcvta::busca_credito_o_contado(
  String tipo_z, String alm_z, String pvta_z, String linea_z, int modo_z
)
{
  double costo_z=0;
  qry_credcont->Close();
  qry_credcont->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_credcont->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_credcont->ParamByName("cia")->AsInteger = cia_z;
  qry_credcont->ParamByName("tiposal")->AsString = tipo_z;
  qry_credcont->ParamByName("alm")->AsString = alm_z;
  qry_credcont->ParamByName("recemi")->AsString = pvta_z;
  qry_credcont->ParamByName("linea")->AsString = linea_z;
  qry_credcont->ParamByName("credocont")->AsInteger = modo_z;
  qry_credcont->Open();
  if(qry_credcont->IsEmpty()) costo_z = qry_credcont->FieldByName("costo")->AsFloat;
  return (costo_z);
}
//---------------------------------------------------------------------------

double __fastcall TForm_tabcvta::busca_credito_o_contado_cancel(
  String tipo_z, String alm_z, String pvta_z, String linea_z, int modo_z
)
{
  double costo_z=0;
  qry_credoconcancel->Close();
  qry_credoconcancel->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_credoconcancel->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_credoconcancel->ParamByName("cia")->AsInteger = cia_z;
  qry_credoconcancel->ParamByName("tiposal")->AsString = tipo_z;
  qry_credoconcancel->ParamByName("alm")->AsString = alm_z;
  qry_credoconcancel->ParamByName("recemi")->AsString = pvta_z;
  qry_credoconcancel->ParamByName("linea")->AsString = linea_z;
  qry_credoconcancel->ParamByName("credocont")->AsInteger = modo_z;
  qry_credoconcancel->Open();
  if(qry_credoconcancel->IsEmpty()) costo_z = qry_credoconcancel->FieldByName("costo")->AsFloat;
  return (costo_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_tabcvta::imprimir_reporteExecute(TObject *Sender)
{
  int idtpvtatmp_z=0, idtpvt_z=0, idtipovta_z, factor_z;
  String tipoent_z, siono1_z, siono2_z, entcan1_z, entcan2_z,
     codigo_z, mensaje_z, titmsg_z, arch_z, situacion_z;
  mensaje_z = "Desea imprimir este reporte?";
  titmsg_z = "Tabla de Costo de Ventas";
  arch_z = "tabcvta.tex";
  enc_z="CTO_VTA_X_LINEA_PVTA";

  primero_z = 0;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  graba_invtmp("NETO");
  TProgressBar *ProgressBar1;
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = Panel1;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Width = Panel1->Width - 4;
  ProgressBar1->Left = 2;
  ProgressBar1->Top = Panel1->Height - 20;
  ProgressBar1->Min = 0;
  fecini_z = date_fecini->Date;
  fecfin_z = date_fecfin->Date;
  qry_zonas->Close();
  qry_zonas->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_zonas->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_zonas->ParamByName("zonaini")->AsString = "";
  qry_zonas->ParamByName("zonafin")->AsString = "zz";
  qry_zonas->ParamByName("ptvtaini")->AsString = "";
  qry_zonas->ParamByName("ptvtafin")->AsString = "zz";
  qry_zonas->ParamByName("lineaini")->AsString = "";
  qry_zonas->ParamByName("lineafin")->AsString = "zz";
  qry_zonas->ParamByName("cia")->AsInteger = cia_z;
  qry_zonas->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_zonas->Open();
  ProgressBar1->Max = qry_zonas->RecordCount;

  pagina_z = 1;
  for(qry_zonas->First(); !qry_zonas->Eof; qry_zonas->Next()) {
    zona_z = qry_zonas->FieldByName("zona")->AsString;
    genera_reporte_x_zona(zona_z);
    ProgressBar1->StepIt();
  }
  if(!primero_z) {
    report_encab(); primero_z = 1;
  }
  //report_subtotxlinea();
  //reporte_datos_x_sit();
  delete ProgressBar1;
  tabla_total_x_zona();
  participacion_existencias();
  tabla_exhibicion_x_linea();
  tabla_costo_x_tipo_vta();
  imprime_tabla_credito_y_contado();
  tabla_costo_x_tipo_vta_cyc();
  fclose(archout);
  elimina_invtmp();
  dm->manda_impresion(arch_z);
  dbgrd_renglones->FullExpand();
  qry_analisma->EnableControls();
}
//---------------------------------------------------------------------------


String  __fastcall TForm_tabcvta::divent(int columnas_z, int anchocol_z, int colextra_z)
{
  int ii_z, ancho_z, anchomax_z, tablas_z, minres_z, cols_z;
  double densa_z, densb_z, densc_z;
  ancho_z = (columnas_z * anchocol_z) + colextra_z;
  densa_z = columnas_z / miceil(ancho_z, 132);
  densb_z = columnas_z / miceil(ancho_z, 90);
  densc_z = columnas_z / miceil(ancho_z, 80);
  anchomax_z = 132;
  if(  densa_z > densb_z && densa_z > densc_z ) {
    anchomax_z = 132;
  } else if( densb_z > densc_z ) {
    anchomax_z = 90;
  } else {
    anchomax_z = 80;
  }
  tablas_z = miceil(ancho_z, anchomax_z);
  return (tablas_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::genera_reporte_x_zona(String mizona_z)
{
  String descri_z, alm_z, strunids_z, pvta_z, nombre_z, pralm_z, ulalm_z;
  int rengs_z, ii_z, ancho_z, tablas_z, nelemxtabla_z, columnas_z;
  bool ultimo_z;
  TLocateOptions Opts;
  Opts.Clear();
  TProgressBar *ProgressBar2;
  ProgressBar2 = new TProgressBar (this);
  ProgressBar2->Parent = Panel1;
  ProgressBar2->Step = 1;
  ProgressBar2->Height = 18;
  ProgressBar2->Width = Panel1->Width - 4;
  ProgressBar2->Left = 2;
  ProgressBar2->Top = Panel1->Height - 40;
  ProgressBar2->Min = 0;
  qry_acumxpvt->Close();
  qry_acumxpvt->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumxpvt->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumxpvt->ParamByName("zonaini")->AsString = mizona_z;
  qry_acumxpvt->ParamByName("zonafin")->AsString = mizona_z;
  qry_acumxpvt->ParamByName("ptvtaini")->AsString = "";
  qry_acumxpvt->ParamByName("ptvtafin")->AsString = "zz";
  qry_acumxpvt->ParamByName("lineaini")->AsString = "";
  qry_acumxpvt->ParamByName("lineafin")->AsString = "zz";
  qry_acumxpvt->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxpvt->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxpvt->Open();
  pralm_z = ""; ulalm_z = "zz";
  if(zona_z == "05") {
     pralm_z = "BO"; ulalm_z = "BO";
  }
  totexizon_z = obten_ultimo_costo(fecfin_z, pralm_z, ulalm_z, "", "zz", zona_z, zona_z);

  qry_acumxlin->Close();
  qry_acumxlin->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumxlin->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumxlin->ParamByName("zonaini")->AsString = mizona_z;
  qry_acumxlin->ParamByName("zonafin")->AsString = mizona_z;
  qry_acumxlin->ParamByName("ptvtaini")->AsString = "";
  qry_acumxlin->ParamByName("ptvtafin")->AsString = "zz";
  qry_acumxlin->ParamByName("lineaini")->AsString = "";
  qry_acumxlin->ParamByName("lineafin")->AsString = "zz";
  qry_acumxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxlin->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxlin->Open();
  qry_lineas->Close();
  qry_lineas->ParamByName("cia")->AsInteger = cia_z;
  qry_lineas->Open();

  columnas_z = qry_acumxpvt->RecordCount + 2;
  tablas_z   = divent(columnas_z, 20, 11).ToInt();
  nelemxtabla_z = miceil(columnas_z, tablas_z);
  anchopag_z = nelemxtabla_z * 20 + 11;
  if(anchopag_z > 132) {
    anchopag_z = 132;
  } else if (anchopag_z > 90) {
    anchopag_z = 90;
  } else {
    anchopag_z = 80;
  }
  ProgressBar2->Max = qry_acumxlin->RecordCount * tablas_z;

  for(int jj_z = 0; jj_z < tablas_z; jj_z++) {
    primerelem_z = jj_z * nelemxtabla_z + 1;
    ultimoelem_z = primerelem_z + nelemxtabla_z -1;
    rengs_z= qry_lineas->RecordCount;
    ii_z=0;
    if(!primero_z) {
      report_encab(); primero_z = 1;
    } else {
      if(!checa_saltopag(rengs_z + 5)) report_subencab_tabla_x_zona();
    }
    for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
      linea_z = qry_lineas->FieldByName("linea")->AsString;
      if(ii_z == rengs_z) ultimo_z = true; else ultimo_z = false;
      checa_saltopag(3);
      pralm_z = ""; ulalm_z = "zz";
      if(zona_z == "05") {
        pralm_z = "BO"; ulalm_z = "BO";
      }
      exixlin_z = obten_ultimo_costo(fecfin_z, pralm_z, ulalm_z, linea_z, linea_z, zona_z, zona_z);
      imprime_ren_x_zona(ultimo_z);
      ii_z++;
      ProgressBar2->StepIt();
    }
    imprime_total_x_zona();
  }
  delete ProgressBar2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::imprime_ren_x_zona(bool ultimo_z)
{

  double importe_z =0, tothor_z=0, porc_z, rot_z;
  String pvta_z, nombre_z, strporc_z;
  int mipos_z=1;
  if(ultimo_z)
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust(linea_z, 4));
  totcosxzon_z = qry_zonas->FieldByName("costotot")->AsFloat;
  for(qry_acumxpvt->First(); !qry_acumxpvt->Eof; qry_acumxpvt->Next()) {
    pvta_z = qry_acumxpvt->FieldByName("ptvta")->AsString;
    totcospvtaxzona_z = qry_acumxpvt->FieldByName("costotot")->AsFloat;
    qry_dato_zona_pvta_linea->Close();
    qry_dato_zona_pvta_linea->ParamByName("fecini")->AsDateTime =fecini_z;
    qry_dato_zona_pvta_linea->ParamByName("fecfin")->AsDateTime =fecfin_z;
    qry_dato_zona_pvta_linea->ParamByName("ptvtaini")->AsString = pvta_z;
    qry_dato_zona_pvta_linea->ParamByName("ptvtafin")->AsString = pvta_z;
    qry_dato_zona_pvta_linea->ParamByName("lineaini")->AsString = linea_z;
    qry_dato_zona_pvta_linea->ParamByName("lineafin")->AsString = linea_z;
    qry_dato_zona_pvta_linea->ParamByName("zonaini")->AsString = zona_z;
    qry_dato_zona_pvta_linea->ParamByName("zonafin")->AsString = zona_z;
    qry_dato_zona_pvta_linea->ParamByName("idtarea")->AsInteger = idtarea_z;
    qry_dato_zona_pvta_linea->ParamByName("cia")->AsInteger = cia_z;
    qry_dato_zona_pvta_linea->Open();
    importe_z = 0;
    if(!qry_dato_zona_pvta_linea->IsEmpty()) {
      importe_z = qry_dato_zona_pvta_linea->FieldByName("costotot")->AsFloat;
    }
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      strporc_z = rjust(calcu_strporc(importe_z, totcospvtaxzona_z, "0.00"),5);
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", importe_z), 12));
      fprintf(archout, "%s|", strporc_z);
    }
    tothor_z += importe_z;
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", tothor_z), 12));
    strporc_z = rjust(calcu_strporc(tothor_z, totcosxzon_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", exixlin_z), 12));
    strporc_z = rjust(calcu_strporc(exixlin_z, totexizon_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    if(tothor_z)  rot_z = exixlin_z / tothor_z * 30; else rot_z = 0;
    fprintf(archout, "%s|", rjust(FormatFloat("##0.0", rot_z), 6));
  }
  if(ultimo_z)
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::imprime_total_x_zona()
{

  double importe_z =0, tothor_z=0, porc_z, rot_z;
  String pvta_z, nombre_z, strporc_z;
  int mipos_z=1;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("Tot.", 4));
  totcosxzon_z = qry_zonas->FieldByName("costotot")->AsFloat;

  for(qry_acumxpvt->First(); !qry_acumxpvt->Eof; qry_acumxpvt->Next()) {
    pvta_z = qry_acumxpvt->FieldByName("ptvta")->AsString;
    totcospvtaxzona_z = qry_acumxpvt->FieldByName("costotot")->AsFloat;
    importe_z = totcospvtaxzona_z;
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      strporc_z = rjust(calcu_strporc(importe_z, totcosxzon_z, "0.00"),5);
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", importe_z), 12));
      fprintf(archout, "%s|", strporc_z);
    }
    tothor_z += importe_z;
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", tothor_z), 12));
    strporc_z = rjust(calcu_strporc(tothor_z, totcosxzon_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", totexizon_z), 12));
    strporc_z = rjust(calcu_strporc(totexizon_z, totexizon_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    if(tothor_z)  rot_z = totexizon_z / tothor_z * 30; else rot_z = 0;
    fprintf(archout, "%s|", rjust(FormatFloat("##0.0", rot_z), 6));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
  salta_linea();
}
//---------------------------------------------------------------------------


String __fastcall TForm_tabcvta::calcu_strporc(double imp_z, double tot_z, String formato_z)
{
  String str_z="";
  if(tot_z) str_z = FormatFloat( formato_z, (imp_z / tot_z) * 100);
  return(str_z);
}

String __fastcall TForm_tabcvta::busca_nombre(String tipo_z, String dato_z)
{
  String sql_z, nombre_z="";
  if(tipo_z == "UBICA") {
    sql_z = "select nombre as nombre from ptovta where clave = :DATO and cia = :CIA";
  }
  if(tipo_z == "ZONA") {
    sql_z = "select nombre as nombre from zonas where zona = :DATO";
  }
  if(tipo_z == "LINEA") {
    sql_z = "select descri as nombre from lineas where numero = :DATO and cia = :CIA";
  }
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = sql_z;
  dm->qry_maxidvnd->ParamByName("DATO")->AsString = dato_z;
  if(tipo_z == "UBICA" || tipo_z == "LINEA") {
    dm->qry_maxidvnd->ParamByName("cia")->AsInteger = cia_z;
  }
  dm->qry_maxidvnd->Open();
  if(!dm->qry_maxidvnd->IsEmpty()) nombre_z = dm->qry_maxidvnd->FieldByName("nombre")->AsString;
  if(tipo_z == "ZONA" && dato_z == "-1") nombre_z = "SUBTOTAL";
  if(tipo_z == "ZONA" && dato_z == "-2") {
    nombre_z = nombremes_z(date_mesantini->Date, date_mesantfin->Date);
  }
  if(tipo_z == "ZONA" && dato_z == "-3") {
    nombre_z = nombremes_z(date_anuantini->Date, date_anuantfin->Date);
  }
  return(nombre_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::impri_renglon(String codigo_z, String situacion_z)
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

void __fastcall TForm_tabcvta::report_subtotxlinea()
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

void __fastcall TForm_tabcvta::salta_linea()
{
  fprintf(archout, "\n");
  lineas_z++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_encab()
{
  String titulo_z;
  int idtpvt_z=0;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s tabcvta %s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), (cjust(dm->diremp_z, 60).TrimRight()), pagina_z
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
  titulo_z = "Analisis de Costo de Ventas Netas";

  idtpvt_z = grp_tiporep->ItemIndex; // El query, en 1 es el tipo de sábana
  if(idtpvt_z == 0 || idtpvt_z == 1) titulo_z += "Tradicional";
  if(idtpvt_z == 0) titulo_z += "-";
  if(idtpvt_z == 0 || idtpvt_z == 2) titulo_z += "Fonacot";
  if(idtpvt_z == 0) titulo_z += "-";
  if(idtpvt_z == 0 || idtpvt_z == 3) titulo_z += "Fide";
  if(idtpvt_z == 0) titulo_z += "-";
  if(idtpvt_z == 0 || idtpvt_z == 4) titulo_z += "Imevi";
  fprintf(archout, "%s\n", titulo_z);

  titulo_z = "Validacion de Costos por Lineas y Zonas";
  fprintf(archout, "%s\n", titulo_z);
  lineas_z = 8;
  if(enc_z == "ARTICULOS_X_PTOVTA")
    report_subencab();
  else if(enc_z == "DATOS_X_SITUACION")
    report_subencab_sit();
  else if(enc_z == "CTO_VTA_X_LINEA_PVTA")
    report_subencab_tabla_x_zona();
  else if(enc_z == "CTO_VTA_X_ZONA_X_LINEA")
    report_subencab_tabla_zonas_general();
  else if(enc_z == "PARTICIPACION_EXISTENCIAS")
    report_subencab_participacion_existencias();
  else if(enc_z == "EXHIBICION_X_LINEA")
    report_subencab_exhib_x_linea();
  else if(enc_z == "TABLA_X_TIPO_VTA")
    report_subencab_tabla_x_tipo_vta();
  else if(enc_z == "TABLA_X_CYC")
    report_subencab_tabla_cyc();

}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_subencab()
{
  String titulo_z;
  int ancho_z;
  titulo_z = busca_nombre("LINEA", linea_z);
  fprintf(archout, "%sLinea:%s%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    antlin_z + " " + titulo_z,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  salta_linea();
  ancho_z = (qry_analixalm->RecordCount + 1) * 5 + 14 + 31 + 13 + 10;
  if(ancho_z > 132) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  } if(ancho_z > 90) {
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

void __fastcall TForm_tabcvta::report_subencab_tabla_x_zona()
{

  String pvta_z, nombre_z;
  int ancho_z=0, font_z = 0, mipos_z=1;
  nombre_z = busca_nombre("ZONA", zona_z);
  if(nombre_z.SubString(1,4) == "____") nombre_z = nombre_z.SubString(6,30);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "Zona:%s", zona_z + " " + nombre_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  ancho_z = ((ultimoelem_z - primerelem_z + 1) * 20) + 11;
  if(ancho_z > 90) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  } else if( ancho_z > 80) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  } else {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  }
  fprintf(archout, "%s", pvta_z.StringOfChar('_',6));
  for(int ll_z=0; ll_z < qry_acumxpvt->RecordCount+1; ll_z++) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s", pvta_z.StringOfChar('_',13));
      fprintf(archout, "%s", pvta_z.StringOfChar('_',7));
    }
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s", pvta_z.StringOfChar('_',13));
      fprintf(archout, "%s", pvta_z.StringOfChar('_',7));
  }
  salta_linea();
  mipos_z = 1;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("LINE", 4));
  for(qry_acumxpvt->First(); !qry_acumxpvt->Eof; qry_acumxpvt->Next()) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      pvta_z = qry_acumxpvt->FieldByName("ptvta")->AsString;
      nombre_z = busca_nombre("UBICA", pvta_z);
      fprintf(archout, "%s|  %%  |", ljust(pvta_z + " " + nombre_z, 12));
    }
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|  %%  |", rjust("Total", 12));
    fprintf(archout, "%s|  %%  |", rjust("Existencia", 12));
    fprintf(archout, "%s|", rjust("RotDia", 6));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

String __fastcall TForm_tabcvta::nombremes_z(double mesini_z, double mesfin_z)
{
  String mimesant_z, mianuant_z, mes1_z, mes2_z, anu1_z;
  mimesant_z = nommes(FormatDateTime("mm", mesini_z).ToInt());
  mimesant_z = mimesant_z.SubString(1,3);
  mes1_z = nommes(FormatDateTime("mm", mesfin_z).ToInt());
  mimesant_z += "-" + mes1_z.SubString(1,3);
  mimesant_z += "/" + FormatDateTime("yyyy", mesfin_z);
  return(mimesant_z);
}
//---------------------------------------------------------------------------

bool __fastcall TForm_tabcvta::checa_saltopag(int numero_de_lineas)
{
  bool haysalto_z = false;
  if(lineas_z > ( LINEAS_X_PAG - numero_de_lineas) ) {
    fprintf(archout, "%c", 12); pagina_z++; report_encab();
    haysalto_z = true;
  }
  return(haysalto_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::reporte_datos_x_sit()
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
    fprintf(archout, "%s", ljust("",20));
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
  fprintf(archout, "%s", ljust("",20));
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

void __fastcall TForm_tabcvta::report_subencab_sit()
{
  String titulo_z;
  int ancho_z;
  titulo_z = "Total de Costo de Ventas por Tipo de Mercancia";
  fprintf(archout, "%s%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF),
    cjust(titulo_z, 80)
  );
  salta_linea();
  fprintf(archout, "%s", ljust("",20));
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


void __fastcall TForm_tabcvta::date_feciniExit(TObject *Sender)
{
  int mm_z, aa_z, dd_z=1;
  TDateTime fecha_z;
  fecha_z = date_fecini->Date;
  date_mesantini->Date = PrimerDiaMes(IncMonth(fecha_z, -1));
  date_mesantfin->Date = UltimoDiaMes(date_mesantini->Date);
  date_anuantini->Date = PrimerDiaMes(IncMonth(fecha_z, -12));
  date_anuantfin->Date = UltimoDiaMes(date_anuantini->Date);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::tabla_total_x_zona()
{

  double importe_z =0, tothor_z=0, porc_z, rot_z, mesini_z, mesfin_z;
  String pvta_z, nombre_z, strporc_z, anttipo_z, tipo_z;
  int mipos_z=1, columnas_z=0, tablas_z=0, nelemxtabla_z, rengs_z;
  enc_z="CTO_VTA_X_ZONA_X_LINEA";
  anttipo_z = "-1";
  TProgressBar *ProgressBar1;
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = Panel1;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Width = Panel1->Width - 4;
  ProgressBar1->Left = 2;
  ProgressBar1->Top = Panel1->Height - 20;
  ProgressBar1->Min = 0;
  qry_zonas2->Close();
  qry_zonas2->Open();
  totcosvta_z=0; totcoscan_z=0;
  ProgressBar1->Max = qry_zonas->RecordCount;
  for(qry_zonas->First(); !qry_zonas->Eof; qry_zonas->Next()) {
    tipo_z = qry_zonas->FieldByName("tipo")->AsString;
    zona_z = qry_zonas->FieldByName("zona")->AsString;
    importe_z = qry_zonas->FieldByName("costotot")->AsFloat;
    if(anttipo_z == "-1") anttipo_z = tipo_z;
    if(anttipo_z != tipo_z) {
      qry_zonas2->Append();
      qry_zonas2->FieldByName("tipo")->AsString = tipo_z;
      qry_zonas2->FieldByName("zona")->AsString = "-1";
      qry_zonas2->Post();
      qry_zonas2->Append();
      qry_zonas2->FieldByName("tipo")->AsString = tipo_z;
      qry_zonas2->FieldByName("zona")->AsString = "-2";
      qry_zonas2->Post();
      qry_zonas2->Append();
      qry_zonas2->FieldByName("tipo")->AsString = tipo_z;
      qry_zonas2->FieldByName("zona")->AsString = "-3";
      qry_zonas2->Post();
      anttipo_z = tipo_z;
    }
    if(qry_zonas->FieldByName("tipo")->AsString == "1") {
      totcosvta_z += importe_z;
    } else {
      totcoscan_z += importe_z;
    }
    qry_zonas2->Append();
    qry_zonas2->FieldByName("tipo")->AsString = tipo_z;
    qry_zonas2->FieldByName("zona")->AsString = zona_z;
    qry_zonas2->FieldByName("costotot")->AsFloat = importe_z;
    qry_zonas2->Post();
  }
  qry_acumxlin->Close();
  qry_acumxlin->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumxlin->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumxlin->ParamByName("zonaini")->AsString = "";
  qry_acumxlin->ParamByName("zonafin")->AsString = "zz";
  qry_acumxlin->ParamByName("ptvtaini")->AsString = "";
  qry_acumxlin->ParamByName("ptvtafin")->AsString = "zz";
  qry_acumxlin->ParamByName("lineaini")->AsString = "";
  qry_acumxlin->ParamByName("lineafin")->AsString = "zz";
  qry_acumxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxlin->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxlin->Open();
  qry_lineas->Close();
  qry_lineas->ParamByName("cia")->AsInteger = cia_z;
  qry_lineas->Open();
  totexizon_z = obten_ultimo_costo(fecfin_z, "", "zz", "", "zz", "", "zz");
  mipos_z = totexizon_z;

  qry_zonas3->Close();
  qry_zonas3->Open();
  totcosmesan_z = 0;
  totcosanuan_z = 0;
  for(qry_zonas3->First(); !qry_zonas3->Eof; qry_zonas3->Next()) {
    if(qry_zonas3->FieldByName("tipo")->AsString == "1") {
      zona_z = qry_zonas3->FieldByName("zona")->AsString;
      mesini_z = date_mesantini->Date;
      mesfin_z = date_mesantfin->Date;
      totcosmesan_z += busca_dato_mesant(mesini_z, mesfin_z, "", "zz", "", "zz", zona_z, zona_z);
      mesini_z = date_anuantini->Date;
      mesfin_z = date_anuantfin->Date;
      totcosanuan_z += busca_dato_mesant(mesini_z, mesfin_z, "", "zz", "", "zz", zona_z, zona_z);
    }
  }


  columnas_z = qry_zonas2->RecordCount + 2;
  tablas_z   = divent(columnas_z, 20, 4).ToInt();
  nelemxtabla_z = miceil(columnas_z, tablas_z);
  anchopag_z = nelemxtabla_z * 20 + 5;
  if(anchopag_z > 132) {
    anchopag_z = 132;
  } else if (anchopag_z > 90) {
    anchopag_z = 90;
  } else {
    anchopag_z = 80;
  }
  ProgressBar1->Max = tablas_z;
  primero_z = 0;
  for(int jj_z = 0; jj_z < tablas_z; jj_z++) {
    ProgressBar1->StepIt();
    primerelem_z = jj_z * nelemxtabla_z + 1;
    ultimoelem_z = primerelem_z + nelemxtabla_z -1;
    rengs_z = qry_lineas->RecordCount + 2;
    if(!primero_z) {
      checa_saltopag(100 + 1); primero_z = 1;
    } else {
      if(!checa_saltopag(rengs_z + 1)) report_subencab_tabla_zonas_general();
    }
    imprime_tabla_x_zona_global();
    salta_linea();
    salta_linea();
  }
  delete ProgressBar1;
  salta_linea();
  salta_linea();
}
//---------------------------------------------------------------------------


void __fastcall TForm_tabcvta::imprime_tabla_x_zona_global()
{
  int ancho_z=0, font_z = 0, ii_z=0, mipos_z=1;
  TLocateOptions Opts;
  bool ultimo_z=false;
  String anttipo_z, tipo_z, strporc_z, zona2_z, mizon_z;
  double tothor_z=0, subtot_z=0, cosmesan_z=0, cosanuan_z=0,
    mesini_z, mesfin_z, importe_z=0, rot_z=0;
  Opts.Clear();
  ii_z = 0;
  TProgressBar *ProgressBar2;
  ProgressBar2 = new TProgressBar (this);
  ProgressBar2->Parent = Panel1;
  ProgressBar2->Step = 1;
  ProgressBar2->Height = 18;
  ProgressBar2->Width = Panel1->Width - 4;
  ProgressBar2->Left = 2;
  ProgressBar2->Top = Panel1->Height - 40;
  ProgressBar2->Min = 0;
  ProgressBar2->Max = qry_acumxlin->RecordCount;

  for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
    mipos_z = 1;
    ii_z++;
    ProgressBar2->StepIt();
    if(ii_z == qry_lineas->RecordCount) ultimo_z = true;
    linea_z = qry_lineas->FieldByName("linea")->AsString;
    if(ultimo_z)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
    fprintf(archout, "|%s|", ljust(linea_z, 4));
    anttipo_z = "-1"; exixlin_z = 0; subtot_z=0; tothor_z=0;
    qry_exiulcos->First();
    if(qry_exiulcos->Locate("linea", linea_z, Opts))
      exixlin_z = qry_exiulcos->FieldByName("existot")->AsFloat;
    for(qry_zonas2->First(); !qry_zonas2->Eof; qry_zonas2->Next()) {
      zona2_z = qry_zonas2->FieldByName("zona")->AsString;
      tipo_z = qry_zonas2->FieldByName("tipo")->AsString;
      totcospvtaxzona_z = qry_zonas2->FieldByName("costotot")->AsFloat;
      if(zona2_z == "-1") {
        importe_z = subtot_z;
        strporc_z = rjust(calcu_strporc(subtot_z, totcosvta_z, "0.00"),5);
      } else if (zona2_z == "-2") {
        mesini_z = date_mesantini->Date;
        mesfin_z = date_mesantfin->Date;
        cosmesan_z =0;
        for(qry_zonas3->First(); !qry_zonas3->Eof; qry_zonas3->Next()) {
          if(qry_zonas3->FieldByName("tipo")->AsString == "1") {
            mizon_z = qry_zonas3->FieldByName("zona")->AsString;
            cosmesan_z += busca_dato_mesant(mesini_z, mesfin_z,linea_z, linea_z,  "", "zz", mizon_z, mizon_z);
          }
        }
        strporc_z = rjust(calcu_strporc(cosmesan_z, totcosmesan_z, "0.00"),5);
        importe_z = cosmesan_z;
      } else if (zona2_z == "-3") {
        mesini_z = date_anuantini->Date;
        mesfin_z = date_anuantfin->Date;
        cosmesan_z =0;
        for(qry_zonas3->First(); !qry_zonas3->Eof; qry_zonas3->Next()) {
          if(qry_zonas3->FieldByName("tipo")->AsString == "1") {
            mizon_z = qry_zonas3->FieldByName("zona")->AsString;
            cosmesan_z += busca_dato_mesant(mesini_z, mesfin_z, linea_z, linea_z,  "", "zz", mizon_z, mizon_z);
          }
        }
        strporc_z = rjust(calcu_strporc(cosmesan_z, totcosanuan_z, "0.00"),5);
        importe_z = cosmesan_z;
      } else {
        zona_z = zona2_z;
        importe_z = busca_dato_mesant(fecini_z, fecfin_z, linea_z, linea_z, "", "zz", zona_z, zona_z);
        strporc_z = rjust(calcu_strporc(importe_z, totcospvtaxzona_z, "0.00"),5);
        tothor_z += importe_z;
        subtot_z += importe_z;
      }
      if(anttipo_z == "-1") anttipo_z = tipo_z;
      if(tipo_z != anttipo_z) {
        anttipo_z = tipo_z; subtot_z =0;
      }
      if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
        fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", importe_z), 12));
        fprintf(archout, "%s|", strporc_z);
      }
      mipos_z++;
    }
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", tothor_z), 12));
      strporc_z = rjust(calcu_strporc(tothor_z, totcosxzon_z, "0.00"),5);
      fprintf(archout, "%s|", strporc_z);
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", exixlin_z), 12));
      strporc_z = rjust(calcu_strporc(exixlin_z, totexizon_z, "0.00"),5);
      fprintf(archout, "%s|", strporc_z);
      if(tothor_z)  rot_z = totexizon_z / tothor_z * 30; else rot_z = 0;
      fprintf(archout, "%s|", rjust(FormatFloat("##0.00", rot_z), 6));
    }
    if(ultimo_z)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
    salta_linea();
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("Tot.", 4));
  anttipo_z = "-1"; exixlin_z = 0; subtot_z=0; tothor_z=0;
  qry_exiulcos->First();
  if(qry_exiulcos->Locate("linea", linea_z, Opts))
      exixlin_z = qry_exiulcos->FieldByName("existot")->AsFloat;
  mipos_z = totexizon_z;
  mipos_z = 1;
  // --> Ahora voy a Imprimir los totales


  // --> Aqui van los totales
  for(qry_zonas2->First(); !qry_zonas2->Eof; qry_zonas2->Next()) {
    zona2_z = qry_zonas2->FieldByName("zona")->AsString;
    tipo_z = qry_zonas2->FieldByName("tipo")->AsString;
    totcospvtaxzona_z = qry_zonas2->FieldByName("costotot")->AsFloat;
    if(zona2_z == "-1") {
      importe_z = subtot_z;
      strporc_z = rjust(calcu_strporc(subtot_z, totcosvta_z, "0.00"),5);
    } else if (zona2_z == "-2") {
      strporc_z = rjust(calcu_strporc(totcosmesan_z, totcosmesan_z, "0.00"),5);
      importe_z = totcosmesan_z;
    } else if (zona2_z == "-3") {
      strporc_z = rjust(calcu_strporc(totcosanuan_z, totcosanuan_z, "0.00"),5);
      importe_z = totcosanuan_z;
    } else {
      zona_z = zona2_z;
      importe_z = busca_dato_mesant(fecini_z, fecfin_z, "", "zz", "", "zz", zona_z, zona_z);
      strporc_z = rjust(calcu_strporc(importe_z, totcosvta_z, "0.00"),5);
      tothor_z += importe_z;
      subtot_z += importe_z;
    }
    if(anttipo_z == "-1") anttipo_z = tipo_z;
    if(tipo_z != anttipo_z) {
      anttipo_z = tipo_z; subtot_z =0;
    }
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", importe_z), 12));
      fprintf(archout, "%s|", strporc_z);
    }
    mipos_z++;
  }
  // Ya Imprimi los totales x Zona, ahora imprimo los datos de Total
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", tothor_z), 12));
    strporc_z = rjust(calcu_strporc(tothor_z, totcosxzon_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", totexizon_z), 12));
    strporc_z = rjust(calcu_strporc(totexizon_z, totexizon_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    if(tothor_z)  rot_z = totexizon_z / tothor_z * 30; else rot_z = 0;
    fprintf(archout, "%s|", rjust(FormatFloat("0.0", rot_z), 6));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
  delete ProgressBar2;

  // Aqui va la Impresion del Total de Zonas
}
//---------------------------------------------------------------------------

double __fastcall TForm_tabcvta::busca_dato_mesant(
  double mesini_z, double mesfin_z, String prlinea_z, String ullinea_z,
  String almini_z, String almfin_z, String zonaini_z, String zonafin_z
)
{
  double costo_z=0;
  qry_dato_zona_pvta_linea->Close();
  qry_dato_zona_pvta_linea->ParamByName("fecini")->AsDateTime = mesini_z;
  qry_dato_zona_pvta_linea->ParamByName("fecfin")->AsDateTime = mesfin_z;
  qry_dato_zona_pvta_linea->ParamByName("ptvtaini")->AsString = almini_z;
  qry_dato_zona_pvta_linea->ParamByName("ptvtafin")->AsString = almfin_z;
  qry_dato_zona_pvta_linea->ParamByName("lineaini")->AsString = prlinea_z;
  qry_dato_zona_pvta_linea->ParamByName("lineafin")->AsString = ullinea_z;
  qry_dato_zona_pvta_linea->ParamByName("zonaini")->AsString  = zonaini_z;
  qry_dato_zona_pvta_linea->ParamByName("zonafin")->AsString  = zonafin_z;
  qry_dato_zona_pvta_linea->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_dato_zona_pvta_linea->ParamByName("cia")->AsInteger     = cia_z;
  qry_dato_zona_pvta_linea->Open();
  for(qry_dato_zona_pvta_linea->First(); !qry_dato_zona_pvta_linea->Eof; qry_dato_zona_pvta_linea->Next()) {
    costo_z += qry_dato_zona_pvta_linea->FieldByName("costotot")->AsFloat;
  }
  return (costo_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_subencab_tabla_zonas_general()
{

  String pvta_z, nombre_z;
  int ancho_z=0, font_z = 0, mipos_z=1;
  double mesini_z, mesfin_z;
  String tipo_z, anttipo_z;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", cjust("Tabla Global de Costos x Zonas",40));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  ancho_z = ((ultimoelem_z - primerelem_z + 1) * 20) + 11;
  if(ancho_z > 90) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  } else if( ancho_z > 80) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  } else {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  }
  fprintf(archout, "%s", pvta_z.StringOfChar('_',6));
  for(int ll_z=0; ll_z < qry_zonas2->RecordCount; ll_z++) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s", pvta_z.StringOfChar('_',13));
      fprintf(archout, "%s", pvta_z.StringOfChar('_',7));
    }
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s", pvta_z.StringOfChar('_',13));
      fprintf(archout, "%s", pvta_z.StringOfChar('_',7));
  }
  salta_linea();
  mipos_z = 1;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("LINE", 4));
  anttipo_z = "-1";
  for(qry_zonas2->First(); !qry_zonas2->Eof; qry_zonas2->Next()) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      zona_z = qry_zonas2->FieldByName("zona")->AsString;
      nombre_z = busca_nombre("ZONA", zona_z);
      if(nombre_z.SubString(1,4) == "ZONA" || nombre_z.SubString(1,4) == "____")
         nombre_z = nombre_z.SubString(6,30);
      if(zona_z == "-1" || zona_z == "-2" || zona_z == "-3") zona_z="";
      fprintf(archout, "%s|  %%  |", ljust((zona_z + " " + nombre_z).Trim(), 12));
    }
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|  %%  |", rjust("Total", 12));
    fprintf(archout, "%s|  %%  |", rjust("Existencia", 12));
    fprintf(archout, "%s|", rjust("RotDia", 6));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

// --> Voy a Calcular la participación de las Existencias por Zona <-- //
void __fastcall TForm_tabcvta::participacion_existencias()
{
  String nombre_z, tipo_z, strporc_z;
  int rengs_z=0, ii_z=0;
  bool ultimo_z;
  double totexi_z=0, exiszon_z=0, totcosvta_z=0, importe_z=0;
  enc_z="PARTICIPACION_EXISTENCIAS";
  totexi_z = obten_ultimo_costo(fecfin_z, "", "zz", "", "zz", "", "zz");
  qry_zonas3->Close();
  qry_zonas3->Open();
  for(qry_zonas3->First(); !qry_zonas3->Eof; qry_zonas3->Next()) {
    zona_z   = qry_zonas3->FieldByName("zona")->AsString;
    tipo_z   = qry_zonas3->FieldByName("tipo")->AsString;
    if(tipo_z == "1")
      totcosvta_z += busca_dato_mesant(fecini_z, fecfin_z, "", "zz", "", "zz", zona_z, zona_z);
  }

  checa_saltopag(100 + 1); primero_z = 1;
  rengs_z = qry_zonas3->RecordCount;
  for(qry_zonas3->First(); !qry_zonas3->Eof; qry_zonas3->Next()) {
    ii_z++;
    if(ii_z == rengs_z) ultimo_z = true; else ultimo_z = false;
    zona_z   = qry_zonas3->FieldByName("zona")->AsString;
    nombre_z = qry_zonas3->FieldByName("nombre")->AsString;
    tipo_z   = qry_zonas3->FieldByName("tipo")->AsString;
    exiszon_z = obten_ultimo_costo(fecfin_z, "", "zz", "", "zz", zona_z, zona_z);
    if(tipo_z == "1") {
      importe_z = busca_dato_mesant(fecini_z, fecfin_z, "", "zz", "", "zz", zona_z, zona_z);
    } else {
      importe_z = 0;
    }
    strporc_z = rjust(calcu_strporc(exiszon_z, totexi_z, "0.00"),5);
    fprintf(archout, "%s|", ljust("",4));
    if(ultimo_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

    fprintf(archout, "%s %s|", ljust(zona_z,2), ljust(nombre_z,30));
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", exiszon_z),12));
    strporc_z = rjust(calcu_strporc(exiszon_z, totexi_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", importe_z),12));
    strporc_z = rjust(calcu_strporc(importe_z, totcosvta_z, "0.00"),5);
    fprintf(archout, "%s|", strporc_z);
    if(ultimo_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
    salta_linea();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_subencab_participacion_existencias()
{

  String pvta_z, nombre_z;
  int ancho_z=0, font_z = 0, mipos_z=1;
  double mesini_z, mesfin_z;
  String tipo_z, anttipo_z;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", cjust("Analisis de Existencias",40));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", cjust("Participacion de las Existencias",40));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  fprintf(archout, "%s", ljust("",4));
  fprintf(archout, "%s", pvta_z.StringOfChar('_', 72));
  salta_linea();
  fprintf(archout, "%s", ljust("",4));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", cjust("ZONA", 33));
  fprintf(archout, "%s|", rjust("Existencia", 12));
  fprintf(archout, "%s|", rjust("%%", 5));
  fprintf(archout, "%s|", rjust("Costo Vta", 12));
  fprintf(archout, "%s|", rjust("%%", 5));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

double __fastcall TForm_tabcvta::obten_ultimo_costo(double fecha_z, String almini_z, String almfin_z,
          String lineaini_z, String lineafin_z, String zonaini_z, String zonafin_z)
{
  double costo_z=0;
  qry_exiulcos->Close();
  qry_exiulcos->ParamByName("fecfin")->AsDateTime  = fecha_z;
  qry_exiulcos->ParamByName("almini")->AsString    = almini_z;
  qry_exiulcos->ParamByName("almfin")->AsString    = almfin_z;
  qry_exiulcos->ParamByName("lineaini")->AsString  = lineaini_z;
  qry_exiulcos->ParamByName("lineafin")->AsString  = lineafin_z;
  qry_exiulcos->ParamByName("zonaini")->AsString   = zonaini_z;
  qry_exiulcos->ParamByName("zonafin")->AsString   = zonafin_z;
  qry_exiulcos->ParamByName("cia")->AsInteger      = cia_z;
  qry_exiulcos->Open();
  for(qry_exiulcos->First(); !qry_exiulcos->Eof; qry_exiulcos->Next()) {
    costo_z += qry_exiulcos->FieldByName("existot")->AsFloat;
  }
  return(costo_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_subencab_exhib_x_linea()
{
  String pvta_z, nombre_z;
  int ancho_z=0, font_z = 0, mipos_z=1;
  double mesini_z, mesfin_z;
  String tipo_z, anttipo_z;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  fprintf(archout, "%s", cjust("Participacion de Mercancia de Exhibicion x Linea",80));
  salta_linea();
  ancho_z = ((ultimoelem_z - primerelem_z +1) * 7) + 24;
  if(ancho_z > 90) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  } else if( ancho_z > 80) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  } else {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  }
  fprintf(archout, "%s", pvta_z.StringOfChar('_',20));
  for(int ll_z=0; ll_z < qry_lineas->RecordCount; ll_z++) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s", pvta_z.StringOfChar('_',7));
    }
    mipos_z++;
  }
  salta_linea();
  mipos_z = 1;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", cjust("Zona", 20));
  for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      linea_z = qry_lineas->FieldByName("linea")->AsString;
      fprintf(archout, "%s|", cjust(linea_z, 6));
    }
    mipos_z++;
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::tabla_exhibicion_x_linea()
{

  double importe_z =0, costovta_z=0, cosmesan_z=0, mesini_z, mesfin_z, exist_z;
  String pvta_z, nombre_z, strporc_z, anttipo_z, tipo_z;
  TProgressBar *ProgressBar1;
  TLocateOptions Opts;
  Opts.Clear();
  int mipos_z=1, columnas_z=0, tablas_z=0, nelemxtabla_z, rengs_z;
  enc_z="EXHIBICION_X_LINEA";
  anttipo_z = "-1";
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = Panel1;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Width = Panel1->Width - 4;
  ProgressBar1->Left = 2;
  ProgressBar1->Top = Panel1->Height - 20;
  ProgressBar1->Min = 0;
  qry_zonas2->Close();
  qry_zonas2->Open();
  totcosvta_z=0; totcoscan_z=0;
  ProgressBar1->Max = qry_zonas3->RecordCount;
  qry_lineas->Close();
  qry_lineas->ParamByName("cia")->AsInteger = cia_z;
  qry_lineas->Open();
  qry_acumxlin->Close();
  qry_acumxlin->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumxlin->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumxlin->ParamByName("zonaini")->AsString = "zz";
  qry_acumxlin->ParamByName("zonafin")->AsString = "zz";
  qry_acumxlin->ParamByName("ptvtaini")->AsString = "";
  qry_acumxlin->ParamByName("ptvtafin")->AsString = "zz";
  qry_acumxlin->ParamByName("lineaini")->AsString = "";
  qry_acumxlin->ParamByName("lineafin")->AsString = "zz";
  qry_acumxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxlin->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxlin->Open();
  totexizon_z = 0;
  totcosvta_z = 0;
  totcosmesan_z = 0;
  qry_zonas2->Close();
  qry_zonas2->Open();

  for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
    linea_z = qry_lineas->FieldByName("linea")->AsString;
    costovta_z = 0; cosmesan_z=0;
    for(qry_zonas3->First(); !qry_zonas3->Eof; qry_zonas3->Next()) {
       zona_z = qry_zonas3->FieldByName("zona")->AsString;
       if(qry_zonas3->FieldByName("tipo")->AsString == "1") {
          cosmesan_z += busca_dato_mesant(date_mesantini->Date, date_mesantfin->Date, linea_z, linea_z, "", "zz", zona_z, zona_z);
          costovta_z += busca_dato_mesant(fecini_z, fecfin_z, linea_z, linea_z, "", "zz", zona_z, zona_z);
       }
      exist_z    = obten_ultimo_costo(fecfin_z, "", "zz", linea_z, linea_z, zona_z, zona_z);
      totexizon_z += exist_z;
      qry_zonas2->First();
      if(qry_zonas2->Locate("zona", zona_z, Opts)) {
        qry_zonas2->Edit();
      } else {
        qry_zonas2->Append();
        qry_zonas2->FieldByName("zona")->AsString = zona_z;
      }
      qry_zonas2->FieldByName("exist")->AsFloat += exist_z;
      qry_zonas2->Post();
    }
    totcosmesan_z += cosmesan_z;
    totcosvta_z   += costovta_z;

    qry_acumxlin->Append();
    qry_acumxlin->FieldByName("linea")->AsString   = linea_z;
    qry_acumxlin->FieldByName("costotot")->AsFloat = exist_z;
    qry_acumxlin->FieldByName("cosmesan")->AsFloat  = cosmesan_z;
    qry_acumxlin->FieldByName("costosi")->AsFloat  = costovta_z;
    qry_acumxlin->Post();
  }

  columnas_z = qry_acumxlin->RecordCount;
  tablas_z   = divent(columnas_z, 6, 20).ToInt();
  nelemxtabla_z = miceil(columnas_z, tablas_z);
  anchopag_z = nelemxtabla_z * 6 + 20;
  if(anchopag_z > 132) {
    anchopag_z = 132;
  } else if (anchopag_z > 90) {
    anchopag_z = 90;
  } else {
    anchopag_z = 80;
  }
  ProgressBar1->Max = tablas_z;
  primero_z = 0;
  salta_linea();
  salta_linea();
  for(int jj_z = 0; jj_z < tablas_z; jj_z++) {
    ProgressBar1->StepIt();
    primerelem_z = jj_z * nelemxtabla_z + 1;
    ultimoelem_z = primerelem_z + nelemxtabla_z -1;
    rengs_z = qry_zonas3->RecordCount + 1;
    if(!primero_z) {
      if(!checa_saltopag(rengs_z + 1)) report_subencab_exhib_x_linea();
    }
    imprime_tabla_exhib_x_linea();
    salta_linea();
    salta_linea();
  }
  delete ProgressBar1;
  salta_linea();
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::imprime_tabla_exhib_x_linea()
{
  int ancho_z=0, font_z = 0, ii_z=0, mipos_z=1;
  TLocateOptions Opts;
  bool ultimo_z=false;
  String anttipo_z, tipo_z, strporc_z, zona2_z, nombre_z;
  double tothor_z=0, subtot_z=0, totexian_z=0, cosmesan_z=0, cosanuan_z=0,
    mesini_z, mesfin_z, cvtaan_z=0, importe_z=0, exist_z=0, rot_z=0;
  Opts.Clear();
  ii_z = 0;
  TProgressBar *ProgressBar2;
  ProgressBar2 = new TProgressBar (this);
  ProgressBar2->Parent = Panel1;
  ProgressBar2->Step = 1;
  ProgressBar2->Height = 18;
  ProgressBar2->Width = Panel1->Width - 4;
  ProgressBar2->Left = 2;
  ProgressBar2->Top = Panel1->Height - 40;
  ProgressBar2->Min = 0;
  ProgressBar2->Max = qry_lineas->RecordCount;
  totexian_z = obten_ultimo_costo(date_mesantfin->Date, "", "zz", "", "zz", "", "zz");

  nombre_z = "Mes Anter (C.Vta)";
  fprintf(archout, "|%s|", ljust(nombre_z, 20));
  for(qry_acumxlin->First(); !qry_acumxlin->Eof; qry_acumxlin->Next()) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      linea_z    = qry_acumxlin->FieldByName("linea")->AsString;
      cvtaan_z  = qry_acumxlin->FieldByName("cosmesan")->AsFloat;
      strporc_z = rjust(calcu_strporc(cvtaan_z, totcosmesan_z, "0.00"),6);
      fprintf(archout, "%s|", strporc_z);
      //fprintf(archout, "%s|", rjust(FormatFloat("###,###", cvtaan_z),12) );
    }
    mipos_z++;
  }
  //fprintf(archout, "%s|", rjust(FormatFloat("###,###", totcosmesan_z),12) );
  salta_linea();
  checa_saltopag(5);
  for(qry_zonas3->First(); !qry_zonas3->Eof; qry_zonas3->Next()) {
    mipos_z = 1;
    ii_z++;
    ProgressBar2->StepIt();
    if(ii_z == qry_zonas3->RecordCount) ultimo_z = true;
    zona_z   = qry_zonas3->FieldByName("zona")->AsString;
    nombre_z = qry_zonas3->FieldByName("nombre")->AsString;
    tipo_z   = qry_zonas3->FieldByName("tipo")->AsString;
    if(tipo_z == "2") continue; // Salto la Zona si es Bodegazo
    checa_saltopag(5);
    if(ultimo_z)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
    fprintf(archout, "|%s|", ljust(zona_z + " " + nombre_z, 20));
    for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
      if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
        linea_z = qry_lineas->FieldByName("linea")->AsString;
        exist_z    = obten_ultimo_costo(fecfin_z, "", "zz", linea_z, linea_z, zona_z, zona_z);
        qry_zonas2->First();
        if( qry_zonas2->Locate("zona", zona_z, Opts) ) {
          exixlin_z = qry_zonas2->FieldByName("exist")->AsFloat;
        }
        strporc_z = rjust(calcu_strporc(exist_z, exixlin_z, "0.00"),6);
        fprintf(archout, "%s|", strporc_z);
      }
      mipos_z++;
    }
    if(ultimo_z)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
    salta_linea();
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("Porc.Costo Ventas.", 20));
  // --> Ahora voy a Imprimir los totales
  for(qry_acumxlin->First(); !qry_acumxlin->Eof; qry_acumxlin->Next()) {
    linea_z = qry_acumxlin->FieldByName("linea")->AsString;
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      exist_z = qry_acumxlin->FieldByName("costosi")->AsFloat;
      strporc_z = rjust(calcu_strporc(exist_z, totcosvta_z, "0.00"),6);
      fprintf(archout, "%s|", strporc_z);
      //fprintf(archout, "%s|", rjust(FormatFloat("###,###", exist_z),12) );
    }
    mipos_z++;
  }
  //fprintf(archout, "%s|", rjust(FormatFloat("###,###", totcosvta_z),12) );
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
  delete ProgressBar2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::tabla_costo_x_tipo_vta()
{

  double importe_z =0, costovta_z=0, cosmesan_z=0, mesini_z, mesfin_z,
    exist_z, totcmen_z, totcmay_z, totcfon_z, totcfid_z, totcime_z,
    tothor_z, totccel_z, cosmen_z, cosmay_z, cosfon_z, cosfid_z, cosime_z,
    coscel_z, costo1_z, rot_z;
  String pvta_z, nombre_z, strporc_z, anttipo_z, tipo_z;
  TProgressBar *ProgressBar1;
  TLocateOptions Opts;
  Opts.Clear();
  int mipos_z=0, columnas_z=0, tablas_z=0, nelemxtabla_z, rengs_z;
  enc_z="TABLA_X_TIPO_VTA";
  rengs_z = qry_lineas->RecordCount;
  fecini_z = date_fecini->Date;
  fecfin_z = date_fecfin->Date;
  if(!checa_saltopag(rengs_z + 2)) {
    report_subencab_tabla_x_tipo_vta();
  } else {
    report_subencab_tabla_x_tipo_vta();
  }
  totcmen_z = obten_costo_x_tipo("V", "", "zz", "TOTAL", "", "zz");
  totcmay_z = obten_costo_x_tipo("M", "", "zz", "TOTAL", "", "zz");
  totcfon_z = obten_costo_x_tipo("F", "", "zz", "TOTAL", "", "zz");
  totccel_z = obten_costo_x_tipo("U", "", "zz", "TOTAL", "", "zz");
  totcfid_z = obten_costo_x_tipo("H", "", "zz", "TOTAL", "", "zz");
  totcime_z = obten_costo_x_tipo("1", "", "zz", "TOTAL", "", "zz");
  totcosvta_z = totcmen_z + totcmay_z + totcfon_z + totccel_z + totcfid_z + totcime_z;
  totexizon_z = obten_ultimo_costo(fecfin_z, "", "zz", "", "zz", "", "zz");


  for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
    tothor_z=0; mipos_z++;
    cosmen_z = cosmay_z =  cosfon_z = cosfid_z = cosime_z = coscel_z = 0;
    if(mipos_z == rengs_z)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

    linea_z = qry_lineas->FieldByName("linea")->AsString;
    fprintf(archout, "|%s|", ljust(linea_z,4));

    cosmen_z = obten_costo_x_tipo("V", linea_z, linea_z, "TOTAL", "", "zz");
    cosfon_z = obten_costo_x_tipo("F", linea_z, linea_z, "TOTAL", "", "zz");
    cosmay_z = obten_costo_x_tipo("M", linea_z, linea_z, "TOTAL", "", "zz");
    cosfid_z = obten_costo_x_tipo("H", linea_z, linea_z, "TOTAL", "", "zz");
    cosime_z = obten_costo_x_tipo("U", linea_z, linea_z, "TOTAL", "", "zz");
    coscel_z = obten_costo_x_tipo("1", linea_z, linea_z, "TOTAL", "", "zz");
    tothor_z = cosmen_z + cosfon_z + cosmay_z + cosfid_z + cosime_z + coscel_z;

    strporc_z = rjust(calcu_strporc(cosmen_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosmen_z), 12));
    fprintf(archout, "%s|", strporc_z);

    strporc_z = rjust(calcu_strporc(cosfon_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosfon_z), 12));
    fprintf(archout, "%s|", strporc_z);

    strporc_z = rjust(calcu_strporc(cosmay_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosmay_z), 12));
    fprintf(archout, "%s|", strporc_z);

    strporc_z = rjust(calcu_strporc(cosfid_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosfid_z), 12));
    fprintf(archout, "%s|", strporc_z);

    strporc_z = rjust(calcu_strporc(cosime_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosime_z), 12));
    fprintf(archout, "%s|", strporc_z);

    strporc_z = rjust(calcu_strporc(coscel_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", coscel_z), 12));
    fprintf(archout, "%s|", strporc_z);

    strporc_z = rjust(calcu_strporc(tothor_z, totcosvta_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", tothor_z), 12));
    fprintf(archout, "%s|", strporc_z);

    exist_z = obten_ultimo_costo(fecfin_z, "", "zz", linea_z, linea_z, "", "zz");
    if(tothor_z)  rot_z = exist_z / tothor_z * 30; else rot_z = 0;
    strporc_z = rjust(FormatFloat("0.0", rot_z),5);

    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", exist_z), 12));
    fprintf(archout, "%s|", strporc_z);
    if(mipos_z == rengs_z)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
    salta_linea();
  }

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

  fprintf(archout, "|%s|", ljust("Tot.",4));

  strporc_z = rjust(calcu_strporc(totcmen_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcmen_z), 12));
  fprintf(archout, "%s|", strporc_z);

  strporc_z = rjust(calcu_strporc(totcfon_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcfon_z), 12));
  fprintf(archout, "%s|", strporc_z);

  strporc_z = rjust(calcu_strporc(totcmay_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcmay_z), 12));
  fprintf(archout, "%s|", strporc_z);

  strporc_z = rjust(calcu_strporc(totcfid_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcfid_z), 12));
  fprintf(archout, "%s|", strporc_z);

  strporc_z = rjust(calcu_strporc(totccel_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totccel_z), 12));
  fprintf(archout, "%s|", strporc_z);

  strporc_z = rjust(calcu_strporc(totcime_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcime_z), 12));
  fprintf(archout, "%s|", strporc_z);

  strporc_z = rjust(calcu_strporc(totcosvta_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcosvta_z), 12));
  fprintf(archout, "%s|", strporc_z);

  if(totcosvta_z)  rot_z = totexizon_z / totcosvta_z * 30; else rot_z = 0;
  strporc_z = rjust(FormatFloat("0.0", rot_z),5);

  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totexizon_z), 12));
  fprintf(archout, "%s|", strporc_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
  salta_linea();

}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_subencab_tabla_x_tipo_vta()
{
  String titulo_z;
  int ancho_z;
  titulo_z = "Costo de Ventas x Tipo y Linea";
  fprintf(archout, "%s", cjust(titulo_z, 80));
  salta_linea();
  titulo_z = titulo_z.StringOfChar('_',140);
  fprintf(archout, "%s", titulo_z);
  salta_linea();

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("Line",4));
  fprintf(archout, "%s|%s|", ljust("Cto.Vta.MEN",12), cjust("%",5));
  fprintf(archout, "%s|%s|", ljust("Cto.Vta.FON",12), cjust("%",5));
  fprintf(archout, "%s|%s|", ljust("Cto.Vta.MAY",12), cjust("%",5));
  fprintf(archout, "%s|%s|", ljust("Cto.Vta.FIDE",12), cjust("%",5));
  fprintf(archout, "%s|%s|", ljust("Cto.Vta.CEL",12), cjust("%",5));
  fprintf(archout, "%s|%s|", ljust("Cto.Vta.IMEVI",12), cjust("%",5));
  fprintf(archout, "%s|%s|", ljust("Total.Cto.V",12), cjust("%",5));
  fprintf(archout, "%s|%s|", ljust("Existencia",12), cjust("Rot",5));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

double __fastcall TForm_tabcvta::obten_costo_x_tipo(
  String tipo_z, String prlinea_z, String ullinea_z, String crdocon_z,
  String ptvtaini_z, String ptvtafin_z
)
{
  double costo_z = 0;
  if(tipo_z == "M") {
    qry_ctovtamay->Close();
    qry_ctovtamay->ParamByName("tipovta")->AsString = tipo_z;
    qry_ctovtamay->ParamByName("fecini")->AsDateTime = fecini_z;
    qry_ctovtamay->ParamByName("fecfin")->AsDateTime = fecfin_z;
    qry_ctovtamay->ParamByName("lineaini")->AsString = prlinea_z;
    qry_ctovtamay->ParamByName("lineafin")->AsString = ullinea_z;
    qry_ctovtamay->ParamByName("cia")->AsInteger = cia_z;
    qry_ctovtamay->Open();
    String sql_z = qry_ctovtamay->SQL->Text;
    sql_z = FormatDateTime("yyyymmdd", fecini_z);
    sql_z = FormatDateTime("yyyymmdd", fecfin_z);
    sql_z = IntToStr(qry_ctovtamay->RecordCount);
    for(qry_ctovtamay->First(); !qry_ctovtamay->Eof; qry_ctovtamay->Next()) {
      costo_z += qry_ctovtamay->FieldByName("costotot")->AsFloat;
    }
  } else {
    qry_dato_x_tipovta->Close();
    qry_dato_x_tipovta->ParamByName("tipovta")->AsString = tipo_z;
    qry_dato_x_tipovta->ParamByName("fecini")->AsDateTime = fecini_z;
    qry_dato_x_tipovta->ParamByName("fecfin")->AsDateTime = fecfin_z;
    qry_dato_x_tipovta->ParamByName("lineaini")->AsString = prlinea_z;
    qry_dato_x_tipovta->ParamByName("lineafin")->AsString = ullinea_z;
    qry_dato_x_tipovta->ParamByName("ptvtaini")->AsString = ptvtaini_z;
    qry_dato_x_tipovta->ParamByName("ptvtafin")->AsString = ptvtafin_z;
    qry_dato_x_tipovta->ParamByName("cia")->AsInteger = cia_z;
    qry_dato_x_tipovta->Open();
    for(qry_dato_x_tipovta->First(); !qry_dato_x_tipovta->Eof; qry_dato_x_tipovta->Next()) {
      if(crdocon_z == "CREDITO")
         costo_z += qry_dato_x_tipovta->FieldByName("ctocred")->AsFloat;
      else if(crdocon_z == "CONTADO")
         costo_z += qry_dato_x_tipovta->FieldByName("ctocont")->AsFloat;
      else
         costo_z += qry_dato_x_tipovta->FieldByName("costotot")->AsFloat;
    }
  }
  return (costo_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_tabcvta::imprime_tabla_credito_y_contado()
{
  enc_z="TABLA_X_CYC";
  TProgressBar *ProgressBar1;
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = Panel1;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Width = Panel1->Width - 4;
  ProgressBar1->Left = 2;
  ProgressBar1->Top = Panel1->Height - 20;
  ProgressBar1->Min = 0;
  elimina_invtmp();
  graba_invtmp("SOLO_VENTAS_TRADICIONALES_BRUTAS");
  qry_zonas->Close();
  qry_zonas->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_zonas->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_zonas->ParamByName("zonaini")->AsString = "";
  qry_zonas->ParamByName("zonafin")->AsString = "zz";
  qry_zonas->ParamByName("ptvtaini")->AsString = "";
  qry_zonas->ParamByName("ptvtafin")->AsString = "zz";
  qry_zonas->ParamByName("lineaini")->AsString = "";
  qry_zonas->ParamByName("lineafin")->AsString = "zz";
  qry_zonas->ParamByName("cia")->AsInteger = cia_z;
  qry_zonas->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_zonas->Open();
  ProgressBar1->Max = qry_zonas->RecordCount;

  primero_z = 0;
  for(qry_zonas->First(); !qry_zonas->Eof; qry_zonas->Next()) {
    zona_z = qry_zonas->FieldByName("zona")->AsString;
    if(qry_zonas->FieldByName("tipo")->AsString == "1") {
      tabla_costo_credito_y_contado_x_zona(zona_z);
    }
    ProgressBar1->StepIt();
  }
  delete ProgressBar1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_subencab_tabla_cyc()
{

  String pvta_z, nombre_z;
  int ancho_z=0, font_z = 0, mipos_z=1;
  nombre_z = busca_nombre("ZONA", zona_z);
  if(nombre_z.SubString(1,4) == "____") nombre_z = nombre_z.SubString(6,30);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "Zona:%s", zona_z + " " + nombre_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  ancho_z = ((ultimoelem_z - primerelem_z + 1) * 13) + 15;
  if(ancho_z > 90) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  } else if( ancho_z > 80) {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  } else {
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  }
  fprintf(archout, "%s", pvta_z.StringOfChar('_',15));
  for(int ll_z=0; ll_z < qry_acumxlin->RecordCount+1; ll_z++) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s", pvta_z.StringOfChar('_',13));
    }
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s", pvta_z.StringOfChar('_',13));
  }
  salta_linea();
  mipos_z = 1;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("Punto Venta", 15));
  for(qry_acumxlin->First(); !qry_acumxlin->Eof; qry_acumxlin->Next()) {
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      linea_z = qry_acumxlin->FieldByName("linea")->AsString;
      nombre_z = busca_nombre("LINEA", linea_z);
      fprintf(archout, "%s|", ljust(linea_z+ " " + nombre_z, 12));
    }
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|", rjust("Total", 12));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------


void __fastcall TForm_tabcvta::tabla_costo_credito_y_contado_x_zona(String mizona_z)
{
  String descri_z, alm_z, strunids_z, pvta_z, nombre_z;
  int rengs_z, ii_z, ancho_z, tablas_z, nelemxtabla_z, columnas_z;
  bool ultimo_z;
  TLocateOptions Opts;
  Opts.Clear();
  TProgressBar *ProgressBar2;
  ProgressBar2 = new TProgressBar (this);
  ProgressBar2->Parent = Panel1;
  ProgressBar2->Step = 1;
  ProgressBar2->Height = 18;
  ProgressBar2->Width = Panel1->Width - 4;
  ProgressBar2->Left = 2;
  ProgressBar2->Top = Panel1->Height - 40;
  ProgressBar2->Min = 0;
  qry_acumxpvt->Close();
  qry_acumxpvt->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumxpvt->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumxpvt->ParamByName("zonaini")->AsString = mizona_z;
  qry_acumxpvt->ParamByName("zonafin")->AsString = mizona_z;
  qry_acumxpvt->ParamByName("ptvtaini")->AsString = "";
  qry_acumxpvt->ParamByName("ptvtafin")->AsString = "zz";
  qry_acumxpvt->ParamByName("lineaini")->AsString = "";
  qry_acumxpvt->ParamByName("lineafin")->AsString = "zz";
  qry_acumxpvt->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxpvt->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxpvt->Open();

  qry_acumxlin->Close();
  qry_acumxlin->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumxlin->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumxlin->ParamByName("zonaini")->AsString = mizona_z;
  qry_acumxlin->ParamByName("zonafin")->AsString = mizona_z;
  qry_acumxlin->ParamByName("ptvtaini")->AsString = "";
  qry_acumxlin->ParamByName("ptvtafin")->AsString = "zz";
  qry_acumxlin->ParamByName("lineaini")->AsString = "";
  qry_acumxlin->ParamByName("lineafin")->AsString = "zz";
  qry_acumxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxlin->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxlin->Open();
  qry_lineas->Close();
  qry_lineas->ParamByName("cia")->AsInteger = cia_z;
  qry_lineas->Open();

  columnas_z = qry_acumxlin->RecordCount + 1;
  tablas_z   = divent(columnas_z, 12, 15).ToInt();
  nelemxtabla_z = miceil(columnas_z, tablas_z);
  anchopag_z = nelemxtabla_z * 12 + 15;
  if(anchopag_z > 132) {
    anchopag_z = 132;
  } else if (anchopag_z > 90) {
    anchopag_z = 90;
  } else {
    anchopag_z = 80;
  }
  ProgressBar2->Max = qry_acumxpvt->RecordCount * tablas_z;

  for(int jj_z = 0; jj_z < tablas_z; jj_z++) {
    primerelem_z = jj_z * nelemxtabla_z + 1;
    ultimoelem_z = primerelem_z + nelemxtabla_z -1;
    rengs_z= (qry_acumxpvt->RecordCount + 1) * 3;
    ii_z=0;
    if(!primero_z) {
      checa_saltopag(1000); primero_z = 1;
    } else {
      if(!checa_saltopag(rengs_z + 5)) report_subencab_tabla_cyc();
    }
    for(qry_acumxpvt->First(); !qry_acumxpvt->Eof; qry_acumxpvt->Next()) {
      //linea_z = qry_lineas->FieldByName("linea")->AsString;
      if( (ii_z * 3) == rengs_z) ultimo_z = true; else ultimo_z = false;
      checa_saltopag(3);
      for(int ll_z = 1; ll_z < 4; ll_z++) {
        imprime_ren_cyc_x_zona(ultimo_z, ll_z);
      }
      ii_z++;
      ProgressBar2->StepIt();
    }
    checa_saltopag(3);
    for(int ll_z = 1; ll_z < 4; ll_z++) {
      imprime_total_cyc_x_zona(ll_z);
    }
    salta_linea();
  }
  delete ProgressBar2;
}
//---------------------------------------------------------------------------


void __fastcall TForm_tabcvta::imprime_ren_cyc_x_zona(bool ultimo_z, int numdato_z)
{

  double importe_z =0, tothor_z=0, porc_z, rot_z;
  String pvta_z, nombre_z, strporc_z;
  int mipos_z=1;
  if(numdato_z == CRED_Y_CONT)
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  pvta_z = qry_acumxpvt->FieldByName("ptvta")->AsString;
  switch (numdato_z) {
    case CONTADO    : nombre_z = "Contado"; break;
    case CREDITO    : nombre_z = "Credito"; break;
    case CRED_Y_CONT: nombre_z = "Cont y Cred"; break;
  }
  fprintf(archout, "|%s|", ljust(pvta_z + " " + nombre_z, 15));
  for(qry_acumxlin->First(); !qry_acumxlin->Eof; qry_acumxlin->Next()) {
    linea_z = qry_acumxlin->FieldByName("linea")->AsString;
    qry_dato_zona_pvta_linea->Close();
    qry_dato_zona_pvta_linea->ParamByName("fecini")->AsDateTime =fecini_z;
    qry_dato_zona_pvta_linea->ParamByName("fecfin")->AsDateTime =fecfin_z;
    qry_dato_zona_pvta_linea->ParamByName("ptvtaini")->AsString = pvta_z;
    qry_dato_zona_pvta_linea->ParamByName("ptvtafin")->AsString = pvta_z;
    qry_dato_zona_pvta_linea->ParamByName("lineaini")->AsString = linea_z;
    qry_dato_zona_pvta_linea->ParamByName("lineafin")->AsString = linea_z;
    qry_dato_zona_pvta_linea->ParamByName("zonaini")->AsString = zona_z;
    qry_dato_zona_pvta_linea->ParamByName("zonafin")->AsString = zona_z;
    qry_dato_zona_pvta_linea->ParamByName("idtarea")->AsInteger = idtarea_z;
    qry_dato_zona_pvta_linea->ParamByName("cia")->AsInteger = cia_z;
    qry_dato_zona_pvta_linea->Open();
    importe_z = 0;
    if(!qry_dato_zona_pvta_linea->IsEmpty()) {
      switch (numdato_z) {
       case CONTADO    :
         importe_z = qry_dato_zona_pvta_linea->FieldByName("ctocont")->AsFloat;
         break;
       case CREDITO    :
         importe_z = qry_dato_zona_pvta_linea->FieldByName("ctocred")->AsFloat;
         break;
       case CRED_Y_CONT:
         importe_z = qry_dato_zona_pvta_linea->FieldByName("costotot")->AsFloat;
         break;
      }
    }
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", importe_z), 12));
    }
    tothor_z += importe_z;
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", tothor_z), 12));
  }
  if(numdato_z == CRED_Y_CONT)
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::imprime_total_cyc_x_zona(int numdato_z)
{

  double importe_z =0, tothor_z=0, porc_z, rot_z;
  String pvta_z, nombre_z, strporc_z;
  int mipos_z=1;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  switch (numdato_z) {
    case CONTADO    : nombre_z = "Tot. Contado"; break;
    case CREDITO    : nombre_z = "Tot. Credito"; break;
    case CRED_Y_CONT: nombre_z = "Tot. Cont y Cred"; break;
  }
  fprintf(archout, "|%s|", ljust(nombre_z, 15));

  for(qry_acumxlin->First(); !qry_acumxlin->Eof; qry_acumxlin->Next()) {
    linea_z = qry_acumxlin->FieldByName("linea")->AsString;
    switch (numdato_z) {
     case CONTADO    :
       importe_z = qry_acumxlin->FieldByName("ctocont")->AsFloat;
       break;
     case CREDITO    :
       importe_z = qry_acumxlin->FieldByName("ctocred")->AsFloat;
       break;
     case CRED_Y_CONT:
       importe_z = qry_acumxlin->FieldByName("costotot")->AsFloat;
       break;
    }
    if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
      fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", importe_z), 12));
    }
    tothor_z += importe_z;
    mipos_z++;
  }
  if(mipos_z >= primerelem_z && mipos_z <= ultimoelem_z) {
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0", tothor_z), 12));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::tabla_costo_x_tipo_vta_cyc()
{

  double importe_z =0, costovta_z=0, cosmesan_z=0, mesini_z, mesfin_z,
    exist_z, totcmen_z, totcmay_z, totcfon_z, totcfid_z, totcime_z,
    tothor_z, totccel_z, cosmen_z, cosmay_z, cosfon_z, cosfid_z, cosime_z,
    coscel_z, costo1_z, rot_z, coscon_z, coscred_z, totcon_z=0, totcred_z=0,
    impvcrdcp_z, impvcrdlp_z, totimpvcrdcp_z=0, totimpvcrdlp_z=0, imptmp_z=0,
    totcyl_z=0;
  String pvta_z, nombre_z, strporc_z, anttipo_z, tipo_z;
  TProgressBar *ProgressBar1;
  TLocateOptions Opts;
  Opts.Clear();
  int mipos_z=0, columnas_z=0, tablas_z=0, nelemxtabla_z, rengs_z;
  enc_z="TABLA_X_TIPO_VTA_CYC";
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = Panel1;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Width = Panel1->Width - 4;
  ProgressBar1->Left = 2;
  ProgressBar1->Top = Panel1->Height - 20;
  ProgressBar1->Min = 0;
  fecini_z = date_fecini->Date;
  fecfin_z = date_fecfin->Date;
  if(!checa_saltopag(rengs_z + 2)) {
    report_subencab_tabla_x_tipo_vta_cyc();
  } else {
    report_subencab_tabla_x_tipo_vta_cyc();
  }
  //totcmen_z = obten_costo_x_tipo("V", "", "zz", "TOTAL");
  totcred_z = obten_costo_x_tipo("V", "", "zz", "CREDITO", "", "zz");
  totcon_z  = obten_costo_x_tipo("V", "", "zz", "CONTADO", "", "zz");
  totcmay_z = obten_costo_x_tipo("M", "", "zz", "TOTAL", "", "zz");
  totcfon_z = obten_costo_x_tipo("F", "", "zz", "TOTAL", "", "zz");
  totccel_z = obten_costo_x_tipo("U", "", "zz", "TOTAL", "", "zz");
  totcfid_z = obten_costo_x_tipo("H", "", "zz", "TOTAL", "", "zz");
  totcime_z = obten_costo_x_tipo("1", "", "zz", "TOTAL", "", "zz");
  totcosvta_z = totcmen_z + totcmay_z + totcfon_z + totccel_z + totcfid_z + totcime_z;
  //totexizon_z = obten_ultimo_costo(fecfin_z, "", "zz", "", "zz", "", "zz");
  qry_acumxpvt->Close();
  qry_acumxpvt->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_acumxpvt->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_acumxpvt->ParamByName("zonaini")->AsString = "";
  qry_acumxpvt->ParamByName("zonafin")->AsString = "zz";
  qry_acumxpvt->ParamByName("ptvtaini")->AsString = "";
  qry_acumxpvt->ParamByName("ptvtafin")->AsString = "zz";
  qry_acumxpvt->ParamByName("lineaini")->AsString = "";
  qry_acumxpvt->ParamByName("lineafin")->AsString = "zz";
  qry_acumxpvt->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_acumxpvt->ParamByName("cia")->AsInteger = cia_z;
  qry_acumxpvt->Open();
  rengs_z = qry_acumxpvt->RecordCount;

  for(qry_acumxpvt->First(); !qry_acumxpvt->Eof; qry_acumxpvt->Next()) {
    tothor_z=0; mipos_z++;
    cosmen_z = cosmay_z =  cosfon_z = cosfid_z = cosime_z = coscel_z = 0;
    coscon_z = coscred_z = 0;
    impvcrdcp_z = impvcrdlp_z = imptmp_z = 0;
    //if(mipos_z == rengs_z)
    //  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

    pvta_z = qry_acumxpvt->FieldByName("ptvta")->AsString;
    fprintf(archout, "|%s|", ljust(pvta_z,4));

    //cosmen_z = obten_costo_x_tipo("V", "", "zz", "TOTAL");
    coscon_z = obten_costo_x_tipo("V", "", "zz", "CONTADO", pvta_z, pvta_z);
    impvcrdcp_z = obten_vtas_clp("CORTO_PLAZO", pvta_z, pvta_z);
    impvcrdlp_z = obten_vtas_clp("LARGO_PLAZO", pvta_z, pvta_z);
    coscred_z = obten_costo_x_tipo("V", "", "zz", "CREDITO", pvta_z, pvta_z);
    cosfon_z = obten_costo_x_tipo("F", "", "zz", "TOTAL", pvta_z, pvta_z);
    cosmay_z = 0; // obten_costo_x_tipo("M", "", "zz", "TOTAL");
    cosfid_z = obten_costo_x_tipo("H", "", "zz", "TOTAL", pvta_z, pvta_z);
    cosime_z = obten_costo_x_tipo("U", "", "zz", "TOTAL", pvta_z, pvta_z);
    coscel_z = obten_costo_x_tipo("1", "", "zz", "TOTAL", pvta_z, pvta_z);
    tothor_z = coscon_z + coscred_z + cosfon_z + cosmay_z + cosfid_z + cosime_z + coscel_z;

    //strporc_z = rjust(calcu_strporc(cosmen_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", coscon_z), 12));
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", coscred_z), 12));
    totcyl_z = impvcrdcp_z + impvcrdlp_z;
    if(totcyl_z) imptmp_z = coscred_z * ( impvcrdlp_z / totcyl_z );
    totimpvcrdlp_z += imptmp_z;
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", imptmp_z), 12));

    if(totcyl_z) imptmp_z = coscred_z * ( impvcrdcp_z / totcyl_z );
    totimpvcrdcp_z += imptmp_z;
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", imptmp_z), 12));

    //fprintf(archout, "%s|", strporc_z);

    //strporc_z = rjust(calcu_strporc(cosfon_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosfon_z), 12));
    //fprintf(archout, "%s|", strporc_z);

    //strporc_z = rjust(calcu_strporc(cosfid_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosfid_z), 12));
    //fprintf(archout, "%s|", strporc_z);

    //strporc_z = rjust(calcu_strporc(cosime_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosime_z), 12));
    //fprintf(archout, "%s|", strporc_z);

    //strporc_z = rjust(calcu_strporc(coscel_z, tothor_z, "0.00"),5);
    //fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", coscel_z), 12));
    //fprintf(archout, "%s|", strporc_z);

    //strporc_z = rjust(calcu_strporc(cosmay_z, tothor_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosmay_z), 12));
    //fprintf(archout, "%s|", strporc_z);

    //strporc_z = rjust(calcu_strporc(tothor_z, totcosvta_z, "0.00"),5);
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", tothor_z), 12));
    //fprintf(archout, "%s|", strporc_z);

    //exist_z = obten_ultimo_costo(fecfin_z, "", "zz", linea_z, linea_z, "", "zz");
    //if(tothor_z)  rot_z = exist_z / tothor_z * 30; else rot_z = 0;
    //strporc_z = rjust(FormatFloat("0.0", rot_z),5);

    //fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", exist_z), 12));
    //fprintf(archout, "%s|", strporc_z);
    salta_linea();
    ProgressBar1->StepIt();
  }
  // Voy a Imprimir la Linea de Mayoreo
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  pvta_z = "AL"; // ->Provisionalmente.
  fprintf(archout, "|%s|", ljust(pvta_z,4));
  cosmen_z = cosmay_z =  cosfon_z = cosfid_z = cosime_z = coscel_z = 0;
  coscon_z = coscred_z = 0;
  impvcrdcp_z = impvcrdlp_z = imptmp_z = 0;
  //if(mipos_z == rengs_z)
  //  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

  //cosmen_z = obten_costo_x_tipo("V", "", "zz", "TOTAL");
  //coscon_z = obten_costo_x_tipo("V", "", "zz", "CONTADO");
  //coscred_z = obten_costo_x_tipo("V", "", "zz", "CREDITO");
  //cosfon_z = obten_costo_x_tipo("F", "", "zz", "TOTAL");
  cosmay_z = totcmay_z; // obten_costo_x_tipo("M", "", "zz", "TOTAL");
  //cosfid_z = obten_costo_x_tipo("H", "", "zz", "TOTAL");
  //cosime_z = obten_costo_x_tipo("U", "", "zz", "TOTAL");
  //coscel_z = obten_costo_x_tipo("1", "", "zz", "TOTAL");
  tothor_z = coscon_z + coscred_z + cosfon_z + cosmay_z + cosfid_z + cosime_z + coscel_z;

  //strporc_z = rjust(calcu_strporc(cosmen_z, tothor_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", coscon_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", coscred_z), 12));
  // Lo dejo en Ceros por que es Mayoreo
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", imptmp_z), 12));
  // Lo dejo en Ceros por que es Mayoreo
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", imptmp_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(cosfon_z, tothor_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosfon_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(cosfid_z, tothor_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosfid_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(cosime_z, tothor_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosime_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(coscel_z, tothor_z, "0.00"),5);
  //fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", coscel_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(cosmay_z, tothor_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", cosmay_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(tothor_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", tothor_z), 12));
  //fprintf(archout, "%s|", strporc_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();

  // Ahora Imprimo el Total
  tothor_z = totcon_z + totcred_z + totcfon_z + totcmay_z + totcfid_z + totcime_z + totccel_z;
  imptmp_z = 0;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

  fprintf(archout, "|%s|", ljust("Tot.",4));

  //strporc_z = rjust(calcu_strporc(totcmen_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcon_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcred_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totimpvcrdlp_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totimpvcrdcp_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(totcfon_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcfon_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(totcfid_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcfid_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(totccel_z, totcosvta_z, "0.00"),5);
  //fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totccel_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(totcime_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcime_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(totcmay_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totcmay_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //strporc_z = rjust(calcu_strporc(totcosvta_z, totcosvta_z, "0.00"),5);
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", tothor_z), 12));
  //fprintf(archout, "%s|", strporc_z);

  //if(totcosvta_z)  rot_z = totexizon_z / totcosvta_z * 30; else rot_z = 0;
  //strporc_z = rjust(FormatFloat("0.0", rot_z),5);

  //fprintf(archout, "%s|", rjust(FormatFloat("###,###,###", totexizon_z), 12));
  //fprintf(archout, "%s|", strporc_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
  salta_linea();
  delete ProgressBar1;
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvta::report_subencab_tabla_x_tipo_vta_cyc()
{
  String titulo_z;
  int ancho_z;
  titulo_z = "Costo de Ventas Global x Tipo";
  fprintf(archout, "%s", cjust(titulo_z, 80));
  salta_linea();
  titulo_z = titulo_z.StringOfChar('_',98);
  fprintf(archout, "%s", titulo_z);
  salta_linea();

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("PVTA",4));
  fprintf(archout, "%s|", ljust("C.Vta.Cont",12));
  fprintf(archout, "%s|", ljust("C.Vta.Cred",12));
  fprintf(archout, "%s|", ljust("Cred L.P",12));
  fprintf(archout, "%s|", ljust("Cred C.P",12));
  fprintf(archout, "%s|", ljust("Cto.Vta.FON",12));
  fprintf(archout, "%s|", ljust("Cto.Vta.FIDE",12));
  //fprintf(archout, "%s|%s|", ljust("Cto.Vta.CEL",12), cjust("%",5));
  fprintf(archout, "%s|", ljust("Cto.Vta.IMEVI",12));
  fprintf(archout, "%s|", ljust("Cto.Vta.MAY",12));
  fprintf(archout, "%s|", ljust("Total.Cto.V",12));
  //fprintf(archout, "%s|%s|", ljust("Existencia",12), cjust("Rot",5));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

double __fastcall TForm_tabcvta::obten_vtas_clp( String cl_z, String ptvtaini_z, String ptvtafin_z)
{
  int nmesesini_z=0, nmesesfin_z=0, quinini_z=0, quinfin_z=0;
  double importe_z = 0;
  String ubicartera_z;
  ubicartera_z = ptvtaini_z;
  if(cl_z == "CORTO_PLAZO") {
    nmesesini_z=1, nmesesfin_z=12;
  } else {
    nmesesini_z=13, nmesesfin_z=999;
  }
  quinini_z = nmesesini_z * 2;
  quinfin_z = nmesesfin_z * 2;
  qry_ubivtacartera->Close();
  qry_ubivtacartera->ParamByName("pvta")->AsString = ptvtaini_z;
  qry_ubivtacartera->Open();
  if(!qry_ubivtacartera->IsEmpty()) {
     if (ptvtaini_z == "M2") {
        ubicartera_z = qry_ubivtacartera->FieldByName("zonacar")->AsString;
        qry_cartera_cylp_zona->Close();
        qry_cartera_cylp_zona->ParamByName("fecini")->AsDateTime = date_fecini->Date;
        qry_cartera_cylp_zona->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
        qry_cartera_cylp_zona->ParamByName("zona")->AsString = ubicartera_z;
        qry_cartera_cylp_zona->ParamByName("ltaquinini")->AsInteger = quinini_z;
        qry_cartera_cylp_zona->ParamByName("ltaquinfin")->AsInteger = quinfin_z;
        qry_cartera_cylp_zona->ParamByName("ltamenini")->AsInteger = nmesesini_z;
        qry_cartera_cylp_zona->ParamByName("ltamenfin")->AsInteger = nmesesfin_z;
        qry_cartera_cylp_zona->Open();
        if(!qry_cartera_cylp_zona->IsEmpty())
           importe_z = qry_cartera_cylp_zona->FieldByName("importe")->AsFloat;
     } else {
        ubicartera_z = qry_ubivtacartera->FieldByName("subzoncar")->AsString;
        qry_cartera_cl->Close();
        qry_cartera_cl->ParamByName("fecini")->AsDateTime = date_fecini->Date;
        qry_cartera_cl->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
        qry_cartera_cl->ParamByName("ptovta")->AsString = ubicartera_z;
        qry_cartera_cl->ParamByName("ltaquinini")->AsInteger = quinini_z;
        qry_cartera_cl->ParamByName("ltaquinfin")->AsInteger = quinfin_z;
        qry_cartera_cl->ParamByName("ltamenini")->AsInteger = nmesesini_z;
        qry_cartera_cl->ParamByName("ltamenfin")->AsInteger = nmesesfin_z;
        qry_cartera_cl->Open();
        if(!qry_cartera_cl->IsEmpty())
           importe_z = qry_cartera_cl->FieldByName("importe")->AsFloat;
     }
  }
  return (importe_z);
}
//---------------------------------------------------------------------------

