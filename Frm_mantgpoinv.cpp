//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantgpoinv.h"
#include "Frme_datosmantgpoinv.h"
#include "dmod.h"
#include "dialg_okcancel.h"
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
TForm_mantgpoinv *Form_mantgpoinv;
//---------------------------------------------------------------------------
__fastcall TForm_mantgpoinv::TForm_mantgpoinv(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::borraExecute(TObject *Sender)
{
  String tabsel_z;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  TQuery *qry_modif;
  tabsel_z = pge_grupos->ActivePage->Name;
  if (tabsel_z == "tbs_grupoartdesp") {
     qry_modif = qry_gpoinv;
  }
  if (tabsel_z == "tbs_grupointernet") {
     qry_modif = qry_gruposinternet;
  }
  if(qry_gpoinv->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Grupo ?", "Eliminar Grupo", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_modif->Delete();
      qry_modif->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  qry_gpoinv->Tag = EN_ESPERA;

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpoinv::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpoinv::modificaExecute(TObject *Sender)
{
  TQuery *qry_modif;
  String tabsel_z;
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }

  tabsel_z = pge_grupos->ActivePage->Name;
  if (tabsel_z == "tbs_grupoartdesp") {
     qry_modif = qry_gpoinv;
  }
  if (tabsel_z == "tbs_grupointernet") {
     qry_modif = qry_gruposinternet;
  }

  if(qry_modif->IsEmpty()) {
    Application->MessageBox("No existe el Grupo que desea modificar", "Grupo Inexistente", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt(MODIF);
  //desp_ptvt();
  //grabar->Tag = MODIF;
  //qry_gpoinv->Tag = MODIF;
  //botones_onoff(INVISIBLES);
  //edt_nombre->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::desp_ptvt()
{
   //edt_nombre->Text=qry_gpoinv->FieldByName("descri")->AsString;
   //edt_ptovta->Text=qry_gpoinv->FieldByName("codigo")->AsString;
   //chk_imprime->Checked = (qry_gpoinv->FieldByName("impri")->AsString == "S");
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantgpoinv::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::primeroExecute(TObject *Sender)
{
  qry_gpoinv->First();
//   mueve_hacia("select min (grupo) as grupo from grupoinv where cia = " + IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::anteriorExecute(TObject *Sender)
{
  qry_gpoinv->Prior();
//   mueve_hacia("select max (grupo) as grupo from grupoinv where grupo < '"+edt_ptovta->Text + "' and cia = " + IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::siguienteExecute(TObject *Sender)
{
  qry_gpoinv->Next();
//   mueve_hacia("select min (grupo) as grupo from grupoinv where grupo > '"+edt_ptovta->Text + "' and cia = " + IntToStr(cia_z));
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpoinv::ultimoExecute(TObject *Sender)
{
  qry_gpoinv->Last();
//   mueve_hacia("select max (grupo) as grupo from grupoinv where cia = " + IntToStr(cia_z));
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::alta_ptvt(int modo_z)
{

   int idgpoinv_z=0, ancho_z, alto_z, numero_z=0, idcodsat_z;
   String descri_z, codigo_z, codsat_z, descrisat_z, tabsel_z, titulo_z;
   bool select_z;
   Tdlg_okcancel *Dlg_mantgpoinv;
   TQuery *qry_modif;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   tabsel_z = pge_grupos->ActivePage->Name;
   TFrame_datosmantgpoinv *Frame_datosmantgpoinv;
   Frame_datosmantgpoinv = new TFrame_datosmantgpoinv (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantgpoinv->Width + 20;
   alto_z = Frame_datosmantgpoinv->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantgpoinv->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z - 50;
   tabsel_z = pge_grupos->ActivePage->Name;
   if (tabsel_z == "tbs_grupoartdesp") {
     Frame_datosmantgpoinv->inicializa("GRUPOINVEN");
     titulo_z = "Grupo Art. Desplazados";
     qry_modif = qry_gpoinv;
   }
   if (tabsel_z == "tbs_grupointernet") {
     Frame_datosmantgpoinv->inicializa("GRUPOSINTERNET");
     titulo_z = "Grupo Internet";
     qry_modif = qry_gruposinternet;
   }
   if ( modo_z == MODIF) {
     Dlg_mantgpoinv->Caption = "Modifica " + titulo_z;

     Frame_datosmantgpoinv->edt_ptovta->Enabled= false;
     Frame_datosmantgpoinv->edt_nombre->Text= qry_modif->FieldByName("descri")->AsString;
     Frame_datosmantgpoinv->edt_ptovta->Text= qry_modif->FieldByName("codigo")->AsString;
     Frame_datosmantgpoinv->chk_imprime->Checked = ( qry_modif->FieldByName("impri")->AsString == "S");
     Frame_datosmantgpoinv->lkcmb_codsat->KeyValue = qry_modif->FieldByName("codsat")->AsString;
   }
   if ( modo_z == NUEVO ) {
     Dlg_mantgpoinv->Caption = "Nuevo " + titulo_z;
   }
   Dlg_mantgpoinv->Position = poScreenCenter;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
     codigo_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
     descri_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();
     select_z = Frame_datosmantgpoinv->chk_imprime->Checked;
     idcodsat_z = Frame_datosmantgpoinv->qry_catprodsat->FieldByName("idprod")->AsInteger;
     codsat_z = Frame_datosmantgpoinv->qry_catprodsat->FieldByName("codigo")->AsString;
     descrisat_z = Frame_datosmantgpoinv->qry_catprodsat->FieldByName("descri")->AsString;
     try {
       dm->manvehi->StartTransaction();
       if(modo_z == NUEVO) {
         if (tabsel_z == "tbs_grupoartdesp") {
           idgpoinv_z=dm->busca_sigid(IDGPOINV);
         }
         if (tabsel_z == "tbs_grupointernet") {
           idgpoinv_z=dm->busca_sigid(IDGPOINTERNET);
         }
         qry_modif->Append();
         qry_modif->FieldByName("idgrupo")->AsInteger = idgpoinv_z;
         qry_modif->FieldByName("codigo")->AsString = codigo_z;
         qry_modif->FieldByName("cia")->AsInteger = cia_z;
       } else {
         qry_modif->Edit();
       }
       qry_modif->FieldByName("descri")->AsString = descri_z;
       qry_modif->FieldByName("idcatprodsat")->AsInteger = idcodsat_z;
       if(select_z) {
         qry_modif->FieldByName("impri")->AsString = "S";
       } else {
         qry_modif->FieldByName("impri")->AsString = "N";
       }
       qry_modif->FieldByName("codsat")->AsString = codsat_z;
       qry_modif->FieldByName("descrisat")->AsString = descrisat_z;
       qry_modif->Post();
       qry_modif->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }

   delete Frame_datosmantgpoinv;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::modif_ptvt(String descri_z, bool select_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(dm->qry_maxidvnd->FieldByName("grupo")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::busca_ptvt(String ptvt_z)
{
//   if(ptvt_z.Trim().IsEmpty()) return;
//   qry_gpoinv->Close();
//   qry_gpoinv->ParamByName("grupo")->AsString = ptvt_z;
//   qry_gpoinv->ParamByName("cia")->AsInteger = cia_z;
//   qry_gpoinv->Open();
//   if(!qry_gpoinv->IsEmpty()) {
//     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
//   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::FormCreate(TObject *Sender)
{
  permis_z=dm->busca_permision(MANTGPOINV);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  
  qry_gpoinv->Tag = EN_ESPERA;
  qry_gpoinv->Close();
//  qry_gpoinv->ParamByName("grupo")->AsString=edt_ptovta->Text;
  qry_gpoinv->ParamByName("cia")->AsInteger = cia_z;
  qry_gpoinv->Open();
  qry_gruposinternet->Close();
//  qry_gpoinv->ParamByName("grupo")->AsString=edt_ptovta->Text;
  qry_gruposinternet->ParamByName("cia")->AsInteger = cia_z;
  qry_gruposinternet->Open();

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantgpoinv::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::qry_gpoinvAfterScroll(TDataSet *DataSet)
{
  if(qry_gpoinv->Tag == EN_ESPERA) desp_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::dbgrd_gruposCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantgpoinv::exportarExecute(TObject *Sender)
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

void __fastcall TForm_mantgpoinv::dbgrd_gruposKeyPress(TObject *Sender,
      char &Key)
{
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_INSERT) nuevoExecute(Sender);
}
//---------------------------------------------------------------------------

