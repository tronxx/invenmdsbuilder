//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_analisma.h"
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
TForm_analisma *Form_analisma;
//---------------------------------------------------------------------------
__fastcall TForm_analisma::TForm_analisma(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analisma::FormCreate(TObject *Sender)
{
  cia_z = dm->cia_z;
  date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
  LINEAS_X_PAG = 66;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::tipo_reporte(String tipo_z)
{
  encab_z = tipo_z;
  if(tipo_z == "ANALISMA") {
    lbl_alm->Visible = false;
    btn_ejecutar->Action = genera_analisma;
    Caption = "Reporte de Movimientos ANALISMA";
  } else if(tipo_z == "REPCVTA") {
    lbl_alm->Visible = true;
    btn_ejecutar->Action = reporte_repcvta;
    grp_tiporep->Visible = false;
    Caption = "Reporte de Movimientos REPCVTA";
    grp_tiporep->Items->Clear();
    grp_tiporep->Items->Add("Menudeo");
    grp_tiporep->Items->Add("Mayoreo");
    grp_tiporep->Items->Add("Fonacot");
    grp_tiporep->Items->Add("Fide");
    grp_tiporep->Items->Add("Celular");
  }
  edt_almini->Visible = lbl_alm->Visible;
  dbgrd_renglonesCOSTOU->Visible = lbl_alm->Visible;
  dbgrd_renglonesPRVTA->Visible = lbl_alm->Visible;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::selecciona_tipo_rep(String tiporep_z)
{
  if(tiporep_z == "ACUMAYO") {
    btn_ejecutar->Action = acum_cob_mayo;
    Caption = "Acumulado de Cobranza Mayoreo x Fecha";
    grp_tiporep->Visible = false;
    grp_netobru->Visible = false;
    grp_statcan->Visible = false;
    grp_statsino->Visible = false;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------
void __fastcall TForm_analisma::Exportara1Click(TObject *Sender)
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
  SaveDialog->FileName = "*.xls";
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

void __fastcall TForm_analisma::exporta_dbgrdExecute(TObject *Sender)
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


void __fastcall TForm_analisma::acumayo()
{
  TDateTime fecini_z, fecfin_z;
  String arch_z, mensaje_z, titmsg_z;
  fecini_z = date_fecini->Date;
  fecfin_z = date_fecfin->Date;
  qry_abonos->Close();
  qry_abonos->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_abonos->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_abonos->ParamByName("cia")->AsInteger = cia_z;
  qry_abonos->Open();
  antmayo_z = "-1";
  encab_z = "ACUMAYO";
  arch_z = "acumayo.txt";
  mensaje_z = "Desea imprimir este reporte?";
  titmsg_z = "Costo de Ventas x Ubicación";

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }

  for(qry_abonos->First(); !qry_abonos->Eof; qry_abonos->Next()) {
    mayoris_z = qry_abonos->FieldByName("mayoris")->AsString;
    if(antmayo_z == "-1") {
      antmayo_z = mayoris_z;
      report_encab();
    }
    if(mayoris_z != antmayo_z ) {
      report_subtotmay();
      antmayo_z = mayoris_z;
      report_subencab();
    }
    checa_saltopag(3);
    imprime_renglon();
  }
  report_subtotmay();
  report_total();
  fclose(archout);
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::report_encab()
{
  String situini_z,situfin_z,tit1_z,tit2_z;
  lineas_z = 0;
  fprintf(archout, "%s%s%s", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  salta_linea();
  fprintf(archout, "%s%s%s%s", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_analisma " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60)
  );
  salta_linea();

  if(encab_z == "ACUMAYO") {
    tit1_z = "Acumulado de Cobranza Mayoreo ";
    tit1_z += "del " + FormatDateTime("dd/mm/yyyy", date_fecini->Date);
    tit1_z += " Al " + FormatDateTime("dd/mm/yyyy", date_fecfin->Date);
    tit1_z += " Pag: " + IntToStr(pagina_z);
    fprintf(archout, "%s", cjust( tit1_z ,80));
    salta_linea();
  }
  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::report_subencab()
{
  if(encab_z == "ANALISMA") {
    subenc_analisma(); return;
  }
  if(encab_z == "REPCVTA") {
    report_subenclin_alm(); return;
  }
  fprintf(archout, "Mayorista:%s %s", antmayo_z, busca_dato("MAYORISTA", antmayo_z));
  salta_linea();
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Fecha",15));
  fprintf(archout, "%s|", cjust("Tipo Pago",12));
  fprintf(archout, "%s|", rjust("Importe",12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
}
//---------------------------------------------------------------------------

String __fastcall TForm_analisma::busca_dato(String tipodato_z, String clave_z)
{
   String nombre_z="", nombreparam_z, sql_z;
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   if (tipodato_z == "PUNTO_VENTA") {
     sql_z = "select nombre from ptovta where clave = :CLAVE";
   } else if (tipodato_z == "ZONA") {
     sql_z = "select nombre from zonainv where zona = :CLAVE";
   } else if (tipodato_z == "MAYORISTA") {
     sql_z = "select nombre from mayoris where codigo = :CLAVE and cia = :CIA";
   } else if (tipodato_z == "LINEA") {
     sql_z = "select descri as nombre from lineas where numero = :CLAVE and cia = :CIA";
   } else if (tipodato_z == "ALMACEN") {
     sql_z = "select nombre from almacen where clave = :CLAVE and cia = :CIA";
   }

   dm->qry_maxidvnd->SQL->Add(sql_z);
   for(int jj_z=0; jj_z < dm->qry_maxidvnd->Params->Count; jj_z++) {
      nombreparam_z = dm->qry_maxidvnd->Params->Items[jj_z]->Name.UpperCase();
      if( nombreparam_z == "CLAVE") {
        dm->qry_maxidvnd->Params->Items[jj_z]->AsString = clave_z;
      }
      if( nombreparam_z == "CIA") {
        dm->qry_maxidvnd->Params->Items[jj_z]->AsInteger = cia_z;
      }
   }
   dm->qry_maxidvnd->Open();
   if(!dm->qry_maxidvnd->IsEmpty())
     nombre_z = dm->qry_maxidvnd->FieldByName("nombre")->AsString;
   return (nombre_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::imprime_renglon()
{
  TDateTime fechapago_z;
  fechapago_z = qry_abonos->FieldByName("fecha")->AsDateTime;
  String tipag_z, tipopago_z;
  double importe_z = 0;
  tipag_z = qry_abonos->FieldByName("tipago")->AsString;
  importe_z = qry_abonos->FieldByName("importe")->AsFloat;
  if(tipag_z == "B") {
    tipopago_z = "Bonificacion";
    bonmay_z += importe_z;
  }
  if(tipag_z == "D") {
    tipopago_z = "Devolucion";
    devmay_z += importe_z;
  }
  if(tipag_z == "E") {
    tipopago_z = "Efectivo";
    totmay_z += importe_z;
  }
  fprintf(archout, "%s|", ljust(FormatDateTime("dd mmm yyyy", fechapago_z),15));
  fprintf(archout, "%s|", ljust(tipopago_z,12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", importe_z),12));
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::report_subtotmay()
{
  if(totmay_z) {
    fprintf(archout, "%s|", ljust("Total de Mayorista",15));
    fprintf(archout, "%s|", ljust("Efectivo",12));
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", totmay_z),12));
    salta_linea();
  }
  if(bonmay_z) {
    fprintf(archout, "%s|", ljust("",15));
    fprintf(archout, "%s|", ljust("Bonificacion",12));
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", bonmay_z),12));
    salta_linea();
  }
  if(devmay_z) {
    fprintf(archout, "%s|", ljust("",15));
    fprintf(archout, "%s|", ljust("Devolucion",12));
    fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", devmay_z),12));
    salta_linea();
  }
  salta_linea();
  bontot_z += bonmay_z; bonmay_z = 0;
  devtot_z += devmay_z; devmay_z = 0;
  tottot_z += totmay_z; totmay_z = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::report_total()
{
  fprintf(archout, "%s|", ljust("Total",15));
  fprintf(archout, "%s|", ljust("Efectivo",12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", tottot_z),12));
  salta_linea();
  fprintf(archout, "%s|", ljust("Total",15));
  fprintf(archout, "%s|", ljust("Bonificacion",12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", bontot_z),12));
  salta_linea();
  fprintf(archout, "%s|", ljust("Total",15));
  fprintf(archout, "%s|", ljust("Devolucion",12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,###,##0.00", devtot_z),12));
  salta_linea();
  bontot_z = 0;
  devtot_z = 0;
  tottot_z = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::acum_cob_mayoExecute(TObject *Sender)
{
  acumayo();

}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::salta_linea()
{
  fprintf(archout, "\n");
  lineas_z++;
}
//---------------------------------------------------------------------------

bool __fastcall TForm_analisma::checa_saltopag(int numero_de_lineas)
{
  bool haysalto_z = false;
  if(lineas_z > ( LINEAS_X_PAG - numero_de_lineas) ) {
    fprintf(archout, "%c", 12); pagina_z++; report_encab();
    haysalto_z = true;
  }
  return(haysalto_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::graba_tipodedato()
{
  int idtpvtatmp_z = 0, idtpvt_z = 0;
  String tipoent_z;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "select max(IDTAREA) as idtarea, max(IDTPVTATMP) as idtpvtatmp from inv_tpvtatmp";
  dm->qry_maxidvnd->Open();
  idtarea_z = dm->qry_maxidvnd->FieldByName("idtarea")->AsInteger + 1;
  idtpvtatmp_z = dm->qry_maxidvnd->FieldByName("idtpvtatmp")->AsInteger + 1;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "insert into inv_tpvtatmp (IDTPVTATMP, IDTAREA, IDTIPOVTA, FACTOR, TIPOSAL) values ( :IDTPVTATMP, :IDTAREA, :IDTIPOVTA, :FACTOR, :TIPOSAL )";
  idtpvt_z = grp_tiporep->ItemIndex;
  if(idtpvt_z < 0) idtpvt_z = 0;
  if(grp_netobru->ItemIndex == 0 || grp_netobru->ItemIndex == 1) {
    switch (idtpvt_z) {
      case 0: tipoent_z = "V"; break;
      case 1: tipoent_z = "M"; break;
      case 2: tipoent_z = "F"; break;
      case 3: tipoent_z = "H"; break;
      case 4: tipoent_z = "Q"; break;
      case 5: tipoent_z = "E"; break;
    }
    dm->qry_maxidvnd->ParamByName("IDTPVTATMP")->AsInteger = idtpvtatmp_z++;
    dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
    dm->qry_maxidvnd->ParamByName("IDTIPOVTA")->AsInteger = 0;
    dm->qry_maxidvnd->ParamByName("FACTOR")->AsInteger = 1;
    dm->qry_maxidvnd->ParamByName("TIPOSAL")->AsString = tipoent_z;
    dm->qry_maxidvnd->ExecSQL();
  }
  if(grp_netobru->ItemIndex == 2 || grp_netobru->ItemIndex == 1) {
    switch (idtpvt_z) {
      case 0: tipoent_z = "C"; break;
      case 1: tipoent_z = "Y"; break;
      case 2: tipoent_z = "O"; break;
      case 3: tipoent_z = "J"; break;
      case 4: tipoent_z = "U"; break;
      case 5: tipoent_z = "R"; break;
    }
    dm->qry_maxidvnd->ParamByName("IDTPVTATMP")->AsInteger = idtpvtatmp_z++;
    dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
    dm->qry_maxidvnd->ParamByName("IDTIPOVTA")->AsInteger = 0;
    dm->qry_maxidvnd->ParamByName("FACTOR")->AsInteger = -1;
    dm->qry_maxidvnd->ParamByName("TIPOSAL")->AsString = tipoent_z;
    dm->qry_maxidvnd->ExecSQL();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::genera_analismaExecute(TObject *Sender)
{

  int idtpvtatmp_z=0, idtpvt_z=0, unidslin_z=0, unidstot_z=0;
  String tipoent_z, siono1_z, siono2_z, entcan1_z, entcan2_z, arch_z,
         antlinea_z;
  double costolin_z=0, costotot_z=0;
  graba_tipodedato();
  if(grp_statcan->ItemIndex == 0 || grp_statcan->ItemIndex == 1) entcan1_z = "S";
  if(grp_statcan->ItemIndex == 0 || grp_statcan->ItemIndex == 2) entcan2_z = "N";
  if(grp_statsino->ItemIndex == 0 || grp_statsino->ItemIndex == 1) siono1_z = "S";
  if(grp_statsino->ItemIndex == 0 || grp_statsino->ItemIndex == 2) siono2_z = "N";
  qry_analisma->Close();
  qry_analisma->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_analisma->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_analisma->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_analisma->ParamByName("cia")->AsInteger = cia_z;
  qry_analisma->ParamByName("siono1")->AsString = siono1_z;
  qry_analisma->ParamByName("siono2")->AsString = siono2_z;
  qry_analisma->ParamByName("entcan1")->AsString = entcan1_z;
  qry_analisma->ParamByName("entcan2")->AsString = entcan2_z;
  qry_analisma->Open();
  encab_z = "ANALISMA";
  arch_z = "acumayo.txt";

  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  antlinea_z = "-1";
  for(qry_analisma->First(); !qry_analisma->Eof; qry_analisma->Next()) {
    linea_z = qry_analisma->FieldByName("linea")->AsString;
    if(antlinea_z == "-1") {
      antlinea_z = linea_z; report_encab();
    }
    if(linea_z != antlinea_z) {
      report_subtotlin("Total esta Linea", unidslin_z, costolin_z);
      unidslin_z = 0;
      costolin_z = 0;
      antlinea_z = linea_z;
      if(!checa_saltopag(5)) report_subenclin_analisma();
    }
    checa_saltopag(3);
    unidslin_z += qry_analisma->FieldByName("unids")->AsInteger;
    costolin_z += qry_analisma->FieldByName("costotot")->AsFloat;
    unidstot_z += qry_analisma->FieldByName("unids")->AsInteger;
    costotot_z += qry_analisma->FieldByName("costotot")->AsFloat;
    imprime_ren_analisma();
  }
  report_subtotlin("Total esta Linea", unidslin_z, costolin_z);
  unidslin_z = 0;
  costolin_z = 0;
  report_subtotlin("Total General", unidstot_z, costotot_z);
  elimina_invtpvtatmp();
  fclose(archout);
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::elimina_invtpvtatmp()
{
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "delete from inv_tpvtatmp where IDTAREA = :IDTAREA";
  dm->qry_maxidvnd->ParamByName("idtarea")->AsInteger = idtarea_z;
  dm->qry_maxidvnd->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::subenc_analisma()
{
    String tit1_z;
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
    fprintf(archout, "%s", cjust( "INFORME DE DIRECCION",40).TrimRight());
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
    salta_linea();
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
    tit1_z = "DEL " + FormatDateTime("dd/mm/yyyy", date_fecini->Date) + " AL " + FormatDateTime("dd/mm/yyyy", date_fecfin->Date);
    fprintf(archout, "%s", cjust( tit1_z,40).TrimRight());
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
    salta_linea();
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
    fprintf(archout, "%s", cjust( "INFORME DE INVENTARIOS",40).TrimRight());
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
    salta_linea();
    tit1_z = "ANALISIS DE COSTO DE ";
    switch(grp_netobru->ItemIndex) {
      case 0: tit1_z += "VENTAS BRUTAS"; break;
      case 1: tit1_z += "VENTAS NETAS"; break;
      case 2: tit1_z += "CANCELACIONES"; break;
    }
    salta_linea();
    report_subenclin_analisma();

}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::report_subenclin_analisma()
{
  String nombre_z;
  nombre_z = busca_dato("LINEA", linea_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "Linea:%s %s", linea_z, nombre_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("codigo", 13));
  fprintf(archout, "%s|", ljust("Descripcion", 30));
  fprintf(archout, "%s|", rjust("unids", 5));
  fprintf(archout, "%s|", rjust("Costo Unitario", 12));
  fprintf(archout, "%s|", rjust("Costo Total", 12));
  if(encab_z == "ANALISMA") {
    fprintf(archout, "%s|", rjust("Ultimo Costo", 12));
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();

}
//---------------------------------------------------------------------------


void __fastcall TForm_analisma::report_subtotlin(String tit_z, int unids_z, double costo_z)
{
  fprintf(archout, "%s|", ljust("", 12));
  fprintf(archout, "%s|", ljust(tit_z, 30));
  fprintf(archout, "%s|", rjust(IntToStr(unids_z), 5));
  fprintf(archout, "%s|", rjust("", 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", costo_z), 12));
  if(encab_z == "ANALISMA") {
    fprintf(archout, "%s|", rjust("", 12));
  }
  salta_linea();
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::imprime_ren_analisma()
{
  String codigo_z, descri_z;
  int unids_z;
  double costou_z=0, costotot_z = 0, ultcosto_z = 0;

  codigo_z = qry_analisma->FieldByName("codigo")->AsString;
  descri_z = qry_analisma->FieldByName("descri")->AsString;
  unids_z  = qry_analisma->FieldByName("unids")->AsInteger;
  costotot_z  = qry_analisma->FieldByName("costotot")->AsFloat;
  if(encab_z == "ANALISMA") {
    costou_z  = qry_analisma->FieldByName("costou")->AsFloat;
    ultcosto_z = qry_analisma->FieldByName("costotot")->AsFloat;
    qry_invulcos->Close();
    qry_invulcos->ParamByName("codigo")->AsString = codigo_z;
    qry_invulcos->ParamByName("fecorte")->AsDateTime = date_fecfin->Date;
    qry_invulcos->ParamByName("cia")->AsInteger   = cia_z;
    qry_invulcos->Open();
    if(!qry_invulcos->IsEmpty()) ultcosto_z = qry_invulcos->FieldByName("coston")->AsFloat;
  } else if (encab_z == "REPCVTA") {
    if(unids_z) costou_z = costotot_z / unids_z;
  }

  fprintf(archout, "%s|", ljust(codigo_z, 12));
  fprintf(archout, "%s|", ljust(descri_z, 30));
  fprintf(archout, "%s|", rjust(IntToStr(unids_z), 5));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", costou_z), 12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", costotot_z), 12));
  if(encab_z == "ANALISMA") {
    fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", ultcosto_z), 12));
  }
  salta_linea();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::date_feciniExit(TObject *Sender)
{
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::reporte_repcvtaExecute(TObject *Sender)
{
  int unidslin_z=0, unidstot_z=0, unidsalm_z=0, unidspvt_z=0;
  String tipoent_z, siono1_z, siono2_z, entcan1_z, entcan2_z, arch_z,
         antlinea_z, sql_z, pralm_z, ulalm_z, antalm_z, antptvta_z, ultptvta_z;
  double costolin_z=0, costotot_z=0, costoalm_z=0, costopvt_z=0;
  pralm_z = edt_almini->Text.Trim(); ulalm_z = pralm_z;
  graba_tipodedato();
  sql_z = "select a.alm, b.recemi as pvta, d.orden, c.linea, c.codigo, c.descri, c.empaqe, ";
  sql_z += "sum(b.unids * factor) as unids, ";
  sql_z += "sum(b.costou * (b.piva/100+1) * factor) as costotot ";
  sql_z += "from inv_tpvtatmp f ";
  sql_z += "join entradas a on f.tiposal=a.tipo ";
  sql_z += "join renentra b on a.numero=b.numero ";
  sql_z += "and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia ";
  sql_z += "join inven c on b.codinv=c.codigo and b.cia=c.cia and a.tipo=b.tipo ";
  sql_z += "join lineas d on c.linea=d.numero where ";
  sql_z += "a.alm between :PRALM and :ULALM and ";
  sql_z += "f.idtarea = :IDTAREA and a.fecha between :FECINI and :FECFIN and a.cia= :CIA ";
  sql_z += "and (b.siono  = :SIONO1  or b.siono  = :SIONO2) ";
  sql_z += "and (b.entcan = :ENTCAN1 or b.entcan = :ENTCAN2) ";
  sql_z += "group by a.alm, b.recemi, d.orden,linea,codigo,c.descri,c.empaqe";
  qry_analisma->SQL->Text = sql_z;


  if(grp_statcan->ItemIndex == 0 || grp_statcan->ItemIndex == 1) entcan1_z = "S";
  if(grp_statcan->ItemIndex == 0 || grp_statcan->ItemIndex == 2) entcan2_z = "N";
  if(grp_statsino->ItemIndex == 0 || grp_statsino->ItemIndex == 1) siono1_z = "S";
  if(grp_statsino->ItemIndex == 0 || grp_statsino->ItemIndex == 2) siono2_z = "N";
  qry_analisma->Close();
  qry_analisma->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_analisma->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_analisma->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_analisma->ParamByName("cia")->AsInteger = cia_z;
  qry_analisma->ParamByName("siono1")->AsString = siono1_z;
  qry_analisma->ParamByName("siono2")->AsString = siono2_z;
  qry_analisma->ParamByName("entcan1")->AsString = entcan1_z;
  qry_analisma->ParamByName("entcan2")->AsString = entcan2_z;
  qry_analisma->ParamByName("pralm")->AsString = pralm_z;
  qry_analisma->ParamByName("ulalm")->AsString = ulalm_z;
  qry_analisma->Open();
  encab_z = "REPCVTA";
  arch_z = "repcvta.txt";

  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  antalm_z = "-1";
  for(qry_analisma->First(); !qry_analisma->Eof; qry_analisma->Next()) {
    linea_z = qry_analisma->FieldByName("linea")->AsString;
    alm_z = qry_analisma->FieldByName("alm")->AsString;
    ptvta_z = qry_analisma->FieldByName("pvta")->AsString;
    if(antalm_z == "-1") {
      antalm_z = alm_z;
      antptvta_z = ptvta_z;
      antlinea_z = linea_z;
      report_encab();
    }
    if(alm_z != antalm_z) {
      report_subtotlin("Total esta Linea", unidslin_z, costolin_z);
      unidslin_z = 0;
      costolin_z = 0;
      report_subtotlin("Total este Punto de Venta", unidspvt_z, costopvt_z);
      unidspvt_z = 0;
      costopvt_z = 0;
      report_subtotlin("Total este Almacen", unidsalm_z, costoalm_z);
      unidsalm_z = 0;
      costoalm_z = 0;
      antlinea_z = linea_z;
      antalm_z = alm_z;
      antptvta_z = ptvta_z;
      if(!checa_saltopag(5)) report_subenclin_repcvta();
    }
    if(ptvta_z != antptvta_z) {
      report_subtotlin("Total esta Linea", unidslin_z, costolin_z);
      unidslin_z = 0;
      costolin_z = 0;
      report_subtotlin("Total este Punto de Venta", unidspvt_z, costopvt_z);
      unidspvt_z = 0;
      costopvt_z = 0;
      antlinea_z = linea_z;
      antalm_z = alm_z;
      antptvta_z = ptvta_z;
      if(!checa_saltopag(5)) report_subenclin_repcvta();
    }
    if(linea_z != antlinea_z) {
      report_subtotlin("Total esta Linea", unidslin_z, costolin_z);
      unidslin_z = 0;
      costolin_z = 0;
      antlinea_z = linea_z;
      if(!checa_saltopag(5)) report_subenclin_analisma();
    }
    checa_saltopag(3);
    unidspvt_z += qry_analisma->FieldByName("unids")->AsInteger;
    costopvt_z += qry_analisma->FieldByName("costotot")->AsFloat;
    unidsalm_z += qry_analisma->FieldByName("unids")->AsInteger;
    costoalm_z += qry_analisma->FieldByName("costotot")->AsFloat;
    unidslin_z += qry_analisma->FieldByName("unids")->AsInteger;
    costolin_z += qry_analisma->FieldByName("costotot")->AsFloat;
    unidstot_z += qry_analisma->FieldByName("unids")->AsInteger;
    costotot_z += qry_analisma->FieldByName("costotot")->AsFloat;
    imprime_ren_analisma();
  }
  report_subtotlin("Total esta Linea", unidslin_z, costolin_z);
  unidslin_z = 0;
  costolin_z = 0;
  report_subtotlin("Total este Punto de Venta", unidspvt_z, costopvt_z);
  unidspvt_z = 0;
  costopvt_z = 0;
  report_subtotlin("Total este Almacen", unidsalm_z, costoalm_z);
  unidslin_z = 0;
  costolin_z = 0;
  report_subtotlin("Total General", unidstot_z, costotot_z);
  elimina_invtpvtatmp();
  fclose(archout);
  dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------


void __fastcall TForm_analisma::report_subenclin_repcvta()
{

  String nombre_z;
  nombre_z = busca_dato("PUNTO_VENTA", ptvta_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "Punto Venta:%s %s", ptvta_z, nombre_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  report_subenclin_analisma();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analisma::report_subenclin_alm()
{

  String nombre_z;
  nombre_z = busca_dato("ALMACEN", alm_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "Almacen:%s %s", alm_z, nombre_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  salta_linea();
  report_subenclin_repcvta();
}
//---------------------------------------------------------------------------


