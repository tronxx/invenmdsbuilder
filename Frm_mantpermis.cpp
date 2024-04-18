//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "dmod.h"
#include "Frm_mantpermis.h"
#include "situaciones.h"
#include "dialg_okcancel.h"
#include "Frme_datosmarca.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TForm_mantpermis *Form_mantpermis;
//---------------------------------------------------------------------------
__fastcall TForm_mantpermis::TForm_mantpermis(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantpermis::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTPERMIS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  botones_onoff(VISIBLES);

  //////////////////////////

  String linea_z;
  int idproyec_z=0;
  linea_z = "CEL";
  qry_proyectos->Close();
  qry_proyectos->Open();
  if(!qry_proyectos->IsEmpty()) {
    idproyec_z = qry_proyectos->FieldByName("idproyecto")->AsInteger;
    lkcmb_codigo->KeyValue = idproyec_z;
    qry_facpermiproyectos->Close();
    qry_facpermiproyectos->ParamByName("idproyecto")->AsInteger = idproyec_z;
    qry_facpermiproyectos->Open();
    qry_permisiones->Close();
    qry_permisiones->Open();
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantpermis::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::botones_onoff(int modo_z)
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

void __fastcall TForm_mantpermis::nuevoExecute(TObject *Sender)
{
  if(qry_proyectos->IsEmpty()) {
     Application->MessageBox("No Tengo Articulo para Agregarle la Cuota", "ERROR", MB_ICONEXCLAMATION);
  }
  int idpermis_z= 0, idproyec_z=0, siagrega_z=0,
    idpermiproyec_z=1, mitop_z = 0, mileft_z = 0;
  String descri_z, clavepermis_z = "";
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_datosmarca *dlg_datosproyec = new TFrame_datosmarca (Dlg_datos);
  TLabel *lbl_clave = new TLabel (dlg_datosproyec);
  mitop_z = dlg_datosproyec->lbl_nombre->Top;
  mileft_z = dlg_datosproyec->lbl_nombre->Left;
  lbl_clave->Caption = "Clave";
  lbl_clave->Parent = dlg_datosproyec->Panel1;
  lbl_clave->Top = mitop_z + 20;
  lbl_clave->Left = mileft_z;
  TEdit *edt_clave =  new TEdit (dlg_datosproyec);
  Dlg_datos->Caption = "Datos de la Permision";
  edt_clave->Parent = dlg_datosproyec->Panel1;
  edt_clave->Top = mitop_z + 20;
  edt_clave->Left = dlg_datosproyec->edt_nombre->Left;
  edt_clave->CharCase = ecUpperCase;
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = dlg_datosproyec->Width + 20;
  Dlg_datos->Height = dlg_datosproyec->Height + 80;
  dlg_datosproyec->Parent = Dlg_datos->Panel1;
  if(Dlg_datos->ShowModal() == mrOk) {
    idpermis_z = dlg_datosproyec->edt_codigo->Text.ToIntDef(0);
    descri_z  = dlg_datosproyec->edt_nombre->Text.Trim();
    clavepermis_z  = edt_clave->Text.Trim();
    idproyec_z = qry_proyectos->FieldByName("idproyecto")->AsInteger;
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Clear();
    dm->qry_maxidvnd->SQL->Add("select idpermis from car_permisiones where idpermis = :IDPERMIS");
    dm->qry_maxidvnd->ParamByName("idpermis")->AsInteger = idpermis_z;
    dm->qry_maxidvnd->Open();
    if(dm->qry_maxidvnd->IsEmpty()) siagrega_z = 1;
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Clear();
    dm->qry_maxidvnd->SQL->Add("select max (idpermiproyecto) as iddato from fac_permiproyectos where idpermiproyecto > 0");
    dm->qry_maxidvnd->Open();
    if(!dm->qry_maxidvnd->IsEmpty())
      idpermiproyec_z = dm->qry_maxidvnd->FieldByName("iddato")->AsInteger + 1;
    qry_permisiones->Append();
    qry_permisiones->FieldByName("idpermis")->AsInteger = idpermis_z;
    qry_permisiones->FieldByName("descripcion")->AsString = descri_z;
    qry_permisiones->FieldByName("clave")->AsString = clavepermis_z;
    qry_permisiones->Post();
    qry_facpermiproyectos->Append();
    qry_facpermiproyectos->FieldByName("idpermiproyecto")->AsInteger = idpermiproyec_z;
    qry_facpermiproyectos->FieldByName("idproyecto")->AsInteger = idproyec_z;
    qry_facpermiproyectos->FieldByName("idpermis")->AsInteger = idpermis_z;
    qry_facpermiproyectos->FieldByName("descripcion")->AsString = descri_z;
    qry_facpermiproyectos->Post();
    try {
       dm->manvehi->StartTransaction();
       if(siagrega_z) qry_permisiones->ApplyUpdates();
       qry_facpermiproyectos->ApplyUpdates();
       dm->manvehi->Commit();
    } catch (Exception &E)
    {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
  delete dlg_datosproyec;
  delete Dlg_datos;
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantpermis::cancelarExecute(TObject *Sender)
{
  grabar->Tag = EN_ESPERA;
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantpermis::borraExecute(TObject *Sender)
{
  int ii_z = Application->MessageBox("Esta Seguro de Eliminar esta Permisión ?", "Eliminar Permisión", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
  if (ii_z != IDOK ) return;
  //qry_cuotacel->Delete();
  try {
    dm->manvehi->StartTransaction();
    qry_facpermiproyectos->Delete();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::dbgrd_cuotacelCustomDrawCell(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxTreeListColumn *AColumn, bool ASelected,
      bool AFocused, bool ANewItemRow, AnsiString &AText, TColor &AColor,
      TFont *AFont, TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------



void __fastcall TForm_mantpermis::lkcmb_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevo_proyec();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::nuevo_proyec()
{
  int idproyec_z = 0;
  String descri_z;
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_datosmarca *dlg_datosproyec = new TFrame_datosmarca (Dlg_datos);
  Dlg_datos->Caption = "Datos del Proyecto";
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = dlg_datosproyec->Width + 20;
  Dlg_datos->Height = dlg_datosproyec->Height + 80;
  dlg_datosproyec->Parent = Dlg_datos->Panel1;
  if(Dlg_datos->ShowModal() == mrOk) {
    idproyec_z = dlg_datosproyec->edt_codigo->Text.ToIntDef(0);
    descri_z = dlg_datosproyec->edt_nombre->Text.Trim();
    qry_proyectos->Tag = NO_REFRESH;
    qry_proyectos->DisableControls();
    qry_proyectos->Append();
    qry_proyectos->FieldByName("idproyecto")->AsInteger = idproyec_z;
    qry_proyectos->FieldByName("descri")->AsString = descri_z;
    qry_proyectos->Post();
    try {
       dm->manvehi->StartTransaction();
       qry_proyectos->ApplyUpdates();
       dm->manvehi->Commit();
    } catch (Exception &E)
    {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    qry_proyectos->EnableControls();
    qry_proyectos->Tag = SI_REFRESH;
  }
  delete Dlg_datos;
  delete dlg_datosproyec;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::qry_proyectosAfterScroll(
      TDataSet *DataSet)
{
  qry_facpermiproyectos->Close();
  qry_facpermiproyectos->ParamByName("idproyecto")->AsInteger = idproyecto_z;
  qry_facpermiproyectos->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::dbgrd_cuotacelKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT)  nuevoExecute(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantpermis::modificaExecute(TObject *Sender)
{
  if(qry_proyectos->IsEmpty()) {
     Application->MessageBox("No Tengo ningún Proyecto Seleccionado", "ERROR", MB_ICONEXCLAMATION);
  }
  int idpermis_z= 0, idproyec_z=0, siagrega_z=0, idpermiproyec_z=1;
  String descri_z;
  TLocateOptions Opts;
  Opts.Clear();
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_datosmarca *dlg_datosproyec = new TFrame_datosmarca (Dlg_datos);
  Dlg_datos->Caption = "Datos de la Permision";
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = dlg_datosproyec->Width + 20;
  Dlg_datos->Height = dlg_datosproyec->Height + 80;
  dlg_datosproyec->Parent = Dlg_datos->Panel1;
  dlg_datosproyec->edt_nombre->Text = qry_facpermiproyectos->FieldByName("descripcion")->AsString;
  dlg_datosproyec->edt_codigo->Text = qry_facpermiproyectos->FieldByName("idpermis")->AsString;
  dlg_datosproyec->edt_codigo->Enabled = false;

  if(Dlg_datos->ShowModal() == mrOk) {
    idpermis_z = dlg_datosproyec->edt_codigo->Text.ToIntDef(0);
    descri_z  = dlg_datosproyec->edt_nombre->Text.Trim();
    idproyec_z = qry_proyectos->FieldByName("idproyecto")->AsInteger;
    qry_permisiones->First();
    if(qry_permisiones->Locate("idpermis", idpermis_z, Opts)) {
      qry_permisiones->Edit();
      qry_permisiones->FieldByName("descripcion")->AsString = descri_z;
      qry_permisiones->Post();
    }
    qry_facpermiproyectos->Edit();
    qry_facpermiproyectos->FieldByName("descripcion")->AsString = descri_z;
    qry_facpermiproyectos->Post();
    try {
       dm->manvehi->StartTransaction();
       if(qry_permisiones->UpdatesPending) qry_permisiones->ApplyUpdates();
       dm->manvehi->Commit();
    } catch (Exception &E)
    {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
  delete dlg_datosproyec;
  delete Dlg_datos;

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantpermis::primeroExecute(TObject *Sender)
{
  qry_facpermiproyectos->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::anteriorExecute(TObject *Sender)
{
  qry_facpermiproyectos->Prior();        
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::siguienteExecute(TObject *Sender)
{
  qry_facpermiproyectos->Next();        
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::ultimoExecute(TObject *Sender)
{
 qry_facpermiproyectos->Last();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpermis::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_cuotacel;
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

