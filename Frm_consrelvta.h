//---------------------------------------------------------------------------

#ifndef Frm_consrelvtaH
#define Frm_consrelvtaH
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
void __fastcall ConsultaRelacionVentas(TForm *Padre);
//---------------------------------------------------------------------------
class TForm_consrelvta: public TForm
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
        TQuery *qry_entradas;
        TUpdateSQL *uqry_entradas;
        TAction *agreren;
        TQuery *qry_ultfol;
        TQuery *qry_conse;
        TUpdateSQL *uqry_renentra;
        TDataSource *dts_entradas;
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
        TPanel *Panel1;
        TPanel *Panel2;
        TGroupBox *GroupBox2;
        TdxDBGrid *dbgrd_ventas;
        TdxDBGridDateColumn *dbgrd_ventasFecha;
        TdxDBGridMaskColumn *dbgrd_ventasSALEDE;
        TdxDBGridMaskColumn *dbgrd_ventasPOBLAC;
        TdxDBGridMaskColumn *dbgrd_ventasPTOVTA;
        TdxDBGridMaskColumn *dbgrd_ventasCODIGO;
        TdxDBGridMaskColumn *dbgrd_ventasDESCRI;
        TdxDBGridCurrencyColumn *dbgrd_ventasPRECIOLISTA;
        TdxDBGridMaskColumn *dbgrd_ventasZona;
        TPopupMenu *PopupMenu1;
        TMenuItem *AgregaReng1;
        TdxDBGridMaskColumn *dbgrd_ventasREMATE;
        TdxDBGridMaskColumn *dbgrd_ventasUBICA;
        TdxDBGridMaskColumn *dbgrd_ventasHORA;
        TdxDBGridMaskColumn *dbgrd_ventasNombre;
        TdxDBGridMaskColumn *dbgrd_ventasVENDEDOR;
        TdxDBGridMaskColumn *dbgrd_ventasTIPOCTE;
        TAction *reporte_acumulados;
        TMenuItem *ReporteAcumulados1;
        TGroupBox *GroupBox1;
        TBitBtn *BitBtn3;
        TMemo *mmo_zonasexclu;
        TSpeedButton *SpeedButton1;
        TAction *definir_zonasexclu;
        TPanel *Panel3;
        TLabel *Label8;
        TDateTimePicker *date_fecini;
        TLabel *Label9;
        TDateTimePicker *date_fecfin;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall exportdbgridExecute(TObject *Sender);
        void __fastcall impritextExecute(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall reporte_acumuladosExecute(TObject *Sender);
        void __fastcall definir_zonasexcluExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_consrelvta(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt();
        void __fastcall modif_ptvt();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall edicion_factible(int modo_z);
        bool __fastcall afecta_kdx();
        void __fastcall report_encab();
        void __fastcall asigna_tipo(int tipo_z);
        void __fastcall busca_cod(String codigo_z);
        void __fastcall reporte_acum_vtas_rel();
        void __fastcall report_encab_acum(String zona_z);
        void __fastcall report_subencab(String zona_z);
        void __fastcall genera_el_reporte_acum();
        void __fastcall genera_reporte_unidades();
        void __fastcall report_subencab_unidades();
        void __fastcall report_unids_impriren(String grupo_z,int unidshoytot_z, int unidsacutot_z, String subraya_z);


        String __fastcall busca_nombre(String tipodato_z, String clave_z);
        void __fastcall report_acum_subtotales(String tit_z,
         double vtaacumzon_z, double vtadiazon_z, double vtaanuazon_z,
         double vtacrdzon_z, double vtaconzon_z);

        int cia_z, mi_entrada_z, entrapor_z, lineas_z, pagina_z;
        String permis_z, tipoent_z, titulo_z, genero_z, este_z, cerrado_z,
          config_z, mensaje_z, titmsg_z, encab_z, MISLIN_X_PAG;
        TForm_selserie *Form_selserie;
        FILE *archout;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_consrelvta *Form_consrelvta;
//---------------------------------------------------------------------------
#endif
