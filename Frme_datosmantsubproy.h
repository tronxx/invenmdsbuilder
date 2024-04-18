//---------------------------------------------------------------------------


#ifndef Frme_datosmantsubproyH
#define Frme_datosmantsubproyH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
//---------------------------------------------------------------------------
class TFrame_datosmantsubproy : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label2;
        TLabel *Label1;
        TdxEdit *edt_acu;
        TLabel *Label3;
        TdxEdit *edt_ptv;
        TComboBox *cmb_tipo;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosmantsubproy(TComponent* Owner);
        int __fastcall busca_idtipo(String tipo_z);

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosmantsubproy *Frame_datosmantsubproy;
//---------------------------------------------------------------------------
#endif
