//---------------------------------------------------------------------------

#ifndef Form_analivtacycH
#define Form_analivtacycH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
//---------------------------------------------------------------------------
class TForm_analivtacyc : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TdxDBGrid *dbgrd_renglones;
        TQuery *qry_analisma;
        TUpdateSQL *uqry_gpodiary;
        TDataSource *dts_analisma;
        TdxDBGridMaskColumn *dbgrd_renglonesLINEA;
        TdxDBGridMaskColumn *dbgrd_renglonesCODIGO;
        TdxDBGridMaskColumn *dbgrd_renglonesDESCRI;
        TdxDBGridMaskColumn *dbgrd_renglonesEMPAQE;
        TdxDBGridMaskColumn *dbgrd_renglonesUNIDS;
        TdxDBGridCurrencyColumn *dbgrd_renglonesCOSTOU;
        TdxDBGridCurrencyColumn *dbgrd_renglonesPRVTA;
        TdxDBGridCurrencyColumn *dbgrd_renglonesCOSTOTOT;
        TPanel *Panel2;
        TLabel *Label1;
        TDateTimePicker *date_fecini;
        TLabel *Label2;
        TDateTimePicker *date_fecfin;
        TBitBtn *BitBtn1;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
        TActionList *ActionList1;
        TAction *exporta_dbgrd;
        TdxDBGridMaskColumn *dbgrd_renglonesCONT;
        TdxDBGridMaskColumn *dbgrd_renglonesUBICA;
        TdxDBGridMaskColumn *dbgrd_renglonesFecha;
        TdxDBGridMaskColumn *dbgrd_renglonesNombre;
        TGroupBox *grp_parametros;
        TLabel *Label5;
        TComboBox *cmb_netobru;
        TLabel *Label6;
        TComboBox *cmb_statsino;
        TComboBox *cmb_statcan;
        TLabel *Label7;
        TComboBox *cmb_contycre;
        TLabel *lbl_contycred;
        TLabel *Label3;
        TEdit *edt_prlin;
        TLabel *Label4;
        TEdit *edt_ullin;
        TLabel *Label9;
        TComboBox *cmb_tiporep;
        TLabel *lbl_ptvtini;
        TEdit *edt_ptvtini;
        TLabel *lbl_ptvtfin;
        TEdit *edt_ptvtfin;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall Exportara1Click(TObject *Sender);
        void __fastcall exporta_dbgrdExecute(TObject *Sender);
        void __fastcall agrega_tipovta(
                  int id_z, int idtarea_z, int factor_z, String tipoent_z);
        void __fastcall cmb_tiporepChange(TObject *Sender);
        void __fastcall edt_prlinDblClick(TObject *Sender);

private:	// User declarations
public:		// User declarations
        __fastcall TForm_analivtacyc(TComponent* Owner);
        int cia_z, idtarea_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_analivtacyc *Form_analivtacyc;
//---------------------------------------------------------------------------
#endif
