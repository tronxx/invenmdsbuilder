//---------------------------------------------------------------------------

#ifndef dlgCnsMayoristaH
#define dlgCnsMayoristaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Db.hpp>
#include <DBTables.hpp>
#include <Buttons.hpp>

//---------------------------------------------------------------------------
String __fastcall BusquedaMayoristas(TForm *Padre);
//---------------------------------------------------------------------------
class TfrmDlgCnsMayoris : public TForm
{
__published:	// IDE-managed Components
        TPanel *RzPanel1;
        TLabel *RzLabel1;
        TEdit *edtClave;
        TEdit *edtNombre;
        TLabel *RzLabel2;
        TBitBtn *btnEjecutar;
        TBitBtn *btnCerrar;
    TdxDBGrid *dxDBGrid1;
    TQuery *qsNombre;
    TDataSource *dtsNombre;
    TdxDBGridMaskColumn *dxDBGrid1CODIGO;
    TdxDBGridMaskColumn *dxDBGrid1NOMBRE;
    TdxDBGridMaskColumn *dxDBGrid1DIREC;
    TdxDBGridMaskColumn *dxDBGrid1CIU;
    TdxDBGridMaskColumn *dxDBGrid1RFC;
    TdxDBGridMaskColumn *dxDBGrid1TEL;
    TdxDBGridMaskColumn *dxDBGrid1CARGOS;
    TdxDBGridMaskColumn *dxDBGrid1ABONOS;
    TdxDBGridMaskColumn *dxDBGrid1COMPRAANU;
    TdxDBGridMaskColumn *dxDBGrid1COMPRAMES;
    TdxDBGridMaskColumn *dxDBGrid1PDSC;
    TdxDBGridMaskColumn *dxDBGrid1ULTMOV;
    TdxDBGridMaskColumn *dxDBGrid1STATUS;
    TdxDBGridMaskColumn *dxDBGrid1CIA;
    TdxDBGridMaskColumn *dxDBGrid1NOMPAG1;
    TdxDBGridMaskColumn *dxDBGrid1NOMPAG2;
    TdxDBGridMaskColumn *dxDBGrid1DIRPAG1;
    TdxDBGridMaskColumn *dxDBGrid1DIRPAG2;
    TdxDBGridMaskColumn *dxDBGrid1CIUPAG;
    TdxDBGridMaskColumn *dxDBGrid1NOMBRE2;
    TCheckBox *chkColumnas;
    void __fastcall btnEjecutarClick(TObject *Sender);
    void __fastcall dxDBGrid1DblClick(TObject *Sender);
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall chkColumnasClick(TObject *Sender);
    void __fastcall dxDBGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtNombreKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtClaveKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
    void __fastcall MostrarColumnas(bool bb);
public:		// User declarations
    bool bOk;
    __fastcall TfrmDlgCnsMayoris(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgCnsMayoris *frmDlgCnsMayoris;
//---------------------------------------------------------------------------
#endif
