//---------------------------------------------------------------------------

#ifndef dmodH
#define dmodH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ImgList.hpp>
//---------------------------------------------------------------------------
class Tdm : public TDataModule
{
__published:	// IDE-managed Components
        TDatabase *manvehi;
  TQuery *qry_ciasinv;
        TQuery *qry_fecha;
        TQuery *qry_maxidvnd;
        TQuery *qry_sigid;
        TQuery *qry_direc;
        TQuery *qry_permis;
        TQuery *qry_iddato;
        TQuery *qry_insbas;
        TQuery *qry_fonts;
        TImageList *ImageList1;
        TDatabase *db_cartera;
        TQuery *qry_ultfol;
        TQuery *qry_sigfol;
        TQuery *qry_sigrenentra;
        TDatabase *db_anuanter;
        void __fastcall DataModuleCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall Tdm(TComponent* Owner);
        TDateTime  __fastcall ahora();
        String __fastcall busca_dato(int iddato_z, int tipodato_z);
        int __fastcall busca_iddato(String text_z, int tipodato_z);
        int __fastcall busca_sigid(int tipodato_z);
        void __fastcall seldatos(int tipodato_z);
        void __fastcall conecta_db();
        String __fastcall font_impre(int impre, int font);
        double __fastcall inianuestadis();
        String __fastcall busca_inifile();
        int __fastcall ultimo_folio_disp(String alm_z, String codigo_z, TDateTime fecha_z, String fechaabierta_z);
        int __fastcall folio_siguiente(String alm_z, String codigo_z);
        void __fastcall MensajeError(String error_z, String caption_z);
        void __fastcall manda_impresion(String arch_z);
        String __fastcall busca_permision(int PERMISION);
        int __fastcall sigte_renentra(String alm_z, String tipo_z, int numero_z);
        int __fastcall sigte_entrada(String alm_z, String tipo_z, int numero_z, int HACIA_DONDE);
        double calcu_prmay(String codigo_z, int tipomayoris_z);
        void __fastcall conecta_db_anuanter();
        void __fastcall desconecta_db_anuanter();
        String __fastcall busca_permistr(String PERMISION);
        String busca_pais_estado(String tipobus_z, String poblac_z);
        String __fastcall obten_nombre(String tipo_z, String clave_z);

        int idusuario_z, cia_z, impre_z, tipoimp_z, ff_z, preview_z, idproyec_z;
        String usermaster_z, iniciales_z, userpol_z, nemp_z, diremp_z, rutaimp_z,
          sequen1_z, sequen2_z, secuen_z, nombreuse_z, tipodb_z, login_z, usuario_z,
          lineamot_z, impresora_z, config_z, bdanuanter_z, basedato_z, bdcartera_z;
        bool usrmanto_z, usrmaster_z, foliosalf_z;

};
//---------------------------------------------------------------------------
extern PACKAGE Tdm *dm;
//---------------------------------------------------------------------------
#endif
