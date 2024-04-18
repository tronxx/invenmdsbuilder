//---------------------------------------------------------------------------

#ifndef Frm_capcancelH
#define Frm_capcancelH
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
#include "Frme_datoscapcancel.h"
#include "Frme_datoscapcancelagrega.h"
#include "Frme_datoscaptrasp.h"
//---------------------------------------------------------------------------
void _fastcall CapCancel(TForm *Padre, String tipo, bool estado);
//---------------------------------------------------------------------------
class TForm_capcancel : public TForm
{
__published:	// IDE-managed Components
    TdxDBGrid *dbgrdReng;
    TQuery *qsAlmacen;
    TQuery *qsConseInv;
    TQuery *qiConseInv;
    TQuery *qsEntradas;
        TQuery *qry_renentra;
        TDataSource *dts_renentra;
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
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TUpdateSQL *uqsEntradas;
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
    TAction *imprime;
        TQuery *qry_folsigent;
        TAction *capobs;
        TAction *abreren;
        TMenuItem *DeshaceAfectaciondeRengln1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton12;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TSpeedButton *SpeedButton3;
        TAction *cerrar_entrada;
        TPanel *Panel1;
        TBitBtn *btn_nvoren;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TFrame_datoscaptrasp *Frame_datoscaptrasp1;
        TMenuItem *Entradas1;
        TMenuItem *Nuevo1;
        TMenuItem *Borra1;
        TMenuItem *Cierra1;
        TMenuItem *Observ1;
        TMenuItem *Imprime1;
        TMenuItem *Primero1;
        TMenuItem *Anterior1;
        TMenuItem *Siguiente1;
        TMenuItem *Ultimo1;
        TMenuItem *Renglones1;
        TAction *despliega_menu;
        TFrame_datoscapcancelagrega *Frame_datoscapcancelagrega1;
    void __fastcall edtNumeroKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btn_salirClick(TObject *Sender);
    void __fastcall qry_renentraAfterScroll(TDataSet *DataSet);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
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
        void __fastcall capobsExecute(TObject *Sender);
        void __fastcall abrerenExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall cerrar_entradaExecute(TObject *Sender);
        void __fastcall despliega_menuExecute(TObject *Sender);
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
    void __fastcall alta_ptvt(String alm_z, double fecha_z, int nument_z);
    void __fastcall modif_ptvt();
    void __fastcall edicion_factible(int modo_z);
public:		// User declarations
    int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, ultrenentra_z, pagina_z;
    AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
      titmsg_z, genero_z, permis_z;
    FILE *archout;
    void __fastcall report_encab();
    void __fastcall busca_cod(String codigo_z);

    __fastcall TForm_capcancel(TComponent* Owner, String tipo_sabana, bool estado);
    void __fastcall aplica_cerrar_renglon();


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_capcancel *Form_capcancel;
//---------------------------------------------------------------------------
#endif
