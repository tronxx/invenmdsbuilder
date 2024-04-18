//---------------------------------------------------------------------------


#ifndef Frme_datosmantoproveH
#define Frme_datosmantoproveH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
//---------------------------------------------------------------------------
class TFrame_datosmantoprove : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label7;
        TLabel *Label6;
        TLabel *Label12;
        TdxCurrencyEdit *edt_limite;
        TEdit *edt_nombre;
        TEdit *edt_direc;
        TEdit *edt_tel;
        TEdit *edt_contacto;
        TEdit *edt_codvnd;
        TEdit *edt_ciudad;
        TLabel *Label5;
        TEdit *edt_rfc;
        TLabel *Label8;
        TComboBox *cmb_estado;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosmantoprove(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosmantoprove *Frame_datosmantoprove;
//---------------------------------------------------------------------------
#endif
