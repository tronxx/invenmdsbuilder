//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantciu.h"
#include "dmod.h"
#include "Frme_datosmarca.h"
#include "dialg_okcancel.h"
#include "Frme_importa.h"
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
TForm_mantciu *Form_mantciu;
//---------------------------------------------------------------------------
__fastcall TForm_mantciu::TForm_mantciu(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantciu::borraExecute(TObject *Sender)
{
  int idciu_z=0;
  String dato_z;
  dato_z = dbgrd_ciudadesCIUDAD->Caption;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_ciudades->IsEmpty()) return;
  idciu_z = qry_ciudades->FieldByName("numero")->AsInteger;
  if(Application->MessageBox(("Esta Seguro de Eliminar esta " + dato_z + " ?").c_str(), ("Eliminar " + dato_z).c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_ciudades->Delete();
      qry_ciudades->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantciu::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantciu::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_ptvt(NUEVO); break;
    case MODIF: modif_ptvt(); break;
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantciu::desp_ptvt()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantciu::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt(NUEVO);
}
//---------------------------------------------------------------------------




void __fastcall TForm_mantciu::alta_ptvt(int modo_z)
{
   int idciu_z, idestado_z, idrelpob_z;
   String nombre_z, estado_z, status_z;
   TDateTime fecbaj_z;
   Tdlg_okcancel* Dlg_datos;
   Dlg_datos = new Tdlg_okcancel (this);
   TFrame_datosmarca *Frame_datosmarca;
   Frame_datosmarca = new TFrame_datosmarca(Dlg_datos);
   Dlg_datos->Caption = "Datos de " + dbgrd_ciudadesCIUDAD->Caption;
   Frame_datosmarca->Parent = Dlg_datos->Panel1;
   Frame_datosmarca->edt_codigo->Visible = false;
   Frame_datosmarca->lbl_codigo->Visible = false;
   if(idtipodato_z == INV_IDPOBLAC ){
      Frame_datosmarca->lbl_status->Visible = false;
      Frame_datosmarca->cmb_status->Visible = false;
      Frame_datosmarca->inicializa("CIUDAD");
   }
   if(idtipodato_z == IDCARESTADOS) Frame_datosmarca->inicializa("ESTADO");
   if(Dlg_datos->ShowModal() == mrOk) {
     try {
       dm->manvehi->StartTransaction();
       idciu_z = dm->busca_sigid(idtipodato_z);
       nombre_z = Frame_datosmarca->edt_nombre->Text.Trim();
       if( tipodato_z == MANTOCIUDADES || tipodato_z == MANTOESTADOS || tipodato_z == MANTOPAISES) {
         idestado_z = Frame_datosmarca->qry_estados->FieldByName("idestado")->AsInteger;
         estado_z = Frame_datosmarca->qry_estados->FieldByName("nombre")->AsString;
       }
       qry_ciudades->Append();
       qry_ciudades->FieldByName("nombre")->AsString = nombre_z;
       if( tipodato_z == MANTOCIUDADES) {
         qry_ciudades->FieldByName("numero")->AsInteger = idciu_z;
         qry_ciudades->FieldByName("status")->AsString = "A";
         qry_ciudades->FieldByName("idestado")->AsInteger = idestado_z;
         qry_ciudades->FieldByName("estado")->AsString = estado_z;
       }
       if( tipodato_z == MANTOESTADOS) {
         qry_ciudades->FieldByName("numero")->AsInteger = idciu_z;
         qry_ciudades->FieldByName("idpais")->AsInteger = idestado_z;
         qry_ciudades->FieldByName("pais")->AsString = estado_z;
         qry_ciudades->FieldByName("tipo")->AsInteger = TIPO_ESTADO_INV;
       }
       if (tipodato_z == MANTOPAISES) {
         qry_ciudades->FieldByName("numero")->AsInteger = idciu_z;
         qry_ciudades->FieldByName("idpais")->AsInteger = idestado_z;
         qry_ciudades->FieldByName("pais")->AsString = estado_z;
         qry_ciudades->FieldByName("tipo")->AsInteger = TIPO_PAIS_INV;
       }
       qry_ciudades->Post();
       agrega_rel_pob(idciu_z, idestado_z);
       qry_ciudades->ApplyUpdates();
       if(qry_carrelpob->UpdatesPending) qry_carrelpob->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }
   delete Frame_datosmarca;
   delete Dlg_datos;
   qry_ciudades->Tag = SI_REFRESH;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantciu::agrega_rel_pob(int idciu_z, int idestado_z)
{
  int idrelpob_z=0;
  qry_carrelpob->Close();
  qry_carrelpob->ParamByName("idrelpob")->AsInteger = -1;
  qry_carrelpob->ParamByName("tiporel")->AsInteger = tiporel_z;
  qry_carrelpob->ParamByName("iddato1")->AsInteger = idciu_z;
  qry_carrelpob->Open();
  if(qry_carrelpob->IsEmpty()) {
     idrelpob_z = dm->busca_sigid(CAR_RELPOB_INV);
     qry_carrelpob->Append();
     qry_carrelpob->FieldByName("idrelpob")->AsInteger = idrelpob_z;
     qry_carrelpob->FieldByName("tiporel")->AsInteger = tiporel_z;
     qry_carrelpob->FieldByName("iddato1")->AsInteger = idciu_z;
  } else {
     qry_carrelpob->Edit();
  }
  qry_carrelpob->FieldByName("iddato2")->AsInteger = idestado_z;
  qry_carrelpob->Post();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantciu::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantciu::botones_onoff(int modo_z)
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

void __fastcall TForm_mantciu::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_ptvt(IntToStr(dm->qry_maxidvnd->FieldByName("idciudad")->AsInteger));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantciu::busca_ptvt(String ptvt_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantciu::FormCreate(TObject *Sender)
{
  permis_z=dm->busca_permision(MANTOCIUD);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantciu::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantciu::AsignaTipo(int TIPO_MANTO)
{
  String sql_z, sqlins_z, sqldel_z, sqlmod_z, nombreparam_z;
  qry_ciudades->Close();
  switch ( TIPO_MANTO ) {
    case MANTOCIUDADES:
      dbgrd_ciudadesCIUDAD->Caption = "Ciudad";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      dbgrd_ciudadesESTADO->Caption = "Estado";
      dbgrd_ciudadesESTADO->FieldName = "estado";
      dbgrd_ciudadesESTADO->Visible = true;
      dbgrd_ciudades->KeyField = "numero";
      sql_z  = "select a.nombre, a.numero, b.idestado, b.nombre as estado, ";
      sql_z  += " a.status, a.fecbaj";
      sql_z  += " from poblacs a join car_relpobs c on a.numero = c.iddato1 ";
      sql_z  += " join car_estados b on c.iddato2 = b.idestado ";
      sql_z  += " where c.tiporel = " + IntToStr(REL_CIUDAD_ESTADO_INV);
      sql_z  += " order by b.nombre, a.nombre";
      sqlmod_z = "update poblacs set NOMBRE = :NOMBRE, STATUS = :STATUS, FECBAJ = :FECBAJ where NUMERO = :OLD_NUMERO ";
      sqldel_z = "delete from poblacs where NUMERO = :OLD_NUMERO";
      sqlins_z = "insert into poblacs (NOMBRE, NUMERO, STATUS, FECBAJ) values (:NOMBRE, :NUMERO, :STATUS, :FECBAJ)";
      Caption  = "Mantenimiento de Ciudades";
      idtipodato_z = INV_IDPOBLAC;
      tiporel_z = REL_CIUDAD_ESTADO_INV;
      mantotipo_z = MANTOCIUDADES;
      break;
    case MANTOESTADOS:
      dbgrd_ciudadesCIUDAD->Caption = "Estado";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      dbgrd_ciudadesESTADO->Caption = "Pais";
      dbgrd_ciudadesESTADO->FieldName = "pais";
      dbgrd_ciudadesESTADO->Visible = true;
      dbgrd_ciudades->KeyField = "numero";
      sql_z   = "select a.idestado as numero, a.nombre, a.tipo, b.idestado as idpais, b.nombre as pais ";
      sql_z  += " from car_estados a join car_relpobs c on a.idestado = c.iddato1 ";
      sql_z  += " join car_estados b on c.iddato2 = b.idestado ";
      sql_z  += " where c.tiporel = " + IntToStr(REL_ESTADO_PAIS_INV);
      sql_z  += " and a.tipo = " + IntToStr(TIPO_ESTADO_INV);
      sql_z  += " order by b.nombre, a.nombre";
      sqlmod_z = "update car_estados set NOMBRE = :NOMBRE,  IDESTADO = :NUMERO, TIPO = :TIPO \
       where NUMERO = :OLD_NUMERO";
      sqldel_z = "delete from car_estados where IDESTADO = :OLD_NUMERO";
      sqlins_z = "insert into car_estados (NOMBRE, IDESTADO, TIPO) values (:NOMBRE, :NUMERO, :TIPO)";
      Caption  = "Mantenimiento de Estados";
      idtipodato_z = IDCARESTADOS;
      tiporel_z = REL_ESTADO_PAIS_INV;
      mantotipo_z = MANTOESTADOS;

      break;
    case MANTOPAISES:
      dbgrd_ciudadesCIUDAD->Caption = "Pais";
      dbgrd_ciudadesCIUDAD->FieldName = "Nombre";
      sql_z   = "select a.idestado as numero, a.nombre, a.tipo, b.idestado, b.nombre as pais ";
      sql_z  += " from car_estados a join car_relpobs c on a.idestado = c.iddato1 ";
      sql_z  += " join car_estados b on c.iddato2 = b.idestado ";
      sql_z  += " where c.tiporel = " + IntToStr(REL_ESTADO_PAIS_INV);
      sql_z  += " order by b.nombre, a.nombre";
      sqlmod_z = "update car_estados set NOMBRE = :NOMBRE,  IDESTADO = :NUMERO, TIPO = :TIPO \
       where NUMERO = :OLD_NUMERO";
      sqldel_z = "delete from car_estados where IDESTADO = :OLD_NUMERO";
      sqlins_z = "insert into car_estados (NOMBRE, IDESTADO, TIPO) values (:NOMBRE, :NUMERO, :TIPO)";
      Caption  = "Mantenimiento de Paises";
      idtipodato_z = IDCARESTADOS;
      mantotipo_z = MANTOPAISES;
      tiporel_z = -1;
      break;
    case MANTOTIPAGO:
      dbgrd_ciudadesCIUDAD->Caption = "Tipo pago";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select idtipago as numero, tipopago as nombre from fac_tipopago order by tipopago";
      sqlmod_z = "update fac_tipopago set TIPOPAGO = :NOMBRE,  idtipago = :NUMERO where idtipago = :OLD_NUMERO";
      sqldel_z = "delete from fac_tipopago where idtipago = :OLD_NUMERO";
      sqlins_z = "insert into fac_tipopago (idtipago, tipopago) values (:NUMERO, :NOMBRE)";
      Caption  = "Mantenimiento de Tipos de Pago";
      idtipodato_z = IDTIPAGO;
      break;
    case MANTO_TITULOS:
      dbgrd_ciudadesCIUDAD->Caption = "Titulo";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select idtitulo as numero, titulo as nombre from vid_titulos order by titulo";
      sqlmod_z = "update vid_titulos  set titulo = :NOMBRE,  idtitulo = :NUMERO where idtitulo = :OLD_NUMERO";
      sqldel_z = "delete from vid_titulos where idtitulo = :OLD_NUMERO";
      sqlins_z = "insert into vid_titulos (titulo, idtitulo) values (:NOMBRE, :NUMERO)";
      Caption  = "Mantenimiento de Titulos de Películas";
      idtipodato_z = IDVIDTITULOS;
      break;
    case MANTO_ACTORES:
      dbgrd_ciudadesCIUDAD->Caption = "Actor";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select idactor as numero, actor as nombre from vid_actores order by actor";
      sqlmod_z = "update vid_actores set actor = :NOMBRE where idtitulo = :OLD_NUMERO";
      sqldel_z = "delete from vid_actores where idactor = :OLD_NUMERO";
      sqlins_z = "insert into vid_actores (actor, idactor) values (:NOMBRE, :NUMERO)";
      Caption  = "Mantenimiento de Nombres de Actores";
      idtipodato_z = IDVIDACTORES;
      break;
    case MANTO_FILMADORAS:
      dbgrd_ciudadesCIUDAD->Caption = "Filamdora";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select idfilmadora as numero, filmadora as nombre from vid_filmadoras order by filmadora";
      sqlmod_z = "update vid_filmadoras set filmadora = :NOMBRE where idfilmadora = :OLD_NUMERO";
      sqldel_z = "delete from vid_filmadoras where idfilmadora = :OLD_NUMERO";
      sqlins_z = "insert into vid_filmadoras (filmadora, idfilmadora) values (:NOMBRE, :NUMERO)";
      Caption  = "Mantenimiento de Casas Filmadoras";
      idtipodato_z = IDVIDFILMADORAS;
      break;
    case MANTO_GENEROS:
      dbgrd_ciudadesCIUDAD->Caption = "Genero";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select idgenero as numero, genero as nombre from vid_generos order by genero";
      sqlmod_z = "update vid_generos set genero= :NOMBRE where idgenero = :OLD_NUMERO";
      sqldel_z = "delete from vid_generos where idgenero = :OLD_NUMERO";
      sqlins_z = "insert into vid_generos (genero, idgenero) values (:NOMBRE, :NUMERO)";
      Caption  = "Mantenimiento de Generos de Películas";
      idtipodato_z = IDVIDGENEROS;
      break;
    case MANTO_CLASIFIC:
      dbgrd_ciudadesCIUDAD->Caption = "Clasificación";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select idclasifica as numero, clasifica as nombre from vid_clasifica order by clasifica";
      sqlmod_z = "update vid_clasifica set clasifica = :NOMBRE where idclasifica = :OLD_NUMERO";
      sqldel_z = "delete from vid_clasifica where idclasifica = :OLD_NUMERO";
      sqlins_z = "insert into vid_clasifica (clasifica, idclasifica) values (:NOMBRE, :NUMERO)";
      Caption  = "Mantenimiento de Clasificaciones de Peliculas";
      idtipodato_z = IDVIDCLASIFICA;
      break;
    case MANTO_DIRECTORES:
      dbgrd_ciudadesCIUDAD->Caption = "Director";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select iddirector as numero, director as nombre from vid_directores order by director";
      sqlmod_z = "update vid_directores set director = :NOMBRE where iddirector = :OLD_NUMERO";
      sqldel_z = "delete from vid_directores where iddirector = :OLD_NUMERO";
      sqlins_z = "insert into vid_directores (director, iddirector) values (:NOMBRE, :NUMERO)";
      Caption  = "Mantenimiento de Directores de Peliculas";
      idtipodato_z = IDVIDDIRECTORES;
      break;
    case MANTO_TIPOS:
      dbgrd_ciudadesCIUDAD->Caption = "Tipo";
      dbgrd_ciudadesCIUDAD->FieldName = "nombre";
      sql_z    = "select idtipo as numero, tipo as nombre from vid_tipo order by tipo";
      sqlmod_z = "update vid_tipo set tipo = :NOMBRE where idtipo = :OLD_NUMERO";
      sqldel_z = "delete from vid_tipo where idtipo = :OLD_NUMERO";
      sqlins_z = "insert into vid_tipo (tipo, idtipo) values (:NOMBRE, :NUMERO)";
      Caption  = "Mantenimiento de Tipos de Peliculas";
      idtipodato_z = IDVIDTIPOS;
      break;
  }
  qry_ciudades->SQL->Text = sql_z;
  uqry_poblacs->ModifySQL->Text= sqlmod_z;
  uqry_poblacs->DeleteSQL->Text= sqldel_z;
  uqry_poblacs->InsertSQL->Text= sqlins_z;
  tipodato_z = TIPO_MANTO;
  qry_ciudades->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantciu::exportaExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  midbgrd_z = dbgrd_ciudades;
  SaveDialog->Filter = "Archivos de Texto (*.csv)|*.CSV|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
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

void __fastcall TForm_mantciu::importaExecute(TObject *Sender)
{
  Tdlg_okcancel* Dlg_datos;
  TLocateOptions Opts;
  TStringList *noagregados_z = new TStringList();
  String errores_z, dato_z, nombre_z, cvetipotercero_z;
  int idciu_z, codigo_z, ultcod_z,
    COL_NOMBRE      = 0,
  ii_z=0;
  TDateTime fecha_z;
  Dlg_datos = new Tdlg_okcancel (this);
  TFrame_importa *Frame_importa;
  Frame_importa = new TFrame_importa (Dlg_datos);
  double limcred_z=0;
  idciu_z = dm->busca_sigid(idtipodato_z);
  ultcod_z = 1;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Clear();
  dm->qry_maxidvnd->SQL->Add("select max (codigo) as codigo from clien where cia="+IntToStr(cia_z));
  dm->qry_maxidvnd->Open();
  if(!dm->qry_maxidvnd->IsEmpty()) {
    ultcod_z = dm->qry_maxidvnd->FieldByName("codigo")->AsInteger;
  }
  Dlg_datos->Caption = "Importación de " + dbgrd_ciudadesCIUDAD->Caption;
  Dlg_datos->AutoSize = false;
  Dlg_datos->Width = Frame_importa->Width + 20;
  Dlg_datos->Height = Frame_importa->Height + 80;
  Frame_importa->Parent = Dlg_datos->Panel1;
  Frame_importa->Align = alTop;
  qry_ciudades->DisableControls();

  if(Dlg_datos->ShowModal() == mrOk) {
    for(ii_z=1; ii_z < Frame_importa->sgrd_datos->RowCount; ii_z++ ) {
       qry_ciudades->First();
       nombre_z = Frame_importa->sgrd_datos->Cells[COL_NOMBRE][ii_z].Trim();
       qry_ciudades->First();
       if(!qry_ciudades->Locate("nombre", nombre_z, Opts)) {
         qry_ciudades->Append();
         qry_ciudades->FieldByName("numero")->AsInteger = idciu_z++;
         qry_ciudades->FieldByName("nombre")->AsString = nombre_z;
         qry_ciudades->FieldByName("status")->AsString = "A";
         qry_ciudades->Post();
       } else {
         noagregados_z->Add("Registro:" + IntToStr(ii_z) + "\t" +
           nombre_z + "\t Ya Existe"
         );
       }
    }
    try {
      dm->manvehi->StartTransaction();
      if(qry_ciudades->UpdatesPending) qry_ciudades->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
    if(noagregados_z->Count)  {
      Tdlg_okcancel *Dlg_datos2 = new Tdlg_okcancel (this);
      TMemo *mmo_errores = new TMemo(Dlg_datos2);
      Dlg_datos2->Caption = "Errores en Importación";
      Dlg_datos2->AutoSize = false;
      mmo_errores->Parent = Dlg_datos2->Panel1;
      mmo_errores->Width = 200;
      mmo_errores->Height = 200;
      Dlg_datos2->Width = mmo_errores->Width + 20;
      Dlg_datos2->Height = mmo_errores->Height + 80;
      mmo_errores->Align = alTop;
      mmo_errores->ScrollBars = ssBoth;
      mmo_errores->Lines->Add("Registros no recibidos:");
      for ( ii_z = 0; ii_z < noagregados_z->Count; ii_z++) {
        mmo_errores->Lines->Add(noagregados_z->Strings[ii_z]);
      }
      Dlg_datos2->ShowModal();
      delete mmo_errores;
      delete Dlg_datos2;
    }

  }
  delete Frame_importa;
  delete Dlg_datos;
  qry_ciudades->Close();
  qry_ciudades->Open();
  qry_ciudades->EnableControls();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantciu::modificaExecute(TObject *Sender)
{
   int jj_z, idciu_z, idestado_z;
   String sq_z, nombre_z, estado_z, status_z;
   Tdlg_okcancel* Dlg_datos;
   TDateTime fecbaj_z;
   fecbaj_z = dm->ahora();
   Dlg_datos = new Tdlg_okcancel (this);
   TFrame_datosmarca *Frame_datosmarca;
   if(qry_ciudades->IsEmpty()) return;
   Frame_datosmarca = new TFrame_datosmarca(Dlg_datos);
   Dlg_datos->Caption = "Nombre de la Ciudad";
   Frame_datosmarca->Parent = Dlg_datos->Panel1;
   Frame_datosmarca->edt_codigo->Visible = false;
   Frame_datosmarca->lbl_codigo->Visible = false;
   Frame_datosmarca->lbl_nombre->Caption = "Nombre";
   Frame_datosmarca->edt_nombre->Text = qry_ciudades->FieldByName("nombre")->AsString;
   Frame_datosmarca->lbl_fecbaj->Visible = false;
   Frame_datosmarca->date_fecbaj->Visible = false;
   if(idtipodato_z == INV_IDPOBLAC) {
     Frame_datosmarca->inicializa("CIUDAD");
     Frame_datosmarca->lkcmb_estados->KeyValue = qry_ciudades->FieldByName("idestado")->AsInteger;
     if( idtipodato_z == INV_IDPOBLAC ) {
       Frame_datosmarca->lbl_status->Visible = true;
       Frame_datosmarca->cmb_status->Visible = true;
       status_z = qry_ciudades->FieldByName("status")->AsString;
       if(status_z == "A") {
         Frame_datosmarca->cmb_status->ItemIndex = 0;
       } else {
         Frame_datosmarca->cmb_status->ItemIndex = 1;
         Frame_datosmarca->lbl_fecbaj->Visible = true;
         Frame_datosmarca->date_fecbaj->Visible = true;
       }
     }

   }
   if(idtipodato_z == IDCARESTADOS) Frame_datosmarca->inicializa("ESTADO");
   if(Dlg_datos->ShowModal() == mrOk) {
     idciu_z = qry_ciudades->FieldByName("numero")->AsInteger;
     nombre_z = Frame_datosmarca->edt_nombre->Text.Trim();
     if (Frame_datosmarca->cmb_status->ItemIndex == 0) {
       status_z = "A";
     } else {
       status_z = "B";
       fecbaj_z = Frame_datosmarca->date_fecbaj->DateTime;
     }
     if( idtipodato_z == INV_IDPOBLAC || idtipodato_z == IDCARESTADOS ) {
       idestado_z = Frame_datosmarca->qry_estados->FieldByName("idestado")->AsInteger;
       estado_z = Frame_datosmarca->qry_estados->FieldByName("nombre")->AsString;
     }
     sq_z = uqry_poblacs->ModifySQL->Text;

     try {
       dm->manvehi->StartTransaction();
       qry_ciudades->Edit();
       qry_ciudades->FieldByName("numero")->AsInteger = idciu_z;
       qry_ciudades->FieldByName("nombre")->AsString = nombre_z;
       qry_ciudades->FieldByName("status")->AsString = status_z;
       qry_ciudades->FieldByName("fecbaj")->AsDateTime = fecbaj_z;
       if( idtipodato_z == INV_IDPOBLAC || idtipodato_z == ESTADO) {
         qry_ciudades->FieldByName("idestado")->AsInteger = idestado_z;
         qry_ciudades->FieldByName("estado")->AsString = estado_z;
       }
       jj_z = qry_ciudades->FieldByName("numero")->AsInteger;
       qry_ciudades->Post();
       agrega_rel_pob(idciu_z, idestado_z);
       qry_ciudades->ApplyUpdates();
       if(qry_carrelpob->UpdatesPending) qry_carrelpob->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }
   delete Frame_datosmarca;
   delete Dlg_datos;
   qry_ciudades->Tag = SI_REFRESH;

}
//---------------------------------------------------------------------------


void __fastcall TForm_mantciu::dbgrd_ciudadesKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_INSERT) nuevoExecute(Sender);
}
//---------------------------------------------------------------------------

