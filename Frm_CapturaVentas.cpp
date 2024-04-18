//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "Frm_CapturaObsPed.h"
#include "Frm_CapturaVentas.h"
#include "dlgCataAlmacen.h"
#include "dmod.h"
#include "impre.h"
#include "Frm_selserie.h"
#include "Frm_kardex.h"
#include "Frm_prever.h"
#include "imprigra.h"
#include "numapal.h"
#include "dialg_busartic.h"
#include "dialg_okcancel.h"
#include "Frme_datossabanaagre.h"
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
#pragma link "Frme_datossabanavta"
#pragma link "Frme_datossabanaagre"
#pragma link "Frme_datoscaptrasp"
#pragma link "Frme_datoscapcancelagrega"
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_capturaventas *Form_capturaventas;
//---------------------------------------------------------------------------
//const int iTpcon=100;  //SABANAS DE FIDE
//const int iTpcon1=110; //SABANA VENTAS CELULARES
//const int iTpcon2=20; //SABANA DE VENTAS TRADICIONAL

//---------------------------------------------------------------------------
void _fastcall CapturadeSabanasVentas(TForm *Padre, String tiposab, bool estado)
{
   Form_capturaventas = new TForm_capturaventas(Padre, tiposab, estado);
   Form_capturaventas->Show();

}
//---------------------------------------------------------------------------
__fastcall TForm_capturaventas::TForm_capturaventas(TComponent* Owner, String tipo_sabana, bool estado)
    : TForm(Owner)
{
  inicializa(tipo_sabana);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::inicializa(String tipo_sabana)
{
  int idpermis_z=0, numero_z=0;
  String alm_z;
  cia_z = dm->cia_z;
  sTipo = tipo_sabana;
  if(sTipo == "V") {
    tipoest_z = EST_X_VTA_TRAD;
    titulo_z = "Sabana Ventas Tradicional";
    genero_z = "F";
    idpermis_z = CAPVTAS;
  } else if(sTipo == "Q") {
    tipoest_z = EST_X_VTA_CEL;
    titulo_z = "Sabana Ventas Celular";
    genero_z = "F";
    Frame_datossabanaagre1->edt_prvta->Visible = true;
    Frame_datossabanaagre1->lbl_prvta->Visible = true;
    idpermis_z = CAPVTASCEL;
  } else if(sTipo == "H") {
    tipoest_z = EST_X_VTA_FID;
    titulo_z = "Sabana Ventas Fide";
    genero_z = "F";
    idpermis_z = CAPVTASFID;
  } else if(sTipo == "F") {
    tipoest_z = EST_X_VTA_FON;
    titulo_z = "Sabana Ventas FONACOT";
    genero_z = "F";
    idpermis_z = CAPVTASFON;
  } else if(sTipo == "1") {
    tipoest_z = EST_X_VTA_IMEVI;
    titulo_z = "Sabana Ventas IMEVI";
    genero_z = "F";
    idpermis_z = CAPVTASIMEVI;
  } else if(sTipo == "M") {
    tipoest_z = EST_X_SAL_MAY;
    titulo_z = "Sabana Ventas Mayoreo";
    genero_z = "F";
    idpermis_z = CAPSALMAY;
  } else if(sTipo == "S") {
    tipoest_z = EST_X_SAL_ESP;
    titulo_z = "Sabana Salidas Especiales";
    genero_z = "F";
    idpermis_z = CAPSALES;
  }
  Caption = "Captura de " + titulo_z;
  if(genero_z == "M") {
    este_z = "Este";
    cerrado_z = "Cerrado";
  } else {
    este_z = "Esta";
    cerrado_z = "Cerrada";
  }
  if( dm->usermaster_z == "S") {
    deshacer_afectacion->Visible = true;
    cambia_pto_vta->Visible = true;
    abrir_sabana->Visible = true;
  } else {
    deshacer_afectacion->Visible = false;
    cambia_pto_vta->Visible = false;
    abrir_sabana->Visible = false;
  }

  permis_z=dm->busca_permision(idpermis_z);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  Frame_datoscaptrasp1->inicializa(sTipo);
  Frame_datossabanaagre1->inicializa(sTipo);
  Frame_datossabanaagre1->dbedt_descriinven->DataSource = dts_renentra;
  qsPuntoVta->Close();
  qsPuntoVta->ParamByName("cia")->AsInteger = cia_z;
  qsPuntoVta->Open();
  alm_z = qsPuntoVta->FieldByName("clave")->AsString;
  qry_vendedor->Close();
  qry_vendedor->Open();
  Frame_datossabanaagre1->lkcmb_vendedr->KeyValue = qry_vendedor->FieldByName("codigo")->AsString;
  qsPoblacion->Close();
  qsPoblacion->Open();
  Frame_datossabanaagre1->lkcmb_poblac->KeyValue = qsPoblacion->FieldByName("numero")->AsInteger;
  TIniFile *ini;
  String  basedato_z, config_z, bdcartera_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  alm_z           = ini->ReadString( "Form_capvtas_"+ sTipo, "ALMACEN", alm_z );
  numero_z        = ini->ReadInteger( "Form_capvtas_"+ sTipo, "NUMERO", 0);
  fechaabierta_z  = ini->ReadString( "Form_capvtas_"+ sTipo, "FECHA_ABIERTA", "N");
  delete ini;
  Frame_datoscaptrasp1->dbedt_importe->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_iva->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_total->DataSource = dts_entradas;
  Frame_datoscaptrasp1->lkcmb_almacen->KeyValue = alm_z;
  SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------


bool __fastcall TForm_capturaventas::BuscarEntrada(int iNumero)
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
    ultrenentra_z = dm->sigte_renentra(alm_z, sTipo, iNumero);

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

void __fastcall TForm_capturaventas::btn_salirClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::ListarRenglon()
{
    qry_renentra->Tag = INACTIVO;
    String alm_z;
    alm_z = qsEntradas->FieldByName("alm")->AsString;
    qry_renentra->Close();
    qry_renentra->ParamByName("Tipo")->AsString = sTipo;
    qry_renentra->ParamByName("Alm" )->AsString  = alm_z;
    qry_renentra->ParamByName("Numero")->AsInteger = qsEntradas->FieldByName("Numero")->AsInteger;
    qry_renentra->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_renentra->Open();
    qry_renentra->Tag = ACTIVO;
    qry_renentraAfterScroll(qry_renentra);
}

void __fastcall TForm_capturaventas::qry_renentraAfterScroll(TDataSet *DataSet)
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

void __fastcall TForm_capturaventas::BuscarVendedor(String sVendedor)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_capturaventas::BuscarPoblacion(int iPoblac)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_capturaventas::BuscarPuntoVenta(String sClave)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_capturaventas::BuscarConcepto(int iCliente)
{
    qsConceps->Close();
    qsConceps->ParamByName("NCon")->AsInteger = iCliente;
    qsConceps->Open();
    if (qsConceps->IsEmpty() )
         Frame_datossabanaagre1->edt_nombre->Text = "NO EXISTE CONCEPTO";
    else Frame_datossabanaagre1->edt_nombre->Text = qsConceps->FieldByName("Concepto")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  String alm_z;
  int numero_z;
  if(qsEntradas->State != dsInactive) {
    alm_z = qsEntradas->FieldByName("alm")->AsString;
    numero_z = qsEntradas->FieldByName("numero")->AsInteger;
    TIniFile *ini;
    String  basedato_z, config_z, bdcartera_z;
    config_z = dm->busca_inifile();
    ini = new TIniFile(config_z);
    ini->WriteString( "Form_capvtas_"+ sTipo, "ALMACEN", alm_z );
    ini->WriteInteger( "Form_capvtas_"+ sTipo, "NUMERO", numero_z);
    delete ini;
  }
  Action = caFree;
  Form_capturaventas = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::SigteSabana(int tipo_mov)
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


void __fastcall TForm_capturaventas::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------



void __fastcall TForm_capturaventas::nuevoExecute(TObject *Sender)
{
   int ancho_z, alto_z, numero_z=0;
   String alm_z, strfecha_z, strfechoy_z, strfecatras_z;
   double fecha_z;
   bool todook_z = true;
   if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
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
       Application->MessageBox("Lo siento, no puede agregar fechas de mas de 20 días de diferencia", "Fecha Incorrecta", MB_ICONEXCLAMATION);
       todook_z = false;
     }
     if(todook_z) alta_ptvt(alm_z, fecha_z, numero_z);
   }
   delete Frame_datoscaptrasp;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  String alm_z;
  int nument_z = 0;
  alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  if(!BuscarEntrada(nument_z)) return;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  if(qsEntradas->IsEmpty()) return;
  if(qsEntradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede eliminar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Eliminar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  mensaje_z = "Esta seguro de eliminar " + este_z + " " + titulo_z + " ? ";
  titmsg_z = "Eliminar " + titulo_z;

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
      if(qry_renentra->FieldByName("status")->AsString == "C") {
        si_borrar = false;
      } else {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
        piva_z = qry_renentra->FieldByName("piva")->AsFloat;
        qsEntradas->Edit();
        qsEntradas->FieldByName("importe")->AsFloat       -= costo_z;
        qsEntradas->FieldByName("iva")->AsFloat           -= costo_z * piva_z / 100;
        qsEntradas->FieldByName("total")->AsFloat         -= costo_z * ((piva_z / 100) + 1);
        qsEntradas->Post();
        qry_renentra->Delete();
      }
    }
    if(si_borrar) {
      qsEntradas->Delete();
    } else {
      mensaje_z = "No puede eliminar " + este_z + " " + titulo_z +
       " por que hay renglones cerrados,\n los renglones no cerrados han sido eliminados";
      titmsg_z = "Imposible Eliminar " + titulo_z;
      Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    }
    try {
      dm->manvehi->StartTransaction();
      qsEntradas->ApplyUpdates();
      qry_renentra->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::alta_ptvt(String alm_z, double fecha_z, int nument_z)
{
   //alm_z = qry_almacen->FieldByName("clave")->AsString;
   //fecha_z = dtFecha->Date;
   //nument_z = edtNumero->IntValue;
   qsEntradas->Close();
   qsEntradas->ParamByName("tipo")->AsString = sTipo;
   qsEntradas->ParamByName("alm")->AsString = alm_z;
   qsEntradas->ParamByName("numero")->AsInteger = nument_z;
   qsEntradas->ParamByName("cia")->AsInteger = cia_z;
   qsEntradas->Open();
   if(!qsEntradas->IsEmpty()) return;
//   idnombre_z=dm->busca_iddato(edt_nombre->Text.Trim(), CONCEPTO);
//"insert into entradas (tipo,alm,recemi,numero,facpro,prove,
// perenvrec,status,coniva,fecha,importe,iva,total,vence,ctofin,
// tascomp,taspro,fechafac,letras,plazocfp,planp,fletes,desxap,
// fechaprp,ctofincomp,usuario,cia,

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
   BuscarEntrada(nument_z);
}
//---------------------------------------------------------------------------



void __fastcall TForm_capturaventas::agrerenExecute(TObject *Sender)
{
   int ancho_z, alto_z, numero_z=0,
      idrenentra_z=0, folio_z=0, ii_z=0, conse_z = 0, idalm_z = 0, idart_z = 0,
      identrada_z=0, idserie_z = 0, idpers_z=0, cantmueve_z=0, idvend_z=0,
      idciudad_z=0, idptovta_z=0, idcodigo_z=0, iddescri_z=0, nentrada_z,
      crdocon_z=0;
   String tipo_z, siono_z="S", serie_z="", entcan_z="", vendedor_z, ptovta_z,
     descri_z, alm_z, codigo_z,nombre_z, status_z,tipago_z;
   double piva_z=0, costo_z =0, prvta_z=0;
   if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
     return;
   }
   if(qsEntradas->FieldByName("status")->AsString == "C") {
     mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
     " no puede Agregar";
     titmsg_z = titulo_z + " " + cerrado_z;
     Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
     return;
   }
   numero_z = qsEntradas->FieldByName("numero")->AsInteger;
   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datossabanaagre *Frame_datossabanaagre;
   Frame_datossabanaagre = new TFrame_datossabanaagre (Dlg_analipol);
   ancho_z = Frame_datossabanaagre->Width + 20;
   alto_z = Frame_datossabanaagre->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datossabanaagre->Parent = Dlg_analipol->Panel1;
   alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
   fecha_z = qsEntradas->FieldByName("fecha")->AsDateTime;
   Frame_datossabanaagre->fecha_z = fecha_z;
   Frame_datossabanaagre->alm_z = alm_z;
   Frame_datossabanaagre->fechaabierta_z = fechaabierta_z;
   Frame_datossabanaagre->lkcmb_ptovta->KeyValue =Frame_datossabanaagre1->qry_PuntoVta->FieldByName("clave")->AsString;
   Frame_datossabanaagre->cmb_status->ItemIndex = Frame_datossabanaagre1->cmb_status->ItemIndex;
   Frame_datossabanaagre->lkcmb_vendedr->KeyValue = Frame_datossabanaagre1->qry_vendedor->FieldByName("codigo")->AsString;
   Frame_datossabanaagre->edt_nombre->Text = Frame_datossabanaagre1->edt_nombre->Text;
   Frame_datossabanaagre->lkcmb_poblac->KeyValue = Frame_datossabanaagre1->qry_Poblacion->FieldByName("numero")->AsInteger;
   Frame_datossabanaagre->cmb_credcont->ItemIndex = Frame_datossabanaagre1->cmb_credcont->ItemIndex;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Captura de Ventas";
   Dlg_analipol->Position = poScreenCenter;
   if( Dlg_analipol->ShowModal() == mrOk) {
      cantmueve_z = Frame_datossabanaagre1->edt_canti->Value;
      if(cantmueve_z < 1) {
        Application->MessageBox(("No pueden ser "+ IntToStr((int)Frame_datossabanaagre1->edt_canti->Value) + " Articulos").c_str(), "Incorrecto Número de Artículos", MB_ICONEXCLAMATION);
        return;
      }
      tipo_z = Frame_datossabanaagre->qry_inven->FieldByName("tipo")->AsString;
      descri_z = Frame_datossabanaagre->qry_inven->FieldByName("descri")->AsString;
      crdocon_z = Frame_datossabanaagre->cmb_credcont->ItemIndex + 1;

      if(tipo_z == "ALF" && (Frame_datossabanaagre->lst_series->Items->Count != Frame_datossabanaagre->edt_canti->Value))  {
        Application->MessageBox(("Debe proporcionar "+ IntToStr((int)Frame_datossabanaagre->edt_canti->Value) + " Series").c_str(), "Incorrecto Número de Series", MB_ICONEXCLAMATION);
        return;
      }
      if(!Frame_datossabanaagre->qry_folsel->State == dsInactive)
        Frame_datossabanaagre->qry_folsel->First();
      vendedor_z = Frame_datossabanaagre->qry_vendedor->FieldByName("codigo")->AsString;
      nentrada_z = qsEntradas->FieldByName("numero")->AsInteger;
      if(!Frame_datossabanaagre->cmb_status->Text.IsEmpty()) siono_z = Frame_datossabanaagre1->cmb_status->Text.SubString(1,1);
      tipago_z = Frame_datossabanaagre->cmb_tipago->Text.SubString(1,1);
      alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
      ptovta_z = Frame_datossabanaagre->qry_PuntoVta->FieldByName("clave")->AsString;
      codigo_z =Frame_datossabanaagre->qry_inven->FieldByName("codigo")->AsString;
      piva_z = Frame_datossabanaagre->qry_inven->FieldByName("piva")->AsFloat;
      nombre_z = Frame_datossabanaagre->edt_nombre->Text.Trim();
      idpers_z = dm->busca_iddato(nombre_z, OLDCONCEPTO);
      idciudad_z = Frame_datossabanaagre->qry_Poblacion->FieldByName("numero")->AsInteger;
      if( sTipo == "Q") prvta_z = Frame_datossabanaagre1->edt_prvta->Value;

      folio_z = Frame_datossabanaagre->qry_folsel->FieldByName("folio")->AsInteger;
      if(tipo_z == "GLO" && !dm->foliosalf_z ) {
        folio_z = dm->ultimo_folio_disp(alm_z, codigo_z, fecha_z, fechaabierta_z);
        serie_z = ""; idserie_z = 0;
      }
      conse_z = dm->sigte_renentra(alm_z, sTipo, numero_z);
      //qry_renentra->Close();
      //qry_insrenen->ParamByName("idrenentra")->AsInteger = -1;
      //qry_insrenen->Open();

     try {
       qry_renentra->Tag = NO_REFRESH;
       dm->manvehi->StartTransaction();
       for(ii_z = 0; ii_z < Frame_datossabanaagre->edt_canti->Value; ii_z++) {
         if(tipo_z == "ALF" || dm->foliosalf_z ) {
           serie_z = Frame_datossabanaagre->qry_folsel->FieldByName("serie")->AsString;
           //idserie_z = dm->busca_iddato(serie_z, SERIE);
           folio_z = Frame_datossabanaagre->qry_folsel->FieldByName("folio")->AsInteger;
         } else {
           idserie_z = 0;
           serie_z = "";
         }
         qry_folsale->Close();
         qry_folsale->ParamByName("codigo")->AsString = codigo_z;
         qry_folsale->ParamByName("alm")->AsString = alm_z;
         qry_folsale->ParamByName("folio")->AsInteger = folio_z;
         qry_folsale->Open();
         if(qry_folsale->IsEmpty()) {
           dm->manvehi->Rollback();
           Application->MessageBox(("No tengo disponible el folio "+IntToStr(folio_z)).c_str(), "ERROR", MB_ICONEXCLAMATION);
           return;
         }
         if(siono_z == "N")
           piva_z = 0;
         else
           piva_z = Frame_datossabanaagre->qry_inven->FieldByName("piva")->AsFloat;
         // ->End if
         //select a.codigo, a.idart, b.idmovart, b.idalm, b.costo, b.modent,
         //b.folio, b.idserie, b.fecha, c.serie,
         //b.entcan, b.fecentori, facpro, b.idprove

         entcan_z = qry_folsale->FieldByName("entcan")->AsString;
         costo_z = qry_folsale->FieldByName("costo")->AsFloat;
         //nombre_z = Frame_datossabanaagre->edt_nombre->Text;
         status_z = Frame_datossabanaagre->cmb_status->Text;

         //idrenentra_z=dm->busca_sigid(IDRENENTRA);
         qry_renentra->Append();
         //qry_renentra->FieldByName("idrenentra")->AsInteger = idrenentra_z;
         qry_renentra->FieldByName("tipo")->AsString = sTipo;
         qry_renentra->FieldByName("alm")->AsString = alm_z;
         qry_renentra->FieldByName("recemi")->AsString = ptovta_z;
         qry_renentra->FieldByName("numero")->AsInteger = nentrada_z;
         //qry_insrenen->FieldByName("idart")->AsInteger = idart_z;
         qry_renentra->FieldByName("codinv")->AsString = codigo_z;
         //qry_renentra->FieldByName("iddescri")->AsInteger = iddescri_z;
         qry_renentra->FieldByName("descri")->AsString = descri_z;
         qry_renentra->FieldByName("serie")->AsString = serie_z;
         qry_renentra->FieldByName("conse")->AsInteger = ++conse_z;
         qry_renentra->FieldByName("siono")->AsString = siono_z;
         qry_renentra->FieldByName("folsal")->AsInteger = folio_z;
         qry_renentra->FieldByName("folent")->AsInteger = crdocon_z;
         qry_renentra->FieldByName("unids")->AsInteger = 1;
         if( sTipo != "Q") {
            qry_renentra->FieldByName("costou")->AsFloat = costo_z;
            qry_renentra->FieldByName("importe")->AsFloat = costo_z;
         } else {
           qry_renentra->FieldByName("costou")->AsFloat = 0;
           qry_renentra->FieldByName("importe")->AsFloat = 0;
         }
         qry_renentra->FieldByName("piva")->AsFloat = piva_z;
         qry_renentra->FieldByName("cantmueve")->AsFloat = cantmueve_z;
         if(cantmueve_z) cantmueve_z = 0;
         qry_renentra->FieldByName("status")->AsString = "A"; //status_z;
         qry_renentra->FieldByName("persenvrec")->AsInteger = idpers_z;
         qry_renentra->FieldByName("vend")->AsString = vendedor_z;
         qry_renentra->FieldByName("poblac")->AsInteger = idciudad_z;
         qry_renentra->FieldByName("tipago")->AsString = tipago_z;
         qry_renentra->FieldByName("prvta")->AsFloat = prvta_z;
         qry_renentra->FieldByName("entosal")->AsString = "S";
         qry_renentra->FieldByName("entcan")->AsString = entcan_z;
         qry_renentra->FieldByName("concepto")->AsString = nombre_z;
         //qry_renentra->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
         qry_renentra->FieldByName("cia")->AsInteger = cia_z;
         qry_renentra->Post();
         qsEntradas->Edit();
         qsEntradas->FieldByName("importe")->AsFloat       += costo_z;
         qsEntradas->FieldByName("iva")->AsFloat           += costo_z * piva_z / 100;
         qsEntradas->FieldByName("total")->AsFloat         += costo_z * ((piva_z / 100) + 1);
         qsEntradas->Post();
         Frame_datossabanaagre->qry_folsel->Next();
       }
       qsEntradas->ApplyUpdates();
       qry_renentra->ApplyUpdates();
       dm->manvehi->Commit();
        //qry_renentra->Close();
        //qry_renentra->ParamByName("identrada")->AsInteger = qsEntradas->FieldByName("identrada")->AsInteger;
        //qry_renentra->Open();
      } catch (Exception &E)
      {
        dm->manvehi->Rollback();
        Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
      }
   }
   delete Frame_datossabanaagre;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::edicion_factible(int modo_z)
{
  bool modo_enabled = true, modo_readonly = false;
  switch (modo_z) {
    case READ_WRITE: modo_enabled = true; modo_readonly = false; break;
    case READ_ONLY: modo_enabled = false; modo_readonly = true; break;
  }
  Frame_datossabanaagre1->edt_codigo->ReadOnly = modo_readonly;
  Frame_datossabanaagre1->lkcmb_vendedr->Enabled = modo_enabled;
  Frame_datossabanaagre1->lkcmb_ptovta->Enabled = modo_enabled;
  Frame_datossabanaagre1->lkcmb_poblac->Enabled = modo_enabled;
  Frame_datossabanaagre1->cmb_status->Enabled = modo_enabled;
  Frame_datossabanaagre1->edt_canti->ReadOnly = modo_readonly;
  Frame_datossabanaagre1->edt_nombre->ReadOnly = modo_readonly;
  Frame_datossabanaagre1->edt_codigo->ReadOnly = modo_readonly;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::CierraRenExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z;
  if(qry_renentra->IsEmpty()) return;
  if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
     return;
  }
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este Renglón ya ha sido previamente Cerrado", "Renglón Cerrado", MB_ICONERROR);
    return;
  }
  int ii_z = Application->MessageBox("Esta Seguro de Afectar Kardex ? \n una vez cerrado No puede dar marcha atrás", "Cerrar Renglón", MB_OKCANCEL | MB_ICONQUESTION );
  if (ii_z != IDOK ) return;
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
  Form_kardex->fechaabierta_z = fechaabierta_z;
  cierre_ren_z = Form_kardex->salida_sabana_vtas(
      codigo_z, serie_z, folio_z, fecha_z,
      alm_z, ptovta_z, sTipo,
      idcomprador_z, siono_z, nsabana_z, npoblac_z, numren_z
  );
  if(!cierre_ren_z) {
    Application->MessageBox
      (Form_kardex->errores_z->Text.c_str(),
       "ERROR: Renglón NO Cerrado", MB_ICONERROR
    );
  } else {
    Application->MessageBox
      ("Todos los Movimientos Han sido efectuados",
       "Renglón Cerrado", MB_OK
    );
    qry_renentra->Edit();
    qry_renentra->FieldByName("Status")->AsString = "C";
    qry_renentra->Post();
  }
  delete Form_kardex->errores_z;
  delete Form_kardex;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::cancela_renglonExecute(TObject *Sender)
{

  permis_z=dm->busca_permision(CAPVTAS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede Eliminar Renglones", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  
  double costo_z, piva_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este renglón ya ha sido cerrado, no lo puede eliminar", "RENGLON CERRADO", MB_ICONEXCLAMATION);
    return;
  }
  int ii_z = Application->MessageBox("Esta Seguro de Eliminar este Renglón ?", "Eliminar Renglón", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
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

void __fastcall TForm_capturaventas::dbgrdRengCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
    
}
//---------------------------------------------------------------------------


void __fastcall TForm_capturaventas::exporta_dbgrdExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//TAdvStringGrid* misgrd_z;
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

void __fastcall TForm_capturaventas::imprimeExecute(TObject *Sender)
{
  double piva_z=0, importe_z=0, iva_z=0, total_z=0, costo_z=0;
  String arch_z = Name+"txt", serie_z="", vnd_z="", pvta_z="", ciu_z="", croc_z;
  if(qsEntradas->FieldByName("status")->AsString != "C") {
    mensaje_z = "debe cerrar " + este_z + " " + titulo_z +
    " para poder imprimir";
    titmsg_z = "Imposible Imprimir " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }

  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresión de " + titulo_z;
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
    Frame_datossabanaagre1->lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
    ciu_z = Frame_datossabanaagre1->qry_Poblacion->FieldByName("nombre")->AsString;
    if( sTipo != "Q") {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
    } else {
        costo_z = qry_renentra->FieldByName("prvta")->AsFloat;
    }
    fprintf(archout, "%s %s|",
      ljust(qry_renentra->FieldByName("codinv")->AsString, 13),
      ljust(qry_renentra->FieldByName("descri")->AsString, 30)
    );
    fprintf(archout, "%s|", rjust(IntToStr(qry_renentra->FieldByName("folsal")->AsInteger), 5));
    fprintf(archout, "%s|", ljust(qry_renentra->FieldByName("serie")->AsString, 20));
    fprintf(archout, "%s|", ljust(qry_renentra->FieldByName("siono")->AsString, 1));
    fprintf(archout, "%s|", ljust(qry_renentra->FieldByName("concepto")->AsString, 20));
    fprintf(archout, "%s|", ljust(pvta_z, 4));
    fprintf(archout, "%s|", ljust(vnd_z, 4));
    fprintf(archout, "%s|", rjust(FormatFloat("#,###,##0.00", costo_z), 12));
    fprintf(archout, "%s|", ljust(ciu_z, 10));
    if(sTipo == "V") {
      croc_z = dm->busca_dato(qry_renentra->FieldByName("folent")->AsInteger, IDCREDCON);
      fprintf(archout, "%s|", ljust(croc_z, 4));
    }
    salta_linea(1);
    piva_z = qry_renentra->FieldByName("piva")->AsFloat;
    importe_z += costo_z;
    iva_z += qry_renentra->FieldByName("costou")->AsFloat * (piva_z / 100);
    total_z = importe_z + iva_z;
  }
  fprintf(archout, "%s",
    rjust(
      "Importe:" + FormatFloat("#,###,##0.00", importe_z) +
      "   Iva:" + FormatFloat("#,###,##0.00", iva_z) +
      "   Total:" + FormatFloat("#,###,##0.00", total_z), 117
    )
  );
  salta_linea(1);
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renentra->Tag = SI_REFRESH;
  qry_renentra->EnableControls();
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::salta_linea(int numlineas_z)
{
  for(; numlineas_z > 0; numlineas_z--) {
    fprintf(archout, "\n"); lineas_z++;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::report_encab()
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
    Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString,
    Frame_datoscaptrasp1->qry_Almacen->FieldByName("nombre")->AsString,
    FormatDateTime("dd-mm-yyyy", qsEntradas->FieldByName("fecha")->AsDateTime),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s%s",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s|", cjust("Articulo", 44));
  fprintf(archout, "%s|", rjust("Folio", 5));
  fprintf(archout, "%s|", ljust("Serie", 20));
  fprintf(archout, "%s|", "S");
  fprintf(archout, "%s|", ljust("Cliente", 20));
  fprintf(archout, "%s|", ljust("Pvta", 4));
  fprintf(archout, "%s|", ljust("Vnd", 4));
  fprintf(archout, "%s|", rjust("Costo_Unitar", 12));
  fprintf(archout, "%s|", ljust("Poblacion", 10));
  if(sTipo == "V") {
    fprintf(archout, "%s|", "Cr/C");
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z = 3;
  salta_linea(1);
//  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::cancelarExecute(TObject *Sender)
{
  grabar->Tag = EN_ESPERA;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------


void __fastcall TForm_capturaventas::capobsExecute(TObject *Sender)
{

    TForm_CapturaObsPed *Form_CapturaObsPed = new TForm_CapturaObsPed(this,
       qsEntradas->FieldByName("Tipo")->AsString,
       qsEntradas->FieldByName("Alm" )->AsString,
       qsEntradas->FieldByName("numero")->AsInteger,
       cia_z,
       "", permis_z
    );
    Form_CapturaObsPed->ShowModal();
    delete Form_CapturaObsPed;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::deshacer_afectacionExecute(
      TObject *Sender)
{

  permis_z=dm->busca_permision(CAPRELVTAM2);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString != "C") {
    Application->MessageBox("Este Renglón no ha sido previamente Cerrado", "Renglón NO Cerrado", MB_ICONERROR);
    return;
  }
  mensaje_z = "Esta seguro de deshacerr este Renglón ? ";
  titmsg_z = "Deshacer Afectacion Kardex";

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) != IDYES) {
    return;
  }

  siono_z = qry_renentra->FieldByName("siono")->AsString;
  folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
  codigo_z = qry_renentra->FieldByName("codinv")->AsString;
  serie_z = qry_renentra->FieldByName("serie")->AsString;
  alm_z   = qry_renentra->FieldByName("alm")->AsString;
  if(sTipo == "M") {
    ptovta_z = qsEntradas->FieldByName("prove")->AsString;
  } else {
    ptovta_z = qry_renentra->FieldByName("recemi")->AsString;
  }
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
       "ERROR: Renglón NO Cerrado", MB_ICONERROR
    );
  } else {
    Application->MessageBox
      ("Todos los Movimientos Han sido efectuados",
       "Renglón Cerrado", MB_OK
    );
    qry_renentra->Edit();
    qry_renentra->FieldByName("Status")->AsString = "A";
    qry_renentra->Post();
  }
  delete Form_kardex->errores_z;
  delete Form_kardex;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capturaventas::cambia_pto_vtaExecute(TObject *Sender)
{
  bool cierre_ren_z;
  if (qry_renentra->IsEmpty()) return;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString != "C") {
    Application->MessageBox("Este Renglón NO ha sido previamente Cerrado", "Renglón Abierto", MB_ICONERROR);
    return;
  }
  AnsiString nvoptovta_z = qry_renentra->FieldByName("recemi")->AsString;
  if (InputQuery("Cambio de Punto de Venta", "Proporcione el Nuevo Punto de Venta", nvoptovta_z)) {
    if(nvoptovta_z != qry_renentra->FieldByName("recemi")->AsString) {
      TForm_kardex *Form_kardex = new TForm_kardex (this);
      cierre_ren_z = Form_kardex->cambia_punto_venta(
        qsEntradas->FieldByName("fecha")->AsDateTime,
        nvoptovta_z,
        qsEntradas->FieldByName("alm")->AsString,
        sTipo,
        qsEntradas->FieldByName("numero")->AsInteger,
        qry_renentra->FieldByName("conse")->AsInteger
      );
      if(!cierre_ren_z) {
        Application->MessageBox
          (Form_kardex->errores_z->Text.c_str(),
           "ERROR: Renglón NO Cerrado", MB_ICONERROR
        );
      } else {
        Application->MessageBox
          ("Todos los Movimientos Han sido efectuados",
           "Renglón Cerrado", MB_OK
        );
        qry_renentra->Edit();
        qry_renentra->FieldByName("recemi")->AsString = nvoptovta_z;
        qry_renentra->Post();

      }
      delete Form_kardex->errores_z;
      delete Form_kardex;
    }
  }
}
//---------------------------------------------------------------------------






void __fastcall TForm_capturaventas::dbgrdRengKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if( Key == VK_DELETE) cancela_renglonExecute(Sender);
  if( Key == VK_INSERT) nuevoExecute(Sender);
  if( Key == VK_F2)     CierraRenExecute(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TForm_capturaventas::Frame_datoscaptrasp1edt_numeroKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarEntrada(Frame_datoscaptrasp1->edt_numero->Value) ) {
           Application->MessageBox("No Existe El Numero de Entrada Solicitado !!", "Entrada", MB_OK | MB_ICONQUESTION);
           return;
       }
       //ListarRenglon();
    }

}
//---------------------------------------------------------------------------


void __fastcall TForm_capturaventas::cierra_entradaExecute(TObject *Sender)
{
  bool si_cerrar = true;
  String alm_z;
  int nument_z = 0;
  alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  if(!BuscarEntrada(nument_z)) return;
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  if(qsEntradas->IsEmpty()) return;
  if(qsEntradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede cerrar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Cerrar" + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  mensaje_z = "Esta seguro de cerrar " + este_z + " " + titulo_z + " ? ";
  titmsg_z = "Cerrar " + titulo_z;

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {

    for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
      if(qry_renentra->FieldByName("status")->AsString == "A") {
        CierraRenExecute(Sender);
      }
    }
    for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
      if(qry_renentra->FieldByName("status")->AsString == "A") {
        si_cerrar = false;
      }
    }
    if(si_cerrar == false) {
      mensaje_z = este_z + " " + titulo_z + " tiene renglones sin cerrar, " +
      " debe afectar todos los renglones para cerrar ";
      titmsg_z = "Imposible Cerrar" + titulo_z;
      Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
      return;
    }
    qsEntradas->Edit();
    qsEntradas->FieldByName("status")->AsString = "C";
    qsEntradas->Post();
    try {
      dm->manvehi->StartTransaction();
      qsEntradas->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::despliega_menuExecute(TObject *Sender)
{
  PopupMenu1->Popup(100, 100);        
}
//---------------------------------------------------------------------------



void __fastcall TForm_capturaventas::abrir_sabanaExecute(TObject *Sender)
{
  String mensaje_z, titmsg_z;
  if(qsEntradas->State == dsInactive) return;
  if(qsEntradas->FieldByName("status")->AsString == "C") return;
  mensaje_z = "Esta seguro de Abrir" + este_z + " " + titulo_z + " ? ";
  titmsg_z = "Abrir " + titulo_z;

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    qsEntradas->Edit();
    qsEntradas->FieldByName("status")->AsString = "A";
    qsEntradas->Post();
    try {
      dm->manvehi->StartTransaction();
      qsEntradas->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capturaventas::FormShow(TObject *Sender)
{
   cia_z = dm->cia_z;        
}
//---------------------------------------------------------------------------



