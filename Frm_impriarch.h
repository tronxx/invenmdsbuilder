//---------------------------------------------------------------------------

#ifndef Frm_impriarchH
#define Frm_impriarchH
//---------------------------------------------------------------------------
#include <stdio.h>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Dialogs.hpp>
#include "impre.h"
//---------------------------------------------------------------------------
class TForm_impriarch : public TForm
{
__published:	// IDE-managed Components
        TLabel *lbl_archivo;
        TEdit *edt_nomarch;
        TButton *btn_explorar;
        TPrinterSetupDialog *PrinterSetupDialog1;
        TButton *btn_imprimir;
        TButton *btn_propiedades;
        void __fastcall btn_explorarClick(TObject *Sender);
        void __fastcall btn_propiedadesClick(TObject *Sender);
        void __fastcall btn_imprimirClick(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_impriarch(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_impriarch *Form_impriarch;
//---------------------------------------------------------------------------
#endif
