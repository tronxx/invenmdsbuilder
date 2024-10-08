//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_capped.h"
#include "dlgFiltroCnsPed.h"
#include "Frm_cappedmanto.h"
#include "Login.h"
#include "RepCapPed.h"
#include "Frm_CapturaObsPed.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
//#pragma link "dxmdaset"
#pragma resource "*.dfm"

#define MENSA Application->MessageBox
TfrmPedidos *frmPedidos;
//---------------------------------------------------------------------------
void __fastcall ConsultaPedidos(TForm *Padre)
{
    try
    {
        frmPedidos = new TfrmPedidos(Padre);
        frmPedidos->Show();
    }
    catch(...)
    {  }

}
//---------------------------------------------------------------------------
__fastcall TfrmPedidos::TfrmPedidos(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TfrmPedidos::actCerrarExecute(TObject *Sender)
{
    Close();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    Action = caFree;
    frmPedidos = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::FormShow(TObject *Sender)
{
    int iMes = TDateTime::CurrentDate().FormatString("mm").ToInt();
    int iAnio = TDateTime::CurrentDate().FormatString("yyyy").ToInt();

    qsPedidos->Close();
    qsPedidos->ParamByName("FechaIni")->AsDateTime = TDateTime(iAnio, iMes, 01);
    qsPedidos->ParamByName("Fechafin")->AsDateTime = TDateTime::CurrentDate();
    qsPedidos->Open();

    //mdadPedidos->Active = false;
    //mdadPedidos->CreateFieldsFromDataSet(qsPedidos);
    //mdadPedidos->LoadFromDataSet(qsPedidos);
    //qsPedidos->Close();

    MuestraRenglones();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPedidos::MuestraRenglones()
{
    qsRenentra->Close();
    qsRenentra->ParamByName("Numero")->AsInteger = qsPedidos->FieldByName("Numero")->AsInteger;
    qsRenentra->ParamByName("Tipo"  )->AsString  = qsPedidos->FieldByName("Tipo"  )->AsString;
    qsRenentra->ParamByName("Almac" )->AsString  = qsPedidos->FieldByName("Alm"   )->AsString;
    qsRenentra->Open();
}
//---------------------------------------------------------------------------
void __fastcall TfrmPedidos::dbgrdPedidosKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{

   // if (Shift == TShiftState() ) {
   //    if (Key == VK_SPACE || Key == VK_DOWN || Key == VK_UP) {
   //        MuestraRenglones();
   //    }
   // }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::dbgrdPedidosDblClick(TObject *Sender)
{
//    MuestraRenglones();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actExpandirExecute(TObject *Sender)
{
    dbgrdPedidos->FullExpand();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actAgruparExecute(TObject *Sender)
{
    dbgrdPedidos->FullCollapse();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actExcelExecute(TObject *Sender)
{
    if (dbgrdPedidos->DataSource->DataSet->IsEmpty() ) return;
        dbgrdPedidos->SaveToXLS("Pedidos.xls", true);
        ShellExecute(0, "open", "Pedidos.xls", NULL, NULL, SW_SHOWNORMAL);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actBuscarExecute(TObject *Sender)
{
   AnsiString InputString = InputBox("Buscar", "Teclee No. Pedido:", "");
   if (InputString != "") {
      TLocateOptions Opts;    Opts.Clear();
      Opts << loPartialKey;
      qsPedidos->First();
      qsPedidos->Locate("Numero", InputString, Opts);
   }
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actFiltroExecute(TObject *Sender)
{
    AnsiString sql = "";
    sql = FiltroPedidos(this);
    if (sql != "") {
       qsPedidos->Close();
       qsPedidos->SQL->Clear();
       qsPedidos->SQL->Add(sql);
       qsPedidos->Open();

       //qsPedidos->Active = false;
       //qsPedidos->CreateFieldsFromDataSet(qsPedidos);
       //qsPedidos->LoadFromDataSet(qsPedidos);
       //qsPedidos->Close();
       MuestraRenglones();
    }
}
//---------------------------------------------------------------------------



void __fastcall TfrmPedidos::actNuevoExecute(TObject *Sender)
{
    if (!ChecaUsuario() ) {
       Application->MessageBox("NO TIENE ACCESO A ESTA OPCION", "Aviso", MB_OK | MB_ICONQUESTION);
       return;
    }
    MantoCapturaPedido(this, qsPedidos->FieldByName("Numero")->AsInteger,
     qsPedidos->FieldByName("Tipo")->AsString, qsPedidos->FieldByName("Alm")->AsString, 1, sIniciales);
}
//---------------------------------------------------------------------------
bool __fastcall TfrmPedidos::ChecaUsuario()
{
    bool bResult = false;
    sIniciales="";
    if (RegistroClave(this, sIniciales) ) bResult = true;
    return bResult;
}

//---------------------------------------------------------------------------
void __fastcall TfrmPedidos::actModificarExecute(TObject *Sender)
{
   if (!ChecaUsuario() ) {
       Application->MessageBox("NO TIENE ACCESO A ESTA OPCION", "Aviso", MB_OK | MB_ICONQUESTION);
       return;
   }
   MantoCapturaPedido(this, qsPedidos->FieldByName("Numero")->AsInteger,
     qsPedidos->FieldByName("Tipo")->AsString, qsPedidos->FieldByName("Alm")->AsString, 2, sIniciales);
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actConsultarExecute(TObject *Sender)
{
   MantoCapturaPedido(this, qsPedidos->FieldByName("Numero")->AsInteger,
     qsPedidos->FieldByName("Tipo")->AsString, qsPedidos->FieldByName("Alm")->AsString, 3, "");
}
//---------------------------------------------------------------------------




void __fastcall TfrmPedidos::mdadPedidosAfterScroll(TDataSet *DataSet)
{
    qsCondiPed->Close();
    qsCondiPed->ParamByName("Numero")->AsInteger = qsPedidos->FieldByName("Numero")->AsInteger;
    qsCondiPed->ParamByName("Almac" )->AsString  = qsPedidos->FieldByName("Alm"   )->AsString;
    qsCondiPed->ParamByName("Tipo"  )->AsString  = qsPedidos->FieldByName("Tipo"  )->AsString;
    qsCondiPed->ParamByName("Cia"   )->AsInteger = qsPedidos->FieldByName("Cia"   )->AsInteger;
    qsCondiPed->Open();
    MuestraRenglones();
}
//---------------------------------------------------------------------------


void __fastcall TfrmPedidos::dbgrdPedidosClick(TObject *Sender)
{
    MuestraRenglones();
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actObservExecute(TObject *Sender)
{
    if (!qsPedidos->Active || qsPedidos->IsEmpty() ) {
       Application->MessageBox("NO EXISTE PEDIDO ACCESADO PARA PODER AGREGAR OBSERVACIONES !!", "Pedido", MB_OK | MB_ICONQUESTION);
       return;
    }
    CapturaObservaPedido(this, qsPedidos->FieldByName("Tipo")->AsString,
                               qsPedidos->FieldByName("Alm" )->AsString,
                               qsPedidos->FieldByName("numero")->AsInteger,
                               qsPedidos->FieldByName("cia")->AsInteger,
                               "", "T");
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::actImprimirExecute(TObject *Sender)
{
  int npedido_z;
  String alm_z, tipo_z;
  int cia_z;
    tipo_z = qsPedidos->FieldByName("Tipo")->AsString;
    alm_z = qsPedidos->FieldByName("Alm" )->AsString;
    npedido_z = qsPedidos->FieldByName("numero")->AsInteger;
    cia_z = qsPedidos->FieldByName("cia")->AsInteger;
    if (!qsPedidos->Active || qsPedidos->IsEmpty() ) return;
    if(!qrImpCapped) TqrImpCapped *qrImpCapped = new TqrImpCapped (this);
    qrImpCapped->qsPedido->Close();
    qrImpCapped->qsPedido->ParamByName("Numero")->AsInteger = npedido_z;
    qrImpCapped->qsPedido->ParamByName("Almac" )->AsString  = alm_z;
    qrImpCapped->qsPedido->ParamByName("Tipo"  )->AsString  = tipo_z;
    qrImpCapped->qsPedido->ParamByName("Cia"   )->AsInteger = cia_z;
    qrImpCapped->qsPedido->Open();
    if (! qrImpCapped->qsPedido->IsEmpty() ) {

       qrImpCapped->qsCias->Close();
       qrImpCapped->qsCias->ParamByName("cia")->AsInteger = cia_z;
       qrImpCapped->qsCias->Open();

       qrImpCapped->qrlblCia->Caption   = qrImpCapped->qsCias->FieldByName("NomFis")->AsString;
       qrImpCapped->qrlblDirec->Caption = qrImpCapped->qsCias->FieldByName("Dir"   )->AsString;

       qrImpCapped->qsRenentra->Close();
       qrImpCapped->qsRenentra->ParamByName("Numero")->AsInteger = npedido_z;
       qrImpCapped->qsRenentra->ParamByName("Almac" )->AsString  = alm_z;
       qrImpCapped->qsRenentra->ParamByName("Tipo"  )->AsString  = tipo_z;
       qrImpCapped->qsRenentra->ParamByName("Cia"   )->AsInteger = cia_z;
       qrImpCapped->qsRenentra->Open();

       qrImpCapped->Preview();
    }
    delete qrImpCapped;
    qrImpCapped = NULL;
}
//---------------------------------------------------------------------------

void __fastcall TfrmPedidos::Refresh(int iNumero, AnsiString sAlm, AnsiString sTipo, int iCia)
{
    TLocateOptions Opts;
    Opts.Clear();
    Opts << loPartialKey;
   // mdadPedidos->First();
   //mdadPedidos->Close();
   //mdadPedidos->Open();
    Variant locvalues[3];
    locvalues[0] = Variant(iNumero);
    locvalues[1] = Variant(sAlm);
    locvalues[2] = Variant(sTipo);
   // locvalues[3] = Variant("Cia");
    qsPedidos->Locate("Numero;Alm;Tipo", VarArrayOf(locvalues, 2), Opts);
}
//---------------------------------------------------------------------------
void __fastcall TfrmPedidos::actEliminarExecute(TObject *Sender)
{
    if (!ChecaUsuario() ) {
       Application->MessageBox("NO TIENE ACCESO A ESTA OPCION", "Aviso", MB_OK | MB_ICONQUESTION);
       return;
    }
    if (!qsPedidos->Active || qsPedidos->IsEmpty() ) return;
    if (qsPedidos->FieldByName("Status")->AsString != "A") {
        Application->MessageBox("EL PEDIDO NO ESTA ABIERTO !!", "Estado", MB_OK | MB_ICONWARNING);
        return;
    }
    int iDel = Application->MessageBox("�SEGURO DE ELIMINAR EL PEDIDO SELECCIONADO?", "Confirmar", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
    if (iDel != 6) return;
    bool bDel = false;
    try
    {
        dm->manvehi->StartTransaction();
        qdPedido->Close();
        qdPedido->ParamByName("Numero")->AsInteger = qsPedidos->FieldByName("Numero")->AsInteger;
        qdPedido->ParamByName("Almac" )->AsString  = qsPedidos->FieldByName("Alm"   )->AsString;
        qdPedido->ParamByName("Tipo"  )->AsString  = qsPedidos->FieldByName("Tipo"  )->AsString;
        qdPedido->ParamByName("Cia"   )->AsInteger = qsPedidos->FieldByName("Cia"   )->AsInteger;
        qdPedido->ExecSQL();
        dm->manvehi->Commit();
        bDel = true;
    }
    catch(...)
    {
        dm->manvehi->Rollback();
        MENSA("Error al Tratar de Eliminar El Registro !!", "Error", MB_OK | MB_ICONERROR);
    }
    if (bDel) {
        ShowMessage("REGISTRO ELIMINADO !!");
        RefreshQuery();
    }


}
//---------------------------------------------------------------------------
void __fastcall TfrmPedidos::RefreshQuery()
{
    qsPedidos->Close();
    qsPedidos->Open();

    //qsPedidos->Active = false;
    //qsPedidos->CreateFieldsFromDataSet(qsPedidos);
    //qsPedidos->LoadFromDataSet(qsPedidos);
    //qsPedidos->Close();

}
//---------------------------------------------------------------------------
void __fastcall TfrmPedidos::actCerrarPedExecute(TObject *Sender)
{
    if (!qsPedidos->Active || qsPedidos->IsEmpty() ) {
        MENSA("NO EXISTE REGISTRO PARA CERRAR !!", "Vacio", MB_OK | MB_ICONWARNING);
        return;
    }
    if (qsPedidos->FieldByName("status")->AsString != "A") {
        MENSA("IMPOSIBLE CERRAR PEDIDO EN ESTE ESTADO !!", "?", MB_OK | MB_ICONWARNING);
        return;
    }
    bool bCerrar=false;
    int iOk = MENSA("�DESEA CERRAR EL PEDIDO?", "Cerrar", MB_YESNO | MB_ICONQUESTION | MB_DEFBUTTON2);
    if (iOk != 6) return;
    try
    {
      dm->manvehi->StartTransaction();
      quCerrarPed->Close();
      quCerrarPed->ParamByName("Numero")->AsInteger = qsPedidos->FieldByName("Numero")->AsInteger;
      quCerrarPed->ParamByName("Almac" )->AsString  = qsPedidos->FieldByName("Alm"   )->AsString;
      quCerrarPed->ParamByName("Tipo"  )->AsString  = qsPedidos->FieldByName("Tipo"  )->AsString;
      quCerrarPed->ParamByName("Cia"   )->AsInteger = qsPedidos->FieldByName("Cia"   )->AsInteger;
      quCerrarPed->ExecSQL();

      qsPedidos->Edit();
      qsPedidos->FieldByName("status")->AsString = "C";
      qsPedidos->FieldByName("sStatus")->AsString = "CERRADO";
      qsPedidos->Post();

      dm->manvehi->Commit();
      bCerrar = true;
    }
    catch(...)
    {
      dm->manvehi->Rollback();
      MENSA("ERROR AL INTENTAR CERRAR EL PEDIDO !!", "Error", MB_OK | MB_ICONERROR);
    }
    if (bCerrar) {
        ShowMessage("PEDIDO CERRARDO !!");
        Refresh(qsPedidos->FieldByName("Numero")->AsInteger,
                qsPedidos->FieldByName("Alm"   )->AsString,
                qsPedidos->FieldByName("Tipo"  )->AsString,
                qsPedidos->FieldByName("Cia"   )->AsInteger);
    }
}
//---------------------------------------------------------------------------

