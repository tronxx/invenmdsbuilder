//---------------------------------------------------------------------------

#ifndef Frm_reltablasH
#define Frm_reltablasH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBGrids.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxTL.hpp"
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ToolWin.hpp>
#include <Buttons.hpp>
#include <stdio.h>
#include <StdActns.hpp>
//---------------------------------------------------------------------------
class TForm_reltablas : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_tablas;
        TDataSource *dts_tablas;
        TUpdateSQL *uqry_tablas;
        TGroupBox *GroupBox1;
        TDataSource *dts_reltabla;
        TQuery *qry_relacs;
        TUpdateSQL *uqry_relacs;
        TPanel *Panel1;
        TDataSource *dts_columns;
        TQuery *qry_columns;
        TActionList *ActionList1;
        TAction *nueva_tabla;
        TQuery *qry_ultid;
        TAction *borrar_tabla;
        TPanel *Panel3;
        TdxDBGrid *dbgrd_polizas;
        TdxDBGridMaskColumn *dbgrd_polizasTABLA;
        TdxDBGridMaskColumn *dbgrd_polizasDESCRI;
        TdxDBGridDateColumn *dbgrd_polizasFECHA_CREA;
        TdxDBGridMaskColumn *dbgrd_polizasENDESUSO;
        TGroupBox *GroupBox3;
        TAction *modif_tabla;
        TAction *impri_tabla;
        TdxDBGrid *dxDBGrid1;
        TListBox *list_columnas;
        TToolBar *ToolBar2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton4;
        TToolButton *ToolButton7;
        TSpeedButton *SpeedButton5;
        TSpeedButton *SpeedButton8;
        TToolBar *ToolBar1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TToolButton *ToolButton1;
        TSpeedButton *SpeedButton10;
        TAction *rel_tabla;
        TQuery *qry_max;
        TAction *modif_rel;
        TAction *borrar_rel;
        TAction *impri_rel;
        TQuery *qry_otra;
        TdxDBGridMaskColumn *dxDBGrid1CAMPO;
        TdxDBGridMaskColumn *dxDBGrid1TABLA;
        TdxDBGridMaskColumn *dxDBGrid1CAMPOREL;
        TdxDBGridMaskColumn *dxDBGrid1TIPOREL;
        TdxDBGridMaskColumn *dxDBGrid1DESCRI;
        TdxDBGridMaskColumn *dxDBGrid1OBSERVS;
        TWindowClose *WindowClose1;
        void __fastcall nueva_tablaExecute(TObject *Sender);
        void __fastcall borrar_tablaExecute(TObject *Sender);
        void __fastcall rel_tablaExecute(TObject *Sender);
        void __fastcall modif_relExecute(TObject *Sender);
        void __fastcall borrar_relExecute(TObject *Sender);
        void __fastcall modif_tablaExecute(TObject *Sender);
        void __fastcall qry_tablasAfterScroll(TDataSet *DataSet);
        void __fastcall impri_tablaExecute(TObject *Sender);
        void __fastcall impri_relExecute(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_reltablas(TComponent* Owner);
         FILE *archout;
         int  lineas_z, pagina_z;
         void __fastcall obter_campos();
         bool __fastcall checa_salto_pag(int margen_z);
         void __fastcall report_encab();
         void __fastcall encab1();
         void __fastcall encab_rel();
         void __fastcall encab_tabla(String tabla_z);
         bool impri1_z,impri2_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_reltablas *Form_reltablas;
//---------------------------------------------------------------------------
#endif
