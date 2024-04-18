//---------------------------------------------------------------------------

#ifndef Frm_canxcamH
#define Frm_canxcamH
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
#include "Frme_datoscaptrasp.h"
//---------------------------------------------------------------------------
void _fastcall CapturadeSabanasCanXCam(TForm *Padre, String tipo, bool estado);
//---------------------------------------------------------------------------
class TForm_canxcam : public TForm
{
__published:	// IDE-managed Components
    TdxDBGrid *dbgrdReng;
    TQuery *qsAlmacen;
    TQuery *qsConseInv;
    TQuery *qiConseInv;
    TQuery *qsEntradas;
        TQuery *qry_renentra;
    TDataSource *dtsRenEntra;
    TdxDBGridMaskColumn *dbgrdRengRECEMI;
    TdxDBGridMaskColumn *dbgrdRengCODINV;
    TdxDBGridMaskColumn *dbgrdRengSERIE;
    TdxDBGridMaskColumn *dbgrdRengSIONO;
    TdxDBGridMaskColumn *dbgrdRengFOLSAL;
    TdxDBGridMaskColumn *dbgrdRengFOLENT;
    TdxDBGridMaskColumn *dbgrdRengUNIDS;
    TdxDBGridMaskColumn *dbgrdRengPIVA;
    TdxDBGridMaskColumn *dbgrdRengIMPORTE;
    TdxDBGridMaskColumn *dbgrdRengSTATUS;
    TdxDBGridMaskColumn *dbgrdRengVEND;
    TdxDBGridColumn *dbgrdRengDESCRI;
    TdxDBGridCurrencyColumn *dbgrdRengCOSTOU;
        TQuery *qry_vendedor;
    TQuery *qsPoblacion;
    TQuery *qsPuntoVta;
        TQuery *qry_sigfol;
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
        TGroupBox *grp_datosren;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TLabel *Label12;
        TLabel *Label2;
        TLabel *Label5;
        TLabel *Label15;
        TLabel *Label11;
        TLabel *Label13;
        TdxCurrencyEdit *edt_canti;
        TdxEdit *edt_folios;
        TDBLookupComboBox *lkcmb_vendedr;
        TDBEdit *DBEdit5;
        TDBLookupComboBox *lkcmb_poblac;
        TDBLookupComboBox *lkcmb_ptovta;
        TDBEdit *DBEdit6;
        TComboBox *cmb_status;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TAction *agreren;
        TAction *acepta_ren;
        TQuery *qry_folsale;
        TUpdateSQL *uqry_renentra;
        TDataSource *dts_entradas;
        TAction *elimina_renglon;
    TdxDBGridMaskColumn *dbgrdRengCLIENTE;
    TAction *CierraRen;
    TPopupMenu *pop_menuren;
    TMenuItem *AgregaReng1;
    TMenuItem *CancelaRenglon1;
    TMenuItem *Exportara1;
    TMenuItem *CierraRenglon1;
    TLabel *lbl_prvta;
    TAction *imprime;
        TLabel *Label6;
        TComboBox *cmb_entosal;
        TLabel *Label7;
        TComboBox *cmb_statcan;
        TComboBox *lst_series;
        TdxDBGridMaskColumn *dbgrdRengENTOSAL;
        TAction *capobs;
        TAction *desafecta_kardex;
        TMenuItem *DeshacerAfectacin1;
        TEdit *edt_codigo;
        TQuery *qry_buscod;
        TDataSource *dts_buscod;
        TGroupBox *GroupBox1;
        TFrame_datoscaptrasp *Frame_datoscaptrasp1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn6;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TBitBtn *BitBtn9;
        TPanel *Panel1;
        TBitBtn *btn_nvoren;
        TBitBtn *BitBtn10;
        TBitBtn *BitBtn11;
        TEdit *edt_descri;
        TAction *cierra_entrada;
        TdxCurrencyEdit *edt_costo;
        TEdit *edt_nombre;
        TMenuItem *Sabana1;
        TMenuItem *Renglones1;
        TMenuItem *Nuevo1;
        TMenuItem *Borra1;
        TMenuItem *Cierra1;
        TMenuItem *imprime1;
        TMenuItem *Primero1;
        TMenuItem *anterior1;
        TMenuItem *siguiente1;
        TMenuItem *ultimo1;
        TAction *despliega_menu;
    void __fastcall FormShow(TObject *Sender);
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
    void __fastcall elimina_renglonExecute(TObject *Sender);
    void __fastcall dbgrdRengCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
    void __fastcall exporta_dbgrdExecute(TObject *Sender);
    void __fastcall imprimeExecute(TObject *Sender);
        void __fastcall capobsExecute(TObject *Sender);
        void __fastcall desafecta_kardexExecute(TObject *Sender);
        void __fastcall Frame_datoscaptrasp1edt_numeroKeyDown(
          TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall dbgrdRengKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall cierra_entradaExecute(TObject *Sender);
        void __fastcall despliega_menuExecute(TObject *Sender);
private:	// User declarations
    void __fastcall LimpiarPantalla();
    void __fastcall BuscarUltimoReg();
    bool __fastcall BuscarEntrada(int iNumero);
    void __fastcall ListarRenglon();
    void __fastcall BuscarVendedor(String sVendedor);
    void __fastcall BuscarPuntoVenta(String sClave);
    void __fastcall SigteSabana(int tipo_mov);
    void __fastcall botones_onoff(int modo_z);
    void __fastcall alta_ptvt(String alm_z, double fecha_z, int nument_z);
    void __fastcall modif_ptvt();
    void __fastcall edicion_factible(int modo_z);
public:		// User declarations
    int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, pagina_z;
    AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
      titmsg_z, genero_z, permis_z;
    FILE *archout;
    void __fastcall report_encab();
    void __fastcall busca_cod(String codigo_z);

    __fastcall TForm_canxcam(TComponent* Owner, String tipo_sabana, bool estado);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_canxcam *Form_canxcam;
//---------------------------------------------------------------------------
#endif
