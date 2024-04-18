//---------------------------------------------------------------------------

#ifndef Frm_detmovartH
#define Frm_detmovartH
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
#include <Db.hpp>
#include <DBTables.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_detmovart : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TdxDBEdit *dxDBEdit1;
        TdxDBCurrencyEdit *dxDBCurrencyEdit1;
        TdxDBEdit *dxDBEdit2;
        TdxDBCurrencyEdit *dxDBCurrencyEdit2;
        TQuery *qry_movart;
        TStringField *qry_movartCODIGO;
        TStringField *qry_movartALMAC;
        TIntegerField *qry_movartFOLIO;
        TStringField *qry_movartPROVE;
        TIntegerField *qry_movartNOMPRO;
        TIntegerField *qry_movartCOMPRO;
        TStringField *qry_movartFACPRO;
        TDateField *qry_movartFECHA;
        TFloatField *qry_movartCOSTO;
        TStringField *qry_movartSESPE;
        TStringField *qry_movartMODSAL;
        TStringField *qry_movartMODENT;
        TIntegerField *qry_movartNENTRADA;
        TStringField *qry_movartTIPO;
        TStringField *qry_movartVIENEDE;
        TIntegerField *qry_movartFOLVIENE;
        TStringField *qry_movartVAHACIA;
        TIntegerField *qry_movartFOLREC;
        TSmallintField *qry_movartPUEBLO;
        TIntegerField *qry_movartNUMFAC;
        TStringField *qry_movartSERIEFAC;
        TStringField *qry_movartSALIO;
        TStringField *qry_movartSMAY;
        TSmallintField *qry_movartCANTI;
        TStringField *qry_movartSERIE;
        TStringField *qry_movartSALVTA;
        TStringField *qry_movartENTCAN;
        TIntegerField *qry_movartNSALIDA;
        TSmallintField *qry_movartENTRAPOR;
        TSmallintField *qry_movartSALEPOR;
        TDateField *qry_movartFECENTORI;
        TDateField *qry_movartFECVENCTO;
        TStringField *qry_movartUSUARIO;
        TSmallintField *qry_movartCIA;
        TStringField *qry_movartPTVTA;
        TStringField *qry_movartVEND;
        TStringField *qry_movartProveedor;
        TStringField *qry_movartComprador;
        TDateField *qry_movartfechsalida;
        TStringField *qry_movartstrentrapor;
        TStringField *qry_movartstrsalepor;
        TStringField *qry_movartstatussal;
        TStringField *qry_movartpoblacion;
        TStringField *qry_movartalmenv;
        TStringField *qry_movartalmrec;
        TDataSource *dts_movart;
        TQuery *qry_conceps;
        TQuery *qry_tpmov;
        TQuery *qry_poblacs;
        TQuery *qry_pedimen;
        TDataSource *dts_pedimen;
    TDateField *qry_movartFECHASAL;
        TGroupBox *GroupBox3;
        TLabel *Label5;
        TdxDBEdit *dxDBEdit3;
        TdxDBEdit *dxDBEdit4;
        TLabel *Label6;
        TdxDBEdit *dxDBEdit5;
        TLabel *Label7;
        TdxDBCurrencyEdit *dxDBCurrencyEdit3;
        TdxDBEdit *dxDBEdit6;
        TdxDBEdit *dxDBEdit7;
        TLabel *Label18;
        TdxDBEdit *dxDBEdit15;
        TLabel *Label19;
        TdxDBCurrencyEdit *dxDBCurrencyEdit5;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label22;
        TdxDBEdit *dxDBEdit17;
        TLabel *Label23;
        TdxDBEdit *dxDBEdit18;
        TLabel *Label24;
        TdxDBEdit *dxDBEdit19;
        TGroupBox *GroupBox1;
        TLabel *Label10;
        TdxDBEdit *dxDBEdit8;
        TLabel *Label11;
        TdxDBCurrencyEdit *dxDBCurrencyEdit4;
        TLabel *Label12;
        TdxDBEdit *dxDBEdit9;
        TLabel *Label13;
        TdxDBEdit *dxDBEdit10;
        TLabel *Label14;
        TdxDBEdit *dxDBEdit11;
        TLabel *Label15;
        TdxDBEdit *dxDBEdit12;
        TLabel *Label16;
        TdxDBEdit *dxDBEdit13;
        TLabel *Label17;
        TdxDBEdit *dxDBEdit14;
        TLabel *Label20;
        TdxDBEdit *dxDBEdit16;
        TLabel *Label21;
        TdxDBCurrencyEdit *dxDBCurrencyEdit6;
        TGroupBox *grp_pedimen;
        TLabel *Label25;
        TLabel *Label26;
        TLabel *Label27;
        TLabel *Label28;
        TdxDBEdit *dxDBEdit20;
        TdxDBEdit *dxDBEdit21;
        TdxDBEdit *dxDBEdit22;
        TdxDBEdit *dxDBEdit23;
        TPanel *Panel3;
        TBitBtn *btn_antermov;
        TBitBtn *btn_sigtemov;
        TBitBtn *btn_origmov;
        TBitBtn *btn_destimov;
        TBitBtn *btn_cierra;
        TStringField *qry_movartcredocon;
        TLabel *Label29;
        TdxDBEdit *dxDBEdit24;
        TActionList *ActionList1;
        TAction *grabar_pedimento;
        TButton *Button1;
        TQuery *qry_credocon;
        TAction *modificar_serie;
        TQuery *qry_updateserie;
        TPopupMenu *PopupMenu1;
        TMenuItem *ModificarSerie1;
  void __fastcall qry_movartCalcFields(TDataSet *DataSet);
  void __fastcall btn_cierraClick(TObject *Sender);
  void __fastcall btn_antermovClick(TObject *Sender);
        void __fastcall grabar_pedimentoExecute(TObject *Sender);
        void __fastcall modificar_serieExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
  __fastcall TForm_detmovart(TComponent* Owner);
  int cia_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_detmovart *Form_detmovart;
//---------------------------------------------------------------------------
#endif
