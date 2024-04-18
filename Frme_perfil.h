//---------------------------------------------------------------------------


#ifndef Frme_perfilH
#define Frme_perfilH
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
class TFrame_perfil : public TFrame
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *Label1;
        TLabel *Label2;
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
        TQuery *qry_perfiles;
        TDataSource *dts_perfiles;
        TLabel *Label10;
        TDBLookupComboBox *lkcmb_perfil;
        TEdit *edt_clave;
        TEdit *edt_descri;
        TBitBtn *BitBtn1;
        TAction *agregar_permi;
        TLabel *Label3;
        TDBLookupComboBox *lkcmb_permisos;
        void __fastcall dbgrd_permisKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall exportarExecute(TObject *Sender);
        void __fastcall agregar_permiExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_perfil(TComponent* Owner);
        void __fastcall inicializa(int miidperfil_z);
        void __fastcall agrega_todas_las_permisiones(int miidperfil_z);
        int cia_z, idproyec_z, idperfil_z, ultimodidperfildet_z;


};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_perfil *Frame_perfil;
//---------------------------------------------------------------------------
#endif
