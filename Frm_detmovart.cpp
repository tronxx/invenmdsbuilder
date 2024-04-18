//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_detmovart.h"
#include "dmod.h"
#include "situaciones.h"
#include "Frme_datospedimento.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"

const int BTN_ANTMOV    = 1;
const int BTN_SIGMOV    = 2;
const int BTN_ORIMOV    = 3;
const int BTN_DESTMOV   = 4;

const int VTA_CONTADO   = 1;
const int VTA_CREDITO   = 2;


TForm_detmovart *Form_detmovart;
//---------------------------------------------------------------------------
__fastcall TForm_detmovart::TForm_detmovart(TComponent* Owner)
  : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_detmovart::qry_movartCalcFields(TDataSet *DataSet)
{
  String proveedor_z, entrapor_z, salepor_z, statussal_z, sqlvtacrd_z,
  comprador_z, vienede_z, vahacia_z, almenv_z, almrec_z, poblac_z;
  int folent_z;
  TDateTime fechasal_z = NULL;
  qry_conceps->Close();
  qry_conceps->ParamByName("idconcepto")->AsInteger = qry_movart->FieldByName("nompro")->AsInteger;
  qry_conceps->Open();
  if(!qry_conceps->IsEmpty()) proveedor_z = qry_conceps->FieldByName("concepto")->AsString;
  proveedor_z += proveedor_z.StringOfChar(' ', 30 - proveedor_z.Length());
  if(qry_movart->FieldByName("folviene")->AsInteger) {
    vienede_z = " "+ qry_movart->FieldByName("vienede")->AsString +
       " " + qry_movart->FieldByName("folviene")->AsString;
    if(proveedor_z.Length() > (30 - vienede_z.Length()))
      proveedor_z = proveedor_z.SubString(1, 30 - vienede_z.Length());
    proveedor_z += vienede_z;
    qry_movart->FieldByName("almenv")->AsString = qry_movart->FieldByName("vienede")->AsString;
  }
  qry_tpmov->Close();
  qry_tpmov->ParamByName("tipomov")->AsInteger = qry_movart->FieldByName("entrapor")->AsInteger;
  qry_tpmov->ParamByName("cia")->AsInteger = cia_z;
  qry_tpmov->Open();
  if(!qry_tpmov->IsEmpty())
    qry_movart->FieldByName("strentrapor")->AsString = qry_tpmov->FieldByName("descri")->AsString;

  if(qry_movart->FieldByName("salio")->AsString == "S") {
    fechasal_z = qry_movart->FieldByName("fechasal")->AsDateTime;
//      TDateTime(
//        qry_movart->FieldByName("anusal")->AsInteger,
//        qry_movart->FieldByName("messal")->AsInteger,
//        qry_movart->FieldByName("diasal")->AsInteger
//      );
    qry_conceps->Close();
    qry_conceps->ParamByName("idconcepto")->AsInteger = qry_movart->FieldByName("compro")->AsInteger;
    qry_conceps->Open();
    if(!qry_conceps->IsEmpty()) comprador_z = qry_conceps->FieldByName("concepto")->AsString;
    comprador_z += comprador_z.StringOfChar(' ', 30 - comprador_z.Length());
    if(qry_movart->FieldByName("folrec")->AsInteger) {
      vahacia_z = " "+ qry_movart->FieldByName("vahacia")->AsString +
         " " + qry_movart->FieldByName("folrec")->AsString;
      if(comprador_z.Length() > (30 - vahacia_z.Length()))
        comprador_z = comprador_z.SubString(1, 30 - vahacia_z.Length());
      comprador_z += vahacia_z;
      qry_movart->FieldByName("almrec")->AsString = qry_movart->FieldByName("vahacia")->AsString;
    }
    qry_poblacs->Close();
    qry_poblacs->ParamByName("pueblo")->AsInteger = qry_movart->FieldByName("pueblo")->AsInteger;
    qry_poblacs->Open();
    if(!qry_poblacs->IsEmpty())
      qry_movart->FieldByName("poblacion")->AsString = qry_poblacs->FieldByName("nombre")->AsString;
    qry_tpmov->Close();
    qry_tpmov->ParamByName("tipomov")->AsInteger = qry_movart->FieldByName("salepor")->AsInteger;
    qry_tpmov->ParamByName("cia")->AsInteger = cia_z;
    qry_tpmov->Open();
    if(!qry_tpmov->IsEmpty())
      qry_movart->FieldByName("strsalepor")->AsString = qry_tpmov->FieldByName("descri")->AsString;

    qry_movart->FieldByName("comprador")->AsString = comprador_z;
    qry_movart->FieldByName("fechsalida")->AsDateTime = fechasal_z;
    qry_movart->FieldByName("statussal")->AsString = qry_movart->FieldByName("modsal")->AsString;
    if(qry_movart->FieldByName("salepor")->AsInteger == EST_X_VTA_TRAD) {
      sqlvtacrd_z = "select folent from renentra where alm = :ALM ";
      sqlvtacrd_z += " and tipo = :TIPOSAL and numero = :NUMSAL ";
      sqlvtacrd_z += " and codinv = :CODIGO and folsal = :FOLIO and cia=:CIA";
      dm->qry_iddato->Close();
      dm->qry_iddato->SQL->Clear();
      dm->qry_iddato->SQL->Text = sqlvtacrd_z;
      dm->qry_iddato->ParamByName("alm")->AsString = qry_movart->FieldByName("almac")->AsString;
      dm->qry_iddato->ParamByName("codigo")->AsString = qry_movart->FieldByName("codigo")->AsString;
      dm->qry_iddato->ParamByName("tiposal")->AsString = "V";
      dm->qry_iddato->ParamByName("numsal")->AsInteger = qry_movart->FieldByName("nsalida")->AsInteger;
      dm->qry_iddato->ParamByName("folio")->AsInteger = qry_movart->FieldByName("folio")->AsInteger;
      dm->qry_iddato->ParamByName("cia")->AsInteger = qry_movart->FieldByName("cia")->AsInteger;
      dm->qry_iddato->Open();
      if (!dm->qry_iddato->IsEmpty()) {
        folent_z = dm->qry_iddato->FieldByName("folent")->AsInteger;
        qry_credocon->Close();
        qry_credocon->ParamByName("IDCREDCON")->AsInteger = folent_z;
        qry_credocon->Open();
        qry_movart->FieldByName("credocon")->AsString = qry_credocon->FieldByName("descri")->AsString;
      }
    }
  }
  qry_movart->FieldByName("proveedor")->AsString = proveedor_z;
  qry_pedimen->Close();
  qry_pedimen->ParamByName("codigo")->AsString = qry_movart->FieldByName("codigo")->AsString;
  qry_pedimen->ParamByName("serie")->AsString = qry_movart->FieldByName("Serie")->AsString;
  qry_pedimen->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm_detmovart::btn_cierraClick(TObject *Sender)
{
  Close();
}
//---------------------------------------------------------------------------
void __fastcall TForm_detmovart::btn_antermovClick(TObject *Sender)
{
  String antalm_z, antcod_z, alm_z;
  int antfolio_z, folio_z, btn_z;
  antcod_z = qry_movart->FieldByName("codigo")->AsString;
  antalm_z = qry_movart->FieldByName("almac")->AsString;
  antfolio_z = qry_movart->FieldByName("folio")->AsInteger;
  btn_z = ((TBitBtn*)(Sender))->Tag;
  switch( btn_z) {
    case BTN_ANTMOV:
      alm_z = antalm_z; folio_z = antfolio_z - 1;
      break;
    case BTN_SIGMOV:
      alm_z = antalm_z; folio_z = antfolio_z + 1;
      break;
    case BTN_ORIMOV:
      alm_z = qry_movart->FieldByName("vienede")->AsString;
      folio_z = qry_movart->FieldByName("folviene")->AsInteger;
      break;
    case BTN_DESTMOV:
      alm_z = qry_movart->FieldByName("vahacia")->AsString;
      folio_z = qry_movart->FieldByName("folrec")->AsInteger;
      break;
  }
  qry_movart->Close();
  qry_movart->ParamByName("codigo")->AsString = antcod_z;
  qry_movart->ParamByName("alm")->AsString = alm_z;
  qry_movart->ParamByName("folio")->AsInteger = folio_z;
  qry_movart->ParamByName("cia")->AsInteger = cia_z;
  qry_movart->Open();
  if(qry_movart->IsEmpty()) {
    qry_movart->Close();
    qry_movart->ParamByName("codigo")->AsString = antcod_z;
    qry_movart->ParamByName("alm")->AsString = antalm_z;
    qry_movart->ParamByName("folio")->AsInteger = antfolio_z;
    qry_movart->ParamByName("cia")->AsInteger = cia_z;
    qry_movart->Open();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_detmovart::grabar_pedimentoExecute(TObject *Sender)
{
   String codigo_z, serie_z, alm_z;
   TDateTime fecha_z;
   int ancho_z, alto_z;
   if(qry_movart->IsEmpty()) return;
   alm_z    = qry_movart->FieldByName("almac")->AsString;
   codigo_z = qry_movart->FieldByName("codigo")->AsString;
   serie_z  = qry_movart->FieldByName("serie")->AsString;

   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datospedimento *Frame_datospedimento;
   Frame_datospedimento = new TFrame_datospedimento (Dlg_analipol);
   ancho_z = Frame_datospedimento->Width + 20;
   alto_z = Frame_datospedimento->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datospedimento->Parent = Dlg_analipol->Panel1;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Teclee los datos";
   Frame_datospedimento->Align = alClient;
   Dlg_analipol->Position = poScreenCenter;
   Frame_datospedimento->busca_datosped(codigo_z, serie_z, alm_z);
   if( Dlg_analipol->ShowModal() == mrOk) {
     Frame_datospedimento->agrega_datosped();
     qry_pedimen->Close();
     qry_pedimen->ParamByName("codigo")->AsString = codigo_z;
     qry_pedimen->ParamByName("serie")->AsString = serie_z;
     qry_pedimen->Open();
   }
   delete Frame_datospedimento;
   delete Dlg_analipol;

}
//---------------------------------------------------------------------------

void __fastcall TForm_detmovart::modificar_serieExecute(TObject *Sender)
{
   String permisalta_z, codigo_z, almac_z, antserie_z, nvaserie_z;
   int folio_z;
   TEdit *edt_serie;
   TLabel *lbl_serie;
   bool nvatrans_z;
   permisalta_z = dm->busca_permision(MANTOINV);
   if(permisalta_z != "T" && permisalta_z != "M" && permisalta_z != "A" && dm->usermaster_z != "S" ) {
     Application->MessageBox("No puede modificar Series", "Permision Negada", MB_ICONEXCLAMATION);
     return;
   }
   if(qry_movart->IsEmpty()) {
     Application->MessageBox("Debe Seleccionar un Articulo", "Sin Articulo", MB_ICONEXCLAMATION);
     return;
   }
   codigo_z = qry_movart->FieldByName("codigo")->AsString;
   antserie_z = qry_movart->FieldByName("serie")->AsString;
   almac_z = qry_movart->FieldByName("almac")->AsString;
   folio_z = qry_movart->FieldByName("folio")->AsInteger;

   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   lbl_serie = new TLabel (Dlg_analipol);
   lbl_serie->Parent = Dlg_analipol->Panel1;
   lbl_serie->Caption = "Nueva Serie:";
   lbl_serie->Top = 20;
   lbl_serie->Left = 20;
   edt_serie = new TEdit  (Dlg_analipol);
   edt_serie->Parent = lbl_serie->Parent;
   edt_serie->CharCase = ecUpperCase;
   edt_serie->MaxLength = 20;
   edt_serie->Top = 20;
   edt_serie->Text = antserie_z;
   edt_serie->Left = lbl_serie->Left + lbl_serie->Width + 4;
   Dlg_analipol->Caption = "Teclee los datos";
   Dlg_analipol->Position = poScreenCenter;
   if( Dlg_analipol->ShowModal() == mrOk) {
     nvaserie_z = edt_serie->Text.Trim();
     try {
       nvatrans_z = !dm->manvehi->InTransaction;
       if(nvatrans_z) dm->manvehi->StartTransaction();
       qry_updateserie->Close();
       qry_updateserie->ParamByName("codigo")->AsString = codigo_z;
       qry_updateserie->ParamByName("almac")->AsString = almac_z;
       qry_updateserie->ParamByName("folio")->AsInteger = folio_z;
       qry_updateserie->ParamByName("serie")->AsString = nvaserie_z;
       qry_updateserie->ParamByName("cia")->AsInteger = cia_z;
       qry_updateserie->ExecSQL();
       if(nvatrans_z) dm->manvehi->Commit();
     } catch (Exception &E) {
       if(nvatrans_z) dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
     qry_movart->Close();
     qry_movart->ParamByName("codigo")->AsString = codigo_z;
     qry_movart->ParamByName("alm")->AsString = almac_z;
     qry_movart->ParamByName("folio")->AsInteger = folio_z;
     qry_movart->ParamByName("cia")->AsInteger = cia_z;
     qry_movart->Open();

   }
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

