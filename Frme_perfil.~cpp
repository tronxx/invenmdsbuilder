//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_perfil.h"
#include "situaciones.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxTL"
#pragma resource "*.dfm"
TFrame_perfil *Frame_perfil;
//---------------------------------------------------------------------------
__fastcall TFrame_perfil::TFrame_perfil(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_perfil::inicializa(int miidperfil_z)
{
  idperfil_z= miidperfil_z;
  String sql_z;
  qry_perfiles->Tag = INACTIVO;
  qry_perfiles->Close();
  qry_perfiles->ParamByName("idperfil")->AsInteger = idperfil_z;
  qry_perfiles->Open();
  if (!qry_perfiles->IsEmpty()) {
    edt_clave->Text = qry_perfiles->FieldByName("clave")->AsString;
    edt_descri->Text = qry_perfiles->FieldByName("descri")->AsString;
  }
  qry_permgrant->Close();
  qry_permgrant->ParamByName("idperfil")->AsInteger = idperfil_z;
  qry_permgrant->Open();
  qry_permisiones->Close();
  qry_permisiones->ParamByName("idproyecto")->AsInteger = dm->idproyec_z;
  qry_permisiones->Open();
  qry_permisos->Close();
  qry_permisos->Open();
  qry_perfiles->Tag = ACTIVO;
  ultimodidperfildet_z =0;
  sql_z = "select max(IDPERFILDET) as IDPERFILDET from car_perfildet where IDPERFILDET > 0";
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Clear();
  dm->qry_maxidvnd->SQL->Add(sql_z);
 dm->qry_maxidvnd->Open();
 if(dm->qry_maxidvnd->IsEmpty()) return;
     ultimodidperfildet_z = dm->qry_maxidvnd->FieldByName("IDPERFILDET")->AsInteger;

}
//---------------------------------------------------------------------------

void __fastcall TFrame_perfil::agrega_todas_las_permisiones(int miidperfil_z)
{
  for (qry_permisiones->First(); !qry_permisiones->Eof; qry_permisiones->Next()) {
    ultimodidperfildet_z++;
    qry_permgrant->Append();
    qry_permgrant->FieldByName("idperfildet")->AsInteger = ultimodidperfildet_z;
    qry_permgrant->FieldByName("idperfil")->AsInteger = idperfil_z;
    qry_permgrant->FieldByName("idpermis")->AsInteger = qry_permisiones->FieldByName("idpermis")->AsInteger;
    qry_permgrant->FieldByName("permis")->AsString = "D";
    qry_permgrant->FieldByName("descripcion")->AsString = qry_permisiones->FieldByName("descripcion")->AsString;
    qry_permgrant->Post();
  }
}
//---------------------------------------------------------------------------




void __fastcall TFrame_perfil::dbgrd_permisKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) {
    if(Application->MessageBox("Seguro de Eliminar este permiso ?", "Eliminar Permiso", MB_ICONQUESTION+MB_YESNO) != mrYes) return;
    qry_permgrant->Delete();
  }
}
//---------------------------------------------------------------------------


void __fastcall TFrame_perfil::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_permis;
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

void __fastcall TFrame_perfil::agregar_permiExecute(TObject *Sender)
{
  String modoperm_z, descri_z;
  int idpermis_z;
  TLocateOptions Opts;
  Opts.Clear();
  idpermis_z = qry_permisiones->FieldByName("idpermis")->AsInteger;
  modoperm_z = qry_permisos->FieldByName("permiso")->AsString;
  descri_z =   qry_permisiones->FieldByName("descripcion")->AsString;
  if(qry_permgrant->State == dsInactive) return;
  qry_permgrant->Tag = EN_ESPERA;
  qry_permgrant->First();
  if (qry_permgrant->Locate("idpermis", idpermis_z, Opts) ) {
     qry_permgrant->Edit();
  } else {
    qry_permgrant->Append();
    ultimodidperfildet_z++;
    qry_permgrant->FieldByName("idperfildet")->AsInteger = ultimodidperfildet_z;
    qry_permgrant->FieldByName("idperfil")->AsInteger = idperfil_z;
    qry_permgrant->FieldByName("idpermis")->AsInteger = idpermis_z;
    qry_permgrant->FieldByName("cia")->AsInteger = cia_z;
    qry_permgrant->FieldByName("descripcion")->AsString = descri_z;
  }
  qry_permgrant->FieldByName("permis")->AsString = modoperm_z;
  qry_permgrant->Post();
  qry_permgrant->Tag = ACTIVO;

}
//---------------------------------------------------------------------------

