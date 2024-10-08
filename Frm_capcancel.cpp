//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "dialg_busartic.h"
#include "dialg_okcancel.h"
#include "Frm_CapturaObsPed.h"
#include "Frm_capcancel.h"
#include "dlgCataAlmacen.h"
#include "dmod.h"
#include "impre.h"
#include "Frm_selserie.h"
#include "Frm_kardex.h"
#include "Frm_prever.h"
#include "imprigra.h"
#include "numapal.h"
#include "situaciones.h"
#include "Frme_datoscapcancelagrega.h"
#include <inifiles.hpp>
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
#pragma link "Frme_datoscapcancel"
#pragma link "Frme_datoscapcancelagrega"
#pragma link "Frme_datoscaptrasp"
#pragma resource "*.dfm"
TForm_capcancel *Form_capcancel;
//---------------------------------------------------------------------------
//const int iTpcon=100;  //SABANAS DE FIDE
//const int iTpcon1=110; //SABANA VENTAS CELULARES
//const int iTpcon2=20; //SABANA DE VENTAS TRADICIONAL

//---------------------------------------------------------------------------
void _fastcall CapCancel(TForm *Padre, String tiposab, bool estado)
{
    try
    {
        Form_capcancel = new TForm_capcancel(Padre, tiposab, estado);
        Form_capcancel->Show();
    }
    catch(...)
    { }

}
//---------------------------------------------------------------------------
__fastcall TForm_capcancel::TForm_capcancel(TComponent* Owner, String tipo_sabana, bool estado)
    : TForm(Owner)
{
  sTipo = tipo_sabana;
  int idpermis_z = 0;
  cia_z = dm->cia_z;
  String config_z, alm_z;
  Frame_datoscaptrasp1->inicializa(sTipo);
  TIniFile *ini;
  config_z = dm->busca_inifile();

  if(sTipo == "C") {
    tipoest_z = EST_X_CAN_TRAD;
    titulo_z = "Sabana Cancelaciones Tradicional";
    genero_z = "F";
    idpermis_z = CAPCANCEL;
  } else if(sTipo == "U") {
    tipoest_z = EST_X_CAN_CEL;
    titulo_z = "Sabana Cancelaciones Celular";
    genero_z = "F";
    idpermis_z = CAPCANCELCEL;
    Frame_datoscapcancelagrega1->edt_prvta->Visible = true;
    Frame_datoscapcancelagrega1->lbl_prvta->Visible = true;
  } else if(sTipo == "P") {
    tipoest_z = EST_X_ENT_ESP;
    titulo_z = "Sabana Entradas Especiales";
    genero_z = "F";
    idpermis_z = CAPENTES;
    Frame_datoscapcancelagrega1->edt_prvta->Visible = true;
    Frame_datoscapcancelagrega1->lbl_prvta->Visible = true;
  } else if(sTipo == "J") {
    tipoest_z = EST_X_CAN_FID;
    titulo_z = "Sabana Cancelaciones Fide";
    genero_z = "F";
    idpermis_z = CAPCANCELFIDE;
  } else if(sTipo == "O") {
    tipoest_z = EST_X_CAN_FON;
    titulo_z = "Sabana Cancelaciones FONACOT";
    genero_z = "F";
    idpermis_z = CAPCANFO;
  } else if(sTipo == "2") {
    tipoest_z = EST_X_CAN_IMEVI;
    titulo_z = "Sabana Cancelaciones IMEVI";
    genero_z = "F";
    idpermis_z = CAPCANCELIMEVI;
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
    abreren->Visible = true;
  } else {
    abreren->Visible = false;
  }

  permis_z=dm->busca_permision(idpermis_z);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  ini = new TIniFile(config_z);
  alm_z = ini->ReadString( "Frm_capcancel_" + sTipo, "ALMACEN", "AL" );
  delete ini;
  Frame_datoscaptrasp1->dbedt_importe->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_iva->DataSource = dts_entradas;
  Frame_datoscaptrasp1->dbedt_total->DataSource = dts_entradas;
  Frame_datoscaptrasp1->lkcmb_almacen->KeyValue = alm_z;
  SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::LimpiarPantalla()
{
}
//---------------------------------------------------------------------------
bool __fastcall TForm_capcancel::BuscarAlmacen(String sClave)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::edtNumeroKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
       if (!BuscarEntrada(Frame_datoscaptrasp1->edt_numero->Text.Trim().ToIntDef(0) ) ) {
           Application->MessageBox("No Existe El Numero de Entrada Solicitado !!", "Entrada", MB_OK | MB_ICONQUESTION);
           return;
       }
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm_capcancel::BuscarUltimoReg()
{
    String alm_z;
    alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
    qsConseInv->Close();
    qsConseInv->ParamByName("Tpcon")->AsInteger = iTpcon;
    qsConseInv->ParamByName("Alm"  )->AsString  = alm_z;
    qsConseInv->ParamByName("Cia"  )->AsInteger = cia_z;
    qsConseInv->Open();
    if (qsConseInv->IsEmpty() ) {
       // (:numtip, :alm, :descri, :ultimo, :cia)
       qiConseInv->Close();
       qiConseInv->ParamByName("NumTip")->AsInteger = iTpcon;
       qiConseInv->ParamByName("Alm"   )->AsString  = alm_z;
       qiConseInv->ParamByName("Descri")->AsString  = sDescriEnt;
       qiConseInv->ParamByName("Ultimo")->AsInteger = 0;
       qiConseInv->ParamByName("Cia"   )->AsInteger = cia_z;
       qiConseInv->Open();
    }
    else
       Frame_datoscaptrasp->edt_numero->Value = qsConseInv->FieldByName("Ultimo")->AsInteger + 1;
}
//---------------------------------------------------------------------------
bool __fastcall TForm_capcancel::BuscarEntrada(int iNumero)
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
       Frame_datoscaptrasp1->edt_numero->Value = qsEntradas->FieldByName("numero")->AsInteger;
       bResult = true;
    }
    ListarRenglon();
    if(qsEntradas->FieldByName("status")->AsString == "C") {
      cerrar_entrada->Enabled = false;
    } else {
      cerrar_entrada->Enabled = true;
    }
    return bResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capcancel::FormShow(TObject *Sender)
{
    cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::btn_salirClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::ListarRenglon()
{
    qry_renentra->Tag = INACTIVO;
    String alm_z;
    int nentrada_z=0;
    alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
    nentrada_z = qsEntradas->FieldByName("Numero")->AsInteger;
    qry_renentra->Close();
    qry_renentra->ParamByName("Tipo")->AsString = sTipo;
    qry_renentra->ParamByName("Alm" )->AsString  = alm_z;
    qry_renentra->ParamByName("Numero")->AsInteger = nentrada_z;
    qry_renentra->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_renentra->Open();
    ultrenentra_z = dm->sigte_renentra(alm_z, sTipo, nentrada_z);
    qry_renentra->Tag = ACTIVO;
    qry_renentraAfterScroll(qry_renentra);
}

void __fastcall TForm_capcancel::qry_renentraAfterScroll(TDataSet *DataSet)
{
  int idnombre_z=0,folio_z=0, crdocon_z=0, identcan_z, istatus_z=0;
  String descripcion_z,status_z,serie_z,statuscan_z;
  double precio_z=0;
  if (qry_renentra->Tag == INACTIVO ) return;
  idnombre_z = qry_renentra->FieldByName("PerSenvRec")->AsInteger;
  descripcion_z = qry_renentra->FieldByName("codinv")->AsString;
  folio_z   = qry_renentra->FieldByName("folent")->AsInteger;
  crdocon_z = qry_renentra->FieldByName("folsal")->AsInteger - 1;
  serie_z   = qry_renentra->FieldByName("serie")->AsString;
  statuscan_z = qry_renentra->FieldByName("entcan")->AsString;
  precio_z    = qry_renentra->FieldByName("importe")->AsFloat;

  Frame_datoscapcancelagrega1->lkcmb_vendedr->KeyValue = qry_renentra->FieldByName("Vend")->AsString;
  Frame_datoscapcancelagrega1->lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
  Frame_datoscapcancelagrega1->lkcmb_ptovta->KeyValue = qry_renentra->FieldByName("RecEmi")->AsString;
  Frame_datoscapcancelagrega1->lst_series->Items->Clear();
  Frame_datoscapcancelagrega1->lst_series->Items->Add(qry_renentra->FieldByName("serie")->AsString);
  Frame_datoscapcancelagrega1->lst_series->ItemIndex = 0;
  Frame_datoscapcancelagrega1->cmb_status->Text = qry_renentra->FieldByName("status")->AsString;
  if(statuscan_z == "S") identcan_z = 0;
  if(statuscan_z == "N") identcan_z = 1;
  Frame_datoscapcancelagrega1->cmb_entcan->ItemIndex = identcan_z;
  Frame_datoscapcancelagrega1->edt_nombre->Text = qry_renentra->FieldByName("concepto")->AsString;
  Frame_datoscapcancelagrega1->edt_prvta->Value = qry_renentra->FieldByName("prvta")->AsFloat;
  Frame_datoscapcancelagrega1->edt_codigo->Text = qry_renentra->FieldByName("codinv")->AsString;

  Frame_datoscapcancelagrega1->edt_descri->Text = descripcion_z;
  Frame_datoscapcancelagrega1->edt_folios->Text = folio_z;
  Frame_datoscapcancelagrega1->cmb_credcont->ItemIndex = crdocon_z;
  Frame_datoscapcancelagrega1->edt_costou->Text = precio_z;

}
//---------------------------------------------------------------------------
void __fastcall TForm_capcancel::BuscarVendedor(String sVendedor)
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
void __fastcall TForm_capcancel::BuscarPoblacion(int iPoblac)
{
    //qsPoblacion->Close();
    //qsPoblacion->ParamByName("Numero")->AsInteger = iPoblac;
    //qsPoblacion->Open();
    //if (qsPoblacion->IsEmpty() )
    //      edtPoblacion->Text = "";
    //else  edtPoblacion->Text = qsPoblacion->FieldByName("Nombre")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capcancel::BuscarPuntoVenta(String sClave)
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
void __fastcall TForm_capcancel::BuscarConcepto(int iCliente)
{
    qsConceps->Close();
    qsConceps->ParamByName("NCon")->AsInteger = iCliente;
    qsConceps->Open();
    if (qsConceps->IsEmpty() )
         Frame_datoscapcancelagrega1->edt_nombre->Text = "NO EXISTE CONCEPTO";
    else Frame_datoscapcancelagrega1->edt_nombre->Text = qsConceps->FieldByName("Concepto")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    Form_capcancel = NULL;
    String config_z, alm_z;
    TIniFile *ini;
    config_z = dm->busca_inifile();
    alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
    ini = new TIniFile(config_z);
    ini->WriteString( "Frm_capcancel_" + sTipo, "ALMACEN", alm_z );
    delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::SigteSabana(int tipo_mov)
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


void __fastcall TForm_capcancel::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------


void __fastcall TForm_capcancel::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  String alm_z, status_z;
  int nument_z = 0;
  alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscaptrasp1->edt_numero->Value;
  if(!BuscarEntrada(nument_z)) return;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Eliminar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  if(qsEntradas->IsEmpty()) return;
  status_z = qsEntradas->FieldByName("status")->AsString;
  if( status_z == "C") {
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
      if(status_z == "C") {
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

void __fastcall TForm_capcancel::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::alta_ptvt(String alm_z, double fecha_z, int nument_z)
{
   //alm_z = Frame_datoscapcancel->qry_Almacen->FieldByName("clave")->AsString;
   //fecha_z = Frame_datoscapcancel->date_fecha->Date;
   //nument_z = Frame_datoscapcancel->edt_numero->IntValue;
   qsEntradas->Close();
   qsEntradas->ParamByName("tipo")->AsString = sTipo;
   qsEntradas->ParamByName("alm")->AsString = alm_z;
   qsEntradas->ParamByName("numero")->AsInteger = nument_z;
   qsEntradas->ParamByName("cia")->AsInteger = cia_z;
   qsEntradas->Open();
   if(!qsEntradas->IsEmpty()) {
     Frame_datoscaptrasp->lkcmb_almacen->KeyValue = alm_z;
     BuscarEntrada(nument_z);
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



void __fastcall TForm_capcancel::agrerenExecute(TObject *Sender)
{

   int ancho_z, alto_z, numero_z=0,
       idrenentra_z=0, folio_z=0, ii_z=0, conse_z = 0, idalm_z = 0,
       idart_z = 0, identrada_z=0, idserie_z = 0, idpers_z=0,
       cantmueve_z=0, idvend_z=0, idciudad_z=0, idptovta_z=0,
       idcodigo_z=0, iddescri_z=0, nentrada_z, crdocon_z=0;
   double piva_z=0, costo_z =0, prvta_z=0;
   String msg_z, tit_z, alm_z, tipo_z, siono_z="S", serie_z="",
      entcan_z="", vendedor_z, ptovta_z,
      descri_z, codigo_z,nombre_z;
   if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
     return;
   }
   Tdlg_okcancel *Dlg_analipol;
   if(qsEntradas->FieldByName("status")->AsString == "C") {
     msg_z = "No puede agregar renglones a " + este_z + " " + titulo_z;
     tit_z = titulo_z + " Cerrado";
     Application->MessageBox(msg_z.c_str(), tit_z.c_str(), MB_ICONEXCLAMATION);
     return;
   }
   alm_z = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;

   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datoscapcancelagrega *Frame_datoscapcancelagrega;
   Frame_datoscapcancelagrega = new TFrame_datoscapcancelagrega (Dlg_analipol);
   ancho_z = Frame_datoscapcancelagrega->Width + 20;
   alto_z = Frame_datoscapcancelagrega->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datoscapcancelagrega->Parent = Dlg_analipol->Panel1;
   Frame_datoscapcancelagrega->alm_z = alm_z;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Datos";
   Dlg_analipol->Position = poScreenCenter;
   // Voy a Asignar los datos iniciales
   Frame_datoscapcancelagrega->edt_codigo->Text = Frame_datoscapcancelagrega1->edt_codigo->Text;
   Frame_datoscapcancelagrega->lkcmb_vendedr->KeyValue  = Frame_datoscapcancelagrega1->lkcmb_vendedr->KeyValue;
   Frame_datoscapcancelagrega->edt_nombre->Text = Frame_datoscapcancelagrega1->edt_nombre->Text.Trim();
   Frame_datoscapcancelagrega->lkcmb_ptovta->KeyValue = Frame_datoscapcancelagrega1->lkcmb_ptovta->KeyValue;
   Frame_datoscapcancelagrega->lkcmb_poblac->KeyValue = Frame_datoscapcancelagrega1->lkcmb_poblac->KeyValue;

   if( Dlg_analipol->ShowModal() == mrOk) {
      cantmueve_z = Frame_datoscapcancelagrega->edt_canti->Value;
      if(cantmueve_z < 1) {
        Application->MessageBox(("No pueden ser "+ IntToStr((int)Frame_datoscapcancelagrega->edt_canti->Value) + " Articulos").c_str(), "Incorrecto N�mero de Art�culos", MB_ICONEXCLAMATION);
        return;
      }
      tipo_z = Frame_datoscapcancelagrega->qry_inven->FieldByName("tipo")->AsString;
      descri_z = Frame_datoscapcancelagrega->qry_inven->FieldByName("descri")->AsString;

      if(tipo_z == "ALF" && (Frame_datoscapcancelagrega->lst_series->Items->Count != Frame_datoscapcancelagrega->edt_canti->Value ))  {
        Application->MessageBox("Debe proporcionar La Serie", "Serie Desconocida", MB_ICONEXCLAMATION);
        delete Frame_datoscapcancelagrega;
        delete Dlg_analipol;
        return;
      }

      vendedor_z = Frame_datoscapcancelagrega->qry_vendedor->FieldByName("codigo")->AsString;
      nentrada_z = qsEntradas->FieldByName("numero")->AsInteger;

      crdocon_z = Frame_datoscapcancelagrega->cmb_credcont->ItemIndex + 1;
      if(!Frame_datoscapcancelagrega->cmb_status->Text.IsEmpty()) siono_z = Frame_datoscapcancelagrega->cmb_status->Text.SubString(1,1);
      //siono_z = qsEntradas->FieldByName("coniva")->AsString;
      nombre_z = Frame_datoscapcancelagrega->edt_nombre->Text.Trim();
      ptovta_z = Frame_datoscapcancelagrega->qry_puntovta->FieldByName("clave")->AsString;
      //idart_z = qry_inven->FieldByName("idart")->AsInteger;
      codigo_z =Frame_datoscapcancelagrega->qry_inven->FieldByName("codigo")->AsString;
      //iddescri_z =dm->busca_iddato(qry_inven->FieldByName("descri")->AsString, CONCEPTO);
      piva_z = Frame_datoscapcancelagrega->qry_inven->FieldByName("piva")->AsFloat;
      idpers_z = dm->busca_iddato(nombre_z, OLDCONCEPTO);
      idciudad_z = Frame_datoscapcancelagrega->qry_poblacion->FieldByName("numero")->AsInteger;
      costo_z = Frame_datoscapcancelagrega->edt_costou->Value;
      entcan_z = Frame_datoscapcancelagrega->cmb_entcan->Text;
      conse_z =  dm->sigte_renentra(alm_z, sTipo, nentrada_z);

      if( sTipo == "U") prvta_z = Frame_datoscapcancelagrega->edt_prvta->Value;
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
        for(ii_z = 0; ii_z < Frame_datoscapcancelagrega->edt_canti->Value; ii_z++) {
          if(ii_z < Frame_datoscapcancelagrega->lst_series->Items->Count && tipo_z == "ALF") {
            serie_z = Frame_datoscapcancelagrega->lst_series->Items->Strings[ii_z];
            //idserie_z = dm->busca_iddato(serie_z, SERIE);
          } else {
            idserie_z = 0; serie_z = "";
          }
          if(siono_z == "N")
            piva_z = 0;
          else
            piva_z = Frame_datoscapcancelagrega->qry_inven->FieldByName("piva")->AsFloat;
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
          qry_renentra->FieldByName("folsal")->AsInteger = crdocon_z;
          qry_renentra->FieldByName("folent")->AsInteger = folio_z;
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
          qry_renentra->FieldByName("entosal")->AsString = "E";
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
      //btn_canceren->Enabled = false;
      //btn_aceptaren->Enabled = false;
      btn_nvoren->Tag = EN_ESPERA;
      qry_renentra->Tag = SI_REFRESH;
    }
    delete Frame_datoscapcancelagrega;
    delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::edicion_factible(int modo_z)
{
  bool modo_enabled = true, modo_readonly = false;
  switch (modo_z) {
    case READ_WRITE: modo_enabled = true; modo_readonly = false; break;
    case READ_ONLY: modo_enabled = false; modo_readonly = true; break;
  }
  Frame_datoscapcancelagrega1->lkcmb_vendedr->Enabled = modo_enabled;
  Frame_datoscapcancelagrega1->lkcmb_ptovta->Enabled = modo_enabled;
  Frame_datoscapcancelagrega1->lkcmb_poblac->Enabled = modo_enabled;
  Frame_datoscapcancelagrega1->cmb_status->Enabled = modo_enabled;
  Frame_datoscapcancelagrega1->edt_canti->ReadOnly = modo_readonly;
  Frame_datoscapcancelagrega1->edt_nombre->ReadOnly = modo_readonly;
  Frame_datoscapcancelagrega1->edt_codigo->ReadOnly = modo_readonly;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::CierraRenExecute(TObject *Sender)
{
  String mensaje_z, titmsg_z;
  if(qry_renentra->IsEmpty()) return;
  if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
     return;
  }
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este Rengl�n ya ha sido previamente Cerrado", "Rengl�n Cerrado", MB_ICONERROR);
    return;
  }
  mensaje_z = "Esta seguro de cerrar este Rengl�n y afectar Kardex ? \n una vez cerrado No puede dar marcha atr�s";
  titmsg_z = "Cerrar Rengl�n";

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    aplica_cerrar_renglon();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::aplica_cerrar_renglon()
{
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z, entcan_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
  if(qry_renentra->IsEmpty()) return;
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

void __fastcall TForm_capcancel::cancela_renglonExecute(TObject *Sender)
{
  double costo_z, piva_z;
  String msg_z, tit_z;
   if(permis_z != "B" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
     return;
   }
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este rengl�n ya ha sido cerrado, no lo puede eliminar", "RENGLON CERRADO", MB_ICONEXCLAMATION);
    return;
  }
  if(qsEntradas->FieldByName("status")->AsString == "C") {
    msg_z = "No puede eliminar renglones de " + este_z + " " + titulo_z;
    tit_z = titulo_z + " " + cerrado_z;
    Application->MessageBox(msg_z.c_str(), tit_z.c_str(), MB_ICONEXCLAMATION);
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

void __fastcall TForm_capcancel::dbgrdRengCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------


void __fastcall TForm_capcancel::exporta_dbgrdExecute(TObject *Sender)
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

void __fastcall TForm_capcancel::imprimeExecute(TObject *Sender)
{
  double piva_z=0, importe_z=0, iva_z=0, total_z=0, costo_z=0;
  String arch_z = Name+".txt", serie_z="", vnd_z="", pvta_z="",
         cred_z="", ciu_z="";
  int crdcon_z;
  if(qsEntradas->FieldByName("status")->AsString != "C") {
    mensaje_z = "debe cerrar " + este_z + " " + titulo_z +
    " para poder imprimir";
    titmsg_z = "Imposible Imprimir " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }

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
    Frame_datoscapcancelagrega1->lkcmb_poblac->KeyValue = qry_renentra->FieldByName("Poblac")->AsInteger;
    ciu_z = Frame_datoscapcancelagrega1->qry_poblacion->FieldByName("nombre")->AsString;
    crdcon_z = qry_renentra->FieldByName("folsal")->AsInteger - 1;
    cred_z = Frame_datoscapcancelagrega1->cmb_credcont->Items->Strings[crdcon_z];

    if( sTipo != "U") {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
    } else {
        costo_z = qry_renentra->FieldByName("prvta")->AsFloat;
    }

    fprintf(archout, "%s %s|", ljust(qry_renentra->FieldByName("codinv")->AsString, 13),
      ljust(qry_renentra->FieldByName("descri")->AsString, 30)
    );
    fprintf(archout, "%s|", rjust(IntToStr(qry_renentra->FieldByName("folent")->AsInteger), 5));
    fprintf(archout, "%s|", ljust(qry_renentra->FieldByName("serie")->AsString, 20));
    fprintf(archout, "%s|", ljust(qry_renentra->FieldByName("siono")->AsString, 1));
    fprintf(archout, "%s|", ljust(qry_renentra->FieldByName("concepto")->AsString, 20));
    fprintf(archout, "%s|", ljust(pvta_z, 4));
    fprintf(archout, "%s|", ljust(vnd_z, 4));
    fprintf(archout, "%s|", rjust(FormatFloat("#,###,##0.00", costo_z), 12));
    fprintf(archout, "%s|", ljust(ciu_z, 10));
    fprintf(archout, "%s|", ljust(cred_z, 4));
    fprintf(archout, "\n");
    lineas_z++;
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
  qry_renentra->Tag = SI_REFRESH;
  qry_renentra->EnableControls();
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::report_encab()
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
  fprintf(archout, "%s|", ljust("Cr/C", 4));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------




void __fastcall TForm_capcancel::capobsExecute(TObject *Sender)
{
    CapturaObservaPedido(this, qsEntradas->FieldByName("Tipo")->AsString,
                               qsEntradas->FieldByName("Alm" )->AsString,
                               qsEntradas->FieldByName("numero")->AsInteger,
                               qsEntradas->FieldByName("cia")->AsInteger,
                               "", permis_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::abrerenExecute(TObject *Sender)
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
  int ii_z = Application->MessageBox("Esta Seguro de Deshacer la afectaci�n de este Rengl�n ?", "Deshacer afectaci�n Kardex", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
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


void __fastcall TForm_capcancel::busca_cod(String codigo_z)
{
  Frame_datoscapcancelagrega1->edt_codigo->Text = codigo_z;
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::nuevoExecute(TObject *Sender)
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
   Dlg_analipol->Position = poScreenCenter;
   Frame_datoscaptrasp->accion_z = NUEVO;
   alm_z    = Frame_datoscaptrasp1->qry_Almacen->FieldByName("clave")->AsString;
   Frame_datoscaptrasp->lkcmb_almacen->KeyValue = alm_z;
   Frame_datoscaptrasp->nuevo();
   if( Dlg_analipol->ShowModal() == mrOk) {
     alm_z    = Frame_datoscaptrasp->qry_Almacen->FieldByName("clave")->AsString;
     fecha_z  = Frame_datoscaptrasp->date_fecha->Date;
     numero_z = Frame_datoscaptrasp->edt_numero->Value;
     strfechoy_z = FormatDateTime("yyyymmdd", dm->ahora());
     strfecatras_z = FormatDateTime("yyyymmdd", dm->ahora() - 90);
     strfecha_z = FormatDateTime("yyyymmdd", fecha_z);
     if( strfecha_z > strfechoy_z) {
       Application->MessageBox("Lo siento, no puede agregar fechas futuras", "Fecha Incorrecta", MB_ICONEXCLAMATION);
       todook_z = false;
     }
     if( strfecha_z < strfecatras_z ) {
       Application->MessageBox("Lo siento, no puede agregar fechas de mas de 90 d�as de diferencia", "Fecha Incorrecta", MB_ICONEXCLAMATION);
       todook_z = false;
     }
     if(todook_z) alta_ptvt(alm_z, fecha_z, numero_z);
   }
   delete Frame_datoscaptrasp;
   delete Dlg_analipol;

}
//---------------------------------------------------------------------------


void __fastcall TForm_capcancel::cerrar_entradaExecute(TObject *Sender)
{
  String status_z;
  if(qsEntradas->IsEmpty()) return;
  if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
     return;
  }
  status_z = qsEntradas->FieldByName("status")->AsString;
  if( status_z == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente";
    titmsg_z = "Imposible Cerrar" + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
    if(qry_renentra->FieldByName("status")->AsString != "C")
      aplica_cerrar_renglon();
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
  mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z;
  titmsg_z = titulo_z + " " + "Cerrado";
  Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capcancel::despliega_menuExecute(TObject *Sender)
{
  pop_menuren->Popup(100, 100);        
}
//---------------------------------------------------------------------------

