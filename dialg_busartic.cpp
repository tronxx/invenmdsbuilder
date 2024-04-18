//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "dialg_busartic.h"
#include <inifiles.hpp>
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"
Tdlg_busartic *dlg_busartic;
//---------------------------------------------------------------------------
__fastcall Tdlg_busartic::Tdlg_busartic(TComponent* Owner)
        : TForm(Owner)
{
  String config_z;
  TIniFile *ini;
  int busxexis_z = 1;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z);
  busxexis_z = ini->ReadInteger("BUSQUEDAS", "BUSXEXIS", 0);
  if(busxexis_z == 0) { eximin_z = 0; eximax_z = 0; }
  if(busxexis_z == 1) { eximin_z = 1; eximax_z = 100000; }
  if(busxexis_z == 2) { eximin_z = 0; eximax_z = 100000; }
  delete ini;

}
//---------------------------------------------------------------------------
void __fastcall Tdlg_busartic::edt_codigoKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
    busca_artic(edt_codigo->Text.Trim() + "%", "-1");
    dbgrd_inven->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_busartic::busca_artic(String codigo_z, String descri_z)
{
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("descri")->AsString = descri_z;
  qry_inven->ParamByName("cia")->AsInteger = dm->cia_z;
  qry_inven->ParamByName("eximin")->AsInteger = eximin_z;
  qry_inven->ParamByName("eximax")->AsInteger = eximax_z;
  qry_inven->Open();
}
//---------------------------------------------------------------------------
void __fastcall Tdlg_busartic::edt_descriKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
    busca_artic("-1", edt_descri->Text.Trim() + "%");
    dbgrd_inven->SetFocus();
  }
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_busartic::qry_invenAfterScroll(TDataSet *DataSet)
{
  edt_codigo->Text = qry_inven->FieldByName("codigo")->AsString;
  edt_descri->Text = qry_inven->FieldByName("descri")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_busartic::dbgrd_invenKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_RETURN) ModalResult = mrOk;
}
//---------------------------------------------------------------------------

void __fastcall Tdlg_busartic::despliega_cambios_precios()
{
   int ii_z, cia_z;
   String campo_z, caption_z, tipocol_z, sql_z, tmp_z;
   TDateTime fechoy_z;
   fechoy_z = dm->ahora();
   cia_z = dm->cia_z;
   sql_z = "select a.fecha, a.fecini, c.codigo, c.descri, \
        b.antprmds, b.precmds, b.precelec, b.antprelec, \
        b.precioext, b.costoext, e.situacion as antsituac, \
        f.situacion as nvasituac, g.descri as garantia \
        from inv_polcampre a \
        join inv_renpolcampre b on a.idpolcampre = b.idpolcampre \
        join inv_invhist d on b.idart = d.idart and a.cia = d.cia \
        join inven c on d.codigo = c.codigo and a.cia = c.cia \
        join inv_situaciones e on b.antempaq = e.idsituac \
        join inv_situaciones f on b.nvoempaq = f.idsituac \
        join inv_garantias g on b.idgarantia = g.idgarantia \
        where a.fecha <= :FECHA and a.status = 2 and a.fecini >= :FECHA and a.cia = :CIA \
        order by a.fecha, a.fecini, c.codigo";
   // Voy a agregar las columnas
   TdxDBTreeListColumn *antcolcosto;
   pnl_articulo->Visible = false;

   antcolcosto = dbgrd_inven->ColumnByFieldName("CODIGO");
   delete antcolcosto;
   antcolcosto = dbgrd_inven->ColumnByFieldName("DESCRI");
   delete antcolcosto;
   antcolcosto = dbgrd_inven->ColumnByFieldName("PRECIO");
   delete antcolcosto;
   antcolcosto = dbgrd_inven->ColumnByFieldName("EMPAQE");
   delete antcolcosto;
   antcolcosto = dbgrd_inven->ColumnByFieldName("PIVA");
   delete antcolcosto;

   TdxDBGridMaskColumn *colmask;
   TdxDBGridCurrencyColumn *colcurr;
   Caption = "Artículos con Cambio de Precios";

   for ( int ii_z = 0; ii_z < 13; ii_z++) {
     switch (ii_z) {
       case 0: campo_z = "FECHA"; caption_z = "Fecha"; tipocol_z = "MASK"; break;
       case 1: campo_z = "FECINI"; caption_z = "Inicia"; tipocol_z = "MASK"; break;
       case 2: campo_z = "CODIGO"; caption_z = "Código"; tipocol_z = "MASK"; break;
       case 3: campo_z = "DESCRI"; caption_z = "Descripción"; tipocol_z = "MASK"; break;
       case 4: campo_z = "antprmds"; caption_z = "Ant. Precio"; tipocol_z = "CURR"; break;
       case 5: campo_z = "precmds"; caption_z = "Nvo. Precio"; tipocol_z = "CURR"; break;
       case 6: campo_z = "antprelec"; caption_z = "Ant Precio Fide"; tipocol_z = "CURR"; break;
       case 7: campo_z = "precelec"; caption_z = "Nvo Precio Fide"; tipocol_z = "CURR"; break;
       case 8: campo_z = "precioext"; caption_z = "Precio Xtensa"; tipocol_z = "CURR"; break;
       case 9: campo_z = "costoext"; caption_z = "Costo Xtensa"; tipocol_z = "CURR"; break;
       case 10: campo_z = "antsituac"; caption_z = "Ant.Situación"; tipocol_z = "MASK"; break;
       case 11: campo_z = "nvasituac"; caption_z = "Nva.Situación"; tipocol_z = "MASK"; break;
       case 12: campo_z = "garantia"; caption_z = "Garantía"; tipocol_z = "-MASK"; break;
     }
     if (tipocol_z == "MASK") {
         colmask = new TdxDBGridMaskColumn (this);
         colmask->ATreeList = dbgrd_inven;
         colmask->FieldName = campo_z;
         colmask->Caption = caption_z;
     }
     if (tipocol_z == "CURR") {
        colcurr = new TdxDBGridCurrencyColumn (this);
        colcurr->ATreeList = dbgrd_inven;
        colcurr->FieldName = campo_z;
        colcurr->Caption = caption_z;
     }
   }
   qry_inven->Close();
   qry_inven->SQL->Text = sql_z;
   qry_inven->ParamByName("fecha")->AsDateTime = fechoy_z;
   qry_inven->ParamByName("cia")->AsInteger = cia_z;
   //qry_inven->ParamByName("eximin")->AsInteger = 0;
   //qry_inven->ParamByName("eximax")->AsInteger = 0;
   qry_inven->Open();
}
//---------------------------------------------------------------------------

