//---------------------------------------------------------------------------

#ifndef Frm_exicanH
#define Frm_exicanH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <stdio.h>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TForm_exican : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TBitBtn *btn_imprel;
        TGroupBox *pnl_datos;
        TLabel *lbl_vigencia;
        TDateTimePicker *date_ini;
        TGroupBox *GroupBox5;
        TRadioButton *rbtn_cancelados;
        TRadioButton *rbtn_nocancel;
        TRadioButton *rbtn_todos;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TLabel *Label3;
        TEdit *edt_almini;
        TEdit *edt_almfin;
        TGroupBox *GroupBox3;
        TRadioButton *rbtn_lasi;
        TRadioButton *rbtn_lano;
        TGroupBox *GroupBox1;
        TRadioButton *rbtn_lzsi;
        TRadioButton *rbtn_lzno;
        TGroupBox *GroupBox4;
        TRadioButton *rbtn_lgsi;
        TRadioButton *rbtn_lgno;
        TQuery *qry_almacen;
        TQuery *qry_exisi;
        TQuery *qry_lineas;
        TQuery *qry_costlinea;
        TQuery *qry_almzona;
        TQuery *qry_zonas;
        TQuery *qry_armzon;
        TQuery *qry_costzon;
        TQuery *qry_zon;
        TQuery *qry_desglose;
        TQuery *qry_gendesg;
        TActionList *ActionList1;
        TAction *imprimir_reporte;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imprimir_reporteExecute(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_exican(TComponent* Owner);
        FILE *archout;
        TStringList *sum;
        String almaini_z,almafin_z,almini_z,almfin_z,entcan_z,nocan_z,
        antzona_z,antnomzon_z,arch_z,zonalin_z,nombrelin_z,zona_z,
        tlinea_z,tzona_z,ttipo_z;
        double costosi_z,costono_z,totconstosi_z,totconstono_z,
        gtotunid_z,gtotcost_z,sumcostos_z,porc_z,totsumcostos_z,totienda_z,
        totexisten_z,gtotsumcostos_z,gtotconstono_z ,gtotienda_z ,
        gtotexisten_z,totallinea_z,totline_z,misuma_z,porctot_z,
        gtcostosi_z,gtcostono_z,gtcostos_z,dtotsi_z,dtotno_z,gtporc1_z,
        gtporc2_z,gtporc3_z,gtsumcostos_z,subtotporc_z,ttotal_z,totporc4_z;
        bool tabla1_z,tabla2_z,tabla3_z;
        TDateTime fecha_z;
        int lineas_z, pagina_z,cia_z,cuant_z,puntt_z,sub_z;
        void __fastcall tabla_almacen();
        void __fastcall report_encab();
        void __fastcall encab_linea( String antzona_z, String antnomzon_z );
        void __fastcall encab2();
        void __fastcall total_zona();
        void __fastcall total_genzona();
        bool __fastcall checa_saltopag(int numero_de_lineas);
        void __fastcall encab_alm(String zona_z);
        void __fastcall tabla_lineas();
        void __fastcall total_linea();
        void __fastcall tabla_lineas_final();
        void __fastcall encab_alm_tabla2();
        void __fastcall total_linea_tabla();
        void __fastcall tabla_linea_global();
        void __fastcall encab_tabla3();
        void __fastcall encab3_tabla3();
        void __fastcall desglose_total_gen();
        void __fastcall total_global_tabla();
        void __fastcall Subtotales_porc(String tlinea_z);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_exican *Form_exican;
//---------------------------------------------------------------------------
#endif
