//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dialg_datosrenagenda.h"
#include "dialg_busartic.h"
#include <inifiles.hpp>
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
#include "dmod.h"
Tdlg_datosrenagenda *dlg_datosrenagenda;
//---------------------------------------------------------------------------
__fastcall Tdlg_datosrenagenda::Tdlg_datosrenagenda(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosrenagenda::FormCreate(TObject *Sender)
{
  TIniFile *ini;
  String  ubica_z, config_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z );
  ubica_z =  ini->ReadString( "Agenda_Embaques", "Ubica", "EMB" );
  delete ini;
  cia_z = dm->cia_z;
  date_fecha->Date = dm->ahora();
  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_almacen->Open();
  lkcmb_ubica->KeyValue = ubica_z;

  qry_ptovta->Close();
  qry_ptovta->ParamByName("cia")->AsInteger = cia_z;
  qry_ptovta->Open();
  if (!qry_ptovta->IsEmpty()) {
    lkcmb_ptovta->KeyValue = qry_ptovta->FieldByName("clave")->AsString;
  }
  qry_chofer->Close();
  qry_chofer->Open();
  if (!qry_chofer->IsEmpty()) {
    lkcmb_chofer->KeyValue = qry_chofer->FieldByName("clave")->AsString;
  }
  qry_poblacs->Close();
  qry_poblacs->Open();
  if (!qry_poblacs->IsEmpty()) {
    lkcmb_poblac->KeyValue = qry_poblacs->FieldByName("nombre")->AsString;
  }
  qry_renagendaart->Close();
  qry_renagendaart->ParamByName("idrenagenda")->AsInteger = -1;
  qry_renagendaart->Open();
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosrenagenda::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  String codigo_z;
  codigo_z = edt_codigo->Text;
  if( (Key == VK_RETURN && codigo_z != "AUXILIAR")) {
    codigo_z = edt_codigo->Text;
    qry_inven->Close();
    qry_inven->ParamByName("codigo")->AsString = codigo_z;
    qry_inven->ParamByName("cia")->AsInteger = cia_z;
    qry_inven->Open();
    if(qry_inven->IsEmpty()) {
      // No Existe el c�digo, habr� que buscarlo
      Tdlg_busartic *dlg_busartic = new Tdlg_busartic (this);
      dlg_busartic->busca_artic(codigo_z + "%", "-1");
      if(dlg_busartic->ShowModal() == mrOk) {
        qry_inven->Close();
        qry_inven->ParamByName("codigo")->AsString = dlg_busartic->qry_inven->FieldByName("codigo")->AsString;
        qry_inven->ParamByName("cia")->AsInteger = cia_z;
        qry_inven->Open();
        if( qry_inven->IsEmpty()) { delete dlg_busartic; return; }
      } else {
        delete dlg_busartic; return;
      }
      edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
      edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
      //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
    } else {
      edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
      edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosrenagenda::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  TIniFile *ini;
  String  ubica_z, config_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z );
  ini->WriteString( "Agenda_Embaques", "Ubica", lkcmb_ubica->KeyValue );
  delete ini;
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosrenagenda::agrega_renExecute(TObject *Sender)
{
  qry_renagendaart->Append();
  qry_renagendaart->FieldByName("idrenagendaart")->AsInteger = qry_renagendaart->RecordCount * -1 -1;
  qry_renagendaart->FieldByName("codigo")->AsString = edt_codigo->Text;
  qry_renagendaart->FieldByName("descri")->AsString = edt_descri->Text;
  qry_renagendaart->Post();
  edt_codigo->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosrenagenda::borra_articuloExecute(TObject *Sender)
{
  if(qry_renagendaart->IsEmpty()) return;
  qry_renagendaart->Delete();
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_datosrenagenda::dbgrd_invenKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_DELETE) borra_articuloExecute(Sender);
}
//---------------------------------------------------------------------------


