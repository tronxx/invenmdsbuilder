//---------------------------------------------------------------------------


#ifndef Frme_datosfacmaH
#define Frme_datosfacmaH
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
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TFrame_datosfacma : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TdxCurrencyEdit *edt_numfac;
        TLabel *Label4;
        TDateTimePicker *date_fecha;
        TLabel *Label15;
        TdxCurrencyEdit *edt_npagos;
        TLabel *Label16;
        TdxCurrencyEdit *edt_pzoxlet;
        TLabel *lbl_mayoris;
        TEdit *edt_nombrefac;
        TLabel *Label2;
        TLabel *Label3;
        TEdit *edt_refer;
        TLabel *Label11;
        TEdit *edt_rfc;
        TLabel *Label14;
        TdxDBCurrencyEdit *edt_import;
        TLabel *Label5;
        TdxDBCurrencyEdit *edt_descto;
        TLabel *Label20;
        TdxDBCurrencyEdit *edt_subtot;
        TLabel *Label6;
        TdxDBCurrencyEdit *edt_iva;
        TLabel *Label7;
        TdxDBCurrencyEdit *edt_total;
        TQuery *qry_mayoris;
        TDataSource *dts_mayoris;
        TEdit *edt_mayoris;
        TUpdateSQL *uqry_seriefacma;
        TQuery *qry_seriefacma;
        TDataSource *dts_seriefacma;
        TLabel *Label8;
        TComboBox *cmb_mayomen;
        TEdit *edt_tipomay;
        TLabel *Label9;
        TComboBox *cmb_intomer;
        TLabel *Label10;
        TEdit *edt_seriefac;
        TLabel *Label18;
        TDBLookupComboBox *lkcmb_metodopago;
        TLabel *Label19;
        TEdit *edt_numcta1;
        TLabel *Label24;
        TDBLookupComboBox *lkcmb_metodopago2;
        TLabel *Label25;
        TEdit *edt_numcta2;
        TQuery *qry_mediospago;
        TQuery *qry_mediopago2;
        TDataSource *dts_mediospago;
        TDataSource *dts_mediopago2;
        TActionList *ActionList1;
        TAction *pide_direc;
        TMemo *mmo_direc;
        TAction *grabar_uuid;
        void __fastcall edt_mayorisExit(TObject *Sender);
        void __fastcall edt_seriefacExit(TObject *Sender);
        void __fastcall pide_direcExecute(TObject *Sender);
        void __fastcall mmo_direcKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosfacma(TComponent* Owner);
        bool __fastcall busca_mayoris(String mayoris_z);
        String  __fastcall selecciona_tipo_fac(String modo_z, String tipo_z);
        String modo_z, calles_z, numpred_z, colonia_z, codpost_z, ciu_z;

        int idpob_z, entrapor_z, cia_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosfacma *Frame_datosfacma;
//---------------------------------------------------------------------------
#endif
