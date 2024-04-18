//---------------------------------------------------------------------------

#ifndef Frm_proycomH
#define Frm_proycomH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <stdio.h>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TForm_proycom : public TForm
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *Label2;
        TBitBtn *btn_aceptar;
        TBitBtn *btn_cancelar;
        TDateTimePicker *date_fecfin;
        TDateTimePicker *date_fecini;
        TGroupBox *GroupBox2;
        TRadioButton *rbtn_fona;
        TRadioButton *rbtn_ime;
        TRadioButton *rbtn_menu;
        TRadioButton *rbtn_fide;
        TRadioButton *rbtn_total;
        TQuery *qry_subproycom;
        TQuery *qry_ubivtas;
        TQuery *qry_tabcvta;
        TQuery *qry_tabcvta2;
        TQuery *qry_tipocredi;
        TQuery *qry_proycom;
        TQuery *qry_tipocont;
        TQuery *qry_tipocardet1;
        TQuery *qry_tipocardet2;
        TActionList *ActionList1;
        TAction *reporte_proycom;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall date_feciniExit(TObject *Sender);
        void __fastcall reporte_proycomExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_proycom(TComponent* Owner);
        FILE *archout;
        int lineas_z, pagina_z,cia_z;
        bool salto_z,tip_z ;
        String fona_z,imevi_z,menudeo_z,fide_z,total_z,antzona_z,ptvtaa_z,
        nombrezon_z,zonapy_z,antsubzona_z,subzonpy_z,descripy_z,credit_z,antdescri_z,antdescrisub_z;
        TDateTime fecini_z,fecfin_z;
        double foncredito_z,foncontado_z,vtaime_z,vtafid_z,fidecontado_z,fidecredito_z,
        imecontado_z,imecredito_z,vtacredito_z, vtacontado_z,vtafon_z,proycon_z,
        proycrd_z,proyfon_z,proyfid_z,proyime_z,totimporte_z,totcostos_z,real_z,
        mub_z,costreal_z,subreal_z,subtotconta_z,subtotcred_z,subfona_z,subfide_z,
        subproycon_z,subproycrd_z,subproyfon_z,subproyfid_z,subproyime_z,subtotimporte_z,
        subtotcostos_z,submub_z,totgenconta_z,totgenproycon_z,totgencred_z,totgenproycrd_z,
        totgenfona_z,totgenproyfon_z,totgenfide_z,totgenproyfid_z,costrealfon_z,
         totgenventan_z,totgencostos_z,togentsubmub_z,subtotreal_z ,
         subrelfon_z,subrelfide_z,subrelcyc_z,subrelcont_z,totgenreal_z,
         totgenrelconta_z,totgenrelcred_z,totgenrelfona_z,totgenrelfide_z,totgenreal2_z,
         realcont_z,realcred_z,realfon_z ,realfide_z,costrealcont_z,costrealcyc_z,
         costrealfide_z,totcostoreal_z,subreal2_z,resultado_z,subresultados_z ;
        double porcon_z,porcrd_z,porfon_z,porfid_z,porcel_z,porime_z,totreal3_z;
        void __fastcall report_encab();
        void __fastcall report_zona(String zonapy_z, String nombrezon_z);
        void __fastcall report_subzona(String subzonpy_z, String descripy_z);
        void __fastcall suma_anual(String tipoent_z,String suboglo_z, String menudeo_z,String zona_z, String ptvta_z,bool tip_z);
        void __fastcall total_ventas(double totimporte_z, double totcostos_z, double mub_z,double totcostoreal_z);
        void __fastcall subtotal_ventas(double subtotconta_z, double subtotcred_z,
        double subfona_z,double subfide_z, double subreal_z);
        void __fastcall report_subtotalzona(String zonapy_z, String nombrezon_z);
        void __fastcall encab1();
        void __fastcall total_generales();
        bool __fastcall checa_saltopag(int numero_de_lineas);
        void __fastcall salta_linea();
        void __fastcall genera_reporte();

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_proycom *Form_proycom;
//---------------------------------------------------------------------------
#endif
