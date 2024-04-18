//---------------------------------------------------------------------------

#ifndef dlgCnsProvesH
#define dlgCnsProvesH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include "dxCntner.hpp"
#include "dxDBCtrl.hpp"
#include "dxDBGrid.hpp"
#include "dxTL.hpp"
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Mask.hpp>
#include <Buttons.hpp>
//---------------------------------------------------------------------------
String __fastcall ConsultaProveedores(TForm *Padre);
//---------------------------------------------------------------------------
class TfrmDlgConsProve : public TForm
{
__published:	// IDE-managed Components
    TPanel *RzPanel1;
    TLabel *RzLabel1;
    TLabel *RzLabel2;
    TEdit *edtClave;
    TEdit *edtNombre;
    TBitBtn *btnEjecutar;
    TBitBtn *btnCerrar;
    TCheckBox *chkColumnas;
    TQuery *qsNombre;
    TDataSource *dtsNombre;
    TdxDBGrid *dxDBGrid1;
    TStringField *qsNombreCODIGO;
    TStringField *qsNombreNOMBRE;
    TStringField *qsNombreDIREC;
    TStringField *qsNombreCIU;
    TStringField *qsNombreRFC;
    TStringField *qsNombreTEL;
    TFloatField *qsNombreCARGOS;
    TFloatField *qsNombreABONOS;
    TFloatField *qsNombreCOMPRAANU;
    TFloatField *qsNombreCOMPRAMES;
    TFloatField *qsNombreLIMITE;
    TStringField *qsNombreCONTACTO;
    TIntegerField *qsNombreULTMOV;
    TStringField *qsNombreSTATUS;
    TSmallintField *qsNombreCIA;
    TdxDBGridMaskColumn *dxDBGrid1CODIGO;
    TdxDBGridMaskColumn *dxDBGrid1NOMBRE;
    TdxDBGridMaskColumn *dxDBGrid1DIREC;
    TdxDBGridMaskColumn *dxDBGrid1CIU;
    TdxDBGridMaskColumn *dxDBGrid1RFC;
    TdxDBGridMaskColumn *dxDBGrid1TEL;
    TdxDBGridMaskColumn *dxDBGrid1CARGOS;
    TdxDBGridMaskColumn *dxDBGrid1ABONOS;
    TdxDBGridMaskColumn *dxDBGrid1COMPRAANU;
    TdxDBGridMaskColumn *dxDBGrid1COMPRAMES;
    TdxDBGridMaskColumn *dxDBGrid1LIMITE;
    TdxDBGridMaskColumn *dxDBGrid1CONTACTO;
    TdxDBGridMaskColumn *dxDBGrid1ULTMOV;
    TdxDBGridMaskColumn *dxDBGrid1STATUS;
    TdxDBGridMaskColumn *dxDBGrid1CIA;
    void __fastcall btnEjecutarClick(TObject *Sender);
    void __fastcall chkColumnasClick(TObject *Sender);
    void __fastcall dxDBGrid1KeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall edtNombreKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
    void __fastcall btnCerrarClick(TObject *Sender);
private:	// User declarations
    void __fastcall MostrarColumnas(bool bb);
public:		// User declarations
    bool bOk;
    __fastcall TfrmDlgConsProve(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TfrmDlgConsProve *frmDlgConsProve;
//---------------------------------------------------------------------------
#endif
