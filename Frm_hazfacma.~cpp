//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_hazfacma.h"
#include "dmod.h"
#include "numapal.h"
#include "imprigra.h"
#include "Frm_selserie.h"
#include "dialg_okcancel.h"
#include "Frme_datosrenfacma.h"
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
#pragma link "Frme_datosfacma"
#pragma link "Frme_datosrenfacma"
#pragma resource "*.dfm"
#include "situaciones.h"

TForm_hazfacma *Form_hazfacma;
//---------------------------------------------------------------------------
__fastcall TForm_hazfacma::TForm_hazfacma(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::borraExecute(TObject *Sender)
{
  bool si_borrar = true;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  qry_facturma->Close();
  qry_facturma->ParamByName("tipofac")->AsInteger = entrapor_z;
  qry_facturma->ParamByName("numero")->AsInteger = Frame_datosfacma1->edt_numfac->Value;
  qry_facturma->ParamByName("cia")->AsInteger = cia_z;
  qry_facturma->Open();
  if(qry_facturma->IsEmpty()) return;
  if(qry_facturma->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede eliminar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Eliminar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  mensaje_z = "Seguro de eliminar " + este_z + " " + titulo_z + " ?";
  titmsg_z = "Eliminar " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(),  MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    for(qry_renfacma->First(); !qry_renfacma->Eof; qry_renfacma->Next()) {
      if(qry_renfacma->FieldByName("status")->AsString == "C") {
        si_borrar = false;
      } else {
        costo_z = qry_renfacma->FieldByName("costou")->AsFloat;
        piva_z = qry_renfacma->FieldByName("piva")->AsFloat;
        qry_facturma->Edit();
        qry_facturma->FieldByName("importe")->AsFloat       -= Redondea(costo_z, 10000);
        qry_facturma->FieldByName("iva")->AsFloat           -= Redondea(costo_z * piva_z / 100, 10000);
        qry_facturma->FieldByName("total")->AsFloat         -= Redondea(costo_z * ((piva_z / 100) + 1), 10000);
        qry_facturma->Post();
        qry_renfacma->Delete();
      }
    }
    if(si_borrar) {
      //for(qry_venfacma->First(); !qry_venfacma->Eof; qry_venfacma->Next()) {
      //  qry_venfacma->Delete();
      //}
      qry_borraseries->Close();
      qry_borraseries->ParamByName("idfacturma")->AsInteger = qry_facturma->FieldByName("idfactur")->AsInteger;
      qry_borraseries->ExecSQL();
      qry_facturma->Delete();
    } else {
      mensaje_z = "No pude eliminar " + este_z + " " + titulo_z + " por que hay renglones cerrados, \nlos renglones no cerrados han sido eliminados";
      titmsg_z = "Eliminar " + titulo_z;
      Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    }
    try {
      dm->manvehi->StartTransaction();
      qry_facturma->ApplyUpdates();
      qry_renfacma->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    if(si_borrar) mueve_hacia("ULTIMO");
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_hazfacma::modificaExecute(TObject *Sender)
{
  int sigfac_z=0;
  if(qry_facturma->IsEmpty()) {
    mensaje_z = "No existe " + titulo_z + "que desea modificar";
    titmsg_z = titulo_z + "Inexistente ";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    return;
  }
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  desp_ptvt();
  alta_ptvt("MODIF");
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::desp_ptvt()
{
     String ciu_z="", mayoris_z, mediospag_z = "",
       direc_z="", numcta1_z = "", numcta2_z = "";
     int medio1_z = 0, medio2_z = 0, idfacturma_z = 0;
     idfacturma_z = qry_facturma->FieldByName("idfactur")->AsInteger;

     mayoris_z = qry_facturma->FieldByName("mayoris")->AsString;
     Frame_datosfacma1->edt_numfac->Value = qry_facturma->FieldByName("num")->AsInteger;
     Frame_datosfacma1->date_fecha->Date = qry_facturma->FieldByName("fecha")->AsDateTime;
     Frame_datosfacma1->edt_npagos->Value = qry_facturma->FieldByName("npagos")->AsInteger;
     Frame_datosfacma1->edt_pzoxlet->Value = qry_facturma->FieldByName("plazo")->AsInteger;
     Frame_datosfacma1->edt_nombrefac->Text = qry_facturma->FieldByName("nomay")->AsString;
     Frame_datosfacma1->edt_mayoris->Text   = mayoris_z;
     Frame_datosfacma1->busca_mayoris(mayoris_z);
     Frame_datosfacma1->edt_refer->Text = qry_facturma->FieldByName("refer")->AsString;
     //Frame_datosfacma1->cmb_venctos->Items->Clear();
     //Frame_datosfacma1->cmb_venctos->Items->Add(FormatDateTime("dd/mm/yyyy", qry_facturma->FieldByName("vence")->AsDateTime));
     //Frame_datosfacma1->cmb_venctos->ItemIndex = 0;
     Frame_datosfacma1->edt_rfc->Text = qry_facturma->FieldByName("rfc")->AsString;
     Frame_datosfacma1->selecciona_tipo_fac("MAYOMEN", qry_facturma->FieldByName("mayomen")->AsString);
     Frame_datosfacma1->selecciona_tipo_fac("INTOMERC", qry_facturma->FieldByName("tipago")->AsString);
     qry_renfacma->Close();
     qry_renfacma->ParamByName("idfacturma")->AsInteger = idfacturma_z;
     qry_renfacma->Open();
     qry_datospago->Close();
     qry_datospago->ParamByName("idfac")->AsInteger = idfacturma_z;
     qry_datospago->ParamByName("cia")->AsInteger = cia_z;
     qry_datospago->Open();
     mediospag_z = obten_datospago ( IntToStr(idfacturma_z), "TIPOPAGO");
     medio1_z = mediospag_z.SubString(1,6).ToIntDef(0);
     medio2_z = mediospag_z.SubString(8,6).ToIntDef(0);
     Frame_datosfacma1->lkcmb_metodopago->KeyValue  = medio1_z;
     Frame_datosfacma1->lkcmb_metodopago2->KeyValue = medio2_z;
     mediospag_z = obten_datospago ( IntToStr(idfacturma_z), "NUMCTA");
     numcta1_z = mediospag_z.SubString(1,4);
     numcta2_z = mediospag_z.SubString(5,4);
     Frame_datosfacma1->edt_numcta1->Text = numcta1_z;
     Frame_datosfacma1->edt_numcta2->Text = numcta2_z;
     Frame_datosfacma1->calles_z  = obten_datospago ( IntToStr(idfacturma_z), "CALLE");
     Frame_datosfacma1->numpred_z = obten_datospago ( IntToStr(idfacturma_z), "NUMPRED");
     Frame_datosfacma1->codpost_z = obten_datospago ( IntToStr(idfacturma_z), "CODPOST");
     Frame_datosfacma1->colonia_z = obten_datospago ( IntToStr(idfacturma_z), "COLONIA");
     direc_z   = Frame_datosfacma1->calles_z;
     direc_z  += " N." + Frame_datosfacma1->numpred_z;
     direc_z  += " Col:" + Frame_datosfacma1->colonia_z;
     direc_z  += " CP:" + Frame_datosfacma1->codpost_z;

     Frame_datosfacma1->mmo_direc->Text = direc_z;
     if(!Frame_datosfacma1->qry_mayoris->IsEmpty())
       ciu_z = Frame_datosfacma1->qry_mayoris->FieldByName("ciu")->AsString;
       Frame_datosfacma1->mmo_direc->Lines->Add(ciu_z);

     if( qry_facturma->FieldByName("status")->AsString == "C") {
       impritext->Enabled = true;
       cierra_entrada->Enabled = false;
     } else {
       impritext->Enabled = false;
       cierra_entrada->Enabled = true;
     }
}
//---------------------------------------------------------------------------

String __fastcall TForm_hazfacma::obten_datospago(
  String codigomay_z, String tipodato_z)
{
   String midato_z="", campo_z;
   int tiporel_z;
   TLocateOptions Opts;
   Opts.Clear();
   if(tipodato_z == "TIPOPAGO" || tipodato_z == "NUMCTA") {
     tiporel_z = REL_FACMAY_TIPOPAGO;
   }
   if(tipodato_z == "TIPOPAGO2" || tipodato_z == "NUMCTA2") {
     tiporel_z = REL_FACMAY_TIPOPAGO;
   }
   if(tipodato_z == "CALLE") {
     tiporel_z = REL_MAYORIS_CALLE;
   }
   if(tipodato_z == "NUMPRED") {
     tiporel_z = REL_MAYORIS_NUMPRED;
   }
   if(tipodato_z == "CODPOST") {
     tiporel_z = REL_MAYORIS_CODPOST;
   }
   if(tipodato_z == "COLONIA") {
     tiporel_z = REL_MAYORIS_COLONIA;
   }
   if(tipodato_z == "EMAIL") {
     tiporel_z = REL_MAYORIS_EMAIL;
   }
   if(tipodato_z == "EMAIL2") {
     tiporel_z = REL_MAYORIS_EMAIL2;
   }
   qry_datospago->First();

   if(qry_datospago->Locate("idtiporel", tiporel_z, Opts)) {
     if(tipodato_z == "NUMCTA") {
       campo_z = "numcta";
     } else {
       campo_z = "tipopago";
     // Fin de if
     }
     midato_z = qry_datospago->FieldByName(campo_z)->AsString;
   }
   return (midato_z);
}
//---------------------------------------------------------------------------

String __fastcall TForm_hazfacma::obten_datosmayoris(
  String codigomay_z, String tipodato_z)
{
   String midato_z="", campo_z;
   int tiporel_z;
   TLocateOptions Opts;
   Opts.Clear();
   if(tipodato_z == "TIPOPAGO" || tipodato_z == "NUMCTA") {
     tiporel_z = REL_MAYORIS_TIPOPAGO;
   }
   if(tipodato_z == "TIPOPAGO2" || tipodato_z == "NUMCTA2") {
     tiporel_z = REL_MAYORIS_TIPOPAGO2;
   }
   if(tipodato_z == "CALLE") {
     tiporel_z = REL_MAYORIS_CALLE;
   }
   if(tipodato_z == "NUMPRED") {
     tiporel_z = REL_MAYORIS_NUMPRED;
   }
   if(tipodato_z == "CODPOST") {
     tiporel_z = REL_MAYORIS_CODPOST;
   }
   if(tipodato_z == "COLONIA") {
     tiporel_z = REL_MAYORIS_COLONIA;
   }
   if(tipodato_z == "EMAIL") {
     tiporel_z = REL_MAYORIS_EMAIL;
   }
   if(tipodato_z == "EMAIL2") {
     tiporel_z = REL_MAYORIS_EMAIL2;
   }
   qry_datosmayoris->First();

   if(qry_datosmayoris->Locate("idtiporel", tiporel_z, Opts)) {
     if(tipodato_z == "NUMCTA") {
       campo_z = "numcta";
     } else {
       campo_z = "tipopago";
     // Fin de if
     }
     midato_z = qry_datosmayoris->FieldByName(campo_z)->AsString;
   }
   return (midato_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::nuevoExecute(TObject *Sender)
{
  int sigfac_z=0;
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt("ALTA");
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::primeroExecute(TObject *Sender)
{
   mueve_hacia("PRIMERO");
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::anteriorExecute(TObject *Sender)
{
   mueve_hacia("ANTERIOR");
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::siguienteExecute(TObject *Sender)
{
   mueve_hacia("SIGUIENTE");
}
//---------------------------------------------------------------------------
void __fastcall TForm_hazfacma::ultimoExecute(TObject *Sender)
{
   mueve_hacia("ULTIMO");
}
//-------------------------------------------------------------------------

void __fastcall TForm_hazfacma::alta_ptvt(String modo_z)
{
   int numfac_z=0, idfacturma_z = 0, idmayoris_z = 0, idnombre_z = 0, iddirec_z =0,
     idciu_z=0, idvenfacma_z=0, dia_z =0, mes_z = 0, anu_z=0, ii_z=0,
     idmediopago_z, idmediopag1_z, idmediopag2_z, idnumcta_z,
     alto_z, ancho_z, nvoidrel_z;
   TDateTime vence_z, fecha_z;
   String serie_z = "MYFA", mayomen_z = "M", tipago_z = "M",
     mediopago_z, numcta_z, calles_z, numpred_z, colonia_z, codpost_z;
   serie_z = Frame_datosfacma1->edt_seriefac->Text.Trim();
   if(modo_z == "ALTA") {
      dm->qry_maxidvnd->Close();
      dm->qry_maxidvnd->SQL->Clear();
      dm->qry_maxidvnd->SQL->Add("select max (num) as num from facturma where tipofac = :TIPOFAC and seriefac = :SERIE and cia = :CIA");
      dm->qry_maxidvnd->ParamByName("serie")->AsString    = serie_z;
      dm->qry_maxidvnd->ParamByName("tipofac")->AsInteger = entrapor_z;
      dm->qry_maxidvnd->ParamByName("cia")->AsInteger     = cia_z;
      dm->qry_maxidvnd->Open();
      if(!dm->qry_maxidvnd->IsEmpty()) numfac_z =dm->qry_maxidvnd->FieldByName("num")->AsInteger ;
      numfac_z++;
      fecha_z = dm->ahora();
   } else if(modo_z == "MODIF") {
     serie_z  = qry_facturma->FieldByName("seriefac")->AsString;
     numfac_z = qry_facturma->FieldByName("num")->AsInteger;
     fecha_z  = qry_facturma->FieldByName("fecha")->AsDateTime;
   }

   Tdlg_okcancel *Dlg_pidenombre;
   Dlg_pidenombre = new Tdlg_okcancel (this);
   Dlg_pidenombre->AutoSize = false;

   TFrame_datosfacma *Frame_datosfacma = new TFrame_datosfacma (Dlg_pidenombre);
   ancho_z = Frame_datosfacma->Width + 20;
   alto_z = Frame_datosfacma->Height + Dlg_pidenombre->Panel2->Height + 80;
   Dlg_pidenombre->Width = ancho_z;
   Dlg_pidenombre->Height = alto_z;
   Frame_datosfacma->Parent = Dlg_pidenombre->Panel1;
   Frame_datosfacma->Top = 0;
   Frame_datosfacma->Left= 0;
   Frame_datosfacma->Align = alClient;
   Frame_datosfacma->edt_numfac->Value  = numfac_z;
   Frame_datosfacma->date_fecha->Date   = fecha_z;
   Frame_datosfacma->edt_seriefac->Text = serie_z;
   Frame_datosfacma->modo_z = modo_z;
   Frame_datosfacma->entrapor_z = entrapor_z;
   Dlg_pidenombre->Caption = "Proporcione Los datos de Factura";
   if(modo_z == "MODIF") {
     Frame_datosfacma->edt_numfac->Enabled = false;
     Frame_datosfacma->edt_seriefac->Enabled = false;
   }

   if( Dlg_pidenombre->ShowModal() != mrOk) {
      delete Frame_datosfacma;
      delete Dlg_pidenombre;
      return;
   }
   numfac_z = Frame_datosfacma->edt_numfac->Value;
   serie_z = Frame_datosfacma->edt_seriefac->Text.Trim();

   qry_facturma->Close();
   qry_facturma->ParamByName("tipofac")->AsInteger = entrapor_z;
   qry_facturma->ParamByName("numero")->AsInteger  = numfac_z;
   qry_facturma->ParamByName("cia")->AsInteger     = cia_z;
   qry_facturma->Open();
   if(modo_z == "ALTA" && !qry_facturma->IsEmpty()) {
     Application->MessageBox("Factura ya Existe", "Factura Exist", MB_ICONEXCLAMATION);
     delete Frame_datosfacma;
     delete Dlg_pidenombre;
     return;
   }
   if(modo_z == "ALTA") {
      idfacturma_z=dm->busca_sigid(IDFACTURMA);
      qry_facturma->Append();
      qry_facturma->FieldByName("num")->AsInteger = numfac_z;
      qry_facturma->FieldByName("cia")->AsInteger = cia_z;
      qry_facturma->FieldByName("idfactur")->AsInteger = idfacturma_z;
      qry_facturma->FieldByName("tipofac")->AsString = entrapor_z;
      qry_facturma->FieldByName("seriefac")->AsString = serie_z;
      qry_facturma->FieldByName("status")->AsString = "A";
      qry_facturma->FieldByName("importe")->AsFloat = 0;
      qry_facturma->FieldByName("descu")->AsFloat = 0;
      qry_facturma->FieldByName("neto")->AsFloat = 0;
      qry_facturma->FieldByName("total")->AsFloat = 0;
      qry_facturma->FieldByName("importe")->AsFloat = 0;
   } else {
      idfacturma_z = qry_facturma->FieldByName("idfactur")->AsInteger;
      qry_facturma->Edit();
   }
   tipago_z  = Frame_datosfacma->selecciona_tipo_fac("SELECCIONA_INTOMERC", Frame_datosfacma->cmb_intomer->Text);
   mayomen_z = Frame_datosfacma->selecciona_tipo_fac("SELECCIONA_MAYOMEN",  Frame_datosfacma->cmb_mayomen->Text);
   idmediopag1_z = Frame_datosfacma->lkcmb_metodopago->KeyValue;
   idmediopag2_z = Frame_datosfacma->lkcmb_metodopago2->KeyValue;
   mediopago_z = FormatFloat( "000000", idmediopag1_z);
   if(idmediopag2_z != idmediopag1_z) {
     mediopago_z += " " + FormatFloat("000000", idmediopag2_z);
   }
   numcta_z    = Frame_datosfacma->edt_numcta1->Text.Trim();
   numcta_z    += " " + Frame_datosfacma->edt_numcta2->Text.Trim();
   numcta_z = numcta_z.Trim();
   qry_facturma->FieldByName("mayoris")->AsString = Frame_datosfacma->edt_mayoris->Text.Trim();
   qry_facturma->FieldByName("refer")->AsString = Frame_datosfacma->edt_refer->Text.Trim();
   qry_facturma->FieldByName("nomay")->AsString = Frame_datosfacma->edt_nombrefac->Text.Trim();
   qry_facturma->FieldByName("dir")->AsString = Frame_datosfacma->mmo_direc->Text;
   qry_facturma->FieldByName("rfc")->AsString = Frame_datosfacma->edt_rfc->Text.Trim();
   qry_facturma->FieldByName("fecha")->AsDateTime = Frame_datosfacma->date_fecha->Date;
   //qry_facturma->ParamByName("vence")->AsDateTime = Frame_datosfacma->date_vence->Date;
   qry_facturma->FieldByName("npagos")->AsInteger = Frame_datosfacma->edt_npagos->Value;
   qry_facturma->FieldByName("plazo")->AsInteger = Frame_datosfacma->edt_pzoxlet->Value;
   qry_facturma->FieldByName("tipago")->AsString = tipago_z;
   qry_facturma->FieldByName("pdsc")->AsFloat = 0;
   qry_facturma->FieldByName("mayomen")->AsString = mayomen_z;
   qry_facturma->Post();
   qry_datospago->Close();
   qry_datospago->ParamByName("idfac")->AsInteger = idfacturma_z;
   qry_datospago->ParamByName("cia")->AsInteger = cia_z;
   qry_datospago->Open();
   calles_z   = Frame_datosfacma->calles_z;
   numpred_z  = Frame_datosfacma->numpred_z;
   colonia_z  = Frame_datosfacma->colonia_z;
   codpost_z  = Frame_datosfacma->codpost_z;
   //idmediopago_z = dm->busca_iddato(mediopago_z, INVCONCEPTO);
   //idnumcta_z    = dm->busca_iddato(numcta_z,    INVCONCEPTO);
   agrega_relac(IntToStr(idfacturma_z),mediopago_z, numcta_z, "FACMAY_TIPOPAGO");
   agrega_relac(IntToStr(idfacturma_z), calles_z, calles_z, "CALLE");
   agrega_relac(IntToStr(idfacturma_z), numpred_z, numpred_z, "NUMPRED");
   agrega_relac(IntToStr(idfacturma_z), colonia_z, colonia_z, "COLONIA");
   agrega_relac(IntToStr(idfacturma_z), codpost_z, codpost_z, "CODPOST");
   try {
      dm->manvehi->StartTransaction();
      qry_facturma->ApplyUpdates();
      if(qry_datospago->UpdatesPending) qry_datospago->ApplyUpdates();
      dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   busca_ptvt(numfac_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::agrega_relac(String mayoris_z, String dato1_z, String dato2_z, String tipodato_z)
{
  int idfac_z = 0, iddato1_z=0, iddato2_z, nvoidrel_z, mitiporel_z;
  nvoidrel_z = dm->busca_sigid(MAY_RELAC);
  nvoidrel_z += qry_datospago->RecordCount;
  idfac_z = mayoris_z.ToIntDef(-1);
  bool encontrado_z=false;
  iddato1_z = dm->busca_iddato(dato1_z, INVCONCEPTO);
  iddato2_z = iddato1_z;

  if(tipodato_z == "TIPOPAGO" || tipodato_z == "NUMCTA") {
    mitiporel_z = REL_MAYORIS_TIPOPAGO;
    iddato2_z = dm->busca_iddato(dato2_z, INVCONCEPTO);
  }
  if(tipodato_z == "FACMAY_TIPOPAGO" ) {
    mitiporel_z = REL_FACMAY_TIPOPAGO;
    iddato2_z = dm->busca_iddato(dato2_z, INVCONCEPTO);
  }
  if(tipodato_z == "TIPOPAGO2" || tipodato_z == "NUMCTA2") {
    mitiporel_z = REL_MAYORIS_TIPOPAGO2;
    iddato2_z = dm->busca_iddato(dato2_z, INVCONCEPTO);
  }
  if(tipodato_z == "CALLE") {
    mitiporel_z = REL_MAYORIS_CALLE;
  }
  if(tipodato_z == "NUMPRED") {
    mitiporel_z = REL_MAYORIS_NUMPRED;
  }
  if(tipodato_z == "CODPOST") {
    mitiporel_z = REL_MAYORIS_CODPOST;
  }
  if(tipodato_z == "COLONIA") {
    mitiporel_z = REL_MAYORIS_COLONIA;
  }
  if(tipodato_z == "EMAIL") {
    mitiporel_z = REL_MAYORIS_EMAIL;
  }
  if(tipodato_z == "EMAIL2") {
    mitiporel_z = REL_MAYORIS_EMAIL2;
  }
  if(tipodato_z == "REL_FACMAY_PIDEPRE") {
    mitiporel_z = REL_FACMAY_PIDEPRE;
  }

  for(qry_datospago->First(); !qry_datospago->Eof; qry_datospago->Next() ) {
    if(qry_datospago->FieldByName("idtiporel")->AsInteger == mitiporel_z) {
      encontrado_z = true; break;
    }
  }
   if(!encontrado_z) {
      qry_datospago->Append();
      qry_datospago->FieldByName("idrelac")->AsInteger = nvoidrel_z;
      qry_datospago->FieldByName("idmayoris")->AsInteger = idfac_z;
      qry_datospago->FieldByName("mayoris")->AsString = "";
      qry_datospago->FieldByName("idtiporel")->AsInteger = mitiporel_z;
      qry_datospago->FieldByName("cia")->AsInteger = cia_z;
      nvoidrel_z++;
   } else {
      qry_datospago->Edit();
   }
   qry_datospago->FieldByName("iddato1")->AsInteger = iddato1_z;
   qry_datospago->FieldByName("iddato2")->AsInteger = iddato2_z;
   qry_datospago->Post();
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::mueve_hacia(String sql_z)
{
   String sql2_z, sentencia_z, hacia_z, serie_z;
   hacia_z = sql_z;
   int numfac_z = 0;
   numfac_z = Frame_datosfacma1->edt_numfac->Value;
   serie_z = Frame_datosfacma1->edt_seriefac->Text.Trim();
   if(hacia_z == "PRIMERO") {
     sentencia_z =  "select min (num)";
     sql2_z = " and num > :NUMFAC -  :NUMFAC ";
   } else if(hacia_z == "ANTERIOR") {
     sentencia_z =  "select max (num) ";
     sql2_z = " and num < :NUMFAC ";
   } else if (hacia_z == "SIGUIENTE") {
     sentencia_z = "select min (num) ";
     sql2_z = " and num > :NUMFAC ";
   } else if (hacia_z == "ULTIMO") {
     sentencia_z =  "select max (num) ";
     sql2_z = " and num > :NUMFAC - :NUMFAC ";
   }
   sentencia_z += " as num from facturma where tipofac = :TIPOFAC and seriefac = :SERIE and cia = :CIA";
   sentencia_z += sql2_z;
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sentencia_z);
   dm->qry_maxidvnd->ParamByName("serie")->AsString    = serie_z;
   dm->qry_maxidvnd->ParamByName("tipofac")->AsInteger = entrapor_z;
   dm->qry_maxidvnd->ParamByName("numfac")->AsInteger  = numfac_z;
   dm->qry_maxidvnd->ParamByName("cia")->AsInteger     = cia_z;
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("num")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::busca_ptvt(String ptvt_z)
{
   mi_entrada_z = SIN_ENTRADA;
   String serie_z;
   serie_z = Frame_datosfacma1->edt_seriefac->Text.Trim();
   if(ptvt_z.Trim().IsEmpty()) return;
   qry_facturma->Close();
   qry_facturma->ParamByName("serie")->AsString    = serie_z;
   qry_facturma->ParamByName("tipofac")->AsInteger = entrapor_z;
   qry_facturma->ParamByName("numero")->AsInteger  = StrToIntDef(ptvt_z, 0);
   qry_facturma->ParamByName("cia")->AsInteger     = cia_z;
   qry_facturma->Open();
   if(!qry_facturma->IsEmpty()) {
     desp_ptvt();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::FormCreate(TObject *Sender)
{
  permis_z="N";
  cia_z = dm->cia_z;
  permis_z=dm->busca_permision(CAPFACMA);
  if(permis_z == "N") {
    Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    Close();
  }
  tipoent_z = "S"; entrapor_z = TIPO_SALIDAS_MAYOREO;
  Frame_datosfacma1->edt_seriefac->Text = "MYFA";
  qry_mayoris->Close();
  qry_mayoris->ParamByName("cia")->AsInteger = cia_z;
  qry_mayoris->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::asigna_tipo(int tipo_z)
{
  int idpermis_z;
  entrapor_z = tipo_z;
  switch (entrapor_z) {
    case  TIPO_FACTURAS_MAYOREO:
        tipoent_z = "F"; idpermis_z = CAPFACMA;
        entrapor_z = STATUS1;
        titulo_z = "Factura Mayoreo";
        genero_z = "F";
        break;
    case  TIPO_REMISIONES_MAYOREO:
        tipoent_z = "R"; idpermis_z = CAPFACMA;
        entrapor_z = STATUS2;
        titulo_z = "Remisión Mayoreo";
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
  String serie_z = "MYFA";
  Frame_datosfacma1->edt_seriefac->Text = serie_z;

  mueve_hacia("ULTIMO");
}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------



void __fastcall TForm_hazfacma::agrerenExecute(TObject *Sender)
{
  int idrenfacma_z=0, ii_z=0, conse_z = 0, idart_z = 0, idcodigo_z=0,
  idfacturma_z=0, idserie_z = 0, idconcep_z=0, cantmueve_z=0, canti_z=0,
  alto_z=0, ancho_z=0, idseriefacma_z=0, factur_z=0;
  String tipo_z, codigo_z, siono_z, serie_z="", descri_z="", conseries_z="";
  double piva_z=0, importe_z=0, preciou_z=0, descu_z=0, pordsc_z=0,
  iva_z =0, total_z=0, costou_z=0;
  if(qry_facturma->State == dsInactive) return;
  if(qry_facturma->IsEmpty()) return;
  if( qry_facturma->FieldByName("status")->AsString == "C" ) {
    mensaje_z = titulo_z + " está " + cerrado_z;
    titmsg_z = titulo_z + " " + cerrado_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION);
    return;
  }
  Tdlg_okcancel *Dlg_pidenombre;
  Dlg_pidenombre = new Tdlg_okcancel (this);
  Dlg_pidenombre->AutoSize = false;
  TFrame_datosrenfacma *Frame_datosrenfacma = new TFrame_datosrenfacma (Dlg_pidenombre);
  ancho_z = Frame_datosrenfacma->Width + 20;
  alto_z = Frame_datosrenfacma->Height + Dlg_pidenombre->Panel2->Height + 80;
  Dlg_pidenombre->Width = ancho_z;
  Dlg_pidenombre->Height = alto_z;
  Frame_datosrenfacma->Parent = Dlg_pidenombre->Panel1;
  Frame_datosrenfacma->Top = 0;
  Frame_datosrenfacma->Left= 0;
  Frame_datosrenfacma->Align = alClient;
  Dlg_pidenombre->Caption = "Proporcione Los datos del Artículo";
  Frame_datosrenfacma->tipomay_z == Frame_datosfacma1->edt_tipomay->Text;
  if( Dlg_pidenombre->ShowModal() == mrOk) {
    idfacturma_z = qry_facturma->FieldByName("idfactur")->AsInteger;
    factur_z = qry_facturma->FieldByName("num")->AsInteger;
    siono_z = "S"; //qry_facturma->FieldByName("coniva")->AsString;
    codigo_z = Frame_datosrenfacma->edt_codigo->Text.Trim();
    descri_z = Frame_datosrenfacma->edt_descri->Text.Trim();
    if( entrapor_z == STATUS1 ) {
      piva_z = Frame_datosrenfacma->edt_piva->Value;
    } else {
      piva_z = 0;
    }
    qry_conse->Close();
    qry_conse->ParamByName("idfacturma")->AsInteger = idfacturma_z;
    qry_conse->Open();
    preciou_z = Frame_datosrenfacma->edt_preciou->Value;
    pordsc_z  = Frame_datosrenfacma->edt_pdsc->Value;
    canti_z   = Frame_datosrenfacma->edt_canti->Value;
    conse_z   = qry_conse->FieldByName("ultren")->AsInteger + 1;
    importe_z = preciou_z * canti_z;
    descu_z   = Redondea(importe_z * pordsc_z / 100, 4);
    iva_z     = Redondea((importe_z - descu_z) * (piva_z / 100), 100);
    total_z   = importe_z - descu_z + iva_z;
    idseriefacma_z=dm->busca_sigid(IDSERIEFACMA);
    idrenfacma_z=dm->busca_sigid(IDRENFACMA);
    try {
      dm->manvehi->StartTransaction();
      qry_renfacma->Tag = NO_REFRESH;
      qry_seriefacma->Close();
      qry_seriefacma->ParamByName("idrenfacma")->AsInteger = idrenfacma_z;
      qry_seriefacma->Open();
      //idseriefacma, idfacturma, idrenfacma, idserie
      for(ii_z = 0; ii_z < Frame_datosrenfacma->lst_series->Items->Count; ii_z++) {
        serie_z = Frame_datosrenfacma->lst_series->Items->Strings[ii_z];
        qry_seriefacma->Append();
        qry_seriefacma->FieldByName("factur")->AsInteger = factur_z;
        qry_seriefacma->FieldByName("renglon")->AsInteger = conse_z;
        qry_seriefacma->FieldByName("codinv")->AsString = codigo_z;
        qry_seriefacma->FieldByName("serie")->AsString = serie_z;
        qry_seriefacma->FieldByName("cia")->AsInteger = cia_z;
        qry_seriefacma->FieldByName("idfactur")->AsInteger = idfacturma_z;
        qry_seriefacma->FieldByName("idrenfacma")->AsInteger = idrenfacma_z;
        qry_seriefacma->FieldByName("idseriefacma")->AsInteger = idseriefacma_z;
        qry_seriefacma->Post();
        idseriefacma_z++;
      }
      qry_renfacma->Append();
      qry_renfacma->FieldByName("factur")->AsInteger = factur_z;
      qry_renfacma->FieldByName("consec")->AsInteger = conse_z;
      qry_renfacma->FieldByName("codigo")->AsString = codigo_z;
      qry_renfacma->FieldByName("descri")->AsString = descri_z;
      qry_renfacma->FieldByName("unids")->AsInteger = canti_z;
      qry_renfacma->FieldByName("preciou")->AsFloat = preciou_z;
      qry_renfacma->FieldByName("importe")->AsFloat = importe_z;
      qry_renfacma->FieldByName("pordsc")->AsFloat = pordsc_z;
      qry_renfacma->FieldByName("descu")->AsFloat = descu_z;
      qry_renfacma->FieldByName("poriva")->AsFloat = piva_z;
      qry_renfacma->FieldByName("iva")->AsFloat = iva_z;
      qry_renfacma->FieldByName("total")->AsFloat = total_z;
      qry_renfacma->FieldByName("costou")->AsFloat = costou_z;
      qry_renfacma->FieldByName("cia")->AsInteger = cia_z;
      qry_renfacma->FieldByName("idfactur")->AsInteger = idfacturma_z;
      qry_renfacma->FieldByName("idrenfacma")->AsInteger = idrenfacma_z;
      qry_renfacma->Post();
      qry_facturma->Edit();
      qry_facturma->FieldByName("importe")->AsFloat       += importe_z;
      qry_facturma->FieldByName("descu")->AsFloat         += descu_z;
      qry_facturma->FieldByName("neto")->AsFloat          += importe_z - descu_z;
      qry_facturma->FieldByName("iva")->AsFloat           += iva_z;
      qry_facturma->FieldByName("total")->AsFloat         += total_z;
      qry_facturma->Post();
      qry_facturma->ApplyUpdates();
      qry_renfacma->ApplyUpdates();
      if( qry_seriefacma->UpdatesPending) qry_seriefacma->ApplyUpdates();
      qry_renfacma->Tag = SI_REFRESH;
      dm->manvehi->Commit();

    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
  delete Frame_datosrenfacma;
  delete Dlg_pidenombre;
}
//---------------------------------------------------------------------------



void __fastcall TForm_hazfacma::edicion_factible(int modo_z)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::calcu_prvta()
{
}



void __fastcall TForm_hazfacma::dbgrd_rengnesKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) borrarenExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::borrarenExecute(TObject *Sender)
{
  int idrenfacma_z=0;
  double iva_z = 0, importe_z = 0, descu_z = 0;
  if(qry_facturma->FieldByName("status")->AsString == "C") {
    Application->MessageBox(
      ("No puede eliminar renglones de " + titulo_z + " " + cerrado_z).c_str(),
      (titulo_z + " " + cerrado_z).c_str(), MB_ICONEXCLAMATION);
    return;
  }
  if(Application->MessageBox("Seguro de eliminar este renglón", "Eliminar Renglón", MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  idrenfacma_z = qry_renfacma->FieldByName("idrenfacma")->AsInteger;
  importe_z = qry_renfacma->FieldByName("importe")->AsFloat;
  descu_z = qry_renfacma->FieldByName("descu")->AsFloat;
  iva_z = qry_renfacma->FieldByName("iva")->AsFloat;
//  idrenfacma_z = qry_renfacma->FieldByName("idrenentra")->AsInteger;
  qry_facturma->Edit();
  qry_facturma->FieldByName("importe")->AsFloat       -= Redondea (importe_z, 10000);
  qry_facturma->FieldByName("descu")->AsFloat           -= Redondea (descu_z, 10000);
  qry_facturma->FieldByName("neto")->AsFloat           -= Redondea (importe_z - descu_z , 10000);
  qry_facturma->FieldByName("iva")->AsFloat           -= Redondea (iva_z, 10000);
  qry_facturma->FieldByName("total")->AsFloat         -= Redondea (importe_z - descu_z + iva_z, 10000);
  qry_facturma->Post();
  qry_renfacma->Delete();
  qry_seriefacma->Close();
  qry_seriefacma->ParamByName("idrenfacma")->AsInteger = idrenfacma_z;
  qry_seriefacma->Open();
  for(qry_seriefacma->First(); !qry_seriefacma->Eof; qry_seriefacma->Next())
    qry_seriefacma->Delete();

  try {
    dm->manvehi->StartTransaction();
    qry_facturma->ApplyUpdates();
    qry_renfacma->ApplyUpdates();
//    qry_borraren->Close();
//    qry_borraren->ParamByName("idrenentra")->AsInteger = idrenfacma_z;
//    qry_borraren->ExecSQL();
    dm->manvehi->Commit();
  } catch (Exception &E)  {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::exportdbgridExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = dbgrd_rengnes->Name + ".xls";
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

void __fastcall TForm_hazfacma::cierra_entradaExecute(TObject *Sender)
{
  bool todobien_z = true;
  int idmayoris_z = 0, docto_z =0, nulets_z=0, anu_z, dia_z, mes_z, ii_z=0,
  idmovmay_z = 0, idconcep_z=0;
  double implet_z =0, impultlet_z = 0, total_z;
  String fecha_z, concepto_z, mayoris_z;
  TDateTime vence_z, fechafac_z;
  if(qry_facturma->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede cerrar "+ titulo_z + cerrado_z + "s";
    titmsg_z = " Imposible Cerrar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  mensaje_z = "Seguro Cerrar " + este_z + " " + titulo_z;
  titmsg_z = "Cerrar " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  todobien_z = true;
  mayoris_z = qry_facturma->FieldByName("mayoris")->AsString;
  docto_z = qry_facturma->FieldByName("num")->AsInteger;
  nulets_z = qry_facturma->FieldByName("npagos")->AsInteger;
  total_z = Redondea(qry_facturma->FieldByName("total")->AsFloat, 100);
  fechafac_z = qry_facturma->FieldByName("fecha")->AsDateTime;
  if(nulets_z == 0) nulets_z = 1;
  if(nulets_z > 1) {
    implet_z = Redondea(total_z / nulets_z, 100);
    impultlet_z = total_z - (implet_z * (nulets_z - 1));
  } else {
    implet_z = total_z; impultlet_z = total_z;
  }
  if(todobien_z) {
    if(dm->secuen_z == "N") idmovmay_z=dm->busca_sigid(IDMOVMAY2);
    qry_facturma->Edit();
    qry_facturma->FieldByName("status")->AsString = "C";
    qry_facturma->Post();
    qry_movmay->Close();
    qry_movmay->ParamByName("mayoris")->AsString = mayoris_z;
    qry_movmay->ParamByName("cargos")->AsString = "C";
    qry_movmay->ParamByName("Abonos")->AsString = "x";
    qry_movmay->ParamByName("docto")->AsInteger = docto_z;
    qry_movmay->ParamByName("cia")->AsInteger = cia_z;
    qry_movmay->Open();
    for(qry_movmay->First(); !qry_movmay->Eof; qry_movmay->Next())
      qry_movmay->Delete();
    for(ii_z = 0; ii_z < nulets_z; ii_z++) {
      fecha_z = dm->ahora(); // Frame_datosfacma1->cmb_venctos->Items->Strings[ii_z].Trim();
      dia_z = StrToInt(fecha_z.SubString(1, 2));
      mes_z = StrToInt(fecha_z.SubString(4, 2));
      anu_z = StrToInt(fecha_z.SubString(7, 4));
      vence_z = EncodeDate((Word) anu_z, (Word) mes_z, (Word)dia_z);
      concepto_z = "Factura " + rjust(IntToStr(docto_z), 6) +
        " Pagare " + IntToStr(ii_z+1) + "/" + IntToStr(nulets_z);
      //idconcep_z = dm->busca_iddato(concepto_z, CONCEPTO);
      if(dm->secuen_z != "N")
        idmovmay_z=dm->busca_sigid(IDMOVMAY);
      else
        idmovmay_z++;
      qry_movmay->Append();
      qry_movmay->FieldByName("mayoris")->AsString = mayoris_z;
      qry_movmay->FieldByName("docto")->AsInteger = docto_z;
      qry_movmay->FieldByName("pagare")->AsInteger = ii_z + 1;
      qry_movmay->FieldByName("conse")->AsInteger = ii_z + 1;
      qry_movmay->FieldByName("fecha")->AsDateTime = fechafac_z;
      qry_movmay->FieldByName("fecsal")->AsDateTime = fechafac_z;
      qry_movmay->FieldByName("vence")->AsDateTime = vence_z;
      qry_movmay->FieldByName("concep")->AsString = concepto_z;
      qry_movmay->FieldByName("coa")->AsString = "C";
      if(ii_z + 1 == nulets_z) {
        qry_movmay->FieldByName("importe")->AsFloat = impultlet_z;
        qry_movmay->FieldByName("saldo")->AsFloat = impultlet_z;
      } else {
        qry_movmay->FieldByName("importe")->AsFloat = implet_z;
        qry_movmay->FieldByName("saldo")->AsFloat = implet_z;
      }
      qry_movmay->FieldByName("cia")->AsInteger = cia_z;
      qry_movmay->FieldByName("tipago")->AsString = "E";
      qry_movmay->FieldByName("idconcep")->AsInteger = 0;
      qry_movmay->FieldByName("idmov")->AsInteger = idmovmay_z;
      qry_movmay->FieldByName("tipofac")->AsInteger = entrapor_z;
      //qry_movmay->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
      qry_movmay->Post();
    }
    try {
      dm->manvehi->StartTransaction();
// select idmovmay, idmayoris, docto, pagare, conse, fecha, vence, fecsaldo,
// idconcep, coa, importe, saldo, cia, tipago from movmay
// where idmayoris = :IDMAYORIS and docto = :DOCTO and coa = 'C'

      qry_facturma->ApplyUpdates();
      qry_movmay->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)  {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  } else {
    mensaje_z = "No pude cerrar " + este_z + " " + titulo_z +
    " debido a que surgió algún problema ";
    titmsg_z = "Error en Renglones, Imposible Cerrar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
  }
  desp_ptvt();
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::impritextExecute(TObject *Sender)
{
  String arch_z = "capsmay.txt", serie_z="";
  int ultidart_z = 0, idfacturma_z = 0, numarts_z=0, numfacma_z =0;
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z + "?";
  titmsg_z = "Impresión " + titulo_z;
  if(qry_facturma->State == dsInactive) return;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  genera_cfdi();
  return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  idfacturma_z = qry_facturma->FieldByName("idfactur")->AsInteger;
  impri_encabfac();
  qry_renfacma->DisableControls();
  qry_renfacma->Tag = NO_REFRESH;
  imprime_renglones();
  imprime_finfac();
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renfacma->Tag = SI_REFRESH;
  qry_renfacma->EnableControls();
  dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::impri_encabfac()
{
  lineas_z = 0;
  String dato_z;
  salta_linea(9);
  fprintf(archout, "%s%s", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF)
  );
  fprintf(archout, "%s%s", ljust("", 60), rjust(FormatFloat("0", qry_facturma->FieldByName("num")->AsInteger),6));
  salta_linea(1);
  fprintf(archout, "%s", ljust("", 10));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", ljust(qry_facturma->FieldByName("nomay")->AsString,50));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  fprintf(archout, "%s", ljust("", 19));
  fprintf(archout, "%s", ljust(qry_facturma->FieldByName("rfc")->AsString,16));
  salta_linea(1);
  fprintf(archout, "%s", ljust("", 10));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", ljust(qry_mayoris->FieldByName("nombre2")->AsString,50));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  salta_linea(1);
  fprintf(archout, "%s", ljust("", 12));
  dato_z = qry_facturma->FieldByName("dir")->AsString + " " + qry_mayoris->FieldByName("ciu")->AsString;
  fprintf(archout, "%s", dato_z);
  salta_linea(5);
}

//---------------------------------------------------------------------------
void __fastcall TForm_hazfacma::salta_linea(int numlineas_z)
{
  for(; numlineas_z > 0; numlineas_z--) { lineas_z++; fprintf(archout, "\n"); }
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::imprime_renglones()
{
  String tipopago_z, numcta_z, msg_z;
  if(!qry_datospago->IsEmpty()) {
    tipopago_z = qry_datospago->FieldByName("tipopago")->AsString;
    numcta_z   = qry_datospago->FieldByName("numcta")->AsString;
  }

  for(qry_renfacma->First(); !qry_renfacma->Eof; qry_renfacma->Next()) {
    fprintf(archout, "%s", ljust("", 2));
    fprintf(archout, "%s", rjust(FormatFloat("0", qry_renfacma->FieldByName("unids")->AsInteger), 5));
    fprintf(archout, "%s", ljust("", 6));
    fprintf(archout, "%s", ljust(qry_renfacma->FieldByName("descri")->AsString, 30));
    fprintf(archout, "%s", ljust("", 10));
    fprintf(archout, "%s", rjust(FormatFloat("###,###,##0.00", qry_renfacma->FieldByName("preciou")->AsFloat), 9));
    fprintf(archout, "%s", ljust("", 1));
    fprintf(archout, "%s", rjust(FormatFloat("###,###,##0.00", qry_renfacma->FieldByName("importe")->AsFloat), 13));
    salta_linea(1);
  }
  salta_linea(47 - lineas_z);
  msg_z = "Esta factura tiene el 16% de Iva";
  msg_z += " Forma de Pago:" + tipopago_z;
  if(!numcta_z.IsEmpty()) msg_z + " Num.Cta:" + numcta_z;
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, EMPHIZED_ON));
  fprintf(archout, "%s", msg_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, EMPHIZED_OFF));
  salta_linea(2);
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::imprime_finfac()
{
  String enletras_z, strcanti_z, msg_z, mimes_z;
  double total_z;
  numapal numapal_z;
  if(qry_facturma->FieldByName("descu")->AsInteger) {
    fprintf(archout, "%s", rjust("Importe : ", 54));
    fprintf(archout, "%s", rjust(FormatFloat("###,###,##0.00", qry_facturma->FieldByName("importe")->AsFloat), 13));
    salta_linea(1);
    fprintf(archout, "%s", rjust("Descuento : ", 54));
    fprintf(archout, "%s", rjust(FormatFloat("###,###,##0.00", qry_facturma->FieldByName("descu")->AsFloat), 13));
    salta_linea(2);
  }
  fprintf(archout, "%s", rjust(FormatFloat("###,###,##0.00", qry_facturma->FieldByName("neto")->AsFloat), 77));
  salta_linea(2);
  fprintf(archout, "%s", rjust(FormatFloat("###,###,##0.00", qry_facturma->FieldByName("iva")->AsFloat), 77));
  salta_linea(1);
  total_z = qry_facturma->FieldByName("total")->AsFloat;
  enletras_z = numapal_z.Obt(int(total_z));
  enletras_z = enletras_z + " Pesos ";
  strcanti_z = FormatFloat("0.00", total_z);
  strcanti_z = strcanti_z.SubString(strcanti_z.Length() - 1, 2);
  enletras_z += strcanti_z + "/100 M.N";
  fprintf(archout, "%s", ljust("", 16));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", enletras_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
  salta_linea(1);
  fprintf(archout, "%s", rjust(FormatFloat("###,###,##0.00", total_z), 77));
  salta_linea(1);
  msg_z = "Esta factura sera pagada en ";
  if( qry_facturma->FieldByName("npagos")->AsInteger > 1) {
    msg_z += FormatFloat("0", qry_facturma->FieldByName("npagos")->AsInteger);
    msg_z += " Exhibiciones";
  } else {
    msg_z += " una sola Exhibicion";
  }
  // -> Ya lo tiene impreso la Factura fprintf(archout, "%s%s", ljust("", 14), ljust(msg_z,60));
  salta_linea(1);
  // -> Ya lo tiene impreso la Factura fprintf(archout, "%s%s", ljust("", 14), ljust("Efectos fiscales al pago",60));
  salta_linea(2);
  mimes_z = nommes(StrToInt(FormatDateTime("mm", qry_facturma->FieldByName("fecha")->AsDateTime)));
  fprintf(archout, "%s%s", ljust("", 32), ljust(FormatDateTime("dd", qry_facturma->FieldByName("fecha")->AsDateTime),2));
  fprintf(archout, "%s%s", ljust("", 6),  ljust(mimes_z,12));
  fprintf(archout, "%s%s", ljust("", 15), ljust(FormatDateTime("yyyy", qry_facturma->FieldByName("fecha")->AsDateTime),4));
  salta_linea(1);
}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::report_encab()
{
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  fprintf(archout, "Impresion de %s\n", titulo_z.c_str());
  fprintf(archout, "Numero:%6d Almacen:%s %s Fecha:%s\n",
    qry_facturma->FieldByName("numero")->AsInteger,
    "qry_almacen->FieldByName(clave)->AsString",
    "qry_almacen->FieldByName(nombre)->AsString",
    FormatDateTime("dd-mm-yyyy", qry_facturma->FieldByName("fecha")->AsDateTime)
  );
  fprintf(archout, "Mayorista:%s %s\n",
    qry_mayoris->FieldByName("codigo")->AsString,
    qry_mayoris->FieldByName("nombre")->AsString
  );
  fprintf(archout, "%s%s%s|%s|%s|%s|%s|%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON),
    cjust("Articulo", 44),
    rjust("Folio", 5),
    rjust("Costo_Unitar", 12),
    cjust("C", 1),
    cjust("S", 1),
    ljust("Serie", 20),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::report_subencab()
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

void __fastcall TForm_hazfacma::qry_renfacmaAfterScroll(TDataSet *DataSet)
{
    int idrenfacma_z = 0;
    String serie_z="";
    if(qry_renfacma->Tag == NO_REFRESH) return;
    //lkcmb_inven->KeyValue = qry_renfacma->FieldByName("idart")->AsInteger;
    //lkcmb_mayoris->KeyValue = qry_renfacma->FieldByName("idvend")->AsInteger;
    idrenfacma_z = qry_renfacma->FieldByName("idrenfacma")->AsInteger;
    Frame_datosrenfacma1->edt_preciou->Value = qry_renfacma->FieldByName("preciou")->AsFloat;
    Frame_datosrenfacma1->edt_canti->Value = qry_renfacma->FieldByName("unids")->AsFloat;
    Frame_datosrenfacma1->edt_pdsc->Value = qry_renfacma->FieldByName("pordsc")->AsFloat;
    Frame_datosrenfacma1->edt_descri->Text = qry_renfacma->FieldByName("descri")->AsString;
    Frame_datosrenfacma1->edt_codigo->Text = qry_renfacma->FieldByName("codigo")->AsString;
    Frame_datosrenfacma1->lst_series->Items->Clear();
    qry_seriefacma->Close();
    qry_seriefacma->ParamByName("idrenfacma")->AsInteger = idrenfacma_z;
    qry_seriefacma->Open();
    for(qry_seriefacma->First(); !qry_seriefacma->Eof; qry_seriefacma->Next()) {
      serie_z = qry_seriefacma->FieldByName("serie")->AsString;
      Frame_datosrenfacma1->lst_series->Items->Add(serie_z);
    }
    Frame_datosrenfacma1->lst_series->ItemIndex = 0;
}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::Frame_datosfacma1edt_numfacKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) busca_ptvt(Frame_datosfacma1->edt_numfac->Text);

}
//---------------------------------------------------------------------------




void __fastcall TForm_hazfacma::Frame_datosrenfacma1edt_codigoKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN)  {
    Frame_datosrenfacma1->lst_series->DroppedDown = true;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::despliega_menuExecute(TObject *Sender)
{
  PopupMenu1->Popup(100, 100);
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::Frame_datosrenfacma1edt_codigoExit(
      TObject *Sender)
{
   String micodigo_z = Frame_datosrenfacma1->edt_codigo->Text;

}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::dbgrd_rengnesCustomDrawCell(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxTreeListColumn *AColumn, bool ASelected,
      bool AFocused, bool ANewItemRow, AnsiString &AText, TColor &AColor,
      TFont *AFont, TAlignment &AAlignment, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::genera_cfdi()
{
    String concepto_z, archfac_z, seriefac_z, valtmp_z,
       mayoris_z, archbus_z="", archxml_z="-1";
    double importe_z, subtot_z, poriva_z, total_z, hora_z;
    int numfac_z, canti_z;
    TStringList *listaxml_z = new TStringList();
    numfac_z = qry_facturma->FieldByName("num")->AsInteger;
    seriefac_z = qry_facturma->FieldByName("seriefac")->AsString;
    feccap_z = qry_facturma->FieldByName("fecha")->AsDateTime;
    hora_z = ( dm->ahora() - int(dm->ahora())) - 60*60*2;
    feccap_z = int(feccap_z) + hora_z;
    // Voy a buscar el dato del UUID de la Factura del Cliente
    archfac_z = "recibos\\" + qry_facturma->FieldByName("seriefac")->AsString;
    archfac_z += FormatFloat("000000", numfac_z) + ".txt";
    archbus_z = "-"  + IntToStr(numfac_z) + seriefac_z.Trim();
    if( (archout = fopen(archfac_z.c_str(), "wt")) == NULL) {
      Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
      return;
    }

    mayoris_z = Frame_datosfacma1->qry_mayoris->FieldByName("codigo")->AsString;
    qry_datosmayoris->Close();
    qry_datosmayoris->ParamByName("mayoris")->AsString = mayoris_z;
    qry_datosmayoris->ParamByName("cia")->AsInteger = cia_z;
    qry_datosmayoris->Open();
    qry_renfacma->Tag = NO_REFRESH;
    qry_renfacma->DisableControls();
    //fprintf(archout, "%s%s", IntToStr(numfac_z), "|"); // Numero de Fac

    for(qry_renfacma->First(); !qry_renfacma->Eof; qry_renfacma->Next()) {
      concepto_z = qry_renfacma->FieldByName("descri")->AsString;
      importe_z =  qry_renfacma->FieldByName("preciou")->AsFloat;
      poriva_z  =  qry_renfacma->FieldByName("poriva")->AsFloat;
      canti_z   =  qry_renfacma->FieldByName("unids")->AsInteger;
      genera_layout(numfac_z, concepto_z, importe_z, poriva_z, canti_z);
    }
    fclose (archout);
    qry_renfacma->Tag = SI_REFRESH;
    qry_renfacma->EnableControls();
    dm->manda_impresion(archfac_z);

    // Ahora lo voy a copiar al directorio donde lo toma el conector

}
//---------------------------------------------------------------------------


bool __fastcall TForm_hazfacma::genera_layout(
  int numfac_z, String concepto_z, double importe_z,
  double poriva_z, int canti_z
)
{
  double impsiniva_z=0;
  TDateTime fecha_z;
  String nombrecli_z, rfccli_z, pais_z, estado_z, poblac_z,
   mediospago_z, medio1_z, medio2_z, numcta_z,
   calles_z, numpred_z, numint_z, colonia_z, codpost_z,
   unidadmedida_z, formapago_z, seriefac_z, condicionespago_z, regimen_z,
   pobsuc_z, emailcli_z, mayoris_z;
  int diaspago_z = 0;
  mayoris_z = qry_mayoris->FieldByName("codigo")->AsString;
  impsiniva_z = importe_z;
  emailcli_z = obten_datosmayoris(mayoris_z, "EMAIL");
  fecha_z = qry_facturma->FieldByName("fecha")->AsDateTime;
  diaspago_z = qry_facturma->FieldByName("npagos")->AsInteger;
  diaspago_z = diaspago_z * qry_facturma->FieldByName("plazo")->AsInteger;
  if(diaspago_z) {
    formapago_z = "Pago en parcialidades";
    condicionespago_z = "Credito";
  } else {
    formapago_z = "Pago en una sola exhibicion";
    condicionespago_z = "Contado";
  }
  unidadmedida_z = "PIEZA";
  seriefac_z = qry_facturma->FieldByName("seriefac")->AsString;
  nombrecli_z = qry_facturma->FieldByName("nomay")->AsString;
  rfccli_z = qry_facturma->FieldByName("rfc")->AsString;
  poblac_z = Frame_datosfacma1->qry_mayoris->FieldByName("codigo")->AsString;
  poblac_z = Frame_datosfacma1->qry_mayoris->FieldByName("ciu")->AsString;
  pais_z   = dm->busca_pais_estado("PAIS", poblac_z);
  estado_z = dm->busca_pais_estado("ESTADO", poblac_z);
  numcta_z = Frame_datosfacma1->edt_numcta1->Text.Trim();
  if(!Frame_datosfacma1->edt_numcta2->Text.Trim().IsEmpty()) {
    numcta_z += " " + Frame_datosfacma1->edt_numcta2->Text.Trim();
  }
  medio1_z = Frame_datosfacma1->qry_mediospago->FieldByName("clave")->AsString;
  medio2_z = Frame_datosfacma1->qry_mediopago2->FieldByName("clave")->AsString;

  mediospago_z = medio1_z + " " + Frame_datosfacma1->qry_mediospago->FieldByName("descri")->AsString;
  if(medio1_z != medio2_z) {
    mediospago_z += "," + medio2_z + " " + Frame_datosfacma1->qry_mediopago2->FieldByName("descri")->AsString;
  }

  String sep_z="|";
  fprintf(archout, "%s", sep_z);
  fprintf(archout, "%s%s", IntToStr(numfac_z), sep_z); // Numero de Fac
  fprintf(archout, "%s%s", seriefac_z, sep_z); // Serie de Fac
  fprintf(archout, "%s%s", nombrecli_z, sep_z); // Nombre del Cliente
  fprintf(archout, "%s%s", rfccli_z, sep_z); // Rfc del Cliente Menudeo AXXXX
  fprintf(archout, "%s%s", pais_z, sep_z);  // Pais del Cliente
  fprintf(archout, "%s%s", estado_z, sep_z); // Estado de la republica
  fprintf(archout, "%s%s", poblac_z, sep_z); // Municipio
  fprintf(archout, "%s%s", poblac_z, sep_z); // Poblacion
  fprintf(archout, "%s%s", Frame_datosfacma1->calles_z.c_str(), sep_z); // Calle
  fprintf(archout, "%s%s", Frame_datosfacma1->numpred_z.c_str(), sep_z); // Número de Predio
  fprintf(archout, "%s", sep_z); // Interior del Predio
  fprintf(archout, "%s%s", Frame_datosfacma1->colonia_z.c_str(), sep_z); // Colonia del Cliente
  fprintf(archout, "%s%s", Frame_datosfacma1->codpost_z.c_str(), sep_z); // Codigo postal del cliente
  fprintf(archout, "%s%s", FormatDateTime("ddmmyyyy:", fecha_z) + FormatDateTime("hh:nn:ss", feccap_z), sep_z); // Municipio
  fprintf(archout, "%s%s", unidadmedida_z.c_str(), sep_z); // Unidad de Medida NO APLICA
  fprintf(archout, "%s%s", FormatFloat("0", canti_z), sep_z); // Cantidad
  fprintf(archout, "%s%s", FormatFloat("0.000", impsiniva_z), sep_z); // Importe del Movimiento
  fprintf(archout, "%s%s", concepto_z.Trim().c_str(), sep_z); // Concepto del Movimiento
  fprintf(archout, "%s", sep_z); // Codigo del Articulo lo dejo vacío
  fprintf(archout, "%s%s", FormatFloat("0", poriva_z), sep_z); // Tasa de Iva del Cliente
  fprintf(archout, "%s%s", "TRUE", sep_z); // Status de la Factura
  fprintf(archout, "%s%s", "0", sep_z); // Tasa de Descuento
  fprintf(archout, "%s%s", "0", sep_z); // Tasa de IEPS
  fprintf(archout, "%s%s", "0", sep_z); // Tasa Ret ISR
  fprintf(archout, "%s%s", "0", sep_z); // Tasa Ret IVA
  fprintf(archout, "%s", sep_z); // Observaciones
  fprintf(archout, "%s%s", "Pesos", sep_z); // Nombre de la Moneda de la Transaccion
  fprintf(archout, "%s%s", "MXN", sep_z); // Simbolo Internacional de la moneda
  fprintf(archout, "%s%s", "1", sep_z); // Tipo de Cambio
  fprintf(archout, "%s%s", formapago_z.c_str(), sep_z); // Forma de Pago Una Sola Exhibicion o Parcialidades
  fprintf(archout, "%s%s", condicionespago_z.c_str(), sep_z); // Condiciones de Pago Credito o Contado
  fprintf(archout, "%s%s", mediospago_z, sep_z); // Metodo de Pago
  fprintf(archout, "%s%s", emailcli_z.c_str(), sep_z); // Correo del Cliente
  for(int ii_z = 0; ii_z < 7; ii_z++)
    fprintf(archout, "%s", sep_z); // Imprimo las 7 Leyendas vacias
  fprintf(archout, "%s%s", numcta_z.c_str(), sep_z); // Número de Cta con que paga el Cliente
  fprintf(archout, "%s%s", pobsuc_z.c_str(), sep_z); // Lugar de Expedicion
  fprintf(archout, "%s%s", regimen_z.c_str(), sep_z); // Regimen fiscal de nosotros
  fprintf(archout, "%s", sep_z); // UUID Original del Cliente
  fprintf(archout, "%s", sep_z); // Serie de la factura original
  fprintf(archout, "%s", sep_z); // Fecha Original de la Compra
  fprintf(archout, "%s", sep_z); // Importe Original de la Venta
  fprintf(archout, "\n"); // Salto de Línea
  return (true);
}
//---------------------------------------------------------------------------


void __fastcall TForm_hazfacma::graba_uuidExecute(TObject *Sender)
{
  String uuid_z;
  int iduuid_z, alto_z, ancho_z;
  if(qry_facturma->State == dsInactive) return;
  if(qry_facturma->IsEmpty() ) return;
  if(qry_facturma->FieldByName("status")->AsString != "C") {
    mensaje_z = este_z + " " + titulo_z + " no ha sido " + cerrado_z +
    " previamente, no puede grabar uuid ";
    titmsg_z = "Imposible Modificar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  Tdlg_okcancel* Dlg_datos;
  Dlg_datos = new Tdlg_okcancel (this);
  TLabel *lbl_uuid = new TLabel (Dlg_datos);
  lbl_uuid->Parent = Dlg_datos->Panel1;
  lbl_uuid->Caption = "Uuid";
  lbl_uuid->Top  = 20;
  lbl_uuid->Left = 20;
  TEdit *edt_uuid = new TEdit (Dlg_datos);
  edt_uuid->Parent = Dlg_datos->Panel1;
  edt_uuid->Width = 250;
  edt_uuid->Top  = 18;
  edt_uuid->Left = lbl_uuid->Left + lbl_uuid->Width + 10;
  edt_uuid->CharCase = ecUpperCase;

  if(Dlg_datos->ShowModal() == mrOk) {
    uuid_z = edt_uuid->Text.Trim();
    iduuid_z = dm->busca_iddato(uuid_z, INVCONCEPTO);
    qry_facturma->Edit();
    qry_facturma->FieldByName("iduuid")->AsInteger = iduuid_z;
    qry_facturma->Post();
    try {
      dm->manvehi->StartTransaction();
      qry_facturma->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
  delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::graba_permision_precioExecute(
      TObject *Sender)
{
  int aplicado_z, idfac_z;
  String permision_z, siono_z, msg_z, antmaster_z;
  if(qry_facturma->State == dsInactive) return;
  if(qry_facturma->IsEmpty()) return;
  antmaster_z = dm->usermaster_z;
  dm->usermaster_z = "N";
  permision_z=dm->busca_permistr("PRECIO_FAC_MAY");
  dm->usermaster_z = antmaster_z;
  if(permision_z != "T") {
    Application->MessageBox("Lo siento, no puede Asignar ese dato", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }

  idfac_z = qry_facturma->FieldByName("idfactur")->AsInteger;
  if(qry_facturma->FieldByName("status")->AsString == "C") {
    mensaje_z = este_z + " " + titulo_z + " ha sido " + cerrado_z +
    " previamente, no puede modificar "+ titulo_z + cerrado_z + "s";
    titmsg_z = "Imposible Modificar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  aplicado_z = Application->MessageBox("Permitir Teclear Precio Venta a Esta Factura ", "Abrir Precio Venta", MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2);
  if(aplicado_z == IDYES) {
    siono_z = "S";
    msg_z = "Ahora Ya se puede teclear el precio";
  } else {
    siono_z = "N";
    msg_z = "Ya NO se puede teclear el precio";
  }
  agrega_relac(IntToStr(idfac_z), siono_z, "","REL_FACMAY_PIDEPRE");
  try {
      dm->manvehi->StartTransaction();
      qry_datospago->ApplyUpdates();
      dm->manvehi->Commit();
  } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
  Application->MessageBox((msg_z).c_str(), "Exito", MB_ICONEXCLAMATION);

}
//---------------------------------------------------------------------------

void __fastcall TForm_hazfacma::cancelarExecute(TObject *Sender)
{
  bool todobien_z = true;
  int idmayoris_z = 0, docto_z =0, nulets_z=0, anu_z, dia_z, mes_z, ii_z=0,
  idmovmay_z = 0, idconcep_z=0;
  double implet_z =0, impultlet_z = 0, total_z;
  String fecha_z, concepto_z, mayoris_z, errores_z;
  TDateTime vence_z, fechafac_z;
  if(qry_facturma->FieldByName("status")->AsString != "C") {
    mensaje_z = este_z + " " + titulo_z + " no ha sido " + cerrado_z;
    titmsg_z = " Imposible Cancelar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }
  mayoris_z = qry_facturma->FieldByName("mayoris")->AsString;
  docto_z = qry_facturma->FieldByName("num")->AsInteger;
  qry_movmay->Close();
  qry_movmay->ParamByName("mayoris")->AsString = mayoris_z;
  qry_movmay->ParamByName("cargos")->AsString = "C";
  qry_movmay->ParamByName("abonos")->AsString = "A";
  qry_movmay->ParamByName("docto")->AsInteger = docto_z;
  qry_movmay->ParamByName("cia")->AsInteger = cia_z;
  qry_movmay->Open();
  errores_z = "";
  for(qry_movmay->First(); !qry_movmay->Eof; qry_movmay->Next()) {
    if(qry_movmay->FieldByName("coa")->AsString == "A") {
      errores_z = errores_z + FormatDateTime ("dd/mm/yyyy", qry_movmay->FieldByName("Fecha")->AsDateTime);
      errores_z = errores_z + " $ " + FormatFloat ("0.00", qry_movmay->FieldByName("importe")->AsFloat) + "\n";
      todobien_z = false;
    }
  }
  if( !todobien_z) {
    mensaje_z = errores_z;
    titmsg_z = " Imposible Cancelar "  + titulo_z + " Tiene Abonos";
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_OK);
    return;
  }

  mensaje_z = "Seguro Cancelar " + este_z + " " + titulo_z;
  titmsg_z = "Cacelar " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO+MB_DEFBUTTON2) != IDYES) return;
  todobien_z = true;
  mayoris_z = qry_facturma->FieldByName("mayoris")->AsString;
  docto_z = qry_facturma->FieldByName("num")->AsInteger;
  nulets_z = qry_facturma->FieldByName("npagos")->AsInteger;
  total_z = Redondea(qry_facturma->FieldByName("total")->AsFloat, 100);
  fechafac_z = qry_facturma->FieldByName("fecha")->AsDateTime;
  if(nulets_z == 0) nulets_z = 1;
  if(nulets_z > 1) {
    implet_z = Redondea(total_z / nulets_z, 100);
    impultlet_z = total_z - (implet_z * (nulets_z - 1));
  } else {
    implet_z = total_z; impultlet_z = total_z;
  }

  if(todobien_z) {
    qry_renfacma->Tag = NO_REFRESH;
    qry_facturma->Delete();
    for(qry_movmay->First(); !qry_movmay->Eof; qry_movmay->First()) {
      qry_movmay->Delete();
    }
    for(qry_renfacma->First(); !qry_renfacma->Eof; qry_renfacma->First()) {
      qry_renfacma->Delete();
    }
    qry_renfacma->Tag = SI_REFRESH;
    try {
      dm->manvehi->StartTransaction();
// select idmovmay, idmayoris, docto, pagare, conse, fecha, vence, fecsaldo,
// idconcep, coa, importe, saldo, cia, tipago from movmay
// where idmayoris = :IDMAYORIS and docto = :DOCTO and coa = 'C'

      qry_facturma->ApplyUpdates();
      qry_renfacma->ApplyUpdates();
      qry_movmay->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)  {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  } else {
    mensaje_z = "No pude cancelar " + este_z + " " + titulo_z +
    " debido a que surgió algún problema ";
    titmsg_z = "Error en Renglones, Imposible Cerrar " + titulo_z;
    Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONEXCLAMATION);
    desp_ptvt();
  }
  mueve_hacia("ULTIMO");
}
//---------------------------------------------------------------------------

