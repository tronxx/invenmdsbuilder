//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Form_analivtacyc.h"
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
TForm_analivtacyc *Form_analivtacyc;
//---------------------------------------------------------------------------
__fastcall TForm_analivtacyc::TForm_analivtacyc(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_analivtacyc::FormCreate(TObject *Sender)
{
  cia_z = dm->cia_z;
  date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
  cmb_tiporep->ItemIndex = 0;
  cmb_netobru->ItemIndex = 0;
  cmb_statsino->ItemIndex = 0;
  cmb_statcan->ItemIndex = 0;
  cmb_contycre->ItemIndex = 0;
}
//---------------------------------------------------------------------------
void __fastcall TForm_analivtacyc::BitBtn1Click(TObject *Sender)
{
  int idtpvtatmp_z=0, idtpvt_z=0, credito_z, contado_z, tc_z, vtbruoneta_z;
  String tipoent_z, siono1_z, siono2_z, entcan1_z, entcan2_z,
  sql_z, prlin_z, ullin_z, ptvtini_z, ptvtfin_z;
  const int VTA_BRUTA = 0;
  const int VTA_NETA = 1;
  const int CANCELACIONES = 2;

  const int VENTAS_TRADICIONALES = 0;
  const int VENTAS_FIDE = 1;
  const int VENTAS_FONACOT = 2;
  const int TRAD_FON_Y_FIDE= 3;
  const int VENTAS_MAYOREO = 4;
  const int VENTAS_CELULAR = 5;
  const int ENTRADAS = 6;
  const int NO_IMPORTA_STATUS_CANCEL=0;
  const int SOLO_STATUS_CANCEL=1;
  const int SOLO_STATUS_NO_CANCEL=2;
  const int CONTADO_Y_CREDITO=0;
  const int SOLO_CONTADO=1;
  const int SOLO_CREDITO=2;
  const int SOLO_TC=3;
  const int NO_IMPORTA_STATUS_SI_NO=0;
  const int SOLO_STATUS_SI=1;
  const int SOLO_STATUS_NO=2;

  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "select max(IDTAREA) as idtarea, max(IDTPVTATMP) as idtpvtatmp from inv_tpvtatmp";
  dm->qry_maxidvnd->Open();
  idtarea_z = dm->qry_maxidvnd->FieldByName("idtarea")->AsInteger + 1;
  idtpvtatmp_z = dm->qry_maxidvnd->FieldByName("idtpvtatmp")->AsInteger + 1;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "insert into inv_tpvtatmp (IDTPVTATMP, IDTAREA, IDTIPOVTA, FACTOR, TIPOSAL) values ( :IDTPVTATMP, :IDTAREA, :IDTIPOVTA, :FACTOR, :TIPOSAL )";
  idtpvt_z = cmb_tiporep->ItemIndex;
  vtbruoneta_z = cmb_netobru->ItemIndex;
  if(idtpvt_z == TRAD_FON_Y_FIDE) {
    if( vtbruoneta_z == VTA_BRUTA || vtbruoneta_z == VTA_NETA) {
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, 1, "V");
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, 1, "F");
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, 1, "H");
    }
    if( vtbruoneta_z == VTA_BRUTA || vtbruoneta_z == VTA_NETA) {
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, -1, "C");
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, -1, "O");
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, -1, "J");
    }
  } else {
    if( vtbruoneta_z == VTA_BRUTA || vtbruoneta_z == VTA_NETA) {
      switch (idtpvt_z) {
        case VENTAS_TRADICIONALES:        tipoent_z = "V"; break;
        case VENTAS_MAYOREO:              tipoent_z = "M"; break;
        case VENTAS_FONACOT:              tipoent_z = "F"; break;
        case VENTAS_FIDE:                 tipoent_z = "H"; break;
        case VENTAS_CELULAR:              tipoent_z = "Q"; break;
        case ENTRADAS:                    tipoent_z = "E"; break;
      }
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, 1, tipoent_z);
    }
    if(cmb_netobru->ItemIndex == CANCELACIONES || cmb_netobru->ItemIndex == VTA_NETA) {
      switch (idtpvt_z) {
        case VENTAS_TRADICIONALES:         tipoent_z = "C"; break;
        case VENTAS_MAYOREO:               tipoent_z = "Y"; break;
        case VENTAS_FONACOT:               tipoent_z = "O"; break;
        case VENTAS_FIDE:                  tipoent_z = "J"; break;
        case VENTAS_CELULAR:               tipoent_z = "U"; break;
        case ENTRADAS:                     tipoent_z = "R"; break;
      }
      agrega_tipovta(idtpvtatmp_z++, idtarea_z, -1, tipoent_z);
    }
  }
  credito_z = contado_z = -1;
  prlin_z = edt_prlin->Text;
  ullin_z = edt_ullin->Text;
  ptvtini_z = edt_ptvtini->Text.Trim();
  ptvtfin_z = edt_ptvtfin->Text.Trim();
  if(cmb_statcan->ItemIndex == NO_IMPORTA_STATUS_CANCEL || cmb_statcan->ItemIndex == SOLO_STATUS_CANCEL) entcan1_z = "S";
  if(cmb_statcan->ItemIndex == NO_IMPORTA_STATUS_CANCEL || cmb_statcan->ItemIndex == SOLO_STATUS_NO_CANCEL) entcan2_z = "N";
  if(cmb_statsino->ItemIndex == NO_IMPORTA_STATUS_SI_NO || cmb_statsino->ItemIndex == SOLO_STATUS_SI) siono1_z = "S";
  if(cmb_statsino->ItemIndex == NO_IMPORTA_STATUS_SI_NO || cmb_statsino->ItemIndex == SOLO_STATUS_NO) siono2_z = "N";
  if(cmb_contycre->ItemIndex == CONTADO_Y_CREDITO || cmb_contycre->ItemIndex == SOLO_CONTADO) contado_z = 1;
  if(cmb_contycre->ItemIndex == CONTADO_Y_CREDITO || cmb_contycre->ItemIndex == SOLO_CREDITO) credito_z = 2;
  if(cmb_contycre->ItemIndex == CONTADO_Y_CREDITO || cmb_contycre->ItemIndex == SOLO_TC) tc_z = 4;
  sql_z = "select ";
  sql_z += "( case b.tipo when 'V' then folent else 1 end ) as folent, ";
  sql_z += "b.recemi, a.fecha, c.linea, c.codigo, ";
  sql_z += "c.descri, c.empaqe, b.costou,  b.prvta * (b.piva/100+1) as prvta, ";
  sql_z += "b.unids, (b.costou * (b.piva/100+1) * factor) as costotot, ";
  sql_z += "concepto as nombre ";
  sql_z += "from inv_tpvtatmp f join entradas a on f.tiposal=a.tipo ";
  sql_z += "join renentra b on a.numero=b.numero and a.tipo=b.tipo ";
  sql_z += "and a.alm=b.alm and a.numero=b.numero and a.cia=b.cia ";
  sql_z += "join inven c on b.codinv=c.codigo and b.cia=c.cia ";
  sql_z += "join conceps e on b.persenvrec = e.ncon ";
  sql_z += "where ";
  sql_z += "f.idtarea = :IDTAREA and a.fecha between :FECINI and :FECFIN ";
  sql_z += " and a.cia= :CIA and (b.siono  = :SIONO1  or b.siono  = :SIONO2) ";
  sql_z += "and (b.entcan = :ENTCAN1 or b.entcan = :ENTCAN2) ";
  sql_z += " and c.linea between :PRLIN and :ULLIN ";
  if(idtpvt_z == VENTAS_TRADICIONALES) {
     sql_z += " and (b.folent = :CONTADO or b.folent = :CREDITO or b.folent = :TCRED ) ";
  }
  if(idtpvt_z == TRAD_FON_Y_FIDE ||
     idtpvt_z == VENTAS_TRADICIONALES ||
     idtpvt_z == VENTAS_FONACOT ||
     idtpvt_z == VENTAS_FIDE) {
     sql_z += " and (b.recemi between :PTVTINI and :PTVTFIN) ";
  }
  if(idtpvt_z == TRAD_FON_Y_FIDE && cmb_contycre->ItemIndex == SOLO_CONTADO) {
     sql_z += " and ( (a.tipo = 'V' and b.folent = :CONTADO ) or a.tipo <> 'V') ";
  }
  if(idtpvt_z == TRAD_FON_Y_FIDE && cmb_contycre->ItemIndex == SOLO_CREDITO) {
     sql_z += " and ( (a.tipo = 'V' and b.folent = :CREDITO ) or a.tipo <> 'V') ";
  }
  if(idtpvt_z == TRAD_FON_Y_FIDE && cmb_contycre->ItemIndex == SOLO_TC) {
     sql_z += " and ( (a.tipo = 'V' and b.folent = :TCRED ) or a.tipo <> 'V') ";
  }
  sql_z += " order by b.folent, b.recemi,a.fecha,linea,codigo,";
  sql_z += " c.descri,c.empaqe, costou,prvta ";

  if(edt_prlin->Tag) {
    TForm *Form_sql = new TForm (this);
    TMemo *mmo_sql = new TMemo (Form_sql);
    mmo_sql->Parent = Form_sql;
    mmo_sql->Lines->Add(sql_z);
    mmo_sql->Align = alClient;
    Form_sql->ShowModal();
    delete Form_sql;
  }

  qry_analisma->Close();
  qry_analisma->SQL->Text = sql_z;
  qry_analisma->ParamByName("idtarea")->AsInteger = idtarea_z;
  qry_analisma->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_analisma->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_analisma->ParamByName("cia")->AsInteger = cia_z;
  qry_analisma->ParamByName("siono1")->AsString = siono1_z;
  qry_analisma->ParamByName("siono2")->AsString = siono2_z;
  qry_analisma->ParamByName("entcan1")->AsString = entcan1_z;
  qry_analisma->ParamByName("entcan2")->AsString = entcan2_z;
  if(idtpvt_z == VENTAS_TRADICIONALES) {
    qry_analisma->ParamByName("credito")->AsInteger = credito_z;
    qry_analisma->ParamByName("contado")->AsInteger = contado_z;
    qry_analisma->ParamByName("TCRED")->AsInteger = tc_z;
  }
  if(idtpvt_z == TRAD_FON_Y_FIDE && cmb_contycre->ItemIndex == SOLO_CONTADO)
    qry_analisma->ParamByName("contado")->AsInteger = contado_z;
  if(idtpvt_z == TRAD_FON_Y_FIDE && cmb_contycre->ItemIndex == SOLO_CREDITO)
    qry_analisma->ParamByName("credito")->AsInteger = credito_z;
  if(idtpvt_z == TRAD_FON_Y_FIDE && cmb_contycre->ItemIndex == SOLO_TC)
    qry_analisma->ParamByName("TCRED")->AsInteger = tc_z;
  if(idtpvt_z == TRAD_FON_Y_FIDE ||
     idtpvt_z == VENTAS_TRADICIONALES ||
     idtpvt_z == VENTAS_FONACOT ||
     idtpvt_z == VENTAS_FIDE) {
     qry_analisma->ParamByName("PTVTINI")->AsString = ptvtini_z;
     qry_analisma->ParamByName("PTVTFIN")->AsString = ptvtfin_z;
  }

  qry_analisma->ParamByName("prlin")->AsString = prlin_z;
  qry_analisma->ParamByName("ullin")->AsString = ullin_z;
  qry_analisma->Open();
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Text = "delete from inv_tpvtatmp where IDTAREA = :IDTAREA";
  dm->qry_maxidvnd->ExecSQL();

}
//---------------------------------------------------------------------------

void __fastcall TForm_analivtacyc::agrega_tipovta(
  int id_z, int idtarea_z, int factor_z, String tipoent_z)
{
      dm->qry_maxidvnd->ParamByName("IDTPVTATMP")->AsInteger = id_z;
      dm->qry_maxidvnd->ParamByName("IDTAREA")->AsInteger = idtarea_z;
      dm->qry_maxidvnd->ParamByName("IDTIPOVTA")->AsInteger = 0;
      dm->qry_maxidvnd->ParamByName("FACTOR")->AsInteger = 1;
      dm->qry_maxidvnd->ParamByName("TIPOSAL")->AsString = tipoent_z;
      dm->qry_maxidvnd->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TForm_analivtacyc::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------
void __fastcall TForm_analivtacyc::Exportara1Click(TObject *Sender)
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

void __fastcall TForm_analivtacyc::exporta_dbgrdExecute(TObject *Sender)
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

void __fastcall TForm_analivtacyc::cmb_tiporepChange(TObject *Sender)
{
  int sel_z=0;
  const int VENTAS_TRADICIONALES = 0;
  const int VENTAS_FIDE = 1;
  const int VENTAS_FONACOT = 2;
  const int TRAD_FON_Y_FIDE= 3;
  sel_z = cmb_tiporep->ItemIndex;
  if(sel_z == VENTAS_TRADICIONALES || sel_z == TRAD_FON_Y_FIDE) {
    cmb_contycre->Visible = true;
  } else {
    cmb_contycre->Visible = false;
    cmb_contycre->ItemIndex = 0;
  }
  if(sel_z == TRAD_FON_Y_FIDE ||
     sel_z == VENTAS_TRADICIONALES ||
     sel_z == VENTAS_FONACOT ||
     sel_z == VENTAS_FIDE) {
    edt_ptvtfin->Visible = true;
  } else {
    edt_ptvtfin->Visible = false;
  }
  lbl_contycred->Visible = cmb_contycre->Visible;
  edt_ptvtini->Visible = edt_ptvtfin->Visible;
  lbl_ptvtini->Visible = edt_ptvtfin->Visible;
  lbl_ptvtfin->Visible = edt_ptvtfin->Visible;

}
//---------------------------------------------------------------------------

void __fastcall TForm_analivtacyc::edt_prlinDblClick(TObject *Sender)
{
  if(edt_prlin->Tag) {
    edt_prlin->Tag = 1;
  } else {
    edt_prlin->Tag = 0;
  }
}
//---------------------------------------------------------------------------

