//---------------------------------------------------------------------------

#ifndef Frm_capsalmayH
#define Frm_capsalmayH

//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Db.hpp>
#include <DBTables.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <DBCtrls.hpp>
#include <ToolWin.hpp>
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
#include "dxDBELib.hpp"
#include <stdio.h>
#include <Menus.hpp>
#include "Frme_datossabanavta.h"
#include "Frme_datossabanaagre.h"
#include "Frme_datoscaptrasp.h"
#include "Frme_datoscapsmay.h"
#include "Frme_datosrensmay.h"
//---------------------------------------------------------------------------
class TForm_capsalmay : public TForm
{
__published:	// IDE-managed Components
    TdxDBGrid *dbgrdReng;
        TQuery *qry_almacen;
    TQuery *qiConseInv;
    TQuery *qsEntradas;
        TQuery *qry_renentra;
        TDataSource *dts_renentra;
    TdxDBGridMaskColumn *dbgrdRengCODINV;
    TdxDBGridMaskColumn *dbgrdRengSERIE;
    TdxDBGridMaskColumn *dbgrdRengSIONO;
    TdxDBGridMaskColumn *dbgrdRengFOLSAL;
    TdxDBGridMaskColumn *dbgrdRengFOLENT;
    TdxDBGridMaskColumn *dbgrdRengUNIDS;
    TdxDBGridMaskColumn *dbgrdRengPIVA;
    TdxDBGridMaskColumn *dbgrdRengIMPORTE;
    TdxDBGridMaskColumn *dbgrdRengSTATUS;
    TdxDBGridColumn *dbgrdRengDESCRI;
    TdxDBGridCurrencyColumn *dbgrdRengCOSTOU;
        TQuery *qry_vendedor;
    TQuery *qsPoblacion;
    TQuery *qsPuntoVta;
    TQuery *qsConceps;
        TActionList *ActionList1;
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
        TDataSource *dts_almacen;
        TDataSource *dts_puntovta;
        TDataSource *dts_vendedor;
        TDataSource *dts_poblacion;
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TUpdateSQL *uqsEntradas;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TAction *agreren;
        TAction *acepta_ren;
        TQuery *qry_folsale;
        TUpdateSQL *uqry_renentra;
        TDataSource *dts_entradas;
        TAction *cancela_renglon;
    TAction *CierraRen;
    TAction *imprime;
        TAction *capobs;
        TAction *deshacer_afectacion;
        TAction *cambia_pto_vta;
        TGroupBox *GroupBox2;
        TPopupMenu *PopupMenu1;
        TMenuItem *CancelaRenglon1;
        TMenuItem *CierraRenglon1;
        TMenuItem *DeshacerAfectacinRengln1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TGroupBox *GroupBox1;
        TSpeedButton *SpeedButton2;
        TAction *cierra_entrada;
        TFrame_datoscapsmay *Frame_datoscapsmay1;
        TFrame_datosrensmay *Frame_datosrensmay1;
        TPanel *Panel1;
        TBitBtn *btn_nvoren;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TMenuItem *Entradas1;
        TMenuItem *Renglones1;
        TMenuItem *AgregaReng1;
        TMenuItem *Nuevo1;
        TMenuItem *Borra1;
        TMenuItem *Modifica1;
        TMenuItem *Cerrar1;
        TMenuItem *Observs1;
        TMenuItem *imprime1;
        TMenuItem *Primero1;
        TMenuItem *Anterior1;
        TMenuItem *Siguiente1;
        TMenuItem *Ultimo1;
        TAction *despliega_menu;
        TQuery *qry_subtotcod;
    void __fastcall btn_salirClick(TObject *Sender);
    void __fastcall qry_renentraAfterScroll(TDataSet *DataSet);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall agrerenExecute(TObject *Sender);
    void __fastcall CierraRenExecute(TObject *Sender);
    void __fastcall cancela_renglonExecute(TObject *Sender);
    void __fastcall dbgrdRengCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
    void __fastcall exporta_dbgrdExecute(TObject *Sender);
    void __fastcall imprimeExecute(TObject *Sender);
    void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall capobsExecute(TObject *Sender);
        void __fastcall deshacer_afectacionExecute(TObject *Sender);
        void __fastcall cambia_pto_vtaExecute(TObject *Sender);
        void __fastcall dbgrdRengKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall cierra_entradaExecute(TObject *Sender);
        void __fastcall Frame_datoscapsmay1edt_numeroKeyDown(
          TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall despliega_menuExecute(TObject *Sender);
private:	// User declarations
    bool __fastcall BuscarEntrada(int iNumero);
    void __fastcall ListarRenglon();
    void __fastcall BuscarVendedor(String sVendedor);
    void __fastcall BuscarPoblacion(int iPoblac);
    void __fastcall BuscarPuntoVenta(String sClave);
    void __fastcall BuscarConcepto(int iCliente);
    void __fastcall SigteSabana(int tipo_mov);
    void __fastcall botones_onoff(int modo_z);
    void __fastcall modif_ptvt();
    void __fastcall edicion_factible(int modo_z);
public:		// User declarations
    void __fastcall alta_ptvt(
      String alm_z, double fecha_z, int nument_z, String mayoris_z,
      String siono_z, int idfacorem_z, int numfac_z
    );
    bool __fastcall checa_salto( int maxlin_z);
    void __fastcall salta_linea();
    void __fastcall subtot_x_codigo(String codigo_z, int canti_z, double totcos_z, double &totalfactur_z);


    int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, pagina_z;
    AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
      titmsg_z, genero_z, permis_z, fechaabierta_z;
    FILE *archout;
    TDateTime fecha_z;
    void __fastcall report_encab();
    void __fastcall ejecuta_sql(String sql_z, String codigo_z);


    __fastcall TForm_capsalmay(TComponent* Owner, String tipo_sabana, bool estado);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_capsalmay *Form_capsalmay;
//---------------------------------------------------------------------------
#endif
