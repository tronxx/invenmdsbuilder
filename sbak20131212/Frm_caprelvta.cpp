//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include <inifiles.hpp>
#include "Frm_caprelvta.h"
#include "dmod.h"
#include "numapal.h"
#include "imprigra.h"
#include "Frm_selserie.h"
#include "dialg_foliosdisp.h"
#include "Frm_prever.h"
#include "Frme_datoscaptrasp.h"
#include "dialg_okcancel.h"
#include "Frme_datosrelvta.h"
#include <sys\timeb.h>

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
#pragma link "RzLabel"
#pragma link "Frme_datosrelvta"
#pragma resource "*.dfm"
#include "situaciones.h"

const int NUEVA_POLIZA     = 1;
const int NUEVA_RELACION   = 2;

TForm_caprelvta *Form_caprelvta;
//---------------------------------------------------------------------------
void __fastcall CapturaRelacionVentas(TForm *Padre)
{
    try
    {
        Form_caprelvta = new TForm_caprelvta(Padre);
        Form_caprelvta->Show();
    }
    catch(...)
    {
    }

}
//---------------------------------------------------------------------------
__fastcall TForm_caprelvta::TForm_caprelvta(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  int idrelvtas_z = 0;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  //qry_entradas->Close();
  //qry_entradas->ParamByName("numero")->AsInteger = edt_nument->Value;
  //qry_entradas->ParamByName("cia")->AsInteger = cia_z;
  //qry_entradas->Open();
  if(qry_entradas->IsEmpty()) return;
  mensaje_z = "Esta seguro de eliminar " + este_z + " " + titulo_z + " ? ";
  titmsg_z = "Eliminar " + titulo_z;

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    idrelvtas_z = qry_entradas->FieldByName("idrelvtas")->AsInteger;
    Frame_datosrelvta1->qry_renentra->Tag = NO_REFRESH;
    qry_entradas->Tag = NO_REFRESH;
    for(Frame_datosrelvta1->qry_renentra->First(); !Frame_datosrelvta1->qry_renentra->Eof; Frame_datosrelvta1->qry_renentra->First() ) {
        Frame_datosrelvta1->qry_renentra->Delete();
    }
    qry_invcomprometart->Close();
    qry_invcomprometart->ParamByName("idrelvtaart")->AsInteger = -1;
    qry_invcomprometart->ParamByName("idrelvtas")->AsInteger = idrelvtas_z;
    qry_invcomprometart->Open();
    for(qry_invcomprometart->First(); !qry_invcomprometart->Eof; qry_invcomprometart->First() ) {
        qry_invcomprometart->Delete();
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
      if (qry_entradas->UpdatesPending)        qry_entradas->ApplyUpdates();
      if (qry_invcomprometart->UpdatesPending) qry_invcomprometart->ApplyUpdates();
      if (Frame_datosrelvta1->qry_renentra->UpdatesPending)        Frame_datosrelvta1->qry_renentra->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    Frame_datosrelvta1->qry_renentra->Tag = SI_REFRESH;
    qry_entradas->Tag = SI_REFRESH;
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_caprelvta::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  //qry_entradas->Close();
  //qry_entradas->ParamByName("numero")->AsInteger = edt_nument->Value;
  //qry_entradas->ParamByName("cia")->AsInteger = cia_z;
  //qry_entradas->Open();
  if(qry_entradas->IsEmpty()) {
    mensaje_z = "No existe " + titulo_z + " que desea modificar";
    titmsg_z = titulo_z + " Inexistente ";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt(MODIF);
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::desp_ptvt()
{
     int idrelvta_z=0, idtipocte_z=0, idtipopago_z=0;
     String tipocte_z;
     TLocateOptions Opts;
     Opts.Clear();
     tipocte_z = qry_entradas->FieldByName("tipocte")->AsString;
     idrelvta_z = qry_entradas->FieldByName("idrelvtas")->AsInteger;
     idtipopago_z  = qry_entradas->FieldByName("tipopago")->AsInteger;
     if(Frame_datosrelvta1->qry_tiposctes->State == dsInactive) return;
     // Le puse esta condición para que se regrese y me permita seguir trabajando
     Frame_datosrelvta1->qry_tiposctes->First();
     if (Frame_datosrelvta1->qry_tiposctes->Locate("ticte", tipocte_z, Opts) )
        Frame_datosrelvta1->lkcmb_tipocte->KeyValue = Frame_datosrelvta1->qry_tiposctes->FieldByName("idticte")->AsInteger;
     Frame_datosrelvta1->edt_nument->Value = qry_entradas->FieldByName("folio")->AsInteger;
     Frame_datosrelvta1->edt_nombre->Text=dm->busca_dato(qry_entradas->FieldByName("idnombre")->AsInteger, OLDCONCEPTO);
     //date_fecha->Date       = qry_entradas->FieldByName("fecha")->AsDateTime;
     Frame_datosrelvta1->lkcmb_entrega->KeyValue  = qry_entradas->FieldByName("entrega")->AsString;
     Frame_datosrelvta1->lkcmb_vendedr->KeyValue = qry_entradas->FieldByName("vendedor")->AsString;
     Frame_datosrelvta1->lkcmb_ptovta->KeyValue  = qry_entradas->FieldByName("ptovta")->AsString;
     Frame_datosrelvta1->lkcmb_tipoentr->KeyValue = qry_entradas->FieldByName("idtipoentrega")->AsInteger;
     Frame_datosrelvta1->lkcmb_tipopago->KeyValue = idtipopago_z;
     Frame_datosrelvta1->date_fentrega->Date     = qry_entradas->FieldByName("fechaent")->AsDateTime;
     Frame_datosrelvta1->date_hora->Time         = tiemporel(qry_entradas->FieldByName("hora")->AsInteger);
     Frame_datosrelvta1->lkcmb_ciudad->KeyValue   = qry_entradas->FieldByName("idpoblac")->AsInteger;
     qry_direcs->Close();
     qry_direcs->ParamByName("idrelvta")->AsInteger = idrelvta_z;
     qry_direcs->Open();
     Frame_datosrelvta1->mmo_direc->Lines->Clear();
     for ( ; !qry_direcs->Eof; qry_direcs->Next())
       Frame_datosrelvta1->mmo_direc->Lines->Add(qry_direcs->FieldByName("direc")->AsString);
     Frame_datosrelvta1->qry_renentra->Tag = NO_REFRESH;
     Frame_datosrelvta1->qry_renentra->Close();
     Frame_datosrelvta1->qry_renentra->ParamByName("idrelvtas")->AsInteger = idrelvta_z;
     Frame_datosrelvta1->qry_renentra->Open();
     Frame_datosrelvta1->qry_renentra->Tag = SI_REFRESH;
     Frame_datosrelvta1->despliega_renentra();
}
//---------------------------------------------------------------------------


void __fastcall TForm_caprelvta::nuevoExecute(TObject *Sender)
{
  if(qry_polrelvta->IsEmpty()) {
    Application->MessageBox("Aun no ha accesado ninguna póliza, no puede agregar datos", "Sin Póliza Activa", MB_ICONEXCLAMATION);
    return;
  }
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt(NUEVO);
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::primeroExecute(TObject *Sender)
{
  qry_entradas->First();
  //String sql_z;
  //sql_z = "select min (folio) as numero from inv_relvtas where cia = ";
  //sql_z = sql_z + IntToStr(cia_z);
  //mueve_hacia(sql_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::anteriorExecute(TObject *Sender)
{
  qry_entradas->Prior();
  //String sql_z;
  //sql_z = "select max (folio) as numero from inv_relvtas where cia = ";
  //sql_z = sql_z + IntToStr(cia_z) + " and folio < " + IntToStr((int) edt_nument->Value);
  //mueve_hacia(sql_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::siguienteExecute(TObject *Sender)
{
  qry_entradas->Next();
  //String sql_z;
  //sql_z = "select min (folio) as numero from inv_relvtas where ";
  //sql_z = sql_z + " cia = " + IntToStr(cia_z) +
  //   " and folio > " + IntToStr((int) edt_nument->Value);
  //mueve_hacia(sql_z);
}
//---------------------------------------------------------------------------
void __fastcall TForm_caprelvta::ultimoExecute(TObject *Sender)
{
  qry_entradas->Last();
  //String sql_z;
  //sql_z = "select max (folio) as numero from inv_relvtas where ";
  //sql_z = sql_z + "cia = " + IntToStr(cia_z);
  //mueve_hacia(sql_z);
}
//-------------------------------------------------------------------------

int __fastcall TForm_caprelvta::dame_sigte_folio()
{
  int sigent_z=0;
  qry_sigent->Close();
  qry_sigent->ParamByName("cia")->AsInteger = cia_z;
  qry_sigent->Open();
  if(!qry_sigent->IsEmpty()) sigent_z = qry_sigent->FieldByName("sigent")->AsInteger;
  return (sigent_z + 1);
}
//-------------------------------------------------------------------------


void __fastcall TForm_caprelvta::alta_ptvt(int modo_z)
{
   int idrelvta_z= 0, idtipoentrega_z=0, idciudad_z=0, idnombre_z=0,
       idpolrelvta_z=0, cuantasdir_z, iddirvta_z, idconcep_z, ii_z,
       min_z=0, idrenentra_z=0, idcomprometart_z=0, ancho_z, alto_z,
       numero_z=0, idtipopago_z=0, nument_z=0;
   String vendedor_z, chofer_z, tipocte_z, ptovta_z, direc_z;

  TDateTime fecha_z;
  String alm_z, strfecha_z, strfechoy_z, strfecatras_z, ubicacion_z;
  bool todook_z = true;
  nument_z = dame_sigte_folio();
  //date_fecha->Date    = Now();
  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TFrame_datosrelvta *Frame_datosrelvta2;
  Frame_datosrelvta2 = new TFrame_datosrelvta (Dlg_analipol);
  ancho_z = Frame_datosrelvta2->Width + 20;
  alto_z = Frame_datosrelvta2->Height + Dlg_analipol->Panel2->Height + 80;
  Frame_datosrelvta2->Parent = Dlg_analipol->Panel1;
  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;
  Dlg_analipol->Caption = "Captura de Datos";
  Frame_datosrelvta2->Align = alClient;
  Frame_datosrelvta2->inicializa("");
  Frame_datosrelvta2->edt_nument->Value = nument_z;
  Frame_datosrelvta2->edt_nument->ReadOnly = true;
  //Frame_datosrelvta->accion_z = NUEVO;
  Dlg_analipol->Position = poScreenCenter;
  if( Dlg_analipol->ShowModal() == mrOk) {
    agrega_punto("Iniciando:", 0);
    idpolrelvta_z = qry_polrelvta->FieldByName("idpolrelvta")->AsInteger;
    idnombre_z = dm->busca_iddato(Frame_datosrelvta2->edt_nombre->Text.Trim(), OLDCONCEPTO);
    idciudad_z = Frame_datosrelvta2->qry_ciudad->FieldByName("numero")->AsInteger;
    chofer_z = Frame_datosrelvta2->qry_chofer->FieldByName("clave")->AsString;
    vendedor_z = Frame_datosrelvta2->qry_vendr->FieldByName("codigo")->AsString;
    tipocte_z = Frame_datosrelvta2->qry_tiposctes->FieldByName("ticte")->AsString;
    ptovta_z = Frame_datosrelvta2->qry_ptovta->FieldByName("clave")->AsString;
    min_z = minutos(Frame_datosrelvta2->date_hora->Time);
    idtipoentrega_z = Frame_datosrelvta2->qry_tipoentrega->FieldByName("idtipoentrega")->AsInteger;
    idtipopago_z = Frame_datosrelvta2->qry_formapago->FieldByName("idcrdcon")->AsInteger;
    Frame_datosrelvta2->qry_exist->Tag = NO_REFRESH;
    try {
      dm->manvehi->StartTransaction();
      agrega_punto("Inicio Transaccion:", 1);

      if (modo_z == NUEVO) {
        agrega_punto("Buscando dm->busca_sigid(IDINVRELVTAS):", 12);
        idrelvta_z=dm->busca_sigid(IDINVRELVTAS);
        agrega_punto("Ya obtuve dm->busca_sigid(IDINVRELVTAS):", 12);
        qry_entradas->Append();
        qry_entradas->FieldByName("idrelvtas")->AsInteger = idrelvta_z;
        qry_entradas->FieldByName("idpolrelvta")->AsInteger = idpolrelvta_z;
        qry_entradas->FieldByName("folio")->AsInteger = dame_sigte_folio();
      } else {
        idrelvta_z = qry_entradas->FieldByName("idrelvtas")->AsInteger;
        qry_entradas->Edit();
      }
      qry_entradas->FieldByName("fecha")->AsDateTime = date_fecha->Date;
      qry_entradas->FieldByName("hora")->AsInteger = min_z;
      qry_entradas->FieldByName("idnombre")->AsInteger = idnombre_z;
      qry_entradas->FieldByName("tipocte")->AsString = tipocte_z;
      qry_entradas->FieldByName("idtipoentrega")->AsInteger = idtipoentrega_z;
      qry_entradas->FieldByName("ptovta")->AsString = ptovta_z;
      qry_entradas->FieldByName("fechaent")->AsDateTime = Frame_datosrelvta2->date_fentrega->Date;
      qry_entradas->FieldByName("entrega")->AsString = chofer_z;
      qry_entradas->FieldByName("vendedor")->AsString = vendedor_z;
      qry_entradas->FieldByName("idpoblac")->AsInteger = idciudad_z;
      qry_entradas->FieldByName("tipopago")->AsInteger = idtipopago_z;
      qry_entradas->FieldByName("idusuario")->AsInteger = idusuario_z;
      qry_entradas->FieldByName("feccap")->AsDateTime = dm->ahora();
      qry_entradas->FieldByName("cia")->AsInteger = cia_z;
      qry_entradas->Post();
      agrega_punto("Agregado Entradas:", 1);
      qry_direcs->Close();
      qry_direcs->ParamByName("idrelvta")->AsInteger = idrelvta_z;
      qry_direcs->Open();
      qry_direcs->First();
      cuantasdir_z = qry_direcs->RecordCount;
      iddirvta_z=dm->busca_sigid(IDINVDIRVTA);
      for ( ii_z = 0; ii_z < Frame_datosrelvta2->mmo_direc->Lines->Count; ii_z++) {
         direc_z = Frame_datosrelvta2->mmo_direc->Lines->Strings[ii_z];
         idconcep_z = dm->busca_iddato(direc_z.Trim().UpperCase(), OLDCONCEPTO);
         if (ii_z >= cuantasdir_z) {
            qry_direcs->Append();
            qry_direcs->FieldByName("iddirvta")->AsInteger = iddirvta_z;
            qry_direcs->FieldByName("idrelvtas")->AsInteger = idrelvta_z;
            iddirvta_z++;
         } else {
            qry_direcs->Edit();
         }
         qry_direcs->FieldByName("idconcep")->AsInteger = idconcep_z;
         qry_direcs->FieldByName("direc")->AsString = direc_z;
         qry_direcs->FieldByName("conse")->AsInteger = ii_z;
         qry_direcs->Post();
      }
      for (qry_direcs->Last(); ii_z < cuantasdir_z; qry_direcs->Last() ) {
         qry_direcs->Delete();
         ii_z++;
      }
      agrega_punto("Agregado Direcs:", 2);
      idrenentra_z = 0; idcomprometart_z = 0;
      qry_renentranew->Close();
      qry_renentranew->ParamByName("idrelvtas")->AsInteger = -1;
      qry_renentranew->Open();
      qry_invcomprometart->Close();
      qry_invcomprometart->ParamByName("idrelvtaart")->AsInteger = -1;
      qry_invcomprometart->ParamByName("idrelvtas")->AsInteger = -1;
      qry_invcomprometart->Open();
      Frame_datosrelvta2->qry_renentra->Tag = NO_REFRESH;
      for ( Frame_datosrelvta2->qry_renentra->First(); !Frame_datosrelvta2->qry_renentra->Eof; Frame_datosrelvta2->qry_renentra->Next() ) {
        if (idrenentra_z) {
           idrenentra_z++;
        } else {
           idrenentra_z = dm->busca_sigid(IDINVRELVTAART);
        }
        if ( Frame_datosrelvta2->qry_renentra->FieldByName("idrelvtaart")->AsInteger < 0) {
          qry_renentranew->Append();
          qry_renentranew->FieldByName("codigo")->AsString = Frame_datosrelvta2->qry_renentra->FieldByName("codigo")->AsString;
          qry_renentranew->FieldByName("descri")->AsString = Frame_datosrelvta2->qry_renentra->FieldByName("descri")->AsString;
          qry_renentranew->FieldByName("idcodigo")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("idcodigo")->AsInteger;
          qry_renentranew->FieldByName("iddescri")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("iddescri")->AsInteger;
          qry_renentranew->FieldByName("idrelvtaart")->AsInteger = idrenentra_z;
          qry_renentranew->FieldByName("idrelvtas")->AsInteger = idrelvta_z;
          qry_renentranew->FieldByName("idart")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("idart")->AsInteger;
          qry_renentranew->FieldByName("salede")->AsString = Frame_datosrelvta2->qry_renentra->FieldByName("salede")->AsString;
          qry_renentranew->FieldByName("preciolista")->AsFloat = Frame_datosrelvta2->qry_renentra->FieldByName("preciolista")->AsFloat;
          qry_renentranew->FieldByName("conse")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("conse")->AsInteger;
          qry_renentranew->FieldByName("idreltransf")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("idreltransf")->AsInteger;
          qry_renentranew->FieldByName("idpolrelvta")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("idpolrelvta")->AsInteger;
          qry_renentranew->Post();
          if (idcomprometart_z) {
            idcomprometart_z++;
          } else {
            idcomprometart_z = dm->busca_sigid(IDCOMPROMETART);
          }
          // idcomprometart, idart, idalm, idrelvtaart, codigo, alm, unids, cia
          qry_invcomprometart->Append();
          qry_invcomprometart->FieldByName("idcomprometart")->AsInteger = idcomprometart_z;
          qry_invcomprometart->FieldByName("idart")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("idart")->AsInteger;
          qry_invcomprometart->FieldByName("idalm")->AsInteger = 0;
          qry_invcomprometart->FieldByName("idrelvtaart")->AsInteger = idrenentra_z;
          qry_invcomprometart->FieldByName("codigo")->AsString = Frame_datosrelvta2->qry_renentra->FieldByName("codigo")->AsString;
          qry_invcomprometart->FieldByName("alm")->AsString = Frame_datosrelvta2->qry_renentra->FieldByName("salede")->AsString;
          qry_invcomprometart->FieldByName("unids")->AsInteger = Frame_datosrelvta2->qry_renentra->FieldByName("folio")->AsInteger;
          qry_invcomprometart->FieldByName("cia")->AsInteger = cia_z;
          qry_invcomprometart->Post();
        }
     }
     agrega_punto("Agregado renentra y comprometart:", 3);
     qry_entradas->ApplyUpdates();
     agrega_punto("qry_entradas->ApplyUpdates():", 4);
     if (qry_invcomprometart->UpdatesPending) qry_invcomprometart->ApplyUpdates();
     agrega_punto("qry_invcomprometart->ApplyUpdates():", 5);
     if (qry_direcs->UpdatesPending) qry_direcs->ApplyUpdates();
     agrega_punto("qry_direcs->ApplyUpdates():", 6);
     if (qry_renentranew->UpdatesPending) qry_renentranew->ApplyUpdates();
     agrega_punto("qry_renentranew->ApplyUpdates():", 7);
     dm->manvehi->Commit();
     agrega_punto("Commit():", 8);
   } catch (Exception &E)
   {
     agrega_punto("Error:" + E.Message, 998);
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
  }
  delete Frame_datosrelvta;
  delete Dlg_analipol;
  agrega_punto("Finalizado:", 999);
  desp_ptvt();

}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::agrega_punto(String sit_z, int punto_z)
{
  String mipunto_z;
  struct timeb inia_z;
  if(debug_z != "SI" && debug_z != "DEBUG_SILENCIOSO") return;
  ftime(&inia_z);
  if(punto_z == 0) {
    mistiempos_z->Clear();
    mipunto_z = sit_z + " Punto:" + FormatFloat("00", punto_z) + " En:" + IntToStr(inia_z.time) + ":" + IntToStr(inia_z.millitm)  + " " + FormatDateTime("dd/mm/yyyy hh:nn:ss", Now());
    mistiempos_z->Add(mipunto_z);
  } else  if(punto_z == 998) {
    mipunto_z = sit_z + " Punto:" + FormatFloat("00", punto_z) + " En:" + IntToStr(inia_z.time) + ":" + IntToStr(inia_z.millitm) + " " + FormatDateTime("dd/mm/yyyy hh:nn:ss", Now());
    mistiempos_z->Add(mipunto_z);
    if(debug_z == "DEBUG_SILENCIOSO") {
      String nombrearch_z = "cap_relvta_error_"+FormatDateTime("yyyymmdd_hh_nn_ss", Now()) + ".txt";
      mistiempos_z->SaveToFile(nombrearch_z);
    }
  } else  if(punto_z == 999) {
    mipunto_z = sit_z + " Punto:" + FormatFloat("00", punto_z) + " En:" + IntToStr(inia_z.time) + ":" + IntToStr(inia_z.millitm) + " " + FormatDateTime("dd/mm/yyyy hh:nn:ss", Now());
    mistiempos_z->Add(mipunto_z);
    if(debug_z == "DEBUG_SILENCIOSO") {
      mistiempos_z->SaveToFile("caprelvtas_debug.txt");
    } else {
      Tdlg_okcancel *Dlg_analipol;
      Dlg_analipol = new Tdlg_okcancel (this);
      Dlg_analipol->AutoSize = false;
      TMemo *mmo_result = new TMemo (Dlg_analipol);
      mmo_result->Parent = Dlg_analipol->Panel1;
      Dlg_analipol->Caption = "Tiempo de aplicación de Datos";
      mmo_result->Align = alClient;
      mmo_result->Lines = mistiempos_z;
      mmo_result->ScrollBars = ssVertical;
      Dlg_analipol->ShowModal();
      delete mmo_result;
      delete Dlg_analipol;
    }
  } else {
    mipunto_z = sit_z + " Punto:" + FormatFloat("00", punto_z) + " En:" + IntToStr(inia_z.time) + ":" + IntToStr(inia_z.millitm);
    mistiempos_z->Add(mipunto_z);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("numero")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::busca_ptvt(String ptvt_z)
{
   mi_entrada_z = SIN_ENTRADA;
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_entradas->Close();
   qry_entradas->ParamByName("numero")->AsInteger = StrToIntDef(ptvt_z, 0);
   qry_entradas->ParamByName("cia")->AsInteger = cia_z;
   qry_entradas->Open();
   if(!qry_entradas->IsEmpty()) {
     mi_entrada_z = CON_ENTRADA;
     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::FormCreate(TObject *Sender)
{
  TIniFile *ini;
  String  ubica_z, config_z;
  permis_z=dm->busca_permision(CAPRELVTA);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z );
  ubica_z =  ini->ReadString( "Relaciones_Ventas", "Ubica", "ME" );
  debug_z =  ini->ReadString( "Relaciones_Ventas", "DEBUG", "NO" );
  delete ini;


  tipoent_z = "V"; entrapor_z = -1;
  asigna_tipo(entrapor_z);
  qry_almacen->Close();
  qry_almacen->ParamByName("cia")->AsInteger = cia_z;
  qry_almacen->Open();
  qry_ubica->Close();
  qry_ubica->ParamByName("cia")->AsInteger = cia_z;
  qry_ubica->Open();
  lkcmb_ubica->KeyValue = ubica_z;
  date_fecha->Date = dm->ahora();
  idusuario_z = dm->idusuario_z;
  grabar->Tag = EN_ESPERA;
  Frame_datosrelvta1->inicializa("");
  Frame_datosrelvta1->btn_nvoren->Visible = false;
  Frame_datosrelvta1->qry_renentra->Tag = READ_ONLY;
  Frame_datosrelvta1->qry_exist->Tag = NO_REFRESH;
  Frame_datosrelvta1->qry_comprometidos->Tag = NO_REFRESH;
  Frame_datosrelvta1->btn_buscarfolio->Visible = false;
  busca_polrelvta();
  Frame_datosrelvta1->qry_exist->Tag = SI_REFRESH;
  if(debug_z == "SI" || debug_z == "DEBUG_SILENCIOSO") {
    mistiempos_z = new TStringList();
    TLabel *lbl_debug = new TLabel (Frame_datosrelvta1);
    lbl_debug->Parent = Frame_datosrelvta1->lbl_folio->Parent;
    lbl_debug->Top = Frame_datosrelvta1->lbl_folio->Top;
    lbl_debug->Left = Frame_datosrelvta1->edt_nument->Left + Frame_datosrelvta1->edt_nument->Width + 10;
    lbl_debug->Caption = "DEBUG:" + debug_z;
    lbl_debug->Color = clRed;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::asigna_tipo(int tipo_z)
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
        tipoent_z = "V"; idpermis_z = CANXCAMFO;
        titulo_z = "Venta";
        genero_z = "F";
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


void __fastcall TForm_caprelvta::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  TIniFile *ini;
  String  ubica_z, config_z;
  TDateTime fecha_z;
  ubica_z = qry_ubica->FieldByName("clave")->AsString;
  fecha_z = date_fecha->Date;
  config_z = dm->busca_inifile();
  ini = new TIniFile(config_z );
  ini->WriteString( "Relaciones_Ventas", "Ubica", ubica_z );
  ini->WriteString( "Relaciones_Ventas", "DEBUG", debug_z );
  delete ini;
  if(debug_z == "SI") delete mistiempos_z;
  Action=caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::edicion_factible(int modo_z)
{
}
//---------------------------------------------------------------------------



bool __fastcall TForm_caprelvta::afecta_kdx()
{
}
//---------------------------------------------------------------------------



void __fastcall TForm_caprelvta::exportdbgridExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = "*.xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    switch( SaveDialog->FilterIndex) {
      case 1: Frame_datosrelvta1->dbgrd_rengnes->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
      case 2: Frame_datosrelvta1->dbgrd_rengnes->SaveToXLS(SaveDialog->FileName, true); break;
      case 3: Frame_datosrelvta1->dbgrd_rengnes->SaveToHTML(SaveDialog->FileName, true); break;
    }
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm_caprelvta::impritextExecute(TObject *Sender)
{
  double total_z=0, subtubi_z=0, subtzona_z=0, subtptovta_z=0, subtremate_z=0;
  int LINEAS_X_PAG = 60, opcion_z;
  if (dm->tipoimp_z == IMPRESORA_GRAFICA ) LINEAS_X_PAG = 90;
  String arch_z = "caprelvta.txt", serie_z="", antubi_z="", antpvta_z="",
    antzona_z="", ticte_z="", antremate_z, titremate_z, antnomubi_z;
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresión de " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_impripol->Close();
  qry_impripol->ParamByName("IDPOLRELVTA")->AsInteger = qry_polrelvta->FieldByName("IDPOLRELVTA")->AsInteger;
  qry_impripol->Open();
  pagina_z = 1;
  antubi_z  = "-1";
  antpvta_z = "-1";
  antremate_z = "-1";
  //--- Aqui Va
  for(qry_impripol->First(); !qry_impripol->Eof; qry_impripol->Next()) {
    remate_z = qry_impripol->FieldByName("remate")->AsString;
    ubica_z  = qry_impripol->FieldByName("ubica")->AsString;
    zona_z   = qry_impripol->FieldByName("zona")->AsString;
    pvta_z   = qry_impripol->FieldByName("ptovta")->AsString;
    nomubi_z = qry_impripol->FieldByName("descriubi")->AsString;
    if (antremate_z != remate_z) {
      if(antremate_z != "-1") {
        reporte_subtot(subtptovta_z, "Total de " + busca_dato("PUNTO_VENTA", antpvta_z), antremate_z);
        reporte_subtot(subtzona_z, "Total de " +    busca_dato("ZONA", antzona_z), antremate_z);
        reporte_subtot(subtubi_z, "Total Ventas " + antnomubi_z, antremate_z);
        if(antremate_z == "N") titremate_z = "Gran total Ventas";
        if(antremate_z == "R") titremate_z = "Total Ventas Remate";
        reporte_subtot(subtremate_z, titremate_z, antremate_z);
        subtubi_z    = 0;
        subtptovta_z = 0;
        subtzona_z   = 0;
        subtremate_z = 0;
        antremate_z = remate_z;
        antubi_z  = ubica_z;
        antpvta_z = pvta_z;
        antzona_z = zona_z;
        antnomubi_z = nomubi_z;
        if(lineas_z > LINEAS_X_PAG - 6) {
          fprintf(archout, "%c", 12); pagina_z++; report_encab();
        } else {
          report_subencabremate();
        }
      } else {
        antremate_z = remate_z;
        antubi_z  = ubica_z;
        antpvta_z = pvta_z;
        antzona_z = zona_z;
        antnomubi_z = nomubi_z;
        report_encab();
      }
    }
    if(antubi_z != ubica_z) {
      reporte_subtot(subtptovta_z, "Total de " + busca_dato("PUNTO_VENTA", antpvta_z), antremate_z);
      reporte_subtot(subtzona_z, "Total de " +    busca_dato("ZONA", antzona_z), antremate_z);
      reporte_subtot(subtubi_z, "Total Ventas " + antnomubi_z, antremate_z);
      subtubi_z    = 0;
      subtptovta_z = 0;
      subtzona_z   = 0;
      if(lineas_z > LINEAS_X_PAG - 6) {
        fprintf(archout, "%c", 12); pagina_z++; report_encab();
      } else {
        report_subencabubi();
      }
      antubi_z  = ubica_z;
      antpvta_z = pvta_z;
      antzona_z = zona_z;
      antnomubi_z = nomubi_z;
    }
    if (antzona_z != zona_z) {
      reporte_subtot(subtptovta_z, "Total de " + busca_dato("PUNTO_VENTA", antpvta_z), antremate_z);
      reporte_subtot(subtzona_z, "Total de " +    busca_dato("ZONA", antzona_z), antremate_z);
      subtptovta_z = 0;
      subtzona_z   = 0;
      antpvta_z = pvta_z;
      antzona_z = zona_z;
      if(lineas_z > LINEAS_X_PAG - 6) {
        fprintf(archout, "%c", 12); pagina_z++; report_encab();
      } else {
        report_subencabzon();
      }
    }
    if (antpvta_z != pvta_z) {
      reporte_subtot(subtptovta_z, "Total de " + busca_dato("PUNTO_VENTA", antpvta_z), antremate_z);
      subtptovta_z = 0;
      antpvta_z = pvta_z;
      if(lineas_z > LINEAS_X_PAG - 6) {
        fprintf(archout, "%c", 12); pagina_z++; report_encab();
      } else {
        report_subencabpvta();
      }
    }
    if(lineas_z > LINEAS_X_PAG) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab();
    }
    fprintf(archout, "%s|", ljust(FormatDateTime("hh:nn", tiemporel(qry_impripol->FieldByName("hora")->AsInteger)), 5));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("nombre")->AsString, 20));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("poblac")->AsString, 20));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("codigo")->AsString, 13));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("descri")->AsString, 30));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("tipocte")->AsString, 2));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("vendedor")->AsString, 4));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("salede")->AsString, 4));
    fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", qry_impripol->FieldByName("preciolista")->AsFloat), 12));
    fprintf(archout, "%s|", ljust(qry_impripol->FieldByName("descritipopago")->AsString, 10));
    fprintf(archout, "\n");
    subtubi_z    += qry_impripol->FieldByName("preciolista")->AsFloat;
    total_z      += qry_impripol->FieldByName("preciolista")->AsFloat;
    subtptovta_z += qry_impripol->FieldByName("preciolista")->AsFloat;
    subtzona_z   += qry_impripol->FieldByName("preciolista")->AsFloat;
    subtremate_z += qry_impripol->FieldByName("preciolista")->AsFloat;
    lineas_z++;
  }
  reporte_subtot(subtptovta_z, "Total de " + busca_dato("PUNTO_VENTA", pvta_z), antremate_z);
  reporte_subtot(subtzona_z, "Total de " +    busca_dato("ZONA", zona_z), antremate_z);
  reporte_subtot(subtubi_z, "Total Ventas " + nomubi_z, antremate_z);
  if(remate_z == "N") titremate_z = "Gran total de Ventas";
  if(remate_z == "R") titremate_z = "Gran total Ventas Remate";
  reporte_subtot(subtremate_z, titremate_z, remate_z);
  fprintf(archout, "%s %s\n\n",
    rjust("Total Ventas General:", 105),
    rjust(FormatFloat("###,##0.00", total_z), 12)
  );
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::report_encab()
{
  titulo_z = "Relacion de Ventas";
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de %s\n", titulo_z);
  fprintf(archout, "Almacen:%s %s Fecha:%s\n",
    qry_ubica->FieldByName("clave")->AsString,
    qry_ubica->FieldByName("nombre")->AsString,
    FormatDateTime("dd-mm-yyyy", date_fecha->Date),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  fprintf(archout, "%s%s",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON)
  );
  fprintf(archout, "%s|", cjust("Hora", 5));
  fprintf(archout, "%s|", ljust("Cliente", 20));
  fprintf(archout, "%s|", ljust("Poblacion", 20));
  fprintf(archout, "%s|", ljust("Articulo", 44));
  fprintf(archout, "%s|", ljust("TC", 2));
  fprintf(archout, "%s|", ljust("Vend", 4));
  fprintf(archout, "%s|", ljust("Sale", 4));
  fprintf(archout, "%s|", rjust("P.Venta", 12));
  fprintf(archout, "%s|", "Forma Pago");
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z = 5;
  report_subencabremate();
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::report_subencabremate()
{
  String titremate_z;
  if(remate_z == "N") titremate_z = "Ventas";
  if(remate_z == "R") titremate_z = "Ventas de Remate";
  fprintf(archout, "%s\n", titremate_z);
  lineas_z++;
  report_subencabubi();
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::report_subencabubi()
{
  fprintf(archout, "Ubicacion: %s %s\n", ubica_z, nomubi_z );
  lineas_z++;
  report_subencabzon();
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::report_subencabzon()
{
   String nombre_z="";
   nombre_z = busca_dato("ZONA", zona_z);
   fprintf(archout, "Zona: %s %s\n", zona_z, nombre_z);
   lineas_z++;
   report_subencabpvta();
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::report_subencabpvta()
{
   String nombre_z="";
   nombre_z = busca_dato("PUNTO_VENTA", pvta_z);
   fprintf(archout, "Punto de Venta: %s %s\n", pvta_z, nombre_z);
   lineas_z++;
}
//---------------------------------------------------------------------------

String __fastcall TForm_caprelvta::busca_dato(String tipodato_z, String clave_z)
{
   String nombre_z="", sql_z;
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   if (tipodato_z == "PUNTO_VENTA") {
     sql_z = "select nombre from ptovta where clave = :CLAVE";
   } else if (tipodato_z == "ZONA") {
     sql_z = "select nombre from zonainv where zona = :CLAVE";
   }
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->ParamByName("CLAVE")->AsString = clave_z;
   dm->qry_maxidvnd->Open();
   if(!dm->qry_maxidvnd->IsEmpty())
     nombre_z = dm->qry_maxidvnd->FieldByName("nombre")->AsString;
   return (nombre_z);
}
//---------------------------------------------------------------------------



void __fastcall TForm_caprelvta::reporte_subtot(double importe_z, String tit_z, String tipo_z)
{
  double PIVA_Z = 16, antesiva_z;
  if(tipo_z == "N") {
    antesiva_z = importe_z / ( PIVA_Z / 100 + 1 );
    fprintf(archout, "%s %s\n",
      rjust(tit_z + " Antes de Iva", 105),
      rjust(FormatFloat("###,##0.00", antesiva_z), 12)
    );
    lineas_z++;
  }
  fprintf(archout, "%s %s\n",
    rjust(tit_z, 105),
    rjust(FormatFloat("###,##0.00", importe_z), 12)
  );
  lineas_z++;
}
//---------------------------------------------------------------------------



void __fastcall TForm_caprelvta::despliega_renentra()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_caprelvta::busca_cod(String codigo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::despliega_comprometidos()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_caprelvta::nueva_polExecute(TObject *Sender)
{
   int ancho_z, alto_z, numero_z=0, idpolrelvta_z=0;
   TDateTime fecha_z;
   String alm_z, strfecha_z, strfechoy_z, strfecatras_z, ubicacion_z;
   bool todook_z = true;
   Tdlg_okcancel *Dlg_analipol;
   Dlg_analipol = new Tdlg_okcancel (this);
   Dlg_analipol->AutoSize = false;
   TFrame_datoscaptrasp *Frame_datoscaptrasp;
   Frame_datoscaptrasp = new TFrame_datoscaptrasp (Dlg_analipol);
   ancho_z = Frame_datoscaptrasp->Width + 20;
   alto_z = Frame_datoscaptrasp->Height + Dlg_analipol->Panel2->Height + 80;
   Frame_datoscaptrasp->Parent = Dlg_analipol->Panel1;
   Dlg_analipol->Width = ancho_z;
   Dlg_analipol->Height = alto_z;
   Dlg_analipol->Caption = "Captura de Datos";
   Frame_datoscaptrasp->Align = alClient;
   Frame_datoscaptrasp->inicializa("");
   Frame_datoscaptrasp->accion_z = NUEVO;
   alm_z    = qry_ubica->FieldByName("clave")->AsString;
   Frame_datoscaptrasp->lkcmb_almacen->KeyValue = alm_z;
   Frame_datoscaptrasp->lbl_numero->Visible = false;
   Frame_datoscaptrasp->edt_numero->Visible = false;
   Frame_datoscaptrasp->dbedt_importe->Visible = false;
   Frame_datoscaptrasp->lbl_importe->Visible = false;
   Frame_datoscaptrasp->dbedt_iva->Visible = false;
   Frame_datoscaptrasp->lbl_iva->Visible = false;
   Frame_datoscaptrasp->dbedt_total->Visible = false;
   Frame_datoscaptrasp->lbl_total->Visible = false;
   Dlg_analipol->Position = poScreenCenter;

   if( Dlg_analipol->ShowModal() == mrOk) {
     alm_z    = Frame_datoscaptrasp->qry_Almacen->FieldByName("clave")->AsString;
     fecha_z  = Frame_datoscaptrasp->date_fecha->Date;
     numero_z = Frame_datoscaptrasp->edt_numero->Value;
     strfechoy_z = FormatDateTime("yyyymmdd", dm->ahora());
     strfecatras_z = FormatDateTime("yyyymmdd", dm->ahora() - 20);
     strfecha_z = FormatDateTime("yyyymmdd", fecha_z);
     if( strfecha_z > strfechoy_z) {
       Application->MessageBox("Lo siento, no puede agregar fechas futuras", "Fecha Incorrecta", MB_ICONEXCLAMATION);
       todook_z = false;
     }
     if( strfecha_z < strfecatras_z ) {
       Application->MessageBox("Lo siento, no puede agregar fechas de mas de 20 días de diferencia", "Fecha Incorrecta", MB_ICONEXCLAMATION);
       todook_z = false;
     }
     if(todook_z) {
        qry_polrelvta->Close();
        qry_polrelvta->ParamByName("fecha")->AsDateTime = fecha_z;
        qry_polrelvta->ParamByName("ubica")->AsString = alm_z;
        qry_polrelvta->ParamByName("cia")->AsInteger = cia_z;
        qry_polrelvta->Open();
        if (qry_polrelvta->IsEmpty()) {
          idpolrelvta_z=dm->busca_sigid(IDPOLRELVTA);
          qry_polrelvta->Append();
          qry_polrelvta->FieldByName("idpolrelvta")->AsInteger = idpolrelvta_z;
          qry_polrelvta->FieldByName("ubicacion")->AsString = alm_z;
          qry_polrelvta->FieldByName("fecha")->AsDateTime = fecha_z;
          qry_polrelvta->FieldByName("cia")->AsInteger = cia_z;
          qry_polrelvta->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
          qry_polrelvta->FieldByName("creacion")->AsDateTime = dm->ahora();
          qry_polrelvta->Post();
          date_fecha->Date = fecha_z;
          lkcmb_ubica->KeyValue = alm_z;

          try {
            dm->manvehi->StartTransaction();
            qry_polrelvta->ApplyUpdates();
            dm->manvehi->Commit();
          } catch (Exception &E) {
            dm->manvehi->Rollback();
            Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
          }
        }
        busca_polrelvta();
     }
   }
   delete Frame_datoscaptrasp;
   delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::alta_pol()
{
  String ubicacion_z;
  int idpolrelvta_z=0;
  TDateTime fecha_z;
  idpolrelvta_z=dm->busca_sigid(IDPOLRELVTA);
  ubicacion_z = qry_ubica->FieldByName("clave")->AsString;
  fecha_z = date_fecha->Date;
  qry_polrelvta->Close();
  qry_polrelvta->ParamByName("fecha")->AsDateTime = date_fecha->Date;
  qry_polrelvta->ParamByName("ubica")->AsString = ubicacion_z;
  qry_polrelvta->ParamByName("cia")->AsInteger = cia_z;
  qry_polrelvta->Open();
  if (qry_polrelvta->IsEmpty()) {
    qry_polrelvta->Append();
    qry_polrelvta->FieldByName("idpolrelvta")->AsInteger = idpolrelvta_z;
    qry_polrelvta->FieldByName("ubicacion")->AsString = ubicacion_z;
    qry_polrelvta->FieldByName("fecha")->AsDateTime = fecha_z;
    qry_polrelvta->FieldByName("cia")->AsInteger = cia_z;
    qry_polrelvta->FieldByName("idusuario")->AsInteger = 0;
    qry_polrelvta->FieldByName("creacion")->AsDateTime = dm->ahora();
    qry_polrelvta->Post();
    try {
      dm->manvehi->StartTransaction();
      qry_polrelvta->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
  desp_polrelvta();
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::desp_polrelvta()
{
  int idpolrelvta_z;
  idpolrelvta_z = qry_polrelvta->FieldByName("IDPOLRELVTA")->AsInteger;
  qry_entradas->Close();
  qry_entradas->ParamByName("IDPOLRELVTA")->AsInteger = idpolrelvta_z;
  qry_entradas->ParamByName("cia")->AsInteger = cia_z;
  qry_entradas->Open();
  date_fecha->Date = qry_polrelvta->FieldByName("FECHA")->AsDateTime;
  lkcmb_ubica->KeyValue = qry_polrelvta->FieldByName("UBICACION")->AsString;
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::busca_polrelvta()
{
  String ubicacion_z;
  TDateTime fecha_z;
  ubicacion_z = qry_ubica->FieldByName("clave")->AsString;
  fecha_z = date_fecha->Date;
  qry_entradas->Tag = NO_REFRESH;
  Frame_datosrelvta1->qry_renentra->Tag = NO_REFRESH;
  qry_polrelvta->Close();
  qry_polrelvta->ParamByName("fecha")->AsDateTime = date_fecha->Date;
  qry_polrelvta->ParamByName("ubica")->AsString = ubicacion_z;
  qry_polrelvta->ParamByName("cia")->AsInteger = cia_z;
  qry_polrelvta->Open();
  if (!qry_polrelvta->IsEmpty()) desp_polrelvta();
  qry_entradas->Tag = SI_REFRESH;
  Frame_datosrelvta1->qry_renentra->Tag = SI_REFRESH;
  if (!qry_polrelvta->IsEmpty()) desp_ptvt();
}
//---------------------------------------------------------------------------


void __fastcall TForm_caprelvta::qry_entradasAfterScroll(TDataSet *DataSet)
{
  if(grabar->Tag == EN_ESPERA && qry_entradas->Tag == SI_REFRESH) desp_ptvt();
}
//---------------------------------------------------------------------------





void __fastcall TForm_caprelvta::lkcmb_ubicaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN && grabar->Tag == EN_ESPERA) busca_polrelvta();
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::date_fechaKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN && grabar->Tag == EN_ESPERA) busca_polrelvta();
}
//---------------------------------------------------------------------------










void __fastcall TForm_caprelvta::date_fechaExit(TObject *Sender)
{
  busca_polrelvta();
}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::lkcmb_ubicaExit(TObject *Sender)
{
  busca_polrelvta();
}
//---------------------------------------------------------------------------



void __fastcall TForm_caprelvta::Frame_datosrelvta1edt_numentKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) busca_ptvt(Frame_datosrelvta1->edt_nument->Text);

}
//---------------------------------------------------------------------------

void __fastcall TForm_caprelvta::Frame_datosrelvta1btn_nvorenClick(
      TObject *Sender)
{
  Frame_datosrelvta1->btn_nvorenClick(Sender);

}
//---------------------------------------------------------------------------

