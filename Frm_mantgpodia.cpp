//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantgpodia.h"
#include "dmod.h"
#include "dialg_okcancel.h"
#include "Frme_datosmantgpoinv.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_mantgpodia *Form_mantgpodia;
//---------------------------------------------------------------------------
__fastcall TForm_mantgpodia::TForm_mantgpodia(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_gpodiary->Close();
//  qry_gpodiary->ParamByName("grupo")->AsString=edt_ptovta->Text;
//  qry_gpodiary->ParamByName("cia")->AsInteger = cia_z;
//  qry_gpodiary->Open();
  if(qry_gpodiary->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Grupo de Diary ?", "Eliminar Grupo Diary", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_gpodiary->Delete();
      qry_gpodiary->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpodia::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  qry_gpodiary->Tag = EN_ESPERA;

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpodia::edt_ptovtaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  //if(Key == VK_RETURN) busca_ptvt(edt_ptovta->Text);
}
//-------------------------------------------------------------------------
void __fastcall TForm_mantgpodia::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpodia::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_gpodiary->IsEmpty()) {
    Application->MessageBox("No existe el Grupo de Diary que desea modificar", "Grupo Inexistente", MB_ICONEXCLAMATION);
    return;
  }

   int ancho_z, alto_z, numero_z=0;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantgpoinv *Frame_datosmantgpoinv;
   Frame_datosmantgpoinv = new TFrame_datosmantgpoinv (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantgpoinv->Width + 20;
   alto_z = Frame_datosmantgpoinv->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantgpoinv->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Modifica Grupos Diarys";
   Frame_datosmantgpoinv->Label1->Caption = "Grupo Diary";
   Frame_datosmantgpoinv->edt_ptovta->Width = 95;
   Frame_datosmantgpoinv->edt_ptovta->Left = 70;
   Dlg_mantgpoinv->Position = poScreenCenter;
   Frame_datosmantgpoinv->edt_ptovta->Enabled= false;
   Frame_datosmantgpoinv->edt_nombre->Text=qry_gpodiary->FieldByName("descri")->AsString;
   Frame_datosmantgpoinv->edt_ptovta->Text=qry_gpodiary->FieldByName("grupo")->AsString;
   Frame_datosmantgpoinv->chk_imprime->Checked = (qry_gpodiary->FieldByName("imprime")->AsString == "S");

   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String descri_z;
      bool select_z;
      descri_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();
      select_z = Frame_datosmantgpoinv->chk_imprime->Checked;

      modif_ptvt(descri_z,select_z);

   }
     delete Frame_datosmantgpoinv;
     delete Dlg_mantgpoinv;

  //desp_ptvt();
  //grabar->Tag = MODIF;
  //qry_gpodiary->Tag = MODIF;
  //botones_onoff(INVISIBLES);
  //edt_nombre->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::desp_ptvt()
{

   //edt_nombre->Text=qry_gpodiary->FieldByName("descri")->AsString;
   //edt_ptovta->Text=qry_gpodiary->FieldByName("grupo")->AsString;
   //chk_imprime->Checked = (qry_gpodiary->FieldByName("imprime")->AsString == "S");
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantgpodia::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }

  int ancho_z, alto_z, numero_z=0;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantgpoinv *Frame_datosmantgpoinv;
   Frame_datosmantgpoinv = new TFrame_datosmantgpoinv (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantgpoinv->Width + 20;
   alto_z = Frame_datosmantgpoinv->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantgpoinv->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z ;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Grupo Diarys";
   Frame_datosmantgpoinv->Label1->Caption = "Grupo Diary";
   Frame_datosmantgpoinv->edt_ptovta->Width = 95;
   Frame_datosmantgpoinv->edt_ptovta->Left = 70;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String codigo_z, descri_z;
      bool select_z;
      codigo_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
      descri_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();
      select_z = Frame_datosmantgpoinv->chk_imprime->Checked;

      alta_ptvt(codigo_z,descri_z,select_z);

   }
     delete Frame_datosmantgpoinv;
     delete Dlg_mantgpoinv;


  //grabar->Tag = NUEVO;
  //botones_onoff(INVISIBLES);
  //qry_gpodiary->Tag = NUEVO;
  //edt_ptovta->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::primeroExecute(TObject *Sender)
{
   qry_gpodiary->First();
//   mueve_hacia("select min (grupo) as grupo from gpodiary where cia = " + IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::anteriorExecute(TObject *Sender)
{
   qry_gpodiary->Prior();
//   mueve_hacia("select max (grupo) as grupo from gpodiary where grupo < '"+edt_ptovta->Text + "' and cia = " + IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::siguienteExecute(TObject *Sender)
{
   qry_gpodiary->Next();
//   mueve_hacia("select min (grupo) as grupo from gpodiary where grupo > '"+edt_ptovta->Text + "' and cia = " + IntToStr(cia_z));
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpodia::ultimoExecute(TObject *Sender)
{
   qry_gpodiary->Last();
//   mueve_hacia("select max (grupo) as grupo from gpodiary where cia = " + IntToStr(cia_z));
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::alta_ptvt(String codigo_z, String descri_z, bool select_z)
{
   int idgpoinv_z=0;
   TLocateOptions Opts;
   Opts.Clear();
//   qry_gpodiary->Close();
//   qry_gpodiary->ParamByName("grupo")->AsString=edt_ptovta->Text;
//   qry_gpodiary->ParamByName("cia")->AsInteger = cia_z;
//   qry_gpodiary->Open();
   if(qry_gpodiary->Locate("grupo", codigo_z, Opts)) {
     Application->MessageBox("No puede utilizar un c�digo que ya est� en Uso", "C�digo Duplicado", MB_ICONEXCLAMATION);
     return;
   }
   try {
     dm->manvehi->StartTransaction();
     idgpoinv_z=dm->busca_sigid(IDGPODIARY);
     qry_gpodiary->Append();
     qry_gpodiary->FieldByName("idgpodiary")->AsInteger = idgpoinv_z;
     qry_gpodiary->FieldByName("grupo")->AsString = codigo_z;
     qry_gpodiary->FieldByName("descri")->AsString = descri_z;
     if(select_z)
       qry_gpodiary->FieldByName("imprime")->AsString = "S";
     else
       qry_gpodiary->FieldByName("imprime")->AsString = "N";
     qry_gpodiary->FieldByName("cia")->AsInteger = cia_z;
     qry_gpodiary->Post();
     qry_gpodiary->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = EN_ESPERA;
   qry_gpodiary->Tag = EN_ESPERA;
   botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::modif_ptvt(String descri_z, bool select_z)
{
   //String descri_z;
   //descri_z = edt_nombre->Text.Trim();
//   qry_gpodiary->Close();
//   qry_gpodiary->ParamByName("grupo")->AsString = edt_ptovta->Text;
//   qry_gpodiary->ParamByName("cia")->AsInteger = cia_z;
//   qry_gpodiary->Open();
   if(qry_gpodiary->IsEmpty()) return;
   try {
     dm->manvehi->StartTransaction();
     qry_gpodiary->Edit();
     qry_gpodiary->FieldByName("descri")->AsString = descri_z;
     if(select_z)
       qry_gpodiary->FieldByName("imprime")->AsString = "S";
     else
       qry_gpodiary->FieldByName("imprime")->AsString = "N";
     qry_gpodiary->Post();
     qry_gpodiary->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = EN_ESPERA;
   qry_gpodiary->Tag = EN_ESPERA;
   botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::botones_onoff(int modo_z)
{
  switch (modo_z) {
    case INVISIBLES:
      nuevo->Enabled=false;
      modifica->Enabled=false;
      borra->Enabled=false;
      grabar->Enabled=true;
      cancelar->Enabled=true;
//      pnl_btngral->Visible=false;
      break;
    case VISIBLES:
//      pnl_btngral->Visible=true;
      nuevo->Enabled=true;
      modifica->Enabled=true;
      borra->Enabled=true;
      grabar->Enabled=false;
      cancelar->Enabled=false;
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(dm->qry_maxidvnd->FieldByName("grupo")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::busca_ptvt(String ptvt_z)
{
//   if(ptvt_z.Trim().IsEmpty()) return;
//   qry_gpodiary->Close();
//   qry_gpodiary->ParamByName("grupo")->AsString = ptvt_z;
//   qry_gpodiary->ParamByName("cia")->AsInteger = cia_z;
//   qry_gpodiary->Open();
//   if(!qry_gpodiary->IsEmpty()) {
//     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
//   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::FormCreate(TObject *Sender)
{
  permis_z=dm->busca_permision(MANTGPODIARY);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  qry_gpodiary->Tag = EN_ESPERA;
  qry_gpodiary->Close();
  qry_gpodiary->ParamByName("cia")->AsInteger = cia_z;
  qry_gpodiary->Open();

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpodia::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::qry_gpodiaryAfterScroll(
      TDataSet *DataSet)
{
  if(qry_gpodiary->Tag == EN_ESPERA) desp_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::dbgrd_gruposCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
        
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpodia::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  midbgrd_z = dbgrd_grupos;
  SaveDialog->Filter = "Archivos de Texto (*.csv)|*.CSV|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = midbgrd_z->Name + ".xls";
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

void __fastcall TForm_mantgpodia::dbgrd_gruposKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_INSERT) nuevoExecute(Sender);
        
}
//---------------------------------------------------------------------------

