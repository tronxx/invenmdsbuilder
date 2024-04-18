//---------------------------------------------------------------------------


#ifndef Frme_datosmantmayoH
#define Frme_datosmantmayoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include "dxTL.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
#include <StdActns.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datosmantmayo : public TFrame
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TEdit *edt_codvnd;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *edt_nombre;
        TLabel *Label12;
        TEdit *edt_nombre2;
        TLabel *Label3;
        TLabel *Label7;
        TLabel *Label10;
        TEdit *edt_rfc;
        TLabel *Label4;
        TEdit *edt_tel;
        TLabel *Label6;
        TdxCurrencyEdit *edt_pdsc;
        TQuery *qry_mayoris;
        TActionList *ActionList1;
        TAction *nuevo;
        TAction *modifica;
        TAction *borra;
        TAction *grabar;
        TAction *cancelar;
        TWindowClose *WindowClose1;
        TAction *primero;
        TAction *anterior;
        TAction *siguiente;
        TAction *ultimo;
        TAction *elimina_tel;
        TQuery *qry_telefonos;
        TDataSource *dts_telefonos;
        TUpdateSQL *uqry_mayoris;
        TQuery *qry_tipostel;
        TDBLookupComboBox *lkcmb_ciudad;
        TQuery *qry_ciudades;
        TDataSource *dts_ciudades;
        TLabel *Label15;
        TPageControl *pge_telefonos;
        TTabSheet *tbs_datospagare;
        TLabel *Label5;
        TEdit *edt_nompag;
        TLabel *Label8;
        TEdit *edt_dirpag;
        TLabel *Label11;
        TEdit *edt_dirpag2;
        TLabel *Label9;
        TDBLookupComboBox *lkcmb_ciudad2;
        TTabSheet *tbs_telefonos;
        TdxDBGrid *dbgrd_telefonos;
        TdxDBGridMaskColumn *dbgrd_telefonosTIPOTEL;
        TdxDBGridMaskColumn *dbgrd_telefonosNUMTEL;
        TUpdateSQL *uqry_telefonos;
        TAction *agregar_tel;
        TQuery *qry_invtipomay;
        TDataSource *dts_invtipomay;
        TDBLookupComboBox *lkcmb_tipomay;
        TComboBox *cmb_status;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TEdit *edt_numcta;
        TQuery *qry_datospago;
        TUpdateSQL *uqry_datospago;
        TLabel *Label19;
        TLabel *Label20;
        TLabel *Label21;
        TEdit *edt_direc;
        TEdit *edt_numpred;
        TEdit *edt_codpost;
        TEdit *edt_colonia;
        TLabel *lbl_email;
        TEdit *edt_email;
        TLabel *Label22;
        TDBEdit *db_estado;
        TQuery *qry_mediospago;
        TDataSource *dts_mediospago;
        TDBLookupComboBox *lkcmb_metodopago;
        TQuery *qry_mediopago2;
        TDataSource *dts_mediopago2;
        TLabel *Label24;
        TDBLookupComboBox *lkcmb_metodopago2;
        TLabel *Label25;
        TEdit *edt_numcta2;
        TDataSource *dts_emailes;
        TQuery *qry_emailes;
        TUpdateSQL *uqry_emailes;
        TTabSheet *tbs_emailes;
        TdxDBGrid *dbgrd_emailes;
        TdxDBGridMaskColumn *dbgrd_emailesCORREODE;
        TdxDBGridMaskColumn *dbgrd_emailesCORREO;
        TPanel *Panel1;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn1;
        TPanel *Panel2;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn4;
        TLabel *Label13;
        TQuery *qry_regimen;
        TDataSource *dts_regimen;
        TDBLookupComboBox *lkcmb_regimen;
        void __fastcall edt_codvndKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall agregar_telExecute(TObject *Sender);
        void __fastcall elimina_telExecute(TObject *Sender);
        void __fastcall pge_telefonosChange(TObject *Sender);
        void __fastcall dbgrd_telefonosKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosmantmayo(TComponent* Owner);
        void __fastcall busca_vnd(String vnd_z);
        void __fastcall desp_vnd();
        String __fastcall obten_datospago(String codigmay_z, String tipodato_z);
        String pide_email_o_tel(String tipodato_z);
        int cia_z, idrelmay_z;
        String pagina_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosmantmayo *Frame_datosmantmayo;
//---------------------------------------------------------------------------
#endif
