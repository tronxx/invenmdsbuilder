//---------------------------------------------------------------------------


#ifndef Frme_datostablaH
#define Frme_datostablaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_datostabla : public TFrame
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TLabel *lbl_orden;
        TLabel *Label1;
        TLabel *Label2;
        TEdit *edt_descri;
        TDateTimePicker *date_fecini;
        TComboBox *cmb_uso;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datostabla(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datostabla *Frame_datostabla;
//---------------------------------------------------------------------------
#endif
