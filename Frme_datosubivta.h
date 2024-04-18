//---------------------------------------------------------------------------


#ifndef Frme_datosubivtaH
#define Frme_datosubivtaH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
//---------------------------------------------------------------------------
class TFrame_datosubivta : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *edt_almac;
        TLabel *Label2;
        TEdit *edt_ptovta;
        TLabel *Label3;
        TEdit *edt_zonainv;
        TLabel *Label4;
        TLabel *Label5;
        TEdit *edt_zonaptvta;
        TLabel *Label6;
        TEdit *edt_ptvta2;
        TLabel *Label7;
        TLabel *Label8;
        TLabel *Label9;
        TEdit *edt_zonartdesp;
        TLabel *Label10;
        TLabel *Label11;
        TEdit *edt_zonapvta2;
        TLabel *Label12;
        TLabel *Label13;
        TEdit *edt_zonacar;
        TLabel *Label14;
        TLabel *Label15;
        TEdit *edt_subzoncar;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TComboBox *cmb_voc;
        TLabel *Label20;
        TLabel *Label21;
        TEdit *edt_ubica;
        TLabel *Label22;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosubivta(TComponent* Owner);
        int cia_z, tipo_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosubivta *Frame_datosubivta;
//---------------------------------------------------------------------------
#endif
