//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_dircli.h"
#include "dmod.h"
#include "numapal.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"
TFrame_dircli *Frame_dircli;
const int  NOMBRE_CLIENTE  = 1,
           DIREC_CLIENTE   = 2,
           POBLACION       = 3,
           NOMBRE_AVAL     = 4,
           DIREC_AVAL      = 5,
           PUNTO_VENTA     = 6,
           QMC             = 7,
           TICTE           = 8,
           NUMFAC          = 9,
           JEFGPO          =10,
           COMISIJEFGPO    =11,
           FEPAGJEFGPO     =12,
           OPCION          =13,
           CUMPLE          =14,
           SERVICIO        =15,
           ENGANCHE        =16,
           SALDOENG        =17,
           NUMLETRAS       =18,
           IMPXLETRA       =19,
           IMPBONIF        =20,
           PRECIOLIS       =21,
           CAMBIO_CODIGO   =22,
           TASADESCTO      =23,
           STATUSCLI       =24,
           CAMBIO_IDCLI    =25,
           CAMBIO_FECHAVTA =26,
           DIREC2_CLIENTE  =27,
           TIPO_MOV_REPORTE=28,
           LINEA_SERV      =29,
           RUTAS_SERV      =30,
           STRING          =1,
           PESOS           =2,
           ENTERO          =3,
           PORCENTAJE      =4,
           BOOLEANO        =5,
           FRME_DIRCLI     =6;

//---------------------------------------------------------------------------
__fastcall TFrame_dircli::TFrame_dircli(TComponent* Owner)
        : TFrame(Owner)
{
  cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------
void __fastcall TFrame_dircli::selecciona_tipodato(String mitipodato_z, String datoini_z)
{
  int tipodato_z;
  tipodato_z = mitipodato_z.ToIntDef(0);
  TLocateOptions Opts;
  Opts.Clear();
  TStringList *campos_z = new TStringList();
  TStringList *titulos_z = new TStringList();
  String qom_z, ticte_z;
  tipo_z = tipodato_z;
  antdato_z = datoini_z;
  if(mitipodato_z == "MAYORIS") {
      edt_dircli->Visible = false;
      edt_dircli2->Visible = false;
      lkcmb_poblac->Visible = false;
      edt_letras->Visible = false;
      lkcmb_tipotarjeta->Visible = false;
      edt_colonia->Visible = false;
      edt_codpost->Visible = false;
      qry_poblac->Close();
      qry_poblac->SQL->Text = "select codigo, nombre \
      from mayoris a where a.cia = :CIA and status = 'A' \
      order by nombre";
      qry_poblac->ParamByName("cia")->AsInteger = cia_z;
      qry_poblac->Open();
      dbgrd_poblacs->Visible = true;
      dbgrd_poblacs->Align = alClient;
      dbgrd_poblacs->DataSource = dts_poblac;
      dbgrd_poblacs->KeyField = "nombre";
      campos_z->Add("codigo"); titulos_z->Append("Código");
      campos_z->Add("nombre"); titulos_z->Append("Nombre");
      agrega_campos(campos_z, titulos_z);
      qry_poblac->Locate("codigo", datoini_z, Opts);
  }
  if (mitipodato_z == "DIREC") {
      qry_poblac->Close();
      qry_poblac->Open();

      lbl_dato->Caption = "Calle y Cruzmtos";
      edt_dircli->Visible = true;
      lbl_dato->Left = edt_dircli->Left - 2 - lbl_dato->Width;

      edt_dircli2->Visible = true;
      lbl_dato2->Caption = "Num.Predio";
      lbl_dato2->Top = edt_dircli2->Top + 3;
      lbl_dato2->Left = edt_dircli2->Left - 2 - lbl_dato2->Width;
      lbl_dato2->Visible = true;


      edt_colonia->Left = edt_dircli2->Left;
      edt_colonia->Top  = edt_dircli2->Top + 4 + edt_dircli2->Height;
      edt_colonia->Visible = true;
      lbl_dato3->Caption = "Colonia";
      lbl_dato3->Top = edt_colonia->Top + 3;
      lbl_dato3->Left = edt_colonia->Left - 2 - lbl_dato3->Width;
      lbl_dato3->Visible = true;

      edt_codpost->Left = edt_colonia->Left;
      edt_codpost->Top  = edt_colonia->Top + 4 + edt_colonia->Height;
      edt_codpost->Visible = true;
      lbl_letras->Caption = "Codigo Postal";
      lbl_letras->Top = edt_codpost->Top + 3;
      lbl_letras->Left = edt_codpost->Left - 2 - lbl_letras->Width;
      lbl_letras->Visible = true;
      lkcmb_poblac->Top = edt_codpost->Top + 4 + edt_codpost->Height;
      lkcmb_poblac->Visible = true;
      lkcmb_poblac->TabOrder = edt_codpost->TabOrder + 1;
      lbl_tipotarjeta->Top = lkcmb_poblac->Top + 3;
      lbl_tipotarjeta->Caption = "Ciudad";
      lbl_tipotarjeta->Left = lkcmb_poblac->Left - lbl_tipotarjeta->Width - 3;
      lbl_tipotarjeta->Visible = true;
  }
  if(mitipodato_z == "TIPOPAGO") {
      qry_poblac->Close();
      qry_poblac->SQL->Text = "select idtipago, clave, descri \
      from car_tipagocfdi a where status = 'A' \
      order by clave ";
      qry_poblac->Open();
      dbgrd_poblacs->Visible = true;
      dbgrd_poblacs->Align = alClient;
      dbgrd_poblacs->DataSource = dts_poblac;
      dbgrd_poblacs->KeyField = "clave";
      campos_z->Add("clave"); titulos_z->Append("Clave");
      campos_z->Add("descri"); titulos_z->Append("Descripción");
      agrega_campos(campos_z, titulos_z);
      qry_poblac->Locate("clave", datoini_z, Opts);
  }
  delete campos_z;
  delete titulos_z;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_dircli::agrega_campos(TStringList *campos_z, TStringList *titulos_z)
{
  for(int ii_z = 0; ii_z < campos_z->Count; ii_z++) {
    TdxDBGridMaskColumn *column;
    column = new TdxDBGridMaskColumn (this);
    column->ATreeList = dbgrd_poblacs;
    column->FieldName = campos_z->Strings[ii_z];
    column->Caption = titulos_z->Strings[ii_z];
  }
}
//---------------------------------------------------------------------------


String __fastcall TFrame_dircli::obten_resultado(String mitipodato_z)
{
  String resultado_z="";
  if(mitipodato_z == "MAYORIS") {
     resultado_z = qry_poblac->FieldByName("codigo")->AsString;
  }
  if(mitipodato_z == "TIPOPAGO") {
     resultado_z = qry_poblac->FieldByName("clave")->AsString;
  }
  return (resultado_z);
}
//---------------------------------------------------------------------------


void __fastcall TFrame_dircli::asignar_cvetar()
{

}
//---------------------------------------------------------------------------


