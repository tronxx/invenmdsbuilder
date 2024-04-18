//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_capentes.h"
#include "dlgCataAlmacen.h"
#include "dmod.h"
#include "impre.h"
#include "Frm_selserie.h"
#include "Frm_kardex.h"
#include "imprigra.h"
#include "numapal.h"
#include "Frm_prever.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBELib"
#pragma link "Frme_datoscaptrasp"
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_capentes *Form_capentes;
//---------------------------------------------------------------------------
//const int iTpcon=100;  //SABANAS DE FIDE
//const int iTpcon1=110; //SABANA VENTAS CELULARES
//const int iTpcon2=20; //SABANA DE VENTAS TRADICIONAL

//---------------------------------------------------------------------------
void _fastcall CapEntes(TForm *Padre, String tiposab, bool estado)
{
    try
    {
        Form_capentes = new TForm_capentes(Padre, tiposab, estado);
        Form_capentes->Show();
    }
    catch(...)
    { }

}
//---------------------------------------------------------------------------
__fastcall TForm_capentes::TForm_capentes(TComponent* Owner, String tipo_sabana, bool estado)
    : TForm(Owner)
{
  sTipo = tipo_sabana;
  cia_z = dm->cia_z;
  qsAlmacen->Close();
  qsAlmacen->ParamByName("cia")->AsInteger = cia_z;
  qsAlmacen->Open();
  Frame_datoscaptrasp1->inicializa(tipo_sabana);
  if(sTipo == "P") {
    tipoest_z = EST_X_ENT_ESP;
    titulo_z = "Sabana Entradas Especiales";
    genero_z = "F";
  } else if(sTipo == "Q") {
    tipoest_z = EST_X_VTA_CEL;
    titulo_z = "Sabana Ventas Celular";
    genero_z = "F";
    edt_prvta->Visible = true;
    lbl_prvta->Visible = true;
  } else if(sTipo == "I") {
    tipoest_z = EST_X_VTA_FID;
    titulo_z = "Sabana Ventas Fide";
    genero_z = "F";
  } else if(sTipo == "F") {
    tipoest_z = EST_X_VTA_FON;
    titulo_z = "Sabana Ventas FONACOT";
    genero_z = "F";
  }
  Caption = "Captura de " + titulo_z;
  if(genero_z == "M") {
    este_z = "Este";
    cerrado_z = "Cerrado";
  } else {
    este_z = "Esta";
    cerrado_z = "Cerrada";
  }
  idpermis_z = CAPVTAS;
  permis_z=dm->busca_permision(idpermis_z);
  if(permis_z == "N") {
    Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    Close();
  }
  if( dm->usermaster_z == "S") {
    deshacer_afeckardex->Visible = true;
  } else {
    deshacer_afeckardex->Visible = false;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::btnNuevoClick(TObject *Sender)
{
    LimpiarPantalla();
    //cmbTipoEnt->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm_capentes::LimpiarPantalla()
{
}
//---------------------------------------------------------------------------

bool __fastcall TForm_capentes::BuscarAlmacen(String sClave)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::BuscarUltimoReg()
{
}
//---------------------------------------------------------------------------
bool __fastcall TForm_capentes::BuscarEntrada(int iNumero)
{
    bool bResult = false;
    String alm_z;
    alm_z = qsAlmacen->FieldByName("clave")->AsString;
    qsEntradas->Close();
    qsEntradas->ParamByName("Tipo"  )->AsString = sTipo;
    qsEntradas->ParamByName("Alm"   )->AsString  = alm_z;
    qsEntradas->ParamByName("Numero")->AsInteger = iNumero;
    qsEntradas->ParamByName("Cia"   )->AsInteger = cia_z;
    qsEntradas->Open();
    if (!qsEntradas->IsEmpty() ) {
       //TODO: Se puede desactivar x que existe
       //ListaRenglones;
      Frame_datoscaptrasp1->date_fecha->Date = qsEntradas->FieldByName("Fecha")->AsDateTime;
       bResult = true;
    }
    ListarRenglon();
    return bResult;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::btn_salirClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::ListarRenglon()
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

void __fastcall TForm_capentes::qry_renentraAfterScroll(TDataSet *DataSet)
{
  int idnombre_z=0;
  if (!qry_renentra->Active || qry_renentra->IsEmpty() || qry_renentra->Tag == INACTIVO ) return;
  idnombre_z = qry_renentra->FieldByName("PerSenvRec")->AsInteger;
  lkcmb_vendedr->KeyValue = qry_renentra->FieldByName("Vend")->AsString;
  lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
  lkcmb_ptovta->KeyValue = qry_renentra->FieldByName("RecEmi")->AsString;
  edt_nombre->Text = qry_renentra->FieldByName("concepto")->AsString;
  edt_prvta->Value = qry_renentra->FieldByName("prvta")->AsFloat;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capentes::BuscarVendedor(String sVendedor)
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
void __fastcall TForm_capentes::BuscarPoblacion(int iPoblac)
{
    //qsPoblacion->Close();
    //qsPoblacion->ParamByName("Numero")->AsInteger = iPoblac;
    //qsPoblacion->Open();
    //if (qsPoblacion->IsEmpty() )
    //      edtPoblacion->Text = "";
    //else  edtPoblacion->Text = qsPoblacion->FieldByName("Nombre")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capentes::BuscarPuntoVenta(String sClave)
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
void __fastcall TForm_capentes::BuscarConcepto(int iCliente)
{
    qsConceps->Close();
    qsConceps->ParamByName("NCon")->AsInteger = iCliente;
    qsConceps->Open();
    if (qsConceps->IsEmpty() )
         edt_nombre->Text = "NO EXISTE CONCEPTO";
    else edt_nombre->Text = qsConceps->FieldByName("Concepto")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    Form_capentes = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::SigteSabana(int tipo_mov)
{
  TQuery *qsSigte = new TQuery (this);
  String alm_z;
  int nument_z=0;
  alm_z = qsAlmacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  qsSigte->DatabaseName = qsAlmacen->DatabaseName;
  switch (tipo_mov) {
    case SIGTE:
      qsSigte->SQL->Text = "select min(numero) as numero from entradas where tipo = :TIPO and alm = :ALM and numero > :NUMERO and cia = :cia";
      break;
    case ANTER:
      qsSigte->SQL->Text = "select max(numero) as numero from entradas where tipo = :TIPO and alm = :ALM and numero < :NUMERO and cia = :cia";
      break;
    case ULTIMO:
      qsSigte->SQL->Text = "select max(numero) as numero from entradas where tipo = :TIPO and alm = :ALM and ( numero <= :NUMERO or  numero >= :NUMERO ) and cia = :cia";
      break;
    case PRIMERO:
      qsSigte->SQL->Text = "select min(numero) as numero from entradas where tipo = :TIPO and alm = :ALM and ( numero <= :NUMERO or  numero >= :NUMERO ) and cia = :cia";
      break;
    }
  qsSigte->ParamByName("tipo")->AsString = sTipo;
  qsSigte->ParamByName("alm")->AsString = alm_z;
  qsSigte->ParamByName("numero")->AsInteger = nument_z;
  qsSigte->ParamByName("cia")->AsInteger = cia_z;
  qsSigte->Open();
  if(!qsSigte->IsEmpty()) {
    nument_z = qsSigte->FieldByName("numero")->AsInteger;
    Frame_datoscaptrasp1->edt_numero->Value = nument_z;
    BuscarEntrada(nument_z);
  }
  delete qsSigte;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentes::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------



void __fastcall TForm_capentes::nuevoExecute(TObject *Sender)
{
  TQuery *qsSigte = new TQuery (this);
  String alm_z;
  int nument_z=0;
  alm_z = qsAlmacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  qsSigte->DatabaseName = qsAlmacen->DatabaseName;
  qsSigte->SQL->Text = "select max(numero) as numero from entradas where tipo = :TIPO and alm = :ALM and cia = :cia";
  qsSigte->ParamByName("tipo")->AsString = sTipo;
  qsSigte->ParamByName("alm")->AsString = alm_z;
  qsSigte->ParamByName("cia")->AsInteger = cia_z;
  qsSigte->Open();
  if(!qsSigte->IsEmpty()) {
    nument_z = qsSigte->FieldByName("numero")->AsInteger;
  }
  nument_z++;
  Frame_datoscaptrasp1->edt_numero->Value = nument_z;
  delete qsSigte;
  Frame_datoscaptrasp1->date_fecha->Date = Now();
  grabar->Tag = NUEVO;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::botones_onoff(int modo_z)
{
  switch (modo_z) {
    case INVISIBLES:
      nuevo->Enabled=false;
      modifica->Enabled=false;
      borra->Enabled=false;
      grabar->Enabled=true;
      cancelar->Enabled=true;
      grp_datosren->Enabled=false;
//      pnl_btngral->Visible=false;
      break;
    case VISIBLES:
//      pnl_btngral->Visible=true;
      nuevo->Enabled=true;
      modifica->Enabled=true;
      borra->Enabled=true;
      grabar->Enabled=false;
      cancelar->Enabled=false;
      grp_datosren->Enabled=true;
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  String permis_z = "T", alm_z;
  int nument_z = 0;
  alm_z = qsAlmacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  if(!BuscarEntrada(nument_z)) return;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
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



void __fastcall TForm_capentes::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_ptvt(); break;
    case MODIF: modif_ptvt(); break;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::alta_ptvt()
{
   String alm_z;
   TDateTime fecha_z;
   int nument_z = 0;
   alm_z = qsAlmacen->FieldByName("clave")->AsString;
   fecha_z = Frame_datoscaptrasp1->date_fecha->Date;
   nument_z = Frame_datoscaptrasp1->edt_numero->Value;
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
   grabar->Tag = 0;
   botones_onoff(VISIBLES);
   BuscarEntrada(nument_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::edt_cantiExit(TObject *Sender)
{
  int folio_z = 0;
  String alm_z, codigo_z;
  alm_z = qsAlmacen->FieldByName("clave")->AsString;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  qry_folsigent->Close();
  qry_folsigent->ParamByName("codigo")->AsString = codigo_z;
  qry_folsigent->ParamByName("alm")->AsString = alm_z;
  qry_folsigent->ParamByName("cia")->AsInteger = cia_z;
  qry_folsigent->Open();
  folio_z = qry_folsigent->FieldByName("ultfol")->AsInteger;
  edt_folios->Text = IntToStr(folio_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentes::agrerenExecute(TObject *Sender)
{
  if( mi_entrada_z == SIN_ENTRADA) {
    mensaje_z = "Aun no ha accesado " + titulo_z;
    titmsg_z = "Sin " + titulo_z;

    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION);
    return;
  }
  if( qsEntradas->FieldByName("status")->AsString == "C" ) {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede modificar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Modificar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION);
    return;
  }
  edicion_factible(READ_WRITE);
  btn_nvoren->Enabled = false;
  btn_canceren->Enabled = true;
  btn_aceptaren->Enabled = true;
  btn_nvoren->Tag = NUEVO;
  edt_serie->Text = "";
  edt_canti->Value = 0;
  Form_selserie = NULL;
  edt_codigo->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::edicion_factible(int modo_z)
{
  bool modo_enabled = true, modo_readonly = false;
  switch (modo_z) {
    case READ_WRITE: modo_enabled = true; modo_readonly = false; break;
    case READ_ONLY: modo_enabled = false; modo_readonly = true; break;
  }
  lkcmb_vendedr->Enabled = modo_enabled;
  lkcmb_ptovta->Enabled = modo_enabled;
  lkcmb_poblac->Enabled = modo_enabled;
  cmb_status->Enabled = modo_enabled;
  edt_codigo->ReadOnly = modo_readonly;
  edt_canti->ReadOnly = modo_readonly;
  edt_nombre->ReadOnly = modo_readonly;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentes::acepta_renExecute(TObject *Sender)
{
  int idrenentra_z=0, folio_z=0, ii_z=0, conse_z = 0, idalm_z = 0, idart_z = 0,
  identrada_z=0, idserie_z = 0, idpers_z=0, cantmueve_z=0, idvend_z=0,
  idciudad_z=0, idptovta_z=0, idcodigo_z=0, iddescri_z=0, nentrada_z;
  String tipo_z, siono_z="S", serie_z="", entcan_z="", vendedor_z, ptovta_z,
  descri_z, alm_z, codigo_z, nombre_z;
  double piva_z=0, costo_z =0, prvta_z=0;
  cantmueve_z = edt_canti->Value;
  if(cantmueve_z < 1) {
    Application->MessageBox(("No pueden ser "+ IntToStr((int)edt_canti->Value) + " Articulos").c_str(), "Incorrecto N�mero de Art�culos", MB_ICONEXCLAMATION);
    return;
  }
  tipo_z = qry_inven->FieldByName("tipo")->AsString;
  descri_z = qry_inven->FieldByName("descri")->AsString;
  if(tipo_z == "ALF" && edt_serie->Text.IsEmpty())  {
    Application->MessageBox("Debe proporcionar La Serie", "Serie Desconocida", MB_ICONEXCLAMATION);
    return;
  }
  vendedor_z = qry_vendedor->FieldByName("codigo")->AsString;
  nentrada_z = qsEntradas->FieldByName("numero")->AsInteger;
  if(!cmb_status->Text.IsEmpty()) siono_z = cmb_status->Text.SubString(1,1);
  //siono_z = qsEntradas->FieldByName("coniva")->AsString;
  alm_z = qsAlmacen->FieldByName("clave")->AsString;
  ptovta_z = qsPuntoVta->FieldByName("clave")->AsString;
  //idart_z = qry_inven->FieldByName("idart")->AsInteger;
  codigo_z =qry_inven->FieldByName("codigo")->AsString;
  //iddescri_z =dm->busca_iddato(qry_inven->FieldByName("descri")->AsString, CONCEPTO);
  piva_z = qry_inven->FieldByName("piva")->AsFloat;
  idpers_z = dm->busca_iddato(edt_nombre->Text.Trim(), OLDCONCEPTO);
  nombre_z = edt_nombre->Text;
  idciudad_z = qsPoblacion->FieldByName("numero")->AsInteger;
  costo_z = edt_costou->Value;
  entcan_z = cmb_entcan->Text;
  conse_z = dm->sigte_renentra(alm_z, sTipo, nentrada_z);
  if( sTipo == "Q") prvta_z = edt_prvta->Value;
  qry_folsigent->Close();
  qry_folsigent->ParamByName("codigo")->AsString = codigo_z;
  qry_folsigent->ParamByName("alm")->AsString = alm_z;
  qry_folsigent->ParamByName("cia")->AsInteger = cia_z;
  qry_folsigent->Open();
  folio_z = qry_folsigent->FieldByName("ultfol")->AsInteger + 1;
  if(tipo_z == "GLO") {
    serie_z = ""; idserie_z = 0;
  }
  //qry_conse->Close();
  //qry_conse->ParamByName("identrada")->AsInteger = identrada_z;
  //qry_conse->Open();
  //conse_z = qry_conse->FieldByName("ultren")->AsInteger;
  //qry_renentra->Close();
  //qry_insrenen->ParamByName("idrenentra")->AsInteger = -1;
  //qry_insrenen->Open();

  try {
    qry_renentra->Tag = NO_REFRESH;
    dm->manvehi->StartTransaction();
    for(ii_z = 0; ii_z < edt_canti->Value; ii_z++) {
      if(tipo_z == "ALF") {
        serie_z = edt_serie->Text.Trim();
        //idserie_z = dm->busca_iddato(serie_z, SERIE);
      } else {
        idserie_z = 0;
      }
      if(siono_z == "N")
        piva_z = 0;
      else
        piva_z = qry_inven->FieldByName("piva")->AsFloat;
      // ->End if
      //select a.codigo, a.idart, b.idmovart, b.idalm, b.costo, b.modent,
      //b.folio, b.idserie, b.fecha, c.serie,
      //b.entcan, b.fecentori, facpro, b.idprove
      //idrenentra_z=dm->busca_sigid(IDRENENTRA);
      qry_renentra->Append();
      //qry_renentra->FieldByName("idrenentra")->AsInteger = idrenentra_z;
      qry_renentra->FieldByName("tipo")->AsString = sTipo;
      qry_renentra->FieldByName("alm")->AsString = alm_z;
      qry_renentra->FieldByName("recemi")->AsString = ptovta_z;
      qry_renentra->FieldByName("numero")->AsInteger = nentrada_z;
      qry_renentra->FieldByName("conse")->AsInteger = conse_z++;
      //qry_insrenen->FieldByName("idart")->AsInteger = idart_z;
      qry_renentra->FieldByName("codinv")->AsString = codigo_z;
      qry_renentra->FieldByName("concepto")->AsString = nombre_z;
      //qry_renentra->FieldByName("iddescri")->AsInteger = iddescri_z;
      qry_renentra->FieldByName("descri")->AsString = descri_z;
      qry_renentra->FieldByName("serie")->AsString = serie_z;
//      qry_renentra->FieldByName("conse")->AsInteger = ++conse_z;
      qry_renentra->FieldByName("siono")->AsString = siono_z;
      qry_renentra->FieldByName("folsal")->AsInteger = 0;
      qry_renentra->FieldByName("folent")->AsInteger = folio_z;
      qry_renentra->FieldByName("unids")->AsInteger = 1;
      if( sTipo != "Q") {
        qry_renentra->FieldByName("costou")->AsFloat = costo_z;
        qry_renentra->FieldByName("importe")->AsFloat = costo_z;
      }
      qry_renentra->FieldByName("piva")->AsFloat = piva_z;
      qry_renentra->FieldByName("cantmueve")->AsFloat = cantmueve_z;
      if(cantmueve_z) cantmueve_z = 0;
      qry_renentra->FieldByName("status")->AsString = "A";
      qry_renentra->FieldByName("persenvrec")->AsInteger = idpers_z;
      qry_renentra->FieldByName("vend")->AsString = vendedor_z;
      qry_renentra->FieldByName("poblac")->AsInteger = idciudad_z;
      qry_renentra->FieldByName("tipago")->AsString = "";
      qry_renentra->FieldByName("prvta")->AsFloat = prvta_z;
      qry_renentra->FieldByName("entosal")->AsString = "E";
      qry_renentra->FieldByName("entcan")->AsString = entcan_z;
      //qry_renentra->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
      qry_renentra->FieldByName("cia")->AsInteger = cia_z;
      qry_renentra->Post();
      qsEntradas->Edit();
      qsEntradas->FieldByName("importe")->AsFloat       += costo_z;
      qsEntradas->FieldByName("iva")->AsFloat           += costo_z * piva_z / 100;
      qsEntradas->FieldByName("total")->AsFloat         += costo_z * ((piva_z / 100) + 1);
      qsEntradas->Post();
      if(Form_selserie != NULL) Form_selserie->qry_folsel->Next();
      folio_z++;
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
  edicion_factible(READ_ONLY);
  btn_nvoren->Enabled = true;
  btn_canceren->Enabled = false;
  btn_aceptaren->Enabled = false;
  btn_nvoren->Tag = EN_ESPERA;
  qry_renentra->Tag = SI_REFRESH;
  if(Form_selserie != NULL)  {
    delete Form_selserie; Form_selserie = NULL;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::btn_cancerenClick(TObject *Sender)
{
  edicion_factible(READ_ONLY);
  btn_nvoren->Enabled = true;
  btn_canceren->Enabled = false;
  btn_aceptaren->Enabled = false;
  btn_nvoren->Tag = EN_ESPERA;
  if(Form_selserie != NULL)  {
    delete Form_selserie; Form_selserie = NULL;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::CierraRenExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z, entcan_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
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
  costou_z = qry_renentra->FieldByName("costou")->AsFloat;
  entcan_z = qry_renentra->FieldByName("entcan")->AsString;

  TForm_kardex *Form_kardex = new TForm_kardex (this);
  cierre_ren_z = Form_kardex->entrada_sabana_cancel(
      codigo_z, serie_z, folio_z, fecha_z,
      alm_z, ptovta_z, sTipo, idcomprador_z, siono_z,
      nsabana_z, npoblac_z, numren_z, costou_z, entcan_z, ""
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

void __fastcall TForm_capentes::cancela_renglonExecute(TObject *Sender)
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

void __fastcall TForm_capentes::dbgrdRengCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
    
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentes::exporta_dbgrdExecute(TObject *Sender)
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

void __fastcall TForm_capentes::imprimeExecute(TObject *Sender)
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
    lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
    ciu_z = qsPoblacion->FieldByName("nombre")->AsString;
    if( sTipo != "Q") {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
    } else {
        costo_z = qry_renentra->FieldByName("prvta")->AsFloat;
    }

    fprintf(archout, "%s %s|%s|%s|%s|%s|%s|%s|%s|%s\n",
      ljust(qry_renentra->FieldByName("codinv")->AsString, 13),
      ljust(qry_renentra->FieldByName("descri")->AsString, 30),
      rjust(IntToStr(qry_renentra->FieldByName("folent")->AsInteger), 5),
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

  qry_renentra->Tag = SI_REFRESH;
  qry_renentra->EnableControls();
  if(dm->preview_z) {
    VistaPrevia(this, arch_z, dm->rutaimp_z, dm->tipoimp_z, dm->ff_z, dm->impresora_z);
  } else {
    manda_imp(arch_z, dm->rutaimp_z, dm->tipoimp_z, dm->ff_z, dm->impresora_z);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::report_encab()
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

void __fastcall TForm_capentes::cancelarExecute(TObject *Sender)
{
  grabar->Tag = EN_ESPERA;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentes::cmb_statusExit(TObject *Sender)
{
  if(cmb_status->Text == "S")
    edt_costou->Value = qry_inven->FieldByName("costos")->AsFloat;
  else
    edt_costou->Value = qry_inven->FieldByName("coston")->AsFloat;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
     busca_cod(edt_codigo->Text.Trim());
     if(qry_inven->IsEmpty()) {
       qry_buscod->Close();
       qry_buscod->ParamByName("codigo")->AsString = edt_codigo->Text.Trim() + "%%";
       qry_buscod->ParamByName("cia")->AsInteger = cia_z;
       qry_buscod->Open();
       if(qry_buscod->IsEmpty())
          Application->MessageBox("No existe ningun registro", "C�digo Inexistente", MB_ICONQUESTION);
       else {
           lkcmb_codigos->Left=edt_codigo->Left;
           lkcmb_codigos->Top=edt_codigo->Top;
           lkcmb_codigos->Width=edt_codigo->Width;
           lkcmb_codigos->Visible=true;
           lkcmb_codigos->KeyValue=qry_buscod->FieldByName("codigo")->AsString;
           edt_codigo->Visible=false;
           lkcmb_codigos->DropDown();
           ActiveControl=lkcmb_codigos;
         }
      }
   }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::lkcmb_codigosExit(TObject *Sender)
{
  lkcmb_codigos->Visible=false;
  edt_codigo->Visible=true;
  busca_cod(qry_buscod->FieldByName("codigo")->AsString);

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::lkcmb_codigosKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_RETURN){
    edt_codigo->Text = lkcmb_codigos->Text.Trim();
    lkcmb_codigos->Visible=false;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::busca_cod(String codigo_z)
{
  edt_codigo->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::Frame_datoscaptrasp1edt_numeroKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
       if (Key != VK_RETURN) {
         if (!BuscarEntrada(Frame_datoscaptrasp1->edt_numero->Value ) ) {
             Application->MessageBox("No Existe El Numero de Entrada Solicitado !!", "Entrada", MB_OK | MB_ICONQUESTION);
         }
       }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentes::deshacer_afeckardexExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z, entcan_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString != "C") {
    Application->MessageBox("Este Rengl�n no ha sido previamente Cerrado", "Rengl�n Abierto", MB_ICONERROR);
    return;
  }
  mensaje_z = "Esta seguro de deshacerr este Rengl�n ? ";
  titmsg_z = "Deshacer Afectacion Kardex";

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) != IDYES) {
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
  costou_z = qry_renentra->FieldByName("costou")->AsFloat;
  entcan_z = qry_renentra->FieldByName("entcan")->AsString;

  TForm_kardex *Form_kardex = new TForm_kardex (this);
  cierre_ren_z = Form_kardex->cancela_entrada_sabana_cancel(
      codigo_z, serie_z, folio_z, fecha_z,
      alm_z, ptovta_z, sTipo, idcomprador_z, siono_z,
      nsabana_z, npoblac_z, numren_z, costou_z, entcan_z
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

