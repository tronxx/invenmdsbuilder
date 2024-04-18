//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosinternet.h"
#include "dmod.h"
#include "numapal.h"
#include "dialg_okcancel.h"
#include "situaciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
TFrame_datosinternet *Frame_datosinternet;
//---------------------------------------------------------------------------
__fastcall TFrame_datosinternet::TFrame_datosinternet(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosinternet::inicializa()
{
   qry_relinv->Close();
   qry_relinv->ParamByName("codigo")->AsString = codigo_z;
   qry_relinv->ParamByName("cia")->AsInteger= cia_z;
   qry_relinv->ParamByName("idrel")->AsInteger= REL_INVEN_GRUPOINTERNET;
   qry_relinv->Open();
   if(qry_relinv->IsEmpty()) {
     qry_invhist->Close();
     qry_invhist->ParamByName("codigo")->AsString = codigo_z;
     qry_invhist->ParamByName("cia")->AsInteger= cia_z;
     qry_invhist->Open();
     idart_z = qry_invhist->FieldByName("idart")->AsInteger;
   } else {
     idgrupo_z = qry_relinv->FieldByName("idgrupo")->AsInteger;
     idart_z = qry_relinv->FieldByName("idart")->AsInteger;
   }

   qry_grupointer->Close();
   qry_grupointer->ParamByName("idgrupo")->AsInteger= idgrupo_z;
   qry_grupointer->Open();
   edt_titulo->Text = "";
   mmo_descripcion->Text = "";
   qry_titulo->Close();
   qry_titulo->ParamByName("codigo")->AsString = codigo_z;
   qry_titulo->ParamByName("tipotitulo")->AsString = "T";
   qry_titulo->ParamByName("tipodescri")->AsString = "D";
   qry_titulo->ParamByName("cia")->AsString = cia_z;
   qry_titulo->Open();
   mmo_descripcion->Text = "";
   for (qry_titulo->First(); !qry_titulo->Eof; qry_titulo->Next()) {
     if(qry_titulo->FieldByName("tipo")->AsString == "T") {
       edt_titulo->Text = qry_titulo->FieldByName("observs")->AsString;
     } else {
       mmo_descripcion->Lines->Append(
         qry_titulo->FieldByName("observs")->AsString
       );
     }
   }

}
//---------------------------------------------------------------------------




void __fastcall TFrame_datosinternet::cambiar_grupoExecute(TObject *Sender)
{
  int ancho_z, alto_z;
  Tdlg_okcancel *Dlg_analipol;
  TdxDBGrid *dbgrd_grupos;
  TLocateOptions Opts;
  Opts.Clear();
  String grupo_z;
  TStringList *campos_z = new TStringList();
  TStringList *titulos_z = new TStringList();
  TdxDBGrid *dbgrd_busqueda = new TdxDBGrid (this);
  TQuery *qry_busqueda = new TQuery(this);
  TDataSource *dts_busqueda;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  ancho_z = mmo_descripcion->Width;
  alto_z = mmo_descripcion->Height;
  dbgrd_busqueda = new TdxDBGrid (Dlg_analipol);

  qry_busqueda = new TQuery(Dlg_analipol);
  dts_busqueda = new TDataSource (Dlg_analipol);
  dts_busqueda->DataSet = qry_busqueda;
  dbgrd_busqueda->KeyField = "idgrupo";
  dbgrd_busqueda->DataSource = dts_busqueda;
  dbgrd_busqueda->Parent = Dlg_analipol->Panel1;
  dbgrd_busqueda->OptionsView << edgoAutoWidth;
  dbgrd_busqueda->OptionsView << edgoRowSelect;
  dbgrd_busqueda->OptionsBehavior << edgoAutoSearch;
  alto_z = mmo_descripcion->Height + 20;
  ancho_z = mmo_descripcion->Width + 20;
  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;


  grupo_z = qry_grupointer->FieldByName("codigo")->AsString;
  qry_busqueda->DatabaseName = qry_grupointer->DatabaseName;
  qry_busqueda->SQL->Text = "select * from inv_gruposinternet where cia = :CIA order by codigo";
  qry_busqueda->ParamByName("cia")->AsInteger = cia_z;
  qry_busqueda->Open();

  dbgrd_busqueda->Visible = true;
  dbgrd_busqueda->Align = alClient;
  campos_z->Add("codigo"); titulos_z->Add("Codigo");
  campos_z->Add("descri"); titulos_z->Add("Descripcion");
  agrega_campos(campos_z, titulos_z, dbgrd_busqueda);
  qry_busqueda->Locate("codigo", grupo_z, Opts);

  Dlg_analipol->Caption = "Seleccione el Grupo de Internet";
  if( Dlg_analipol->ShowModal() == mrOk) {
    grupo_z =   qry_busqueda->FieldByName("codigo")->AsString;
    idgrupo_z =   qry_busqueda->FieldByName("idgrupo")->AsInteger;
    qry_grupointer->Close();
    qry_grupointer->ParamByName("idgrupo")->AsInteger= idgrupo_z;
    qry_grupointer->Open();
  }
  delete Dlg_analipol;

}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosinternet::agrega_campos(
TStringList *campos_z, TStringList *titulos_z,
TdxDBGrid *dbgrd_busqueda)
{
  for(int ii_z = 0; ii_z < campos_z->Count; ii_z++) {
    TdxDBGridMaskColumn *column;
    column = new TdxDBGridMaskColumn (this);
    column->ATreeList = dbgrd_busqueda;
    column->FieldName = campos_z->Strings[ii_z];
    column->Caption = titulos_z->Strings[ii_z];
  }
}
//---------------------------------------------------------------------------


void __fastcall TFrame_datosinternet::grabar_datosinternetExecute(
      TObject *Sender)
{
  graba_datos_internet();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosinternet::graba_datos_internet()
{
  int idrelinv_z = 0, ii_z=0, numobs_z=0;
  String tipoobs_z = "", obs_z = "";
  numobs_z = 0;

  if (qry_relinv->IsEmpty()) {
    qry_relinv->Append();
    idrelinv_z = dm->busca_sigid(IDRELINV);
    qry_relinv->FieldByName("idrelinv")->AsInteger = idrelinv_z;
    qry_relinv->FieldByName("idart")->AsInteger = idart_z;
    qry_relinv->FieldByName("idrel")->AsInteger = REL_INVEN_GRUPOINTERNET;
    qry_relinv->FieldByName("conse")->AsInteger = 0;
  } else {
    qry_relinv->Edit();
  }
  qry_relinv->FieldByName("iddato")->AsInteger = idgrupo_z;
  qry_relinv->Post();
  for(qry_titulo->First(); !qry_titulo->Eof; qry_titulo->First()) {
    qry_titulo->Delete();
  }
  numobs_z = mmo_descripcion->Lines->Count + 1;
  for ( ii_z = 0; ii_z <= numobs_z; ii_z++) {
    if(ii_z == numobs_z) {
      tipoobs_z = "T";
      obs_z = edt_titulo->Text.Trim();
    } else {
      tipoobs_z = "D";
      obs_z = mmo_descripcion->Lines->Strings[ii_z];
    }
    qry_titulo->Append();
    qry_titulo->FieldByName("codigo")->AsString = codigo_z;
    qry_titulo->FieldByName("alm")->AsString = "";
    qry_titulo->FieldByName("numero")->AsInteger = 0;
    qry_titulo->FieldByName("fecha")->AsDateTime = dm->ahora();
    qry_titulo->FieldByName("tipo")->AsString= tipoobs_z;
    qry_titulo->FieldByName("observs")->AsString= obs_z;
    qry_titulo->FieldByName("cia")->AsInteger = cia_z;
    qry_titulo->FieldByName("conse")->AsInteger = ii_z;
    qry_titulo->Post();
  }
  try {
    dm->manvehi->StartTransaction();
    if(qry_titulo->UpdatesPending) qry_titulo->ApplyUpdates();
    qry_relinv->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E)
  {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

