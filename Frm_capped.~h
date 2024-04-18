//---------------------------------------------------------------------------

#ifndef Frm_cappedH
#define Frm_cappedH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
void __fastcall ConsultaPedidos(TForm *Padre);
//---------------------------------------------------------------------------
class TfrmPedidos : public TForm
{
__published:	// IDE-managed Components
    TCoolBar *CoolBar1;
    TToolBar *ToolBar1;
    TToolButton *tbtnAgregar;
    TToolButton *tbtnGuardar;
    TToolButton *ToolButton8;
    TToolButton *ToolButton2;
    TToolButton *ToolButton1;
    TToolButton *ToolButton5;
    TToolButton *ToolButton3;
    TToolButton *ToolButton4;
    TToolButton *tbtnCerrar;
    TToolButton *tbtnAyuda;
    TActionList *ActionList1;
    TAction *actFiltro;
    TAction *actBuscar;
    TAction *actExpandir;
    TAction *actAgrupar;
    TAction *actImprimir;
    TAction *actExcel;
    TAction *actCerrar;
    TImageList *imsg;
    TToolButton *ToolButton7;
    TToolButton *ToolButton9;
    TToolButton *ToolButton10;
        TPanel *RzSplitter1;
    TdxDBGrid *dbgrdPedidos;
    TdxDBGrid *dbgrdRenent;
    TQuery *qsPedidos;
    TDataSource *dtsPedidos;
    TdxDBGridMaskColumn *dbgrdPedidosTIPO;
    TdxDBGridMaskColumn *dbgrdPedidosALM;
    TdxDBGridMaskColumn *dbgrdPedidosNUMERO;
    TdxDBGridMaskColumn *dbgrdPedidosPROVE;
    TdxDBGridMaskColumn *dbgrdPedidosSNOMPROVE;
    TdxDBGridMaskColumn *dbgrdPedidosPERENVREC;
    TdxDBGridMaskColumn *dbgrdPedidosSTATUS;
    TdxDBGridMaskColumn *dbgrdPedidosSSTATUS;
    TdxDBGridMaskColumn *dbgrdPedidosCONIVA;
    TdxDBGridDateColumn *dbgrdPedidosFECHA;
    TdxDBGridMaskColumn *dbgrdPedidosSNOMUSU;
    TdxDBGridCurrencyColumn *dbgrdPedidosIMPORTE;
    TdxDBGridCurrencyColumn *dbgrdPedidosIVA;
    TdxDBGridCurrencyColumn *dbgrdPedidosTOTAL;
    TAction *actNuevo;
    TAction *actModificar;
    TAction *actConsultar;
    TQuery *qsRenentra;
    TDataSource *dtsRenentra;
    TdxDBGridMaskColumn *dbgrdRenentTIPO;
    TdxDBGridMaskColumn *dbgrdRenentALM;
    TdxDBGridMaskColumn *dbgrdRenentRECEMI;
    TdxDBGridMaskColumn *dbgrdRenentNUMERO;
    TdxDBGridMaskColumn *dbgrdRenentCONSE;
    TdxDBGridMaskColumn *dbgrdRenentCODINV;
    TdxDBGridMaskColumn *dbgrdRenentSERIE;
    TdxDBGridMaskColumn *dbgrdRenentSIONO;
    TdxDBGridMaskColumn *dbgrdRenentFOLSAL;
    TdxDBGridMaskColumn *dbgrdRenentFOLENT;
    TdxDBGridMaskColumn *dbgrdRenentCANTMUEVE;
    TdxDBGridMaskColumn *dbgrdRenentSTATUS;
    TdxDBGridMaskColumn *dbgrdRenentPERSENVREC;
    TdxDBGridMaskColumn *dbgrdRenentCIA;
    TdxDBGridMaskColumn *dbgrdRenentVEND;
    TdxDBGridMaskColumn *dbgrdRenentPOBLAC;
    TdxDBGridMaskColumn *dbgrdRenentTIPAGO;
    TdxDBGridMaskColumn *dbgrdRenentPRVTA;
    TdxDBGridMaskColumn *dbgrdRenentENTOSAL;
    TdxDBGridMaskColumn *dbgrdRenentENTCAN;
    TdxDBGridCurrencyColumn *dbgrdRenentUNIDS;
    TdxDBGridCurrencyColumn *dbgrdRenentCOSTOU;
    TdxDBGridCurrencyColumn *dbgrdRenentPIVA;
    TdxDBGridCurrencyColumn *dbgrdRenentIMPORTE;
    TdxDBGridColumn *dbgrdRenentDESCRI;
        TStatusBar *RzStatusBar1;
    TQuery *qsCondiPed;
    TDataSource *dtsCondiPed;
    TdxDBGridColumn *dbgrdPedidosSCONTACTO;
    TAction *actObserv;
    TPopupMenu *PopupMenu1;
    TMenuItem *VerObservaciones1;
    TMenuItem *EnviaraExcel1;
    TMenuItem *FiltrarPedidos1;
    TMenuItem *ExpandirNodos1;
    TMenuItem *AgruparNodos1;
    TMenuItem *Buscar1;
    TMenuItem *ImprimirPedido1;
    TMenuItem *CerrarPedido1;
    TQuery *quCerrarPed;
    TToolButton *ToolButton6;
    TAction *actEliminar;
    TQuery *qdPedido;
    TMenuItem *N1;
    TMenuItem *N2;
    TToolButton *ToolButton11;
    TAction *actCerrarPed;
    void __fastcall actCerrarExecute(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall dbgrdPedidosKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall dbgrdPedidosDblClick(TObject *Sender);
    void __fastcall actExpandirExecute(TObject *Sender);
    void __fastcall actAgruparExecute(TObject *Sender);
    void __fastcall actExcelExecute(TObject *Sender);
    void __fastcall actBuscarExecute(TObject *Sender);
    void __fastcall actFiltroExecute(TObject *Sender);
    void __fastcall actNuevoExecute(TObject *Sender);
    void __fastcall actModificarExecute(TObject *Sender);
    void __fastcall actConsultarExecute(TObject *Sender);
    void __fastcall mdadPedidosAfterScroll(TDataSet *DataSet);
    void __fastcall dbgrdPedidosClick(TObject *Sender);
    void __fastcall actObservExecute(TObject *Sender);
    void __fastcall actImprimirExecute(TObject *Sender);
    void __fastcall actEliminarExecute(TObject *Sender);
    void __fastcall actCerrarPedExecute(TObject *Sender);
private:	// User declarations
    void __fastcall MuestraRenglones();
    bool __fastcall ChecaUsuario();
    void __fastcall Refresh(int iNumero, AnsiString sAlm, AnsiString sTipo, int iCia);
    void __fastcall RefreshQuery();
public:		// User declarations
    AnsiString sIniciales;
    __fastcall TfrmPedidos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmPedidos *frmPedidos;
//---------------------------------------------------------------------------
#endif
