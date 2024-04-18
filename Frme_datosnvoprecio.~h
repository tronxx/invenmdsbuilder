//---------------------------------------------------------------------------


#ifndef Frme_datosnvoprecioH
#define Frme_datosnvoprecioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Db.hpp>
#include <DBTables.hpp>
#include "Frm_consuinv.h"
//---------------------------------------------------------------------------
class TFrame_datosnvoprecio : public TFrame
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Fecha;
        TEdit *edt_fecha;
        TDataSource *dts_cambios;
        TQuery *qry_cambios;
        TUpdateSQL *uqry_cambios;
        TQuery *qry_inven;
        TLabel *Label2;
        TEdit *edt_vigencia;
        TGroupBox *GroupBox3;
        TGroupBox *GroupBox4;
        TGroupBox *GroupBox6;
        TLabel *Label6;
        TEdit *edt_mayact;
        TLabel *Label9;
        TEdit *edt_mubmayact;
        TLabel *Label10;
        TEdit *edt_filact;
        TLabel *Label11;
        TEdit *edt_maynvo;
        TLabel *Label12;
        TEdit *edt_mubmaynvo;
        TLabel *Label13;
        TEdit *edt_filnvo;
        TGroupBox *GroupBox1;
        TGroupBox *GroupBox5;
        TLabel *Label1;
        TLabel *Label3;
        TLabel *Label4;
        TEdit *edt_pract;
        TEdit *edt_mubact;
        TEdit *edt_sitact;
        TGroupBox *GroupBox2;
        TLabel *Label5;
        TLabel *Label7;
        TLabel *Label8;
        TEdit *edt_prnvo;
        TEdit *edt_mubnvo;
        TEdit *edt_sitnvo;
        TLabel *Label14;
        TEdit *edt_coston;
        TLabel *Label15;
        TEdit *edt_comboact;
        TLabel *Label16;
        TEdit *edt_combonvo;
        TEdit *edt_plazo;
        TLabel *Label26;
        TEdit *edt_plazonvo;
        TLabel *Label17;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosnvoprecio(TComponent* Owner);
        void __fastcall despliega_cambio_precio(String codigo_z);
        double __fastcall calcu_prmay(String codigo_z, int tipomayoris_z, double preciomen_z);
        TForm_consuinv *Form_consuinv;
        int cia_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosnvoprecio *Frame_datosnvoprecio;
//---------------------------------------------------------------------------
#endif
