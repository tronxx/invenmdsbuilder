//---------------------------------------------------------------------------


#ifndef Frme_datoscappedmagrnuevoH
#define Frme_datoscappedmagrnuevoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_datoscappedmagrnuevo : public TFrame
{
__published:	// IDE-managed Components
        TEdit *edt_codigo;
        TLabel *Label8;
        TEdit *edt_descri;
        TLabel *Label12;
        TdxCurrencyEdit *edt_canti;
        TLabel *lbl_costo;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_preciomaypro;
        TdxCurrencyEdit *edt_costou;
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall edt_codigoExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscappedmagrnuevo(TComponent* Owner);
        int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z,
        pagina_z, tipomayoris_z;
        AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
        titmsg_z, genero_z;
        double __fastcall calcu_prvta();
        void __fastcall busca_cod(String codigo_z);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscappedmagrnuevo *Frame_datoscappedmagrnuevo;
//---------------------------------------------------------------------------
#endif
