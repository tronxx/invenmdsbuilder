//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_consrelvta.h"
#include <inifiles.hpp>
#include "dialg_okcancel.h"
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

TForm_consrelvta* Form_consrelvta;
//---------------------------------------------------------------------------
void __fastcall ConsultaRelacionVentas(TForm *Padre)
{
    try
    {
        Form_consrelvta = new TForm_consrelvta(Padre);
        Form_consrelvta->Show();
    }
    catch(...)
    {
    }

}
//---------------------------------------------------------------------------
__fastcall TForm_consrelvta::TForm_consrelvta(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  edicion_factible(READ_ONLY);
}
//---------------------------------------------------------------------------
void __fastcall TForm_consrelvta::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  alta_ptvt();
  //switch(grabar->Tag) {
  //  case NUEVO: alta_ptvt(); break;
  //  case MODIF: modif_ptvt(); break;
  //}
  grabar->Tag = EN_ESPERA;
  edicion_factible(READ_ONLY);

}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::desp_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::alta_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::botones_onoff(int modo_z)
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

void __fastcall TForm_consrelvta::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("numero")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::busca_ptvt(String ptvt_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::FormCreate(TObject *Sender)
{
  permis_z="T";
  cia_z = dm->cia_z;
  config_z = dm->config_z;

  MISLIN_X_PAG = LIN_X_PAG;
  String zonaexclu01_z, zonaexclu02_z, zonaexclu03_z;
  if( dm->tipoimp_z == IMPRESORA_GRAFICA) MISLIN_X_PAG = LIN_X_PAG * 1.5;
  //if(dm->usermaster_z != "S") {
  //  dm->qry_permis->Close();
  //  dm->qry_permis->ParamByName("idusuario")->AsInteger=dm->idusuario_z;
  //  dm->qry_permis->ParamByName("idpermis")->AsInteger=CAPVTAS;
  //  dm->qry_permis->Open();
  //  if(!dm->qry_permis->IsEmpty())
  //    permis_z=dm->qry_permis->FieldByName("permis")->AsString;
  //  if(permis_z == "N") {
  //    Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
  //    Close();
  //  }
  //} else {
  //  permis_z="T";
  //}
  date_fecini->Date = Now();
  date_fecfin->Date = Now();
  tipoent_z = "V"; entrapor_z = TIPO_SABANA_VENTAS;
  TIniFile *ini;
  ini = new TIniFile(config_z );
  zonaexclu01_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_01", "02" );
  zonaexclu02_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_02", "30" );
  zonaexclu03_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_03", "04" );
  dbgrd_ventas->LoadFromIniFile(config_z);

  delete ini;
  mmo_zonasexclu->Lines->Clear();
  mmo_zonasexclu->Lines->Add("Zonas a Excluir:");
  mmo_zonasexclu->Lines->Add(zonaexclu01_z);
  mmo_zonasexclu->Lines->Add(zonaexclu02_z);
  mmo_zonasexclu->Lines->Add(zonaexclu03_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::asigna_tipo(int tipo_z)
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


void __fastcall TForm_consrelvta::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  String config_z;
  config_z = dm->busca_inifile();
  dbgrd_ventas->SaveToIniFile(config_z);
  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_consrelvta::edicion_factible(int modo_z)
{
  bool modo_enabled = true, modo_readonly = false;
  switch (modo_z) {
    case READ_WRITE: modo_enabled = true; modo_readonly = false; break;
    case READ_ONLY: modo_enabled = false; modo_readonly = true; break;
  }
}
//---------------------------------------------------------------------------



bool __fastcall TForm_consrelvta::afecta_kdx()
{
  bool todobien_z = true;
  return (todobien_z);
}
//---------------------------------------------------------------------------



void __fastcall TForm_consrelvta::exportdbgridExecute(TObject *Sender)
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


void __fastcall TForm_consrelvta::impritextExecute(TObject *Sender)
{
  double total_z = 0;
  String arch_z = "consrelvta.txt", serie_z="", vnd_z="", pvta_z="", ciu_z="";
  mensaje_z = "Desea imprimir " + este_z + " " + titulo_z;
  titmsg_z = "Impresión de " + titulo_z;
  int ii_z=0;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_relvtas->DisableControls();
  qry_relvtas->Tag == NO_REFRESH;
  qry_relvtas->First();
//  if(!qry_renentra->IsEmpty())
//    zona_z = qry_renpogas->FieldByName("zona")->AsInteger;
  pagina_z = 1; report_encab();
  for(qry_relvtas->First(); !qry_relvtas->Eof; qry_relvtas->Next()) {
    if(lineas_z > MISLIN_X_PAG) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab();
    }
    ii_z++;
    if(ii_z == qry_relvtas->RecordCount)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

    fprintf(archout, "%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|",
      ljust(qry_relvtas->FieldByName("zonaptvta")->AsString, 2),
      ljust(FormatDateTime("dd/mm/yyyy", qry_relvtas->FieldByName("fecha")->AsDateTime), 10),
      ljust(qry_relvtas->FieldByName("salede")->AsString, 4),
      ljust(qry_relvtas->FieldByName("tipoentrega")->AsString, 4),
      ljust(qry_relvtas->FieldByName("entrega")->AsString, 4),
      ljust(qry_relvtas->FieldByName("poblac")->AsString, 30),
      ljust(FormatDateTime("dd/mm/yyyy", qry_relvtas->FieldByName("fecha")->AsDateTime), 10),
      ljust(qry_relvtas->FieldByName("ptovta")->AsString, 4),
      ljust(qry_relvtas->FieldByName("codigo")->AsString, 13),
      ljust(qry_relvtas->FieldByName("descri")->AsString, 30),
      rjust(FormatFloat("###,###,##0.00", qry_relvtas->FieldByName("preciolista")->AsFloat), 12)
    );
    if(ii_z == qry_relvtas->RecordCount)
      fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
    total_z += qry_relvtas->FieldByName("preciolista")->AsFloat;
    fprintf(archout, "\n");
  }
  fprintf(archout, "%s%s|%s|%s\n",
    rjust("",120),
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    rjust(FormatFloat("###,###,##0.00", total_z), 12),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  fclose(archout);

//  vehiculo, kmts, serv, descri, chofer, costo, cambio
  qry_renentra->Tag == SI_REFRESH;
  qry_renentra->EnableControls();
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::report_encab()
{
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  //fprintf(archout, "Impresion de %s%s\n", titulo_z, dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s%s%s|%s|%s|%s|%s|%s|%s|%s|%s|%s|%s%s\n",
    dm->font_impre(dm->impre_z, SUBRAYADO_ON),
    dm->font_impre(dm->impre_z, CONDENSADO_ON),
    ljust("Zn", 2),
    ljust("Fecha", 10),
    ljust("Sale", 4),
    ljust("Tipo", 4),
    ljust("Chfr", 4),
    ljust("Poblacion", 30),
    ljust("F.Entrega", 10),
    ljust("PVta", 4),
    ljust("Codigo", 13),
    ljust("Descripcion", 30),
    rjust("P.Lista", 12),
    dm->font_impre(dm->impre_z, SUBRAYADO_OFF)
  );
  lineas_z = 5;
//  report_subencab();
}
//---------------------------------------------------------------------------


void __fastcall TForm_consrelvta::busca_cod(String codigo_z)
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

void __fastcall TForm_consrelvta::BitBtn1Click(TObject *Sender)
{
  qry_relvtas->Close();
  qry_relvtas->ParamByName("fecini")->AsDateTime = date_fecini->Date;
  qry_relvtas->ParamByName("fecfin")->AsDateTime = date_fecfin->Date;
  qry_relvtas->ParamByName("cia")->AsInteger = cia_z;
  qry_relvtas->Open();
  dbgrd_ventas->FullExpand();
}
//---------------------------------------------------------------------------
void __fastcall TForm_consrelvta::reporte_acumuladosExecute(
      TObject *Sender)
{
  reporte_acum_vtas_rel();
}
//---------------------------------------------------------------------------


///--- Reporte adumulado de ventas relacionadas ----
void __fastcall TForm_consrelvta::reporte_acum_vtas_rel()
{
  TDateTime fecini_z, fecfin_z, inianuant_z, finanuant_z, inidia_z,
    inimes_z, hoy_z, ayer_z;
  int ii_z=0;
  String sql_z, strfecha_z, sqlpisos_z, sqlcalle_z, sqlini_z,
    sqlhoy_z, sqlacum_z, sqlanua_z, sqlvtacon_z, sqlvtacrd_z,
    sqlcontacalle_z, sqlcontapisos_z, sqlcredicalle_z, sqlcredipisos_z,
    preciolis_z, unidshoy_z, unidsacu_z, sqlunids_z,
    zonaexclu01_z, zonaexclu02_z, zonaexclu03_z;
  TIniFile *ini;
  ini = new TIniFile(config_z );
  zonaexclu01_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_01", "02" );
  zonaexclu02_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_02", "30" );
  zonaexclu03_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_03", "04" );
  delete ini;

  hoy_z = date_fecfin->Date;
  ayer_z = hoy_z - 1;
  strfecha_z = FormatDateTime("dd", hoy_z);
  if(strfecha_z == "01") {
    inimes_z = IncMonth(hoy_z, 12);
    ayer_z = inimes_z;
  } else {
    inimes_z = PrimerDiaMes(hoy_z);
  }
  finanuant_z = IncMonth(hoy_z, -12);
  inianuant_z = PrimerDiaMes(finanuant_z);

  for(ii_z = 0; ii_z < 2; ii_z++) {
    if(ii_z == 0) sqlini_z = "delete from entpagtmp";
    if(ii_z == 1) sqlini_z = "delete from rezagtmp";
    qry_conse->Close();
    qry_conse->SQL->Text = sqlini_z;
    qry_conse->ExecSQL();
  }

  preciolis_z =  "sum(preciolista / (1.16))";
  sqlhoy_z      = preciolis_z + ", sum(0), sum(0), sum(0), sum(0)";
  sqlacum_z     = "sum(0), " + preciolis_z + ", sum(0), sum(0), sum(0)";
  sqlanua_z     = "sum(0), sum(0), " + preciolis_z + ", sum(0), sum(0)";
  sqlvtacon_z   = "sum(0), sum(0), sum(0), " + preciolis_z + ", sum(0)";
  sqlvtacrd_z   = "sum(0), sum(0), sum(0), sum(0), " + preciolis_z;
  unidshoy_z    = "count(*), sum(0)";
  unidsacu_z    = "sum(0), count(*)";

  sqlunids_z = "insert into rezagtmp (linea, alm, codigo, ordalm, cuantos) \
    select h.zona, d.ptovta, g.codigo as grupo, [ACU] from inv_polrelvta i \
    join inv_relvtas d on i.idpolrelvta = d.idpolrelvta \
    left outer join inv_relvtaart a  on d.idrelvtas = a.idrelvtas \
    left outer join conceps b on a.idcodigo = b.ncon \
    left outer join inven c on b.concepto = c.codigo and i.cia = c.cia \
    left outer join inv_invhist e on c.codigo = e.codigo and i.cia = e.cia \
    left outer join inv_relinv f on e.idart = f.idart and f.idrel = " + IntToStr(REL_INVEN_ARTDESP) +
    " left outer join inv_grupos g on f.iddato = g.idgrupo and i.cia = g.cia \
    join inv_relubiptovta h on d.ptovta = h.ptovta \
    join car_tiposctes j on d.tipocte = j.ticte \
    join inv_credcon k on d.tipopago = k.idcrdcon \
    where i.fecha between :FECINI and :FECFIN \
    and j.ticte <> 'RC' and g.impri = 'S' \
    and h.zona <> :ZONAEXCLU01 and h.zona <> :ZONAEXCLU02  and h.zona <> :ZONAEXCLU03 \
    group by h.zona, d.ptovta, g.codigo";

  sqlpisos_z = "insert into  entpagtmp ( prove, facpro, \
    tasacfc, importe, total, ctofinent, ivacfcent ) \
    select h.zona, d.ptovta, [ACU] from inv_polrelvta i \
    join inv_relvtas d on i.idpolrelvta = d.idpolrelvta \
    left outer join inv_relvtaart a  on d.idrelvtas = a.idrelvtas \
    join inv_relubiptovta h on d.ptovta = h.ptovta \
    join car_tiposctes j on d.tipocte = j.ticte \
    join inv_credcon k on d.tipopago = k.idcrdcon \
    where i.fecha between :FECINI and :FECFIN and d.ptovta <> 'M2' \
    and j.ticte <> 'RC' \
    and h.zona <> :ZONAEXCLU01 and h.zona <> :ZONAEXCLU02  and h.zona <> :ZONAEXCLU03 \
    group by h.zona, d.ptovta";
  sqlcalle_z = "insert into  entpagtmp ( prove, facpro, \
    tasacfc, importe, total, ctofinent, ivacfcent ) \
    select h.zona, d.entrega, [ACU] from inv_polrelvta i \
    join inv_relvtas d on i.idpolrelvta = d.idpolrelvta \
    left outer join inv_relvtaart a  on d.idrelvtas = a.idrelvtas \
    join inv_relubiptovta h on d.ptovta = h.ptovta \
    join car_tiposctes j on d.tipocte = j.ticte \
    join inv_credcon k on d.tipopago = k.idcrdcon \
    where i.fecha between :FECINI and :FECFIN and d.ptovta = 'M2' \
    and j.ticte <> 'RC' \
    and h.zona <> :ZONAEXCLU01 and h.zona <> :ZONAEXCLU02  and h.zona <> :ZONAEXCLU03 \
    group by h.zona, d.entrega";
  sqlcontacalle_z = "insert into  entpagtmp ( prove, facpro, \
    tasacfc, importe, total, ctofinent, ivacfcent ) \
    select h.zona, d.entrega, [ACU] from inv_polrelvta i \
    join inv_relvtas d on i.idpolrelvta = d.idpolrelvta \
    left outer join inv_relvtaart a  on d.idrelvtas = a.idrelvtas \
    join inv_relubiptovta h on d.ptovta = h.ptovta \
    join car_tiposctes j on d.tipocte = j.ticte \
    join inv_credcon k on d.tipopago = k.idcrdcon \
    where i.fecha between :FECINI and :FECFIN and d.ptovta = 'M2' \
    and ( j.ticte = 'CC' or j.ticte = 'TC' or j.ticte = 'AP' ) \
    and j.ticte <> 'RC' \
    and h.zona <> :ZONAEXCLU01 and h.zona <> :ZONAEXCLU02  and h.zona <> :ZONAEXCLU03 \
    group by h.zona, d.entrega";
  sqlcontapisos_z = "insert into  entpagtmp ( prove, facpro, \
    tasacfc, importe, total, ctofinent, ivacfcent ) \
    select h.zona, d.ptovta, [ACU] from inv_polrelvta i \
    join inv_relvtas d on i.idpolrelvta = d.idpolrelvta \
    left outer join inv_relvtaart a  on d.idrelvtas = a.idrelvtas \
    join inv_relubiptovta h on d.ptovta = h.ptovta \
    join car_tiposctes j on d.tipocte = j.ticte \
    join inv_credcon k on d.tipopago = k.idcrdcon \
    where i.fecha between :FECINI and :FECFIN and d.ptovta <> 'M2' \
    and ( j.ticte = 'CC' or j.ticte = 'TC' or j.ticte = 'AP' ) \
    and j.ticte <> 'RC' \
    and h.zona <> :ZONAEXCLU01 and h.zona <> :ZONAEXCLU02  and h.zona <> :ZONAEXCLU03 \
    group by h.zona, d.ptovta";

  sqlcredicalle_z = "insert into  entpagtmp ( prove, facpro, \
    tasacfc, importe, total, ctofinent, ivacfcent ) \
    select h.zona, d.entrega, [ACU] from inv_polrelvta i \
    join inv_relvtas d on i.idpolrelvta = d.idpolrelvta \
    left outer join inv_relvtaart a  on d.idrelvtas = a.idrelvtas \
    join inv_relubiptovta h on d.ptovta = h.ptovta \
    join car_tiposctes j on d.tipocte = j.ticte \
    join inv_credcon k on d.tipopago = k.idcrdcon \
    where i.fecha between :FECINI and :FECFIN and d.ptovta = 'M2' \
    and ( j.ticte <> 'CC' and j.ticte <> 'TC' and j.ticte <> 'AP' ) \
    and j.ticte <> 'RC' \
    and h.zona <> :ZONAEXCLU01 and h.zona <> :ZONAEXCLU02  and h.zona <> :ZONAEXCLU03 \
    group by h.zona, d.entrega";
  sqlcredipisos_z = "insert into  entpagtmp ( prove, facpro, \
    tasacfc, importe, total, ctofinent, ivacfcent ) \
    select h.zona, d.ptovta, [ACU] from inv_polrelvta i \
    join inv_relvtas d on i.idpolrelvta = d.idpolrelvta \
    left outer join inv_relvtaart a  on d.idrelvtas = a.idrelvtas \
    join inv_relubiptovta h on d.ptovta = h.ptovta \
    join car_tiposctes j on d.tipocte = j.ticte \
    join inv_credcon k on d.tipopago = k.idcrdcon \
    where i.fecha between :FECINI and :FECFIN and d.ptovta <> 'M2' \
    and ( j.ticte <> 'CC' and j.ticte <> 'TC' and j.ticte <> 'AP' ) \
    and j.ticte <> 'RC' \
    and h.zona <> :ZONAEXCLU01 and h.zona <> :ZONAEXCLU02  and h.zona <> :ZONAEXCLU03 \
    group by h.zona, d.ptovta";

  for(ii_z=0; ii_z < 12; ii_z++) {
    if (ii_z == 0) { sql_z = StrReplace( sqlpisos_z, "[ACU]", sqlhoy_z); fecini_z = hoy_z; fecfin_z = hoy_z; }
    if (ii_z == 1) { sql_z = StrReplace( sqlcalle_z, "[ACU]", sqlhoy_z); fecini_z = hoy_z; fecfin_z = hoy_z; }
    if (ii_z == 2) { sql_z = StrReplace( sqlpisos_z, "[ACU]", sqlacum_z); fecini_z = inimes_z; fecfin_z = ayer_z; }
    if (ii_z == 3) { sql_z = StrReplace( sqlcalle_z, "[ACU]", sqlacum_z); fecini_z = inimes_z; fecfin_z = ayer_z; }
    if (ii_z == 4) { sql_z = StrReplace( sqlpisos_z, "[ACU]", sqlanua_z); fecini_z = inianuant_z; fecfin_z = finanuant_z; }
    if (ii_z == 5) { sql_z = StrReplace( sqlcalle_z, "[ACU]", sqlanua_z); fecini_z = inianuant_z; fecfin_z = finanuant_z; }
    if (ii_z == 6) { sql_z = StrReplace( sqlcontacalle_z, "[ACU]", sqlvtacon_z); fecini_z = PrimerDiaMes(hoy_z); fecfin_z = hoy_z; }
    if (ii_z == 7) { sql_z = StrReplace( sqlcontapisos_z, "[ACU]", sqlvtacon_z); fecini_z = PrimerDiaMes(hoy_z); fecfin_z = hoy_z; }
    if (ii_z == 8) { sql_z = StrReplace( sqlcredicalle_z, "[ACU]", sqlvtacrd_z); fecini_z = PrimerDiaMes(hoy_z); fecfin_z = hoy_z; }
    if (ii_z == 9) { sql_z = StrReplace( sqlcredipisos_z, "[ACU]", sqlvtacrd_z); fecini_z = PrimerDiaMes(hoy_z); fecfin_z = hoy_z; }
    if (ii_z == 10) { sql_z = StrReplace( sqlunids_z, "[ACU]", unidshoy_z); fecini_z = hoy_z; fecfin_z = hoy_z; }
    if (ii_z == 11) { sql_z = StrReplace( sqlunids_z, "[ACU]", unidsacu_z); fecini_z = inimes_z; fecfin_z = ayer_z; }
    qry_conse->Close();
    qry_conse->SQL->Text = sql_z;
    qry_conse->ParamByName("fecini")->AsDateTime = fecini_z;
    qry_conse->ParamByName("fecfin")->AsDateTime = fecfin_z;
    qry_conse->ParamByName("zonaexclu01")->AsString = zonaexclu01_z;
    qry_conse->ParamByName("zonaexclu02")->AsString = zonaexclu02_z;
    qry_conse->ParamByName("zonaexclu03")->AsString = zonaexclu03_z;
    qry_conse->ExecSQL();
  }
  // --> Ya terminé de Acumular, ahora voy a generar las tablas
  genera_el_reporte_acum();
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::genera_el_reporte_acum()
{
  String sql_z, zona_z, antzona_z, ptvta_z,  arch_z = "consrelvta.txt",
    zonaexclu01_z, zonaexclu02_z;
  double vtaacumzon_z=0, vtadiazon_z=0, vtaanuazon_z=0, vtacrdzon_z=0, vtaconzon_z=0,
    vtaacumtot_z=0, vtadiatot_z=0, vtaanuatot_z=0, vtacrdtot_z=0, vtacontot_z=0,
    vtaacumptv_z=0, vtadiaptv_z=0, vtaanuaptv_z=0, vtacrdptv_z=0, vtaconptv_z=0;

  sql_z = "select prove as zona, facpro as ptvta,\
    sum(importe) as vtaacu,\
    sum(tasacfc) as vtahoy,\
    sum(importe+tasacfc) as vtatot,\
    sum(total) as vtaanua,\
    sum(ivacfcent) as vtacred,\
    sum(ctofinent) as vtacont\
    from entpagtmp group by prove, facpro";
  qry_conse->Close();
  qry_conse->SQL->Text = sql_z;
  qry_conse->Open();
  encab_z = "REPORTE_PESOS";
  antzona_z = "-1";
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  for(qry_conse->First(); !qry_conse->Eof; qry_conse->Next()) {
    zona_z = qry_conse->FieldByName("zona")->AsString;
    if(antzona_z == "-1") {
      antzona_z = zona_z;
      pagina_z = 1;
      report_encab_acum(zona_z);
    }
    if(antzona_z != zona_z) {
      if(lineas_z > MISLIN_X_PAG -6) {
        fprintf(archout, "%c", 12); pagina_z++; report_encab_acum(antzona_z);
      }
      report_acum_subtotales("Subt",
        vtaacumzon_z, vtadiazon_z, vtaanuazon_z,
        vtacrdzon_z, vtaconzon_z);
      vtaacumzon_z= vtadiazon_z = vtaanuazon_z = vtacrdzon_z = vtaconzon_z=0;
      antzona_z = zona_z;
      report_subencab(zona_z);
    }
    if(lineas_z > MISLIN_X_PAG -3) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab_acum(zona_z);
    }
    ptvta_z      = qry_conse->FieldByName("ptvta")->AsString;
    vtaacumptv_z = qry_conse->FieldByName("vtaacu")->AsFloat;
    vtadiaptv_z  = qry_conse->FieldByName("vtahoy")->AsFloat;
    vtaanuaptv_z = qry_conse->FieldByName("vtaanua")->AsFloat;
    vtacrdptv_z  = qry_conse->FieldByName("vtacred")->AsFloat;
    vtaconptv_z  = qry_conse->FieldByName("vtacont")->AsFloat;
    report_acum_subtotales(ptvta_z,
        vtaacumptv_z, vtadiaptv_z, vtaanuaptv_z, vtacrdptv_z, vtaconptv_z
    );

    vtaacumzon_z += vtaacumptv_z;
    vtadiazon_z  += vtadiaptv_z;
    vtaanuazon_z += vtaanuaptv_z;
    vtacrdzon_z  += vtacrdptv_z;
    vtaconzon_z  += vtaconptv_z;
    vtaacumtot_z += vtaacumptv_z;
    vtadiatot_z  += vtadiaptv_z;
    vtaanuatot_z += vtaanuaptv_z;
    vtacrdtot_z  += vtacrdptv_z;
    vtacontot_z  += vtaconptv_z;
  }
  report_acum_subtotales("Subt",
        vtaacumzon_z, vtadiazon_z, vtaanuazon_z,
        vtacrdzon_z, vtaconzon_z);
  vtaacumzon_z= vtadiazon_z = vtaanuazon_z = vtacrdzon_z = vtaconzon_z=0;
  report_acum_subtotales("TOTAL",
        vtaacumtot_z, vtadiatot_z, vtaanuatot_z,
  vtacrdtot_z, vtacontot_z);
  vtaacumtot_z= vtadiatot_z = vtaanuatot_z = vtacrdtot_z = vtacontot_z=0;
  // Ahora tengo que generar el repore de Unidades
  genera_reporte_unidades();
  fclose(archout);
  dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_consrelvta::report_encab_acum(String zona_z)
{
  String titrep_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  titrep_z = "Reporte de Acumulado de Ventas Relacionadas";
  fprintf(archout, "%s\n", cjust(titrep_z,80));
  titrep_z = "Al " + FormatDateTime("dd/mm/yyyy", date_fecfin->Date);
  fprintf(archout, "%s\n", cjust(titrep_z,80));
  lineas_z = 4;
  if(encab_z == "REPORTE_PESOS") report_subencab(zona_z);
  if(encab_z == "REPORTE_UNIDADES") report_subencab_unidades();
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::report_subencab(String zona_z)
{
  String nombre_z;
  nombre_z = busca_nombre("ZONA", zona_z);
  fprintf(archout, "Zona:%s%s%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    zona_z  + " " + nombre_z,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "|%s|", ljust("Punto",5));
  fprintf(archout, "%s|", cjust("Venta",12));
  fprintf(archout, "%s|", cjust("Vta.del.Dia",12));
  fprintf(archout, "%s|", cjust("Venta",12));
  fprintf(archout, "%s|", cjust("Venta Anu",12));
  fprintf(archout, "%s|", cjust("Venta",12));
  fprintf(archout, "%s|", cjust("Venta",12));
  fprintf(archout, "\n");

  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("Venta",5));
  fprintf(archout, "%s|", cjust("Acumulada",12));
  fprintf(archout, "%s|", cjust(FormatDateTime("dd", date_fecfin->Date),12));
  fprintf(archout, "%s|", cjust("Total",12));
  fprintf(archout, "%s|", cjust("Anterior",12));
  fprintf(archout, "%s|", cjust("Credito",12));
  fprintf(archout, "%s|", cjust("Contado",12));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 3;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::report_acum_subtotales(String tit_z,
         double vtaacumzon_z, double vtadiazon_z, double vtaanuazon_z,
         double vtacrdzon_z, double vtaconzon_z)
{
  double totvta_z=0;
  totvta_z = vtaacumzon_z + vtadiazon_z;
  if(tit_z == "Subt" || tit_z == "TOTAL" )
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust(tit_z,5));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", vtaacumzon_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", vtadiazon_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", totvta_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", vtaanuazon_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", vtacrdzon_z),12));
  fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", vtaconzon_z),12));
  if(tit_z == "Subt" || tit_z == "TOTAL" )
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  if(tit_z == "Subt") { fprintf(archout, "\n");  lineas_z++; }
  fprintf(archout, "\n");
  lineas_z++;
}
//---------------------------------------------------------------------------

String __fastcall TForm_consrelvta::busca_nombre(String tipodato_z, String clave_z)
{
  String nombre_z="", sql_z;
  if(tipodato_z == "ZONA") {
    sql_z = "select nombre as dato from zonainv where zona = :CLAVE";
  }
  if(tipodato_z == "GPODIARY") {
    sql_z = "select descri as dato from gpodiary where grupo = :CLAVE";
  }
  if(tipodato_z == "GRUPO") {
    sql_z = "select descri as dato from inv_grupos where codigo = :CLAVE";
  }
  qry_sigent->Close();
  qry_sigent->SQL->Text = sql_z;
  qry_sigent->ParamByName("clave")->AsString = clave_z;
  qry_sigent->Open();
  if(!qry_sigent->IsEmpty()) nombre_z = qry_sigent->FieldByName("dato")->AsString;
  return (nombre_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::genera_reporte_unidades()
{
  String sql_z, grupo_z, consubrayado_z="";
  int nregtros_z=0, unidshoy_z=0, unidsacu_z=0, unidshoytot_z=0,
    jj_z, unidsacutot_z=0;
  sql_z = "select codigo, sum(ordalm) as unihoy, sum(cuantos) as uniacu from rezagtmp group by codigo";
  qry_conse->Close();
  qry_conse->SQL->Text = sql_z;
  qry_conse->Open();
  encab_z = "REPORTE_UNIDADES";
  fprintf(archout, "\n\n");  lineas_z += 2;
  report_subencab_unidades();
  // fprintf(archout, "%c", 12); pagina_z++; report_encab_acum("");
  nregtros_z = qry_conse->RecordCount;
  jj_z = 1;
  for(qry_conse->First(); !qry_conse->Eof; qry_conse->Next()) {
    grupo_z = qry_conse->FieldByName("codigo")->AsString;
    if(lineas_z > MISLIN_X_PAG -3) {
      fprintf(archout, "%c", 12); pagina_z++; report_encab_acum("");
    }
    unidshoy_z   = qry_conse->FieldByName("unihoy")->AsInteger;
    unidsacu_z   = qry_conse->FieldByName("uniacu")->AsInteger;
    consubrayado_z ="NO";
    if(jj_z == nregtros_z) consubrayado_z ="SI";
    report_unids_impriren(grupo_z, unidshoy_z, unidsacu_z, consubrayado_z);
    unidshoytot_z += unidshoy_z;
    unidsacutot_z += unidsacu_z;
    jj_z++;
  }
  report_unids_impriren("TOTAL", unidshoytot_z, unidsacutot_z, "SI");

}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::report_subencab_unidades()
{
  String nombre_z;
  nombre_z = "Acumulado Global de Todas las Zonas";
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON),
    nombre_z,
    dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF)
  );
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "|%s|", ljust("Grupo",12));
  fprintf(archout, "%s|", ljust("Descripcion",30));
  fprintf(archout, "%s|", cjust("Acum.", 5));
  fprintf(archout, "%s|", cjust("V.Dia", 5));
  fprintf(archout, "%s|", cjust("Total", 5));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z += 2;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::report_unids_impriren(String grupo_z,int unidshoytot_z, int unidsacutot_z, String subraya_z)
{
  int totvta_z=0;
  String nombre_z="";
  totvta_z = unidshoytot_z + unidsacutot_z;
  if(subraya_z == "SI" )
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  if(grupo_z != "TOTAL" ) {
    nombre_z = busca_nombre("GRUPO", grupo_z);
  }
  fprintf(archout, "|%s|", ljust(grupo_z,12));
  fprintf(archout, "%s|", ljust(nombre_z,30));
  fprintf(archout, "%s|", rjust(FormatFloat("0", unidsacutot_z), 5));
  fprintf(archout, "%s|", rjust(FormatFloat("0", unidshoytot_z), 5));
  fprintf(archout, "%s|", rjust(FormatFloat("0", totvta_z),      5));
  if(subraya_z == "SI" )
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  fprintf(archout, "\n");
  lineas_z++;
}
//---------------------------------------------------------------------------

void __fastcall TForm_consrelvta::definir_zonasexcluExecute(
      TObject *Sender)
{
   String zonaexclu01_z, zonaexclu02_z, zonaexclu03_z;
   Tdlg_okcancel* Dlg_datos;
   Dlg_datos = new Tdlg_okcancel (this);
   TLabel *lbl_zona1 = new TLabel (Dlg_datos);
   lbl_zona1->Parent = Dlg_datos->Panel1;
   lbl_zona1->Caption = "Zona 1 a Excluir:";
   lbl_zona1->Top  = 20;
   lbl_zona1->Left = 20;
   TEdit *edt_zona01 = new TEdit (Dlg_datos);
   edt_zona01->Parent = Dlg_datos->Panel1;
   edt_zona01->Top  = 18;
   edt_zona01->Left = 100;
   TLabel *lbl_zona2 = new TLabel (Dlg_datos);
   lbl_zona2->Parent = Dlg_datos->Panel1;
   lbl_zona2->Caption = "Zona 2 a Excluir:";
   lbl_zona2->Top  = 50;
   lbl_zona2->Left = 20;
   TEdit *edt_zona02 = new TEdit (Dlg_datos);
   edt_zona02->Parent = Dlg_datos->Panel1;
   edt_zona02->Top  = 48;
   edt_zona02->Left = 100;
   TLabel *lbl_zona3 = new TLabel (Dlg_datos);
   lbl_zona3->Parent = Dlg_datos->Panel1;
   lbl_zona3->Caption = "Zona 2 a Excluir:";
   lbl_zona3->Top  = 80;
   lbl_zona3->Left = 20;
   TEdit *edt_zona03 = new TEdit (Dlg_datos);
   edt_zona03->Parent = Dlg_datos->Panel1;
   edt_zona03->Top  = 78;
   edt_zona03->Left = 100;
   Dlg_datos->Caption = "Datos de las Zonas a Excluir ";
   TIniFile *ini;
   ini = new TIniFile (config_z);
   zonaexclu01_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_01", "02" );
   zonaexclu02_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_02", "30" );
   zonaexclu03_z =  ini->ReadString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_03", "04" );
   edt_zona01->Text = zonaexclu01_z;
   edt_zona02->Text = zonaexclu02_z;
   edt_zona03->Text = zonaexclu03_z;
   if(Dlg_datos->ShowModal() == mrOk) {
     zonaexclu01_z = edt_zona01->Text;
     zonaexclu02_z = edt_zona02->Text;
     zonaexclu03_z = edt_zona03->Text;
     ini->WriteString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_01", zonaexclu01_z );
     ini->WriteString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_02", zonaexclu02_z );
     ini->WriteString( "Relaciones_Ventas_Acumulado", "ZONA_EXCLUYE_03", zonaexclu03_z );
     mmo_zonasexclu->Lines->Clear();
     mmo_zonasexclu->Lines->Add("Zonas a Excluir:");
     mmo_zonasexclu->Lines->Add(zonaexclu01_z);
     mmo_zonasexclu->Lines->Add(zonaexclu02_z);
     mmo_zonasexclu->Lines->Add(zonaexclu03_z);
   }
   delete ini;
   delete Dlg_datos;
}
//---------------------------------------------------------------------------

