//---------------------------------------------------------------------------

#ifndef Frm_mantoalmH
#define Frm_mantoalmH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ActnList.hpp>
#include <ComCtrls.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include <DBCtrls.hpp>
#include "dxDBELib.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_mantoalm : public TForm
{
__published:	// IDE-managed Components
        TQuery *qry_clien;
        TUpdateSQL *uqry_clien;
        TToolBar *ToolBar1;
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
        TToolButton *ToolButton2;
  TQuery *qry_ciudades;
  TDataSource *dts_ciudades;
        TDataSource *dts_clien;
        TAction *exportar;
        TdxDBGrid *dbgrd_clien;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
        TMenuItem *Borra1;
        TSpeedButton *SpeedButton2;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TSpeedButton *SpeedButton6;
        TSpeedButton *SpeedButton7;
        TSpeedButton *SpeedButton8;
        TSpeedButton *SpeedButton9;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton5;
        TAction *generar_html;
        TMenuItem *Nuevo1;
        TMenuItem *Modifica1;
        TMenuItem *GeneraHTML1;
        TdxDBGridMaskColumn *dbgrd_clienCLAVE;
        TdxDBGridMaskColumn *dbgrd_clienNOMBRE;
        TdxDBGridMaskColumn *dbgrd_clienDIREC;
        TdxDBGridMaskColumn *dbgrd_clienORDIARY;
        TdxDBGridMaskColumn *dbgrd_clienEXIB;
        TdxDBGridMaskColumn *dbgrd_clienZONA;
        TdxDBGridMaskColumn *dbgrd_clienORDTABT;
        TdxDBGridMaskColumn *dbgrd_clienSTATUS;
        TQuery *qry_relubiptovta;
        TDataSource *dts_relubiptovta;
        TUpdateSQL *uqry_ubiptovta;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall generar_htmlExecute(TObject *Sender);
        void __fastcall dbgrd_clienDblClick(TObject *Sender);
        void __fastcall dbgrd_clienKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantoalm(TComponent* Owner);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall alta_vnd(int modo_z);
        void __fastcall modif_vnd();
        void __fastcall busca_vnd(String vnd_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall desp_vnd();
        int __fastcall busca_iddato(String text_z, int tipodato_z);
        void __fastcall asigna_tipo(String tipo_z);

        int cia_z, ordtab_z, ordiary_z;
        String permis_z, clave_z, nombre_z, direc_z, exib_z, zona_z, tipo_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantoalm *Form_mantoalm;
//---------------------------------------------------------------------------
#endif
