//---------------------------------------------------------------------------


#ifndef Frme_nvaobspedH
#define Frme_nvaobspedH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_nvaobsped : public TFrame
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TDateTimePicker *dtFecha;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *edtObserva;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_nvaobsped(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_nvaobsped *Frame_nvaobsped;
//---------------------------------------------------------------------------
#endif
