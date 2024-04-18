//---------------------------------------------------------------------------

#ifndef Frm_mantcuocelH
#define Frm_mantcuocelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm_mantcuocel : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TDBLookupComboBox *lkcmb_codigo;
    TDBEdit *DBEdit1;
    TDBEdit *DBEdit2;
    TQuery *qry_inven;
    TDataSource *dts_inven;
    TQuery *qry_descri2;
    TDataSource *dts_descri2;
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
    TToolBar *ToolBar1;
    TToolButton *ToolButton3;
    TQuery *qry_cuotacel;
    TDataSource *dts_cuotacel;
    TIntegerField *qry_cuotacelIDVTACEL;
    TIntegerField *qry_cuotacelIDART;
    TFloatField *qry_cuotacelCUOTAMARG;
    TDateField *qry_cuotacelFECHAINI;
    TPanel *Panel2;
    TPanel *Panel3;
    TdxDBGrid *dbgrd_cuotacel;
    TdxDBGridCurrencyColumn *dbgrd_cuotacelCUOTAMARG;
    TdxDBGridDateColumn *dbgrd_cuotacelFECHAINI;
    TdxCurrencyEdit *edt_importe;
    TLabel *Label2;
        TDateTimePicker *date_fecha;
    TLabel *Label3;
        TUpdateSQL *uqry_cuotacel;
        TBitBtn *btn_aceptaren;
        TBitBtn *btn_canceren;
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
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall qry_invenAfterScroll(TDataSet *DataSet);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall ToolButton6Click(TObject *Sender);
        void __fastcall ToolButton5Click(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall dbgrd_cuotacelCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall qry_cuotacelAfterScroll(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
    __fastcall TForm_mantcuocel(TComponent* Owner);
    void __fastcall botones_onoff(int modo_z);
    int cia_z;
    String permis_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantcuocel *Form_mantcuocel;
//---------------------------------------------------------------------------
#endif
