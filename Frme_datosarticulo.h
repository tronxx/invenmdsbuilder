//---------------------------------------------------------------------------


#ifndef Frme_datosarticuloH
#define Frme_datosarticuloH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include "Frm_consuinv.h"
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datosarticulo : public TFrame
{
__published:	// IDE-managed Components
        TLabel *etiqcodigo;
        TEdit *edt_codigo;
        TLabel *lbl_nombre;
        TDBLookupComboBox *lkcmb_linea;
        TLabel *Label1;
        TDBLookupComboBox *lkcmb_grupo;
        TLabel *Label2;
        TDBLookupComboBox *lkcmb_prove;
        TLabel *Label3;
        TDBLookupComboBox *lkcmb_diary;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *edt_alta;
        TdxCurrencyEdit *edt_costosi;
        TLabel *lbl_prvta;
        TLabel *Label6;
        TdxCurrencyEdit *edt_costono;
        TLabel *Label7;
        TdxCurrencyEdit *edt_preciomds;
        TLabel *Label8;
        TdxCurrencyEdit *edt_precelec;
        TLabel *Label9;
        TdxCurrencyEdit *edt_costocext;
        TLabel *Label10;
        TdxCurrencyEdit *edt_prvtacext;
        TLabel *Label11;
        TdxCurrencyEdit *edt_mubmds;
        TdxCurrencyEdit *edt_mubelec;
        TLabel *Label12;
        TdxCurrencyEdit *edt_mubcext;
        TLabel *Label13;
        TdxCurrencyEdit *edt_minimo;
        TLabel *Label14;
        TLabel *Label15;
        TdxCurrencyEdit *edt_maximo;
        TLabel *Label16;
        TLabel *Label17;
        TdxCurrencyEdit *edt_piva;
        TEdit *edt_plazo;
        TLabel *Label18;
        TLabel *Label19;
        TDBLookupComboBox *lkcmb_situacion;
        TLabel *Label20;
        TDBLookupComboBox *lkcmb_marcas;
        TLabel *Label21;
        TDBLookupComboBox *lkcmb_garantia;
        TLabel *Label22;
        TdxEdit *edt_descri2;
        TQuery *qry_diary;
        TDataSource *dts_diary;
        TQuery *qry_lineas;
        TDataSource *dts_lineas;
        TQuery *qry_grupos;
        TDataSource *dts_grupos;
        TQuery *qry_prove;
        TDataSource *dts_prove;
        TQuery *qry_situaciones;
        TDataSource *dts_situaciones;
        TQuery *qry_marcas;
        TDataSource *dts_marcas;
        TQuery *qry_garantia;
        TDataSource *dts_garantia;
        TComboBox *cmb_tipo;
        TQuery *qry_inven;
        TQuery *qry_invhist;
        TEdit *edt_descri;
        TUpdateSQL *uqry_inven;
        TUpdateSQL *uqry_invhist;
        TUpdateSQL *uqry_invrelinv;
        TQuery *qry_invrelinv;
        TQuery *qry_buscasigid;
        TQuery *qry_catprodsat;
        TDataSource *dts_catprodsat;
        TGroupBox *grp_codsat;
        TDBLookupComboBox *lkcmb_catsat;
        TDBEdit *dbedt_codsat;
        TLabel *lbl_codsat;
        TRadioButton *rbtn_catsatcod;
        TRadioButton *rbtn_catsatgpo;
        void __fastcall edt_costosiExit(TObject *Sender);
        void __fastcall rbtn_catsatcodClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosarticulo(TComponent* Owner);
        void __fastcall inicializa(String codigo_z, int modo_z);
        void __fastcall busca_articulo(String codigo_z);
        void __fastcall agrega_relaciones_inv(String grupo_z, String prove_z,
          String linea_z, String situac_z, String garantia_z,
          String  descri2_z, String marca_z);
        void __fastcall graba_articulo(int modo_z);
        int buscaid(String tabla_z);

        TForm_consuinv *Form_consuinv;
        int cia_z, modo_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosarticulo *Frame_datosarticulo;
//---------------------------------------------------------------------------
#endif
