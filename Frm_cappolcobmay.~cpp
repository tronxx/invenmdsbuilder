//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_cappolcobmay.h"
#include "Frme_datosrenpolcobma.h"
#include "dlgCataAlmacen.h"
#include "dlgCnsMayorista.h"
#include "dmod.h"
#include "situaciones.h"
#include "dlgCnsPenPagMay.h"
#include "RepPolCobMa.h"
#include "Frme_datospolcobma.h"
#include "dialg_okcancel.h"
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
#pragma link "Frme_datospolcobma"
#pragma resource "*.dfm"

#define MENSA Application->MessageBox
TForm_CapPolCobMay *Form_CapPolCobMay;
//---------------------------------------------------------------------------
void __fastcall MantenimientoPolizasMayorista(TForm *Padre, int iModo_, TDateTime dtFecha_, AnsiString sAlmac_)
{
    try
    {
        Form_CapPolCobMay = new TForm_CapPolCobMay(Padre, iModo_, dtFecha_, sAlmac_);
        Form_CapPolCobMay->ShowModal();
        delete Form_CapPolCobMay;
    }
    catch(...)
    { delete Form_CapPolCobMay; }
}
//---------------------------------------------------------------------------
__fastcall TForm_CapPolCobMay::TForm_CapPolCobMay(TComponent* Owner, int iMODOp, TDateTime dtFechap, AnsiString sAlmacp)
    : TForm(Owner)
{
    iMODO = iMODOp;
    dtFechaPol = dtFechap;
    sAlmac = sAlmacp;

}
//---------------------------------------------------------------------------
bool __fastcall TForm_CapPolCobMay::BuscarAlmacen(String sClave_)
{
    bool bResult = false;
    return bResult;
}
//---------------------------------------------------------------------------

bool __fastcall TForm_CapPolCobMay::BuscarMayorista(AnsiString sMayorista_)
{
    bool bResult = false;
    return bResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm_CapPolCobMay::btnBorrarClick(TObject *Sender)
{
    LimpiarRenglon();
}
//---------------------------------------------------------------------------
void __fastcall TForm_CapPolCobMay::LimpiarRenglon()
{
}
//---------------------------------------------------------------------------

bool __fastcall TForm_CapPolCobMay::BuscarPoliza(String alm_z, int folio_z)
{
    bool bResult=false;
    qry_poliza->Close();
    qry_poliza->ParamByName("Almac")->AsString   = alm_z;
    qry_poliza->ParamByName("folio")->AsInteger  = folio_z;
    qry_poliza->ParamByName("Cia"  )->AsInteger  = cia_z;
    qry_poliza->Open();
    if (!qry_poliza->IsEmpty() ) {
        Frame_datospolcobma1->lkcmb_almacen->KeyValue = alm_z;
        Frame_datospolcobma1->edt_folio->Value = folio_z;
        Frame_datospolcobma1->date_fecha->Date = qry_poliza->FieldByName("fecha")->AsDateTime;
        Frame_datospolcobma1->edt_usuario->Text = qry_poliza->FieldByName("usuario")->AsString;
        Frame_datospolcobma1->edt_concepto->Text = qry_poliza->FieldByName("concep")->AsString;
        DesplegarRenglon();
        bResult = true;
    }
    return bResult;
}
//---------------------------------------------------------------------------
bool __fastcall TForm_CapPolCobMay::AgregarPoliza(String alm_z, int folio_z, TDateTime fecha_z, String concepto_z)
{
    bool bResult = false;
    int idconcep_z;
    if (!BuscarPoliza(alm_z, folio_z) ) {
      idconcep_z = dm->busca_iddato(concepto_z, INVCONCEPTO);
      qry_poliza->Append();
      qry_poliza->FieldByName("Alm"    )->AsString   = alm_z;
      qry_poliza->FieldByName("Fecha"  )->AsDateTime = fecha_z;
      qry_poliza->FieldByName("folio"  )->AsInteger  = folio_z;
      qry_poliza->FieldByName("idconcep")->AsInteger  = idconcep_z;
      qry_poliza->FieldByName("Importe")->AsFloat    = 0;
      qry_poliza->FieldByName("status")->AsString    = "A";
      qry_poliza->FieldByName("Usuario")->AsString   = dm->login_z;
      qry_poliza->FieldByName("Cia"    )->AsInteger  = cia_z;
      qry_poliza->Post();
      try
      {
          dm->manvehi->StartTransaction();
          qry_poliza->ApplyUpdates();
          dm->manvehi->Commit();
          bResult = true;
      }
      catch(...)
      {
          dm->manvehi->Rollback();
          MENSA("NO FUE POSIBLE AGREGAR LA POLIZA DE COBRO !!", "Error", MB_OK | MB_ICONERROR);
      }
    }
    return bResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm_CapPolCobMay::DesplegarRenglon()
{
  String alm_z;
  int folio_z;
  alm_z = qry_poliza->FieldByName("alm")->AsString;
  folio_z = qry_poliza->FieldByName("folio")->AsInteger;
  qry_renpolco->Close();
  qry_renpolco->ParamByName("Almac")->AsString   = alm_z;
  qry_renpolco->ParamByName("folio")->AsInteger  = folio_z;
  qry_renpolco->ParamByName("Cia"  )->AsInteger  = cia_z;
  qry_renpolco->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm_CapPolCobMay::dtpFechaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Shift == TShiftState() ) {
     if (Key != VK_RETURN) return;
      //TfrmCapPolCobMay::dtpFechaExit(this);
  }
}
//---------------------------------------------------------------------------



void __fastcall TForm_CapPolCobMay::actExpandirExecute(TObject *Sender)
{
    dbgrdRenglones->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapPolCobMay::actAgruparExecute(TObject *Sender)
{
    dbgrdRenglones->FullCollapse();
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapPolCobMay::actEliminarExecute(TObject *Sender)
{
    if (!qry_renpolco->Active || qry_renpolco->IsEmpty() ) {
       MENSA("NO EXISTEN RENGLONES PARA ELIMINAR !!", "Eliminar", MB_OK | MB_ICONWARNING);
       return;
    }
    if (qry_poliza->FieldByName("status")->AsString == "C") {
       MENSA("POLIZA CERRADA NO PUEDE EFECTUAR MOVIMIENTOS !!", "Cerrada", MB_OK | MB_ICONEXCLAMATION);
       return;
    }
    int iOk = MENSA("¿SEGURO DE ELIMINAR EL RENGLON SELECCIONADO?", "Confirma", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
    if (iOk != 6) return;
    bool bOk = false;
    try
    {
        dm->manvehi->StartTransaction();
        //RESTAR EL IMPORTE AL TOTAL DE LA POLIZA
        TotalPoliza(qry_renpolco->FieldByName("Importe")->AsFloat*-1);

        //BUSCAR EL MOVIMIENTO EN MOV MAY Y BUSCAR EL CARGO PARA REGRESAR
        //EL IMPORTE OIRG
        ModificarSaldoMov(qry_renpolco->FieldByName("Importe")->AsFloat*-1,
                          qry_renpolco->FieldByName("Cliente")->AsString,
                          qry_renpolco->FieldByName("Docto"  )->AsInteger,
                          qry_renpolco->FieldByName("Letra"  )->AsInteger, Now());

        //Eliminar el documento del estado de cuenta
        qry_movmay->Close();
        qry_movmay->ParamByName("Fecha"  )->AsDateTime = qry_renpolco->FieldByName("Fecha"  )->AsDateTime;
        qry_movmay->ParamByName("Mayoris")->AsString   = qry_renpolco->FieldByName("Cliente")->AsString;
        qry_movmay->ParamByName("Docto"  )->AsInteger  = qry_renpolco->FieldByName("Docto"  )->AsInteger;
        qry_movmay->ParamByName("Concep" )->AsString   = qry_renpolco->FieldByName("Concep" )->AsString;
        qry_movmay->ParamByName("Importe")->AsFloat    = qry_renpolco->FieldByName("Importe")->AsFloat;
        qry_movmay->ParamByName("Cia"    )->AsInteger  = qry_renpolco->FieldByName("Cia"    )->AsInteger;
        qry_movmay->ParamByName("Pagare" )->AsInteger  = qry_renpolco->FieldByName("Letra"  )->AsInteger;
        qry_movmay->ParamByName("idmovmay" )->AsInteger  = -1;
        qry_movmay->Open();
        if (!qry_movmay->IsEmpty() ) {
            qdMovMay2->Close();
            qdMovMay2->ParamByName("Fecha"  )->AsDateTime = qry_renpolco->FieldByName("Fecha"  )->AsDateTime;
            qdMovMay2->ParamByName("Mayoris")->AsString   = qry_renpolco->FieldByName("Cliente")->AsString;
            qdMovMay2->ParamByName("Docto"  )->AsInteger  = qry_renpolco->FieldByName("Docto"  )->AsInteger;
            qdMovMay2->ParamByName("Concep" )->AsString   = qry_renpolco->FieldByName("Concep" )->AsString;
            qdMovMay2->ParamByName("Importe")->AsFloat    = qry_renpolco->FieldByName("Importe")->AsFloat;
            qdMovMay2->ParamByName("Cia"    )->AsInteger  = qry_renpolco->FieldByName("Cia"    )->AsInteger;
            qdMovMay2->ParamByName("Pagare" )->AsInteger  = qry_renpolco->FieldByName("Letra"  )->AsInteger;
            qdMovMay2->ExecSQL();
        }
        //ELIMINAR EL MOVIMIENTO EN MOVMAY
        qdRenglon->Close();
        qdRenglon->ParamByName("Fecha")->AsDateTime = qry_renpolco->FieldByName("Fecha")->AsDateTime;
        qdRenglon->ParamByName("Alm"  )->AsString   = qry_renpolco->FieldByName("Alm"  )->AsString;
        qdRenglon->ParamByName("Cia"  )->AsInteger  = qry_renpolco->FieldByName("Cia"  )->AsInteger;
        qdRenglon->ParamByName("NumRen")->AsInteger = qry_renpolco->FieldByName("NumRen")->AsInteger;
        qdRenglon->ParamByName("Letra")->AsInteger  = qry_renpolco->FieldByName("Letra")->AsInteger;
        qdRenglon->ExecSQL();

        dm->manvehi->Commit();
        bOk = true;
    }
    catch(...)
    {
        dm->manvehi->Rollback();
        MENSA("ERROR AL TRATAR DE ELIMINAR EL RENGLON !!", "Error", MB_OK | MB_ICONERROR);
    }
    if (bOk) {
       qsCountRenPol->Close();
       qsCountRenPol->ParamByName("Fecha")->AsDateTime = qry_renpolco->FieldByName("Fecha")->AsDateTime;
       qsCountRenPol->ParamByName("Almac")->AsString   = qry_renpolco->FieldByName("Alm"  )->AsString;
       qsCountRenPol->ParamByName("Cia"  )->AsInteger  = qry_renpolco->FieldByName("Cia"  )->AsInteger;
       qsCountRenPol->Open();
       if (qsCountRenPol->FieldByName("iTotal")->AsInteger == 0) {
          try
          {
             dm->manvehi->StartTransaction();
             quPolCobStat->Close();
             quPolCobStat->ParamByName("Status")->AsString   = "A";
             quPolCobStat->ParamByName("Fecha" )->AsDateTime = qry_renpolco->FieldByName("Fecha")->AsDateTime;
             quPolCobStat->ParamByName("Alm"   )->AsString   = qry_renpolco->FieldByName("Alm"  )->AsString;
             quPolCobStat->ParamByName("Cia"   )->AsInteger  = qry_renpolco->FieldByName("Cia"  )->AsInteger;
             quPolCobStat->ExecSQL();
             dm->manvehi->Commit();
          }
          catch(...)
          {  dm->manvehi->Rollback();
          }

       }
    }

}
//---------------------------------------------------------------------------
void __fastcall TForm_CapPolCobMay::TotalPoliza(float fTotal)
{
}
//---------------------------------------------------------------------------



void __fastcall TForm_CapPolCobMay::agregar_pago(
  String mayoris_z, String concepto_z, String refer_z, double importe_z,
  int idmovafecta_z, String tipago_z
)
{
    int idmov_z = 0, folio_z=0, consemov_z, conseren_z=0,
    idconcep_z, idrenpolco_z, docto_z, pagare_z, letra_z, idpoliza_z,
    tipofac_z;
    bool bOk = false;
    double saldo_z;
    TDateTime fecha_z, vence_z;
    String alm_z;
    alm_z = qry_poliza->FieldByName("alm")->AsString;
    folio_z = qry_poliza->FieldByName("folio")->AsInteger;
    idconcep_z = qry_poliza->FieldByName("idconcep")->AsInteger;
    idpoliza_z = qry_poliza->FieldByName("idpolcob")->AsInteger;

    qry_movmay->Close();
    qry_movmay->ParamByName("Fecha"  )->AsDateTime = qry_renpolco->FieldByName("Fecha"  )->AsDateTime;
    qry_movmay->ParamByName("Mayoris")->AsString   = qry_renpolco->FieldByName("Cliente")->AsString;
    qry_movmay->ParamByName("Docto"  )->AsInteger  = qry_renpolco->FieldByName("Docto"  )->AsInteger;
    qry_movmay->ParamByName("Concep" )->AsString   = qry_renpolco->FieldByName("Concep" )->AsString;
    qry_movmay->ParamByName("Importe")->AsFloat    = qry_renpolco->FieldByName("Importe")->AsFloat;
    qry_movmay->ParamByName("Cia"    )->AsInteger  = qry_renpolco->FieldByName("Cia"    )->AsInteger;
    qry_movmay->ParamByName("Pagare" )->AsInteger  = qry_renpolco->FieldByName("Letra"  )->AsInteger;
    qry_movmay->ParamByName("idmovmay" )->AsInteger  = idmovafecta_z;
    qry_movmay->Open();
    if(qry_movmay->IsEmpty()) {
      Application->MessageBox("No existe el movimiento al que debe abonar", "Error", MB_ICONEXCLAMATION);
      return;
    }
    saldo_z   = qry_movmay->FieldByName("saldo")->AsFloat;
    docto_z   = qry_movmay->FieldByName("docto")->AsInteger;
    pagare_z  = qry_movmay->FieldByName("pagare")->AsInteger;
    tipofac_z = qry_movmay->FieldByName("tipofac")->AsInteger;
    vence_z   = qry_movmay->FieldByName("vence")->AsInteger;

    qry_numren->Close();
    qry_numren->ParamByName("Alm")->AsString   = alm_z;
    qry_numren->ParamByName("folio")->AsInteger = folio_z;
    qry_numren->ParamByName("Cia"  )->AsInteger  = cia_z;
    qry_numren->Open();
    conseren_z = qry_numren->FieldByName("IdNumRen")->AsInteger + 1;
    qry_numren->Close();
    qsSigConseMov->Close();
    qsSigConseMov->ParamByName("Mayoris")->AsString   = mayoris_z;
    qsSigConseMov->ParamByName("Fecha"  )->AsDateTime = fecha_z;
    qsSigConseMov->ParamByName("Cia"    )->AsInteger  = cia_z;
    qsSigConseMov->Open();
    consemov_z = qsSigConseMov->FieldByName("IdMovto")->AsInteger + 1;
    qsSigConseMov->Close();

    idconcep_z = dm->busca_iddato(concepto_z, INVCONCEPTO);
    idrenpolco_z = dm->busca_sigid(IDRENPOLCOB);
    idmov_z = dm->busca_sigid(IDMOVMAY2);
    qry_renpolco->Append();
    qry_renpolco->FieldByName("alm")->AsString = alm_z;
    qry_renpolco->FieldByName("fecha")->AsDateTime = fecha_z;
    qry_renpolco->FieldByName("numren")->AsInteger = conseren_z;
    qry_renpolco->FieldByName("docto")->AsInteger = docto_z;
    qry_renpolco->FieldByName("refer")->AsString = refer_z;
    qry_renpolco->FieldByName("concep")->AsString = concepto_z;
    qry_renpolco->FieldByName("importe")->AsFloat = importe_z;
    qry_renpolco->FieldByName("cliente")->AsString = mayoris_z;
    qry_renpolco->FieldByName("letra")->AsInteger = letra_z;
    qry_renpolco->FieldByName("cia")->AsInteger = cia_z;
    qry_renpolco->FieldByName("tipago")->AsString = tipago_z;
    qry_renpolco->FieldByName("idpolcob")->AsInteger = idpoliza_z;
    qry_renpolco->FieldByName("folio")->AsInteger = folio_z;
    qry_renpolco->FieldByName("idrenpolco")->AsInteger = idrenpolco_z;
    qry_renpolco->FieldByName("idconcep")->AsInteger = idconcep_z;
    qry_renpolco->FieldByName("tipofac")->AsInteger = tipofac_z;
    qry_renpolco->Post();
    try
    {
        dm->manvehi->StartTransaction();

        qiMovMay->Close();
        qiMovMay->ParamByName("Mayoris")->AsString  = mayoris_z;
        qiMovMay->ParamByName("Docto"  )->AsInteger = docto_z;
        qiMovMay->ParamByName("Pagare" )->AsInteger = pagare_z;
        qiMovMay->ParamByName("Conse"  )->AsInteger = consemov_z;
        qiMovMay->ParamByName("Fecha"  )->AsDateTime= fecha_z;
        qiMovMay->ParamByName("Vence"  )->AsDateTime= vence_z;
        qiMovMay->ParamByName("Concep" )->AsString  = concepto_z;
        qiMovMay->ParamByName("Coa"    )->AsString  = "A";
        qiMovMay->ParamByName("Importe")->AsFloat   = importe_z;
        qiMovMay->ParamByName("Saldo"  )->AsFloat   = saldo_z - importe_z;
        qiMovMay->ParamByName("Cia"    )->AsInteger = dm->cia_z;
        qiMovMay->ParamByName("Tipago" )->AsString  = tipago_z;
        qiMovMay->ParamByName("idconcep")->AsInteger = idconcep_z;
        qiMovMay->ParamByName("fecsal"  )->AsDateTime = fecha_z;
        qiMovMay->ParamByName("idmov"   )->AsInteger = idmov_z;
        qiMovMay->ParamByName("tipofac" )->AsInteger = tipofac_z;
        qiMovMay->ExecSQL();
        //AFECTAR MOVIMIENTO QUE SE ESTA PAGANDO
        ModificarSaldoMov(importe_z, mayoris_z, docto_z, pagare_z, fecha_z );

        dm->manvehi->Commit();
        bOk = true;
    }
    catch(...)
    {
        dm->manvehi->Rollback();
        MENSA("Error al intentar grabar el movimiento de pago !!", "Error", MB_OK | MB_ICONERROR);
        return;
    }
    if (bOk) {
      DesplegarRenglon();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapPolCobMay::ModificarSaldoMov(double fImporte, String sCveMay, int iDocto, int iPagare, TDateTime fecha_z)
{
        quMovPendPag->Close();
        quMovPendPag->ParamByName("Importe")->AsFloat    = fImporte;
        quMovPendPag->ParamByName("Mayoris")->AsString   = sCveMay;
        quMovPendPag->ParamByName("Docto"  )->AsInteger  = iDocto;
        quMovPendPag->ParamByName("Pagare" )->AsSmallInt = iPagare;
        quMovPendPag->ParamByName("Cia"    )->AsSmallInt = dm->cia_z;
        quMovPendPag->ExecSQL();
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapPolCobMay::actListarExecute(TObject *Sender)
{
    DesplegarRenglon();
}
//---------------------------------------------------------------------------


void __fastcall TForm_CapPolCobMay::actImprimirExecute(TObject *Sender)
{
//       ReporteCobranzaMayoristas(dm->cia_z, edtAlmac->Text.Trim(), dtpFecha->Date);
}
//---------------------------------------------------------------------------


void __fastcall TForm_CapPolCobMay::nuevoExecute(TObject *Sender)
{
  int alto_z=0, ancho_z=0, folio_z=0;
  String alm_z, concepto_z;
  TDateTime fecha_z;
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_datospolcobma *Frame_datospolcobma;
  Frame_datospolcobma = new TFrame_datospolcobma(Dlg_datos);
  Dlg_datos->AutoSize = false;
  Frame_datospolcobma->Parent = Dlg_datos->Panel1;
  ancho_z = Frame_datospolcobma->Width + 20;
  alto_z = Frame_datospolcobma->Height + Dlg_datos->Panel2->Height + 80;
  Frame_datospolcobma->Parent = Dlg_datos->Panel1;
  Dlg_datos->Width = ancho_z ;
  Dlg_datos->Height = alto_z - 50;
  Dlg_datos->Caption = "Agregar Poliza Cobranza";
  Dlg_datos->Position = poScreenCenter;
  if(Dlg_datos->ShowModal() == mrOk) {
    alm_z = Frame_datospolcobma->qry_almacen->FieldByName("clave")->AsString;
    folio_z = Frame_datospolcobma->edt_folio->Value;
    fecha_z = Frame_datospolcobma->date_fecha->Date;
    AgregarPoliza(alm_z, folio_z, fecha_z, concepto_z);
  }
  delete Frame_datospolcobma;
  delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_CapPolCobMay::FormCreate(TObject *Sender)
{
  cia_z = dm->cia_z;        
}
//---------------------------------------------------------------------------



void __fastcall TForm_CapPolCobMay::agregar_renglonExecute(TObject *Sender)
{
  int alto_z=0, ancho_z=0, folio_z=0, idmov_z;
  String alm_z, concepto_z, mayoris_z, refer_z, tipago_z;
  double importe_z;
  TDateTime fecha_z;
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_datosrenpolcobma *Frame_datosrenpolcobma;
  Frame_datosrenpolcobma = new TFrame_datosrenpolcobma(Dlg_datos);
  Dlg_datos->AutoSize = false;
  Frame_datosrenpolcobma->Parent = Dlg_datos->Panel1;
  ancho_z = Frame_datosrenpolcobma->Width + 20;
  alto_z = Frame_datosrenpolcobma->Height + Dlg_datos->Panel2->Height + 80;
  Frame_datosrenpolcobma->Parent = Dlg_datos->Panel1;
  Dlg_datos->Width = ancho_z ;
  Dlg_datos->Height = alto_z - 50;
  Dlg_datos->Caption = "Agregar Poliza Cobranza";
  Dlg_datos->Position = poScreenCenter;
  Frame_datosrenpolcobma->inicializa();
  if(Dlg_datos->ShowModal() == mrOk) {
     mayoris_z = Frame_datosrenpolcobma->qry_mayoris->FieldByName("codigo")->AsString;
     concepto_z = Frame_datosrenpolcobma->edt_concepto->Text.Trim();
     refer_z = Frame_datosrenpolcobma->edt_referencia->Text.Trim();
     importe_z = Frame_datosrenpolcobma->edt_importe->Value;
     idmov_z = Frame_datosrenpolcobma->qry_facturas->FieldByName("idmov")->AsInteger;
     //tipago_z = Frame_datosrenpolcobma->cmb_tipopago->Strings[Frame_datosrenpolcobma->cmb_tipopago->ItemIndex];
     agregar_pago(
       mayoris_z, concepto_z, refer_z, importe_z,
       idmov_z, tipago_z);
  }
  delete Frame_datosrenpolcobma;
  delete Dlg_datos;

}
//---------------------------------------------------------------------------



