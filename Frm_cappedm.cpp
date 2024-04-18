//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "Frm_cappedm.h"
#include "dlgCataAlmacen.h"
#include "dmod.h"
#include "numapal.h"
#include "impre.h"
#include "Frm_selserie.h"
#include "Frm_kardex.h"
#include "imprigra.h"
#include "numapal.h"
#include "dialg_okcancel.h"
#include "Frme_datoscappedm.h"
#include "Frme_datoscappedmagrnuevo.h"
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
#pragma link "Frme_datoscappedm"
//#pragma link "Frme_datoscappedmagreg"
//#pragma link "Frme_datoscappedmagrnuevo"
#pragma resource "*.dfm"
#include "situaciones.h"
const int MAX_LINEAS = 60;
TForm_cappedm *Form_cappedm;
//---------------------------------------------------------------------------
//const int iTpcon=100;  //SABANAS DE FIDE
//const int iTpcon1=110; //SABANA VENTAS CELULARES
//const int iTpcon2=20; //SABANA DE VENTAS TRADICIONAL

//---------------------------------------------------------------------------
void _fastcall CapPedM(TForm *Padre, String tiposab, bool estado)
{
    try
    {
        Form_cappedm = new TForm_cappedm(Padre, tiposab, estado);
        Form_cappedm->Show();
    }
    catch(...)
    { }

}
//---------------------------------------------------------------------------
__fastcall TForm_cappedm::TForm_cappedm(TComponent* Owner, String tipo_sabana, bool estado)
    : TForm(Owner)
{
  sTipo = tipo_sabana;
  cia_z = dm->cia_z;
  idpermis_z=0;
  Frame_datoscappedm1->inicializa(sTipo);
  String perio_z, alm_z;
  int numero_z;
  //TLocateOptions Opts;
  //Opts.Clear();
  //qsPuntoVta->Close();
  //qsPuntoVta->ParamByName("cia")->AsInteger = cia_z;
  //qsPuntoVta->Open();
  //lkcmb_ptovta->KeyValue = qsPuntoVta->FieldByName("clave")->AsString;
  qry_mayorista->Close();
  qry_mayorista->ParamByName("cia")->AsInteger = cia_z;
  qry_mayorista->Open();
  //lkcmb_vendedr->KeyValue = qry_mayorista->FieldByName("codigo")->AsString;
  qsPoblacion->Close();
  qsPoblacion->Open();
  //lkcmb_poblac->KeyValue = qsPoblacion->FieldByName("numero")->AsInteger;
  if(sTipo == "G") {
    tipoest_z = EST_X_ENT_ESP;
    titulo_z = "Pedidos Mayoreo";
    genero_z = "M";
    idpermis_z = CAPEDMAY;
    valpermis_z = "Capedmay " + IntToStr(CAPEDMAY);
  } else if(sTipo == "Q") {
    tipoest_z = EST_X_VTA_CEL;
    titulo_z = "Sabana Ventas Celular";
    genero_z = "F";
    //edt_prvta->Visible = true;
    //lbl_prvta->Visible = true;
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
  //qsAlmacen->Close();
  //qsAlmacen->ParamByName("cia")->AsInteger = cia_z;
  //qsAlmacen->Open();
  //perio_z = PeriodoToString(dm->ahora());
  //qsAlmacen->Locate("clave", perio_z, Opts);
  //lkcmb_almacen->KeyValue = qsAlmacen->FieldByName("clave")->AsString;
  //abreren->Visible = dm->usrmanto_z;
  permis_z=dm->busca_permision(idpermis_z);
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  Frame_datoscappedm1->dbedt_importe->DataSource = dts_entradas;
  Frame_datoscappedm1->dbedt_iva->DataSource = dts_entradas;
  Frame_datoscappedm1->dbedt_total->DataSource = dts_entradas;
  TIniFile *ini;
  String  basedato_z, config_z, bdcartera_z;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  alm_z    =  ini->ReadString( "Form_cappedm_"+ sTipo, "ALMACEN", alm_z );
  numero_z =  ini->ReadInteger( "Form_cappedm_"+ sTipo, "NUMERO", 0);
  delete ini;
  SigteSabana(ULTIMO);

}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::LimpiarPantalla()
{
}
//---------------------------------------------------------------------------
bool __fastcall TForm_cappedm::BuscarAlmacen(String sClave)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::BuscarUltimoReg()
{
}
//---------------------------------------------------------------------------
bool __fastcall TForm_cappedm::BuscarEntrada(int iNumero)
{
    bool bResult = false;
    String alm_z, mayoris_z;
    int idcontacto_z=0;
    alm_z = Frame_datoscappedm1->qry_Almacen->FieldByName("clave")->AsString;
    qry_entradas->Close();
    qry_entradas->ParamByName("Tipo"  )->AsString = sTipo;
    qry_entradas->ParamByName("Alm"   )->AsString  = alm_z;
    qry_entradas->ParamByName("Numero")->AsInteger = iNumero;
    qry_entradas->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_entradas->Open();
    if (!qry_entradas->IsEmpty() ) {
      idcontacto_z = qry_entradas->FieldByName("perenvrec")->AsInteger;
      mayoris_z = qry_entradas->FieldByName("prove")->AsString;
      Frame_datoscappedm1->edt_facpro->Text = qry_entradas->FieldByName("facpro")->AsString;
      Frame_datoscappedm1->edt_contacto->Text = dm->busca_dato(idcontacto_z, OLDCONCEPTO);
      Frame_datoscappedm1->lkcmb_vendedr->KeyValue = mayoris_z;
       //TODO: Se puede desactivar x que existe
       //ListaRenglones;
      Frame_datoscappedm1->date_fecha->Date = qry_entradas->FieldByName("Fecha")->AsDateTime;
       bResult = true;
    }
    ListarRenglon();
    if(qry_entradas->FieldByName("status")->AsString  == "C") {
      imprime->Enabled = true;
    } else {
      imprime->Enabled = false;
    }
    return bResult;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::FormShow(TObject *Sender)
{
    //iTpcon      = cmbTipoEnt->Text.SubString(1,3).ToIntDef(0);
    //sDescriEnt = cmbTipoEnt->Text.SubString(3,40).Trim();
    cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::btn_salirClick(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::ListarRenglon()
{
    qry_renentra->Tag = INACTIVO;
    String alm_z;
    alm_z = Frame_datoscappedm1->qry_Almacen->FieldByName("clave")->AsString;
    qry_renentra->Close();
    qry_renentra->ParamByName("Tipo")->AsString = sTipo;
    qry_renentra->ParamByName("Alm" )->AsString  = alm_z;
    qry_renentra->ParamByName("Numero")->AsInteger = qry_entradas->FieldByName("Numero")->AsInteger;
    qry_renentra->ParamByName("Cia"   )->AsInteger = cia_z;
    qry_renentra->Open();
    qry_renentra->Tag = ACTIVO;
}

void __fastcall TForm_cappedm::BuscarVendedor(String sVendedor)
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
void __fastcall TForm_cappedm::BuscarPoblacion(int iPoblac)
{
    //qsPoblacion->Close();
    //qsPoblacion->ParamByName("Numero")->AsInteger = iPoblac;
    //qsPoblacion->Open();
    //if (qsPoblacion->IsEmpty() )
    //      edtPoblacion->Text = "";
    //else  edtPoblacion->Text = qsPoblacion->FieldByName("Nombre")->AsString;
}
//---------------------------------------------------------------------------
void __fastcall TForm_cappedm::BuscarPuntoVenta(String sClave)
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
void __fastcall TForm_cappedm::BuscarConcepto(int iCliente)
{
    String nombre_z;
    qsConceps->Close();
    qsConceps->ParamByName("NCon")->AsInteger = iCliente;
    qsConceps->Open();
    if (qsConceps->IsEmpty() )
         nombre_z = "NO EXISTE CONCEPTO";
    else nombre_z = qsConceps->FieldByName("Concepto")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  String alm_z;
  int numero_z;
  if(qry_entradas->State != dsInactive) {
    alm_z = qry_entradas->FieldByName("alm")->AsString;
    numero_z = qry_entradas->FieldByName("numero")->AsInteger;
    TIniFile *ini;
    String  basedato_z, config_z, bdcartera_z;
    config_z = dm->busca_inifile();
    ini = new TIniFile(config_z);
    ini->WriteString( "Form_capvtas_"+ sTipo, "ALMACEN", alm_z );
    ini->WriteInteger( "Form_capvtas_"+ sTipo, "NUMERO", numero_z);
    delete ini;
  }
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::SigteSabana(int tipo_mov)
{
    String alm_z;
    int nument_z;
    alm_z = Frame_datoscappedm1->qry_Almacen->FieldByName("clave")->AsString;
    nument_z = Frame_datoscappedm1->edt_numero->Value;
    nument_z = dm->sigte_entrada(alm_z, sTipo, nument_z, tipo_mov);
    Frame_datoscappedm1->edt_numero->Value = nument_z;
    BuscarEntrada(nument_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_cappedm::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);
}
//---------------------------------------------------------------------------



void __fastcall TForm_cappedm::nuevoExecute(TObject *Sender)
{
   int ancho_z, alto_z, nument_z=0,idcontacto_z;
   String alm_z, strfecha_z, strfechoy_z, strfecatras_z, mayoris_z, plazo_z;
   double fecha_z;
   bool todook_z = true;

   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datoscappedm *Frame_datoscappedm;
   Frame_datoscappedm = new TFrame_datoscappedm (Dlg_analipol);
   ancho_z = Frame_datoscappedm->Width + 20;
   alto_z = Frame_datoscappedm->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datoscappedm->Parent = Dlg_analipol->Panel1;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Ingrese los Datos del Pedido";
   Frame_datoscappedm->Align = alClient;
   Frame_datoscappedm->inicializa(sTipo);
   Frame_datoscappedm->accion_z = NUEVO;
   Dlg_analipol->Position = poScreenCenter;

   if( Dlg_analipol->ShowModal() == mrOk) {
     alm_z = Frame_datoscappedm->qry_Almacen->FieldByName("clave")->AsString;
     fecha_z = Frame_datoscappedm->date_fecha->Date;
     nument_z = Frame_datoscappedm->edt_numero->Value;
     mayoris_z = Frame_datoscappedm->qry_mayorista->FieldByName("codigo")->AsString;
     plazo_z = Frame_datoscappedm->edt_facpro->Text;
     idcontacto_z = dm->busca_iddato(Frame_datoscappedm->edt_contacto->Text, OLDCONCEPTO);
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
     if(todook_z) alta_ptvt(alm_z, fecha_z, nument_z,mayoris_z,idcontacto_z, plazo_z);
   }
   delete Frame_datoscappedm;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  String alm_z;
  int nument_z = 0;
  alm_z = Frame_datoscappedm1->qry_Almacen->FieldByName("clave")->AsString;
  nument_z = Frame_datoscappedm1->edt_numero->Value;
  if(!BuscarEntrada(nument_z)) return;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
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
    for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
        qry_renentra->Delete(); qry_renentra->First(); continue;
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
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::alta_ptvt(
  String alm_z, double fecha_z, int nument_z,String mayoris_z,
  int idcontacto_z, String plazo_z
)
{

   qry_entradas->Close();
   qry_entradas->ParamByName("tipo")->AsString = sTipo;
   qry_entradas->ParamByName("alm")->AsString = alm_z;
   qry_entradas->ParamByName("numero")->AsInteger = nument_z;
   qry_entradas->ParamByName("cia")->AsInteger = cia_z;
   qry_entradas->Open();
   if(!qry_entradas->IsEmpty()) return;
//   idnombre_z=dm->busca_iddato(edt_nombre->Text.Trim(), CONCEPTO);
//"insert into entradas (tipo,alm,recemi,numero,facpro,prove,
// perenvrec,status,coniva,fecha,importe,iva,total,vence,ctofin,
// tascomp,taspro,fechafac,letras,plazocfp,planp,fletes,desxap,
// fechaprp,ctofincomp,usuario,cia,

   try {
     qry_entradas->Append();
     qry_entradas->FieldByName("tipo")->AsString = sTipo;
     qry_entradas->FieldByName("alm")->AsString = alm_z;
     qry_entradas->FieldByName("recemi")->AsString = "";
     qry_entradas->FieldByName("numero")->AsInteger = nument_z;
     qry_entradas->FieldByName("facpro")->AsString = plazo_z;
     qry_entradas->FieldByName("prove")->AsString = mayoris_z;
     qry_entradas->FieldByName("perenvrec")->AsInteger = idcontacto_z;
     qry_entradas->FieldByName("status")->AsString = "A";
     qry_entradas->FieldByName("coniva")->AsString = "";
     qry_entradas->FieldByName("fecha")->AsDateTime = fecha_z;
     qry_entradas->FieldByName("importe")->AsFloat = 0;
     qry_entradas->FieldByName("iva")->AsFloat = 0;
     qry_entradas->FieldByName("total")->AsFloat = 0;
     qry_entradas->FieldByName("vence")->AsDateTime = fecha_z;
     qry_entradas->FieldByName("ctofin")->AsFloat = 0;
     qry_entradas->FieldByName("tascomp")->AsFloat = 0;
     qry_entradas->FieldByName("taspro")->AsFloat = 0;
     qry_entradas->FieldByName("fechafac")->AsDateTime = fecha_z;
     qry_entradas->FieldByName("letras")->AsInteger = 0;
     qry_entradas->FieldByName("fletes")->AsInteger = 0;
     qry_entradas->FieldByName("desxap")->AsInteger = 0;
     qry_entradas->FieldByName("planp")->AsInteger = 0;
     qry_entradas->FieldByName("plazocfp")->AsInteger = 0;
     qry_entradas->FieldByName("taspro")->AsFloat = 0;
     qry_entradas->FieldByName("ctofincomp")->AsFloat = 0;
     //qry_entradas->FieldByName("idusuario")->AsString = dm->idusuario_z;
     qry_entradas->FieldByName("fechaprp")->AsDateTime = fecha_z;
     qry_entradas->FieldByName("cia")->AsInteger = cia_z;
     qry_entradas->Post();
     dm->manvehi->StartTransaction();
     qry_entradas->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = 0;
   BuscarEntrada(nument_z);
}
//---------------------------------------------------------------------------



void __fastcall TForm_cappedm::agrerenExecute(TObject *Sender)
{

   int ancho_z, alto_z, numero_z=0, idrenentra_z=0, folio_z=0, ii_z=0, conse_z = 0, idalm_z = 0, idart_z = 0,
      identrada_z=0, idserie_z = 0, idpers_z=0, cantmueve_z=0, idvend_z=0,
      idciudad_z=0, idptovta_z=0, idcodigo_z=0, iddescri_z=0, nentrada_z=0, canti_z=0;
      String tipo_z, siono_z="S", serie_z="", entcan_z="", vendedor_z, ptovta_z,
      descri_z, alm_z, codigo_z, nombre_z;
   double piva_z=0, costo_z =0, prvta_z=0, costotot_z=0, iva_z=0;
   String cvemay_z;
   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datoscappedmagrnuevo *Frame_datoscappedmagrnuevo;
   Frame_datoscappedmagrnuevo = new TFrame_datoscappedmagrnuevo (Dlg_analipol);
   ancho_z = Frame_datoscappedmagrnuevo->Width + 20;
   alto_z = Frame_datoscappedmagrnuevo->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datoscappedmagrnuevo->Parent = Dlg_analipol->Panel1;
   Frame_datoscappedmagrnuevo->tipomayoris_z = Frame_datoscappedm1->qry_mayorista->FieldByName("tipo")->AsInteger;
   cvemay_z = Frame_datoscappedm1->qry_mayorista->FieldByName("codigo")->AsString;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Agregar Art�culo";
   Dlg_analipol->Position = poScreenCenter;
   if( Dlg_analipol->ShowModal() == mrOk) {

      canti_z = Frame_datoscappedmagrnuevo->edt_canti->Value;
      cantmueve_z = Frame_datoscappedmagrnuevo->edt_canti->Value;
      if(cantmueve_z < 1) {
        Application->MessageBox(("No pueden ser "+ IntToStr((int)Frame_datoscappedmagrnuevo->edt_canti->Value) + " Articulos").c_str(), "Incorrecto N�mero de Art�culos", MB_ICONEXCLAMATION);
        return;
      }
      tipo_z = Frame_datoscappedmagrnuevo->qry_inven->FieldByName("tipo")->AsString;
      descri_z = Frame_datoscappedmagrnuevo->edt_descri->Text.Trim().UpperCase();
      vendedor_z = "";
      nentrada_z = qry_entradas->FieldByName("numero")->AsInteger;
      siono_z = "";
      alm_z = Frame_datoscappedm1->qry_Almacen->FieldByName("clave")->AsString;
      ptovta_z = "";
      piva_z = Frame_datoscappedmagrnuevo->qry_inven->FieldByName("piva")->AsFloat;
      codigo_z = Frame_datoscappedmagrnuevo->edt_codigo->Text.Trim().UpperCase();
      //iddescri_z =dm->busca_iddato(qry_inven->FieldByName("descri")->AsString, CONCEPTO);
      idpers_z = dm->busca_iddato(descri_z, OLDCONCEPTO);
      nombre_z = descri_z;
      idciudad_z = 0;
      costo_z = Frame_datoscappedmagrnuevo->edt_costou->Value;
      costotot_z = Redondea(costo_z * canti_z, 100);
      iva_z = Redondea(costotot_z * piva_z / 100, 100);
      entcan_z = "N";
      conse_z = qry_renentra->RecordCount + 1;
      //prvta_z = edt_prvta->Value;
      //qry_conse->Close();
      //qry_conse->ParamByName("identrada")->AsInteger = identrada_z;
      //qry_conse->Open();
      //conse_z = qry_conse->FieldByName("ultren")->AsInteger;
      //qry_renentra->Close();
      //qry_insrenen->ParamByName("idrenentra")->AsInteger = -1;
      //qry_insrenen->Open();

      serie_z = "";
      // ->End if
      //select a.codigo, a.idart, b.idmovart, b.idalm, b.costo, b.modent,
      //b.folio, b.idserie, b.fecha, c.serie,
      //b.entcan, b.fecentori, facpro, b.idprove
      //idrenentra_z=dm->busca_sigid(IDRENENTRA);
      qry_renentra->Tag = NO_REFRESH;
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
      qry_renentra->FieldByName("descripcion")->AsString = descri_z;
      qry_renentra->FieldByName("serie")->AsString = serie_z;
  //      qry_renentra->FieldByName("conse")->AsInteger = ++conse_z;
      qry_renentra->FieldByName("siono")->AsString = siono_z;
      qry_renentra->FieldByName("folsal")->AsInteger = 0;
      qry_renentra->FieldByName("folent")->AsInteger = 0;
      qry_renentra->FieldByName("unids")->AsInteger = canti_z;
      qry_renentra->FieldByName("costou")->AsFloat = costo_z;
      qry_renentra->FieldByName("importe")->AsFloat = costotot_z;
      qry_renentra->FieldByName("piva")->AsFloat = piva_z;
      qry_renentra->FieldByName("cantmueve")->AsFloat = cantmueve_z;
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
      qry_entradas->Edit();
      qry_entradas->FieldByName("importe")->AsFloat       += costotot_z;
      qry_entradas->FieldByName("iva")->AsFloat           += iva_z;
      qry_entradas->FieldByName("total")->AsFloat         = qry_entradas->FieldByName("importe")->AsFloat + qry_entradas->FieldByName("iva")->AsFloat;
      qry_entradas->Post();
      try {
        dm->manvehi->StartTransaction();
        qry_entradas->ApplyUpdates();
        qry_renentra->ApplyUpdates();
        dm->manvehi->Commit();
        //qry_renentra->Close();
        //qry_renentra->ParamByName("identrada")->AsInteger = qry_entradas->FieldByName("identrada")->AsInteger;
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
   delete Frame_datoscappedmagrnuevo;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::edicion_factible(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::CierraRenExecute(TObject *Sender)
{
  return;
  bool cierre_ren_z;
  String codigo_z, serie_z, alm_z, ptovta_z, tiposal_z, siono_z, entcan_z;
  int folio_z, idcomprador_z, nsabana_z, npoblac_z, numren_z;
  double fecha_z, costou_z;
  cierre_ren_z = true; return;
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

void __fastcall TForm_cappedm::borra_renglonExecute(TObject *Sender)
{
  double costo_z, piva_z, costotot_z=0, iva_z=0;
  if(qry_renentra->IsEmpty()) return;
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este rengl�n ya ha sido cerrado, no lo puede eliminar", "RENGLON CERRADO", MB_ICONEXCLAMATION);
    return;
  }
  int ii_z = Application->MessageBox("Esta Seguro de Eliminar este Rengl�n ?", "Eliminar Rengl�n", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
  if (ii_z != IDOK ) return;
  costo_z = qry_renentra->FieldByName("costou")->AsFloat;
  piva_z = qry_renentra->FieldByName("piva")->AsFloat;
  costotot_z = Redondea(costo_z * qry_renentra->FieldByName("unids")->AsFloat, 100);
  iva_z = Redondea(costotot_z * piva_z /100, 100);
  qry_entradas->Edit();
  qry_entradas->FieldByName("importe")->AsFloat       -= costotot_z;
  qry_entradas->FieldByName("iva")->AsFloat           -= iva_z;
  qry_entradas->FieldByName("total")->AsFloat         = qry_entradas->FieldByName("importe")->AsFloat + qry_entradas->FieldByName("iva")->AsFloat;
  qry_entradas->Post();
  qry_renentra->Delete();
  try {
    dm->manvehi->StartTransaction();
    qry_renentra->ApplyUpdates();
    qry_entradas->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::dbgrdRengCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
    
}
//---------------------------------------------------------------------------


void __fastcall TForm_cappedm::exporta_dbgrdExecute(TObject *Sender)
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

void __fastcall TForm_cappedm::imprimeExecute(TObject *Sender)
{
  String descrip_z,arch_z,nombre_z,usuario_z,concep_z,inic_z,usua_z,strrec_z;
  double importe_z,mub_z,total_z=0,cantidad_z=0,preciounit_z, observ_z=0,
  totalimp_z=0,iva_z,gtotal_z,precio_z=0;
  int ii_z;
  pagina_z = 1;
  strrec_z = "";
  if(Application->MessageBox("Seguro De imprimir Este Reporte ?", "Impresi�n Reporte", MB_OKCANCEL) != IDOK ) return;
     arch_z = "frm_cappedm.txt";
    if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
         Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
         return;
  }

  report_encab();
  qry_renentra->DisableControls();
  qry_renentra->Tag == NO_REFRESH;
  ii_z = 0;

   for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
     ii_z++;
     cantidad_z = qry_renentra->FieldByName("unids")->AsFloat;
     descrip_z = qry_renentra->FieldByName("descripcion")->AsString;
     preciounit_z = qry_renentra->FieldByName("costou")->AsFloat;
     importe_z = qry_renentra->FieldByName("importe")->AsFloat;
     precio_z =  qry_renentra->FieldByName("costos")->AsFloat;
     mub_z = 0;
     if(preciounit_z) mub_z =  (1-(precio_z / preciounit_z)) * 100;
     observ_z = qry_renentra->FieldByName("cantmueve")->AsFloat;
     if(sTipo != "G") {
       if (observ_z) strrec_z = cjust(FormatFloat("0", observ_z), 10);
     }
     if(ii_z == qry_renentra->RecordCount)
       fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
     fprintf(archout, "|");
     fprintf(archout, "%s|", ljust(cantidad_z , 5));
     fprintf(archout, "%s|", ljust(descrip_z , 30));
     fprintf(archout, "%s|", rjust(FormatFloat("#,###,##0.00", preciounit_z), 12));
     fprintf(archout, "%s|", rjust(FormatFloat("#,###,##0.00", importe_z), 12));
     fprintf(archout, "%s|", rjust(FormatFloat("#,###,##0.00", mub_z ), 6));
     fprintf(archout, "%s|",cjust(strrec_z, 13));
     if(ii_z == qry_renentra->RecordCount)
       fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
     fprintf(archout, "\n");
     totalimp_z += importe_z;
     lineas_z += 1;
     checa_salto_pag(3);
     mub_z = 0;
     observ_z= 0;
     strrec_z = "";
  }
  iva_z = qry_entradas->FieldByName("iva")->AsFloat;
  fprintf(archout,"\n\n");
  fprintf(archout, "%sPlazo:%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    qry_entradas->FieldByName("facpro")->AsString,
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s", ljust("Condiciones de Compra:",84));
  fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout,"\n\n");

  gtotal_z = totalimp_z + iva_z;
  fprintf(archout, "%s\n%s\n%s\n\n",
    rjust("Importe:" + rjust(FormatFloat("#,###,##0.00", totalimp_z), 12), 63),
    rjust("    Iva:" + rjust(FormatFloat("#,###,##0.00", iva_z), 12), 63),
    rjust("  Total:" + rjust(FormatFloat("#,###,##0.00", gtotal_z), 12), 63)
  );

  fprintf(archout,"\n");
   fprintf(archout, "%s\n",
    rjust("Total:" + ljust(FormatFloat("#,###,##0.00", gtotal_z), 12), 16));

  inic_z = qry_entradas->FieldByName("usuario")->AsString;
  qry_usuarios->Close();
  qry_usuarios->ParamByName("INIC")->AsString = inic_z;
  qry_usuarios->Open();

  usua_z = qry_usuarios->FieldByName("login")->AsString;
  fprintf(archout,"\n");
  fprintf(archout, "Elaboro:%s%s%s\n",
    dm->font_impre(dm->impre_z, EMPHIZED_ON), inic_z + " " + usua_z,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout,"\n");
  fprintf(archout, "Almacen __________________ Facturacion _____________________ ACL _________________\n");
  fclose(archout);
  totalimp_z  = gtotal_z = iva_z = 0;
  qry_renentra->Tag == SI_REFRESH;
  qry_renentra->EnableControls();
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::report_encab()
{
  int idcontacto_z=0;
  String contacto_z = "";
  idcontacto_z = qry_entradas->FieldByName("perenvrec")->AsInteger;
  contacto_z = dm->busca_dato(idcontacto_z, OLDCONCEPTO);

  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de %s\n", titulo_z);
  fprintf(archout, "Pedido:%s%s %6d Fecha:%s%s\n",
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    Frame_datoscappedm1->qry_Almacen->FieldByName("clave")->AsString,
    qry_entradas->FieldByName("numero")->AsInteger,
    FormatDateTime("dd-mm-yyyy", qry_entradas->FieldByName("fecha")->AsDateTime),
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout, "Mayorista:%s%s %s%s\n",
    dm->font_impre(dm->impre_z, EMPHIZED_ON),
    Frame_datoscappedm1->qry_mayorista->FieldByName("codigo")->AsString,
    Frame_datoscappedm1->qry_mayorista->FieldByName("nombre")->AsString,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout, "Contacto :%s%s%s\n",
    dm->font_impre(dm->impre_z, EMPHIZED_ON), contacto_z,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout, "%s|%s|%s|%s|%s|%s|%s|%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    ljust("Canti", 5),
    cjust("Descripcion", 30),
    rjust("Precio Unit.", 12),
    rjust("Importe", 12),
    ljust("M.U.B", 6),
    ljust("Observaciones", 13),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------

bool __fastcall TForm_cappedm::checa_salto_pag(int margen_z)
{
  bool haysalto_z = false;
  if(lineas_z > (MAX_LINEAS - margen_z)) {
    fprintf(archout, "%c", 12);
    pagina_z++;
    report_encab();
    haysalto_z = true;
  }
  return (haysalto_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_cappedm::busca_cod(String codigo_z)
{
}
//---------------------------------------------------------------------------

double __fastcall TForm_cappedm::calcu_prvta()
{
}

//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::dbgrdRengKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
  if(Key == VK_INSERT) agrerenExecute(Sender);
  if(Key == VK_DELETE) borra_renglonExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::cerrar_entradaExecute(TObject *Sender)
{
  String status_z;
  if(qry_entradas->IsEmpty()) return;
  if(permis_z != "A" && permis_z != "T") {
     Application->MessageBox("Lo siento, no puede Agrear datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
     return;
  }
  status_z = qry_entradas->FieldByName("status")->AsString;
  if( status_z == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente";
    titmsg_z = "Imposible Cerrar" + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  qry_entradas->Edit();
  qry_entradas->FieldByName("status")->AsString = "C";
  qry_entradas->Post();
  try {
    dm->manvehi->StartTransaction();
    qry_entradas->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z;
  titmsg_z = titulo_z + " " + "Cerrado";
  Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
  if(qry_entradas->FieldByName("status")->AsString  == "C") {
      imprime->Enabled = true;
  } else {
      imprime->Enabled = false;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::despliega_menuExecute(TObject *Sender)
{
  pop_menuren->Popup(100, 100);        
}
//---------------------------------------------------------------------------

void __fastcall TForm_cappedm::ver_permisionExecute(TObject *Sender)
{
  dm->MensajeError("Permision:" + valpermis_z, "Permision");
}
//---------------------------------------------------------------------------

