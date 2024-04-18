//---------------------------------------------------------------------------

#ifndef Frm_mantoptvtH
#define Frm_mantoptvtH
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
//---------------------------------------------------------------------------
class TForm_mantoptvt : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TQuery *qry_clien;
        TUpdateSQL *uqry_clien;
        TToolBar *ToolBar1;
        TToolButton *tbtn_nuevo;
        TToolButton *tbtn_modif;
        TToolButton *tbtn_borra;
        TToolButton *ToolButton1;
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
        TImageList *ImageList1;
        TToolButton *ToolButton2;
        TToolButton *ToolButton3;
        TToolButton *ToolButton4;
        TToolButton *ToolButton5;
        TToolButton *ToolButton6;
  TQuery *qry_ciudades;
  TDataSource *dts_ciudades;
  TToolButton *ToolButton7;
  TToolButton *ToolButton8;
        TEdit *edt_nombre;
        TEdit *edt_direc;
        TEdit *edt_codvnd;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall edt_codvndKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall grabarExecute(TObject *Sender);
        void __fastcall cancelarExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_mantoptvt(TComponent* Owner);
        void __fastcall botones_onoff(int modo_z);
        void __fastcall alta_vnd();
        void __fastcall modif_vnd();
        void __fastcall busca_vnd(String vnd_z);
        void __fastcall mueve_hacia(String sql_z);
        void __fastcall desp_vnd();
        int __fastcall busca_iddato(String text_z, int tipodato_z);
        int cia_z;
        String permis_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_mantoptvt *Form_mantoptvt;
//---------------------------------------------------------------------------
#endif
