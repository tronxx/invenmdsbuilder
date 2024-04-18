//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_relsurti.h"
#include "dmod.h"
#include "numapal.h"
#include "imprigra.h"
#include "Frm_selserie.h"
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
#pragma link "dxDBELib"
#pragma resource "*.dfm"
#include "situaciones.h"

TForm_relsurti* Form_relsurti;
//---------------------------------------------------------------------------
void __fastcall GeneraRelSurti(TForm *Padre)
{
    try
    {
        Form_relsurti = new TForm_relsurti (Padre);
        Form_relsurti->Show();
    }
    catch(...)
    {
    }

}
//---------------------------------------------------------------------------
__fastcall TForm_relsurti::TForm_relsurti(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  qry_relsurti->Close();
  qry_relsurti->ParamByName("folio")->AsInteger = edt_nument->Value;
  qry_relsurti->ParamByName("cia")->AsInteger = cia_z;
  qry_relsurti->Open();
  if(qry_relsurti->IsEmpty()) return;
  mensaje_z = "Esta seguro de eliminar " + este_z + " " + titulo_z + " ? ";
  titmsg_z = "Eliminar " + titulo_z;

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
        qry_renentra->Delete();
    }
    qry_relsurti->Delete();
    try {
      dm->manvehi->StartTransaction();
      qry_relsurti->ApplyUpdates();
      qry_renentra->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_relsurti::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  edicion_factible(READ_ONLY);
}
//---------------------------------------------------------------------------
void __fastcall TForm_relsurti::edt_numentKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) busca_ptvt(edt_nument->Text);
}
//-------------------------------------------------------------------------
void __fastcall TForm_relsurti::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  alta_ptvt();
  switch(grabar->Tag) {
    case NUEVO: alta_ptvt(); break;
    case MODIF: modif_ptvt(); break;
  }
  grabar->Tag = EN_ESPERA;
  edicion_factible(READ_ONLY);

}
//---------------------------------------------------------------------------
void __fastcall TForm_relsurti::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  qry_relvtas->Close();
  qry_relvtas->ParamByName("numero")->AsInteger = edt_nument->Value;
  qry_relvtas->ParamByName("cia")->AsInteger = cia_z;
  qry_relvtas->Open();
  if(qry_relvtas->IsEmpty()) {
    mensaje_z = "No existe " + titulo_z + " que desea modificar";
    titmsg_z = titulo_z + " Inexistente ";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  desp_ptvt();
  grabar->Tag = MODIF;
  botones_onoff(INVISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::desp_ptvt()
{
  edt_nument->Value = qry_relsurti->FieldByName("folio")->AsInteger;
  date_fecha->Date =  qry_relsurti->FieldByName("fecha")->AsDateTime;
  date_fecini->Date =  qry_relsurti->FieldByName("fechaini")->AsDateTime;
  date_fecfin->Date =  qry_relsurti->FieldByName("fechafin")->AsDateTime;
  date_horaini->Time =  tiemporel(qry_relsurti->FieldByName("horaini")->AsInteger);
  date_horafin->Time =  tiemporel(qry_relsurti->FieldByName("horafin")->AsInteger);
  qry_renentra->Close();
  qry_renentra->ParamByName("idreltransf")->AsInteger = qry_relsurti->FieldByName("idreltransf")->AsInteger;
  qry_renentra->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  qry_sigent->Close();
  qry_sigent->ParamByName("cia")->AsInteger = cia_z;
  qry_sigent->Open();
  if(!qry_sigent->IsEmpty()) edt_nument->Value = qry_sigent->FieldByName("sigent")->AsInteger;
  edt_nument->Value++;
  date_fecha->Date    = dm->ahora();
  date_hora->Time    = minutos(dm->ahora());
  date_fecini->Date = date_fecha->Date;
  date_fecfin->Date = date_fecha->Date;
  date_horaini->Time = date_hora->Time;
  date_horafin->Time = date_hora->Time;
  //date_fentrega->Date = Now();
  grabar->Tag = NUEVO;
  botones_onoff(INVISIBLES);
  edicion_factible(READ_WRITE);
  edt_nument->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::primeroExecute(TObject *Sender)
{
  String sql_z;
  sql_z = "select min (folio) as numero from inv_relvtas where cia = ";
  sql_z = sql_z + IntToStr(cia_z);
   mueve_hacia(sql_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::anteriorExecute(TObject *Sender)
{
  String sql_z;
  sql_z = "select max (folio) as numero from inv_relvtas where cia = ";
  sql_z = sql_z + IntToStr(cia_z) + " and folio < " + IntToStr((int) edt_nument->Value);
  mueve_hacia(sql_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::siguienteExecute(TObject *Sender)
{
  String sql_z;
  sql_z = "select min (folio) as numero from inv_relvtas where ";
  sql_z = sql_z + " cia = " + IntToStr(cia_z) + \
     " and folio > " + IntToStr((int) edt_nument->Value);
  mueve_hacia(sql_z);
}
//---------------------------------------------------------------------------
void __fastcall TForm_relsurti::ultimoExecute(TObject *Sender)
{
  String sql_z;
  sql_z = "select max (folio) as numero from inv_relvtas where ";
  sql_z = sql_z + "cia = " + IntToStr(cia_z);
  mueve_hacia(sql_z);
}
//-------------------------------------------------------------------------

void __fastcall TForm_relsurti::alta_ptvt()
{
   int idreltransf_z= 0, horaini_z, horafin_z, hora_z;
   TDateTime fecha_z, fechaini_z, fechafin_z;
   fecha_z = date_fecha->Date;
   fechaini_z = date_fecini->Date;
   fechafin_z = date_fecfin->Date;
   horaini_z = minutos(date_horaini->Time);
   horafin_z = minutos(date_horafin->Time);
   hora_z = minutos(date_hora->Time);
   qry_relsurti->Close();
   qry_relsurti->ParamByName("folio")->AsInteger = edt_nument->Value;
   qry_relsurti->ParamByName("cia")->AsInteger = cia_z;
   qry_relsurti->Open();
   if (grabar->Tag == NUEVO) {
     if(!qry_relsurti->IsEmpty()) return;
   } else {
     if(qry_relsurti->IsEmpty()) return;
     idreltransf_z=qry_relsurti->FieldByName("idrelvtas")->AsInteger;
   }
   try {
     dm->manvehi->StartTransaction();
     if (grabar->Tag == NUEVO) {
       idreltransf_z=dm->busca_sigid(IDINVRELTRANSF);
       qry_relsurti->Append();
       qry_relsurti->FieldByName("idreltransf")->AsInteger = idreltransf_z;
       qry_relsurti->FieldByName("folio")->AsInteger = edt_nument->Value;
     } else {
       qry_relsurti->Edit();
     }
     qry_relsurti->FieldByName("fecha")->AsDateTime = date_fecha->Date;
     qry_relsurti->FieldByName("hora")->AsInteger = hora_z;
     qry_relsurti->FieldByName("fechaini")->AsDateTime = fechaini_z;
     qry_relsurti->FieldByName("fechafin")->AsDateTime = fechafin_z;
     qry_relsurti->FieldByName("horaini")->AsInteger = horaini_z;
     qry_relsurti->FieldByName("horafin")->AsInteger = horafin_z;
     qry_relsurti->FieldByName("hora")->AsInteger = hora_z;
     qry_relsurti->FieldByName("idusuario")->AsInteger = 0;
     qry_relsurti->FieldByName("feccap")->AsDateTime = dm->ahora();
     qry_relsurti->FieldByName("cia")->AsInteger = cia_z;
     qry_relsurti->Post();
     qry_relsurti->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   grabar->Tag = 0;
   botones_onoff(VISIBLES);
   busca_ptvt(edt_nument->Text);
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::modif_ptvt()
{

  qry_relvtas->Close();
  qry_relvtas->ParamByName("tipoent")->AsString = tipoent_z;
  qry_relvtas->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
  qry_relvtas->ParamByName("numero")->AsInteger = edt_nument->Value;
  qry_relvtas->ParamByName("cia")->AsInteger = cia_z;
  qry_relvtas->Open();
   if(qry_relvtas->IsEmpty()) return;
   try {
     dm->manvehi->StartTransaction();
     qry_relvtas->Edit();
//     qry_relvtas->FieldByName("situacion")->AsString = edt_nombre->Text;
     qry_relvtas->Post();
     qry_relvtas->ApplyUpdates();
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

void __fastcall TForm_relsurti::botones_onoff(int modo_z)
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

void __fastcall TForm_relsurti::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("numero")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::busca_ptvt(String ptvt_z)
{
   mi_entrada_z = SIN_ENTRADA;
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_relsurti->Close();
   qry_relsurti->ParamByName("folio")->AsInteger = StrToIntDef(ptvt_z, 0);
   qry_relsurti->ParamByName("cia")->AsInteger = cia_z;
   qry_relsurti->Open();
   if(!qry_relsurti->IsEmpty()) {
     mi_entrada_z = CON_ENTRADA;
     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::FormCreate(TObject *Sender)
{

  permis_z=dm->busca_permision(RELSURTI);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }

  date_fecini->Date = Now();
  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_almacen->Open();
  qry_tipoentrega->Close();
  qry_tipoentrega->ParamByName("cia")->AsInteger = cia_z;
  qry_tipoentrega->Open();
  qry_vendr->Close();
  qry_vendr->Open();
  qry_chofer->Close();
  qry_chofer->Open();
  qry_ciudad->Close();
  qry_ciudad->Open();
  qry_ptovta->Close();
  qry_ptovta->ParamByName("cia")->AsInteger = cia_z;
  qry_ptovta->Open();
  qry_tiposctes->Close();
  qry_tiposctes->ParamByName("cia")->AsInteger = cia_z;
  qry_tiposctes->Open();
  date_fecha->Date   = dm->ahora();
  date_fecini->Date  = date_fecha->Date;
  date_fecfin->Date  = date_fecini->Date;
  date_hora->Time    = minutos(dm->ahora());
  date_horaini->Time = date_hora->Time;
  date_horafin->Time = date_horaini->Time;
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::asigna_tipo(int tipo_z)
{
  int idpermis_z = 0;
  entrapor_z = tipo_z;
  switch (entrapor_z) {
    case  TIPO_SABANA_VENTAS:
        tipoent_z = "V"; idpermis_z = CAPVTAS;
        titulo_z = "Sabana Ventas Tradicional";
        genero_z = "F";
        break;
    case  TIPO_VENTAS_FONACOT:
        tipoent_z = "F"; idpermis_z = CAPVTASFON;
        titulo_z = "Sabana Ventas FONACOT";
        genero_z = "F";
        break;
    default:
        tipoent_z = "Z"; idpermis_z = CANXCAMFO;
        titulo_z = "Movimientos no Definidos";
        genero_z = "M";
        break;

  }
  Caption = "Captura de " + titulo_z;
  if(genero_z == "M") {
    este_z = "Este";
    cerrado_z = "Cerrado";
  } else {
    este_z = "Esta";
    cerrado_z = "Cerrada";
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------




void __fastcall TForm_relsurti::btn_aceptarenClick(TObject *Sender)
{
  int idrenentra_z=0, conse_z = 0, idart_z = 0, idrelvtas_z=0;
  String codigo_z, alm_z, descri_z;
  double piva_z=0, costo_z =0;
  idrelvtas_z = qry_relvtas->FieldByName("idrelvtas")->AsInteger;
  alm_z       = qry_almacen->FieldByName("clave")->AsString;
  codigo_z    = qry_inven->FieldByName("codigo")->AsString;
  descri_z    = qry_inven->FieldByName("descri")->AsString;
  idart_z     = qry_inven->FieldByName("idart")->AsInteger;
  try {
    qry_renentra->Tag = NO_REFRESH;
    dm->manvehi->StartTransaction();
    idrenentra_z=dm->busca_sigid(IDINVRELVTAART);
    qry_renentra->Append();
    qry_renentra->FieldByName("codigo")->AsString = codigo_z;
    qry_renentra->FieldByName("descri")->AsString = descri_z;
    qry_renentra->FieldByName("idrelvtaart")->AsInteger = idrenentra_z;
    qry_renentra->FieldByName("idrelvtas")->AsInteger = idrelvtas_z;
    qry_renentra->FieldByName("idart")->AsInteger = idart_z;
    qry_renentra->FieldByName("salede")->AsString = alm_z;
    qry_renentra->FieldByName("conse")->AsInteger = 0;
    qry_renentra->Post();
    qry_renentra->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E)
  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  qry_renentra->Tag = SI_REFRESH;
}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::edicion_factible(int modo_z)
{
  bool modo_enabled = true, modo_readonly = false;
  switch (modo_z) {
    case READ_WRITE: modo_enabled = true; modo_readonly = false; break;
    case READ_ONLY: modo_enabled = false; modo_readonly = true; break;
  }
  date_fecha->Enabled = modo_enabled;
  date_hora->Enabled = modo_enabled;
  date_fecini->Enabled = modo_enabled;
  date_horaini->Enabled = modo_enabled;
  date_fecfin->Enabled = modo_enabled;
  date_horafin->Enabled = modo_enabled;
  //lkcmb_entrega->Enabled = modo_enabled;
  //lkcmb_tipocte->Enabled = modo_enabled;
  //lkcmb_tipoentr->Enabled = modo_enabled;
  //lkcmb_ptovta->Enabled = modo_enabled;
  //lkcmb_ciudad->Enabled = modo_enabled;
  //edt_nombre->ReadOnly = modo_readonly;
  //mmo_direc->ReadOnly = modo_readonly;
}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::cierrarenExecute(TObject *Sender)
{
  // Este proceso cierra un renglón de entrada especial, hay que agregar el
  // movart, afectar exist, afectar inven, afectar estadis, afectar edoexis
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este renglón ya ha sido cerrado previamente", "Renglón Cerrado", MB_ICONEXCLAMATION);
    return;
  }
  if(Application->MessageBox("Seguro de Afectar los datos de Este renglón", "Cerrar Renglón", MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
}
//---------------------------------------------------------------------------

bool __fastcall TForm_relsurti::afecta_kdx()
{
  bool todobien_z = true;
  return (todobien_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::borrarenExecute(TObject *Sender)
{
  int idrelvtaart_z=0, idreltransf_z=0;
  if (qry_renentra->IsEmpty()) return;
  if(Application->MessageBox("Seguro de eliminar este renglón", "Eliminar Renglón", MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  idrelvtaart_z = qry_renentra->FieldByName("idrelvtaart")->AsInteger;
  idreltransf_z    = qry_renentra->FieldByName("idreltransf")->AsInteger;
  qry_renentra->Delete();
  qry_grabaartrel->Close();
  qry_grabaartrel->ParamByName("idreltransf")->AsInteger = 0;
  qry_grabaartrel->ParamByName("idrelvtaart")->AsInteger = idrelvtaart_z;
  qry_grabaartrel->ExecSQL();
  try {
    dm->manvehi->StartTransaction();
    qry_renentra->ApplyUpdates();
    dm->manvehi->Commit();
  } catch (Exception &E)  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::exportdbgridExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = Name + ".xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    switch( SaveDialog->FilterIndex) {
      case 1: dbgrd_ventas->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
      case 2: dbgrd_ventas->SaveToXLS(SaveDialog->FileName, true); break;
      case 3: dbgrd_ventas->SaveToHTML(SaveDialog->FileName, true); break;
    }
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::impritextExecute(TObject *Sender)
{
  double total_z = 0;
  String arch_z = "relsurti.txt", serie_z="", vnd_z="", alm_z="", ciu_z="";
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresión de " + titulo_z;
  TLocateOptions Opts;
  int ii_z=0;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_renentra->DisableControls();
  qry_renentra->Tag == NO_REFRESH;
  qry_renentra->First();
  alm_z = "-1";
//  if(!qry_renentra->IsEmpty())
//    zona_z = qry_renpogas->FieldByName("zona")->AsInteger;
  pagina_z = 1; report_encab();
  for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
    if(lineas_z > LIN_X_PAG) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab();
    }
    if (alm_z != qry_renentra->FieldByName("salede")->AsString) {
      alm_z = qry_renentra->FieldByName("salede")->AsString;
      qry_almacen->First();
      qry_almacen->Locate("clave", alm_z, Opts);
      fprintf(archout, "\nRetirar de:%s %s\n", alm_z, qry_almacen->FieldByName("nombre")->AsString);
      lineas_z = lineas_z + 2;
    }
    fprintf(archout, "%s|%s|%s|%s|%s|%s|%s|",
      ljust(qry_renentra->FieldByName("zonaptvta")->AsString, 2),
      ljust(qry_renentra->FieldByName("ptovta")->AsString, 4),
      ljust(FormatDateTime("dd/mm/yyyy", qry_renentra->FieldByName("fechaent")->AsDateTime), 10),
      ljust(qry_renentra->FieldByName("tipoentrega")->AsString, 4),
      ljust(qry_renentra->FieldByName("entrega")->AsString, 4),
      ljust(qry_renentra->FieldByName("codigo")->AsString, 13),
      ljust(qry_renentra->FieldByName("descri")->AsString, 30)
    );
    lineas_z++;
    fprintf(archout, "\n");
  }
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renentra->Tag == SI_REFRESH;
  qry_renentra->EnableControls();
  manda_imp(arch_z, dm->rutaimp_z, dm->tipoimp_z, dm->ff_z, dm->impresora_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::report_encab()
{
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de Relacion de Traspasos de Mercancia: %s Fecha:%s%s\n",
    qry_relsurti->FieldByName("folio")->AsString,
    FormatDateTime("dd/mm/YYYY", qry_relsurti->FieldByName("Fecha")->AsDateTime),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF)
  );
  fprintf(archout, "%s%s|%s|%s|%s|%s|%s|%s|%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    ljust("Zn", 2),
    ljust("PVta", 4),
    ljust("Fecha", 10),
    ljust("Tipo", 4),
    ljust("Chfr", 4),
    ljust("Codigo", 13),
    ljust("Descripcion", 30),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::report_subencab()
{
/*
  fprintf(archout, "Zona:%s%s%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    qry_zonas->FieldByName("strzona")->AsString + " "
    + qry_zonas->FieldByName("nombre")->AsString,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout, "%s%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    cjust("Vehiculo", 35), cjust("Fecha Nota", 10),
    ljust("Chofer", 6),
    rjust("Kmt.Ant", 7),
    rjust("Kmt.Act", 7),
    rjust("Recorre", 7),
    rjust("Rendto.", 7),
    "G",
    rjust("Litros", 7),
    rjust("P.Litro", 7),
    rjust("Importe", 12),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z += 3;
*/
}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::busca_cod(String codigo_z)
{
  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString=codigo_z;
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  qry_exist->Close();
  qry_exist->ParamByName("codigo")->AsString=codigo_z;
  qry_exist->ParamByName("cia")->AsInteger = cia_z;
  qry_exist->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::BitBtn1Click(TObject *Sender)
{
  int folio_z;
  folio_z = edt_nument->Value;
  qry_relsurti->Close();
  qry_relsurti->ParamByName("folio")->AsInteger = folio_z;
  qry_relsurti->ParamByName("cia")->AsInteger   = cia_z;
  qry_relsurti->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::dbgrd_ventasDblClick(TObject *Sender)
{
  busca_ptvt(qry_relvtas->FieldByName("folio")->AsInteger);
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::dbgrd_ventasKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if ( Key == VK_DELETE) borrarenExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::BitBtn3Click(TObject *Sender)
{
  TDateTime fechini_z, fechfin_z;
  fechini_z = date_fecini->Date;
  fechfin_z = date_fecfin->Date;
  qry_relvtas->Close();
  qry_relvtas->ParamByName("fecini")->AsDateTime = fechini_z;
  qry_relvtas->ParamByName("fecfin")->AsDateTime = fechfin_z;
  qry_relvtas->ParamByName("cia")->AsInteger     = cia_z;
  qry_relvtas->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_relsurti::agrerenExecute(TObject *Sender)
{
  String campos_z[] = { "idrelvtaart", "zonaptvta", "idrelvtas", "fecha",
    "fechaent", "entrega", "salede", "ptovta", "folio", "codigo", "descri",
    "poblac", "preciolista", "tipoentrega"
    };
  int ii_z, iddatreltransf_z=0, idrelvtaart_z=0, idreltransf_z=0;

  if (qry_relvtas->IsEmpty()) return;
  iddatreltransf_z = dm->busca_sigid(IDINVDATRELTRANSF);
  idrelvtaart_z = qry_relvtas->FieldByName("idrelvtaart")->AsInteger;
  idreltransf_z = qry_relsurti->FieldByName("idreltransf")->AsInteger;

  qry_renentra->Append();
  qry_renentra->FieldByName("iddatreltransf")->AsInteger = iddatreltransf_z;
  qry_renentra->FieldByName("idreltransf")->AsInteger    = idreltransf_z;
  qry_renentra->FieldByName("cia")->AsInteger = cia_z;
  for ( ii_z = 0; ii_z < 14; ii_z++) {
    qry_renentra->FieldByName(campos_z[ii_z])->Value = qry_relvtas->FieldByName(campos_z[ii_z])->Value;
  }
  qry_renentra->Post();
  qry_relvtas->Delete();
  try {
    dm->manvehi->StartTransaction();
    qry_relsurti->ApplyUpdates();
    qry_renentra->ApplyUpdates();
    qry_grabaartrel->Close();
    qry_grabaartrel->ParamByName("idreltransf")->AsInteger = idreltransf_z;
    qry_grabaartrel->ParamByName("idrelvtaart")->AsInteger = idrelvtaart_z;
    qry_grabaartrel->ExecSQL();
    dm->manvehi->Commit();
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_relsurti::dxDBGrid1DblClick(TObject *Sender)
{
  agrerenExecute(Sender);        
}
//---------------------------------------------------------------------------

