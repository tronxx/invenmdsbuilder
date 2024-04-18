//---------------------------------------------------------------------------


#ifndef Frme_datoscaptraspH
#define Frme_datoscaptraspH
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
class TFrame_datoscaptrasp : public TFrame
{
__published:	// IDE-managed Components
        TDBLookupComboBox *lkcmb_almacen;
        TDBEdit *DBEdit1;
        TdxDBCurrencyEdit *dbedt_total;
        TLabel *lbl_total;
        TdxDBCurrencyEdit *dbedt_iva;
        TLabel *lbl_iva;
        TdxDBCurrencyEdit *dbedt_importe;
        TLabel *lbl_importe;
        TQuery *qry_Almacen;
        TDataSource *dts_almacen;
        TLabel *lbl_alm;
        TLabel *lbl_numero;
        TLabel *Label6;
        TdxCurrencyEdit *edt_numero;
        TDateTimePicker *date_fecha;
        void __fastcall lkcmb_almacenExit(TObject *Sender);
        void __fastcall date_fechaExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscaptrasp(TComponent* Owner);
        void __fastcall nuevo();
        void __fastcall inicializa(String mitipo_z);

        String tipo_z;
        int cia_z, accion_z, checafecha_z;
        TDateTime fecmin_z, fecmax_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscaptrasp *Frame_datoscaptrasp;
//---------------------------------------------------------------------------
#endif
