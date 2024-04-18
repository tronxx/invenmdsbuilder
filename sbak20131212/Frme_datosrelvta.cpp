//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_datosrelvta.h"
#include "dmod.h"
#include "situaciones.h"
#include "numapal.h"
#include "dialg_busartic.h"
#include "dialg_foliosdisp.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxGrClms"
#pragma link "dxTL"
#pragma resource "*.dfm"
TFrame_datosrelvta *Frame_datosrelvta;
//---------------------------------------------------------------------------
__fastcall TFrame_datosrelvta::TFrame_datosrelvta(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::inicializa(String modo_z)
{
  date_fentrega->Date = dm->ahora();
  date_hora->Time     = FormatDateTime("hh:nn", dm->ahora());
  cia_z = dm->cia_z;
  qry_renentra->Close();
  qry_renentra->ParamByName("idrelvtas")->AsInteger = -1;
  qry_renentra->Open();
  qry_tipoentrega->Close();
  qry_tipoentrega->ParamByName("cia")->AsInteger = cia_z;
  qry_tipoentrega->Open();
  lkcmb_tipoentr->KeyValue = qry_tipoentrega->FieldByName("idtipoentrega")->AsInteger;
  qry_vendr->Close();
  qry_vendr->Open();
  lkcmb_vendedr->KeyValue = qry_vendr->FieldByName("codigo")->AsString;
  qry_chofer->Close();
  qry_chofer->Open();
  lkcmb_entrega->KeyValue = qry_chofer->FieldByName("clave")->AsString;
  qry_ciudad->Close();
  qry_ciudad->Open();
  lkcmb_ciudad->KeyValue = qry_ciudad->FieldByName("numero")->AsString;
  qry_ptovta->Close();
  qry_ptovta->ParamByName("cia")->AsInteger = cia_z;
  qry_ptovta->Open();
  lkcmb_ptovta->KeyValue = qry_ptovta->FieldByName("clave")->AsString;
  qry_tiposctes->Close();
  qry_tiposctes->ParamByName("cia")->AsInteger = cia_z;
  qry_tiposctes->Open();
  lkcmb_tipocte->KeyValue = qry_tiposctes->FieldByName("idticte")->AsInteger;
  qry_ubica->Close();
  qry_ubica->ParamByName("cia")->AsInteger = cia_z;
  qry_ubica->Open();
  qry_formapago->Close();
  qry_formapago->ParamByName("TIPORELVTAS")->AsInteger = 2;
  qry_formapago->Open();
  lkcmb_tipopago->KeyValue = qry_formapago->FieldByName("idcrdcon")->AsInteger;
  qry_comprometidos->Tag = SI_REFRESH;
}
//---------------------------------------------------------------------------
void __fastcall TFrame_datosrelvta::edt_codigoExit(TObject *Sender)
{
  String codigo_z;
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
  }
  edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
  edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
  edt_preciolis->Value = qry_inven->FieldByName("precio")->AsFloat;
  //edt_costou->Value = qry_inven->FieldByName("costou")->AsFloat;
  edt_preciolis->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::btn_nvorenClick(TObject *Sender)
{
  int idrenentra_z=0, conse_z = 0, idart_z = 0, idrelvtas_z=0, idcodigo_z,
      iddescri_z;
  String codigo_z, alm_z, descri_z, ticte_z, mensaje_z, titmsg_z;
  double piva_z=0, precio_z =0, prinv_z=0;
  idrelvtas_z = -1;
  ticte_z     = qry_tiposctes->FieldByName("ticte")->AsString;
  alm_z       = ""; //qry_almacen->FieldByName("clave")->AsString;
  codigo_z    = edt_codigo->Text.Trim().UpperCase();
  descri_z    = edt_descri->Text.Trim().UpperCase();
  precio_z    = edt_preciolis->Value;
  prinv_z     = qry_inven->FieldByName("precio")->AsFloat;
  conse_z     = qry_renentra->RecordCount + 1;
  if (precio_z == 0 && prinv_z && conse_z == 1 ) {
    mensaje_z = "No puede dejar en ceros el precio de venta\n";
    mensaje_z += "Precio Venta:" + FormatFloat("###,##0.00", prinv_z);
    titmsg_z = "Error";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  if ( ticte_z != "PC" && ticte_z != "AR" && ticte_z != "CR" && conse_z > 1 && precio_z ) {
    mensaje_z = "En ventas que no son de Cr�dito solo puede poner precio de Venta en el primer art�culo\n";
    titmsg_z = "Error";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    precio_z = 0;
  }
  if (codigo_z == "AUXILIAR")
     idart_z = -1;
  else
    idart_z     = qry_inven->FieldByName("idart")->AsInteger;

  idcodigo_z  = dm->busca_iddato(codigo_z, OLDCONCEPTO);
  iddescri_z  = dm->busca_iddato(descri_z, OLDCONCEPTO);
  try {
    qry_renentra->Tag = NO_REFRESH;
    qry_renentra->Append();
    idrenentra_z = (qry_renentra->RecordCount + 1) * -1;
    qry_renentra->FieldByName("codigo")->AsString = codigo_z;
    qry_renentra->FieldByName("descri")->AsString = descri_z;
    qry_renentra->FieldByName("idcodigo")->AsInteger = idcodigo_z;
    qry_renentra->FieldByName("iddescri")->AsInteger = iddescri_z;
    qry_renentra->FieldByName("idrelvtaart")->AsInteger = idrenentra_z;
    qry_renentra->FieldByName("idrelvtas")->AsInteger = idrelvtas_z;
    qry_renentra->FieldByName("idart")->AsInteger = idart_z;
    qry_renentra->FieldByName("salede")->AsString = alm_z;
    qry_renentra->FieldByName("preciolista")->AsFloat = precio_z;
    qry_renentra->FieldByName("conse")->AsInteger = qry_renentra->RecordCount + 1;
    qry_renentra->FieldByName("idreltransf")->AsInteger = 0;
    qry_renentra->FieldByName("idpolrelvta")->AsInteger = qry_renentra->FieldByName("idpolrelvta")->AsInteger;
    qry_renentra->FieldByName("folio")->AsInteger = 0;
    qry_renentra->Post();
  } catch (Exception &E)
  {
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  qry_renentra->Tag = SI_REFRESH;
  edt_codigo->SetFocus();
  qry_exist->Close();
  qry_exist->ParamByName("codigo")->AsString=codigo_z;
  qry_exist->ParamByName("cia")->AsInteger = cia_z;
  qry_exist->Open();
  if( qry_comprometidos->Tag == SI_REFRESH) despliega_comprometidos();

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) edt_codigoExit(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::btn_buscarfolioClick(TObject *Sender)
{
  if(qry_renentra->IsEmpty()) return;
  Tdlg_foliosdisp *dlg_foliosdisp = new Tdlg_foliosdisp (this);
  dlg_foliosdisp->edt_preciovta->Value = qry_renentra->FieldByName("preciolista")->AsFloat;
  dlg_foliosdisp->pnl_preciovta->Visible = true;
  dlg_foliosdisp->busca_dispo(qry_renentra->FieldByName("codigo")->AsString, cia_z);
  if(dlg_foliosdisp->ShowModal() == mrOk) {
    qry_renentra->Edit();
    qry_renentra->FieldByName("salede")->AsString = dlg_foliosdisp->alm_z;
    qry_renentra->FieldByName("folio")->AsString = dlg_foliosdisp->folio_z;
    qry_renentra->FieldByName("preciolista")->AsFloat = dlg_foliosdisp->precioventa_z;
    qry_renentra->Post();
  }
  delete dlg_foliosdisp;

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::despliega_comprometidos()
{
  String  codigo_z, alm_z, antalm_z, cad_z, relcomp_z;
  int unids_z =0;
  TStringList *comp_z = new TStringList();
  TLocateOptions Opts;
  Opts.Clear();
  if(qry_exist->IsEmpty()) return;
  codigo_z = edt_codigo->Text;
  qry_comprometidos->Close();
  qry_comprometidos->ParamByName("codigo")->AsString=codigo_z;
  qry_comprometidos->ParamByName("cia")->AsInteger = cia_z;
  qry_comprometidos->Open();
  antalm_z = "-1";
  for (qry_comprometidos->First(); !qry_comprometidos->Eof; qry_comprometidos->Next()) {
      alm_z = qry_comprometidos->FieldByName("salede")->AsString;
      if(antalm_z == "-1") antalm_z = alm_z;
      if(alm_z != antalm_z) {
        cad_z = ljust(alm_z, 4);
        cad_z += " " + FormatFloat("0000", unids_z);
        cad_z += " " + relcomp_z;
        comp_z->Append(cad_z);
        antalm_z = alm_z;
        relcomp_z = "";
        unids_z = 0;
      }
      relcomp_z += " " + qry_comprometidos->FieldByName("tipocte")->AsString + "-" +
          FormatFloat("0", qry_comprometidos->FieldByName("unids")->AsFloat);
      unids_z += qry_comprometidos->FieldByName("unids")->AsFloat;
  }
  qry_exist->First();
  for (int ii_z = 0; ii_z < comp_z->Count; ii_z++ ) {
      alm_z = comp_z->Strings[ii_z].SubString(1,4);
      alm_z = alm_z.Trim();
      unids_z = comp_z->Strings[ii_z].SubString(6,4).ToIntDef(0);
      relcomp_z = comp_z->Strings[ii_z].SubString(11,300);
      if(qry_exist->Locate("alm", alm_z, Opts)) {
        qry_exist->Edit();
        qry_exist->FieldByName("compr")->AsString = relcomp_z;
        qry_exist->FieldByName("comprom")->AsInteger = unids_z;
        qry_exist->Post();
      }
  }
  delete comp_z;

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::qry_renentraAfterScroll(
      TDataSet *DataSet)
{
  if(qry_renentra->Tag == NO_REFRESH || qry_renentra->Eof) return;
  qry_exist->Tag = NO_REFRESH;
  despliega_renentra();

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::despliega_renentra()
{
  String codigo_z, descri_z;
  //lkcmb_almacen->KeyValue = qry_renentra->FieldByName("salede")->AsString;
  codigo_z = dm->busca_dato(qry_renentra->FieldByName("idcodigo")->AsInteger, OLDCONCEPTO);
  descri_z = dm->busca_dato(qry_renentra->FieldByName("iddescri")->AsInteger, OLDCONCEPTO);
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  qry_exist->Close();
  qry_exist->ParamByName("codigo")->AsString=codigo_z;
  qry_exist->ParamByName("cia")->AsInteger = cia_z;
  qry_exist->Open();
  edt_preciolis->Value = qry_renentra->FieldByName("preciolista")->AsFloat;
  edt_descri->Text = descri_z;
  edt_codigo->Text = codigo_z;
  if(qry_comprometidos->Tag == SI_REFRESH) despliega_comprometidos();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::dbgrd_rengnesKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_DELETE) borrarenExecute(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::borrarenExecute(TObject *Sender)
{
  if(qry_renentra->Tag == READ_ONLY) return;
  double costo_z = 0, piva_z = 0;
  if ( !qry_renentra->IsEmpty()) {
    if(Application->MessageBox("Seguro de eliminar este rengl�n", "Eliminar Rengl�n", MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
    qry_renentra->Delete();
  }

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::primer_articExecute(TObject *Sender)
{
  qry_renentra->First();
}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::anter_articExecute(TObject *Sender)
{
  qry_renentra->Prior();

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::sigte_articExecute(TObject *Sender)
{
  qry_renentra->Next();

}
//---------------------------------------------------------------------------

void __fastcall TFrame_datosrelvta::ultimo_articExecute(TObject *Sender)
{
  qry_renentra->Last();

}
//---------------------------------------------------------------------------

