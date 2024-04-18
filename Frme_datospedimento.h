//---------------------------------------------------------------------------


#ifndef Frme_datospedimentoH
#define Frme_datospedimentoH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFrame_datospedimento : public TFrame
{
__published:	// IDE-managed Components
        TLabel *lbl_serie;
        TEdit *edt_serie;
        TLabel *lbl_codigo;
        TEdit *edt_codigo;
        TLabel *lbl_seriemot;
        TEdit *edt_seriemot;
        TLabel *lbl_pedimento;
        TEdit *edt_pedimento;
        TLabel *lbl_aduana;
        TEdit *edt_aduana;
        TLabel *lbl_fechaped;
        TDateTimePicker *date_fecha;
        TQuery *qry_datosped;
        TUpdateSQL *uqry_datosped;
        TQuery *qry_idart;
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datospedimento(TComponent* Owner);
        void __fastcall agrega_datosped();
        void __fastcall busca_datosped(String codigo_z, String serie_z, String almac_z);
        void __fastcall agrega_datosped_sin_close();
        void __fastcall borra_datosped(String codigo_z, String serie_z, String almac_z);

        void __fastcall solo_serie();
        int cia_z, entrada_z, iddatosent_z;
        String alm_z, tipo_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datospedimento *Frame_datospedimento;
//---------------------------------------------------------------------------
#endif
