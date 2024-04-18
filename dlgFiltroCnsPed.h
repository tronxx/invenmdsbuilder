//---------------------------------------------------------------------------

#ifndef dlgFiltroCnsPedH
#define dlgFiltroCnsPedH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
//---------------------------------------------------------------------------
String __fastcall FiltroPedidos(TForm *Padre);
//---------------------------------------------------------------------------
class TfrmDlgFilPedidos : public TForm
{
__published:	// IDE-managed Components
    TPanel *RzPanel1;
    TLabel *RzLabel1;
    TLabel *RzLabel2;
    TLabel *RzLabel3;
    TLabel *RzLabel4;
    TLabel *RzLabel5;
    TLabel *RzLabel6;
    TdxCurrencyEdit *edtPriPed;
    TdxCurrencyEdit *edtUltPed;
    TCheckBox *chkRangoFecha;
    TDateTimePicker *dtFechaIni;
    TDateTimePicker *dtFechaFin;
    TEdit *edtProve;
    TEdit *edtNomProve;
    TBitBtn *btnAceptar;
    TBitBtn *btnCerrar;
    TQuery *qsProve;
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall btnAceptarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall chkRangoFechaClick(TObject *Sender);
    void __fastcall edtProveAltBtnClick(TObject *Sender);
    void __fastcall edtProveKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    bool __fastcall BuscarProveedor(String sClave);
public:		// User declarations
    bool bOk;
    AnsiString sql;
    __fastcall TfrmDlgFilPedidos(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgFilPedidos *frmDlgFilPedidos;
//---------------------------------------------------------------------------
#endif
