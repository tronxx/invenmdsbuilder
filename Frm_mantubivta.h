//---------------------------------------------------------------------------

#ifndef Frm_mantubivtaH
#define Frm_mantubivtaH
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
//---------------------------------------------------------------------------
class TForm_mantubivta : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TQuery *qry_situac;
        TUpdateSQL *uqry_marcas;
        TActionList *ActionList1;
        TAction *nuevo;
        TAction *modifica;
        TAction *borra;
        TAction *cancelar;
        TWindowClose *WindowClose1;
        TAction *primero;
        TAction *anterior;
        TAction *siguiente;
        TAction *ultimo;
        TdxDBGrid *dbgrd_ubivta;
        TDataSource *dts_marcas;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton6;
        TdxDBGridMaskColumn *dbgrd_ubivtaALM;
        TdxDBGridMaskColumn *dbgrd_ubivtaPVTA;
        TdxDBGridMaskColumn *dbgrd_ubivtaZONAINV;
        TdxDBGridMaskColumn *dbgrd_ubivtaVOC;
        TdxDBGridMaskColumn *dbgrd_ubivtaZONA2;
        TdxDBGridMaskColumn *dbgrd_ubivtaPTVTA2;
        TdxDBGridMaskColumn *dbgrd_ubivtaZONARTDES;
        TdxDBGridMaskColumn *dbgrd_ubivtaZONAPTVTA;
        TdxDBGridMaskColumn *dbgrd_ubivtaZONACAR;
        TdxDBGridMaskColumn *dbgrd_ubivtaSUBZONCAR;
        TAction *exportar;
        TdxDBGridMaskColumn *dbgrd_ubivtaColumn11;
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall dbgrd_ubivtaCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
        void __fastcall dbgrd_ubivtaKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall exportarExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantubivta(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt(String situacion_z);
        void __fastcall modif_ptvt(String situacion_z);
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall agregar_modificar(int tipo_z);

        int cia_z;
        String permis_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantubivta *Form_mantubivta;
//---------------------------------------------------------------------------
#endif
