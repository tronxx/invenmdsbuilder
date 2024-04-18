//---------------------------------------------------------------------------

#ifndef Frm_mantlineaH
#define Frm_mantlineaH
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
class TForm_mantlinea : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *tbtn_nuevo;
        TToolButton *tbtn_modif;
        TToolButton *tbtn_borra;
        TToolButton *ToolButton1;
        TToolButton *ToolButton3;
        TQuery *qry_lineas;
        TUpdateSQL *uqry_lineas;
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
  TToolButton *ToolButton7;
  TToolButton *ToolButton8;
        TQuery *qry_obslinmds;
        TDataSource *dts_obslinmds;
        TQuery *qry_obslinelec;
        TDataSource *dts_obslinelec;
        TUpdateSQL *uqry_obslinmds;
        TUpdateSQL *uqry_obslinelec;
        TAction *agregaobs;
        TAction *borraobs;
        TAction *borratodasobs;
        TDataSource *dts_fonini;
        TDataSource *dts_fonfin;
        TAction *modifren;
        TPanel *Panel2;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TdxEdit *edt_nombre;
        TEdit *edt_ptovta;
        TdxCurrencyEdit *edt_ordlin;
        TdxEdit *edt_region;
        TGroupBox *GroupBox2;
        TPanel *Panel1;
        TPageControl *page_observs;
        TTabSheet *tbs_mds;
        TdxDBGrid *dbgrd_obsmds;
        TdxDBGridMaskColumn *dbgrd_obsmdsORDEN;
        TdxDBGridMaskColumn *dbgrd_obsmdsOBSER;
        TdxDBGridMaskColumn *dbgrd_obsmdsFONINI;
        TdxDBGridMaskColumn *dbgrd_obsmdsFONFIN;
        TdxDBGrid *dxDBGrid1;
        TDataSource *dts_lineas;
        TdxDBGridMaskColumn *dxDBGrid1LINEA;
        TdxDBGridMaskColumn *dxDBGrid1DESCRI;
        TdxDBGridMaskColumn *dxDBGrid1ORDEN;
        TdxDBGridMaskColumn *dxDBGrid1REGION;
        TSplitter *Splitter1;
        TBitBtn *BitBtn1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TQuery *qry_busconse;
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall agregaobsExecute(TObject *Sender);
        void __fastcall borraobsExecute(TObject *Sender);
        void __fastcall dbgrd_obsmdsKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall borratodasobsExecute(TObject *Sender);
        void __fastcall qry_lineasAfterScroll(TDataSet *DataSet);
        void __fastcall modifrenExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantlinea(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt();
        void __fastcall modif_ptvt();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall alta_linea(int modo_z);
        void __fastcall alta_obs(int modo_z);
        int  __fastcall busca_cuantos_conse(String linea_z, int conse_z, String moe_z);


        int cia_z;
        String permis_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantlinea *Form_mantlinea;
//---------------------------------------------------------------------------
#endif
