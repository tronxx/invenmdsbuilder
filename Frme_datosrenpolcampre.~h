//---------------------------------------------------------------------------


#ifndef Frme_datosrenpolcampreH
#define Frme_datosrenpolcampreH
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
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datosrenpolcampre : public TFrame
{
__published:	// IDE-managed Components
        TLabel *lbl_numero;
        TEdit *edt_codigo;
        TEdit *edt_descri;
        TdxCurrencyEdit *edt_precioant;
        TLabel *lbl_precioant;
        TLabel *lbl_precionvo;
        TdxCurrencyEdit *edt_precionvo;
        TLabel *lbl_subsidioant;
        TdxCurrencyEdit *edt_fideant;
        TLabel *lbl_subsidionvo;
        TdxCurrencyEdit *edt_fidenvo;
        TLabel *lbl_costorepo;
        TdxCurrencyEdit *edt_costoxten;
        TdxCurrencyEdit *edt_precioxten;
        TLabel *lbl_precioxtensa;
        TLabel *lbl_garantia;
        TDBLookupComboBox *lkcmb_garantia;
        TLabel *lbl_descri;
        TLabel *lbl_observs;
        TEdit *edt_observs;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_garantias;
        TDataSource *dts_garantias;
        TDBEdit *dbedt_garantia;
        TLabel *lbl_situanvo;
        TDBLookupComboBox *lkcmb_situaciones;
        TQuery *qry_situaciones;
        TDataSource *dts_situaciones;
        TLabel *lbl_situaant;
        TEdit *edt_antsit;
        TQuery *qry_invxtensa;
        TQuery *qry_invgarantia;
        TUpdateSQL *uqry_invxtensa;
        TQuery *qry_invhist;
        void __fastcall edt_codigoExit(TObject *Sender);
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall edt_costoxtenExit(TObject *Sender);
        void __fastcall lkcmb_garantiaExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosrenpolcampre(TComponent* Owner);
        void __fastcall busca_inven();
        void __fastcall solo_reposicion();
        void __fastcall graba_reposicion();

        int cia_z, eximin_z, eximax_z;
        double factorxten_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosrenpolcampre *Frame_datosrenpolcampre;
//---------------------------------------------------------------------------
#endif
