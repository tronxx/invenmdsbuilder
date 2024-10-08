//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "Frm_CapturaObsPed.h"
#include "Frm_capsales.h"
#include "dlgCataAlmacen.h"
#include "dmod.h"
#include "impre.h"
#include "Frm_selserie.h"
#include "Frm_kardex.h"
#include "Frm_prever.h"
#include "imprigra.h"
#include "dialg_okcancel.h"
#include "numapal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBELib"
#pragma link "Frme_datoscaptrasp"
#pragma link "Frme_datossabanaagre"
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_capsales *Form_capsales;
//---------------------------------------------------------------------------
//const int iTpcon=100;  //SABANAS DE FIDE
//const int iTpcon1=110; //SABANA VENTAS CELULARES
//const int iTpcon2=20; //SABANA DE VENTAS TRADICIONAL

//---------------------------------------------------------------------------
void _fastcall CapSales(TForm *Padre, String tiposab, bool estado)
{
    try
    {
        Form_capsales = new TForm_capsales(Padre, tiposab, estado);
        Form_capsales->Show();
    }
    catch(...)
    { }

}
//---------------------------------------------------------------------------
__fastcall TForm_capsales::TForm_capsales(TComponent* Owner, String tipo_sabana, bool estado)
    : TForm(Owner)
{
  sTipo = tipo_sabana;
  String alm_z;
  int idpermis_z=0;
  cia_z = dm->cia_z;
  if(sTipo == "S") {
    tipoest_z = EST_X_SAL_ESP;
    titulo_z = "Sabana Salidas Especiales";
    genero_z = "F";
    idpermis_z = CAPSALES;
  } else if(sTipo == "Q") {
    tipoest_z = EST_X_VTA_CEL;
    titulo_z = "Sabana Ventas Celular";
    genero_z = "F";
    idpermis_z = CAPVTASCEL;
  } else if(sTipo == "I") {
    tipoest_z = EST_X_VTA_FID;
    titulo_z = "Sabana Ventas Fide";
    genero_z = "F";
    idpermis_z = CAPVTASIMEVI;
  } else if(sTipo == "F") {
    tipoest_z = EST_X_VTA_FON;
    titulo_z = "Sabana Ventas FONACOT";
    genero_z = "F";
    idpermis_z = CAPVTASFON;
  }
  Caption = "Captura de " + titulo_z;
  if(genero_z == "M") {
    este_z = "Este";
    cerrado_z = "Cerrado";
  } else {
    este_z = "Esta";
    cerrado_z = "Cerrada";
  }

  permis_z=dm->busca_permision(CAPSALES);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  deshacer_afectacion->Visible = dm->usrmaster_z;
  qsAlmacen->Close();
  qsAlmacen->ParamByName("cia")->AsInteger = cia_z;
  qsAlmacen->Open();
  qsPuntoVta->Close();
  qsPuntoVta->ParamByName("cia")->AsInteger = cia_z;
  qsPuntoVta->Open();
//  lkcmb_ptovta->KeyValue = qsPuntoVta->FieldByName("clave")->AsString;
  qry_vendedor->Close();
  qry_vendedor->Open();
  qsPoblacion->Close();
  qsPoblacion->Open();
  Frame_datossabanaagre1->lkcmb_poblac->KeyValue = qsPoblacion->FieldByName("numero")->AsInteger;
  TIniFile *ini;
  String  basedato_z, config_z, bdcartera_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  alm_z    =  ini->ReadString( "Form_capsales_"+ sTipo, "ALMACEN", alm_z );
  //numero_z =  ini->ReadInteger( "Form_capsales_"+ sTipo, "NUMERO", 0);
  delete ini;
  Frame_datoscaptrasp1->dbedt_importe->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_iva->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_total->DataSource = dts_entradas;
  Frame_datoscaptrasp1->lkcmb_almacen->KeyValue = alm_z;
  SigteSabana(ULTIMO);

}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::LimpiarPantalla()
{
}
//---------------------------------------------------------------------------
bool __fastcall TForm_capsales::BuscarAlmacen(String sClave)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::BuscarUltimoReg()
{
}
//---------------------------------------------------------------------------
bool __fastcall TForm_capsales::BuscarEntrada(int iNumero)
{
    bool bResult = false;
    String alm_z;
    alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
    qsEntradas->Close();
    qsEntradas->ParamByName("Tipo"  )->AsString = sTipo;
    qsEntradas->ParamByName("Alm"   )->AsString  = alm_z;
    qsEntradas->ParamByName("Numero")->AsInteger = iNumero;
    qsEntradas->ParamByName("Cia"   )->AsInteger = cia_z;
    qsEntradas->Open();
    if (!qsEntradas->IsEmpty() ) {
       //TODO: Se puede desactivar x que existe
       //ListaRenglones;
       Frame_datoscaptrasp1->edt_numero->Value= iNumero;
       Frame_datoscaptrasp1->date_fecha->Date = qsEntradas->FieldByName("Fecha")->AsDateTime;
       bResult = true;
    }
    ListarRenglon();
    if(qsEntradas->FieldByName("status")->AsString == "C") {
      cierra_entrada->Enabled = false;
    } else {
      cierra_entrada->Enabled = true;
    }
    return bResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capsales::FormShow(TObject *Sender)
{
    //iTpcon      = cmbTipoEnt->Text.SubString(1,3).ToIntDef(0);
    //sDescriEnt = cmbTipoEnt->Text.SubString(3,40).Trim();
    cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::btn_salirClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::ListarRenglon()
{
    qry_renentra->Tag = INACTIVO;
    String alm_z;
    alm_z = qsAlmacen->FieldByName("clave")->AsString;
    qry_renentra->Close();
    qry_renentra->ParamByName("Tipo")->AsString = sTipo;
    qry_renentra->ParamByName("Alm" )->AsString  = alm_z;
    qry_renentra->ParamByName("Numero")->AsInteger = qsEntradas->FieldByName("Numero")->AsInteger;
    qry_renentra->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_renentra->Open();
    qry_renentra->Tag = ACTIVO;
}

void __fastcall TForm_capsales::qry_renentraAfterScroll(TDataSet *DataSet)
{
  int idnombre_z=0, credcon_z, isiono_z,folios_z;
  String siono_z,descripcion_z,series_z;
  if (!qry_renentra->Active || qry_renentra->IsEmpty() || qry_renentra->Tag == INACTIVO ) return;
  idnombre_z = qry_renentra->FieldByName("PerSenvRec")->AsInteger;
  Frame_datossabanaagre1->lkcmb_vendedr->KeyValue = qry_renentra->FieldByName("Vend")->AsString;
  Frame_datossabanaagre1->lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
  Frame_datossabanaagre1->lkcmb_ptovta->KeyValue = qry_renentra->FieldByName("RecEmi")->AsString;
  Frame_datossabanaagre1->edt_nombre->Text = qry_renentra->FieldByName("concepto")->AsString;
  Frame_datossabanaagre1->edt_prvta->Value = qry_renentra->FieldByName("prvta")->AsFloat;
  Frame_datossabanaagre1->edt_codigo->Text = qry_renentra->FieldByName("codinv")->AsString;
   Frame_datossabanaagre1->lst_series->Items->Clear();
  Frame_datossabanaagre1->lst_series->Items->Add(qry_renentra->FieldByName("serie")->AsString);
  credcon_z = qry_renentra->FieldByName("folent")->AsInteger - 1;
  siono_z = qry_renentra->FieldByName("siono")->AsString;
  descripcion_z = qry_renentra->FieldByName("codinv")->AsString;
  folios_z = qry_renentra->FieldByName("folsal")->AsInteger;
  //series_z = qry_renentra->FieldByName("serie")->AsString;
  Frame_datossabanaagre1->cmb_credcont->ItemIndex = credcon_z;
  isiono_z = Frame_datossabanaagre1->cmb_status->Items->IndexOf(siono_z);
  Frame_datossabanaagre1->cmb_status->ItemIndex = isiono_z;
  //Frame_datossabanaagre1->edt_descri->Text = descripcion_z;
  Frame_datossabanaagre1->edt_folios->Text = folios_z;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capsales::BuscarVendedor(String sVendedor)
{
    //qry_vendedor->Close();
    //qry_vendedor->ParamByName("Vendedor")->AsString = sVendedor;
    //qry_vendedor->Open();
    //if (qry_vendedor->IsEmpty() ) {
    //   edtVendedor->Text = "";
    //   lblVendedor->Caption = "";
    //}else {
    //   edtVendedor->Text = qry_vendedor->FieldByName("codigo")->AsString;
    //   lblVendedor->Caption = qry_vendedor->FieldByName("Nombre")->AsString;
    //}
}
//---------------------------------------------------------------------------
void __fastcall TForm_capsales::BuscarPoblacion(int iPoblac)
{
    //qsPoblacion->Close();
    //qsPoblacion->ParamByName("Numero")->AsInteger = iPoblac;
    //qsPoblacion->Open();
    //if (qsPoblacion->IsEmpty() )
    //      edtPoblacion->Text = "";
    //else  edtPoblacion->Text = qsPoblacion->FieldByName("Nombre")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capsales::BuscarPuntoVenta(String sClave)
{
    //qsPuntoVta->Close();
    //qsPuntoVta->ParamByName("Clave")->AsString = sClave;
    //qsPuntoVta->ParamByName("Cia"  )->AsInteger = dm->cia_z;
    //qsPuntoVta->Open();
    //if (qsPuntoVta->IsEmpty() ) {
    //   edtPuntoVta->Text    = "";
    //   lblPuntoVta->Caption = "";
    //}else {
    //   edtPuntoVta->Text    = qsPuntoVta->FieldByName("Clave")->AsString;
    //   lblPuntoVta->Caption = qsPuntoVta->FieldByName("Nombre")->AsString;
    //}
}
//---------------------------------------------------------------------------
void __fastcall TForm_capsales::BuscarConcepto(int iCliente)
{
 //   qsConceps->Close();
 //   qsConceps->ParamByName("NCon")->AsInteger = iCliente;
 //   qsConceps->Open();
 //   if (qsConceps->IsEmpty() )
 //   edt_nombre->Text = "NO EXISTE CONCEPTO";
 //  S else edt_nombre->Text = qsConceps->FieldByName("Concepto")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    Form_capsales = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::SigteSabana(int tipo_mov)
{
  int nument_z=0;
  String alm_z;
  alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  nument_z = dm->sigte_entrada(alm_z, sTipo, nument_z, tipo_mov);
  Frame_datoscaptrasp1->edt_numero->Value = nument_z;
  BuscarEntrada(nument_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_capsales::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------



void __fastcall TForm_capsales::nuevoExecute(TObject *Sender)
{
   int ancho_z, alto_z, numero_z=0;
   String alm_z, strfecha_z, strfechoy_z, strfecatras_z;
   double fecha_z;
   bool todook_z = true;
   if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
     return;
   }
   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datoscaptrasp *Frame_datoscaptrasp;
   Frame_datoscaptrasp = new TFrame_datoscaptrasp (Dlg_analipol);
   ancho_z = Frame_datoscaptrasp->Width + 20;
   alto_z = Frame_datoscaptrasp->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datoscaptrasp->Parent = Dlg_analipol->Panel1;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Captura de Datos";
   Frame_datoscaptrasp->Align = alClient;
   Frame_datoscaptrasp->inicializa(sTipo);
   Frame_datoscaptrasp->accion_z = NUEVO;
   Dlg_analipol->Position = poScreenCenter;
   alm_z    = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
   Frame_datoscaptrasp->lkcmb_almacen->KeyValue = alm_z;
   Frame_datoscaptrasp->nuevo();

   if( Dlg_analipol->ShowModal() == mrOk) {
     alm_z    = Frame_datoscaptrasp->qry_Almacen->FieldByName("clave")->AsString;
     fecha_z  = Frame_datoscaptrasp->date_fecha->Date;
     numero_z = Frame_datoscaptrasp->edt_numero->Value;
     strfechoy_z = FormatDateTime("yyyymmdd", dm->ahora());
     strfecatras_z = FormatDateTime("yyyymmdd", dm->ahora() - 20);
     strfecha_z = FormatDateTime("yyyymmdd", fecha_z);
     if( strfecha_z > strfechoy_z) {
       Application->MessageBox("Lo siento, no puede agregar fechas futuras", "Fecha Incorrecta", MB_ICONEXCLAMATION);
       todook_z = false;
     }
     if( strfecha_z < strfecatras_z ) {
       Application->MessageBox("Lo siento, no puede agregar fechas de mas de 20 d�as de diferencia", "Fecha Incorrecta", MB_ICONEXCLAMATION);
       todook_z = false;
     }
     if(todook_z) alta_ptvt(alm_z, fecha_z, numero_z);
   }
   delete Frame_datoscaptrasp;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------





void __fastcall TForm_capsales::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::alta_ptvt(String alm_z, double fecha_z, int nument_z)
{
   qsEntradas->Close();
   qsEntradas->ParamByName("tipo")->AsString = sTipo;
   qsEntradas->ParamByName("alm")->AsString = alm_z;
   qsEntradas->ParamByName("numero")->AsInteger = nument_z;
   qsEntradas->ParamByName("cia")->AsInteger = cia_z;
   qsEntradas->Open();
   if(!qsEntradas->IsEmpty()) return;

   try {
     qsEntradas->Append();
     qsEntradas->FieldByName("tipo")->AsString = sTipo;
     qsEntradas->FieldByName("alm")->AsString = alm_z;
     qsEntradas->FieldByName("recemi")->AsString = "";
     qsEntradas->FieldByName("numero")->AsInteger = nument_z;
     qsEntradas->FieldByName("facpro")->AsString = "";
     qsEntradas->FieldByName("prove")->AsString = "";
     qsEntradas->FieldByName("perenvrec")->AsInteger = 0;
     qsEntradas->FieldByName("status")->AsString = "A";
     qsEntradas->FieldByName("coniva")->AsString = "";
     qsEntradas->FieldByName("fecha")->AsDateTime = fecha_z;
     qsEntradas->FieldByName("importe")->AsFloat = 0;
     qsEntradas->FieldByName("iva")->AsFloat = 0;
     qsEntradas->FieldByName("total")->AsFloat = 0;
     qsEntradas->FieldByName("vence")->AsDateTime = fecha_z;
     qsEntradas->FieldByName("ctofin")->AsFloat = 0;
     qsEntradas->FieldByName("tascomp")->AsFloat = 0;
     qsEntradas->FieldByName("taspro")->AsFloat = 0;
     qsEntradas->FieldByName("fechafac")->AsDateTime = fecha_z;
     qsEntradas->FieldByName("letras")->AsInteger = 0;
     qsEntradas->FieldByName("fletes")->AsInteger = 0;
     qsEntradas->FieldByName("desxap")->AsInteger = 0;
     qsEntradas->FieldByName("planp")->AsInteger = 0;
     qsEntradas->FieldByName("plazocfp")->AsInteger = 0;
     qsEntradas->FieldByName("taspro")->AsFloat = 0;
     qsEntradas->FieldByName("ctofincomp")->AsFloat = 0;
     //qsEntradas->FieldByName("idusuario")->AsString = dm->idusuario_z;
     qsEntradas->FieldByName("fechaprp")->AsDateTime = fecha_z;
     qsEntradas->FieldByName("cia")->AsInteger = cia_z;
     qsEntradas->Post();
     dm->manvehi->StartTransaction();
     qsEntradas->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = 0;
   botones_onoff(VISIBLES);
   BuscarEntrada(nument_z);
}
//---------------------------------------------------------------------------




void __fastcall TForm_capsales::edicion_factible(int modo_z)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm_capsales::CierraRenExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este Rengl�n ya ha sido previamente Cerrado", "Rengl�n Cerrado", MB_ICONERROR);
    return;
  }
  siono_z = qry_renentra->FieldByName("siono")->AsString;
  folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
  codigo_z = qry_renentra->FieldByName("codinv")->AsString;
  serie_z = qry_renentra->FieldByName("serie")->AsString;
  alm_z   = qry_renentra->FieldByName("alm")->AsString;
  ptovta_z = qry_renentra->FieldByName("recemi")->AsString;
  idcomprador_z = qry_renentra->FieldByName("persenvrec")->AsInteger;
  fecha_z = qsEntradas->FieldByName("fecha")->AsDateTime;
  nsabana_z = qry_renentra->FieldByName("numero")->AsInteger;
  npoblac_z = qry_renentra->FieldByName("poblac")->AsInteger;
  numren_z = qry_renentra->FieldByName("conse")->AsInteger;

  TForm_kardex *Form_kardex = new TForm_kardex (this);
  cierre_ren_z = Form_kardex->salida_sabana_vtas(
      codigo_z, serie_z, folio_z, fecha_z,
      alm_z, ptovta_z, sTipo,
      idcomprador_z, siono_z, nsabana_z, npoblac_z, numren_z
  );
  if(!cierre_ren_z) {
    Application->MessageBox
      (Form_kardex->errores_z->Text.c_str(),
       "ERROR: Rengl�n NO Cerrado", MB_ICONERROR
    );
  } else {
    Application->MessageBox
      ("Todos los Movimientos Han sido efectuados",
       "Rengl�n Cerrado", MB_OK
    );
    qry_renentra->Edit();
    qry_renentra->FieldByName("Status")->AsString = "C";
    qry_renentra->Post();
  }
  delete Form_kardex->errores_z;
  delete Form_kardex;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::cancela_renglonExecute(TObject *Sender)
{
  double costo_z, piva_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este rengl�n ya ha sido cerrado, no lo puede eliminar", "RENGLON CERRADO", MB_ICONEXCLAMATION);
    return;
  }
  int ii_z = Application->MessageBox("Esta Seguro de Eliminar este Rengl�n ?", "Eliminar Rengl�n", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
  if (ii_z != IDOK ) return;
  costo_z = qry_renentra->FieldByName("costou")->AsFloat;
  piva_z = qry_renentra->FieldByName("piva")->AsFloat;
  qsEntradas->Edit();
  qsEntradas->FieldByName("importe")->AsFloat       -= costo_z;
  qsEntradas->FieldByName("iva")->AsFloat           -= costo_z * piva_z / 100;
  qsEntradas->FieldByName("total")->AsFloat         -= costo_z * ((piva_z / 100) + 1);
  qsEntradas->Post();
  qry_renentra->Delete();
  try {
    dm->manvehi->StartTransaction();
    qry_renentra->ApplyUpdates();
    qsEntradas->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::dbgrdRengCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------


void __fastcall TForm_capsales::exporta_dbgrdExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrdReng;
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
  SaveDialog->FileName = "*.xls";
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

void __fastcall TForm_capsales::imprimeExecute(TObject *Sender)
{
  double piva_z=0, importe_z=0, iva_z=0, total_z=0, costo_z=0;
  String arch_z = Name+"txt", serie_z="", vnd_z="", pvta_z="", ciu_z="";
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresi�n de " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_renentra->DisableControls();
  qry_renentra->Tag == NO_REFRESH;
  qry_renentra->First();
//  if(!qry_renentra->IsEmpty())
//    zona_z = qry_renpogas->FieldByName("zona")->AsInteger;
  pagina_z = 1; report_encab();
  for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
    if(lineas_z > LIN_X_PAG) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab();
    }
/*
    if(qry_renentra->FieldByName("zona")->AsInteger != zona_z) {
      fprintf(archout, "%s", cjust("Total de Esta Zona:", 70));
      rendto_z=0;
      fprintf(archout, "%s ", rjust(FormatFloat("###,##0", reczon_z), 7));
      if(litzon_z) rendto_z = reczon_z / litzon_z;
      fprintf(archout, "%s   ", rjust(FormatFloat("##.00", rendto_z), 7));
      fprintf(archout, "%s ", rjust(FormatFloat("###0.00", litzon_z), 7));
      fprintf(archout, "%s\n\n", rjust(FormatFloat("#,###,##0.00", impzon_z), 20));
      lineas_z +=2;
      rectot_z += reczon_z; reczon_z = 0;
      littot_z += litzon_z; litzon_z = 0;
      imptot_z += impzon_z; impzon_z = 0;
      zona_z = qry_renentra->FieldByName("zona")->AsInteger;
      report_subencab();
    }
*/
    vnd_z = qry_renentra->FieldByName("vend")->AsString;
    pvta_z = qry_renentra->FieldByName("recemi")->AsString;
    //lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
    ciu_z = qsPoblacion->FieldByName("nombre")->AsString;
    if( sTipo != "Q") {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
    } else {
        costo_z = qry_renentra->FieldByName("prvta")->AsFloat;
    }

    fprintf(archout, "%s %s|%s|%s|%s|%s|%s|%s|%s|%s\n",
      ljust(qry_renentra->FieldByName("codinv")->AsString, 13),
      ljust(qry_renentra->FieldByName("descri")->AsString, 30),
      rjust(IntToStr(qry_renentra->FieldByName("folsal")->AsInteger), 5),
      ljust(qry_renentra->FieldByName("serie")->AsString, 20),
      ljust(qry_renentra->FieldByName("siono")->AsString, 1),
      ljust(qry_renentra->FieldByName("concepto")->AsString, 20),
      ljust(pvta_z, 4),
      ljust(vnd_z, 4),
      rjust(FormatFloat("#,###,##0.00", costo_z), 12),
      ljust(ciu_z, 10)
    );
    piva_z = qry_renentra->FieldByName("piva")->AsFloat;
    importe_z += costo_z;
    iva_z += qry_renentra->FieldByName("costou")->AsFloat * (piva_z / 100);
    total_z = importe_z + iva_z;
  }
  fprintf(archout, "%s\n",
    rjust(
      "Importe:" + FormatFloat("#,###,##0.00", importe_z) +
      "   Iva:" + FormatFloat("#,###,##0.00", iva_z) +
      "   Total:" + FormatFloat("#,###,##0.00", total_z), 117
    )
  );
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renentra->Tag == SI_REFRESH;
  qry_renentra->EnableControls();
  qry_renentra->EnableControls();
  if(dm->preview_z) {
    VistaPrevia(this, arch_z, dm->rutaimp_z, dm->tipoimp_z, dm->ff_z, dm->impresora_z);
  } else {
    manda_imp(arch_z, dm->rutaimp_z, dm->tipoimp_z, dm->ff_z, dm->impresora_z);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::report_encab()
{
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de %s\n", titulo_z);
  fprintf(archout, "Numero:%6d Almacen:%s %s Fecha:%s\n",
    qsEntradas->FieldByName("numero")->AsInteger,
    qsAlmacen->FieldByName("clave")->AsString,
    qsAlmacen->FieldByName("nombre")->AsString,
    FormatDateTime("dd-mm-yyyy", qsEntradas->FieldByName("fecha")->AsDateTime),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s%s%s|%s|%s|%s|%s|%s|%s|%s|%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON),
    cjust("Articulo", 44),
    rjust("Folio", 5),
    ljust("Serie", 20),
    "S",
    ljust("Cliente", 20),
    ljust("Pvta", 4),
    ljust("Vnd", 4),
    rjust("Costo_Unitar", 12),
    ljust("Poblaci�n", 10),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::cancelarExecute(TObject *Sender)
{
  grabar->Tag = EN_ESPERA;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------



void __fastcall TForm_capsales::capobsExecute(TObject *Sender)
{
    CapturaObservaPedido(this, qsEntradas->FieldByName("Tipo")->AsString,
                               qsEntradas->FieldByName("Alm" )->AsString,
                               qsEntradas->FieldByName("numero")->AsInteger,
                               qsEntradas->FieldByName("cia")->AsInteger,
                               "", permis_z);

}
//---------------------------------------------------------------------------


void __fastcall TForm_capsales::busca_cod(String codigo_z)
{
  //edt_codigo->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capsales::deshacer_afectacionExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString != "C") {
    Application->MessageBox("Este Rengl�n No ha sido previamente Cerrado", "Rengl�n Abierto", MB_ICONERROR);
    return;
  }
  siono_z = qry_renentra->FieldByName("siono")->AsString;
  folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
  codigo_z = qry_renentra->FieldByName("codinv")->AsString;
  serie_z = qry_renentra->FieldByName("serie")->AsString;
  alm_z   = qry_renentra->FieldByName("alm")->AsString;
  ptovta_z = qry_renentra->FieldByName("recemi")->AsString;
  idcomprador_z = qry_renentra->FieldByName("persenvrec")->AsInteger;
  fecha_z = qsEntradas->FieldByName("fecha")->AsDateTime;
  nsabana_z = qry_renentra->FieldByName("numero")->AsInteger;
  npoblac_z = qry_renentra->FieldByName("poblac")->AsInteger;
  numren_z = qry_renentra->FieldByName("conse")->AsInteger;

  TForm_kardex *Form_kardex = new TForm_kardex (this);
  cierre_ren_z = Form_kardex->cancela_salida_sabana_vtas(
      codigo_z, serie_z, folio_z, fecha_z,
      alm_z, ptovta_z, sTipo,
      idcomprador_z, siono_z, nsabana_z, npoblac_z, numren_z
  );
  if(!cierre_ren_z) {
    Application->MessageBox
      (Form_kardex->errores_z->Text.c_str(),
       "ERROR: Rengl�n NO Abierto", MB_ICONERROR
    );
  } else {
    Application->MessageBox
      ("Todos los Movimientos Han sido efectuados",
       "Rengl�n Abierto", MB_OK
    );
    qry_renentra->Edit();
    qry_renentra->FieldByName("Status")->AsString = "A";
    qry_renentra->Post();
  }
  delete Form_kardex->errores_z;
  delete Form_kardex;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capsales::Frame_datoscaptrasp1edt_numeroKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarEntrada(Frame_datoscaptrasp1->edt_numero->Value ) ) {
           Application->MessageBox("No Existe El Numero de Entrada Solicitado !!", "Entrada", MB_OK | MB_ICONQUESTION);
           return;
       }
       ListarRenglon();
    }

}
//---------------------------------------------------------------------------

