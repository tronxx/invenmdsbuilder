//---------------------------------------------------------------------------

#ifndef dlgImpPendPagMayH
#define dlgImpPendPagMayH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
void __fastcall ImpresionPendientesMayoristas(TForm *Padre, bool bTipo);
//---------------------------------------------------------------------------
class TfrmDlgImpPenPag : public TForm
{
__published:	// IDE-managed Components
        TPanel *RzPanel1;
        TLabel *RzLabel5;
        TLabel *RzLabel4;
        TEdit *edtCveMay;
        TEdit *edtMayorista;
        TEdit *edtDirecc;
        TBitBtn *btnCerrar;
        TBitBtn *btnImpEdoCta;
    TQuery *qsMayoris;
        TLabel *rlblLetrero;
        TLabel *lblAnio;
        TdxSpinEdit *spinAnio;
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall edtCveMayKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtCveMayAltBtnClick(TObject *Sender);
    void __fastcall btnImpEdoCtaClick(TObject *Sender);
private:	// User declarations
    bool __fastcall BuscarMayorista(String sCodigo);
public:		// User declarations
    bool bTIPO;
    __fastcall TfrmDlgImpPenPag(TComponent* Owner, bool bTipop);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgImpPenPag *frmDlgImpPenPag;
//---------------------------------------------------------------------------
#endif
