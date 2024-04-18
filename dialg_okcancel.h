//---------------------------------------------------------------------------

#ifndef dialg_okcancelH
#define dialg_okcancelH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class Tdlg_okcancel : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel2;
        TBitBtn *btn_ok;
        TBitBtn *btn_cancel;
        TPanel *Panel1;
        void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tdlg_okcancel(TComponent* Owner);

};
//---------------------------------------------------------------------------
extern PACKAGE Tdlg_okcancel *dlg_okcancel;
//---------------------------------------------------------------------------
#endif
