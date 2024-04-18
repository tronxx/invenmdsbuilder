//---------------------------------------------------------------------------

#ifndef dlgCnsConceptoH
#define dlgCnsConceptoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
int __fastcall BuscarConcepts(TForm *Padre);
//---------------------------------------------------------------------------
class TfrmDlgConcepto : public TForm
{
__published:	// IDE-managed Components
    TPanel *RzPanel1;
    TLabel *RzLabel1;
    TLabel *RzLabel2;
    TEdit *edtClave;
    TEdit *edtNombre;
    TBitBtn *btnEjecutar;
    TBitBtn *btnCerrar;
    TdxDBGrid *dxDBGrid1;
    TQuery *qsConcepto;
    TDataSource *dtsConcepto;
    TdxDBGridColumn *dxDBGrid1NCON;
    TdxDBGridColumn *dxDBGrid1CONCEPTO;
    TStringField *qsConceptoCONCEPTO;
    TIntegerField *qsConceptoNCON;
    void __fastcall btnEjecutarClick(TObject *Sender);
    void __fastcall dxDBGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall dxDBGrid1DblClick(TObject *Sender);
    void __fastcall btnCerrarClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool bOk;
    __fastcall TfrmDlgConcepto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgConcepto *frmDlgConcepto;
//---------------------------------------------------------------------------
#endif
