//---------------------------------------------------------------------------


#ifndef Frme_pideseriesH
#define Frme_pideseriesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ActnList.hpp>
#include <ExtCtrls.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFrame_pideseries : public TFrame
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TActionList *ActionList1;
        TListBox *lst_series;
        TAction *nueva_serie;
        TBitBtn *BitBtn1;
        TAction *elimina_serie;
        TAction *modifica_serie;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn3;
        void __fastcall nueva_serieExecute(TObject *Sender);
        void __fastcall elimina_serieExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_pideseries(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_pideseries *Frame_pideseries;
//---------------------------------------------------------------------------
#endif
