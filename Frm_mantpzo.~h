//---------------------------------------------------------------------------

#ifndef Frm_mantpzoH
#define Frm_mantpzoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include "dxExEdtr.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Mask.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_mantpzo : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TQuery *qry_plazoscrd;
        TUpdateSQL *uqry_plazoscrd;
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
        TDataSource *dts_plazoscrd;
        TQuery *qry_preciosart;
        TDataSource *dts_preciosart;
        TAction *exportar;
        TQuery *qry_plazoxgrupo;
        TDataSource *dts_plazoxgrupo;
        TQuery *qry_plazoxprecio;
        TDataSource *dts_plazoxprecio;
        TQuery *qry_plazoxlinea;
        TDataSource *dts_plazoxlinea;
        TQuery *qry_invgpomayprecio;
        TUpdateSQL *uqry_invgpomayprecio;
        TDataSource *dts_invgpomayprecio;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TQuery *qry_precioxprove;
        TUpdateSQL *uqry_precioxprove;
        TDataSource *dts_precioxprove;
        TPopupMenu *PopupMenu1;
        TMenuItem *Nuevo1;
        TMenuItem *Borra1;
        TMenuItem *Modifica1;
        TMenuItem *Expotara1;
        TPageControl *pge_mayomen;
        TTabSheet *tbs_menudeo;
        TPageControl *pge_listas;
        TTabSheet *tbs_lineas;
        TdxDBGrid *dbgrd_pzolineas;
        TdxDBGridMaskColumn *dbgrd_pzolineasLINEA;
        TdxDBGridMaskColumn *dbgrd_pzolineasDESCRI;
        TdxDBGridMaskColumn *dbgrd_pzolineasPLAZOMAX;
        TdxDBGridMaskColumn *dbgrd_pzolineasColumn5;
        TdxDBGridMaskColumn *dbgrd_pzolineasTIPO;
        TTabSheet *tbs_precios;
        TdxDBGrid *dbgrd_plazoxprecio;
        TdxDBGridMaskColumn *dxDBGridPLAZOMAX;
        TdxDBGridCurrencyColumn *dxDBGridCurrencyPLISTAMAX;
        TdxDBGridMaskColumn *dxDBGridTIPO;
        TTabSheet *tbs_grupos;
        TdxDBGrid *dbgrd_plazoxgpo;
        TdxDBGridMaskColumn *dbgrd_plazoxgpoLinea;
        TdxDBGridMaskColumn *dxDBGridMaskColumn5;
        TdxDBGridMaskColumn *dxDBGridMaskColumn6;
        TdxDBGridMaskColumn *dxDBGridMaskColumn9;
        TdxDBGridMaskColumn *dxDBGridMaskColumn10;
        TdxDBGridMaskColumn *dbgrd_plazoxgpoColumn6;
        TTabSheet *tbs_articulos;
        TdxDBGrid *dbgrd_pzoartic;
        TdxDBGridMaskColumn *dxDBGridMaskColumn1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn2;
        TdxDBGridMaskColumn *dxDBGridMaskColumn3;
        TdxDBGridMaskColumn *dxDBGridMaskColumn4;
        TTabSheet *tbs_mayoreo;
        TPageControl *pge_mayoreo;
        TTabSheet *tbs_gpomayoreo;
        TdxDBGrid *dbgrd_gpomayprecio;
        TdxDBGridMaskColumn *dbgrd_gpomayprecioCODIGO;
        TdxDBGridMaskColumn *dbgrd_gpomayprecioDESCRI;
        TdxDBGridCurrencyColumn *dbgrd_gpomayprecioFACTORPRECIO;
        TdxDBGridMaskColumn *dbgrd_gpomayprecioFECHA;
        TdxDBGridMaskColumn *dbgrd_gpomayprecioTIPO;
        TTabSheet *tbs_preciomaypro;
        TdxDBGrid *dbgrd_preciomaypro;
        TdxDBGridMaskColumn *dxDBGridMaskColumn11;
        TdxDBGridMaskColumn *dxDBGridMaskColumn12;
        TdxDBGridCurrencyColumn *dxDBGridCurrencyColumn2;
        TdxDBGridMaskColumn *dxDBGridMaskColumn14;
        TSplitter *Splitter1;
        TMemo *mmo_instruc;
        TSplitter *Splitter2;
        TMemo *mmo_observsmay;
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall dbgrd_pzolineasCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall dbgrd_pzolineasKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgrd_pzoarticKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall tbs_lineasShow(TObject *Sender);
        void __fastcall pge_mayomenChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantpzo(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt();
        void __fastcall modif_ptvt();
        void __fastcall abre_querys();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall busca_cod(String codigo_z);
        int cia_z,
            TBS_LINEAS,
            TBS_PRECIOS,
            TBS_ARTICULOS,
            TBS_GRUPOS,
            TBS_GPOMAYOREO,
            TBS_MENUDEO,
            TBS_MAYOREO,
            TBS_PRECIOMAYPRO,
            TIPOLISTA_LINEAS,
            TIPOLISTA_GRUPOS,
            idplazo_z, idlinea_z, plazomax_z, tipo_z;
        String pagina_z, permis_z, linea_z, descri_z, prioridad_z;
        double plistamax_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantpzo *Form_mantpzo;
//---------------------------------------------------------------------------
#endif
