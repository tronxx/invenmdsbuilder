//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_relfacmay.h"
#include "dmod.h"
#include "numapal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_relfacmay *Form_relfacmay;
//---------------------------------------------------------------------------
__fastcall TForm_relfacmay::TForm_relfacmay(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_relfacmay::desp_ptvt()
{

}
//---------------------------------------------------------------------------






void __fastcall TForm_relfacmay::alta_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::mueve_hacia(String sql_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::busca_ptvt(String ptvt_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::FormCreate(TObject *Sender)
{
  permis_z="N";
  cia_z = dm->cia_z;
  date_fecini->Date = PrimerDiaMes(IncMonth(dm->ahora(), -1));
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
  qry_marcas->Close();
  qry_marcas->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_marcas->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_marcas->ParamByName("prmay")->AsString = edt_prmay->Text;
  qry_marcas->ParamByName("ulmay")->AsString = edt_ulmay->Text;
  qry_marcas->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::qry_marcasAfterScroll(TDataSet *DataSet)
{
  if(qry_marcas->Tag == EN_ESPERA) desp_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::dbgrd_doctosCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------


void __fastcall TForm_relfacmay::BitBtn1Click(TObject *Sender)
{
  TDateTime anuini_z, anufin_z, estemes_z;
  TLocateOptions Opts;
  int anu_z, mes_z=1, dia_z=1, pagina_z=1;
  const int TBS_MENSUAL=0;
  const int TBS_ANUAL=1;
  anu_z = FormatDateTime("yyyy", date_fecini->Date).ToInt();
  anuini_z = EncodeDate(anu_z, mes_z, dia_z);
  anu_z = FormatDateTime("yyyy", date_fecfin->Date).ToInt();
  mes_z = FormatDateTime("mm", date_fecfin->Date).ToInt();
  anufin_z = EncodeDate(anu_z, mes_z, dia_z);
  anufin_z = UltimoDiaMes(anufin_z);
  String mayoris_z, strmes_z, sql_z, stranuini_z, stranufin_z, strestemes_z;
  double total_z, impmes_z;
  Opts.Clear();
  switch (page_acum->ActivePageIndex) {
    case TBS_MENSUAL:
      qry_marcas->Close();
      qry_marcas->ParamByName("fecini")->AsDateTime = date_fecini->Date;
      qry_marcas->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
      qry_marcas->ParamByName("prmay")->AsString = edt_prmay->Text;
      qry_marcas->ParamByName("ulmay")->AsString = edt_ulmay->Text;
      qry_marcas->Open();
      break;
    case TBS_ANUAL:
      estemes_z = anuini_z;
      strestemes_z   = FormatDateTime("yyyymm", anuini_z);
      stranufin_z    = FormatDateTime("yyyymm", anufin_z);
      qry_mayoris->Close();
      qry_mayoris->Open();
      qry_meses->Close();
      qry_meses->ParamByName("fecini")->AsDateTime = anuini_z;
      qry_meses->ParamByName("fecfin")->AsDateTime = anufin_z;
      qry_meses->ParamByName("prmay")->AsString = edt_prmay->Text;
      qry_meses->ParamByName("ulmay")->AsString = edt_ulmay->Text;
      qry_meses->Open();
      mayoris_z = "-1"; total_z = 0;
      for(qry_meses->First(); !qry_meses->Eof; qry_meses->Next()) {
          if(mayoris_z != qry_meses->FieldByName("Mayoris")->AsString) {
             if(mayoris_z != "-1") {
               qry_mayoris->FieldByName("tot")->AsFloat = total_z;
               qry_mayoris->Post();
               total_z = 0;
             }
             mayoris_z = qry_meses->FieldByName("mayoris")->AsString;
             qry_mayoris->Append();
             qry_mayoris->FieldByName("mayoris")->AsString = mayoris_z;
          }
          strmes_z = nommes(qry_meses->FieldByName("mesvence")->AsInteger);
          strmes_z = strmes_z.SubString(1,3);
          impmes_z = qry_meses->FieldByName("importe")->AsFloat;
          qry_mayoris->FieldByName(strmes_z)->AsFloat =impmes_z;
          total_z += impmes_z;
      }
      qry_mayoris->FieldByName("tot")->AsFloat = total_z;
      qry_mayoris->Post();
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_relfacmay::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  String tipogrd_z, nombre_z;
  const int TBS_MENSUAL=0;
  const int TBS_ANUAL=1;
  switch (page_acum->ActivePageIndex) {
    case TBS_MENSUAL: midbgrd_z = dbgrd_doctos; break;
    case TBS_ANUAL  : midbgrd_z = dbgrd_anual;  break;
  }
  tipogrd_z="DBG";
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
  }
  delete SaveDialog;

}
//---------------------------------------------------------------------------


