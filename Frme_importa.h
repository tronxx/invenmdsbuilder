//---------------------------------------------------------------------------


#ifndef Frme_importaH
#define Frme_importaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <Dialogs.hpp>
#include <ActnList.hpp>
#include "AdvGrid.hpp"
#include <Grids.hpp>
#include <ComCtrls.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_importa : public TFrame
{
__published:	// IDE-managed Components
        TOpenDialog *OpenDialog1;
        TActionList *ActionList1;
        TAction *buscar_archivo;
        TPanel *Panel1;
        TPageControl *PageControl1;
        TTabSheet *TabSheet1;
        TTabSheet *TabSheet2;
        TAdvStringGrid *sgrd_datos;
        TMemo *mmo_formato;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TEdit *edt_nomarch;
        TBitBtn *BitBtn1;
        void __fastcall buscar_archivoExecute(TObject *Sender);
        void __fastcall edt_nomarchKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_importa(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_importa *Frame_importa;
//---------------------------------------------------------------------------
#endif
