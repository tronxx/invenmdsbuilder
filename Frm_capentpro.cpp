//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "Frm_prever.h"
#include "Frm_capentpro.h"
#include "dlgCataAlmacen.h"
#include "dmod.h"
#include "impre.h"
#include "Frm_selserie.h"
#include "Frm_kardex.h"
#include "imprigra.h"
#include "numapal.h"
#include "Frm_CapturaObsPed.h"
#include "Frme_datoscapentpro.h"
#include "dialg_okcancel.h"
#include "Frme_datoscapentproagre.h"
#include "Frme_datospedimento.h"
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
#pragma link "Frme_datoscapentpro"
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_capentpro *Form_capentpro;
//---------------------------------------------------------------------------
//const int iTpcon=100;  //SABANAS DE FIDE
//const int iTpcon1=110; //SABANA VENTAS CELULARES
//const int iTpcon2=20; //SABANA DE VENTAS TRADICIONAL

//---------------------------------------------------------------------------
void _fastcall CapEntPro(TForm *Padre, String tiposab, bool estado)
{
    try
    {
        Form_capentpro = new TForm_capentpro(Padre, tiposab, estado);
        Form_capentpro->Show();
    }
    catch(...)
    { }

}
//---------------------------------------------------------------------------
__fastcall TForm_capentpro::TForm_capentpro(TComponent* Owner, String tipo_sabana, bool estado)
    : TForm(Owner)
{
  int idpermis_z=0, poriva_z;
  sTipo = tipo_sabana;
  cia_z = dm->cia_z;
  Frame_datoscapentpro1->inicializa(sTipo);
  if(sTipo == "E") {
    tipoest_z = EST_X_ENT_COM;
    titulo_z = "Entradas Proveedor";
    genero_z = "F";
    idpermis_z = CAPENTPROV;
  } else if(sTipo == "Q") {
    tipoest_z = EST_X_VTA_CEL;
    titulo_z = "Sabana Ventas Celular";
    genero_z = "F";
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
  permis_z = dm->busca_permision(idpermis_z);
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  TIniFile *ini;
  String  basedato_z, config_z, bdcartera_z, alm_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  alm_z = "AL";
  alm_z    =  ini->ReadString( "Form_capentpro_"+ sTipo, "ALMACEN", alm_z );
  pivapag_z =  ini->ReadInteger( "Form_capentpro_"+ sTipo, "PORC_IVA", 16);
  Frame_datoscapentpro1->lkcmb_almacen->KeyValue = alm_z;
  if( dm->usermaster_z == "S") {
    deshacer_afectar->Visible = true;
  } else {
    deshacer_afectar->Visible = false;
  }

  delete ini;
  SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::btnNuevoClick(TObject *Sender)
{
    LimpiarPantalla();
    //cmbTipoEnt->SetFocus();
}
//---------------------------------------------------------------------------
void __fastcall TForm_capentpro::LimpiarPantalla()
{
    //edt_nument   ->Text    = 0;
    //date_fecha     ->Date    = TDateTime::CurrentDate();
    //edt_nombre  ->Text    = "";
    //edtVendedor ->Text    = "";
    //lblVendedor ->Text    = "";
    //edtPoblacion->Text    = "";
    //edtPuntoVta ->Text    = "";
    //lblPuntoVta ->Caption = "";
}
//---------------------------------------------------------------------------

bool __fastcall TForm_capentpro::BuscarEntrada(int iNumero)
{
    bool bResult = false;
    String alm_z;
    alm_z = Frame_datoscapentpro1->qry_almacen->FieldByName("clave")->AsString;
    qry_entradas->Close();
    qry_entradas->ParamByName("Tipo"  )->AsString = sTipo;
    qry_entradas->ParamByName("Alm"   )->AsString  = alm_z;
    qry_entradas->ParamByName("Numero")->AsInteger = iNumero;
    qry_entradas->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_entradas->Open();
    if (!qry_entradas->IsEmpty() ) {
       //TODO: Se puede desactivar x que existe
       //ListaRenglones;
       Frame_datoscapentpro1->date_fecha->Date = qry_entradas->FieldByName("Fecha")->AsDateTime;
       Frame_datoscapentpro1->lkcmb_prove->KeyValue  = qry_entradas->FieldByName("prove")->AsString;
       Frame_datoscapentpro1->lkcmb_planp->KeyValue =  qry_entradas->FieldByName("planp")->AsInteger;
       Frame_datoscapentpro1->edt_facpro->Text = qry_entradas->FieldByName("facpro")->AsString;
       Frame_datoscapentpro1->date_fecha->Date = qry_entradas->FieldByName("fecha")->AsDateTime;
       Frame_datoscapentpro1->date_prpago->Date = qry_entradas->FieldByName("fechaprp")->AsDateTime;
       Frame_datoscapentpro1->date_ulpago->Date = qry_entradas->FieldByName("vence")->AsDateTime;
       Frame_datoscapentpro1->edt_nulets->Value = qry_entradas->FieldByName("letras")->AsInteger;
       Frame_datoscapentpro1->edt_tasaent->Value = qry_entradas->FieldByName("tascomp")->AsFloat;
       Frame_datoscapentpro1->edt_tasapro->Value = qry_entradas->FieldByName("taspro")->AsFloat;
       Frame_datoscapentpro1->edt_nument->Value = iNumero;
       despliega_totales();
       bResult = true;
    }
    ListarRenglon();
    if(qry_entradas->FieldByName("status"  )->AsString == "C") {
      cierra_ent->Enabled = false;
      imprime->Enabled = true;
    } else {
      cierra_ent->Enabled = true;
      imprime->Enabled = false;
    }
    grp_datosren->Enabled = true;
    return bResult;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentpro::despliega_totales()
{
       Frame_datoscapentpro1->edt_cfc->Value = qry_entradas->FieldByName("ctofincomp")->AsFloat;
       Frame_datoscapentpro1->edt_cfp->Value = qry_entradas->FieldByName("ctofin")->AsFloat;
       Frame_datoscapentpro1->edt_desxapli->Value = qry_entradas->FieldByName("desxap")->AsFloat;
       Frame_datoscapentpro1->edt_flete->Value = qry_entradas->FieldByName("fletes")->AsFloat;
       Frame_datoscapentpro1->edt_grtotal->Value = qry_entradas->FieldByName("importe")->AsFloat +
       qry_entradas->FieldByName("iva")->AsFloat +
       Frame_datoscapentpro1->edt_flete->Value + Frame_datoscapentpro1->edt_cfc->Value + Frame_datoscapentpro1->edt_cfp->Value;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::ListarRenglon()
{
    qry_renentra->Tag = INACTIVO;
    String alm_z;
    int num_z;
    alm_z = Frame_datoscapentpro1->qry_almacen->FieldByName("clave")->AsString;
    num_z = qry_entradas->FieldByName("Numero")->AsInteger;
    qry_renentra->Close();
    qry_renentra->ParamByName("Tipo")->AsString = sTipo;
    qry_renentra->ParamByName("Alm" )->AsString  = alm_z;
    qry_renentra->ParamByName("Numero")->AsInteger = num_z;
    qry_renentra->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_renentra->Open();
    qry_renentra->Tag = ACTIVO;
    dbgrd_renentra->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    Form_capentpro = NULL;
    TIniFile *ini;
    String  basedato_z, config_z, bdcartera_z, alm_z;
    config_z = dm->busca_inifile();
    ini = new TIniFile(config_z);
    alm_z    = Frame_datoscapentpro1->qry_almacen->FieldByName("clave")->AsString;
    ini->WriteString( "Form_capentpro_"+ sTipo, "ALMACEN", alm_z );
    ini->WriteInteger( "Form_capentpro_"+ sTipo, "PORC_IVA", pivapag_z);
    delete ini;

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::SigteSabana(int tipo_mov)
{
  TQuery *qsSigte = new TQuery (this);
  String alm_z;
  int nument_z=0;
  alm_z = Frame_datoscapentpro1->qry_almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscapentpro1->edt_nument->Value;
  qsSigte->DatabaseName = Frame_datoscapentpro1->qry_almacen->DatabaseName;
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
    Frame_datoscapentpro1->edt_nument->Value = nument_z;
    BuscarEntrada(nument_z);
  }
  delete qsSigte;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentpro::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------



void __fastcall TForm_capentpro::nuevoExecute(TObject *Sender)
{

 int ancho_z, alto_z, numero_z=0;
   String alm_z, strfecha_z, strfechoy_z, strfecatras_z;
   double fecha_z;
   bool todook_z = true;
   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datoscapentpro *Frame_datoscapentpro;
   Frame_datoscapentpro = new TFrame_datoscapentpro (Dlg_analipol);
   ancho_z = Frame_datoscapentpro->Width + 20;
   alto_z = Frame_datoscapentpro->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datoscapentpro->Parent = Dlg_analipol->Panel1;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Captura de Datos";
   Frame_datoscapentpro->Align = alClient;
   Frame_datoscapentpro->inicializa(sTipo);
   Frame_datoscapentpro->accion_z = NUEVO;
   Frame_datoscapentpro->nuevo();
   Dlg_analipol->Position = poScreenCenter;

   if( Dlg_analipol->ShowModal() == mrOk) {
     alm_z    = Frame_datoscapentpro->qry_almacen->FieldByName("clave")->AsString;
     fecha_z  = Frame_datoscapentpro->date_fecha->Date;
     numero_z = Frame_datoscapentpro->edt_nument->Value;
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
     Frame_datoscapentpro1->edt_facpro->Text    = Frame_datoscapentpro->edt_facpro->Text;
   //idnombre_z = dm->busca_iddato(qry_prove->FieldByName("nombre")->AsString, OLDCONCEPTO);
     Frame_datoscapentpro1->edt_cfc->Value      = Frame_datoscapentpro->edt_cfc->Value;
     Frame_datoscapentpro1->edt_tasaent->Value  = Frame_datoscapentpro->edt_tasaent->Value;
     Frame_datoscapentpro1->edt_tasapro->Value  = Frame_datoscapentpro->edt_tasapro->Value;
     Frame_datoscapentpro1->edt_nulets->Value   = Frame_datoscapentpro->edt_nulets->Value;
     Frame_datoscapentpro1->edt_flete->Value    = Frame_datoscapentpro->edt_flete->Value;
     Frame_datoscapentpro1->edt_desxapli->Value = Frame_datoscapentpro->edt_desxapli->Value;
     Frame_datoscapentpro1->lkcmb_planp->KeyValue  = Frame_datoscapentpro->qry_planesp->FieldByName("clave")->AsInteger;
     Frame_datoscapentpro1->edt_plazo->Value       = Frame_datoscapentpro->edt_plazo->Value;
     Frame_datoscapentpro1->edt_cfp->Value         = Frame_datoscapentpro->edt_cfp->Value;
     Frame_datoscapentpro1->date_prpago->Date      = Frame_datoscapentpro->date_prpago->Date;
     Frame_datoscapentpro1->date_ulpago->Date      = Frame_datoscapentpro->date_ulpago->Date;
     Frame_datoscapentpro1->lkcmb_prove->KeyValue  = Frame_datoscapentpro->qry_prove->FieldByName("codigo")->AsString;

     if(todook_z) alta_ptvt(alm_z, fecha_z, numero_z);
   }
   delete Frame_datoscapentpro;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::botones_onoff(int modo_z)
{
  switch (modo_z) {
    case INVISIBLES:
      nuevo->Enabled=false;
      modifica->Enabled=false;
      borra->Enabled=false;
      grabar->Enabled=true;
      cancelar->Enabled=true;
      grp_datosren->Enabled = false;
//      pnl_btngral->Visible=false;
      break;
    case VISIBLES:
//      pnl_btngral->Visible=true;
      nuevo->Enabled=true;
      modifica->Enabled=true;
      borra->Enabled=true;
      grabar->Enabled=false;
      cancelar->Enabled=false;
      grp_datosren->Enabled = true;
      break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  String permis_z = "T", alm_z, codigo_z, serie_z, tipo_z, linea_z;
  int nument_z = 0, haypedto_z=0;
  alm_z = Frame_datoscapentpro1->qry_almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscapentpro1->edt_nument->Value;
  if(!BuscarEntrada(nument_z)) return;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z;
  TFrame_datospedimento *Frame_datospedimento;
  Frame_datospedimento = NULL;

  if(qry_entradas->IsEmpty()) return;
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede eliminar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Eliminar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  mensaje_z = "Esta seguro de eliminar " + este_z + " " + titulo_z + " ? ";
  titmsg_z = "Eliminar " + titulo_z;

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    for(qry_renentra->Last(); !qry_renentra->Bof; ) {
      if(qry_renentra->FieldByName("status")->AsString == "C") {
        si_borrar = false; qry_renentra->Prior();
      } else {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
        piva_z = qry_renentra->FieldByName("piva")->AsFloat;
        qry_entradas->Edit();
        qry_entradas->FieldByName("importe")->AsFloat       -= costo_z;
        qry_entradas->FieldByName("iva")->AsFloat           -= costo_z * piva_z / 100;
        qry_entradas->FieldByName("total")->AsFloat         -= costo_z * ((piva_z / 100) + 1);
        qry_entradas->Post();
        codigo_z = qry_renentra->FieldByName("codinv")->AsString;
        serie_z  = qry_renentra->FieldByName("serie")->AsString;
        busca_cod(codigo_z);
        tipo_z  = qry_inven->FieldByName("tipo")->AsString;
        linea_z = qry_inven->FieldByName("linea")->AsString;
        if(tipo_z == "ALF" && linea_z == dm->lineamot_z) {
          if(Frame_datospedimento == NULL) {
             Frame_datospedimento= new TFrame_datospedimento (this);
          }
          Frame_datospedimento->borra_datosped(codigo_z, serie_z, alm_z);
          haypedto_z=1;
        }
        qry_renentra->Delete();
        qry_renentra->Last();
      }
    }
    if(si_borrar) {
      qry_entradas->Delete();
    } else {
      mensaje_z = "No puede eliminar " + este_z + " " + titulo_z +
       " por que hay renglones cerrados,\n los renglones no cerrados han sido eliminados";
      titmsg_z = "Imposible Eliminar " + titulo_z;
      Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    }
    try {
      dm->manvehi->StartTransaction();
      qry_entradas->ApplyUpdates();
      qry_renentra->ApplyUpdates();
      if(haypedto_z) {
        if(Frame_datospedimento->qry_datosped->UpdatesPending)
          Frame_datospedimento->qry_datosped->ApplyUpdates();
      }
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    if(Frame_datospedimento != NULL) delete Frame_datospedimento;
    SigteSabana(ULTIMO);
  }

}
//---------------------------------------------------------------------------



void __fastcall TForm_capentpro::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    //case NUEVO: alta_ptvt(); break;
    case MODIF: modif_ptvt(); break;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::alta_ptvt(String alm_z, double fecha_z, int nument_z)
{
   String  facpro_z;
   int  idnombre_z=0, letras_z, plazo_z, planp_z;
   double ctofin_z=0, tascomp_z, taspro_z, fletes_z, desxap_z, ctofincomp_z;
   TDateTime fechaprp_z, fechaulp_z;
   //alm_z = qsAlmacen->FieldByName("clave")->AsString;
   //fecha_z = date_fecha->Date;
   //nument_z = edt_nument->Value;
   qry_entradas->Close();
   qry_entradas->ParamByName("tipo")->AsString = sTipo;
   qry_entradas->ParamByName("alm")->AsString = alm_z;
   qry_entradas->ParamByName("numero")->AsInteger = nument_z;
   qry_entradas->ParamByName("cia")->AsInteger = cia_z;
   qry_entradas->Open();
   if(!qry_entradas->IsEmpty()) return;
   facpro_z = Frame_datoscapentpro1->edt_facpro->Text;
   //idnombre_z = dm->busca_iddato(qry_prove->FieldByName("nombre")->AsString, OLDCONCEPTO);
   ctofin_z = Frame_datoscapentpro1->edt_cfc->Value;
   tascomp_z = Frame_datoscapentpro1->edt_tasaent->Value;
   taspro_z = Frame_datoscapentpro1->edt_tasapro->Value;
   letras_z = Frame_datoscapentpro1->edt_nulets->Value;
   fletes_z = Frame_datoscapentpro1->edt_flete->Value;
   desxap_z = Frame_datoscapentpro1->edt_desxapli->Value;
   planp_z = Frame_datoscapentpro1->qry_planesp->FieldByName("clave")->AsInteger;
   plazo_z = Frame_datoscapentpro1->edt_plazo->Value;
   ctofincomp_z = Frame_datoscapentpro1->edt_cfp->Value;
   fechaprp_z   = Frame_datoscapentpro1->date_prpago->Date;
   fechaulp_z   = Frame_datoscapentpro1->date_ulpago->Date;


   //"insert into entradas (tipo,alm,recemi,numero,facpro,prove,
// perenvrec,status,coniva,fecha,importe,iva,total,vence,ctofin,
// tascomp,taspro,fechafac,letras,plazocfp,planp,fletes,desxap,
// fechaprp,ctofincomp,usuario,cia,

   qry_entradas->Append();
   qry_entradas->FieldByName("tipo")->AsString = sTipo;
   qry_entradas->FieldByName("alm")->AsString = alm_z;
   qry_entradas->FieldByName("recemi")->AsString = "";
   qry_entradas->FieldByName("numero")->AsInteger = nument_z;
   qry_entradas->FieldByName("facpro")->AsString = facpro_z;
   qry_entradas->FieldByName("prove")->AsString = Frame_datoscapentpro1->qry_prove->FieldByName("codigo")->AsString;
   qry_entradas->FieldByName("perenvrec")->AsInteger = idnombre_z;
   qry_entradas->FieldByName("status")->AsString = "A";
   qry_entradas->FieldByName("coniva")->AsString = "S";
   qry_entradas->FieldByName("fecha")->AsDateTime = fecha_z;
   qry_entradas->FieldByName("importe")->AsFloat = 0;
   qry_entradas->FieldByName("iva")->AsFloat = 0;
   qry_entradas->FieldByName("total")->AsFloat = 0;
   qry_entradas->FieldByName("vence")->AsDateTime = fechaulp_z;
   qry_entradas->FieldByName("ctofin")->AsFloat = ctofin_z;
   qry_entradas->FieldByName("tascomp")->AsFloat = tascomp_z;
   qry_entradas->FieldByName("taspro")->AsFloat = taspro_z;
   qry_entradas->FieldByName("fechafac")->AsDateTime = fecha_z;
   qry_entradas->FieldByName("letras")->AsInteger = letras_z;
   qry_entradas->FieldByName("fletes")->AsInteger = fletes_z;
   qry_entradas->FieldByName("desxap")->AsInteger = desxap_z;
   qry_entradas->FieldByName("planp")->AsInteger = planp_z;
   qry_entradas->FieldByName("plazocfp")->AsInteger = plazo_z;
   qry_entradas->FieldByName("ctofincomp")->AsFloat = ctofincomp_z;
   //qry_entradas->FieldByName("idusuario")->AsString = dm->idusuario_z;
   qry_entradas->FieldByName("fechaprp")->AsDateTime = fechaprp_z;
   qry_entradas->FieldByName("cia")->AsInteger = cia_z;
   qry_entradas->Post();
   try {
     dm->manvehi->StartTransaction();
     qry_entradas->ApplyUpdates();
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



void __fastcall TForm_capentpro::agrerenExecute(TObject *Sender)
{
  int ancho_z, alto_z, numero_z=0, idrenentra_z=0, folio_z=0, ii_z=0, conse_z = 0, idalm_z = 0, idart_z = 0,
  identrada_z=0, idserie_z = 0, idpers_z=0, cantmueve_z=0, idvend_z=0, canti_z=0,
  idciudad_z=0, idptovta_z=0, idcodigo_z=0, iddescri_z=0, nentrada_z;
  String tipo_z, siono_z="S", serie_z="", entcan_z="", vendedor_z, ptovta_z,
  descri_z, alm_z, codigo_z, nombre_z, linea_z; 
  double costo_z =0, prvta_z=0,costou_z=0,costoneto_z=0, piva_z, iva_z=0, precio_z=0;
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z + " previamente";
    titmsg_z = titulo_z + cerrado_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  nentrada_z = qry_entradas->FieldByName("numero")->AsInteger;
  siono_z = qry_entradas->FieldByName("coniva")->AsString;
  alm_z = qry_entradas->FieldByName("alm")->AsString;

  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TFrame_datoscapentproagre *Frame_datoscapentproagre;
  Frame_datoscapentproagre = new TFrame_datoscapentproagre(Dlg_analipol);
  ancho_z = Frame_datoscapentproagre->Width + 20;
  alto_z = Frame_datoscapentproagre->Height + Dlg_analipol->Panel2->Height + 80;
  Frame_datoscapentproagre->Parent = Dlg_analipol->Panel1;
  Frame_datoscapentproagre->alm_z = alm_z;

  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;
  Dlg_analipol->Caption = "Captura de Ventas";
  Dlg_analipol->Position = poScreenCenter;
   if( Dlg_analipol->ShowModal() == mrOk) {

      cantmueve_z = Frame_datoscapentproagre->edt_canti->Value;
      canti_z = cantmueve_z;
      if(cantmueve_z < 1) {
        Application->MessageBox(("No pueden ser "+ IntToStr((int)edt_canti->Value) + " Articulos").c_str(), "Incorrecto N�mero de Art�culos", MB_ICONEXCLAMATION);
        return;
      }
      tipo_z = Frame_datoscapentproagre->qry_inven->FieldByName("tipo")->AsString;
      //descri_z = qry_inven->FieldByName("descri")->AsString;
      //if(tipo_z == "ALF" && edt_serie->Text.IsEmpty())  {
      //  Application->MessageBox("Debe proporcionar La Serie", "Serie Desconocida", MB_ICONEXCLAMATION);
      //  return;
      //}
      //vendedor_z = qry_vendedor->FieldByName("codigo")->AsString;

      codigo_z = Frame_datoscapentproagre->qry_inven->FieldByName("codigo")->AsString;
      //iddescri_z =dm->busca_iddato(qry_inven->FieldByName("descri")->AsString, CONCEPTO);
      piva_z = Frame_datoscapentproagre->qry_inven->FieldByName("piva")->AsFloat;
      costou_z = Frame_datoscapentproagre->edt_costou->Value;
      costoneto_z = Frame_datoscapentproagre->qry_inven->FieldByName("coston")->AsFloat;
      //idpers_z = qry_entradas->FieldByName("perenvrec")->AsInteger;
      nombre_z = Frame_datoscapentpro1->qry_prove->FieldByName("nombre")->AsString;
      idpers_z = dm->busca_iddato(nombre_z, OLDCONCEPTO);
      descri_z = Frame_datoscapentproagre->qry_inven->FieldByName("descri")->AsString;
      linea_z  = Frame_datoscapentproagre->qry_inven->FieldByName("linea")->AsString;
      precio_z = Frame_datoscapentproagre->qry_inven->FieldByName("precio")->AsFloat;
      idciudad_z = 0;
      costo_z = Frame_datoscapentproagre->edt_costou->Value;
      entcan_z = "N";
      conse_z = dm->sigte_renentra(alm_z, sTipo, nentrada_z);
      qry_folsigent->Close();
      qry_folsigent->ParamByName("codigo")->AsString = codigo_z;
      qry_folsigent->ParamByName("alm")->AsString = alm_z;
      qry_folsigent->ParamByName("cia")->AsInteger = cia_z;
      qry_folsigent->Open();
      folio_z = qry_folsigent->FieldByName("ultfol")->AsInteger + 1;
      idserie_z = 0;
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
        if( tipo_z == "ALF" && ( dm->foliosalf_z || linea_z == dm->lineamot_z)) {
          Frame_datoscapentproagre->qry_datosped->First();
          if(tipo_z == "ALF" && linea_z == dm->lineamot_z) {
            Frame_datospedimento = new TFrame_datospedimento (this);
            Frame_datospedimento->entrada_z = nentrada_z;
            Frame_datospedimento->tipo_z = sTipo;
            Frame_datospedimento->alm_z = alm_z;
          }
        }
        for(ii_z = 0; ii_z < canti_z; ii_z++) {
          if(tipo_z == "ALF" && ( dm->foliosalf_z || linea_z == dm->lineamot_z) ) {
            serie_z = Frame_datoscapentproagre->qry_datosped->FieldByName("serie")->AsString;
            if(linea_z == dm->lineamot_z) {
              Frame_datospedimento->edt_codigo->Text = codigo_z;
              Frame_datospedimento->edt_serie->Text = serie_z;
              Frame_datospedimento->edt_seriemot->Text = Frame_datoscapentproagre->qry_datosped->FieldByName("seriemot")->AsString;
              Frame_datospedimento->edt_pedimento->Text = Frame_datoscapentproagre->qry_datosped->FieldByName("pedto")->AsString;
              Frame_datospedimento->edt_aduana->Text = Frame_datoscapentproagre->qry_datosped->FieldByName("aduana")->AsString;
              Frame_datospedimento->date_fecha->Date = Frame_datoscapentproagre->qry_datosped->FieldByName("fechaped")->AsDateTime;
              Frame_datoscapentproagre->qry_datosped->Next();
            }

            //idserie_z = dm->busca_iddato(serie_z, SERIE);
          } else {
            idserie_z = 0;
          }

          if(siono_z == "N") piva_z = 0;
          //select a.codigo, a.idart, b.idmovart, b.idalm, b.costo, b.modent,
          //b.folio, b.idserie, b.fecha, c.serie,
          //b.entcan, b.fecentori, facpro, b.idprove
          //idrenentra_z=dm->busca_sigid(IDRENENTRA);
          iva_z = Redondea(costou_z * piva_z / 100, 100);
          qry_renentra->Append();
          //qry_renentra->FieldByName("idrenentra")->AsInteger = idrenentra_z;
          qry_renentra->FieldByName("tipo")->AsString = sTipo;
          qry_renentra->FieldByName("alm")->AsString = alm_z;
          qry_renentra->FieldByName("recemi")->AsString = ptovta_z;
          qry_renentra->FieldByName("numero")->AsInteger = nentrada_z;
          qry_renentra->FieldByName("conse")->AsInteger = conse_z++;
          //qry_insrenen->FieldByName("idart")->AsInteger = idart_z;
          qry_renentra->FieldByName("codinv")->AsString = codigo_z;
          //qry_renentra->FieldByName("concepto")->AsString = nombre_z;
          //qry_renentra->FieldByName("iddescri")->AsInteger = iddescri_z;
          //qry_renentra->FieldByName("descri")->AsString = descri_z;
          qry_renentra->FieldByName("serie")->AsString = serie_z;
    //      qry_renentra->FieldByName("conse")->AsInteger = ++conse_z;
          qry_renentra->FieldByName("siono")->AsString = siono_z;
          qry_renentra->FieldByName("folsal")->AsInteger = 0;
          qry_renentra->FieldByName("folent")->AsInteger = folio_z;
          qry_renentra->FieldByName("unids")->AsInteger = 1;
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

          qry_renentra->FieldByName("descri")->AsString = descri_z ;
          qry_renentra->FieldByName("precio")->AsString = precio_z;

          qry_renentra->FieldByName("costou")->AsFloat= costou_z;
          qry_renentra->FieldByName("costoneto")->AsFloat= costoneto_z;
          //--qry_renentra->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
          qry_renentra->FieldByName("cia")->AsInteger = cia_z;
          qry_renentra->Post();
          qry_entradas->Edit();
          qry_entradas->FieldByName("importe")->AsFloat       += costou_z;
          qry_entradas->FieldByName("iva")->AsFloat           += iva_z;
          qry_entradas->FieldByName("total")->AsFloat         += costou_z + iva_z;
          qry_entradas->Post();
          if(tipo_z == "ALF" && linea_z == dm->lineamot_z) {
             Frame_datospedimento->agrega_datosped_sin_close();
          }
          folio_z++;
        }
        qry_entradas->ApplyUpdates();
        qry_renentra->ApplyUpdates();
        if(tipo_z == "ALF" && linea_z == dm->lineamot_z) {
           Frame_datospedimento->qry_datosped->ApplyUpdates();
        }
        dm->manvehi->Commit();
        //qry_renentra->Close();
        //qry_renentra->ParamByName("identrada")->AsInteger = qsEntradas->FieldByName("identrada")->AsInteger;
        //qry_renentra->Open();
      } catch (Exception &E)
      {
        dm->manvehi->Rollback();
        Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
      }
      despliega_totales();

   }
   if(tipo_z == "ALF" && linea_z == dm->lineamot_z) {
     delete Frame_datospedimento;
   }
   delete Frame_datoscapentproagre;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::edicion_factible(int modo_z)
{
  bool modo_enabled = true, modo_readonly = false;
  switch (modo_z) {
    case READ_WRITE: modo_enabled = true; modo_readonly = false; break;
    case READ_ONLY: modo_enabled = false; modo_readonly = true; break;
  }
  //cmb_status->Enabled = modo_enabled;
  edt_canti->ReadOnly = modo_readonly;
  edt_codigo->ReadOnly = modo_readonly;
  //edt_nombre->ReadOnly = modo_readonly;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentpro::CierraRenExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z,
         entcan_z, prove_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este Rengl�n ya ha sido previamente Cerrado", "Rengl�n Cerrado", MB_ICONERROR);
    return;
  }
  prove_z = qry_entradas->FieldByName("prove")->AsString;
  siono_z = qry_renentra->FieldByName("siono")->AsString;
  folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
  codigo_z = qry_renentra->FieldByName("codinv")->AsString;
  serie_z = qry_renentra->FieldByName("serie")->AsString;
  alm_z   = qry_renentra->FieldByName("alm")->AsString;
  ptovta_z = qry_renentra->FieldByName("recemi")->AsString;
  idcomprador_z = qry_renentra->FieldByName("persenvrec")->AsInteger;
  fecha_z = qry_entradas->FieldByName("fecha")->AsDateTime;
  nsabana_z = qry_renentra->FieldByName("numero")->AsInteger;
  npoblac_z = qry_renentra->FieldByName("poblac")->AsInteger;
  numren_z = qry_renentra->FieldByName("conse")->AsInteger;
  costou_z = qry_renentra->FieldByName("costou")->AsFloat;
  entcan_z = qry_renentra->FieldByName("entcan")->AsString;

  TForm_kardex *Form_kardex = new TForm_kardex (this);
  cierre_ren_z = Form_kardex->entrada_sabana_cancel(
      codigo_z, serie_z, folio_z, fecha_z,
      alm_z, ptovta_z, sTipo, idcomprador_z, siono_z,
      nsabana_z, npoblac_z, numren_z, costou_z, entcan_z, prove_z
  );
  if(!cierre_ren_z) {
    Application->MessageBox
      (Form_kardex->errores_z->Text.c_str(),
       "ERROR: Rengl�n NO Cerrado", MB_ICONERROR
    );
  } else {
    qry_renentra->Edit();
    qry_renentra->FieldByName("Status")->AsString = "C";
    qry_renentra->Post();
  }
  delete Form_kardex->errores_z;
  delete Form_kardex;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::afecta_pagare()
{
  int identpag_z=0, idmventpag_z=0, letras_z=0, plazo_z=0, identrada_z=0,
  idprove_z=0, nentrada_z=0, idplanp_z=0, ind1_z=0, numpag_z=0,
  conspag_z=0, plazo_plp=0, nletiva_plp=0, idconcep_flete_z=0;
  double importe_z=0, fletes_z=0, imppag_z, descxap_z=0,
  ctofinent_z=0, capital_z=0, ivafcfcent_z=0, tasacfc_z=0,
  ind2_z=0, nprpag_z=0, ivapag_z=0, amort_z=0, cfc_z=0, descxlet_z=0,
  fletexlet_z=0, sdocap_z=0, totint_z=0, desxappag_z=0, iva_z=0,
  capitpag_z=0, interespag_z=0, tasa_z=0, cosfc_z=0, ivaint_z=0,
  cfcpag_z=0, saldopag_z=0, ivacfcent_z=0, ivaintpag_z=0;
  TDateTime fecprp_z, feculp_z, vence_z;
  String ivadis_plp="S", letivaemp_plp="S", fletedis_plp = "S",
  letivasol_plp="S", intssal_plp = "S", prove_z="", dscxapdis_plp="S";

  idconcep_flete_z=dm->busca_iddato("FLETE", OLDCONCEPTO);
  iva_z = qry_entradas->FieldByName("iva")->AsFloat;
  nentrada_z = qry_entradas->FieldByName("numero")->AsInteger;
  prove_z = qry_entradas->FieldByName("prove")->AsString;
  letivaemp_plp=Frame_datoscapentpro1->qry_planesp->FieldByName("letivaemp")->AsString;
  nletiva_plp=Frame_datoscapentpro1->qry_planesp->FieldByName("nletiva")->AsInteger;
  fletedis_plp = Frame_datoscapentpro1->qry_planesp->FieldByName("fletedis")->AsString;
  dscxapdis_plp = Frame_datoscapentpro1->qry_planesp->FieldByName("dscxapdis")->AsString;
  letivasol_plp = Frame_datoscapentpro1->qry_planesp->FieldByName("letivasol")->AsString;
  ivadis_plp = Frame_datoscapentpro1->qry_planesp->FieldByName("ivadis")->AsString;
  intssal_plp = Frame_datoscapentpro1->qry_planesp->FieldByName("intssal")->AsString;
  plazo_plp = Frame_datoscapentpro1->qry_planesp->FieldByName("plazo")->AsInteger;
  idplanp_z = Frame_datoscapentpro1->qry_planesp->FieldByName("clave")->AsInteger;
  tasa_z = Frame_datoscapentpro1->edt_tasapro->Value;
  qry_entpag->Close();
  qry_entpag->ParamByName("numentrada")->AsInteger = nentrada_z;
  qry_entpag->ParamByName("prove")->AsString = prove_z;
  qry_entpag->ParamByName("cia")->AsInteger = cia_z;
  qry_entpag->Open();
  //  ==> Si ya existe una Entrada primero se Borran todos los movtos <==  *
  if(!qry_entpag->IsEmpty()) {
    qry_entpag->Edit();
  } else {
    //identpag_z = dm->busca_sigid(IDENTPAG);
    qry_entpag->Append();
  }
  qry_mventpag->Close();
  qry_mventpag->ParamByName("entrada")->AsInteger = nentrada_z;
  qry_mventpag->ParamByName("prove")->AsString = prove_z;
  qry_mventpag->ParamByName("cia")->AsInteger = cia_z;
  qry_mventpag->Open();
  for(qry_mventpag->First(); !qry_mventpag->Eof; qry_mventpag->Next()) qry_mventpag->Delete();
  letras_z=Frame_datoscapentpro1->edt_nulets->Value; plazo_z=Frame_datoscapentpro1->edt_plazo->Value;
  importe_z = qry_entradas->FieldByName("importe")->AsFloat;
  fletes_z  = qry_entradas->FieldByName("fletes")->AsFloat;
  imppag_z = Redondea(importe_z -  ( fletes_z  / (1 + (pivapag_z / 100) ) ), 100);
  descxap_z = Redondea(Frame_datoscapentpro1->edt_desxapli->Value, 100);
  ctofinent_z = Redondea(Frame_datoscapentpro1->edt_cfc->Value / (1 + (pivapag_z / 100)), 100);
  capital_z = imppag_z  + ctofinent_z + descxap_z;
  iva_z = Redondea(capital_z * pivapag_z / 100, 100);
  ivapag_z = Redondea(capital_z * pivapag_z / 100, 100);
  ivacfcent_z = Redondea(ctofinent_z * pivapag_z / 100, 100);
  fecprp_z = Frame_datoscapentpro1->date_prpago->Date;
  feculp_z = Frame_datoscapentpro1->date_ulpago->Date;
  qry_entpag->FieldByName("prove")->AsString = prove_z;
  qry_entpag->FieldByName("numero")->AsInteger = nentrada_z;
  qry_entpag->FieldByName("fecha")->AsDateTime = Frame_datoscapentpro1->date_fecha->Date;
  qry_entpag->FieldByName("facpro")->AsString = Frame_datoscapentpro1->edt_facpro->Text.Trim();
  qry_entpag->FieldByName("fecentra")->AsDateTime = Frame_datoscapentpro1->date_fecha->Date;
  qry_entpag->FieldByName("tasacfc")->AsFloat = tasacfc_z;
  qry_entpag->FieldByName("importe")->AsFloat = importe_z;
  qry_entpag->FieldByName("total")->AsFloat = 0;
  qry_entpag->FieldByName("ctofinent")->AsFloat = ctofinent_z;
  qry_entpag->FieldByName("ivacfcent")->AsFloat = ivacfcent_z;
  qry_entpag->FieldByName("letras")->AsInteger = letras_z;
  qry_entpag->FieldByName("poriva")->AsFloat = pivapag_z;
  qry_entpag->FieldByName("tasapro")->AsFloat = Frame_datoscapentpro1->edt_tasapro->Value;
  qry_entpag->FieldByName("plazo")->AsInteger = Frame_datoscapentpro1->edt_plazo->Value;
  qry_entpag->FieldByName("tasmen")->AsString = "";
  qry_entpag->FieldByName("planp")->AsInteger = idplanp_z;
  qry_entpag->FieldByName("descxap")->AsFloat = descxap_z;
  qry_entpag->FieldByName("pagcap")->AsFloat = 0;
  qry_entpag->FieldByName("fecprp")->AsDateTime = fecprp_z;
  qry_entpag->FieldByName("feculp")->AsDateTime = feculp_z;
  qry_entpag->FieldByName("fletes")->AsFloat = fletes_z;
  qry_entpag->FieldByName("cia")->AsInteger = cia_z;
  qry_entpag->FieldByName("fecsal")->AsDateTime = Frame_datoscapentpro1->date_fecha->Date;
//  qry_entpag->Post();
// --> Ahora Inserto los Movimientos... <--  *
  ivapag_z = Redondea( iva_z / letras_z , 100);
  capitpag_z = Redondea ( capital_z / letras_z ,100);
  cfcpag_z = Redondea (ctofinent_z / letras_z, 100);
  desxappag_z = Redondea ( descxap_z / letras_z,100);
  sdocap_z=capital_z; totint_z=0;
  feculp_z = Frame_datoscapentpro1->date_ulpago->Date;
  fecprp_z = Frame_datoscapentpro1->date_prpago->Date;

//  if(dm->secuen_z != "S")
//    idmventpag_z = dm->busca_sigid(IDMVENTPAG);

  for(ind1_z = 1; ind1_z <= letras_z ; ++ind1_z) {
    numpag_z= ind1_z; conspag_z = ind1_z;
    if(intssal_plp == "S") {
      interespag_z = Redondea(sdocap_z * tasa_z / 100, 100);
    } else {
      interespag_z = Redondea(capital_z * tasa_z / 100 / letras_z, 100);
    }
    ivaintpag_z = Redondea (interespag_z * pivapag_z /100, 100);
    if(ind1_z <= nprpag_z)
      vence_z = fecprp_z;
    else if(ind1_z == letras_z)
      vence_z = feculp_z;
    else
      if(letivaemp_plp == "N" && ind1_z > nletiva_plp && letivasol_plp == "S")
        vence_z = fecprp_z + ( plazo_plp * (ind1_z - 2) );
      else
        vence_z = fecprp_z + ( plazo_plp * (ind1_z - 1) );
    if(ivadis_plp != "S") {// El iva no es distribuido, asi que queda en una sola letra
      if( ind1_z == nletiva_plp) {
        ivapag_z = iva_z; // Si esta es la letra del iva le pongo todo el iva
      } else {
        ivapag_z = 0;     // Si no es la letra del iva, el iva es cero
        ivaintpag_z = 0;
      }
    }
    if(dscxapdis_plp != "S") { // El descuento x aplicar no se distribuye
      if(ind1_z == 1) {
        desxappag_z = descxap_z; // Si es la letra 1 le pongo todo el descuento x aplicar
      } else {
        desxappag_z = 0; // Si no es la letra 1 lo pongo a ceros
      }

    }
    saldopag_z = capitpag_z + interespag_z + ivapag_z;
//    if(dm->secuen_z == "S")
//      idmventpag_z = dm->busca_sigid(IDMVENTPAG);
//    else
//      idmventpag_z++;

    qry_mventpag->Append();
    qry_mventpag->FieldByName("prove")->AsString = prove_z;
    qry_mventpag->FieldByName("entrada")->AsInteger = nentrada_z;
    qry_mventpag->FieldByName("fecha")->AsDateTime = Frame_datoscapentpro1->date_fecha->Date;
    qry_mventpag->FieldByName("pagare")->AsInteger = ind1_z;
    qry_mventpag->FieldByName("conse")->AsInteger = ind1_z;
    qry_mventpag->FieldByName("vence")->AsDateTime = vence_z;
    qry_mventpag->FieldByName("tpmov")->AsString = "A";
    qry_mventpag->FieldByName("tipo2")->AsString = "O";
    qry_mventpag->FieldByName("cia")->AsFloat = cia_z;
    qry_mventpag->FieldByName("concep")->AsInteger = 0;
    qry_mventpag->FieldByName("capital")->AsFloat = capitpag_z;
    qry_mventpag->FieldByName("interes")->AsFloat = interespag_z;
    qry_mventpag->FieldByName("iva")->AsFloat = ivapag_z + ivaintpag_z;
    qry_mventpag->FieldByName("saldo")->AsFloat = saldopag_z;
    qry_mventpag->FieldByName("cfc")->AsFloat = cfcpag_z;
    qry_mventpag->FieldByName("desxap")->AsFloat = desxappag_z;
    qry_mventpag->Post();
  }
  qry_entpag->FieldByName("capital")->AsFloat = capital_z;
  qry_entpag->FieldByName("iva")->AsFloat = iva_z;
  qry_entpag->FieldByName("ivaint")->AsFloat = ivaint_z;
  qry_entpag->FieldByName("sdocap")->AsFloat = capital_z;
  qry_entpag->FieldByName("pagint")->AsFloat = 0;
  qry_entpag->FieldByName("totalinter")->AsFloat = totint_z;
  qry_entpag->FieldByName("total")->AsFloat = capital_z + iva_z +
  ivaint_z+ totint_z + fletes_z;
  qry_entpag->FieldByName("pagos")->AsFloat = 0;
  qry_entpag->FieldByName("pagiva")->AsFloat = 0;
  qry_entpag->Post();
  qry_entradas->Edit();
  qry_entradas->FieldByName("ctofin")->AsFloat = totint_z + ivaint_z;
  qry_entradas->Post();
  if(fletedis_plp == "N" && fletes_z != 0) {
    qry_mventpag->Append();
    qry_mventpag->FieldByName("prove")->AsString = prove_z;
    qry_mventpag->FieldByName("entrada")->AsInteger = nentrada_z;
    qry_mventpag->FieldByName("fecha")->AsDateTime = Frame_datoscapentpro1->date_fecha->Date;
    qry_mventpag->FieldByName("pagare")->AsInteger = ind1_z;
    qry_mventpag->FieldByName("conse")->AsInteger = ind1_z;
    qry_mventpag->FieldByName("vence")->AsDateTime = Frame_datoscapentpro1->date_fecha->Date;
    qry_mventpag->FieldByName("tpmov")->AsString = "A";
    qry_mventpag->FieldByName("tipo2")->AsString = "O";
    qry_mventpag->FieldByName("cia")->AsFloat = cia_z;
    qry_mventpag->FieldByName("concep")->AsInteger = idconcep_flete_z;
    qry_mventpag->FieldByName("capital")->AsFloat = fletes_z;
    qry_mventpag->FieldByName("interes")->AsFloat = 0;
    qry_mventpag->FieldByName("iva")->AsFloat = 0;
    qry_mventpag->FieldByName("saldo")->AsFloat = 0;
    qry_mventpag->FieldByName("cfc")->AsFloat = 0;
    qry_mventpag->FieldByName("desxap")->AsFloat = 0;
    qry_mventpag->Post();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::cancela_renglonExecute(TObject *Sender)
{
  double costo_z, piva_z, iva_z;
  String codigo_z,alm_z, serie_z;
  TFrame_datospedimento *Frame_datospedimento;
  int folio_z, haypedto_z=0;
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z + " previamente";
    titmsg_z = titulo_z + cerrado_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este rengl�n ya ha sido cerrado, no lo puede eliminar", "RENGLON CERRADO", MB_ICONEXCLAMATION);
    return;
  }
  int ii_z = Application->MessageBox("Esta Seguro de Eliminar este Rengl�n ?", "Eliminar Rengl�n", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
  if (ii_z != IDOK ) return;
  costo_z = qry_renentra->FieldByName("costou")->AsFloat;
  piva_z = qry_renentra->FieldByName("piva")->AsFloat;
  codigo_z = qry_renentra->FieldByName("codinv")->AsString;
  serie_z  = qry_renentra->FieldByName("serie")->AsString;
  busca_cod(codigo_z);
  alm_z = qry_renentra->FieldByName("alm")->AsString;
  iva_z = Redondea(costo_z * piva_z / 100, 100);
  qry_entradas->Edit();
  qry_entradas->FieldByName("importe")->AsFloat       -= costo_z;
  qry_entradas->FieldByName("iva")->AsFloat           -= iva_z;
  qry_entradas->FieldByName("total")->AsFloat         -= costo_z + iva_z;
  qry_entradas->Post();
  if(qry_inven->FieldByName("linea")->AsString == dm->lineamot_z) {
    Frame_datospedimento= new TFrame_datospedimento (this);
    Frame_datospedimento->borra_datosped(codigo_z, serie_z, alm_z);
    haypedto_z=1;
  }
  qry_renentra->Delete();
  try {
    dm->manvehi->StartTransaction();
    qry_renentra->ApplyUpdates();
    qry_entradas->ApplyUpdates();
    if(haypedto_z) {
      if(Frame_datospedimento->qry_datosped->UpdatesPending)
        Frame_datospedimento->qry_datosped->ApplyUpdates();
    }
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  if(haypedto_z) delete Frame_datospedimento;
  despliega_totales();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::dbgrd_renentraCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
    
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentpro::exporta_dbgrdExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_renentra;
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

void __fastcall TForm_capentpro::imprimeExecute(TObject *Sender)
{
  double piva_z=0, importe_z=0, iva_z=0, total_z=0, costo_z=0, totcos_z=0,
  fletes_z=0, desxap_z=0, ctofincomp_z=0, ctofin_z=0, mub_z=0;
  String arch_z = Name+".txt", serie_z="", descri2_z, tipo_z, linea_z,
    gpoartdesp_z, gpodiary_z,
    prove_z="", codigo_z="", alm_z="", antcod_z = "-1";
  int nentrada_z=0, nartics_z=0;
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresi�n de " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_renentra->DisableControls();
  qry_renentra->Tag == NO_REFRESH;
  nentrada_z = qry_entradas->FieldByName("numero")->AsInteger;
  prove_z = qry_entradas->FieldByName("prove")->AsString;
  alm_z = qry_entradas->FieldByName("alm")->AsString;
//  if(!qry_renentra->IsEmpty())
//    zona_z = qry_renpogas->FieldByName("zona")->AsInteger;
  antcod_z = "-1"; pagina_z = 1; report_encab();
  for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
    busca_cod(codigo_z);
    tipo_z  = qry_inven->FieldByName("tipo")->AsString;
    linea_z = qry_inven->FieldByName("linea")->AsString;
    if(!nartics_z) {
      codigo_z = qry_renentra->FieldByName("codinv")->AsString;
    }
    if(codigo_z != qry_renentra->FieldByName("codinv")->AsString) {
      if(nartics_z > 1) {
        fprintf(archout, "%s|", cjust("Total de Este Articulo:", 44));
        fprintf(archout, "%s|", rjust(FormatFloat("####0", nartics_z), 5));
        fprintf(archout, "%s", rjust(FormatFloat("#,###,##0.00", totcos_z), 12));
        salta_linea();
      }
      codigo_z = qry_renentra->FieldByName("codinv")->AsString;
      nartics_z=0; totcos_z = 0;
    }
    if( sTipo != "Q") {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
    } else {
        costo_z = qry_renentra->FieldByName("prvta")->AsFloat;
    }
    totcos_z += qry_renentra->FieldByName("costou")->AsFloat;
    mub_z = -1;
    if (qry_renentra->FieldByName("precio")->AsFloat != 0) {
      mub_z = (qry_renentra->FieldByName("precio")->AsFloat -
              qry_renentra->FieldByName("costoneto")->AsFloat ) /
              qry_renentra->FieldByName("precio")->AsFloat * 100;
    }
    fprintf(archout, "%s ",  ljust(qry_renentra->FieldByName("codinv")->AsString, 13));
    fprintf(archout, "%s|",  ljust(qry_renentra->FieldByName("descri")->AsString, 30));
    fprintf(archout, "%s|",  rjust(IntToStr(qry_renentra->FieldByName("folent")->AsInteger), 5));
    fprintf(archout, "%s|",  rjust(FormatFloat("#,###,##0.00", costo_z), 12));
    fprintf(archout, "%s|",  rjust(FormatFloat("#,###,##0.00", qry_renentra->FieldByName("costoneto")->AsFloat), 12));
    fprintf(archout, "%s|",  rjust(FormatFloat("#,###,##0.00", qry_renentra->FieldByName("precio")->AsFloat), 12));
    fprintf(archout, "%s|",  rjust(FormatFloat("##0.00", mub_z), 5));
    if(!nartics_z) {
      gpodiary_z = obten_grupo( "GPODIARY", codigo_z);
      gpoartdesp_z = qry_renentra->FieldByName("grupo")->AsString;
      fprintf(archout, "%s|",  ljust(gpodiary_z, 15));
      fprintf(archout, "%s|",  ljust(gpoartdesp_z, 5));
      if(tipo_z == "ALF" && ( linea_z == dm->lineamot_z | dm->foliosalf_z)) {
        salta_linea();
        fprintf(archout, "%s|Serie:%s|",  ljust("",13),ljust(qry_renentra->FieldByName("serie")->AsString, 20));
      }
    }
    salta_linea();
    piva_z = qry_renentra->FieldByName("piva")->AsFloat;
    importe_z += costo_z;
    iva_z += qry_renentra->FieldByName("costou")->AsFloat * (piva_z / 100);
    total_z = importe_z + iva_z;
    if(!nartics_z) {
      descri2_z = obten_grupo( "DESCRI2", codigo_z);
      fprintf(archout, "%s|%s",  ljust("",13), descri2_z.c_str());
      salta_linea();
    }
    nartics_z++;
  }
  if(nartics_z > 1) {
    fprintf(archout, "%s|", cjust("Total de Este Articulo:", 44));
    fprintf(archout, "%s|", rjust(FormatFloat("####0", nartics_z), 5));
    fprintf(archout, "%s\n", rjust(FormatFloat("#,###,##0.00", totcos_z), 12));
  }
  fprintf(archout, "%s",
    rjust(
      "Importe:" + FormatFloat("#,###,##0.00", importe_z) +
      "   Iva:" + FormatFloat("#,###,##0.00", iva_z) +
      "   Total:" + FormatFloat("#,###,##0.00", total_z), 63
    )
  );
  salta_linea();
  totcos_z = qry_entradas->FieldByName("importe")->AsFloat +
    qry_entradas->FieldByName("iva")->AsFloat;
  fletes_z = qry_entradas->FieldByName("fletes")->AsFloat;
  desxap_z = qry_entradas->FieldByName("desxap")->AsFloat;
  ctofincomp_z = qry_entradas->FieldByName("ctofincomp")->AsFloat;
  ctofin_z = qry_entradas->FieldByName("ctofin")->AsFloat;
  totcos_z = totcos_z- fletes_z + ctofin_z + ctofincomp_z + desxap_z;
  fprintf(archout, "Fletes: %s Descuento x Aplicar: %s Costo Financiero de Compra: %s",
    ljust(FormatFloat("#,###,##0.00", fletes_z), 12),
    ljust(FormatFloat("#,###,##0.00", desxap_z), 12),
    ljust(FormatFloat("#,###,##0.00", ctofincomp_z), 12)
  );
  salta_linea();
  fprintf(archout, " Costo Financiero de Proveedor: %s %s",
    ljust(FormatFloat("#,###,##0.00", ctofin_z), 12),
    rjust("Gran Total: " + FormatFloat("#,###,##0.00", totcos_z), 33)
  );
  salta_linea();
  fprintf(archout, "%s%s%s", serie_z.StringOfChar('=',80),
    dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, SUBRAYADO_ON)
  );
  salta_linea();
  fprintf(archout, "%s|", "Lta");
  fprintf(archout, "%s|", cjust("Vence", 10));
  fprintf(archout, "%s|", rjust("Costo_F.Comp", 12));
  fprintf(archout, "%s|", rjust("Capital", 12));
  fprintf(archout, "%s|", rjust("Interes", 12));
  fprintf(archout, "%s|", rjust("IVA", 12));
  fprintf(archout, "%s|", rjust("DescxAplicar",12));
  fprintf(archout, "%s|", rjust("Saldo",12));
  fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
  qry_mventpag->Close();
  qry_mventpag->ParamByName("entrada")->AsInteger = nentrada_z;
  qry_mventpag->ParamByName("prove")->AsString = prove_z;
  qry_mventpag->ParamByName("cia")->AsInteger = cia_z;
  qry_mventpag->Open();
  totcos_z = 0;
  for(qry_mventpag->First(); !qry_mventpag->Eof; qry_mventpag->Next()) {
    fprintf(archout, "%s|", rjust(qry_mventpag->FieldByName("pagare")->AsString, 3));
    fprintf(archout, "%s|", rjust(FormatDateTime("dd-mm-yyyy", qry_mventpag->FieldByName("vence")->AsDateTime), 10));
    fprintf(archout, "%s|", rjust(FormatFloat("##,##0.00", qry_mventpag->FieldByName("cfc")->AsFloat), 12));
    fprintf(archout, "%s|", rjust(FormatFloat("##,##0.00", qry_mventpag->FieldByName("capital")->AsFloat), 12));
    fprintf(archout, "%s|", rjust(FormatFloat("##,##0.00", qry_mventpag->FieldByName("interes")->AsFloat), 12));
    fprintf(archout, "%s|", rjust(FormatFloat("##,##0.00", qry_mventpag->FieldByName("iva")->AsFloat), 12));
    fprintf(archout, "%s|", rjust(FormatFloat("##,##0.00", qry_mventpag->FieldByName("desxap")->AsFloat), 12));
    fprintf(archout, "%s|", rjust(FormatFloat("##,##0.00", qry_mventpag->FieldByName("saldo")->AsFloat), 12));
    salta_linea();
    totcos_z += qry_mventpag->FieldByName("saldo")->AsFloat;
  }
  fprintf(archout, "%sVencimiento:%s %s %s%s",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    rjust(FormatDateTime("dd-mm-yyyy", qry_entradas->FieldByName("vence")->AsDateTime), 10),
    rjust("Total:", 56),
    rjust(FormatFloat("##,##0.00", totcos_z), 12),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  salta_linea();
  TQuery *qry_observs = new TQuery (this);
  qry_observs->DatabaseName = qry_entradas->DatabaseName;
  qry_observs->SQL->Text=("select * from observent where tipo = :Tipo and alm =:Almac and numero = :Numero and cia = :Cia order by conse");
  qry_observs->ParamByName("tipo")->AsString = sTipo;
  qry_observs->ParamByName("almac")->AsString = alm_z;
  qry_observs->ParamByName("numero")->AsInteger = nentrada_z;
  qry_observs->ParamByName("cia")->AsInteger = cia_z;
  qry_observs->Open();
  for(qry_observs->First(); !qry_observs->Eof; qry_observs->Next()) {
      fprintf(archout, "%s %s",
        FormatDateTime("dd/mm/yyyy ", qry_observs->FieldByName("fecha")->AsDateTime),
        qry_observs->FieldByName("observs")->AsString
      );
      salta_linea();
  }
  qry_observs->Close();
  delete qry_observs;
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renentra->Tag == SI_REFRESH;
  qry_renentra->EnableControls();
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

String __fastcall TForm_capentpro::obten_grupo(String dato_z, String codigo_z)
{
  String nuevodato_z = "";
  int tiporel_z;
  TQuery *qry_busca = new TQuery (this);
  if(dato_z == "GPODIARY") qry_busca->SQL->Text = qry_diary->SQL->Text;
  if(dato_z == "DESCRI2") qry_busca->SQL->Text = qry_descri2->SQL->Text;
  qry_busca->DatabaseName = qry_descri2->DatabaseName;

  qry_busca->Close();
  qry_busca->ParamByName("codigo")->AsString=codigo_z;
  if(dato_z == "GPODIARY") tiporel_z = REL_INVEN_GPODIARY;
  if(dato_z == "DESCRI2") tiporel_z = REL_INVEN_DESCRILAR;
  qry_busca->ParamByName("tiporel")->AsInteger = tiporel_z;
  qry_busca->ParamByName("cia")->AsInteger = cia_z;
  qry_busca->Open();
  if(!qry_busca->IsEmpty()) {
    nuevodato_z = qry_busca->FieldByName("dato")->AsString;
  }
  delete qry_busca;
  return (nuevodato_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::salta_linea()
{
  fprintf(archout, "\n");
  lineas_z++;
  if(lineas_z > LIN_X_PAG) {
    fprintf(archout, "%c", 12); pagina_z++; report_encab();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::report_encab()
{
  lineas_z = 0;
  fprintf(archout, "%s%s%s", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  salta_linea();
  fprintf(archout, "%s%s%s%s Pag:%d", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  salta_linea();
  fprintf(archout, "Impresion de %s", titulo_z);
  salta_linea();
  fprintf(archout, "Numero:%6d Almacen:%s %s Fecha:%s",
    qry_entradas->FieldByName("numero")->AsInteger,
    Frame_datoscapentpro1->qry_almacen->FieldByName("clave")->AsString,
    Frame_datoscapentpro1->qry_almacen->FieldByName("nombre")->AsString,
    FormatDateTime("dd-mm-yyyy", qry_entradas->FieldByName("fecha")->AsDateTime),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  salta_linea();
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, EMPHIZED_ON));
  fprintf(archout, "Proveedor:%s ", Frame_datoscapentpro1->qry_prove->FieldByName("codigo")->AsString);
  fprintf(archout, "%s", Frame_datoscapentpro1->qry_prove->FieldByName("nombre")->AsString);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, EMPHIZED_OFF));
  salta_linea();
  fprintf(archout, "Plan de Pago:%s ", Frame_datoscapentpro1->qry_planesp->FieldByName("clave")->AsString);
  fprintf(archout, "%s ", Frame_datoscapentpro1->qry_planesp->FieldByName("descri")->AsString);
  fprintf(archout, "Letras:%s ", IntToStr(qry_entradas->FieldByName("letras")->AsInteger));
  fprintf(archout, "Factura:%s ", qry_entradas->FieldByName("facpro")->AsString);
  salta_linea();
  fprintf(archout, "%% Costo Fin.Compra   :%s ", FormatFloat("#0.0000", qry_entradas->FieldByName("tascomp")->AsFloat));
  fprintf(archout, "%% Costo Fin.Proveedor:%s ", FormatFloat("#0.0000", qry_entradas->FieldByName("taspro")->AsFloat));
  salta_linea();
  fprintf(archout, "%s%s",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s|", cjust("Articulo", 44));
  fprintf(archout, "%s|", rjust("Folio", 5));
  fprintf(archout, "%s|", rjust("Costo.Unitar", 12));
  fprintf(archout, "%s|", rjust("Costo Neto", 12));
  fprintf(archout, "%s|", ljust("Precio Lista", 12));
  fprintf(archout, "%s|", "MUB");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();
//  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::cancelarExecute(TObject *Sender)
{
  grabar->Tag = EN_ESPERA;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::edt_numentKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarEntrada(Frame_datoscapentpro1->edt_nument->Value ) ) {
           Application->MessageBox("No Existe El Numero de Entrada Solicitado !!", "Entrada", MB_OK | MB_ICONQUESTION);
           return;
       }
       //ListarRenglon();
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::cierra_entExecute(TObject *Sender)
{
  bool todobien_z = true;
//  if(qry_entradas->FieldByName("status")->AsString == "C") {
//    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z + " previamente";
//    titmsg_z = titulo_z + cerrado_z;
//    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
//    return;
//  }
  mensaje_z = "Seguro de cerrar " + este_z + " " + titulo_z;
  titmsg_z = "Cerrar " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    for(qry_renentra->First(); !qry_renentra->Eof && todobien_z; qry_renentra->Next()) {
      if(qry_renentra->FieldByName("status")->AsString != "C") CierraRenExecute(Sender);
    }
  }
  afecta_pagare();
  if(todobien_z) {
    try {
      dm->manvehi->StartTransaction();
      qry_entradas->Edit();
      qry_entradas->FieldByName("status")->AsString = "C";
      qry_entradas->FieldByName("recemi")->AsString = "C";
      qry_entradas->Post();
      qry_entpag->ApplyUpdates();
      qry_mventpag->ApplyUpdates();
      qry_entradas->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)  {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  } else {
    mensaje_z = "No puede cerrar " + este_z + " " + titulo_z + " debido a que surgi� alg�n problmea con alg�n rengl�n";
    titmsg_z = "ERROR EN RENGLONES";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
  }
  if(qry_entradas->FieldByName("status"  )->AsString == "C") {
    cierra_ent->Enabled = false;
    imprime->Enabled = true;
  } else {
    cierra_ent->Enabled = true;
    imprime->Enabled = false;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::capobsExecute(TObject *Sender)
{
  String tipo_z, alm_z;
  int nument_z;
  tipo_z = qry_entradas->FieldByName("Tipo")->AsString;
  alm_z = qry_entradas->FieldByName("Alm" )->AsString;
  nument_z = qry_entradas->FieldByName("numero")->AsInteger;

  TForm_CapturaObsPed *Form_CapturaObsPed = new TForm_CapturaObsPed(
    this, tipo_z, alm_z, nument_z, cia_z, "", permis_z);
  Form_CapturaObsPed->ShowModal();
  delete Form_CapturaObsPed;

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::deshacer_afectarExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z, entcan_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString != "C") {
    Application->MessageBox("Este Rengl�n No ha sido previamente Cerrado", "Rengl�n Abiero", MB_ICONERROR);
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
  fecha_z = qry_entradas->FieldByName("fecha")->AsDateTime;
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
       "ERROR: Rengl�n NO Cerrado", MB_ICONERROR
    );
  } else {
    Application->MessageBox
      ("Todos los Movimientos Han sido efectuados",
       "Rengl�n Cerrado", MB_OK
    );
    qry_renentra->Edit();
    qry_renentra->FieldByName("Status")->AsString = "A";
    qry_renentra->Post();
  }
  delete Form_kardex->errores_z;
  delete Form_kardex;

}
//---------------------------------------------------------------------------


bool __fastcall TForm_capentpro::busca_cod(String codigo_z)
{
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  return(!qry_inven->IsEmpty());
}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::modifica_pagaresExecute(TObject *Sender)
{
  TQuery *qsSigte = new TQuery (this);
  int nument_z=0, pagare_z=0;
  double porc1_z=0, porc2_z;
  String sql1_z;
  sql1_z = "update mventpag set capital = round( capital * 2 * :PORC1 /100 , 2),\
    interes = round ( interes * 2 * :PORC1 /100, 2), \
    iva = round ( iva * 2 * :PORC1 /100, 2), \
    saldo = round ( saldo * 2 * :PORC1 /100, 2), \
    interes = round ( interes * 2 * :PORC1 /100 , 2), \
    desxap = round ( desxap * 2 * :PORC2 /100, 2) \
    where entrada = :ENTRADA and pagare = :PAGARE";
  porc1_z = Frame_datoscapentpro1->edt_tasaent->Value;
  porc2_z = Frame_datoscapentpro1->edt_tasapro->Value;
  nument_z = Frame_datoscapentpro1->edt_nument->Value;
  pagare_z = Frame_datoscapentpro1->edt_nulets->Value;
  if( Application->MessageBox( (
     "Seguro de aplicar el " + FormatFloat ("0.000", porc1_z) +
     " y el " + FormatFloat ("0.000", porc2_z) + " Al pagares " + IntToStr(pagare_z) + "\n" +
     "Estos datos corresponden a Tasa E =  " +
     FormatFloat ("0.000", porc1_z) +
     " y Tasa P = " + FormatFloat ("0.000", porc2_z) +
     " Y Letras = " + IntToStr(pagare_z)
     ).c_str(), "Aplicacion de Pagares",
     MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) != IDYES) return;
  qsSigte->DatabaseName = Frame_datoscapentpro1->qry_almacen->DatabaseName;
  qsSigte->SQL->Text = sql1_z;
  qsSigte->ParamByName("entrada")->AsInteger = nument_z;
  qsSigte->ParamByName("pagare")->AsInteger = pagare_z;
  qsSigte->ParamByName("porc1")->AsFloat = porc1_z;
  qsSigte->ParamByName("porc2")->AsFloat = porc2_z;
  try {
      dm->manvehi->StartTransaction();
      qsSigte->ExecSQL();
      dm->manvehi->Commit();
  } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  delete qsSigte;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentpro::Frame_datoscapentpro1edt_numentKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarEntrada(Frame_datoscapentpro1->edt_nument->Value ) ) {
           Application->MessageBox("No Existe El Numero de Entrada Solicitado !!", "Entrada", MB_OK | MB_ICONQUESTION);
           return;
       }
       //ListarRenglon();
    }


}
//---------------------------------------------------------------------------



void __fastcall TForm_capentpro::dbgrd_renentraKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_DELETE) cancela_renglonExecute(Sender);
  if (Key == VK_INSERT) agrerenExecute(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentpro::abre_entradaExecute(TObject *Sender)
{
  String mensaje_z, titmsg_z, prove_z;
  int nentrada_z;
  if ( qry_entradas->IsEmpty()) return;
  if(qry_entradas->FieldByName("recemi")->AsString != "C") {
    mensaje_z = titulo_z + " No est� " + cerrado_z;
    titmsg_z = titulo_z + " " + cerrado_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }

  mensaje_z = "Seguro de abrir " + este_z + " " + titulo_z;
  titmsg_z = "Abrir" + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  prove_z = qry_entradas->FieldByName("prove")->AsString;
  nentrada_z = qry_entradas->FieldByName("numero")->AsInteger;
  qry_entpag->Close();
  qry_entpag->ParamByName("numentrada")->AsInteger = nentrada_z;
  qry_entpag->ParamByName("prove")->AsString = prove_z;
  qry_entpag->ParamByName("cia")->AsInteger = cia_z;
  qry_entpag->Open();
  //  ==> Si ya existe una Entrada primero se Borran todos los movtos <==  *
  if(!qry_entpag->IsEmpty()) {
    qry_entpag->Delete();
  }
  qry_mventpag->Close();
  qry_mventpag->ParamByName("entrada")->AsInteger = nentrada_z;
  qry_mventpag->ParamByName("prove")->AsString = prove_z;
  qry_mventpag->ParamByName("cia")->AsInteger = cia_z;
  qry_mventpag->Open();
  for(qry_mventpag->First(); !qry_mventpag->Eof; qry_mventpag->Next()) qry_mventpag->Delete();
  qry_entradas->Edit();
  if(dm->usrmaster_z) qry_entradas->FieldByName("status")->AsString = "A";
  qry_entradas->FieldByName("recemi")->AsString = "A";
  qry_entradas->Post();
  try {
      dm->manvehi->StartTransaction();
      qry_entpag->ApplyUpdates();
      qry_mventpag->ApplyUpdates();
      qry_entradas->ApplyUpdates();
      dm->manvehi->Commit();
  } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  mensaje_z = titulo_z + " " + cerrado_z;
  titmsg_z = titulo_z + " " + cerrado_z;
  Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), 0);

}
//---------------------------------------------------------------------------

void __fastcall TForm_capentpro::ver_datospedExecute(TObject *Sender)
{
   if(qry_renentra->IsEmpty()) return;
   String alm_z, codigo_z, serie_z;
   int ancho_z, alto_z, entrada_z;
   alm_z = qry_renentra->FieldByName("alm")->AsString;
   codigo_z = qry_renentra->FieldByName("codinv")->AsString;
   serie_z  = qry_renentra->FieldByName("serie")->AsString;
   entrada_z = qry_renentra->FieldByName("numero")->AsInteger;
   if(!busca_cod(codigo_z)) return;
   if(qry_inven->FieldByName("linea")->AsString != dm->lineamot_z) return;
   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datospedimento *Frame_datospedimento;
   Frame_datospedimento= new TFrame_datospedimento (Dlg_analipol);
   ancho_z = Frame_datospedimento->Width + 20;
   alto_z = Frame_datospedimento->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datospedimento->Parent = Dlg_analipol->Panel1;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Pedimento";
   Frame_datospedimento->Align = alClient;
   Frame_datospedimento->entrada_z = entrada_z;
   Frame_datospedimento->tipo_z = sTipo;
   Frame_datospedimento->alm_z = alm_z;
   Frame_datospedimento->busca_datosped(codigo_z, serie_z, alm_z);
   Dlg_analipol->btn_cancel->Visible = false;
   Dlg_analipol->btn_ok->Visible     = false;
   Dlg_analipol->ShowModal();
   delete Frame_datospedimento;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------


void __fastcall TForm_capentpro::activar_menuExecute(TObject *Sender)
{
  pop_menuren->Popup(100, 100);        
}
//---------------------------------------------------------------------------

