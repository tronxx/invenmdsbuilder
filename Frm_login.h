//---------------------------------------------------------------------------

#ifndef Frm_loginH
#define Frm_loginH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
class TForm_login : public TForm
{
__published:	// IDE-managed Components
        TDatabase *dbmanvehi;
        TQuery *qry_login;
        TLabel *Label1;
        TEdit *edt_usuario;
        TLabel *Label2;
        TEdit *edt_passwd;
        TLabel *lbl_status;
        TBitBtn *btn_aceptar;
        TBitBtn *BitBtn2;
        void __fastcall btn_aceptarClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall edt_usuarioChange(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_login(TComponent* Owner);
        bool __fastcall revisar_instalacion();

        int idusuario_z;
        String usermaster_z, iniciales_z, userpol_z, login_z;
        bool ok_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_login *Form_login;
//---------------------------------------------------------------------------
#endif
