//----------------------------------------------------------------------------
#ifndef dialg_foliosdispH
#define dialg_foliosdispH
//----------------------------------------------------------------------------
#include <vcl\System.hpp>
#include <vcl\Windows.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Classes.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\ExtCtrls.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxTL.hpp"
#include <Db.hpp>
#include <DBTables.hpp>
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
//----------------------------------------------------------------------------
class Tdlg_foliosdisp : public TForm
{
__published:
        TPanel *Panel1;
        TBitBtn *btn_ok;
        TBitBtn *BitBtn2;
        TQuery *qry_disponibles;
        TDataSource *dts_disponibles;
        TGroupBox *GroupBox2;
        TdxDBGrid *dbgrd_dispo;
        TdxDBGridMaskColumn *dbgrd_dispoALM;
        TdxDBGridMaskColumn *dbgrd_dispoFOLIO;
        TdxDBGridDateColumn *dbgrd_dispoFECHA;
        TdxDBGridMaskColumn *dbgrd_dispoSERIE;
        TdxDBGridMaskColumn *dbgrd_dispoPROVE;
        TdxDBGridMaskColumn *dbgrd_dispoMODENT;
        TdxDBGridMaskColumn *dbgrd_dispoNENTRADA;
        TdxDBGridMaskColumn *dbgrd_dispoENTCAN;
        TdxDBGridMaskColumn *dbgrd_dispoVIENEDE;
        TdxDBGridMaskColumn *dbgrd_dispoFOLVIENE;
        TPanel *pnl_preciovta;
        TdxCurrencyEdit *edt_preciovta;
        TLabel *Label1;
        void __fastcall btn_okClick(TObject *Sender);
private:
public:
	virtual __fastcall Tdlg_foliosdisp(TComponent* AOwner);
        void __fastcall busca_dispo(String codigo_z, int cia_z);

        String alm_z;
        int folio_z;
        double precioventa_z;
};
//----------------------------------------------------------------------------
extern PACKAGE Tdlg_foliosdisp *dlg_foliosdisp;
//----------------------------------------------------------------------------
#endif
