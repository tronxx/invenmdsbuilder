//---------------------------------------------------------------------------

#ifndef Frm_mantzonaH
#define Frm_mantzonaH
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
void __fastcall MantoZonas(TForm *Padre);
//---------------------------------------------------------------------------
class TForm_mantzona : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_zonas;
        TUpdateSQL *uqry_ptovta;
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
        TDataSource *dts_zonas;
        TToolBar *ToolBar1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton5;
        TToolButton *ToolButton3;
        TAction *exportar;
        TPageControl *PageControl1;
        TTabSheet *tbs_zonas;
        TdxDBGrid *dbgrd_zonas;
        TdxDBGridMaskColumn *dbgrd_zonasColumn1;
        TdxDBGridMaskColumn *dbgrd_zonasColumn2;
        TTabSheet *tbs_megazonas;
        TQuery *qry_megazonas;
        TUpdateSQL *UpdateSQL1;
        TDataSource *dts_megazonas;
        TGroupBox *GroupBox1;
        TdxDBGrid *dbgrd_megazonas;
        TdxDBGridMaskColumn *dbgrd_megazonasclave;
        TdxDBGridMaskColumn *dbgrd_megazonasNombre;
        TGroupBox *grp_megazonasdet;
        TdxDBGrid *dbgrd_megazonasdet;
        TdxDBGridMaskColumn *dts_megazonasdetZONA;
        TdxDBGridMaskColumn *dts_megazonasdetNOMBRE;
        TPanel *Panel1;
        TBitBtn *btn_nvoren;
        TBitBtn *BitBtn1;
        TAction *agrega_megazonadet;
        TQuery *qry_megazonasdet;
        TUpdateSQL *uqry_megazonasdet;
        TDataSource *dts_megazonasdet;
        TAction *eliminar_megazonasdet;
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
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall tbs_zonasShow(TObject *Sender);
        void __fastcall tbs_megazonasShow(TObject *Sender);
        void __fastcall agrega_megazonadetExecute(TObject *Sender);
        void __fastcall eliminar_megazonasdetExecute(TObject *Sender);
        void __fastcall qry_megazonasAfterScroll(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantzona(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt();
        void __fastcall modif_ptvt();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
      int cia_z;
    bool bOk;
        String tipo_z, permis_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantzona *Form_mantzona;
//---------------------------------------------------------------------------
#endif
