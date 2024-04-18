//---------------------------------------------------------------------------

#ifndef dialg_datosagendaH
#define dialg_datosagendaH
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
#include "dxDBELib.hpp"
//---------------------------------------------------------------------------
class Tdlg_datosagenda : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TQuery *qry_almacen;
        TDataSource *dts_almacen;
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TDateTimePicker *date_fecha;
        TDBLookupComboBox *lkcmb_ubica;
        TDBEdit *DBEdit1;
        TdxDBCurrencyEdit *edt_folio;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tdlg_datosagenda(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE Tdlg_datosagenda *dlg_datosagenda;
//---------------------------------------------------------------------------
#endif
