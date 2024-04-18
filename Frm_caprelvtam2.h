//---------------------------------------------------------------------------

#ifndef Frm_caprelvtam2H
#define Frm_caprelvtam2H
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
#include "Frme_datosrelvta.h"
//---------------------------------------------------------------------------
void __fastcall CapturaRelacionVentas(TForm *Padre);
//---------------------------------------------------------------------------
class TForm_caprelvtam2: public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
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
        TQuery *qry_conse;
        TUpdateSQL *uqry_renentra;
        TDataSource *dts_entradas;
        TAction *cierraren;
        TPopupMenu *pop_menuren;
        TAction *borraren;
        TMenuItem *EliminarRengln1;
        TAction *exportdbgrid;
        TMenuItem *Exportara1;
        TAction *cierra_entrada;
        TAction *impritext;
        TQuery *qry_folsale;
        TQuery *qry_ptovta;
        TDataSource *dts_ptovta;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_direcs;
        TUpdateSQL *uqry_direcs;
        TUpdateSQL *uqry_renentranew;
        TQuery *qry_renentranew;
        TAction *nueva_pol;
        TDataSource *dts_polrelvta;
        TQuery *qry_polrelvta;
        TUpdateSQL *uqry_polrelvta;
        TQuery *qry_ubica;
        TDataSource *dts_ubica;
        TAction *busca_polizas;
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TPanel *Panel2;
        TLabel *Label4;
        TLabel *Label13;
        TDateTimePicker *date_fecha;
        TDBLookupComboBox *lkcmb_ubica;
        TDBEdit *DBEdit2;
        TdxDBGrid *dxDBGrid2;
        TdxDBGridMaskColumn *dxDBGridMaskColumn1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn2;
        TdxDBGridDateColumn *dxDBGridDateColumn1;
        TAction *asigna_alm;
        TPopupMenu *PopupMenu1;
        TMenuItem *Ubicar1;
        TQuery *qry_comprometidos;
        TUpdateSQL *uqry_invcompromet;
        TQuery *qry_invcompromet;
        TUpdateSQL *uqry_invcomprometart;
        TQuery *qry_invcomprometart;
        TMenuItem *AgregaReng1;
        TAction *recargar_datos;
        TAction *ren_sigte;
        TAction *ren_anter;
        TAction *exist_anter;
        TAction *exist_sigte;
        TAction *ren_primero;
        TAction *ren_ultimo;
        TAction *exist_primera;
        TAction *exist_ultima;
        TQuery *qry_impripol;
        TAction *cambia_precio;
        TMenuItem *CambiarPrecio1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton12;
        TSpeedButton *SpeedButton13;
        TSpeedButton *SpeedButton14;
        TGroupBox *GroupBox3;
        TFrame_datosrelvta *Frame_datosrelvta1;
        TQuery *qry_entradas;
        TUpdateSQL *uqry_entradas;
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall exportdbgridExecute(TObject *Sender);
        void __fastcall impritextExecute(TObject *Sender);
        void __fastcall qry_renentraAfterScroll(TDataSet *DataSet);
        void __fastcall nueva_polExecute(TObject *Sender);
        void __fastcall qry_entradasAfterScroll(TDataSet *DataSet);
        void __fastcall asigna_almExecute(TObject *Sender);
        void __fastcall lkcmb_ubicaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall date_fechaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall ren_sigteExecute(TObject *Sender);
        void __fastcall date_fechaExit(TObject *Sender);
        void __fastcall lkcmb_ubicaExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_caprelvtam2(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt(int modo_z);
        void __fastcall modif_ptvt();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall edicion_factible(int modo_z);
        bool __fastcall afecta_kdx();
        void __fastcall report_encab();
        void __fastcall report_subencabremate();
        void __fastcall report_subencabubi();
        void __fastcall report_subencabzon();
        void __fastcall report_subencabpvta();
        void __fastcall asigna_tipo(int tipo_z);
        void __fastcall busca_cod(String codigo_z);
        void __fastcall alta_pol();
        void __fastcall desp_polrelvta();
        void __fastcall busca_polrelvta();
        void __fastcall despliega_renentra();
        void __fastcall reporte_subtot(double importe_z, String tit_z, String tipo_z);
        String __fastcall busca_dato(String tipodato_z, String clave_z);
        int cia_z, mi_entrada_z, entrapor_z, lineas_z, pagina_z, idusuario_z;
        String permis_z, tipoent_z, titulo_z, genero_z, este_z, cerrado_z,
          mensaje_z, titmsg_z, ubica_z, pvta_z, nomubi_z, nomptovt_z,
          zona_z, remate_z;
        TForm_selserie *Form_selserie;
        FILE *archout;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_caprelvtam2 *Form_caprelvtam2;
//---------------------------------------------------------------------------
#endif
