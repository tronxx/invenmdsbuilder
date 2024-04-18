//---------------------------------------------------------------------------

#ifndef dialg_datosrenagendaH
#define dialg_datosrenagendaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "dxExEdtr.hpp"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
#include <ComCtrls.hpp>
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class Tdlg_datosrenagenda : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TQuery *qry_ptovta;
        TDataSource *dts_ptovta;
        TPanel *pnl_datosentrega;
        TLabel *Label2;
        TDBLookupComboBox *lkcmb_chofer;
        TDBEdit *DBEdit2;
        TQuery *qry_chofer;
        TDataSource *dts_promotor;
        TDBEdit *DBEdit3;
        TLabel *Label5;
        TDBLookupComboBox *lkcmb_ptovta;
        TLabel *Label6;
        TDBLookupComboBox *lkcmb_poblac;
        TLabel *Label1;
        TEdit *edt_codigo;
        TEdit *edt_descri;
        TEdit *edt_colonia;
        TLabel *Label4;
        TLabel *Observs;
        TEdit *edt_observs;
        TDataSource *dts_poblacs;
        TQuery *qry_poblacs;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TLabel *Label7;
        TDateTimePicker *date_fecha;
        TLabel *Label8;
        TDBLookupComboBox *lkcmb_ubica;
        TDBEdit *DBEdit1;
        TQuery *qry_almacen;
        TDataSource *dts_almacen;
        TQuery *qry_renagendaart;
        TDataSource *dts_renagendaart;
        TUpdateSQL *uqry_renagendaart;
        TdxDBGrid *dbgrd_inven;
        TdxDBGridMaskColumn *dbgrd_invenCODIGO;
        TdxDBGridMaskColumn *dbgrd_invenDESCRI;
        TActionList *ActionList1;
        TAction *agrega_ren;
        TBitBtn *BitBtn3;
        TAction *borra_articulo;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall agrega_renExecute(TObject *Sender);
        void __fastcall borra_articuloExecute(TObject *Sender);
        void __fastcall dbgrd_invenKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall Tdlg_datosrenagenda(TComponent* Owner);

        int cia_z;
};
//---------------------------------------------------------------------------
extern PACKAGE Tdlg_datosrenagenda *dlg_datosrenagenda;
//---------------------------------------------------------------------------
#endif
