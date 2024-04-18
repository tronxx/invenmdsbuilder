//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantoptvt.h"
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBELib"
#pragma resource "*.dfm"

#include "situaciones.h"
TForm_mantoptvt *Form_mantoptvt;
//---------------------------------------------------------------------------
__fastcall TForm_mantoptvt::TForm_mantoptvt(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::botones_onoff(int modo_z)
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

void __fastcall TForm_mantoptvt::alta_vnd()
{
   int vendedor_z=0;
   String status_z, ciu_z;
   qry_clien->Close();
   qry_clien->ParamByName("codigo")->AsString= edt_codvnd->Text;
   qry_clien->ParamByName("cia")->AsInteger=cia_z;
   qry_clien->Open();
   if(!qry_clien->IsEmpty()) return;
 //  ciu_z = qry_ciudades->FieldByName("ciudad")->AsString;
//   numiden_z=dm->busca_iddato(edt_nombre->Text, ENFIMO);
//   idciudad_z=qry_ciudades->FieldByName("idciudad")->AsInteger;
//   iddir_z=dm->busca_iddato(edt_direc->Text, DIRECCION);
//   idtel_z=dm->busca_iddato(edt_tel->Text, TELEFONO);
//   idpuesto_z = qry_puestos->FieldByName("idpuesto")->AsInteger;
//   status_z = qry_status->FieldByName("status")->AsString;
   try {
     dm->manvehi->StartTransaction();
     //idvnd_z=dm->busca_sigid(IDEMPLEAD);
     qry_clien->Append();
     //qry_clien->FieldByName("idemplead")->AsInteger = idvnd_z;
     qry_clien->FieldByName("clave")->AsString = edt_codvnd->Text;
     qry_clien->FieldByName("nombre")->AsString = edt_nombre->Text;
     qry_clien->FieldByName("direc")->AsString = edt_direc->Text;
 //  qry_clien->FieldByName("poblac")->AsString = ciu_z;
     qry_clien->FieldByName("sdoini")->AsFloat = 0;
     qry_clien->FieldByName("impent")->AsFloat = 0;
     qry_clien->FieldByName("impsal")->AsFloat = 0;
     qry_clien->FieldByName("sdofin")->AsFloat = 0;
 //  qry_clien->FieldByName("telefono")->AsString = edt_tel->Text;
     qry_clien->FieldByName("cia")->AsInteger = cia_z;
     qry_clien->Post();
     qry_clien->ApplyUpdates();
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

void __fastcall TForm_mantoptvt::modif_vnd()
{
   int vendedor_z=0;
   String status_z, ciu_z;
   qry_clien->Close();
   qry_clien->ParamByName("codigo")->AsString= edt_codvnd->Text;
   qry_clien->ParamByName("cia")->AsInteger=cia_z;
   qry_clien->Open();
  // ciu_z = qry_ciudades->FieldByName("ciudad")->AsString;
   if(qry_clien->IsEmpty()) return;
  // ciu_z = qry_ciudades->FieldByName("ciudad")->AsString;
   try {
     dm->manvehi->StartTransaction();
     //idvnd_z=dm->busca_sigid(IDEMPLEAD);
     qry_clien->Edit();
     //qry_clien->FieldByName("idemplead")->AsInteger = idvnd_z;
     qry_clien->FieldByName("clave")->AsString = edt_codvnd->Text;
     qry_clien->FieldByName("nombre")->AsString = edt_nombre->Text;
     qry_clien->FieldByName("direc")->AsString = edt_direc->Text;
 //  qry_clien->FieldByName("poblac")->AsString = ciu_z;
 //    qry_clien->FieldByName("sdoini")->AsFloat = edt_porcom->Value;
 //    qry_clien->FieldByName("impent")->AsFloat = edt_comxc->Value;
 //    qry_clien->FieldByName("impsal")->AsFloat = edt_porcom->Value;
 //    qry_clien->FieldByName("sdofin")->AsFloat = edt_comxc->Value;

 //  qry_clien->FieldByName("tel")->AsString = edt_tel->Text;
 //    qry_clien->FieldByName("cia")->AsInteger = cia_z;
     qry_clien->Post();
     qry_clien->ApplyUpdates();
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

void __fastcall TForm_mantoptvt::edt_codvndKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{  if(Key == VK_RETURN) busca_vnd(edt_codvnd->Text.Trim());
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::desp_vnd()
{
  String ciu_z;
  int idciu_z=0;
  // edt_nombre->Text = qry_clien->FieldByName("nombre")->AsString;
  // lkcmb_ciudad->KeyValue=qry_clien->FieldByName("idciudad")->AsInteger;
  // edt_direc->Text=qry_clien->FieldByName("direc")->AsString;
  // edt_tel->Text=dm->busca_dato(qry_clien->FieldByName("tel")->AsString;
  //ciu_z = qry_clien->FieldByName("poblac")->AsString;
  //TLocateOptions Opts;
  //Opts.Clear();
  //if(qry_ciudades->Locate("ciudad", ciu_z, Opts)) {
  //  idciu_z = qry_ciudades->FieldByName("idciudad")->AsInteger;
  //}
   //lkcmb_ciudad->KeyValue = idciu_z;
    edt_codvnd->Text = qry_clien->FieldByName("clave")->AsString;
    edt_nombre->Text = qry_clien->FieldByName("nombre")->AsString;
    edt_direc->Text = qry_clien->FieldByName("direc")->AsString;
 // edt_rfc->Text = qry_clien->FieldByName("rfc")->AsString;
 // edt_porcom->Value = qry_clien->FieldByName("sdoini")->AsFloat;
 // edt_comxc->Value = qry_clien->FieldByName("impent")->AsFloat;

 // edt_tel->Text =qry_clien->FieldByName("telefono")->AsString;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoptvt::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  grabar->Tag = NUEVO;
  edt_codvnd->Text = "";
  edt_nombre->Text = "";
  edt_direc->Text = "";
  
  botones_onoff(INVISIBLES);
  edt_codvnd->SetFocus();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::grabarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
  switch(grabar->Tag) {
    case NUEVO: alta_vnd(); break;
    case MODIF: modif_vnd(); break;
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::cancelarExecute(TObject *Sender)
{
  botones_onoff(VISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::FormCreate(TObject *Sender)
{
  permis_z="N";
  cia_z = dm->cia_z;
  if(dm->usermaster_z != "S") {
    dm->qry_permis->Close();
    dm->qry_permis->ParamByName("idusuario")->AsInteger=dm->idusuario_z;
    dm->qry_permis->ParamByName("idpermis")->AsInteger=MANTOEMP;
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
  //qry_ciudades->Open();
  //qry_puestos->Open();
  //qry_status->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoptvt::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  busca_vnd(edt_codvnd->Text.Trim());
  if(qry_clien->IsEmpty()) return;
  grabar->Tag = MODIF;
  botones_onoff(INVISIBLES);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  qry_clien->Close();
  qry_clien->ParamByName("codigo")->AsString= edt_codvnd->Text;
  qry_clien->ParamByName("cia")->AsInteger=cia_z;
  qry_clien->Open();
  if(qry_clien->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Cliente ?", "Eliminar Cliente", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_clien->Delete();
      qry_clien->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_vnd(dm->qry_maxidvnd->FieldByName("clave")->AsString);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoptvt::busca_vnd(String vnd_z)
{
  int codvnd_z = 0;
  qry_clien->Close();
  qry_clien->ParamByName("codigo")->AsString = vnd_z;
  qry_clien->ParamByName("cia")->AsInteger = cia_z;
  qry_clien->Open();
  if(!qry_clien->IsEmpty()) {
        desp_vnd(); grabar->Tag = 0; botones_onoff(VISIBLES);
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoptvt::primeroExecute(TObject *Sender)
{
   mueve_hacia("select min (clave) as clave from ptovta where cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::anteriorExecute(TObject *Sender)
{
   mueve_hacia("select max (clave) as clave from ptovta where clave < '"+edt_codvnd->Text +"' and cia="+IntToStr(cia_z));

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::siguienteExecute(TObject *Sender)
{
   mueve_hacia("select min (clave) as clave from ptovta where clave > '"+edt_codvnd->Text + "' and cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoptvt::ultimoExecute(TObject *Sender)
{
   mueve_hacia("select max (clave) as clave from ptovta where cia="+IntToStr(cia_z));

}
//---------------------------------------------------------------------------






