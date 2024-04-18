//---------------------------------------------------------------------------

#ifndef Frm_cvtaubiH
#define Frm_cvtaubiH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ComCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <Buttons.hpp>
#include <Menus.hpp>
#include <ActnList.hpp>
#include <stdio.h>
//---------------------------------------------------------------------------
class TForm_cvtaubi : public TForm
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TdxDBGrid *dbgrd_renglones;
        TQuery *qry_analisma;
        TUpdateSQL *uqry_gpodiary;
        TDataSource *dts_analisma;
        TdxDBGridMaskColumn *dbgrd_renglonesLINEA;
        TdxDBGridMaskColumn *dbgrd_renglonesCODIGO;
        TdxDBGridMaskColumn *dbgrd_renglonesDESCRI;
        TdxDBGridMaskColumn *dbgrd_renglonesEMPAQE;
        TdxDBGridMaskColumn *dbgrd_renglonesUNIDS;
        TdxDBGridCurrencyColumn *dbgrd_renglonesCOSTOTOT;
        TRadioGroup *grp_netobru;
        TRadioGroup *grp_statcan;
        TRadioGroup *grp_statsino;
        TPanel *Panel2;
        TPopupMenu *PopupMenu1;
        TMenuItem *Exportara1;
        TActionList *ActionList1;
        TAction *exporta_dbgrd;
        TAction *imprimir_reporte;
        TQuery *qry_analixalm;
        TQuery *qry_analixart;
        TQuery *qry_lineas;
        TLabel *Label1;
        TDateTimePicker *date_fecini;
        TLabel *Label2;
        TDateTimePicker *date_fecfin;
        TBitBtn *BitBtn1;
        TMenuItem *Imprimir1;
        TQuery *qry_acumxsit;
        TQuery *qry_acumxlin;
        TQuery *qry_acumxpvt;
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall exporta_dbgrdExecute(TObject *Sender);
        void __fastcall imprimir_reporteExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_cvtaubi(TComponent* Owner);
        void __fastcall agrega_invtpvtatmp(int idtpvtatmp_z, int idtipovta_z, int factor_z, String tipoent_z);
        void __fastcall impri_renglon(String codigo_z, String situacion_z);
        void __fastcall elimina_invtmp();
        void __fastcall report_subtotxlinea();
        void __fastcall report_encab();
        void __fastcall report_subencab();
        void __fastcall salta_linea();
        void __fastcall graba_invtmp();
        void __fastcall busca_ubicaciones_x_linea(String linea_z);
        bool __fastcall checa_saltopag(int numero_de_lineas);
        void __fastcall reporte_datos_x_sit();
        void __fastcall report_subencab_sit();

        int cia_z, idtarea_z, lineas_z, pagina_z, primero_z;
        String antlin_z, linea_z, enc_z;
        double totcosxlin_z;
        FILE *archout;
};
//---------------------------------------------------------------------------
extern PACKAGE TForm_cvtaubi *Form_cvtaubi;
//---------------------------------------------------------------------------
#endif
