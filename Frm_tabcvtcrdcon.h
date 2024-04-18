//---------------------------------------------------------------------------

#ifndef Frm_tabcvtcrdconH
#define Frm_tabcvtcrdconH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm_tabcvtcrdcon : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnl_datos;
        TdxDBGrid *dbgrd_renglones;
        TQuery *qry_analisma;
        TUpdateSQL *uqry_gpodiary;
        TDataSource *dts_analisma;
        TdxDBGridMaskColumn *dbgrd_renglonesLINEA;
        TdxDBGridMaskColumn *dbgrd_renglonesCODIGO;
        TdxDBGridCurrencyColumn *dbgrd_renglonesTOTCONT;
        TdxDBGridCurrencyColumn *dbgrd_renglonesTOTCRED;
        TdxDBGridCurrencyColumn *dbgrd_renglonesTOTFON;
        TPanel *Panel2;
        TLabel *Label1;
        TDateTimePicker *date_fecini;
        TLabel *Label2;
        TDateTimePicker *date_fecfin;
        TBitBtn *BitBtn1;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
        TActionList *ActionList1;
        TAction *exporta_dbgrd;
        TdxDBGridMaskColumn *dbgrd_renglonesZONA;
        TAction *imprimir;
        TBitBtn *BitBtn2;
        TQuery *qry_buscaventas;
        TQuery *qry_datosventas;
        TdxDBGridCurrencyColumn *dbgrd_renglonestotfide;
        TdxDBGridCurrencyColumn *dbgrd_renglonestotimevi;
        TdxDBGridCurrencyColumn *dbgrd_renglonestotgral;
        TQuery *qry_lineas;
        TMemo *Memo1;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Exportara1Click(TObject *Sender);
        void __fastcall exporta_dbgrdExecute(TObject *Sender);
        void __fastcall dbgrd_renglonesCustomDraw(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxDBTreeListColumn *AColumn, const AnsiString AText,
          TFont *AFont, TColor &AColor, bool ASelected, bool AFocused,
          bool &ADone);
        void __fastcall imprimirExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_tabcvtcrdcon(TComponent* Owner);
        void __fastcall reporte_subtot(double importe_z, String tit_z, String tipo_z);
        void __fastcall report_subencabzona();
        void __fastcall report_subencabvend();
        void __fastcall report_encab();
        void __fastcall generar_reporte();
        String __fastcall busca_dato(String tipodato_z, String clave_z);
        int cia_z, idtarea_z, pagina_z, lineas_z;
        String titulo_z, antvend_z, antzona_z, zona_z, vendedor_z;
        FILE *archout;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_tabcvtcrdcon *Form_tabcvtcrdcon;
//---------------------------------------------------------------------------
#endif
