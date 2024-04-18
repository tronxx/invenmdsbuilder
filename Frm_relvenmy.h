//---------------------------------------------------------------------------

#ifndef Frm_relvenmyH
#define Frm_relvenmyH
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
class TForm_relvenmy : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TGroupBox *pnl_datos;
        TLabel *lbl_vigencia;
        TDateTimePicker *date_corte;
        TGroupBox *GroupBox5;
        TRadioButton *rbtn_sipreciomay;
        TRadioButton *rbtn_nopreciomay;
        TGroupBox *GroupBox2;
        TLabel *Label1;
        TEdit *edt_almini;
        TGroupBox *GroupBox4;
        TRadioButton *rbtn_exisi;
        TRadioButton *rbtn_exino;
        TQuery *qry_almacen;
        TQuery *qry_exisi;
        TQuery *qry_lineas;
        TQuery *qry_costlinea;
        TQuery *qry_updtedomay;
        TQuery *qry_mubmay;
        TQuery *qry_armzon;
        TQuery *qry_costzon;
        TQuery *qry_edomay;
        TQuery *qry_mayoristas;
        TActionList *ActionList1;
        TAction *imprimir_reporte;
        TLabel *Label3;
        TDateTimePicker *date_fecini;
        TRadioButton *rbtn_exitot;
        TQuery *qry_perioxmay;
        TQuery *qry_doctospend;
        TUpdateSQL *uqry_perioxmay;
        TQuery *qry_abonos;
        TUpdateSQL *uqry_updtedomay;
        TQuery *qry_saldos;
        TLabel *Label5;
        TDateTimePicker *date_fecfin;
        TLabel *Label2;
        TEdit *edt_mayoini;
        TEdit *edt_mayofin;
        TLabel *Label4;
        TBitBtn *btn_imprel;
        TGroupBox *GroupBox1;
        TCheckBox *chk_relvigtes;
        TCheckBox *chk_tablasem;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall imprimir_reporteExecute(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall date_corteExit(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm_relvenmy(TComponent* Owner);
        FILE *archout;
        TStringList *sumas_z;
        String antven_z, antmayoris_z, mayoris_z, subenc_z;
              TDateTime fecha_z, inianu_z;
        double saldototal_z, importotal_z, importvenc_z, saldovenc_z;

        int lineas_z, pagina_z,cia_z,cuant_z,puntt_z;
        void __fastcall genera_reporte();
        void __fastcall calcula_vigencia();
        void __fastcall report_encab();

        void __fastcall encab2();
        void __fastcall total_zona();
        void __fastcall total_genzona();
        bool __fastcall checa_saltopag(int numero_de_lineas);
        bool __fastcall checa_iniciopag();
        void __fastcall salto_pagina();


        void __fastcall encab_mub_may();
        void __fastcall imprime_ren_mubmay(String modo_z);
        void __fastcall imprime_ulin_mubmay(String modo_z,
                double salmay_z, double facmay_z, double notcred_z);

        void __fastcall mub_mayoreo();
        void __fastcall Subtotales_porc(String tlinea_z);
        void __fastcall reporte_vigtes_may();
        void __fastcall imprime_doctopend();
        void __fastcall encab_mayoris ( String antmayoris_z, String antnombre_z );
        void __fastcall genera_reporte_vigtes();
        void __fastcall encab_tabla_venctos_x_mayorista();
        void __fastcall imprime_totalmay();
        void __fastcall encab_total_vigentes_x_meses();
        void __fastcall edo_res_mayoreo();
        void __fastcall imprime_ren_edoresmay();
        void __fastcall imprime_ulin_edoresmay();
        void __fastcall encab_edo_may();
        void __fastcall subenc_analiabonos();
        void __fastcall analitico_abonos();
        void __fastcall subtotal_abonos_mayoreo(String mayoris_z, double efectivo_z,
          double bonifi_z, double devol_z);
        void __fastcall imprime_ren_analiabonos();
        void __fastcall ulin_fecha_venctos();
        void __fastcall subtotal_fecha_venctos();
        void __fastcall graba_edomay(String mayoris_z,
          double efectivo_z, double bonifi_z, double devol_z, String modo_z);
        void __fastcall analitico_cargos();
        void __fastcall subenc_analicargos();
        void __fastcall imprime_ren_analicargos();
        void __fastcall subtotal_cargos_mayoreo(String mayoris_z,
          double efectivo_z, double bonifi_z, double devol_z);
        void __fastcall subenc_venctos();
        void __fastcall tabla_venctos_x_mayorista();
        void __fastcall tabla_venctos_semanal();
        void __fastcall encab_tabla_semanal_venctos_x_mayorista();
        void __fastcall imprime_ren_tabla_semamal(String modo_z);



};
//---------------------------------------------------------------------------
extern PACKAGE TForm_relvenmy *Form_relvenmy;
//---------------------------------------------------------------------------
#endif
