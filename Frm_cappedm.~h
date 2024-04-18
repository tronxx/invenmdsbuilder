//---------------------------------------------------------------------------

#ifndef Frm_cappedmH
#define Frm_cappedmH
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
#include "Frme_datoscappedm.h"
#include "Frme_datoscappedmagreg.h"
#include "Frme_datoscappedmagrnuevo.h"
//---------------------------------------------------------------------------
void _fastcall CapPedM(TForm *Padre, String tipo, bool estado);
//---------------------------------------------------------------------------
class TForm_cappedm : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_Almacen;
    TQuery *qsConseInv;
    TQuery *qiConseInv;
        TQuery *qry_entradas;
        TQuery *qry_renentra;
    TDataSource *dtsRenEntra;
        TQuery *qry_mayorista;
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
        TDataSource *dts_mayorista;
        TDataSource *dts_poblacion;
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
        TAction *borra_renglon;
    TAction *CierraRen;
    TPopupMenu *pop_menuren;
    TMenuItem *AgregaReng1;
    TMenuItem *CancelaRenglon1;
    TMenuItem *Exportara1;
    TAction *imprime;
        TQuery *qry_folsigent;
        TQuery *qry_buscod;
        TDataSource *dts_buscod;
        TLabel *Label12;
        TGroupBox *GroupBox1;
        TPanel *Panel1;
        TdxDBGrid *dbgrdReng;
        TdxDBGridMaskColumn *dbgrdRengCODINV;
        TdxDBGridColumn *dbgrdRengDESCRI;
        TdxDBGridMaskColumn *dbgrdRengFOLSAL;
        TdxDBGridMaskColumn *dbgrdRengUNIDS;
        TdxDBGridCurrencyColumn *dbgrdRengCOSTOU;
        TdxDBGridMaskColumn *dbgrdRengPIVA;
        TdxDBGridCurrencyColumn *dbgrdRengIMPORTE;
        TBitBtn *btn_nvoren;
        TBitBtn *BitBtn1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton14;
        TGroupBox *GroupBox2;
        TFrame_datoscappedm *Frame_datoscappedm1;
        TAction *cerrar_entrada;
        TQuery *qry_usuarios;
        TMenuItem *Sabana1;
        TMenuItem *Renglones1;
        TMenuItem *Nuevo1;
        TMenuItem *Modifica1;
        TMenuItem *CierraReng1;
        TMenuItem *Primero1;
        TMenuItem *Anterior1;
        TMenuItem *Siguiente1;
        TMenuItem *Ultimo1;
        TMenuItem *Imprime1;
        TAction *despliega_menu;
        TAction *ver_permision;
        TMenuItem *Permision1;
    void __fastcall FormShow(TObject *Sender);
    void __fastcall btn_salirClick(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall agrerenExecute(TObject *Sender);
    void __fastcall CierraRenExecute(TObject *Sender);
    void __fastcall borra_renglonExecute(TObject *Sender);
    void __fastcall dbgrdRengCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
    void __fastcall exporta_dbgrdExecute(TObject *Sender);
    void __fastcall imprimeExecute(TObject *Sender);
        void __fastcall dbgrdRengKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall cerrar_entradaExecute(TObject *Sender);
        void __fastcall despliega_menuExecute(TObject *Sender);
        void __fastcall ver_permisionExecute(TObject *Sender);
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
    void __fastcall alta_ptvt(
       String alm_z, double fecha_z, int nument_z,String mayoris_z,
       int idcontacto_z, String plazo_z
    );
    void __fastcall modif_ptvt();
    void __fastcall edicion_factible(int modo_z);
public:		// User declarations
    void __fastcall report_encab();
    void __fastcall busca_cod(String codigo_z);
    double __fastcall calcu_prvta();
    bool __fastcall checa_salto_pag(int margen_z);

    __fastcall TForm_cappedm(TComponent* Owner, String tipo_sabana, bool estado);
    int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, pagina_z, idpermis_z;
    AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
      titmsg_z, genero_z, permis_z, valpermis_z;
    FILE *archout;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_cappedm *Form_cappedm;
//---------------------------------------------------------------------------
#endif
