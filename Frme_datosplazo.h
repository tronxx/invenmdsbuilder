//---------------------------------------------------------------------------


#ifndef Frme_datosplazoH
#define Frme_datosplazoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datosplazo : public TFrame
{
__published:	// IDE-managed Components
        TPanel *pnl_pzoxlinea;
        TLabel *Label1;
        TDBLookupComboBox *lkcmb_lineas;
        TDBEdit *DBEdit1;
        TPanel *pnl_pzoxcodigo;
        TLabel *Label4;
        TEdit *edt_codigo;
        TEdit *edt_descri;
        TPanel *pnl_pzoxgrupo;
        TPanel *pnl_datosprecios;
        TLabel *lbl_precio;
        TLabel *lbl_plazo;
        TdxCurrencyEdit *edt_plismax;
        TdxCurrencyEdit *edt_plazomax;
        TLabel *lgl_gpo;
        TDBLookupComboBox *lkcmb_grupos;
        TDBEdit *dbedt_descri;
        TCheckBox *chk_prioridad;
        TDataSource *dts_lineas;
        TQuery *qry_lineas;
        TDataSource *dts_grupos;
        TQuery *qry_grupos;
        TQuery *qry_buscod;
        TDataSource *dts_buscod;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TDBLookupComboBox *lkcmb_codigos;
        TCheckBox *chk_prioridadgpo;
        TComboBox *cmb_tipo;
        TLabel *lbl_tipo;
        TDBLookupComboBox *lkcmb_tipoplazo;
        TQuery *qry_tipoplazo;
        TDataSource *dts_tipoplazo;
        TLabel *lbl_tipoplzo;
        TDBEdit *dbedt_tipoplazo;
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall lkcmb_codigosExit(TObject *Sender);
        void __fastcall lkcmb_codigosKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosplazo(TComponent* Owner);
        void __fastcall busca_cod(String codigo_z);
        int cia_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosplazo *Frame_datosplazo;
//---------------------------------------------------------------------------
#endif
