//---------------------------------------------------------------------------


#ifndef Frme_datoscambioH
#define Frme_datoscambioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_datoscambio : public TFrame
{
__published:	// IDE-managed Components
        TLabel *lbl_tipo;
        TEdit *edt_tipo;
        TLabel *lbl_idcli;
        TEdit *edt_idcli;
        TLabel *lbl_fecha;
        TDateTimePicker *date_fecha;
        TLabel *lbl_codigo;
        TEdit *edt_codigo;
        TLabel *lbl_sentencia;
        TEdit *edt_sentencia;
        TCheckBox *chk_ejecutar;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscambio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscambio *Frame_datoscambio;
//---------------------------------------------------------------------------
#endif
