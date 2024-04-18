//---------------------------------------------------------------------------

#ifndef Frm_mantovndH
#define Frm_mantovndH

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
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_mantovnd : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TQuery *qry_cajeras;
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
        TDataSource *dts_cajeras;
        TdxDBGrid *dbgrd_vendedores;
        TdxDBGridMaskColumn *dbgrd_vendedoresColumn1;
        TdxDBGridMaskColumn *dbgrd_vendedoresColumn2;
        TUpdateSQL *uqry_cajeras;
        TQuery *qry_vndptovta;
        TUpdateSQL *uqry_vndptovta;
        TQuery *qry_ptovta;
        TDataSource *dts_ptovta;
        TdxDBGridColumn *dbgrd_vendedoresColumn3;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TAction *expotar;
        TToolButton *ToolButton1;
        TPopupMenu *PopupMenu1;
        TMenuItem *Modifica1;
        TMenuItem *Borra1;
        TMenuItem *Nuevo1;
        TMenuItem *Exportara1;
        TdxDBGridMaskColumn *dbgrd_vendedoresColumn4;
        TdxDBGridMaskColumn *dbgrd_vendedoresColumn5;
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
        void __fastcall dbgrd_vendedoresCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall dbgrd_vendedoresKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall expotarExecute(TObject *Sender);
        void __fastcall dbgrd_vendedoresDblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantovnd(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_vnd(int modo_z);
        void __fastcall alta_ptvt(String vnd_z, String nombre_z, String zona_z, String status_z, double fecbaj_z, int modo_z);
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        int cia_z, tiporel_z;
        String permis_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantovnd *Form_mantovnd;
//---------------------------------------------------------------------------
#endif
