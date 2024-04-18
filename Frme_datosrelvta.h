//---------------------------------------------------------------------------


#ifndef Frme_datosrelvtaH
#define Frme_datosrelvtaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxDBTLCl.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include "dxGrClms.hpp"
#include "dxTL.hpp"
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <DBCtrls.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <ToolWin.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TFrame_datosrelvta : public TFrame
{
__published:	// IDE-managed Components
        TPanel *Panel3;
        TSplitter *Splitter1;
        TGroupBox *GroupBox5;
        TdxDBGrid *dxDBGrid1;
        TdxDBGridMaskColumn *dxDBGrid1Column1;
        TdxDBGridMaskColumn *dxDBGrid1Column2;
        TdxDBGridDateColumn *dxDBGrid1Column3;
        TdxDBGridMaskColumn *dxDBGrid1Column4;
        TdxDBGridMaskColumn *dxDBGrid1Column5;
        TGroupBox *GroupBox4;
        TGroupBox *grp_datosvta;
        TLabel *lbl_folio;
        TLabel *Label2;
        TLabel *Label15;
        TLabel *Label7;
        TLabel *Label9;
        TLabel *lbl_codigo;
        TLabel *lbl_prlista;
        TLabel *Label3;
        TLabel *lbl_vendedor;
        TLabel *Label14;
        TLabel *lbl_choferentrega;
        TLabel *Label11;
        TLabel *Label16;
        TdxCurrencyEdit *edt_nument;
        TdxEdit *edt_nombre;
        TDBLookupComboBox *lkcmb_ciudad;
        TMemo *mmo_direc;
        TEdit *edt_codigo;
        TBitBtn *btn_nvoren;
        TdxCurrencyEdit *edt_preciolis;
        TDateTimePicker *date_fentrega;
        TDBLookupComboBox *lkcmb_vendedr;
        TDBEdit *DBEdit3;
        TDBLookupComboBox *lkcmb_tipocte;
        TDBEdit *DBEdit6;
        TDBLookupComboBox *lkcmb_choferentrega;
        TDBEdit *dbedt_choferentrega;
        TDBLookupComboBox *lkcmb_ptovta;
        TDBEdit *dbedt_ptovta;
        TDBLookupComboBox *lkcmb_tipoentr;
        TDBEdit *DBEdit7;
        TEdit *edt_descri;
        TButton *btn_buscarfolio;
        TQuery *qry_tiposctes;
        TDataSource *dts_tiposctes;
        TQuery *qry_ciudad;
        TDataSource *dts_ciudad;
        TQuery *qry_vendr;
        TDataSource *dts_vendr;
        TQuery *qry_chofer;
        TDataSource *dts_chofer;
        TQuery *qry_exist;
        TDataSource *dts_exist;
        TQuery *qry_tipoentrega;
        TDataSource *dts_tipoentrega;
        TQuery *qry_ptovta;
        TDataSource *dts_ptovta;
        TUpdateSQL *uqry_renentra;
        TQuery *qry_renentra;
        TDataSource *dts_renentra;
        TdxDBGrid *dbgrd_rengnes;
        TdxDBGridMaskColumn *dbgrd_rengnesCODIGO;
        TdxDBGridMaskColumn *dbgrd_rengnesDESCRI;
        TdxDBGridMaskColumn *dbgrd_rengnesSALEDE;
        TdxDBGridCurrencyColumn *dbgrd_rengnesColumn4;
        TQuery *qry_ubica;
        TDataSource *dts_ubica;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_comprometidos;
        TUpdateSQL *uqry_exist;
        TActionList *ActionList1;
        TAction *borraren;
        TAction *primer_artic;
        TAction *anter_artic;
        TAction *sigte_artic;
        TAction *ultimo_artic;
        TdxTimeEdit *date_hora;
        TPanel *Panel1;
        TLabel *lbl_formapago;
        TDBLookupComboBox *lkcmb_tipopago;
        TQuery *qry_formapago;
        TDataSource *dts_formapago;
        TBitBtn *BitBtn5;
        TPopupMenu *pop_menuren;
        TAction *despiega_menu;
        TQuery *qry_buscadescto;
        TCheckBox *chk_modifprecio;
        void __fastcall edt_codigoExit(TObject *Sender);
        void __fastcall btn_nvorenClick(TObject *Sender);
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall btn_buscarfolioClick(TObject *Sender);
        void __fastcall qry_renentraAfterScroll(TDataSet *DataSet);
        void __fastcall dbgrd_rengnesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall borrarenExecute(TObject *Sender);
        void __fastcall primer_articExecute(TObject *Sender);
        void __fastcall anter_articExecute(TObject *Sender);
        void __fastcall sigte_articExecute(TObject *Sender);
        void __fastcall ultimo_articExecute(TObject *Sender);
        void __fastcall despiega_menuExecute(TObject *Sender);
        void __fastcall FrameEnter(TObject *Sender);
        void __fastcall lkcmb_tipocteExit(TObject *Sender);
        void __fastcall chk_modifprecioClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosrelvta(TComponent* Owner);
        void __fastcall inicializa(String modo_z);
        void __fastcall despliega_comprometidos();
        void __fastcall despliega_renentra();
        void __fastcall agrega_chofer();
        double busca_descto(String codigo_z, String ticte_z);


        int cia_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosrelvta *Frame_datosrelvta;
//---------------------------------------------------------------------------
#endif
