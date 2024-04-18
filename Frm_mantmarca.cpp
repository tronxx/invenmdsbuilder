//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantmarca.h"
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
TForm_mantmarca *Form_mantmarca;
//---------------------------------------------------------------------------
__fastcall TForm_mantmarca::TForm_mantmarca(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_marcas->Close();
//  qry_marcas->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//  qry_marcas->Open();
  if(qry_marcas->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Marca ?", "Eliminar Marca", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_marcas->Delete();
      qry_marcas->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantmarca::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  qry_marcas->Tag = EN_ESPERA;
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantmarca::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    //case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantmarca::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_marcas->Close();
//  qry_marcas->ParamByName("idmarcainv")->AsInteger = edt_ptovta->Text.ToIntDef(0);
//  qry_marcas->Open();
  //qry_marcas->Tag = MODIF;
  if(qry_marcas->IsEmpty()) {
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
   Dlg_mantgpoinv->Width = ancho_z - 150;
   Dlg_mantgpoinv->Height = alto_z - 50;
   Dlg_mantgpoinv->Caption = "Agregar Marca Articulo Inven ";
   Frame_datosmantgpoinv->Label1->Caption = "Codigo";
   Frame_datosmantgpoinv->edt_ptovta->Width = 54;
   Frame_datosmantgpoinv->edt_ptovta->Left = 45;
   Frame_datosmantgpoinv->Label2->Left = 115;
   Frame_datosmantgpoinv->Label2->Caption = "Nombre";
   Frame_datosmantgpoinv->edt_nombre->Width = 280;
   Frame_datosmantgpoinv->edt_nombre->Left = 160;
   Frame_datosmantgpoinv->chk_imprime->Visible= false;
   Dlg_mantgpoinv->Position = poScreenCenter;
   Frame_datosmantgpoinv->edt_ptovta->Enabled= false;
   Frame_datosmantgpoinv->edt_nombre->Text=qry_marcas->FieldByName("marca")->AsString;
   Frame_datosmantgpoinv->edt_ptovta->Text=qry_marcas->FieldByName("codigo")->AsString;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String marca_z="", descri_z="";
      marca_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
      descri_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();
      modif_ptvt(marca_z,descri_z);

   }
   delete Frame_datosmantgpoinv;
   delete Dlg_mantgpoinv;




  //desp_ptvt();
  //grabar->Tag = MODIF;
  //botones_onoff(INVISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::desp_ptvt()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantmarca::nuevoExecute(TObject *Sender)
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
   Dlg_mantgpoinv->Caption = "Agregar Marca Articulo Inven ";
   Frame_datosmantgpoinv->Label1->Caption = "Codigo";
   Frame_datosmantgpoinv->edt_ptovta->Width = 54;
   Frame_datosmantgpoinv->edt_ptovta->Left = 45;
   Frame_datosmantgpoinv->Label2->Left = 115;
   Frame_datosmantgpoinv->Label2->Caption = "Nombre";
   Frame_datosmantgpoinv->edt_nombre->Width = 280;
   Frame_datosmantgpoinv->edt_nombre->Left = 160;
   Frame_datosmantgpoinv->chk_imprime->Visible= false;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      String marca_z="", descri_z="";
      marca_z = Frame_datosmantgpoinv->edt_ptovta->Text.Trim();
      descri_z = Frame_datosmantgpoinv->edt_nombre->Text.Trim();

       alta_ptvt(marca_z,descri_z);

   }
     delete Frame_datosmantgpoinv;
     delete Dlg_mantgpoinv;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::primeroExecute(TObject *Sender)
{
   qry_marcas->First();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::anteriorExecute(TObject *Sender)
{
   qry_marcas->Prior();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas where idmarcainv < "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::siguienteExecute(TObject *Sender)
{
   qry_marcas->Next();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas where idmarcainv > "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantmarca::ultimoExecute(TObject *Sender)
{
   qry_marcas->Last();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas");
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantmarca::alta_ptvt(String marca_z, String descri_z)
{
  TLocateOptions Opts;
  Opts.Clear();
    int idmarca_z=0;
    qry_marcas->First();
    if(qry_marcas->Locate("codigo", marca_z, Opts)) {
      Application->MessageBox("No puede Usar un Código que Ya Existe", "Código Duplicado", MB_ICONEXCLAMATION);
      return;
    }
    qry_marcas->First();
    if(qry_marcas->Locate("marca", descri_z, Opts)) {
      Application->MessageBox("No puede Usar una Descripción que Ya Existe", "Descripción Duplicada", MB_ICONEXCLAMATION);
      return;
    }
//  qry_marcas->Close();
//   qry_marcas->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//   qry_marcas->Open();
//   if(!qry_marcas->IsEmpty()) return;
   try {
     dm->manvehi->StartTransaction();
     idmarca_z=dm->busca_sigid(IDMARCAINV);
     qry_marcas->Append();
     qry_marcas->FieldByName("idmarcainv")->AsInteger = idmarca_z;
     qry_marcas->FieldByName("codigo")->AsString = marca_z;
     qry_marcas->FieldByName("marca")->AsString = descri_z;
     qry_marcas->Post();
     qry_marcas->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = EN_ESPERA;
   qry_marcas->Tag = EN_ESPERA;
   botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::modif_ptvt(String marca_z, String descri_z)
{
   try {
     dm->manvehi->StartTransaction();
     qry_marcas->Edit();
     qry_marcas->FieldByName("marca")->AsString = descri_z;
     qry_marcas->Post();
     qry_marcas->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = EN_ESPERA;
   qry_marcas->Tag = EN_ESPERA;
   botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::botones_onoff(int modo_z)
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

void __fastcall TForm_mantmarca::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idmarcainv")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::busca_ptvt(String ptvt_z)
{
//   if(ptvt_z.Trim().IsEmpty()) return;
//   qry_marcas->Close();
//   qry_marcas->ParamByName("idmarcainv")->AsInteger = StrToIntDef(ptvt_z, 0);
//   qry_marcas->Open();
//   if(!qry_marcas->IsEmpty()) {
//     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
//   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTOMARCAS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  
  qry_marcas->Tag = EN_ESPERA;
  qry_marcas->Close();
  qry_marcas->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::qry_marcasAfterScroll(TDataSet *DataSet)
{
  if(qry_marcas->Tag == EN_ESPERA) desp_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantmarca::dxDBGrid1CustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------

