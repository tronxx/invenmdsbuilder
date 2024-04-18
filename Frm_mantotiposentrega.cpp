//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantotiposentrega.h"
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
TForm_mantotiposentrega *Form_mantotiposentrega;
//---------------------------------------------------------------------------
__fastcall TForm_mantotiposentrega::TForm_mantotiposentrega(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_promot->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Tipo de Entrega?", "Eliminar Tipo Entrega", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_promot->Delete();
      //if (!qry_vndptovta->IsEmpty()) qry_vndptovta->Delete();
      qry_promot->ApplyUpdates();
      //if (qry_vndptovta->UpdatesPending) qry_vndptovta->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantotiposentrega::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantotiposentrega::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantotiposentrega::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_promot->IsEmpty()) {
    Application->MessageBox("No existe El tipo de Entrega que desea modificar", "Tipo de Entrega Inexistente", MB_ICONEXCLAMATION);
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
   Dlg_mantgpoinv->Width = ancho_z - 150;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Modificar Tipo de Entrega  ";
   Frame_datosmantgpoinv->Label1->Caption = "Codigo";
   Frame_datosmantgpoinv->edt_ptovta->Width = 54;
   Frame_datosmantgpoinv->edt_ptovta->Left = 45;
   Frame_datosmantgpoinv->Label2->Left = 115;
   Frame_datosmantgpoinv->Label2->Caption = "Nombre";
   Frame_datosmantgpoinv->edt_nombre->Width = 280;
   Frame_datosmantgpoinv->edt_nombre->Left = 160;
   Frame_datosmantgpoinv->chk_imprime->Visible= false;
   Frame_datosmantgpoinv->edt_ptovta->MaxLength = 4;
   Dlg_mantgpoinv->Position = poScreenCenter;
   Frame_datosmantgpoinv->edt_ptovta->Enabled= false;
   Frame_datosmantgpoinv->edt_nombre->Text=qry_promot->FieldByName("descri")->AsString;
   Frame_datosmantgpoinv->edt_ptovta->Text=qry_promot->FieldByName("codigo")->AsString;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String marca_z="", descri_z="";
      marca_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
      descri_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();

        modif_ptvt(descri_z);

   }
     delete Frame_datosmantgpoinv;
     delete Dlg_mantgpoinv;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::desp_ptvt()
{

   edt_nombre->Text=qry_promot->FieldByName("ciudad")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantotiposentrega::nuevoExecute(TObject *Sender)
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
   Dlg_mantgpoinv->Width = ancho_z - 150;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Tipo Entrega";
   Frame_datosmantgpoinv->Label1->Caption = "Codigo";
   Frame_datosmantgpoinv->edt_ptovta->Width = 54;
   Frame_datosmantgpoinv->edt_ptovta->Left = 45;
   Frame_datosmantgpoinv->Label2->Left = 115;
   Frame_datosmantgpoinv->Label2->Caption = "Nombre";
   Frame_datosmantgpoinv->edt_nombre->Width = 280;
   Frame_datosmantgpoinv->edt_nombre->Left = 160;
   Frame_datosmantgpoinv->chk_imprime->Visible= false;
   Frame_datosmantgpoinv->edt_ptovta->MaxLength = 4;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String codigo_z="", nombre_z="";
      codigo_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
      nombre_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();

       alta_ptvt(codigo_z,nombre_z);

   }
     delete Frame_datosmantgpoinv;
     delete Dlg_mantgpoinv;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::primeroExecute(TObject *Sender)
{
   qry_promot->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::anteriorExecute(TObject *Sender)
{
   qry_promot->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::siguienteExecute(TObject *Sender)
{
   qry_promot->Next();
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantotiposentrega::ultimoExecute(TObject *Sender)
{
   qry_promot->Last();
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::alta_ptvt(String codigo_z, String nombre_z)
{
  //String vnd_z, nombre_z, zona_z, status_z;
  int idticte_z=0;
  //vnd_z = edt_cajera->Text.Trim();
  //nombre_z = edt_nombre->Text.Trim();
  idticte_z = dm->busca_sigid(IDTIPOENTREGA);
  qry_promot->Append();
  //tienda, clave, nombre, ubi, numzon, cvezon, poc, comlet, comrec, status
  qry_promot->FieldByName("idtipoentrega")->AsInteger = idticte_z;
  qry_promot->FieldByName("codigo")->AsString = codigo_z;
  qry_promot->FieldByName("cia")->AsInteger = cia_z;
  qry_promot->FieldByName("descri")->AsString = nombre_z;
  try {
    dm->manvehi->StartTransaction();
    qry_promot->ApplyUpdates();
    //if (qry_vndptovta->UpdatesPending) qry_vndptovta->ApplyUpdates();
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

void __fastcall TForm_mantotiposentrega::modif_ptvt(String nombre_z)
{
  //String vnd_z, nombre_z, zona_z, status_z;
  //vnd_z = edt_cajera->Text.Trim();
  //nombre_z = edt_nombre->Text.Trim();
  if(qry_promot->IsEmpty()) return;
  qry_promot->Edit();
  qry_promot->FieldByName("descri")->AsString = nombre_z;
  qry_promot->Post();
  try {
     dm->manvehi->StartTransaction();
     qry_promot->ApplyUpdates();
     dm->manvehi->Commit();
  } catch (Exception &E)
  {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  grabar->Tag = 0;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::botones_onoff(int modo_z)
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

void __fastcall TForm_mantotiposentrega::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idciudad")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::busca_ptvt(String ptvt_z)
{
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_promot->Close();
   qry_promot->ParamByName("idciudad")->AsInteger = StrToIntDef(ptvt_z, 0);
   qry_promot->Open();
   if(!qry_promot->IsEmpty()) {
     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTOCIUDADES);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  qry_promot->Close();
  qry_promot->ParamByName("cia")->AsInteger = cia_z;
  qry_promot->Open();
  qry_zonas->Close();
  qry_zonas->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantotiposentrega::qry_promotAfterScroll(TDataSet *DataSet)
{
  if ( grabar->Tag != 0) return;
  edt_nombre->Text = qry_promot->FieldByName("descri")->AsString;
  edt_cajera->Text = qry_promot->FieldByName("codigo")->AsString;
//  edt_clave->Text = qry_promot->FieldByName("codigo")->AsString;
//  edt_direc->Text = qry_promot->FieldByName("direc")->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::dxDBGrid1CustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
        
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposentrega::dxDBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_F2)     modificaExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);

}
//---------------------------------------------------------------------------

