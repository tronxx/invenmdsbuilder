//---------------------------------------------------------------------------

#ifndef SelectdbH
#define SelectdbH
//---------------------------------------------------------------------------
#include <ToolWin.hpp>
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "RzBorder.hpp"
#include "RzButton.hpp"
#include "RzCmboBx.hpp"
#include "RzLabel.hpp"
#include <StdActns.hpp>
//---------------------------------------------------------------------------
class TfrmSelecciondb : public TForm
{
__published:	// IDE-managed Components
    TRzComboBox *cmbBasedatos;
    TRzLabel *RzLabel1;
    TRzBorder *RzBorder1;
    TRzBitBtn *btnAceptar;
    TRzBitBtn *btnCerrar;
    void __fastcall btnCerrarClick(TObject *Sender);
    void __fastcall btnAceptarClick(TObject *Sender);
    void __fastcall FormShow(TObject *Sender);
private:	// User declarations
public:		// User declarations
    __fastcall TfrmSelecciondb(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmSelecciondb *frmSelecciondb;
//---------------------------------------------------------------------------
#endif
