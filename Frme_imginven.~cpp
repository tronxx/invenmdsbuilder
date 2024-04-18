//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frme_imginven.h"
#include "situaciones.h"
#include <inifiles.hpp>
#include "dmod.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma resource "*.dfm"
TFrame_imginven *Frame_imginven;
//---------------------------------------------------------------------------
__fastcall TFrame_imginven::TFrame_imginven(TComponent* Owner)
        : TFrame(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TFrame_imginven::busca_ptvt(String ptvt_z)
{
//   if(ptvt_z.Trim().IsEmpty()) return;
//   qry_gpoinv->Close();
//   qry_gpoinv->ParamByName("grupo")->AsString = ptvt_z;
//   qry_gpoinv->ParamByName("cia")->AsInteger = cia_z;
//   qry_gpoinv->Open();
//   if(!qry_gpoinv->IsEmpty()) {
//     desp_ptvt(); grabar->Tag = 0; botones_onoff(VISIBLES);
//   }
}
//---------------------------------------------------------------------------

void __fastcall TFrame_imginven::carga_imagen()
{
  String nomarch_z;
  int ii_z;
  qry_folsel->Close();
  qry_folsel->Tag = INACTIVO;
  qry_folsel->Open();
  //nomarch_z = directorioimgs_z + "\\" + linea_z + "\\"  + codigo_z + ".jpg";
  //if (!FileExists(nomarch_z)) {
  //  nomarch_z = directorioimgs_z + "\\" + "artsinfoto" + "\\"  + "SINFOTO" + ".jpg";
  for(ii_z = 0; ii_z < 10; ii_z++) {
    nomarch_z = directorioimgs_z + "\\" + linea_z + "\\"  + codigo_z;
    if(ii_z) {
      nomarch_z += "_" + IntToStr(ii_z) + ".jpg";
    } else {
      nomarch_z += ".jpg";
      if (!FileExists(nomarch_z)) {
        nomarch_z = directorioimgs_z + "\\" + "artsinfoto" + "\\"  + "SINFOTO" + ".jpg";
      }
      img_principal->Picture->LoadFromFile(nomarch_z);
    }
    if (FileExists(nomarch_z)) {
      qry_folsel->Append();
      qry_folsel->FieldByName("nimg")->AsInteger = ii_z;
      qry_folsel->FieldByName("nomarch")->AsString = nomarch_z;
      qry_folsel->Post();
    }
  }
  qry_folsel->Tag = ACTIVO;

}
//---------------------------------------------------------------------------
void __fastcall TFrame_imginven::ajusta_imagenExecute(TObject *Sender)
{
  bool ajuste_z;
  ajuste_z = chk_ajustaimg->Checked;
  if(ajuste_z) {
    img_principal->Align = alClient;
    img_principal->Stretch = ajuste_z;
    if( img_principal->Tag == ACTIVO) pnl_imagen->Width = 321;
  } else {
    //if( img_principal->Tag == ACTIVO) pnl_imagen->Width = tbs_imagenes->Width - 10;
    img_principal->Align = alNone;
    img_principal->Stretch = ajuste_z;
  }

}
//---------------------------------------------------------------------------
void __fastcall TFrame_imginven::cambia_imagenExecute(TObject *Sender)
{
  agregar_o_cambiar_imagen("MODIFICAR");
}
//---------------------------------------------------------------------------

void __fastcall TFrame_imginven::agregar_imagenExecute(TObject *Sender)
{
  agregar_o_cambiar_imagen("AGREGAR");

}
//---------------------------------------------------------------------------

void __fastcall TFrame_imginven::agregar_o_cambiar_imagen(String modo_z)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  String nompic_z, imgmodificadas_z, codimg_z, nomarch_z, cmd_z;
  TOpenDialog *newimgdlg_z = new TOpenDialog (this);
  newimgdlg_z->Filter = "Archivos de Imagenes (*.jpg)|*.jpg";

  if(newimgdlg_z->Execute()) {
    nompic_z = newimgdlg_z->FileName;
    img_principal->Picture->LoadFromFile(nompic_z);
    Application->MessageBox(nompic_z.c_str(), "Archivo:", 0);
    estadoimg_z = MODIF;
    imgmodificadas_z = dirpython_z + "\\..\\fotos_actualizadas.txt";
    TStringList *imagenesmodif_z = new TStringList();
    imagenesmodif_z->LoadFromFile(imgmodificadas_z);
    cmd_z = "copy \"" + nompic_z + "\"" + " " + directorioimgs_z + "\\" + linea_z + "\\";
    codimg_z = codigo_z;
    if(modo_z == "MODIFICAR") {
      if(idimg_z) {
        codimg_z += "_" + IntToStr(idimg_z);
      }
    }
    if(modo_z == "AGREGAR") {
      idimg_z += 1;
      codimg_z += "_" + IntToStr(idimg_z);
    }
    codimg_z += ".jpg";
    cmd_z += codimg_z + " /y";
    nomarch_z = directorioimgs_z + "\\" + linea_z + "\\" + codimg_z;
    Application->MessageBox(cmd_z.c_str(), "Archivo:", 0);
    system(cmd_z.c_str());
    cmd_z = "copy \"" + nompic_z + "\"" + " " + dirpython_z + "\\" + linea_z + "\\";
    cmd_z += codimg_z + " /y";
    Application->MessageBox(cmd_z.c_str(), "Archivo:", 0);
    system(cmd_z.c_str());
    imagenesmodif_z->Append("html/fotos/" + linea_z + "/"  + codimg_z);
    if(modo_z == "AGREGAR") {
      qry_folsel->Append();
      qry_folsel->FieldByName("nimg")->AsInteger = idimg_z;
      qry_folsel->FieldByName("nomarch")->AsString = nomarch_z;
      qry_folsel->Post();
    }
    mmo_fotos_actualizadas->Lines = imagenesmodif_z;
    imagenesmodif_z->SaveToFile(imgmodificadas_z);
  }
  delete newimgdlg_z;
}
//---------------------------------------------------------------------------


void __fastcall TFrame_imginven::carga_interactivo()
{
  String baseimg_z, basepython_z, permis_z;
  permis_z=dm->busca_permistr("MANTO_IMAGENES");
  if(permis_z != "T") return;

  cambia_imagen->Visible = true;
  agregar_imagen->Visible = true;
  grp_listasimagenes->Visible = true;
  TIniFile *ini;
  ini = new TIniFile(dm->config_z);
  baseimg_z = "\\\\melvin\\Documents\\html\\fotos";
  basepython_z  = "\\\\melvin\\python\\pruglade\\inven\\html\\fotos";
  directorioimgs_z =  ini->ReadString( "Form_consuinv", "DIRECTORIO_IMAGENES", "-1");
  dirpython_z =  ini->ReadString( "Form_consuinv", "DIRECTORIO_IMAGENES_PYTHON", "-1");
  if( directorioimgs_z == "-1") {
    directorioimgs_z = baseimg_z;
    ini->WriteString( "Form_consuinv", "DIRECTORIO_IMAGENES", directorioimgs_z);
  }
  if( dirpython_z == "-1") {
    dirpython_z = basepython_z;
    ini->WriteString( "Form_consuinv", "DIRECTORIO_IMAGENES_PYTHON", dirpython_z);
  }
  edt_dirbaselan->Text = directorioimgs_z;
  edt_dirpython->Text = dirpython_z;
  delete ini;
}
//---------------------------------------------------------------------------

void __fastcall TFrame_imginven::qry_folselAfterScroll(TDataSet *DataSet)
{
  int estaimagen_z = 0;
  String nomarch_z;
  if(qry_folsel->Tag != ACTIVO) return;
  estaimagen_z = qry_folsel->FieldByName("nimg")->AsInteger;
  nomarch_z = qry_folsel->FieldByName("nomarch")->AsString;
  if(idimg_z == estaimagen_z) return;
  img_principal->Picture->LoadFromFile(nomarch_z);
  idimg_z = estaimagen_z;

}
//---------------------------------------------------------------------------



