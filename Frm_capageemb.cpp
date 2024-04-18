//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_capageemb.h"
#include "dmod.h"
#include "dialg_datosagenda.h"
#include "dialg_datosrenagenda.h"
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
#include "numapal.h"
#include "imprigra.h"
TForm_capageemb *Form_capageemb;

//---------------------------------------------------------------------------
__fastcall TForm_capageemb::TForm_capageemb(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::borraExecute(TObject *Sender)
{
  int ii_z=0;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_agenda->Close();
//  qry_agenda->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//  qry_agenda->Open();
  if(qry_agenda->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Marca ?", "Eliminar Marca", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    for(qry_renagenda->First(); !qry_renagenda->Eof; qry_renagenda->First()) qry_renagenda->Delete();
    qry_agenda->Delete();
    try {
      dm->manvehi->StartTransaction();
      if (qry_renagenda->UpdatesPending) qry_renagenda->ApplyUpdates();
      qry_agenda->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_capageemb::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  qry_agenda->Tag = EN_ESPERA;
}
//---------------------------------------------------------------------------
void __fastcall TForm_capageemb::edt_ptovtaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
//  if(Key == VK_RETURN) busca_ptvt(edt_ptovta->Text);
}
//-------------------------------------------------------------------------
void __fastcall TForm_capageemb::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_ptvt(); break;
    case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_capageemb::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_agenda->Close();
//  qry_agenda->ParamByName("idmarcainv")->AsInteger = edt_ptovta->Text.ToIntDef(0);
//  qry_agenda->Open();
  qry_agenda->Tag = MODIF;
  if(qry_agenda->IsEmpty()) {
    Application->MessageBox("No existe la Marca que desea modificar", "Marca Inexistente", MB_ICONEXCLAMATION);
    return;
  }
  desp_ptvt();
  grabar->Tag = MODIF;
  botones_onoff(INVISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::desp_ptvt()
{
  qry_renagenda->Close();
  qry_renagenda->ParamByName("idagenda")->AsInteger = qry_agenda->FieldByName("idagenda")->AsInteger;
  qry_renagenda->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_capageemb::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  Tdlg_datosagenda *dlg_datosagenda = new Tdlg_datosagenda (this);
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Clear();
  dm->qry_maxidvnd->SQL->Add("select max(folio) as ultfol from inv_agendaentrega where cia = :CIA");
  dm->qry_maxidvnd->ParamByName("cia")->AsInteger = cia_z;
  dm->qry_maxidvnd->Open();
  if(!dm->qry_maxidvnd->IsEmpty()) {
    dlg_datosagenda->edt_folio->Value = dm->qry_maxidvnd->FieldByName("ultfol")->AsInteger + 1;
  }
  if( dlg_datosagenda->ShowModal() == mrOk) {
    folio_z = dlg_datosagenda->edt_folio->Value;
    fecha_z = dlg_datosagenda->date_fecha->Date;
    ubica_z = dlg_datosagenda->qry_almacen->FieldByName("ubica")->AsString;
    alta_ptvt();
  }

//  dm->qry_maxidvnd->Close();
//  dm->qry_maxidvnd->SQL->Clear();
//  dm->qry_maxidvnd->SQL->Add("select max (idmarcainv) as idmarcainv from inv_marcas");
//  dm->qry_maxidvnd->Open();
  //edt_ptovta->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::primeroExecute(TObject *Sender)
{
   qry_agenda->First();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas");
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::anteriorExecute(TObject *Sender)
{
   qry_agenda->Prior();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas where idmarcainv < "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::siguienteExecute(TObject *Sender)
{
   qry_agenda->Next();
   //mueve_hacia("select min (idmarcainv) as idmarcainv from inv_marcas where idmarcainv > "+edt_ptovta->Text);
}
//---------------------------------------------------------------------------
void __fastcall TForm_capageemb::ultimoExecute(TObject *Sender)
{
   qry_agenda->Last();
   //mueve_hacia("select max (idmarcainv) as idmarcainv from inv_marcas");
}
//-------------------------------------------------------------------------

int __fastcall TForm_capageemb::alta_ptvt()
{
  int idagenda_z=0;
  idagenda_z=dm->busca_sigid(INVIDAGENDAENTREGA);
  qry_buscagenda->Close();
  qry_buscagenda->ParamByName("fecha")->AsDateTime = fecha_z;
  qry_buscagenda->ParamByName("ubica")->AsString = ubica_z;
  qry_buscagenda->ParamByName("cia")->AsInteger = cia_z;
  qry_buscagenda->Open();
  qry_buscagenda->Append();
  qry_buscagenda->FieldByName("idagenda")->AsInteger = idagenda_z;
  qry_buscagenda->FieldByName("folio")->AsString = folio_z;
  qry_buscagenda->FieldByName("fecha")->AsDateTime = fecha_z;
  qry_buscagenda->FieldByName("ubica")->AsString = ubica_z;
  qry_buscagenda->FieldByName("horaini")->AsInteger = 0;
  qry_buscagenda->FieldByName("horafin")->AsInteger = 0;
  qry_buscagenda->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
  qry_buscagenda->FieldByName("cia")->AsInteger = cia_z;
  qry_buscagenda->Post();
  try {
     dm->manvehi->StartTransaction();
     qry_buscagenda->ApplyUpdates();
     dm->manvehi->Commit();
  } catch (Exception &E)
  {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  return(idagenda_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::modif_ptvt()
{
   try {
     dm->manvehi->StartTransaction();
     qry_agenda->Edit();
     //qry_agenda->FieldByName("marca")->AsString = edt_nombre->Text.Trim();
     qry_agenda->Post();
     qry_agenda->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = EN_ESPERA;
   qry_agenda->Tag = EN_ESPERA;
   botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::botones_onoff(int modo_z)
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

void __fastcall TForm_capageemb::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idmarcainv")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::busca_ptvt(String ptvt_z)
{
//   if(ptvt_z.Trim().IsEmpty()) return;
//   qry_agenda->Close();
//   qry_agenda->ParamByName("idmarcainv")->AsInteger = StrToIntDef(ptvt_z, 0);
//   qry_agenda->Open();
//   if(!qry_agenda->IsEmpty()) {
//     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
//   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::FormCreate(TObject *Sender)
{
  permis_z="N";
  cia_z = dm->cia_z;
  if(dm->usermaster_z != "S") {
    dm->qry_permis->Close();
    dm->qry_permis->ParamByName("idusuario")->AsInteger=dm->idusuario_z;
    dm->qry_permis->ParamByName("idpermis")->AsInteger=MANTOMARCAS;
    dm->qry_permis->Open();
    if(!dm->qry_permis->IsEmpty())
      permis_z=dm->qry_permis->FieldByName("permis")->AsString;
    if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
    }
  } else {
    permis_z="T";
  }
  qry_agenda->Tag = EN_ESPERA;
  date_fecini->Date = PrimerDiaMes(dm->ahora());
  date_fecfin->Date = UltimoDiaMes(date_fecini->Date);
  qry_agenda->Close();
  qry_agenda->ParamByName("fechaini")->AsDateTime = date_fecini->Date;
  qry_agenda->ParamByName("fechafin")->AsDateTime = date_fecfin->Date;
  qry_agenda->ParamByName("cia")->AsInteger = cia_z;
  qry_agenda->Open();
  desp_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::qry_agendaAfterScroll(TDataSet *DataSet)
{
  if(qry_agenda->Tag == EN_ESPERA) desp_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::dbrgd_renagendaCustomDrawCell(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxTreeListColumn *AColumn, bool ASelected, bool AFocused,
      bool ANewItemRow, AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
    //if(qry_renagenda->FieldByName("estado")->AsString == "1") AFont->Style = TFontStyles()<< fsStrikeOut;

}
//---------------------------------------------------------------------------


void __fastcall TForm_capageemb::nueva_entregaExecute(TObject *Sender)
{
  String codigo_z, descri_z, observs_z, chofer_z, ptovta_z, colonia_z,
  poblac_z;
  int idrenagenda_z, idpoblac_z, idagenda_z, idcolonia_z,
    idcodigo_z, iddescri_z, idobservs_z, idrenagendaart_z;
  Tdlg_datosrenagenda *dlg_datosrenagenda = new Tdlg_datosrenagenda (this);
  if (dlg_datosrenagenda->ShowModal() != mrOk) {
    delete dlg_datosrenagenda;
    return;
  }
  fecha_z  = dlg_datosrenagenda->date_fecha->Date;
  ubica_z  = dlg_datosrenagenda->qry_almacen->FieldByName("ubica")->AsString;
  codigo_z = dlg_datosrenagenda->edt_codigo->Text;
  descri_z = dlg_datosrenagenda->edt_descri->Text;
  observs_z = dlg_datosrenagenda->edt_observs->Text;
  colonia_z = dlg_datosrenagenda->edt_colonia->Text;
  chofer_z = dlg_datosrenagenda->qry_chofer->FieldByName("clave")->AsString;
  ptovta_z = dlg_datosrenagenda->qry_ptovta->FieldByName("clave")->AsString;
  idpoblac_z = dlg_datosrenagenda->qry_poblacs->FieldByName("numero")->AsInteger;
  poblac_z = dlg_datosrenagenda->qry_poblacs->FieldByName("nombre")->AsString;
  idobservs_z = dm->busca_iddato(observs_z, INVCONCEPTO);
  idcodigo_z = dm->busca_iddato(codigo_z, OLDCONCEPTO);
  iddescri_z = dm->busca_iddato(descri_z, OLDCONCEPTO);
  idcolonia_z = dm->busca_iddato(colonia_z, OLDCONCEPTO);
  idrenagenda_z = dm->busca_sigid(INVIDRENAGENDAENTREGA);
  idrenagendaart_z = dm->busca_sigid(INVIDRENAGENDAART);
  qry_buscagenda->Close();
  qry_buscagenda->ParamByName("fecha")->AsDateTime = fecha_z;
  qry_buscagenda->ParamByName("ubica")->AsString = ubica_z;
  qry_buscagenda->ParamByName("cia")->AsInteger = cia_z;
  qry_buscagenda->Open();
  if (qry_buscagenda->IsEmpty()) {
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Clear();
    dm->qry_maxidvnd->SQL->Add("select max(folio) as ultfol from inv_agendaentrega where cia = :CIA");
    dm->qry_maxidvnd->ParamByName("cia")->AsInteger = cia_z;
    dm->qry_maxidvnd->Open();
    folio_z = dm->qry_maxidvnd->FieldByName("ultfol")->AsInteger + 1;
    idagenda_z = alta_ptvt();
  } else {
    idagenda_z = qry_agenda->FieldByName("idagenda")->AsInteger;
  }
  qry_renagenda->Append();
  qry_renagenda->FieldByName("idrenagenda")->AsInteger = idrenagenda_z;
  qry_renagenda->FieldByName("idagenda")->AsInteger = idagenda_z;
  qry_renagenda->FieldByName("conse")->AsInteger = qry_renagenda->RecordCount +1;
  qry_renagenda->FieldByName("promotor")->AsString = chofer_z;
  qry_renagenda->FieldByName("ptovta")->AsString = ptovta_z;
  qry_renagenda->FieldByName("idcolonia")->AsInteger = idcolonia_z;
  qry_renagenda->FieldByName("poblacion")->AsInteger = idpoblac_z;
  qry_renagenda->FieldByName("idcodigo")->AsInteger = idcodigo_z;
  qry_renagenda->FieldByName("iddescri")->AsInteger = iddescri_z;
  qry_renagenda->FieldByName("hora")->AsInteger = 0;
  qry_renagenda->FieldByName("estado")->AsInteger = EDO_PENDIENTE;
  qry_renagenda->FieldByName("idrelvtaart")->AsInteger = -1;
  qry_renagenda->FieldByName("idobservs")->AsInteger = idobservs_z;
  qry_renagenda->FieldByName("cia")->AsInteger = cia_z;
  qry_renagenda->FieldByName("codigo")->AsString = codigo_z;
  qry_renagenda->FieldByName("descri")->AsString = descri_z;
  qry_renagenda->FieldByName("ciudad")->AsString = poblac_z;
  qry_renagenda->FieldByName("colonia")->AsString = colonia_z;
  qry_renagendaart->Close();
  qry_renagendaart->ParamByName("idrenagenda")->AsInteger = idrenagendaart_z;
  qry_renagendaart->Open();
  qry_renagenda->Post();
  for (dlg_datosrenagenda->qry_renagendaart->First(); !dlg_datosrenagenda->qry_renagendaart->Eof; dlg_datosrenagenda->qry_renagendaart->Next() ) {
    codigo_z = dlg_datosrenagenda->qry_renagendaart->FieldByName("codigo")->AsString;
    descri_z = dlg_datosrenagenda->qry_renagendaart->FieldByName("descri")->AsString;
    idcodigo_z = dm->busca_iddato(codigo_z, OLDCONCEPTO);
    iddescri_z = dm->busca_iddato(descri_z, OLDCONCEPTO);
    qry_renagendaart->Append();
    qry_renagendaart->FieldByName("idrenagendaart")->AsInteger = idrenagendaart_z;
    qry_renagendaart->FieldByName("idagenda")->AsInteger = idagenda_z;
    qry_renagendaart->FieldByName("idrenagenda")->AsInteger = idrenagenda_z;
    qry_renagendaart->FieldByName("idcodigo")->AsInteger = idcodigo_z;
    qry_renagendaart->FieldByName("iddescri")->AsInteger = iddescri_z;
    qry_renagendaart->Post();
    idrenagendaart_z++;
  }
  try {
    dm->manvehi->StartTransaction();
    qry_renagenda->ApplyUpdates();
    if (qry_renagendaart->UpdatesPending) qry_renagendaart->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E)
  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  qry_agenda->Close();
  qry_agenda->ParamByName("fechaini")->AsDateTime = date_fecini->Date;
  qry_agenda->ParamByName("fechafin")->AsDateTime = date_fecfin->Date;
  qry_agenda->ParamByName("cia")->AsInteger = cia_z;
  qry_agenda->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_capageemb::Button1Click(TObject *Sender)
{
  qry_agenda->Close();
  qry_agenda->ParamByName("fechaini")->AsDateTime = date_fecini->Date;
  qry_agenda->ParamByName("fechafin")->AsDateTime = date_fecfin->Date;
  qry_agenda->ParamByName("cia")->AsInteger = cia_z;
  qry_agenda->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::elimina_entregaExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede eliminar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
//  qry_agenda->Close();
//  qry_agenda->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//  qry_agenda->Open();
  if(qry_renagenda->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Entrega ?", "Eliminar Entrega", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_renagenda->Delete();
      qry_renagenda->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::dbrgd_renagendaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_DELETE) elimina_entregaExecute(Sender);
  if (Key == VK_RETURN || Key == VK_SPACE)   detalles_entregaExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::resolver_entregaExecute(TObject *Sender)
{
  String msg_z;
  int nvo_estado_z=0;
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if( qry_renagenda->FieldByName("estado")->AsInteger == EDO_RESUELTO) {
    msg_z = "Dejar Pendiente";
    nvo_estado_z=EDO_PENDIENTE;
  } else {
    msg_z = "Resolver";
    nvo_estado_z=EDO_RESUELTO;
  }
//  qry_agenda->Close();
//  qry_agenda->ParamByName("idmarcainv")->AsInteger=edt_ptovta->Text.ToIntDef(0);
//  qry_agenda->Open();
  if(qry_renagenda->IsEmpty()) return;
  if(Application->MessageBox(("Esta Seguro de " + msg_z + " esta Entrega ?").c_str(), (msg_z + " Entrega").c_str(), MB_YESNO+MB_ICONQUESTION) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_renagenda->Edit();
      qry_renagenda->FieldByName("estado")->AsInteger = nvo_estado_z;
      qry_renagenda->Post();
      qry_renagenda->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::impri_textExecute(TObject *Sender)
{
  double piva_z=0, importe_z=0, iva_z=0, total_z=0, subtubi_z=0,
  subtzona_z=0, subtptovta_z=0;
  int LINEAS_X_PAG = 60;
  if (dm->tipoimp_z == IMPRESORA_GRAFICA ) LINEAS_X_PAG = 90;
  String arch_z = "caprelvta.txt", antprom_z="", antpvta_z="",
  mensaje_z, titulo_z, titmsg_z, este_z, antciu_z;
  TLocateOptions Opts;
  Opts.Clear();
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresión de " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_impripol->Close();
  qry_impripol->ParamByName("idagenda")->AsInteger = qry_agenda->FieldByName("IDAGENDA")->AsInteger;
  qry_impripol->Open();
  pagina_z = 1;
  antprom_z  = "-1";
  antciu_z = "-1";
  for(qry_impripol->First(); !qry_impripol->Eof; qry_impripol->Next()) {
    promotor_z = qry_impripol->FieldByName("promotor")->AsString;
    ciudad_z   = qry_impripol->FieldByName("ciudad")->AsString;
    if(antprom_z != promotor_z ) {
      if(antprom_z != "-1") {
        antprom_z = promotor_z;
        antciu_z = ciudad_z;
        fprintf(archout, "\n"); lineas_z++;
        report_subencab();
      } else {
        antprom_z = promotor_z;
        antciu_z = ciudad_z;
        report_encab();
      }
    }
    if (antciu_z != ciudad_z) {
      fprintf(archout, "\n"); lineas_z++;
      antciu_z = ciudad_z;
      report_subencab2();
    }
    if(lineas_z > LINEAS_X_PAG) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab();
    }
    fprintf(archout, "%s|%s|%s|%s\n",
      ljust(qry_impripol->FieldByName("ptovta")->AsString, 4),
      ljust(qry_impripol->FieldByName("descri")->AsString, 30),
      ljust(qry_impripol->FieldByName("colonia")->AsString, 30),
      ljust(qry_impripol->FieldByName("observs")->AsString, 50)
    );
    lineas_z++;
  }
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  manda_imp(arch_z, dm->rutaimp_z, dm->tipoimp_z, dm->ff_z, dm->impresora_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::report_encab()
{
  String titulo_z = "Agenda de Embarques";
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de %s\n", titulo_z);
  fprintf(archout, "Folio: %s Ubicacion:%s %s Fecha:%s\n",
    qry_agenda->FieldByName("folio")->AsString,
    qry_agenda->FieldByName("ubica")->AsString,
    qry_agenda->FieldByName("nombrealm")->AsString,
    FormatDateTime("dd-mm-yyyy", qry_agenda->FieldByName("fecha")->AsDateTime),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s%s%s|%s|%s|%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON),
    cjust("P.Vta", 5),
    ljust("Articulo", 30),
    ljust("Colonia", 30),
    ljust("Observaciones", 50),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::report_subencab()
{
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Clear();
  dm->qry_maxidvnd->SQL->Add("select nombre from promotor where tienda = ' 0' and clave = :CVEPROMO");
  dm->qry_maxidvnd->ParamByName("cvepromo")->AsString = promotor_z;
  dm->qry_maxidvnd->Open();
  if(!dm->qry_maxidvnd->IsEmpty()) {
    nombreprom_z = dm->qry_maxidvnd->FieldByName("nombre")->AsString;
  } else {
    nombreprom_z = "Inexistente";
  }
  fprintf(archout, "Promotor: %s %s\n", promotor_z, nombreprom_z);
  lineas_z++;
  report_subencab2();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::report_subencab2()
{
  fprintf(archout, "%s\n", ciudad_z);
  lineas_z++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::detalles_entregaExecute(TObject *Sender)
{
  if (qry_renagenda->IsEmpty()) return;
  Tdlg_datosrenagenda *dlg_datosrenagenda = new Tdlg_datosrenagenda (this);
  dlg_datosrenagenda->date_fecha->Date = qry_agenda->FieldByName("fecha")->AsDateTime;
  dlg_datosrenagenda->lkcmb_ubica->KeyValue = qry_agenda->FieldByName("ubica")->AsString;
  dlg_datosrenagenda->edt_codigo->Text = qry_renagenda->FieldByName("codigo")->AsString;
  dlg_datosrenagenda->edt_descri->Text = qry_renagenda->FieldByName("descri")->AsString;
  dlg_datosrenagenda->edt_observs->Text = qry_renagenda->FieldByName("observs")->AsString;
  dlg_datosrenagenda->edt_colonia->Text = qry_renagenda->FieldByName("colonia")->AsString;
  dlg_datosrenagenda->lkcmb_chofer->KeyValue = qry_renagenda->FieldByName("promotor")->AsString;
  dlg_datosrenagenda->lkcmb_ptovta->KeyValue = qry_renagenda->FieldByName("ptovta")->AsString;
  dlg_datosrenagenda->lkcmb_poblac->KeyValue = qry_renagenda->FieldByName("ciudad")->AsString;
  dlg_datosrenagenda->qry_renagendaart->Close();
  dlg_datosrenagenda->qry_renagendaart->ParamByName("idrenagenda")->AsInteger = qry_renagenda->FieldByName("idrenagenda")->AsInteger;
  dlg_datosrenagenda->qry_renagendaart->Open();
  dlg_datosrenagenda->ShowModal();
  delete dlg_datosrenagenda;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capageemb::dbrgd_renagendaDblClick(TObject *Sender)
{
  detalles_entregaExecute(Sender);
}
//---------------------------------------------------------------------------

