//---------------------------------------------------------------------------


#ifndef Frme_datospedmtoH
#define Frme_datospedmtoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_datospedmto : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label8;
        TEdit *edt_codigo;
        TLabel *Label10;
        TdxEdit *edt_folios;
        TLabel *Label1;
        TEdit *edt_serie;
        TLabel *Label2;
        TEdit *edt_seriemot;
        TLabel *Label3;
        TEdit *edt_pedimento;
        TLabel *Label4;
        TEdit *edt_aduana;
        TDateTimePicker *date_fechaped;
        TLabel *Label5;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datospedmto(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datospedmto *Frame_datospedmto;
//---------------------------------------------------------------------------
#endif
