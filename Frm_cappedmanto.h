//---------------------------------------------------------------------------

#ifndef Frm_cappedmantoH
#define Frm_cappedmantoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
int __fastcall MantoCapturaPedido(TForm *Padre, int iNumero, String &sTipo, String &sAlmac, int iMODO_, AnsiString sIniciales_);
//---------------------------------------------------------------------------
class TfrmDlgCapPed : public TForm
{
__published:	// IDE-managed Components
    TPanel *pnlPedido;
    TLabel *RzLabel1;
    TLabel *RzLabel2;
    TLabel *RzLabel3;
    TLabel *RzLabel4;
    TLabel *RzLabel5;
    TLabel *RzLabel6;
    TdxCurrencyEdit *edtImporte;
    TdxCurrencyEdit *edtIva;
    TdxCurrencyEdit *edtTotal;
    TEdit *edtPeriodo;
    TEdit *edtNumero;
    TDateTimePicker *dtFecha;
    TLabel *RzLabel7;
    TEdit *edtProve;
    TEdit *edtNomPro;
    TLabel *RzLabel8;
    TEdit *edtContacto;
    TLabel *RzLabel9;
    TEdit *edtPlazo;
    TQuery *qsAnios;
    TQuery *qsMaxPed;
    TQuery *qsPedido;
    TQuery *qsProve;
    TGroupBox *grpRenglon;
    TdxDBGrid *dbgrdReng;
    TLabel *RzLabel10;
    TLabel *RzLabel11;
    TLabel *RzLabel12;
    TLabel *RzLabel13;
    TLabel *RzLabel14;
    TLabel *RzLabel15;
    TEdit *lblEstado;
    TdxCurrencyEdit *edtCantidad;
    TEdit *edtCodigo;
    TEdit *edtDescri;
    TdxCurrencyEdit *edtCosto;
    TdxCurrencyEdit *edtTotRen;
    TBitBtn *btnNuevo;
    TBitBtn *btnAgregar;
    TBitBtn *btnObserva;
    TBitBtn *btnGuardar;
    TBitBtn *btnCerrar;
    TQuery *qsRenentra;
    TDataSource *dtsRenEntra;
    TdxDBGridMaskColumn *dbgrdRengTIPO;
    TdxDBGridMaskColumn *dbgrdRengALM;
    TdxDBGridMaskColumn *dbgrdRengRECEMI;
    TdxDBGridMaskColumn *dbgrdRengNUMERO;
    TdxDBGridMaskColumn *dbgrdRengCONSE;
    TdxDBGridMaskColumn *dbgrdRengCODINV;
    TdxDBGridMaskColumn *dbgrdRengSERIE;
    TdxDBGridMaskColumn *dbgrdRengSIONO;
    TdxDBGridMaskColumn *dbgrdRengFOLSAL;
    TdxDBGridMaskColumn *dbgrdRengFOLENT;
    TdxDBGridMaskColumn *dbgrdRengCANTMUEVE;
    TdxDBGridMaskColumn *dbgrdRengSTATUS;
    TdxDBGridMaskColumn *dbgrdRengPERSENVREC;
    TdxDBGridMaskColumn *dbgrdRengCIA;
    TdxDBGridMaskColumn *dbgrdRengVEND;
    TdxDBGridMaskColumn *dbgrdRengPOBLAC;
    TdxDBGridMaskColumn *dbgrdRengTIPAGO;
    TdxDBGridMaskColumn *dbgrdRengPRVTA;
    TdxDBGridMaskColumn *dbgrdRengENTOSAL;
    TdxDBGridMaskColumn *dbgrdRengENTCAN;
    TdxDBGridCurrencyColumn *dbgrdRengUNIDS;
    TdxDBGridCurrencyColumn *dbgrdRengCOSTOU;
    TdxDBGridCurrencyColumn *dbgrdRengPIVA;
    TdxDBGridCurrencyColumn *dbgrdRengIMPORTE;
    TQuery *qsCodInv;
    TdxDBGridColumn *dbgrdRengDESCRI;
    TLabel *RzLabel16;
    TLabel *RzLabel17;
    TdxCurrencyEdit *edtPrecLista;
    TLabel *RzLabel18;
    TdxCurrencyEdit *edtMub;
    TUpdateSQL *upsqlRenEntra;
    TQuery *qsMaxReng;
    TdxDBGrid *dxDBGrid1;
    TQuery *qsExistencias;
    TDataSource *dtsExistencias;
    TdxDBGridMaskColumn *dxDBGrid1ALM;
    TdxDBGridMaskColumn *dxDBGrid1EXISTENCIA;
    TLabel *RzLabel19;
    TdxCurrencyEdit *edtPorcIva;
    TQuery *qiPedido;
    TQuery *qsConcepto;
    TQuery *qsMaxConcep;
    TQuery *qiConceps;
    TdxCurrencyEdit *edtIvaRen;
    TLabel *RzLabel20;
    TQuery *quPedido;
    TComboBox *cmbPedido;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall btnGuardarClick(TObject *Sender);
    void __fastcall edtProveKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtProveExit(TObject *Sender);
    void __fastcall edtProveAltBtnClick(TObject *Sender);
    void __fastcall edtCodigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtCodigoAltBtnClick(TObject *Sender);
    void __fastcall edtCantidadChange(TObject *Sender);
    void __fastcall btnNuevoClick(TObject *Sender);
    void __fastcall btnAgregarClick(TObject *Sender);
    void __fastcall edtContactoExit(TObject *Sender);
    void __fastcall edtCodigoChange(TObject *Sender);
    void __fastcall edtCostoChange(TObject *Sender);
    void __fastcall edtNumeroKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtContactoAltBtnClick(TObject *Sender);
    void __fastcall btnObservaClick(TObject *Sender);
    void __fastcall edtDescriExit(TObject *Sender);
    void __fastcall qsRenentraAfterOpen(TDataSet *DataSet);
private:	// User declarations
    void __fastcall BuscarPedido();
    void __fastcall LimpiarPantalla();
    void __fastcall LimpiarEncabezado();
    void __fastcall LimpiarRenglones();
    void __fastcall ActivarControles(bool bb);
    void __fastcall DesplegarDatos(TQuery  *qsPed);
    bool __fastcall BuscarProveedor(String sClave);
    bool __fastcall BuscarCodigo(String sCodigo);
    void __fastcall DesplegarRenglones();
    void __fastcall MostrarExistencias(AnsiString sCodigo);
    void __fastcall CalcularTotalReng();
    void __fastcall BuscarConcepto(AnsiString sConceptop);
    void __fastcall SumaRenglones();
public:		// User declarations
    int iNumero, iMODO, iConcepto, iConcepEnt;
    bool bOk, bCambio;
    AnsiString sTipo, sAlmac, sIniciales;

    __fastcall TfrmDlgCapPed(TComponent* Owner, int iNumerop, String &sTipop, String &sAlmacp, int iMODOp, AnsiString sInicialesp);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgCapPed *frmDlgCapPed;
//---------------------------------------------------------------------------
#endif
