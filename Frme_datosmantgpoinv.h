//---------------------------------------------------------------------------


#ifndef Frme_datosmantgpoinvH
#define Frme_datosmantgpoinvH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datosmantgpoinv : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edt_ptovta;
        TLabel *Label2;
        TEdit *edt_nombre;
        TCheckBox *chk_imprime;
        TLabel *lbl_codsat;
        TDBLookupComboBox *lkcmb_codsat;
        TQuery *qry_catprodsat;
        TDataSource *dts_catprodsat;
        TDBEdit *dbedt_codsat;
        void __fastcall edt_ptovtaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosmantgpoinv(TComponent* Owner);
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall inicializa (String tipo_z);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosmantgpoinv *Frame_datosmantgpoinv;
//---------------------------------------------------------------------------
#endif
