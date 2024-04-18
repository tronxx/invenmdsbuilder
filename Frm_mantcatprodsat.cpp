//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantcatprodsat.h"
#include "dmod.h"
#include "dialg_okcancel.h"
#include "situaciones.h"
#include "Frme_datosmantotiposctes.h"
#include "Frme_importa.h"
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
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"

TForm_mantcatprodsat *Form_mantcatprodsat;
//---------------------------------------------------------------------------
__fastcall TForm_mantcatprodsat::TForm_mantcatprodsat(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcatprodsat::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(tab_activa_z == "CATPROD"    && qry_catprodsat->IsEmpty()) return;
  if(tab_activa_z == "CATUSOCFDI" && qry_usocfdi->IsEmpty())    return;
  if(tab_activa_z == "REGIMEN"    && qry_regimen->IsEmpty())    return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Registro ?", "Eliminar Registro", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      if(tab_activa_z == "CATPROD" )   {
        qry_catprodsat->Delete();
        qry_catprodsat->ApplyUpdates();
      }
      if(tab_activa_z == "CATUSOCFDI" ) {
        qry_usocfdi->Delete();
        qry_usocfdi->ApplyUpdates();
      }
      if(tab_activa_z == "REGIMEN" ) {
        qry_regimen->Delete();
        qry_regimen->ApplyUpdates();
      }
      //if (!qry_vndptovta->IsEmpty()) qry_vndptovta->Delete();
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
void __fastcall TForm_mantcatprodsat::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(tab_activa_z == "CATPROD"    && qry_catprodsat->IsEmpty()) {
    Application->MessageBox("No existe El tipo de datos a modificar", "Tipo de Dato Inexistente", MB_ICONEXCLAMATION);
    return;
  }

  if(tab_activa_z == "CATUSOCFDI" && qry_usocfdi->IsEmpty()) {
    Application->MessageBox("No existe El tipo de datos a modificar", "Tipo de Dato Inexistente", MB_ICONEXCLAMATION);
    return;
  }

  if(tab_activa_z == "REGIMEN" && qry_regimen->IsEmpty()) {
    Application->MessageBox("No existe El tipo de datos a modificar", "Tipo de Dato Inexistente", MB_ICONEXCLAMATION);
    return;
  }

  alta_ptvt("MODIF");
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantcatprodsat::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt("NUEVO");
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantcatprodsat::alta_ptvt(String modo_z)
{
   int idticte_z=0,idqom_z, ancho_z, alto_z, numero_z=0,idtipocar_z=0;
   double tasa_z;
   tasa_z = 0;
   idqom_z = 0;
   String titulo_z, codigo_z="", descri_z ="", status_z="";

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
   if(tab_activa_z == "CATPROD") {
     Frame_datosmantotiposctes->asigna_tipo("CAT_PRODSAT");
   }
   if(tab_activa_z == "CATUSOCFDI") {
     Frame_datosmantotiposctes->asigna_tipo("CAT_USOCFDI");
   }
   if(tab_activa_z == "REGIMEN") {
     Frame_datosmantotiposctes->asigna_tipo("CAT_REGIMEN");
   }
   if(modo_z == "NUEVO") {
     if(tab_activa_z == "CATPROD") {
       titulo_z = "Agregar Tipo Producto";
     }
     if(tab_activa_z == "CATUSOCFDI" ) {
       titulo_z = "Agregar Uso CFDI";
     }
     if(tab_activa_z == "REGIMEN" ) {
       titulo_z = "Agregar Régimen";
     }
   }
   if(modo_z == "MODIF") {
     if(tab_activa_z == "CATPROD") {
       titulo_z = "Modificar Tipo Producto";
       descri_z = qry_catprodsat->FieldByName("descri")->AsString;
       Frame_datosmantotiposctes->edt_nombre->Text = descri_z;
       codigo_z = qry_catprodsat->FieldByName("codigo")->AsString;
       Frame_datosmantotiposctes->edt_ptovta->Enabled = false;
       Frame_datosmantotiposctes->edt_ptovta->Text = codigo_z;
     }
     if(tab_activa_z == "CATUSOCFDI") {
       titulo_z = "Modificar Uso CFDI";
       descri_z = qry_usocfdi->FieldByName("descri")->AsString;
       Frame_datosmantotiposctes->edt_nombre->Text = descri_z;
       codigo_z = qry_usocfdi->FieldByName("codigo")->AsString;
       Frame_datosmantotiposctes->edt_ptovta->Enabled = false;
       Frame_datosmantotiposctes->edt_ptovta->Text = codigo_z;
     }
     if(tab_activa_z == "REGIMEN") {
       titulo_z = "Modificar Régimen Fiscal";
       descri_z = qry_regimen->FieldByName("descri")->AsString;
       Frame_datosmantotiposctes->edt_nombre->Text = descri_z;
       codigo_z = qry_regimen->FieldByName("codigo")->AsString;
       Frame_datosmantotiposctes->edt_ptovta->Enabled = false;
       Frame_datosmantotiposctes->edt_ptovta->Text = codigo_z;
     }
   }
   Dlg_mantgpoinv->Caption = titulo_z;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      codigo_z = Frame_datosmantotiposctes->edt_ptovta->Text.Trim();
      descri_z = Frame_datosmantotiposctes->edt_nombre->Text.Trim();
      if(tab_activa_z == "CATPROD") {
        if (modo_z == "NUEVO") {
            idticte_z = dm->busca_sigid(IDSATPRODSERV);
            qry_catprodsat->Append();
            qry_catprodsat->FieldByName("idprod")->AsInteger = idticte_z;
            qry_catprodsat->FieldByName("codigo")->AsString = codigo_z;
            qry_catprodsat->FieldByName("status")->AsString = "A";
        } else {
            qry_catprodsat->Edit();
        }
        qry_catprodsat->FieldByName("descri")->AsString = descri_z;
        qry_catprodsat->Post();
      }
      if(tab_activa_z == "CATUSOCFDI") {
        if (modo_z == "NUEVO") {
            idticte_z = dm->busca_sigid(IDSATUSOCFDI);
            qry_usocfdi->Append();
            qry_usocfdi->FieldByName("idusocfdi")->AsInteger = idticte_z;
            qry_usocfdi->FieldByName("codigo")->AsString = codigo_z;
            qry_usocfdi->FieldByName("status")->AsString = "A";
        } else {
            qry_usocfdi->Edit();
        }
        qry_usocfdi->FieldByName("descri")->AsString = descri_z;
        qry_usocfdi->Post();
      }
      if(tab_activa_z == "REGIMEN") {
        if (modo_z == "NUEVO") {
            idticte_z = dm->busca_sigid(IDSATREGIMEN);
            qry_regimen->Append();
            qry_regimen->FieldByName("idregimen")->AsInteger = idticte_z;
            qry_regimen->FieldByName("codigo")->AsString = codigo_z;
            qry_regimen->FieldByName("status")->AsString = "A";
        } else {
            qry_regimen->Edit();
        }
        qry_regimen->FieldByName("descri")->AsString = descri_z;
        qry_regimen->Post();
      }

      try {
        dm->manvehi->StartTransaction();
        if(tab_activa_z == "CATPROD") {
          qry_catprodsat->ApplyUpdates();
        }
        if(tab_activa_z == "CATUSOCFDI") {
          qry_usocfdi->ApplyUpdates();
        }
        if(tab_activa_z == "REGIMEN") {
          qry_regimen->ApplyUpdates();
        }
        dm->manvehi->Commit();
      } catch
       (Exception &E)
      {
        dm->manvehi->Rollback();
        Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
      }
   }
   delete Frame_datosmantotiposctes;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantcatprodsat::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcatprodsat::mueve_hacia(String sql_z)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantcatprodsat::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTGPOINV);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  qry_catprodsat->Close();
  qry_catprodsat->Open();
  pge_catprod->ActivePageIndex = 0;
  tab_activa_z = "CATPROD";
  qry_usocfdi->Close();
  qry_usocfdi->Open();
  qry_regimen->Close();
  qry_regimen->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcatprodsat::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantcatprodsat::dbgrd_catprodsatCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantcatprodsat::dbgrd_catprodsatKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_F2)     modificaExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcatprodsat::importarExecute(TObject *Sender)
{
  Tdlg_okcancel* Dlg_datos;
  TLocateOptions Opts;
  TStringList *noagregados_z = new TStringList();
  String errores_z, dato_z, codigo_z, descri_z;
  int idticte_z, ultcod_z,
    COL_CODIGO      = 0,
    COL_DESCRI      = 1,
  ii_z=0;
  TDateTime fecha_z;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_importa *Frame_importa;
  Frame_importa = new TFrame_importa (Dlg_datos);
  double limcred_z=0;
  ultcod_z = 1;
  idticte_z = dm->busca_sigid(IDSATPRODSERV);
  Dlg_datos->Caption = "Importación de Catálogo de Códigos Productos SAT";
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = Frame_importa->Width + 20;
  Dlg_datos->Height = Frame_importa->Height + 80;
  Frame_importa->Parent = Dlg_datos->Panel1;
  Frame_importa->Align = alTop;
  qry_catprodsat->DisableControls();

  if(Dlg_datos->ShowModal() == mrOk) {
    for(ii_z=1; ii_z < Frame_importa->sgrd_datos->RowCount; ii_z++ ) {
       qry_catprodsat->First();
       codigo_z = Frame_importa->sgrd_datos->Cells[COL_CODIGO][ii_z].Trim();
       descri_z = Frame_importa->sgrd_datos->Cells[COL_DESCRI][ii_z].Trim();
       qry_catprodsat->First();
       if(!qry_catprodsat->Locate("codigo", codigo_z, Opts)) {
         qry_catprodsat->Append();
         qry_catprodsat->FieldByName("idprod")->AsInteger = idticte_z;
         qry_catprodsat->FieldByName("codigo")->AsString = codigo_z;
         qry_catprodsat->FieldByName("status")->AsString = "A";
         qry_catprodsat->FieldByName("descri")->AsString = descri_z;
         qry_catprodsat->Post();
       } else {
         noagregados_z->Add("Registro:" + IntToStr(ii_z) + "\t" +
           codigo_z + "\t " + descri_z + "\t Ya Existe"
         );
       }
    }
    try {
      dm->manvehi->StartTransaction();
      if(qry_catprodsat->UpdatesPending) qry_catprodsat->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    if(noagregados_z->Count)  {
      Tdlg_okcancel *Dlg_datos2 = new Tdlg_okcancel (this);
      TMemo *mmo_errores = new TMemo(Dlg_datos2);
      Dlg_datos2->Caption = "Errores en Importación";
      Dlg_datos2->AutoSize = false;
      mmo_errores->Parent = Dlg_datos2->Panel1;
      mmo_errores->Width = 200;
      mmo_errores->Height = 200;
      Dlg_datos2->Width = mmo_errores->Width + 20;
      Dlg_datos2->Height = mmo_errores->Height + 80;
      mmo_errores->Align = alTop;
      mmo_errores->ScrollBars = ssBoth;
      mmo_errores->Lines->Add("Registros no recibidos:");
      for ( ii_z = 0; ii_z < noagregados_z->Count; ii_z++) {
        mmo_errores->Lines->Add(noagregados_z->Strings[ii_z]);
      }
      Dlg_datos2->ShowModal();
      delete mmo_errores;
      delete Dlg_datos2;
    }

  }
  delete Frame_importa;
  delete Dlg_datos;
  qry_catprodsat->Close();
  qry_catprodsat->Open();
  qry_catprodsat->EnableControls();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcatprodsat::pge_catprodChange(TObject *Sender)
{
  if( pge_catprod->ActivePageIndex == 0 ) {
    tab_activa_z = "CATPROD";
  }
  if( pge_catprod->ActivePageIndex == 1 ) {
    tab_activa_z = "CATUSOCFDI";
  }
  if( pge_catprod->ActivePageIndex == 2 ) {
    tab_activa_z = "REGIMEN";
  }


}
//---------------------------------------------------------------------------

