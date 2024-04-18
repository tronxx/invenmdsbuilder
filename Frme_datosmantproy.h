//---------------------------------------------------------------------------


#ifndef Frme_datosmantproyH
#define Frme_datosmantproyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include "dxExEdtr.hpp"
//---------------------------------------------------------------------------
class TFrame_datosmantproy : public TFrame
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TDBLookupComboBox *lkcmb_ptovta;
        TDBEdit *DBEdit1;
        TLabel *Label2;
        TdxEdit *edt_subzon;
        TdxEdit *edt_nombre;
        TLabel *Label3;
        TGroupBox *Porcentajes;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TLabel *Label8;
        TDataSource *dts_zonas;
        TQuery *qry_zonas;
        TdxCurrencyEdit *edt_conta;
        TdxCurrencyEdit *edt_crd;
        TdxCurrencyEdit *edt_fona;
        TdxCurrencyEdit *edt_fide;
        TdxCurrencyEdit *edt_imevi;
        TLabel *Label9;
        TdxCurrencyEdit *edt_oferta;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosmantproy(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosmantproy *Frame_datosmantproy;
//---------------------------------------------------------------------------
#endif
