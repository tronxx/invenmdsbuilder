//---------------------------------------------------------------------------

#ifndef Frm_exiubiH
#define Frm_exiubiH
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
//---------------------------------------------------------------------------
class TForm_exiubi : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TBitBtn *btn_imprel;
        TGroupBox *pnl_datos;
        TLabel *lbl_vigencia;
        TDateTimePicker *date_ini;
        TGroupBox *GroupBox4;
        TRadioButton *rbtn_sitsi;
        TRadioButton *rbtn_sitno;
        TGroupBox *GroupBox5;
        TRadioButton *rbtn_cancelados;
        TRadioButton *rbtn_nocancel;
        TRadioButton *rbtn_todos;
        TLabel *Label2;
        TGroupBox *GroupBox2;
        TEdit *edt_almini;
        TEdit *edt_almfin;
        TLabel *Label1;
        TLabel *Label3;
        TGroupBox *GroupBox3;
        TRadioButton *rbtn_exisi;
        TRadioButton *rbtn_exino;
        TRadioButton *rbtn_exitot;
        TGroupBox *GroupBox6;
        TRadioButton *rbtn_ccosto;
        TRadioButton *rbtn_scosto;
        TGroupBox *GroupBox7;
        TRadioButton *rbtn_imptod;
        TRadioButton *rbtn_impcostc;
        TGroupBox *GroupBox1;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *edt_lineini;
        TEdit *edt_linefin;
        TGroupBox *GroupBox9;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *edt_provini;
        TEdit *edt_provfin;
        TGroupBox *GroupBox8;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *edt_sitini;
        TEdit *edt_sitfin;
        TQuery *qry_agrepuntos;
        TQuery *qry_puntos;
        TQuery *qry_lineas;
        TQuery *qry_inven;
        TQuery *qry_armar;
        TQuery *qry_invulcos;
        TQuery *qry_exists;
        void __fastcall btn_imprelClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_exiubi(TComponent* Owner);
        FILE *archout;
        TStringList *sum;
        TStringList *total;
        bool si_z,no_z;
        int lineas_z, pagina_z,cia_z,puntt_z,cuant_z,ii_z,exitsi_z,exitno_z;
        String drv_z,dad_z,can_z,tit1_z,almini_z,almfin_z,arch_z,ptvta_z,tpunto_z,
        moden_z,codigo_z,entcan_z,antlinea_z,antdescrip_z;
        double totunid_z,totcost_z,misuma_z,misuma2_z,gtotunid_z, gtotcost_z,
        totalunid_z,unidades_z,ggtotcost_z,ggtotunid_z,costosi_z,costono_z,piva_z;
        TDateTime fecha_z,gtotresult_z;
        void __fastcall report_encab();
        void __fastcall mensajes();
        void __fastcall encab_linea();
         void __fastcall encab2();
         void __fastcall sumar_exits();
         void __fastcall armar();
         void __fastcall total_linea();
         bool __fastcall checa_saltopag(int numero_de_lineas);
         void __fastcall costos_sino(String codigo);
         void __fastcall total_gen();
         void __fastcall buscar_exits();
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_exiubi *Form_exiubi;
//---------------------------------------------------------------------------
#endif
