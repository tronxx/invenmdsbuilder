//---------------------------------------------------------------------------

#ifndef Frm_mantciuH
#define Frm_mantciuH
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
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include "dxExEdtr.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
//---------------------------------------------------------------------------
class TForm_mantciu : public TForm
{
__published:	// IDE-managed Components
        TToolBar *ToolBar1;
        TToolButton *ToolButton3;
        TQuery *qry_ciudades;
        TUpdateSQL *uqry_poblacs;
        TActionList *ActionList1;
        TAction *nuevo;
        TAction *modifica;
        TAction *borra;
        TAction *grabar;
        TAction *cancelar;
        TWindowClose *WindowClose1;
        TAction *primero;
        TAction *anterior;
        TAction *siguiente;
        TAction *ultimo;
        TDataSource *dts_ciudades;
        TAction *exporta;
        TAction *importa;
        TQuery *qry_modif;
        TQuery *qry_inserta;
        TQuery *qry_borra;
        TdxDBGrid *dbgrd_ciudades;
        TdxDBGridMaskColumn *dbgrd_ciudadesCIUDAD;
        TdxDBGridMaskColumn *dbgrd_ciudadesESTADO;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton5;
        TQuery *qry_estado;
        TQuery *qry_carrelpob;
        TUpdateSQL *uqry_carrelpob;
        TUpdateSQL *uqry_estado;
        TdxDBGridMaskColumn *dbgrd_ciudadesSTATUS;
        TdxDBGridDateColumn *dbgrd_ciudadesFECBAJ;
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall exportaExecute(TObject *Sender);
        void __fastcall importaExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall dbgrd_ciudadesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantciu(TComponent* Owner);
        void __fastcall desp_ptvt();
        void __fastcall alta_ptvt(int modo_z);
        void __fastcall modif_ptvt();
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall AsignaTipo(int TIPO_MANTO);
        void __fastcall agrega_rel_pob(int idciu_z, int idestado_z);


        int cia_z, tipodato_z, idtipodato_z, tiporel_z, mantotipo_z;
        String permis_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantciu *Form_mantciu;
//---------------------------------------------------------------------------
#endif
