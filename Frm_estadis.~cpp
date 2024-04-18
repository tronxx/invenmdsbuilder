//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_estadis.h"
#include "situaciones.h"
#include <shellapi.h>
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
#pragma resource "*.dfm"

const int CMB_SAL_ESP           = 0;
const int CMB_SAL_VTA           = 1;
const int CMB_ENT_CAN           = 2;
const int CMB_ENT_ESP           = 3;
const int CMB_SAL_MAY           = 4;
const int CMB_ENT_COM           = 5;

TForm_estadis *Form_estadis;
//---------------------------------------------------------------------------
__fastcall TForm_estadis::TForm_estadis(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_estadis::btn_estadisClick(TObject *Sender)
{
  String nommes_z[]= {"ENE", "FEB", "MAR", "ABR", "MAY", "JUN", "JUL", "AGO", "SEP", "OCT", "NOV", "DIC" };
  String strmes_z, codigo_z, alm_z, selmes_z="", group_z="";
  int tipest_z=0, tipo1_z= -1, tipo2_z = -1, tipo3_z= -1, tipo4_z = -1, tipo5_z = -1,
  nummes_z=0, anu_z=0;
  tipest_z = cmb_tipoestadi->ItemIndex;
  anu_z = edt_anuestadis->IntValue;

  switch (tipest_z) {
    case CMB_SAL_ESP   : tipo1_z = EST_X_SAL_ESP; break;
    case CMB_SAL_VTA   :
       tipo1_z = EST_X_VTA_TRAD; tipo2_z = EST_X_VTA_FON;
       tipo3_z = EST_X_VTA_FID;  tipo4_z = EST_X_VTA_CEL;
        tipo5_z = EST_X_VTA_IMEVI;
       break;
    case CMB_ENT_CAN   :
       tipo1_z = EST_X_CAN_TRAD; tipo2_z = EST_X_CAN_FON;
       tipo3_z = EST_X_CAN_FID; tipo4_z = EST_X_CAN_CEL;
       break;
    case CMB_ENT_ESP   : tipo1_z = EST_X_ENT_ESP; break;
    case CMB_SAL_MAY   : tipo1_z = EST_X_SAL_MAY; break;
    case CMB_ENT_COM   : tipo1_z = EST_X_ENT_COM; break;
  }
  selmes_z =  "cast(NULL as float) as Ene, cast(NULL as float) as Feb,";
  selmes_z += "cast(NULL as float) as Mar, cast(NULL as float) as Abr,";
  selmes_z += "cast(NULL as float) as May, cast(NULL as float) as Jun,";
  selmes_z += "cast(NULL as float) as Jul, cast(NULL as float) as Ago,";
  selmes_z += "cast(NULL as float) as Sep, cast(NULL as float) as Oct,";
  selmes_z += "cast(NULL as float) as Nov, cast(NULL as float) as Dic";
  if(chk_grpxalm->Checked)
    sql_z = "select cast((a.codigo || a.alm) as varchar(20)) as llave, a.codigo, a.alm,";
  else
    sql_z = "select cast((a.codigo) as varchar(20)) as llave, a.codigo, ";
  // Fin de If
  sql_z += " mca.codigo as marca, ";
  sql_z += " sit.situacion as situacion, ";
  sql_z += " dia.grupo as diary,";
  sql_z += " gpo.codigo as grupo,";
  sql_z += " inv.prove as prove,";
  sql_z += " inv.descri as descri,";
  sql_z += " inv.linea as linea, ";

  switch(tipest_z) {
    case CMB_SAL_MAY :
      sql_z += "cast( NULL as FLOAT) as Tot,  ";
      if(chk_grpxalm->Checked)
        sql_z += "nombre, mayo.codigo as zona, ";
      else
        sql_z += " '' as zona, ";
      sql_z += selmes_z +
      " from estadis a join inv_invhist b on a.codigo=b.codigo and a.cia = b.cia";
      sql_z += " join mayoris mayo on a.alm = mayo.codigo and a.cia = mayo.cia ";
      if(chk_grpxalm->Checked)
        group_z += " mayo.codigo, nombre ";
      else
        group_z = " a.codigo ";
      break;
    case CMB_SAL_ESP  :
    case CMB_ENT_ESP  :
    case CMB_ENT_COM  :
      sql_z += "cast( NULL as FLOAT) as Tot, nombre, e.zona, " + selmes_z +
      " from estadis a join inv_invhist b on a.codigo=b.codigo and a.cia = b.cia ";
      if(chk_grpxalm->Checked) {
        sql_z += " join almacen e on a.alm = e.clave and e.cia = a.cia ";
         group_z = " e.zona";
      } else {
         group_z = " a.codigo, inv.descri ";
      }
      break;
    case CMB_SAL_VTA  :
    case CMB_ENT_CAN  :
      sql_z += "cast( NULL as FLOAT) as Tot, ";
      if(chk_grpxalm->Checked) sql_z += " nombre, f.zonaptvta as zona,";
      sql_z += selmes_z +
      " from estadis a join inv_invhist b on a.codigo=b.codigo and a.cia = b.cia ";
      sql_z += " join ptovta e on a.alm = e.clave and e.cia = a.cia ";
      sql_z += " join ubivtainv f on e.clave = f.pvta and f.alm='' ";
      if(chk_grpxalm->Checked) {
        group_z = " f.zonaptvta";
      }
      break;
  }
  // -> Se agrega que siempre tenga los campos
  //if (chk_marca->Checked)
  sql_z += " join inv_relinv ra on b.idart = ra.idart and ra.idrel = " +
     IntToStr(REL_INVEN_MARCAS) +
     " join inv_marcas mca on ra.iddato = mca.idmarcainv ";
  //if (chk_diary->Checked)
  sql_z += " join inv_relinv rb on b.idart = rb.idart and rb.idrel = " +
    IntToStr(REL_INVEN_GPODIARY) +
    " join gpodiary dia on rb.iddato = dia.idgpodiary ";
  //if (chk_situac->Checked)
  sql_z += " join inv_relinv rc on b.idart = rc.idart and rc.idrel = " +
    IntToStr(REL_INVEN_SITUACION) +
    " join inv_situaciones sit on rc.iddato = sit.idsituac ";
  //if (chk_grupo->Checked)
  sql_z += " join inv_relinv rd on b.idart = rd.idart and rd.idrel = " +
    IntToStr(REL_INVEN_ARTDESP) +
    " join inv_grupos gpo on rd.iddato = gpo.idgrupo ";
  //if (chk_linea->Checked)
  sql_z += " join inv_relinv re on b.idart = re.idart and re.idrel = " +
    IntToStr(REL_INVEN_LINEA) +
    " join inv_lineas lin on re.iddato = lin.idlinea ";
    sql_z += " left outer join inven inv on b.codigo = inv.codigo and b.cia = inv.cia ";
  //if(chk_prove->Checked)
  //  sql_z += " join inven inv on b.codigo = inv.codigo and b.cia = inv.cia ";
  sql_z += " where (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU and a.cia = :CIA ";
  if(chk_codigo->Checked) sql_z += " and a.codigo like '" + edt_prcod->Text.Trim() + "'";
  if(chk_marca->Checked) sql_z += " and mca.codigo like '" + edt_prmarca->Text.Trim()  + "'";
  if(chk_situac->Checked) sql_z += " and sit.situacion like '" + edt_prsit->Text.Trim()  + "'";
  if(chk_diary->Checked) sql_z += " and dia.grupo like '" + edt_diary->Text.Trim()  + "'";
  if(chk_grupo->Checked) sql_z += " and gpo.codigo like '" + edt_prgrp->Text.Trim()  + "'";
  if(chk_prove->Checked) sql_z += " and inv.prove like '" + edt_prprove->Text.Trim()  + "'";
  if(chk_linea->Checked) sql_z += " and lin.linea like '" + edt_prlin->Text.Trim()  + "'";
  if(tipest_z ==  CMB_SAL_VTA || tipest_z ==  CMB_ENT_CAN) {
    sql_z += " and f.zonaptvta between '" + qry_zonini->FieldByName("zona")->AsString +
      "' and '" + qry_zonfin->FieldByName("zona")->AsString + "'";
  }
  sql_z += " group by a.codigo, inv.descri ";
  if(chk_grpxalm->Checked) sql_z += " , a.alm, nombre";
  group_z += " ,marca,";
  group_z += " situacion,";
  group_z += " diary,";
  group_z += " grupo,";
  group_z += " inv.prove,";
  group_z += " inv.linea";

  if( !group_z.IsEmpty()) sql_z += ", " + group_z;

  estadialm_z = "select ";
  if(chk_grpxalm->Checked) estadialm_z += " a.alm, ";
  estadialm_z += " a.codigo as codigo, mes, cast(sum(unidades) as integer) as unids from estadis a ";
  estadialm_z += " join inv_invhist b on a.codigo = b.codigo and a.cia = b.cia ";
  if (chk_marca->Checked)
    estadialm_z += " join inv_relinv ra on b.idart = ra.idart and ra.idrel = " +
     IntToStr(REL_INVEN_MARCAS) +
     " join inv_marcas mca on ra.iddato = mca.idmarcainv ";
  if (chk_diary->Checked)
    estadialm_z += " join inv_relinv rb on b.idart = rb.idart and rb.idrel = " +
    IntToStr(REL_INVEN_GPODIARY) +
    " join gpodiary dia on rb.iddato = dia.idgpodiary ";
  if (chk_situac->Checked)
    estadialm_z += " join inv_relinv rc on b.idart = rc.idart and rc.idrel = " +
    IntToStr(REL_INVEN_SITUACION) +
    " join inv_situaciones sit on rc.iddato = sit.idsituac ";
  if (chk_grupo->Checked)
    estadialm_z += " join inv_relinv rd on b.idart = rd.idart and rd.idrel = " +
    IntToStr(REL_INVEN_ARTDESP) +
    " join inv_grupos gpo on rd.iddato = gpo.idgrupo ";
  if (chk_linea->Checked)
    estadialm_z += " join inv_relinv re on b.idart = re.idart and re.idrel = " +
    IntToStr(REL_INVEN_LINEA) +
    " join inv_lineas lin on re.iddato = lin.idlinea ";

  if(chk_prove->Checked)
      estadialm_z += " join inven inv on a.codigo = inv.codigo and a.cia = inv.cia ";
  if(tipest_z ==  CMB_SAL_VTA || tipest_z ==  CMB_ENT_CAN)
      estadialm_z += " join ubivtainv f on a.alm = f.pvta and f.alm='' ";

  estadialm_z += " where a.codigo = :CODART ";
  if(chk_grpxalm->Checked) estadialm_z += " and a.alm = :ALM ";
  estadialm_z += " and (a.tipo= :TIPO1 or a.tipo = :TIPO2 or a.tipo = :TIPO3 or a.tipo = :TIPO4 or a.tipo = :TIPO5) and anu = :ANU and a.cia = :CIA ";
  if(chk_marca->Checked)  estadialm_z += " and mca.codigo like '" + edt_prmarca->Text.Trim()  + "'";
  if(chk_situac->Checked) estadialm_z += " and sit.situacion like '" + edt_prsit->Text.Trim()  + "'";
  if(chk_diary->Checked)  estadialm_z += " and dia.grupo like '" + edt_diary->Text.Trim()  + "'";
  if(chk_grupo->Checked)  estadialm_z += " and gpo.codigo like '" + edt_prgrp->Text.Trim()  + "'";
  if(chk_prove->Checked)  estadialm_z += " and inv.prove like '" + edt_prprove->Text.Trim()  + "'";
  if(chk_linea->Checked)  estadialm_z += " and lin.linea like '" + edt_prlin->Text.Trim()  + "'";

  if(tipest_z ==  CMB_SAL_VTA || tipest_z ==  CMB_ENT_CAN) {
      estadialm_z += " and f.zonaptvta between '" + qry_zonini->FieldByName("zona")->AsString +
        "' and '" + qry_zonfin->FieldByName("zona")->AsString + "'";
  }
  estadialm_z += " group by ";
  if(chk_grpxalm->Checked) estadialm_z += " a.alm, ";
  estadialm_z += " a.codigo, mes";

  if(dbedt_zonini->Tag) {
    TForm *Form_sql = new TForm (this);
    TMemo *mmo_sql = new TMemo (Form_sql);
    mmo_sql->Parent = Form_sql;
    mmo_sql->Lines->Add(sql_z);
    mmo_sql->Lines->Add(":");
    mmo_sql->Lines->Add(estadialm_z);
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

  qry_estadis->DisableControls();
  qry_estadis->Tag = mrCancel;
  qry_estadis->Close();
  qry_estadis->SQL->Text = sql_z;
  qry_estadis->ParamByName("anu")->AsInteger = anu_z;
  qry_estadis->ParamByName("cia")->AsInteger = cia_z;
  qry_estadis->ParamByName("tipo1")->AsInteger = tipo1_z;
  qry_estadis->ParamByName("tipo2")->AsInteger = tipo2_z;
  qry_estadis->ParamByName("tipo3")->AsInteger = tipo3_z;
  qry_estadis->ParamByName("tipo4")->AsInteger = tipo4_z;
  qry_estadis->ParamByName("tipo5")->AsInteger = tipo5_z;
//  qry_estadis->ParamByName("codigo")->AsString = edt_codestad->Text.Trim();
  qry_estadis->Open();

//  delete Form_splash;


  for(qry_estadis->First(); !qry_estadis->Eof; qry_estadis->Next()) {
    codigo_z = qry_estadis->FieldByName("codigo")->AsString;
    if(chk_grpxalm->Checked) alm_z = qry_estadis->FieldByName("alm")->AsString;
    qry_estadialm->Close();
    qry_estadialm->SQL->Text = estadialm_z;
    qry_estadialm->ParamByName("anu")->AsInteger = anu_z;
    qry_estadialm->ParamByName("cia")->AsInteger = cia_z;
    qry_estadialm->ParamByName("tipo1")->AsInteger = tipo1_z;
    qry_estadialm->ParamByName("tipo2")->AsInteger = tipo2_z;
    qry_estadialm->ParamByName("tipo3")->AsInteger = tipo3_z;
    qry_estadialm->ParamByName("tipo4")->AsInteger = tipo4_z;
    qry_estadialm->ParamByName("tipo5")->AsInteger = tipo5_z;
    qry_estadialm->ParamByName("codart")->AsString = codigo_z;
    if(chk_grpxalm->Checked) qry_estadialm->ParamByName("alm")->AsString = alm_z;
    qry_estadialm->Open();
    qry_estadis->Edit();
    for(qry_estadialm->First(); !qry_estadialm->Eof; qry_estadialm->Next()) {
      nummes_z = qry_estadialm->FieldByName("mes")->AsInteger - 1;
      strmes_z = nommes_z[nummes_z];
      qry_estadis->FieldByName(strmes_z)->AsInteger += qry_estadialm->FieldByName("unids")->AsInteger;
      qry_estadis->FieldByName("tot")->AsInteger += qry_estadialm->FieldByName("unids")->AsInteger;
      qry_estadis->FieldByName("codigo")->AsString = qry_estadialm->FieldByName("codigo")->AsString;
    }
    qry_estadis->Post();
  }
  qry_estadis->Tag = mrOk;
  calcu_alto_dbgrid();
  qry_estadis->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TForm_estadis::chk_codigoClick(TObject *Sender)
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
void __fastcall TForm_estadis::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TForm_estadis::BitBtn1Click(TObject *Sender)
{
  String titulo_z = InputBox("Título de la Ventana", "Nuevo Título:", "Estadísticas de:");
  Caption = titulo_z;        
}
//---------------------------------------------------------------------------

void __fastcall TForm_estadis::ExportaraExcel1Click(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  midbgrd_z = dbgrd_estadis;
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
  ShellExecute(NULL,"open",SaveDialog->FileName.c_str(),0,0,SW_SHOWDEFAULT);
  delete SaveDialog;
}
//---------------------------------------------------------------------------

void __fastcall TForm_estadis::FormCreate(TObject *Sender)
{
  qry_zonini->Close();
  qry_zonini->Open();
  lkcmb_zonini->KeyValue = qry_zonini->FieldByName("zona")->AsString;
  qry_zonfin->Close();
  qry_zonfin->Open();
  qry_zonfin->Last();
  lkcmb_zonfin->KeyValue = qry_zonfin->FieldByName("zona")->AsString;
  edt_anuestadis->MaxValue = StrToIntDef(FormatDateTime("yyyy", Now()), 2021);
  edt_anuestadis->IntValue = StrToIntDef(FormatDateTime("yyyy", Now()), 2003);
  chk_codigoClick(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_estadis::dbedt_zoniniDblClick(TObject *Sender)
{
  dbedt_zonini->Tag = !dbedt_zonini->Tag;
}
//---------------------------------------------------------------------------

void __fastcall TForm_estadis::calcu_alto_dbgrid()
{
  int ARowsNumber, ii_z, AHeight;
  dbgrd_estadis->Align = alClient;
  dbgrd_estadis->Align = alNone;
  ARowsNumber = qry_estadis->RecordCount;
  AHeight = 0;
  AHeight = dbgrd_estadis->RowHeight * ARowsNumber +
    dbgrd_estadis->RowSeparatorLineWidth * ( ARowsNumber + 2) ;
  AHeight += dbgrd_estadis->GroupPanelHeight + dbgrd_estadis->FooterPanelHeight +
   + dbgrd_estadis->HeaderHeight;
  if(AHeight < dbgrd_estadis->Height) dbgrd_estadis->Height = AHeight;
}
//---------------------------------------------------------------------------

void __fastcall TForm_estadis::dbgrd_estadisCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
}
//---------------------------------------------------------------------------



