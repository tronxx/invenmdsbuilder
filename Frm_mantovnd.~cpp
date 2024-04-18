//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantovnd.h"
#include "dmod.h"
#include "dialg_okcancel.h"
#include "Frme_datosmantovnd.h"
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
TForm_mantovnd *Form_mantovnd;
//---------------------------------------------------------------------------
__fastcall TForm_mantovnd::TForm_mantovnd(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::borraExecute(TObject *Sender)
{
  String vnd_z;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_cajeras->IsEmpty()) return;
  vnd_z = qry_cajeras->FieldByName("codigo")->AsString;
  if(Application->MessageBox("Está Seguro de Eliminar este Vendedor?", "Eliminar Vendedor", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_cajeras->Delete();
      qry_vndptovta->Close();
      qry_vndptovta->ParamByName("codigo")->AsString = vnd_z;
      qry_vndptovta->ParamByName("tipo")->AsInteger = TIPO_REL_VND_ZONA;
      qry_vndptovta->Open();
      for( ; !qry_vndptovta->IsEmpty(); qry_vndptovta->First()) {
        qry_vndptovta->Delete();
      }
      qry_cajeras->ApplyUpdates();
      if (qry_vndptovta->UpdatesPending) qry_vndptovta->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantovnd::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantovnd::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantovnd::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_cajeras->IsEmpty()) {
    Application->MessageBox("No existe el Vendedor que desea modificar", "vendedor Inexistente", MB_ICONEXCLAMATION);
    return;
  }
  alta_vnd(MODIF);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::desp_ptvt()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantovnd::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_vnd(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::alta_vnd(int modo_z)
{
   Tdlg_okcancel *Dlg_mantgpoinv;
   String status_z = "A", vnd_z, nombre_z, zona_z;
   TDateTime fecbaj_z;
   int ancho_z, alto_z, numero_z=0;
   fecbaj_z = dm->ahora();
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantovnd *Frame_datosmantovnd;
   Frame_datosmantovnd = new TFrame_datosmantovnd (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantovnd->Width + 20;
   alto_z = Frame_datosmantovnd->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantovnd->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z ;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Vendedor";
   Dlg_mantgpoinv->Position = poScreenCenter;
   if(modo_z == EN_ESPERA) {
     Dlg_mantgpoinv->btn_cancel->Visible = false;
   }

   if(modo_z == NUEVO) {
     Frame_datosmantovnd->lbs_status->Visible = false;
     Frame_datosmantovnd->cmb_status->Visible = false;
     Frame_datosmantovnd->lbl_fecbaj->Visible = false;
     Frame_datosmantovnd->date_fecbaj->Visible = false;
   } else {
     Frame_datosmantovnd->edt_cajera->Text = qry_cajeras->FieldByName("codigo")->AsString;
     Frame_datosmantovnd->edt_cajera->Enabled = false;
     Frame_datosmantovnd->edt_nombre->Text = qry_cajeras->FieldByName("nombre")->AsString;
     Frame_datosmantovnd->lkcmb_ptovta->KeyValue = qry_cajeras->FieldByName("zona")->AsString;
     status_z = qry_cajeras->FieldByName("status")->AsString;
     if(status_z == "A") {
       Frame_datosmantovnd->cmb_status->ItemIndex = 0;
     } else {
       Frame_datosmantovnd->cmb_status->ItemIndex = 1;
       fecbaj_z = qry_cajeras->FieldByName("fecbaj")->AsDateTime;
     }
   }
   Frame_datosmantovnd->date_fecbaj->Date= fecbaj_z;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      vnd_z = Frame_datosmantovnd->edt_cajera->Text.Trim();
      nombre_z = Frame_datosmantovnd->edt_nombre->Text.Trim();
      zona_z = Frame_datosmantovnd->qry_ptovta->FieldByName("zona")->AsString;
      if (Frame_datosmantovnd->cmb_status->ItemIndex == 0) {
        status_z = "A";
      } else {
        status_z = "B"; fecbaj_z = Frame_datosmantovnd->date_fecbaj->Date;
      }
      if( modo_z == NUEVO) {
        alta_ptvt(vnd_z, nombre_z, zona_z, "A", fecbaj_z, NUEVO);
      }
      if(modo_z == MODIF) {
        alta_ptvt(vnd_z, nombre_z, zona_z, status_z, fecbaj_z, MODIF);
      }
   }
   delete Frame_datosmantovnd;
   delete Dlg_mantgpoinv;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::primeroExecute(TObject *Sender)
{
   qry_cajeras->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::anteriorExecute(TObject *Sender)
{
   qry_cajeras->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::siguienteExecute(TObject *Sender)
{
   qry_cajeras->Next();
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantovnd::ultimoExecute(TObject *Sender)
{
   qry_cajeras->Last();
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantovnd::alta_ptvt(String vnd_z, String nombre_z, String zona_z,
  String status_z, double fecbaj_z, int modo_z)
{
  //String vnd_z, nombre_z, zona_z;
  int idvndptovt_z=0;
  //vnd_z = edt_cajera->Text.Trim();
  //nombre_z = edt_nombre->Text.Trim();
  //zona_z = qry_ptovta->FieldByName("zona")->AsString;
  if(modo_z == NUEVO) {
    qry_cajeras->Append();
    qry_cajeras->FieldByName("codigo")->AsString = vnd_z;
  } else {
    qry_cajeras->Edit();
  }
//  qry_cajeras->FieldByName("clave")->AsString = edt_clave->Text.Trim();
  qry_cajeras->FieldByName("nombre")->AsString = nombre_z;
  qry_cajeras->FieldByName("zona")->AsString = zona_z;
  qry_cajeras->FieldByName("status")->AsString = status_z;
  qry_cajeras->FieldByName("fecbaj")->AsDateTime = fecbaj_z;
  qry_cajeras->Post();
//  qry_cajeras->FieldByName("direc")->AsString = edt_direc->Text.Trim();
//  qry_cajeras->FieldByName("cia")->AsInteger = cia_z;
  qry_vndptovta->Close();
  qry_vndptovta->ParamByName("codigo")->AsString = vnd_z;
  qry_vndptovta->ParamByName("tipo")->AsInteger = TIPO_REL_VND_ZONA;
  qry_vndptovta->Open();
  if(qry_vndptovta->IsEmpty() ) {
    idvndptovt_z = dm->busca_sigid(IDVNDPTOVT);
    qry_vndptovta->Append();
    qry_vndptovta->FieldByName("idvndptovt")->AsInteger = idvndptovt_z;
    qry_vndptovta->FieldByName("cia")->AsInteger = cia_z;
  } else {
    qry_vndptovta->Edit();
  }
  qry_vndptovta->FieldByName("idvendedor")->AsInteger = 0;
  qry_vndptovta->FieldByName("tipo")->AsInteger = TIPO_REL_VND_ZONA;
  qry_vndptovta->FieldByName("codigo")->AsString = vnd_z;
  qry_vndptovta->FieldByName("idptovta")->AsInteger = 0;
  qry_vndptovta->FieldByName("ptovta")->AsString = "";
  qry_vndptovta->FieldByName("zona")->AsString = zona_z;
  qry_vndptovta->Post();
  try {
    dm->manvehi->StartTransaction();
    qry_cajeras->ApplyUpdates();
    if (qry_vndptovta->UpdatesPending) qry_vndptovta->ApplyUpdates();
    dm->manvehi->Commit();
  }catch
   (Exception &E)
  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  grabar->Tag = 0;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantovnd::botones_onoff(int modo_z)
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

void __fastcall TForm_mantovnd::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idciudad")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::busca_ptvt(String ptvt_z)
{
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_cajeras->Close();
   qry_cajeras->ParamByName("idciudad")->AsInteger = StrToIntDef(ptvt_z, 0);
   qry_cajeras->Open();
   if(!qry_cajeras->IsEmpty()) {
     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTOVND);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  qry_cajeras->Close();
//  qry_cajeras->ParamByName("cia")->AsInteger = cia_z;
  qry_cajeras->Open();
  qry_ptovta->Close();
  qry_ptovta->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantovnd::dbgrd_vendedoresCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantovnd::dbgrd_vendedoresKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_F2)     modificaExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantovnd::expotarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_vendedores;
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


void __fastcall TForm_mantovnd::dbgrd_vendedoresDblClick(TObject *Sender)
{
  alta_vnd(EN_ESPERA);

}
//---------------------------------------------------------------------------

