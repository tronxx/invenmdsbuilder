//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_CapturaObsPed.h"
#include "dmod.h"
#include "Frme_nvaobsped.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
#pragma resource "*.dfm"
TForm_CapturaObsPed *Form_CapturaObsPed;
//---------------------------------------------------------------------------
void __fastcall CapturaObservaPedido(TForm *Padre, AnsiString sTipo, AnsiString sAlmac, int iNumero, int iCia, AnsiString sCodigo, AnsiString sPermi)
{
     try
    {
        Form_CapturaObsPed = new TForm_CapturaObsPed(Padre, sTipo, sAlmac, iNumero, iCia, sCodigo, sPermi);
        Form_CapturaObsPed->ShowModal();
    }
    catch(...)
    {
    }

}
//---------------------------------------------------------------------------
__fastcall TForm_CapturaObsPed::TForm_CapturaObsPed(TComponent* Owner, AnsiString sTipop, AnsiString sAlmacp, int iNumerop, int iCiap, AnsiString sCodigop, AnsiString sPermip)
    : TForm(Owner)
{
    iNumero_ = iNumerop;
    iCia_    = iCiap;
    sTipo_   = sTipop;
    sAlmac_  = sAlmacp;
    codigo_z = sCodigop;
    permis_z = sPermip;
    nuevo->Enabled    = false;
    if(permis_z == "T") nuevo->Enabled = true;
    modif->Enabled    = nuevo->Enabled;
    eliminar->Enabled = nuevo->Enabled;
    abierto_z = "N";
    if(sAlmac_.IsEmpty()) {
      if(sTipo_ == "P" || sTipo_ == "O" || sTipo_ == "T") abierto_z = "S";
    }
    qsObservPed->Close();
    hoy_z = dm->ahora();
    MostrarRenglones();
}
//---------------------------------------------------------------------------


void __fastcall TForm_CapturaObsPed::MostrarRenglones()
{
    qsObservPed->Close();
    qsObservPed->ParamByName("Numero")->AsInteger = iNumero_;
    qsObservPed->ParamByName("Almac" )->AsString  = sAlmac_;
    qsObservPed->ParamByName("Tipo"  )->AsString  = sTipo_;
    qsObservPed->ParamByName("codigo"  )->AsString  = codigo_z;
    qsObservPed->ParamByName("Cia"   )->AsInteger = iCia_;
    qsObservPed->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapturaObsPed::nuevoExecute(TObject *Sender)
{
  modifica_o_agrega("NUEVO");
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapturaObsPed::modifExecute(TObject *Sender)
{

   int ancho_z, alto_z,sig_z, dias_z;
   String observ_z;
   TDateTime fecha_z;
   if(qsObservPed->State == dsInactive) return;
   if(qsObservPed->IsEmpty() ) return;
   if(abierto_z != "S") {
     fecha_z = qsObservPed->FieldByName("fecha")->AsDateTime;
     dias_z = hoy_z - fecha_z;
     if(dias_z > 10) {
       Application->MessageBox("No puede modificar observaciones con mas de 10 días", "Antiguedad Protegida", MB_ICONEXCLAMATION);
       return;
     }
   }
   modifica_o_agrega("MODIF");
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapturaObsPed::modifica_o_agrega(String modo_z)
{

   int ancho_z, alto_z,sig_z;
   String observ_z;
   TDateTime fecha_z;
   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_nvaobsped *Frame_nvaobsped;
   Frame_nvaobsped = new TFrame_nvaobsped (Dlg_analipol);
   ancho_z = Frame_nvaobsped->Width + 20;
   alto_z = Frame_nvaobsped->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_nvaobsped->Parent = Dlg_analipol->Panel1;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   if ( modo_z == "NUEVO") {
     Dlg_analipol->Caption = "Nueva Observacion";
     Frame_nvaobsped->dtFecha->Date = dm->ahora();
     sig_z = 0;

   }
   if (modo_z == "MODIF") {
     Dlg_analipol->Caption = "Modifica Observacion";
     Frame_nvaobsped->edtObserva->Text = qsObservPed->FieldByName("observs")->AsString;
     Frame_nvaobsped->dtFecha->Date = qsObservPed->FieldByName("fecha")->AsDateTime;
     sig_z = qsObservPed->FieldByName("conse")->AsInteger;
   }
   if( Dlg_analipol->ShowModal() == mrOk) {
     observ_z = Frame_nvaobsped->edtObserva->Text;
     fecha_z = Frame_nvaobsped->dtFecha->Date;
     agrega_obs(modo_z, observ_z, fecha_z, sig_z);

   }
   delete Frame_nvaobsped;
   delete Dlg_analipol;


}
//---------------------------------------------------------------------------

void __fastcall TForm_CapturaObsPed::agrega_obs(String modo_z, String observs_z, double fecha_z, int consec_z)
{
   if ( modo_z == "NUEVO") {
     qsMaxSec->Close();
     qsMaxSec->ParamByName("Numero")->AsInteger = iNumero_;
     qsMaxSec->ParamByName("Tipo"  )->AsString  = sTipo_;
     qsMaxSec->ParamByName("Almac" )->AsString  = sAlmac_;
     qsMaxSec->ParamByName("codigo")->AsString  = codigo_z;
     qsMaxSec->ParamByName("cia"   )->AsInteger = iCia_;
     qsMaxSec->Open();
     consec_z = 1;
     if (!qsMaxSec->IsEmpty()) {
       consec_z = qsMaxSec->FieldByName("Ultimo")->AsInteger + 1;
     }

     qsObservPed->Append();
     qsObservPed->FieldByName("tipo")->AsString = sTipo_;
     qsObservPed->FieldByName("alm")->AsString = sAlmac_;
     qsObservPed->FieldByName("numero")->AsInteger = iNumero_;
     qsObservPed->FieldByName("cia")->AsInteger = iCia_;
     qsObservPed->FieldByName("codigo")->AsString = codigo_z;
   }
   if ( modo_z == "MODIF") {
     qsObservPed->Edit();
   }
   qsObservPed->FieldByName("fecha")->AsDateTime = fecha_z ;
   qsObservPed->FieldByName("conse")->AsInteger = consec_z;
   qsObservPed->FieldByName("observs")->AsString = observs_z;
   qsObservPed->Post();
   try {
     dm->manvehi->StartTransaction();
     qsObservPed->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapturaObsPed::listarExecute(TObject *Sender)
{

    MostrarRenglones();
            
}
//---------------------------------------------------------------------------


void __fastcall TForm_CapturaObsPed::eliminarExecute(TObject *Sender)
{
  TDateTime fecha_z;
  int dias_z;
  String campos_z;
  if(qsObservPed->State == dsInactive) return;
  if(qsObservPed->IsEmpty() ) return;
  if(abierto_z != "S") {
    fecha_z = qsObservPed->FieldByName("fecha")->AsDateTime;
    dias_z = hoy_z - fecha_z;
    if(dias_z > 10) {
       Application->MessageBox("No puede modificar observaciones con mas de 10 días", "Antiguedad Protegida", MB_ICONEXCLAMATION);
       return;
    }
  }

  if(Application->MessageBox("Esta Seguro de Eliminar esta Observacion ?", "Eliminar Chofer", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      // campos_z = qsObservPed->FieldByName("TIPO")->AsString;
      // campos_z +=  " - " +qsObservPed->FieldByName("ALM")->AsString;
      // campos_z +=  " - " +qsObservPed->FieldByName("NUMERO")->AsString;
      // campos_z +=  " - " +qsObservPed->FieldByName("FECHA")->AsString;
      // campos_z +=  " - " +qsObservPed->FieldByName("CONSE")->AsString;
      // Application->MessageBox(campos_z.c_str(), "Campos:", MB_ICONEXCLAMATION);

      dm->manvehi->StartTransaction();
      qsObservPed->Delete();
      qsObservPed->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_CapturaObsPed::dbgrdRengCustomDraw(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxDBTreeListColumn *AColumn, const AnsiString AText, TFont *AFont,
      TColor &AColor, bool ASelected, bool AFocused, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------

void __fastcall TForm_CapturaObsPed::salirExecute(TObject *Sender)
{
  this->Close();
}
//---------------------------------------------------------------------------


void __fastcall TForm_CapturaObsPed::qsObservPedAfterScroll(
      TDataSet *DataSet)
{
   TDateTime fecha_z;
   int dias_z=0;
   if (nuevo->Enabled && abierto_z != "S") {
     fecha_z = qsObservPed->FieldByName("fecha")->AsDateTime;
     dias_z = hoy_z - fecha_z;
     if(dias_z > 10) {
       modif->Enabled = false;
     } else {
       modif->Enabled = nuevo->Enabled;
     }
     eliminar->Enabled = modif->Enabled;
   }

}
//---------------------------------------------------------------------------

void __fastcall TForm_CapturaObsPed::dbgrdRengKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if( Key == VK_DELETE) eliminarExecute(this);
  if( Key == VK_INSERT) nuevoExecute(this);
  if( Key == VK_F2)     modifExecute(this);

}
//---------------------------------------------------------------------------

