//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosfacma.h"
#include "Frme_dircli.h"
#include "dmod.h"
#include "situaciones.h"
#include "dialg_okcancel.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TFrame_datosfacma *Frame_datosfacma;
//---------------------------------------------------------------------------
__fastcall TFrame_datosfacma::TFrame_datosfacma(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
  cmb_intomer->ItemIndex = 0;
  cmb_mayomen->ItemIndex = 0;
  qry_mediospago->Close();
  qry_mediospago->ParamByName("ACTIVO")->AsInteger = TIPO_PAGO_ACTIVO;
  qry_mediospago->Open();
  qry_mediopago2->Close();
  qry_mediopago2->ParamByName("ACTIVO")->AsInteger = TIPO_PAGO_ACTIVO;
  qry_mediopago2->Open();
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosfacma::edt_mayorisExit(TObject *Sender)
{
  int ancho_z=0, alto_z=0;
  String mayoris_z;
  mayoris_z = edt_mayoris->Text.Trim();
  if(!busca_mayoris(mayoris_z)) {
    Tdlg_okcancel *Dlg_pidenombre;
    Dlg_pidenombre = new Tdlg_okcancel (this);
    TFrame_dircli *Frame_dircli = new TFrame_dircli (Dlg_pidenombre);
    ancho_z = Frame_dircli->Width + 20;
    alto_z = Frame_dircli->Height + Dlg_pidenombre->Panel2->Height + 80;
    Dlg_pidenombre->AutoSize = false;
    Dlg_pidenombre->Width = ancho_z;
    Dlg_pidenombre->Height = alto_z;
    Frame_dircli->Top = 0;
    Frame_dircli->Left= 0;
    Frame_dircli->Parent = Dlg_pidenombre->Panel1;
    Frame_dircli->Align = alClient;
    Frame_dircli->Visible = true;
    Dlg_pidenombre->Caption = "Seleccione el Cliente";
    Frame_dircli->selecciona_tipodato("MAYORIS", mayoris_z);
    if( Dlg_pidenombre->ShowModal() == mrOk) {
       mayoris_z = Frame_dircli->obten_resultado("MAYORIS");
       busca_mayoris(mayoris_z);
    }
    delete Frame_dircli;
    delete Dlg_pidenombre;
  }
}
//---------------------------------------------------------------------------

String  __fastcall TFrame_datosfacma::selecciona_tipo_fac(String modo_z, String tipo_z)
{
  int index_z = 0;
  String result_z = "";
  if(modo_z == "MAYOMEN") {
    if(tipo_z == "M") index_z = 1;
    if(tipo_z == "Y") index_z = 0;
    cmb_mayomen->ItemIndex = index_z;
    result_z = IntToStr(index_z);
  }
  if(modo_z == "INTOMERC") {
    if(tipo_z == "M") index_z = 0;
    if(tipo_z == "I") index_z = 1;
    if(tipo_z == "O") index_z = 2;
    cmb_intomer->ItemIndex = index_z;
    result_z = IntToStr(index_z);
  }
  if(modo_z == "SELECCIONA_MAYOMEN") {
    if(tipo_z.UpperCase() == "MAYOREO") result_z = "Y";
    if(tipo_z.UpperCase() == "MENUDEO") result_z = "M";
  }
  if(modo_z == "SELECCIONA_INTOMERC") {
    if(tipo_z.UpperCase() == "MERCANCÍA") result_z = "M";
    if(tipo_z.UpperCase() == "INTERESES NORMALES") result_z = "I";
    if(tipo_z.UpperCase() == "INTERESES MORATORIOS") result_z = "O";
  }
  return (result_z);
}

bool __fastcall TFrame_datosfacma::busca_mayoris(String mayoris_z)
{
  String direc_z;
  qry_mayoris->Close();
  qry_mayoris->ParamByName("mayoris")->AsString = mayoris_z;
  qry_mayoris->ParamByName("cia")->AsInteger = cia_z;
  qry_mayoris->Open();
  if(!qry_mayoris->IsEmpty()) {
    edt_mayoris->Text = qry_mayoris->FieldByName("codigo")->AsString;
    edt_nombrefac->Text = qry_mayoris->FieldByName("nombre")->AsString;
    direc_z = qry_mayoris->FieldByName("direc")->AsString;
    ciu_z = qry_mayoris->FieldByName("ciu")->AsString;
    mmo_direc->Text = direc_z + "\n" + ciu_z;
    edt_tipomay->Text = qry_mayoris->FieldByName("tipomay")->AsString;
    if(edt_tipomay->Text == "FILIAL") {
      edt_tipomay->Color = clYellow;
    } else {
      edt_tipomay->Color = edt_rfc->Color;
    }
  }
  return(!qry_mayoris->IsEmpty());
}
//---------------------------------------------------------------------------



void __fastcall TFrame_datosfacma::edt_seriefacExit(TObject *Sender)
{
   String serie_z;
   int numfac_z;
   serie_z = edt_seriefac->Text.Trim();
   if(modo_z == "ALTA") {
      dm->qry_maxidvnd->Close();
      dm->qry_maxidvnd->SQL->Clear();
      dm->qry_maxidvnd->SQL->Add("select max (num) as num from facturma where tipofac = :TIPOFAC and seriefac = :SERIE and cia = :CIA");
      dm->qry_maxidvnd->ParamByName("serie")->AsString    = serie_z;
      dm->qry_maxidvnd->ParamByName("tipofac")->AsInteger = entrapor_z;
      dm->qry_maxidvnd->ParamByName("cia")->AsInteger     = cia_z;
      dm->qry_maxidvnd->Open();
      if(!dm->qry_maxidvnd->IsEmpty()) numfac_z =dm->qry_maxidvnd->FieldByName("num")->AsInteger ;
      numfac_z++;
      edt_numfac->Value = numfac_z;
   }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosfacma::pide_direcExecute(TObject *Sender)
{
  int ancho_z=0, alto_z=0;
  String direc_z = "";
  if(direc_z.IsEmpty()) {
    Tdlg_okcancel *Dlg_pidenombre;
    Dlg_pidenombre = new Tdlg_okcancel (this);
    TFrame_dircli *Frame_dircli = new TFrame_dircli (Dlg_pidenombre);
    ancho_z = Frame_dircli->Width + 20;
    alto_z = Frame_dircli->Height + Dlg_pidenombre->Panel2->Height + 80;
    Dlg_pidenombre->AutoSize = false;
    Dlg_pidenombre->Width = ancho_z;
    Dlg_pidenombre->Height = alto_z;
    Frame_dircli->Top = 0;
    Frame_dircli->Left= 0;
    Frame_dircli->Parent = Dlg_pidenombre->Panel1;
    Frame_dircli->Align = alClient;
    Frame_dircli->Visible = true;
    Dlg_pidenombre->Caption = "Proporcione la dirección";
    Frame_dircli->selecciona_tipodato("DIREC", "");
    if( Dlg_pidenombre->ShowModal() == mrOk) {
       calles_z  = Frame_dircli->edt_dircli->Text.Trim();
       numpred_z = Frame_dircli->edt_dircli2->Text.Trim();
       colonia_z = Frame_dircli->edt_colonia->Text.Trim();
       codpost_z = Frame_dircli->edt_codpost->Text.Trim();
       ciu_z     = Frame_dircli->qry_poblac->FieldByName("nombre")->AsString;
       idpob_z   = Frame_dircli->qry_poblac->FieldByName("numero")->AsInteger;
       direc_z   = calles_z;
       direc_z  += " N." + numpred_z;
       direc_z  += " Col:" + colonia_z;
       direc_z  += " CP:" + codpost_z;
       mmo_direc->Text = direc_z + "\n" + ciu_z;
    }
    delete Frame_dircli;
    delete Dlg_pidenombre;
  }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosfacma::mmo_direcKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  pide_direcExecute(Sender);
}
//---------------------------------------------------------------------------


