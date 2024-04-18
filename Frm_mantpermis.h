//---------------------------------------------------------------------------

#ifndef Frm_mantpermisH
#define Frm_mantpermisH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_mantpermis : public TForm
{
__published:	// IDE-managed Components
    TPanel *Panel1;
    TLabel *Label1;
    TDBLookupComboBox *lkcmb_codigo;
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
    TToolBar *ToolBar1;
    TToolButton *ToolButton3;
    TPanel *Panel2;
    TdxDBGrid *dbgrd_cuotacel;
        TDBEdit *DBEdit1;
        TUpdateSQL *uqry_proyectos;
        TQuery *qry_proyectos;
        TDataSource *dts_proyectos;
        TQuery *qry_permisiones;
        TUpdateSQL *uqry_permisiones;
        TDataSource *dts_permisiones;
        TQuery *qry_facpermiproyectos;
        TUpdateSQL *uqry_facpermiproyectos;
        TDataSource *dts_facpermiproyectos;
        TdxDBGridMaskColumn *dbgrd_cuotacelColumn1;
        TdxDBGridMaskColumn *dbgrd_cuotacelColumn2;
        TDBGrid *dbgrd_permisiones;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton10;
        TAction *exportar;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
    void __fastcall FormCreate(TObject *Sender);
    void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall dbgrd_cuotacelCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall lkcmb_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall qry_proyectosAfterScroll(TDataSet *DataSet);
        void __fastcall dbgrd_cuotacelKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall exportarExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm_mantpermis(TComponent* Owner);
    void __fastcall botones_onoff(int modo_z);
    void __fastcall nuevo_proyec();
    int idproyecto_z,cia_z;
    String permis_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantpermis *Form_mantpermis;
//---------------------------------------------------------------------------
#endif
