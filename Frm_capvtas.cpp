//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_capvtas.h"
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

const int SIN_ENTRADA = -1;
const int CON_ENTRADA = 1;
const int LIN_X_PAG     = 60;

TForm_capvtas *Form_capvtas;
//---------------------------------------------------------------------------
void __fastcall CapturaSAbadadeVentas(TForm *Padre)
{
    try
    {
        Form_capvtas = new TForm_capvtas(Padre);
        Form_capvtas->Show();
    }
    catch(...)
    {
    }

}
//---------------------------------------------------------------------------
__fastcall TForm_capvtas::TForm_capvtas(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  qry_entradas->Close();
  qry_entradas->ParamByName("tipoent")->AsString = tipoent_z;
  qry_entradas->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
  qry_entradas->ParamByName("numero")->AsInteger = edt_nument->Value;
  qry_entradas->ParamByName("cia")->AsInteger = cia_z;
  qry_entradas->Open();
  if(qry_entradas->IsEmpty()) return;
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede eliminar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Eliminar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  mensaje_z = "Esta seguro de eliminar " + este_z + " " + titulo_z + " ? ";
  titmsg_z = "Eliminar " + titulo_z;

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
      if(qry_renentra->FieldByName("status")->AsString == "C") {
        si_borrar = false;
      } else {
        costo_z = qry_renentra->FieldByName("costou")->AsFloat;
        piva_z = qry_renentra->FieldByName("piva")->AsFloat;
        qry_entradas->Edit();
        qry_entradas->FieldByName("importe")->AsFloat       -= costo_z;
        qry_entradas->FieldByName("iva")->AsFloat           -= costo_z * piva_z / 100;
        qry_entradas->FieldByName("total")->AsFloat         -= costo_z * ((piva_z / 100) + 1);
        qry_entradas->Post();
        qry_renentra->Delete();
      }
    }
    if(si_borrar) {
      qry_entradas->Delete();
    } else {
      mensaje_z = "No puede eliminar " + este_z + " " + titulo_z +
       " por que hay renglones cerrados,\n los renglones no cerrados han sido eliminados";
      titmsg_z = "Imposible Eliminar " + titulo_z;
      Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    }
    try {
      dm->manvehi->StartTransaction();
      qry_entradas->ApplyUpdates();
      qry_renentra->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_capvtas::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_capvtas::edt_numentKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) busca_ptvt(edt_nument->Text);
}
//-------------------------------------------------------------------------
void __fastcall TForm_capvtas::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_ptvt(); break;
    case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_capvtas::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  qry_entradas->Close();
  qry_entradas->ParamByName("tipoent")->AsString = tipoent_z;
  qry_entradas->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalm")->AsInteger;
  qry_entradas->ParamByName("numero")->AsInteger = edt_nument->Value;
  qry_entradas->ParamByName("cia")->AsInteger = cia_z;
  qry_entradas->Open();
  if(qry_entradas->IsEmpty()) {
    mensaje_z = "No existe " + titulo_z + " que desea modificar";
    titmsg_z = titulo_z + " Inexistente ";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede modificar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Modificar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  desp_ptvt();
  grabar->Tag = MODIF;
  botones_onoff(INVISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::desp_ptvt()
{
     lkcmb_almacen->KeyValue = qry_entradas->FieldByName("idalm")->AsInteger;
     edt_nument->Value = qry_entradas->FieldByName("numero")->AsInteger;
     edt_nombre->Text=dm->busca_dato(qry_entradas->FieldByName("perenvrec")->AsInteger, CONCEPTO);
//     edt_facpro->Text = qry_entradas->FieldByName("facpro")->AsString;
     date_fecha->Date = qry_entradas->FieldByName("fecha")->AsDateTime;
     qry_renentra->Close();
     qry_renentra->ParamByName("identrada")->AsInteger = qry_entradas->FieldByName("identrada")->AsInteger;
     qry_renentra->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_capvtas::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  edt_nument->Value = 0;
  date_fecha->Date = Now();
  grabar->Tag = NUEVO;
  botones_onoff(INVISIBLES);
  lkcmb_almacen->SetFocus();

}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::primeroExecute(TObject *Sender)
{
   mueve_hacia("select min (numero) as numero from entradas where tipo = '" +
     tipoent_z + "' and idalm = " +
     qry_almacen->FieldByName("idalmacen")->AsString + " and cia = " +
     IntToStr(cia_z)
   );
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::anteriorExecute(TObject *Sender)
{
   mueve_hacia("select max (numero) as numero from entradas where tipo = '" +
     tipoent_z + "' and idalm = " +
     qry_almacen->FieldByName("idalmacen")->AsString + " and cia = " +
     IntToStr(cia_z) +
     " and numero < " + IntToStr((int) edt_nument->Value)
   );
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::siguienteExecute(TObject *Sender)
{
   mueve_hacia("select min (numero) as numero from entradas where tipo = '" +
     tipoent_z + "' and idalm = " +
     qry_almacen->FieldByName("idalmacen")->AsString + " and cia = " +
     IntToStr(cia_z) +
     " and numero > " + IntToStr((int) edt_nument->Value)
   );
}
//---------------------------------------------------------------------------
void __fastcall TForm_capvtas::ultimoExecute(TObject *Sender)
{
   mueve_hacia("select min (numero) as numero from entradas where tipo = '" +
     tipoent_z + "' and idalm = " +
     qry_almacen->FieldByName("idalmacen")->AsString + " and cia = " +
     IntToStr(cia_z)
   );
}
//-------------------------------------------------------------------------

void __fastcall TForm_capvtas::alta_ptvt()
{
   int identrada_z = 0;
   qry_entradas->Close();
   qry_entradas->ParamByName("tipoent")->AsString = tipoent_z;
   qry_entradas->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
   qry_entradas->ParamByName("numero")->AsInteger = edt_nument->Value;
   qry_entradas->ParamByName("cia")->AsInteger = cia_z;
   qry_entradas->Open();
   if(!qry_entradas->IsEmpty()) return;
//   idnombre_z=dm->busca_iddato(edt_nombre->Text.Trim(), CONCEPTO);
//IDENTRADA, TIPO, IDALM, IDRECEMI, NUMERO, IDPROVE,
//PERENVREC, FACPRO, STATUS, CONIVA, FECHA, IMPORTE, IVA, TOTAL,
//VENCE, CTOFIN, TASCOMP, TASPRO, FECHAFAC, LETRAS, PLAZOCFP,
//IDPLANP, FLETES, DESXAP,  FECHAPRP,  CTOFINCOMP, IDUSUARIO, CIA

   try {
     dm->manvehi->StartTransaction();
     identrada_z=dm->busca_sigid(IDENTRADA);
     qry_entradas->Append();
     qry_entradas->FieldByName("identrada")->AsInteger = identrada_z;
     qry_entradas->FieldByName("tipo")->AsString = tipoent_z;
     qry_entradas->FieldByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
     qry_entradas->FieldByName("idrecemi")->AsInteger = 0;
     qry_entradas->FieldByName("numero")->AsInteger = edt_nument->Value;
     qry_entradas->FieldByName("idprove")->AsInteger = 0;
     qry_entradas->FieldByName("perenvrec")->AsInteger = 0;
//     qry_entradas->FieldByName("facpro")->AsString = edt_facpro->Text.Trim();
     qry_entradas->FieldByName("status")->AsString = "A";
     qry_entradas->FieldByName("coniva")->AsString = "";
     qry_entradas->FieldByName("fecha")->AsDateTime = date_fecha->Date;
     qry_entradas->FieldByName("importe")->AsFloat = 0;
     qry_entradas->FieldByName("iva")->AsFloat = 0;
     qry_entradas->FieldByName("total")->AsFloat = 0;
     qry_entradas->FieldByName("ctofin")->AsFloat = 0;
     qry_entradas->FieldByName("tascomp")->AsFloat = 0;
     qry_entradas->FieldByName("letras")->AsInteger = 0;
     qry_entradas->FieldByName("fletes")->AsInteger = 0;
     qry_entradas->FieldByName("desxap")->AsInteger = 0;
     qry_entradas->FieldByName("idplanp")->AsInteger = 0;
     qry_entradas->FieldByName("plazocfp")->AsInteger = 0;
     qry_entradas->FieldByName("taspro")->AsFloat = 0;
     qry_entradas->FieldByName("ctofincomp")->AsFloat = 0;
     qry_entradas->FieldByName("idusuario")->AsFloat = dm->idusuario_z;
     qry_entradas->FieldByName("vence")->AsDateTime = date_fecha->Date;
     qry_entradas->FieldByName("fechafac")->AsDateTime = date_fecha->Date;
     qry_entradas->FieldByName("fechaprp")->AsDateTime = date_fecha->Date;
     qry_entradas->FieldByName("cia")->AsInteger = cia_z;
     qry_entradas->Post();
     qry_entradas->ApplyUpdates();
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

void __fastcall TForm_capvtas::modif_ptvt()
{

  qry_entradas->Close();
  qry_entradas->ParamByName("tipoent")->AsString = tipoent_z;
  qry_entradas->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
  qry_entradas->ParamByName("numero")->AsInteger = edt_nument->Value;
  qry_entradas->ParamByName("cia")->AsInteger = cia_z;
  qry_entradas->Open();
   if(qry_entradas->IsEmpty()) return;
   try {
     dm->manvehi->StartTransaction();
     qry_entradas->Edit();
//     qry_entradas->FieldByName("situacion")->AsString = edt_nombre->Text;
     qry_entradas->Post();
     qry_entradas->ApplyUpdates();
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

void __fastcall TForm_capvtas::botones_onoff(int modo_z)
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

void __fastcall TForm_capvtas::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("numero")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::busca_ptvt(String ptvt_z)
{
   mi_entrada_z = SIN_ENTRADA;
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_entradas->Close();
   qry_entradas->ParamByName("tipoent")->AsString = tipoent_z;
   qry_entradas->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
   qry_entradas->ParamByName("numero")->AsInteger = StrToIntDef(ptvt_z, 0);
   qry_entradas->ParamByName("cia")->AsInteger = cia_z;
   qry_entradas->Open();
   if(!qry_entradas->IsEmpty()) {
     mi_entrada_z = CON_ENTRADA;
     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::FormCreate(TObject *Sender)
{
  permis_z="N";
  cia_z = dm->cia_z;
  if(dm->usermaster_z != "S") {
    dm->qry_permis->Close();
    dm->qry_permis->ParamByName("idusuario")->AsInteger=dm->idusuario_z;
    dm->qry_permis->ParamByName("idpermis")->AsInteger=CAPVTAS;
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
  tipoent_z = "V"; entrapor_z = TIPO_SABANA_VENTAS;
  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_almacen->Open();
  qry_inven->Close();
  qry_inven->ParamByName("cia")->AsInteger = cia_z;
  qry_inven->Open();
  qry_vendr->Close();
  qry_vendr->ParamByName("cia")->AsInteger = cia_z;
  qry_vendr->Open();
  qry_ciudad->Close();
  qry_ciudad->Open();
  qry_ptovta->Close();
  qry_ptovta->ParamByName("cia")->AsInteger = cia_z;
  qry_ptovta->Open();

}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::asigna_tipo(int tipo_z)
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


void __fastcall TForm_capvtas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::edt_numentEnter(TObject *Sender)
{
  if(!edt_nument->Value) {
    qry_sigent->Close();
    qry_sigent->ParamByName("tipoent")->AsString = tipoent_z;
    qry_sigent->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
    qry_sigent->Open();
    if(!qry_sigent->IsEmpty()) edt_nument->Value = qry_sigent->FieldByName("sigent")->AsInteger;
    edt_nument->Value++;
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_capvtas::agrerenExecute(TObject *Sender)
{
  if( mi_entrada_z == SIN_ENTRADA) {
    mensaje_z = "Aun no ha accesado " + titulo_z;
    titmsg_z = "Sin " + titulo_z;

    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION);
    return;
  }
  if( qry_entradas->FieldByName("status")->AsString == "C" ) {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede modificar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Modificar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION);
    return;
  }
  edicion_factible(READ_WRITE);
  btn_nvoren->Enabled = false;
  btn_canceren->Enabled = true;
  btn_aceptaren->Enabled = true;
  btn_nvoren->Tag = NUEVO;
  lst_series->Items->Clear();
  edt_canti->Value = 0;
  Form_selserie = NULL;
  lkcmb_inven->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::btn_aceptarenClick(TObject *Sender)
{
  int idrenentra_z=0, folio_z=0, ii_z=0, conse_z = 0, idalm_z = 0, idart_z = 0,
  identrada_z=0, idserie_z = 0, idpers_z=0, cantmueve_z=0, idvend_z=0,
  idciudad_z=0, idptovta_z=0, idcodigo_z=0, iddescri_z=0;
  String tipo_z, siono_z="S", serie_z="", entcan_z="";
  double piva_z=0, costo_z =0;
  cantmueve_z = edt_canti->Value;
  if(cantmueve_z < 1) {
    Application->MessageBox(("No pueden ser "+ IntToStr((int)edt_canti->Value) + " Articulos").c_str(), "Incorrecto Número de Artículos", MB_ICONEXCLAMATION);
    return;
  }
  tipo_z = qry_inven->FieldByName("tipo")->AsString;
  if(tipo_z == "ALF" && (lst_series->Items->Count != edt_canti->Value || Form_selserie == NULL))  {
    Application->MessageBox(("Debe proporcionar "+ IntToStr((int)edt_canti->Value) + " Series").c_str(), "Incorrecto Número de Series", MB_ICONEXCLAMATION);
    return;
  }
  if(Form_selserie != NULL) Form_selserie->qry_folsel->First();

  idvend_z = qry_vendr->FieldByName("idvend")->AsInteger;
  identrada_z = qry_entradas->FieldByName("identrada")->AsInteger;
  if(!cmb_status->Text.IsEmpty()) siono_z = cmb_status->Text.SubString(1,1);
  //siono_z = qry_entradas->FieldByName("coniva")->AsString;
  idalm_z = qry_almacen->FieldByName("idalmacen")->AsInteger;
  idptovta_z = qry_ptovta->FieldByName("idptovta")->AsInteger;
  idart_z = qry_inven->FieldByName("idart")->AsInteger;
  idcodigo_z =dm->busca_iddato(qry_inven->FieldByName("codigo")->AsString, CONCEPTO);
  iddescri_z =dm->busca_iddato(qry_inven->FieldByName("descri")->AsString, CONCEPTO);
  piva_z = qry_inven->FieldByName("piva")->AsFloat;
  idpers_z = dm->busca_iddato(edt_nombre->Text.Trim(), CONCEPTO);
  idciudad_z = qry_ciudad->FieldByName("idciudad")->AsInteger;

  if(tipo_z == "GLO") {
    qry_ultfol->Close();
    qry_ultfol->ParamByName("idart")->AsInteger = idart_z;
    qry_ultfol->ParamByName("idalm")->AsInteger = idalm_z;
    qry_ultfol->ParamByName("cia")->AsInteger = cia_z;
    qry_ultfol->Open();
    folio_z = qry_ultfol->FieldByName("ultfol")->AsInteger;
    serie_z = ""; idserie_z = 0;
  }
  qry_conse->Close();
  qry_conse->ParamByName("identrada")->AsInteger = identrada_z;
  qry_conse->Open();
  conse_z = qry_conse->FieldByName("ultren")->AsInteger;
  qry_insrenen->Close();
  qry_insrenen->ParamByName("idrenentra")->AsInteger = -1;
  qry_insrenen->Open();

  try {
    qry_renentra->Tag = NO_REFRESH;
    dm->manvehi->StartTransaction();
    for(ii_z = 0; ii_z < edt_canti->Value; ii_z++) {
      if(tipo_z == "ALF") {
        serie_z = Form_selserie->qry_folsel->FieldByName("serie")->AsString;
        idserie_z = dm->busca_iddato(serie_z, SERIE);
        folio_z = Form_selserie->qry_folsel->FieldByName("folio")->AsInteger;
      } else {
        idserie_z = 0;
      }
      qry_folsale->Close();
      qry_folsale->ParamByName("idart")->AsInteger = idart_z;
      qry_folsale->ParamByName("idalm")->AsInteger = idalm_z;
      qry_folsale->ParamByName("folio")->AsInteger = folio_z;
      qry_folsale->Open();
      if(qry_folsale->IsEmpty()) {
        dm->manvehi->Rollback();
        Application->MessageBox(("No tengo disponible el folio "+IntToStr(folio_z)).c_str(), "ERROR", MB_ICONEXCLAMATION);
        return;
      }
      if(siono_z == "N")
        piva_z = 0;
      else
        piva_z = qry_inven->FieldByName("piva")->AsFloat;
      // ->End if
      //select a.codigo, a.idart, b.idmovart, b.idalm, b.costo, b.modent,
      //b.folio, b.idserie, b.fecha, c.serie,
      //b.entcan, b.fecentori, facpro, b.idprove
      entcan_z = qry_folsale->FieldByName("entcan")->AsString;
      costo_z = qry_folsale->FieldByName("costo")->AsFloat;


      idrenentra_z=dm->busca_sigid(IDRENENTRA);

      qry_insrenen->Append();
      qry_insrenen->FieldByName("idrenentra")->AsInteger = idrenentra_z;
      qry_insrenen->FieldByName("identrada")->AsInteger = identrada_z;
      qry_insrenen->FieldByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
      qry_insrenen->FieldByName("idrecemi")->AsInteger = idptovta_z;
      qry_insrenen->FieldByName("conse")->AsInteger = conse_z++;
      qry_insrenen->FieldByName("idart")->AsInteger = idart_z;
      qry_insrenen->FieldByName("idcodigo")->AsInteger = idcodigo_z;
      qry_insrenen->FieldByName("iddescri")->AsInteger = iddescri_z;
      qry_insrenen->FieldByName("idserie")->AsInteger = idserie_z;
      qry_insrenen->FieldByName("conse")->AsInteger = ++conse_z;
      qry_insrenen->FieldByName("siono")->AsString = siono_z;
      qry_insrenen->FieldByName("folsal")->AsInteger = folio_z;
      qry_insrenen->FieldByName("folent")->AsInteger = 0;
      qry_insrenen->FieldByName("unids")->AsInteger = 1;
      qry_insrenen->FieldByName("costou")->AsFloat = costo_z;
      qry_insrenen->FieldByName("piva")->AsFloat = piva_z;
      qry_insrenen->FieldByName("importe")->AsFloat = costo_z;
      qry_insrenen->FieldByName("cantmueve")->AsFloat = cantmueve_z;
      if(cantmueve_z) cantmueve_z = 0;
      qry_insrenen->FieldByName("status")->AsString = "A";
      qry_insrenen->FieldByName("persenvrec")->AsInteger = idpers_z;
      qry_insrenen->FieldByName("idvend")->AsInteger = idvend_z;
      qry_insrenen->FieldByName("idciudad")->AsInteger = idciudad_z;
      qry_insrenen->FieldByName("tipago")->AsString = "";
      qry_insrenen->FieldByName("prvta")->AsFloat = 0;
      qry_insrenen->FieldByName("entosal")->AsString = "S";
      qry_insrenen->FieldByName("entcan")->AsString = entcan_z;
      qry_insrenen->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
      qry_insrenen->FieldByName("cia")->AsInteger = cia_z;
      qry_insrenen->Post();
      qry_entradas->Edit();
      qry_entradas->FieldByName("importe")->AsFloat       += costo_z;
      qry_entradas->FieldByName("iva")->AsFloat           += costo_z * piva_z / 100;
      qry_entradas->FieldByName("total")->AsFloat         += costo_z * ((piva_z / 100) + 1);
      qry_entradas->Post();
      if(Form_selserie != NULL) Form_selserie->qry_folsel->Next();
    }
    qry_entradas->ApplyUpdates();
    qry_insrenen->ApplyUpdates();
    dm->manvehi->Commit();
    qry_renentra->Close();
    qry_renentra->ParamByName("identrada")->AsInteger = qry_entradas->FieldByName("identrada")->AsInteger;
    qry_renentra->Open();
  } catch (Exception &E)
  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  edicion_factible(READ_ONLY);
  btn_nvoren->Enabled = true;
  btn_canceren->Enabled = false;
  btn_aceptaren->Enabled = false;
  btn_nvoren->Tag = EN_ESPERA;
  qry_renentra->Tag = SI_REFRESH;
  if(Form_selserie != NULL)  {
    delete Form_selserie; Form_selserie = NULL;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::btn_cancerenClick(TObject *Sender)
{
  edicion_factible(READ_ONLY);
  btn_nvoren->Enabled = true;
  btn_canceren->Enabled = false;
  btn_aceptaren->Enabled = false;
  btn_nvoren->Tag = EN_ESPERA;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::edicion_factible(int modo_z)
{
  bool modo_enabled = true, modo_readonly = false;
  switch (modo_z) {
    case READ_WRITE: modo_enabled = true; modo_readonly = false; break;
    case READ_ONLY: modo_enabled = false; modo_readonly = true; break;
  }
  lkcmb_inven->Enabled = modo_enabled;
  lkcmb_vendedr->Enabled = modo_enabled;
  lkcmb_ptovta->Enabled = modo_enabled;
  lkcmb_ciudad->Enabled = modo_enabled;
  cmb_status->Enabled = modo_enabled;
  edt_canti->ReadOnly = modo_readonly;
  edt_nombre->ReadOnly = modo_readonly;
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::lkcmb_invenExit(TObject *Sender)
{
  //edt_prvta->Value = qry_inven->FieldByName("costos")->AsFloat;
  lst_series->Enabled = (qry_inven->FieldByName("tipo")->AsString == "ALF");
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::edt_cantiExit(TObject *Sender)
{
  int prfol_z = 0, dispo_z=0;
  String folios_z = "";
  if(qry_inven->FieldByName("tipo")->AsString == "GLO") {
    qry_ultfol->Close();
    qry_ultfol->ParamByName("idart")->AsInteger = qry_inven->FieldByName("idart")->AsInteger;
    qry_ultfol->ParamByName("idalm")->AsInteger = qry_almacen->FieldByName("idalmacen")->AsInteger;
    qry_ultfol->ParamByName("fecha")->AsDateTime = qry_entradas->FieldByName("fecha")->AsDateTime;
    qry_ultfol->ParamByName("cia")->AsInteger = cia_z;
    qry_ultfol->Open();
    prfol_z = qry_ultfol->FieldByName("ultfol")->AsInteger + 1;
    dispo_z = qry_ultfol->FieldByName("exist")->AsInteger;
    if(dispo_z < edt_canti->Value) {
      // Si exist es menor que la Cantidad solicitada lo informo
      Application->MessageBox(("Solo Dispone de " + IntToStr(dispo_z)+ " folios").c_str(), "Imposible disponer de folios", MB_ICONEXCLAMATION);
      return;
    }
    edt_folios->Text = IntToStr(prfol_z) + " - " + IntToStr(prfol_z + (int)edt_canti->Value - 1);
  } else {
    if(Form_selserie == NULL) {
       Form_selserie = new TForm_selserie (this);
      Form_selserie->busca_series(
        qry_inven->FieldByName("idart")->AsInteger,
        qry_almacen->FieldByName("idalmacen")->AsInteger,
        (int)edt_canti->Value,
        qry_entradas->FieldByName("fecha")->AsDateTime
      );
    }
    if(Form_selserie->ShowModal() == mrOk) {
      lst_series->Items->Clear();
      for(Form_selserie->qry_folsel->First(); !Form_selserie->qry_folsel->Eof; Form_selserie->qry_folsel->Next()) {
        if(folios_z.IsEmpty())
          folios_z = Form_selserie->qry_folsel->FieldByName("folio")->AsString;
        else
          folios_z = folios_z + " - " + Form_selserie->qry_folsel->FieldByName("folio")->AsString;
        lst_series->Items->Add(Form_selserie->qry_folsel->FieldByName("serie")->AsString);
      }
      lst_series->ItemIndex = 0; edt_folios->Text = folios_z;
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::lst_seriesKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
/*
  if(Key == VK_INSERT) {
    if(lst_series->Items->Count > edt_canti->Value || lst_series->Items->Count == edt_canti->Value) {
      Application->MessageBox(("Solo puedes teclear "+ IntToStr((int)edt_canti->Value) + " Series").c_str(), "Exceso de Series", MB_ICONEXCLAMATION);
      return;
    }
    lst_series->Items->Add(lst_series->Text);
    lst_series->DroppedDown = false;
    lst_series->DroppedDown = true;
  }
  if(Key == VK_DELETE) {
    if(lst_series->Items->Count) lst_series->Items->Delete(lst_series->ItemIndex);
    lst_series->DroppedDown = false;
    lst_series->DroppedDown = true;
  }
*/
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::dbgrd_rengnesKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) borrarenExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::cierrarenExecute(TObject *Sender)
{
  // Este proceso cierra un renglón de entrada especial, hay que agregar el
  // movart, afectar exist, afectar inven, afectar estadis, afectar edoexis
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("Este renglón ya ha sido cerrado previamente", "Renglón Cerrado", MB_ICONEXCLAMATION);
    return;
  }
  if(Application->MessageBox("Seguro de Afectar los datos de Este renglón", "Cerrar Renglón", MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  afecta_kdx();
}
//---------------------------------------------------------------------------

bool __fastcall TForm_capvtas::afecta_kdx()
{
  int idmovart_z = 0, idart_z=0, idalm_z=0, folio_z=0, idcompro_z=0,
      canti_z=1, perio_z=0, nsalida_z=0, idestadis_z = 0, idserie_z = 0,
      idvnd_z = 0, idciu_z=0, idptovta_z=0;
  unsigned short anu_z = 0, mes_z = 0, dia_z = 0;
  String facpro_z = "", siono_z="S";
  TDateTime fecha_z = Now();
  double costo_z = 0;
  bool todobien_z = false;

//IDRENENTRA, IDENTRADA, CONSE, siono, entcan,
//a.IDART, a.IDSERIE, FOLENT, FOLSAL, COSTOU, a.piva, prvta,
//codigo, descri, serie, status, idvend, tipago, persenvrec, idciudad


  idart_z = qry_renentra->FieldByName("idart")->AsInteger;
  idserie_z = qry_renentra->FieldByName("idserie")->AsInteger;
  idalm_z = qry_entradas->FieldByName("idalm")->AsInteger;
  nsalida_z = qry_entradas->FieldByName("numero")->AsInteger;
  idptovta_z = qry_renentra->FieldByName("idrecemi")->AsInteger;
  idvnd_z = qry_renentra->FieldByName("idvend")->AsInteger;
  idciu_z = qry_renentra->FieldByName("idciudad")->AsInteger;
  idcompro_z = qry_renentra->FieldByName("persenvrec")->AsInteger;
  facpro_z = qry_entradas->FieldByName("facpro")->AsString;
  fecha_z = qry_entradas->FieldByName("fecha")->AsDateTime;
  siono_z = qry_renentra->FieldByName("siono")->AsString;
  lkcmb_inven->KeyValue = idart_z;
  if(qry_inven->FieldByName("tipo")->AsString == "GLO") {
    qry_ultfol->Close();
    qry_ultfol->ParamByName("idart")->AsInteger = idart_z;
    qry_ultfol->ParamByName("idalm")->AsInteger = idalm_z;
    qry_ultfol->ParamByName("cia")->AsInteger = cia_z;
    qry_ultfol->Open();
    folio_z = qry_ultfol->FieldByName("ultfol")->AsInteger;
  } else {
    folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
  }
  qry_folsale->Close();
  qry_folsale->ParamByName("idart")->AsInteger = idart_z;
  qry_folsale->ParamByName("idalm")->AsInteger = idalm_z;
  qry_folsale->ParamByName("folio")->AsInteger = folio_z;
  qry_folsale->Open();
  if(qry_folsale->IsEmpty()) {
    Application->MessageBox(("No tengo disponible el folio "+IntToStr(folio_z)).c_str(), "ERROR", MB_ICONEXCLAMATION);
    return (todobien_z);
  }
  idmovart_z = qry_folsale->FieldByName("idmovart")->AsInteger;
  costo_z = qry_folsale->FieldByName("costo")->AsFloat;
  qry_movart->Close();
  qry_movart->ParamByName("idmovart")->AsInteger = idmovart_z;
  qry_movart->Open();
  if(qry_movart->IsEmpty()) {
    Application->MessageBox(("No tengo disponible el movart "+IntToStr(idmovart_z)).c_str(), "ERROR", MB_ICONEXCLAMATION);
    return (todobien_z);
  }

  fecha_z.DecodeDate(&anu_z, &mes_z, &dia_z);
  perio_z = anu_z * 100 + mes_z;
  try {
    dm->manvehi->StartTransaction();
    qry_movart->Edit();
//    folio_z = qry_ultfol->FieldByName("ultfol")->AsInteger + 1;
//    idmovart_z = dm->busca_sigid(IDMOVART);
    // IDMOVART, IDART, IDALM, FOLIO, IDPROVE, NOMPRO, COMPRO,
    // FACPRO, FECHA, COSTO, SESPE, MODSAL, MODENT, NENTRADA,
    // TIPO, IDALMVIENE, FOLVIENE, IDALMHACIA, FOLREC, IDCIUDAD,
    // NUMFAC, SERIEFAC, SALIO, SMAY, FECHASAL,  CANTI, IDSERIE, SALVTA,
    // ENTCAN, NSALIDA, ENTRAPOR, SALEPOR, FECENTORI,
    // FECVENCTO, IDUSUARIO, CIA, IDPTOVTA, IDVEND
//    qry_movart->Append();
//    qry_movart->FieldByName("idmovart")->AsInteger = idmovart_z;
//    qry_movart->FieldByName("idart")->AsInteger = idart_z;
//    qry_movart->FieldByName("idalm")->AsInteger = idalm_z;
//    qry_movart->FieldByName("folio")->AsInteger = folio_z;
//    qry_movart->FieldByName("idprove")->AsInteger = 0;
//    qry_movart->FieldByName("nompro")->AsInteger = idcompro_z;
    qry_movart->FieldByName("compro")->AsInteger = idcompro_z;
//    qry_movart->FieldByName("facpro")->AsString = facpro_z;
//    qry_movart->FieldByName("fecha")->AsDateTime = fecha_z;
//    qry_movart->FieldByName("costo")->AsFloat = costo_z;
    qry_movart->FieldByName("sespe")->AsString = "N";
    qry_movart->FieldByName("modsal")->AsString = siono_z;
    qry_movart->FieldByName("salvta")->AsString = "S";
//    qry_movart->FieldByName("modent")->AsString = siono_z;
//    qry_movart->FieldByName("nentrada")->AsInteger = nsalida_z;
//    qry_movart->FieldByName("tipo")->AsString = "E";
//    qry_movart->FieldByName("numfac")->AsInteger = 0;
//    qry_movart->FieldByName("seriefac")->AsString = "";
    qry_movart->FieldByName("salio")->AsString = "S";
//    qry_movart->FieldByName("smay")->AsString = "N";
//    qry_movart->FieldByName("idalmviene")->AsInteger = 0;
//    qry_movart->FieldByName("folviene")->AsInteger = 0;
//    qry_movart->FieldByName("idalmhacia")->AsInteger = 0;
//    qry_movart->FieldByName("folrec")->AsInteger = 0;
    qry_movart->FieldByName("idciudad")->AsInteger = idciu_z;
    qry_movart->FieldByName("idserie")->AsInteger = idserie_z;
//    if(chk_entcan->Checked)
//      qry_movart->FieldByName("entcan")->AsString = "S";
//    else
//      qry_movart->FieldByName("entcan")->AsString = "N";
    // ->End if
    qry_movart->FieldByName("nsalida")->AsInteger = nsalida_z;
//    qry_movart->FieldByName("canti")->AsInteger = canti_z;
//    qry_movart->FieldByName("entrapor")->AsInteger = entrapor_z;
    qry_movart->FieldByName("salepor")->AsInteger = entrapor_z;
    qry_movart->FieldByName("fechasal")->AsDateTime = fecha_z;
//    qry_movart->FieldByName("fecentori")->AsDateTime = fecha_z;
//    qry_movart->FieldByName("fecvencto")->AsDateTime = fecha_z;
//    qry_movart->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
//    qry_movart->FieldByName("cia")->AsInteger = cia_z;
    qry_movart->FieldByName("idptovta")->AsInteger = idptovta_z;
    qry_movart->FieldByName("idvend")->AsInteger = idvnd_z;
    qry_movart->Post();
    qry_exist->Close();
    qry_exist->ParamByName("idart")->AsInteger = idart_z;
    qry_exist->ParamByName("idalm")->AsInteger = idalm_z;
    qry_exist->Open();
    if(qry_exist->IsEmpty()) {
      // IDART, IDALM, EXISTES, EXISTEN, ULTFOL, CIA
      qry_exist->Append();
      qry_exist->FieldByName("idart")->AsInteger = idart_z;
      qry_exist->FieldByName("idalm")->AsInteger = idalm_z;
      qry_exist->FieldByName("cia")->AsInteger = cia_z;
      qry_exist->FieldByName("existes")->AsFloat = 0;
      qry_exist->FieldByName("existen")->AsFloat = 0;
    } else {
      qry_exist->Edit();
    }
    if(siono_z == "S")
      qry_exist->FieldByName("existes")->AsFloat -= canti_z;
    else
      qry_exist->FieldByName("existen")->AsFloat -= canti_z;
    //-> Endif
//    qry_exist->FieldByName("ultfol")->AsInteger = folio_z;
    qry_exist->Post();
    qry_edoexi->Close();
    qry_edoexi->ParamByName("idart")->AsInteger = idart_z;
    qry_edoexi->ParamByName("idalm")->AsInteger = idalm_z;
    qry_edoexi->ParamByName("tipo")->AsInteger = entrapor_z;
    qry_edoexi->ParamByName("eos")->AsString = "S";
    qry_edoexi->ParamByName("sino")->AsString = siono_z;
    qry_edoexi->Open();
    if(qry_edoexi->IsEmpty()) {
      qry_edoexi->Append();
      qry_edoexi->FieldByName("idart")->AsInteger = idart_z;
      qry_edoexi->FieldByName("idalm")->AsInteger = idalm_z;
      qry_edoexi->FieldByName("tipo")->AsInteger = entrapor_z;
      qry_edoexi->FieldByName("eos")->AsString = "S";
      qry_edoexi->FieldByName("sino")->AsString = siono_z;
    } else {
      qry_edoexi->Edit();
    }
    qry_edoexi->FieldByName("unids")->AsFloat += canti_z;
    qry_edoexi->FieldByName("costo")->AsFloat += costo_z;
    qry_edoexi->Post();
    qry_renentra->Edit();
    qry_renentra->FieldByName("status")->AsString = "C";
    qry_renentra->FieldByName("folsal")->AsInteger = folio_z;
    qry_renentra->Post();
//    (IDART, IDALM, TIPO, EOS, SINO, UNIDS, COSTO)

//  (IDESTADIS, TIPO, IDART, IDALM, PERIO, UNIDADES, IMPORTE, CIA)
    qry_estadis->Close();
    qry_estadis->ParamByName("tipo")->AsInteger = entrapor_z;
    qry_estadis->ParamByName("idart")->AsInteger = idart_z;
    qry_estadis->ParamByName("idalm")->AsInteger = idalm_z;
    qry_estadis->ParamByName("perio")->AsInteger = perio_z;
    qry_estadis->Open();
    if(qry_estadis->IsEmpty()) {
      idestadis_z = dm->busca_sigid(IDESTADIS);
      qry_estadis->Append();
      qry_estadis->FieldByName("idestadis")->AsInteger = idestadis_z;
      qry_estadis->FieldByName("tipo")->AsInteger = entrapor_z;
      qry_estadis->FieldByName("idart")->AsInteger = idart_z;
      qry_estadis->FieldByName("idalm")->AsInteger = idalm_z;
      qry_estadis->FieldByName("perio")->AsInteger = perio_z;
      qry_estadis->FieldByName("cia")->AsInteger = cia_z;
    } else {
      qry_estadis->Edit();
    }
    qry_estadis->FieldByName("unidades")->AsFloat += canti_z;
    qry_estadis->FieldByName("importe")->AsFloat += costo_z;
    qry_estadis->Post();

    qry_edoexi->ApplyUpdates();
    qry_exist->ApplyUpdates();
    qry_movart->ApplyUpdates();
    qry_renentra->ApplyUpdates();
    qry_estadis->ApplyUpdates();
    dm->manvehi->Commit();
    todobien_z = true;
  } catch (Exception &E)  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    todobien_z = false;
  }
  return (todobien_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_capvtas::borrarenExecute(TObject *Sender)
{
  double costo_z = 0, piva_z = 0;
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede modificar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Modificar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  if(qry_renentra->FieldByName("status")->AsString == "C") {
    Application->MessageBox("No puede eliminar renglones cerrados", "Renglón Cerrado", MB_ICONEXCLAMATION);
    return;
  }
  if(Application->MessageBox("Seguro de eliminar este renglón", "Eliminar Renglón", MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  costo_z = qry_renentra->FieldByName("costou")->AsFloat;
  piva_z = qry_renentra->FieldByName("piva")->AsFloat;
//  idrenentra_z = qry_renentra->FieldByName("idrenentra")->AsInteger;
  qry_entradas->Edit();
  qry_entradas->FieldByName("importe")->AsFloat       -= costo_z;
  qry_entradas->FieldByName("iva")->AsFloat           -= costo_z * piva_z / 100;
  qry_entradas->FieldByName("total")->AsFloat         -= costo_z * ((piva_z / 100) + 1);
  qry_entradas->Post();
  qry_renentra->Delete();
  try {
    dm->manvehi->StartTransaction();
    qry_entradas->ApplyUpdates();
    qry_renentra->ApplyUpdates();
//    qry_borraren->Close();
//    qry_borraren->ParamByName("idrenentra")->AsInteger = idrenentra_z;
//    qry_borraren->ExecSQL();
    dm->manvehi->Commit();
  } catch (Exception &E)  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::exportdbgridExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = "*.xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    switch( SaveDialog->FilterIndex) {
      case 1: dbgrd_rengnes->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
      case 2: dbgrd_rengnes->SaveToXLS(SaveDialog->FileName, true); break;
      case 3: dbgrd_rengnes->SaveToHTML(SaveDialog->FileName, true); break;
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::cierra_entradaExecute(TObject *Sender)
{
  bool todobien_z = true;
  if(qry_entradas->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z + " previamente";
    titmsg_z = titulo_z + cerrado_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  mensaje_z = "Seguro de cerrar " + este_z + " " + titulo_z;
  titmsg_z = "Cerrar " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  for(qry_renentra->First(); !qry_renentra->Eof && todobien_z; qry_renentra->Next()) {
    if(qry_renentra->FieldByName("status")->AsString != "C") todobien_z = afecta_kdx();
  }
  if(todobien_z) {
    try {
      dm->manvehi->StartTransaction();
      qry_entradas->Edit();
      qry_entradas->FieldByName("status")->AsString = "C";
      qry_entradas->Post();
      qry_entradas->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)  {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  } else {
    mensaje_z = "No puede cerrar " + este_z + " " + titulo_z + " debido a que surgió algún problmea con algún renglón";
    titmsg_z = "ERROR EN RENGLONES";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::impritextExecute(TObject *Sender)
{
  double piva_z=0, importe_z=0, iva_z=0, total_z=0;
  String arch_z = "capvtas.txt", serie_z="", vnd_z="", pvta_z="", ciu_z="";
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresión de " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_renentra->DisableControls();
  qry_renentra->Tag == NO_REFRESH;
  qry_renentra->First();
//  if(!qry_renentra->IsEmpty())
//    zona_z = qry_renpogas->FieldByName("zona")->AsInteger;
  pagina_z = 1; report_encab();
  for(qry_renentra->First(); !qry_renentra->Eof; qry_renentra->Next()) {
    if(lineas_z > LIN_X_PAG) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab();
    }
/*
    if(qry_renentra->FieldByName("zona")->AsInteger != zona_z) {
      fprintf(archout, "%s", cjust("Total de Esta Zona:", 70));
      rendto_z=0;
      fprintf(archout, "%s ", rjust(FormatFloat("###,##0", reczon_z), 7));
      if(litzon_z) rendto_z = reczon_z / litzon_z;
      fprintf(archout, "%s   ", rjust(FormatFloat("##.00", rendto_z), 7));
      fprintf(archout, "%s ", rjust(FormatFloat("###0.00", litzon_z), 7));
      fprintf(archout, "%s\n\n", rjust(FormatFloat("#,###,##0.00", impzon_z), 20));
      lineas_z +=2;
      rectot_z += reczon_z; reczon_z = 0;
      littot_z += litzon_z; litzon_z = 0;
      imptot_z += impzon_z; impzon_z = 0;
      zona_z = qry_renentra->FieldByName("zona")->AsInteger;
      report_subencab();
    }
*/
    lkcmb_vendedr->KeyValue = qry_renentra->FieldByName("idvend")->AsInteger;
    vnd_z = qry_vendr->FieldByName("codigo")->AsString;
    lkcmb_ptovta->KeyValue = qry_renentra->FieldByName("idrecemi")->AsInteger;
    pvta_z = qry_ptovta->FieldByName("clave")->AsString;
    lkcmb_ciudad->KeyValue = qry_renentra->FieldByName("idciudad")->AsInteger;
    ciu_z = qry_ciudad->FieldByName("ciudad")->AsString;
    fprintf(archout, "%s %s|%s|%s|%s|%s|%s|%s|%s|%s|%s\n",
      ljust(qry_renentra->FieldByName("codigo")->AsString, 13),
      ljust(qry_renentra->FieldByName("descri")->AsString, 30),
      rjust(IntToStr(qry_renentra->FieldByName("folsal")->AsInteger), 5),
      rjust(FormatFloat("#,###,##0.00", qry_renentra->FieldByName("costou")->AsFloat), 12),
      ljust(qry_renentra->FieldByName("entcan")->AsString, 1),
      ljust(qry_renentra->FieldByName("siono")->AsString, 1),
      ljust(qry_renentra->FieldByName("serie")->AsString, 20),
      ljust(dm->busca_dato(qry_renentra->FieldByName("persenvrec")->AsInteger, CONCEPTO).c_str(), 20),
      ljust(pvta_z, 4),
      ljust(vnd_z, 4),
      ljust(ciu_z, 10)
    );
    piva_z = qry_renentra->FieldByName("piva")->AsFloat;
    importe_z += qry_renentra->FieldByName("costou")->AsFloat;
    iva_z += qry_renentra->FieldByName("costou")->AsFloat * (piva_z / 100);
    total_z = importe_z + iva_z;
  }
  fprintf(archout, "%s\n",
    rjust(
      "Importe:" + FormatFloat("#,###,##0.00", importe_z) +
      "   Iva:" + FormatFloat("#,###,##0.00", iva_z) +
      "   Total:" + FormatFloat("#,###,##0.00", total_z), 63
    )
  );
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renentra->Tag == SI_REFRESH;
  qry_renentra->EnableControls();
  manda_imp(arch_z, dm->rutaimp_z, dm->tipoimp_z, dm->ff_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::report_encab()
{
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de %s\n", titulo_z);
  fprintf(archout, "Numero:%6d Almacen:%s %s Fecha:%s\n",
    qry_entradas->FieldByName("numero")->AsInteger,
    qry_almacen->FieldByName("clave")->AsString,
    qry_almacen->FieldByName("nombre")->AsString,
    FormatDateTime("dd-mm-yyyy", qry_entradas->FieldByName("fecha")->AsDateTime),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s%s%s|%s|%s|%s|%s|%s|%s|%s|%s|%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON),
    cjust("Articulo", 44),
    rjust("Folio", 5),
    rjust("Costo_Unitar", 12),
    "C",
    "S",
    ljust("Serie", 20),
    ljust("Cliente", 20),
    ljust("Pvta", 4),
    ljust("Vnd", 4),
    ljust("Población", 10),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::report_subencab()
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





void __fastcall TForm_capvtas::qry_renentraAfterScroll(TDataSet *DataSet)
{
    char fpago_z;
    String tipago_z;
    if(qry_renentra->Tag == NO_REFRESH && qry_renentra->Eof) return;
    lkcmb_inven->KeyValue = qry_renentra->FieldByName("idart")->AsInteger;
    lkcmb_vendedr->KeyValue = qry_renentra->FieldByName("idvend")->AsInteger;
    lkcmb_ptovta->KeyValue = qry_renentra->FieldByName("idrecemi")->AsInteger;
    /* edt_prvta->Value = qry_renentra->FieldByName("prvta")->AsFloat;
    tipago_z = qry_renentra->FieldByName("tipago")->AsString;
    fpago_z = 'A';
    if(!tipago_z.IsEmpty()) fpago_z = tipago_z[1];
    switch (fpago_z) {
      case 'A': cmb_formapag->ItemIndex = 0; break;
      case 'C': cmb_formapag->ItemIndex = 1; break;
      case 'E': cmb_formapag->ItemIndex = 2; break;
    }
    */
    edt_nombre->Text = dm->busca_dato(qry_renentra->FieldByName("persenvrec")->AsInteger, CONCEPTO);
    lkcmb_ciudad->KeyValue = qry_renentra->FieldByName("idciudad")->AsInteger;
    lst_series->Items->Clear();
    lst_series->Items->Add(qry_renentra->FieldByName("serie")->AsString);
}
//---------------------------------------------------------------------------

void __fastcall TForm_capvtas::lkcmb_invenEnter(TObject *Sender)
{
  edt_canti->Value = 0;
}
//---------------------------------------------------------------------------

