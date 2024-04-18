//---------------------------------------------------------------------------

#ifndef dialg_datosalmH
#define dialg_datosalmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include "dxExEdtr.hpp"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class Tdlg_datosalm : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TBitBtn *BitBtn1;
        TBitBtn *btn_cancel;
        TPanel *Panel1;
        TLabel *Label1;
        TEdit *edt_codvnd;
        TLabel *Label2;
        TEdit *edt_nombre;
        TLabel *Label3;
        TEdit *edt_direc;
        TLabel *Label4;
        TdxSpinEdit *edt_ordiary;
        TLabel *Label5;
        TEdit *edt_exib;
        TLabel *Label6;
        TQuery *qry_zonas;
        TDataSource *dts_zonas;
        TDBEdit *DBEdit1;
        TLabel *Label7;
        TdxSpinEdit *edt_ordtab;
        TDBLookupComboBox *lkcmb_zona;
        TLabel *Label8;
        TComboBox *cmb_status;
        TQuery *qry_relubivta;
        TDataSource *dts_relubivta;
        TLabel *lbl_relubivta;
        TDBLookupComboBox *lkcmb_relubivta;
        TDBEdit *dbedt_ubivta;
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tdlg_datosalm(TComponent* Owner);
        void __fastcall asigna_tipo(String tipo_z);

};
//---------------------------------------------------------------------------
extern PACKAGE Tdlg_datosalm *dlg_datosalm;
//---------------------------------------------------------------------------
#endif
