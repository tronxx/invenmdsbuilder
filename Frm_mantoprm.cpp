//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantoprm.h"
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
const int ALTA  = 0;
const int BAJA   = 1;

TForm_mantoprm *Form_mantoprm;
//---------------------------------------------------------------------------
__fastcall TForm_mantoprm::TForm_mantoprm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_promot->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este chofer?", "Eliminar Chofer", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
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
void __fastcall TForm_mantoprm::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantoprm::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantoprm::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_promot->IsEmpty()) {
    Application->MessageBox("No existe el Chofer que desea modificar", "Chofer Inexistente", MB_ICONEXCLAMATION);
    return;
  }
   int ancho_z, alto_z, numero_z=0,itemindex_z = 0;
   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantovnd *Frame_datosmantovnd;
   Frame_datosmantovnd = new TFrame_datosmantovnd (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantovnd->Width + 20;
   alto_z = Frame_datosmantovnd->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantovnd->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z ;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Chofer";
   Dlg_mantgpoinv->Position = poScreenCenter;
   Frame_datosmantovnd->edt_cajera->Text = qry_promot->FieldByName("clave")->AsString;
   Frame_datosmantovnd->edt_nombre->Text = qry_promot->FieldByName("nombre")->AsString;
   Frame_datosmantovnd->lkcmb_ptovta->KeyValue = qry_promot->FieldByName("numzon")->AsString;
   if(qry_promot->FieldByName("status")->AsString == "A")
    itemindex_z = ALTA;
  else
    itemindex_z = BAJA;
    Frame_datosmantovnd->cmb_status->ItemIndex = itemindex_z;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String vnd_z, nombre_z, zona_z,status_z;
      int valor_z;
      valor_z = Frame_datosmantovnd->cmb_status->ItemIndex;
      if ( valor_z == BAJA) status_z = "B"; else status_z = "A";
      vnd_z = Frame_datosmantovnd->edt_cajera->Text.Trim();
      nombre_z = Frame_datosmantovnd->edt_nombre->Text.Trim();
      zona_z = Frame_datosmantovnd->qry_ptovta->FieldByName("zona")->AsString;

      modif_ptvt(vnd_z, nombre_z, zona_z,status_z);

   }
     delete Frame_datosmantovnd;
     delete Dlg_mantgpoinv;


  //grabar->Tag = MODIF;
  //botones_onoff(INVISIBLES);
  //edt_nombre->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::desp_ptvt()
{

   edt_nombre->Text=qry_promot->FieldByName("ciudad")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoprm::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }

   int ancho_z, alto_z, numero_z=0;
   Tdlg_okcancel *Dlg_mantgpoinv;
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
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String vnd_z, nombre_z, zona_z,status_z;
      if (cmb_status->ItemIndex == BAJA ) status_z = "B"; else status_z = "A";
      vnd_z = Frame_datosmantovnd->edt_cajera->Text.Trim();
      nombre_z = Frame_datosmantovnd->edt_nombre->Text.Trim();
      zona_z = Frame_datosmantovnd->qry_ptovta->FieldByName("zona")->AsString;


      alta_ptvt(vnd_z, nombre_z, zona_z,status_z);

   }
     delete Frame_datosmantovnd;
     delete Dlg_mantgpoinv;



  //grabar->Tag = NUEVO;
  //botones_onoff(INVISIBLES);
  //edt_cajera->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::primeroExecute(TObject *Sender)
{
   qry_promot->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::anteriorExecute(TObject *Sender)
{
   qry_promot->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::siguienteExecute(TObject *Sender)
{
   qry_promot->Next();
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantoprm::ultimoExecute(TObject *Sender)
{
   qry_promot->Last();
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantoprm::alta_ptvt(String vnd_z, String nombre_z, String zona_z,String status_z)
{
  //String vnd_z, nombre_z, zona_z, status_z;
  int idvndptovt_z=0;
  //vnd_z = edt_cajera->Text.Trim();
  //nombre_z = edt_nombre->Text.Trim();
  //zona_z = qry_zonas->FieldByName("zona")->AsString;
  //if (cmb_status->ItemIndex > 0) status_z = "B"; else status_z = "A";
  qry_promot->Append();
  //tienda, clave, nombre, ubi, numzon, cvezon, poc, comlet, comrec, status
  qry_promot->FieldByName("tienda")->AsString = " 0";
  qry_promot->FieldByName("ubi")->AsString = "";
  qry_promot->FieldByName("cvezon")->AsString = "";
  qry_promot->FieldByName("poc")->AsString = "";
  qry_promot->FieldByName("comlet")->AsFloat = 0;
  qry_promot->FieldByName("comrec")->AsFloat = 0;
  qry_promot->FieldByName("clave")->AsString = vnd_z;
//  qry_promot->FieldByName("clave")->AsString = edt_clave->Text.Trim();
  qry_promot->FieldByName("nombre")->AsString = nombre_z;
  qry_promot->FieldByName("numzon")->AsString = zona_z;
  qry_promot->FieldByName("status")->AsString = status_z;
//  qry_promot->FieldByName("direc")->AsString = edt_direc->Text.Trim();
//  qry_promot->FieldByName("cia")->AsInteger = cia_z;
//  qry_vndptovta->Close();
//  qry_vndptovta->ParamByName("codigo")->AsString = vnd_z;
//  qry_vndptovta->ParamByName("tipo")->AsInteger = TIPO_REL_VND_ZONA;
//  qry_vndptovta->Open();
//  if (qry_vndptovta->IsEmpty()) {
//    idvndptovt_z = dm->busca_sigid(IDVNDPTOVT);
//    qry_vndptovta->Append();
//    qry_vndptovta->FieldByName("idvndptovt")->AsInteger = idvndptovt_z;
//    qry_vndptovta->FieldByName("idvendedor")->AsInteger = 0;
//    qry_vndptovta->FieldByName("tipo")->AsInteger = TIPO_REL_VND_ZONA;
//    qry_vndptovta->FieldByName("codigo")->AsString = vnd_z;
//    qry_vndptovta->FieldByName("cia")->AsInteger = cia_z;
//  } else {
//    if (qry_vndptovta->FieldByName("zona")->AsString != zona_z) {
//      qry_vndptovta->Edit();
//    }
//  }
//  if ((qry_vndptovta->State == dsEdit) || (qry_vndptovta->State == dsInsert)) {
//     qry_vndptovta->FieldByName("idptovta")->AsInteger = 0;
//     qry_vndptovta->FieldByName("ptovta")->AsString = "";
//     qry_vndptovta->FieldByName("zona")->AsString = zona_z;
//     qry_vndptovta->Post();
//  }
//  qry_promot->Post();
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

void __fastcall TForm_mantoprm::modif_ptvt(String vnd_z, String nombre_z, String zona_z,String status_z)
{
  //String vnd_z, nombre_z, zona_z, status_z;
  //vnd_z = edt_cajera->Text.Trim();
  //nombre_z = edt_nombre->Text.Trim();
  //zona_z = qry_zonas->FieldByName("zona")->AsString;
  //if (cmb_status->ItemIndex > 0) status_z = "B"; else status_z = "A";
  int idvndptovt_z = 0;
  if(qry_promot->IsEmpty()) return;
  qry_promot->Edit();
  qry_promot->FieldByName("tienda")->AsString = " 0";
  qry_promot->FieldByName("ubi")->AsString = "";
  qry_promot->FieldByName("cvezon")->AsString = "";
  qry_promot->FieldByName("poc")->AsString = "";
  qry_promot->FieldByName("comlet")->AsFloat = 0;
  qry_promot->FieldByName("comrec")->AsFloat = 0;
  qry_promot->FieldByName("clave")->AsString = vnd_z;
  qry_promot->FieldByName("nombre")->AsString = nombre_z;
  qry_promot->FieldByName("numzon")->AsString = zona_z;
  qry_promot->FieldByName("status")->AsString = status_z;
   qry_promot->Post();
//   qry_vndptovta->Close();
//   qry_vndptovta->ParamByName("codigo")->AsString = vnd_z;
//   qry_vndptovta->ParamByName("tipo")->AsInteger = TIPO_REL_VND_ZONA;
//   qry_vndptovta->Open();
//   if (qry_vndptovta->IsEmpty()) {
//     idvndptovt_z = dm->busca_sigid(IDVNDPTOVT);
//     qry_vndptovta->Append();
//     qry_vndptovta->FieldByName("idvndptovt")->AsInteger = idvndptovt_z;
//     qry_vndptovta->FieldByName("tipo")->AsInteger = TIPO_REL_VND_ZONA;
//     qry_vndptovta->FieldByName("idvendedor")->AsInteger = 0;
//     qry_vndptovta->FieldByName("codigo")->AsString = vnd_z;
//     qry_vndptovta->FieldByName("cia")->AsInteger = cia_z;
//   } else {
//     if( qry_vndptovta->FieldByName("zona")->AsString != zona_z) {
//       qry_vndptovta->Edit();
//     }
//   }
//   if (qry_vndptovta->State == dsEdit || qry_vndptovta->State == dsInsert) {
//      qry_vndptovta->FieldByName("idptovta")->AsInteger = 0;
//      qry_vndptovta->FieldByName("ptovta")->AsString = "";
//      qry_vndptovta->FieldByName("zona")->AsString = zona_z;
//      qry_vndptovta->Post();
//   }
   try {
     dm->manvehi->StartTransaction();
     qry_promot->ApplyUpdates();
     //if (qry_vndptovta->UpdatesPending) qry_vndptovta->ApplyUpdates();
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

void __fastcall TForm_mantoprm::botones_onoff(int modo_z)
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

void __fastcall TForm_mantoprm::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idciudad")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::busca_ptvt(String ptvt_z)
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

void __fastcall TForm_mantoprm::FormCreate(TObject *Sender)
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
  qry_zonas->Close();
  qry_zonas->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoprm::qry_promotAfterScroll(TDataSet *DataSet)
{
  int itemindex_z = 0;
  if ( grabar->Tag != 0) return;
  edt_nombre->Text = qry_promot->FieldByName("nombre")->AsString;
  edt_cajera->Text = qry_promot->FieldByName("clave")->AsString;
  lkcmb_ptovta->KeyValue = qry_promot->FieldByName("numzon")->AsString;
  if(qry_promot->FieldByName("status")->AsString == "A")
    itemindex_z = ALTA;
  else
    itemindex_z = BAJA;
  cmb_status->ItemIndex = itemindex_z;

//  edt_clave->Text = qry_promot->FieldByName("clave")->AsString;
//  edt_direc->Text = qry_promot->FieldByName("direc")->AsString;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoprm::dxDBGrid1CustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
        
}
//---------------------------------------------------------------------------

