//---------------------------------------------------------------------------

#ifndef Frm_consupolcobmayoH
#define Frm_consupolcobmayoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxTL.hpp"
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <StdActns.hpp>
#include <stdio.h>
#include "dxDBELib.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Menus.hpp>
//#include "dxmdaset.hpp"
//---------------------------------------------------------------------------
void __fastcall ConsPolCobMayoristas(TForm *Padre);
//---------------------------------------------------------------------------
class TForm_ConsPolCobMay : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_polizas;
        TDataSource *dts_polizas;
        TQuery *qry_renpolco;
    TDataSource *dtsRenpolco;
        TQuery *qsPolCob;
        TActionList *ActionList2;
        TPanel *Panel1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TPanel *Panel2;
        TGroupBox *GroupBox1;
        TdxDBGrid *dbgrd_Polizas;
        TdxDBGridMaskColumn *dbgrd_PolizasALM;
        TdxDBGridMaskColumn *dbgrd_PolizasFOLIO;
        TdxDBGridDateColumn *dbgrd_PolizasFECHA;
        TdxDBGridCurrencyColumn *dbgrd_PolizasIMPORTE;
        TdxDBGridMaskColumn *dbgrd_PolizasSTATUS;
        TdxDBGridMaskColumn *dbgrd_PolizasSESTADO;
        TdxDBGridMaskColumn *dbgrd_PolizasUSUARIO;
        TdxDBGridMaskColumn *dbgrd_PolizasCIA;
        TPanel *Panel3;
        TLabel *Label1;
        TLabel *Label2;
        TDateTimePicker *dtFechaIni;
        TDateTimePicker *dtFechaFin;
        TGroupBox *GroupBox2;
        TPanel *Panel4;
        TLabel *Label3;
        TEdit *edt_conceppol;
        TdxDBGrid *dbgrdRenpolco;
        TdxDBGridMaskColumn *dbgrdRenpolcoCLIENTE;
        TdxDBGridMaskColumn *dbgrdRenpolcoNOMBRE;
        TdxDBGridMaskColumn *dbgrdRenpolcoALM;
        TdxDBGridDateColumn *dbgrdRenpolcoFECHA;
        TdxDBGridMaskColumn *dbgrdRenpolcoNUMREN;
        TdxDBGridMaskColumn *dbgrdRenpolcoDOCTO;
        TdxDBGridMaskColumn *dbgrdRenpolcoLETRA;
        TdxDBGridMaskColumn *dbgrdRenpolcoREFER;
        TdxDBGridMaskColumn *dbgrdRenpolcoCONCEP;
        TdxDBGridCurrencyColumn *dbgrdRenpolcoIMPORTE;
        TdxDBGridMaskColumn *dbgrdRenpolcoTIPAGO;
        TdxDBGridColumn *dbgrdRenpolcoSSTATUS;
        TAction *nvapol;
        TAction *consult;
        TAction *Elimina;
        TAction *Imp;
        TAction *exportar;
        TAction *cerrar;
        TWindowClose *WindowClose1;
        TAction *buscar;
        TQuery *qry_poliza;
        TUpdateSQL *uqry_polizas;
        TPanel *Panel5;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TAction *agrega_renglon;
        TAction *elimreglon;
        TAction *imprrenglon;
        TQuery *qsSigConseMov;
        TQuery *qry_movmay;
        TQuery *qry_numren;
        TUpdateSQL *uqry_renpolco;
        TQuery *qiMovMay;
        TQuery *quMovPendPag;
        TQuery *qry_facturas;
        TUpdateSQL *uqry_facturas;
        TQuery *qry_fechavenc;
        TSpeedButton *SpeedButton11;
        TLabel *Label4;
        TDBEdit *DBEdit1;
        TLabel *Label5;
        TLabel *Label6;
        TdxDBCurrencyEdit *dxDBCurrencyEdit1;
        TdxDBCurrencyEdit *dxDBCurrencyEdit2;
        TAction *despliega_menu;
        TPopupMenu *pop_menuren;
        TMenuItem *Polizas1;
        TMenuItem *Renglones1;
        TMenuItem *NvaPoliza1;
        TMenuItem *Borrar1;
        TMenuItem *Imprimir1;
        TMenuItem *CerrarPl1;
        TMenuItem *Agregar1;
        TMenuItem *Exportara1;
        TMenuItem *Borrar2;
        TBitBtn *BitBtn1;
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall qry_polizasAfterScroll(TDataSet *DataSet);
        void __fastcall buscarExecute(TObject *Sender);
        void __fastcall consultExecute(TObject *Sender);
        void __fastcall EliminaExecute(TObject *Sender);
        void __fastcall ImpExecute(TObject *Sender);
        void __fastcall cerrarExecute(TObject *Sender);
        void __fastcall nvapolExecute(TObject *Sender);
        void __fastcall agrega_renglonExecute(TObject *Sender);
        void __fastcall elimreglonExecute(TObject *Sender);
        void __fastcall imprrenglonExecute(TObject *Sender);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall dbgrdRenpolcoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgrdRenpolcoCustomDraw(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxDBTreeListColumn *AColumn, const AnsiString AText,
          TFont *AFont, TColor &AColor, bool ASelected, bool AFocused,
          bool &ADone);
private:	// User declarations
    void __fastcall MostrarPolizas();
    
public:		// User declarations
    __fastcall TForm_ConsPolCobMay(TComponent* Owner);
    FILE *archout;
    int  lineas_z, pagina_z;
    void __fastcall muestra_renpolco();
    bool __fastcall AgregarPoliza(String alm_z, int folio_z, TDateTime fecha_z, String concepto_z);
    void __fastcall agregar_pago(
    String mayoris_z, String concepto_z, String refer_z, double importe_z,
    int idmovafecta_z, String tip_z, int letra_z);
    void __fastcall ModificarSaldoMov(double fImporte, String sCveMay, int iDocto, int iPagare, TDateTime fecha_z);
    void __fastcall DesplegarRenglon();
    void __fastcall ModificarImporte( double importe_z, int modif_z);
    void __fastcall ModificarFactura( double importe_z, int docto_z, int letra_z, String cliente_z);
    void __fastcall encab1();
    void __fastcall report_encab();
    bool __fastcall checa_salto_pag(int margen_z);
    void __fastcall datosencab(int doc_z , TDateTime fec_z, String usuario_z, String concep_z, String cliente_z, String nombre_z);
    void __fastcall totales( double bonif_z ,double devol_z ,double efect_z ,double total_z );
    int cia_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_ConsPolCobMay *Form_ConsPolCobMay;
//---------------------------------------------------------------------------
#endif
