//---------------------------------------------------------------------------

#ifndef Frm_mantgpoinvH
#define Frm_mantgpoinvH
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
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_mantgpoinv : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TQuery *qry_gpoinv;
        TUpdateSQL *uqry_gpoinv;
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
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TSpeedButton *SpeedButton11;
        TDataSource *dts_gpoinv;
        TAction *exportar;
        TSpeedButton *SpeedButton1;
        TPopupMenu *PopupMenu1;
        TMenuItem *Nuevo1;
        TMenuItem *Borra1;
        TMenuItem *Modifica1;
        TMenuItem *Exportaa1;
        TPageControl *pge_grupos;
        TTabSheet *tbs_grupoartdesp;
        TdxDBGrid *dbgrd_grupos;
        TdxDBGridMaskColumn *dbgrd_gruposCODIGO;
        TdxDBGridMaskColumn *dbgrd_gruposDESCRI;
        TdxDBGridMaskColumn *dbgrd_gruposIMPRI;
        TdxDBGridMaskColumn *dbgrd_gruposCODSAT;
        TdxDBGridMaskColumn *dbgrd_gruposDESCRISAT;
        TTabSheet *tbs_grupointernet;
        TdxDBGrid *dxDBGrid1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn1;
        TdxDBGridMaskColumn *dxDBGridMaskColumn2;
        TQuery *qry_gruposinternet;
        TUpdateSQL *uqry_gruposinternet;
        TDataSource *dts_gruposinternet;
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
        void __fastcall qry_gpoinvAfterScroll(TDataSet *DataSet);
        void __fastcall dbgrd_gruposCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall dbgrd_gruposKeyPress(TObject *Sender, char &Key);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantgpoinv(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt(int modo_z);
        void __fastcall modif_ptvt(String descri_z, bool select_z);
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        int cia_z;
        String permis_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantgpoinv *Form_mantgpoinv;
//---------------------------------------------------------------------------
#endif
