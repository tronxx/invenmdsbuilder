//---------------------------------------------------------------------------


#ifndef Frme_datosmantotiposctesH
#define Frme_datosmantotiposctesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datosmantotiposctes : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edt_ptovta;
        TLabel *lbl_nombre;
        TdxEdit *edt_nombre;
        TDBLookupComboBox *lkcmb_ptovta;
        TLabel *lbl_tipocartera;
        TQuery *qry_tipocar;
        TDataSource *dts_tipocar;
        TLabel *lbl_remate;
        TComboBox *cmb_remate;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosmantotiposctes(TComponent* Owner);
        void __fastcall asigna_tipo(String tipo_z);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosmantotiposctes *Frame_datosmantotiposctes;
//---------------------------------------------------------------------------
#endif
