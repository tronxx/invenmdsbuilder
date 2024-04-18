//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantpzo.h"
#include "dmod.h"
#include "dialg_okcancel.h"
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
#include "situaciones.h"
#include "Frme_datosplazo.h"

TForm_mantpzo *Form_mantpzo;

//---------------------------------------------------------------------------
__fastcall TForm_mantpzo::TForm_mantpzo(TComponent* Owner)
        : TForm(Owner)
{
    TBS_LINEAS               = 0;
    TBS_PRECIOS              = 1;
    TBS_GRUPOS               = 2;
    TBS_ARTICULOS            = 3;
    TBS_GPOMAYOREO           = 11;
    TBS_PRECIOMAYPRO         = 12;
    TIPOLISTA_LINEAS         = 1;
    TIPOLISTA_GRUPOS         = 2;
    TBS_MENUDEO              = 0;
    TBS_MAYOREO              = 0;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_plazoscrd->Close();
//  qry_plazoscrd->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//  qry_plazoscrd->Open();
  int idcrdplazo_z = -1;
  TLocateOptions Opts;
  Opts.Clear();
  TQuery *qry_seleccionado;
  if( qry_plazoscrd->IsEmpty()) return;
  if( pagina_z == "TBS_LINEAS")       qry_seleccionado = qry_plazoxlinea;
  if( pagina_z == "TBS_PRECIOS")      qry_seleccionado = qry_plazoxprecio;
  if( pagina_z == "TBS_ARTICULOS")    qry_seleccionado = qry_preciosart;
  if( pagina_z == "TBS_GRUPOS")       qry_seleccionado = qry_plazoxgrupo;
  if( pagina_z == "TBS_GPOMAYOREO")   qry_seleccionado = qry_invgpomayprecio;
  if( pagina_z == "TBS_PRECIOMAYPRO") qry_seleccionado = qry_precioxprove;
  if(qry_seleccionado->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Registro?", "Eliminar", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) != IDYES)
     return;
  if(pagina_z != "TBS_GPOMAYOREO") {
    if(!qry_seleccionado->IsEmpty())
       idcrdplazo_z = qry_seleccionado->FieldByName("idplazocrd")->AsInteger;
    if(!qry_plazoscrd->Locate("idplazocrd", idcrdplazo_z, Opts)) return;
    qry_plazoscrd->Delete();
  } else {
    qry_invgpomayprecio->Delete();
  }
  try {
    dm->manvehi->StartTransaction();
    if(qry_plazoscrd->UpdatesPending) qry_plazoscrd->ApplyUpdates();
    if(qry_invgpomayprecio->UpdatesPending) qry_invgpomayprecio->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E)
  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  abre_querys();
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantpzo::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_ptvt(); break;
    case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  int idcrdplazo_z = -1, height_z=0, page_z=0;
  TLocateOptions Opts;
  Opts.Clear();
  TQuery *qry_seleccionado;
  if(qry_plazoscrd->IsEmpty()) return;
  page_z = pge_listas->ActivePageIndex;
  if( pagina_z == "TBS_LINEAS")     qry_seleccionado = qry_plazoxlinea;
  if( pagina_z == "TBS_PRECIOS")    qry_seleccionado = qry_plazoxprecio;
  if( pagina_z == "TBS_ARTICULOS")  qry_seleccionado = qry_preciosart;
  if( pagina_z == "TBS_GRUPOS")     qry_seleccionado = qry_plazoxgrupo;
  if( pagina_z == "TBS_GPOMAYOREO") qry_seleccionado = qry_invgpomayprecio;
  if( pagina_z == "TBS_PRECIOMAYPRO") qry_seleccionado = qry_precioxprove;
  if(qry_seleccionado->IsEmpty()) return;
  if(pagina_z != "TBS_GPOMAYOREO") {
    idcrdplazo_z = qry_seleccionado->FieldByName("idplazocrd")->AsInteger;
    if(!qry_plazoscrd->Locate("idplazocrd", idcrdplazo_z, Opts)) return;
    plazomax_z=qry_plazoscrd->FieldByName("plazomax")->AsInteger;
    plistamax_z=qry_plazoscrd->FieldByName("plistamax")->AsFloat;
    linea_z = qry_plazoscrd->FieldByName("linea")->AsString;
    idlinea_z = qry_plazoscrd->FieldByName("idlinea")->AsInteger;
  } else {
    idcrdplazo_z = qry_invgpomayprecio->FieldByName("idgpomayprecio")->AsInteger;
    plistamax_z  = qry_invgpomayprecio->FieldByName("factorprecio")->AsFloat;
    plazomax_z   = qry_invgpomayprecio->FieldByName("tipo")->AsInteger;
    idlinea_z    = qry_invgpomayprecio->FieldByName("idgrupo")->AsInteger;
  }

  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_datosplazo *Frame_datosplazo;
  Frame_datosplazo = new TFrame_datosplazo(Dlg_datos);
  Dlg_datos->Caption = "Datos del Plazo";
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = Frame_datosplazo->Width + 20;
  Frame_datosplazo->Parent = Dlg_datos->Panel1;
  Frame_datosplazo->cia_z = cia_z;
  Frame_datosplazo->edt_plazomax->Value = plazomax_z;
  Frame_datosplazo->edt_plismax->Value = plistamax_z;
  height_z = Frame_datosplazo->pnl_datosprecios->Height;
  if( pagina_z == "TBS_LINEAS") {
       idcrdplazo_z = qry_plazoxlinea->FieldByName("tipo")->AsInteger;
       Frame_datosplazo->pnl_pzoxlinea->Visible = true;
       Frame_datosplazo->qry_lineas->Close();
       Frame_datosplazo->qry_lineas->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_lineas->Open();
       Frame_datosplazo->lkcmb_lineas->KeyValue = idlinea_z;
       Frame_datosplazo->lbl_precio->Visible = false;
       Frame_datosplazo->edt_plismax->Visible = false;
       height_z += Frame_datosplazo->pnl_pzoxlinea->Height;
       qry_plazoscrd->Tag = NUEVO;
       Frame_datosplazo->qry_tipoplazo->Close();
       Frame_datosplazo->qry_tipoplazo->ParamByName("tipolista")->AsInteger = TIPOLISTA_LINEAS;
       Frame_datosplazo->qry_tipoplazo->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_tipoplazo->Open();
       Frame_datosplazo->lkcmb_tipoplazo->KeyValue = idcrdplazo_z;
       //Frame_datosplazo->chk_prioridad->Checked = (tipo_z==TIPO_PLAZO_LINEA_PRIORIDAD);
  }
  if( pagina_z == "TBS_PRECIOS") {
       qry_preciosart->Tag = NUEVO;
       tipo_z=TIPO_PLAZO_PRECIO;
  }
  if( pagina_z == "TBS_ARTICULOS") {
       Frame_datosplazo->pnl_pzoxcodigo->Visible = true;
       Frame_datosplazo->edt_plismax->Visible = false;
       Frame_datosplazo->lbl_precio->Visible = false;
       qry_preciosart->Tag = NUEVO;
       tipo_z=TIPO_PLAZO_ARTICULO;
       height_z += Frame_datosplazo->pnl_pzoxcodigo->Height;
       Frame_datosplazo->edt_codigo->Text = qry_preciosart->FieldByName("CODIGO")->AsString;
       Frame_datosplazo->edt_descri->Text = qry_preciosart->FieldByName("DESCRI")->AsString;
       Frame_datosplazo->edt_plazomax->Value = qry_preciosart->FieldByName("plazomax")->AsInteger;
       Frame_datosplazo->busca_cod(Frame_datosplazo->edt_codigo->Text.Trim());
  }
  if( pagina_z == "TBS_GRUPOS") {
       idcrdplazo_z = qry_plazoxgrupo->FieldByName("tipo")->AsInteger;
       Frame_datosplazo->qry_grupos->Close();
       Frame_datosplazo->qry_grupos->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_grupos->Open();
       Frame_datosplazo->lkcmb_grupos->KeyValue = idlinea_z;
       Frame_datosplazo->pnl_pzoxgrupo->Visible = true;
       Frame_datosplazo->edt_plismax->Visible = false;
       Frame_datosplazo->lbl_precio->Visible = false;
       qry_preciosart->Tag = NUEVO;
       Frame_datosplazo->qry_tipoplazo->Close();
       Frame_datosplazo->qry_tipoplazo->ParamByName("tipolista")->AsInteger = TIPOLISTA_GRUPOS;
       Frame_datosplazo->qry_tipoplazo->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_tipoplazo->Open();
       Frame_datosplazo->lkcmb_grupos->KeyValue = Frame_datosplazo->qry_grupos->FieldByName("idgrupo")->AsInteger;
       Frame_datosplazo->lkcmb_tipoplazo->KeyValue = idcrdplazo_z;
       Frame_datosplazo->lkcmb_tipoplazo->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->dbedt_tipoplazo->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->lbl_tipoplzo->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       //Frame_datosplazo->chk_prioridadgpo->Checked = ( tipo_z==TIPO_PLAZO_GRUPO_PRIORIDAD);
       height_z += Frame_datosplazo->pnl_pzoxgrupo->Height;
  }
  if( pagina_z == "TBS_GPOMAYOREO") {
       Frame_datosplazo->qry_grupos->Close();
       Frame_datosplazo->qry_grupos->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_grupos->Open();
       Frame_datosplazo->lkcmb_grupos->KeyValue = idlinea_z;
       Frame_datosplazo->pnl_pzoxlinea->Visible = false;
       Frame_datosplazo->pnl_pzoxcodigo->Visible = false;
       Frame_datosplazo->chk_prioridadgpo->Visible = false;
       Frame_datosplazo->pnl_pzoxgrupo->Visible = true;
       Frame_datosplazo->lbl_tipo->Visible = true;
       Frame_datosplazo->cmb_tipo->Visible = true;
       Frame_datosplazo->lbl_plazo->Visible = false;
       Frame_datosplazo->edt_plazomax->Visible = false;
       Frame_datosplazo->edt_plismax->Visible = true;
       Frame_datosplazo->edt_plismax->DisplayFormat="0.000;-0.000";
       Frame_datosplazo->lbl_precio->Caption = "Factor Precio";
       Frame_datosplazo->lbl_precio->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->edt_plismax->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->lbl_precio->Top = Frame_datosplazo->lbl_tipo->Top;
       Frame_datosplazo->edt_plismax->Top = Frame_datosplazo->cmb_tipo->Top;
       Frame_datosplazo->edt_plismax->Value = plistamax_z;
       Frame_datosplazo->cmb_tipo->ItemIndex = plazomax_z - 1;
       qry_preciosart->Tag = NUEVO;
       height_z += Frame_datosplazo->pnl_pzoxgrupo->Height;
       tipo_z=TIPO_FACTOR_PRECIOMAY;
  }
  if( pagina_z == "TBS_PRECIOMAYPRO") {
       Frame_datosplazo->qry_grupos->Close();
       Frame_datosplazo->lkcmb_grupos->KeyField = "codigo";
       Frame_datosplazo->dbedt_descri->DataField = "nombre";
       Frame_datosplazo->cmb_tipo->Visible = false;
       Frame_datosplazo->qry_grupos->SQL->Text = "select codigo, nombre from proveedor where cia = :CIA order by codigo";
       Frame_datosplazo->qry_grupos->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_grupos->Open();
       Frame_datosplazo->lkcmb_grupos->KeyValue = qry_plazoscrd->FieldByName("linea")->AsString;
       Frame_datosplazo->pnl_pzoxlinea->Visible = false;
       Frame_datosplazo->pnl_pzoxcodigo->Visible = false;
       Frame_datosplazo->chk_prioridadgpo->Visible = false;
       Frame_datosplazo->pnl_pzoxgrupo->Visible = true;
       Frame_datosplazo->lbl_plazo->Visible = false;
       Frame_datosplazo->edt_plazomax->Visible = false;
       Frame_datosplazo->edt_plismax->Visible = true;
       Frame_datosplazo->edt_plismax->DisplayFormat="0.000;-0.000";
       Frame_datosplazo->edt_plismax->DecimalPlaces = 4;
       Frame_datosplazo->lbl_precio->Caption = "Factor Precio";
       Frame_datosplazo->lbl_precio->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->edt_plismax->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->lbl_precio->Top = Frame_datosplazo->lbl_tipo->Top;
       Frame_datosplazo->edt_plismax->Top = Frame_datosplazo->cmb_tipo->Top;
       height_z += Frame_datosplazo->pnl_pzoxgrupo->Height;
       tipo_z=TIPO_FACTOR_PRECIOMAYPRO;
  }
  Frame_datosplazo->Height = height_z;
  Dlg_datos->Height = Frame_datosplazo->Height + Dlg_datos->Panel2->Height + 50;
  if(Dlg_datos->ShowModal() == mrOk) {
    plazomax_z=Frame_datosplazo->edt_plazomax->Value;
    plistamax_z=Frame_datosplazo->edt_plismax->Value;
    if( pagina_z == "TBS_LINEAS") {
         idlinea_z=Frame_datosplazo->qry_lineas->FieldByName("idlinea")->AsInteger;
         linea_z=Frame_datosplazo->qry_lineas->FieldByName("linea")->AsString;
         descri_z=Frame_datosplazo->qry_lineas->FieldByName("descri")->AsString;
         tipo_z=Frame_datosplazo->qry_tipoplazo->FieldByName("idplazo")->AsInteger;
         //if(Frame_datosplazo->chk_prioridad->Checked)
         //  tipo_z=TIPO_PLAZO_LINEA_PRIORIDAD;
         //else
         //  tipo_z=TIPO_PLAZO_LINEA;
         // End if
    }
    if( pagina_z == "TBS_GRUPOS") {
         idlinea_z=Frame_datosplazo->qry_grupos->FieldByName("idgrupo")->AsInteger;
         linea_z=Frame_datosplazo->qry_grupos->FieldByName("codigo")->AsString;
         descri_z=Frame_datosplazo->qry_grupos->FieldByName("descri")->AsString;
         tipo_z=Frame_datosplazo->qry_tipoplazo->FieldByName("idplazo")->AsInteger;
         //if(Frame_datosplazo->chk_prioridadgpo->Checked)
         //  tipo_z=TIPO_PLAZO_GRUPO_PRIORIDAD;
         //else
         //  tipo_z=TIPO_PLAZO_GRUPO;
         // End if
    }
    if( pagina_z == "TBS_ARTICULOS") {
         idlinea_z=Frame_datosplazo->qry_inven->FieldByName("idart")->AsInteger;
         linea_z=Frame_datosplazo->qry_inven->FieldByName("codigo")->AsString;
         descri_z=Frame_datosplazo->qry_inven->FieldByName("descri")->AsString;
    }
    if( pagina_z == "TBS_PRECIOS") {
         idlinea_z=0;
         linea_z="";
         descri_z="";
    }
    if( pagina_z == "TBS_GPOMAYOREO") {
         idlinea_z=Frame_datosplazo->qry_grupos->FieldByName("idgrupo")->AsInteger;
         plazomax_z = Frame_datosplazo->cmb_tipo->ItemIndex + 1;
    }
    if( pagina_z == "TBS_PRECIOMAYPRO") {
         idlinea_z=0;
         linea_z=Frame_datosplazo->qry_grupos->FieldByName("codigo")->AsString;
         descri_z="";
    }
    modif_ptvt();
  }
  qry_seleccionado = NULL;
  delete qry_seleccionado;
  delete Frame_datosplazo;
  delete Dlg_datos;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::desp_ptvt()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantpzo::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  int height_z=0, page_z=0, idcrdplzo_z = 1;
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_datosplazo *Frame_datosplazo;
  Frame_datosplazo = new TFrame_datosplazo(Dlg_datos);
  Dlg_datos->Caption = "Datos del Plazo";
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = Frame_datosplazo->Width + 20;
  Frame_datosplazo->Parent = Dlg_datos->Panel1;
  Frame_datosplazo->cia_z = cia_z;
  page_z = pge_listas->ActivePageIndex;
  height_z = Frame_datosplazo->pnl_datosprecios->Height;
  if( pagina_z == "TBS_LINEAS") {
       idcrdplzo_z = 1;
       Frame_datosplazo->pnl_pzoxlinea->Visible = true;
       Frame_datosplazo->qry_lineas->Close();
       Frame_datosplazo->qry_lineas->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_lineas->Open();
       Frame_datosplazo->qry_tipoplazo->Close();
       Frame_datosplazo->qry_tipoplazo->ParamByName("tipolista")->AsInteger = TIPOLISTA_LINEAS;
       Frame_datosplazo->qry_tipoplazo->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_tipoplazo->Open();
       Frame_datosplazo->lkcmb_lineas->KeyValue = Frame_datosplazo->qry_lineas->FieldByName("idlinea")->AsInteger;
       Frame_datosplazo->lkcmb_tipoplazo->KeyValue = Frame_datosplazo->qry_tipoplazo->FieldByName("idplazo")->AsInteger;
       Frame_datosplazo->lbl_precio->Visible = false;
       Frame_datosplazo->edt_plismax->Visible = false;
       qry_plazoscrd->Tag = NUEVO;
       height_z += Frame_datosplazo->pnl_pzoxlinea->Height;
       tipo_z=TIPO_PLAZO_LINEA;
  }
  if( pagina_z == "TBS_PRECIOS") {
       qry_preciosart->Tag = NUEVO;
       tipo_z=TIPO_PLAZO_PRECIO;
  }
  if( pagina_z == "TBS_ARTICULOS") {
       Frame_datosplazo->pnl_pzoxcodigo->Visible = true;
       Frame_datosplazo->edt_plismax->Visible = false;
       Frame_datosplazo->lbl_precio->Visible = false;
       qry_preciosart->Tag = NUEVO;
       tipo_z=TIPO_PLAZO_ARTICULO;
       height_z += Frame_datosplazo->pnl_pzoxcodigo->Height;
  }
  if( pagina_z == "TBS_GRUPOS") {
       idcrdplzo_z = 5;
       Frame_datosplazo->lkcmb_tipoplazo->KeyValue = idcrdplzo_z;
       Frame_datosplazo->lkcmb_tipoplazo->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->dbedt_tipoplazo->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->lbl_tipoplzo->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->qry_grupos->Close();
       Frame_datosplazo->qry_grupos->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_grupos->Open();
       Frame_datosplazo->qry_tipoplazo->Close();
       Frame_datosplazo->qry_tipoplazo->ParamByName("tipolista")->AsInteger = TIPOLISTA_GRUPOS;
       Frame_datosplazo->qry_tipoplazo->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_tipoplazo->Open();
       Frame_datosplazo->lkcmb_grupos->KeyValue = Frame_datosplazo->qry_grupos->FieldByName("idgrupo")->AsInteger;
       Frame_datosplazo->pnl_pzoxgrupo->Visible = true;
       Frame_datosplazo->edt_plismax->Visible = false;
       Frame_datosplazo->lbl_precio->Visible = false;
       qry_preciosart->Tag = NUEVO;
       Frame_datosplazo->lkcmb_grupos->KeyValue = idlinea_z;
       Frame_datosplazo->pnl_pzoxgrupo->Visible = true;
       Frame_datosplazo->edt_plismax->Visible = false;
       Frame_datosplazo->lbl_precio->Visible = false;
       height_z += Frame_datosplazo->pnl_pzoxgrupo->Height;
       tipo_z=TIPO_PLAZO_GRUPO;
  }
  if( pagina_z == "TBS_GPOMAYOREO") {
       Frame_datosplazo->qry_grupos->Close();
       Frame_datosplazo->qry_grupos->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_grupos->Open();
       Frame_datosplazo->lkcmb_grupos->KeyValue = Frame_datosplazo->qry_grupos->FieldByName("idgrupo")->AsInteger;
       Frame_datosplazo->pnl_pzoxlinea->Visible = false;
       Frame_datosplazo->pnl_pzoxcodigo->Visible = false;
       Frame_datosplazo->chk_prioridadgpo->Visible = false;
       Frame_datosplazo->pnl_pzoxgrupo->Visible = true;
       Frame_datosplazo->lbl_tipo->Visible = true;
       Frame_datosplazo->cmb_tipo->Visible = true;
       Frame_datosplazo->cmb_tipo->ItemIndex = 0;
       Frame_datosplazo->lbl_plazo->Visible = false;
       Frame_datosplazo->edt_plazomax->Visible = false;
       Frame_datosplazo->edt_plismax->Visible = true;
       Frame_datosplazo->edt_plismax->DisplayFormat="0.000;-0.000";
       Frame_datosplazo->edt_plismax->DecimalPlaces = 4;
       Frame_datosplazo->lbl_precio->Caption = "Factor Precio";
       Frame_datosplazo->lbl_precio->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->edt_plismax->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->edt_plismax->Left = Frame_datosplazo->lkcmb_grupos->Left + Frame_datosplazo->lkcmb_grupos->Width - Frame_datosplazo->edt_plismax->Width;
       Frame_datosplazo->lbl_precio->Top = Frame_datosplazo->lbl_tipo->Top;
       Frame_datosplazo->edt_plismax->Top = Frame_datosplazo->cmb_tipo->Top;
       qry_preciosart->Tag = NUEVO;
       height_z += Frame_datosplazo->pnl_pzoxgrupo->Height;
       tipo_z=TIPO_FACTOR_PRECIOMAY;
  }
  if( pagina_z == "TBS_PRECIOMAYPRO") {
       Frame_datosplazo->qry_grupos->Close();
       Frame_datosplazo->lkcmb_grupos->KeyField = "codigo";
       Frame_datosplazo->dbedt_descri->DataField = "nombre";
       Frame_datosplazo->cmb_tipo->Visible = false;
       Frame_datosplazo->qry_grupos->SQL->Text = "select codigo, nombre from proveedor where cia = :CIA order by codigo";
       Frame_datosplazo->qry_grupos->ParamByName("cia")->AsInteger = cia_z;
       Frame_datosplazo->qry_grupos->Open();
       Frame_datosplazo->lkcmb_grupos->KeyValue = Frame_datosplazo->qry_grupos->FieldByName("codigo")->AsString;
       Frame_datosplazo->pnl_pzoxlinea->Visible = false;
       Frame_datosplazo->pnl_pzoxcodigo->Visible = false;
       Frame_datosplazo->chk_prioridadgpo->Visible = false;
       Frame_datosplazo->pnl_pzoxgrupo->Visible = true;
       Frame_datosplazo->lbl_plazo->Visible = false;
       Frame_datosplazo->edt_plazomax->Visible = false;
       Frame_datosplazo->edt_plismax->Visible = true;
       Frame_datosplazo->edt_plismax->DisplayFormat="0.000;-0.000";
       Frame_datosplazo->edt_plismax->DecimalPlaces = 4;
       Frame_datosplazo->lbl_precio->Caption = "Factor Precio";
       Frame_datosplazo->lgl_gpo->Caption = "Mayorista";
       Frame_datosplazo->lbl_precio->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->edt_plismax->Parent = Frame_datosplazo->pnl_pzoxgrupo;
       Frame_datosplazo->edt_plismax->Left = Frame_datosplazo->lkcmb_grupos->Left + Frame_datosplazo->lkcmb_grupos->Width - Frame_datosplazo->edt_plismax->Width;
       Frame_datosplazo->lbl_precio->Top = Frame_datosplazo->lbl_tipo->Top;
       Frame_datosplazo->edt_plismax->Top = Frame_datosplazo->cmb_tipo->Top;
       height_z += Frame_datosplazo->pnl_pzoxgrupo->Height;
       tipo_z=TIPO_FACTOR_PRECIOMAYPRO;
  }
  Frame_datosplazo->Height = height_z;
  Dlg_datos->Height = Frame_datosplazo->Height + Dlg_datos->Panel2->Height + 50;
  if(Dlg_datos->ShowModal() == mrOk) {
    plazomax_z=Frame_datosplazo->edt_plazomax->Value;
    plistamax_z=Frame_datosplazo->edt_plismax->Value;
    if( pagina_z == "TBS_LINEAS") {
         idlinea_z=Frame_datosplazo->qry_lineas->FieldByName("idlinea")->AsInteger;
         linea_z=Frame_datosplazo->qry_lineas->FieldByName("linea")->AsString;
         descri_z=Frame_datosplazo->qry_lineas->FieldByName("descri")->AsString;
         tipo_z=Frame_datosplazo->qry_tipoplazo->FieldByName("idplazo")->AsInteger;
         //if(Frame_datosplazo->chk_prioridad->Checked)
         //  tipo_z=TIPO_PLAZO_LINEA_PRIORIDAD;
         //else
         //  tipo_z=TIPO_PLAZO_LINEA;
         // End if
    }
    if( pagina_z == "TBS_GRUPOS") {
         idlinea_z=Frame_datosplazo->qry_grupos->FieldByName("idgrupo")->AsInteger;
         linea_z=Frame_datosplazo->qry_grupos->FieldByName("codigo")->AsString;
         descri_z=Frame_datosplazo->qry_grupos->FieldByName("descri")->AsString;
         tipo_z=Frame_datosplazo->qry_tipoplazo->FieldByName("idplazo")->AsInteger;
         //if(Frame_datosplazo->chk_prioridadgpo->Checked)
         //  tipo_z=TIPO_PLAZO_GRUPO_PRIORIDAD;
         //else
         //  tipo_z=TIPO_PLAZO_GRUPO;
         // End if
    }
    if( pagina_z == "TBS_ARTICULOS") {
         idlinea_z=Frame_datosplazo->qry_inven->FieldByName("idart")->AsInteger;
         linea_z=Frame_datosplazo->qry_inven->FieldByName("codigo")->AsString;
         descri_z=Frame_datosplazo->qry_inven->FieldByName("descri")->AsString;
    }
    if( pagina_z == "TBS_PRECIOS") {
         idlinea_z=0;
         linea_z="";
         descri_z="";
    }
    if( pagina_z == "TBS_GPOMAYOREO") {
         idlinea_z=Frame_datosplazo->qry_grupos->FieldByName("idgrupo")->AsInteger;
         plazomax_z = Frame_datosplazo->cmb_tipo->ItemIndex + 1;
    }
    if( pagina_z == "TBS_PRECIOMAYPRO") {
         idlinea_z=0;
         linea_z=Frame_datosplazo->qry_grupos->FieldByName("codigo")->AsString;
         descri_z="";
    }
    alta_ptvt();
  }
  delete Frame_datosplazo;
  delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::primeroExecute(TObject *Sender)
{
   qry_plazoscrd->First();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas");
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::anteriorExecute(TObject *Sender)
{
   qry_plazoscrd->Prior();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas where idmarcainv < "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::siguienteExecute(TObject *Sender)
{
   qry_plazoscrd->Next();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas where idmarcainv > "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantpzo::ultimoExecute(TObject *Sender)
{
   qry_plazoscrd->Last();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas");
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantpzo::alta_ptvt()
{
  TLocateOptions Opts;
  Opts.Clear();
  bool yahay_z=false;
  int page_z=0;
  Variant locvalues[2];
  page_z = pge_listas->ActivePageIndex;
  if (tipo_z == -1) {
    qry_plazoscrd->First();
    locvalues[0] = Variant(idlinea_z);
    locvalues[1] = Variant(plazomax_z);
    yahay_z=qry_plazoscrd->Locate("idlinea;plazomax", VarArrayOf(locvalues, 1), Opts);
    if(yahay_z) {
      Application->MessageBox("No puede Usar una Linea que Ya Existe", "Linea Duplicada", MB_ICONEXCLAMATION);
      return;
    }
  }
  if(pagina_z == "TBS_GPOMAYOREO") {
    idplazo_z=dm->busca_sigid(INV_IDFACTORPRECIOMAY);
    qry_invgpomayprecio->Append();
    qry_invgpomayprecio->FieldByName("idgpomayprecio")->AsInteger = idplazo_z;
    qry_invgpomayprecio->FieldByName("idgrupo")->AsInteger = idlinea_z;
    qry_invgpomayprecio->FieldByName("factorprecio")->AsFloat= plistamax_z;
    qry_invgpomayprecio->FieldByName("fecha")->AsDateTime = dm->ahora();
    qry_invgpomayprecio->FieldByName("fechora")->AsDateTime = dm->ahora();
    qry_invgpomayprecio->FieldByName("cia")->AsInteger = cia_z;
    qry_invgpomayprecio->FieldByName("tipo")->AsInteger = plazomax_z;
    qry_invgpomayprecio->Post();
  } else {
    idplazo_z=dm->busca_sigid(INV_IDPLAZOCRD);
    qry_plazoscrd->Append();
    qry_plazoscrd->FieldByName("idplazocrd")->AsInteger = idplazo_z;
    qry_plazoscrd->FieldByName("idlinea")->AsInteger = idlinea_z;
    qry_plazoscrd->FieldByName("linea")->AsString = linea_z;
    qry_plazoscrd->FieldByName("plazomax")->AsInteger = plazomax_z;
    qry_plazoscrd->FieldByName("plistamax")->AsFloat = plistamax_z;
    qry_plazoscrd->FieldByName("tipo")->AsInteger = tipo_z;
    qry_plazoscrd->FieldByName("cia")->AsInteger = cia_z;
    qry_plazoscrd->Post();
  }
  try {
    dm->manvehi->StartTransaction();
    if(qry_plazoscrd->UpdatesPending) qry_plazoscrd->ApplyUpdates();
    if(qry_invgpomayprecio->UpdatesPending)  qry_invgpomayprecio->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  abre_querys();
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantpzo::modif_ptvt()
{
  int page_z=0;
  page_z = pge_listas->ActivePageIndex;
  if(pagina_z == "TBS_GPOMAYOREO") {
    qry_invgpomayprecio->Edit();
    qry_invgpomayprecio->FieldByName("idgrupo")->AsInteger = idlinea_z;
    qry_invgpomayprecio->FieldByName("factorprecio")->AsFloat= plistamax_z;
    qry_invgpomayprecio->FieldByName("fecha")->AsDateTime = dm->ahora();
    qry_invgpomayprecio->FieldByName("fechora")->AsDateTime = dm->ahora();
    qry_invgpomayprecio->FieldByName("tipo")->AsInteger = plazomax_z;
    qry_invgpomayprecio->Post();
  } else {
    qry_plazoscrd->Edit();
    qry_plazoscrd->FieldByName("plazomax")->AsInteger = plazomax_z;
    qry_plazoscrd->FieldByName("plistamax")->AsFloat = plistamax_z;
    qry_plazoscrd->FieldByName("tipo")->AsInteger = tipo_z;
    qry_plazoscrd->Post();
  }
  try {
     dm->manvehi->StartTransaction();
     if(qry_invgpomayprecio->UpdatesPending) qry_invgpomayprecio->ApplyUpdates();
     if(qry_plazoscrd->UpdatesPending) qry_plazoscrd->ApplyUpdates();
     dm->manvehi->Commit();
  } catch (Exception &E) {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  abre_querys();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idmarcainv")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::busca_ptvt(String ptvt_z)
{
//   if(ptvt_z.Trim().IsEmpty()) return;
//   qry_plazoscrd->Close();
//   qry_plazoscrd->ParamByName("idmarcainv")->AsInteger = StrToIntDef(ptvt_z, 0);
//   qry_plazoscrd->Open();
//   if(!qry_plazoscrd->IsEmpty()) {
//     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
//   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(MANTOPLAZOS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  abre_querys();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::abre_querys()
{
  qry_plazoscrd->Close();
  qry_plazoscrd->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoscrd->Open();
  qry_preciosart->Close();
  qry_preciosart->ParamByName("tipoart")->AsInteger = TIPO_PLAZO_ARTICULO;
  qry_preciosart->ParamByName("cia")->AsInteger = cia_z;
  qry_preciosart->Open();
  qry_plazoxlinea->Close();
  qry_plazoxlinea->ParamByName("tipo1")->AsInteger = TIPOLISTA_LINEAS;
  //qry_plazoxlinea->ParamByName("tipo2")->AsInteger = TIPO_PLAZO_LINEA_PRIORIDAD;
  qry_plazoxlinea->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxlinea->Open();
  qry_plazoxprecio->Close();
  qry_plazoxprecio->ParamByName("tipo1")->AsInteger = TIPO_PLAZO_PRECIO;
  qry_plazoxprecio->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxprecio->Open();
  qry_plazoxgrupo->Close();
  qry_plazoxgrupo->ParamByName("tipo1")->AsInteger = TIPOLISTA_GRUPOS;
  //qry_plazoxgrupo->ParamByName("tipo2")->AsInteger = TIPO_PLAZO_GRUPO_PRIORIDAD;
  qry_plazoxgrupo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxgrupo->Open();
  qry_invgpomayprecio->Close();
  qry_invgpomayprecio->ParamByName("cia")->AsInteger = cia_z;
  qry_invgpomayprecio->Open();
  qry_precioxprove->Close();
  qry_precioxprove->ParamByName("cia")->AsInteger = cia_z;
  qry_precioxprove->ParamByName("tipo")->AsInteger = TIPO_FACTOR_PRECIOMAYPRO;
  qry_precioxprove->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantpzo::dbgrd_pzolineasCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;

}
//---------------------------------------------------------------------------




void __fastcall TForm_mantpzo::busca_cod(String codigo_z)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantpzo::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//  TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_pzolineas;
  int page_z;
  tipogrd_z="DBG";
  page_z = pge_listas->ActivePageIndex;
  if( pagina_z == "TBS_LINEAS") {
       midbgrd_z = dbgrd_pzolineas;   tipogrd_z="DBG";
  }
  if( pagina_z == "TBS_ARTICULOS") {
     midbgrd_z = dbgrd_pzoartic;    tipogrd_z="DBG";
  }
  if( pagina_z == "TBS_GPOMAYOREO") {
    midbgrd_z = dbgrd_gpomayprecio; tipogrd_z="DBG";
  }
  if( pagina_z == "TBS_PRECIOS") {
    midbgrd_z = dbgrd_plazoxprecio; tipogrd_z="DBG";
  }
  if( pagina_z == "TBS_GRUPOS") {
    midbgrd_z =  dbgrd_plazoxgpo; tipogrd_z="DBG";
  }

  if( pagina_z == "TBS_GPOMAYOREO") {
    midbgrd_z =  dbgrd_gpomayprecio; tipogrd_z="DBG";
  }
  if( pagina_z == "TBS_PRECIOMAYPRO") {
    midbgrd_z =  dbgrd_preciomaypro; tipogrd_z="DBG";
  }

  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = midbgrd_z->Name + ".xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    if(tipogrd_z == "DBG") {
      switch( SaveDialog->FilterIndex) {
        case 1: midbgrd_z->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
        case 2: midbgrd_z->SaveToXLS(SaveDialog->FileName, true); break;
        case 3: midbgrd_z->SaveToHTML(SaveDialog->FileName, true); break;
      }
    }
//    else if (tipogrd_z == "ADV") {
//      switch( SaveDialog->FilterIndex) {
//        case 1: misgrd_z->SaveToCSV(SaveDialog->FileName); break;
//        case 2: misgrd_z->SaveToXLS(SaveDialog->FileName); break;
//        case 3: misgrd_z->SaveToHTML(SaveDialog->FileName); break;
//      }
//    }
  }
  delete SaveDialog;

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantpzo::dbgrd_pzolineasKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_INSERT) nuevoExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::dbgrd_pzoarticKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) borraExecute(Sender);
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantpzo::tbs_lineasShow(TObject *Sender)
{
  pagina_z = pagina_z;
  TTabSheet *pPC = dynamic_cast<TTabSheet *>(Sender);
  pagina_z = pPC->Name;
  pagina_z = pagina_z.UpperCase();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantpzo::pge_mayomenChange(TObject *Sender)
{
  pagina_z = pagina_z;
  TTabSheet *pPC = pge_mayomen->ActivePage;
  //TTabSheet *pPC = dynamic_cast<TTabSheet *>(Sender);
  pagina_z = pPC->Name;
  pagina_z = pagina_z.UpperCase();
  if(pagina_z == "TBS_MAYOREO") {
    pPC = pge_mayoreo->ActivePage;
    pagina_z = pPC->Name;
    pagina_z = pagina_z.UpperCase();
  }
  if(pagina_z == "TBS_MENUDEO") {
    pPC = pge_listas->ActivePage;
    pagina_z = pPC->Name;
    pagina_z = pagina_z.UpperCase();
  }

}
//---------------------------------------------------------------------------

