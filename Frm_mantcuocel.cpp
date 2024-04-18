//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "dmod.h"
#include "Frm_mantcuocel.h"
#include "situaciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma resource "*.dfm"
TForm_mantcuocel *Form_mantcuocel;
//---------------------------------------------------------------------------
__fastcall TForm_mantcuocel::TForm_mantcuocel(TComponent* Owner)
    : TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantcuocel::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTCOUCEL);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  
  botones_onoff(VISIBLES);
  /////

  String linea_z;
  linea_z = "CEL";
  qry_inven->Close();
  qry_inven->ParamByName("linea")->AsString = linea_z;
  qry_inven->Open();
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantcuocel::qry_invenAfterScroll(TDataSet *DataSet)
{
  String codigo_z;
  int cia_z, idart_z;
  codigo_z = qry_inven->FieldByName("codigo")->AsString;
  idart_z = qry_inven->FieldByName("idart")->AsInteger;
  cia_z = 1;
  qry_descri2->Close();
  qry_descri2->ParamByName("codigo")->AsString = codigo_z;
  qry_descri2->ParamByName("cia")->AsInteger = cia_z;
  qry_descri2->ParamByName("idrel")->AsInteger = REL_INVEN_DESCRILAR;
  qry_descri2->Open();
  qry_cuotacel->Close();
  qry_cuotacel->ParamByName("idart")->AsInteger = idart_z;
  qry_cuotacel->Open();
  lkcmb_codigo->KeyValue = codigo_z;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantcuocel::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::botones_onoff(int modo_z)
{
  switch (modo_z) {
    case INVISIBLES:
      nuevo->Enabled=false;
      modifica->Enabled=false;
      borra->Enabled=false;
      grabar->Enabled=true;
      cancelar->Enabled=true;
//      pnl_btngral->Visible=false;
      break;
    case VISIBLES:
//      pnl_btngral->Visible=true;
      nuevo->Enabled=true;
      modifica->Enabled=true;
      borra->Enabled=true;
      grabar->Enabled=false;
      cancelar->Enabled=false;
      break;
  }
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantcuocel::ToolButton6Click(TObject *Sender)
{
   qry_inven->Next();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::ToolButton5Click(TObject *Sender)
{
   qry_inven->Last();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::primeroExecute(TObject *Sender)
{
  qry_inven->First();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::anteriorExecute(TObject *Sender)
{
  qry_inven->Prior();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::siguienteExecute(TObject *Sender)
{
   qry_inven->Next();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::ultimoExecute(TObject *Sender)
{
   qry_inven->Last();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::nuevoExecute(TObject *Sender)
{
  if(qry_inven->IsEmpty()) {
     Application->MessageBox("No Tengo Articulo para Agregarle la Cuota", "ERROR", MB_ICONEXCLAMATION);
  }

  grabar->Tag = NUEVO;
  botones_onoff(INVISIBLES);
  edt_importe->SetFocus();
//   BuscarEntrada(nument_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::grabarExecute(TObject *Sender)
{
  int idvta_z, idart_z;
  double importe_z =0;
  TDateTime fecha_z;
  importe_z = edt_importe->Value;
  fecha_z = date_fecha->Date;
  idart_z = qry_inven->FieldByName("idart")->AsInteger;
  switch ( grabar->Tag) {
     case NUEVO:
       idvta_z = dm->busca_sigid(IDVTACEL);
       qry_cuotacel->Append();
       qry_cuotacel->FieldByName("idvtacel")->AsInteger = idvta_z;
       qry_cuotacel->FieldByName("idart")->AsInteger = idart_z;
       break;
     case MODIF:
       qry_cuotacel->Edit();
       break;
  }
  qry_cuotacel->FieldByName("cuotamarg")->AsFloat = importe_z;
  qry_cuotacel->FieldByName("fechaini")->AsDateTime = fecha_z;
  qry_cuotacel->Post();
  try {
     dm->manvehi->StartTransaction();
     qry_cuotacel->ApplyUpdates();
     dm->manvehi->Commit();
  } catch (Exception &E)
  {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  grabar->Tag = 0;
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantcuocel::cancelarExecute(TObject *Sender)
{
  grabar->Tag = EN_ESPERA;
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantcuocel::borraExecute(TObject *Sender)
{
  int ii_z = Application->MessageBox("Esta Seguro de Eliminar este Renglón ?", "Eliminar Renglón", MB_OKCANCEL | MB_ICONQUESTION | MB_DEFBUTTON2);
  if (ii_z != IDOK ) return;
  qry_cuotacel->Delete();
  try {
    dm->manvehi->StartTransaction();
    qry_cuotacel->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::dbgrd_cuotacelCustomDrawCell(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxTreeListColumn *AColumn, bool ASelected,
      bool AFocused, bool ANewItemRow, AnsiString &AText, TColor &AColor,
      TFont *AFont, TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::modificaExecute(TObject *Sender)
{
  if(qry_inven->IsEmpty()) {
     Application->MessageBox("No Tengo Articulo para Agregarle la Cuota", "ERROR", MB_ICONEXCLAMATION);
  }
  grabar->Tag = MODIF;
  botones_onoff(INVISIBLES);
  edt_importe->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantcuocel::qry_cuotacelAfterScroll(
      TDataSet *DataSet)
{
  edt_importe->Value =   qry_cuotacel->FieldByName("cuotamarg")->AsFloat;
  date_fecha->Date = qry_cuotacel->FieldByName("fechaini")->AsDateTime;
}
//---------------------------------------------------------------------------


