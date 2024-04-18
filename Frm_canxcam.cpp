//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_CapturaObsPed.h"
#include "Frm_canxcam.h"
#include "dlgCataAlmacen.h"
#include "dmod.h"
#include "impre.h"
#include "Frm_selserie.h"
#include "Frm_kardex.h"
#include "imprigra.h"
#include "numapal.h"
#include "dialg_okcancel.h"
#include <inifiles.hpp>
#include "Frme_datosrencanxcam.h"
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
#pragma resource "*.dfm"
#include "situaciones.h"
TForm_canxcam *Form_canxcam;
//---------------------------------------------------------------------------
//const int iTpcon=100;  //SABANAS DE FIDE
//const int iTpcon1=110; //SABANA VENTAS CELULARES
//const int iTpcon2=20; //SABANA DE VENTAS TRADICIONAL

//---------------------------------------------------------------------------
void _fastcall CapturadeSabanasCanXCam(TForm *Padre, String tiposab, bool estado)
{
    try
    {
        Form_canxcam = new TForm_canxcam(Padre, tiposab, estado);
        Form_canxcam->Show();
    }
    catch(...)
    { }

}
//---------------------------------------------------------------------------
__fastcall TForm_canxcam::TForm_canxcam(TComponent* Owner, String tipo_sabana, bool estado)
    : TForm(Owner)
{
  sTipo = tipo_sabana;
  cia_z = dm->cia_z;
  String config_z, alm_z;
  int idpermis_z = 0;
  TIniFile *ini;
  config_z = dm->busca_inifile();
  Frame_datoscaptrasp1->inicializa(tipo_sabana);
  qsPuntoVta->Close();
  qsPuntoVta->ParamByName("cia")->AsInteger = cia_z;
  qsPuntoVta->Open();
  lkcmb_ptovta->KeyValue = qsPuntoVta->FieldByName("clave")->AsString;
  qry_vendedor->Close();
  qry_vendedor->Open();
  lkcmb_vendedr->KeyValue = qry_vendedor->FieldByName("codigo")->AsString;
  qsPoblacion->Close();
  qsPoblacion->Open();
  lkcmb_poblac->KeyValue = qsPoblacion->FieldByName("numero")->AsInteger;
  idpermis_z = CANXCAM;
  if(sTipo == "X") {
    tipoest_z = CAN_X_CAM_TRAD;
    titulo_z = "Cancelacion x Cambio Tradicional";
    genero_z = "F";
  } else if(sTipo == "W") {
    tipoest_z = EST_X_CANXCAM_CEL;
    titulo_z = "Cancelacion x Cambio Celular";
    genero_z = "F";
    edt_costo->Visible = true;
    lbl_prvta->Visible = true;
    idpermis_z = CANXCAM;
  } else if(sTipo == "K") {
    tipoest_z = EST_X_CANXCAM_FID;
    titulo_z = "Cancelacion x Cambio Fide";
    genero_z = "F";
  } else if(sTipo == "I") {
    tipoest_z = EST_X_MOV_INTERNO;
    titulo_z = "Movimientos Internos";
    genero_z = "F";
  } else if(sTipo == "N") {
    tipoest_z = EST_X_CANXCAM_FON;
    titulo_z = "Cancelacion x Cambio FONACOT";
    genero_z = "F";
  } else if(sTipo == "3") {
    tipoest_z = EST_X_CANXCAM_IMEVI;
    titulo_z = "Cancelacion x Cambio IMEVI";
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
  permis_z=dm->busca_permision(idpermis_z);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  ini = new TIniFile(config_z);
  alm_z = ini->ReadString( "Frm_canxcam_" + sTipo, "ALMACEN", "AL" );
  delete ini;
  Frame_datoscaptrasp1->lkcmb_almacen->KeyValue = alm_z;
  desafecta_kardex->Visible = dm->usrmaster_z;
  Frame_datoscaptrasp1->dbedt_importe->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_iva->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_total->DataSource = dts_entradas;
  SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::LimpiarPantalla()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_canxcam::BuscarUltimoReg()
{
}
//---------------------------------------------------------------------------
bool __fastcall TForm_canxcam::BuscarEntrada(int iNumero)
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
       Frame_datoscaptrasp1->date_fecha->Date = qsEntradas->FieldByName("Fecha")->AsDateTime;
       bResult = true;
    }
    if(qsEntradas->FieldByName("status")->AsString == "C") {
      cierra_entrada->Enabled = false;
      imprime->Enabled = true;
    } else {
      cierra_entrada->Enabled = true;
      imprime->Enabled = false;
    }
    ListarRenglon();
    return bResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm_canxcam::FormShow(TObject *Sender)
{
    //iTpcon      = cmbTipoEnt->Text.SubString(1,3).ToIntDef(0);
    //sDescriEnt = cmbTipoEnt->Text.SubString(3,40).Trim();
    cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::btn_salirClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::ListarRenglon()
{
    qry_renentra->Tag = INACTIVO;
    String alm_z;
    alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
    qry_renentra->Close();
    qry_renentra->ParamByName("Tipo")->AsString = sTipo;
    qry_renentra->ParamByName("Alm" )->AsString  = alm_z;
    qry_renentra->ParamByName("Numero")->AsInteger = qsEntradas->FieldByName("Numero")->AsInteger;
    qry_renentra->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_renentra->Open();
    qry_renentra->Tag = ACTIVO;
    qry_renentraAfterScroll(qry_renentra);
}

void __fastcall TForm_canxcam::qry_renentraAfterScroll(TDataSet *DataSet)
{
  int idnombre_z=0;
  if (!qry_renentra->Active || qry_renentra->IsEmpty() || qry_renentra->Tag == INACTIVO ) return;
  edt_codigo->Text= qry_renentra->FieldByName("codinv")->AsString;
  edt_descri->Text= qry_renentra->FieldByName("descri")->AsString;
  idnombre_z = qry_renentra->FieldByName("PerSenvRec")->AsInteger;
  lkcmb_vendedr->KeyValue = qry_renentra->FieldByName("Vend")->AsString;
  lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
  lkcmb_ptovta->KeyValue = qry_renentra->FieldByName("RecEmi")->AsString;
  edt_nombre->Text = qry_renentra->FieldByName("concepto")->AsString;
  edt_costo->Value = qry_renentra->FieldByName("costou")->AsFloat;
  cmb_entosal->Text = qry_renentra->FieldByName("entosal")->AsString;
  cmb_statcan->Text = qry_renentra->FieldByName("entcan")->AsString;
  cmb_status->Text = qry_renentra->FieldByName("siono")->AsString;
  lst_series->Items->Text = qry_renentra->FieldByName("serie")->AsString;
  lst_series->ItemIndex = 0;
  if(qry_renentra->FieldByName("entosal")->AsString == "E")
    edt_folios->Text = qry_renentra->FieldByName("folent")->AsString;
  else
    edt_folios->Text = qry_renentra->FieldByName("folsal")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm_canxcam::BuscarVendedor(String sVendedor)
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
void __fastcall TForm_canxcam::BuscarPuntoVenta(String sClave)
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

void __fastcall TForm_canxcam::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    TIniFile *ini;
    String alm_z, config_z;
    config_z = dm->busca_inifile();
    ini = new TIniFile(config_z);
    alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
    ini->WriteString( "Frm_canxcam_" + sTipo, "ALMACEN", alm_z );
    delete ini;
    Form_canxcam = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::SigteSabana(int tipo_mov)
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


void __fastcall TForm_canxcam::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------



void __fastcall TForm_canxcam::nuevoExecute(TObject *Sender)
{
   int ancho_z, alto_z, numero_z=0;
   String alm_z, strfecha_z, strfechoy_z, strfecatras_z;
   double fecha_z;
   bool todook_z = true;
   if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
     return;
   }
   alm_z    = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
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
   Dlg_analipol->Caption = "Teclee los datos";
   Frame_datoscaptrasp->Align = alClient;
   Frame_datoscaptrasp->inicializa(sTipo);
   Frame_datoscaptrasp->accion_z = NUEVO;
   Frame_datoscaptrasp->lkcmb_almacen->KeyValue = alm_z;
   Dlg_analipol->Position = poScreenCenter;
   Frame_datoscaptrasp->nuevo();

   if( Dlg_analipol->ShowModal() == mrOk) {
     alm_z    = Frame_datoscaptrasp->qry_Almacen->FieldByName("clave")->AsString;
     fecha_z  = Frame_datoscaptrasp->date_fecha->Date;
     numero_z = Frame_datoscaptrasp->edt_numero->Value;
     if(dm->usermaster_z != "S") {
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
     }
   }
   if(todook_z) alta_ptvt(alm_z, fecha_z, numero_z);
   delete Frame_datoscaptrasp;
   delete Dlg_analipol;

}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  String alm_z;
  int nument_z = 0;
  alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Agrear datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
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




void __fastcall TForm_canxcam::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::alta_ptvt(String alm_z, double fecha_z, int nument_z)
{
   qsEntradas->Close();
   qsEntradas->ParamByName("tipo")->AsString = sTipo;
   qsEntradas->ParamByName("alm")->AsString = alm_z;
   qsEntradas->ParamByName("numero")->AsInteger = nument_z;
   qsEntradas->ParamByName("cia")->AsInteger = cia_z;
   qsEntradas->Open();
   if(!qsEntradas->IsEmpty()) {
      Frame_datoscaptrasp1->lkcmb_almacen->KeyValue = alm_z;
      BuscarEntrada(nument_z);
      return;
   }
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



void __fastcall TForm_canxcam::agrerenExecute(TObject *Sender)
{
   int ancho_z, alto_z, numero_z=0, factor_z = 1,
      idrenentra_z=0, folio_z=0, ii_z=0, conse_z = 0, idalm_z = 0, idart_z = 0,
      identrada_z=0, idserie_z = 0, idpers_z=0, cantmueve_z=0, idvend_z=0,
      idciudad_z=0, idptovta_z=0, idcodigo_z=0, iddescri_z=0, nentrada_z;
   String tipo_z, siono_z="S", serie_z="", entcan_z="", vendedor_z, ptovta_z,
      descri_z, codigo_z,nombre_z, entosal_z, msg_z, tit_z, alm_z;
   double piva_z=0, costo_z =0, prvta_z=0;
   Tdlg_okcancel *Dlg_analipol;
   TDateTime fecha_z;
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

   alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
   fecha_z = qsEntradas->FieldByName("fecha")->AsDateTime;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datosrencanxcam *Frame_datosrencanxcam;
   Frame_datosrencanxcam = new TFrame_datosrencanxcam (Dlg_analipol);
   ancho_z = Frame_datosrencanxcam->Width + 20;
   alto_z = Frame_datosrencanxcam->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datosrencanxcam->Parent = Dlg_analipol->Panel1;
   Frame_datosrencanxcam->fecha_z = fecha_z;
   Frame_datosrencanxcam->alm_z = alm_z;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Datos";
   Dlg_analipol->Position = poScreenCenter;
   if( Dlg_analipol->ShowModal() == mrOk) {
      entosal_z = Frame_datosrencanxcam->cmb_entosal->Text.SubString(1,1);
      cantmueve_z = Frame_datosrencanxcam->edt_canti->Value;
      if(cantmueve_z < 1) {
        Application->MessageBox(("No pueden ser "+ IntToStr((int)Frame_datosrencanxcam->edt_canti->Value) + " Articulos").c_str(), "Incorrecto Número de Artículos", MB_ICONEXCLAMATION);
        delete Dlg_analipol;
        return;
      }
      tipo_z = Frame_datosrencanxcam->qry_inven->FieldByName("tipo")->AsString;
      descri_z = Frame_datosrencanxcam->qry_inven->FieldByName("descri")->AsString;

      if(tipo_z == "ALF" && (Frame_datosrencanxcam->lst_series->Items->Count != Frame_datosrencanxcam->edt_canti->Value ))  {
        Application->MessageBox("Debe proporcionar La Serie", "Serie Desconocida", MB_ICONEXCLAMATION);
        delete Frame_datosrencanxcam;
        delete Dlg_analipol;
        return;
      }

      vendedor_z = Frame_datosrencanxcam->qry_vendedor->FieldByName("codigo")->AsString;
      nentrada_z = qsEntradas->FieldByName("numero")->AsInteger;

      if(!Frame_datosrencanxcam->cmb_status->Text.IsEmpty()) siono_z = Frame_datosrencanxcam->cmb_status->Text.SubString(1,1);
      //siono_z = qsEntradas->FieldByName("coniva")->AsString;
      nombre_z = Frame_datosrencanxcam->edt_nombre->Text.Trim();
      ptovta_z = Frame_datosrencanxcam->qry_puntovta->FieldByName("clave")->AsString;
      //idart_z = qry_inven->FieldByName("idart")->AsInteger;
      codigo_z =Frame_datosrencanxcam->qry_inven->FieldByName("codigo")->AsString;
      //iddescri_z =dm->busca_iddato(qry_inven->FieldByName("descri")->AsString, CONCEPTO);
      piva_z = Frame_datosrencanxcam->qry_inven->FieldByName("piva")->AsFloat;
      idpers_z = dm->busca_iddato(nombre_z, OLDCONCEPTO);
      idciudad_z = Frame_datosrencanxcam->qry_poblacion->FieldByName("numero")->AsInteger;
      costo_z = Frame_datosrencanxcam->edt_costo->Value;
      entcan_z = Frame_datosrencanxcam->cmb_statcan->Text;
      conse_z = dm->sigte_renentra(alm_z, sTipo, nentrada_z);

      //if( sTipo == "U") prvta_z = Frame_datosrencanxcam->edt_prvta->Value;
      if(entosal_z == "E") {
        folio_z = dm->folio_siguiente(alm_z, codigo_z);
        if(tipo_z == "GLO") {
          serie_z = ""; idserie_z = 0;
        }
      }

      try {
        qry_renentra->Tag = NO_REFRESH;
        dm->manvehi->StartTransaction();
        for(ii_z = 0; ii_z < Frame_datosrencanxcam->edt_canti->Value; ii_z++) {
          if(entosal_z == "E") {
            factor_z = 1;
            if(ii_z < Frame_datosrencanxcam->lst_series->Items->Count && tipo_z == "ALF") {
              serie_z = Frame_datosrencanxcam->lst_series->Items->Strings[ii_z];
              //idserie_z = dm->busca_iddato(serie_z, SERIE);
            } else {
              idserie_z = 0; serie_z = "";
            }
          } else {
            factor_z = -1;
            serie_z = Frame_datosrencanxcam->qry_folsel->FieldByName("serie")->AsString;
             //idserie_z = dm->busca_iddato(serie_z, SERIE);
             folio_z = Frame_datosrencanxcam->qry_folsel->FieldByName("folio")->AsInteger;
             costo_z = Frame_datosrencanxcam->qry_folsel->FieldByName("costo")->AsFloat;
             entcan_z = Frame_datosrencanxcam->qry_folsel->FieldByName("entcan")->AsString;
             qry_folsale->Close();
             qry_folsale->ParamByName("codigo")->AsString = codigo_z;
             qry_folsale->ParamByName("alm")->AsString = alm_z;
             qry_folsale->ParamByName("folio")->AsInteger = folio_z;
             qry_folsale->Open();
             if(qry_folsale->IsEmpty()) {
               dm->manvehi->Rollback();
               Application->MessageBox(("No tengo disponible el folio "+IntToStr(folio_z)).c_str(), "ERROR", MB_ICONEXCLAMATION);
               delete Dlg_analipol;
               return;
             }
          }
          if(siono_z == "N")
            piva_z = 0;
          else
            piva_z = Frame_datosrencanxcam->qry_inven->FieldByName("piva")->AsFloat;
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
          //qry_renentra->FieldByName("iddescri")->AsInteger = iddescri_z;
          qry_renentra->FieldByName("descri")->AsString = descri_z;
          qry_renentra->FieldByName("serie")->AsString = serie_z;
    //      qry_renentra->FieldByName("conse")->AsInteger = ++conse_z;
          qry_renentra->FieldByName("siono")->AsString = siono_z;
          if(entosal_z == "S") {
            qry_renentra->FieldByName("folsal")->AsInteger = folio_z;
          } else {
            qry_renentra->FieldByName("folent")->AsInteger = folio_z;
          }
          qry_renentra->FieldByName("unids")->AsInteger = 1;
          if( sTipo != "U") {
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
          qry_renentra->FieldByName("entosal")->AsString = entosal_z;
          qry_renentra->FieldByName("entcan")->AsString = entcan_z;
          qry_renentra->FieldByName("concepto")->AsString = nombre_z;
          //qry_renentra->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
          qry_renentra->FieldByName("cia")->AsInteger = cia_z;
          qry_renentra->Post();
          qsEntradas->Edit();
          qsEntradas->FieldByName("importe")->AsFloat       += costo_z*factor_z;
          qsEntradas->FieldByName("iva")->AsFloat           += costo_z * piva_z / 100 *factor_z;
          qsEntradas->FieldByName("total")->AsFloat         += costo_z * ((piva_z / 100) + 1) * factor_z;
          qsEntradas->Post();
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
      btn_nvoren->Tag = EN_ESPERA;
      qry_renentra->Tag = SI_REFRESH;
    }
    delete Frame_datosrencanxcam;
    delete Dlg_analipol;

}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::edicion_factible(int modo_z)
{
}
//---------------------------------------------------------------------------




void __fastcall TForm_canxcam::CierraRenExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z,
    entcan_z, entosal_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este Renglón ya ha sido previamente Cerrado", "Renglón Cerrado", MB_ICONERROR);
    return;
  }
  if(Application->MessageBox("Seguro de Afectar Kardex ?", "Cerrar Renglón", MB_ICONQUESTION + MB_YESNO + MB_DEFBUTTON2) != IDYES) {
    return;
  }
  siono_z = qry_renentra->FieldByName("siono")->AsString;
  codigo_z = qry_renentra->FieldByName("codinv")->AsString;
  serie_z = qry_renentra->FieldByName("serie")->AsString;
  alm_z   = qry_renentra->FieldByName("alm")->AsString;
  ptovta_z = qry_renentra->FieldByName("recemi")->AsString;
  idcomprador_z = qry_renentra->FieldByName("persenvrec")->AsInteger;
  fecha_z = qsEntradas->FieldByName("fecha")->AsDateTime;
  nsabana_z = qry_renentra->FieldByName("numero")->AsInteger;
  npoblac_z = qry_renentra->FieldByName("poblac")->AsInteger;
  numren_z = qry_renentra->FieldByName("conse")->AsInteger;
  entcan_z = qry_renentra->FieldByName("entcan")->AsString;
  costou_z = qry_renentra->FieldByName("costou")->AsFloat;
  entosal_z = qry_renentra->FieldByName("entosal")->AsString;
  if(entosal_z == "S")
    folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
  else
    folio_z = qry_renentra->FieldByName("folent")->AsInteger;

  TForm_kardex *Form_kardex = new TForm_kardex (this);
  if(entosal_z == "S")
    cierre_ren_z = Form_kardex->salida_sabana_vtas(
        codigo_z, serie_z, folio_z, fecha_z,
        alm_z, ptovta_z, sTipo,
        idcomprador_z, siono_z, nsabana_z, npoblac_z, numren_z
    );
  else
    cierre_ren_z = Form_kardex->entrada_sabana_cancel(
        codigo_z, serie_z, folio_z, fecha_z,
        alm_z, ptovta_z, sTipo,
        idcomprador_z, siono_z, nsabana_z, npoblac_z, numren_z,
        costou_z, entcan_z, ""
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

void __fastcall TForm_canxcam::elimina_renglonExecute(TObject *Sender)
{
  double costo_z, piva_z;
  int factor_z=1;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este renglón ya ha sido cerrado, no lo puede eliminar", "RENGLON CERRADO", MB_ICONEXCLAMATION);
    return;
  }
  int ii_z = Application->MessageBox("Esta Seguro de Eliminar este Renglón ?", "Eliminar Renglón", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
  if (ii_z != IDOK ) return;
  costo_z = qry_renentra->FieldByName("costou")->AsFloat;
  piva_z = qry_renentra->FieldByName("piva")->AsFloat;
  if(qry_renentra->FieldByName("entosal")->AsString == "E") {
     factor_z = 1;
  } else {
     factor_z = -1;
  }

  qsEntradas->Edit();
  qsEntradas->FieldByName("importe")->AsFloat       -= costo_z * factor_z;
  qsEntradas->FieldByName("iva")->AsFloat           -= costo_z * piva_z / 100 * factor_z;
  qsEntradas->FieldByName("total")->AsFloat         -= costo_z * ((piva_z / 100) + 1) * factor_z;
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

void __fastcall TForm_canxcam::dbgrdRengCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------


void __fastcall TForm_canxcam::exporta_dbgrdExecute(TObject *Sender)
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

void __fastcall TForm_canxcam::imprimeExecute(TObject *Sender)
{
  double piva_z=0, importe_z=0, iva_z=0, total_z=0, costo_z=0;
  int folio_z=0, factor_z;
  String arch_z = Name+".txt", serie_z="", vnd_z="", pvta_z="", ciu_z="";

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
    if(qry_renentra->FieldByName("entosal")->AsString == "E") {
      folio_z = qry_renentra->FieldByName("folent")->AsInteger;
      factor_z = 1;
    } else {
      folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
      factor_z = -1;
    }
    vnd_z = qry_renentra->FieldByName("vend")->AsString;
    pvta_z = qry_renentra->FieldByName("recemi")->AsString;
    lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
    ciu_z = qsPoblacion->FieldByName("nombre")->AsString;
    if( sTipo != "W") {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
    } else {
        costo_z = qry_renentra->FieldByName("prvta")->AsFloat;
    }

    fprintf(archout, "%s %s|%s|%s|%s|%s|%s|%s|%s|%s\n",
      ljust(qry_renentra->FieldByName("codinv")->AsString, 13),
      ljust(qry_renentra->FieldByName("descri")->AsString, 30),
      rjust(IntToStr(folio_z), 5),
      ljust(qry_renentra->FieldByName("serie")->AsString, 20),
      ljust(qry_renentra->FieldByName("siono")->AsString, 1),
      ljust(qry_renentra->FieldByName("concepto")->AsString, 20),
      ljust(pvta_z, 4),
      ljust(vnd_z, 4),
      rjust(FormatFloat("#,###,##0.00", costo_z), 12),
      ljust(ciu_z, 10)
    );
    piva_z = qry_renentra->FieldByName("piva")->AsFloat;
    importe_z += costo_z * factor_z;
    iva_z += qry_renentra->FieldByName("costou")->AsFloat * (piva_z / 100) * factor_z;
    total_z = importe_z + iva_z;
  }
  fprintf(archout, "%s\n",
    rjust(
      "Importe:" + FormatFloat("#,###,##0.00", importe_z) +
      "   Iva:" + FormatFloat("#,###,##0.00", iva_z) +
      "   Total:" + FormatFloat("#,###,##0.00", total_z), 117
    )
  );
  TQuery *qsSigte = new TQuery (this);
  String alm_z;
  int nument_z=0;
  alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  qsSigte->DatabaseName = Frame_datoscaptrasp1->qry_Almacen->DatabaseName;
  qsSigte->SQL->Text=("select * from observent where tipo = :Tipo and alm =:Almac and numero = :Numero and cia = :Cia order by conse");
  qsSigte->ParamByName("tipo")->AsString = qsEntradas->FieldByName("tipo")->AsString;
  qsSigte->ParamByName("almac")->AsString = qsEntradas->FieldByName("alm")->AsString;
  qsSigte->ParamByName("numero")->AsInteger = qsEntradas->FieldByName("numero")->AsInteger;
  qsSigte->ParamByName("cia")->AsInteger = cia_z;
  qsSigte->Open();
  for(qsSigte->First(); !qsSigte->Eof; qsSigte->Next()) {
      fprintf(archout, "%s %s\n",
        FormatDateTime("dd/mm/yyyy ", qsSigte->FieldByName("fecha")->AsDateTime),
        qsSigte->FieldByName("observs")->AsString
      );
  }
  qsSigte->Close();
  delete qsSigte;
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renentra->Tag == SI_REFRESH;
  qry_renentra->EnableControls();
  dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::report_encab()
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
  fprintf(archout, "%s%s%s|%s|%s|%s|%s|%s|%s|%s|%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON),
    cjust("Articulo", 44),
    rjust("Folio", 5),
    ljust("Serie", 20),
    ljust("E/S", 3),
    ljust("Cliente", 20),
    ljust("Pvta", 4),
    ljust("Vnd", 4),
    rjust("Costo_Unitar", 12),
    ljust("Población", 10),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------






void __fastcall TForm_canxcam::capobsExecute(TObject *Sender)
{
    CapturaObservaPedido(this, qsEntradas->FieldByName("Tipo")->AsString,
                               qsEntradas->FieldByName("Alm" )->AsString,
                               qsEntradas->FieldByName("numero")->AsInteger,
                               qsEntradas->FieldByName("cia")->AsInteger,
                               "", permis_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::desafecta_kardexExecute(TObject *Sender)
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z,
    entcan_z, entosal_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "A") {
    Application->MessageBox("Este Renglón No ha sido previamente Cerrado", "Renglón Cerrado", MB_ICONERROR);
    return;
  }
  siono_z = qry_renentra->FieldByName("siono")->AsString;
  codigo_z = qry_renentra->FieldByName("codinv")->AsString;
  serie_z = qry_renentra->FieldByName("serie")->AsString;
  alm_z   = qry_renentra->FieldByName("alm")->AsString;
  ptovta_z = qry_renentra->FieldByName("recemi")->AsString;
  idcomprador_z = qry_renentra->FieldByName("persenvrec")->AsInteger;
  fecha_z = qsEntradas->FieldByName("fecha")->AsDateTime;
  nsabana_z = qry_renentra->FieldByName("numero")->AsInteger;
  npoblac_z = qry_renentra->FieldByName("poblac")->AsInteger;
  numren_z = qry_renentra->FieldByName("conse")->AsInteger;
  entcan_z = qry_renentra->FieldByName("entcan")->AsString;
  costou_z = qry_renentra->FieldByName("costou")->AsFloat;
  entosal_z = qry_renentra->FieldByName("entosal")->AsString;
  if(entosal_z == "S")
    folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
  else
    folio_z = qry_renentra->FieldByName("folent")->AsInteger;

  TForm_kardex *Form_kardex = new TForm_kardex (this);
  if(entosal_z == "S")
    cierre_ren_z = Form_kardex->cancela_salida_sabana_vtas(
        codigo_z, serie_z, folio_z, fecha_z,
        alm_z, ptovta_z, sTipo,
        idcomprador_z, siono_z, nsabana_z, npoblac_z, numren_z
    );
  else
    cierre_ren_z = Form_kardex->cancela_entrada_sabana_cancel(
        codigo_z, serie_z, folio_z, fecha_z,
        alm_z, ptovta_z, sTipo,
        idcomprador_z, siono_z, nsabana_z, npoblac_z, numren_z,
        costou_z, entcan_z
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


void __fastcall TForm_canxcam::busca_cod(String codigo_z)
{
  edt_codigo->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::Frame_datoscaptrasp1edt_numeroKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarEntrada(Frame_datoscaptrasp1->edt_numero->Value ) ) {
           Application->MessageBox("No Existe El Numero de Entrada Solicitado !!", "Entrada", MB_OK | MB_ICONQUESTION);
           return;
       }
       //ListarRenglon();
    }

}
//---------------------------------------------------------------------------



void __fastcall TForm_canxcam::dbgrdRengKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_INSERT) agrerenExecute(Sender);
  if(Key == VK_DELETE) elimina_renglonExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_canxcam::cierra_entradaExecute(TObject *Sender)
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

void __fastcall TForm_canxcam::despliega_menuExecute(TObject *Sender)
{
  pop_menuren->Popup(100, 100);        
}
//---------------------------------------------------------------------------

