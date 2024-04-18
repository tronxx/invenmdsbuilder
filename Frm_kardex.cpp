//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_kardex.h"
#include "numapal.h"
#include <inifiles.hpp>
#include "situaciones.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm_kardex *Form_kardex;
//---------------------------------------------------------------------------
__fastcall TForm_kardex::TForm_kardex(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

bool TForm_kardex::afecta_traspasos(String codigo_z, String serie_z,
          int folent_z, int folsal_z, double fecha_z,
          String alm_z, String recemi_z,
          String tiposal_z, int idcomprador_z, int idprovee_z,
          String siono_z, int nsabana_z, int npoblac_z, int numren_z
)
{
   Word aa_z, mm_z, dd_z;
   int cia_z, idnompro_z=0, numfac_z=0, tipoest_z=0;
   double costou_z=0, piva_z=0;
   TDateTime fecha2_z, fecentori_z, vence_z;
   String msg_z, vend_z, facpro_z, entcan_z, prove_z, seriefac_z,
   nompro_z, compro_z;
   TLocateOptions Opts;
   bool result_z = true;
   errores_z = new TStringList ();

   Opts.Clear();
   fecha2_z = fecha_z;
   DecodeDate(fecha2_z, aa_z, mm_z, dd_z);
   tipoest_z = busca_tipo_est(tiposal_z);

   cia_z = dm->cia_z;
//   select tipo, alm, numero, conse, codinv, folsal, folent, costou, importe, piva, status, cia
//   from renentra
//  where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse = :NUMREN and
// cia = :CIA
   qry_almacen->Close();
   qry_almacen->ParamByName("almrec")->AsString = alm_z;
   qry_almacen->ParamByName("almenv")->AsString = recemi_z;
   qry_almacen->ParamByName("cia")->AsInteger = cia_z;
   qry_almacen->Open();
   for(qry_almacen->First(); !qry_almacen->Eof; qry_almacen->Next()) {
     if(qry_almacen->FieldByName("clave")->AsString == alm_z) {
       nompro_z = qry_almacen->FieldByName("nombre")->AsString;
     }
     if(qry_almacen->FieldByName("clave")->AsString == recemi_z) {
       compro_z = qry_almacen->FieldByName("nombre")->AsString;
     }
   }
   idnompro_z = dm->busca_iddato(nompro_z, OLDCONCEPTO);
   idcomprador_z = dm->busca_iddato(compro_z, OLDCONCEPTO);
   qry_ultfol->Close();
   qry_ultfol->ParamByName("almrec")->AsString = recemi_z;
   qry_ultfol->ParamByName("codigo")->AsString = codigo_z;
   qry_ultfol->ParamByName("cia")->AsInteger = cia_z;
   qry_ultfol->Open();
   if(qry_ultfol->IsEmpty())
     folent_z = 1;
   else
     folent_z = qry_ultfol->FieldByName("ultfol")->AsInteger + 1;

   qry_renentra->Close();
   qry_renentra->ParamByName("tipo")->AsString = tiposal_z;
   qry_renentra->ParamByName("alm")->AsString = alm_z;
   qry_renentra->ParamByName("numero")->AsInteger = nsabana_z;
   qry_renentra->ParamByName("numren")->AsInteger = numren_z;
   qry_renentra->ParamByName("cia")->AsInteger = cia_z;
   qry_renentra->Open();
   if(qry_renentra->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Renglón" + IntToStr(numren_z) + " No existe");
   }
   //vend_z = qry_renentra->FieldByName("vend")->AsString;
   // Primero genero la Entrada
   qry_movart->Close();
   qry_movart->ParamByName("codigo")->AsString = codigo_z;
   qry_movart->ParamByName("alm")->AsString = alm_z;
   qry_movart->ParamByName("folio")->AsInteger = folsal_z;
   qry_movart->ParamByName("alment")->AsString = "xx";
   qry_movart->ParamByName("folent")->AsInteger = -1;
   qry_movart->ParamByName("cia")->AsInteger = cia_z;
   qry_movart->Open();
   // Estan las Validaciones
   if(qry_movart->IsEmpty()) {
     result_z = false;
     errores_z->Add("No existe el Folio " + IntToStr(folsal_z));
   }
   if(fechaabierta_z != "S") {
     if( qry_movart->FieldByName("fecha")->AsDateTime > fecha2_z) {
       result_z = false;
       errores_z->Add("La Fecha de Entrada es Posterior a la de Salida");
     }
   }
   if(qry_movart->FieldByName("salio")->AsString == "S") {
     result_z = false;
     errores_z->Add("El Folio ya no está Disponible");
   }
   if(! result_z) return(result_z);
   // Si no es de Celular tomo el costo del Movart
   // Tomo los datos que necesito del movart que sale
   //if(tiposal_z != "Q") costou_z = qry_movart->FieldByName("costo")->AsFloat;
   // Marco el Folio como Salido .-.-.-.-.-.
   siono_z = qry_movart->FieldByName("modent")->AsString;
   costou_z = qry_movart->FieldByName("costo")->AsFloat;
   fecentori_z = qry_movart->FieldByName("fecentori")->AsDateTime;
   vence_z = qry_movart->FieldByName("fecvencto")->AsDateTime;
   facpro_z = qry_movart->FieldByName("facpro")->AsString;
   entcan_z = qry_movart->FieldByName("entcan")->AsString;
   prove_z = qry_movart->FieldByName("prove")->AsString;
   if (siono_z == "S") {
     qry_inven->Close();
     qry_inven->ParamByName("codigo")->AsString = codigo_z;
     qry_inven->ParamByName("cia")->AsInteger = cia_z;
     qry_inven->Open();
     piva_z = qry_inven->FieldByName("piva")->AsFloat;
   } else {
     piva_z = 0;
   }

   qry_movart->Edit();
   qry_movart->FieldByName("salio")->AsString = "S";
   qry_movart->FieldByName("fechasal")->AsDateTime = fecha2_z;
   if(qry_movart->FieldByName("serie")->AsString.Trim().IsEmpty())
     qry_movart->FieldByName("serie")->AsString = serie_z;
   qry_movart->FieldByName("compro")->AsInteger = idcomprador_z;
   qry_movart->FieldByName("modsal")->AsString = siono_z;
   qry_movart->FieldByName("nsalida")->AsInteger = nsabana_z;
   qry_movart->FieldByName("salepor")->AsInteger = tipoest_z;
//   qry_movart->FieldByName("ptvta")->AsString = ptovta_z;
   qry_movart->FieldByName("pueblo")->AsInteger = npoblac_z;
   qry_movart->FieldByName("vahacia")->AsString = recemi_z;
   qry_movart->FieldByName("folrec")->AsInteger = folent_z;
   qry_movart->FieldByName("vend")->AsString = vend_z;
   qry_movart->Post();
   // -.-.-.-.-.-.-. Ahora genero el Renglón de Entrada .-.-.-.-.-.
   agrega_movart();
   qry_movart->FieldByName("codigo")->AsString = codigo_z;
   qry_movart->FieldByName("almac")->AsString = recemi_z;
   qry_movart->FieldByName("folio")->AsInteger = folent_z;
   qry_movart->FieldByName("entrapor")->AsInteger = tipoest_z;
   qry_movart->FieldByName("prove")->AsString = prove_z;
   qry_movart->FieldByName("nompro")->AsString = idnompro_z;
   qry_movart->FieldByName("facpro")->AsString = facpro_z;
   qry_movart->FieldByName("fecha")->AsDateTime = fecha2_z;
   qry_movart->FieldByName("costo")->AsFloat = costou_z;
   qry_movart->FieldByName("modent")->AsString = siono_z;
   qry_movart->FieldByName("nentrada")->AsInteger = nsabana_z;
   qry_movart->FieldByName("tipo")->AsString = "E";
   qry_movart->FieldByName("vienede")->AsString = alm_z;
   qry_movart->FieldByName("folviene")->AsInteger = folsal_z;
   qry_movart->FieldByName("numfac")->AsInteger = numfac_z;
   qry_movart->FieldByName("seriefac")->AsString = seriefac_z;
   qry_movart->FieldByName("salio")->AsString = "N";
   qry_movart->FieldByName("canti")->AsInteger = 1;
   qry_movart->FieldByName("serie")->AsString = serie_z;
   qry_movart->FieldByName("entcan")->AsString = entcan_z;
   qry_movart->FieldByName("fecentori")->AsDateTime = fecentori_z;
   qry_movart->FieldByName("fecvencto")->AsDateTime = vence_z;
   qry_movart->FieldByName("usuario")->AsString = dm->iniciales_z;
   qry_movart->FieldByName("cia")->AsString = cia_z;
   qry_movart->Post();
   //.-.-.-.-.-.-.-. Resto la Existencia en Exist .-.-.-._:_:_:_:_
   qry_exist->Close();
   qry_exist->ParamByName("codigo")->AsString = codigo_z;
   qry_exist->ParamByName("almsale")->AsString = alm_z;
   qry_exist->ParamByName("almentra")->AsString = recemi_z;
   qry_exist->ParamByName("cia")->AsInteger = cia_z;
   qry_exist->Open();
   qry_exist->First();
   // -- Primero Localizo al Emisor ---- //
   if(!qry_exist->Locate("alm", alm_z, Opts)) {
      agrega_exist(codigo_z, alm_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   if(siono_z == "S") {
     qry_exist->FieldByName("salesps")->AsFloat = qry_exist->FieldByName("salesps")->AsFloat + 1;
     qry_exist->FieldByName("cossalesps")->AsFloat = qry_exist->FieldByName("cossalesps")->AsFloat + costou_z;
     qry_exist->FieldByName("existes")->AsFloat = qry_exist->FieldByName("existes")->AsFloat - 1;
     qry_exist->FieldByName("cosexistes")->AsFloat = qry_exist->FieldByName("cosexistes")->AsFloat - costou_z;
   } else {
     qry_exist->FieldByName("salespn")->AsFloat = qry_exist->FieldByName("salespn")->AsFloat + 1;
     qry_exist->FieldByName("cossalespn")->AsFloat = qry_exist->FieldByName("cossalespn")->AsFloat + costou_z;
     qry_exist->FieldByName("existen")->AsFloat = qry_exist->FieldByName("existen")->AsFloat - 1;
     qry_exist->FieldByName("cosexisten")->AsFloat = qry_exist->FieldByName("cosexisten")->AsFloat - costou_z;
   }
   qry_exist->Post();
   //.-.-.-.-.-.-.-. Sumo la Existencia en Receptor .-.-.-._:_:_:_:_
   qry_exist->First();
   // -- Ahora Localizo al Receptor ---- //
   if(!qry_exist->Locate("alm", recemi_z, Opts)) {
      agrega_exist(codigo_z, recemi_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   if(siono_z == "S") {
     qry_exist->FieldByName("entesps")->AsFloat = qry_exist->FieldByName("salesps")->AsFloat + 1;
     qry_exist->FieldByName("cosentesps")->AsFloat = qry_exist->FieldByName("cossalesps")->AsFloat + costou_z;
     qry_exist->FieldByName("existes")->AsFloat = qry_exist->FieldByName("existes")->AsFloat + 1;
     qry_exist->FieldByName("cosexistes")->AsFloat = qry_exist->FieldByName("cosexistes")->AsFloat + costou_z;
   } else {
     qry_exist->FieldByName("enteson")->AsFloat = qry_exist->FieldByName("salespn")->AsFloat + 1;
     qry_exist->FieldByName("cosentespn")->AsFloat = qry_exist->FieldByName("cossalespn")->AsFloat + costou_z;
     qry_exist->FieldByName("existen")->AsFloat = qry_exist->FieldByName("existen")->AsFloat + 1;
     qry_exist->FieldByName("cosexisten")->AsFloat = qry_exist->FieldByName("cosexisten")->AsFloat + costou_z;
   }
   qry_exist->FieldByName("ultfol")->AsInteger += 1;
   qry_exist->Post();
   qry_renentra->Edit();
   qry_renentra->FieldByName("costou")->AsFloat = costou_z;
   qry_renentra->FieldByName("importe")->AsFloat = costou_z;
   qry_renentra->FieldByName("status")->AsString = "C";
   qry_renentra->FieldByName("siono")->AsString = siono_z;
   qry_renentra->FieldByName("folent")->AsInteger = folent_z;
   qry_renentra->Post();
   try {
     dm->manvehi->StartTransaction();
     qry_movart->ApplyUpdates();
     qry_exist->ApplyUpdates();
     qry_renentra->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   return (true);


}
//---------------------------------------------------------------------------


bool TForm_kardex::salida_sabana_vtas(
  String codigo_z,
  String serie_z,
  int folio_z,
  double fecha_z,
  String alm_z,
  String ptovta_z,
  String tiposal_z,
  int idcomprador_z,
  String siono_z,
  int nsabana_z,
  int npoblac_z,
  int numren_z
)
{
   Word aa_z, mm_z, dd_z;
   int cia_z, tipoest_z;
   double costou_z=0;
   TDateTime fecha2_z;
   String msg_z, vend_z;
   bool result_z = true;
   errores_z = new TStringList ();

   fecha2_z = fecha_z;
   DecodeDate(fecha2_z, aa_z, mm_z, dd_z);
   tipoest_z = busca_tipo_est(tiposal_z);

   cia_z = dm->cia_z;
//   select tipo, alm, numero, conse, codinv, folsal, folent, costou, importe, piva, status, cia
//   from renentra
//  where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse = :NUMREN and
// cia = :CIA

   qry_renentra->Close();
   qry_renentra->ParamByName("tipo")->AsString = tiposal_z;
   qry_renentra->ParamByName("alm")->AsString = alm_z;
   qry_renentra->ParamByName("numero")->AsInteger = nsabana_z;
   qry_renentra->ParamByName("numren")->AsInteger = numren_z;
   qry_renentra->ParamByName("cia")->AsInteger = cia_z;
   qry_renentra->Open();
   if(qry_renentra->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Renglón" + IntToStr(numren_z) + " No existe");
   }
   vend_z = qry_renentra->FieldByName("vend")->AsString;

   qry_inven->Close();
   qry_inven->ParamByName("codigo")->AsString = codigo_z;
   qry_inven->ParamByName("cia")->AsInteger = cia_z;
   qry_inven->Open();
   if(qry_inven->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Código " + codigo_z + " No existe");
   }

   qry_movart->Close();
   qry_movart->ParamByName("codigo")->AsString = codigo_z;
   qry_movart->ParamByName("alm")->AsString = alm_z;
   qry_movart->ParamByName("folio")->AsInteger = folio_z;
   qry_movart->ParamByName("cia")->AsInteger = cia_z;
   qry_movart->ParamByName("alment")->AsString = "xx";
   qry_movart->ParamByName("folent")->AsInteger = -1;
   qry_movart->Open();
   // Estan las Validaciones
   if(qry_movart->IsEmpty()) {
     result_z = false;
     errores_z->Add("No Existe el Folio " + IntToStr(folio_z));
   }
   if(fechaabierta_z != "S") {
     if(qry_movart->FieldByName("fecha")->AsDateTime > fecha2_z) {
       result_z = false;
       errores_z->Add("La Fecha de Entrada es Posterior a la de Salida");
     }
   }
   if(qry_movart->FieldByName("salio")->AsString == "S") {
     result_z = false;
     errores_z->Add("El Folio ya no está Disponible");
   }
   if(! result_z) return(result_z);
   // Si no es de Celular tomo el costo del Movart
   if(tiposal_z != "Q") costou_z = qry_movart->FieldByName("costo")->AsFloat;
   // Marco el Folio como Salido .-.-.-.-.-.
   qry_movart->Edit();
   qry_movart->FieldByName("salio")->AsString = "S";
   qry_movart->FieldByName("fechasal")->AsDateTime = fecha2_z;
   if(qry_movart->FieldByName("serie")->AsString.Trim().IsEmpty())
     qry_movart->FieldByName("serie")->AsString = serie_z;
   qry_movart->FieldByName("compro")->AsInteger = idcomprador_z;
   qry_movart->FieldByName("modsal")->AsString = siono_z;
   qry_movart->FieldByName("nsalida")->AsInteger = nsabana_z;
   qry_movart->FieldByName("salepor")->AsInteger = tipoest_z;
   qry_movart->FieldByName("ptvta")->AsString = ptovta_z;
   qry_movart->FieldByName("pueblo")->AsInteger = npoblac_z;
   qry_movart->FieldByName("vahacia")->AsString = ptovta_z;
   qry_movart->FieldByName("vend")->AsString = vend_z;
   qry_movart->Post();

   //.-.-.-.-.-.-.-. Resto la Existencia en Exist .-.-.-._:_:_:_:_
   qry_exist->Close();
   qry_exist->ParamByName("codigo")->AsString = codigo_z;
   qry_exist->ParamByName("almsale")->AsString = alm_z;
   qry_exist->ParamByName("almentra")->AsString = "xxxx";
   qry_exist->ParamByName("cia")->AsInteger = cia_z;
   qry_exist->Open();
   if(qry_exist->IsEmpty()) {
     agrega_exist(codigo_z, alm_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   qry_inven->Edit();
   if(siono_z == "S") {
     if(tiposal_z == "V" || tiposal_z == "Q" || tiposal_z == "H") {
       qry_exist->FieldByName("salvtas")->AsFloat += 1;
       qry_exist->FieldByName("cossalvtas")->AsFloat +=  costou_z;
       qry_inven->FieldByName("salvtas")->AsFloat += 1;
       qry_inven->FieldByName("cossalvtas")->AsFloat +=  costou_z;
     } else if(tiposal_z == "F" || tiposal_z == "1") {
       qry_exist->FieldByName("salfons")->AsFloat += 1;
       qry_exist->FieldByName("cossalfons")->AsFloat += costou_z;
       qry_inven->FieldByName("salfons")->AsFloat += 1;
       qry_inven->FieldByName("cossalfons")->AsFloat += costou_z;
     } else if(tiposal_z == "M") {
       qry_exist->FieldByName("salmays")->AsFloat += 1;
       qry_exist->FieldByName("cossalvtas")->AsFloat += costou_z;
       qry_inven->FieldByName("salmays")->AsFloat += 1;
       qry_inven->FieldByName("cossalvtas")->AsFloat += costou_z;
     } else {
       qry_exist->FieldByName("salesps")->AsFloat += 1;
       qry_exist->FieldByName("cossalesps")->AsFloat += costou_z;
       qry_inven->FieldByName("salesps")->AsFloat += 1;
       qry_inven->FieldByName("cossalesps")->AsFloat += costou_z;
     }
     qry_exist->FieldByName("existes")->AsFloat -= 1;
     qry_exist->FieldByName("cosexistes")->AsFloat -= costou_z;
     qry_inven->FieldByName("existes")->AsFloat -= 1;
     qry_inven->FieldByName("cosexistes")->AsFloat -= costou_z;
   } else {
     if(tiposal_z == "V" || tiposal_z == "Q" || tiposal_z == "H") {
       qry_exist->FieldByName("salvtan")->AsFloat += 1;
       qry_exist->FieldByName("cossalvtan")->AsFloat += costou_z;
       qry_inven->FieldByName("salvtan")->AsFloat += 1;
       qry_inven->FieldByName("cossalvtan")->AsFloat += costou_z;
     } else if(tiposal_z == "F" || tiposal_z == "1") {
       qry_exist->FieldByName("salfonn")->AsFloat += 1;
       qry_exist->FieldByName("cossalfonn")->AsFloat += costou_z;
       qry_inven->FieldByName("salfonn")->AsFloat += 1;
       qry_inven->FieldByName("cossalfonn")->AsFloat += costou_z;
     } else if(tiposal_z == "M") {
       qry_exist->FieldByName("salmayn")->AsFloat += 1;
       qry_exist->FieldByName("cossalvtan")->AsFloat += costou_z;
       qry_inven->FieldByName("salmayn")->AsFloat += 1;
       qry_inven->FieldByName("cossalvtan")->AsFloat += costou_z;
     } else {
       qry_exist->FieldByName("salespn")->AsFloat += 1;
       qry_exist->FieldByName("cossalespn")->AsFloat += costou_z;
       qry_inven->FieldByName("salespn")->AsFloat += 1;
       qry_inven->FieldByName("cossalespn")->AsFloat += costou_z;
     }
     qry_exist->FieldByName("existen")->AsFloat -= 1;
     qry_exist->FieldByName("cosexisten")->AsFloat -= costou_z;
     qry_inven->FieldByName("existen")->AsFloat -= 1;
     qry_inven->FieldByName("cosexisten")->AsFloat -= costou_z;
   }
   qry_exist->Post();
   qry_inven->Post();

   //.-.-.-.-.-.-.-. Agrego las Estadísticas .-.-.-._:_:_:_:_
   afecta_estadis(tipoest_z, codigo_z, ptovta_z, aa_z, mm_z, 1, costou_z);
   qry_renentra->Edit();
   qry_renentra->FieldByName("costou")->AsFloat = costou_z;
   qry_renentra->FieldByName("importe")->AsFloat = costou_z;
   qry_renentra->FieldByName("status")->AsString = "C";
   qry_renentra->Post();
   try {
     dm->manvehi->StartTransaction();
     qry_movart->ApplyUpdates();
     qry_exist->ApplyUpdates();
     qry_inven->ApplyUpdates();
     qry_estadis->ApplyUpdates();
     qry_renentra->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   return (true);
}
//---------------------------------------------------------------------------


void __fastcall TForm_kardex::agrega_exist(String codigo_z, String alm_z, int cia_z)
{

  qry_exist->Append();
  qry_exist->FieldByName("codigo")->AsString = codigo_z;
  qry_exist->FieldByName("alm")->AsString = alm_z;
  qry_exist->FieldByName("inicials")->AsFloat = 0;
  qry_exist->FieldByName("entcoms")->AsFloat = 0;
  qry_exist->FieldByName("entcans")->AsFloat = 0;
  qry_exist->FieldByName("entesps")->AsFloat = 0;
  qry_exist->FieldByName("salvtas")->AsFloat = 0;
  qry_exist->FieldByName("salfons")->AsFloat = 0;
  qry_exist->FieldByName("salesps")->AsFloat = 0;
  qry_exist->FieldByName("entcans")->AsFloat = 0;
  qry_exist->FieldByName("entcans")->AsFloat = 0;
  qry_exist->FieldByName("entcans")->AsFloat = 0;
  qry_exist->FieldByName("entcans")->AsFloat = 0;
  qry_exist->FieldByName("entcans")->AsFloat = 0;
  qry_exist->FieldByName("entcans")->AsFloat = 0;


  qry_exist->FieldByName("salmays")->AsFloat = 0;
  qry_exist->FieldByName("existes")->AsFloat = 0;
  qry_exist->FieldByName("inicialn")->AsFloat = 0;
  qry_exist->FieldByName("entcomn")->AsFloat = 0;
  qry_exist->FieldByName("entcann")->AsFloat = 0;
  qry_exist->FieldByName("entespn")->AsFloat = 0;
  qry_exist->FieldByName("salvtan")->AsFloat = 0;
  qry_exist->FieldByName("salfonn")->AsFloat = 0;
  qry_exist->FieldByName("salespn")->AsFloat = 0;
  qry_exist->FieldByName("salmayn")->AsFloat = 0;
  qry_exist->FieldByName("existen")->AsFloat = 0;
  qry_exist->FieldByName("cosinicials")->AsFloat = 0;
  qry_exist->FieldByName("cosentcoms")->AsFloat = 0;
  qry_exist->FieldByName("cosentcans")->AsFloat = 0;
  qry_exist->FieldByName("cosentesps")->AsFloat = 0;
  qry_exist->FieldByName("cossalvtas")->AsFloat = 0;
  qry_exist->FieldByName("cossalfons")->AsFloat = 0;
  qry_exist->FieldByName("cossalesps")->AsFloat = 0;
  qry_exist->FieldByName("cosexistes")->AsFloat = 0;
  qry_exist->FieldByName("cosinicialn")->AsFloat = 0;
  qry_exist->FieldByName("cosentcomn")->AsFloat = 0;
  qry_exist->FieldByName("cosentcann")->AsFloat = 0;
  qry_exist->FieldByName("cosentespn")->AsFloat = 0;
  qry_exist->FieldByName("cossalvtan")->AsFloat = 0;
  qry_exist->FieldByName("cossalfonn")->AsFloat = 0;
  qry_exist->FieldByName("cossalespn")->AsFloat = 0;
  qry_exist->FieldByName("cossalmayn")->AsFloat = 0;
  qry_exist->FieldByName("cosexisten")->AsFloat = 0;
  qry_exist->FieldByName("ultfol")->AsFloat = 0;
  qry_exist->FieldByName("cia")->AsInteger = cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_kardex::agrega_movart()
{
   qry_movart->Append();

   qry_movart->FieldByName("codigo")->AsString = "";
   qry_movart->FieldByName("almac")->AsString = "";
   qry_movart->FieldByName("folio")->AsInteger = 0;
   qry_movart->FieldByName("prove")->AsString = "";
   qry_movart->FieldByName("compro")->AsInteger = 0;
   qry_movart->FieldByName("facpro")->AsString = "";
   qry_movart->FieldByName("fecha")->AsDateTime = Now();
   qry_movart->FieldByName("costo")->AsFloat = 0;
   qry_movart->FieldByName("sespe")->AsString = "";
   qry_movart->FieldByName("modsal")->AsString = "";
   qry_movart->FieldByName("modent")->AsString = "";
   qry_movart->FieldByName("nentrada")->AsInteger = 0;
   qry_movart->FieldByName("tipo")->AsString = "";
   qry_movart->FieldByName("vienede")->AsString = "";
   qry_movart->FieldByName("folviene")->AsInteger = 0;
   qry_movart->FieldByName("vahacia")->AsString = "";
   qry_movart->FieldByName("folrec")->AsInteger = 0;
   qry_movart->FieldByName("pueblo")->AsInteger = 0;
   qry_movart->FieldByName("numfac")->AsInteger = 0;
   qry_movart->FieldByName("seriefac")->AsString = "";
   qry_movart->FieldByName("salio")->AsString = "";
   qry_movart->FieldByName("smay")->AsString = "";
   qry_movart->FieldByName("fechasal")->AsDateTime = Now();
   qry_movart->FieldByName("canti")->AsInteger = 0;
   qry_movart->FieldByName("serie")->AsString = "";
   qry_movart->FieldByName("salvta")->AsString = "";
   qry_movart->FieldByName("entcan")->AsString = "";
   qry_movart->FieldByName("nsalida")->AsInteger = 0;
   qry_movart->FieldByName("entrapor")->AsInteger = 0;
   qry_movart->FieldByName("salepor")->AsInteger = 0;
   qry_movart->FieldByName("fecentori")->AsDateTime = Now();
   qry_movart->FieldByName("fecvencto")->AsDateTime = Now();
   qry_movart->FieldByName("usuario")->AsString = "";
   qry_movart->FieldByName("cia")->AsInteger = 0;
   qry_movart->FieldByName("ptvta")->AsString = "";
   qry_movart->FieldByName("vend")->AsString = "";

// codigo,almac,folio,prove,nompro,compro,facpro,fecha,costo,
// sespe,modsal,modent,nentrada,tipo,vienede,folviene,vahacia,folrec,
// pueblo,numfac,seriefac,salio,smay,fechasal,canti,serie,salvta,
// entcan,nsalida,entrapor,salepor,fecentori,fecvencto,usuario,cia,
// ptvta,vend
}
//---------------------------------------------------------------------------

bool TForm_kardex::entrada_sabana_cancel(
  String codigo_z,
  String serie_z,
  int folio_z,
  double fecha_z,
  String alm_z,
  String ptovta_z,
  String tiposal_z,
  int idcomprador_z,
  String siono_z,
  int nsabana_z,
  int npoblac_z,
  int numren_z,
  double costou_z,
  String entcan_z,
  String prove_z
)
{
   Word aa_z, mm_z, dd_z;
   int cia_z, tipoest_z;
   TDateTime fecha2_z;
   String msg_z, vend_z;
   bool result_z = true;
   double piva_z;
   errores_z = new TStringList ();

   fecha2_z = fecha_z;
   DecodeDate(fecha2_z, aa_z, mm_z, dd_z);
   tipoest_z = busca_tipo_est(tiposal_z);

   cia_z = dm->cia_z;
//   select tipo, alm, numero, conse, codinv, folsal, folent, costou, importe, piva, status, cia
//   from renentra
//  where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse = :NUMREN and
// cia = :CIA

   qry_renentra->Close();
   qry_renentra->ParamByName("tipo")->AsString = tiposal_z;
   qry_renentra->ParamByName("alm")->AsString = alm_z;
   qry_renentra->ParamByName("numero")->AsInteger = nsabana_z;
   qry_renentra->ParamByName("numren")->AsInteger = numren_z;
   qry_renentra->ParamByName("cia")->AsInteger = cia_z;
   qry_renentra->Open();
   if(qry_renentra->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Renglón" + IntToStr(numren_z) + " No existe");
   }
   vend_z = qry_renentra->FieldByName("vend")->AsString;
   piva_z = qry_renentra->FieldByName("piva")->AsFloat;

   qry_inven->Close();
   qry_inven->ParamByName("codigo")->AsString = codigo_z;
   qry_inven->ParamByName("cia")->AsInteger = cia_z;
   qry_inven->Open();
   if(qry_inven->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Código" + codigo_z + " No existe");
   }

   qry_ultfol->Close();
   qry_ultfol->ParamByName("almrec")->AsString = alm_z;
   qry_ultfol->ParamByName("codigo")->AsString = codigo_z;
   qry_ultfol->ParamByName("cia")->AsInteger = cia_z;
   qry_ultfol->Open();
   if(qry_ultfol->IsEmpty())
     folio_z = 1;
   else
     folio_z = qry_ultfol->FieldByName("ultfol")->AsInteger + 1;
   // -.-.-.-.-.-.-. Ahora genero el Renglón de Entrada .-.-.-.-.-.
   qry_movart->Close();
   qry_movart->ParamByName("codigo")->AsString = codigo_z;
   qry_movart->ParamByName("alm")->AsString = alm_z;
   qry_movart->ParamByName("folio")->AsInteger = folio_z;
   qry_movart->ParamByName("cia")->AsInteger = cia_z;
   qry_movart->ParamByName("alment")->AsString = "xx";
   qry_movart->ParamByName("folent")->AsInteger = -1;
   qry_movart->Open();
   agrega_movart();
   qry_movart->FieldByName("codigo")->AsString = codigo_z;
   qry_movart->FieldByName("almac")->AsString = alm_z;
   qry_movart->FieldByName("folio")->AsInteger = folio_z;
   qry_movart->FieldByName("entrapor")->AsInteger = tipoest_z;
   qry_movart->FieldByName("prove")->AsString = prove_z;
   qry_movart->FieldByName("nompro")->AsString = idcomprador_z;
   qry_movart->FieldByName("facpro")->AsString = "";
   qry_movart->FieldByName("fecha")->AsDateTime = fecha2_z;
   qry_movart->FieldByName("costo")->AsFloat = costou_z;
   qry_movart->FieldByName("modent")->AsString = siono_z;
   qry_movart->FieldByName("nentrada")->AsInteger = nsabana_z;
   qry_movart->FieldByName("tipo")->AsString = "E";
   qry_movart->FieldByName("vienede")->AsString = "";
   qry_movart->FieldByName("folviene")->AsInteger = 0;
   qry_movart->FieldByName("numfac")->AsInteger = 0;
   qry_movart->FieldByName("seriefac")->AsString = "";
   qry_movart->FieldByName("salio")->AsString = "N";
   qry_movart->FieldByName("canti")->AsInteger = 1;
   qry_movart->FieldByName("serie")->AsString = serie_z;
   qry_movart->FieldByName("entcan")->AsString = entcan_z;
   qry_movart->FieldByName("fecentori")->AsDateTime = fecha2_z;
   qry_movart->FieldByName("fecvencto")->AsDateTime = fecha2_z;
   qry_movart->FieldByName("usuario")->AsString = dm->iniciales_z;
   qry_movart->FieldByName("cia")->AsString = cia_z;
   qry_movart->Post();
   //.-.-.-.-.-.-.-. Agrego la Existencia en Exist .-.-.-._:_:_:_:_
   qry_inven->Edit();
   qry_exist->Close();
   qry_exist->ParamByName("codigo")->AsString = codigo_z;
   qry_exist->ParamByName("almentra")->AsString = alm_z;
   qry_exist->ParamByName("almsale")->AsString = "xxxx";
   qry_exist->ParamByName("cia")->AsInteger = cia_z;
   qry_exist->Open();
   // -- Ahora Localizo al Receptor ---- //
   if(qry_exist->IsEmpty()) {
      agrega_exist(codigo_z, alm_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   qry_inven->Edit();
   if(siono_z == "S") {
     if(tiposal_z == "C" || tiposal_z == "Q" || tiposal_z == "H" || tiposal_z == "2") {
       qry_exist->FieldByName("entcans")->AsFloat += 1;
       qry_exist->FieldByName("cosentcans")->AsFloat +=  costou_z;
       qry_inven->FieldByName("entcans")->AsFloat += 1;
       qry_inven->FieldByName("cosentcans")->AsFloat +=  costou_z;
     } else if(tiposal_z == "E") {
       qry_exist->FieldByName("entcoms")->AsFloat += 1;
       qry_exist->FieldByName("cosentcoms")->AsFloat +=  costou_z;
       qry_inven->FieldByName("entcoms")->AsFloat += 1;
       qry_inven->FieldByName("cosentcoms")->AsFloat +=  costou_z;
     } else {
       qry_exist->FieldByName("entesps")->AsFloat += 1;
       qry_exist->FieldByName("cosentesps")->AsFloat += costou_z;
       qry_inven->FieldByName("entesps")->AsFloat += 1;
       qry_inven->FieldByName("cosentesps")->AsFloat += costou_z;
     }
     qry_exist->FieldByName("existes")->AsFloat += 1;
     qry_exist->FieldByName("cosexistes")->AsFloat += costou_z;
     qry_inven->FieldByName("existes")->AsFloat += 1;
     qry_inven->FieldByName("cosexistes")->AsFloat += costou_z;
   } else {
     if(tiposal_z == "C" || tiposal_z == "Q" || tiposal_z == "H" || tiposal_z == "2") {
       qry_exist->FieldByName("entcann")->AsFloat += 1;
       qry_exist->FieldByName("cosentcann")->AsFloat += costou_z;
       qry_inven->FieldByName("entcann")->AsFloat += 1;
       qry_inven->FieldByName("cosentcann")->AsFloat += costou_z;
     } else if(tiposal_z == "E" ) {
       qry_exist->FieldByName("entcomn")->AsFloat += 1;
       qry_exist->FieldByName("cosentcomn")->AsFloat += costou_z;
       qry_inven->FieldByName("entcomn")->AsFloat += 1;
       qry_inven->FieldByName("cosentcomn")->AsFloat += costou_z;
     } else {
       qry_exist->FieldByName("entespn")->AsFloat += 1;
       qry_exist->FieldByName("cosentespn")->AsFloat += costou_z;
       qry_inven->FieldByName("entespn")->AsFloat += 1;
       qry_inven->FieldByName("cosentespn")->AsFloat += costou_z;
     }
     qry_exist->FieldByName("existen")->AsFloat += 1;
     qry_exist->FieldByName("cosexisten")->AsFloat += costou_z;
     qry_inven->FieldByName("existen")->AsFloat += 1;
     qry_inven->FieldByName("cosexisten")->AsFloat += costou_z;
   }
   qry_exist->FieldByName("ultfol")->AsInteger += 1;
   qry_exist->Post();
   qry_inven->Post();
   if(tiposal_z == "E" || tiposal_z == "P" || tiposal_z == "C") {
     qry_invulcos->Close();
     qry_invulcos->ParamByName("codigo")->AsString = codigo_z;
     qry_invulcos->ParamByName("fecha")->AsDateTime = fecha2_z;
     qry_invulcos->ParamByName("cia")->AsInteger = cia_z;
     qry_invulcos->Open();
     if(qry_invulcos->IsEmpty()) {
       qry_invulcos->Append();
       qry_invulcos->FieldByName("codigo")->AsString = codigo_z;
       qry_invulcos->FieldByName("fecha")->AsDateTime = fecha2_z;
       qry_invulcos->FieldByName("cia")->AsInteger = cia_z;
     } else {
       qry_invulcos->Edit();
     }
     qry_invulcos->FieldByName("costos")->AsFloat = costou_z;
     qry_invulcos->FieldByName("coston")->AsFloat = Redondea(costou_z * ( piva_z / 100 +1), 100);
     qry_invulcos->Post();
   }

   //.-.-.-.-.-.-.-. Agrego las Estadísticas .-.-.-._:_:_:_:_
   afecta_estadis(tipoest_z, codigo_z, ptovta_z, aa_z, mm_z, 1, costou_z);
   qry_renentra->Edit();
   qry_renentra->FieldByName("status")->AsString = "C";
   qry_renentra->FieldByName("folent")->AsInteger = folio_z;
   qry_renentra->Post();
   try {
     dm->manvehi->StartTransaction();
     qry_movart->ApplyUpdates();
     qry_exist->ApplyUpdates();
     qry_inven->ApplyUpdates();
     qry_estadis->ApplyUpdates();
     qry_renentra->ApplyUpdates();
     if(qry_invulcos->UpdatesPending) qry_invulcos->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   return (true);
}
//---------------------------------------------------------------------------

bool TForm_kardex::cancela_entrada_sabana_cancel(
  String codigo_z,
  String serie_z,
  int folio_z,
  double fecha_z,
  String alm_z,
  String ptovta_z,
  String tiposal_z,
  int idcomprador_z,
  String siono_z,
  int nsabana_z,
  int npoblac_z,
  int numren_z,
  double costou_z,
  String entcan_z
)
{
   Word aa_z, mm_z, dd_z;
   int cia_z, tipoest_z;
   TDateTime fecha2_z;
   String msg_z, vend_z;
   bool result_z = true;
   errores_z = new TStringList ();

   fecha2_z = fecha_z;
   DecodeDate(fecha2_z, aa_z, mm_z, dd_z);
   tipoest_z = busca_tipo_est(tiposal_z);

   cia_z = dm->cia_z;
//   select tipo, alm, numero, conse, codinv, folsal, folent, costou, importe, piva, status, cia
//   from renentra
//  where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse = :NUMREN and
// cia = :CIA

   qry_renentra->Close();
   qry_renentra->ParamByName("tipo")->AsString = tiposal_z;
   qry_renentra->ParamByName("alm")->AsString = alm_z;
   qry_renentra->ParamByName("numero")->AsInteger = nsabana_z;
   qry_renentra->ParamByName("numren")->AsInteger = numren_z;
   qry_renentra->ParamByName("cia")->AsInteger = cia_z;
   qry_renentra->Open();
   if(qry_renentra->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Renglón" + IntToStr(numren_z) + " No existe");
   }
   vend_z = qry_renentra->FieldByName("vend")->AsString;

   qry_inven->Close();
   qry_inven->ParamByName("codigo")->AsString = codigo_z;
   qry_inven->ParamByName("cia")->AsInteger = cia_z;
   qry_inven->Open();
   if(qry_inven->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Código" + codigo_z + " No existe");
   }
   folio_z = qry_renentra->FieldByName("folent")->AsInteger;
   qry_movart->Close();
   qry_movart->ParamByName("codigo")->AsString = codigo_z;
   qry_movart->ParamByName("alm")->AsString = alm_z;
   qry_movart->ParamByName("folio")->AsInteger = folio_z;
   qry_movart->ParamByName("cia")->AsInteger = cia_z;
   qry_movart->ParamByName("alment")->AsString = "xx";
   qry_movart->ParamByName("folent")->AsInteger = -1;
   qry_movart->Open();
   if(qry_movart->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Movimiento en Movart de: " + codigo_z + " "+ IntToStr(folio_z)+ " No existe");
   }
   qry_movart->Delete();
   //.-.-.-.-.-.-.-. Agrego la Existencia en Exist .-.-.-._:_:_:_:_
   qry_inven->Edit();
   qry_exist->Close();
   qry_exist->ParamByName("codigo")->AsString = codigo_z;
   qry_exist->ParamByName("almentra")->AsString = alm_z;
   qry_exist->ParamByName("almsale")->AsString = "xxxx";
   qry_exist->ParamByName("cia")->AsInteger = cia_z;
   qry_exist->Open();
   // -- Ahora Localizo al Receptor ---- //
   if(qry_exist->IsEmpty()) {
      agrega_exist(codigo_z, alm_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   qry_inven->Edit();
   if(siono_z == "S") {
     if(tiposal_z == "C" || tiposal_z == "Q" || tiposal_z == "H" || tiposal_z == "2") {
       qry_exist->FieldByName("entcans")->AsFloat -= 1;
       qry_exist->FieldByName("cosentcans")->AsFloat -=  costou_z;
       qry_inven->FieldByName("entcans")->AsFloat -= 1;
       qry_inven->FieldByName("cosentcans")->AsFloat -=  costou_z;
     } else if(tiposal_z == "E") {
       qry_exist->FieldByName("entcoms")->AsFloat -= 1;
       qry_exist->FieldByName("cosentcoms")->AsFloat -=  costou_z;
       qry_inven->FieldByName("entcoms")->AsFloat -= 1;
       qry_inven->FieldByName("cosentcoms")->AsFloat -=  costou_z;
     } else {
       qry_exist->FieldByName("entesps")->AsFloat -= 1;
       qry_exist->FieldByName("cosentesps")->AsFloat -= costou_z;
       qry_inven->FieldByName("entesps")->AsFloat -= 1;
       qry_inven->FieldByName("cosentesps")->AsFloat -= costou_z;
     }
     qry_exist->FieldByName("existes")->AsFloat -= 1;
     qry_exist->FieldByName("cosexistes")->AsFloat -= costou_z;
     qry_inven->FieldByName("existes")->AsFloat -= 1;
     qry_inven->FieldByName("cosexistes")->AsFloat -= costou_z;
   } else {
     if(tiposal_z == "V" || tiposal_z == "Q" || tiposal_z == "H" || tiposal_z == "2") {
       qry_exist->FieldByName("entcann")->AsFloat -= 1;
       qry_exist->FieldByName("cosentcann")->AsFloat -= costou_z;
       qry_inven->FieldByName("entcann")->AsFloat -= 1;
       qry_inven->FieldByName("cosentcann")->AsFloat -= costou_z;
     } else if(tiposal_z == "E" ) {
       qry_exist->FieldByName("entcomn")->AsFloat -= 1;
       qry_exist->FieldByName("cosentcomn")->AsFloat -= costou_z;
       qry_inven->FieldByName("entcomn")->AsFloat -= 1;
       qry_inven->FieldByName("cosentcomn")->AsFloat -= costou_z;
     } else {
       qry_exist->FieldByName("entespn")->AsFloat -= 1;
       qry_exist->FieldByName("cosentespn")->AsFloat -= costou_z;
       qry_inven->FieldByName("entespn")->AsFloat -= 1;
       qry_inven->FieldByName("cosentespn")->AsFloat -= costou_z;
     }
     qry_exist->FieldByName("existen")->AsFloat -= 1;
     qry_exist->FieldByName("cosexisten")->AsFloat -= costou_z;
     qry_inven->FieldByName("existen")->AsFloat -= 1;
     qry_inven->FieldByName("cosexisten")->AsFloat -= costou_z;
   }
   qry_exist->FieldByName("ultfol")->AsInteger -= 1;
   qry_exist->Post();
   qry_inven->Post();

   //.-.-.-.-.-.-.-. Agrego las Estadísticas .-.-.-._:_:_:_:_
   afecta_estadis(tipoest_z, codigo_z, ptovta_z, aa_z, mm_z, -1, costou_z * -1);
   qry_renentra->Edit();
   qry_renentra->FieldByName("status")->AsString = "A";
   qry_renentra->FieldByName("folent")->AsInteger = folio_z;
   qry_renentra->Post();
   try {
     dm->manvehi->StartTransaction();
     qry_movart->ApplyUpdates();
     qry_exist->ApplyUpdates();
     qry_inven->ApplyUpdates();
     qry_estadis->ApplyUpdates();
     qry_renentra->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   return (true);
}
//---------------------------------------------------------------------------

bool TForm_kardex::cancela_salida_sabana_vtas(
  String codigo_z,
  String serie_z,
  int folio_z,
  double fecha_z,
  String alm_z,
  String ptovta_z,
  String tiposal_z,
  int idcomprador_z,
  String siono_z,
  int nsabana_z,
  int npoblac_z,
  int numren_z
)
{
   Word aa_z, mm_z, dd_z;
   int cia_z, tipoest_z;
   double costou_z=0;
   TDateTime fecha2_z;
   String msg_z, vend_z;
   bool result_z = true;
   errores_z = new TStringList ();

   fecha2_z = fecha_z;
   DecodeDate(fecha2_z, aa_z, mm_z, dd_z);
   tipoest_z = busca_tipo_est(tiposal_z);

   cia_z = dm->cia_z;
//   select tipo, alm, numero, conse, codinv, folsal, folent, costou, importe, piva, status, cia
//   from renentra
//  where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse = :NUMREN and
// cia = :CIA

   qry_renentra->Close();
   qry_renentra->ParamByName("tipo")->AsString = tiposal_z;
   qry_renentra->ParamByName("alm")->AsString = alm_z;
   qry_renentra->ParamByName("numero")->AsInteger = nsabana_z;
   qry_renentra->ParamByName("numren")->AsInteger = numren_z;
   qry_renentra->ParamByName("cia")->AsInteger = cia_z;
   qry_renentra->Open();
   if(qry_renentra->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Renglón" + IntToStr(numren_z) + " No existe");
   }
   vend_z = qry_renentra->FieldByName("vend")->AsString;

   qry_inven->Close();
   qry_inven->ParamByName("codigo")->AsString = codigo_z;
   qry_inven->ParamByName("cia")->AsInteger = cia_z;
   qry_inven->Open();
   if(qry_inven->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Código " + codigo_z + " No existe");
   }

   qry_movart->Close();
   qry_movart->ParamByName("codigo")->AsString = codigo_z;
   qry_movart->ParamByName("alm")->AsString = alm_z;
   qry_movart->ParamByName("folio")->AsInteger = folio_z;
   qry_movart->ParamByName("cia")->AsInteger = cia_z;
   qry_movart->ParamByName("alment")->AsString = "xx";
   qry_movart->ParamByName("folent")->AsInteger = -1;
   qry_movart->Open();
   // Estan las Validaciones
   if(qry_movart->IsEmpty()) {
     result_z = false;
     errores_z->Add("No Existe el Folio " + IntToStr(folio_z));
   }
   if(qry_movart->FieldByName("salio")->AsString != "S") {
     result_z = false;
     errores_z->Add("El Folio ya no está Disponible");
   }
   if(! result_z) return(result_z);
   // Si no es de Celular tomo el costo del Movart
   if(tiposal_z != "Q") costou_z = qry_movart->FieldByName("costo")->AsFloat;
   // Marco el Folio como Salido .-.-.-.-.-.
   qry_movart->Edit();
   qry_movart->FieldByName("salio")->AsString = "N";
   qry_movart->FieldByName("fechasal")->AsDateTime = NULL;
//   if(qry_movart->FieldByName("serie")->AsString.Trim().IsEmpty())
//     qry_movart->FieldByName("serie")->AsString = serie_z;
   qry_movart->FieldByName("compro")->AsInteger = 0;
   qry_movart->FieldByName("modsal")->AsString = NULL;
   qry_movart->FieldByName("nsalida")->AsInteger = 0;
   qry_movart->FieldByName("salepor")->AsInteger = 0;
   qry_movart->FieldByName("ptvta")->AsString = NULL;
   qry_movart->FieldByName("pueblo")->AsInteger = NULL;
   qry_movart->FieldByName("vahacia")->AsString = NULL;
   qry_movart->FieldByName("vend")->AsString = NULL;
   qry_movart->Post();

   //.-.-.-.-.-.-.-. Resto la Existencia en Exist .-.-.-._:_:_:_:_
   qry_exist->Close();
   qry_exist->ParamByName("codigo")->AsString = codigo_z;
   qry_exist->ParamByName("almsale")->AsString = alm_z;
   qry_exist->ParamByName("almentra")->AsString = "xxxx";
   qry_exist->ParamByName("cia")->AsInteger = cia_z;
   qry_exist->Open();
   if(qry_exist->IsEmpty()) {
     agrega_exist(codigo_z, alm_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   qry_inven->Edit();
   if(siono_z == "S") {
     if(tiposal_z == "V" || tiposal_z == "Q" || tiposal_z == "H") {
       qry_exist->FieldByName("salvtas")->AsFloat -= 1;
       qry_exist->FieldByName("cossalvtas")->AsFloat -=  costou_z;
       qry_inven->FieldByName("salvtas")->AsFloat -= 1;
       qry_inven->FieldByName("cossalvtas")->AsFloat -=  costou_z;
     } else if(tiposal_z == "F" || tiposal_z == "1") {
       qry_exist->FieldByName("salfons")->AsFloat -= 1;
       qry_exist->FieldByName("cossalfons")->AsFloat -= costou_z;
       qry_inven->FieldByName("salfons")->AsFloat -= 1;
       qry_inven->FieldByName("cossalfons")->AsFloat -= costou_z;
     } else if(tiposal_z == "M") {
       qry_exist->FieldByName("salmays")->AsFloat -= 1;
       qry_exist->FieldByName("cossalvtas")->AsFloat -= costou_z;
       qry_inven->FieldByName("salmays")->AsFloat -= 1;
       qry_inven->FieldByName("cossalvtas")->AsFloat -= costou_z;
     } else {
       qry_exist->FieldByName("salesps")->AsFloat -= 1;
       qry_exist->FieldByName("cossalesps")->AsFloat -= costou_z;
       qry_inven->FieldByName("salesps")->AsFloat -= 1;
       qry_inven->FieldByName("cossalesps")->AsFloat -= costou_z;
     }
     qry_exist->FieldByName("existes")->AsFloat += 1;
     qry_exist->FieldByName("cosexistes")->AsFloat += costou_z;
     qry_inven->FieldByName("existes")->AsFloat += 1;
     qry_inven->FieldByName("cosexistes")->AsFloat += costou_z;
   } else {
     if(tiposal_z == "V" || tiposal_z == "Q" || tiposal_z == "H") {
       qry_exist->FieldByName("salvtan")->AsFloat -= 1;
       qry_exist->FieldByName("cossalvtan")->AsFloat -= costou_z;
       qry_inven->FieldByName("salvtan")->AsFloat -= 1;
       qry_inven->FieldByName("cossalvtan")->AsFloat -= costou_z;
     } else if(tiposal_z == "F") {
       qry_exist->FieldByName("salfonn")->AsFloat -= 1;
       qry_exist->FieldByName("cossalfonn")->AsFloat -= costou_z;
       qry_inven->FieldByName("salfonn")->AsFloat -= 1;
       qry_inven->FieldByName("cossalfonn")->AsFloat -= costou_z;
     } else if(tiposal_z == "M") {
       qry_exist->FieldByName("salmayn")->AsFloat -= 1;
       qry_exist->FieldByName("cossalvtan")->AsFloat -= costou_z;
       qry_inven->FieldByName("salmayn")->AsFloat -= 1;
       qry_inven->FieldByName("cossalvtan")->AsFloat -= costou_z;
     } else {
       qry_exist->FieldByName("salespn")->AsFloat -= 1;
       qry_exist->FieldByName("cossalespn")->AsFloat -= costou_z;
       qry_inven->FieldByName("salespn")->AsFloat -= 1;
       qry_inven->FieldByName("cossalespn")->AsFloat -= costou_z;
     }
     qry_exist->FieldByName("existen")->AsFloat += 1;
     qry_exist->FieldByName("cosexisten")->AsFloat += costou_z;
     qry_inven->FieldByName("existen")->AsFloat += 1;
     qry_inven->FieldByName("cosexisten")->AsFloat += costou_z;
   }
   qry_exist->Post();
   qry_inven->Post();

   //.-.-.-.-.-.-.-. Agrego las Estadísticas .-.-.-._:_:_:_:_
   afecta_estadis(tipoest_z, codigo_z, ptovta_z, aa_z, mm_z, -1, costou_z * -1);
   qry_renentra->Edit();
   qry_renentra->FieldByName("costou")->AsFloat = costou_z;
   qry_renentra->FieldByName("importe")->AsFloat = costou_z;
   qry_renentra->FieldByName("status")->AsString = "A";
   qry_renentra->Post();
   try {
     dm->manvehi->StartTransaction();
     qry_movart->ApplyUpdates();
     qry_exist->ApplyUpdates();
     qry_inven->ApplyUpdates();
     qry_estadis->ApplyUpdates();
     qry_renentra->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   return (true);
}
//---------------------------------------------------------------------------

bool TForm_kardex::cancela_afecta_traspasos(String codigo_z, String serie_z,
          int folent_z, int folsal_z, double fecha_z,
          String alm_z, String recemi_z,
          String tiposal_z, int idcomprador_z, int idprovee_z,
          String siono_z, int nsabana_z, int npoblac_z, int numren_z
)
{
   Word aa_z, mm_z, dd_z;
   int cia_z, idnompro_z=0, numfac_z=0, tipoest_z=0;
   double costou_z=0, piva_z=0;
   TDateTime fecha2_z, fecentori_z, vence_z;
   String msg_z, vend_z, facpro_z, entcan_z, prove_z, seriefac_z,
   nompro_z, compro_z;
   TLocateOptions Opts;
   bool result_z = true;
   errores_z = new TStringList ();

   Opts.Clear();
   fecha2_z = fecha_z;
   DecodeDate(fecha2_z, aa_z, mm_z, dd_z);
   tipoest_z = busca_tipo_est(tiposal_z);

   cia_z = dm->cia_z;
//   select tipo, alm, numero, conse, codinv, folsal, folent, costou, importe, piva, status, cia
//   from renentra
//  where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse = :NUMREN and
// cia = :CIA
   qry_almacen->Close();
   qry_almacen->ParamByName("almrec")->AsString = alm_z;
   qry_almacen->ParamByName("almenv")->AsString = recemi_z;
   qry_almacen->ParamByName("cia")->AsInteger = cia_z;
   qry_almacen->Open();
   for(qry_almacen->First(); !qry_almacen->Eof; qry_almacen->Next()) {
     if(qry_almacen->FieldByName("clave")->AsString == alm_z) {
       nompro_z = qry_almacen->FieldByName("nombre")->AsString;
     }
     if(qry_almacen->FieldByName("clave")->AsString == recemi_z) {
       compro_z = qry_almacen->FieldByName("nombre")->AsString;
     }
   }
   idnompro_z = dm->busca_iddato(nompro_z, OLDCONCEPTO);
   idcomprador_z = dm->busca_iddato(compro_z, OLDCONCEPTO);
   qry_renentra->Close();
   qry_renentra->ParamByName("tipo")->AsString = tiposal_z;
   qry_renentra->ParamByName("alm")->AsString = alm_z;
   qry_renentra->ParamByName("numero")->AsInteger = nsabana_z;
   qry_renentra->ParamByName("numren")->AsInteger = numren_z;
   qry_renentra->ParamByName("cia")->AsInteger = cia_z;
   qry_renentra->Open();
   if(qry_renentra->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Renglón" + IntToStr(numren_z) + " No existe");
   }
   folent_z = qry_renentra->FieldByName("folent")->AsInteger;
   folsal_z = qry_renentra->FieldByName("folsal")->AsInteger;
   // Primero genero la Entrada
   qry_movart->Close();
   qry_movart->ParamByName("codigo")->AsString = codigo_z;
   qry_movart->ParamByName("alm")->AsString = alm_z;
   qry_movart->ParamByName("folio")->AsInteger = folsal_z;
   qry_movart->ParamByName("cia")->AsInteger = cia_z;
   qry_movart->ParamByName("alment")->AsString = recemi_z;
   qry_movart->ParamByName("folent")->AsInteger = folent_z;
   qry_movart->Open();
   // Estan las Validaciones
   if(qry_movart->IsEmpty()) {
     result_z = false;
     errores_z->Add("No existe el Folio " + IntToStr(folsal_z));
   }
   //if( qry_movart->FieldByName("fecha")->AsDateTime > fecha2_z) {
   //  result_z = false;
   //  errores_z->Add("La Fecha de Entrada es Posterior a la de Salida");
   //}
   if(qry_movart->FieldByName("salio")->AsString != "S") {
     result_z = false;
     errores_z->Add("El Folio está Disponible");
   }
   if(! result_z) return(result_z);
   // Si no es de Celular tomo el costo del Movart
   // Tomo los datos que necesito del movart que sale
   //if(tiposal_z != "Q") costou_z = qry_movart->FieldByName("costo")->AsFloat;
   // Marco el Folio como Salido .-.-.-.-.-.
   siono_z = qry_movart->FieldByName("modent")->AsString;
   costou_z = qry_movart->FieldByName("costo")->AsFloat;
   fecentori_z = qry_movart->FieldByName("fecentori")->AsDateTime;
   vence_z = qry_movart->FieldByName("fecvencto")->AsDateTime;
   facpro_z = qry_movart->FieldByName("facpro")->AsString;
   entcan_z = qry_movart->FieldByName("entcan")->AsString;
   prove_z = qry_movart->FieldByName("prove")->AsString;
   if (siono_z == "S") {
     qry_inven->Close();
     qry_inven->ParamByName("codigo")->AsString = codigo_z;
     qry_inven->ParamByName("cia")->AsInteger = cia_z;
     qry_inven->Open();
     piva_z = qry_inven->FieldByName("piva")->AsFloat;
   } else {
     piva_z = 0;
   }

   qry_movart->First();
   if(qry_movart->Locate("almac", alm_z, Opts)) {
     qry_movart->Edit();
     qry_movart->FieldByName("salio")->AsString = "N";
     qry_movart->FieldByName("fechasal")->AsDateTime = NULL;
     qry_movart->FieldByName("compro")->AsInteger = 0;
     qry_movart->FieldByName("modsal")->AsString = "";
     qry_movart->FieldByName("nsalida")->AsInteger = 0;
     qry_movart->FieldByName("salepor")->AsInteger = 0;
  //   qry_movart->FieldByName("ptvta")->AsString = ptovta_z;
     qry_movart->FieldByName("pueblo")->AsInteger = 0;
     qry_movart->FieldByName("vahacia")->AsString = "";
     qry_movart->FieldByName("folrec")->AsInteger = 0;
     qry_movart->FieldByName("vend")->AsString = "";
     qry_movart->Post();
  }
  qry_movart->First();
  if(qry_movart->Locate("almac", recemi_z, Opts)) qry_movart->Delete();
   //.-.-.-.-.-.-.-. Resto la Existencia en Exist .-.-.-._:_:_:_:_
   qry_exist->Close();
   qry_exist->ParamByName("codigo")->AsString = codigo_z;
   qry_exist->ParamByName("almsale")->AsString = alm_z;
   qry_exist->ParamByName("almentra")->AsString = recemi_z;
   qry_exist->ParamByName("cia")->AsInteger = cia_z;
   qry_exist->Open();
   qry_exist->First();
   // -- Primero Localizo al Emisor ---- //
   if(!qry_exist->Locate("alm", alm_z, Opts)) {
      agrega_exist(codigo_z, alm_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   if(siono_z == "S") {
     qry_exist->FieldByName("salesps")->AsFloat -=  1;
     qry_exist->FieldByName("cossalesps")->AsFloat -= costou_z;
     qry_exist->FieldByName("existes")->AsFloat += 1;
     qry_exist->FieldByName("cosexistes")->AsFloat += costou_z;
   } else {
     qry_exist->FieldByName("salespn")->AsFloat -= 1;
     qry_exist->FieldByName("cossalespn")->AsFloat -= costou_z;
     qry_exist->FieldByName("existen")->AsFloat += 1;
     qry_exist->FieldByName("cosexisten")->AsFloat += costou_z;
   }
   qry_exist->Post();
   //.-.-.-.-.-.-.-. Sumo la Existencia en Receptor .-.-.-._:_:_:_:_
   qry_exist->First();
   // -- Ahora Localizo al Receptor ---- //
   if(!qry_exist->Locate("alm", recemi_z, Opts)) {
      agrega_exist(codigo_z, recemi_z, cia_z);
   } else {
     qry_exist->Edit();
   }
   if(siono_z == "S") {
     qry_exist->FieldByName("entesps")->AsFloat -= 1;
     qry_exist->FieldByName("cosentesps")->AsFloat -= costou_z;
     qry_exist->FieldByName("existes")->AsFloat -= 1;
     qry_exist->FieldByName("cosexistes")->AsFloat -= costou_z;
   } else {
     qry_exist->FieldByName("entespn")->AsFloat -= 1;
     qry_exist->FieldByName("cosentespn")->AsFloat -= costou_z;
     qry_exist->FieldByName("existen")->AsFloat -= 1;
     qry_exist->FieldByName("cosexisten")->AsFloat -= costou_z;
   }
   qry_exist->FieldByName("ultfol")->AsInteger -= 1;
   qry_exist->Post();
   qry_renentra->Edit();
   qry_renentra->FieldByName("costou")->AsFloat = costou_z;
   qry_renentra->FieldByName("importe")->AsFloat = costou_z;
   qry_renentra->FieldByName("status")->AsString = "A";
   qry_renentra->FieldByName("siono")->AsString = siono_z;
   qry_renentra->FieldByName("folent")->AsInteger = folent_z;
   qry_renentra->Post();
   try {
     dm->manvehi->StartTransaction();
     qry_movart->ApplyUpdates();
     qry_exist->ApplyUpdates();
     qry_renentra->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   return (true);


}
//---------------------------------------------------------------------------

bool TForm_kardex::afecta_estadis(int tipoest_z, String codigo_z, String alm_z, int anu_z, int mes_z, int unids_z, double costou_z)
{
   //.-.-.-.-.-.-.-. Agrego las Estadísticas .-.-.-._:_:_:_:_
   bool todook_z = false;
   int cia_z = 0;
   cia_z = dm->cia_z;
   qry_estadis->Close();
   qry_estadis->ParamByName("tipoest")->AsInteger = tipoest_z;
   qry_estadis->ParamByName("codigo")->AsString = codigo_z;
   qry_estadis->ParamByName("alm")->AsString = alm_z;
   qry_estadis->ParamByName("anu")->AsInteger = anu_z;
   qry_estadis->ParamByName("mes")->AsInteger = mes_z;
   qry_estadis->ParamByName("cia")->AsInteger = cia_z;
   qry_estadis->Open();
   if(qry_estadis->IsEmpty()) {
     qry_estadis->Append();
     qry_estadis->FieldByName("tipo")->AsInteger = tipoest_z;
     qry_estadis->FieldByName("codigo")->AsString = codigo_z;
     qry_estadis->FieldByName("alm")->AsString = alm_z;
     qry_estadis->FieldByName("anu")->AsInteger = anu_z;
     qry_estadis->FieldByName("mes")->AsInteger = mes_z;
     qry_estadis->FieldByName("cia")->AsInteger = cia_z;
   } else {
     qry_estadis->Edit();
   }
   qry_estadis->FieldByName("unidades")->AsInteger = qry_estadis->FieldByName("unidades")->AsInteger + unids_z;
   qry_estadis->FieldByName("importe")->AsFloat = qry_estadis->FieldByName("importe")->AsFloat + costou_z;
   if( qry_estadis->FieldByName("unidades")->AsInteger == 0) {
     qry_estadis->Delete();
   } else {
     qry_estadis->Post();
   }
   todook_z = true;
   return (todook_z);
}
//---------------------------------------------------------------------------

bool TForm_kardex::cambia_punto_venta(
  double fecha_z,
  String nvoptovta_z,
  String alm_z,
  String tiposal_z,
  int nsabana_z,
  int numren_z
)
{
   Word aa_z, mm_z, dd_z;
   int cia_z, tipoest_z, folio_z;
   double costou_z=0;
   TDateTime fecha2_z;
   String msg_z, codigo_z, ptovta_z;
   bool result_z = true;
   errores_z = new TStringList ();

   fecha2_z = fecha_z;
   DecodeDate(fecha2_z, aa_z, mm_z, dd_z);
   tipoest_z = busca_tipo_est(tiposal_z);
   cia_z = dm->cia_z;
//   select tipo, alm, numero, conse, codinv, folsal, folent, costou, importe, piva, status, cia
//   from renentra
//  where tipo = :TIPO and alm = :ALM and numero = :NUMERO and conse = :NUMREN and
// cia = :CIA
   qry_renentra->Close();
   qry_renentra->ParamByName("tipo")->AsString = tiposal_z;
   qry_renentra->ParamByName("alm")->AsString = alm_z;
   qry_renentra->ParamByName("numero")->AsInteger = nsabana_z;
   qry_renentra->ParamByName("numren")->AsInteger = numren_z;
   qry_renentra->ParamByName("cia")->AsInteger = cia_z;
   qry_renentra->Open();
   if(qry_renentra->IsEmpty()) {
     result_z = false;
     errores_z->Add("El Renglón" + IntToStr(numren_z) + " No existe");
   }
   folio_z = qry_renentra->FieldByName("folsal")->AsInteger;
   ptovta_z = qry_renentra->FieldByName("recemi")->AsString;
   codigo_z = qry_renentra->FieldByName("codinv")->AsString;
   qry_movart->Close();
   qry_movart->ParamByName("codigo")->AsString = codigo_z;
   qry_movart->ParamByName("alm")->AsString = alm_z;
   qry_movart->ParamByName("folio")->AsInteger = folio_z;
   qry_movart->ParamByName("cia")->AsInteger = cia_z;
   qry_movart->ParamByName("alment")->AsString = "xx";
   qry_movart->ParamByName("folent")->AsInteger = -1;
   qry_movart->Open();
   // Estan las Validaciones
   if(qry_movart->IsEmpty()) {
     result_z = false;
     errores_z->Add("No Existe el Folio " + IntToStr(folio_z));
   }
   qry_movart->Edit();
   qry_movart->FieldByName("ptvta")->AsString = nvoptovta_z;
   qry_movart->FieldByName("vahacia")->AsString = nvoptovta_z;
   qry_movart->Post();
   qry_renentra->Edit();
   qry_renentra->FieldByName("recemi")->AsString = nvoptovta_z;
   qry_renentra->Post();
   afecta_estadis(tipoest_z, codigo_z, ptovta_z, aa_z, mm_z, -1, costou_z * -1);
   try {
     dm->manvehi->StartTransaction();
     qry_movart->ApplyUpdates();
     qry_estadis->ApplyUpdates();
     qry_renentra->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   afecta_estadis(tipoest_z, codigo_z, nvoptovta_z, aa_z, mm_z, 1, costou_z);
   try {
     dm->manvehi->StartTransaction();
     qry_estadis->ApplyUpdates();
     dm->manvehi->Commit();
   } catch (Exception &E)
   {
     dm->manvehi->Rollback();
     result_z = false;
     Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   return (true);
}

// -----> Para Actualización de Tablas <-------------- //
void __fastcall TForm_kardex::actualiza_tablas()
{
   TIniFile *ini;
   String sql_z, strdir_z, config_z, accion_z, campo_z, sqlstruc_z;
   bool actualizada_z, crear_z;
   config_z = dm->busca_inifile();
   ini = new TIniFile(config_z );
   TQuery *qry_creacampo;
   qry_creacampo = new TQuery(this);
   qry_creacampo->DatabaseName = qry_exist->DatabaseName;

   TStringList* campos_nuevos_z = new TStringList();
   TStringList* tipos_campos_nuevos_z = new TStringList();
   TStringList* valoresxdefault_z= new TStringList();
   TStringList* reginicial_z= new TStringList();

   // --> Checo si existe Sentencia para saber si existe tabla ---
   accion_z = "sentencia_existe_tabla";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     // Seccion donde Creo la Tabla de Fac_facmds --------
     reginicial_z->Clear();
     sql_z = "select * from parambd where tipodb = 'SOLID' and identi = 'EXISTE_TABLA'";
     if(!existe_registro(sql_z)) reginicial_z->Append("insert into parambd ( tipodb, identi, sentencia) values ( 'SOLID', 'EXISTE_TABLA', 'select count(*) as cuantos from TABLES where TABLE_NAME=')");
     sql_z = "select * from parambd where tipodb = 'SOLID3.0' and identi = 'EXISTE_TABLA'";
     if(!existe_registro(sql_z)) reginicial_z->Append("insert into parambd ( tipodb, identi, sentencia) values ( 'SOLID3.0', 'EXISTE_TABLA', 'select count(*) as cuantos from TABLES where TABLE_NAME=')");
     sql_z = "select * from parambd where tipodb = 'INTERBASE' and identi = 'EXISTE_TABLA'";
     if(!existe_registro(sql_z)) reginicial_z->Append("insert into parambd ( tipodb, identi, sentencia) values ( 'INTERBASE', 'EXISTE_TABLA', 'select count(RDB$RELATION_NAME) as cuantos from RDB$RELATIONS where RDB$RELATION_NAME =')");
     sql_z = "select * from parambd where tipodb = 'OTROS' and identi = 'EXISTE_TABLA'";
     if(!existe_registro(sql_z)) reginicial_z->Append("insert into parambd ( tipodb, identi, sentencia) values ( 'OTROS', 'EXISTE_TABLA', 'select count(RDB$RELATION_NAME) as cuantos from RDB$RELATIONS where RDB$RELATION_NAME =')");
     datos_iniciales(reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }


   // -> Checo si existe car_tipocar
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", "crear_tabla_inv_gpomayprecio", false);
   if(!actualizada_z) {
     // Seccion donde Creo la Tabla de Fac_facmds --------
     sqlstruc_z = "create table inv_gpomayprecio( \
       IDGPOMAYPRECIO INTEGER NOT NULL primary key, \
       IDGRUPO INTEGER NOT NULL, \
       FACTORPRECIO DOUBLE PRECISION, \
       FECHA DATE,\
       FECHORA TIMESTAMP,\
       CIA INTEGER,\
       TIPO INTEGER)";
     reginicial_z->Clear();
     crea_tabla("inv_gpomayprecio", sqlstruc_z, reginicial_z);
     // buscar indices y crearlos crea_tabla("FAC_FACMDS_X01","create index fac_facmds_x01 on fac_facmds(fecha)");
     ini->WriteBool( "Actualizacion_tablas", "crear_tabla_inv_gpomayprecio", true);
   }
   reginicial_z->Clear();
   // Creacion Columna tipo en inv_gpomayprecio
   accion_z = "column_inv_gpomayprecio";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("tipo");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add(IntToStr(TIPO_FILIAL));
     actualiza_campos("inv_gpomayprecio", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Clear();
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   reginicial_z->Clear();
   // Creacion Columna tipo en inv_gpomayprecio
   accion_z = "column_mayoris_tipo";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("tipo");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add(IntToStr(TIPO_MAYORISTA));
     actualiza_campos("mayoris", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Clear();
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   // -> Checo si existe car_tipocar
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", "crear_tabla_car_tipocar", false);
   if(!actualizada_z) {
     // Seccion donde Creo la Tabla de Fac_facmds --------
     sqlstruc_z = "create table car_tipocar( \
       idtipocar            integer,\
       tipocar              char(1),\
       descri               varchar(30),\
       orden                integer,\
       cia                  integer)";
     reginicial_z->Clear();
     crea_tabla("CAR_TIPOCAR", sqlstruc_z, reginicial_z);
     // buscar indices y crearlos crea_tabla("FAC_FACMDS_X01","create index fac_facmds_x01 on fac_facmds(fecha)");
     ini->WriteBool( "Actualizacion_tablas", "crear_tabla_car_tipocar", true);
   }
   // -> Checo si existe inv_tipomayoris
   accion_z = "crear_tabla_inv_tipomayoris";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     // Seccion donde Creo la Tabla de Fac_facmds --------
     sqlstruc_z = "create table inv_tipomayoris( \
       idtipomay                integer not null primary key,\
       tipomay                  char(1) not null,\
       descri                   varchar(30),\
       orden                    integer,\
       cia                     integer not null,\
       unique                   (tipomay, cia))";
     reginicial_z->Clear();
     reginicial_z->Append("insert into inv_tipomayoris ( idtipomay, tipomay, descri, orden, cia) values ( 1, 'F', 'FILIAL', 1, 1)");
     reginicial_z->Append("insert into inv_tipomayoris ( idtipomay, tipomay, descri, orden, cia) values ( 2, 'M', 'MAYORISTA', 2, 1)");
     crea_tabla("INV_TIPOMAYORIS", sqlstruc_z, reginicial_z);
     // buscar indices y crearlos crea_tabla("FAC_FACMDS_X01","create index fac_facmds_x01 on fac_facmds(fecha)");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   // Creacion Columnas folentini y folentfin en inv_tpvtatmp
   accion_z = "column_inv_tpvtatmp_folentini_y_folentfin";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("folentini");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add("0");
     campos_nuevos_z->Add("folentfin");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add("0");
     actualiza_campos("inv_tpvtatmp", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Clear();
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   // Creacion Columnas ctocont y ctocred en tabcvta
   accion_z = "column_tbcvta_ctocont_cotcred";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("ctocont");
     tipos_campos_nuevos_z->Add("double precision");
     valoresxdefault_z->Add("0");
     campos_nuevos_z->Add("ctocred");
     tipos_campos_nuevos_z->Add("double precision");
     valoresxdefault_z->Add("0");
     actualiza_campos("tabcvta", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Clear();
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
    // -> Crear Tabla de inf tablas inven de B.D
   accion_z = "crear_info_car_tablas";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     // Seccion donde Creo la Tabla de info_inv_tablas --------
     sqlstruc_z = "create table info_car_tablas( \
       idtabla                integer not null primary key,\
       tabla                  varchar(30),\
       descri                 varchar(100),\
       fecha_crea             date,\
       endesuso               char(1))";
     reginicial_z->Clear();
     crea_tabla("INFO_CAR_TABLAS ", sqlstruc_z, reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------

   // -> Crear Tabla de inf tablas inven de B.D
   accion_z = "crear_info_car_reltabla";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     // Seccion donde Creo la Tabla de info_inv_reltablas --------
     sqlstruc_z = "create table info_car_reltabla( \
       idreltabla             integer not null primary key,\
       idtabla                integer(10),\
       campo                  varchar(30),\
       idtablarel             integer(10),\
       camporel               varchar(30),\
       tiporel                integer(10),\
       descri                 varchar(100),\
       observs                varchar(100))";
     reginicial_z->Clear();
     crea_tabla("INFO_CAR_RELTABLA", sqlstruc_z, reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   reginicial_z->Clear();
   // Creacion Columna ubica en ubivtainv
   accion_z = "column_ubivtainv_ubica";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("ubica");
     tipos_campos_nuevos_z->Add("varchar(4)");
     valoresxdefault_z->Add("pvta");
     actualiza_campos("ubivtainv", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   reginicial_z->Clear();
   // Creacion Columna ubica en ubivtainv
   accion_z = "column_ubivtainv_ubica";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("ubica");
     tipos_campos_nuevos_z->Add("varchar(4)");
     valoresxdefault_z->Add("pvta");
     actualiza_campos("ubivtainv", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   reginicial_z->Clear();
   // Creacion Columna ubica en ubivtainv
   accion_z = "column_inv_relubiptovta";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("zona");
     tipos_campos_nuevos_z->Add("varchar(2)");
     valoresxdefault_z->Add("''");
     actualiza_campos("inv_relubiptovta", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   reginicial_z->Clear();
   // Creacion Columna ubica en ubivtainv
   accion_z = "column_inv_credcon_tipo";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("tipo");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add("1");
     actualiza_campos("inv_credcon", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     reginicial_z->Add("insert into inv_credcon (idcrdcon, descri, tipo) values (3,'EFECTIVO',2)");
     reginicial_z->Add("insert into inv_credcon (idcrdcon, descri, tipo) values (4,'TC TARJETA CRED',2)");
     datos_iniciales(reginicial_z);
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   reginicial_z->Clear();
   // Creacion Columna ubica en ubivtainv
   accion_z = "column_inv_relvtas_tipopago";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("tipopago");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add("3");
     actualiza_campos("inv_relvtas", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------

   reginicial_z->Clear();
   // Creacion tabla_inv_plazoslispre
   accion_z = "tabla_inv_plazoslispre";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_plazoslispre ( \
	idplazo		integer not null primary key, \
	cvepzo		varchar(10) not null, \
	descri		varchar(30), \
	tipolista	integer not null, \
	cia		integer not null, \
	unique (idplazo, cia))";
     reginicial_z->Append("insert into inv_plazoslispre ( idplazo, cvepzo, descri, tipolista, cia) values (11, '1.0', 'Plazo Unico (fijo)', 1, 1)");
     reginicial_z->Append("insert into inv_plazoslispre ( idplazo, cvepzo, descri, tipolista, cia) values (12, '2.0', 'Plazo x Tabla de Precios', 1, 1)");
     reginicial_z->Append("insert into inv_plazoslispre ( idplazo, cvepzo, descri, tipolista, cia) values (13, '3.0', 'Plazo x Grupo', 1, 1)");
     reginicial_z->Append("insert into inv_plazoslispre ( idplazo, cvepzo, descri, tipolista, cia) values (14, '4.0', 'Plazo x Tabla de Precios', 1, 1)");
     reginicial_z->Append("insert into inv_plazoslispre ( idplazo, cvepzo, descri, tipolista, cia) values (15, '3.1', 'Plazo Unico (Fijo)', 2, 1)");
     reginicial_z->Append("insert into inv_plazoslispre ( idplazo, cvepzo, descri, tipolista, cia) values (16, '3.2', 'Plazo x Tablas de Precios', 2, 1)");
     //(PLAZO_X_LINEA)=(1);
     //(PLAZO_X_PRECIO)=(2);
     //(PLAZO_X_ARTICULO)=(3);
     //(PLAZO_LINEA_PRIORIDAD)=(4);
     //(PLAZO_X_GRUPO_PRIORIDAD)=(5);
     //(PLAZO_X_GRUPO)=(6);
     crea_tabla("INV_PLAZOSLISPRE", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   // --> Checo si existe Sentencia para saber si existe tabla ---
   accion_z = "permision_observaciones_negociacion";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   crear_z = false;
   if(!actualizada_z) {
       // Seccion donde Creo la Tabla de Fac_facmds --------
     reginicial_z->Clear();
     sql_z = "select * from car_permisiones where idpermis = " + IntToStr(INV_PERMI_OBSNEG);
     if(!existe_registro(sql_z)) {
        crear_z = true;
        sql_z = "insert into car_permisiones (idpermis, descripcion) values (";
        sql_z  += IntToStr(INV_PERMI_OBSNEG) + ", 'MANTENIMIENTO OBSERVACIONES DE NEGOCIACION DE ARTICULOS')";
         reginicial_z->Append(sql_z);
     }
     sql_z = "select * from fac_permiproyectos where idpermis = " + IntToStr(INV_PERMI_OBSNEG) + " and idproyecto = " + IntToStr(PROYEC_INVENMDS);
     if(!existe_registro(sql_z)) {
        crear_z = true;
        sql_z = "insert into fac_permiproyectos  (idpermiproyecto, idproyecto, idpermis) select ";
        sql_z += "(select max(idpermiproyecto+1) from fac_permiproyectos ) as id, idproyecto, ";
        sql_z += IntToStr(INV_PERMI_OBSNEG);
        sql_z += "from  fac_proyectos where  idproyecto = " + IntToStr(PROYEC_INVENMDS);
        reginicial_z->Append(sql_z);
        datos_iniciales(reginicial_z);
     }
     if(crear_z) datos_iniciales(reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   reginicial_z->Clear();
   // Creacion tabla_inv_megazonas
   accion_z = "tabla_inv_megazonas";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_megazonas ( \
	idmegazona		integer not null primary key, \
	clave		varchar(2) not null, \
	descri		varchar(30), \
	cia		integer not null, \
	unique (clave, cia))";
     reginicial_z->Append("insert into inv_megazonas ( idmegazona, clave, descri, cia) values (1, '01', 'MDS', 1)");
     reginicial_z->Append("insert into inv_megazonas ( idmegazona, clave, descri, cia) values (2, '02', 'SUR', 1)");
     reginicial_z->Append("insert into inv_megazonas ( idmegazona, clave, descri, cia) values (3, '03', 'MAYA', 1)");
     crea_tabla("INV_MEGAZONAS", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   accion_z = "permision_imagenes_inven";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   reginicial_z->Clear();
   crear_z = false;
   if(!actualizada_z) {
       // Seccion donde Creo la Tabla de Fac_facmds --------
     reginicial_z->Clear();
     int PERMI_IMAGENES = 377;
     sql_z = "select * from car_permisiones where clave = 'MANTO_IMAGENES'";
     if(!existe_registro(sql_z)) {
        crear_z = true;
        sql_z = "insert into car_permisiones (idpermis, descripcion, clave) values (";
        sql_z  += IntToStr(PERMI_IMAGENES) + ", 'MANTENIMIENTO IMAGENES DE ARTICULOS', ";
        sql_z  += "'MANTO_IMAGENES')";
         reginicial_z->Append(sql_z);
     }
     sql_z = "select * from fac_permiproyectos where idpermis = " + IntToStr(PERMI_IMAGENES) + " and idproyecto = " + IntToStr(PROYEC_INVENMDS);
     if(!existe_registro(sql_z)) {
        crear_z = true;
        sql_z = "insert into fac_permiproyectos  (idpermiproyecto, idproyecto, idpermis) select ";
        sql_z += "(select max(idpermiproyecto+1) from fac_permiproyectos ) as id, idproyecto, ";
        sql_z += IntToStr(PERMI_IMAGENES);
        sql_z += "from  fac_proyectos where  idproyecto = " + IntToStr(PROYEC_INVENMDS);
        reginicial_z->Append(sql_z);
        datos_iniciales(reginicial_z);
     }
     if(crear_z) datos_iniciales(reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }

   accion_z = "tabla_inv_megazonasdet";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_megazonasdet ( \
	idmegazonadet		integer not null primary key, \
        idmegazona              integer not null, \
	zona		varchar(2) not null, \
	cia		integer not null)";
     reginicial_z->Clear();
     reginicial_z->Append("insert into inv_megazonasdet ( idmegazonadet, idmegazona, zona, cia) values (1, 1, '01', 1)");
     reginicial_z->Append("insert into inv_megazonasdet ( idmegazonadet, idmegazona, zona, cia) values (2, 1, '04', 1)");
     reginicial_z->Append("insert into inv_megazonasdet ( idmegazonadet, idmegazona, zona, cia) values (3, 1, '03', 1)");
     reginicial_z->Append("insert into inv_megazonasdet ( idmegazonadet, idmegazona, zona, cia) values (4, 1, '05', 1)");
     reginicial_z->Append("insert into inv_megazonasdet ( idmegazonadet, idmegazona, zona, cia) values (5, 1, '40', 1)");
     reginicial_z->Append("insert into inv_megazonasdet ( idmegazonadet, idmegazona, zona, cia) values (6, 2, '02', 1)");
     reginicial_z->Append("insert into inv_megazonasdet ( idmegazonadet, idmegazona, zona, cia) values (7, 3, '30', 1)");
     crea_tabla("INV_MEGAZONASDET", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   accion_z = "tabla_inv_sucmegazonas";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_sucmegazonas ( \
	idsucmegazona		   integer not null primary key, \
	idmegazona			   integer not null, \
	zona					   varchar(2), \
	alm					   varchar(4), \
	cia		integer not null)";
     reginicial_z->Clear();
     sql_z = "inv_sucmegazonas ( idsucmegazona, idmegazona, zona, alm, cia) select rownum, \
       c.idmegazona, b.zona, b.clave, a.cia from inv_megazonas a  \
       join inv_megazonasdet c on a.idmegazona = c.idmegazona \
       join almacen b on c.zona = b.zona ";
     reginicial_z->Append(sql_z);
     crea_tabla("INV_SUCMEGAZONAS", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // Creacion Columna tipopago en car_tiposctes
   reginicial_z->Clear();
   accion_z = "column_car_tiposctes_tipopago";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("tipopago");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add("2");
     actualiza_campos("car_tiposctes", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Append("update car_tiposctes set tipopago=1 where ticte = 'CC'");
     reginicial_z->Append("update car_tiposctes set tipopago=1 where ticte = 'RC'");
     reginicial_z->Append("update car_tiposctes set tipopago=1 where ticte = 'AP'");
     reginicial_z->Append("update car_tiposctes set tipopago=4 where ticte = 'TC'");
     datos_iniciales(reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // Creacion Columna status en almacen
   reginicial_z->Clear();
   accion_z = "column_almacen_status";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("status");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'A'");
     actualiza_campos("almacen", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Append("update almacen set status = 'A' where status is null");
     datos_iniciales(reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // Creacion Columna status en ptovta
   reginicial_z->Clear();
   accion_z = "column_ptovta_status";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("status");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'A'");
     actualiza_campos("ptovta", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Append("update ptovta set status = 'A' where status is null");
     datos_iniciales(reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }

   // Creacion Columna exib zona y ordtabt en ptovta
   reginicial_z->Clear();
   accion_z = "column_ptovta_exib_zona_ortabt";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("exib");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'E'");
     campos_nuevos_z->Add("zona");
     tipos_campos_nuevos_z->Add("varchar(2)");
     valoresxdefault_z->Add("'01'");
     campos_nuevos_z->Add("ordtabt");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add("0");
     actualiza_campos("ptovta", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     // buscar indices y crearlos
     reginicial_z->Append("update ptovta set status = 'A' where status is null");
     datos_iniciales(reginicial_z);
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }

  // --> Checo si existe el campo status, fecbaj en car_usuarios --- 27-Sep-2014
   reginicial_z->Clear();
   accion_z = "columna_status_fecbaj_en_car_usuarios";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     tipos_campos_nuevos_z->Clear();
     campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("status");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'A'");
     campos_nuevos_z->Add("fecbaj");
     tipos_campos_nuevos_z->Add("date");
     valoresxdefault_z->Add("NULL");
     actualiza_campos("CAR_USUARIOS", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
  // --> Checo si existe el campo serie en movmay2 --- 27-Sep-2014
   reginicial_z->Clear();
   accion_z = "columna_serie_en_proycom";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     tipos_campos_nuevos_z->Clear();
     campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("porofert");
     tipos_campos_nuevos_z->Add("double precision");
     valoresxdefault_z->Add("88");
     actualiza_campos("PROYCOM", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
     reginicial_z->Append("update proycom set porofert = porcon where porofert is null");
     datos_iniciales(reginicial_z);
   }
  // --> Checo si existe el campo porofert en proycom --- 27-Sep-2014
   reginicial_z->Clear();
   accion_z = "columna_porofert_en_movmay2";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     tipos_campos_nuevos_z->Clear();
     campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("serie");
     tipos_campos_nuevos_z->Add("varchar(5)");
     valoresxdefault_z->Add("''");
     actualiza_campos("MOVMAY2", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
     reginicial_z->Append("update movmay2 set serie = 'MYFA' where coa = 'C' and fecha > '2013-01-01' and tipofac = 1");
     reginicial_z->Append("update movmay2 set serie = 'MYFA' where coa = 'A' and fecha > '2013-01-01' and docto < 2000 and tipofac=1");
     datos_iniciales(reginicial_z);
   }

  // --> Creando la columna de status y fecbaj en vendedores
   reginicial_z->Clear();
   accion_z = "columna_status_fecbaj_en_vendedores";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     tipos_campos_nuevos_z->Clear();
     campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("status");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'A'");
     campos_nuevos_z->Add("fecbaj");
     tipos_campos_nuevos_z->Add("date");
     valoresxdefault_z->Add("NULL");
     actualiza_campos("vendedor", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }

  // --> Creando la columna de status y fecbaj en poblacs
   reginicial_z->Clear();
   accion_z = "columna_status_fecbaj_en_poblacs";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     tipos_campos_nuevos_z->Clear();
     campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("status");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'A'");
     campos_nuevos_z->Add("fecbaj");
     tipos_campos_nuevos_z->Add("date");
     valoresxdefault_z->Add("NULL");
     actualiza_campos("poblacs", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }

   // --> Creando la tabla de catálogos del Sat en Inven
   accion_z = "tabla_inv_catprodsat";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_catprodsat ( \
	idprod		integer not null primary key, \
	codigo		varchar(20), \
	descri		varchar(50), \
	status		char(1), \
	fecbaj		date)";
     reginicial_z->Clear();
     reginicial_z->Append("insert into inv_catprodsat ( idprod, codigo, descri, status) values ( 1, '01010101', 'NO EXISTE EN EL CATALOGO', 'A')");
     crea_tabla("INV_CATPRODSAT", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // --> Creando la tabla de catálogos del Sat en Inven
   accion_z = "tabla_inv_catusocfdisat";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_catusocfdisat ( \
	idusocfdi		integer not null primary key, \
	codigo		varchar(20), \
	descri		varchar(50), \
	status		char(1), \
	fecbaj		date)";
     reginicial_z->Clear();
     reginicial_z->Append("insert into inv_catusocfdisat ( idusocfdi, codigo, descri, status) values ( 1, 'G03', 'GASTOS EN GENERAL', 'A')");
     crea_tabla("INV_CATUSOCFDISAT", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // --> Creando la tabla de catálogos del Sat Régimen
   accion_z = "tabla_inv_regimenfiscal";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_regimenfiscal ( \
	idregimen		integer not null primary key, \
	codigo		varchar(20), \
	descri		varchar(100), \
	status		char(1), \
	fecbaj		date)";
     reginicial_z->Clear();
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 601, '601', 'General de Ley Personas Morales', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 603, '603', 'Personas Morales con Fines no Lucrativos', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 605, '605', 'Sueldos y Salarios e Ingresos Asimilados a Salarios', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 606, '606', 'Arrendamiento', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 607, '607', 'Régimen de Enajenacion o Adquisicion de Bienes', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 608, '608', 'Demás ingresos', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 612, '612', 'Personas Fisicas con Actividades Empresariales y Profesionales', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 616, '616', 'Sin obligaciones fiscales', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 621, '621', 'Incorporacion Fiscal', 'A')");
     reginicial_z->Append("insert into inv_regimenfiscal ( idregimen, codigo, descri, status) values ( 626, '626', 'Regimen Simplificado de Confianza', 'A')");
     crea_tabla("INV_REGIMENFISCAL", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }

   //---------------------------------------------
   // --> Creando la columna de status y fecbaj en poblacs
   reginicial_z->Clear();
   accion_z = "columna_status_fecbaj_idcatprossat_en_inv_grupos";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     tipos_campos_nuevos_z->Clear();
     campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("status");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'A'");
     campos_nuevos_z->Add("fecbaj");
     tipos_campos_nuevos_z->Add("date");
     valoresxdefault_z->Add("NULL");
     campos_nuevos_z->Add("idcatprodsat");
     tipos_campos_nuevos_z->Add("integer");
     valoresxdefault_z->Add("1");
     actualiza_campos("inv_grupos", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //--------------------------------------------- 2018-Jun-25
   // --> Creando la columna de fecffin y tipo en inv_polcampre
   reginicial_z->Clear();
   accion_z = "columna_tipo_fecfin_en_inv_polcampre";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     tipos_campos_nuevos_z->Clear();
     campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     campos_nuevos_z->Add("tipo");
     tipos_campos_nuevos_z->Add("varchar(1)");
     valoresxdefault_z->Add("'P'");
     campos_nuevos_z->Add("fecfin");
     tipos_campos_nuevos_z->Add("date");
     valoresxdefault_z->Add("NULL");
     actualiza_campos("inv_polcampre", campos_nuevos_z, tipos_campos_nuevos_z, valoresxdefault_z, "N");
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // --> Creando la tabla de poliza_Ofertas 2018-Jun-28
   accion_z = "tabla_inv_polofertas";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_polofertas( \
       IDPOLCAMPRE INTEGER NOT NULL, \
       FOLIO INTEGER NOT NULL, \
       FECHA DATE NOT NULL, \
       FECINI DATE NOT NULL, \
       IDUSUARIO INTEGER NOT NULL, \
       STATUS INTEGER NOT NULL, \
       IDCONCEP INTEGER NOT NULL, \
       CIA INTEGER NOT NULL, \
       TIPO VARCHAR(1), \
       FECFIN DATE, \
       PRIMARY KEY (IDPOLCAMPRE), \
       UNIQUE (FOLIO,CIA))";
     reginicial_z->Clear();
     crea_tabla("INV_POLOFERTAS", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   //---------------------------------------------
   // --> Creando la tabla de renglon_poliza_Ofertas 2018-Jun-28
   accion_z = "tabla_inv_renpolofertas";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_renpolofertas( \
       IDRENPOLCAMPRE INTEGER NOT NULL, \
       IDPOLCAMPRE INTEGER NOT NULL, \
       IDART INTEGER NOT NULL, \
       ANTPRMDS DOUBLE PRECISION, \
       ANTPRELEC DOUBLE PRECISION, \
       PRECMDS DOUBLE PRECISION, \
       PRECELEC DOUBLE PRECISION, \
       ANTEMPAQ INTEGER NOT NULL, \
       NVOEMPAQ INTEGER NOT NULL, \
       IDOBSERV INTEGER NOT NULL, \
       PRECIOEXT DOUBLE PRECISION, \
       COSTOEXT DOUBLE PRECISION, \
       IDGARANTIA INTEGER, \
       PRIMARY KEY (IDRENPOLCAMPRE) )";
     reginicial_z->Clear();
     reginicial_z->Append("create index inv_renpolofertas_x01 on inv_renpolofertas(idpolcampre)");
     crea_tabla("INV_RENPOLOFERTAS", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // --> Creando la tabla de renglon_poliza_Ofertas 2018-Jun-28
   accion_z = "tabla_inv_servicios";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_servicios ( \
        idart                       integer not null, \
        codigo                      varchar(14), \
        impservicio                 double precision, \
        tipo                        integer not null, \
        fecha                       date, \
        cia                         integer not null, \
        unique (idart, tipo, cia) )";
     reginicial_z->Clear();
     crea_tabla("inv_servicios", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------
   // --> Creando la tabla de catálogos de Colores para Internet
   accion_z = "tabla_inv_colores";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_colores ( \
	idcolor		integer not null primary key, \
	codigo		varchar(20) not null, \
	descri		varchar(50), \
	status		char(1), \
	fecbaj		date,\
        cia             integer not null, \
        unique (codigo, cia) )";
     reginicial_z->Clear();
     crea_tabla("inv_colores", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   // --> Creando la tabla de Grupos p/Internet
   accion_z = "tabla_inv_gruposinternet";
   actualizada_z =  ini->ReadBool( "Actualizacion_tablas", accion_z, false);
   if(!actualizada_z) {
     campos_nuevos_z->Clear();
     sqlstruc_z = "create table inv_gruposinternet ( \
	idgrupo		integer not null primary key, \
	codigo		varchar(14) not null, \
	descri		varchar(50), \
	impri		char(1), \
	status		char(1), \
	fecbaj		date,\
        idcatprodsat    integer,\
        cia             integer not null, \
        unique (codigo, cia) )";
     reginicial_z->Clear();
     crea_tabla("inv_gruposinternet", sqlstruc_z, reginicial_z);
     tipos_campos_nuevos_z->Clear();
     valoresxdefault_z->Clear();
     // buscar indices y crearlos
     ini->WriteBool( "Actualizacion_tablas", accion_z, true);
   }
   //---------------------------------------------

   delete valoresxdefault_z;
   delete campos_nuevos_z;
   delete tipos_campos_nuevos_z;
   delete reginicial_z;
   delete ini;
}
//---------------------------------------------------------------------------


bool TForm_kardex::existe_tabla(String tabla_z)
{
   TQuery *qry_parametros;
   bool result_z;
   String sql_z;
   qry_parametros = new TQuery(this);
   qry_parametros->DatabaseName = qry_exist->DatabaseName;
   // Seccion donde Creo la Tabla de Fac_tipotercero --------
   sql_z = "select sentencia from mibd a join parambd b on a.mitipodb=b.tipodb where identi = 'EXISTE_TABLA'";
   qry_parametros->Close();
   qry_parametros->SQL->Text = sql_z;
   qry_parametros->Open();
   if(!qry_parametros->IsEmpty()) {
     sql_z = qry_parametros->FieldByName("sentencia")->AsString;
   } else {
     sql_z = "select count(*) as cuantos from TABLES where TABLE_NAME=";
   }
   qry_parametros->Close();
   qry_parametros->SQL->Text = sql_z +" '" + tabla_z.UpperCase() + "'";
   qry_parametros->Open();
   if (!qry_parametros->FieldByName("cuantos")->AsInteger)
     result_z = false;
   else
     result_z = true;
   delete qry_parametros;
   return result_z;
}

void __fastcall TForm_kardex::crea_tabla(String tabla_z, String estructura_z, TStringList *reginicial_z)
{
   TQuery *qry_parametros;
   TQuery *qry_creatabla;
   String insercion_z;

   if(existe_tabla(tabla_z)) return;
   qry_parametros = new TQuery(this);
   qry_creatabla = new TQuery(this);
   qry_creatabla->DatabaseName = qry_exist->DatabaseName;
   qry_parametros->DatabaseName = qry_exist->DatabaseName;
   // Seccion donde Creo la Tabla de Fac_tipotercero --------
   qry_creatabla->Close();
   qry_creatabla->SQL->Text = estructura_z;
   try {
       dm->manvehi->StartTransaction();
       qry_creatabla->ExecSQL();
       dm->manvehi->Commit();
   } catch (Exception &E)  {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   datos_iniciales(reginicial_z);
   delete qry_parametros;
   delete qry_creatabla;
}

void __fastcall TForm_kardex::datos_iniciales(TStringList *reginicial_z)
{
   TQuery *qry_parametros;
   TQuery *qry_creatabla;
   String insercion_z;

   qry_parametros = new TQuery(this);
   qry_creatabla = new TQuery(this);
   qry_creatabla->DatabaseName = qry_exist->DatabaseName;
   qry_parametros->DatabaseName = qry_exist->DatabaseName;
   // Seccion donde Creo la Tabla de Fac_tipotercero --------
   try {
       dm->manvehi->StartTransaction();
       for(int ii_z=0; ii_z < reginicial_z->Count; ii_z++ ) {
         qry_creatabla->Close();
         insercion_z = reginicial_z->Strings[ii_z];
         qry_creatabla->SQL->Text = insercion_z;
         qry_creatabla->ExecSQL();
       }
       dm->manvehi->Commit();
   } catch (Exception &E)  {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
   }
   delete qry_parametros;
   delete qry_creatabla;
}


void __fastcall TForm_kardex::actualiza_campos(String tabla_z,
  TStringList *campos_nuevos_z,
  TStringList *tipos_campos_nuevos_z,
  TStringList *valoresxdefault_z,
  String generador_z
)
{
   TQuery *qry_parametros;
   TQuery *qry_creacampo;
   TQuery *qry_valorxdefault;

   if(!existe_tabla(tabla_z)) return;
   qry_parametros = new TQuery(this);
   qry_creacampo = new TQuery(this);
   qry_valorxdefault = new TQuery(this);
   qry_creacampo->DatabaseName = qry_exist->DatabaseName;
   qry_parametros->DatabaseName = qry_exist->DatabaseName;
   qry_valorxdefault->DatabaseName = qry_exist->DatabaseName;
   String sqlcreacampo_z, sqlvalorxdefault_z, campo_z, creagen_z, dropgen_z;
   TStringList* camposact_z = new TStringList();
   int ii_z, jj_z, idnomisalint_z;
   bool agregar_z;
   creagen_z = "CREATE GENERATOR generador_idaux";
   dropgen_z = "drop GENERATOR generador_idaux";
   // --> Checo si existe el campo idtipotercero ---
   if(dm->tipodb_z == "INTERBASE") {
     qry_parametros->SQL->Text = "select first 0 * from " + tabla_z;
   }
   if(dm->tipodb_z == "SOLID") {
     qry_parametros->SQL->Text = "select * from " + tabla_z + " where rownum < 1";
   }
   qry_parametros->Close();
   qry_parametros->Open();
   //mmo_sql->Lines->Clear();
   for( jj_z = 0; jj_z < qry_parametros->FieldCount; jj_z++) {
      campo_z = qry_parametros->Fields->Fields[jj_z]->FieldName.UpperCase();
      //mmo_sql->Lines->Add(campo_z);
      camposact_z->Add(campo_z);
   }

   for ( ii_z = 0; ii_z < campos_nuevos_z->Count; ii_z++ ) {
      campo_z = campos_nuevos_z->Strings[ii_z].UpperCase();
      jj_z = camposact_z->IndexOf(campo_z);
      if( jj_z == -1) agregar_z = true; else agregar_z = false;
      if ( agregar_z ) {
         sqlcreacampo_z = "alter table " + tabla_z + " add ";
         sqlcreacampo_z += campo_z + " ";
         sqlcreacampo_z += tipos_campos_nuevos_z->Strings[ii_z];
         sqlvalorxdefault_z = "update " + tabla_z + " set ";
         sqlvalorxdefault_z += campos_nuevos_z->Strings[ii_z] + " = ";
         sqlvalorxdefault_z += valoresxdefault_z->Strings[ii_z];
         sqlvalorxdefault_z += " where " + campos_nuevos_z->Strings[ii_z] + " is null";
         qry_creacampo->SQL->Text = sqlcreacampo_z;
         qry_valorxdefault->SQL->Text = sqlvalorxdefault_z;
         try {
             dm->manvehi->StartTransaction();
             qry_creacampo->ExecSQL();
             if(generador_z == "S") {
               qry_creacampo->SQL->Text = creagen_z;
               qry_creacampo->ExecSQL();
             }
             dm->manvehi->Commit();
         } catch (Exception &E)  {
             dm->manvehi->Rollback();
             Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
         }
         try {
             dm->manvehi->StartTransaction();
             qry_valorxdefault->ExecSQL();
             if(generador_z == "S") {
               qry_creacampo->SQL->Text = dropgen_z;
               qry_creacampo->ExecSQL();
             }
             dm->manvehi->Commit();
         } catch (Exception &E)  {
             dm->manvehi->Rollback();
             Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
         }
      }
   }
   delete qry_parametros;
   delete qry_creacampo;
   delete qry_valorxdefault;
   delete camposact_z;
}
//---------------------------------------------------------------------------

bool __fastcall TForm_kardex::existe_registro(String sql_z)
{
   TQuery *qry_comando;
   String insercion_z;
   bool vacio_z;

   qry_comando = new TQuery(this);
   qry_comando->DatabaseName = qry_exist->DatabaseName;
   // Seccion donde Creo la Tabla de Fac_tipotercero --------
   qry_comando->Close();
   qry_comando->SQL->Text = sql_z;
   qry_comando->Open();
   vacio_z = qry_comando->IsEmpty();
   return(!vacio_z);
}


