//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantproy.h"
#include "numapal.h"
#include "situaciones.h"
#include "dmod.h"
#include "imprigra.h"
#include "math.h"
#include "Frme_datosmantproy.h"
#include "Frme_datosmantsubproy.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"
TForm_mantproy *Form_mantproy;
//---------------------------------------------------------------------------
__fastcall TForm_mantproy::TForm_mantproy(TComponent* Owner)
        : TForm(Owner)
{
  qry_zonas->Close();
  qry_zonas->Open();
  cia_z = dm->cia_z;
  lkcmb_ptovta->KeyValue = qry_zonas->FieldByName("zona")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantproy::qry_zonasAfterScroll(TDataSet *DataSet)
{

  String zona_z;
  zona_z = qry_zonas->FieldByName("zona")->AsString;
  qry_proycom->Close();
  qry_proycom->ParamByName("zona")->AsString = zona_z;
  qry_proycom->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::qry_proycomAfterScroll(TDataSet *DataSet)
{

  String zonapy_z,subzonpy_z;
  zonapy_z = qry_proycom->FieldByName("zona")->AsString;
  subzonpy_z = qry_proycom->FieldByName("subzona")->AsString;

  qry_subproycom->Close();
  qry_subproycom->ParamByName("zona")->AsString = zonapy_z ;
  qry_subproycom->ParamByName("subzon")->AsString = subzonpy_z;
  qry_subproycom->ParamByName("cia")->AsInteger = cia_z;
  qry_subproycom->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::nuevoExecute(TObject *Sender)
{
  alta_proy(NUEVO);
}

void __fastcall TForm_mantproy::alta_proy(int modo_z)
{

   int ancho_z, alto_z;
   String zona_z,subzona_z,descri_z,zonapy_z;
   double porcon_z,porcrd_z,porfon_z,porcel_z,porime_z, porofert_z;

   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantproy *Frame_datosmantproy;
   Frame_datosmantproy = new TFrame_datosmantproy (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantproy->Width + 40;
   alto_z = Frame_datosmantproy->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantproy->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z ;
   Dlg_mantgpoinv->Height = alto_z ;
   Dlg_mantgpoinv->Caption = "Agregar Proyeccion de Venta";
   Dlg_mantgpoinv->Position = poScreenCenter;
   zonapy_z =  qry_zonas->FieldByName("zona")->AsString;
   Frame_datosmantproy->lkcmb_ptovta->KeyValue = zonapy_z;
   if(modo_z == MODIF) {
      Frame_datosmantproy->lkcmb_ptovta->KeyValue = qry_proycom->FieldByName("zona")->AsString;
      Frame_datosmantproy->lkcmb_ptovta->Enabled = false;
      Frame_datosmantproy->edt_subzon->Text = qry_proycom->FieldByName("subzona")->AsString;
      Frame_datosmantproy->edt_subzon->Enabled = false;
      Frame_datosmantproy->edt_nombre->Text = qry_proycom->FieldByName("descri")->AsString;
      Frame_datosmantproy->edt_conta->Value = qry_proycom->FieldByName("porcon")->AsFloat;
      Frame_datosmantproy->edt_crd->Value = qry_proycom->FieldByName("porcrd")->AsFloat;
      Frame_datosmantproy->edt_fona->Value = qry_proycom->FieldByName("porfon")->AsFloat;
      Frame_datosmantproy->edt_fide->Value = qry_proycom->FieldByName("porcel")->AsFloat;
      Frame_datosmantproy->edt_imevi->Value = qry_proycom->FieldByName("porime")->AsFloat;
      Frame_datosmantproy->edt_oferta->Value = qry_proycom->FieldByName("porofert")->AsFloat;
   }
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {

      zona_z = Frame_datosmantproy->lkcmb_ptovta->Text.Trim();
      subzona_z = Frame_datosmantproy->edt_subzon->Text.Trim();
      descri_z = Frame_datosmantproy->edt_nombre->Text.Trim();
      porcon_z = Frame_datosmantproy->edt_conta->Value;
      porcrd_z = Frame_datosmantproy->edt_crd->Value;
      porfon_z = Frame_datosmantproy->edt_fona->Value;
      porcel_z = Frame_datosmantproy->edt_fide->Value;
      porime_z = Frame_datosmantproy->edt_imevi->Value;
      porofert_z = Frame_datosmantproy->edt_oferta->Value;

      if(modo_z == NUEVO) {
        qry_proycom->Append();
        qry_proycom->FieldByName("zona")->AsString = zona_z;
        qry_proycom->FieldByName("suboglo")->AsString = "S";
        qry_proycom->FieldByName("subzona")->AsString = subzona_z;
        qry_proycom->FieldByName("cia")->AsInteger = cia_z;
      }
      if(modo_z == MODIF) {
        qry_proycom->Edit();
      }
      qry_proycom->FieldByName("descri")->AsString = descri_z;
      qry_proycom->FieldByName("porcon")->AsFloat= porcon_z;
      qry_proycom->FieldByName("porcrd")->AsFloat= porcrd_z;
      qry_proycom->FieldByName("porfon")->AsFloat= porfon_z;
      qry_proycom->FieldByName("porcel")->AsFloat= porcel_z;
      qry_proycom->FieldByName("porime")->AsFloat= porime_z;
      qry_proycom->FieldByName("porofert")->AsFloat= porofert_z;
      qry_proycom->Post();

      try
      {
         dm->manvehi->StartTransaction();
         qry_proycom->ApplyUpdates();
         dm->manvehi->Commit();
      }
      catch(...)
      {
         dm->manvehi->Rollback();
         Application->MessageBox("No Fue Posible Agregar Esta Suc.", "Error", MB_OK | MB_ICONERROR);
      }
   }
   delete Frame_datosmantproy;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::borraExecute(TObject *Sender)
{

if (qry_proycom->IsEmpty()) return;
 if(Application->MessageBox("Esta Seguro de Eliminar esta Suc.?", "Eliminar Tabla", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    // Elimino los elementos hijos
    for(qry_subproycom->First(); !qry_subproycom->Eof; qry_subproycom->First())
      qry_subproycom->Delete();
    qry_proycom->Delete();

    try {
      dm->manvehi->StartTransaction();
      qry_proycom->ApplyUpdates();
      qry_subproycom->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E){
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude Eliminar el dato:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::modificaExecute(TObject *Sender)
{
  if (qry_proycom->IsEmpty()) return;
  alta_proy(MODIF);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::nuevosubExecute(TObject *Sender)
{
        alta_subproy(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::alta_subproy(int modo_z)
{
   int idtipo_z, ancho_z, alto_z;
   String tipo_z,subzonaacu_z,ptva_z,zona_z,subzona_z;

   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datosmantsubproy *Frame_datosmantsubproy;
   Frame_datosmantsubproy = new TFrame_datosmantsubproy (Dlg_mantgpoinv);
   ancho_z = Frame_datosmantsubproy->Width + 40;
   alto_z = Frame_datosmantsubproy->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datosmantsubproy->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z ;
   Dlg_mantgpoinv->Height = alto_z ;
   Dlg_mantgpoinv->Caption = "Agregar SubProyeccion de Venta";
   Dlg_mantgpoinv->Position = poScreenCenter;

   zona_z    = qry_proycom->FieldByName("zona")->AsString;
   subzona_z = qry_proycom->FieldByName("subzona")->AsString;
   Frame_datosmantsubproy->edt_acu->Text = zona_z ;
   if(modo_z == MODIF) {
      tipo_z = qry_subproycom->FieldByName("tipo")->AsString;
      idtipo_z = Frame_datosmantsubproy->busca_idtipo(tipo_z);

     Frame_datosmantsubproy->cmb_tipo->ItemIndex = idtipo_z;
     Frame_datosmantsubproy->edt_acu->Text  = qry_subproycom->FieldByName("zonaacu")->AsString;
     Frame_datosmantsubproy->edt_ptv->Text = qry_subproycom->FieldByName("ptvta")->AsString;
   }

   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      tipo_z = Frame_datosmantsubproy->cmb_tipo->Text.SubString(1,1);
      subzonaacu_z = Frame_datosmantsubproy->edt_acu->Text;
      ptva_z = Frame_datosmantsubproy->edt_ptv->Text;

      if(modo_z == NUEVO) {
        qry_subproycom->Append();
      }
      if(modo_z == MODIF) {
        qry_subproycom->Edit();
      }
      qry_subproycom->FieldByName("zona")->AsString = zona_z;
      qry_subproycom->FieldByName("subzona")->AsString = subzona_z;
      qry_subproycom->FieldByName("tipo")->AsString = tipo_z;
      qry_subproycom->FieldByName("zonaacu")->AsString = subzonaacu_z;
      qry_subproycom->FieldByName("ptvta")->AsString = ptva_z;
      qry_subproycom->FieldByName("cia")->AsString = cia_z;
      qry_subproycom->Post();

      try
      {
         dm->manvehi->StartTransaction();
         qry_subproycom->ApplyUpdates();
         dm->manvehi->Commit();
      }
      catch(...)
      {
         dm->manvehi->Rollback();
         Application->MessageBox("No Fue Posible Agregar Esta Suc.", "Error", MB_OK | MB_ICONERROR);
      }



   }
   delete Frame_datosmantsubproy;
   delete Dlg_mantgpoinv;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::BorrsubExecute(TObject *Sender)
{
  if ( qry_subproycom->IsEmpty()) return;

  if(Application->MessageBox("Esta Seguro de Eliminar esta Sub ptvta.?", "Eliminar Tabla", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_subproycom->Delete();
      qry_subproycom->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E){
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude Eliminar el dato:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::modifsubExecute(TObject *Sender)
{
  if ( qry_subproycom->IsEmpty()) return;
  alta_subproy(MODIF);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantproy::dxDBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevosubExecute (Sender);
  if(Key == VK_F2)     modifsubExecute (Sender);
  if(Key == VK_DELETE) BorrsubExecute  (Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::dbgrd_polizasKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute    (Sender);
  if(Key == VK_F2)     modificaExecute (Sender);
  if(Key == VK_DELETE) borraExecute    (Sender);

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantproy::FormClose(TObject *Sender,
      TCloseAction &Action)
{
 Action = caFree;        
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantproy::FormCreate(TObject *Sender)
{
  permis_z=dm->busca_permision(INV_PERMI_CAP_PROYEC_COSTOS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

}
//---------------------------------------------------------------------------

