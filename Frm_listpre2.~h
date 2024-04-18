//---------------------------------------------------------------------------

#ifndef Frm_listpre2H
#define Frm_listpre2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <stdio.h>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DBCtrls.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_listpre2 : public TForm
{
__published:	// IDE-managed Components
        TPanel *pnl_datos;
        TdxDBGrid *dbgrd_renglones;
        TQuery *qry_delete;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TdxDBGridMaskColumn *dbgrd_renglonesCODIGO;
        TdxDBGridMaskColumn *dbgrd_renglonesDESCRI;
        TdxDBGridMaskColumn *dbgrd_renglonesCOSTOS;
        TdxDBGridMaskColumn *dbgrd_renglonesLINEA;
        TdxDBGridMaskColumn *dbgrd_renglonesPIVA;
        TdxDBGridMaskColumn *dbgrd_renglonesPRECIO;
        TdxDBGridMaskColumn *dbgrd_renglonesEMPAQE;
        TdxDBGridMaskColumn *dbgrd_renglonesORDEN;
        TdxDBGridMaskColumn *dbgrd_renglonesGRUPO;
        TQuery *qry_inventmp;
        TUpdateSQL *uqry_inventmp;
        TQuery *qry_invorden;
        TQuery *qry_exist;
        TQuery *qry_plazmax;
        TQuery *qry_idart;
        TQuery *qry_linea;
        TQuery *qry_obs;
        TDataSource *dts_lineas;
        TQuery *qry_remates;
        TDataSource *dts_remates;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
        TPanel *Panel1;
        TGroupBox *GroupBox2;
        TLabel *lbl_linea;
        TLabel *lbl_linea2;
        TDBLookupComboBox *lkcmb_lineaini;
        TDBLookupComboBox *lkcmb_lineafin;
        TGroupBox *GroupBox3;
        TLabel *Label3;
        TLabel *Label1;
        TRadioButton *rbtn_mesta;
        TRadioButton *rbtn_estas;
        TDBLookupComboBox *lkcmb_rematfin;
        TDBLookupComboBox *lkcmb_rematini;
        TGroupBox *GroupBox4;
        TRadioButton *rbtn_cost;
        TRadioButton *rbtn_scost;
        TPanel *Panel2;
        TGroupBox *grp_fecha;
        TLabel *lbl_vigencia;
        TLabel *lbl_corte;
        TDateTimePicker *date_vigencia;
        TDateTimePicker *date_corte;
        TGroupBox *GroupBox6;
        TLabel *Label2;
        TLabel *Label4;
        TEdit *edt_codini;
        TEdit *edt_codfin;
        TGroupBox *GroupBox7;
        TCheckBox *ckb_obser;
        TCheckBox *ckb_salto;
        TBitBtn *btn_imprel;
        TGroupBox *GroupBox8;
        TRadioButton *rbtn_cprec;
        TRadioButton *rbtn_sprec;
        TGroupBox *GroupBox5;
        TRadioButton *rbtn_mds;
        TRadioButton *rbtn_electro;
        TRadioButton *rbtn_ambos;
        TActionList *ActionList2;
        TAction *imprimir_lista;
        TAction *exportar;
        TQuery *qry_garantia;
        TQuery *qry_caracteristicas;
        TQuery *qry_xtensa;
        TQuery *qry_buscaidart;
        TQuery *qry_plazoxarticulo;
        TQuery *qry_plazoxgrupo;
        TQuery *qry_plazoxlin;
        TQuery *qry_plazoxprecio;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall imprimir_listaExecute(TObject *Sender);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall dbgrd_renglonesCustomDraw(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxDBTreeListColumn *AColumn, const AnsiString AText,
          TFont *AFont, TColor &AColor, bool ASelected, bool AFocused,
          bool &ADone);
private:	// User declarations
public:		// User declarations
        FILE *archout;
        String lineaini_z,linea_z,sql_z,moe_z,antlineatmp_z,antnombrelinea_z;
        int lineas_z, pagina_z, cia_z,plazoxpr_z;
        __fastcall TForm_listpre2(TComponent* Owner);
        void __fastcall report_encab();
        void __fastcall encab_linea(String antlineatmp_z, String antnombrelinea_z);
        void __fastcall agregar_datos();
        void __fastcall encab2();
        void __fastcall imprimir_renglon(String descritmp_z, String clavegrt_z,
                double preciolta_z, int plazoxpr_z, String empaqetmp_z,
                double costoneto_z, double mub_z, String caractetist_z,
                double preciotmp_z, String conext_z);
       void __fastcall impri_obs(String antlineatmp_z);
       void __fastcall encab_obser();
       bool __fastcall checa_salto_pag(int margen_z);
       void __fastcall leer_o_grabar_ini(String accion_z);
       int __fastcall busca_plazo(String codigo_z, String linea_z, String grupo_z, double precio_z);

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_listpre2 *Form_listpre2;
//---------------------------------------------------------------------------
#endif
