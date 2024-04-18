//---------------------------------------------------------------------------

#ifndef Frm_capageembH
#define Frm_capageembH
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
#include <Mask.hpp>
#include <Menus.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm_capageemb : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TQuery *qry_agenda;
        TUpdateSQL *uqry_agenda;
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
        TDataSource *dts_agenda;
        TDBLookupComboBox *lkcmb_almacen;
        TPanel *Panel1;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox2;
        TPanel *Panel2;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TDBEdit *DBEdit1;
        TdxDBGrid *dbrgd_renagenda;
        TdxDBGrid *dbgrd_agendas;
        TQuery *qry_renagenda;
        TUpdateSQL *uqry_renangenda;
        TDataSource *dts_renangenda;
        TdxDBGridMaskColumn *dbgrd_agendasFOLIO;
        TdxDBGridDateColumn *dbgrd_agendasFECHA;
        TdxDBGridMaskColumn *dbgrd_agendasUBICA;
        TDBEdit *DBEdit2;
        TdxDBGridMaskColumn *dbrgd_renagendaPROMOTOR;
        TdxDBGridMaskColumn *dbrgd_renagendaPTOVTA;
        TdxDBGridMaskColumn *dbrgd_renagendaPOBLACION;
        TdxDBGridMaskColumn *dbrgd_renagendaIDCODIGO;
        TdxDBGridMaskColumn *dbrgd_renagendaIDDESCRI;
        TdxDBGridMaskColumn *dbrgd_renagendaHORA;
        TDBEdit *DBEdit3;
        TDBEdit *DBEdit4;
        TAction *nueva_entrega;
        TPopupMenu *PopupMenu1;
        TMenuItem *NuevaEntrega1;
        TdxDBGridImageColumn *dbrgd_renagendaESTADO;
        TPanel *Panel3;
        TLabel *Label2;
        TDateTimePicker *date_fecini;
        TLabel *Label5;
        TDateTimePicker *date_fecfin;
        TButton *Button1;
        TAction *elimina_entrega;
        TMenuItem *EliminaEntrega1;
        TAction *resolver_entrega;
        TMenuItem *Resolver1;
        TAction *impri_text;
        TQuery *qry_impripol;
        TQuery *qry_buscagenda;
        TUpdateSQL *uqry_buscagenda;
        TDataSource *dts_buscagenda;
        TAction *detalles_entrega;
        TUpdateSQL *uqry_renagendaart;
        TDataSource *dts_renagendaart;
        TQuery *qry_renagendaart;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall edt_ptovtaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall qry_agendaAfterScroll(TDataSet *DataSet);
        void __fastcall dbrgd_renagendaCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall nueva_entregaExecute(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall elimina_entregaExecute(TObject *Sender);
        void __fastcall dbrgd_renagendaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall resolver_entregaExecute(TObject *Sender);
        void __fastcall impri_textExecute(TObject *Sender);
        void __fastcall detalles_entregaExecute(TObject *Sender);
        void __fastcall dbrgd_renagendaDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_capageemb(TComponent* Owner);
        void __fastcall desp_ptvt();
        int __fastcall alta_ptvt();
        void __fastcall modif_ptvt();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall report_encab();
        void __fastcall report_subencab();
        void __fastcall report_subencab2();


        int cia_z, folio_z, pagina_z, lineas_z;
        TDateTime fecha_z;
        String permis_z, ubica_z, promotor_z, ciudad_z, nombreprom_z;
        FILE *archout;



};
//---------------------------------------------------------------------------
extern PACKAGE TForm_capageemb *Form_capageemb;
//---------------------------------------------------------------------------
#endif
