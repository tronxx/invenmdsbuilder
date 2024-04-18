//---------------------------------------------------------------------------

#ifndef Frm_cappolcobmayH
#define Frm_cappolcobmayH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ActnList.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <DBCtrls.hpp>
#include "dxDBELib.hpp"
#include <StdActns.hpp>
#include "Frme_datospolcobma.h"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
void __fastcall MantenimientoPolizasMayorista(TForm *Padre, int iModo_, TDateTime dtFecha_, AnsiString sAlmac_);
//---------------------------------------------------------------------------
class TForm_CapPolCobMay : public TForm
{
__published:	// IDE-managed Components
    TQuery *qsAlmacen;
    TdxDBGrid *dbgrdRenglones;
    TActionList *ActionList1;
    TAction *actFiltro;
    TAction *actNuevo;
    TAction *actListar;
    TAction *actConsultar;
    TAction *actBuscar;
    TAction *actExpandir;
    TAction *actAgrupar;
    TAction *actImprimir;
    TAction *actExcel;
    TAction *actCerrar;
    TAction *actObserv;
    TAction *actEliminar;
    TAction *actCerrarPol;
    TImageList *imsg;
    TQuery *qsMayorista;
        TQuery *qry_poliza;
        TQuery *qry_renpolco;
    TDataSource *dtsRenpolcob;
    TdxDBGridMaskColumn *dbgrdRenglonesALM;
    TdxDBGridDateColumn *dbgrdRenglonesFECHA;
    TdxDBGridMaskColumn *dbgrdRenglonesNUMREN;
    TdxDBGridMaskColumn *dbgrdRenglonesDOCTO;
    TdxDBGridMaskColumn *dbgrdRenglonesREFER;
    TdxDBGridMaskColumn *dbgrdRenglonesCONCEP;
    TdxDBGridMaskColumn *dbgrdRenglonesCLIENTE;
    TdxDBGridMaskColumn *dbgrdRenglonesLETRA;
    TdxDBGridMaskColumn *dbgrdRenglonesCIA;
    TdxDBGridMaskColumn *dbgrdRenglonesTIPAGO;
    TdxDBGridMaskColumn *dbgrdRenglonesNOMBRE;
    TdxDBGridCurrencyColumn *dbgrdRenglonesIMPORTE;
    TQuery *qdRenglon;
    TQuery *quPolCob;
        TQuery *qry_movmay;
    TQuery *qdMovMay2;
    TQuery *qsPendPag;
    TQuery *qiMovMay;
        TQuery *qry_numren;
    TQuery *qsSigConseMov;
    TQuery *qiRenPolCob;
    TQuery *quMovPendPag;
    TQuery *qiPolCob;
    TQuery *qsCountRenPol;
    TQuery *quPolCobStat;
        TDataSource *dts_almacen;
        TToolBar *ToolBar2;
        TToolButton *tbtn_nuevo;
        TToolButton *tbtn_modif;
        TToolButton *tbtn_borra;
        TToolButton *ToolButton7;
        TToolButton *ToolButton4;
        TToolButton *ToolButton10;
        TToolButton *ToolButton11;
        TToolButton *ToolButton12;
        TToolButton *ToolButton13;
        TToolButton *ToolButton14;
        TToolButton *ToolButton15;
        TToolButton *ToolButton16;
        TToolButton *ToolButton17;
        TToolButton *ToolButton18;
        TImageList *ImageList1;
        TActionList *ActionList2;
        TAction *nuevo;
        TAction *modifica;
        TAction *borra;
        TAction *grabar;
        TAction *cancelar;
        TWindowClose *WindowClose1;
        TAction *primero;
        TAction *anterior;
        TAction *siguiente;
        TAction *ultimo;
        TAction *exporta_dbgrd;
        TAction *selec_orden;
        TAction *agregar_renglon;
        TAction *cancela_renglon;
        TAction *CierraRen;
        TAction *imprime;
        TAction *capobs;
        TAction *deshacer_afectacion;
        TDataSource *dts_poliza;
        TUpdateSQL *uqry_polizas;
        TGroupBox *GroupBox1;
        TFrame_datospolcobma *Frame_datospolcobma1;
        TGroupBox *GroupBox2;
        TBitBtn *BitBtn1;
        TUpdateSQL *uqry_renpolco;
    void __fastcall btnBorrarClick(TObject *Sender);
    void __fastcall dtpFechaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall actExpandirExecute(TObject *Sender);
    void __fastcall actAgruparExecute(TObject *Sender);
    void __fastcall actEliminarExecute(TObject *Sender);
    void __fastcall actListarExecute(TObject *Sender);
    void __fastcall actImprimirExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall agregar_renglonExecute(TObject *Sender);
private:	// User declarations
    bool __fastcall BuscarAlmacen(String sClave_);
    bool __fastcall BuscarMayorista(AnsiString sMayorista_);
    void __fastcall LimpiarRenglon();
    void __fastcall DesplegarRenglon();
    void __fastcall TotalPoliza(float fTotal);
public:		// User declarations
    bool __fastcall AgregarPoliza(String alm_z, int folio_z, TDateTime fecha_z, String concepto_z);
    bool __fastcall BuscarPoliza(String alm_z, int folio_z);
    void __fastcall ModificarSaldoMov(double fImporte, String sCveMay, int iDocto, int iPagare, TDateTime fecha_z);
    void __fastcall agregar_pago(String mayoris_z, String concepto_z,
                    String refer_z, double importe_z, int idmovafecta_z, String tipago_z);
    int iMODO, cia_z;
    TDateTime dtFechaPol;
    AnsiString sAlmac;
    __fastcall TForm_CapPolCobMay(TComponent* Owner, int iMODOp, TDateTime dtFechap, AnsiString sAlmacp);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_CapPolCobMay *Form_CapPolCobMay;
//---------------------------------------------------------------------------
#endif
