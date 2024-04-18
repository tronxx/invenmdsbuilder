//---------------------------------------------------------------------------


#ifndef Frme_agregarelacH
#define Frme_agregarelacH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <ExtCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
//---------------------------------------------------------------------------
class TFrame_agregarelac : public TFrame
{
__published:	// IDE-managed Components
        TQuery *qry_tablas;
        TGroupBox *GroupBox1;
        TLabel *Label1;
        TLabel *lbl_tabla;
        TGroupBox *GroupBox2;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *edt_rela;
        TEdit *edt_descrip;
        TEdit *edt_observ;
        TDataSource *dts_tablas;
        TQuery *qry_columns;
        TGroupBox *GroupBox3;
        TListBox *ListBox1;
        TGroupBox *GroupBox4;
        TdxDBGrid *dbgrd_polizas;
        TdxDBGridMaskColumn *dbgrd_polizasTABLA;
        TdxDBGridMaskColumn *dbgrd_polizasENDESUSO;
        TGroupBox *GroupBox5;
        TListBox *lista_colum;
        TEdit *edt_idrel;
        TQuery *qry_tablarel;
        TEdit *edt_tablarel;
        void __fastcall qry_tablasAfterScroll(TDataSet *DataSet);
private:	// User declarations
public:		// User declarations
        __fastcall TFrame_agregarelac(TComponent* Owner);
       
      
        String tabla_z,sql_z,ver_z,columna_z;
};
//---------------------------------------------------------------------------
extern PACKAGE TFrame_agregarelac *Frame_agregarelac;
//---------------------------------------------------------------------------
#endif
