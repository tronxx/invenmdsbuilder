//---------------------------------------------------------------------------

#ifndef Frm_mantotiposentregaH
#define Frm_mantotiposentregaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include "dxExEdtr.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TForm_mantotiposentrega : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TQuery *qry_promot;
        TActionList *ActionList1;
        TAction *nuevo;
        TAction *modifica;
        TAction *borra;
        TAction *grabar;
        TAction *cancelar;
        TWindowClose *WindowClose1;
        TAction *primero;
        TAction *anterior;
        TAction *siguiente;
        TAction *ultimo;
        TPanel *Panel1;
        TLabel *Label2;
        TdxEdit *edt_nombre;
        TDataSource *dts_cajeras;
        TdxDBGrid *dxDBGrid1;
        TdxDBGridMaskColumn *dxDBGrid1Column1;
        TdxDBGridMaskColumn *dxDBGrid1Column2;
        TLabel *Label1;
        TEdit *edt_cajera;
        TUpdateSQL *uqry_promot;
        TQuery *qry_vndptovta;
        TUpdateSQL *uqry_vndptovta;
        TQuery *qry_zonas;
        TDataSource *dts_zonas;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall qry_promotAfterScroll(TDataSet *DataSet);
        void __fastcall dxDBGrid1CustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall dxDBGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantotiposentrega(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt(String codigo_z, String nombre_z);
        void __fastcall modif_ptvt(String nombre_z);
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        int cia_z, tiporel_z;
        String permis_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantotiposentrega *Form_mantotiposentrega;
//---------------------------------------------------------------------------
#endif
