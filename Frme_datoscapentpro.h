//---------------------------------------------------------------------------


#ifndef Frme_datoscapentproH
#define Frme_datoscapentproH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBELib.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datoscapentpro : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label3;
        TDBLookupComboBox *lkcmb_almacen;
        TDBEdit *DBEdit1;
        TLabel *Label1;
        TdxCurrencyEdit *edt_nument;
        TLabel *Label4;
        TDateTimePicker *date_fecha;
        TLabel *Label14;
        TDBLookupComboBox *lkcmb_prove;
        TDBEdit *DBEdit3;
        TLabel *Label17;
        TdxDBCurrencyEdit *dxDBCurrencyEdit1;
        TdxDBCurrencyEdit *dxDBCurrencyEdit2;
        TLabel *Label18;
        TdxEdit *edt_facpro;
        TLabel *Label16;
        TDBEdit *DBEdit2;
        TDBLookupComboBox *lkcmb_planp;
        TLabel *Label20;
        TLabel *Label21;
        TdxCurrencyEdit *edt_nulets;
        TLabel *Label31;
        TdxCurrencyEdit *edt_plazo;
        TLabel *Label29;
        TDateTimePicker *date_prpago;
        TLabel *Label19;
        TdxDBCurrencyEdit *dxDBCurrencyEdit3;
        TdxCurrencyEdit *edt_flete;
        TLabel *Label26;
        TDateTimePicker *date_ulpago;
        TLabel *Label30;
        TdxCurrencyEdit *edt_cfc;
        TLabel *Label23;
        TdxCurrencyEdit *edt_tasaent;
        TLabel *Label22;
        TLabel *Label24;
        TdxCurrencyEdit *edt_tasapro;
        TLabel *Label25;
        TdxCurrencyEdit *edt_cfp;
        TLabel *Label27;
        TdxCurrencyEdit *edt_desxapli;
        TLabel *Label28;
        TdxCurrencyEdit *edt_grtotal;
        TQuery *qry_almacen;
        TDataSource *dts_almacen;
        TQuery *qry_prove;
        TDataSource *dts_prove;
        TQuery *qry_planesp;
        TDataSource *dts_planesp;
        TQuery *qry_entradas;
        TUpdateSQL *uqry_entradas;
        TDataSource *dts_entradas;
        TQuery *qry_renentra;
        TDataSource *dtsRenEntra;
        TUpdateSQL *uqry_renentra;
        void __fastcall edt_numentExit(TObject *Sender);
        void __fastcall lkcmb_almacenExit(TObject *Sender);
        void __fastcall edt_plazoExit(TObject *Sender);
        void __fastcall qry_planespAfterScroll(TDataSet *DataSet);
        void __fastcall date_prpagoExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscapentpro(TComponent* Owner);
        void __fastcall nuevo();
        void __fastcall inicializa(String mitipo_z);
        bool __fastcall BuscarEntrada(int iNumero);
        void __fastcall ListarRenglon();
         int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, pagina_z,
         accion_z;
         AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
         titmsg_z, genero_z, permis_z;
         String tipo_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscapentpro *Frame_datoscapentpro;
//---------------------------------------------------------------------------
#endif
