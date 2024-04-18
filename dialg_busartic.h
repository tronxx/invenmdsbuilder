//---------------------------------------------------------------------------

#ifndef dialg_busarticH
#define dialg_busarticH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <Buttons.hpp>
#include <DBCtrls.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ExtCtrls.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
//---------------------------------------------------------------------------
class Tdlg_busartic : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TPanel *pnl_articulo;
        TLabel *Label1;
        TEdit *edt_codigo;
        TLabel *Label2;
        TEdit *edt_descri;
        TdxDBGrid *dbgrd_inven;
        TPanel *Panel2;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TdxDBGridMaskColumn *dbgrd_invenCODIGO;
        TdxDBGridMaskColumn *dbgrd_invenDESCRI;
        TdxDBGridMaskColumn *dbgrd_invenEMPAQE;
        TdxDBGridMaskColumn *dbgrd_invenPIVA;
        TdxDBGridCurrencyColumn *dbgrd_invenPRECIO;
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall edt_descriKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall qry_invenAfterScroll(TDataSet *DataSet);
        void __fastcall dbgrd_invenKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall Tdlg_busartic(TComponent* Owner);
        void __fastcall busca_artic(String codigo_z, String descri_z);
        void __fastcall despliega_cambios_precios();
        int cia_z, eximin_z, eximax_z;


};
//---------------------------------------------------------------------------
extern PACKAGE Tdlg_busartic *dlg_busartic;
//---------------------------------------------------------------------------
#endif
