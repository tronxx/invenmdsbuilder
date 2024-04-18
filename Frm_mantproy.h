//---------------------------------------------------------------------------

#ifndef Frm_mantproyH
#define Frm_mantproyH
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
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ToolWin.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
//---------------------------------------------------------------------------
class TForm_mantproy : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton9;
        TPanel *Panel1;
        TLabel *Label3;
        TDBLookupComboBox *lkcmb_ptovta;
        TDBEdit *DBEdit1;
        TQuery *qry_zonas;
        TDataSource *dts_zonas;
        TActionList *ActionList1;
        TAction *nuevo;
        TAction *modifica;
        TAction *borra;
        TWindowClose *WindowClose1;
        TQuery *qry_proycom;
        TDataSource *dts_proycom;
        TdxDBGrid *dbgrd_polizas;
        TdxDBGridMaskColumn *dbgrd_polizasZONA;
        TdxDBGridMaskColumn *dbgrd_polizasSUBZONA;
        TdxDBGridMaskColumn *dbgrd_polizasDESCRI;
        TQuery *qry_subproycom;
        TDataSource *dts_subproycom;
        TAction *nuevosub;
        TAction *modifsub;
        TAction *Borrsub;
        TUpdateSQL *uqry_proycom;
        TUpdateSQL *uqry_subproycom;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TGroupBox *GroupBox2;
        TToolBar *ToolBar2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TPanel *Panel2;
        TdxDBGrid *dxDBGrid1;
        TdxDBGridMaskColumn *dxDBGrid1TIPO;
        TdxDBGridMaskColumn *dxDBGrid1ZONAACU;
        TdxDBGridMaskColumn *dxDBGrid1PTVTA;
        TGroupBox *GroupBox1;
        TListBox *ListBox1;
        TSplitter *Splitter1;
        TdxDBGridCurrencyColumn *dbgrd_polizasPORCON;
        TdxDBGridCurrencyColumn *dbgrd_polizasPORCRD;
        TdxDBGridCurrencyColumn *dbgrd_polizasPORFON;
        TdxDBGridCurrencyColumn *dbgrd_polizasPORCEL;
        TdxDBGridCurrencyColumn *dbgrd_polizasPORIME;
        TdxDBGridCurrencyColumn *dbgrd_polizasPOROFERT;
        void __fastcall qry_zonasAfterScroll(TDataSet *DataSet);
        void __fastcall qry_proycomAfterScroll(TDataSet *DataSet);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevosubExecute(TObject *Sender);
        void __fastcall BorrsubExecute(TObject *Sender);
        void __fastcall modifsubExecute(TObject *Sender);
        void __fastcall dxDBGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgrd_polizasKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantproy(TComponent* Owner);
        void __fastcall alta_proy(int modo_z);
        void __fastcall alta_subproy(int modo_z);

        int cia_z;
        String permis_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantproy *Form_mantproy;
//---------------------------------------------------------------------------
#endif
