//---------------------------------------------------------------------------

#ifndef Frm_exispcon2H
#define Frm_exispcon2H
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
class TForm_exispcon2 : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TGroupBox *pnl_datos;
        TLabel *lbl_vigencia;
        TDateTimePicker *date_ini;
        TGroupBox *GroupBox5;
        TRadioButton *rbtn_sipreciomay;
        TRadioButton *rbtn_nopreciomay;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TEdit *edt_almini;
        TGroupBox *GroupBox1;
        TRadioButton *rbtn_mayoristas;
        TRadioButton *rbtn_lzno;
        TGroupBox *GroupBox4;
        TRadioButton *rbtn_exisi;
        TRadioButton *rbtn_exino;
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
        TGroupBox *GroupBox3;
        TLabel *Label2;
        TLabel *Label4;
        TEdit *edt_lineaini;
        TEdit *edt_lineafin;
        TLabel *Label3;
        TDateTimePicker *date_vigencia;
        TRadioButton *rbtn_exitot;
        TQuery *qry_fecorte;
        TBitBtn *btn_imprel;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imprimir_reporteExecute(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall date_iniExit(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm_exispcon2(TComponent* Owner);
        FILE *archout;
        TStringList *sum;
        String almaini_z,almafin_z,almini_z,almfin_z,entcan_z,nocan_z,
        antzona_z,antnomzon_z,arch_z,zonalin_z,nombrelin_z,zona_z,
        tlinea_z,tzona_z,ttipo_z, antlinea_z, linea_z;
        double costosi_z,costono_z,totconstosi_z,totconstono_z,
        gtotunid_z,gtotcost_z,sumcostos_z,porc_z,totsumcostos_z,totienda_z,
        totexisten_z,gtotsumcostos_z,gtotconstono_z ,gtotienda_z ,
        gtotexisten_z,totallinea_z,totline_z,misuma_z,porctot_z,
        gtcostosi_z,gtcostono_z,gtcostos_z,dtotsi_z,dtotno_z,gtporc1_z,
        gtporc2_z,gtporc3_z,gtsumcostos_z,subtotporc_z,ttotal_z,totporc4_z;
        bool tabla1_z,tabla2_z,tabla3_z;
        TDateTime fecha_z, inianu_z;
        int lineas_z, pagina_z,cia_z,cuant_z,puntt_z,sub_z;
        int  __fastcall calcula_maximo();
        void __fastcall genera_reporte();
        void __fastcall tabla_almacen();
        void __fastcall calcula_vigencia();
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
        void __fastcall imprime_renglon();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_exispcon2 *Form_exispcon2;
//---------------------------------------------------------------------------
#endif
