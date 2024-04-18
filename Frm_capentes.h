//---------------------------------------------------------------------------

#ifndef Frm_capentesH
#define Frm_capentesH
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
void _fastcall CapEntes(TForm *Padre, String tipo, bool estado);
//---------------------------------------------------------------------------
class TForm_capentes : public TForm
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
        TDBLookupComboBox *lkcmb_codigos;
        TDBEdit *DBEdit4;
        TBitBtn *btn_nvoren;
        TBitBtn *btn_aceptaren;
        TBitBtn *btn_canceren;
        TdxCurrencyEdit *edt_canti;
        TdxEdit *edt_folios;
        TdxEdit *edt_nombre;
        TDBLookupComboBox *lkcmb_vendedr;
        TDBEdit *DBEdit5;
        TDBLookupComboBox *lkcmb_poblac;
        TDBLookupComboBox *lkcmb_ptovta;
        TDBEdit *DBEdit6;
        TComboBox *cmb_status;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_ultfol;
        TAction *agreren;
        TAction *acepta_ren;
        TQuery *qry_folsale;
        TUpdateSQL *uqry_renentra;
        TDataSource *dts_entradas;
        TAction *cancela_renglon;
    TdxDBGridMaskColumn *dbgrdRengCLIENTE;
    TAction *CierraRen;
    TPopupMenu *pop_menuren;
    TMenuItem *AgregaReng1;
    TMenuItem *CancelaRenglon1;
    TMenuItem *Exportara1;
    TMenuItem *CierraRenglon1;
    TLabel *lbl_prvta;
    TAction *imprime;
    TdxCurrencyEdit *edt_prvta;
        TdxCurrencyEdit *edt_costou;
        TLabel *Label6;
        TQuery *qry_folsigent;
        TdxEdit *edt_serie;
        TLabel *Label7;
        TComboBox *cmb_entcan;
        TEdit *edt_codigo;
        TQuery *qry_buscod;
        TDataSource *dts_buscod;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TGroupBox *GroupBox1;
        TFrame_datoscaptrasp *Frame_datoscaptrasp1;
        TAction *deshacer_afeckardex;
        TMenuItem *DeshacerAfectacin1;
    void __fastcall btnNuevoClick(TObject *Sender);
    void __fastcall btn_salirClick(TObject *Sender);
    void __fastcall qry_renentraAfterScroll(TDataSet *DataSet);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall edt_cantiExit(TObject *Sender);
        void __fastcall agrerenExecute(TObject *Sender);
        void __fastcall acepta_renExecute(TObject *Sender);
        void __fastcall btn_cancerenClick(TObject *Sender);
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
        void __fastcall cmb_statusExit(TObject *Sender);
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall lkcmb_codigosExit(TObject *Sender);
        void __fastcall lkcmb_codigosKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall Frame_datoscaptrasp1edt_numeroKeyDown(
          TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall deshacer_afeckardexExecute(TObject *Sender);
private:	// User declarations
    void __fastcall LimpiarPantalla();
    bool __fastcall BuscarAlmacen(String sClave);
    void __fastcall BuscarUltimoReg();
    bool __fastcall BuscarEntrada(int iNumero);
    void __fastcall ListarRenglon();
    void __fastcall BuscarVendedor(String sVendedor);
    void __fastcall BuscarPoblacion(int iPoblac);
    void __fastcall BuscarPuntoVenta(String sClave);
    void __fastcall BuscarConcepto(int iCliente);
    void __fastcall SigteSabana(int tipo_mov);
    void __fastcall botones_onoff(int modo_z);
    void __fastcall alta_ptvt();
    void __fastcall modif_ptvt();
    void __fastcall edicion_factible(int modo_z);
public:		// User declarations
    int iTpcon, tipoest_z, cia_z, idpermis_z, mi_entrada_z, lineas_z, pagina_z;
    AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
      titmsg_z, genero_z, permis_z;
    FILE *archout;
    void __fastcall report_encab();
    void __fastcall busca_cod(String codigo_z);


    __fastcall TForm_capentes(TComponent* Owner, String tipo_sabana, bool estado);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_capentes *Form_capentes;
//---------------------------------------------------------------------------
#endif
