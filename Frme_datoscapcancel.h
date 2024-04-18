//---------------------------------------------------------------------------


#ifndef Frme_datoscapcancelH
#define Frme_datoscapcancelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBELib.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFrame_datoscapcancel : public TFrame
{
__published:	// IDE-managed Components
        TDBLookupComboBox *lkcmb_almacen;
        TLabel *RzLabel1;
        TDBEdit *DBEdit1;
        TLabel *Label1;
        TdxDBCurrencyEdit *dxDBCurrencyEdit1;
        TLabel *Label3;
        TdxDBCurrencyEdit *dxDBCurrencyEdit2;
        TLabel *RzLabel3;
        TdxCurrencyEdit *edt_numero;
        TLabel *RzLabel4;
        TDateTimePicker *date_fecha;
        TLabel *Label4;
        TdxDBCurrencyEdit *dxDBCurrencyEdit3;
        TQuery *qry_Almacen;
        TDataSource *dts_almacen;
        void __fastcall lkcmb_almacenExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscapcancel(TComponent* Owner);
        String tipo_z;
        int cia_z, modo_z;
        void __fastcall nuevo();
        void __fastcall inicializa(String mitipo_z);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscapcancel *Frame_datoscapcancel;
//---------------------------------------------------------------------------
#endif
