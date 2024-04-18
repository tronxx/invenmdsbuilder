//---------------------------------------------------------------------------


#ifndef Frme_datosmarcaH
#define Frme_datosmarcaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <ExtCtrls.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_datosmarca : public TFrame
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *lbl_codigo;
        TEdit *edt_codigo;
        TLabel *lbl_nombre;
        TdxEdit *edt_nombre;
        TLabel *lbl_estado;
        TDataSource *dts_estados;
        TQuery *qry_estados;
        TDBLookupComboBox *lkcmb_estados;
        TLabel *lbl_status;
        TComboBox *cmb_status;
        TLabel *lbl_fecbaj;
        TDateTimePicker *date_fecbaj;
        void __fastcall cmb_statusChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosmarca(TComponent* Owner);
        void __fastcall inicializa(String tipo_z);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosmarca *Frame_datosmarca;
//---------------------------------------------------------------------------
#endif
