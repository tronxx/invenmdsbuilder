//---------------------------------------------------------------------------

#ifndef Frm_analientH
#define Frm_analientH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <stdio.h>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <ActnList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_analient : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TGroupBox *pnl_datos;
        TLabel *lbl_vigencia;
        TLabel *lbl_corte;
        TDateTimePicker *date_ini;
        TDateTimePicker *date_fin;
        TBitBtn *BitBtn1;
        TdxDBGrid *dbgrd_renglones;
        TQuery *qry_min;
        TQuery *qry_max;
        TQuery *qry_datos;
        TQuery *qry_unid;
        TDataSource *dts_datos;
        TdxDBGridMaskColumn *dbgrd_renglonesPROVE;
        TdxDBGridMaskColumn *dbgrd_renglonesDESCRI;
        TdxDBGridMaskColumn *dbgrd_renglonesCOSTON;
        TdxDBGridDateColumn *dbgrd_renglonesFECHA;
        TdxDBGridMaskColumn *dbgrd_renglonesNUMERO;
        TActionList *ActionList1;
        TAction *exportar;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
        TAction *imprir_reporte;
        TdxDBGridMaskColumn *dbgrd_renglonesCODIGO;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall imprir_reporteExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_analient(TComponent* Owner);
        void __fastcall define_tiporeporte(String tiporep_z);

        FILE *archout;
        TDateTime fecini_z,fecfin_z;
        String mitiporep_z, tpent_z, antprover_z, antnomb_z,
          proveedor_z, nombreprov_z;
        int min_z,max_z,lineas_z, pagina_z,cia_z ;
        double totprov_z,gtotprov_z;
        void __fastcall report_encab();
        void __fastcall encab();
        void __fastcall encab_punto(String prove_z, String nombre_z);
        void __fastcall maxymin();
        void __fastcall imprimir_datos();
        bool __fastcall checa_salto_pag(int margen_z);
        void __fastcall total_punto();
        void __fastcall total_todosprover();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_analient *Form_analient;
//---------------------------------------------------------------------------
#endif
