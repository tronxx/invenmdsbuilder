//---------------------------------------------------------------------------

#ifndef Frm_relsurtiH
#define Frm_relsurtiH
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
#include <Mask.hpp>
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxDBELib.hpp"
#include <stdio.h>
#include <Menus.hpp>
#include "Frm_selserie.h"
//---------------------------------------------------------------------------
void __fastcall GeneraRelSurti(TForm *Padre);
//---------------------------------------------------------------------------
class TForm_relsurti: public TForm
{
__published:	// IDE-managed Components
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
        TQuery *qry_almacen;
        TDataSource *dts_almacen;
        TQuery *qry_renentra;
        TDataSource *dts_renentra;
        TQuery *qry_sigent;
        TAction *agreren;
        TQuery *qry_ultfol;
        TQuery *qry_grabaartrel;
        TUpdateSQL *uqry_renentra;
        TAction *cierraren;
        TQuery *qry_exist;
        TAction *borraren;
        TAction *exportdbgrid;
        TAction *cierra_entrada;
        TAction *impritext;
        TQuery *qry_vendr;
        TDataSource *dts_vendr;
        TQuery *qry_folsale;
        TQuery *qry_ciudad;
        TDataSource *dts_ciudad;
        TQuery *qry_ptovta;
        TDataSource *dts_ptovta;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_tiposctes;
        TDataSource *dts_tiposctes;
        TQuery *qry_tipoentrega;
        TDataSource *dts_tipoentrega;
        TQuery *qry_chofer;
        TDataSource *dts_chofer;
        TQuery *qry_buscod;
        TDataSource *dts_buscod;
        TQuery *qry_direcs;
        TUpdateSQL *uqry_direcs;
        TDataSource *dts_exist;
        TQuery *qry_relvtas;
        TDataSource *dts_relvtas;
        TPopupMenu *PopupMenu1;
        TMenuItem *AgregaReng1;
        TPanel *Panel2;
        TLabel *Label8;
        TLabel *Label9;
        TDateTimePicker *date_fecini;
        TDateTimePicker *date_fecfin;
        TLabel *Label1;
        TdxCurrencyEdit *edt_nument;
        TLabel *Label2;
        TDateTimePicker *date_fecha;
        TdxTimeEdit *date_hora;
        TLabel *Label3;
        TUpdateSQL *uqry_relsurti;
        TQuery *qry_relsurti;
        TDataSource *dts_relsurti;
        TLabel *Label4;
        TdxTimeEdit *date_horaini;
        TLabel *Label5;
        TdxTimeEdit *date_horafin;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TdxDBGrid *dbgrd_ventas;
        TdxDBGridMaskColumn *dbgrd_ventasZona;
        TdxDBGridDateColumn *dbgrd_ventasFecha;
        TdxDBGridMaskColumn *dbgrd_ventasSALEDE;
        TdxDBGridMaskColumn *dbgrd_ventasTIPOENTREGA;
        TdxDBGridMaskColumn *dbgrd_ventasENTREGA;
        TdxDBGridMaskColumn *dbgrd_ventasPOBLAC;
        TdxDBGridMaskColumn *dbgrd_ventasPTOVTA;
        TdxDBGridMaskColumn *dbgrd_ventasCODIGO;
        TdxDBGridMaskColumn *dbgrd_ventasDESCRI;
        TdxDBGridDateColumn *dbgrd_ventasFECHAENT;
        TdxDBGridCurrencyColumn *dbgrd_ventasPRECIOLISTA;
        TdxDBGrid *dxDBGrid1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn1;
        TdxDBGridDateColumn *dxDBGridDateColumn1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn2;
        TdxDBGridMaskColumn *dxDBGridMaskColumn3;
        TdxDBGridMaskColumn *dxDBGridMaskColumn4;
        TdxDBGridMaskColumn *dxDBGridMaskColumn5;
        TdxDBGridMaskColumn *dxDBGridMaskColumn6;
        TdxDBGridMaskColumn *dxDBGridMaskColumn7;
        TdxDBGridMaskColumn *dxDBGridMaskColumn8;
        TdxDBGridDateColumn *dxDBGridDateColumn2;
        TdxDBGridCurrencyColumn *dxDBGridCurrencyColumn1;
        TPanel *Panel1;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TUpdateSQL *uqry_relvtas;
        TMenuItem *EliminarRengln1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton12;
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall edt_numentKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall btn_aceptarenClick(TObject *Sender);
        void __fastcall cierrarenExecute(TObject *Sender);
        void __fastcall borrarenExecute(TObject *Sender);
        void __fastcall exportdbgridExecute(TObject *Sender);
        void __fastcall impritextExecute(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall dbgrd_ventasDblClick(TObject *Sender);
        void __fastcall dbgrd_ventasKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall BitBtn3Click(TObject *Sender);
        void __fastcall agrerenExecute(TObject *Sender);
        void __fastcall dxDBGrid1DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_relsurti(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt();
        void __fastcall modif_ptvt();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall edicion_factible(int modo_z);
        bool __fastcall afecta_kdx();
        void __fastcall report_encab();
        void __fastcall report_subencab();
        void __fastcall asigna_tipo(int tipo_z);
        void __fastcall busca_cod(String codigo_z);

        int cia_z, mi_entrada_z, entrapor_z, lineas_z, pagina_z;
        String permis_z, tipoent_z, titulo_z, genero_z, este_z, cerrado_z,
          mensaje_z, titmsg_z;
        TForm_selserie *Form_selserie;
        FILE *archout;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_relsurti *Form_relsurti;
//---------------------------------------------------------------------------
#endif
