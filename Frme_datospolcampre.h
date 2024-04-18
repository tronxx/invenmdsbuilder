//---------------------------------------------------------------------------


#ifndef Frme_datospolcampreH
#define Frme_datospolcampreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_datospolcampre : public TFrame
{
__published:	// IDE-managed Components
        TLabel *lbl_numero;
        TdxCurrencyEdit *edt_folio;
        TLabel *Label6;
        TDateTimePicker *date_fecha;
        TLabel *lbl_inivig;
        TDateTimePicker *date_inivig;
        TEdit *edt_concepto;
        TLabel *Label8;
        TLabel *lbl_finvigencia;
        TDateTimePicker *date_finvigencia;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datospolcampre(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datospolcampre *Frame_datospolcampre;
//---------------------------------------------------------------------------
#endif
