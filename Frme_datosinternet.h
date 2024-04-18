//---------------------------------------------------------------------------


#ifndef Frme_datosinternetH
#define Frme_datosinternetH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <ActnList.hpp>
#include <Buttons.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <DBCtrls.hpp>
#include <Mask.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
//---------------------------------------------------------------------------
class TFrame_datosinternet : public TFrame
{
__published:	// IDE-managed Components
        TPanel *Panel1;
        TLabel *lbl_oferta;
        TEdit *edt_titulo;
        TGroupBox *GroupBox1;
        TMemo *mmo_descripcion;
        TActionList *ActionList1;
        TLabel *Label1;
        TAction *grabar_datosinternet;
        TBitBtn *btn_cambiagrp;
        TAction *cambiar_grupo;
        TDataSource *dts_titulo;
        TQuery *qry_titulo;
        TUpdateSQL *uqry_titulo;
        TDataSource *dts_relinv;
        TQuery *qry_relinv;
        TUpdateSQL *uqry_relinv;
        TDataSource *dts_grupointer;
        TQuery *qry_grupointer;
        TDBEdit *DBEdit1;
        TQuery *qry_idart;
        TQuery *qry_invhist;
        TDataSource *DataSource1;
        void __fastcall cambiar_grupoExecute(TObject *Sender);
        void __fastcall grabar_datosinternetExecute(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_datosinternet(TComponent* Owner);
        void __fastcall inicializa();
        void __fastcall agrega_campos(
          TStringList *campos_z, TStringList *titulos_z, TdxDBGrid *dbgrd_busqueda);
        void __fastcall graba_datos_internet();


        String codigo_z;
        int idgrupo_z, cia_z, idart_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_datosinternet *Frame_datosinternet;
//---------------------------------------------------------------------------
#endif
