//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_consupolcobmayo.h"
#include "Frme_datosrenpolcobma.h"
#include "dmod.h"
#include "situaciones.h"
#include "numapal.h"
#include "imprigra.h"
#include "Frm_cappolcobmay.h"
#include "RepPolCobMa.h"
#include "dialg_okcancel.h"
#include "Frme_datospolcobma.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
//#pragma link "dxmdaset"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TForm_ConsPolCobMay *Form_ConsPolCobMay;
const int MAX_LINEAS = 60;
//---------------------------------------------------------------------------
void __fastcall ConsPolCobMayoristas(TForm *Padre)
{
    try
    {
      Form_ConsPolCobMay = new TForm_ConsPolCobMay(Padre);
      Form_ConsPolCobMay->Show();
    }
    catch(...)
    {
    }

}

//---------------------------------------------------------------------------
__fastcall TForm_ConsPolCobMay::TForm_ConsPolCobMay(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    Form_ConsPolCobMay = NULL;
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::MostrarPolizas()
{
    qry_polizas->Close();
    qry_polizas->ParamByName("FechaIni")->AsDateTime = dtFechaIni->Date;
    qry_polizas->ParamByName("FechaFin")->AsDateTime = dtFechaFin->Date;
    qry_polizas->ParamByName("Cia")->AsInteger  = cia_z;
    qry_polizas->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::FormCreate(TObject *Sender)
{
    int iDia = 01, iMes =0, iAnio=0;
    iMes = TDateTime::CurrentDate().FormatString("mm").ToInt();
    iAnio = TDateTime::CurrentDate().FormatString("yyyy").ToInt();
    dtFechaIni->Date = TDateTime(iAnio, iMes, iDia);
    dtFechaFin->Date = TDateTime::CurrentDate();
    cia_z = dm->cia_z;
    qry_polizas->Tag = NO_REFRESH;
    MostrarPolizas();
    qry_polizas->Tag = SI_REFRESH;
    if(qry_polizas->FieldByName("status")->AsString == "C") {
      imprrenglon->Enabled = true;
    } else {
      imprrenglon->Enabled = false;
    }
    muestra_renpolco();
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::muestra_renpolco()
{
  if(qry_polizas->IsEmpty()) return;
  qry_renpolco->Close();
  qry_renpolco->ParamByName("Alm"  )->AsString   = qry_polizas->FieldByName("Alm"  )->AsString;
  //qry_renpolco->ParamByName("Fecha")->AsDateTime = qry_polizas->FieldByName("Fecha")->AsDateTime;
  qry_renpolco->ParamByName("folio")->AsInteger  = qry_polizas->FieldByName("folio"  )->AsInteger;
  qry_renpolco->ParamByName("Cia"  )->AsInteger  = qry_polizas->FieldByName("Cia"  )->AsInteger;
  qry_renpolco->Open();
  edt_conceppol->Text = qry_polizas->FieldByName("concep"  )->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsPolCobMay::qry_polizasAfterScroll(
      TDataSet *DataSet)
{
  if(Tag == SI_REFRESH) {
    muestra_renpolco();
    if(qry_polizas->FieldByName("status")->AsString == "C") {
      imprrenglon->Enabled = true;
    } else {
      imprrenglon->Enabled = false;
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::buscarExecute(TObject *Sender)
{
   if (dtFechaIni->Date.FormatString("yyyymmdd").ToInt() > dtFechaFin->Date.FormatString("yyyymmdd").ToInt() ) {
       Application->MessageBox("La fecha inicial es mayor que la final !!", "Fechas", MB_OK | MB_ICONWARNING);
       return;
    }
    if (dtFechaFin->Date.FormatString("yyyymmdd").ToInt() < dtFechaIni->Date.FormatString("yyyymmdd").ToInt() ) {
       Application->MessageBox("La fecha Final es Menor que la Inicial !!", "Fechas", MB_OK | MB_ICONWARNING);
       return;
    }
    MostrarPolizas();
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::consultExecute(TObject *Sender)
{
  muestra_renpolco();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsPolCobMay::EliminaExecute(TObject *Sender)
{
   String cliente_z;
   int docto_z, letra_z;
   double importe_z;

  if (!qry_polizas->Active || qry_polizas->IsEmpty() ) {
      Application->MessageBox("No Existen Registros para Eliminar !!", "Eliminar", MB_OK | MB_ICONWARNING);
      return;
  }
  if(qry_polizas->FieldByName("status")->AsString != "C") {
    Application->MessageBox("No puede Eliminar Polizas cerradas", "Eliminar Póliza", MB_ICONEXCLAMATION);
    return;
  }
  if(Application->MessageBox("Esta Seguro de Eliminar esta Póliza ?", "Eliminar Póliza", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {

     for(qry_renpolco->First(); !qry_renpolco->Eof; qry_renpolco->First()) {

       docto_z   = qry_renpolco->FieldByName("docto")->AsInteger;
       importe_z = qry_renpolco->FieldByName("importe")->AsFloat;
       cliente_z = qry_renpolco->FieldByName("cliente")->AsString;
       letra_z   = qry_renpolco->FieldByName("letra")->AsInteger;

       ModificarFactura( importe_z,docto_z,letra_z, cliente_z);

       try {
           dm->manvehi->StartTransaction();
           qry_renpolco->Delete();
           qry_renpolco->ApplyUpdates();
           dm->manvehi->Commit();
       } catch (Exception &E){
           dm->manvehi->Rollback();
           Application->MessageBox(("No pude Eliminar el Renglon:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
       }
     }

     try {
         dm->manvehi->StartTransaction();
         qry_polizas->Delete();
         qry_polizas->ApplyUpdates();
         dm->manvehi->Commit();
     } catch (Exception &E){
         dm->manvehi->Rollback();
         Application->MessageBox(("No pude Eliminar el Renglon:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
     edt_conceppol->Text = "";
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::ImpExecute(TObject *Sender)
{
  if (!qry_polizas->Active || qry_polizas->IsEmpty() ) {
      Application->MessageBox("No Existen Polizas para ser impresas !!", "Imp.Pol.", MB_OK | MB_ICONQUESTION);
      return;
  }
  //ReporteCobranzaMayoristas(qry_polizas->FieldByName("Alm")->AsString, qry_polizas->FieldByName("Fecha")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsPolCobMay::cerrarExecute(TObject *Sender)
{
   if (!qry_polizas->Active || qry_polizas->IsEmpty() ) {
       Application->MessageBox("No Existe Registro para Cerrar !!", "Cierre", MB_OK | MB_ICONQUESTION);
       return;
   }
   if(qry_polizas->FieldByName("status")->AsString == "C") {
     Application->MessageBox("Esta Póliza ya ha sido cerrada", "Póliza cerrada", MB_ICONEXCLAMATION);
     return;
   }
   int iOk = Application->MessageBox("SEGURO DE CERRAR LA POLIZA DE COBRO?", "Cierre", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
   if (iOk != IDYES) return;
   bool bOk=false;
   try
   {
        dm->manvehi->StartTransaction();
        qsPolCob->Close();
        qsPolCob->ParamByName("status")->AsString   = "C";
        qsPolCob->ParamByName("Alm"   )->AsString   = qry_polizas->FieldByName("Alm"  )->AsString;
        qsPolCob->ParamByName("Fecha" )->AsDateTime = qry_polizas->FieldByName("Fecha")->AsDateTime;
        qsPolCob->ParamByName("folio" )->AsInteger  = qry_polizas->FieldByName("folio"  )->AsInteger;
        qsPolCob->ParamByName("Cia"   )->AsInteger  = qry_polizas->FieldByName("Cia"  )->AsInteger;
        qsPolCob->ExecSQL();
        dm->manvehi->Commit();
        qry_polizas->Edit();
        qry_polizas->FieldByName("status")->AsString = "C";
        qry_polizas->Post();
        bOk = true;
   }
   catch(...)
   {
        dm->manvehi->Rollback();
        Application->MessageBox("ERROR AL CAMBIAR EL ESTADO DE LA POLIZA !!", "Error", MB_OK | MB_ICONERROR);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsPolCobMay::nvapolExecute(TObject *Sender)
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
  Frame_datospolcobma->lkcmb_almacenExit(this);
  if(Dlg_datos->ShowModal() == mrOk) {
    alm_z = Frame_datospolcobma->qry_almacen->FieldByName("clave")->AsString;
    folio_z = Frame_datospolcobma->edt_folio->Value;
    fecha_z = Frame_datospolcobma->date_fecha->Date;
    concepto_z = Frame_datospolcobma->edt_concepto->Text;
    AgregarPoliza(alm_z, folio_z, fecha_z, concepto_z);
  }
  delete Frame_datospolcobma;
  delete Dlg_datos;
  //MostrarPolizas();
}
//---------------------------------------------------------------------------
bool __fastcall TForm_ConsPolCobMay::AgregarPoliza(String alm_z, int folio_z, TDateTime fecha_z, String concepto_z)
{
    bool bResult = false;
    int idconcep_z;

    idconcep_z = dm->busca_iddato(concepto_z, INVCONCEPTO);
    qry_polizas->Append();
    qry_polizas->FieldByName("Alm")->AsString = alm_z;
    qry_polizas->FieldByName("Fecha")->AsDateTime = fecha_z;
    qry_polizas->FieldByName("folio")->AsInteger = folio_z;
    qry_polizas->FieldByName("idconcep")->AsInteger = idconcep_z;
    qry_polizas->FieldByName("Importe")->AsFloat = 0;
    qry_polizas->FieldByName("sEstado")->AsString = "ABIERTO";
    qry_polizas->FieldByName("status")->AsString = "A";
    qry_polizas->FieldByName("Usuario")->AsString = dm->login_z;
    qry_polizas->FieldByName("Cia")->AsInteger = cia_z;
    qry_polizas->Post();
    try
    {
        dm->manvehi->StartTransaction();
        qry_polizas->ApplyUpdates();
        dm->manvehi->Commit();
        bResult = true;
    }
    catch(...)
    {
        dm->manvehi->Rollback();
        Application->MessageBox("NO FUE POSIBLE AGREGAR LA POLIZA DE COBRO !!", "Error", MB_OK | MB_ICONERROR);
    }

    return bResult;
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::agrega_renglonExecute(TObject *Sender)
{

  if (qry_polizas->IsEmpty() ) {
      Application->MessageBox("No Existen Polizas !!", "Consulta", MB_OK | MB_ICONWARNING);
      return;
  }
  if(qry_polizas->FieldByName("status")->AsString == "C") {
    Application->MessageBox("No puede Modificar Pólizas cerradas", "Agregar Movimiento", MB_ICONEXCLAMATION);
    return;
  }

  int alto_z=0, ancho_z=0, folio_z=0, idmov_z,letra_z;
  String alm_z, concepto_z, mayoris_z, refer_z,tip_z,tipago_z;
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
  Dlg_datos->Caption = "Agregar Renglon de Cobranza";
  Dlg_datos->Position = poScreenCenter;
  Frame_datosrenpolcobma->inicializa();
  if(Dlg_datos->ShowModal() == mrOk) {
     mayoris_z = Frame_datosrenpolcobma->qry_mayoris->FieldByName("codigo")->AsString;
     concepto_z = Frame_datosrenpolcobma->edt_concepto->Text.Trim();
     letra_z = Frame_datosrenpolcobma->edt_letra->Value;
     refer_z = Frame_datosrenpolcobma->edt_referencia->Text.Trim();
     importe_z = Frame_datosrenpolcobma->edt_importe->Value;
     idmov_z = Frame_datosrenpolcobma->qry_facturas->FieldByName("idmov")->AsInteger;
     tipago_z = Frame_datosrenpolcobma->cmb_tipopago->Text;

     if (tipago_z == "Efectivo"){
        tip_z = "E";
     }else if (tipago_z == "Bonificación"){
        tip_z = "B";
     }else if (tipago_z == "Devolución"){
        tip_z = "D";
     }

     agregar_pago(mayoris_z, concepto_z, refer_z, importe_z, idmov_z, tip_z,letra_z);
  }
  delete Frame_datosrenpolcobma;
  delete Dlg_datos;

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsPolCobMay::agregar_pago(
  String mayoris_z, String concepto_z, String refer_z, double importe_z,
  int idmovafecta_z, String tip_z, int letra_z
)
{
    TDateTime fecha_z, vence_z;
    String alm_z;
    int idmov_z = 0, folio_z=0, consemov_z, conseren_z=0,
    idconcep_z, idrenpolco_z, docto_z, pagare_z, idpoliza_z,
    tipofac_z,modif_z;
    bool bOk = false;
    double saldo_z;
    modif_z = 0;

    alm_z = qry_polizas->FieldByName("alm")->AsString;
    folio_z = qry_polizas->FieldByName("folio")->AsInteger;
    idconcep_z = qry_polizas->FieldByName("idconcep")->AsInteger;
    idpoliza_z = qry_polizas->FieldByName("idpolcob")->AsInteger;
    fecha_z = qry_polizas->FieldByName("fecha")->AsDateTime;


    qry_movmay->Close();
    qry_movmay->ParamByName("Fecha"  )->AsDateTime = Now();
    qry_movmay->ParamByName("Mayoris")->AsString   = "";
    qry_movmay->ParamByName("Docto"  )->AsInteger  = -1;
    qry_movmay->ParamByName("Concep" )->AsString   = "";
    qry_movmay->ParamByName("Importe")->AsFloat    = 0;
    qry_movmay->ParamByName("Cia"    )->AsInteger  = -1;
    qry_movmay->ParamByName("Pagare" )->AsInteger  = -1;
    qry_movmay->ParamByName("idmovmay" )->AsInteger  = idmovafecta_z;
    qry_movmay->Open();

    if(qry_movmay->IsEmpty()) {
      Application->MessageBox("No existe el movimiento al que debe abonar", "Error", MB_ICONEXCLAMATION);
      return;
    }
    saldo_z = qry_movmay->FieldByName("saldo")->AsFloat;
    docto_z = qry_movmay->FieldByName("docto")->AsInteger;
    pagare_z = qry_movmay->FieldByName("pagare")->AsInteger;
    tipofac_z = qry_movmay->FieldByName("tipofac")->AsInteger;
    vence_z = qry_movmay->FieldByName("vence")->AsDateTime;

    qry_numren->Close();
    qry_numren->ParamByName("Alm")->AsString   = alm_z;
    qry_numren->ParamByName("folio")->AsInteger = folio_z;
    qry_numren->ParamByName("Cia")->AsInteger  = cia_z;
    qry_numren->Open();
    conseren_z = qry_numren->FieldByName("IdNumRen")->AsInteger + 1;
    //qry_numren->Close();
    qsSigConseMov->Close();
    qsSigConseMov->ParamByName("Mayoris")->AsString   = mayoris_z;
    qsSigConseMov->ParamByName("Fecha")->AsDateTime = fecha_z;
    qsSigConseMov->ParamByName("Cia")->AsInteger  = cia_z;
    qsSigConseMov->Open();
    consemov_z = qsSigConseMov->FieldByName("IdMovto")->AsInteger + 1;
    //qsSigConseMov->Close();

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
    qry_renpolco->FieldByName("tipago")->AsString = tip_z;
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
        qiMovMay->ParamByName("Tipago" )->AsString  = tip_z;
        qiMovMay->ParamByName("idconcep")->AsInteger = idconcep_z;
        qiMovMay->ParamByName("fecsal"  )->AsDateTime = fecha_z;
        qiMovMay->ParamByName("idmov"   )->AsInteger = idmov_z;
        qiMovMay->ParamByName("tipofac" )->AsInteger = tipofac_z;
        qiMovMay->ExecSQL();
        //AFECTAR MOVIMIENTO QUE SE ESTA PAGANDO
        ModificarSaldoMov(importe_z, mayoris_z, docto_z, pagare_z, fecha_z );
        qry_renpolco->ApplyUpdates();
        dm->manvehi->Commit();
        bOk = true;
    }
    catch(...)
    {
        dm->manvehi->Rollback();
        Application->MessageBox("Error al intentar grabar el movimiento de pago !!", "Error", MB_OK | MB_ICONERROR);
        return;
    }
    if (bOk) {
    // Afectar Importe de Poliza
      ModificarImporte(importe_z,NUEVO);
      //DesplegarRenglon();
      //MostrarPolizas();
    }
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::ModificarSaldoMov(double fImporte, String sCveMay, int iDocto, int iPagare, TDateTime fecha_z)
{
  quMovPendPag->Close();
  quMovPendPag->ParamByName("Importe")->AsFloat    = fImporte;
  quMovPendPag->ParamByName("Mayoris")->AsString   = sCveMay;
  quMovPendPag->ParamByName("Docto"  )->AsInteger  = iDocto;
  quMovPendPag->ParamByName("Pagare" )->AsSmallInt = iPagare;
  quMovPendPag->ParamByName("Cia"    )->AsSmallInt = cia_z;
  quMovPendPag->ExecSQL();
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::DesplegarRenglon()
{
  String alm_z;
  int folio_z;
  alm_z = qry_polizas->FieldByName("alm")->AsString;
  folio_z = qry_polizas->FieldByName("folio")->AsInteger;
  qry_renpolco->Close();
  qry_renpolco->ParamByName("Alm")->AsString   = alm_z;
  qry_renpolco->ParamByName("folio")->AsInteger  = folio_z;
  qry_renpolco->ParamByName("Cia"  )->AsInteger  = cia_z;
  qry_renpolco->Open();
}
//---------------------------------------------------------------------------/---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::ModificarImporte( double importe_z, int modif_z)
{
    qry_polizas->Edit();
    switch (modif_z) {
      case NUEVO:  qry_polizas->FieldByName("importe")->AsFloat += importe_z;
           break;
      case MODIF: qry_polizas->FieldByName("importe")->AsFloat -= importe_z;
           break;
    }
    qry_polizas->Post();

    try {
        dm->manvehi->StartTransaction();
        qry_polizas->ApplyUpdates();
        dm->manvehi->Commit();
    }catch (Exception &E){
        dm->manvehi->Rollback();
        Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
}
//---------------------------------------------------------------------------/-
void __fastcall TForm_ConsPolCobMay::elimreglonExecute(TObject *Sender)
{

  int docto_z, letra_z;
  double importe_z;
  String cliente_z;
  if(qry_renpolco->IsEmpty()) return;
  if(qry_polizas->FieldByName("status")->AsString == "C") {
    Application->MessageBox("No puede Modificar Pólizas cerradas", "Eliminar Movimiento", MB_ICONEXCLAMATION);
    return;
  }
  cliente_z = qry_renpolco->FieldByName("cliente")->AsString;
  docto_z = qry_renpolco->FieldByName("docto")->AsInteger;
  letra_z = qry_renpolco->FieldByName("letra")->AsInteger;
  importe_z = qry_renpolco->FieldByName("importe")->AsFloat;
  if(Application->MessageBox("Esta Seguro de Eliminar este Renglon ?", "Eliminar Tabla", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
     try {
       dm->manvehi->StartTransaction();
       qry_renpolco->Delete();
       qry_renpolco->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E){
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude Eliminar el Renglon:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
     //Moficar Importe de Poliza
     ModificarImporte(importe_z, MODIF);

     //Modificar Importe de Factura
     ModificarFactura(importe_z,docto_z,letra_z, cliente_z);
  }

}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::ModificarFactura( double importe_z, int docto_z, int letra_z, String cliente_z)
{
    TLocateOptions Opts;
    Opts.Clear();
    qry_facturas->Close();
    qry_facturas->ParamByName("mayoris")->AsString  = cliente_z;
    qry_facturas->ParamByName("cia")->AsInteger  = cia_z;
    qry_facturas->ParamByName("docto"  )->AsInteger  = docto_z ;
    qry_facturas->Open();
    if(qry_facturas->Locate("pagare", letra_z, Opts)) {
      qry_facturas->Edit();
      qry_facturas->FieldByName("saldo")->AsFloat += importe_z;
      qry_facturas->Post();

      try {
          dm->manvehi->StartTransaction();
          qry_facturas->ApplyUpdates();
          dm->manvehi->Commit();
      }catch(Exception &E){
          dm->manvehi->Rollback();
          Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
      }
    }
}
//---------------------------------------------------------------------------/-

void __fastcall TForm_ConsPolCobMay::imprrenglonExecute(TObject *Sender)
{

  String concepto_z,cliente_z,pago_z,arch_z,nombre_z,usuario_z,concep_z;
  double importe_z,bonif_z=0 ,devol_z=0 ,efect_z=0 ,total_z=0 ;
  int docto_z,pagare_z,line_z,doc_z;
  TDateTime fechafact_z,vencimient_z,fec_z;
  pagina_z = 1;
  line_z= 0;
  if(qry_polizas->FieldByName("status")->AsString != "C") {
    Application->MessageBox("No puede imprimir Polizas abiertas", "Impresión Póliza", MB_ICONEXCLAMATION);
    return;
  }

  if(Application->MessageBox("Seguro De imprimir Este Reporte ?", "Impresión Reporte", MB_OKCANCEL) != IDOK ) return;
     arch_z = "frm_consupolcobmay.txt";
    if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
         Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
         return;
  }

  report_encab();

  for(qry_renpolco->First(); !qry_renpolco->Eof; qry_renpolco->Next()) {
     concepto_z = qry_renpolco->FieldByName("concep")->AsString;
     docto_z = qry_renpolco->FieldByName("docto")->AsInteger;
     pagare_z = qry_renpolco->FieldByName("letra")->AsInteger;
     importe_z = qry_renpolco->FieldByName("importe")->AsFloat;
     pago_z = qry_renpolco->FieldByName("tipago")->AsString;
     cliente_z = qry_renpolco->FieldByName("cliente")->AsString;
     nombre_z = qry_renpolco->FieldByName("nombre")->AsString;

     if(line_z == 0 ){
       doc_z = qry_polizas->FieldByName("folio")->AsInteger;
       fec_z = qry_polizas->FieldByName("fecha")->AsDateTime;
       usuario_z = qry_polizas->FieldByName("usuario")->AsString;
       concep_z =  qry_polizas->FieldByName("concep")->AsString;
       datosencab(doc_z ,fec_z,usuario_z,concep_z,cliente_z,nombre_z);
       encab1();
       line_z= 1;
     }

     qry_fechavenc->Close();
     qry_fechavenc->ParamByName("docto")->AsInteger  = docto_z;
     qry_fechavenc->ParamByName("coa")->AsString  = "C";
     qry_fechavenc->ParamByName("letra"  )->AsInteger  = pagare_z;
     qry_fechavenc->ParamByName("cliente"  )->AsString  = cliente_z ;
     qry_fechavenc->Open();
     fechafact_z = qry_fechavenc->FieldByName("fecha")->AsDateTime;
     vencimient_z = qry_fechavenc->FieldByName("vence")->AsDateTime;

     fprintf(archout, "|");
     fprintf(archout, "%s|", ljust(concepto_z, 30));
     fprintf(archout, "%s|", ljust(FormatDateTime("dd/mm/yyyy",fechafact_z), 10));
     fprintf(archout, "%s", rjust(docto_z, 6));
     fprintf(archout, "%s", ljust("/", 1));
     fprintf(archout, "%s|",  rjust(pagare_z, 2));
     fprintf(archout, "%s|", ljust( FormatDateTime("dd/mm/yyyy",vencimient_z), 10));
     fprintf(archout, "%s|", rjust(FormatFloat("#,###,##0.00", importe_z), 12));
     fprintf(archout, "%s|\n", ljust(pago_z, 1));

     if (pago_z == "B"){
       bonif_z += importe_z;
     }else if (pago_z == "D"){
       devol_z += importe_z;
     }else if (pago_z == "E"){
       efect_z += importe_z;
     }

     total_z = bonif_z + devol_z + efect_z;

     lineas_z += 1;
     checa_salto_pag(3);
  }
  totales(bonif_z ,devol_z ,efect_z ,total_z );
  fclose(archout);
  importe_z = bonif_z = devol_z = efect_z =total_z = 0;
  dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsPolCobMay::report_encab()
{
  String situini_z,situfin_z,tit1_z,tit2_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    "Frm_consupolcobmayo" + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );
  lineas_z = 2;
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::encab1()
{

   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Concepto",30 ));
   fprintf(archout, "%s|", cjust("Fecha Fact",10));
   fprintf(archout, "%s|", cjust("Docto./Lt",9 ));
   fprintf(archout, "%s|", cjust("Vencimiento",10));
   fprintf(archout, "%s|", cjust("Importe",12));
   fprintf(archout, "%s|", cjust("B",1));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;

}
//---------------------------------------------------------------------------

 bool __fastcall TForm_ConsPolCobMay::checa_salto_pag(int margen_z)
{
  bool haysalto_z = false;
  if(lineas_z > (MAX_LINEAS - margen_z)) {
    fprintf(archout, "%c", 12);
    pagina_z++;
    report_encab();
    encab1();
    haysalto_z = true;
  }
  return (haysalto_z);
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::datosencab( int doc_z , TDateTime fec_z, String usuario_z, String concep_z, String cliente_z, String nombre_z)
{

  String upol_z,ufec_z;
  upol_z = "Poliza de Cobranza:";
  ufec_z = "Fecha:";
  fprintf(archout, "%s", ljust(upol_z + doc_z + " AL " + ufec_z  + FormatDateTime("dd/mm/yyyy",
  fec_z),60));
  fprintf(archout,"\n");
  fprintf(archout, "%s", ljust( "Usuario:" + usuario_z + " " + "Concepto:" + concep_z,80));
  fprintf(archout,"\n");
  fprintf(archout, "%s", ljust( "Cliente:" + cliente_z + " " + nombre_z,70));
  fprintf(archout,"\n");

}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsPolCobMay::totales( double bonif_z ,double devol_z ,double efect_z ,double total_z )
{
  fprintf(archout,"\n");
  fprintf(archout, "%s", ljust(" Bonif: ",8));
  fprintf(archout, "%s", rjust(FormatFloat("#,###,##0.00", bonif_z), 10));
  fprintf(archout, "%s", ljust(" Devols: ",9));
  fprintf(archout, "%s", rjust(FormatFloat("#,###,##0.00", devol_z), 10));
  fprintf(archout, "%s", ljust(" Efectivo: ",11));
  fprintf(archout, "%s", rjust(FormatFloat("#,###,##0.00", efect_z), 10));
  fprintf(archout, "%s", ljust(" Total: ",8));
  fprintf(archout, "%s", rjust(FormatFloat("#,###,##0.00", total_z), 10));
  fprintf(archout,"\n");
}
//---------------------------------------------------------------------------



void __fastcall TForm_ConsPolCobMay::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrdRenpolco;
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
  SaveDialog->FileName = midbgrd_z->Name + ".xls";
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


void __fastcall TForm_ConsPolCobMay::dbgrdRenpolcoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) agrega_renglonExecute(Sender);
  if(Key == VK_DELETE) elimreglonExecute(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsPolCobMay::dbgrdRenpolcoCustomDraw(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxDBTreeListColumn *AColumn,
      const AnsiString AText, TFont *AFont, TColor &AColor, bool ASelected,
      bool AFocused, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------

