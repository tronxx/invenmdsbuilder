//---------------------------------------------------------------------------


#ifndef Frme_datosrenfacmaH
#define Frme_datosrenfacmaH
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
#include <DBTables.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFrame_datosrenfacma : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label8;
        TEdit *edt_codigo;
        TEdit *edt_descri;
        TLabel *Label12;
        TdxCurrencyEdit *edt_canti;
        TLabel *Label10;
        TdxCurrencyEdit *edt_preciou;
        TLabel *Label19;
        TdxCurrencyEdit *edt_pdsc;
        TLabel *lbl_series;
        TComboBox *lst_series;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TButton *btn_series;
        TActionList *ActionList1;
        TAction *selecciona_series;
        TLabel *lbl_piva;
        TdxCurrencyEdit *edt_piva;
        TQuery *qry_extensa;
        void __fastcall edt_codigoExit(TObject *Sender);
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall selecciona_seriesExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosrenfacma(TComponent* Owner);
        void __fastcall busca_inven();
        void __fastcall calcu_prvta();
        int cia_z, tipofac_z;
        String tipomay_z;
        double margenrepo_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosrenfacma *Frame_datosrenfacma;
//---------------------------------------------------------------------------
#endif
