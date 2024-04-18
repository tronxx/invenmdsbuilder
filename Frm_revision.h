//---------------------------------------------------------------------------

#ifndef Frm_revisionH
#define Frm_revisionH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "AdvGrid.hpp"
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Grids.hpp>
//---------------------------------------------------------------------------
class TForm_revision : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel6;
        TLabel *Label21;
        TLabel *Label22;
        TDateTimePicker *date_fentini;
        TDateTimePicker *date_fentfin;
        TButton *btn_revisa;
        TAdvStringGrid *sgrd_pendtes;
        TQuery *qry_revision;
        TQuery *qry_movto;
        void __fastcall btn_revisaClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_revision(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_revision *Form_revision;
//---------------------------------------------------------------------------
#endif
