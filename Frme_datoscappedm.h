//---------------------------------------------------------------------------


#ifndef Frme_datoscappedmH
#define Frme_datoscappedmH
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
class TFrame_datoscappedm : public TFrame
{
__published:	// IDE-managed Components
        TDBLookupComboBox *lkcmb_almacen;
        TLabel *Label14;
        TDBLookupComboBox *lkcmb_vendedr;
        TLabel *Label2;
        TEdit *edt_facpro;
        TDBEdit *DBEdit2;
        TDBEdit *DBEdit1;
        TLabel *Label5;
        TEdit *edt_contacto;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TdxDBCurrencyEdit *dbedt_total;
        TdxDBCurrencyEdit *dbedt_iva;
        TdxDBCurrencyEdit *dbedt_importe;
        TQuery *qry_Almacen;
        TDataSource *dts_almacen;
        TQuery *qry_mayorista;
        TDataSource *dts_mayorista;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TDateTimePicker *date_fecha;
        TdxCurrencyEdit *edt_numero;
        void __fastcall lkcmb_almacenExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscappedm(TComponent* Owner);
        void __fastcall nuevo();
        void __fastcall inicializa(String mitipomov_z);
        String tipomov_z,tipo_z;
        int cia_z, accion_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscappedm *Frame_datoscappedm;
//---------------------------------------------------------------------------
#endif
