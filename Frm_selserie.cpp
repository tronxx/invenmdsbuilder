//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_selserie.h"
#include "Frme_datosmarca.h"
#include "dmod.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
#pragma resource "*.dfm"
TForm_selserie *Form_selserie;
//---------------------------------------------------------------------------
__fastcall TForm_selserie::TForm_selserie(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::sel_primeros_folios(int cuantos_z)
{
  for(int ii_z = 0; ii_z < cuantos_z; ii_z++) {
    qry_foldisp->First(); SeleccionaExecute(this);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::permitir_seleccionar(bool siono_z)
{
  Selecciona->Enabled = siono_z;
  Elimina->Enabled = siono_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::SeleccionaExecute(TObject *Sender)
{
//  (CODIGO, IDART, IDMOVART, IDALM, COSTO, MODENT, FOLIO, IDSERIE, FECHA,
//   SERIE, ENTCAN, FECENTORI, FACPRO, IDPROVE)
  String serie_z, folio_z;
  if(qry_foldisp->IsEmpty()) return;
  if( seriesel_z + 1 > nseries_z) {
    if(Application->MessageBox("El numero de Series que seleccionó es mayor al que debería, desea seccionarlo de todas formas ?", "Verificar series", MB_YESNO+MB_ICONQUESTION) == IDNO)
      return;
  }
  serie_z = qry_foldisp->FieldByName("serie")->AsString;
  folio_z = qry_foldisp->FieldByName("folio")->AsString;
  if(tipoinv_z == "ALF" && serie_z.IsEmpty()) {
    bool serieok_z=true;
    int ancho_z, alto_z;
    Tdlg_okcancel *Dlg_analipol;
    Dlg_analipol = new Tdlg_okcancel (this);
    Dlg_analipol->AutoSize = false;
    TFrame_datosmarca *Frame_datosmarca;
    Frame_datosmarca = new TFrame_datosmarca (Dlg_analipol);
    ancho_z = Frame_datosmarca->Width + 20;
    alto_z = Frame_datosmarca->Height + Dlg_analipol->Panel2->Height + 80;
    Frame_datosmarca->Parent = Dlg_analipol->Panel1;
    Frame_datosmarca->lbl_codigo->Caption = "Folio";
    Frame_datosmarca->edt_codigo->Text = folio_z;
    Frame_datosmarca->edt_codigo->ReadOnly = true;
    Frame_datosmarca->lbl_nombre->Caption = "Serie:";
    Frame_datosmarca->edt_nombre->MaxLength = 20;
    Dlg_analipol->Width = ancho_z;
    Dlg_analipol->Height = alto_z;
    Dlg_analipol->Caption = "Datos";
    Dlg_analipol->Position = poScreenCenter;
    if( Dlg_analipol->ShowModal() == mrOk) {
      serie_z = Frame_datosmarca->edt_nombre->Text.Trim();
      serieok_z = true;
    }
    delete Dlg_analipol;
    if(!serieok_z) return;
  }

  qry_folsel->Append();
  qry_folsel->FieldByName("codigo")->Value = qry_foldisp->FieldByName("codigo")->Value;
  //qry_folsel->FieldByName("idart")->Value = qry_foldisp->FieldByName("idart")->Value;
  //qry_folsel->FieldByName("idmovart")->Value = qry_foldisp->FieldByName("idmovart")->Value;
  qry_folsel->FieldByName("almac")->Value = qry_foldisp->FieldByName("almac")->Value;
  qry_folsel->FieldByName("costo")->Value = qry_foldisp->FieldByName("costo")->Value;
  qry_folsel->FieldByName("modent")->Value = qry_foldisp->FieldByName("modent")->Value;
  qry_folsel->FieldByName("folio")->Value = qry_foldisp->FieldByName("folio")->Value;
  qry_folsel->FieldByName("serie")->Value = serie_z;
  qry_folsel->FieldByName("fecha")->Value = qry_foldisp->FieldByName("fecha")->Value;
  qry_folsel->FieldByName("entcan")->Value = qry_foldisp->FieldByName("entcan")->Value;
  qry_folsel->FieldByName("fecentori")->Value = qry_foldisp->FieldByName("fecentori")->Value;
  qry_folsel->FieldByName("facpro")->Value = qry_foldisp->FieldByName("facpro")->Value;
  qry_folsel->FieldByName("prove")->Value = qry_foldisp->FieldByName("prove")->Value;
  qry_folsel->Post();
  qry_foldisp->Delete();
  seriesel_z++;

}
//---------------------------------------------------------------------------
void __fastcall TForm_selserie::FormResize(TObject *Sender)
{
  //grp_foldisp->Width = ( Width - pnl_centro->Width ) / 2;
}
//---------------------------------------------------------------------------


void __fastcall TForm_selserie::busca_series(String codigo_z, String alm_z, int numseries, TDateTime fecha)
{
  TDateTime fechabus_z = fecha;
  String fecstr_z = DateToStr(fecha);
  if(fechaabierta_z == "S") {
    fechabus_z = IncMonth(fechabus_z, 120);
  }
  fecstr_z = DateToStr(fechabus_z);
  qry_foldisp->Close();
  qry_foldisp->ParamByName("codigo")->AsString = codigo_z;
  qry_foldisp->ParamByName("alm")->AsString = alm_z;
  qry_foldisp->ParamByName("fechaent")->AsDateTime = fechabus_z;
  qry_foldisp->Open();
  qry_folsel->Close();
  qry_folsel->Open();
  seriesel_z = 0;
  nseries_z = numseries;

}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::EliminaExecute(TObject *Sender)
{
//  (CODIGO, IDART, IDMOVART, IDALM, COSTO, MODENT, FOLIO, IDSERIE, FECHA,
//   SERIE, ENTCAN, FECENTORI, FACPRO, IDPROVE)
  if(qry_folsel->IsEmpty()) return;
  qry_foldisp->Append();
  qry_foldisp->FieldByName("codigo")->Value = qry_folsel->FieldByName("codigo")->Value;
  //qry_foldisp->FieldByName("art")->Value = qry_folsel->FieldByName("idart")->Value;
  //qry_foldisp->FieldByName("idmovart")->Value = qry_folsel->FieldByName("idmovart")->Value;
  qry_foldisp->FieldByName("almac")->Value = qry_folsel->FieldByName("almac")->Value;
  qry_foldisp->FieldByName("costo")->Value = qry_folsel->FieldByName("costo")->Value;
  qry_foldisp->FieldByName("modent")->Value = qry_folsel->FieldByName("modent")->Value;
  qry_foldisp->FieldByName("folio")->Value = qry_folsel->FieldByName("folio")->Value;
  qry_foldisp->FieldByName("serie")->Value = qry_folsel->FieldByName("serie")->Value;
  qry_foldisp->FieldByName("fecha")->Value = qry_folsel->FieldByName("fecha")->Value;
  qry_foldisp->FieldByName("serie")->Value = qry_folsel->FieldByName("serie")->Value;
  qry_foldisp->FieldByName("entcan")->Value = qry_folsel->FieldByName("entcan")->Value;
  qry_foldisp->FieldByName("fecentori")->Value = qry_folsel->FieldByName("fecentori")->Value;
  qry_foldisp->FieldByName("facpro")->Value = qry_folsel->FieldByName("facpro")->Value;
  qry_foldisp->FieldByName("prove")->Value = qry_folsel->FieldByName("prove")->Value;
  qry_foldisp->Post();
  qry_folsel->Delete();
  seriesel_z--;
}
//---------------------------------------------------------------------------


void __fastcall TForm_selserie::btn_cancelarClick(TObject *Sender)
{
    seriesel_z = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::btn_aceptarClick(TObject *Sender)
{
  if( seriesel_z != nseries_z) {
    if(Application->MessageBox("El numero de Series que seleccionó no es el que debería, desea salir de todas formas ?", "Verificar series", MB_YESNO+MB_ICONQUESTION) == IDNO)
    ModalResult = mrNone;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::dxDBGrid1KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_SPACE) SeleccionaExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::dxDBGrid2KeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_SPACE) EliminaExecute(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::dxDBGrid1DblClick(TObject *Sender)
{
  SeleccionaExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_selserie::dxDBGrid2DblClick(TObject *Sender)
{
  EliminaExecute(Sender);
}
//---------------------------------------------------------------------------


void __fastcall TForm_selserie::dxDBGrid1CustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
        
}
//---------------------------------------------------------------------------

