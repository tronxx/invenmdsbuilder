//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantzona.h"
#include "dmod.h"
#include "Frame_zonas.h"
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
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_mantzona *Form_mantzona;
void __fastcall MantoZonas(TForm *Padre)
{
    bool bResult = false;
    try
    {
        Form_mantzona = new TForm_mantzona(Padre);
        Form_mantzona->Show();
    }
    catch(...)
    {
    }
}
//---------------------------------------------------------------------------

__fastcall TForm_mantzona::TForm_mantzona(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::borraExecute(TObject *Sender)
{
  String tit_z, tit1_z, tit2_z;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if (tipo_z == "MEGAZONAS") {
     if(qry_megazonas->IsEmpty()) return;
     tit_z = "Megazona";
  }
  if (tipo_z == "MEGAZONAS") {
     if(qry_zonas->IsEmpty()) return;
     tit_z = "Zona";
  }

  tit1_z = "Esta Seguro de Eliminar esta " + tit_z;
  tit2_z = "Eliminar " + tit_z;

  if(Application->MessageBox(tit1_z.c_str(), tit2_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      if (tipo_z == "MEGAZONAS") {
        qry_megazonas->Delete();
        qry_megazonas->ApplyUpdates();
      }
      if (tipo_z == "ZONAS") {
        qry_zonas->Delete();
        qry_zonas->ApplyUpdates();
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
void __fastcall TForm_mantzona::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantzona::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_ptvt(); break;
    case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantzona::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if (tipo_z == "MEGAZONAS") {
     if(qry_megazonas->IsEmpty()) return;
  }
  if (tipo_z == "MEGAZONAS") {
     if(qry_zonas->IsEmpty()) return;
  }
  modif_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::desp_ptvt()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantzona::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::primeroExecute(TObject *Sender)
{
   //mueve_hacia("select min (zona) as zona from zonasmve where cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::anteriorExecute(TObject *Sender)
{
   //mueve_hacia("select max (zona) as zona from zonasmve where zona < "+edt_ptovta->Text+" and cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::siguienteExecute(TObject *Sender)
{
    //mueve_hacia("select min (zona) as zona from zonasmve where zona > "+edt_ptovta->Text+" and cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantzona::ultimoExecute(TObject *Sender)
{
   //mueve_hacia("select max (zona) as zona from zonasmve where cia="+IntToStr(cia_z));
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantzona::alta_ptvt()
{
   String tit_z;
   int idmegazona_z;
   Tdlg_okcancel* Dlg_datos;
   Dlg_datos = new Tdlg_okcancel (this);
   TFrme_zonas *Frme_zonas;
   Frme_zonas = new TFrme_zonas (Dlg_datos);
   if (tipo_z == "MEGAZONAS") {
     tit_z = "Megazona";
   }
   if (tipo_z == "ZONAS") {
     tit_z = "Zona";
   }
   Dlg_datos->Caption = "Datos de la " + tit_z;
   Frme_zonas->Parent = Dlg_datos->Panel1;
   if(Dlg_datos->ShowModal() == mrOk) {
     try {
       dm->manvehi->StartTransaction();
       if (tipo_z == "MEGAZONAS") {
         idmegazona_z = dm->busca_sigid(IDMEGAZONAINV);
         qry_megazonas->Append();
         qry_megazonas->FieldByName("idmegazona")->AsInteger = idmegazona_z;
         qry_megazonas->FieldByName("clave")->AsString = FormatFloat("00", Frme_zonas->edt_ptovta->Value);
         qry_megazonas->FieldByName("descri")->AsString = Frme_zonas->edt_nombre->Text;
         qry_megazonas->FieldByName("cia")->AsInteger = cia_z;
         qry_megazonas->Post();
         qry_megazonas->ApplyUpdates();
       }
       if (tipo_z == "ZONAS") {
         qry_zonas->Append();
         qry_zonas->FieldByName("zona")->AsString  = FormatFloat("00", Frme_zonas->edt_ptovta->Value);
         qry_zonas->FieldByName("nombre")->AsString = Frme_zonas->edt_nombre->Text;
         //qry_zonas->FieldByName("cia")->AsInteger = cia_z;
         qry_zonas->Post();
         qry_zonas->ApplyUpdates();
       }
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }
   delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::modif_ptvt()
{
   Tdlg_okcancel* Dlg_datos;
   String tit_z;
   Dlg_datos = new Tdlg_okcancel (this);
   TFrme_zonas *Frme_zonas;
   Frme_zonas = new TFrme_zonas (Dlg_datos);
   if (tipo_z == "MEGAZONAS") {
     tit_z = "Megazona";
     Frme_zonas->edt_nombre->Text = qry_zonas->FieldByName("descri")->AsString;
     Frme_zonas->edt_ptovta->Text = qry_megazonas->FieldByName("clave")->AsString;
   }
   if (tipo_z == "ZONAS") {
     tit_z = "Zona";
     Frme_zonas->edt_nombre->Text = qry_zonas->FieldByName("nombre")->AsString;
     Frme_zonas->edt_ptovta->Value = qry_zonas->FieldByName("zona")->AsInteger;
   }

   Frme_zonas->Parent = Dlg_datos->Panel1;
   Frme_zonas->edt_ptovta->Enabled = false;
   Dlg_datos->Caption = "Datos de la " + tit_z;
   if(Dlg_datos->ShowModal() == mrOk) {
     try {
       dm->manvehi->StartTransaction();
       if (tipo_z == "ZONAS") {
         qry_zonas->Edit();
         qry_zonas->FieldByName("nombre")->AsString = Frme_zonas->edt_nombre->Text;
         qry_zonas->Post();
         qry_zonas->ApplyUpdates();
       }
       if (tipo_z == "MEGAZONAS") {
         qry_megazonas->Edit();
         qry_megazonas->FieldByName("descri")->AsString = Frme_zonas->edt_nombre->Text;
         qry_megazonas->Post();
         qry_megazonas->ApplyUpdates();
       }
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }
   delete Frme_zonas;
   delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::botones_onoff(int modo_z)
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

void __fastcall TForm_mantzona::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(dm->qry_maxidvnd->FieldByName("zona")->AsInteger);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::busca_ptvt(String ptvt_z)
{
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_zonas->Close();
   qry_zonas->ParamByName("zona")->AsString= FormatFloat("00", StrToIntDef(ptvt_z, 0));
   //qry_zonas->ParamByName("cia")->AsInteger = cia_z;
   qry_zonas->Open();
   if(!qry_zonas->IsEmpty()) {
     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::FormCreate(TObject *Sender)
{
  permis_z="N";
  permis_z=dm->busca_permision(MANTOZONAS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
    Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    Close();
  }
  qry_zonas->Close();
  //qry_zonas->ParamByName("cia")->AsInteger = cia_z;
  qry_zonas->Open();
  qry_megazonas->Close();
  qry_megazonas->ParamByName("cia")->AsInteger = cia_z;
  qry_megazonas->Open();

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantzona::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantzona::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = dbgrd_zonas->Name + ".xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    switch( SaveDialog->FilterIndex) {
      case 1: dbgrd_zonas->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
      case 2: dbgrd_zonas->SaveToXLS(SaveDialog->FileName, true); break;
      case 3: dbgrd_zonas->SaveToHTML(SaveDialog->FileName, true); break;
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::tbs_zonasShow(TObject *Sender)
{
  tipo_z = "ZONAS";
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::tbs_megazonasShow(TObject *Sender)
{
  tipo_z = "MEGAZONAS";
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantzona::agrega_megazonadetExecute(TObject *Sender)
{
  int idmegazona_z=0, idmegazonadet_z=0;
  String zona_z="", nombre_z, tit_z ="Zona";
  if(qry_megazonas->IsEmpty()) return;
  if(qry_zonas->IsEmpty()) return;
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrme_zonas *Frme_zonas;
  Frme_zonas = new TFrme_zonas (Dlg_datos);
  Dlg_datos->Caption = "Datos de la " + tit_z;
  Frme_zonas->Parent = Dlg_datos->Panel1;
  Frme_zonas->lbl_codigo->Caption = "Zona";
  TDBLookupComboBox *lkcmb_zonas = new TDBLookupComboBox (Frme_zonas);
  lkcmb_zonas->Parent = Frme_zonas;
  lkcmb_zonas->ListSource = dts_zonas;
  lkcmb_zonas->ListField = "nombre";
  lkcmb_zonas->KeyField = "nombre";
  lkcmb_zonas->Width = Frme_zonas->edt_nombre->Width;
  lkcmb_zonas->Left = Frme_zonas->edt_ptovta->Left;
  lkcmb_zonas->Top = Frme_zonas->edt_nombre->Top;
  delete Frme_zonas->edt_nombre;
  delete Frme_zonas->edt_ptovta;
  delete Frme_zonas->lbl_nombre;
  lkcmb_zonas->KeyValue=qry_zonas->FieldByName("nombre")->AsString;
  idmegazona_z = qry_megazonas->FieldByName("idmegazona")->AsInteger;
  if(Dlg_datos->ShowModal() == mrOk) {
     try {
       dm->manvehi->StartTransaction();
       if (tipo_z == "MEGAZONAS") {
         idmegazonadet_z = dm->busca_sigid(IDMEGAZONADETINV);
         zona_z = qry_zonas->FieldByName("zona")->AsString;
         nombre_z = qry_zonas->FieldByName("nombre")->AsString;
         qry_megazonasdet->Append();
         qry_megazonasdet->FieldByName("idmegazonadet")->AsInteger = idmegazonadet_z;
         qry_megazonasdet->FieldByName("idmegazona")->AsInteger = idmegazona_z;
         qry_megazonasdet->FieldByName("zona")->AsString = zona_z;
         qry_megazonasdet->FieldByName("nombre")->AsString = nombre_z;
         qry_megazonasdet->FieldByName("cia")->AsInteger = cia_z;
         qry_megazonasdet->Post();
         qry_megazonasdet->ApplyUpdates();
       }
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
  }
  delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::eliminar_megazonasdetExecute(
      TObject *Sender)
{
  int zona_z=0, idmegazona_z=0, idmegazonadet_z=0;
  String nombre_z, tit1_z, tit2_z;
  if(qry_megazonas->IsEmpty()) return;
  if(qry_megazonasdet->IsEmpty()) return;
  tit1_z = "Seguro de Quitar esta Zona de esta Megazona ?";
  tit2_z = "Eliminar relación de Zona Megazona";
  if(Application->MessageBox(tit1_z.c_str(), tit2_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_megazonasdet->Delete();
      qry_megazonasdet->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantzona::qry_megazonasAfterScroll(TDataSet *DataSet)
{
  int idmegazona_z;
  idmegazona_z = qry_megazonas->FieldByName("idmegazona")->AsInteger;
  qry_megazonasdet->Close();
  qry_megazonasdet->ParamByName("idmegazona")->AsInteger = idmegazona_z;
  qry_megazonasdet->ParamByName("cia")->AsInteger = cia_z;
  qry_megazonasdet->Open();

}
//---------------------------------------------------------------------------

