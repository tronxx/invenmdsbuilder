//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_exists.h"
#include "inven_constants.h"
#include "dmod.h"
#include "numapal.h"
#include <inifiles.hpp>
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxLayout"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"

TForm_exists *Form_exists;
//---------------------------------------------------------------------------
__fastcall TForm_exists::TForm_exists(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_exists::btn_estadisClick(TObject *Sender)
{
  String codigo_z, alm_z, sqlexi_z, sqlalm_z, sqlcod_z, descri_z;
  int exist_z, univtas_z, univtasmay_z, univtasmen_z, univtmay_z,
      maximo_z, maximay_z, maximoant_z;
  unsigned short anu_z, mes_z, dia_z;
  double costo_z, plista_z, mub_z;
  TDateTime fecalta_z, fecexi_z, inianu_z;
  TStringList *alms_z = new TStringList();
  TLocateOptions Opts;
  Opts.Clear();
//  tipest_z = cmb_tipoestadi->ItemIndex;
  inianu_z = dm->inianuestadis();
  fecexi_z = date_fecexis->Date;
  DecodeDate(fecexi_z, anu_z, mes_z, dia_z);

//  sqlalm_z = "select clave, nombre from almacen order by ordiary";
//  qry_nombrestad->Close();
//  qry_nombrestad->SQL->Text = sqlalm_z;
//  qry_nombrestad->Open();
//  sqlalm_z = "select cast(null as varchar(13)) as codigo";
//  for (qry_nombrestad->First(); !qry_nombrestad->Eof; qry_nombrestad->Next()) {
//    sqlalm_z += ", cast(NULL as Integer) as _" + qry_nombrestad->FieldByName("clave")->AsString;
//  }
//  sqlalm_z += ", cast(null as integer) as total from almacen where clave = 'xx' ";
//  qry_exist->Close();
//  qry_exist->SQL->Text = sqlalm_z;
//  qry_exist->Open();
//  dbgrd_exist->CreateDefaultColumns(dbgrd_exist->DataSource->DataSet, dbgrd_exist);
  qry_exist->Close();
  qry_exist->Open();

  sqlexi_z = "select a.codigo, a.almac as alm, count(*) as exist from inv_invhist b join movart a on b.codigo = a.codigo and b.cia = a.cia";
  sqlcod_z = "select b.codigo, (salvtas + salvtan + salfons + salfonn) as univta, ";
  sqlcod_z += "(salmays + salmayn) as univtamay";

  sqlcod_z += ", cast(NULL As integer) as total";
  sqlcod_z += " from inv_invhist b join movart a on b.codigo = a.codigo and b.cia = a.cia";
  if (chk_marca->Checked) {
    sqlexi_z += " join inv_relinv ra on b.idart = ra.idart and ra.idrel = " +
     IntToStr(REL_INVEN_MARCAS) +
     " join inv_marcas mca on ra.iddato = mca.idmarcainv ";
    sqlcod_z += " join inv_relinv ra on b.idart = ra.idart and ra.idrel = " +
     IntToStr(REL_INVEN_MARCAS) +
     " join inv_marcas mca on ra.iddato = mca.idmarcainv ";
  }
  if (chk_diary->Checked) {
    sqlexi_z += " join inv_relinv rb on b.idart = rb.idart and rb.idrel = " +
    IntToStr(REL_INVEN_GPODIARY) +
    " join gpodiary dia on rb.iddato = dia.idgpodiary ";
    sqlcod_z += " join inv_relinv rb on b.idart = rb.idart and rb.idrel = " +
    IntToStr(REL_INVEN_GPODIARY) +
    " join gpodiary dia on rb.iddato = dia.idgpodiary ";
  }
  if (chk_situac->Checked) {
    sqlexi_z += " join inv_relinv rc on b.idart = rc.idart and rc.idrel = " +
    IntToStr(REL_INVEN_SITUACION) +
    " join inv_situaciones sit on rc.iddato = sit.idsituac ";
    sqlcod_z += " join inv_relinv rc on b.idart = rc.idart and rc.idrel = " +
    IntToStr(REL_INVEN_SITUACION) +
    " join inv_situaciones sit on rc.iddato = sit.idsituac ";
  }
  if (chk_grupo->Checked) {
    sqlexi_z += " join inv_relinv rd on b.idart = rd.idart and rd.idrel = " +
    IntToStr(REL_INVEN_ARTDESP) +
    " join inv_grupos gpo on rd.iddato = gpo.idgrupo ";
    sqlcod_z += " join inv_relinv rd on b.idart = rd.idart and rd.idrel = " +
    IntToStr(REL_INVEN_ARTDESP) +
    " join inv_grupos gpo on rd.iddato = gpo.idgrupo ";
  }
  if (chk_linea->Checked) {
    sqlexi_z += " join inv_relinv re on b.idart = re.idart and re.idrel = " +
    IntToStr(REL_INVEN_LINEA) +
    " join inv_lineas lin on re.iddato = lin.idlinea ";
    sqlcod_z += " join inv_relinv re on b.idart = re.idart and re.idrel = " +
    IntToStr(REL_INVEN_LINEA) +
    " join inv_lineas lin on re.iddato = lin.idlinea ";
  }
  if(chk_prove->Checked) {
    sqlexi_z += " join inven inv on b.codigo = inv.codigo and b.cia = inv.cia ";
    sqlcod_z += " join inven inv on b.codigo = inv.codigo and b.cia = inv.cia ";
  }
  sqlexi_z += " join almacen alm on a.almac = alm.clave and a.cia = alm.cia ";
  sqlcod_z += " join almacen alm on a.almac = alm.clave and a.cia = alm.cia ";

  sqlexi_z += " where a.fecha <= :FECEXIS and ( a.salio <> 'S' or ( a.salio = 'S' and fechasal > :FECEXIS ) ) and a.cia = :CIA ";
  sqlcod_z += " where a.fecha <= :FECEXIS and ( a.salio <> 'S' or ( a.salio = 'S' and fechasal > :FECEXIS ) ) and a.cia = :CIA ";

  if(chk_codigo->Checked) {
    sqlexi_z += " and a.codigo like '" + edt_prcod->Text.Trim() + "'";
    sqlcod_z += " and a.codigo like '" + edt_prcod->Text.Trim() + "'";
  }
  if(chk_marca->Checked) {
    sqlexi_z += " and mca.codigo like '" + edt_prmarca->Text.Trim()  + "'";
    sqlcod_z += " and mca.codigo like '" + edt_prmarca->Text.Trim()  + "'";
  }
  if(chk_situac->Checked) {
    sqlexi_z += " and sit.situacion like '" + edt_prsit->Text.Trim()  + "'";
    sqlcod_z += " and sit.situacion like '" + edt_prsit->Text.Trim()  + "'";
  }
  if(chk_diary->Checked) {
    sqlexi_z += " and dia.grupo like '" + edt_diary->Text.Trim()  + "'";
    sqlcod_z += " and dia.grupo like '" + edt_diary->Text.Trim()  + "'";
  }
  if(chk_grupo->Checked) {
    sqlexi_z += " and gpo.codigo like '" + edt_prgrp->Text.Trim()  + "'";
    sqlcod_z += " and gpo.codigo like '" + edt_prgrp->Text.Trim()  + "'";
  }
  if(chk_prove->Checked) {
    sqlexi_z += " and inv.prove like '" + edt_prprove->Text.Trim()  + "'";
    sqlcod_z += " and inv.prove like '" + edt_prprove->Text.Trim()  + "'";
  }
  if(chk_linea->Checked) {
    sqlexi_z += " and lin.linea like '" + edt_prlin->Text.Trim()  + "'";
    sqlcod_z += " and lin.linea like '" + edt_prlin->Text.Trim()  + "'";
  }
  sqlexi_z += " and alm.zona between '" + qry_zonini->FieldByName("zona")->AsString +
      "' and '" + qry_zonfin->FieldByName("zona")->AsString + "'";
  sqlcod_z += " and alm.zona between '" + qry_zonini->FieldByName("zona")->AsString +
      "' and '" + qry_zonfin->FieldByName("zona")->AsString + "'";
  sqlexi_z += " group by a.codigo, a.almac";
  sqlcod_z += " group by llave, a.codigo, a.almTot, nombre, zona";

  if(dbedt_zonini->Tag) {
    TForm *Form_sql = new TForm (this);
    TMemo *mmo_sql = new TMemo (Form_sql);
    mmo_sql->Parent = Form_sql;
    mmo_sql->Lines->Add(sqlexi_z);
    mmo_sql->Lines->Add(":");
    mmo_sql->Lines->Add(sqlcod_z);
    mmo_sql->Align = alClient;
    Form_sql->ShowModal();
    delete Form_sql;
  }

//  TForm *Form_splash = new TForm (this);
//  Form_splash->Position = poDesktopCenter;
//  Form_splash->FormStyle = fsStayOnTop;
//  Form_splash->BorderStyle = bsNone;
//  TLabel *lbl_aviso = new TLabel (Form_splash);
//  lbl_aviso->Parent = Form_splash;
//  lbl_aviso->ParentColor = true;
//  lbl_aviso->Font = Font;
//  lbl_aviso->Caption = "Procesando la Consulta... Espere por favor...";
//  lbl_aviso->Align = alClient;
//  lbl_aviso->Visible = true;
//  Form_splash->Show();
//  Form_splash->Refresh();

  qry_estadis->Close();
  qry_estadis->SQL->Text = sqlexi_z;
  qry_estadis->ParamByName("fecexis")->AsDateTime = fecexi_z;
  qry_estadis->ParamByName("cia")->AsInteger = cia_z;
  qry_estadis->Open();
  alms_z->Clear();
//  dbgrd_exist->Options = (dbgrd_exist->Options >> egoAutoWidth);
  qry_exist->Tag = mrCancel;
  qry_exist->DisableControls();
  for (qry_estadis->First(); !qry_estadis->Eof; qry_estadis->Next()) {
    alm_z = "xx" + qry_estadis->FieldByName("alm")->AsString;
    exist_z = qry_estadis->FieldByName("exist")->AsInteger;
    codigo_z = qry_estadis->FieldByName("codigo")->AsString;
    qry_exist->First();
    if(qry_exist->Locate("codigo", codigo_z, Opts)) {
      qry_exist->Edit();
    } else {
      qry_exist->Append();
      qry_exist->FieldByName("codigo")->AsString = codigo_z;
      qry_codigo->Close();
      qry_codigo->ParamByName("codigo")->AsString = codigo_z;
      qry_codigo->ParamByName("cia")->AsInteger = cia_z;
      qry_codigo->Open();
      if(!qry_codigo->IsEmpty()) {
        descri_z = qry_codigo->FieldByName("descri")->AsString;
        plista_z = qry_codigo->FieldByName("precio")->AsFloat;
        if(plista_z)
          mub_z = (1 - qry_codigo->FieldByName("coston")->AsFloat / plista_z)* 100;
        else
          mub_z    = 0;
        qry_exist->FieldByName("descripcion")->AsString = descri_z;
        qry_exist->FieldByName("mub")->AsFloat = mub_z;

        //qry_ventas->Close();
        //qry_ventas->ParamByName("codigo")->AsString = codigo_z;
        //qry_ventas->ParamByName("cia")->AsInteger = cia_z;
        //qry_ventas->ParamByName("tipovta")->AsInteger = EST_X_VTA_TRAD;
        //qry_ventas->ParamByName("tipofon")->AsInteger = EST_X_VTA_FON;
        //qry_ventas->ParamByName("tipofid")->AsInteger = EST_X_VTA_FID;
        //qry_ventas->ParamByName("tipocel")->AsInteger = EST_X_VTA_CEL;
        //qry_ventas->ParamByName("perioini")->AsInteger = FormatDateTime("yyyymm", inianu_z).ToInt();
        //qry_ventas->ParamByName("periofin")->AsInteger = FormatDateTime("yyyymm", date_fecexis->Date).ToInt();
        //qry_ventas->Open();
        costo_z = qry_codigo->FieldByName("coston")->AsFloat;
        univtas_z = qry_codigo->FieldByName("ventas")->AsFloat;
        univtmay_z = qry_codigo->FieldByName("univtamay")->AsFloat;

        //univtas_z = qry_ventas->FieldByName("univta")->AsInteger;
        fecalta_z = qry_codigo->FieldByName("fecalta")->AsDateTime;
        qry_exist->FieldByName("precio")->AsString = plista_z;
        qry_exist->FieldByName("costo")->AsFloat = costo_z;
        univtasmen_z = busca_unidades_vendidas(codigo_z, "VENTAS_MENUDEO");
        univtasmay_z = busca_unidades_vendidas(codigo_z, "VENTAS_MAYOREO");

        maximo_z = inv_maximo(
          fecalta_z, univtas_z, fecexi_z, inianu_z,
          maxdiasglo_z, maxdiasmen_z, univtasmen_z
        );
        maximay_z = inv_maximo(
          fecalta_z, univtmay_z, fecexi_z, inianu_z,
          maxdiasglo_z, maxdiasmay_z, univtasmay_z
        );
        maximoant_z = busca_maximoant(codigo_z);
        if(maximoant_z > maximo_z) maximo_z = maximoant_z;
        qry_exist->FieldByName("maximo")->AsInteger  = maximo_z;
        qry_exist->FieldByName("maxmay")->AsInteger = maximay_z;
        qry_exist->FieldByName("ventas")->AsInteger  = univtas_z;
      }
    }
    qry_exist->FieldByName(alm_z)->AsInteger += exist_z;
    qry_exist->FieldByName("total")->AsInteger += exist_z;
    qry_exist->Post();
  }
//  delete Form_splash;
//  dbgrd_exist->Options = (dbgrd_exist->Options << egoAutoWidth);
  dbgrd_exist->OptionsBehavior = (dbgrd_exist->OptionsBehavior << edgoMultiSort);
  calcu_alto_dbgrid();
  qry_exist->First();
  qry_exist->Tag = mrOk;
  qry_exist->EnableControls();
}
//---------------------------------------------------------------------------

int __fastcall TForm_exists::busca_maximoant(String codigo_z)
{

  int anuant_z=0, maximoant_z=0;
  String strfec_z;
  TDateTime hoy_z;
  hoy_z = date_fecexis->Date;
  strfec_z = FormatDateTime("mmdd", hoy_z);
  anuant_z = FormatDateTime("yyyy", hoy_z).ToInt();
  anuant_z = anuant_z - 1;

  if(strfec_z < "0301") {
    dm->qry_sigid->Close();
    dm->qry_sigid->SQL->Clear();
    dm->qry_sigid->SQL->Add("select unidades as maximo from estadis where codigo = :CODIGO and anu = :ANU and tipo=:TIPO and cia=:CIA");
    dm->qry_sigid->ParamByName("codigo")->AsString = codigo_z;
    dm->qry_sigid->ParamByName("anu")->AsInteger = anuant_z;
    dm->qry_sigid->ParamByName("cia")->AsInteger = cia_z;
    dm->qry_sigid->ParamByName("tipo")->AsInteger = EST_TIPO_MAXIMO;
    dm->qry_sigid->Open();
    if(!dm->qry_sigid->IsEmpty()) {
      maximoant_z = dm->qry_sigid->FieldByName("maximo")->AsInteger;
    }
  }
  return (maximoant_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_exists::chk_codigoClick(TObject *Sender)
{
  edt_prcod->Enabled = chk_codigo->Checked;
  edt_prmarca->Enabled = chk_marca->Checked;
  edt_prsit->Enabled = chk_situac->Checked;
  edt_prgrp->Enabled = chk_grupo->Checked;
  edt_prprove->Enabled = chk_prove->Checked;
  edt_prlin->Enabled = chk_linea->Checked;
  edt_diary->Enabled = chk_diary->Checked;
}
//---------------------------------------------------------------------------
void __fastcall TForm_exists::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TForm_exists::BitBtn1Click(TObject *Sender)
{
  String titulo_z = InputBox("Título de la Ventana", "Nuevo Título:", "Estadísticas de:");
  Caption = titulo_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exists::ExportaraExcel1Click(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  midbgrd_z = dbgrd_exist;
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = "*.xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    switch( SaveDialog->FilterIndex) {
      case 1: midbgrd_z->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
      case 2: midbgrd_z->SaveToXLS(SaveDialog->FileName, true); break;
      case 3: midbgrd_z->SaveToHTML(SaveDialog->FileName, true); break;
    }
  }
  delete SaveDialog;
}
//---------------------------------------------------------------------------

void __fastcall TForm_exists::FormCreate(TObject *Sender)
{
  String sqlalm_z, alm_z, config_z;
  int ii_z=0, essuma_z=0;
  cia_z = dm->cia_z;
  config_z = dm->config_z;
  TIniFile *ini;
  ini = new TIniFile(config_z);
  maxdiasglo_z = ini->ReadInteger("MAXIMOS", "DIAS_GLOBAL",  30);
  maxdiasmen_z = ini->ReadInteger("MAXIMOS", "DIAS_MENUDEO", 90);
  maxdiasmay_z = ini->ReadInteger("MAXIMOS", "DIAS_MAYOREO", 60);

  qry_zonini->Close();
  qry_zonini->Open();
  lkcmb_zonini->KeyValue = qry_zonini->FieldByName("zona")->AsString;
  qry_zonfin->Close();
  qry_zonfin->Open();
  qry_zonfin->Last();
  lkcmb_zonfin->KeyValue = qry_zonfin->FieldByName("zona")->AsString;
  date_fecexis->Date = dm->ahora();
  chk_codigoClick(Sender);
  sqlalm_z = "select clave, nombre from almacen where cia = " + IntToStr(cia_z)+" and status = 'A' order by ordiary";
  qry_nombrestad->Close();
  qry_nombrestad->SQL->Text = sqlalm_z;
  qry_nombrestad->Open();
  sqlalm_z = "select cast(null as varchar(13)) as codigo, cast(null as varchar(30)) as descripcion";
  sqlalm_z += ", cast(NULL as float) as mub";
  for (qry_nombrestad->First(); !qry_nombrestad->Eof; qry_nombrestad->Next()) {
    sqlalm_z += ", cast(NULL as Integer) as xx" + qry_nombrestad->FieldByName("clave")->AsString;
  }
  sqlalm_z += ", cast(null as integer) as total, cast(null as float) as costo";
  sqlalm_z += ", cast(null as integer) as maximo";
  sqlalm_z += ", cast(null as integer) as maxmay ";
  sqlalm_z += ", cast(null as integer) as ventas";
  sqlalm_z += ", cast(null as float) as precio";
  sqlalm_z += "  from almacen where clave = 'xx' ";
  qry_exist->Close();
  qry_exist->SQL->Text = sqlalm_z;
  qry_exist->Open();
  dbgrd_exist->CreateDefaultColumns(dbgrd_exist->DataSource->DataSet, dbgrd_exist);
  TdxDBGridCurrencyColumn *colcosto;
  TdxDBTreeListColumn *antcolcosto;
  antcolcosto = dbgrd_exist->ColumnByFieldName("COSTO");
  delete antcolcosto;
  colcosto = new TdxDBGridCurrencyColumn (this);
  colcosto->ATreeList = dbgrd_exist;
  colcosto->FieldName = "COSTO";
  colcosto->Caption = "Costo U.Neto";
  antcolcosto = dbgrd_exist->ColumnByFieldName("PRECIO");
  delete antcolcosto;
  antcolcosto = dbgrd_exist->ColumnByFieldName("CODIGO");
  delete antcolcosto;
  colcosto = new TdxDBGridCurrencyColumn (this);
  colcosto->ATreeList = dbgrd_exist;
  colcosto->FieldName = "PRECIO";
  colcosto->Caption = "Precio Lista";
  antcolcosto = dbgrd_exist->ColumnByFieldName("MUB");
  delete antcolcosto;
  colcosto = new TdxDBGridCurrencyColumn (this);
  colcosto->ATreeList = dbgrd_exist;
  colcosto->FieldName = "MUB";
  colcosto->Caption = "M.U.B.";
  colcosto->DisplayFormat = "0.00;-,0.00";
  colcosto->DecimalPlaces = 2;
  ii_z = dbgrd_exist->ColumnCount - 2;
//  dbgrd_exist->Columns[ii_z]->DecimalPlaces = 2;
//  dbgrd_exist->Columns[ii_z]->FieldName("COSTO");
//  (*TdxDBGridCurrencyColumn)(dbgrd_exist->Columns[ii_z])->Properties->DisplayFormat("$,0.00;-$,0.00");
  for(ii_z=0; ii_z < dbgrd_exist->ColumnCount; ii_z++) {
    essuma_z=0;
    alm_z = dbgrd_exist->Columns[ii_z]->Caption;
    if(alm_z.SubString(1, 2).UpperCase() == "XX") {
      alm_z = alm_z.SubString(3, alm_z.Length() -2 );
      essuma_z = 1;
      dbgrd_exist->Columns[ii_z]->Width = dbgrd_exist->Columns[ii_z]->MinWidth;
    }
    if(alm_z == "TOTAL" || alm_z == "VENTAS" ) essuma_z = 1;
    if(essuma_z) {
      dbgrd_exist->Columns[ii_z]->SummaryFooterField = dbgrd_exist->Columns[ii_z]->FieldName;  //Set the field which values will be summarized in the footer cell
      dbgrd_exist->Columns[ii_z]->SummaryFooterType = cstSum;  //Set the summary type (SUM)
      dbgrd_exist->Columns[ii_z]->SummaryFooterFormat = "0";  //Set the summary format
    }
    if(alm_z.Length() > 1) alm_z = alm_z.SubString(1, 1) + alm_z.SubString(2, alm_z.Length() -1).LowerCase();
    dbgrd_exist->Columns[ii_z]->Caption = alm_z;
  }
  //dbgrd_exist->ColumnByFieldName("CODIGO")->Width = dbgrd_exist->Canvas->TextWidth("O") * 13;
  //dbgrd_exist->ColumnByFieldName("DESCRIPCION")->Width = dbgrd_exist->Canvas->TextWidth("O") * 25;
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("VENTAS"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("COSTO"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("MAXIMO"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("MAXMAY"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("TOTAL"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("PRECIO"));
  dbgrd_exist->ApplyBestFit(dbgrd_exist->ColumnByFieldName("MUB"));
  date_fecexis->Date = dm->ahora();
}
//---------------------------------------------------------------------------

void __fastcall TForm_exists::dbedt_zoniniDblClick(TObject *Sender)
{
  dbedt_zonini->Tag = !dbedt_zonini->Tag;
}
//---------------------------------------------------------------------------


void __fastcall TForm_exists::calcu_alto_dbgrid()
{
  int ARowsNumber, ii_z, AHeight;
  dbgrd_exist->Align = alClient;
  dbgrd_exist->Align = alNone;
  ARowsNumber = qry_exist->RecordCount;
  AHeight = 0;
  AHeight = dbgrd_exist->RowHeight * (ARowsNumber + 1) +
    dbgrd_exist->RowSeparatorLineWidth * ARowsNumber - 1;
  AHeight += dbgrd_exist->GroupPanelHeight + dbgrd_exist->FooterPanelHeight +
   + dbgrd_exist->HeaderHeight;
  if(AHeight < dbgrd_exist->Height) dbgrd_exist->Height = AHeight;
}
//---------------------------------------------------------------------------


void __fastcall TForm_exists::dbgrd_existCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
}
//---------------------------------------------------------------------------

int __fastcall TForm_exists::busca_unidades_vendidas(
  String codigo_z, String tiposalida_z
)
{
  int unidades_z=0, dias_z, ancho_z, alto_z;
  String tipovta_z, sql_z;
  TDateTime fecini_z;
  double hoy_z;
  hoy_z = dm->ahora();
  sql_z = "select sum(unids) as unids from entradas a join renentra b on ";
  sql_z += "a.tipo = b.tipo and a.numero = b.numero and a.alm = b.alm ";
  sql_z += " and a.cia = b.cia where a.tipo = :TIPOVTA ";
  sql_z += " and a.fecha between :FECINI and :FECFIN and a.status = 'C' ";
  sql_z += " and a.cia = :CIA ";
  sql_z += " and b.codinv  = :CODIGO ";

  if(tiposalida_z == "VENTAS_MENUDEO") {
    tipovta_z = "V";
    dias_z = maxdiasmen_z;
  }
  if(tiposalida_z == "VENTAS_MAYOREO") {
    tipovta_z = "M";
    dias_z = maxdiasmay_z;
  }
  fecini_z = hoy_z - dias_z;
  if( ( hoy_z - dias_z) >= 1) {
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Text = sql_z;
    dm->qry_maxidvnd->ParamByName("fecini")->AsDateTime = fecini_z;
    dm->qry_maxidvnd->ParamByName("fecfin")->AsDateTime = hoy_z;
    dm->qry_maxidvnd->ParamByName("codigo")->AsString = codigo_z;
    dm->qry_maxidvnd->ParamByName("tipovta")->AsString = tipovta_z;
    dm->qry_maxidvnd->ParamByName("cia")->AsInteger = cia_z;
    dm->qry_maxidvnd->Open();
    if(!dm->qry_maxidvnd->IsEmpty()) {
      unidades_z = dm->qry_maxidvnd->FieldByName("unids")->AsInteger;
    }
  }
  return (unidades_z);
}
