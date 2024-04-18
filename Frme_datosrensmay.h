//---------------------------------------------------------------------------


#ifndef Frme_datosrensmayH
#define Frme_datosrensmayH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFrame_datosrensmay : public TFrame
{
__published:	// IDE-managed Components
        TLabel *Label8;
        TEdit *edt_codigo;
        TLabel *lbl_canti;
        TdxCurrencyEdit *edt_canti;
        TLabel *lbl_folio;
        TdxEdit *edt_folios;
        TLabel *lbl_serie;
        TListBox *lst_series;
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_PuntoVta;
        TDataSource *dts_puntovta;
        TDataSource *dts_vendedor;
        TQuery *qry_vendedor;
        TDataSource *dts_poblacion;
        TQuery *qry_Poblacion;
        TQuery *qry_ultfol;
        TQuery *qry_folsel;
        TUpdateSQL *uqry_folsel;
        TDBEdit *dbedt_descriinven;
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall edt_cantiExit(TObject *Sender);
        void __fastcall edt_codigoExit(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosrensmay(TComponent* Owner);
        void __fastcall pide_series();
        void __fastcall inicializa(String tipo_z);

        int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, pagina_z;
        String sDescriEnt, sTipo, mensaje_z, este_z, titulo_z,
        cerrado_z, accion_z, alm_z, modoframe_z,
        titmsg_z, genero_z, permis_z;
        TDateTime fecha_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosrensmay *Frame_datosrensmay;
//---------------------------------------------------------------------------
#endif
