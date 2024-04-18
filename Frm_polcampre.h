//---------------------------------------------------------------------------

#ifndef Frm_polcampreH
#define Frm_polcampreH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "Frme_datoscaptrasp.h"
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <ComCtrls.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
#include "Frme_datospolcampre.h"
#include <Db.hpp>
#include <DBTables.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include "dxDBTLCl.hpp"
#include "dxGrClms.hpp"
#include <ExtCtrls.hpp>
#include <stdio.h>
#include <Menus.hpp>
//---------------------------------------------------------------------------
class TForm_polcampre : public TForm
{
__published:	// IDE-managed Components
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
        TAction *exporta_dbgrd;
        TAction *agreren;
        TAction *elimina_renglon;
        TAction *CierraRen;
        TAction *imprime;
        TAction *capobs;
        TAction *cierra_entrada;
        TAction *despliega_menu;
        TToolBar *ToolBar1;
        TBitBtn *BitBtn5;
        TBitBtn *BitBtn4;
        TBitBtn *BitBtn3;
        TBitBtn *BitBtn2;
        TBitBtn *BitBtn1;
        TToolButton *ToolButton3;
        TBitBtn *BitBtn9;
        TBitBtn *BitBtn7;
        TBitBtn *BitBtn8;
        TBitBtn *BitBtn6;
        TGroupBox *GroupBox1;
        TFrame_datospolcampre *Frame_datospolcampre1;
        TQuery *qry_polcampre;
        TUpdateSQL *uqry_polcampre;
        TDataSource *dts_marcas;
        TQuery *qry_renpolcampre;
        TUpdateSQL *uqry_renpolcampre;
        TDataSource *dts_renpolcampre;
        TdxDBGrid *dbgrd_renglones;
        TdxDBGridMaskColumn *dbgrd_renglonesCODIGO;
        TdxDBGridMaskColumn *dbgrd_renglonesDESCRI;
        TdxDBGridMaskColumn *dbgrd_renglonesNVOEMPAQ;
        TdxDBGridMaskColumn *dbgrd_renglonesANTEMPAQ;
        TdxDBGridMaskColumn *dbgrd_renglonesDESCRIGTIA;
        TdxDBGridMaskColumn *dbgrd_renglonesCONCEP;
        TdxDBGridCurrencyColumn *dbgrd_renglonesPRECMDS;
        TdxDBGridCurrencyColumn *dbgrd_renglonesANTPRMDS;
        TdxDBGridCurrencyColumn *dbgrd_renglonesPRECELEC;
        TdxDBGridCurrencyColumn *dbgrd_renglonesANTPRELEC;
        TPanel *Panel1;
        TBitBtn *BitBtn10;
        TQuery *qry_invrelinv;
        TUpdateSQL *uqry_invrelinv;
        TQuery *qry_invulpre;
        TUpdateSQL *uqry_invulpre;
        TQuery *qry_invxtensa;
        TUpdateSQL *uqry_invxtensa;
        TQuery *qry_observent;
        TUpdateSQL *uqry_observent;
        TQuery *qry_inven;
        TUpdateSQL *uqry_inven;
        TQuery *qry_invhist;
        TAction *despliega_renglon;
        TdxDBGridCurrencyColumn *dbgrd_renglonesMUB;
        TAction *aplica_cambios;
        TBitBtn *BitBtn11;
        TPopupMenu *PopupMenu1;
        TMenuItem *Polizas1;
        TMenuItem *Nuevo1;
        TMenuItem *Borra1;
        TMenuItem *Renglones1;
        TMenuItem *Salir1;
        TMenuItem *AgregaReng1;
        TMenuItem *EliminarRengln1;
        TMenuItem *Cierra1;
        TMenuItem *Exportara1;
        TQuery *qry_descri2;
        TQuery *qry_plazoxlin;
        TQuery *qry_plazoxprecio;
        TQuery *qry_plazoxarticulo;
        TQuery *qry_plazoxgrupo;
        TQuery *qry_servicio;
        TQuery *qry_servxgpo;
        TAction *captura_observs;
        TMenuItem *Observaciones1;
        TQuery *qry_linea;
        TQuery *qry_obsoferta;
        TAction *abrir_poliza;
        TMenuItem *AbrirPliza1;
        TBitBtn *BitBtn12;
        TAction *duplica_poliza;
        TBitBtn *BitBtn13;
        void __fastcall nuevoExecute(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
        void __fastcall primeroExecute(TObject *Sender);
        void __fastcall anteriorExecute(TObject *Sender);
        void __fastcall siguienteExecute(TObject *Sender);
        void __fastcall ultimoExecute(TObject *Sender);
        void __fastcall Frame_datospolcampre1edt_folioKeyDown(
          TObject *Sender, WORD &Key, TShiftState Shift);
        void __fastcall agrerenExecute(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall cierra_entradaExecute(TObject *Sender);
        void __fastcall imprimeExecute(TObject *Sender);
        void __fastcall despliega_renglonExecute(TObject *Sender);
        void __fastcall dbgrd_renglonesDblClick(TObject *Sender);
        void __fastcall dbgrd_renglonesKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall dbgrd_renglonesCustomDraw(TObject *Sender,
          TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
          TdxDBTreeListColumn *AColumn, const AnsiString AText,
          TFont *AFont, TColor &AColor, bool ASelected, bool AFocused,
          bool &ADone);
        void __fastcall aplica_cambiosExecute(TObject *Sender);
        void __fastcall elimina_renglonExecute(TObject *Sender);
        void __fastcall exporta_dbgrdExecute(TObject *Sender);
        void __fastcall captura_observsExecute(TObject *Sender);
        void __fastcall abrir_polizaExecute(TObject *Sender);
        void __fastcall modificaExecute(TObject *Sender);
        void __fastcall duplica_polizaExecute(TObject *Sender);
        void __fastcall borraExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm_polcampre(TComponent* Owner);
        void __fastcall agregar_modificar(int tipo_z);
        int __fastcall busca_sigfolio();
        void __fastcall SigteSabana(int HACIA_DONDE);
        void __fastcall busca_polcampre(int folio_z);
        void __fastcall agrega_obs(int conse_z, double fechapol_z, String obscam_z, String codigo_z);
        int __fastcall agrega_relinv(int idart_z, int tiporel_z, int iddatorel_z, int idrelinv_z);
        void __fastcall report_encab();
        void __fastcall report_subenc();
        void __fastcall salta_linea(int cuantas_z);
        bool __fastcall checa_salto_pag(int margen_z);
        void __fastcall aplica_cambio();
        void __fastcall busca_cambios_x_aplicar();
        void __fastcall inicializa(String tipo_z);
        String __fastcall busca_descri(String codigo_z);
        void __fastcall impresion_poliza();
        void __fastcall boletin_precios();
        void __fastcall aplica_cambio_situacion();
        int __fastcall busca_plazo(String codigo_z, String linea_z, String grupo_z, double precio_z);
        int __fastcall busca_servicio(String codigo_z);
        String __fastcall busca_descrilin(String linea_z);

        int cia_z, lineas_z, pagina_z;
        String permis_z, tipoobserv_z, tipopol_z, impenc_z,
          tiporep_z, antlinea_z;
        FILE *archout;

};
//---------------------------------------------------------------------------
extern PACKAGE TForm_polcampre *Form_polcampre;
//---------------------------------------------------------------------------
#endif
