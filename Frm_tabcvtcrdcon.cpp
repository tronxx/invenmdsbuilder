//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_tabcvtcrdcon.h"
#include "numapal.h"
#include "imprigra.h"
#include "stdio.h"
#include "dmod.h"
#include "Frm_prever.h"
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
TForm_tabcvtcrdcon *Form_tabcvtcrdcon;
//---------------------------------------------------------------------------
__fastcall TForm_tabcvtcrdcon::TForm_tabcvtcrdcon(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_tabcvtcrdcon::FormCreate(TObject *Sender)
{
  cia_z = dm->cia_z;
  date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
}
//---------------------------------------------------------------------------
void __fastcall TForm_tabcvtcrdcon::BitBtn1Click(TObject *Sender)
{
  int idtpvtatmp_z=0, idtpvt_z=0, folent_z=0;
  double totcont_z, totcred_z, totfon_z, totfide_z, totimevi_z, costo_z=0;
  String tipoent_z, zona_z, linea_z, descrilin_z, sql_z, descritipo_z,
  nombrezon_z, pvta_z;
  const int VENTAS_CONTADO=1;
  const int VENTAS_CREDITO=2;
  TdxDBGridCurrencyColumn *colcosto_z;
  TdxDBGridMaskColumn     *colmask_z;

  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "select max(IDTAREA) as idtarea, max(IDTPVTATMP) as idtpvtatmp from inv_tpvtatmp";
  dm->qry_maxidvnd->Open();
  idtarea_z = dm->qry_maxidvnd->FieldByName("idtarea")->AsInteger + 1;
  idtpvtatmp_z = dm->qry_maxidvnd->FieldByName("idtpvtatmp")->AsInteger + 1;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "insert into inv_tpvtatmp (IDTPVTATMP, IDTAREA, IDTIPOVTA, FACTOR, TIPOSAL) values ( :IDTPVTATMP, :IDTAREA, :IDTIPOVTA, :FACTOR, :TIPOSAL )";
  for(int ii_z = 0; ii_z < 1; ii_z++) {
    switch (ii_z) {
      case 0: tipoent_z = "V"; break;
      case 1: tipoent_z = "F"; break;
      case 2: tipoent_z = "H"; break;
      case 4: tipoent_z = "1"; break;
    }
    dm->qry_maxidvnd->ParamByName("IDTPVTATMP")->AsInteger = idtpvtatmp_z++;
    dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
    dm->qry_maxidvnd->ParamByName("IDTIPOVTA")->AsInteger = 0;
    dm->qry_maxidvnd->ParamByName("FACTOR")->AsInteger = 1;
    dm->qry_maxidvnd->ParamByName("TIPOSAL")->AsString = tipoent_z;
    dm->qry_maxidvnd->ExecSQL();
  }
  qry_lineas->Close();
  qry_lineas->ParamByName("cia")->AsInteger = cia_z;
  qry_lineas->Open();
  qry_analisma->DisableControls();
  // Primero Elimino todas las columnas
  for(int ii_z=dbgrd_renglones->ColumnCount-1; ii_z >= 0; ii_z--) {
    delete dbgrd_renglones->Columns[ii_z];
  }
  colmask_z = new TdxDBGridMaskColumn (this);
  colmask_z->ATreeList = dbgrd_renglones;
  colmask_z->FieldName = "zonaacum";
  colmask_z->Caption = "Zona";
  colmask_z = new TdxDBGridMaskColumn (this);
  colmask_z->ATreeList = dbgrd_renglones;
  colmask_z->FieldName = "pvta";
  colmask_z->Caption = "Ubica";
  colmask_z = new TdxDBGridMaskColumn (this);
  colmask_z->ATreeList = dbgrd_renglones;
  colmask_z->FieldName = "descritipo";
  colmask_z->Caption = "Crd/Cont";

  sql_z = "select cast('' as varchar(10)) as llave, ";
  sql_z += "numero as zona, descri as nombrezon, ";
  sql_z += "cast('' as varchar(35)) as zonaacum, ";
  sql_z += "numero as pvta, cast('' as varchar(35)) as nompvta, ";
  sql_z += "numero as tipo, cast('' as varchar(10)) as descritipo, ";
  for (qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
    linea_z = qry_lineas->FieldByName("numero")->AsString;
    sql_z += "cast(NULL as float) as " + linea_z + ", ";
    colcosto_z = new TdxDBGridCurrencyColumn (this);
    colcosto_z->ATreeList = dbgrd_renglones;
    colcosto_z->FieldName = linea_z;
    colcosto_z->Caption = linea_z;
  }
  sql_z += "0 as totgral from lineas where cia = -1";
  colcosto_z = new TdxDBGridCurrencyColumn (this);
  colcosto_z->ATreeList = dbgrd_renglones;
  colcosto_z->FieldName = "totgral";
  colcosto_z->Caption = "Total";
  Memo1->Text = sql_z;

  qry_analisma->Close();
  qry_analisma->SQL->Text = sql_z;
  qry_analisma->Open();
  TProgressBar *ProgressBar1;
  ProgressBar1 = new TProgressBar (this);
  ProgressBar1->Parent = pnl_datos;
  ProgressBar1->Step = 1;
  ProgressBar1->Height = 18;
  ProgressBar1->Align = alBottom;
  ProgressBar1->Min = 0;

  qry_buscaventas->Close();
  qry_buscaventas->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_buscaventas->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_buscaventas->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_buscaventas->ParamByName("cia")->AsInteger = cia_z;
  qry_buscaventas->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_buscaventas->Open();
  ProgressBar1->Max = qry_buscaventas->RecordCount * qry_lineas->RecordCount;
  for(qry_buscaventas->First(); !qry_buscaventas->Eof; qry_buscaventas->Next()) {
     zona_z = qry_buscaventas->FieldByName("zonainv")->AsString;
     pvta_z = qry_buscaventas->FieldByName("pvta")->AsString;
     totcont_z=totcred_z=totfon_z=totfide_z=totimevi_z=0;
     ProgressBar1->StepIt();
     for(folent_z = 1; folent_z <= 2; folent_z++) {
       if(folent_z == VENTAS_CONTADO) {
         descritipo_z = "CONTADO";
       }
       if(folent_z == VENTAS_CREDITO) {
         descritipo_z = "CREDITO";
       }

       nombrezon_z = busca_dato("ZONA", zona_z);
       qry_analisma->Append();
       qry_analisma->FieldByName("llave")->AsString = zona_z + "." + pvta_z + "." + IntToStr(folent_z);
       qry_analisma->FieldByName("zona")->AsString = zona_z;
       qry_analisma->FieldByName("zonaacum")->AsString = zona_z + " " + nombrezon_z;
       qry_analisma->FieldByName("nombrezon")->AsString = nombrezon_z;
       qry_analisma->FieldByName("pvta")->AsString = pvta_z;
       qry_analisma->FieldByName("nompvta")->AsString = pvta_z;
       qry_analisma->FieldByName("tipo")->AsString = IntToStr(folent_z);
       qry_analisma->FieldByName("descritipo")->AsString = descritipo_z;
       for(qry_lineas->First(); !qry_lineas->Eof; qry_lineas->Next()) {
         linea_z = qry_lineas->FieldByName("numero")->AsString;
         // Recortado a 1 para que solo se tome en cuenta a pvta
         for (int ii_z = 0; ii_z < 1; ii_z++) {
           switch (ii_z) {
             case 0: tipoent_z = "V"; break;
             case 1: tipoent_z = "F"; break;
             case 2: tipoent_z = "H"; break;
             case 4: tipoent_z = "1"; break;
           }
           qry_datosventas->Close();
           qry_datosventas->ParamByName("fecini")->AsDateTime = date_fecini->Date;
           qry_datosventas->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
           qry_datosventas->ParamByName("cia")->AsInteger = cia_z;
           qry_datosventas->ParamByName("tipo")->AsString = tipoent_z;
           qry_datosventas->ParamByName("zona")->AsString = zona_z;
           qry_datosventas->ParamByName("linea")->AsString = linea_z;
           qry_datosventas->ParamByName("ptovta")->AsString = pvta_z;
           if(tipoent_z == "V") {
             qry_datosventas->ParamByName("folentini")->AsInteger = folent_z;
             qry_datosventas->ParamByName("folentfin")->AsInteger = folent_z;
           } else {
             qry_datosventas->ParamByName("folentini")->AsInteger = 0;
             qry_datosventas->ParamByName("folentfin")->AsInteger = 999999;
           }
           qry_datosventas->Open();
           costo_z = qry_datosventas->FieldByName("costo")->AsFloat;
           totcont_z = costo_z;
           if(tipoent_z == "F") totfon_z += costo_z;
           if(tipoent_z == "H") totfide_z += costo_z;
           if(tipoent_z == "1") totimevi_z += costo_z;
         }
         if(totcont_z) qry_analisma->FieldByName(linea_z)->AsFloat = totcont_z;
         qry_analisma->FieldByName("totgral")->AsFloat += totcont_z;
       }
       qry_analisma->Post();
     }
  }

  delete ProgressBar1;
  qry_analisma->EnableControls();
  //dbgrd_renglones->OptionsView->edgoAutoWitdh=true;
  //dbgrd_renglones->OptionsView->edgoAutoWitdh=false;
  dbgrd_renglones->AddGroupColumn(dbgrd_renglones->Columns[0]);
  dbgrd_renglones->AddGroupColumn(dbgrd_renglones->Columns[1]);
  dbgrd_renglones->FullExpand();
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "delete from inv_tpvtatmp where IDTAREA = :IDTAREA";
  dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
  dm->qry_maxidvnd->ExecSQL();

}
//---------------------------------------------------------------------------
void __fastcall TForm_tabcvtcrdcon::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TForm_tabcvtcrdcon::Exportara1Click(TObject *Sender)
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

void __fastcall TForm_tabcvtcrdcon::exporta_dbgrdExecute(TObject *Sender)
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



void __fastcall TForm_tabcvtcrdcon::dbgrd_renglonesCustomDraw(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxDBTreeListColumn *AColumn,
      const AnsiString AText, TFont *AFont, TColor &AColor, bool ASelected,
      bool AFocused, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvtcrdcon::imprimirExecute(TObject *Sender)
{
  generar_reporte();
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvtcrdcon::generar_reporte()
{
  double total_z=0, subtvend_z=0, subtzona_z=0;
  int LINEAS_X_PAG = 60;
  if (dm->tipoimp_z == IMPRESORA_GRAFICA ) LINEAS_X_PAG = 90;
  String arch_z = "tabcvtcrdcon.txt", titremate_z, antnomubi_z,
    mensaje_z, titmsg_z;
  mensaje_z = "Desea imprimir el reporte ";
  titmsg_z = "Impresión de Reporte de Tabla de Costo de Ventas x Zona y Linea";
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    dm->MensajeError("No puedo abrir el archivo textual de salida", "Error");
    return;
  }
  pagina_z = 1;
  antzona_z  = "-1";
  //--- Aqui Va
  qry_analisma->DisableControls();
  for(qry_analisma->First(); !qry_analisma->Eof; qry_analisma->Next()) {
    zona_z = qry_analisma->FieldByName("zona")->AsString;
    if(antzona_z == "-1") {
      antzona_z = zona_z;
      report_encab();
    }
    if (zona_z != antzona_z) {
        //reporte_subtot(subtvend_z, "Total de " + busca_dato("VENDEDOR", antvend_z), "");
        //reporte_subtot(subtzona_z, "Total de " +    busca_dato("ZONA", antzona_z), "");
        subtvend_z    = 0;
        subtzona_z   = 0;
        antzona_z = zona_z;
        antvend_z = vendedor_z;
        if(lineas_z > LINEAS_X_PAG - 6) {
          fprintf(archout, "%c", 12); pagina_z++; report_encab();
        } else {
          report_subencabzona();
        }
    }
    if (vendedor_z != antvend_z ) {
        //reporte_subtot(subtvend_z, "Total de " + busca_dato("VENDEDOR", antvend_z), "");
        subtvend_z    = 0;
        antvend_z = vendedor_z;
        if(lineas_z > LINEAS_X_PAG - 6) {
          fprintf(archout, "%c", 12); pagina_z++; report_encab();
        } else {
          report_subencabvend();
        }
    }
    if(lineas_z > LINEAS_X_PAG) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab();
    }
    fprintf(archout, "%s|", ljust(qry_analisma->FieldByName("recemi")->AsString, 5));
    fprintf(archout, "%s|", FormatDateTime("dd/mm/yyyy", qry_analisma->FieldByName("fecha")->AsDateTime));
    fprintf(archout, "%s|", ljust(qry_analisma->FieldByName("numero")->AsString, 5));
    fprintf(archout, "%s|", ljust(qry_analisma->FieldByName("codigo")->AsString, 13));
    fprintf(archout, "%s|", ljust(qry_analisma->FieldByName("descri")->AsString, 30));
    fprintf(archout, "\n");
    subtvend_z    += qry_analisma->FieldByName("costotot")->AsFloat;
    total_z      += qry_analisma->FieldByName("costotot")->AsFloat;
    subtzona_z   += qry_analisma->FieldByName("costotot")->AsFloat;
    lineas_z++;
  }
  //reporte_subtot(subtvend_z, "Total de " + busca_dato("VENDEDOR", antvend_z), "");
  //reporte_subtot(subtzona_z, "Total de " +    busca_dato("ZONA", zona_z), "");
  //reporte_subtot(total_z, "Total General", "");
  fclose(archout);
  qry_analisma->EnableControls();

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvtcrdcon::report_encab()
{
  titulo_z = "Relacion de Ventas";
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de %s\n", titulo_z);
  fprintf(archout, "Ventas del :%s  al %s%s \n",
    FormatDateTime("dd-mm-yyyy", date_fecini->Date),
    FormatDateTime("dd-mm-yyyy", date_fecfin->Date),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  fprintf(archout, "%s%s",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF)
  );
  fprintf(archout, "%s|", ljust("Suc", 4));
  fprintf(archout, "%s|", ljust("Fecha Vta", 10));
  fprintf(archout, "%s|", ljust("N.Sal", 5));
  fprintf(archout, "%s|", ljust("Articulo", 44));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z = 5;
  report_subencabzona();
}
//---------------------------------------------------------------------------


void __fastcall TForm_tabcvtcrdcon::report_subencabvend()
{
   String nombre_z="";
   nombre_z = busca_dato("VENDEDOR", antvend_z);
   fprintf(archout, "Vendedor: %s %s\n", antvend_z, nombre_z);
   lineas_z++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvtcrdcon::report_subencabzona()
{
   String nombre_z="";
   nombre_z = busca_dato("ZONA", antzona_z);
   fprintf(archout, "Zona: %s %s\n", antzona_z, nombre_z);
   lineas_z++;
   report_subencabvend();

}
//---------------------------------------------------------------------------

String __fastcall TForm_tabcvtcrdcon::busca_dato(String tipodato_z, String clave_z)
{
   String nombre_z="", sql_z;
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   if (tipodato_z == "VENDEDOR") {
     sql_z = "select nombre from vendedor where codigo = :CLAVE";
   } else if (tipodato_z == "ZONA") {
     sql_z = "select nombre from zonainv where zona = :CLAVE";
   } else if (tipodato_z == "LINEA") {
     sql_z = "select descri as nombre from lineas where numero= :CLAVE";
   }
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->ParamByName("CLAVE")->AsString = clave_z;
   dm->qry_maxidvnd->Open();
   if(!dm->qry_maxidvnd->IsEmpty())
     nombre_z = dm->qry_maxidvnd->FieldByName("nombre")->AsString;
   return (nombre_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_tabcvtcrdcon::reporte_subtot(double importe_z, String tit_z, String tipo_z)
{
  double PIVA_Z = 15, antesiva_z;
  if(tipo_z == "N") {
    antesiva_z = importe_z / ( PIVA_Z / 100 + 1 );
    fprintf(archout, "%s %s\n",
      rjust(tit_z + " Antes de Iva", 105),
      rjust(FormatFloat("###,##0.00", antesiva_z), 12)
    );
    lineas_z++;
  }
  fprintf(archout, "%s %s\n",
    rjust(tit_z, 69),
    rjust(FormatFloat("###,##0.00", importe_z), 12)
  );
  lineas_z++;
}
//---------------------------------------------------------------------------

