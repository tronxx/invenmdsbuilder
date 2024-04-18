//---------------------------------------------------------------------------

#ifndef Frm_mantoproveH
#define Frm_mantoproveH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include "dxDBELib.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
//---------------------------------------------------------------------------
class TForm_mantoprove : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_prove;
        TUpdateSQL *uqry_clien;
        TToolBar *ToolBar1;
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
        TToolButton *ToolButton2;
  TQuery *qry_ciudades;
  TDataSource *dts_ciudades;
        TQuery *qry_status;
        TDataSource *dts_status;
        TdxDBGrid *dbgrd_proveedores;
        TQuery *qry_most;
        TDataSource *dts_prove;
        TdxDBGridMaskColumn *dbgrd_proveedoresCODIGO;
        TdxDBGridMaskColumn *dbgrd_proveedoresNOMBRE;
        TdxDBGridMaskColumn *dbgrd_proveedoresDIREC;
        TdxDBGridMaskColumn *dbgrd_proveedoresCIU;
        TdxDBGridMaskColumn *dbgrd_proveedoresRFC;
        TdxDBGridMaskColumn *dbgrd_proveedoresTEL;
        TdxDBGridMaskColumn *dbgrd_proveedoresCARGOS;
        TdxDBGridMaskColumn *dbgrd_proveedoresABONOS;
        TdxDBGridMaskColumn *dbgrd_proveedoresCOMPRAANU;
        TdxDBGridMaskColumn *dbgrd_proveedoresCOMPRAMES;
        TdxDBGridMaskColumn *dbgrd_proveedoresLIMITE;
        TdxDBGridMaskColumn *dbgrd_proveedoresCONTACTO;
        TdxDBGridMaskColumn *dbgrd_proveedoresULTMOV;
        TdxDBGridMaskColumn *dbgrd_proveedoresSTATUS;
        TdxDBGridMaskColumn *dbgrd_proveedoresCIA;
        TUpdateSQL *uqry_prove;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TAction *exportar;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall dbgrd_proveedoresCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall dbgrd_proveedoresKeyDown(TObject *Sender,
          WORD &Key, TShiftState Shift);
        void __fastcall dbgrd_proveedoresDblClick(TObject *Sender);
        void __fastcall exportarExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantoprove(TComponent* Owner);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall busca_vnd(String vnd_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall desp_vnd();
        int __fastcall busca_iddato(String text_z, int tipodato_z);
        void __fastcall desp_ptvt();
        void __fastcall alta_o_modif(int modo_z);

        int cia_z;
        String permis_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantoprove *Form_mantoprove;
//---------------------------------------------------------------------------
#endif
