//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantempaqe.h"
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
TForm_mantempaqe *Form_mantempaqe;
//---------------------------------------------------------------------------
__fastcall TForm_mantempaqe::TForm_mantempaqe(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_situac->Close();
//  qry_situac->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//  qry_situac->Open();
  if(qry_situac->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Marca ?", "Eliminar Marca", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_situac->Delete();
      qry_situac->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantempaqe::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  qry_situac->Tag = EN_ESPERA;
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantempaqe::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) busca_ptvt(edt_codigo->Text);
}
//-------------------------------------------------------------------------
void __fastcall TForm_mantempaqe::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantempaqe::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }

  if(qry_situac->IsEmpty()) {
    Application->MessageBox("No existe la Marca que desea modificar", "Marca Inexistente", MB_ICONEXCLAMATION);
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
   Dlg_mantgpoinv->Width = ancho_z - 300;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Marca Articulo Inven ";
   Frame_datosmantgpoinv->Label1->Align = Top;
   Frame_datosmantgpoinv->Label1->Caption = "Codigo";
   Frame_datosmantgpoinv->edt_ptovta->Width = 190;
   Frame_datosmantgpoinv->edt_ptovta->Left = 45;
   Frame_datosmantgpoinv->Label2->Visible= false;
   Frame_datosmantgpoinv->edt_nombre->Visible= false;
   Frame_datosmantgpoinv->chk_imprime->Visible= false;
   Dlg_mantgpoinv->Position = poScreenCenter;
   Frame_datosmantgpoinv->edt_ptovta->Text=qry_situac->FieldByName("situacion")->AsString;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String situacion_z;
      situacion_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
       modif_ptvt(situacion_z);

   }
     delete Frame_datosmantgpoinv;
     delete Dlg_mantgpoinv;
  
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::desp_ptvt()
{

//   edt_nombre->Text=qry_situac->FieldByName("marca")->AsString;
   edt_codigo->Text=qry_situac->FieldByName("situacion")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantempaqe::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
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
   Dlg_mantgpoinv->Width = ancho_z - 300;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Marca Articulo Inven ";
   Frame_datosmantgpoinv->Label1->Align = alTop;
   Frame_datosmantgpoinv->Label1->Caption = "Codigo";
   Frame_datosmantgpoinv->edt_ptovta->Width = 190;
   Frame_datosmantgpoinv->edt_ptovta->Left = 45;
   Frame_datosmantgpoinv->Label2->Visible= false;
   Frame_datosmantgpoinv->edt_nombre->Visible= false;
   Frame_datosmantgpoinv->chk_imprime->Visible= false;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String situacion_z;
      situacion_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
       alta_ptvt(situacion_z);

   }
   delete Frame_datosmantgpoinv;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::primeroExecute(TObject *Sender)
{
   qry_situac->First();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::anteriorExecute(TObject *Sender)
{
   qry_situac->Prior();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas where idmarcainv < "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::siguienteExecute(TObject *Sender)
{
   qry_situac->Next();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas where idmarcainv > "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantempaqe::ultimoExecute(TObject *Sender)
{
   qry_situac->Last();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas");
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::alta_ptvt(String situacion_z)
{
  TLocateOptions Opts;
  Opts.Clear();
    int idsituac_z=0;
    //String situacion_z;
    //situacion_z = edt_codigo->Text.Trim();
    qry_situac->First();
    if(qry_situac->Locate("situacion", situacion_z, Opts)) {
      Application->MessageBox("No puede Usar un Situacion que Ya Existe", "Situacion Duplicado", MB_ICONEXCLAMATION);
      return;
    }
//  qry_situac->Close();
//   qry_situac->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//   qry_situac->Open();
//   if(!qry_situac->IsEmpty()) return;
   try {
     dm->manvehi->StartTransaction();
     idsituac_z=dm->busca_sigid(IDSITUAC);
     qry_situac->Append();
     qry_situac->FieldByName("idsituac")->AsInteger = idsituac_z;
     qry_situac->FieldByName("situacion")->AsString = situacion_z;
     qry_situac->Post();
     qry_situac->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = EN_ESPERA;
   qry_situac->Tag = EN_ESPERA;
   botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::modif_ptvt(String situacion_z)
{
   try {
     dm->manvehi->StartTransaction();
     qry_situac->Edit();
     qry_situac->FieldByName("situacion")->AsString = situacion_z;
     qry_situac->Post();
     qry_situac->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = EN_ESPERA;
   qry_situac->Tag = EN_ESPERA;
   botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::botones_onoff(int modo_z)
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

void __fastcall TForm_mantempaqe::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idsituacion")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::busca_ptvt(String ptvt_z)
{
//   if(ptvt_z.Trim().IsEmpty()) return;
//   qry_situac->Close();
//   qry_situac->ParamByName("idmarcainv")->AsInteger = StrToIntDef(ptvt_z, 0);
//   qry_situac->Open();
//   if(!qry_situac->IsEmpty()) {
//     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
//   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::FormCreate(TObject *Sender)
{
  permis_z=dm->busca_permision(MANTOMARCAS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  qry_situac->Tag = EN_ESPERA;
  qry_situac->Close();
  qry_situac->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantempaqe::qry_situacAfterScroll(TDataSet *DataSet)
{
  if(qry_situac->Tag == EN_ESPERA) desp_ptvt();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantempaqe::dxDBGrid1CustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
        
}
//---------------------------------------------------------------------------

