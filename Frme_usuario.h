//---------------------------------------------------------------------------


#ifndef Frme_usuarioH
#define Frme_usuarioH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxEditor.hpp"
#include "dxEdLib.hpp"
#include "dxExEdtr.hpp"
#include "dxTL.hpp"
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBCtrls.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Mask.hpp>
//---------------------------------------------------------------------------
class TFrame_usuario : public TFrame
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TLabel *Label5;
        TLabel *Label7;
        TdxEdit *edt_nombre;
        TdxEdit *edt_login;
        TdxEdit *edt_passw;
        TCheckBox *chk_maestro;
        TEdit *edt_numpol;
        TdxCurrencyEdit *edt_codvnd;
        TCheckBox *chk_verpwd;
        TEdit *edt_iniciales;
        TGroupBox *grp_permisiones;
        TGroupBox *GroupBox1;
        TdxDBGrid *dbgrd_permis;
        TdxDBGridMaskColumn *dbgrd_permisDESCRIPCION;
        TdxDBGridMaskColumn *dbgrd_permisPERMIS;
        TQuery *qry_permisiones;
        TDataSource *dts_permisiones;
        TQuery *qry_permisos;
        TDataSource *dts_permisos;
        TUpdateSQL *uqry_permisos;
        TQuery *qry_permgrant;
        TDataSource *dts_permgrant;
        TUpdateSQL *uqry_permgrant;
        TActionList *ActionList1;
        TAction *exportar;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
        TCheckBox *chk_baja;
        TDateTimePicker *date_fecbaja;
        TLabel *lbl_fecbaja;
        TQuery *qry_perfiles;
        TDataSource *dts_perfiles;
        TLabel *Label10;
        TDBLookupComboBox *lkcmb_perfil;
        TDBEdit *DBEdit1;
        void __fastcall chk_verpwdClick(TObject *Sender);
        void __fastcall dbgrd_permisKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall chk_bajaClick(TObject *Sender);
        void __fastcall qry_perfilesAfterScroll(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_usuario(TComponent* Owner);
        void __fastcall inicializa(int idusuario_z);
        void __fastcall agrega_perfil_usuario(int idusuario_z);
        int idproyec_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_usuario *Frame_usuario;
//---------------------------------------------------------------------------
#endif
