//---------------------------------------------------------------------------


#ifndef Frme_imginvenH
#define Frme_imginvenH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <Buttons.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <Dialogs.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFrame_imginven : public TFrame
{
__published:	// IDE-managed Components
        TPanel *pnl_imagen;
        TGroupBox *grp_ajustaimg;
        TCheckBox *chk_ajustaimg;
        TScrollBox *scroll_boximg;
        TImage *img_principal;
        TActionList *ActionList1;
        TAction *ajusta_imagen;
        TAction *cambia_imagen;
        TBitBtn *btn_cambiaimg;
        TSplitter *Splitter1;
        TGroupBox *grp_listasimagenes;
        TdxDBGrid *dbgrd_imagenes;
        TdxDBGridMaskColumn *dbgrd_imagenesIDMAGEN;
        TdxDBGridMaskColumn *dbgrd_imagenesNOMARCH;
        TQuery *qry_folsel;
        TUpdateSQL *uqry_folsel;
        TDataSource *dts_folsel;
        TPanel *Panel1;
        TLabel *Label1;
        TEdit *edt_dirbaselan;
        TLabel *Label2;
        TEdit *edt_dirpython;
        TGroupBox *grp_fotosact;
        TMemo *mmo_fotos_actualizadas;
        TAction *agregar_imagen;
        TBitBtn *BitBtn1;
        void __fastcall ajusta_imagenExecute(TObject *Sender);
        void __fastcall cambia_imagenExecute(TObject *Sender);
        void __fastcall qry_folselAfterScroll(TDataSet *DataSet);
        void __fastcall agregar_imagenExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_imginven(TComponent* Owner);
        void __fastcall busca_ptvt(String ptvt_z);
        void __fastcall carga_imagen();
        void __fastcall carga_interactivo();
        void __fastcall agregar_o_cambiar_imagen(String modo_z);
        String dirpython_z, directorioimgs_z, codigo_z, linea_z;
        int numimgs_z, idimg_z, estadoimg_z;

};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_imginven *Frame_imginven;
//---------------------------------------------------------------------------
#endif
