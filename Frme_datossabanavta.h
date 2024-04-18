//---------------------------------------------------------------------------


#ifndef Frme_datossabanavtaH
#define Frme_datossabanavtaH
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
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datossabanavta : public TFrame
{
__published:	// IDE-managed Components
        TDataSource *dts_almacen;
        TQuery *qry_almacen;
        TQuery *qry_conse;
        TLabel *Label1;
        TdxDBCurrencyEdit *dxDBCurrencyEdit1;
        TDBLookupComboBox *lkcmb_almacen;
        TDBEdit *DBEdit1;
        TdxDBCurrencyEdit *dxDBCurrencyEdit2;
        TLabel *Label3;
        TdxDBCurrencyEdit *dxDBCurrencyEdit3;
        TLabel *Label4;
        TdxCurrencyEdit *edt_numero;
        TDateTimePicker *date_fecha;
        TLabel *Label2;
        TLabel *Label5;
        TLabel *Label6;
        void __fastcall lkcmb_almacenExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datossabanavta(TComponent* Owner);
        void __fastcall inicializa(String mitipo_z);
        void __fastcall nuevo();
        String tipo_z;
        int cia_z, accion_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datossabanavta *Frame_datossabanavta;
//---------------------------------------------------------------------------
#endif
