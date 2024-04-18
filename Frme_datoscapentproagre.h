//---------------------------------------------------------------------------


#ifndef Frme_datoscapentproagreH
#define Frme_datoscapentproagreH
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
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include "dxTL.hpp"
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TFrame_datoscapentproagre : public TFrame
{
__published:	// IDE-managed Components
        TQuery *qry_inven;
        TDataSource *dts_inven;
        TQuery *qry_folsigent;
        TUpdateSQL *uqry_folsigent;
        TPanel *Panel1;
        TLabel *Label8;
        TEdit *edt_codigo;
        TDBEdit *DBEdit4;
        TLabel *Label12;
        TdxCurrencyEdit *edt_canti;
        TLabel *Label6;
        TdxCurrencyEdit *edt_costou;
        TLabel *Label10;
        TdxEdit *edt_folios;
        TQuery *qry_datosped;
        TDataSource *dts_datosped;
        TGroupBox *grp_series;
        TdxDBGrid *dbgrd_renentra;
        TdxDBGridMaskColumn *dbgrd_renentraFOLIO;
        TdxDBGridMaskColumn *dbgrd_renentraSERIE;
        TdxDBGridMaskColumn *dbgrd_renentraSERIEMOT;
        TdxDBGridMaskColumn *dbgrd_renentraPEDTO;
        TdxDBGridMaskColumn *dbgrd_renentraADUANA;
        TdxDBGridDateColumn *dbgrd_renentraFECHAPED;
        TActionList *ActionList1;
        TAction *agrega_serie;
        TAction *modifica_serie;
        TPanel *Panel2;
        TSpeedButton *SpeedButton7;
        TUpdateSQL *uqry_datosped;
        void __fastcall edt_codigoKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall edt_cantiExit(TObject *Sender);
        void __fastcall edt_codigoExit(TObject *Sender);
        void __fastcall elimina_serieExecute(TObject *Sender);
        void __fastcall modifica_serieExecute(TObject *Sender);
        void __fastcall dbgrd_renentraKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall agrega_serieExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datoscapentproagre(TComponent* Owner);
        int iTpcon, tipoest_z, cia_z, mi_entrada_z, lineas_z, pagina_z;
        AnsiString sDescriEnt, sTipo, mensaje_z, este_z, titulo_z, cerrado_z,
        titmsg_z, genero_z, alm_z;
        TDateTime fecha_z;
        void __fastcall busca_cod(String codigo_z);
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datoscapentproagre *Frame_datoscapentproagre;
//---------------------------------------------------------------------------
#endif
