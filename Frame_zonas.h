//---------------------------------------------------------------------------


#ifndef Frame_zonasH
#define Frame_zonasH
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
class TFrme_zonas : public TFrame
{
__published:	// IDE-managed Components
        TLabel *lbl_codigo;
        TdxCurrencyEdit *edt_ptovta;
        TLabel *lbl_nombre;
        TdxEdit *edt_nombre;
private:	// User declarations
public:		// User declarations
        __fastcall TFrme_zonas(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrme_zonas *Frme_zonas;
//---------------------------------------------------------------------------
#endif
