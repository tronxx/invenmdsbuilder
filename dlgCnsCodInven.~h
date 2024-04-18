//---------------------------------------------------------------------------

#ifndef dlgCnsCodInvenH
#define dlgCnsCodInvenH
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
String __fastcall ConsultaCodInventario(TForm *Padre);
//---------------------------------------------------------------------------
class TfrmDlgCnsCodInven : public TForm
{
__published:	// IDE-managed Components
    TPanel *RzPanel1;
    TLabel *RzLabel1;
    TLabel *RzLabel2;
    TEdit *edtClave;
    TEdit *edtDescri;
    TBitBtn *btnEjecutar;
    TBitBtn *btnCerrar;
    TdxDBGrid *dbgrdCodigo;
    TQuery *qsCodigo;
    TDataSource *dtsCodigo;
    TdxDBGridMaskColumn *dbgrdCodigoCODIGO;
    TdxDBGridMaskColumn *dbgrdCodigoDESCRI;
    void __fastcall btnEjecutarClick(TObject *Sender);
    void __fastcall edtClaveKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtDescriKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall dbgrdCodigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall dbgrdCodigoDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool bOk;
    __fastcall TfrmDlgCnsCodInven(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgCnsCodInven *frmDlgCnsCodInven;
//---------------------------------------------------------------------------
#endif
