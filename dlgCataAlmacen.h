//---------------------------------------------------------------------------

#ifndef dlgCataAlmacenH
#define dlgCataAlmacenH
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
#include <Buttons.hpp>
//---------------------------------------------------------------------------
AnsiString __fastcall CatalogoAlmacenes(TForm *Padre);
//---------------------------------------------------------------------------
class TfrmDlgCataAlmacen : public TForm
{
__published:	// IDE-managed Components
    TdxDBGrid *dxDBGrid1;
    TBitBtn *btnAceptar;
    TBitBtn *btnCerrar;
    TQuery *qsAlmancen;
    TDataSource *dtsAlmacen;
    TdxDBGridMaskColumn *dxDBGrid1CLAVE;
    TdxDBGridMaskColumn *dxDBGrid1NOMBRE;
    void __fastcall btnAceptarClick(TObject *Sender);
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    bool bOk;
    __fastcall TfrmDlgCataAlmacen(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgCataAlmacen *frmDlgCataAlmacen;
//---------------------------------------------------------------------------
#endif
