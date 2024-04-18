//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantousr.h"
#include "dmod.h"
#include "dialg_okcancel.h"
#include "Frme_usuario.h"
#include "Frme_perfil.h"
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
#pragma link "dxGrClEx"
#pragma link "dxGrClms"
#pragma resource "*.dfm"

#include "situaciones.h"
TForm_mantousr *Form_mantousr;
//---------------------------------------------------------------------------
__fastcall TForm_mantousr::TForm_mantousr(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::botones_onoff(int modo_z)
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

void __fastcall TForm_mantousr::alta_vnd()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::modif_vnd()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantousr::desp_vnd()
{
  if(pagina_z == "TBS_USUARIOS") alta_usuario(EN_ESPERA);
  if(pagina_z == "TBS_PERFILES") alta_perfil(EN_ESPERA);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::nuevoExecute(TObject *Sender)
{
  int idusuario_z;
  String modoperm_z;
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(pagina_z == "TBS_USUARIOS") alta_usuario(NUEVO);
  if(pagina_z == "TBS_PERFILES") alta_perfil(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(pagina_z == "TBS_USUARIOS") alta_usuario(MODIF);
  if(pagina_z == "TBS_PERFILES") alta_perfil(MODIF);

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::alta_usuario(int modo_z)
{
  int idusuario_z=0, numiden_z=0, resultmodal_z=0;
  bool esmaestro_z=0, esdebaja_z=0;
  if(modo_z == NUEVO) {
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Clear();
    dm->qry_maxidvnd->SQL->Add("select max (idusuario) as clave from car_usuarios");
    dm->qry_maxidvnd->Open();
    if(!dm->qry_maxidvnd->IsEmpty())
      idusuario_z = dm->qry_maxidvnd->FieldByName("clave")->AsInteger + 1;
  } else {
    idusuario_z = qry_usuario->FieldByName("idusuario")->AsInteger;
  }
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_usuario *Frame_usuario;
  Frame_usuario = new TFrame_usuario(Dlg_datos);
  Dlg_datos->Caption = "Datos del Usuario";
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = Frame_usuario->Width + 20;
  Dlg_datos->Height = Frame_usuario->Height + 80;
  Frame_usuario->Parent = Dlg_datos->Panel1;
  Frame_usuario->idproyec_z = idproyec_z;
  Frame_usuario->inicializa(idusuario_z);
  Frame_usuario->edt_codvnd->Value = idusuario_z;
  Frame_usuario->Align = alClient;
  if(modo_z == NUEVO) {
    Frame_usuario->edt_codvnd->Enabled = false;
  } else {
    esmaestro_z = (qry_usuario->FieldByName("maestro")->AsString == "S");
    esdebaja_z  = (qry_usuario->FieldByName("status")->AsString == "B");
    Frame_usuario->edt_nombre->Text=qry_usuario->FieldByName("nombre")->AsString;
    Frame_usuario->edt_codvnd->Value=qry_usuario->FieldByName("idusuario")->AsInteger;
    Frame_usuario->edt_numpol->Text=qry_usuario->FieldByName("numpol")->AsString;
    Frame_usuario->edt_login->Text=qry_usuario->FieldByName("login")->AsString;
    Frame_usuario->edt_passw->Text=qry_usuario->FieldByName("clave")->AsString;
    Frame_usuario->edt_iniciales->Text=qry_usuario->FieldByName("iniciales")->AsString;
    Frame_usuario->chk_maestro->Checked = esmaestro_z;
    Frame_usuario->chk_baja->Checked = esdebaja_z;
  }
  if(modo_z == EN_ESPERA) {
    Dlg_datos->btn_cancel->Visible = false;
    Frame_usuario->lkcmb_perfil->Enabled = false;
  }
  resultmodal_z = Dlg_datos->ShowModal();
  if(modo_z == EN_ESPERA) {
    delete Frame_usuario;
    delete Dlg_datos;
    return;
  }
  if(resultmodal_z == mrOk) {
     idusuario_z = Frame_usuario->edt_codvnd->Value;
     Frame_usuario->agrega_perfil_usuario(idusuario_z);
     numiden_z=dm->busca_iddato(Frame_usuario->edt_nombre->Text.Trim(), ENFIMO);
     if(modo_z == NUEVO) {
       qry_usuario->Append();
       qry_usuario->FieldByName("idusuario")->AsInteger = idusuario_z;
     } else {
       qry_usuario->Edit();
     }
     qry_usuario->FieldByName("idnombre")->AsInteger = numiden_z;
     qry_usuario->FieldByName("numpol")->AsString = Frame_usuario->edt_numpol->Text;
     qry_usuario->FieldByName("login")->AsString = Frame_usuario->edt_login->Text;
     qry_usuario->FieldByName("clave")->AsString =Frame_usuario->edt_passw->Text;
     qry_usuario->FieldByName("iniciales")->AsString = Frame_usuario->edt_iniciales->Text;
     qry_usuario->FieldByName("nombre")->AsString = Frame_usuario->edt_nombre->Text;
     if(Frame_usuario->chk_maestro->Checked)
       qry_usuario->FieldByName("maestro")->AsString = "S";
     else
       qry_usuario->FieldByName("maestro")->AsString = "N";
     if(Frame_usuario->chk_baja->Checked) {
       qry_usuario->FieldByName("status")->AsString = "B";
       qry_usuario->FieldByName("fecbaj")->AsDateTime = Frame_usuario->date_fecbaja->Date;
     } else {
       qry_usuario->FieldByName("status")->AsString = "A";
     }
     qry_usuario->Post();
     try {
       dm->manvehi->StartTransaction();
       qry_usuario->ApplyUpdates();
       if (Frame_usuario->qry_permgrant->UpdatesPending)
          Frame_usuario->qry_permgrant->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
  }
  delete Frame_usuario;
  delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_vnd(); break;
    case MODIF: modif_vnd(); break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::FormCreate(TObject *Sender)
{
  permis_z=dm->busca_permision(MANTOUSR);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  qry_usuario->Close();
  qry_usuario->Open();
  qry_perfiles->Close();
  qry_perfiles->ParamByName("cia")->AsInteger = cia_z;
  qry_perfiles->Open();
  pgctrl_datos->ActivePageIndex = 0;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantousr::borraExecute(TObject *Sender)
{
  borra_usuario();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::borra_usuario()
{
  if(pagina_z == "TBS_USUARIOS")  if(qry_usuario->IsEmpty()) return;
  if(pagina_z == "TBS_PERFILES")  if(qry_perfiles->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Registro ?", "Eliminar", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      if(pagina_z == "TBS_USUARIOS") {
        qry_permgrant->Close();
        qry_permgrant->ParamByName("idusuario")->AsInteger = qry_usuario->FieldByName("idusuario")->AsInteger;
        qry_permgrant->ExecSQL();
        qry_usuario->Delete();
        qry_usuario->ApplyUpdates();
      }
      if(pagina_z == "TBS_PERFILES") {
        qry_eliminapermiperfil->Close();
        qry_eliminapermiperfil->ParamByName("idperfil")->AsInteger = qry_perfiles->FieldByName("idperfil")->AsInteger;
        qry_eliminapermiperfil->ExecSQL();
        qry_perfiles->Delete();
        qry_perfiles->ApplyUpdates();
      }
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_vnd(dm->qry_maxidvnd->FieldByName("clave")->AsString);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantousr::busca_vnd(String vnd_z)
{
   if(vnd_z.Trim().IsEmpty()) return;
    qry_usuario->Close();
    qry_usuario->ParamByName("idusuario")->AsInteger = StrToIntDef(vnd_z, 0);
    qry_usuario->Open();
    if(!qry_usuario->IsEmpty()) {
      desp_vnd(); grabar->Tag = 0; botones_onoff(VISIBLES);
    }
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantousr::primeroExecute(TObject *Sender)
{
    qry_usuario->First();
   //mueve_hacia("select min (idusuario) as clave from car_usuarios");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::anteriorExecute(TObject *Sender)
{
    qry_usuario->Prior();
   //mueve_hacia("select max (idusuario) as clave from car_usuarios where idusuario < "+IntToStr((int)edt_codvnd->Value));

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::siguienteExecute(TObject *Sender)
{
   qry_usuario->Next();
   //mueve_hacia("select min (idusuario) as clave from car_usuarios where idusuario > "+IntToStr((int)edt_codvnd->Value));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::ultimoExecute(TObject *Sender)
{

    qry_usuario->Last();
   //mueve_hacia("select max (idusuario) as clave from car_usuarios");

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantousr::dbgrd_usuariosDblClick(TObject *Sender)
{
  desp_vnd();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::dbgrd_usuariosKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_SPACE)  desp_vnd();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  if(pagina_z == "TBS_USUARIOS")  midbgrd_z = dbgrd_usuarios;
  if(pagina_z == "TBS_PERFILES")  midbgrd_z = dbgrd_perfiles;
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

void __fastcall TForm_mantousr::tbs_usuariosShow(TObject *Sender)
{
  pagina_z = pagina_z;
  TTabSheet *pPC = dynamic_cast<TTabSheet *>(Sender);
  pagina_z = pPC->Name;
  pagina_z = pagina_z.UpperCase();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantousr::alta_perfil(int modo_z)
{

  int idperfil_z=0, numiden_z=0, resultmodal_z=0;
  if(modo_z == NUEVO) {
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Clear();
    dm->qry_maxidvnd->SQL->Add("select max (idperfil) as clave from car_perfil where idperfil > 0");
    dm->qry_maxidvnd->Open();
    if(!dm->qry_maxidvnd->IsEmpty())
      idperfil_z = dm->qry_maxidvnd->FieldByName("clave")->AsInteger + 1;
  } else {
    idperfil_z = qry_perfiles->FieldByName("idperfil")->AsInteger;
  }
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_perfil *Frame_perfil;
  Frame_perfil = new TFrame_perfil(Dlg_datos);
  Dlg_datos->Caption = "Datos del Perfil";
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = Frame_perfil->Width + 20;
  Dlg_datos->Height = Frame_perfil->Height + 80;
  Frame_perfil->Parent = Dlg_datos->Panel1;
  Frame_perfil->idproyec_z = idproyec_z;
  Frame_perfil->inicializa(idperfil_z);
  Frame_perfil->Align = alClient;
  if(modo_z == NUEVO) {
    Frame_perfil->edt_clave->Enabled = true;
  } else {
    Frame_perfil->edt_clave->Enabled = false;
  }
  if(modo_z == EN_ESPERA) {
    Dlg_datos->btn_cancel->Visible = false;
    Frame_perfil->grp_permisiones->Visible = false;
  }
  resultmodal_z = Dlg_datos->ShowModal();
  if(modo_z == EN_ESPERA) {
    delete Frame_perfil;
    delete Dlg_datos;
    return;
  }
  if(resultmodal_z == mrOk) {
     if(modo_z == NUEVO) {
       qry_perfiles->Append();
       qry_perfiles->FieldByName("idperfil")->AsInteger = idperfil_z;
     } else {
       qry_perfiles->Edit();
     }
     qry_perfiles->FieldByName("clave")->AsString = Frame_perfil->edt_clave->Text.Trim();
     qry_perfiles->FieldByName("descri")->AsString = Frame_perfil->edt_descri->Text.Trim();
     qry_perfiles->FieldByName("cia")->AsInteger = cia_z;
     qry_perfiles->Post();
     try {
       dm->manvehi->StartTransaction();
       qry_perfiles->ApplyUpdates();
       resultmodal_z= resultmodal_z;
       if (Frame_perfil->qry_permgrant->UpdatesPending)
          Frame_perfil->qry_permgrant->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
  }
  delete Frame_perfil;
  delete Dlg_datos;
}
//---------------------------------------------------------------------------

