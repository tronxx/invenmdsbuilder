//---------------------------------------------------------------------------

#ifndef Frm_dlgcriterioH
#define Frm_dlgcriterioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TForm_dlgcriterio : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TPanel *Panel1;
        TCheckBox *chk_linea;
        TComboBox *cmb_linea;
        TPanel *Panel2;
        TCheckBox *chk_grupo;
        TComboBox *cmb_grupo;
        TPanel *Panel3;
        TCheckBox *chk_prove;
        TComboBox *cmb_prove;
        TPanel *Panel4;
        TCheckBox *chk_precio;
        TComboBox *cmb_precio;
        TPanel *Panel5;
        TBitBtn *btn_ok;
        TBitBtn *BitBtn2;
        TPanel *Panel6;
        TCheckBox *chk_existencia;
        TComboBox *cmb_conexistencia;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall btn_okClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_dlgcriterio(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_dlgcriterio *Form_dlgcriterio;
//---------------------------------------------------------------------------
#endif
