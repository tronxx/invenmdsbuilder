//---------------------------------------------------------------------------

#ifndef dlgFiltroConsFacMayH
#define dlgFiltroConsFacMayH
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
AnsiString __fastcall FiltroBusquedaFacMay(TForm *Padre);
//---------------------------------------------------------------------------
class TdlgFilConsufacma : public TForm
{
__published:	// IDE-managed Components
    TPanel *RzPanel1;
    TGroupBox *grpPlazos;
    TLabel *RzLabel7;
    TdxCurrencyEdit *edtPrimPlazo;
    TLabel *RzLabel8;
    TdxCurrencyEdit *edtUltPlazo;
    TGroupBox *grpTipoFact;
    TCheckBox *chkMercancia;
    TCheckBox *chkInteres;
    TGroupBox *grpTipoCompra;
    TCheckBox *chkMayoreo;
    TCheckBox *chklMenudeo;
    TCheckBox *chkOtros;
    TQuery *qsProve;
    TLabel *RzLabel9;
    TCheckBox *chkAbierto;
    TCheckBox *chkCerrado;
        TPanel *Panel1;
        TBitBtn *btnAceptar;
        TBitBtn *btnCerrar;
        TLabel *RzLabel1;
        TdxCurrencyEdit *edtPriFac;
        TLabel *RzLabel2;
        TdxCurrencyEdit *edtUltFac;
        TGroupBox *grp_rangofac;
        TGroupBox *GroupBox1;
        TCheckBox *chkRangoFecha;
        TLabel *RzLabel3;
        TDateTimePicker *dtFechaIni;
        TLabel *RzLabel4;
        TDateTimePicker *dtFechaFin;
        TGroupBox *GroupBox2;
        TLabel *RzLabel5;
        TEdit *edtProve;
        TLabel *RzLabel6;
        TEdit *edtNomProve;
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall btnAceptarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
    void __fastcall edtProveKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtProveAltBtnClick(TObject *Sender);
private:	// User declarations
    bool __fastcall BuscarProveedor(String sClave);
public:		// User declarations
    bool bOk;
    AnsiString sql;
    __fastcall TdlgFilConsufacma(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TdlgFilConsufacma *dlgFilConsufacma;
//---------------------------------------------------------------------------
#endif
