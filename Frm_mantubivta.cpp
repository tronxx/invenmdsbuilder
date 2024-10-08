//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantubivta.h"
#include "dmod.h"
#include "dialg_okcancel.h"
#include "Frme_datosubivta.h"
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
TForm_mantubivta *Form_mantubivta;
//---------------------------------------------------------------------------
__fastcall TForm_mantubivta::TForm_mantubivta(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_situac->Close();
//  qry_situac->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//  qry_situac->Open();
  if(qry_situac->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Ubicación ?", "Eliminar Ubicación ", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
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
void __fastcall TForm_mantubivta::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }

  if(qry_situac->IsEmpty()) {
    Application->MessageBox("No existe la Ubicación que desea modificar", "Ubicación Inexistente", MB_ICONEXCLAMATION);
    return;
  }
  agregar_modificar(MODIF);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::desp_ptvt()
{

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantubivta::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  agregar_modificar(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::agregar_modificar(int tipo_z)
{
   int ancho_z, alto_z, numero_z=0;
   String ubica_z, alm_z, ptovta_z, zona_z, voc_z,
      zonapvta_z, ptvta2_z, zonartdesp_z, zonaptvta2_z,
      zonacar_z, subzoncar_z;

   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosubivta *Frame_datosubivta;
   Frame_datosubivta = new TFrame_datosubivta (Dlg_mantgpoinv);
   ancho_z = Frame_datosubivta->Width + 20;
   alto_z = Frame_datosubivta->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosubivta->Parent = Dlg_mantgpoinv->Panel1;
   Frame_datosubivta->tipo_z = tipo_z;
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z;
   Dlg_mantgpoinv->Caption = "Agregar Ubicacion Venta Inven ";
   Dlg_mantgpoinv->Position = poScreenCenter;
   if(tipo_z == MODIF) {
      Frame_datosubivta->edt_ubica->Text = qry_situac->FieldByName("ubica")->AsString;
      //Frame_datosubivta->edt_ubica->Enabled = false;
      Frame_datosubivta->edt_almac->Text = qry_situac->FieldByName("alm")->AsString;
      Frame_datosubivta->edt_ptovta->Text = qry_situac->FieldByName("pvta")->AsString;
      Frame_datosubivta->edt_zonainv->Text = qry_situac->FieldByName("zonainv")->AsString;
      Frame_datosubivta->cmb_voc->ItemIndex = qry_situac->FieldByName("voc")->AsInteger  - 1;
      Frame_datosubivta->edt_zonaptvta->Text = qry_situac->FieldByName("zona2")->AsString;
      Frame_datosubivta->edt_ptvta2->Text = qry_situac->FieldByName("ptvta2")->AsString;
      Frame_datosubivta->edt_zonartdesp->Text = qry_situac->FieldByName("zonartdes")->AsString;
      Frame_datosubivta->edt_zonapvta2->Text = qry_situac->FieldByName("zonaptvta")->AsString;
      Frame_datosubivta->edt_zonacar->Text = qry_situac->FieldByName("zonacar")->AsString;
      Frame_datosubivta->edt_subzoncar->Text = qry_situac->FieldByName("subzoncar")->AsString;
   }
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      ubica_z      = Frame_datosubivta->edt_ubica->Text.Trim();
      alm_z        = Frame_datosubivta->edt_almac->Text.Trim();
      ptovta_z     = Frame_datosubivta->edt_ptovta->Text.Trim();
      zona_z       = Frame_datosubivta->edt_zonainv->Text.Trim();
      voc_z        = IntToStr(Frame_datosubivta->cmb_voc->ItemIndex + 1);
      zonapvta_z   = Frame_datosubivta->edt_zonaptvta->Text.Trim();
      ptvta2_z     = Frame_datosubivta->edt_ptvta2->Text.Trim();
      zonartdesp_z = Frame_datosubivta->edt_zonartdesp->Text.Trim();
      zonaptvta2_z = Frame_datosubivta->edt_zonapvta2->Text.Trim();
      zonacar_z    = Frame_datosubivta->edt_zonacar->Text.Trim();
      subzoncar_z  = Frame_datosubivta->edt_subzoncar->Text.Trim();
      if(tipo_z == NUEVO) {
        qry_situac->Append();
        qry_situac->FieldByName("alm")->AsString = alm_z;
        qry_situac->FieldByName("pvta")->AsString = ptovta_z;
        qry_situac->FieldByName("ubica")->AsString = ubica_z;
      } else {
        qry_situac->Edit();
      }
      qry_situac->FieldByName("ubica")->AsString = ubica_z;
      qry_situac->FieldByName("zonainv")->AsString = zona_z;
      qry_situac->FieldByName("voc")->AsString = zona_z;
      qry_situac->FieldByName("zona2")->AsString = zonapvta_z;
      qry_situac->FieldByName("ptvta2")->AsString = ptvta2_z;
      qry_situac->FieldByName("zonartdes")->AsString = zonartdesp_z;
      qry_situac->FieldByName("zonaptvta")->AsString = zonaptvta2_z;
      qry_situac->FieldByName("zonacar")->AsString = zonacar_z;
      qry_situac->FieldByName("subzoncar")->AsString = subzoncar_z;
      qry_situac->Post();
      try {
         dm->manvehi->StartTransaction();
         qry_situac->ApplyUpdates();
         dm->manvehi->Commit();
      } catch (Exception &E)
      {
         dm->manvehi->Rollback();
         dm->MensajeError("No pude grabar los datos:\n"+E.Message, "ERROR");
      }
   }
   delete Frame_datosubivta;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::alta_ptvt(String situacion_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::modif_ptvt(String situacion_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::mueve_hacia(String sql_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::busca_ptvt(String ptvt_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::FormCreate(TObject *Sender)
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
  dbgrd_ubivta->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantubivta::dbgrd_ubivtaCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::dbgrd_ubivtaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_F2)     modificaExecute(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantubivta::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_ubivta;
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

