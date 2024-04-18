//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantmayo.h"
#include "dmod.h"
#include "Frme_datosmantmayo.h"
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
#pragma link "Frme_datosmantmayo"
#pragma resource "*.dfm"

#include "situaciones.h"
TForm_mantmayo *Form_mantmayo;
//---------------------------------------------------------------------------
__fastcall TForm_mantmayo::TForm_mantmayo(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::agrega_relac(String mayoris_z, String dato1_z, String dato2_z, String tipodato_z)
{
  int iddato1_z=0, iddato2_z, nvoidrel_z, mitiporel_z;
  nvoidrel_z = dm->busca_sigid(MAY_RELAC);
  nvoidrel_z += qry_datospago->RecordCount;
  bool encontrado_z=false;
  iddato1_z = dm->busca_iddato(dato1_z, INVCONCEPTO);
  iddato2_z = iddato1_z;
  if(tipodato_z == "TIPOPAGO" || tipodato_z == "NUMCTA") {
    mitiporel_z = REL_MAYORIS_TIPOPAGO;
    iddato2_z = dm->busca_iddato(dato2_z, INVCONCEPTO);
  }
  if(tipodato_z == "TIPOPAGO2" || tipodato_z == "NUMCTA2") {
    mitiporel_z = REL_MAYORIS_TIPOPAGO2;
    iddato2_z = dm->busca_iddato(dato2_z, INVCONCEPTO);
  }
  if(tipodato_z == "CALLE") {
    mitiporel_z = REL_MAYORIS_CALLE;
  }
  if(tipodato_z == "NUMPRED") {
    mitiporel_z = REL_MAYORIS_NUMPRED;
  }
  if(tipodato_z == "CODPOST") {
    mitiporel_z = REL_MAYORIS_CODPOST;
  }
  if(tipodato_z == "COLONIA") {
    mitiporel_z = REL_MAYORIS_COLONIA;
  }
  if(tipodato_z == "EMAIL") {
    mitiporel_z = REL_MAYORIS_EMAIL;
  }
  if(tipodato_z == "EMAIL2") {
    mitiporel_z = REL_MAYORIS_EMAIL2;
  }
  if(tipodato_z == "REGIMEN") {
    mitiporel_z = REL_MAYORIS_REGIMEN;
  }

  for(qry_datospago->First(); !qry_datospago->Eof; qry_datospago->Next() ) {
    if(qry_datospago->FieldByName("idtiporel")->AsInteger == mitiporel_z) {
      encontrado_z = true; break;
    }
  }
   if(!encontrado_z) {
      qry_datospago->Append();
      qry_datospago->FieldByName("idrelac")->AsInteger = nvoidrel_z;
      qry_datospago->FieldByName("idmayoris")->AsInteger = -1;
      qry_datospago->FieldByName("mayoris")->AsString = mayoris_z;
      qry_datospago->FieldByName("idtiporel")->AsInteger = mitiporel_z;
      qry_datospago->FieldByName("cia")->AsInteger = cia_z;
      nvoidrel_z++;
   } else {
      qry_datospago->Edit();
   }
   qry_datospago->FieldByName("iddato1")->AsInteger = iddato1_z;
   qry_datospago->FieldByName("iddato2")->AsInteger = iddato2_z;
   qry_datospago->Post();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::desp_vnd()
{
   if(qry_mayoris->IsEmpty()) return;
   agrega_o_modif("DESPLIEGA");
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  agrega_o_modif("NUEVO");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::agrega_o_modif(String accion_z)
{
   int ancho_z, alto_z, numero_z=0, tipo_z=0,
     idvnd_z=0, iddir_z,  idtel_z, numiden_z, iddirpag_z,
     idnompag_z, idrelmay_z;

   String codigo_z="", tit_z, nombre_z, apell_z, direc_z, poblac_z,
       rfc_z,telef_z,nombrepag_z,direcpag_z,direc2pag_z,
       poblacpag_z, descritipo_z, mediopago_z, mediopago2_z,
       numcta2_z, numcta_z, email_z, calle_z, npred_z, codpost_z, colonia_z,
       ciupag_z, email2_z, regimen_z, status_z = "";
   double descu_z;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantmayo *Frame_datosmantmayo;
   Frame_datosmantmayo = new TFrame_datosmantmayo (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantmayo->Width + 20;
   alto_z = Frame_datosmantmayo->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantmayo->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z ;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if(accion_z == "MODIF") {
     codigo_z = qry_mayoris->FieldByName("codigo")->AsString;
     tit_z = "Modificar Cliente Mayorista";
     Frame_datosmantmayo->edt_codvnd->Enabled = false;
   }
   if(accion_z == "NUEVO") {
     tit_z = "Nuevo Cliente Mayorista";
   }
   if(accion_z == "DESPLIEGA") {
     codigo_z = qry_mayoris->FieldByName("codigo")->AsString;
     tit_z = "Datos Cliente Mayorista";
     Frame_datosmantmayo->edt_codvnd->Enabled = false;
     Dlg_mantgpoinv->btn_ok->Width += Dlg_mantgpoinv->btn_cancel->Width + 30;
     Dlg_mantgpoinv->btn_cancel->Visible = false;
   }
   Dlg_mantgpoinv->Caption = tit_z;
   Frame_datosmantmayo->busca_vnd(codigo_z);
   if( Dlg_mantgpoinv->ShowModal() == mrOk && (accion_z == "NUEVO" || accion_z == "MODIF" )) {
       //Datos Gnerales//
       codigo_z = Frame_datosmantmayo->edt_codvnd->Text.Trim();
       nombre_z = Frame_datosmantmayo->edt_nombre->Text.Trim();
       apell_z = Frame_datosmantmayo->edt_nombre2->Text.Trim();
       calle_z = Frame_datosmantmayo->edt_direc->Text.Trim();
       npred_z = Frame_datosmantmayo->edt_numpred->Text.Trim();
       codpost_z = Frame_datosmantmayo->edt_codpost->Text.Trim();
       colonia_z = Frame_datosmantmayo->edt_colonia->Text.Trim();
       email_z = Frame_datosmantmayo->edt_email->Text.Trim();
       //email2_z = Frame_datosmantmayo->edt_email2->Text.Trim();
       poblac_z = Frame_datosmantmayo->lkcmb_ciudad->Text;
       rfc_z = Frame_datosmantmayo->edt_rfc->Text.Trim();
       telef_z = Frame_datosmantmayo->edt_tel->Text.Trim();
       //Datos Pagaré//
       nombrepag_z = Frame_datosmantmayo->edt_nompag->Text;
       direcpag_z = Frame_datosmantmayo->edt_dirpag->Text;
       direc2pag_z = Frame_datosmantmayo->edt_dirpag2->Text;
       poblacpag_z = Frame_datosmantmayo->lkcmb_ciudad2->Text;
       descu_z = Frame_datosmantmayo->edt_pdsc->Value;
       tipo_z = Frame_datosmantmayo->qry_invtipomay->FieldByName("idtipomay")->AsInteger;
       descritipo_z = Frame_datosmantmayo->qry_invtipomay->FieldByName("descri")->AsString;
       mediopago_z = Frame_datosmantmayo->qry_mediospago->FieldByName("idtipago")->AsString;
       numcta_z = Frame_datosmantmayo->edt_numcta->Text;
       mediopago2_z = Frame_datosmantmayo->qry_mediopago2->FieldByName("idtipago")->AsString;
       numcta2_z = Frame_datosmantmayo->edt_numcta2->Text;
       regimen_z = Frame_datosmantmayo->qry_regimen->FieldByName("idregimen")->AsString;

       if(Frame_datosmantmayo->cmb_status->ItemIndex ) {
         status_z = "B";
       } else {
         status_z = "A";
       };

       qry_mostmayo->Close();
       qry_mostmayo->ParamByName("codigo")->AsString = codigo_z;
       qry_mostmayo->ParamByName("cia")->AsInteger=cia_z;
       qry_mostmayo->Open();
       if(accion_z == "NUEVO") {
         if(!qry_mostmayo->IsEmpty()) return;
       } else {
         if(qry_mostmayo->IsEmpty()) return;
       }
       if(accion_z == "NUEVO") {
         qry_mayoris->Append();
         qry_mayoris->FieldByName("codigo")->AsString = codigo_z;
       } else {
         qry_mayoris->Edit();
       }
    //     qry_mayoris->FieldByName("idmayoris")->AsInteger = idvnd_z;
       direc_z = calle_z + " N." + npred_z + " Col:" + colonia_z + " CP:" + codpost_z;
       qry_mayoris->FieldByName("nombre")->AsString = nombre_z;
       qry_mayoris->FieldByName("nombre2")->AsString = apell_z;
       qry_mayoris->FieldByName("direc")->AsString = direc_z;
       qry_mayoris->FieldByName("ciu")->AsString =  poblac_z;
       qry_mayoris->FieldByName("rfc")->AsString = rfc_z;
       qry_mayoris->FieldByName("tel")->AsString = telef_z;
       qry_mayoris->FieldByName("cargos")->AsFloat = 0;
       qry_mayoris->FieldByName("abonos")->AsFloat = 0;
       qry_mayoris->FieldByName("compraanu")->AsFloat = 0;
       qry_mayoris->FieldByName("comprames")->AsFloat = 0;
       qry_mayoris->FieldByName("pdsc")->AsFloat = descu_z;
       qry_mayoris->FieldByName("ultmov")->AsInteger = 0;
       qry_mayoris->FieldByName("status")->AsString = status_z;
       qry_mayoris->FieldByName("cia")->AsInteger = cia_z;
       qry_mayoris->FieldByName("nompag1")->AsString = nombrepag_z;
       qry_mayoris->FieldByName("nompag2")->AsString = "";
       qry_mayoris->FieldByName("dirpag1")->AsString = direcpag_z;
       qry_mayoris->FieldByName("dirpag2")->AsString = direc2pag_z;
       qry_mayoris->FieldByName("ciupag")->AsString = poblacpag_z;
       qry_mayoris->FieldByName("tipo")->AsInteger = tipo_z;
       qry_mayoris->FieldByName("descri")->AsString = descritipo_z;
       qry_mayoris->Post();
       qry_datospago->Close();
       qry_datospago->ParamByName("mayoris")->AsString = codigo_z;
       qry_datospago->ParamByName("cia")->AsInteger = cia_z;
       //qry_datospago->ParamByName("idtiporel")->AsInteger = REL_MAYORIS_TIPOPAGO;
       qry_datospago->Open();
       agrega_relac(codigo_z, mediopago_z, numcta_z, "TIPOPAGO");
       agrega_relac(codigo_z, mediopago2_z, "", "TIPOPAGO2");
       agrega_relac(codigo_z, calle_z,   calle_z, "CALLE");
       agrega_relac(codigo_z, npred_z,   npred_z, "NUMPRED");
       agrega_relac(codigo_z, codpost_z, codpost_z, "CODPOST");
       agrega_relac(codigo_z, colonia_z, colonia_z, "COLONIA");
       agrega_relac(codigo_z, email_z,   email_z, "EMAIL");
       agrega_relac(codigo_z, regimen_z,   regimen_z, "REGIMEN");
       //agrega_relac(codigo_z, email2_z,   email2_z, "EMAIL2");

       try {
         dm->manvehi->StartTransaction();
         qry_mayoris->ApplyUpdates();
         qry_datospago->ApplyUpdates();
         if(Frame_datosmantmayo->qry_telefonos->UpdatesPending) {
           Frame_datosmantmayo->qry_telefonos->ApplyUpdates();
         }
         if(Frame_datosmantmayo->qry_emailes->UpdatesPending) {
           Frame_datosmantmayo->qry_emailes->ApplyUpdates();
         }
         dm->manvehi->Commit();
       } catch (Exception &E)
       {
         dm->manvehi->Rollback();
         Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
       }
       grabar->Tag = 0;
   }
   delete Frame_datosmantmayo;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantmayo::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTOMAY);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  qry_mayoris->Close();
  qry_mayoris->ParamByName("cia")->AsInteger = cia_z;
  qry_mayoris->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_mayoris->IsEmpty()) return;
  agrega_o_modif("MODIF");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::borraExecute(TObject *Sender)
{
  String codigo_z;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede eliminar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_mayoris->IsEmpty()) return;

  if(Application->MessageBox("Esta Seguro de Eliminar este Mayorista ?", "Eliminar Mayorista", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    codigo_z = qry_mayoris->FieldByName("codigo")->AsString;
    qry_telefonos->Close();
    qry_telefonos->ParamByName("mayoris")->AsString = codigo_z;
    qry_telefonos->ParamByName("cia")->AsInteger = cia_z;
    qry_telefonos->ParamByName("idtiporel")->AsInteger = RELTELFAX;
    qry_telefonos->Open();
    qry_datospago->Close();
    qry_datospago->ParamByName("mayoris")->AsString = codigo_z;
    qry_datospago->ParamByName("cia")->AsInteger = cia_z;
    qry_datospago->Open();
    for( qry_telefonos->First(); !qry_telefonos->IsEmpty(); qry_telefonos->Next())
       qry_telefonos->Delete();
    for( qry_datospago->First(); !qry_datospago->IsEmpty(); qry_datospago->Next())
       qry_datospago->Delete();
    try {
      dm->manvehi->StartTransaction();
      qry_mayoris->Delete();
      qry_mayoris->ApplyUpdates();
      if ( qry_telefonos->UpdatesPending) qry_telefonos->ApplyUpdates();
      if ( qry_datospago->UpdatesPending) qry_datospago->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_vnd(dm->qry_maxidvnd->FieldByName("codigo")->AsString);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::busca_vnd(String vnd_z)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::primeroExecute(TObject *Sender)
{
   //mueve_hacia("select min (codigo) as codigo from mayoris  where cia="+IntToStr(cia_z));
   qry_mayoris->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::anteriorExecute(TObject *Sender)
{
   //mueve_hacia("select max (codigo) as codigo from mayoris  where codigo < '"+edt_codvnd->Text.Trim()+"' and cia="+IntToStr(cia_z));
   qry_mayoris->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::siguienteExecute(TObject *Sender)
{
   //mueve_hacia("select min (codigo) as codigo from mayoris  where codigo > '"+edt_codvnd->Text.Trim()+"' and cia="+IntToStr(cia_z));
   qry_mayoris->Next();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::ultimoExecute(TObject *Sender)
{
   //mueve_hacia("select max (codigo) as codigo from mayoris  where cia="+IntToStr(cia_z));
   qry_mayoris->Last();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::actualiza_tipostel()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmayo::dbgrd_mayorisKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_SPACE)  desp_vnd();
  if(Key == VK_INSERT) nuevoExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::dbgrd_mayorisDblClick(TObject *Sender)
{
  desp_vnd();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::dbgrd_mayorisCustomDrawCell(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxTreeListColumn *AColumn, bool ASelected,
      bool AFocused, bool ANewItemRow, AnsiString &AText, TColor &AColor,
      TFont *AFont, TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;        
        
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmayo::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_mayoris;
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
  SaveDialog->FileName = dbgrd_mayoris->Name + ".xls";
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

