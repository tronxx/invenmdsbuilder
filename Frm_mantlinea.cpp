//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantlinea.h"
#include "dmod.h"
#include "Frme_datosnvaobslin.h"
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
#include "dialg_okcancel.h"
#include "Frme_datosmantgpoinv.h"

const int TBS_OBSMDS            = 0;
const int TBS_OBSELEC           = 1;

TForm_mantlinea *Form_mantlinea;
//---------------------------------------------------------------------------
__fastcall TForm_mantlinea::TForm_mantlinea(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Eliminar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_lineas->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Línea ?", "Eliminar Línea", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
     qry_lineas->Delete();
     for(qry_obslinmds->First(); !qry_obslinmds->Eof; qry_obslinmds->Next() )
        qry_obslinmds->Delete();
     for(qry_obslinelec->First(); !qry_obslinelec->Eof; qry_obslinelec->Next() )
        qry_obslinelec->Delete();

    try {
      dm->manvehi->StartTransaction();
      qry_lineas->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantlinea::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantlinea::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_lineas->IsEmpty()) {
    Application->MessageBox("No existe la Línea que desea modificar", "Línea Inexistente", MB_ICONEXCLAMATION);
    return;
  }
  alta_linea(MODIF);
  //grabar->Tag = MODIF;
  //botones_onoff(INVISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::desp_ptvt()
{
   edt_nombre->Text=qry_lineas->FieldByName("descri")->AsString;
   edt_ptovta->Text=qry_lineas->FieldByName("linea")->AsString;
   edt_ordlin->Value=qry_lineas->FieldByName("orden")->AsInteger;
   edt_region->Text=qry_lineas->FieldByName("region")->AsString;
   qry_obslinmds->Close();
   qry_obslinmds->ParamByName("linea")->AsString = qry_lineas->FieldByName("linea")->AsString;
   qry_obslinmds->ParamByName("cia")->AsInteger = cia_z;
   qry_obslinmds->Open();
   qry_obslinelec->Close();
   qry_obslinelec->ParamByName("linea")->AsString = qry_lineas->FieldByName("linea")->AsString;
   qry_obslinelec->ParamByName("cia")->AsInteger = cia_z;
   qry_obslinelec->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantlinea::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_linea(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::alta_linea(int modo_z)
{
   int ancho_z, alto_z, numero_z=0, idlinea_z = 0;
   String linea_z, orden_z, region_z, nombre_z;
   TEdit *edt_nvoorden;
   TEdit *edt_nvoregion;
   TLabel *lbl_orden;
   TLabel *lbl_region;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantgpoinv *Frame_datosmantgpoinv;
   Frame_datosmantgpoinv = new TFrame_datosmantgpoinv (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantgpoinv->Width + 20;
   alto_z = Frame_datosmantgpoinv->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantgpoinv->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z;
   Dlg_mantgpoinv->Caption = "Datos de la Línea";
   Frame_datosmantgpoinv->Label1->Caption = "Linea";
   Frame_datosmantgpoinv->edt_ptovta->Width = edt_ptovta->Width;
   Frame_datosmantgpoinv->edt_ptovta->Left = edt_ptovta->Left;
   Frame_datosmantgpoinv->edt_ptovta->MaxLength = 4;
   Frame_datosmantgpoinv->edt_nombre->MaxLength = 30;
   Frame_datosmantgpoinv->chk_imprime->Visible= false;
   lbl_orden = new TLabel (Frame_datosmantgpoinv);
   lbl_orden->Parent = Frame_datosmantgpoinv;
   lbl_orden->Top = Frame_datosmantgpoinv->edt_ptovta->Top + edt_ptovta->Height + 4;
   lbl_orden->Caption = "Orden";
   lbl_orden->Left = Frame_datosmantgpoinv->edt_ptovta->Left - lbl_orden->Width - 4;
   edt_nvoorden = new TEdit (Frame_datosmantgpoinv);
   edt_nvoorden->Parent = Frame_datosmantgpoinv;
   edt_nvoorden->Top = Frame_datosmantgpoinv->edt_ptovta->Top  + edt_ptovta->Height +4;
   edt_nvoorden->Left= Frame_datosmantgpoinv->edt_ptovta->Left;
   edt_nvoorden->Width = edt_ptovta->Width;
   lbl_region = new TLabel (Frame_datosmantgpoinv);
   lbl_region->Parent = Frame_datosmantgpoinv;
   lbl_region->Top = lbl_orden->Top;
   lbl_region->Caption = "Region";
   lbl_region->Left = Frame_datosmantgpoinv->edt_nombre->Left - lbl_region->Width - 4;
   edt_nvoregion = new TEdit (Frame_datosmantgpoinv);
   edt_nvoregion->Parent = Frame_datosmantgpoinv;
   edt_nvoregion->Top = edt_nvoorden->Top;
   edt_nvoregion->Left= Frame_datosmantgpoinv->edt_nombre->Left;
   edt_nvoregion->Width = edt_ptovta->Width;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if(modo_z == MODIF) {
     Frame_datosmantgpoinv->edt_ptovta->Text = edt_ptovta->Text;
     Frame_datosmantgpoinv->edt_nombre->Text = edt_nombre->Text;
     edt_nvoorden->Text = edt_ordlin->Text;
     edt_nvoregion->Text = edt_region->Text;
   }
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
     linea_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
     nombre_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();
     orden_z = edt_nvoorden->Text.Trim();
     region_z = edt_nvoregion->Text.Trim();
     qry_lineas->Tag = INACTIVO;
     if(modo_z == NUEVO) {
       idlinea_z=dm->busca_sigid(IDLINEA_INV);
       //if(dm->secuen_z == "S") idobslin_z = dm->busca_sigid(IDOBSLIN);
       qry_lineas->Append();
       qry_lineas->FieldByName("idlinea")->AsInteger = idlinea_z;
       qry_lineas->FieldByName("linea")->AsString = linea_z;
       qry_lineas->FieldByName("cia")->AsInteger = cia_z;
     }
     if(modo_z == MODIF) {
       qry_lineas->Edit();
     }
     qry_lineas->FieldByName("descri")->AsString = nombre_z;
     qry_lineas->FieldByName("orden")->AsString = orden_z;
     qry_lineas->FieldByName("region")->AsString = region_z;
     qry_lineas->Post();
     try {
       dm->manvehi->StartTransaction();
       qry_lineas->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }
   qry_lineas->Tag = ACTIVO;
   delete edt_nvoorden;
   delete edt_nvoregion;
   delete lbl_orden;
   delete lbl_region;
   delete Frame_datosmantgpoinv;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantlinea::primeroExecute(TObject *Sender)
{
   mueve_hacia("select min (linea) as linea from inv_lineas");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::anteriorExecute(TObject *Sender)
{
   mueve_hacia("select max (linea) as linea from inv_lineas where linea < '"+edt_ptovta->Text+"'");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::siguienteExecute(TObject *Sender)
{
   mueve_hacia("select min (linea) as linea from inv_lineas where linea > '"+edt_ptovta->Text+"'");
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantlinea::ultimoExecute(TObject *Sender)
{
   mueve_hacia("select max (linea) as linea from inv_lineas");
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantlinea::alta_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::botones_onoff(int modo_z)
{
  switch (modo_z) {
    case INVISIBLES:
      nuevo->Enabled=false;
      modifica->Enabled=false;
      borra->Enabled=false;
      grabar->Enabled=true;
      cancelar->Enabled=true;
      agregaobs->Enabled=true;
      borraobs->Enabled=true;
      borratodasobs->Enabled=true;
//      pnl_btngral->Visible=false;
      dbgrd_obsmds->Tag = !EN_ESPERA;
      //dbgrd_obselec->Tag = !EN_ESPERA;
      dts_obslinelec->AutoEdit = true;
      dts_obslinmds->AutoEdit = true;
       break;
    case VISIBLES:
//      pnl_btngral->Visible=true;
      nuevo->Enabled=true;
      modifica->Enabled=true;
      borra->Enabled=true;
      grabar->Enabled=false;
      cancelar->Enabled=false;
      agregaobs->Enabled=false;
      borraobs->Enabled=false;
      borratodasobs->Enabled=false;
      dbgrd_obsmds->Tag = EN_ESPERA;
      //dbgrd_obselec->Tag = EN_ESPERA;
      dts_obslinelec->AutoEdit = false;
      dts_obslinmds->AutoEdit = false;
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(dm->qry_maxidvnd->FieldByName("linea")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::busca_ptvt(String ptvt_z)
{
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_lineas->Close();
   qry_lineas->ParamByName("linea")->AsString = ptvt_z;
   qry_lineas->ParamByName("cia")->AsInteger = cia_z;
   qry_lineas->Open();
   if(!qry_lineas->IsEmpty()) {
     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::FormCreate(TObject *Sender)
{
  permis_z="N";
  cia_z = dm->cia_z;
  permis_z = dm->busca_permision(MANTLINEA_INV);
  if(permis_z == "N") {
    Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    Close();
  }
  qry_lineas->Tag = INACTIVO;
  qry_lineas->Close();
  qry_lineas->ParamByName("cia")->AsInteger = cia_z;
  qry_lineas->Open();
  qry_obslinmds->Close();
  qry_obslinmds->ParamByName("linea")->AsString = qry_lineas->FieldByName("linea")->AsString;
  qry_obslinmds->ParamByName("cia")->AsInteger = cia_z;
  qry_obslinmds->Open();

  qry_lineas->Tag = ACTIVO;

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantlinea::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantlinea::agregaobsExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_obs(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::alta_obs(int modo_z)
{
   int esok_z=0, result_z, cuantos_z, antconse_z, alto_z,
      ancho_z, conse_z=0, nrecord_z = 0;
   String error_z, linea_z, moe_z = "M";
   TQuery *qry_obslin;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosnvaobslin *Frame_datosnvaobslin;
   Frame_datosnvaobslin = new TFrame_datosnvaobslin (Dlg_mantgpoinv);
   ancho_z = Frame_datosnvaobslin->Width + 20;
   alto_z = Frame_datosnvaobslin->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosnvaobslin->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Caption = "Datos de la Observación";
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z;
   linea_z = qry_lineas->FieldByName("linea")->AsString;
   Frame_datosnvaobslin->inicializa();

   if(page_observs->ActivePage == tbs_mds) {
      qry_obslin = qry_obslinmds;
      moe_z = "M";
      qry_obslin->UpdateObject = qry_obslinmds->UpdateObject;
   } else {
      qry_obslin = qry_obslinelec;
      moe_z = "E";
      qry_obslin->UpdateObject = qry_obslinelec->UpdateObject;
   }
   if (modo_z == MODIF) {
     antconse_z = qry_obslin->FieldByName("conse")->AsInteger;
     Frame_datosnvaobslin->edt_obser->Text = qry_obslin->FieldByName("obser")->AsString;
     Frame_datosnvaobslin->edt_ordobs->Value = antconse_z;
     Frame_datosnvaobslin->lkcmb_fonini->KeyValue = qry_obslin->FieldByName("fonini")->AsInteger;
     Frame_datosnvaobslin->lkcmb_fonfin->KeyValue = qry_obslin->FieldByName("fonfin")->AsInteger;
   }
   result_z = 0;
   while(!result_z) {
     result_z = Dlg_mantgpoinv->ShowModal();
     conse_z = Frame_datosnvaobslin->edt_ordobs->Value;
     cuantos_z = 0;
     if( result_z == mrOk) {
       cuantos_z = busca_cuantos_conse(linea_z, conse_z, moe_z);
       esok_z = 1;
       if(conse_z != antconse_z && modo_z == MODIF) {
         if(cuantos_z > 0) {
           esok_z = 0;
           error_z = "Ya Existe otro renglon con ese consecutivo";
         }
       }
       if (modo_z == NUEVO && cuantos_z > 0) {
         esok_z = 0;
         error_z = "Ya Existe otro renglon con ese consecutivo";
       }
       if(esok_z == 1) {
         if (modo_z == NUEVO) {
           qry_obslin->Append();
           nrecord_z = qry_obslin->RecordCount * -1;
          //qry_obslinelec->FieldByName("idobslin")->AsInteger = dm->busca_sigid(IDOBSLIN);
          //qry_obslin->FieldByName("idobslin")->AsInteger = nrecord_z;
           qry_obslin->FieldByName("linea")->AsString= linea_z;
           qry_obslin->FieldByName("cia")->AsInteger = cia_z;
         } else {
           qry_obslin->Edit();
         }
         qry_obslin->FieldByName("obser")->AsString = Frame_datosnvaobslin->edt_obser->Text.TrimRight();
         qry_obslin->FieldByName("fonini")->AsInteger = Frame_datosnvaobslin->qry_fonini->FieldByName("numero")->AsInteger;
         qry_obslin->FieldByName("fonfin")->AsInteger = Frame_datosnvaobslin->qry_fonfin->FieldByName("numero")->AsInteger;
         qry_obslin->FieldByName("conse")->AsInteger = Frame_datosnvaobslin->edt_ordobs->Value;
         qry_obslin->FieldByName("moe")->AsString = moe_z;
         qry_obslin->Post();
         try {
           dm->manvehi->StartTransaction();
           qry_obslin->ApplyUpdates();
           dm->manvehi->Commit();
         } catch (Exception &E)
         {
           dm->manvehi->Rollback();
           Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
         }
       } else {
         result_z = 0;
         Application->MessageBox("No pude repetir un consecutivo", "ERROR", MB_ICONEXCLAMATION);
       }
     }
   }
   delete Frame_datosnvaobslin;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::borraobsExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede eliminar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  String obs_z;
  if(page_observs->ActivePage == tbs_mds) {
      if(qry_obslinmds->IsEmpty()) return;
      obs_z = qry_obslinmds->FieldByName("obser")->AsString;
    } else {
      if(qry_obslinelec->IsEmpty()) return;
      obs_z = qry_obslinelec->FieldByName("obser")->AsString;
  }

  if(Application->MessageBox(("eliminar esta observación:\n" + obs_z).c_str(),"Eliminar Observacion", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == mrYes) {
    if(page_observs->ActivePage == tbs_mds) {
      qry_obslinmds->Delete();
    } else {
      qry_obslinelec->Delete();
    }
    try {
       dm->manvehi->StartTransaction();
       if(page_observs->ActivePage == tbs_mds) {
         qry_obslinmds->ApplyUpdates();
       } else {
         qry_obslinelec->ApplyUpdates();
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

int __fastcall TForm_mantlinea::busca_cuantos_conse(String linea_z, int conse_z, String moe_z)
{
  qry_busconse->Close();
  qry_busconse->ParamByName("linea")->AsString = linea_z;
  qry_busconse->ParamByName("moe")->AsString = moe_z;
  qry_busconse->ParamByName("conse")->AsInteger = conse_z;
  qry_busconse->ParamByName("cia")->AsInteger = cia_z;
  qry_busconse->Open();
  return (qry_busconse->FieldByName("cuantos")->AsInteger);

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::dbgrd_obsmdsKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(((TdxDBGrid*)Sender)->Tag == EN_ESPERA) return;
  if(Key == VK_DELETE) borraobsExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantlinea::borratodasobsExecute(TObject *Sender)
{
  int result_z = 0;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede eliminar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  result_z = Application->MessageBox("Esta seguro que quiere eliminar TODAS LAS OBSERVACIONES","Eliminar Observaciones", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2);
  if( result_z == mrYes) {
    result_z = Application->MessageBox("Esta REALMENTE seguro que quiere eliminar TODAS LAS OBSERVACIONES","Eliminar Observaciones", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2);
  }
  if( result_z == mrYes) {
    if(page_observs->ActivePage == tbs_mds) {
      for(qry_obslinmds->First(); !qry_obslinmds->Eof; qry_obslinmds->First() )
        qry_obslinmds->Delete();
    } else {
      for(qry_obslinelec->First(); !qry_obslinelec->Eof; qry_obslinelec->First() )
        qry_obslinelec->Delete();
    }
    try {
       dm->manvehi->StartTransaction();
       if(page_observs->ActivePage == tbs_mds) {
         qry_obslinmds->ApplyUpdates();
       } else {
         qry_obslinelec->ApplyUpdates();
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


void __fastcall TForm_mantlinea::qry_lineasAfterScroll(TDataSet *DataSet)
{
  if (qry_lineas->Tag == ACTIVO) {
    desp_ptvt();
  }

}
//---------------------------------------------------------------------------



void __fastcall TForm_mantlinea::modifrenExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_obs(MODIF);

}
//---------------------------------------------------------------------------

