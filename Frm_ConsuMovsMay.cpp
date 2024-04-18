//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_ConsuMovsMay.h"
#include "dlgCnsMayorista.h"
#include "situaciones.h"
#include "numapal.h"
#include "dmod.h"
#include "RepEdoCtaMayoris.h"
#include "Frm_CapturaObsPed.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
//#pragma link "dxmdaset"
#pragma link "dxTL"
#pragma link "dxDBELib"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "AdvGrid"
#pragma resource "*.dfm"
#include "Frm_hazfacma.h"
#include "stdlib.h"
#include "math.h"

  const int TBS_EDOMAY   = 0;
  const int TBS_FACXMESGLO      = 1;
  const int TBS_PRONOSTICOS     = 0;
  const int TBS_DATOSMAY = 1;
  const int TBS_FACTURAS        = 0;
  const int TBS_PAGOS           = 1;
  const int TBS_PENDPAG         = 2;
  const int TBS_CHARCOMPRAS     = 3;
  const int TBS_CHARCOMPRAPAGO  = 4;
  const int TBS_CHARCOBRANZA    = 5;
  const int TBS_CHARCARTERA     = 6;
  const int TBS_TARJETA         = 7;
  const int TBS_OBSERVSMAY      = 8;

  const int COL_DOCTO           = 0;
  const int COL_PAGARE          = 1;
  const int COL_FECHAFAC        = 2;
  const int COL_VENCIMIENTO     = 3;
  const int COL_CONCEPTO        = 4;
  const int COL_IMPORTE         = 5;
  const int COL_SALDO           = 6;
  const int COL_ACUMULADO       = 7;

TForm_ConsuMovsMay *Form_ConsuMovsMay;
//---------------------------------------------------------------------------
void __fastcall ConsultaMovtosMayoris(TForm *Padre)
{
    try
    {
        Form_ConsuMovsMay = new TForm_ConsuMovsMay(Padre);
        Form_ConsuMovsMay->Show();
    }
    catch(...)
    {
    }

}
//---------------------------------------------------------------------------
__fastcall TForm_ConsuMovsMay::TForm_ConsuMovsMay(TComponent* Owner)
    : TForm(Owner)
{
    edt_anumay->Value = TDateTime::CurrentDate().FormatString("yyyy").ToInt();
    int iDiaIni = 1, iDiaFin = 31, iMesIni = 1, iMesFin = 12;
    int iAnioIni =  FormatDateTime("yyyy", dm->inianuestadis()).ToInt();
    int iAnioFin =  FormatDateTime("yyyy", Now()).ToInt();
    edt_anu->Value = iAnioFin;
    edt_mes->Value = FormatDateTime("mm", Now()).ToInt();
    dtFechaIni = TDateTime(iAnioIni, iMesIni, iDiaIni);
    dtFechaFin = TDateTime(iAnioFin, iMesFin, iDiaFin);
    cia_z = dm->cia_z;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::DesplegarDatos()
{
    //DesplegarEstadoCuenta();

    TLocateOptions Opts;
    Opts.Clear();
    Cierra_Consultas();
    qry_mayoristas->First();
    if(qry_mayoristas->Locate("codigo", qry_edoanu->FieldByName("codigo")->AsString, Opts))
       desp_tarjeta();
    switch (page_movmay->ActivePageIndex) {
      case TBS_FACTURAS         :     DesplegarFacturas();              break;
      case TBS_PENDPAG          :     DesplegarPendientes();            break;
      case TBS_PAGOS            :     DesplegarPagos();                 break;
      case TBS_CHARCOMPRAS      :     DesplegarCharCompras();           break;
      case TBS_CHARCOBRANZA     :     DesplegarCharCompras();           break;
      case TBS_CHARCARTERA      :     DesplegarCharCompras();           break;
      case TBS_OBSERVSMAY       :     DesplegarObserrvs();              break;

    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::desp_tarjeta()
{
   edt_nombre->Text=qry_mayoristas->FieldByName("nombre")->AsString;
   edt_nombre2->Text=qry_mayoristas->FieldByName("nombre2")->AsString;
   edt_ciu->Text=qry_mayoristas->FieldByName("ciu")->AsString;
   edt_direc->Text=qry_mayoristas->FieldByName("direc")->AsString;
   edt_tel->Text=qry_mayoristas->FieldByName("tel")->AsString;
   edt_codvnd->Text=qry_mayoristas->FieldByName("codigo")->AsString;
   edt_rfc->Text=qry_mayoristas->FieldByName("rfc")->AsString;
   edt_pdsc->Text=qry_mayoristas->FieldByName("pdsc")->AsFloat;
   qry_mayrelac->Close();
   qry_mayrelac->ParamByName("mayoris")->AsString = qry_mayoristas->FieldByName("codigo")->AsString;
   qry_mayrelac->ParamByName("cia")->AsInteger = cia_z;
   qry_mayrelac->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::DesplegarEstadoCuenta()
{
    qsMovCli2->Close();
    qsMovCli2->ParamByName("Mayoris" )->AsString   = mayoris_z;
    qsMovCli2->ParamByName("FechaIni")->AsDateTime = dtFechaIni;
    qsMovCli2->ParamByName("FechaFin")->AsDateTime = dtFechaFin;
    qsMovCli2->ParamByName("Cia"     )->AsInteger  = cia_z;
    qsMovCli2->Open();
    bEstado= true;
}
//---------------------------------------------------------------------------
void __fastcall TForm_ConsuMovsMay::DesplegarPendientes()
{
   if ( !qsPendPag->Active ) {
     qsSaldoMes->Tag = NO_REFRESH;
     qsPendPag->Tag = NO_REFRESH;
     qsSaldoMes->DisableControls();
     qsPendPag->DisableControls();
     qsSaldoMes->Close();
     qsSaldoMes->ParamByName("Mayoris" )->AsString  = mayoris_z;
     qsSaldoMes->ParamByName("Cia"     )->AsInteger = cia_z;
     qsSaldoMes->Open();
     qsSaldoMes->First();
     DesplegarPendientesDelMes();
     qsSaldoMes->EnableControls();
     qsPendPag->EnableControls();
     qsSaldoMes->Tag = SI_REFRESH;
     qsPendPag->Tag = SI_REFRESH;
     if (qsPendPag->Active) qsPendPag->Last();
   }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::DesplegarPendientesDelMes()
{
   double acum_z=0;
   String fechax_z;
   TDateTime fecini_z;
   qsPendPag->Close();
   if(qsSaldoMes->IsEmpty()) return;
   fechax_z = qsSaldoMes->FieldByName("fechax")->AsString;
   fecini_z = EncodeDate(
     StrToInt(fechax_z.SubString(1,4)),
     StrToInt(fechax_z.SubString(5,2)), 1
   );
   qsPendPag->DisableControls();
   qsPendPag->Close();
   qsPendPag->ParamByName("Mayoris")->AsString  = mayoris_z;
   qsPendPag->ParamByName("Cia"    )->AsInteger = cia_z;
   qsPendPag->ParamByName("vencini")->AsDateTime = PrimerDiaMes(fecini_z);
   qsPendPag->ParamByName("vencfin")->AsDateTime = UltimoDiaMes(fecini_z);
   qsPendPag->Open();
   for(qsPendPag->First(); !qsPendPag->Eof; qsPendPag->Next()) {
     acum_z += qsPendPag->FieldByName("saldo")->AsFloat;
     qsPendPag->Edit();
     qsPendPag->FieldByName("acum")->AsFloat = acum_z;
     qsPendPag->Post();
   }
   qsPendPag->First();
   qsPendPag->EnableControls();
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::FormClose(TObject *Sender,
      TCloseAction &Action)
{
    String config_z;
    config_z = dm->busca_inifile();
    Action = caFree;
    Form_ConsuMovsMay = NULL;
    dbgrd_acumuanual->SaveToIniFile(config_z);
}
//---------------------------------------------------------------------------



void __fastcall TForm_ConsuMovsMay::mdatMovCli2AfterScroll(
      TDataSet *DataSet)
{
    String tpmov_z;
    double saldo_z;
    saldo_z = qsMovCli2->FieldByName("Saldo")->AsFloat;
    tpmov_z = qsMovCli2->FieldByName("Coa")->AsString;

    if (bEstado) {
      if (tpmov_z == "C" && saldo_z <= 0.1) {
          qsForPago->Close();
          qsForPago->ParamByName("Mayoris")->AsString  = qsMovCli2->FieldByName("Mayoris")->AsString;
          qsForPago->ParamByName("Docto"  )->AsInteger = qsMovCli2->FieldByName("Docto"  )->AsInteger;
          qsForPago->ParamByName("Cia"    )->AsInteger = qsMovCli2->FieldByName("Cia"    )->AsInteger;
          qsForPago->ParamByName("tipofac")->AsInteger = qsMovCli2->FieldByName("tipofac")->AsInteger;
          qsForPago->Open();
      } else qsForPago->Close();
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::btnImpEdoCtaClick(TObject *Sender)
{
    if (!mayoris_z.IsEmpty() ) {
       TqrRepEdoCtaMayoris *qrRepEdoCtaMayoris = new TqrRepEdoCtaMayoris (this);
       ImpRepEdoCtaMayoris(mayoris_z, cia_z);
       delete qrRepEdoCtaMayoris; qrRepEdoCtaMayoris=NULL;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::DesplegarFacturas()
{
    double acum_z = 0;
    String param_z;
    if(!qry_facturas->Active) {
      qry_facxmes->Close();
      for(int jj_z=0; jj_z < qry_facxmes->ParamCount; jj_z++) {
        param_z = qry_facxmes->Params->Items[jj_z]->Name.UpperCase();
        if(param_z == "MAYORIS") qry_facxmes->Params->Items[jj_z]->AsString = mayoris_z;
        if(param_z == "CIA") qry_facxmes->Params->Items[jj_z]->AsInteger = cia_z;
        if(param_z == "FECHAINI") qry_facxmes->Params->Items[jj_z]->AsDateTime = dtFechaIni;
        if(param_z == "FECHAFIN") qry_facxmes->Params->Items[jj_z]->AsDateTime = dtFechaFin;
        if(param_z == "TIPO_NTC_MAY") qry_facxmes->Params->Items[jj_z]->AsInteger = TIPO_NTC_MAY;
      }
      qry_facxmes->Open();
      qry_facturas->Tag = NO_REFRESH;
      qry_facturas->Close();
      qry_facturas->ParamByName("FechaIni")->AsDateTime = dtFechaIni;
      qry_facturas->ParamByName("FechaFin")->AsDateTime = dtFechaFin;
      qry_facturas->ParamByName("Cia"     )->AsInteger  = cia_z;
      qry_facturas->ParamByName("Mayoris" )->AsString   = mayoris_z;
      qry_facturas->Open();
      for ( qry_facturas->First(); !qry_facturas->Eof; qry_facturas->Next() ) {
         acum_z += qry_facturas->FieldByName("total")->AsFloat;
         qry_facturas->Edit();
         qry_facturas->FieldByName("acum")->AsFloat = acum_z;
         qry_facturas->Post();
      }
      qry_facturas->Tag = SI_REFRESH;
      if(qry_facturas->RecordCount == 1) {
        qry_facturasAfterScroll(qry_facturas);
      }
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::qsSaldoMesAfterScroll(
      TDataSet *DataSet)
{
  if( qsSaldoMes->Tag == SI_REFRESH) {
    qsPendPag->Tag = NO_REFRESH;
    qsPendPag->DisableControls();
    DesplegarPendientesDelMes();
    qsPendPag->EnableControls();
    qsPendPag->Tag = SI_REFRESH;
    if(!qsPendPag->IsEmpty()) {
      DespliegaDatosFac(
        qsPendPag->FieldByName("docto")->AsInteger,
        qsPendPag->FieldByName("tipofac")->AsInteger
      );
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::DesplegarPagos()
{
  if ( !qry_abonosxmes->Active) {
    qry_abonosxmes->Tag = NO_REFRESH;
    qry_abonosxmes->Close();
    qry_abonosxmes->ParamByName("Mayoris")->AsString  = mayoris_z;
    qry_abonosxmes->ParamByName("Cia"    )->AsInteger = cia_z;
    qry_abonosxmes->ParamByName("FechaIni")->AsDateTime = dtFechaIni;
    qry_abonosxmes->ParamByName("FechaFin")->AsDateTime = dtFechaFin;
    qry_abonosxmes->Open();
    qry_abonosxmes->Last();
    qry_abonosxmes->Tag = SI_REFRESH;
    Despliega_Abonos();
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::qry_abonosxmesAfterScroll(
      TDataSet *DataSet)
{
  Despliega_Abonos();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::Despliega_Abonos()
{

  String fechax_z, tipodato_z, tipago_z, fectmp_z;
  TDateTime fecini_z=0, fecfin_z=0, fecha_z=0;
  double importe_z=0;
  int aa_z, mm_z, dd_z, folio_z;
  if(qry_abonosxmes->Tag == NO_REFRESH) return;
  if(qry_abonosxmes->IsEmpty()) return;
  TLocateOptions Opts;
  Opts.Clear();
  fechax_z = qry_abonosxmes->FieldByName("fechax")->AsString;
  fecini_z = TDateTime(StrToInt(fechax_z.SubString(1,4)), StrToInt(fechax_z.SubString(5,2)), 1);
  fecfin_z = UltimoDiaMes(fecini_z);
  qry_aboxtipo->Tag = NO_REFRESH;
  qry_aboxtipo->Close();
  qry_aboxtipo->ParamByName("mayoris")->AsString = mayoris_z;
  qry_aboxtipo->ParamByName("cia")->AsInteger = cia_z;
  qry_aboxtipo->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_aboxtipo->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_aboxtipo->Open();
  qry_abonomesxtipo->Close();
  qry_abonomesxtipo->ParamByName("mayoris")->AsString = mayoris_z;
  qry_abonomesxtipo->ParamByName("cia")->AsInteger = cia_z;
  qry_abonomesxtipo->ParamByName("fecini")->AsDateTime = fecini_z;
  qry_abonomesxtipo->ParamByName("fecfin")->AsDateTime = fecfin_z;
  qry_abonomesxtipo->Open();
  for(qry_abonomesxtipo->First(); !qry_abonomesxtipo->Eof; qry_abonomesxtipo->Next()) {
    qry_aboxtipo->First();
    fecha_z = qry_abonomesxtipo->FieldByName("fecha")->AsDateTime;
    fectmp_z = FormatDateTime("yyyymmdd", fecha_z);
    folio_z = qry_abonomesxtipo->FieldByName("folio")->AsInteger;
    importe_z = qry_abonomesxtipo->FieldByName("imp")->AsFloat;
    tipodato_z = qry_abonomesxtipo->FieldByName("tipcompra")->AsString;
    tipago_z = qry_abonomesxtipo->FieldByName("tipago")->AsString;
    //if(fectmp_z == "20090414") {
    //  GroupBox8->Caption = tipago_z + " " + FormatFloat("###,##0.00", importe_z) + " Folio:" + IntToStr(folio_z);
    //}

    if(qry_aboxtipo->Locate("folio", folio_z, Opts)) {
      qry_aboxtipo->Edit();
      if(tipago_z == "D")
        qry_aboxtipo->FieldByName("dev")->AsFloat += importe_z;
      else if(tipago_z == "B")
        qry_aboxtipo->FieldByName("bon")->AsFloat += importe_z;
      else if(tipago_z == "N")
        qry_aboxtipo->FieldByName("bon")->AsFloat += importe_z;
      else if(tipodato_z == "O")
        qry_aboxtipo->FieldByName("mora")->AsFloat += importe_z;
      else if(tipago_z == "I")
        qry_aboxtipo->FieldByName("interes")->AsFloat += importe_z;
      else
        qry_aboxtipo->FieldByName("merc")->AsFloat += importe_z;
      qry_aboxtipo->Post();
    }
  }
  importe_z = 0;
  for(qry_aboxtipo->First(); !qry_aboxtipo->Eof; qry_aboxtipo->Next()) {
    importe_z += qry_aboxtipo->FieldByName("total")->AsFloat;
    qry_aboxtipo->Edit();
    qry_aboxtipo->FieldByName("acum")->AsFloat = importe_z;
    qry_aboxtipo->Post();
  }
  qry_aboxtipo->Tag = SI_REFRESH;
  Despliega_AbonosxDia();
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::FormCreate(TObject *Sender)
{
   String group_z, sqlpendpag_z, sqlabonos_z, sqlfacs_z, sqlvigpagglob_z,
   sqlanucmp_z, sqlgrpcomp_z, sqlvigpagglob2_z, sqlfacxmesglo_z;
   TIniFile *ini;
   char direc_z[200];
   String  basedato_z, config_z, strdir_z, tipoimp_z;
   config_z = dm->busca_inifile();
   bool max_z, usrmanto_z;
   ini = new TIniFile(config_z);
   mesesatras_z =  ini->ReadInteger( "MAYOREO", "Meses_Atras_ComprasPagos", 16 );
   mesesatras_z = (mesesatras_z -1 ) * -1;
   date_fecedomay->Date = UltimoDiaMes(IncMonth(dm->ahora(), -1));
   delete ini;
   if (dm->tipodb_z == "SOLID") {
       group_z = " group by fechax";
       sqlgrpcomp_z = " group by mayoris, anu, mes";

   } else if (dm->tipodb_z == "INTERBASE") {
       group_z = " group by 1";
       sqlgrpcomp_z = " group by mayoris, 2, 3";
   }

    sqlpendpag_z = "select cast( extract(YEAR  from vence) * 100 + extract(month from vence) as varchar(6) ) as fechax,";
    sqlpendpag_z += "  sum(saldo) as SALDO";
    sqlpendpag_z += " from movmay2 where mayoris = :Mayoris and saldo > 0.05 and coa = 'C' and cia = :Cia";
    sqlpendpag_z += group_z;

    sqlvigpagglob2_z = "select vence as fechax,";
    sqlvigpagglob2_z += "  sum(saldo) as SALDO";
    sqlvigpagglob2_z += " from movmay2 where saldo > 0.05 and coa = 'C' and cia = :Cia";
    sqlvigpagglob2_z += group_z;

    sqlvigpagglob_z = "select cast( extract(YEAR  from vence) * 100 + extract(month from vence) as varchar(6) ) as fechax,";
    sqlvigpagglob_z += "  sum(saldo) as SALDO";
    sqlvigpagglob_z += " from movmay2 where saldo > 0.05 and coa = 'C' and cia = :Cia";
    sqlvigpagglob_z += group_z;

    sqlabonos_z = "select cast( extract(YEAR  from fecha) * 100 + extract(month from fecha) as varchar(6) ) as fechax,";
    sqlabonos_z += "  sum(importe) as importe";
    sqlabonos_z += " from movmay2 where mayoris = :Mayoris and fecha between :FECHAINI and :FECHAFIN and coa = 'A' and cia = :Cia";
    sqlabonos_z += group_z;

    sqlfacs_z = "select cast( extract(YEAR  from fecha) * 100 + extract(month from fecha) as varchar(6) ) as fechax,";
    sqlfacs_z += "  sum(total) as total";
    sqlfacs_z += " from facturma where mayoris = :Mayoris and fecha between :FECHAINI and :FECHAFIN and cia = :Cia and mayomen = 'Y' and tipofac <> :TIPO_NTC_MAY";
    sqlfacs_z += group_z;

    sqlfacxmesglo_z = "select cast( extract(YEAR  from fecha) * 100 + extract(month from fecha) as varchar(6) ) as fechax,";
    sqlfacxmesglo_z += " sum ( case coa when 'C' then importe else 0 end ) as cargos, ";
    sqlfacxmesglo_z += " sum ( case coa when 'A' then importe else 0 end ) as abonos ";
    sqlfacxmesglo_z += " from movmay2 where fecha between :FECHAINI and :FECHAFIN and cia = :CIA ";
    sqlfacxmesglo_z += group_z;

    sqlanucmp_z = "select mayoris, cast ( extract(YEAR  from fecha) as integer) as anu, ";
    sqlanucmp_z += "cast ( extract(MONTH from fecha) as integer) as mes, ";
    sqlanucmp_z += "sum ( case coa when 'C' then importe else 0 end ) as cargos, ";
    sqlanucmp_z += "sum ( case coa when 'A' then importe else 0 end ) as abonos ";
    sqlanucmp_z += " from movmay2 where mayoris = :MAYORIS and fecha between :FECHAINI and :FECHAFIN and cia = :CIA ";
    sqlanucmp_z += sqlgrpcomp_z;
    dbgrd_acumuanual->LoadFromIniFile(config_z);


    qsSaldoMes->Tag = NO_REFRESH;
    qsSaldoMes->Close();
    qsSaldoMes->SQL->Clear();
    qsSaldoMes->SQL->Add(sqlpendpag_z);
    qry_abonosxmes->Close();
    qry_abonosxmes->SQL->Clear();
    qry_abonosxmes->SQL->Add(sqlabonos_z);
    qry_facxmes->Close();
    qry_facxmes->SQL->Clear();
    qry_facxmes->SQL->Add(sqlfacs_z);

    qry_facxmesglo->Close();
    qry_facxmesglo->SQL->Clear();
    qry_facxmesglo->SQL->Add(sqlfacxmesglo_z);

    qry_pendpagglob->SQL->Clear();
    qry_pendpagglob->SQL->Add(sqlvigpagglob_z);
    qry_compraspagosxmes->Close();
    qry_compraspagosxmes->SQL->Clear();
    qry_compraspagosxmes->SQL->Add(sqlanucmp_z);
    //dbgrd_analipend->EndSorting = RecalcularAcumulados;
    DespliegaPronosticos();
    DespliegaPronostMensual();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::qry_facxmesAfterScroll(
      TDataSet *DataSet)
{
  double acum_z = 0;
  qry_facturas->Tag = NO_REFRESH;
  qry_facturas->Filter = "FECH = '" + qry_facxmes->FieldByName("fechax")->AsString +"'";
  qry_facturas->Filtered = true;
  if (qry_facturas->Active) {
    for ( qry_facturas->First(); !qry_facturas->Eof; qry_facturas->Next() ) {
       acum_z += qry_facturas->FieldByName("total")->AsFloat;
       qry_facturas->Edit();
       qry_facturas->FieldByName("acum")->AsFloat = acum_z;
       qry_facturas->Post();
    }
  }
  qry_facturas->Tag = SI_REFRESH;
  if(qry_facturas->Active) qry_facturas->First();
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::qry_facturasAfterScroll(
      TDataSet *DataSet)
{
  if(qry_facturas->Tag == NO_REFRESH) return;
  DespliegaDatosFac(
    qry_facturas->FieldByName("num"    )->AsInteger,
    qry_facturas->FieldByName("tipofac")->AsInteger
  );
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::page_movmayChange(TObject *Sender)
{
  int npage_z = page_movmay->ActivePageIndex;
    switch (npage_z) {
      case TBS_FACTURAS      :     DesplegarFacturas();   break;
      case TBS_PENDPAG       :     DesplegarPendientes(); break;
      case TBS_PAGOS         :     DesplegarPagos();      break;
      case TBS_OBSERVSMAY    :     DesplegarObserrvs();   break;
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::DespliegaPronosticos()
{
    int ii_z = 0, perio1_z, perio0_z, mes_z=0, perio_z, dias_z;
    double saldotot_z=0, saldo_z=0, atras1_z=0, atras2_z=0, impant_z=0;
    TDateTime vence_z, fechoy_z;
    String titulo_z, stranu_z, strimpant_z, fecfinanuant_z,
      sqlvigpagglob2_z, group_z;
    TLocateOptions Opts;
    Opts.Clear();
    fechoy_z = dm->ahora();
    fecfinanuant_z = dtFechaIni - 1;
    perio1_z = StrToInt (FormatDateTime("yyyymm", IncMonth(fechoy_z, -2)));
    perio0_z = StrToInt (FormatDateTime("yyyymm", IncMonth(fechoy_z, -1)));
    qry_edoanu->Tag = NO_REFRESH;
    qry_edoanu->Close();
    qry_edoanu->ParamByName("Cia"    )->AsInteger = cia_z;
    qry_edoanu->ParamByName("FechaIni")->AsDateTime = dtFechaIni;
    qry_edoanu->ParamByName("FechaFin")->AsDateTime = dtFechaFin;
    qry_edoanu->Open();
    for(qry_edoanu->First(); !qry_edoanu->Eof; qry_edoanu->Next())  {
      qry_edoanu->Edit();
      qry_edoanu->FieldByName("sdoini")->AsFloat =
        qry_edoanu->FieldByName("saldo")->AsFloat -
        qry_edoanu->FieldByName("neto")->AsFloat;
      qry_edoanu->Post();
    }
    qry_edoanuant->Close();
    qry_edoanuant->ParamByName("FECHAFINANUANT")->AsDateTime = fecfinanuant_z;
    qry_edoanuant->ParamByName("cia")->AsInteger = cia_z;
    qry_edoanuant->Open();
    for (qry_edoanuant->First(); !qry_edoanuant->Eof; qry_edoanuant->Next()) {
      qry_edoanu->First();
      if(!qry_edoanu->Locate("codigo", qry_edoanuant->FieldByName("mayoris")->AsString, Opts)) {
        qry_edoanu->Append();
        qry_edoanu->FieldByName("codigo")->AsString = qry_edoanuant->FieldByName("mayoris")->AsString;
        qry_edoanu->FieldByName("descri")->AsString = qry_edoanuant->FieldByName("descri")->AsString;
        qry_edoanu->FieldByName("nombre")->AsString = qry_edoanuant->FieldByName("nombre")->AsString;
        qry_edoanu->FieldByName("sdoini")->AsFloat = qry_edoanuant->FieldByName("sdofin")->AsFloat;
        qry_edoanu->FieldByName("saldo")->AsFloat = qry_edoanuant->FieldByName("sdofin")->AsFloat;
        qry_edoanu->Append();
      }
    }
    qry_edoanu2->Close();
    qry_edoanu2->ParamByName("Cia"    )->AsInteger = -1;
    qry_edoanu2->ParamByName("FechaIni")->AsDateTime = dtFechaIni;
    qry_edoanu2->ParamByName("FechaFin")->AsDateTime = dtFechaFin;
    qry_edoanu2->Open();
    qry_edoanu2->DisableControls();
    for(qry_edoanu->First(); !qry_edoanu->Eof; qry_edoanu->Next()) {
      saldo_z = qry_edoanu->FieldByName("saldo")->AsFloat;
      if(saldo_z > 1) {
        qry_edoanu2->Append();
        for(int jj_z=0; jj_z < qry_edoanu->FieldCount; jj_z++)
          qry_edoanu2->Fields->Fields[jj_z]->Value = qry_edoanu->Fields->Fields[jj_z]->Value;
        qry_edoanu2->Post();
      }
    }
    qry_edoanu2->EnableControls();
    qry_edoanu->Tag = SI_REFRESH;
    dbgrd_acumuanual->FullExpand();
    titulo_z = qry_pendpagglob->SQL->Text;

    qry_pendpagglob->Close();
    qry_pendpagglob->ParamByName("cia")->AsInteger = cia_z;
    qry_pendpagglob->Open();
    TQuery *qry_pendpagglob2 = new TQuery(this);
    qry_pendpagglob2->DatabaseName = qry_pendpagglob->DatabaseName;
    if (dm->tipodb_z == "SOLID") {
       group_z = " group by fechax";
    } else if (dm->tipodb_z == "INTERBASE") {
       group_z = " group by 1";
    }

    sqlvigpagglob2_z = "select vence as fechax,";
    sqlvigpagglob2_z += "  sum(saldo) as SALDO";
    sqlvigpagglob2_z += " from movmay2 where saldo > 0.05 and coa = 'C' and cia = :Cia";
    sqlvigpagglob2_z += group_z;
    qry_pendpagglob2->SQL->Text = sqlvigpagglob2_z;

    qry_pendpagglob2->Close();
    qry_pendpagglob2->ParamByName("cia")->AsInteger = cia_z;
    qry_pendpagglob2->Open();
    sgrd_pendpag->RowCount = 2;
    sgrd_pendpag->ColCount = 2;
    sgrd_pendpag->ColumnHeaders->Clear();
    sgrd_pendpag->ColumnHeaders->Add("Venc > 30");
    sgrd_pendpag->ColumnHeaders->Add("Venc 1 - 30");
    ii_z = 0;
    bar_vencglo->Clear();
    bar_vencglo->Title = "Vencimientos";
    bar_vencglo->Add(atras1_z, "V.>30", clTeeColor);
    bar_vencglo->Add(atras2_z, "V.1-30", clTeeColor);
    for(qry_pendpagglob2->First(); !qry_pendpagglob2->Eof; qry_pendpagglob2->Next()) {
      vence_z = qry_pendpagglob2->FieldByName("fechax")->AsDateTime;
      titulo_z = FormatDateTime("yyyymm", vence_z);
      perio_z = StrToInt( FormatDateTime("yyyymm", vence_z));
      saldo_z = qry_pendpagglob2->FieldByName("saldo")->AsFloat;
      if(perio_z <= perio0_z) {
        dias_z = fechoy_z - vence_z;
        if(dias_z > 30 ) {
          saldotot_z += saldo_z;
          atras1_z += saldo_z; saldo_z = atras1_z; ii_z = 0;
        } else {
          saldotot_z += saldo_z;
          atras2_z += saldo_z; saldo_z = atras2_z; ii_z = 1;
        }
      }
    }
    delete qry_pendpagglob2;
    sgrd_pendpag->Cells[0][1]= FormatFloat("$#,###,##0.00", atras1_z);
    sgrd_pendpag->Cells[1][1]= FormatFloat("$#,###,##0.00", atras2_z);
    bar_vencglo->Clear();
    bar_vencglo->Title = "Vencimientos";
    bar_vencglo->Add(atras1_z, "V.>30", clTeeColor);
    bar_vencglo->Add(atras2_z, "V.1-30", clTeeColor);

    for(qry_pendpagglob->First(); !qry_pendpagglob->Eof; qry_pendpagglob->Next()) {
      //vence_z = qry_pendpagglob->FieldByName("fechax")->AsDateTime;
      titulo_z = qry_pendpagglob->FieldByName("fechax")->AsString;
//      perio_z = StrToInt( FormatDateTime("yyyymm", vence_z));
      perio_z = titulo_z.ToIntDef(0);
      saldo_z = qry_pendpagglob->FieldByName("saldo")->AsFloat;
      if(perio_z > perio0_z) {
        mes_z = StrToInt(titulo_z.SubString(5,2));
        stranu_z = titulo_z.SubString(1,4);
        titulo_z = nommes(mes_z) + "/" + titulo_z.SubString(1,4);
        saldotot_z += saldo_z;
        ii_z = sgrd_pendpag->ColumnHeaders->IndexOf(titulo_z);
        if(ii_z == -1) {
          sgrd_pendpag->ColumnHeaders->Add(titulo_z);
          ii_z = sgrd_pendpag->ColumnHeaders->IndexOf(titulo_z);
          sgrd_pendpag->ColCount++;
          bar_vencglo->Add(saldo_z, titulo_z, clTeeColor);
        }
        strimpant_z = sgrd_pendpag->Cells[ii_z][1];
        strimpant_z = StrReplace(strimpant_z, "$", "");
        strimpant_z = StrReplace(strimpant_z, ",", "");
        impant_z = atof(strimpant_z.c_str());
        sgrd_pendpag->Cells[ii_z][1]= FormatFloat("$#,###,##0.00", saldo_z + impant_z);
        titulo_z = qry_pendpagglob->FieldByName("fechax")->AsString;
        titulo_z = nommes(mes_z).SubString(1,3) + "/" + titulo_z.SubString(3,2);
      }
    }
    sgrd_pendpag->ColCount++;
    ii_z = sgrd_pendpag->ColCount - 1;
    sgrd_pendpag->ColumnHeaders->Add("Total");
    sgrd_pendpag->Cells[ii_z][1]= FormatFloat("$#,###,##0.00", saldotot_z);
    sgrd_pendpag->DefaultColWidth = (Width - 2) / sgrd_pendpag->ColCount;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::lkcmb_mayorisKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if( Key == VK_RETURN) desp_datos_mayExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::dbgrd_pronostmensCustomDraw(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxDBTreeListColumn *AColumn, const AnsiString AText, TFont *AFont,
      TColor &AColor, bool ASelected, bool AFocused, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::edt_anuKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if (Key == VK_RETURN) DespliegaPronostMensual();
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::DespliegaPronostMensual()
{
    int anu_z, mes_z, ii_z=0;
    TDateTime fechafin_z, fechaini_z, fechanter_z, fecha_z;
    String mimay_z;
    TLocateOptions Opts;
    double pagos_z=0, porpag_z=0, antvenc_z, porvenc_z, nvovenc_z,
    exigible_z=0, abonos_z=0, abonoesp_z=0;
    chart_pronosticos->Title->Text->Text = "Analisis de Pagos Mayoristas";
    Series1->Clear();
    Series2->Clear();
    Series3->Clear();
    Series1->Title = "Exigible";
    Series2->Title = "Esperado";
    Series3->Title = "Abonos";

    anu_z = edt_anu->Value;
    mes_z = edt_mes->Value;
    edt_mesmay->Value = mes_z;
    fecha_z = TDateTime(anu_z, mes_z, 1);
    fechaini_z = PrimerDiaMes(fecha_z);
    fechafin_z = UltimoDiaMes(fecha_z);
    fechanter_z = UltimoDiaMes(IncMonth(fechafin_z, -1));
    qry_pronost->Close();
    qry_pronost->ParamByName("Cia"    )->AsInteger = cia_z;
    qry_pronost->ParamByName("FechaIni")->AsDateTime = fechaini_z;
    qry_pronost->ParamByName("FechaFin")->AsDateTime = fechafin_z;
    qry_pronost->Open();
    qry_pronost->DisableControls();
    qry_mayoristas->Close();
    qry_mayoristas->ParamByName("Cia"    )->AsInteger = cia_z;
    qry_mayoristas->Open();
    for(qry_mayoristas->First(); !qry_mayoristas->Eof; qry_mayoristas->Next()) {
      mimay_z = qry_mayoristas->FieldByName("codigo")->AsString;
      qry_vencs->Close();
      qry_vencs->ParamByName("mayoris")->AsString = mimay_z;
      qry_vencs->ParamByName("fecha")->AsDateTime = fechanter_z;
      qry_vencs->ParamByName("cia")->AsInteger = cia_z;
      qry_vencs->Open();
      if(!qry_vencs->IsEmpty()) {
        antvenc_z = qry_vencs->FieldByName("vencant")->AsFloat;
        nvovenc_z = qry_vencs->FieldByName("vencrec")->AsFloat;
        porvenc_z = qry_vencs->FieldByName("porvenc")->AsFloat;
        ii_z++;
        qry_pronost->First();
        if(qry_pronost->Locate("mayoris", mimay_z, Opts)) {
          qry_pronost->Edit();
        } else {
          qry_pronost->Append();
          qry_pronost->FieldByName("mayoris")->AsString = mimay_z;
        }
        qry_pronost->FieldByName("antvenc")->AsFloat = antvenc_z;
        qry_pronost->FieldByName("nvovenc")->AsFloat = nvovenc_z;
        qry_pronost->FieldByName("porvenc")->AsFloat = porvenc_z;
        qry_pronost->FieldByName("venctot")->AsFloat = antvenc_z + nvovenc_z;
        qry_pronost->FieldByName("pagoantven")->AsFloat = antvenc_z / 10;
        qry_pronost->FieldByName("pagonvoven")->AsFloat = porvenc_z * .67;
        qry_pronost->FieldByName("abonoesp")->AsFloat =
          Redondea ( ( ( antvenc_z / 10) + (porvenc_z * .67) + nvovenc_z)+.49, 1);
        qry_pronost->FieldByName("exigible")->AsFloat =
          Redondea ( antvenc_z + porvenc_z + nvovenc_z, 1);
        if (qry_pronost->FieldByName("abonoesp")->AsFloat != 0)
          qry_pronost->FieldByName("porcen")->AsFloat =
            Redondea(
              qry_pronost->FieldByName("abonos")->AsFloat /
              qry_pronost->FieldByName("abonoesp")->AsFloat * 100, 100
            );

        abonos_z   = qry_pronost->FieldByName("abonos")->AsFloat;
        abonoesp_z = qry_pronost->FieldByName("abonoesp")->AsFloat;
        exigible_z = qry_pronost->FieldByName("exigible")->AsFloat;
        qry_pronost->Post();
        pagos_z += abonos_z;
        porpag_z += abonoesp_z;
        if(exigible_z || abonoesp_z || abonos_z) {
          Series1->Add(exigible_z, mimay_z, clTeeColor);
          Series2->Add(abonoesp_z, mimay_z, clTeeColor);
          Series3->Add(abonos_z,   mimay_z, clTeeColor);
        }
      }
    }
    if(porpag_z != 0) {
      qry_pronost->First();
      qry_pronost->Edit();
      qry_pronost->FieldByName("porglo")->AsFloat =
        pagos_z / porpag_z * 100;
      qry_pronost->Post();
    }
    qry_pronost->EnableControls();

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::exporta_dbgridExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  String nombre_z;
  if(!ActiveControl) return;
  midbgrd_z = (TdxDBGrid*) ActiveControl;
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = midbgrd_z->Name + ".xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
      switch( SaveDialog->FilterIndex) {
        case 1: midbgrd_z->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
        case 2: midbgrd_z->SaveToXLS(SaveDialog->FileName, true); break;
        case 3: midbgrd_z->SaveToHTML(SaveDialog->FileName, true); break;
      }
  }
  delete SaveDialog;
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::qry_edoanuAfterScroll(
      TDataSet *DataSet)
{
  if(qry_edoanu->FieldByName("descri")->AsString == "FILIAL") {
    dbedt_descri->Color = clYellow;
  } else {
    dbedt_descri->Color = lkcmb_mayoris->Color;
  }
//  if(qry_edoanu->Tag == NO_REFRESH) return;
//  mayoris_z = qry_edoanu->FieldByName("codigo")->AsString;
//  lkcmb_mayoris->KeyValue = mayoris_z;
//  Cierra_Consultas();
//  TLocateOptions Opts;
//  Opts.Clear();
//  if(qry_pronost->Active) {
//    qry_pronost->First();
//    if(!qry_pronost->Locate("mayoris", mayoris_z, Opts)) {
//      qry_pronost->Next();
//    }
//  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::Cierra_Consultas()
{
  qry_abonosxmes->Close();
  qry_facxmes->Close();
  qry_facturas->Close();
  qry_abonos->Close();
  qsPendPag->Close();
  qsSaldoMes->Close();
  qry_compraspagosxmes->Close();
  qry_vencs->Close();
  qsForPago->Close();
  qsLetras->Close();
  qry_pendpagglob->Close();
  qry_aboxtipo->Close();

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::tbs_detmayoShow(TObject *Sender)
{
  TLocateOptions Opts;
  Opts.Clear();
  if(qry_pronost->Active) {
    qry_pronost->First();
    if(qry_pronost->Locate("mayoris", mayoris_z, Opts))
      dts_consmay->DataSet = qry_pronost;
    else
      dts_consmay->DataSet =  NULL;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::tbs_graffacxabonoShow(TObject *Sender)
{
  if(qry_compraspagosxmes->Active) return;
  DesplegarCharCompras();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::DesplegarCharCompras()
{
  int anu2_z=0, anu1_z=0, anu0_z=0, mesfin_z=0, mesini_z=0, anu_z=0,
    perioini_z, periofin_z, mes_z=0, perio_z=0, ancho_z=0,
    perioinic_z=0, periofinc_z=0;
  String nombre_z, tit_z, tit2_z, aux_z;
  double pagos_z, compras_z, cartera_z, cobranza_z, deuda_z;
  TLocateOptions Opts;
  Variant locvalues_z[2];

  TDateTime fechaini_z, fechafin_z, feculmes_z, fecha_z, fecha2_z;
  nombre_z = qry_edoanu->FieldByName("nombre")->AsString;
  char_comprasanual->Title->Text->Text= ("Compras Anuales de \n"+ nombre_z).c_str();
  char_compraspagos->Title->Text->Text= ("Comparativo de Facturacion y Abonos de \n"+ nombre_z).c_str();
  char_cobranza->Title->Text->Text= ("Comparativo de Cobranza y Pagos de \n"+ nombre_z).c_str();
  char_cartera->Title->Text->Text= ("Comparativo de Cartera y Deuda de \n"+ nombre_z).c_str();
  anu0_z = edt_anumay->Value;
  mesini_z = edt_mesmay->Value;
  mesfin_z = edt_mesmay->Value;
  fechafin_z = UltimoDiaMes(TDateTime(anu0_z, mesini_z, 1));
  aux_z = fechafin_z.FormatString("yyyymmdd");
  fecha2_z = PrimerDiaMes(IncMonth(fechafin_z, -15));
  aux_z = fecha2_z.FormatString("yyyymmdd");
  mesini_z = StrToInt(FormatDateTime("mm", fecha2_z));
  anu0_z = fechafin_z.FormatString("yyyy").ToInt();
  anu1_z = anu0_z - 1;
  anu2_z = anu0_z - 2;
  //perioini_z =  fechafin_z.FormatString("yyyymmdd").ToInt();
  perioini_z = anu1_z * 100 + mesini_z;
  perioinic_z = anu2_z * 100 + mesini_z;
  periofinc_z = anu0_z * 100 + mesfin_z;
  fechaini_z = TDateTime(anu2_z, 1, 1);
  chartserie_anuantier->Clear();
  chartserie_anuayer->Clear();
  chartserie_anuhoy->Clear();
  ancho_z = 5;
//  ancho_z = StrToIntDef(
//    InputBox("Ancho de Linea", "Ancho:", IntToStr(chartserie_anuantier->LinePen->Width)),
//    100)
//  ;
  chartserie_anuantier->LinePen->Width = ancho_z;
  chartserie_anuayer->LinePen->Width = ancho_z;
  chartserie_anuhoy->LinePen->Width = ancho_z;
  chartserie_anuantier->LinePen->Color= clRed;
  chartserie_anuayer->LinePen->Color = clBlue;
  chartserie_anuhoy->LinePen->Color = clGreen;
  chartserie_anuantier->Pointer->Visible = true;
  chartserie_anuayer->Pointer->Visible = true;
  chartserie_anuhoy->Pointer->Visible = true;

  chartserie_anuantier->Title = IntToStr(anu2_z);
  chartserie_anuayer->Title = IntToStr(anu1_z);
  chartserie_anuhoy->Title = IntToStr(anu0_z);

  chartserie_compras->Clear();
  chartserie_pagos->Clear();
  chartserie_compras->Title = "Facturaci�n";
  chartserie_pagos->Title = "Abonos";

// Grafica de Documentos Cobrados contra Pagos a MDS
  chartserie_cobranza->Clear();
  chartserie_pagos2->Clear();
  chartserie_cobranza->LinePen->Width = ancho_z;
  chartserie_pagos2->LinePen->Width = ancho_z;
  chartserie_cobranza->LinePen->Color= clRed;
  chartserie_pagos2->LinePen->Color = clBlue;
  chartserie_cobranza->Pointer->Visible = true;
  chartserie_pagos2->Pointer->Visible = true;
  chartserie_cobranza->Title = "Documentos Cobrados";
  chartserie_pagos2->Title = "Pagos a Diaz y Sol�s";

// Grafica de Cartera contra Deuda
  chartserie_deuda->Clear();
  chartserie_cartera->Clear();
  chartserie_deuda->LinePen->Width = ancho_z;
  chartserie_cartera->LinePen->Width = ancho_z;
  chartserie_deuda->LinePen->Color= clRed;
  chartserie_cartera->LinePen->Color = clBlue;
  chartserie_deuda->Pointer->Visible = true;
  chartserie_cartera->Pointer->Visible = true;
  chartserie_cartera->Title = "Cartera Final";
  chartserie_deuda->Title = "Saldo de Deuda con Diaz y Solis";


  qry_compraspagosxmes->Close();
  qry_compraspagosxmes->ParamByName("cia")->AsInteger = cia_z;
  qry_compraspagosxmes->ParamByName("fechaini")->AsDateTime = fechaini_z;
  qry_compraspagosxmes->ParamByName("fechafin")->AsDateTime = fechafin_z;
  qry_compraspagosxmes->ParamByName("mayoris")->AsString = mayoris_z;
  qry_compraspagosxmes->Open();
  aux_z = FormatDateTime("yyyymmdd", fechaini_z) + " - " + FormatDateTime("yyyymmdd", fechafin_z);
  perio_z = StrToInt(FormatDateTime("yyyymm", fechaini_z));
  fecha_z = fechaini_z;
  aux_z = fecha_z.FormatString("yyyymmdd");
  for(; periofinc_z > perio_z ; fecha_z = IncMonth(fecha_z, 1)) {
    Opts.Clear();
    anu_z = StrToInt(FormatDateTime("yyyy", fecha_z));
    mes_z = StrToInt(FormatDateTime("mm", fecha_z));
    perio_z = anu_z * 100 + mes_z;
    locvalues_z[0] = Variant(anu_z);
    locvalues_z[1] = Variant(mes_z);
    qry_compraspagosxmes->First();
    pagos_z = 0;
    compras_z = 0;
    if(qry_compraspagosxmes->Locate("anu;mes", VarArrayOf(locvalues_z, 1), Opts)) {
      pagos_z = qry_compraspagosxmes->FieldByName("abonos")->AsFloat;
      compras_z = qry_compraspagosxmes->FieldByName("cargos")->AsFloat;
    }
    tit_z = nommes(mes_z);
    tit2_z = tit_z.SubString(1,3) + "-" + IntToStr(anu_z);
    if(anu_z == anu2_z) chartserie_anuantier->Add(compras_z, tit_z, clRed);
    if(anu_z == anu1_z) chartserie_anuayer->Add(compras_z, tit_z, clBlue);
    if(anu_z == anu0_z) chartserie_anuhoy->Add(compras_z, tit_z, clGreen);
    // if(perio_z >= perioini_z) {  MOdificado 2014-01-21
    //  chartserie_compras->Add(compras_z, tit2_z, clTeeColor);
    //  chartserie_pagos->Add(pagos_z, tit2_z, clTeeColor);
    //}
    if(perio_z >= perioinic_z) {
      chartserie_compras->Add(compras_z, tit2_z, clTeeColor);
      chartserie_pagos->Add(pagos_z, tit2_z, clTeeColor);
    }
    if(perio_z >= perioinic_z && perio_z <= periofinc_z) {
      feculmes_z = UltimoDiaMes(TDateTime(anu_z, mes_z, 1));
      qry_vencs->Close();
      qry_vencs->ParamByName("mayoris")->AsString = mayoris_z;
      qry_vencs->ParamByName("fecha")->AsDateTime = feculmes_z;
      qry_vencs->ParamByName("cia")->AsInteger = cia_z;
      qry_vencs->Open();
      cobranza_z = qry_vencs->FieldByName("cobinterna")->AsFloat;
      cartera_z = qry_vencs->FieldByName("cartera")->AsFloat;
      deuda_z = qry_vencs->FieldByName("sdofin")->AsFloat;
      chartserie_cobranza->Add(cobranza_z, tit2_z, clTeeColor);
      chartserie_pagos2->Add(pagos_z, tit2_z, clTeeColor);
      chartserie_deuda->Add(deuda_z, tit2_z, clTeeColor);
      chartserie_cartera->Add(cartera_z, tit2_z, clTeeColor);
    }
  }
  qry_vencs->Close();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::impri_graphExecute(TObject *Sender)
{
  TChart* michart_z;
  switch (page_general->ActivePageIndex) {
  case TBS_DATOSMAY:
    switch (page_movmay->ActivePageIndex) {
        case TBS_CHARCOMPRAS      : michart_z = char_comprasanual;        break;
        case TBS_CHARCOMPRAPAGO   : michart_z = char_compraspagos;        break;
        case TBS_CHARCOBRANZA     : michart_z = char_cobranza;            break;
        case TBS_CHARCARTERA      : michart_z = char_cartera;             break;
    }
    break;
  case TBS_EDOMAY:
    switch (page_global->ActivePageIndex) {
        case TBS_PRONOSTICOS      :  michart_z = chart_pronosticos;        break;
        case TBS_FACXMESGLO       :  michart_z = chart_comprasglo;         break;
    }
    break;
  }
//  michart_z->PrintResolution = 100;
//  michart_z->MarginLeft   = 5;
//  michart_z->MarginTop    = 5;
//  michart_z->MarginRight  = 5;
//  michart_z->MarginBottom = 5;
  michart_z->PrintLandscape();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::graba_bitmapExecute(TObject *Sender)
{
  TChart* michart_z;
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  switch (page_general->ActivePageIndex) {
  case TBS_DATOSMAY:
    switch (page_movmay->ActivePageIndex) {
        case TBS_CHARCOMPRAS      : michart_z = char_comprasanual;        break;
        case TBS_CHARCOMPRAPAGO   : michart_z = char_compraspagos;        break;
        case TBS_CHARCOBRANZA     : michart_z = char_cobranza;            break;
        case TBS_CHARCARTERA      : michart_z = char_cartera;             break;
    }
    break;
  case TBS_EDOMAY:
    switch (page_global->ActivePageIndex) {
        case TBS_PRONOSTICOS      :  michart_z = chart_pronosticos;        break;
        case TBS_FACXMESGLO       :  michart_z = chart_comprasglo;         break;
    }
    break;
  }

  SaveDialog->Filter = "Imagenes Redimensionables (*.wmf)|*.wmf|Mapas de Bits (*.bmp)|*.bmp";
  SaveDialog->DefaultExt = "Imagenes Redimensionables";
  SaveDialog->FileName = michart_z->Name;
  SaveDialog->FilterIndex = 1;
  if (SaveDialog->Execute()) {
      switch( SaveDialog->FilterIndex) {
        case 1: michart_z->SaveToBitmapFile(SaveDialog->FileName); break;
        case 2: michart_z->SaveToMetafileEnh(SaveDialog->FileName); break;
      }
  }
  delete SaveDialog;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::date_fecedomayKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) {
      TDateTime fecha_z;
      fecha_z = UltimoDiaMes(date_fecedomay->Date);
      date_fecedomay->Date = fecha_z;
      qry_vencs->Close();
      qry_vencs->ParamByName("mayoris")->AsString = mayoris_z;
      qry_vencs->ParamByName("fecha")->AsDateTime = fecha_z;
      qry_vencs->ParamByName("cia")->AsInteger = cia_z;
      qry_vencs->Open();
      edt_cartera->Value = 0;
      edt_cobranza->Value = 0;
      if(!qry_vencs->IsEmpty()) {
        edt_cartera->Value = qry_vencs->FieldByName("cartera")->AsFloat;
        edt_cobranza->Value = qry_vencs->FieldByName("cobinterna")->AsFloat;
      }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::btn_grabadatomayClick(TObject *Sender)
{
  if(!qry_vencs->Active) {
    Application->MessageBox("Primero debe seleccionar la fecha y darle Enter", "Fecha No Seleccionada", MB_ICONQUESTION);
    return;
  }
  if(qry_vencs->IsEmpty()) {
    qry_vencs->Append();
    qry_vencs->FieldByName("mayoris")->AsString = mayoris_z;
    qry_vencs->FieldByName("FECHA")->AsDateTime = date_fecedomay->Date;
    qry_vencs->FieldByName("COMPRAS")->AsFloat = 0;
    qry_vencs->FieldByName("ABONOS")->AsFloat = 0;
    qry_vencs->FieldByName("DEVOLS")->AsFloat = 0;
    qry_vencs->FieldByName("SDOFIN")->AsFloat = 0;
    qry_vencs->FieldByName("CIA")->AsInteger = cia_z;
    qry_vencs->FieldByName("BONIF")->AsFloat = 0;
    qry_vencs->FieldByName("VENCANT")->AsFloat = 0;
    qry_vencs->FieldByName("VENCREC")->AsFloat = 0;
    qry_vencs->FieldByName("PORVENC")->AsFloat = 0;
  } else {
    qry_vencs->Edit();
  }
  qry_vencs->FieldByName("COBINTERNA")->AsFloat = edt_cobranza->Value;
  qry_vencs->FieldByName("CARTERA")->AsFloat = edt_cartera->Value;
  qry_vencs->Post();
  try {
    dm->manvehi->StartTransaction();
    qry_vencs->ApplyUpdates();
    dm->manvehi->Commit();
    Application->MessageBox("Datos Actualizados", "Operacion Exitosa", MB_ICONEXCLAMATION);
  } catch (Exception &E) {
    dm->manvehi->Rollback();
    Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::qsPendPagAfterScroll(
      TDataSet *DataSet)
{
  if(qsPendPag->Tag == SI_REFRESH)
    DespliegaDatosFac(
      qsPendPag->FieldByName("docto")->AsInteger,
      qsPendPag->FieldByName("tipofac")->AsInteger
    );
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::DespliegaDatosFac(int docto_z, int tipofac_z)
{
  String fpagado_z, fvence_z, hoymax_z;
  double imppago_z, impletra_z;
  //int letra_z;
  hoymax_z  = FormatDateTime("yyyymmdd", Now() - 5);
  qsForPago->Close();
  qsForPago->ParamByName("Mayoris")->AsString  = mayoris_z;
  qsForPago->ParamByName("Docto"  )->AsInteger = docto_z;
  qsForPago->ParamByName("Cia"    )->AsInteger = cia_z;
  qsForPago->ParamByName("tipofac")->AsInteger = tipofac_z;
  qsForPago->Open();

  qsLetras->Close();
  qsLetras->ParamByName("Mayoris"  )->AsString  = mayoris_z;
  qsLetras->ParamByName("Documento")->AsInteger = docto_z;
  qsLetras->ParamByName("Cia"      )->AsInteger = cia_z;
  qsLetras->ParamByName("tipofac"  )->AsInteger = tipofac_z;
  qsLetras->Open();
  for( qsLetras->First(); !qsLetras->Eof; qsLetras->Next()) {
    qsLetras->Edit();
    //letra_z = qsLetras->FieldByName("pagare")->AsInteger;
    fpagado_z = "";
    impletra_z = qsLetras->FieldByName("importe")->AsFloat;
    imppago_z = qsLetras->FieldByName("imppago")->AsFloat;
    if (!qsLetras->FieldByName("sFechaPago")->AsString.IsEmpty()) fpagado_z = FormatDateTime("yyyymmdd", qsLetras->FieldByName("sFechaPago")->AsDateTime);
    fvence_z  = FormatDateTime("yyyymmdd", qsLetras->FieldByName("vence")->AsDateTime + 5);
    if( imppago_z >= impletra_z ) {
      if( fpagado_z > fvence_z )
         qsLetras->FieldByName("sGrafico")->AsString = "PATRASADO";
      else
         qsLetras->FieldByName("sGrafico")->AsString = "PUNTUAL";
    } else {
       if(fvence_z <= hoymax_z) qsLetras->FieldByName("sGrafico")->AsString = "VENCIDO";
    }
    qsLetras->Post();
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::page_generalChange(TObject *Sender)
{
  if (page_general->ActivePageIndex == TBS_DATOSMAY) {
     mayoris_z = qry_edoanu->FieldByName("codigo")->AsString;
     lkcmb_mayoris->KeyValue = mayoris_z;
     desp_datos_mayExecute(Sender);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::qry_aboxtipoAfterScroll(
      TDataSet *DataSet)
{
  Despliega_AbonosxDia();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::Despliega_AbonosxDia()
{
  TDateTime fecha_z;
  String strfecha_z;
  int folio_z;
  if(qry_aboxtipo->Tag == NO_REFRESH ) return;
  fecha_z = qry_aboxtipo->FieldByName("fecha")->AsDateTime;
  folio_z = qry_aboxtipo->FieldByName("folio")->AsInteger;
  strfecha_z = DateToStr(fecha_z);
  qry_abonos->Close();
  qry_abonos->ParamByName("Mayoris")->AsString    = mayoris_z;
  qry_abonos->ParamByName("Cia"    )->AsInteger   = cia_z;
  qry_abonos->ParamByName("FechaIni")->AsDateTime = fecha_z;
  qry_abonos->ParamByName("FechaFin")->AsDateTime = fecha_z;
  qry_abonos->ParamByName("folio"   )->AsInteger  = folio_z;
  qry_abonos->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::page_globalChange(TObject *Sender)
{
    switch (page_global->ActivePageIndex) {
      case TBS_FACXMESGLO : DespliegaCompraGLobal(); break;
    }

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::DespliegaCompraGLobal()
{
  String mimes_z;
  TDateTime fechini_z, fechfin_z;
  double compras_z, pagos_z;
  fechfin_z = Now();
  fechini_z = PrimerDiaMes(IncMonth(fechfin_z, mesesatras_z));
//  Application->MessageBox(("Inicio:"+DateToStr(fechini_z)+" Fin:"+DateToStr(fechfin_z)).c_str(), "Fechas", 0);
  if(qry_facxmesglo->Active) return;
  qry_facxmesglo->Close();
  qry_facxmesglo->ParamByName("Cia"    )->AsInteger = cia_z;
  qry_facxmesglo->ParamByName("FechaIni")->AsDateTime = fechini_z;
  qry_facxmesglo->ParamByName("FechaFin")->AsDateTime = fechfin_z;
  qry_facxmesglo->Open();
  chart_comprasglo->Title->Text->Text = "Compras / Pagos Globales de Mayoristas";
  charseries_comprasglo->Clear();
  charseries_pagosglo->Clear();
  charseries_comprasglo->Title = "Compras";
  charseries_pagosglo->Title = "Pagos";
  for(qry_facxmesglo->First(); !qry_facxmesglo->Eof; qry_facxmesglo->Next()) {
    mimes_z = nommes(qry_facxmesglo->FieldByName("fechax")->AsString.SubString(5,2).ToIntDef(1));
    mimes_z = mimes_z.SubString(1, 3) + "/" + qry_facxmesglo->FieldByName("fechax")->AsString.SubString(3,2);
    compras_z = qry_facxmesglo->FieldByName("cargos")->AsFloat;
    pagos_z = qry_facxmesglo->FieldByName("abonos")->AsFloat;
    charseries_comprasglo->Add(compras_z, mimes_z, clTeeColor);
    charseries_pagosglo->Add(pagos_z, mimes_z, clTeeColor);
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::edt_mesChange(TObject *Sender)
{
  if (edt_mes->Value > 12) {
    edt_mes->Value = 1;
    edt_anu->Value++;
  }
  if (edt_mes->Value < 1) {
    edt_mes->Value = 12;
    edt_anu->Value--;
  }
}
//---------------------------------------------------------------------------



void __fastcall TForm_ConsuMovsMay::dbgrd_pagosxmesCustomDrawFooterNode(
      TObject *Sender, TCanvas *ACanvas, TRect &ARect,
      TdxTreeListNode *ANode, TdxTreeListColumn *AColumn, int AFooterIndex,
      AnsiString &AText, TColor &AColor, TFont *AFont,
      TAlignment &AAlignment, bool &ADone)
{
  double acum_z =0;
  for(qry_aboxtipo->First(); !qry_aboxtipo->Eof; qry_aboxtipo->Next()) {
    acum_z += qry_aboxtipo->FieldByName("total")->AsFloat;
    qry_aboxtipo->Edit();
    qry_aboxtipo->FieldByName("acum")->AsFloat = acum_z;
    qry_aboxtipo->Post();
  }

}
//---------------------------------------------------------------------------




void __fastcall TForm_ConsuMovsMay::desp_datos_mayExecute(TObject *Sender)
{
      TLocateOptions Opts;
      Opts.Clear();
      qry_edoanu->Tag = NO_REFRESH;
      mayoris_z = qry_edoanu->FieldByName("codigo")->AsString;
      Cierra_Consultas();
      if(qry_pronost->Active) {
        qry_pronost->First();
        if(!qry_pronost->Locate("mayoris", mayoris_z, Opts)) {
          qry_pronost->Next();
        }
      }
      qry_edoanu->Tag = SI_REFRESH;
      DesplegarDatos();

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::lkcmb_mayorisExit(TObject *Sender)
{
  desp_datos_mayExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::dbgrd_analipendColumnSorting(
      TObject *Sender, TdxDBTreeListColumn *Column, bool &Allow)
{
   ordenado_z = true;
   String column_z, sql_z, fechax_z;
   double acum_z = 0;
   TDateTime fecini_z;
   fechax_z = qsSaldoMes->FieldByName("fechax")->AsString;
   fecini_z = EncodeDate(
     StrToInt(fechax_z.SubString(1,4)),
     StrToInt(fechax_z.SubString(5,2)), 1
   );
   sql_z = "select mayoris,docto,pagare,conse,fecha,vence,concep,coa,\
     importe,saldo,cia,tipago, tipofac,0 as acum, \
     cast( extract(YEAR  from vence) * 100 + extract(month from vence) as varchar(6) ) as venc,\
     cast((mayoris || cast(docto as varchar(12) ) || cast(pagare as varchar(6) ) ) as varchar(25) ) as sLlave \
     from movmay2 where \
     mayoris = :Mayoris and saldo > 0.05 and vence between :VENCINI and :VENCFIN \
     and coa = 'C' and cia = :Cia order by ";

   column_z = Column->FieldName;
   Allow = false;
   sql_z += column_z;
   qsPendPag->DisableControls();
   qsPendPag->Close();
   qsPendPag->SQL->Text = sql_z;
   qsPendPag->ParamByName("Mayoris")->AsString  = mayoris_z;
   qsPendPag->ParamByName("Cia"    )->AsInteger = cia_z;
   qsPendPag->ParamByName("vencini")->AsDateTime = PrimerDiaMes(fecini_z);
   qsPendPag->ParamByName("vencfin")->AsDateTime = UltimoDiaMes(fecini_z);
   qsPendPag->Open();
   for(qsPendPag->First(); !qsPendPag->Eof; qsPendPag->Next()) {
     acum_z += qsPendPag->FieldByName("saldo")->AsFloat;
     qsPendPag->Edit();
     qsPendPag->FieldByName("acum")->AsFloat = acum_z;
     qsPendPag->Post();
   }
   qsPendPag->EnableControls();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::RecalcularAcumulados(TObject *Sender)
{
  double acum_z=0;
  String milinea_z;
  if (!ordenado_z) return;
  ordenado_z = false;
  if (!dbgrd_analipend->UseBookmarks) return;
  qsPendPag->DisableControls();
  TdxTreeListNode *Node_z = NULL;
  Node_z = dbgrd_analipend->TopNode;
  while( Node_z != NULL ) {
     Node_z->Focused = true;
     acum_z += qsPendPag->FieldByName("saldo")->AsFloat;
     milinea_z = qsPendPag->FieldByName("CONCEP")->AsString +
       FormatFloat("\t $ ###,##0.00", qsPendPag->FieldByName("saldo")->AsFloat) +
       FormatFloat("\t $ ###,##0.00", acum_z);
     qsPendPag->Edit();
     qsPendPag->FieldByName("acum")->AsFloat = acum_z;
     qsPendPag->Post();
     Node_z = Node_z->GetNext();
  }
  qsPendPag->First();
  qsPendPag->EnableControls();

}
//---------------------------------------------------------------------------


void __fastcall TForm_ConsuMovsMay::edt_anumayKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
    if (Shift == TShiftState() ) {
       if (Key != VK_RETURN) return;
        int iDiaIni = 1, iDiaFin = 31, iMesIni = 1, iMesFin = 12;
        int iAnioIni = edt_anumay->Value;
        int iAnioFin = edt_anumay->Value;
        dtFechaIni = TDateTime(iAnioIni, iMesIni, iDiaIni);
        dtFechaFin = TDateTime(iAnioFin, iMesFin, iDiaFin);
        DesplegarDatos();
    }
        
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::edt_mesmayChange(TObject *Sender)
{
  if (edt_mesmay->Value > 12) {
    edt_mesmay->Value = 1;
    edt_anumay->Value++;
  }
  if (edt_mesmay->Value < 1) {
    edt_mesmay->Value = 12;
    edt_anumay->Value--;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::consulta_facturaExecute(
      TObject *Sender)
{
  int numfac_z;
  if(qry_facturas->State == dsInactive) return;
  numfac_z = qry_facturas->FieldByName("num")->AsInteger;
  TForm_hazfacma *Form_hazfacma = new TForm_hazfacma (this);
  Form_hazfacma->asigna_tipo(TIPO_FACTURAS_MAYOREO);
  Form_hazfacma->busca_ptvt(numfac_z);
  Form_hazfacma->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::dbgrd_acumuanualDblClick(
      TObject *Sender)
{
    mayoris_z = qry_edoanu2->FieldByName("codigo")->AsString;
    lkcmb_mayoris->KeyValue = mayoris_z;
    desp_datos_mayExecute(Sender);
    page_general->ActivePageIndex = TBS_DATOSMAY;
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::observs_mayExecute(TObject *Sender)
{
  String permisobs_z = "", tipo_z = "M", alm_z = mayoris_z, cod_z = mayoris_z;
  permisobs_z = dm->busca_permistr("OBSERV_MAYOREO");
  if(permisobs_z != "D" && permisobs_z!= "N") {
    CapturaObservaPedido(this, tipo_z, alm_z, 0, cia_z, cod_z, permisobs_z);
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::DesplegarObserrvs()
{
  String permisobs_z = "", tipo_z = "M", alm_z = mayoris_z,
  codigo_z = mayoris_z;
  permisobs_z = dm->busca_permistr("OBSERV_MAYOREO");
  if(permisobs_z != "D" && permisobs_z!= "N") {
    pnl_cmdobs->Visible = true;
  } else {
    pnl_cmdobs->Visible = false;
  }
  qry_observs->Close();
  qry_observs->ParamByName("codigo")->AsString  = codigo_z;
  qry_observs->ParamByName("tipoobs")->AsString = tipo_z;
  qry_observs->ParamByName("alm")->AsString     = alm_z;
  qry_observs->ParamByName("numero")->AsInteger = 0;
  qry_observs->ParamByName("cia")->AsInteger    = cia_z;
  qry_observs->Open();
}
//---------------------------------------------------------------------------

void __fastcall TForm_ConsuMovsMay::ver_permisionesExecute(TObject *Sender)
{
  String mispermisiones_z;
  mispermisiones_z += "\nObservs Mayoreo : OBSERV_MAYOREO";
  dm->MensajeError(mispermisiones_z, "Permisiones");

}
//---------------------------------------------------------------------------

