//---------------------------------------------------------------------------


#ifndef Frme_nuevasseriesH
#define Frme_nuevasseriesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include "AdvGrid.hpp"
#include <Grids.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
//---------------------------------------------------------------------------
class TFrame_nuevasseries : public TFrame
{
__published:	// IDE-managed Components
        TGroupBox *GroupBox1;
        TListBox *lst_series;
        TGroupBox *GroupBox2;
        TLabel *Label9;
        TdxEdit *edt_serie;
        TActionList *ActionList1;
        TAction *agrega_serie;
        TAction *elimnar_serie;
        TAction *modificar_serie;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TGroupBox *grp_seriesvendidas;
        TAdvStringGrid *sgrd_series;
        TQuery *qry_seriesanuanter;
        TAction *cargar_series_anuant;
        TPanel *Panel1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton5;
        TAction *cargar_series_actuales;
        void __fastcall lst_seriesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall agrega_serieExecute(TObject *Sender);
        void __fastcall elimnar_serieExecute(TObject *Sender);
        void __fastcall modificar_serieExecute(TObject *Sender);
        void __fastcall edt_serieKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall sgrd_seriesSelectCell(TObject *Sender, int ACol,
          int ARow, bool &CanSelect);
        void __fastcall cargar_series_anuantExecute(TObject *Sender);
        void __fastcall cargar_series_actualesExecute(TObject *Sender);
        void __fastcall sgrd_seriesDblClickCell(TObject *Sender, int aRow,
          int aCol);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_nuevasseries(TComponent* Owner);
        void __fastcall cargar_series_vendidas();
        void __fastcall cargar_series_vendidas_x_anu(String queanu_z);

        int numseries_z, cia_z;
        String codigo_z, ptovta_z, nomcli_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_nuevasseries *Frame_nuevasseries;
//---------------------------------------------------------------------------
#endif
