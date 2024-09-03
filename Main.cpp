//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "Main.h"
#include "About.h"
#include "dmod.h"
#include <inifiles.hpp>
#include "Frm_consuinv.h"
#include "about.h"
#include "situaciones.h"
#include "Frm_impriarch.h"
#include "Frm_revision.h"
#include "Frm_mantgpodia.h"
#include "Frm_mantgpoinv.h"
#include "Frm_mantmarca.h"
#include "Frm_mantpzo.h"
//#include "Frm_capvtas.h"
#include "Frm_CapturaVentas.h"
#include "Frm_consufacma.h"
#include "Frm_capped.h"
#include "Frm_consupolcobmayo.h"
#include "Frm_ConsuMovsMay.h"
#include "dlgImpPendPagMay.h"
#include "Frm_mantcuocel.h"
#include "dlg_seltipoimp.h"
#include "Frm_captrasp.h"
#include "Frm_capcancel.h"
#include "Frm_capsales.h"
#include "Frm_canxcam.h"
#include "Frm_mantempaqe.h"
#include "Frm_mantoprove.h"
#include "Frm_mantovnd.h"
#include "Frm_capentpro.h"
#include "Frm_selecdb.h"
#include "Frm_cappedm.h"
#include "Frm_analisma.h"
#include "Frm_caprelvta.h"
#include "Frm_consrelvta.h"
#include "Frm_mantmayo.h"
#include "Frm_relsurti.h"
#include "Frm_mantoprm.h"
#include "Frm_mantotiposctes.h"
#include "Frm_mantotiposentrega.h"
#include "Frm_mantousr.h"
#include "Frm_mantoalm.h"
#include "Frm_capageemb.h"
#include "Frm_mantpermis.h"
#include <dir.h>
#include "Frm_relfacmay.h"
#include "Frm_repvtaxvnd.h"
#include "Frm_kardex.h"
#include "Form_analivtacyc.h"
#include "Frm_tabcvtcrdcon.h"
#include "Frm_condevpr.h"
#include "Frm_infent.h"
#include "Frm_reltablas.h"
#include "Frm_capsalmay.h"
#include "Frm_listpre2.h"
#include "Frm_analient.h"
#include "Frm_analifon.h"
#include "Frm_mantubivta.h"
#include "Frm_cvtaubi.h"
#include "Frm_tabcvta.h"
#include "Frm_proycom.h"
#include "Frm_mantproy.h"
#include "Frm_exiubi.h"
#include "Frm_polcampre.h"
#include "Frm_exican.h"
#include "Frm_infcvtacyc.h"
#include "Frm_hazfacma.h"
#include "Frm_mantciu.h"
#include "Frm_mantzona.h"
#include "Frm_mantlinea.h"
#include "Frm_exispcon2.h"
#include "Frm_exiserie.h"
#include "Frm_analimvm.h"
#include "Frm_relvenmy.h"
#include "Frm_mantcatprodsat.h"
#include "Frm_mantservi.h"
#include "Frm_analisabvta.h"

//---------------------------------------------------------------------------
#pragma resource "*.dfm"
TMainForm *MainForm;
//---------------------------------------------------------------------------

__fastcall TMainForm::TMainForm(TComponent *Owner)
	: TForm(Owner)
{
   TIniFile *ini;
   String  basedato_z, config_z, tipoimp_z;
   config_z = dm->config_z;
   bool max_z, usrmanto_z;
   ini = new TIniFile(config_z);
   cia_z   =  ini->ReadInteger( Name, "cia", 1 );
//   Caption =  ini->ReadString( Name, "Caption",
//                               "Default Caption" );
   max_z   = ini->ReadBool( Name, "InitMax", false );
   usrmanto_z   = ini->ReadBool( "Mantos", "UsrManto", false );
   menu_mantos->Visible = usrmanto_z;
   menu_item_movtospend->Visible = usrmanto_z;
   menu_item_permisiones->Visible = usrmanto_z;
   dm->idusuario_z=0;
   dm->usermaster_z = "S";
   if(max_z) {
     WindowState = wsMaximized;
   }  else {
     //WindowState = wsNormal;
     Top     =  ini->ReadInteger( Name, "Top", 20 );
     Height  =  ini->ReadInteger( Name, "Height", 480 );
     Width   =  ini->ReadInteger( Name, "Width", 640 );
     Left    =  ini->ReadInteger( Name, "Left", 20 );
   }
   dm->cia_z = cia_z;
   dm->impre_z   =  ini->ReadInteger( Name, "Numero Impresora", 1);
   tipoimp_z =  ini->ReadString( "Impresora", "Tipo", "Matriz" );
   dm->rutaimp_z =  ini->ReadString( "Impresora", "Ruta", "lpt" );
   dm->preview_z =  ini->ReadInteger( "Vista_previa", "Vista_previa", 0);
   dm->impresora_z = ini->ReadString( "Impresora", "Nombre", "");

   if(tipoimp_z == "Matriz")
     dm->tipoimp_z = IMPRESORA_MATRIZ;
   else
     dm->tipoimp_z = IMPRESORA_GRAFICA;
   dm->qry_ciasinv->Close();
   dm->qry_ciasinv->ParamByName("cia")->AsInteger = cia_z;
   dm->qry_ciasinv->Open();
   dm->nemp_z = dm->qry_ciasinv->FieldByName("razon")->AsString;
   if(!dm->qry_ciasinv->IsEmpty()) {
     Caption = dm->qry_ciasinv->FieldByName("razon")->AsString +
     " " + dm->manvehi->AliasName + lbl_version->Caption;
     dm->nemp_z = dm->qry_ciasinv->FieldByName("razon")->AsString;
     dm->diremp_z = dm->qry_ciasinv->FieldByName("dir")->AsString;
   }
   dm->idproyec_z = PROYEC_INVENMDS;
   if(dm->usermaster_z != "S") {
     Menu_mantoUsuarios->Visible = false;
   }
   delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CreateMDIChild(String Name)
{
	TMDIChild *Child;

	//--- create a new MDI child window ----
	Child = new TMDIChild(Application);
	Child->Caption = Name;
	if (FileExists (Name))
		Child->Memo1->Lines->LoadFromFile(Name);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileNew1Execute(TObject *Sender)
{
	CreateMDIChild("NONAME" + IntToStr(MDIChildCount + 1));
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileOpen1Execute(TObject *Sender)
{
	if (OpenDialog->Execute())
		CreateMDIChild(OpenDialog->FileName);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::HelpAbout1Execute(TObject *Sender)
{
  AboutBox = new TAboutBox(this); 
	AboutBox->ShowModal();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FileExit1Execute(TObject *Sender)
{
	Close();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Inven1Click(TObject *Sender)
{
  TForm_consuinv *Form_consuinv = new TForm_consuinv (this);
  Form_consuinv->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::menu_item_movtospendClick(TObject *Sender)
{
  TForm_revision *Form_revision = new TForm_revision (this);
  Form_revision->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Grupos1Click(TObject *Sender)
{
  TForm_mantgpoinv *Form_mantgpoinv = new TForm_mantgpoinv (this);
  Form_mantgpoinv->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Diarys1Click(TObject *Sender)
{
  TForm_mantgpodia *Form_mantgpodia = new TForm_mantgpodia (this);
  Form_mantgpodia->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Marcas1Click(TObject *Sender)
{
  TForm_mantmarca *Form_mantmarca = new TForm_mantmarca (this);
  Form_mantmarca->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PlazosListaPrecio1Click(TObject *Sender)
{
  TForm_mantpzo *Form_mantpzo = new TForm_mantpzo(this);
  Form_mantpzo->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FacturaMayoristas1Click(TObject *Sender)
{
    //TODO: OPCION DE CONSULTA DE FACTURAS DE MAYORISTAS.
    ConsultaFacturaMayoreo(this);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CapturadePedidos1Click(TObject *Sender)
{
    CapPedM(this, "G", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PolizaCobroMayoristas1Click(TObject *Sender)
{
    //ConsPolCobMayoristas(this);
    TForm_ConsPolCobMay *Form_ConsPolCobMay = new TForm_ConsPolCobMay(this);
    Form_ConsPolCobMay->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EstadoCuentaMayorista1Click(TObject *Sender)
{
    ConsultaMovtosMayoris(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ReportePendPago1Click(TObject *Sender)
{
    ImpresionPendientesMayoristas(this, true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ReporteCargosAbonos1Click(TObject *Sender)
{
    ImpresionPendientesMayoristas(this, false);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CuotasMargenUtilidadCelulares1Click(
      TObject *Sender)
{
  TForm_mantcuocel *Form_mantcuocel = new TForm_mantcuocel (this);
  Form_mantcuocel->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PropiedadesImpresora1Click(TObject *Sender)
{
  Tdialg_seltipoimp *dialg_seltipoimp = new Tdialg_seltipoimp (this);
  dialg_seltipoimp->ShowModal();
  String tipoimp_z="";
  TIniFile *ini;
  ini = new TIniFile(ChangeFileExt( Application->ExeName, ".INI" ) );
  tipoimp_z =  ini->ReadString( "Impresora", "Tipo", "Matriz" );
  dm->rutaimp_z =  ini->ReadString( "Impresora", "Ruta", "lpt" );
  dm->ff_z =  ini->ReadInteger( "Impresora", "Salto_pagina", 0 );
  dm->impresora_z = ini->ReadString( "Impresora", "Nombre", "");
  delete ini;
  if(tipoimp_z == "Matriz")
    dm->tipoimp_z = IMPRESORA_MATRIZ;
  else
    dm->tipoimp_z = IMPRESORA_GRAFICA;
  delete dialg_seltipoimp;

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CapturaSabanasdeVentasTradicional1Click(
      TObject *Sender)
{
    //TForm_capturaventas
    CapturadeSabanasVentas(this, "V", true);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Fonacot1Click(TObject *Sender)
{
    //TForm_capturaventas
    CapturadeSabanasVentas(this, "F", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Fide1Click(TObject *Sender)
{
    //TForm_capturaventas
    CapturadeSabanasVentas(this, "H", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Celular1Click(TObject *Sender)
{
    //TForm_capturaventas
    CapturadeSabanasVentas(this, "Q", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Traspasos1Click(TObject *Sender)
{
    //TForm_captrasp *Form_captrasp;
    CapturadeSabanasTraspasos(this, "T", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Devoluciones1Click(TObject *Sender)
{
    CapturadeSabanasTraspasos(this, "D", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Tradicional1Click(TObject *Sender)
{
    //Frm_capcancel.h
    CapCancel(this, "C", true);
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::SalidasEspeciales2Click(TObject *Sender)
{
    //TForm_capturaventas
    int jj_z=0;
    TForm_capturaventas *Form_capturaventas;
    Form_capturaventas = new TForm_capturaventas(this, "S", true);
    Form_capturaventas->inicializa("S");
    //CapturadeSabanasVentas(this, "S", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelacionesxCambioTradicional1Click(
      TObject *Sender)
{
  // TForm_canxcam *Form_canxcam;
  CapturadeSabanasCanXCam(this, "X", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Situaciones1Click(TObject *Sender)
{
  TForm_mantempaqe *Form_mantempaqe = new TForm_mantempaqe (this);
  Form_mantempaqe->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelacionesxCambioFonacot1Click(
      TObject *Sender)
{
  CapturadeSabanasCanXCam(this, "N", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelacionesxCambioFide1Click(TObject *Sender)
{
  CapturadeSabanasCanXCam(this, "K", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelacionesxCambioCelular1Click(
      TObject *Sender)
{
  CapturadeSabanasCanXCam(this, "W", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::MovientosInternos1Click(TObject *Sender)
{
  CapturadeSabanasCanXCam(this, "I", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EntradasEspeciales1Click(TObject *Sender)
{
    //Frm_capcancel.h
    CapCancel(this, "P", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Fonacot2Click(TObject *Sender)
{
    //Frm_capcancel.h
    CapCancel(this, "O", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Fide2Click(TObject *Sender)
{
    //Frm_capcancel.h
    CapCancel(this, "J", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Celular2Click(TObject *Sender)
{
    //Frm_capcancel.h
    CapCancel(this, "U", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Proveedores1Click(TObject *Sender)
{
  TForm_mantoprove *Form_mantoprove = new TForm_mantoprove (this);
  Form_mantoprove->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Vendedores1Click(TObject *Sender)
{
  TForm_mantovnd *Form_mantovnd = new TForm_mantovnd (this);
  Form_mantovnd->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::EntradasProveedor1Click(TObject *Sender)
{
    CapEntPro(this, "E", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::SeleccionarBasedeDatos1Click(TObject *Sender)
{
  TForm_selecbd *Form_selecbd = new TForm_selecbd (this);
  Form_selecbd->ShowModal();
  dm->conecta_db();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Mayoreo1Click(TObject *Sender)
{
   TForm_capsalmay *Form_capsalmay = new TForm_capsalmay (this, "M", true);
   Form_capsalmay->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnaliticodeMenudeoMayoreo1Click(TObject *Sender)
{
  TForm_analisma *Form_analisma = new TForm_analisma (this);
  Form_analisma->tipo_reporte("ANALISMA");
  Form_analisma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Imevi1Click(TObject *Sender)
{
    CapturadeSabanasVentas(this, "1", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::cancelimeviClick(TObject *Sender)
{
    CapCancel(this, "2", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CancelacionesxCambioImevi1Click(TObject *Sender)
{
  CapturadeSabanasCanXCam(this, "3", true);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CapturaRelacionVentas1Click(TObject *Sender)
{
  CapturaRelacionVentas(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ConsultaRelacionesdeVentas1Click(
      TObject *Sender)
{
  //"Frm_consrelvta.h"
  ConsultaRelacionVentas(this);

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Mayoristas1Click(TObject *Sender)
{
  TForm_mantmayo *Form_mantmayo = new TForm_mantmayo (this);
  Form_mantmayo->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::GenerarRelacionTraspasos1Click(TObject *Sender)
{
   GeneraRelSurti(this);
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Choferes1Click(TObject *Sender)
{
  TForm_mantoprm *Form_mantoprm = new TForm_mantoprm (this);
  Form_mantoprm->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TiposdeVenta1Click(TObject *Sender)
{
  TForm_mantotiposctes *Form_mantotiposctes = new TForm_mantotiposctes (this);
  Form_mantotiposctes->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TiposdeEntregas1Click(TObject *Sender)
{
  TForm_mantotiposentrega *Form_mantotiposentrega = new TForm_mantotiposentrega (this);
  Form_mantotiposentrega->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Menu_mantoUsuariosClick(TObject *Sender)
{
  TForm_mantousr *Form_mantousr = new TForm_mantousr (this);
  Form_mantousr->idproyec_z = PROYEC_INVENMDS;
  Form_mantousr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormShow(TObject *Sender)
{
  StatusBar->Panels->Items[0]->Text = "Usuario:" + dm->login_z;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Almacenes1Click(TObject *Sender)
{
  TForm_mantoalm *Form_mantoalm = new TForm_mantoalm (this);
  Form_mantoalm->asigna_tipo("ALMACEN");
  Form_mantoalm->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CapturaAgenda1Click(TObject *Sender)
{
  TForm_capageemb *Form_capageemb = new TForm_capageemb (this);
  Form_capageemb->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::FormDestroy(TObject *Sender)
{
   TIniFile *ini;
   String  basedato_z, config_z, tipoimp_z;
   config_z = dm->config_z;
   bool max_z, usrmanto_z;
   ini = new TIniFile(config_z);
   cia_z   =  ini->ReadInteger( Name, "cia", 1 );
//   Caption =  ini->ReadString( Name, "Caption",
//                               "Default Caption" );
   ini->WriteBool( Name, "InitMax", WindowState == wsMaximized);
   ini->WriteInteger( Name, "Top", Top );
   ini->WriteInteger( Name, "Height", Height );
   ini->WriteInteger( Name, "Width", Width );
   ini->WriteInteger( Name, "Left", Left );
   delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::menu_item_permisionesClick(TObject *Sender)
{
  TForm_mantpermis *Form_mantpermis = new TForm_mantpermis (this);
  Form_mantpermis->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Facturasrangovencimiento1Click(TObject *Sender)
{
  TForm_relfacmay *Form_relfacmay = new TForm_relfacmay (this);
  Form_relfacmay->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::VentasxVendedoryZona1Click(TObject *Sender)
{
  TForm_repvtaxvnd *Form_repvtaxvnd = new TForm_repvtaxvnd (this);
  Form_repvtaxvnd->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::CapturaRelacindeVentas1Click(TObject *Sender)
{
  //TForm_caprelvtam2 *Form_caprelvtam2 = new TForm_caprelvtam2 (this);
  //Form_caprelvtam2->Show();
  TForm_caprelvta *Form_caprelvta = new TForm_caprelvta (this);
  Form_caprelvta->calle_z = "SI";
  Form_caprelvta->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::FormActivate(TObject *Sender)
{
  if(!yaestuvo_z) {
    TForm_kardex *Form_kardex = new TForm_kardex (this);
    Form_kardex->actualiza_tablas();
    yaestuvo_z=1;
    delete Form_kardex;
  }

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PromocionesMayoreoxGrupo1Click(TObject *Sender)
{
  TForm_mantpzo *Form_mantpzo = new TForm_mantpzo(this);
  Form_mantpzo->mmo_instruc->Text = "Las promociones de mayoreo hacen que el precio sea el costo / factor";
  Form_mantpzo->tbs_articulos->Visible = false;
  Form_mantpzo->tbs_grupos->Visible = false;
  Form_mantpzo->tbs_precios->Visible = false;
  Form_mantpzo->tbs_lineas->Visible = false;

  delete Form_mantpzo->tbs_articulos;
  delete Form_mantpzo->tbs_grupos;
  delete Form_mantpzo->tbs_precios;
  delete Form_mantpzo->tbs_lineas;
  Form_mantpzo->TBS_GPOMAYOREO=0;
  Form_mantpzo->TBS_PRECIOMAYPRO=1;
  Form_mantpzo->TBS_LINEAS=-1;
  Form_mantpzo->TBS_PRECIOS=-1;
  Form_mantpzo->TBS_ARTICULOS=-1;
  Form_mantpzo->TBS_GRUPOS=-1;
  Form_mantpzo->Caption = "Mantenimiento Promociones Mayoreo";
  Form_mantpzo->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::analitico_vtasClick(TObject *Sender)
{
  TForm_analivtacyc *Form_analivtacyc = new TForm_analivtacyc (this);
  Form_analivtacyc->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::TabladeVentasCreditoContadorFonacotFide1Click(
      TObject *Sender)
{
  TForm_tabcvtcrdcon *Form_tabcvtcrdcon = new TForm_tabcvtcrdcon (this);
  Form_tabcvtcrdcon->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ConcentradoDevolucionesProveedor1Click(
      TObject *Sender)
{
  TForm_condevpr *Form_condevpr = new TForm_condevpr (this);
  Form_condevpr->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::InformedeEntradasProveedor1Click(
      TObject *Sender)
{
   TForm_infent *Form_infent = new TForm_infent (this);
   Form_infent->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RelacionesdeTablas1Click(TObject *Sender)
{
  TForm_reltablas *Form_reltablas = new TForm_reltablas (this);
  Form_reltablas->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ConsultaMovimientosMayoreo1Click(
      TObject *Sender)
{
    ConsultaMovtosMayoris(this);
        
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ListadePrecios1Click(TObject *Sender)
{
  TForm_listpre2 *Form_listpre2 = new TForm_listpre2 (this);
  Form_listpre2->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnalticodeEntradas1Click(TObject *Sender)
{
  TForm_analient *Form_analient = new TForm_analient (this);
  Form_analient->define_tiporeporte("ANALITICO_ENTRADAS");        
  Form_analient->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnalticodeVentasFONACOT1Click(TObject *Sender)
{
  TForm_analifon *Form_analifon = new TForm_analifon (this);
  Form_analifon->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::UbicacionespZonas1Click(TObject *Sender)
{
  TForm_mantubivta *Form_mantubivta = new TForm_mantubivta (this);
  Form_mantubivta->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CostodeVentasxUbicacin1Click(TObject *Sender)
{
  TForm_cvtaubi *Form_cvtaubi = new TForm_cvtaubi (this);
  Form_cvtaubi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TabladeCostodeVentas1Click(TObject *Sender)
{
  TForm_tabcvta *Form_tabcvta = new TForm_tabcvta (this);
  Form_tabcvta->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ProyeccinyComparativo1Click(TObject *Sender)
{
  TForm_proycom *Form_proycom = new TForm_proycom (this);
  Form_proycom->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ProyeccindeCostos1Click(TObject *Sender)
{
  TForm_mantproy *Form_mantproy = new TForm_mantproy (this);
  Form_mantproy->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AcumuladodeCobranzaMayoreo1Click(
      TObject *Sender)
{
  TForm_analisma *Form_analisma = new TForm_analisma (this);
  Form_analisma->selecciona_tipo_rep("ACUMAYO");
  Form_analisma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExistenciasxUbicacin1Click(TObject *Sender)
{
  TForm_exiubi *Form_exiubi = new TForm_exiubi (this);
  Form_exiubi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExistenciasMciaCancelada1Click(TObject *Sender)
{
  TForm_exican *Form_exican = new TForm_exican (this);
  Form_exican->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::InformeCostodeVentasyCancelacionesinfcvta1Click(
      TObject *Sender)
{
  TForm_infcvtacyc *Form_infcvtacyc = new TForm_infcvtacyc (this);
  Form_infcvtacyc->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnalticoxAlmacnPuntoVtaLnearepcvta1Click(
      TObject *Sender)
{
  TForm_analisma *Form_analisma = new TForm_analisma (this);
  Form_analisma->tipo_reporte("REPCVTA");
  Form_analisma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CapturadeFacturasMayoreo1Click(TObject *Sender)
{
  TForm_hazfacma *Form_hazfacma = new TForm_hazfacma (this);
  Form_hazfacma->asigna_tipo(TIPO_FACTURAS_MAYOREO);
  Form_hazfacma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PuntosdeVenta1Click(TObject *Sender)
{
  TForm_mantoalm *Form_mantoalm = new TForm_mantoalm (this);
  Form_mantoalm->asigna_tipo("PTOVTA");
  Form_mantoalm->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Ciudades1Click(TObject *Sender)
{
  TForm_mantciu *Form_mantciu = new TForm_mantciu (this);
  Form_mantciu->AsignaTipo(MANTOCIUDADES);
  Form_mantciu->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Estados1Click(TObject *Sender)
{
  TForm_mantciu *Form_mantciu = new TForm_mantciu (this);
  Form_mantciu->AsignaTipo(MANTOESTADOS);
  Form_mantciu->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ZonasyMegazonas1Click(TObject *Sender)
{
  TForm_mantzona *Form_mantzona = new TForm_mantzona(this);
  Form_mantzona->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::Lneas1Click(TObject *Sender)
{
  TForm_mantlinea *Form_mantlinea = new TForm_mantlinea (this);
  Form_mantlinea->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ReportedeEntradasparaEnvo1Click(TObject *Sender)
{
  TForm_analient *Form_analient = new TForm_analient (this);
  Form_analient->define_tiporeporte("ANALITICO_PARA_MAYOREO");
  Form_analient->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ImpresindeArchivos1Click(TObject *Sender)
{
// Aqui Va la rutina
  TForm_impriarch *Form_impriarch = new TForm_impriarch (this);
  Form_impriarch->ShowModal();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::ExistenciasparaRequerimientos1Click(
      TObject *Sender)
{
  TForm_exispcon2 *Form_exispcon2 = new TForm_exispcon2 (this);
  Form_exispcon2->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::ExistenciasconSeries1Click(TObject *Sender)
{
  TForm_exiserie *Form_exiserie = new TForm_exiserie (this);
  Form_exiserie->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::RelacinFacturasVigentes1Click(TObject *Sender)
{
  TForm_analimvm *Form_analimvm = new TForm_analimvm (this);
  Form_analimvm->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::RelacindeVencimientosxFecha1Click(
      TObject *Sender)
{
  TForm_relvenmy *Form_relvenmy = new TForm_relvenmy (this);
  Form_relvenmy->Show();


}
//---------------------------------------------------------------------------

void __fastcall TMainForm::CatlogoProductosSatCFD331Click(TObject *Sender)
{
  TForm_mantcatprodsat *Form_mantcatprodsat = new TForm_mantcatprodsat (this);
  Form_mantcatprodsat->Show();
}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PlizadeOfertas1Click(TObject *Sender)
{
  TForm_polcampre *Form_polcampre = new TForm_polcampre (this);
  Form_polcampre->inicializa("POL_OFERTAS");
  Form_polcampre->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PolizasCambiosdePrecios1Click(TObject *Sender)
{
  TForm_polcampre *Form_polcampre = new TForm_polcampre (this);
  Form_polcampre->inicializa("POL_CAMPRE");
  Form_polcampre->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TablaServiciosporArticulo1Click(TObject *Sender)
{
  TForm_mantservi *Form_mantservi = new TForm_mantservi (this);
  Form_mantservi->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::DefinirGruposconSerieAumentada1Click(
      TObject *Sender)
{
  TForm_mantservi *Form_mantservi = new TForm_mantservi (this);
  Form_mantservi->pge_servicios->ActivePage = Form_mantservi->tbs_serieaumentada;
  Form_mantservi->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::TabladeColoresSalasBicicletas1Click(
      TObject *Sender)
{
  TForm_mantservi *Form_mantservi = new TForm_mantservi (this);
  Form_mantservi->pge_servicios->ActivePage = Form_mantservi->tbs_colores;
  Form_mantservi->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PolizaOutlet1Click(TObject *Sender)
{
  TForm_polcampre *Form_polcampre = new TForm_polcampre (this);
  Form_polcampre->inicializa("POL_OUTLET");
  Form_polcampre->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::AnalticodeSabandeVentas1Click(TObject *Sender)
{
  TForm_analisabvta *Form_analisabvta = new TForm_analisabvta (this);
  Form_analisabvta->Show();
}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PlizaOfertasInternet1Click(TObject *Sender)
{
  TForm_polcampre *Form_polcampre = new TForm_polcampre (this);
  Form_polcampre->inicializa("POL_OFERTAINTERNET");
  Form_polcampre->Show();

}
//---------------------------------------------------------------------------

void __fastcall TMainForm::PlizaCambioSituacin1Click(TObject *Sender)
{
  TForm_polcampre *Form_polcampre = new TForm_polcampre (this);
  Form_polcampre->inicializa("POL_CAMBIOSITUACION");
  Form_polcampre->Show();

}
//---------------------------------------------------------------------------


void __fastcall TMainForm::PlizadepreciosASI1Click(TObject *Sender)
{
  TForm_polcampre *Form_polcampre = new TForm_polcampre (this);
  Form_polcampre->inicializa("POL_ASI");
  Form_polcampre->Show();

}
//---------------------------------------------------------------------------

