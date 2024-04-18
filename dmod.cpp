//---------------------------------------------------------------------------

#include <vcl.h>
#include <inifiles.hpp>
#include <dir.h>
#pragma hdrstop
#include "situaciones.h"
#include "numapal.h"
#include <Printers.hpp>

#include "dmod.h"
#include "imprigra.h"
#include "Frm_selecdb.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
Tdm *dm;
//---------------------------------------------------------------------------
__fastcall Tdm::Tdm(TComponent* Owner)
        : TDataModule(Owner)
{
  config_z = "";
}
//---------------------------------------------------------------------------

void __fastcall Tdm::conecta_db()
{
   TIniFile *ini;
   config_z = busca_inifile();
   ini = new TIniFile(config_z );
   basedato_z   =  ini->ReadString( "DataBase", "DataBase", "Sin BD" );
   bdcartera_z  =  ini->ReadString( "DataBase", "Cartera", "capycon" );
   bdanuanter_z =  ini->ReadString( "DataBase", "AnuAnter", "inven" );
   usrmanto_z   = ini->ReadBool( "Mantos", "UsrManto", false );
   foliosalf_z  = ini->ReadBool( "Mantos", "FoliosAlf", false );
   usrmaster_z  = ini->ReadBool( "Mantos", "UsrMaster", false );
   lineamot_z   = ini->ReadString( "Pedimentos", "Linea_moto", "MOTO");
   
   delete ini;
   //Application->MessageBox(("Base datos:"+basedato_z+"\nConfig:"+config_z+"\nDirectorio:"+strdir_z).c_str(), "Config", 0);
   if(manvehi->Connected) manvehi->Connected = false;
   manvehi->AliasName = basedato_z;
   if(db_cartera->Connected) db_cartera->Connected = false;
   db_cartera->AliasName = bdcartera_z;
   try {
     manvehi->Connected = true;
     db_cartera->Connected = true;
   }  catch (Exception &E)
   {
     Application->MessageBox(("Base datos:"+basedato_z+
       "\nConfig:"+config_z+
       "\nCartera:" +bdcartera_z +
       "\nNo pude conectarme a la base de datos:\n"+E.Message).c_str(), "Error", MB_ICONEXCLAMATION);
     TForm_selecbd *Form_selecbd = new TForm_selecbd (this);
     Form_selecbd->ShowModal();
     Application->MessageBox("Ahora se terminará el programa, Intentelo de nuevo por Favor",
       "Base de datos Selccionada", MB_ICONEXCLAMATION);
     exit(-1);
   }
   qry_maxidvnd->Close();
   qry_maxidvnd->SQL->Text = "select mitipodb from mibd";
   qry_maxidvnd->Open();
   if(!qry_maxidvnd->IsEmpty()) tipodb_z = qry_maxidvnd->FieldByName("mitipodb")->AsString;
   qry_maxidvnd->Close();
   qry_maxidvnd->SQL->Text = "select login from car_usuarios where idusuario = :IDUSUARIO";
   usuario_z = "";
   qry_maxidvnd->ParamByName("idusuario")->AsInteger = idusuario_z;
   qry_maxidvnd->Open();
   if(!qry_maxidvnd->IsEmpty()) usuario_z = qry_maxidvnd->FieldByName("login")->AsString;
   qry_maxidvnd->Close();
}
//---------------------------------------------------------------------------

void __fastcall Tdm::manda_impresion(String arch_z)
{
  if(preview_z) {
    VistaPrevia(NULL, arch_z, rutaimp_z, tipoimp_z, ff_z, impresora_z);
  } else {
    manda_imp(arch_z, rutaimp_z, tipoimp_z, ff_z, impresora_z);
  }
}
//---------------------------------------------------------------------------

String __fastcall Tdm::busca_permision(int PERMISION)
{
  String permis_z="N";
  permis_z = busca_permistr(IntToStr(PERMISION));
  return(permis_z);
}
//---------------------------------------------------------------------------

String __fastcall Tdm::busca_permistr(String PERMISION)
{
  String permis_z="N";
  if(usermaster_z != "S") {
    qry_permis->Close();
    qry_permis->ParamByName("idusuario")->AsInteger  =idusuario_z;
    qry_permis->ParamByName("clavepermis")->AsString =PERMISION;
    qry_permis->ParamByName("idproyecto")->AsInteger =idproyec_z;
    qry_permis->Open();
    if(!qry_permis->IsEmpty())
      permis_z=qry_permis->FieldByName("permis")->AsString;
  } else {
    permis_z="T";
  }
  return(permis_z);
}
//---------------------------------------------------------------------------

TDateTime __fastcall Tdm::ahora()
{
  qry_fecha->Close();
  qry_fecha->Open();
  return (qry_fecha->FieldByName("fechora")->AsDateTime);
}
//---------------------------------------------------------------------------

int __fastcall Tdm::ultimo_folio_disp(
  String alm_z, String codigo_z, TDateTime fecha_z, String fechaabierta_z
)
{
  int ultfol_z = 0;
  qry_ultfol->Close();
  qry_ultfol->ParamByName("codigo")->AsString = codigo_z;
  qry_ultfol->ParamByName("alm")->AsString = alm_z;
  if(fechaabierta_z == "S") fecha_z = ahora();
  qry_ultfol->ParamByName("fecha")->AsDateTime = fecha_z;
  qry_ultfol->ParamByName("cia")->AsInteger = cia_z;
  qry_ultfol->Open();
  if(!qry_ultfol->IsEmpty()) ultfol_z = qry_ultfol->FieldByName("ultfol")->AsInteger;
  return (ultfol_z);
}
//---------------------------------------------------------------------------

int __fastcall Tdm::sigte_renentra(String alm_z, String tipo_z, int numero_z)
{
  int conse_z = 0;
  qry_sigrenentra->Close();
  qry_sigrenentra->ParamByName("tipo")->AsString = tipo_z;
  qry_sigrenentra->ParamByName("alm")->AsString = alm_z;
  qry_sigrenentra->ParamByName("numero")->AsInteger = numero_z;
  qry_sigrenentra->ParamByName("cia")->AsInteger = cia_z;
  qry_sigrenentra->Open();
  if(!qry_sigrenentra->IsEmpty()) conse_z = qry_sigrenentra->FieldByName("conse")->AsInteger;
  conse_z++;
  return (conse_z);
}
//---------------------------------------------------------------------------

int __fastcall Tdm::sigte_entrada(String alm_z, String tipo_z, int numero_z, int HACIA_DONDE)
{
  int conse_z = 0;
  String sql_z, where_z;
  TQuery *qry_sigentrada = new TQuery (this);
  sql_z = "select ";
  where_z = " where tipo = :TIPO and alm = :ALM and cia = :CIA and ";
  switch  (HACIA_DONDE) {
    case ANTER: sql_z += "max (numero) ";
                where_z += " numero < :NUMERO";
    break;
    case SIGTE: sql_z += "min (numero) ";
                where_z += " numero > :NUMERO";
    break;
    case ULTIMO: sql_z += "max (numero) ";
                where_z += " numero > :NUMERO"; numero_z = 0;
    break;
    case PRIMERO: sql_z += "min (numero) ";
                where_z += " numero > :NUMERO"; numero_z = -1;
    break;
  }
  sql_z += " as numero from entradas " + where_z;
  qry_sigentrada->SQL->Text = sql_z;
  qry_sigentrada->DatabaseName = qry_permis->DatabaseName;
  qry_sigentrada->Close();
  qry_sigentrada->ParamByName("tipo")->AsString = tipo_z;
  qry_sigentrada->ParamByName("alm")->AsString = alm_z;
  qry_sigentrada->ParamByName("cia")->AsInteger = cia_z;
  qry_sigentrada->ParamByName("numero")->AsInteger = numero_z;
  qry_sigentrada->Open();
  if(!qry_sigentrada->IsEmpty()) conse_z = qry_sigentrada->FieldByName("numero")->AsInteger;
  delete qry_sigentrada;
  return (conse_z);
}
//---------------------------------------------------------------------------


int __fastcall Tdm::folio_siguiente(String alm_z, String codigo_z)
{
  int sigfol_z = 1;
  qry_sigfol->Close();
  qry_sigfol->ParamByName("codigo")->AsString = codigo_z;
  qry_sigfol->ParamByName("alm")->AsString = alm_z;
  qry_sigfol->ParamByName("cia")->AsInteger = cia_z;
  qry_sigfol->Open();
  if(!qry_sigfol->IsEmpty()) sigfol_z = qry_sigfol->FieldByName("ultfol")->AsInteger + 1;
  return (sigfol_z);
}
//---------------------------------------------------------------------------


void __fastcall Tdm::DataModuleCreate(TObject *Sender)
{
  String secuenfecha_z="select now() as fechora";
  conecta_db();
  //idusuario_z = 1; 
  qry_sigid->Close();
  qry_sigid->Open();
  if(qry_sigid->IsEmpty()) {
    sequen1_z ="select max("; sequen2_z = "+1) as ultid from";
    //sequen1_z = "select "; sequen2_z = ".NextVal as ultid";
    secuen_z = "N";
  } else {
    sequen1_z = qry_sigid->FieldByName("parte1")->AsString;
    sequen2_z = qry_sigid->FieldByName("parte2")->AsString;
    secuen_z = qry_sigid->FieldByName("secuen")->AsString;
  }
  qry_fecha->Close();
  qry_fecha->Open();
  if(!qry_fecha->IsEmpty())
    secuenfecha_z= qry_fecha->FieldByName("sentencia")->AsString;
  qry_fecha->Close();
  qry_fecha->SQL->Text = secuenfecha_z;

}
//---------------------------------------------------------------------------

int __fastcall Tdm::busca_iddato(String text_z, int tipodato_z)
{
  int iddato_z;
  bool esnuevo_z=false, nvatrans_z=false;
  qry_iddato->SQL->Clear();
  qry_insbas->SQL->Clear();
  switch (tipodato_z) {
    case CIUDAD         :
      qry_iddato->SQL->Add("select idciudad as ultid from ctciudades where ciudad = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into ctciudades (idciudad, ciudad) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case INV_IDPOBLAC :
      qry_iddato->SQL->Add("select numero as ultid from poblacs where nombre = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into poblacs (numero, nombre) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case DIRECCION        :
      qry_iddato->SQL->Add("select iddirec as ultid from ctdirec where direc = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into ctdirec (iddirec, direc) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case TELEFONO       :
      qry_iddato->SQL->Add("select idtel as ultid from telfax where telfax = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into telfax (idtel, telfax) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case SERIE        :
      qry_iddato->SQL->Add("select idserie as ultid from series where serie = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into series (idserie, serie) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case ENFIMO        :
    case NOMBRE        :
      qry_iddato->SQL->Add("select idnombre as ultid from pvenfimo where nombre = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into pvenfimo (idnombre, nombre) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case INVCONCEPTO     :
      qry_iddato->SQL->Add("select idconcep as ultid from inv_conceps where concep = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into inv_conceps (idconcep, concep) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case CONCEPTO       :
      qry_iddato->SQL->Add("select idconcep as ultid from conceps where concepto = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into conceps (idconcep, concepto) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case OLDCONCEPTO       :
      qry_iddato->SQL->Add("select ncon as ultid from conceps where concepto = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into conceps (ncon, concepto) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case IDOBSERV       :
      qry_iddato->SQL->Add("select idobserv as ultid from observs where observ = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into observs (idobserv, observ) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case DATOSOLICIT      :
      qry_iddato->SQL->Add("select iddatsol as ultid from datsol where concepto = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into datsol (iddatsol, concepto) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case DATPOLSER      :
      qry_iddato->SQL->Add("select iddatpolser as ultid from datpolser where concepto = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into datpolser (iddatpolser, concepto) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
    case MAY_TIPOSTEL    :
      qry_iddato->SQL->Add("select idtipotel as ultid from may_tipostel where descri = :DATO");
      qry_iddato->ParamByName("DATO")->AsString = text_z;
      qry_iddato->Open();
      if(qry_iddato->IsEmpty()) {
        iddato_z = busca_sigid(tipodato_z);
        qry_insbas->SQL->Add("insert into may_tipostel (idtipotel, descri) values (:ID, :DATO)");
        esnuevo_z = true;
      } else {
        iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
      }
      break;
  }
  if(esnuevo_z) {
    try {
      nvatrans_z = !manvehi->InTransaction;
      if(nvatrans_z) manvehi->StartTransaction();
      qry_insbas->ParamByName("ID")->AsInteger=iddato_z;
      qry_insbas->ParamByName("DATO")->AsString=text_z;
      qry_insbas->ExecSQL();
      if(nvatrans_z) manvehi->Commit();
    } catch (Exception &E)
    {
      manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
  return(iddato_z);
}
//---------------------------------------------------------------------------

String __fastcall Tdm::busca_dato(int iddato_z, int tipodato_z)
{
  String dato_z="", sql_z="";
  qry_direc->SQL->Clear();
  switch (tipodato_z) {
    case PAIS           :
      sql_z="select idpais as iddato, pais as dato from ctpaises where idpais ="+IntToStr(iddato_z);
      break;
    case ESTADO         :
      sql_z="select idestado as iddato, estado as dato from ctestados where idestado ="+IntToStr(iddato_z);
      break;
    case CIUDAD         :
      sql_z="select idciudad as iddato, ciudad as dato from ctciudades where idciudad ="+IntToStr(iddato_z);
      break;
    case INV_IDPOBLAC   :
      sql_z="select numero as iddato, nombre as dato from poblacs where numero ="+IntToStr(iddato_z);
      break;
    case COLONIA        :
      sql_z="select idcolonia as iddato, colonia as dato from ctcolonias where idcolonia ="+IntToStr(iddato_z);
      break;
    case CRUZMTOS       :
    case CRUZMTO2       :
      sql_z="select idcalle as iddato, calle as dato from ctcalles where idcalle ="+IntToStr(iddato_z);
      break;
    case NUMERO         :
    case NUMINT         :
      sql_z="select iddirnum as iddato, dirnum as dato from ctdirnum where iddirnum ="+IntToStr(iddato_z);
      break;
    case CODPOST        :
      sql_z="select idcodpost as iddato, codpost as dato from ctcodpost where idcodpost ="+IntToStr(iddato_z);
      break;
    case TIPODIR        :
      sql_z="select idtipo as iddato, descri as dato from cttipodir where idtipo ="+IntToStr(iddato_z);
      break;
    case DIRECCION        :
      sql_z="select iddirec as iddato, direc as dato from ctdirec where iddirec="+IntToStr(iddato_z);
      break;
    case TELEFONO       :
      sql_z="select idtel as iddato, telfax as dato from telfax where idtel="+IntToStr(iddato_z);
      break;
    case ENFIMO        :
      sql_z="select idnombre as iddato, nombre as dato from pvenfimo where idnombre="+IntToStr(iddato_z);
      break;
    case DATPOLSER     :
      sql_z="select iddatpolser as iddato, concepto as dato from datpolser where iddatpolser="+IntToStr(iddato_z);
      break;
    case SERIE         :
      sql_z="select idserie as iddato, serie as dato from series where idserie ="+IntToStr(iddato_z);
      break;
    case CONCEPTO      :
      sql_z="select idconcep as iddato, concepto as dato from conceps where idconcep ="+IntToStr(iddato_z);
      break;
    case OLDCONCEPTO      :
      sql_z="select ncon as iddato, concepto as dato from conceps where ncon ="+IntToStr(iddato_z);
      break;
    case IDOBSERV        :
      sql_z="select idobserv as iddato, observ as dato from observs where idobserv ="+IntToStr(iddato_z);
      break;
    case INVCONCEPTO     :
      sql_z = "select idconcep as iddato, concep as dato from inv_conceps where idconcep ="+IntToStr(iddato_z);
      break;
    case IDCREDCON     :
      sql_z = "select idcrdcon as iddato, descri as dato from inv_credcon where idcrdcon ="+IntToStr(iddato_z);
      break;
    case IDCARESTADOS  :
      sql_z = "select idestado as iddato, nombre as dato from car_estados where idestado="+IntToStr(iddato_z);
      break;

  }
  qry_direc->SQL->Add(sql_z);
  qry_direc->Open();
  if(!qry_direc->Eof) dato_z=qry_direc->FieldByName("dato")->AsString;
  qry_direc->Close();
  return (dato_z);
}
//---------------------------------------------------------------------------

void __fastcall Tdm::seldatos(int tipodato_z)
{
  String sql_z;
  qry_direc->SQL->Clear();
  switch (tipodato_z) {
    case PAIS           :
      sql_z="select idpais as iddato, pais as dato from ctpaises order by pais";
      break;
    case ESTADO         :
      sql_z="select idestado as iddato, estado as dato from ctestados order by estado";
      break;
    case IDCARESTADOS:
      sql_z="select idestado as iddato, nombre as dato from car_estados order by nombre";
      break;
    case CIUDAD         :
      sql_z="select idciudad as iddato, ciudad as dato from ctciudades order by ciudad";
      break;
    case INV_IDPOBLAC   :
      sql_z="select numero as iddato, nombre as dato from poblacs order by nombre";
      break;
    case COLONIA        :
      sql_z="select idcolonia as iddato, colonia as dato from ctcolonias order by colonia";
      break;
    case CALLE          :
    case CRUZMTOS       :
    case CRUZMTO2       :
      sql_z="select idcalle as iddato, calle as dato from ctcalles order by calle";
      break;
    case NUMERO         :
    case NUMINT         :
      sql_z="select iddirnum as iddato, dirnum as dato from ctdirnum order by dirnum";
      break;
    case CODPOST        :
      sql_z="select idcodpost as iddato, codpost as dato from ctcodpost order by codpost";
      break;
    case TIPODIR        :
      sql_z="select idtipo as iddato, descri as dato from cttipodir order by descri";
      break;
    case SERIE        :
      sql_z="select idserie as iddato, serie as dato from series order by serie";
      break;
  }
  qry_direc->SQL->Add(sql_z);
}
//---------------------------------------------------------------------------

int __fastcall Tdm::busca_sigid(int tipodato_z)
{
  int iddato_z=0;
  qry_iddato->SQL->Clear();
  String seq_z = "DESCONOCIDA", campo_z = "desconocido", table_z="";
  switch (tipodato_z) {
    case IDCIASFON     : seq_z = "seq_idciasfon"; 	campo_z = "idciasfon"; 	table_z="ciasfon";	break;
    case IDTIENDAS     : seq_z = "seq_idtiendas";	campo_z = "idtienda"; 	table_z="tiendas";	break;
    case IDUSUARIO     : seq_z = "seq_idusuario";	campo_z = "idusuario";	table_z="usuarios";	break;
    case IDRENPOSER    : seq_z = "seq_idrenposer";	campo_z = "idrenposer";	table_z="renposer";	break;
    case IDCOMISCOB    : seq_z = "seq_idcomiscob";	campo_z = "idcomiscob";	table_z="comiscob";	break;
    case IDRUTA        : seq_z = "seq_idruta";	        campo_z = "idruta"; 	table_z="rutas";	break;
    case CIUDAD        : seq_z = "seq_idciudad";	campo_z = "idciudad";	table_z="ctciudades";	break;
    case INV_IDPOBLAC  : seq_z = "seq_poblacs";	        campo_z = "numero";	table_z="poblacs";	break;
    case IDCHOFER      : seq_z = "seq_idchofer";	campo_z = "idchofer";	table_z="chofer";	break;
    case IDEMPLEAD     : seq_z = "seq_idemplead";	campo_z = "idemplead";	table_z="emplead";	break;
    case IDNOMIALM     : seq_z = "seq_idnomialm";	campo_z = "idnomialm";	table_z="nomi_almacen";	break;
    case IDSERVMANTO   : seq_z = "seq_idservmanto";	campo_z = "idservmanto";table_z="servmanto";	break;
    case IDVEHICULO    : seq_z = "seq_idvehiculo";	campo_z = "idvehiculo";	table_z="vehiculo";	break;
    case IDCOMBUST     : seq_z = "seq_idcombust";	campo_z = "idcombust";	table_z="combust";	break;
    case IDPRECIOSCOMB : seq_z = "seq_idprecioscomb";   campo_z = "idprecioscomb";	table_z="precioscomb";	break;
    case IDALMREP      : seq_z = "seq_idalmrep";        campo_z = "idalmrep";	table_z="almrep";	break;
    case IDALMACEN     : seq_z = "seq_idalmacen";       campo_z = "idalmacen";	table_z="almacen";	break;
    case IDTALLERAUT   : seq_z = "seq_idtalleraut";     campo_z = "idtalleraut";	table_z="talleraut";	break;
    case IDPOLIGAS     : seq_z = "seq_idpoligas";       campo_z = "idpoligas"; 	table_z="poligas";	break;
    case IDRENPOGAS    : seq_z = "seq_idrenpogas";      campo_z = "idrenpogas";	table_z="renpogas";	break;
    case IDMVPOLSRV    : seq_z = "seq_idmvpolsrv";      campo_z = "idmvpolsrv";	table_z="mvpolsrv";	break;
    case IDMVRENPOSRV  : seq_z = "seq_idmvrenposrv";    campo_z = "idmvrenposrv";	table_z="mvrenposrv";	break;
    case IDOBSERV      : seq_z = "seq_idobserv";        campo_z = "idobserv";	table_z="observs";	break;
    case DATOSOLICIT   : seq_z = "seq_iddatsol";        campo_z = "iddatsol";	table_z="datsol";	break;
    case DATPOLSER     : seq_z = "seq_iddatpolser";     campo_z = "iddatpolser";	table_z="datpolser";	break;
    case IDMISDATSOL   : seq_z = "seq_idmisdatsol";     campo_z = "idmisdatsol";	table_z="misdatsol";	break;
    case IDTDAPOL      : seq_z = "seq_idtdapol";        campo_z = "idtdapol";	table_z="tdapol";	break;
    case IDREFCOMSOL   : seq_z = "seq_idrefcomsol";     campo_z = "idrefcomsol";	table_z="refcomsol";	break;
    case IDREPORTE     : seq_z = "seq_idreporte";       campo_z = "idreporte";	table_z="reporte";	break;
    case CLIENTE       : seq_z = "seq_idcliente";       campo_z = "idcliente";	table_z="clientes";	break;
    case SERIE         : seq_z = "seq_idserie";         campo_z = "idserie";	table_z="series";	break;
    case IDCOMPRA      : seq_z = "seq_idcompra";        campo_z = "idcompra";	table_z="compra";	break;
    case AVAL          : seq_z = "seq_idaval";          campo_z = "idaval";	table_z="avales";	break;
    case DIRECCION     : seq_z = "seq_iddirec";         campo_z = "iddirec";	table_z="ctdirec";	break;
    case TELEFONO      : seq_z = "seq_idtel";           campo_z = "idtel"; 	table_z="telfax";	break;
    case ENFIMO        : seq_z = "seq_idnombre";        campo_z = "idnombre";	table_z="pvenfimo";	break;
    case CONCEPTO      : seq_z = "seq_idconcep";        campo_z = "idconcep";	table_z="conceps";	break;
    case INVCONCEPTO   : seq_z = "seq_idconcep";        campo_z = "idconcep";	table_z="inv_conceps";	break;
    case OLDCONCEPTO   : seq_z = "seq_idconcep";        campo_z = "ncon";	table_z="conceps";	break;
    case IDRENPOLCOB   : seq_z = "seq_idrenpolco";      campo_z = "idrenpolco";	table_z="renpolco";	break;
    case IDVENDEDOR    : seq_z = "seq_idvendedor";      campo_z = "idvendedor";	table_z="vendedor";	break;
    case IDPROMOTOR    : seq_z = "seq_idpromotor";      campo_z = "idpromotor";	table_z="promotor";	break;
    case IDPTOVTA      : seq_z = "seq_idptovta";        campo_z = "idptovta";	table_z="ptovta";	break;
    case IDMOVCLI      : seq_z = "seq_idmovcli";        campo_z = "idmovcli";	table_z="mvcli";	break;
    case IDPOLCOB      : seq_z = "seq_polcob";          campo_z = "idpolcob";	table_z="polcob";	break;
    case IDFACCLI      : seq_z = "seq_idfaccli";        campo_z = "idfaccli";	table_z="faccli";	break;
    case IDRENFACCLI   : seq_z = "seq_idrenfaccli";     campo_z = "idrenfaccli";	table_z="renfaccli";	break;
    case IDNOMIPOLMOV  : seq_z = "seq_idnomipolmov";    campo_z = "idnomipolmov";	table_z="nomi_polmov";	break;
    case IDNOMIRENPOLMOV : seq_z = "seq_idnomirenpolmov";    campo_z = "idnomirenpolmov";	table_z="nomi_renpolmov";	break;
    case IDNOMITPMOV   : seq_z = "seq_idnomi_tpmov";    campo_z = "idnomi_tpmov";     	table_z="nomi_tpmov";	break;
    case IDNOMIDEPTO   : seq_z = "seq_idnomidepto";	campo_z = "iddepto";     	table_z="nomi_deptos";	break;
    case IDNOMITURNO   : seq_z = "seq_idnomiturno";	campo_z = "idturno";     	table_z="nomi_turnos";	break;
    case IDNOMIDESTURNO: seq_z = "seq_idnomidesturno";	campo_z = "iddesturno";     	table_z="nomi_desturno";	break;
    case IDNOMITIPOEMP : seq_z = "seq_idnomitipoemp";	campo_z = "idtipoemp";     	table_z="nomi_tiposemp";	break;
    case IDNOMIMVREL   : seq_z = "seq_idnomimvrel";	campo_z = "idtipo";     	table_z="nomi_mvrel";	        break;
    case IDNOMIMOVTOSREL: seq_z = "seq_idnomimovtosrel"; campo_z = "idnomi_movtosrel";  table_z="nomi_movtosrel";	break;
    case IDNOMITIPONOMI: seq_z = "seq_idnomitiponomi"; campo_z = "idtiponomi";          table_z="nomi_tiponomi";        break;
    case IDNOMIGAFETE  : seq_z = "seq_idnomigafete";	campo_z = "idgafete";     	table_z="nomi_gafete";	break;
    case IDNOMIRELOJ   : seq_z = "seq_idnomireloj";	campo_z = "idnomi_reloj";     	table_z="nomi_reloj";	break;
    case IDNOMIENTSAL  : seq_z = "seq_idnomientsal";	campo_z = "idnomi_entsal";     	table_z="nomi_entsal";	break;
    case IDPOLSER      : seq_z = "seq_idpolser";        campo_z = "idpolser";	table_z="polser";	break;
    case PAIS          : seq_z = "seq_ctpaises";        campo_z = "idpais";	table_z="ctpaises";	break;
    case ESTADO        : seq_z = "seq_ctestados";       campo_z = "idestado";	table_z="ctestados";	break;
    case COLONIA       : seq_z = "seq_ctcolonias";      campo_z = "idcolonia";	table_z="ctcolonias";	break;
    case CALLE         :
    case CRUZMTOS      :
    case CRUZMTO2      : seq_z = "seq_ctcalles";        campo_z = "idcalle";	table_z="ctcalles";	break;
    case NUMERO        :
    case NUMINT        : seq_z = "seq_ctdirnum";        campo_z = "iddirnum";	table_z="ctdirnum";	break;
    case CODPOST       : seq_z = "seq_ctcodpost";       campo_z = "idcodpost";	table_z="ctcodpost";    break;

    case IDMAYORIS     : seq_z = "seq_idmayoris"; campo_z="idmayoris"; table_z = "mayoris";   break;
    case IDPROVE       : seq_z = "seq_idprove";   campo_z="idprove";   table_z="prove";       break;
    case IDGPOINV      : seq_z = "seq_idgrupoinv"; campo_z="idgrupo"; table_z="inv_grupos";  break;
    case IDMARCAINV      : seq_z = "seq_marcainv"; campo_z="idmarcainv"; table_z="inv_marcas";  break;
    case IDGPODIARY    : seq_z = "seq_idgpodiary"; campo_z="idgpodiary"; table_z="gpodiary";  break;
    case IDART         : seq_z = "seq_idart"; campo_z="idart"; table_z="inven";  break;
    case IDENTRADA     : seq_z = "seq_identrada"; campo_z="identrada"; table_z="entradas"; break;
    case IDRENENTRA    : seq_z = "seq_idrenentra"; campo_z="idrenentra"; table_z="renentra"; break;
    case IDMOVART      : seq_z = "seq_idmovart"; campo_z="idmovart"; table_z="movart"; break;
    case IDESTADIS     : seq_z = "seq_idestadis"; campo_z="idestadis"; table_z="estadis"; break;
    case IDFACTURMA    : seq_z = "seq_idfacturma"; campo_z="idfactur"; table_z="facturma"; break;
    case IDVENFACMA    : seq_z = "seq_idvenfacma"; campo_z="idvenfacma"; table_z="venfacma"; break;
    case IDRENFACMA    : seq_z = "seq_idrenfacma"; campo_z="idrenfacma"; table_z="renfacma"; break;
    case IDSERIEFACMA  : seq_z = "seq_idseriefacma"; campo_z = "idseriefacma"; table_z = "seriefacma"; break;
    case IDMOVMAY      : seq_z = "seq_idmovmay"; campo_z = "idmovmay"; table_z = "movmay"; break;
    case IDLINEA_INV   : seq_z = "seq_idlinea"; campo_z = "idlinea"; table_z = "lineas"; break;
    case IDOBSLIN      : seq_z = "seq_idobslin"; campo_z = "idobslin"; table_z = "obslin"; break;
    case IDPEDIDO      : seq_z = "seq_idpedido"; campo_z="idpedido"; table_z="pedidos"; break;
    case IDRENPEDIDO   : seq_z = "seq_idrenpedido"; campo_z="idrenpedido"; table_z="renpedido"; break;
    case IDPOLCOBMA    : seq_z = "seq_idpolcobma"; campo_z="idpolcobma"; table_z="polcobma"; break;
    case IDRENPOLCOBMA : seq_z = "seq_idrenpolcobma"; campo_z="idrenpolcobma"; table_z="renpolcobma"; break;
    case IDMOVMAY2     : seq_z = "seq_idmovmay2"; campo_z="idmov"; table_z="movmay2"; break;
    case IDENTPAG      : seq_z = "seq_identpag"; campo_z="identpag"; table_z="entpag"; break;
    case IDMVENTPAG    : seq_z = "seq_idmventpag"; campo_z="idmventpag"; table_z="mventpag"; break;
    case IDOBSERVENT   : seq_z = "seq_idobservent"; campo_z="idobservent"; table_z="observent"; break;
    case IDVTACEL      : seq_z = "seq_invvtacel"; campo_z="idvtacel"; table_z="inv_vtacel"; break;
    case IDSITUAC      : seq_z = "seq_invsituaciones"; campo_z="idsituac"; table_z="inv_situaciones"; break;
    case IDINVRELVTAS  : seq_z = "seq_invrelvtas"; campo_z="idrelvtas"; table_z="inv_relvtas"; break;
    case IDINVDIRVTA   : seq_z = "seq_invdirvta";  campo_z="iddirvta"; table_z="inv_dirvta"; break;
    case IDINVRELVTAART: seq_z = "seq_invrelvtaart";  campo_z="idrelvtaart"; table_z="inv_relvtaart"; break;
    case IDINVRELTRANSF: seq_z = "seq_invreltransf";  campo_z="idreltransf"; table_z="inv_reltransf"; break;
    case IDINVDATRELTRANSF: seq_z = "seq_invdatreltransf";  campo_z="iddatreltransf"; table_z="inv_datreltransf";       break;
    case INV_IDPLAZOCRD: seq_z = "seq_idplazocrd"; campo_z="idplazocrd"; table_z="plazoscrd";                           break;
    case MAY_RELAC     : seq_z = "seq_idmayrelac"; campo_z="idrelac"; table_z="may_relac";                              break;
    case MAY_TIPOSTEL  : seq_z = "seq_idmaytipostel"; campo_z="idtipotel"; table_z="may_tipostel";                      break;
    case IDVNDPTOVT    : seq_z = "seq_idvndptovt";    campo_z="idvndptovt"; table_z="inv_vndptovt";                     break;
    case IDPOLRELVTA   : seq_z = "seq_polrelvta";    campo_z="idpolrelvta"; table_z="inv_polrelvta";                    break;
    case IDTICTE       : seq_z = "seq_car_tiposctes";    campo_z="idticte"; table_z="car_tiposctes";                    break;
    case IDTIPOENTREGA : seq_z = "seq_inv_tipoentrega";  campo_z="idtipoentrega"; table_z="inv_tipoentrega";            break;
    case IDCOMPROMETART: seq_z = "seq_inv_comprometart";  campo_z="idcomprometart"; table_z="inv_comprometart";         break;
    case INVIDAGENDAENTREGA: seq_z = "seq_inv_agendaentrega";  campo_z="idagenda"; table_z="inv_agendaentrega";         break;
    case INVIDRENAGENDAENTREGA: seq_z = "seq_inv_renagendaentrega";  campo_z="idrenagenda"; table_z="inv_renagendaentrega"; break;
    case INVIDRENAGENDAART : seq_z = "seq_inv_renagendaart";  campo_z="idrenagendaart"; table_z="inv_renagendaart";     break;
    case INV_IDFACTORPRECIOMAY : seq_z = "seq_inv_gpomayprecio";  campo_z="idgpomayprecio"; table_z="inv_gpomayprecio"; break;
    case IDDATOSENT     : seq_z = "seq_inv_datosent";  campo_z="iddatosent"; table_z="inv_datosent";                    break;
    case IDPOLCAMPRE    : seq_z = "seq_inv_polcampre";  campo_z="idpolcampre"; table_z="inv_polcampre";                 break;
    case IDRENPOLCAMPRE : seq_z = "seq_inv_renpolcampre";  campo_z="idrenpolcampre"; table_z="inv_renpolcampre";        break;
    case IDPOLOFERTAS    : seq_z = "seq_inv_polofertas";  campo_z="idpolcampre"; table_z="inv_polofertas";              break;
    case IDRENPOLOFERTAS : seq_z = "seq_inv_renpolofertas";  campo_z="idrenpolcampre"; table_z="inv_renpolofertas";     break;
    case IDEXTENSA      : seq_z = "seq_inv_extensa";  campo_z="idextensa"; table_z="inv_extensa";                       break;
    case IDRELINV       : seq_z = "seq_inv_relinv";  campo_z="idrelinv"; table_z="inv_relinv";                          break;
    case IDCARESTADOS   : seq_z = "seq_car_estados";  campo_z="idestado"; table_z="car_estados";                        break;
    case CAR_RELPOB_INV : seq_z = "seq_car_relpobs";  campo_z="idrelpob"; table_z="car_relpobs";                        break;
    case IDMEGAZONAINV  : seq_z = "seq_inv_megazonas";  campo_z="idmegazona"; table_z="inv_megazonas";                  break;
    case IDMEGAZONADETINV : seq_z = "seq_inv_megazonasdet";  campo_z="idmegazonadet"; table_z="inv_megazonasdet";       break;
    case IDSATPRODSERV  : seq_z = "seq_inv_catprodsat";  campo_z="idprod"; table_z="inv_catprodsat";                    break;
    case IDSATUSOCFDI   : seq_z = "seq_inv_catusocfdisat";  campo_z="idusocfdi"; table_z="inv_catusocfdisat";           break;
    case INVRELUBIPTOVTA : seq_z = "seq_inv_relubiptovta";  campo_z="idrelubiptovta"; table_z="inv_relubiptovta";       break;
    case IDGPOINTERNET   : seq_z = "seq_inv_gruposinternet";  campo_z="idgrupo"; table_z="inv_gruposinternet";       break;
    case IDSATREGIMEN    : seq_z = "seq_inv_regimenfiscal";  campo_z="idregimen"; table_z="inv_regimenfiscal";       break;
  }
  if(secuen_z == "S") {
    qry_iddato->SQL->Add(sequen1_z + seq_z +sequen2_z);
  } else {
    qry_iddato->SQL->Add(sequen1_z + campo_z +sequen2_z + " " + table_z + " where " + campo_z + " > 0");
  }
  qry_iddato->Open();
  iddato_z = qry_iddato->FieldByName("ultid")->AsInteger;
  if(secuen_z != "S") ++iddato_z;
  qry_iddato->Close();
  return(iddato_z);
}
//---------------------------------------------------------------------------

String __fastcall Tdm::font_impre(int impre, int font)
{
  String fnt_z, secuen_z;
  char car_z, cad_z[50];
  memset(cad_z, 0, 50);
  int ii_z=0;
  qry_fonts->Close();
  qry_fonts->ParamByName("impre")->AsInteger = impre;
  qry_fonts->ParamByName("font")->AsInteger = font;
  qry_fonts->Open();
  if(!qry_fonts->IsEmpty()) {
    secuen_z=qry_fonts->FieldByName("secuen")->AsString;
    for(ii_z = 1; ii_z <= qry_fonts->FieldByName("ncars")->AsInteger; ii_z++) {
      car_z = secuen_z.SubString( ( (ii_z -1)*3 + 1   ), 3).ToIntDef(0);
      cad_z[ii_z - 1] = car_z;
    }
  }
  fnt_z = cad_z;
  return (fnt_z);
}
//---------------------------------------------------------------------------

double __fastcall Tdm::inianuestadis()
{
  double fecinianu_z;
  String seqfecinianu_z="select fecorte from inv_corteanu where cia = " + IntToStr(cia_z);
  qry_iddato->Close();
  qry_iddato->SQL->Text = seqfecinianu_z;
  qry_iddato->Open();
  if(!qry_iddato->IsEmpty()) {
    fecinianu_z = qry_iddato->FieldByName("fecorte")->AsDateTime;
  } else {
    unsigned short dia_z=0, mes_z=0, anu_z=0;
    DecodeDate(Now(), anu_z, mes_z, dia_z);
    // if(mes_z < 6) anu_z--; Ya no se toma en Cuenta el Anu Anterior DRBR 25-Ene-2004
    dia_z=1; mes_z=1;
    fecinianu_z = EncodeDate((Word)anu_z, (Word)mes_z, (Word)dia_z);
  }
  seqfecinianu_z = DateToStr(fecinianu_z);
  return(fecinianu_z);
}
//---------------------------------------------------------------------------

String __fastcall Tdm::busca_inifile()
{
   char direc_z[200];
   String  strdir_z, miprog_z;
   if(config_z.IsEmpty()) {
     getcurdir(0, direc_z);
     strdir_z = direc_z;
     miprog_z = ExtractFileName(ChangeFileExt( Application->ExeName, ".INI"));
     config_z = "";
     config_z += "\\" + strdir_z + "\\" + miprog_z;
     if (!DirectoryExists("recibos")) {
        if (!CreateDir("recibos"))
        throw Exception("No se pudo crear directorio recibos");
     }
   }
   return (config_z);
}

void __fastcall Tdm::MensajeError(String error_z, String caption_z)
{
  Application->MessageBox(error_z.c_str(), caption_z.c_str(), MB_ICONEXCLAMATION);
}
//---------------------------------------------------------------------------


double Tdm::calcu_prmay(String codigo_z, int tipomayoris_z)
{
  double mubmds_z=0, costo_z=0, preciou_z=0, costos_z=0,
    piva_z =0, factorprecio_z=0;
  String gpoesp_z="", empaqe_z = "", prove_z,
         sqlgpoesp_z, sqlinven_z, sqlpreciomaypro_z;
  int mitipomay_z;
  TQuery *qry_inven              = new TQuery (this);
  TQuery *qry_preciomaypro       = new TQuery (this);
  TQuery *qry_grupoesp           = new TQuery (this);
  qry_inven->DatabaseName        = qry_permis->DatabaseName;
  qry_preciomaypro->DatabaseName = qry_permis->DatabaseName;
  qry_grupoesp->DatabaseName     = qry_permis->DatabaseName;
  sqlgpoesp_z = " select a.codigo, b.codigo as grupo, c.* ";
  sqlgpoesp_z += " from inv_invhist a join inv_relinv d on a.idart = d.idart";
  sqlgpoesp_z += " and d.idrel = :TIPOREL join inv_grupos b on d.iddato = b.idgrupo ";
  sqlgpoesp_z += " join inv_gpomayprecio c on b.idgrupo = c.idgrupo ";
  sqlgpoesp_z += " where a.codigo = :CODIGO and a.cia = :CIA and c.tipo = :TIPOMAY";
  sqlinven_z  = "select * from inven where codigo = :CODIGO and cia = :CIA";

  sqlpreciomaypro_z = "select idplazocrd, a.linea as prove, a.idlinea, plistamax as factorprecio, a.tipo, a.cia";
  sqlpreciomaypro_z += " from plazoscrd a";
  sqlpreciomaypro_z += " where a.linea = :PROVE and a.cia = :CIA and  a.tipo = :TIPO";

  qry_inven->SQL->Text        =  sqlinven_z;
  qry_grupoesp->SQL->Text     = sqlgpoesp_z;
  qry_preciomaypro->SQL->Text = sqlpreciomaypro_z;

  qry_inven->Close();
  qry_inven->ParamByName("codigo")->AsString = codigo_z;
  qry_inven->ParamByName("cia")->AsString = cia_z;
  qry_inven->Open();
  if(!qry_inven->IsEmpty()) {
    codigo_z = qry_inven->FieldByName("codigo")->AsString;
    preciou_z = qry_inven->FieldByName("precio")->AsFloat;
    piva_z = qry_inven->FieldByName("piva")->AsFloat;
    costo_z = qry_inven->FieldByName("costos")->AsFloat;
    empaqe_z = qry_inven->FieldByName("empaqe")->AsString;
    prove_z =  qry_inven->FieldByName("prove")->AsString;
    qry_preciomaypro->Close();
    qry_preciomaypro->ParamByName("prove")->AsString = prove_z;
    qry_preciomaypro->ParamByName("cia")->AsInteger = cia_z;
    qry_preciomaypro->ParamByName("tipo")->AsInteger = TIPO_FACTOR_PRECIOMAYPRO;
    qry_preciomaypro->Open();
    if(!qry_preciomaypro->IsEmpty()) {
       gpoesp_z = "G";
       factorprecio_z = qry_preciomaypro->FieldByName("factorprecio")->AsFloat;
       qry_preciomaypro->Close();
       if(factorprecio_z == 0) factorprecio_z = 1;
       preciou_z = Redondea( costo_z / factorprecio_z, 100);
    } else {
      qry_grupoesp->Close();
      qry_grupoesp->ParamByName("codigo")->AsString = codigo_z;
      qry_grupoesp->ParamByName("cia")->AsInteger = cia_z;
      qry_grupoesp->ParamByName("tiporel")->AsInteger = REL_INVEN_ARTDESP;
      qry_grupoesp->ParamByName("TIPOMAY")->AsInteger = tipomayoris_z;
      qry_grupoesp->Open();
      if(qry_grupoesp->IsEmpty()) {
        gpoesp_z = "N"; factorprecio_z = 0;
      } else {
        mitipomay_z = qry_grupoesp->FieldByName("tipo")->AsInteger;
        if(tipomayoris_z == mitipomay_z) {
           if(tipomayoris_z == TIPO_FILIAL)          gpoesp_z = "S";
           if(tipomayoris_z == TIPO_MAYORISTA)       gpoesp_z = "S";
           factorprecio_z = qry_grupoesp->FieldByName("factorprecio")->AsFloat;
        } else {
          gpoesp_z = "N"; factorprecio_z = 0;
        }
      }
    }
    preciou_z = Redondea(calcu_preciomay(empaqe_z, costo_z, preciou_z, piva_z, gpoesp_z, factorprecio_z), 100);

  }
  delete qry_grupoesp;
  delete qry_inven;
  delete qry_preciomaypro;

  return(preciou_z);
}
//---------------------------------------------------------------------------


void __fastcall Tdm::conecta_db_anuanter()
{
  String paso_z;
  paso_z = "0";
  if ( !db_anuanter->Connected) {
     db_anuanter->AliasName = bdanuanter_z;
     try {
       db_anuanter->Connected = true;
     }  catch (Exception &E)
     {
       Application->MessageBox(("Base datos:"+ bdanuanter_z +
         "\nConfig:"+config_z+
         "\nAnu anter:" + bdanuanter_z +
         "\nNo pude conectarme a la base de datos:\n"+E.Message).c_str(), "Error", MB_ICONEXCLAMATION);
     }
  }
}
//---------------------------------------------------------------------------

void __fastcall Tdm::desconecta_db_anuanter()
{
  if( db_anuanter->Connected)  db_anuanter->Connected = false;
}
//---------------------------------------------------------------------------

String Tdm::busca_pais_estado(String tipobus_z, String poblac_z)
{
  int nref_z=0, REL_POB_ESTADO=2, REL_ESTADO_PAIS=3;
  String dato_z="", sql_z;
  if(tipobus_z == "PAIS" || tipobus_z == "ESTADO" ) {
    if(tipobus_z == "ESTADO" ) {
        sql_z = "select c.nombre from poblacs a join car_relpobs b on \
          a.numero = b.iddato1 and b.tiporel= ";
        sql_z += IntToStr(REL_POB_ESTADO);
        sql_z += " join car_estados c on b.iddato2 = c.idestado ";
        sql_z += " where a.nombre = '" + poblac_z + "'";
    }
    if(tipobus_z == "PAIS") {
        sql_z = "select c.nombre from poblacs a join car_relpobs b on \
          a.numero = b.iddato1 and b.tiporel= ";
        sql_z += IntToStr(REL_POB_ESTADO);
        sql_z += " join car_relpobs d on b.iddato2 = d.iddato1 and d.tiporel = ";
        sql_z += IntToStr(REL_ESTADO_PAIS);
        sql_z += " join car_estados c on d.iddato2 = c.idestado ";
        sql_z += " where a.nombre = '" + poblac_z + "'";
    }
    dm->qry_maxidvnd->Close();
    dm->qry_maxidvnd->SQL->Text = sql_z;
    dm->qry_maxidvnd->Open();
    if(!dm->qry_maxidvnd->IsEmpty()) {
      dato_z = dm->qry_maxidvnd->FieldByName("nombre")->AsString;
    }
  }
  return (dato_z);

}
//---------------------------------------------------------------------------

String __fastcall Tdm::obten_nombre(String tipo_z, String clave_z)
{
  String sql_z, nombre_z;
  if(tipo_z == "MAY") {
    sql_z = "select nombre from mayoris where codigo = :DATO";
  }
  qry_iddato->Close();
  qry_iddato->SQL->Text = sql_z;
  qry_iddato->ParamByName("dato")->AsString = clave_z;
  qry_iddato->Open();
  if(!qry_iddato->IsEmpty()) nombre_z = qry_iddato->FieldByName("nombre")->AsString;
  qry_iddato->Close();
  return (nombre_z);

}
//---------------------------------------------------------------------------

