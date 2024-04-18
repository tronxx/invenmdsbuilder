//---------------------------------------------------------------------------


#ifndef Frme_datosrenpolcobmaH
#define Frme_datosrenpolcobmaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include "dxCntner.hpp"
#include "dxDBELib.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxTL.hpp"
//---------------------------------------------------------------------------
class TFrame_datosrenpolcobma : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TDBLookupComboBox *lkcmb_mayoris;
        TDBEdit *DBEdit1;
        TLabel *Label2;
        TDBEdit *DBEdit2;
        TLabel *Label3;
        TdxDBCurrencyEdit *edt_letra;
        TLabel *Label4;
        TComboBox *cmb_tipopago;
        TLabel *Label5;
        TEdit *edt_concepto;
        TLabel *Label6;
        TDBEdit *DBEdit4;
        TLabel *Label7;
        TdxCurrencyEdit *edt_importe;
        TQuery *qry_mayoris;
        TDataSource *dts_mayoris;
        TDataSource *dts_facturas;
        TQuery *qry_facturas;
        TdxDBCurrencyEdit *dxDBCurrencyEdit2;
        TLabel *Label9;
        TLabel *Label8;
        TdxDBCurrencyEdit *db_edit;
        TLabel *Label10;
        TDBEdit *DBEdit3;
        TLabel *Label11;
        TEdit *edt_referencia;
        TdxDBGrid *dbgrd_facturas;
        TdxDBGridMaskColumn *dbgrd_facturasFactura;
        TdxDBGridMaskColumn *dbgrd_facturasPAGARE;
        TdxDBGridDateColumn *dbgrd_facturasFECHA;
        TdxDBGridCurrencyColumn *dbgrd_facturasIMPORTE;
        TdxDBGridMaskColumn *dbgrd_facturasVENCE;
        TdxDBGridCurrencyColumn *dbgrd_facturasSALDO;
        TdxDBCurrencyEdit *dxDBCurrencyEdit1;
        void __fastcall lkcmb_mayorisExit(TObject *Sender);
        void __fastcall qry_facturasAfterScroll(TDataSet *DataSet);
        void __fastcall edt_importeExit(TObject *Sender);
        void __fastcall dbgrd_facturasCustomDraw(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxDBTreeListColumn *AColumn, const AnsiString AText,
          TFont *AFont, TColor &AColor, bool ASelected, bool AFocused,
          bool &ADone);
        void __fastcall lkcmb_mayorisEnter(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosrenpolcobma(TComponent* Owner);
        void __fastcall inicializa();

        int cia_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosrenpolcobma *Frame_datosrenpolcobma;
//---------------------------------------------------------------------------
#endif
