//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantotiposctes.h"
#include "dmod.h"
#include "dialg_okcancel.h"
#include "situaciones.h"
#include "Frme_datosmantotiposctes.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "Frme_datosmantotiposctes"
#pragma resource "*.dfm"

TForm_mantotiposctes *Form_mantotiposctes;
//---------------------------------------------------------------------------
__fastcall TForm_mantotiposctes::TForm_mantotiposctes(TComponent* Owner)
        : TForm(Owner)
{

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_promot->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Tipo de Venta?", "Eliminar Tipo Venta", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
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
void __fastcall TForm_mantotiposctes::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantotiposctes::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantotiposctes::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_promot->IsEmpty()) {
    Application->MessageBox("No existe El tipo de cliente modificar", "Tipo de Cliente Inexistente", MB_ICONEXCLAMATION);
    return;
  }

   int ancho_z, alto_z, numero_z=0,itemindex_z=0;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantotiposctes *Frame_datosmantotiposctes;
   Frame_datosmantotiposctes = new TFrame_datosmantotiposctes (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantotiposctes->Width + 20;
   alto_z = Frame_datosmantotiposctes->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantotiposctes->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Marca Articulo Inven ";
   Dlg_mantgpoinv->Position = poScreenCenter;
   Frame_datosmantotiposctes->edt_ptovta->Enabled= false;
   Frame_datosmantotiposctes->edt_nombre->Text=qry_promot->FieldByName("descri")->AsString;
   Frame_datosmantotiposctes->edt_ptovta->Text=qry_promot->FieldByName("ticte")->AsString;
   Frame_datosmantotiposctes->lkcmb_ptovta->KeyValue=qry_promot->FieldByName("tipo")->AsString;
   if(qry_promot->FieldByName("remate")->AsString == "N")
    itemindex_z = 0;
   else
    itemindex_z = 1;
   Frame_datosmantotiposctes->cmb_remate->ItemIndex = itemindex_z;

   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String descri_z="",tipo_z,remate_z;
      int valor_z;
      valor_z = Frame_datosmantotiposctes->cmb_remate->ItemIndex;
      if ( valor_z >= 1) remate_z = "R"; else remate_z = "N";
      descri_z = Frame_datosmantotiposctes->edt_nombre->Text.Trim();
      tipo_z = Frame_datosmantotiposctes->qry_tipocar->FieldByName("descri")->AsString;
      modif_ptvt(descri_z,remate_z,tipo_z);
   }
   delete Frame_datosmantotiposctes;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::desp_ptvt()
{

   //edt_nombre->Text=qry_promot->FieldByName("ciudad")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantotiposctes::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }

   int ancho_z, alto_z, numero_z=0,idtipocar_z=0,cia_z,idqom_z;
   double tasa_z;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantotiposctes *Frame_datosmantotiposctes;
   Frame_datosmantotiposctes = new TFrame_datosmantotiposctes (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantotiposctes->Width + 20;
   alto_z = Frame_datosmantotiposctes->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantotiposctes->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Tipo Cliente Venta ";
   Dlg_mantgpoinv->Position = poScreenCenter;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String codigo_z="", nombre_z="",remate_z="", tipo_z;
      codigo_z = Frame_datosmantotiposctes->edt_ptovta->Text.Trim();
      nombre_z = Frame_datosmantotiposctes->edt_nombre->Text.Trim();
      idtipocar_z = Frame_datosmantotiposctes->qry_tipocar->FieldByName("idtipocar")->AsInteger;
      cia_z = Frame_datosmantotiposctes->qry_tipocar->FieldByName("cia")->AsInteger;
      if (Frame_datosmantotiposctes->cmb_remate->ItemIndex > 0) remate_z = "R"; else remate_z = "N";
      tipo_z = Frame_datosmantotiposctes->lkcmb_ptovta->KeyValue;

       alta_ptvt(codigo_z,nombre_z,idtipocar_z,cia_z,remate_z,tipo_z);

   }
     delete Frame_datosmantotiposctes;
     delete Dlg_mantgpoinv;




}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::primeroExecute(TObject *Sender)
{
   qry_promot->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::anteriorExecute(TObject *Sender)
{
   qry_promot->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::siguienteExecute(TObject *Sender)
{
   qry_promot->Next();
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantotiposctes::ultimoExecute(TObject *Sender)
{
   qry_promot->Last();
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::alta_ptvt(String codigo_z, String nombre_z, int idtipocar_z, int cia_z, String remate_z, String tipo_z)
{
    int idticte_z=0,idqom_z;
    double tasa_z;
    tasa_z = 0;
    idqom_z = 0;
    idticte_z = dm->busca_sigid(IDTICTE);
    qry_promot->Append();
    qry_promot->FieldByName("idticte")->AsInteger = idticte_z;
    qry_promot->FieldByName("idtipocar")->AsInteger = idtipocar_z;
    qry_promot->FieldByName("idqom")->AsInteger = idqom_z;
    qry_promot->FieldByName("ticte")->AsString = codigo_z;
    qry_promot->FieldByName("descri")->AsString = nombre_z;
    qry_promot->FieldByName("tasacom")->AsFloat = tasa_z;
    qry_promot->FieldByName("cia")->AsInteger = cia_z;
    qry_promot->FieldByName("remate")->AsString = remate_z;
    qry_promot->FieldByName("tipo")->AsString = tipo_z;


    qry_promot->Post();
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
  //grabar->Tag = 0;
  //botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::modif_ptvt(String nombre_z,String remate_z,String tipo_z)
{
  //String vnd_z, nombre_z, zona_z, status_z;
  //vnd_z = edt_cajera->Text.Trim();
  //nombre_z = edt_nombre->Text.Trim();
  if(qry_promot->IsEmpty()) return;
  qry_promot->Edit();
  qry_promot->FieldByName("descri")->AsString = nombre_z;
  qry_promot->FieldByName("remate")->AsString = remate_z;
  qry_promot->FieldByName("tipo")->AsString = tipo_z;

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
  //grabar->Tag = 0;
  //botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::botones_onoff(int modo_z)
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

void __fastcall TForm_mantotiposctes::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idciudad")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::busca_ptvt(String ptvt_z)
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

void __fastcall TForm_mantotiposctes::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTOCIUDADES);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  
  qry_promot->Close();
//  qry_promot->ParamByName("cia")->AsInteger = cia_z;
  qry_promot->Open();
  //qry_zonas->Close();
  //qry_zonas->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantotiposctes::qry_promotAfterScroll(TDataSet *DataSet)
{
 int itemindex_z;
 String tipo_z;
 tipo_z= qry_promot->FieldByName("tipo")->AsString;
  if ( grabar->Tag != 0) return;

  Frame_datosmantotiposctes1->edt_ptovta->Text = qry_promot->FieldByName("ticte")->AsString;
  Frame_datosmantotiposctes1->edt_nombre->Text = qry_promot->FieldByName("descri")->AsString;
  Frame_datosmantotiposctes1->lkcmb_ptovta->KeyValue = tipo_z;
  if(qry_promot->FieldByName("remate")->AsString == "N")
    itemindex_z = 0;
  else
    itemindex_z = 1;
  Frame_datosmantotiposctes1->cmb_remate->ItemIndex = itemindex_z;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantotiposctes::dxDBGrid1CustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantotiposctes::dxDBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_F2)     modificaExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);
}
//---------------------------------------------------------------------------

