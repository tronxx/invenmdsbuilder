//---------------------------------------------------------------------------

#ifndef Frm_mantserviH
#define Frm_mantserviH
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
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <stdio.h>
#include <Menus.hpp>
//---------------------------------------------------------------------------
void __fastcall MantoZonas(TForm *Padre);
//---------------------------------------------------------------------------
class TForm_mantservi : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_servicio;
        TUpdateSQL *uqry_servicio;
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
        TDataSource *dts_servicio;
        TToolBar *ToolBar1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton5;
        TToolButton *ToolButton3;
        TAction *exportar;
        TQuery *qry_invhist;
        TAction *agrega_megazonadet;
        TAction *eliminar_megazonasdet;
        TAction *imprimir_reporte;
        TSpeedButton *SpeedButton6;
        TPageControl *pge_servicios;
        TTabSheet *tbs_productos;
        TdxDBGrid *dbgrd_servicios;
        TdxDBGridMaskColumn *dbgrd_serviciosLINEA;
        TdxDBGridMaskColumn *dbgrd_serviciosCODIGO;
        TdxDBGridMaskColumn *dbgrd_serviciosDESCRI;
        TdxDBGridCurrencyColumn *dbgrd_serviciosIMPSERVICIO;
        TdxDBGridDateColumn *dbgrd_serviciosFECHA;
        TTabSheet *tbs_grupos;
        TdxDBGrid *dbgrd_servxgrupo;
        TdxDBGridMaskColumn *dxDBGridMaskColumn2;
        TdxDBGridMaskColumn *dxDBGridMaskColumn3;
        TdxDBGridCurrencyColumn *dxDBGridCurrencyColumn1;
        TdxDBGridDateColumn *dxDBGridDateColumn1;
        TQuery *qry_servxgpo;
        TUpdateSQL *uqry_servxgpo;
        TDataSource *dts_servxgpo;
        TQuery *qry_grupos;
        TDataSource *dts_grupos;
        TDataSource *dts_invhist;
        TPopupMenu *PopupMenu1;
        TMenuItem *Nuevo1;
        TMenuItem *Modifica1;
        TMenuItem *Borra1;
        TMenuItem *Imprimir1;
        TAction *actualiza_precios;
        TSpeedButton *SpeedButton7;
        TQuery *qry_gruposserieaum;
        TUpdateSQL *uqry_gruposserieaum;
        TDataSource *dts_gruposserieaum;
        TTabSheet *tbs_serieaumentada;
        TdxDBGrid *dxDBGrid1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn4;
        TdxDBGridDateColumn *dxDBGridDateColumn2;
        TTabSheet *tbs_colores;
        TdxDBGrid *dbgd_colores;
        TQuery *qry_colores;
        TUpdateSQL *uqry_colores;
        TDataSource *dts_colores;
        TdxDBGridMaskColumn *dbgd_coloresCODIGO;
        TdxDBGridMaskColumn *dbgd_coloresDESCRI;
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall tbs_zonasShow(TObject *Sender);
        void __fastcall tbs_megazonasShow(TObject *Sender);
        void __fastcall imprimir_reporteExecute(TObject *Sender);
        void __fastcall tbs_gruposShow(TObject *Sender);
        void __fastcall tbs_productosShow(TObject *Sender);
        void __fastcall dbgrd_serviciosKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall actualiza_preciosExecute(TObject *Sender);
        void __fastcall tbs_serieaumentadaShow(TObject *Sender);
        void __fastcall tbs_coloresShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantservi(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt(int modo_z);
        void __fastcall modif_ptvt();
        int  __fastcall busca_idart(String codigo_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall genera_reporte();
        void __fastcall salta_linea();
        void __fastcall report_encab();
        void __fastcall report_subenc();
        void __fastcall impri_ren();
        void __fastcall genera_reporte_articulos_x_grupo();
        void __fastcall prepara_query_articulos_x_grupo();
        void __fastcall alta_colores(int modo_z);
        int __fastcall busca_idcolor();

      int cia_z, pagina_z, lineas_z;
      String antlin_z, subenc_z;
      FILE *archout;

    bool bOk;
        String tipo_z, permis_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantservi *Form_mantservi;
//---------------------------------------------------------------------------
#endif
