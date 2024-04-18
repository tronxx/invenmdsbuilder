//---------------------------------------------------------------------------

#ifndef Frm_selecdbH
#define Frm_selecdbH
//---------------------------------------------------------------------------
#include <ToolWin.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <StdActns.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm_selecbd : public TForm
{
__published:	// IDE-managed Components
    TLabel *RzLabel1;
    TBitBtn *btnAceptar;
    TBitBtn *btnCerrar;
        TComboBox *cmbBasedatos;
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall btnAceptarClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TForm_selecbd(TComponent* Owner);
    String archini_z, odbclocal_z, odbclinux_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_selecbd *Form_selecbd;
//---------------------------------------------------------------------------
#endif
