//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantoalm.h"
#include "dmod.h"
#include "numapal.h"
#include "dialg_datosalm.h"
#include "dialg_okcancel.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxEditor"
#pragma link "dxEdLib"
#pragma link "dxExEdtr"
#pragma link "dxDBELib"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"

#include "situaciones.h"
TForm_mantoalm *Form_mantoalm;
//---------------------------------------------------------------------------
__fastcall TForm_mantoalm::TForm_mantoalm(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::alta_vnd(int modo_z)
{
  int vendedor_z=0, idstatus_z, idrelubiptovta_z, idubiptovta_z;
  String status_z, mialm_z = "-1";
  if(modo_z == MODIF) {
     mialm_z = qry_clien->FieldByName("clave")->AsString;
  }
  Tdlg_datosalm *dlg_datosalm = new Tdlg_datosalm (this);
  dlg_datosalm->asigna_tipo(tipo_z);
  qry_relubiptovta->Close();
  qry_relubiptovta->ParamByName("ptovta")->AsString = mialm_z;
  qry_relubiptovta->ParamByName("cia")->AsInteger = cia_z;
  qry_relubiptovta->Open();
  mialm_z = qry_relubiptovta->FieldByName("ptovta")->AsString;
  if (modo_z == MODIF) {
    dlg_datosalm->edt_codvnd->Text = qry_clien->FieldByName("clave")->AsString;
    dlg_datosalm->edt_nombre->Text = qry_clien->FieldByName("nombre")->AsString;
    dlg_datosalm->edt_direc->Text  = qry_clien->FieldByName("direc")->AsString;
    dlg_datosalm->edt_ordiary->IntValue = qry_clien->FieldByName("ordiary")->AsInteger;
    dlg_datosalm->edt_exib->Text       = qry_clien->FieldByName("exib")->AsString;
    dlg_datosalm->edt_ordtab->IntValue = qry_clien->FieldByName("ordtabt")->AsInteger;
    dlg_datosalm->lkcmb_zona->KeyValue = qry_clien->FieldByName("zona")->AsString;
    if(tipo_z == "PTOVTA") {
      idubiptovta_z = qry_relubiptovta->FieldByName("idubiptovta")->AsInteger;
      dlg_datosalm->lkcmb_relubivta->KeyValue = idubiptovta_z;
    }
    if (qry_clien->FieldByName("status")->AsString == "A") {
      idstatus_z = STATUS1 -1;
    } else {
      idstatus_z = STATUS2 -1;
    }
    dlg_datosalm->cmb_status->ItemIndex = idstatus_z;
  }
  if(dlg_datosalm->ShowModal() == mrOk) {
     clave_z   = dlg_datosalm->edt_codvnd->Text;
     nombre_z  = dlg_datosalm->edt_nombre->Text;
     direc_z   = dlg_datosalm->edt_direc->Text;
     ordiary_z = dlg_datosalm->edt_ordiary->IntValue;
     exib_z    = dlg_datosalm->edt_exib->Text;
     ordtab_z  = dlg_datosalm->edt_ordtab->IntValue;
     zona_z    = dlg_datosalm->qry_zonas->FieldByName("zona")->AsString;
     idstatus_z = dlg_datosalm->cmb_status->ItemIndex + 1;
     if(tipo_z == "PTOVTA") {
        idubiptovta_z = dlg_datosalm->qry_relubivta->FieldByName("idubiptovta")->AsInteger;
     }

     if (idstatus_z == STATUS1) {
       status_z = "A";
     } else {
       status_z = "B";
     }

     try {
       dm->manvehi->StartTransaction();
       //idvnd_z=dm->busca_sigid(IDEMPLEAD);
       if (modo_z == NUEVO) {
         qry_clien->Append();
         qry_clien->FieldByName("clave")->AsString = clave_z;
         qry_clien->FieldByName("cia")->AsInteger = cia_z;
         qry_clien->FieldByName("sdoini")->AsFloat = 0;
         qry_clien->FieldByName("impent")->AsFloat = 0;
         qry_clien->FieldByName("impsal")->AsFloat = 0;
         qry_clien->FieldByName("sdofin")->AsFloat = 0;
       }
       if (modo_z == MODIF) {
         qry_clien->Edit();
       }
       qry_clien->FieldByName("nombre")->AsString = nombre_z;
       qry_clien->FieldByName("direc")->AsString = direc_z;
       qry_clien->FieldByName("exib")->AsString = exib_z;
       qry_clien->FieldByName("zona")->AsString = zona_z;
       qry_clien->FieldByName("ordiary")->AsInteger = ordiary_z;
       qry_clien->FieldByName("ordtabt")->AsInteger = ordtab_z;
       qry_clien->FieldByName("status")->AsString = status_z;
       qry_clien->Post();
       if(tipo_z == "PTOVTA") {
          if(qry_relubiptovta->IsEmpty()) {
            idrelubiptovta_z = dm->busca_sigid(INVRELUBIPTOVTA);
            qry_relubiptovta->Append();
            qry_relubiptovta->FieldByName("idrelubiptovta")->AsInteger = idrelubiptovta_z;
            qry_relubiptovta->FieldByName("ptovta")->AsString = clave_z;
            qry_relubiptovta->FieldByName("cia")->AsInteger = cia_z;
          } else {
            qry_relubiptovta->Edit();
          }
          qry_relubiptovta->FieldByName("idubiptovta")->AsInteger = idubiptovta_z;
          qry_relubiptovta->FieldByName("zona")->AsString = zona_z;
          qry_relubiptovta->Post();
          qry_relubiptovta->ApplyUpdates();
       }

       qry_clien->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
  }
  delete dlg_datosalm;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::modif_vnd()
{
}

//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::asigna_tipo(String ttipo_z)
{
  tipo_z = ttipo_z;
  if(tipo_z == "ALMACEN") {
    qry_clien->SQL->Text = StrReplace(qry_clien->SQL->Text, "almacen", "almacen");
    uqry_clien->DeleteSQL->Text = StrReplace(uqry_clien->DeleteSQL->Text, "almacen", "almacen");
    uqry_clien->InsertSQL->Text = StrReplace(uqry_clien->InsertSQL->Text, "almacen", "almacen");
    uqry_clien->ModifySQL->Text = StrReplace(uqry_clien->ModifySQL->Text, "almacen", "almacen");
  }
  if(tipo_z == "PTOVTA") {
    qry_clien->SQL->Text = StrReplace(qry_clien->SQL->Text, "almacen", "ptovta");
    //qry_clien->SQL->Text = StrReplace(qry_clien->SQL->Text, "exib,", "");
    uqry_clien->DeleteSQL->Text = StrReplace(uqry_clien->DeleteSQL->Text, "almacen", "ptovta");
    uqry_clien->InsertSQL->Text = StrReplace(uqry_clien->InsertSQL->Text, "almacen", "ptovta");
    uqry_clien->ModifySQL->Text = StrReplace(uqry_clien->ModifySQL->Text, "almacen", "ptovta");
    uqry_clien->InsertSQL->Text = StrReplace(uqry_clien->InsertSQL->Text, ":exhib,", "");
    uqry_clien->ModifySQL->Text = StrReplace(uqry_clien->ModifySQL->Text, "exhib,", "");
  }
  qry_clien->Close();
  qry_clien->ParamByName("cia")->AsInteger = cia_z;
  qry_clien->Open();

}

//---------------------------------------------------------------------------


void __fastcall TForm_mantoalm::desp_vnd()
{
  Tdlg_datosalm *dlg_datosalm = new Tdlg_datosalm (this);
  String mialm_z = "";
  int idubiptovta_z=-1;
  dlg_datosalm->asigna_tipo(tipo_z);
  dlg_datosalm->edt_codvnd->Text = qry_clien->FieldByName("clave")->AsString;
  dlg_datosalm->edt_nombre->Text = qry_clien->FieldByName("nombre")->AsString;
  dlg_datosalm->edt_direc->Text  = qry_clien->FieldByName("direc")->AsString;
  dlg_datosalm->edt_ordiary->IntValue = qry_clien->FieldByName("ordiary")->AsInteger;
  dlg_datosalm->edt_exib->Text       = qry_clien->FieldByName("exib")->AsString;
  dlg_datosalm->edt_ordtab->IntValue = qry_clien->FieldByName("ordtabt")->AsInteger;
  dlg_datosalm->lkcmb_zona->KeyValue = qry_clien->FieldByName("zona")->AsString;
  dlg_datosalm->btn_cancel->Visible = false;
  if(tipo_z == "PTOVTA") {
      mialm_z = qry_clien->FieldByName("clave")->AsString;
      qry_relubiptovta->Close();
      qry_relubiptovta->ParamByName("ptovta")->AsString = mialm_z;
      qry_relubiptovta->ParamByName("cia")->AsInteger = cia_z;
      qry_relubiptovta->Open();
      idubiptovta_z = qry_relubiptovta->FieldByName("idubiptovta")->AsInteger;
      dlg_datosalm->lkcmb_relubivta->KeyValue = idubiptovta_z;
  }
  dlg_datosalm->ShowModal();
  delete dlg_datosalm;
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoalm::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_vnd(NUEVO);
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantoalm::FormCreate(TObject *Sender)
{
  //permis_z="N";

  permis_z=dm->busca_permision(MANTOALM);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  /*
  if(dm->usermaster_z != "S") {
    dm->qry_permis->Close();
    dm->qry_permis->ParamByName("idusuario")->AsInteger=dm->idusuario_z;
    dm->qry_permis->ParamByName("idpermis")->AsInteger=MANTOALM;
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
  */
  qry_clien->Close();
  qry_clien->ParamByName("cia")->AsInteger = cia_z;
  qry_clien->Open();
  grabar->Tag = EN_ESPERA;
  //qry_ciudades->Open();
  //qry_puestos->Open();
  //qry_status->Open();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoalm::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_vnd(MODIF);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::borraExecute(TObject *Sender)
{
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  //qry_clien->Close();
  //qry_clien->ParamByName("codigo")->AsString= edt_codvnd->Text;
  //qry_clien->ParamByName("cia")->AsInteger=cia_z;
  //qry_clien->Open();
  if(qry_clien->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar este Almacén?", "Eliminar Almacén", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
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

void __fastcall TForm_mantoalm::mueve_hacia(String sql_z)
{
   dm->qry_maxidvnd->Close();
   dm->qry_maxidvnd->SQL->Clear();
   dm->qry_maxidvnd->SQL->Add(sql_z);
   dm->qry_maxidvnd->Open();
   if(dm->qry_maxidvnd->IsEmpty()) return;
   busca_vnd(dm->qry_maxidvnd->FieldByName("clave")->AsString);
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoalm::busca_vnd(String vnd_z)
{
  int codvnd_z = 0;
  qry_clien->Close();
  qry_clien->ParamByName("codigo")->AsString = vnd_z;
  qry_clien->ParamByName("cia")->AsInteger = cia_z;
  qry_clien->Open();
  if(!qry_clien->IsEmpty()) {
        desp_vnd(); grabar->Tag = EN_ESPERA; botones_onoff(VISIBLES);
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantoalm::primeroExecute(TObject *Sender)
{
  qry_clien->First();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::anteriorExecute(TObject *Sender)
{
  qry_clien->Prior();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::siguienteExecute(TObject *Sender)
{
  qry_clien->Next();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::ultimoExecute(TObject *Sender)
{
  qry_clien->Last();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
  midbgrd_z = dbgrd_clien;
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


void __fastcall TForm_mantoalm::generar_htmlExecute(TObject *Sender)
{
  String cadena_z, arch_z;
  TOpenDialog *OpenDialog = new TOpenDialog (this);
  OpenDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  OpenDialog->DefaultExt = "Archivos de Texto";
  TStringList *milista_z = new TStringList();
  TStringList *textohtml_z = new TStringList();
  if (OpenDialog->Execute()) {
    arch_z = OpenDialog->FileName;
    milista_z->LoadFromFile(arch_z);
    textohtml_z->Append("<table border=\"1\">");
    for(int ii_z = 0; ii_z < milista_z->Count-2; ii_z +=4) {
      textohtml_z->Append("<tr><td>");
      cadena_z="<a href=\"";
      cadena_z += milista_z->Strings[ii_z];
      cadena_z += "\">";
      textohtml_z->Append(cadena_z);
      cadena_z="<img src=\"";
      cadena_z += milista_z->Strings[ii_z+1];
      cadena_z += "\"><br>";
      textohtml_z->Append(cadena_z);
      cadena_z="";
      cadena_z += milista_z->Strings[ii_z+2];
      cadena_z += "</a>";
      textohtml_z->Append(cadena_z);
      textohtml_z->Append("</td></tr>");
    }
    textohtml_z->Append("</table>");
  }
  arch_z += ".html";
  textohtml_z->SaveToFile(arch_z);
  Application->MessageBox("Archivo Generado", "Html Generado", MB_OK);
  delete textohtml_z;
  delete milista_z;
  delete OpenDialog;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::dbgrd_clienDblClick(TObject *Sender)
{
   desp_vnd();        
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantoalm::dbgrd_clienKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_F2)     modificaExecute(Sender);
}
//---------------------------------------------------------------------------

