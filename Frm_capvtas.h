//---------------------------------------------------------------------------

#ifndef Frm_capvtasH
#define Frm_capvtasH
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
void __fastcall CapturaSAbadadeVentas(TForm *Padre);
//---------------------------------------------------------------------------
class TForm_capvtas : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *tbtn_nuevo;
        TToolButton *tbtn_modif;
        TToolButton *tbtn_borra;
        TToolButton *ToolButton1;
        TToolButton *ToolButton3;
        TToolButton *ToolButton2;
        TToolButton *ToolButton4;
        TToolButton *ToolButton6;
        TToolButton *ToolButton5;
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
        TImageList *ImageList1;
  TToolButton *ToolButton7;
  TToolButton *ToolButton8;
        TGroupBox *GroupBox1;
        TLabel *Label3;
        TQuery *qry_almacen;
        TDataSource *dts_almacen;
        TDBLookupComboBox *lkcmb_almacen;
        TDBEdit *DBEdit1;
        TDateTimePicker *date_fecha;
        TLabel *Label1;
        TdxCurrencyEdit *edt_nument;
        TLabel *Label4;
        TLabel *Label14;
        TLabel *Label6;
        TLabel *Label7;
        TGroupBox *GroupBox2;
        TLabel *Label8;
        TDBLookupComboBox *lkcmb_inven;
        TDBEdit *DBEdit2;
        TLabel *Label9;
        TBitBtn *btn_nvoren;
        TBitBtn *btn_aceptaren;
        TBitBtn *btn_canceren;
        TLabel *Label10;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_renentra;
        TDataSource *dts_renentra;
        TLabel *Label12;
        TdxCurrencyEdit *edt_canti;
        TdxEdit *edt_folios;
        TQuery *qry_sigent;
        TQuery *qry_entradas;
        TUpdateSQL *uqry_entradas;
        TAction *agreren;
        TQuery *qry_ultfol;
        TQuery *qry_insrenen;
        TUpdateSQL *uqry_insrenen;
        TQuery *qry_conse;
        TQuery *qry_borraren;
        TUpdateSQL *uqry_renentra;
        TDataSource *dts_entradas;
        TdxDBCurrencyEdit *dxDBCurrencyEdit1;
        TdxDBCurrencyEdit *dxDBCurrencyEdit2;
        TdxDBCurrencyEdit *dxDBCurrencyEdit3;
        TAction *cierraren;
        TQuery *qry_edoexi;
        TUpdateSQL *uqry_edoexi;
        TQuery *qry_movart;
        TUpdateSQL *uqry_movart;
        TQuery *qry_exist;
        TUpdateSQL *uqry_exist;
        TQuery *qry_estadis;
        TUpdateSQL *uqry_estadis;
        TGroupBox *GroupBox3;
        TdxDBGrid *dbgrd_rengnes;
        TPopupMenu *pop_menuren;
        TAction *borraren;
        TMenuItem *EliminarRengln1;
        TMenuItem *AgregaReng1;
        TAction *exportdbgrid;
        TMenuItem *Exportara1;
        TdxDBGridMaskColumn *dbgrd_rengnesCODIGO;
        TdxDBGridMaskColumn *dbgrd_rengnesDESCRI;
        TdxDBGridMaskColumn *dbgrd_rengnesFOLSAL;
        TdxDBGridMaskColumn *dbgrd_rengnesSERIE;
        TdxDBGridMaskColumn *dbgrd_rengnesCOSTOU;
        TdxDBGridMaskColumn *dbgrd_rengnesSTATUS;
        TAction *cierra_entrada;
        TToolButton *ToolButton9;
        TAction *impritext;
        TToolButton *ToolButton10;
        TdxDBGridMaskColumn *dbgrd_rengnesENTCAN;
        TLabel *Label2;
        TdxEdit *edt_nombre;
        TLabel *Label5;
        TDBLookupComboBox *lkcmb_vendedr;
        TDBEdit *DBEdit3;
        TQuery *qry_vendr;
        TDataSource *dts_vendr;
        TQuery *qry_folsale;
        TStringField *qry_folsaleCODIGO;
        TIntegerField *qry_folsaleIDART;
        TIntegerField *qry_folsaleIDMOVART;
        TIntegerField *qry_folsaleIDALM;
        TFloatField *qry_folsaleCOSTO;
        TStringField *qry_folsaleMODENT;
        TIntegerField *qry_folsaleFOLIO;
        TIntegerField *qry_folsaleIDSERIE;
        TDateTimeField *qry_folsaleFECHA;
        TStringField *qry_folsaleSERIE;
        TStringField *qry_folsaleENTCAN;
        TDateTimeField *qry_folsaleFECENTORI;
        TStringField *qry_folsaleFACPRO;
        TIntegerField *qry_folsaleIDPROVE;
        TLabel *Label15;
        TDBLookupComboBox *lkcmb_ciudad;
        TQuery *qry_ciudad;
        TDataSource *dts_ciudad;
        TListBox *lst_series;
        TQuery *qry_ptovta;
        TDataSource *dts_ptovta;
        TLabel *Label11;
        TDBLookupComboBox *lkcmb_ptovta;
        TDBEdit *DBEdit4;
        TLabel *Label13;
        TComboBox *cmb_status;
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
        void __fastcall edt_numentEnter(TObject *Sender);
        void __fastcall agrerenExecute(TObject *Sender);
        void __fastcall btn_aceptarenClick(TObject *Sender);
        void __fastcall btn_cancerenClick(TObject *Sender);
        void __fastcall lkcmb_invenExit(TObject *Sender);
        void __fastcall edt_cantiExit(TObject *Sender);
        void __fastcall lst_seriesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgrd_rengnesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall cierrarenExecute(TObject *Sender);
        void __fastcall borrarenExecute(TObject *Sender);
        void __fastcall exportdbgridExecute(TObject *Sender);
        void __fastcall cierra_entradaExecute(TObject *Sender);
        void __fastcall impritextExecute(TObject *Sender);
        void __fastcall qry_renentraAfterScroll(TDataSet *DataSet);
        void __fastcall lkcmb_invenEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_capvtas(TComponent* Owner);
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

        int cia_z, mi_entrada_z, entrapor_z, lineas_z, pagina_z;
        String permis_z, tipoent_z, titulo_z, genero_z, este_z, cerrado_z,
          mensaje_z, titmsg_z;
        TForm_selserie *Form_selserie;
        FILE *archout;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_capvtas *Form_capvtas;
//---------------------------------------------------------------------------
#endif
