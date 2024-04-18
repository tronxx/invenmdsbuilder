//---------------------------------------------------------------------------

#ifndef Frm_existsH
#define Frm_existsH
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
#include "dxLayout.hpp"
#include "dxTL.hpp"
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Dialogs.hpp>
#include <Menus.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <DBGrids.hpp>
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
//---------------------------------------------------------------------------
class TForm_exists : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_estadialm;
        TQuery *qry_estadis;
        TQuery *qry_nombrestad;
        TDataSource *dts_estadis;
        TPanel *Panel1;
        TPanel *Panel2;
        TGroupBox *GroupBox1;
        TCheckBox *chk_codigo;
        TEdit *edt_prcod;
        TGroupBox *GroupBox2;
        TEdit *edt_prgrp;
        TCheckBox *chk_grupo;
        TGroupBox *GroupBox5;
        TEdit *edt_prsit;
        TCheckBox *chk_situac;
        TGroupBox *GroupBox3;
        TEdit *edt_prmarca;
        TCheckBox *chk_marca;
        TGroupBox *GroupBox6;
        TCheckBox *chk_prove;
        TEdit *edt_prprove;
        TPanel *Panel4;
        TLabel *Label19;
        TBitBtn *btn_estadis;
        TBitBtn *BitBtn1;
        TPopupMenu *PopupMenu1;
        TMenuItem *ExportaraExcel1;
        TSaveDialog *SaveDialog1;
        TGroupBox *GroupBox7;
        TGroupBox *GroupBox8;
        TCheckBox *chk_linea;
        TEdit *edt_prlin;
        TLabel *Label1;
        TDBLookupComboBox *lkcmb_zonini;
        TDBEdit *dbedt_zonini;
        TLabel *Label2;
        TDataSource *dts_zonini;
        TQuery *qry_zonini;
        TDBLookupComboBox *lkcmb_zonfin;
        TDBEdit *DBEdit2;
        TQuery *qry_zonfin;
        TDataSource *dts_zonfin;
        TGroupBox *GroupBox4;
        TEdit *edt_diary;
        TCheckBox *chk_diary;
        TQuery *qry_exist;
        TDataSource *dts_exist;
        TUpdateSQL *uqry_exist;
        TQuery *qry_codigo;
        TQuery *qry_ventas;
        TDateTimePicker *date_fecexis;
        TdxDBGrid *dbgrd_exist;
        void __fastcall btn_estadisClick(TObject *Sender);
        void __fastcall chk_codigoClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall BitBtn1Click(TObject *Sender);
        void __fastcall ExportaraExcel1Click(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall dbedt_zoniniDblClick(TObject *Sender);
        void __fastcall calcu_alto_dbgrid();
        void __fastcall dbgrd_existCustomDrawCell(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
          bool ANewItemRow, AnsiString &AText, TColor &AColor,
          TFont *AFont, TAlignment &AAlignment, bool &ADone);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_exists(TComponent* Owner);
        int __fastcall busca_maximoant(String codigo_z);
        int __fastcall busca_unidades_vendidas( String codigo_z,
          String tiposalida_z);
        String sql_z, estadialm_z;
        int cia_z, estesi_z, maxdiasglo_z, maxdiasmen_z, maxdiasmay_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_exists *Form_exists;
//---------------------------------------------------------------------------
#endif
