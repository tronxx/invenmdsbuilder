//---------------------------------------------------------------------------


#ifndef Frme_datoscapcancelagregaH
#define Frme_datoscapcancelagregaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFrame_datoscapcancelagrega : public TFrame
{
__published:	// IDE-managed Components
        TEdit *edt_codigo;
        TLabel *Label8;
        TDBEdit *edt_descri;
        TLabel *Label12;
        TdxCurrencyEdit *edt_canti;
        TLabel *Label13;
        TComboBox *cmb_status;
        TLabel *Label10;
        TdxEdit *edt_folios;
        TLabel *Label11;
        TDBLookupComboBox *lkcmb_ptovta;
        TDBEdit *DBEdit6;
        TLabel *Label9;
        TLabel *Label2;
        TdxEdit *edt_nombre;
        TLabel *Label7;
        TComboBox *cmb_entcan;
        TLabel *Label6;
        TLabel *Label15;
        TDBLookupComboBox *lkcmb_poblac;
        TLabel *Label5;
        TDBLookupComboBox *lkcmb_vendedr;
        TDBEdit *DBEdit5;
        TLabel *lbl_prvta;
        TQuery *qry_puntovta;
        TDataSource *dts_puntovta;
        TQuery *qry_poblacion;
        TDataSource *dts_poblacion;
        TQuery *qry_vendedor;
        TDataSource *dts_vendedor;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_folsigent;
        TQuery *qry_ultfol;
        TQuery *qry_folsel;
        TUpdateSQL *uqry_folsel;
        TComboBox *lst_series;
        TdxCurrencyEdit *edt_costou;
        TdxCurrencyEdit *edt_prvta;
        TButton *Button1;
        TLabel *lbl_crdocont;
        TComboBox *cmb_credcont;
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall edt_cantiExit(TObject *Sender);
        void __fastcall cmb_statusExit(TObject *Sender);
        void __fastcall edt_codigoExit(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscapcancelagrega(TComponent* Owner);
        int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, pagina_z;
        AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
        titmsg_z, genero_z;
        String alm_z;
        TDateTime fecha_z;
        void __fastcall busca_cod(String codigo_z);
        void __fastcall pide_series();

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscapcancelagrega *Frame_datoscapcancelagrega;
//---------------------------------------------------------------------------
#endif
