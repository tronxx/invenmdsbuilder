//---------------------------------------------------------------------------

#ifndef Frm_infentH
#define Frm_infentH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <stdio.h>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <ActnList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_infent : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TBitBtn *btn_imprel;
        TGroupBox *pnl_datos;
        TLabel *lbl_vigencia;
        TLabel *lbl_corte;
        TDateTimePicker *date_ini;
        TDateTimePicker *date_fin;
        TdxDBGrid *dbgrd_renglones;
        TQuery *qry_delete;
        TQuery *qry_proves;
        TQuery *qry_compra;
        TQuery *qry_companio;
        TQuery *qry_infent;
        TUpdateSQL *uqry_infent;
        TQuery *qry_nomprov;
        TQuery *qry_llenar;
        TDataSource *dts_llenar;
        TdxDBGridMaskColumn *dbgrd_renglonesPROVE;
        TdxDBGridMaskColumn *dbgrd_renglonesNOMBRE;
        TdxDBGridMaskColumn *dbgrd_renglonesRANK1;
        TdxDBGridMaskColumn *dbgrd_renglonesRANK2;
        TdxDBGridMaskColumn *dbgrd_renglonesRANK3;
        TQuery *qry_compmes;
        TQuery *qry_companu;
        TQuery *qry_totmes;
        TQuery *qry_totanual;
        TQuery *qry_lineacod;
        TQuery *qry_devol;
        TQuery *qry_totdevmes;
        TdxDBGridCurrencyColumn *dbgrd_renglonesCOMPRASI;
        TdxDBGridCurrencyColumn *dbgrd_renglonesCOMPRANO;
        TdxDBGridCurrencyColumn *dbgrd_renglonesCOMPRAMES;
        TdxDBGridCurrencyColumn *dbgrd_renglonesCOMPRANU;
        TdxDBGridCurrencyColumn *dbgrd_renglonesTOTGRAL;
        TActionList *ActionList1;
        TAction *exportar;
        TPopupMenu *PopupMenu1;
        TMenuItem *Expotara1;
        TAction *generar_reporte;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall generar_reporteExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_infent(TComponent* Owner);
        FILE *archout;
        TDateTime fecini_z,fecfin_z,fecinianu_z;
        String tpent_z,antlinea_z,tpdev_z;
        int lineas_z, pagina_z,cia_z, numenc_z;
        double totprov_z,comprsi_z,comprno_z,totmes_z,compranio_z,tototal_z,
        gtotsi_z,gtotno_z,gtotm_z,gtotanu_z,gtotgen_z,
        gtotmes_z,gtotpoc1_z,gtoanu_z,gtotpoc2_z ,gtotgbal_z,gtotpoc3_z,
        totcprames_z,totcopeanu_z,totglobal_z,comprames_z,compranual_z,devmesual_z,
        totdevmes_z,gtodev_z ;
        void __fastcall report_encab();
        void __fastcall encab1();
        void __fastcall encab2();
        void __fastcall encab3();
        void __fastcall total_tabla1();
        void __fastcall total_tabla2();
        void __fastcall total_tabla3();
        bool __fastcall checa_salto_pag(int margen_z);
        void __fastcall crear_tabla_proveanual();
        void __fastcall llenar_grip();
        void __fastcall grabar_ranking(String campo_z, int nelem_z);
        void __fastcall imprimir_tabla1();
        void __fastcall imprimir_anual();
        void __fastcall totales();
        void __fastcall crear_tabla_lineanul();
        void __fastcall totales_mensual();
        void __fastcall imprimir_mensual();
        void __fastcall crear_tabla_linedev();

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_infent *Form_infent;
//---------------------------------------------------------------------------
#endif
