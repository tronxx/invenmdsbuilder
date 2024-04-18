//---------------------------------------------------------------------------

#ifndef LoginH
#define LoginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
bool __fastcall RegistroClave(TForm *Padre, String &sInicialesp);
//---------------------------------------------------------------------------
class TfrmdlgLogin : public TForm
{
__published:	// IDE-managed Components
    TLabel *RzLabel1;
    TLabel *RzLabel2;
    TBitBtn *btnAceptar;
    TBitBtn *btnCancelar;
    TEdit *edtLogin;
    TEdit *edtPassword;
    TBevel *Bevel1;
    TQuery *qsUsarios;
    TQuery *qsPermiUsar;
    void __fastcall btnAceptarClick(TObject *Sender);
    void __fastcall btnCancelarClick(TObject *Sender);
    void __fastcall edtPasswordKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
    bool bOk;
    AnsiString sIniciales;
    __fastcall TfrmdlgLogin(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmdlgLogin *frmdlgLogin;
//---------------------------------------------------------------------------
#endif
