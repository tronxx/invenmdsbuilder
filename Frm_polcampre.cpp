//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include <inifiles.hpp>

#include "Frm_polcampre.h"
#include "dialg_okcancel.h"
#include "Frme_datospolcampre.h"
#include "dmod.h"
#include "situaciones.h"
#include "numapal.h"
#include "Frme_datosrenpolcampre.h"
#include "Frm_CapturaObsPed.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "Frme_datoscaptrasp"
#pragma link "Frme_datospolcampre"
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxTL"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma resource "*.dfm"

const int MAX_LINEAS = 63;

TForm_polcampre *Form_polcampre;
//---------------------------------------------------------------------------
__fastcall TForm_polcampre::TForm_polcampre(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  agregar_modificar(NUEVO);

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::inicializa(String tipo_z)
{
   int ancho_z, alto_z, folio_z=0, idconcep_z=0;
   TDateTime fecha_z, vigencia_z;
   String titulo_z, concepto_z, sql_z;
   tipopol_z = tipo_z;
   TLabel *lbl_tipopol = new TLabel(this);
   lbl_tipopol->Parent = Frame_datospolcampre1;
   lbl_tipopol->Left = Frame_datospolcampre1->date_finvigencia->Left + Frame_datospolcampre1->date_finvigencia->Width + 4;
   lbl_tipopol->Top =  Frame_datospolcampre1->date_finvigencia->Top;

   if (tipo_z == "POL_CAMPRE") {
     titulo_z = "Póliza de Cambios de Precios";
     lbl_tipopol->Caption = "CAMBIO PRECIOS";
     lbl_tipopol->Color = clRed;
     lbl_tipopol->Left = Frame_datospolcampre1->date_inivig->Left + Frame_datospolcampre1->date_inivig->Width + 4;
     Frame_datospolcampre1->lbl_finvigencia->Visible = false;
     Frame_datospolcampre1->date_finvigencia->Visible = false;
     tipopol_z = "P";
   }
   if (tipo_z == "POL_OFERTAS") {
     titulo_z = "Póliza de Ofertas";
     tipopol_z = "O";
     lbl_tipopol->Caption = "OFERTAS";
     lbl_tipopol->Color = clYellow;
     Frame_datospolcampre1->lbl_finvigencia->Visible = true;
     Frame_datospolcampre1->date_finvigencia->Visible = true;
     dbgrd_renglonesNVOEMPAQ->Visible = false;
     dbgrd_renglonesANTEMPAQ->Visible = false;
     dbgrd_renglonesDESCRIGTIA->Visible = false;
     dbgrd_renglonesCONCEP->Visible = false;
     dbgrd_renglonesPRECELEC->Visible = false;
     dbgrd_renglonesANTPRELEC->Visible = false;
     dbgrd_renglonesPRECMDS->Caption = "Precio Oferta";
     sql_z = qry_polcampre->SQL->Text;
     qry_polcampre->SQL->Text = StrReplace(qry_polcampre->SQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->DeleteSQL->Text = StrReplace(uqry_polcampre->DeleteSQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->ModifySQL->Text = StrReplace(uqry_polcampre->ModifySQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->InsertSQL->Text = StrReplace(uqry_polcampre->InsertSQL->Text, "inv_polcampre", "inv_polofertas");
     qry_renpolcampre->SQL->Text = StrReplace(qry_renpolcampre->SQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->DeleteSQL->Text = StrReplace(uqry_renpolcampre->DeleteSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->ModifySQL->Text = StrReplace(uqry_renpolcampre->ModifySQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->InsertSQL->Text = StrReplace(uqry_renpolcampre->InsertSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     sql_z = qry_renpolcampre->SQL->Text;
   }
   if (tipo_z == "POL_OUTLET") {
     titulo_z = "Póliza de Outlet";
     tipopol_z = "T";
     lbl_tipopol->Caption = "OUTLET";
     lbl_tipopol->Color = clLime;
     Frame_datospolcampre1->lbl_finvigencia->Visible = true;
     Frame_datospolcampre1->date_finvigencia->Visible = true;
     dbgrd_renglonesNVOEMPAQ->Visible = false;
     dbgrd_renglonesANTEMPAQ->Visible = false;
     dbgrd_renglonesDESCRIGTIA->Visible = false;
     dbgrd_renglonesCONCEP->Visible = false;
     dbgrd_renglonesPRECELEC->Visible = false;
     dbgrd_renglonesANTPRELEC->Visible = false;
     dbgrd_renglonesPRECMDS->Caption = "Precio Outlet";
     sql_z = qry_polcampre->SQL->Text;
     qry_polcampre->SQL->Text = StrReplace(qry_polcampre->SQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->DeleteSQL->Text = StrReplace(uqry_polcampre->DeleteSQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->ModifySQL->Text = StrReplace(uqry_polcampre->ModifySQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->InsertSQL->Text = StrReplace(uqry_polcampre->InsertSQL->Text, "inv_polcampre", "inv_polofertas");
     qry_renpolcampre->SQL->Text = StrReplace(qry_renpolcampre->SQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->DeleteSQL->Text = StrReplace(uqry_renpolcampre->DeleteSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->ModifySQL->Text = StrReplace(uqry_renpolcampre->ModifySQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->InsertSQL->Text = StrReplace(uqry_renpolcampre->InsertSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     sql_z = qry_renpolcampre->SQL->Text;
   }
   if (tipo_z == "POL_OFERTAINTERNET") {
     titulo_z = "Póliza de Ofertas Internet";
     tipopol_z = "N";
     lbl_tipopol->Caption = "OFERTA_INTERNET";
     lbl_tipopol->Color = clLime;
     Frame_datospolcampre1->lbl_finvigencia->Visible = true;
     Frame_datospolcampre1->date_finvigencia->Visible = true;
     dbgrd_renglonesNVOEMPAQ->Visible = false;
     dbgrd_renglonesANTEMPAQ->Visible = false;
     dbgrd_renglonesDESCRIGTIA->Visible = false;
     dbgrd_renglonesCONCEP->Visible = false;
     dbgrd_renglonesPRECELEC->Visible = false;
     dbgrd_renglonesANTPRELEC->Visible = false;
     dbgrd_renglonesPRECMDS->Caption = "Pr Oferta Internet";
     sql_z = qry_polcampre->SQL->Text;
     qry_polcampre->SQL->Text = StrReplace(qry_polcampre->SQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->DeleteSQL->Text = StrReplace(uqry_polcampre->DeleteSQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->ModifySQL->Text = StrReplace(uqry_polcampre->ModifySQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->InsertSQL->Text = StrReplace(uqry_polcampre->InsertSQL->Text, "inv_polcampre", "inv_polofertas");
     qry_renpolcampre->SQL->Text = StrReplace(qry_renpolcampre->SQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->DeleteSQL->Text = StrReplace(uqry_renpolcampre->DeleteSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->ModifySQL->Text = StrReplace(uqry_renpolcampre->ModifySQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->InsertSQL->Text = StrReplace(uqry_renpolcampre->InsertSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     sql_z = qry_renpolcampre->SQL->Text;
   }
   if (tipo_z == "POL_CAMBIOSITUACION") {
     titulo_z = "Póliza de Cambio de Situación";
     tipopol_z = "S";
     lbl_tipopol->Caption = "CAMBIO_SITUACION";
     lbl_tipopol->Color = clLime;
     Frame_datospolcampre1->lbl_finvigencia->Visible = false;
     Frame_datospolcampre1->date_finvigencia->Visible = false;
     Frame_datospolcampre1->lbl_inivig->Visible = false;
     Frame_datospolcampre1->date_inivig->Visible = false;
     dbgrd_renglonesNVOEMPAQ->Visible = true;
     dbgrd_renglonesANTEMPAQ->Visible = true;
     dbgrd_renglonesDESCRIGTIA->Visible = false;
     dbgrd_renglonesCONCEP->Visible = false;
     dbgrd_renglonesPRECELEC->Visible = false;
     dbgrd_renglonesANTPRELEC->Visible = false;
     dbgrd_renglonesPRECMDS->Caption = "Pr Oferta Internet";
     dbgrd_renglonesPRECMDS->Visible = false;
     dbgrd_renglonesMUB->Visible = false;
     dbgrd_renglonesANTPRMDS->Visible = false;

     sql_z = qry_polcampre->SQL->Text;
     qry_polcampre->SQL->Text = StrReplace(qry_polcampre->SQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->DeleteSQL->Text = StrReplace(uqry_polcampre->DeleteSQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->ModifySQL->Text = StrReplace(uqry_polcampre->ModifySQL->Text, "inv_polcampre", "inv_polofertas");
     uqry_polcampre->InsertSQL->Text = StrReplace(uqry_polcampre->InsertSQL->Text, "inv_polcampre", "inv_polofertas");
     qry_renpolcampre->SQL->Text = StrReplace(qry_renpolcampre->SQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->DeleteSQL->Text = StrReplace(uqry_renpolcampre->DeleteSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->ModifySQL->Text = StrReplace(uqry_renpolcampre->ModifySQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     uqry_renpolcampre->InsertSQL->Text = StrReplace(uqry_renpolcampre->InsertSQL->Text, "inv_renpolcampre", "inv_renpolofertas");
     sql_z = qry_renpolcampre->SQL->Text;
   }
   Caption = titulo_z;
   SigteSabana(ULTIMO);

}

void __fastcall TForm_polcampre::agregar_modificar(int tipo_z)
{
   int ancho_z, alto_z, folio_z=0, idpol_z=0, idconcep_z=0;
   TDateTime fecha_z, vigencia_z, finvigencia_z;
   String titulo_z, concepto_z;

   Tdlg_okcancel *Dlg_mantgpoinv;
   Dlg_mantgpoinv = new Tdlg_okcancel (this);
   Dlg_mantgpoinv->AutoSize = false;
   TFrame_datospolcampre *Frame_datospolcampre;
   Frame_datospolcampre = new TFrame_datospolcampre (Dlg_mantgpoinv);
   ancho_z = Frame_datospolcampre->Width + 20;
   alto_z = Frame_datospolcampre->Height + Dlg_mantgpoinv->Panel2->Height + 80;
   Frame_datospolcampre->Parent = Dlg_mantgpoinv->Panel1;
   Dlg_mantgpoinv->Width = ancho_z;
   Dlg_mantgpoinv->Height = alto_z;
   if (tipopol_z == "P") {
     titulo_z = "Póliza Cambios de Precios";
     Frame_datospolcampre->lbl_finvigencia->Visible = false;
     Frame_datospolcampre->date_finvigencia->Visible = false;

   }
   if (tipopol_z == "O") {
     titulo_z = "Póliza de Ofertas";
     Frame_datospolcampre->lbl_finvigencia->Visible = true;
     Frame_datospolcampre->date_finvigencia->Visible = true;
   }
   if (tipopol_z == "T") {
     titulo_z = "Póliza de Outlet";
     Frame_datospolcampre->lbl_finvigencia->Visible = true;
     Frame_datospolcampre->date_finvigencia->Visible = true;
   }
   if (tipopol_z == "N") {
     titulo_z = "Póliza de Ofertas Internet";
     Frame_datospolcampre->lbl_finvigencia->Visible = true;
     Frame_datospolcampre->date_finvigencia->Visible = true;
   }
   if (tipopol_z == "S") {
     titulo_z = "Póliza de Cambio de Situación";
     Frame_datospolcampre->lbl_finvigencia->Visible = false;
     Frame_datospolcampre->date_finvigencia->Visible = false;
     Frame_datospolcampre->lbl_inivig->Visible = false;
     Frame_datospolcampre->date_inivig->Visible = false;
   }

   Dlg_mantgpoinv->Caption = titulo_z;
   Dlg_mantgpoinv->Position = poScreenCenter;
   if(tipo_z == MODIF) {
      Frame_datospolcampre->edt_folio->Value = qry_polcampre->FieldByName("folio")->AsInteger;
      //Frame_datospolcampre->edt_ubica->Enabled = false;
      Frame_datospolcampre->date_fecha->Date = qry_polcampre->FieldByName("fecha")->AsDateTime;
      Frame_datospolcampre->date_finvigencia->Date = qry_polcampre->FieldByName("fecfin")->AsDateTime;
      Frame_datospolcampre->date_inivig->Date = qry_polcampre->FieldByName("fecini")->AsDateTime;
      Frame_datospolcampre->edt_concepto->Text = qry_polcampre->FieldByName("concep")->AsString;
   }
   if(tipo_z == NUEVO) {
      Frame_datospolcampre->edt_folio->Value = busca_sigfolio();
      //Frame_datospolcampre->edt_ubica->Enabled = false;
      Frame_datospolcampre->date_fecha->Date = dm->ahora();
      Frame_datospolcampre->date_inivig->Date = dm->ahora();
      Frame_datospolcampre->date_finvigencia->Date = Frame_datospolcampre->date_inivig->Date;
      Frame_datospolcampre->edt_concepto->Text = "ACTUALIZACION DE PRECIOS";
   }
   if( Dlg_mantgpoinv->ShowModal() == mrOk) {
      folio_z      = Frame_datospolcampre->edt_folio->Value;
      fecha_z      = Frame_datospolcampre->date_fecha->Date;
      vigencia_z   = Frame_datospolcampre->date_inivig->Date;
      finvigencia_z = Frame_datospolcampre->date_finvigencia->Date;
      concepto_z   = Frame_datospolcampre->edt_concepto->Text.Trim();
      idconcep_z   = dm->busca_iddato(concepto_z, INVCONCEPTO);

      if(tipo_z == NUEVO) {
        qry_polcampre->Append();
        if(tipopol_z == "P") {
          idpol_z = dm->busca_sigid(IDPOLCAMPRE);
        }
        if(tipopol_z == "O") {
          idpol_z = dm->busca_sigid(IDPOLOFERTAS);
        }
        if(tipopol_z == "T") {
          idpol_z = dm->busca_sigid(IDPOLOFERTAS);
        }
        if(tipopol_z == "N") {
          idpol_z = dm->busca_sigid(IDPOLOFERTAS);
        }
        if(tipopol_z == "S") {
          idpol_z = dm->busca_sigid(IDPOLOFERTAS);
        }
        qry_polcampre->FieldByName("idpolcampre")->AsInteger = idpol_z;
        qry_polcampre->FieldByName("folio")->AsInteger = folio_z;
        qry_polcampre->FieldByName("tipo")->AsString = tipopol_z;
      } else {
        qry_polcampre->Edit();
      }
      qry_polcampre->FieldByName("fecha")->AsDateTime = fecha_z;
      qry_polcampre->FieldByName("fecini")->AsDateTime = vigencia_z;
      qry_polcampre->FieldByName("fecfin")->AsDateTime = finvigencia_z;
      qry_polcampre->FieldByName("concep")->AsString = concepto_z;
      qry_polcampre->FieldByName("idusuario")->AsInteger = dm->idusuario_z;
      qry_polcampre->FieldByName("status")->AsInteger =  INV_STATUS_CAMBIO_PRECIO_CREADO;
      qry_polcampre->FieldByName("idconcep")->AsInteger = idconcep_z;
      qry_polcampre->FieldByName("cia")->AsInteger = cia_z;
      qry_polcampre->Post();
      try {
         dm->manvehi->StartTransaction();
         qry_polcampre->ApplyUpdates();
         dm->manvehi->Commit();
         busca_polcampre(folio_z);
      } catch (Exception &E)
      {
         dm->manvehi->Rollback();
         dm->MensajeError("No pude grabar los datos:\n"+E.Message, "ERROR");
      }
   }
   delete Frame_datospolcampre;
   delete Dlg_mantgpoinv;
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::FormCreate(TObject *Sender)
{
  String permiabrepol_z = "N";
  cia_z = dm->cia_z;
  permis_z=dm->busca_permision(POLCAMPRE);
  cia_z = dm->cia_z;
  tipoobserv_z = "I";
  tipopol_z = "P";
  if(permis_z == "N") {
      Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
      Close();
  }
  if(dm->usermaster_z != "S") {
    permiabrepol_z = dm->busca_permistr("ABREPOLCAMPRE");
  } else {
    permiabrepol_z = "T";
  }
  if (permiabrepol_z == "T") {
    abrir_poliza->Visible = true;
  } else {
    abrir_poliza->Visible = false;
  }

}
//---------------------------------------------------------------------------

int __fastcall TForm_polcampre::busca_sigfolio()
{
  int folio_z;
  String sql_z = "select max(folio) as folio from ";
  if(tipopol_z == "P") {
    sql_z += "inv_polcampre ";
  }
  if(tipopol_z == "O") {
    sql_z += "inv_polofertas ";
  }
  if(tipopol_z == "T") {
    sql_z += "inv_polofertas ";
  }
  if(tipopol_z == "N") {
    sql_z += "inv_polofertas ";
  }
  if(tipopol_z == "S") {
    sql_z += "inv_polofertas ";
  }
  sql_z += "where folio > 0 and tipo = :TIPOPOL and cia = :CIA";
  dm->qry_iddato->SQL->Text = sql_z;
  dm->qry_iddato->Close();
  dm->qry_iddato->ParamByName("cia")->AsInteger = cia_z;
  dm->qry_iddato->ParamByName("tipopol")->AsString = tipopol_z;
  dm->qry_iddato->Open();
  folio_z = dm->qry_iddato->FieldByName("folio")->AsInteger + 1;
  dm->qry_iddato->Close();
  return ( folio_z );
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::primeroExecute(TObject *Sender)
{
   SigteSabana(PRIMERO);

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::anteriorExecute(TObject *Sender)
{
   SigteSabana(ANTER);

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::siguienteExecute(TObject *Sender)
{
   SigteSabana(SIGTE);

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::ultimoExecute(TObject *Sender)
{
   SigteSabana(ULTIMO);

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::SigteSabana(int HACIA_DONDE)
{
  int folio_z = Frame_datospolcampre1->edt_folio->Value;
  String sql_z, where_z;
  sql_z = "select ";
  where_z = " where cia = :CIA and tipo = :TIPOPOL and ";
  switch  (HACIA_DONDE) {
    case ANTER: sql_z += "max (folio) ";
                where_z += " folio < :NUMERO";
    break;
    case SIGTE: sql_z += "min (folio) ";
                where_z += " folio > :NUMERO";
    break;
    case ULTIMO: sql_z += "max (folio) ";
                where_z += " folio > :NUMERO"; folio_z = 0;
    break;
    case PRIMERO: sql_z += "min (folio) ";
                where_z += " folio > :NUMERO"; folio_z = -1;
    break;
  }
  sql_z += " as folio from ";
  if(tipopol_z == "P") {
    sql_z += "inv_polcampre ";
  }
  if(tipopol_z == "O") {
    sql_z += "inv_polofertas ";
  }
  if(tipopol_z == "T") {
    sql_z += "inv_polofertas ";
  }
  if(tipopol_z == "N") {
    sql_z += "inv_polofertas ";
  }
  if(tipopol_z == "S") {
    sql_z += "inv_polofertas ";
  }
  sql_z += where_z;
  dm->qry_iddato->SQL->Text = sql_z;
  dm->qry_iddato->Close();
  dm->qry_iddato->ParamByName("cia")->AsInteger = cia_z;
  dm->qry_iddato->ParamByName("numero")->AsInteger = folio_z;
  dm->qry_iddato->ParamByName("tipopol")->AsString = tipopol_z;
  dm->qry_iddato->Open();
  folio_z = dm->qry_iddato->FieldByName("folio")->AsInteger;
  dm->qry_iddato->Close();
  busca_polcampre(folio_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::busca_polcampre(int folio_z)
{
  int idpolcampre_z = 0;
  qry_polcampre->Close();
  qry_polcampre->ParamByName("folio")->AsInteger = folio_z;
  qry_polcampre->ParamByName("cia")->AsInteger = cia_z;
  qry_polcampre->ParamByName("tipo")->AsString = tipopol_z;

  qry_polcampre->Open();
  idpolcampre_z = qry_polcampre->FieldByName("idpolcampre")->AsInteger;
  qry_renpolcampre->Close();
  qry_renpolcampre->ParamByName("IDPOLCAMPRE")->AsInteger = idpolcampre_z;
  qry_renpolcampre->Open();
  Frame_datospolcampre1->edt_folio->Value = qry_polcampre->FieldByName("folio")->AsInteger;
  Frame_datospolcampre1->date_fecha->Date = qry_polcampre->FieldByName("fecha")->AsDateTime;
  Frame_datospolcampre1->date_inivig->Date = qry_polcampre->FieldByName("fecini")->AsDateTime;
  Frame_datospolcampre1->date_finvigencia->Date = qry_polcampre->FieldByName("fecfin")->AsDateTime;
  Frame_datospolcampre1->edt_concepto->Text = qry_polcampre->FieldByName("concep")->AsString;
  if(qry_polcampre->FieldByName("status")->AsInteger == INV_STATUS_CAMBIO_PRECIO_CREADO) {
    cierra_entrada->Enabled = true;
  } else {
    cierra_entrada->Enabled = false;
  }
  imprime->Enabled = !cierra_entrada->Enabled;
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::Frame_datospolcampre1edt_folioKeyDown(
      TObject *Sender, WORD &Key, TShiftState Shift)
{
  if(Key == VK_RETURN) busca_polcampre( Frame_datospolcampre1->edt_folio->Value);
}
//---------------------------------------------------------------------------


void __fastcall TForm_polcampre::agrerenExecute(TObject *Sender)
{
  int ancho_z, alto_z, idrenpol_z=0, idart_z=0, idpol_z=0, conse_z,
    antidempaq_z, idnvoempaq_z, idobservs_z, idrelinv_z,
    left_z = 0, idgarantia_z;
  TDateTime fechapol_z, fecvig_z;
  TLocateOptions Opts;
  double antprmds_z=0, antprelec_z=0, precmds_z=0, precelec_z=0, precioext_z,
  costoext_z;
  String codigo_z, nvasit_z, observs_z, obscam_z, antsit_z,
    titulo_z, descri_z, garantia_z;
  Opts.Clear();
  if(qry_polcampre->State == dsInactive) return;
  if(qry_polcampre->IsEmpty() ) return;
  if(qry_polcampre->FieldByName("status")->AsInteger == INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICADO) {
    Application->MessageBox("No puedes agregar renglones a pólizas cerradas", "Póliza Cerrada", MB_ICONEXCLAMATION);
    return;
  }
  fechapol_z = qry_polcampre->FieldByName("fecha")->AsDateTime;
  fecvig_z   = qry_polcampre->FieldByName("fecini")->AsDateTime;
  idpol_z    = qry_polcampre->FieldByName("idpolcampre")->AsInteger;

  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TFrame_datosrenpolcampre *Frame_datosrenpolcampre;
  Frame_datosrenpolcampre = new TFrame_datosrenpolcampre (Dlg_analipol);

  if (tipopol_z == "P") {
     titulo_z = "Datos del Cambios de Precios";
  }
  if (tipopol_z == "O") {
     titulo_z = "Datos de la Oferta";
     Frame_datosrenpolcampre->lbl_precioant->Visible = false;
     Frame_datosrenpolcampre->edt_precioant->Visible = false;
     Frame_datosrenpolcampre->lbl_precionvo->Caption = "Precio Oferta";
     Frame_datosrenpolcampre->edt_precionvo->Left = Frame_datosrenpolcampre->lbl_precionvo->Left + Frame_datosrenpolcampre->lbl_precionvo->Width + 4;
     Frame_datosrenpolcampre->lbl_subsidionvo->Visible = false;
     Frame_datosrenpolcampre->edt_fidenvo->Visible = false;
     Frame_datosrenpolcampre->lbl_subsidioant->Visible = false;
     Frame_datosrenpolcampre->edt_fideant->Visible = false;
     Frame_datosrenpolcampre->lbl_situanvo->Visible = false;
     Frame_datosrenpolcampre->lkcmb_situaciones->Visible = false;
     Frame_datosrenpolcampre->lbl_situaant->Visible = false;
     Frame_datosrenpolcampre->edt_antsit->Visible = false;
     Frame_datosrenpolcampre->lbl_garantia->Visible = false;
     Frame_datosrenpolcampre->lkcmb_garantia->Visible = false;
     Frame_datosrenpolcampre->dbedt_garantia->Visible = false;
     Frame_datosrenpolcampre->lbl_observs->Visible = false;
     Frame_datosrenpolcampre->edt_observs->Visible = false;
     Frame_datosrenpolcampre->lbl_costorepo->Visible = false;
     Frame_datosrenpolcampre->edt_costoxten->Visible = false;
     Frame_datosrenpolcampre->lbl_precioxtensa->Visible = false;
     Frame_datosrenpolcampre->edt_precioxten->Visible = false;
  }
  if (tipopol_z == "T") {
     titulo_z = "Datos del Outlet";
     Frame_datosrenpolcampre->lbl_precioant->Visible = false;
     Frame_datosrenpolcampre->edt_precioant->Visible = false;
     Frame_datosrenpolcampre->lbl_precionvo->Caption = "Precio Outlet";
     Frame_datosrenpolcampre->edt_precionvo->Left = Frame_datosrenpolcampre->lbl_precionvo->Left + Frame_datosrenpolcampre->lbl_precionvo->Width + 4;
     Frame_datosrenpolcampre->lbl_subsidionvo->Visible = false;
     Frame_datosrenpolcampre->edt_fidenvo->Visible = false;
     Frame_datosrenpolcampre->lbl_subsidioant->Visible = false;
     Frame_datosrenpolcampre->edt_fideant->Visible = false;
     Frame_datosrenpolcampre->lbl_situanvo->Visible = false;
     Frame_datosrenpolcampre->lkcmb_situaciones->Visible = false;
     Frame_datosrenpolcampre->lbl_situaant->Visible = false;
     Frame_datosrenpolcampre->edt_antsit->Visible = false;
     Frame_datosrenpolcampre->lbl_garantia->Visible = false;
     Frame_datosrenpolcampre->lkcmb_garantia->Visible = false;
     Frame_datosrenpolcampre->dbedt_garantia->Visible = false;
     Frame_datosrenpolcampre->lbl_observs->Visible = false;
     Frame_datosrenpolcampre->edt_observs->Visible = false;
     Frame_datosrenpolcampre->lbl_costorepo->Visible = false;
     Frame_datosrenpolcampre->edt_costoxten->Visible = false;
     Frame_datosrenpolcampre->lbl_precioxtensa->Visible = false;
     Frame_datosrenpolcampre->edt_precioxten->Visible = false;
  }
  if (tipopol_z == "N") {
     titulo_z = "Datos de Oferta Internet";
     Frame_datosrenpolcampre->lbl_precioant->Visible = false;
     Frame_datosrenpolcampre->edt_precioant->Visible = false;
     Frame_datosrenpolcampre->lbl_precionvo->Caption = "Pr Oferta Internet";
     Frame_datosrenpolcampre->edt_precionvo->Left = Frame_datosrenpolcampre->lbl_precionvo->Left + Frame_datosrenpolcampre->lbl_precionvo->Width + 4;
     Frame_datosrenpolcampre->lbl_subsidionvo->Visible = false;
     Frame_datosrenpolcampre->edt_fidenvo->Visible = false;
     Frame_datosrenpolcampre->lbl_subsidioant->Visible = false;
     Frame_datosrenpolcampre->edt_fideant->Visible = false;
     Frame_datosrenpolcampre->lbl_situanvo->Visible = false;
     Frame_datosrenpolcampre->lkcmb_situaciones->Visible = false;
     Frame_datosrenpolcampre->lbl_situaant->Visible = false;
     Frame_datosrenpolcampre->edt_antsit->Visible = false;
     Frame_datosrenpolcampre->lbl_garantia->Visible = false;
     Frame_datosrenpolcampre->lkcmb_garantia->Visible = false;
     Frame_datosrenpolcampre->dbedt_garantia->Visible = false;
     Frame_datosrenpolcampre->lbl_observs->Visible = false;
     Frame_datosrenpolcampre->edt_observs->Visible = false;
     Frame_datosrenpolcampre->lbl_costorepo->Visible = false;
     Frame_datosrenpolcampre->edt_costoxten->Visible = false;
     Frame_datosrenpolcampre->lbl_precioxtensa->Visible = false;
     Frame_datosrenpolcampre->edt_precioxten->Visible = false;
  }
  if (tipopol_z == "S") {
     titulo_z = "Datos de Cambio de Situacion";
     Frame_datosrenpolcampre->lbl_precioant->Visible = false;
     Frame_datosrenpolcampre->edt_precioant->Visible = false;
     Frame_datosrenpolcampre->edt_precionvo->Visible = false;
     Frame_datosrenpolcampre->lbl_precionvo->Caption = "Pr Oferta Internet";
     Frame_datosrenpolcampre->edt_precionvo->Left = Frame_datosrenpolcampre->lbl_precionvo->Left + Frame_datosrenpolcampre->lbl_precionvo->Width + 4;
     Frame_datosrenpolcampre->lbl_subsidionvo->Visible = false;
     Frame_datosrenpolcampre->edt_fidenvo->Visible = false;
     Frame_datosrenpolcampre->lbl_subsidioant->Visible = false;
     Frame_datosrenpolcampre->edt_fideant->Visible = false;
     Frame_datosrenpolcampre->lbl_situanvo->Visible = true;
     Frame_datosrenpolcampre->lkcmb_situaciones->Visible = true;
     Frame_datosrenpolcampre->lbl_situaant->Visible = true;
     Frame_datosrenpolcampre->edt_antsit->Visible = true;
     Frame_datosrenpolcampre->lbl_garantia->Visible = false;
     Frame_datosrenpolcampre->lkcmb_garantia->Visible = false;
     Frame_datosrenpolcampre->dbedt_garantia->Visible = false;
     Frame_datosrenpolcampre->lbl_observs->Visible = false;
     Frame_datosrenpolcampre->edt_observs->Visible = false;
     Frame_datosrenpolcampre->lbl_costorepo->Visible = false;
     Frame_datosrenpolcampre->edt_costoxten->Visible = false;
     Frame_datosrenpolcampre->lbl_precioxtensa->Visible = false;
     Frame_datosrenpolcampre->edt_precioxten->Visible = false;
  }

  ancho_z = Frame_datosrenpolcampre->Width + 20;
  alto_z = Frame_datosrenpolcampre->Height + Dlg_analipol->Panel2->Height + 80;
  Frame_datosrenpolcampre->Parent = Dlg_analipol->Panel1;
  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;
  Dlg_analipol->Caption = titulo_z;
  Frame_datosrenpolcampre->Align = alClient;
  if(Dlg_analipol->ShowModal() == mrOk) {
    if(tipopol_z == "P") {
      idrenpol_z = dm->busca_sigid(IDRENPOLCAMPRE);
    } else  {
      idrenpol_z = dm->busca_sigid(IDRENPOLOFERTAS);
    }

    codigo_z  = Frame_datosrenpolcampre->qry_inven->FieldByName("codigo")->AsString;
    descri_z  = Frame_datosrenpolcampre->qry_inven->FieldByName("descri")->AsString;
    precmds_z = Frame_datosrenpolcampre->edt_precionvo->Value;
    precelec_z = Frame_datosrenpolcampre->edt_fidenvo->Value;
    precioext_z = Frame_datosrenpolcampre->edt_precioxten->Value;
    costoext_z  = Frame_datosrenpolcampre->edt_costoxten->Value;
    idnvoempaq_z = Frame_datosrenpolcampre->qry_situaciones->FieldByName("idsituac")->AsInteger;
    nvasit_z  = Frame_datosrenpolcampre->qry_situaciones->FieldByName("situacion")->AsString;
    idgarantia_z = Frame_datosrenpolcampre->qry_garantias->FieldByName("idgarantia")->AsInteger;
    garantia_z = Frame_datosrenpolcampre->qry_garantias->FieldByName("clave")->AsString;
    observs_z = Frame_datosrenpolcampre->edt_observs->Text;
    idobservs_z = dm->busca_iddato(observs_z, INVCONCEPTO);
//    antprmds_z  = Frame_datosrenpolcampre->edt_precioant->Value;
    antprmds_z  = Frame_datosrenpolcampre->qry_inven->FieldByName("precio")->AsFloat;
    antprelec_z = Frame_datosrenpolcampre->qry_inven->FieldByName("precelec")->AsFloat;
    antsit_z  = Frame_datosrenpolcampre->qry_inven->FieldByName("empaqe")->AsString;
    Frame_datosrenpolcampre->qry_situaciones->First();
    qry_inven->Close();
    qry_inven->ParamByName("codigo")->AsString = codigo_z;
    qry_inven->ParamByName("cia")->AsInteger = cia_z;
    qry_inven->Open();
    if(qry_inven->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe ese artículo", "Artículo Inexistente", MB_ICONEXCLAMATION);
      return;
    }
    qry_invhist->Close();
    qry_invhist->ParamByName("codigo")->AsString = codigo_z;
    qry_invhist->ParamByName("cia")->AsInteger = cia_z;
    qry_invhist->Open();
    if(qry_invhist->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe en invhist ese artículo", "Artículo Inexistente", MB_ICONEXCLAMATION);
      return;
    }
    idart_z = qry_invhist->FieldByName("idart")->AsInteger;

    if(Frame_datosrenpolcampre->qry_situaciones->Locate("situacion", antsit_z, Opts))
      antidempaq_z = Frame_datosrenpolcampre->qry_situaciones->FieldByName("idsituac")->AsInteger;
    qry_renpolcampre->Append();
    qry_renpolcampre->FieldByName("IDRENPOLCAMPRE")->AsInteger = idrenpol_z;
    qry_renpolcampre->FieldByName("idPOLCAMPRE")->AsInteger = idpol_z;
    qry_renpolcampre->FieldByName("idart")->AsInteger    = idart_z;
    qry_renpolcampre->FieldByName("codigo")->AsString = codigo_z;
    qry_renpolcampre->FieldByName("descri")->AsString = descri_z;
    qry_renpolcampre->FieldByName("descrigtia")->AsString = garantia_z;
    qry_renpolcampre->FieldByName("concep")->AsString = observs_z;
    qry_renpolcampre->FieldByName("antprmds")->AsFloat   = antprmds_z;
    qry_renpolcampre->FieldByName("antprelec")->AsFloat  = antprelec_z;
    qry_renpolcampre->FieldByName("precmds")->AsFloat    = precmds_z;
    qry_renpolcampre->FieldByName("precelec")->AsFloat    = precelec_z;
    qry_renpolcampre->FieldByName("antempaq")->AsInteger = antidempaq_z;
    qry_renpolcampre->FieldByName("nvoempaq")->AsInteger = idnvoempaq_z;
    qry_renpolcampre->FieldByName("idobserv")->AsInteger = idobservs_z;
    qry_renpolcampre->FieldByName("precioext")->AsFloat  = precioext_z;
    qry_renpolcampre->FieldByName("costoext")->AsFloat   = costoext_z;
    qry_renpolcampre->FieldByName("idgarantia")->AsInteger = idgarantia_z;
    qry_renpolcampre->FieldByName("antersit")->AsString = antsit_z;
    qry_renpolcampre->FieldByName("nuevasit")->AsString = nvasit_z;
    qry_renpolcampre->Post();
    try {
      dm->manvehi->StartTransaction();
      qry_renpolcampre->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }

  }
  delete Frame_datosrenpolcampre;
  delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::busca_cambios_x_aplicar()
{
  String strfecha_z, antsql_z, nvosql_z;
  TDateTime fecha_z;
  int cuantos_z, idpolcampre_z;
  fecha_z = dm->ahora();
  nvosql_z = " select \
  IDPOLCAMPRE, FOLIO, FECHA, FECINI, IDUSUARIO, STATUS, a.IDCONCEP, a.CIA, \
  a.tipo, a.fecfin, CONCEP \
  from inv_polcampre a join inv_conceps b on a.idconcep = b.idconcep \
  where a.fecha <= :FECHA and a.status = 2 and \
  a.fecini <= :FECHA and a.cia = :CIA and a.tipo = :TIPOPOL";
  strfecha_z = DateToStr(fecha_z);
  antsql_z = qry_polcampre->SQL->Text;
  qry_polcampre->SQL->Text = nvosql_z;
  qry_polcampre->Close();
  qry_polcampre->ParamByName("fecha")->AsDateTime = fecha_z;
  qry_polcampre->ParamByName("cia")->AsInteger = cia_z;
  qry_polcampre->ParamByName("tipopol")->AsString= tipopol_z;
  qry_polcampre->Open();
  if(qry_polcampre->IsEmpty()) return;
  for(qry_polcampre->First(); !qry_polcampre->Eof; qry_polcampre->Next()) {
    idpolcampre_z = qry_polcampre->FieldByName("idpolcampre")->AsInteger;
    qry_renpolcampre->Close();
    qry_renpolcampre->ParamByName("IDPOLCAMPRE")->AsInteger = idpolcampre_z;
    qry_renpolcampre->Open();
    aplica_cambio();
    qry_polcampre->Edit();
    qry_polcampre->FieldByName("status")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICADO;
    qry_polcampre->Post();
  }
  if (qry_polcampre->UpdatesPending) {
      try {
      dm->manvehi->StartTransaction();
      qry_polcampre->ApplyUpdates();
      dm->manvehi->Commit();
      Application->MessageBox("Se han aplicado los cambios de precios", "Cambios de Precios", MB_ICONEXCLAMATION);
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }

}
//---------------------------------------------------------------------------


void __fastcall TForm_polcampre::aplica_cambio()
{
  int ancho_z, alto_z, idrenpol_z=0, idart_z=0, idpol_z=0, conse_z,
    antidempaq_z, idnvoempaq_z, idobservs_z, idrelinv_z, idgarantia_z;
  TDateTime fechapol_z, fecvig_z;
  TLocateOptions Opts;
  double antprmds_z=0, antprelec_z=0, precmds_z=0, precelec_z=0, precioext_z,
  costoext_z;
  String codigo_z, nvasit_z, observs_z, obscam_z, antsit_z,
     descri_z, garantia_z;
  Opts.Clear();

  fecvig_z = qry_polcampre->FieldByName("fecini")->AsDateTime;

  for (qry_renpolcampre->First(); !qry_renpolcampre->Eof; qry_renpolcampre->Next()) {
    codigo_z = qry_renpolcampre->FieldByName("codigo")->AsString;
    idart_z = qry_renpolcampre->FieldByName("idart")->AsInteger;
    idgarantia_z = qry_renpolcampre->FieldByName("idgarantia")->AsInteger;
    idrenpol_z = qry_renpolcampre->FieldByName("IDRENPOLCAMPRE")->AsInteger;
    idpol_z = qry_renpolcampre->FieldByName("idPOLCAMPRE")->AsInteger;
    antprmds_z = qry_renpolcampre->FieldByName("antprmds")->AsFloat;
    antprelec_z = qry_renpolcampre->FieldByName("antprelec")->AsFloat;
    precmds_z = qry_renpolcampre->FieldByName("precmds")->AsFloat;
    precelec_z = qry_renpolcampre->FieldByName("precelec")->AsFloat;
    antidempaq_z = qry_renpolcampre->FieldByName("antempaq")->AsInteger;
    nvasit_z = qry_renpolcampre->FieldByName("nuevasit")->AsString;
    idnvoempaq_z = qry_renpolcampre->FieldByName("nvoempaq")->AsInteger;
    idobservs_z = qry_renpolcampre->FieldByName("idobserv")->AsInteger;
    precioext_z = qry_renpolcampre->FieldByName("precioext")->AsFloat;
    costoext_z = qry_renpolcampre->FieldByName("costoext")->AsFloat;
    idgarantia_z = qry_renpolcampre->FieldByName("idgarantia")->AsInteger;
    observs_z = qry_renpolcampre->FieldByName("concep")->AsString;
    qry_inven->Close();
    qry_inven->ParamByName("codigo")->AsString = codigo_z;
    qry_inven->ParamByName("cia")->AsInteger = cia_z;
    qry_inven->Open();
    if(qry_inven->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe ese artículo", "Artículo Inexistente", MB_ICONEXCLAMATION);
      return;
    }
    qry_inven->Edit();
    qry_inven->FieldByName("precio")->AsFloat = precmds_z;
    qry_inven->FieldByName("precelec")->AsFloat = precelec_z;
    qry_inven->FieldByName("empaqe")->AsString = nvasit_z;
    qry_inven->Post();
    qry_invrelinv->Close();
    qry_invrelinv->ParamByName("idart")->AsInteger = idart_z;
    qry_invrelinv->Open();
    idrelinv_z = dm->busca_sigid(IDRELINV);
    if(agrega_relinv(idart_z, REL_INVEN_SITUACION, idnvoempaq_z, idrelinv_z) == NUEVO) idrelinv_z++;
    if(agrega_relinv(idart_z, REL_INVEN_GARANTIA,  idgarantia_z, idrelinv_z) == NUEVO) idrelinv_z++;
    qry_invulpre->Close();
    qry_invulpre->ParamByName("codigo")->AsString = codigo_z;
    qry_invulpre->ParamByName("fecha")->AsDateTime = fecvig_z;
    qry_invulpre->ParamByName("cia")->AsInteger = cia_z;
    qry_invulpre->Open();
    if(qry_invulpre->IsEmpty()) {
      qry_invulpre->Append();
      qry_invulpre->FieldByName("codigo")->AsString = codigo_z;
      qry_invulpre->FieldByName("fecha")->AsDateTime = fecvig_z;
      qry_invulpre->FieldByName("cia")->AsInteger = cia_z;
    } else {
      qry_invulpre->Edit();
    }
    qry_invulpre->FieldByName("precmds")->AsFloat = precmds_z;
    qry_invulpre->FieldByName("precelec")->AsFloat    = precelec_z;
    qry_invulpre->FieldByName("empqe")->AsString = nvasit_z;
    qry_invulpre->FieldByName("observs")->AsString = observs_z;
    qry_invulpre->FieldByName("fecinivig")->AsDateTime = fecvig_z;
    qry_invulpre->Post();
    //qry_invxtensa->Close();
    //qry_invxtensa->ParamByName("idart")->AsInteger = idart_z;
    //qry_invxtensa->ParamByName("cia")->AsInteger = cia_z;
    //qry_invxtensa->Open();
    //if(qry_invxtensa->IsEmpty()) {
    //  qry_invxtensa->Append();
    //  qry_invxtensa->FieldByName("idextensa")->AsInteger = dm->busca_sigid(IDEXTENSA);
    //  qry_invxtensa->FieldByName("idart")->AsInteger = idart_z;
    //  qry_invxtensa->FieldByName("cia")->AsInteger = cia_z;
    //} else {
    //  qry_invxtensa->Edit();
    //}
    //qry_invxtensa->FieldByName("precioext")->AsFloat  = precioext_z;
    //qry_invxtensa->FieldByName("costoext")->AsFloat   = costoext_z;
    //qry_invxtensa->Post();
    qry_observent->Close();
    qry_observent->ParamByName("tipo")->AsString = tipoobserv_z;
    qry_observent->ParamByName("codigo")->AsString = codigo_z;
    qry_observent->ParamByName("fecha")->AsDateTime = fecvig_z;
    qry_observent->ParamByName("cia")->AsInteger = cia_z;
    qry_observent->Open();
    conse_z = 0;
    if(!qry_observent->IsEmpty()) {
      qry_observent->Last();
      conse_z = qry_observent->FieldByName("conse")->AsInteger;
    }
    conse_z++;
    obscam_z = "CAMB.PREC: (Antes) P.L:" + FormatFloat("###,##0.00", antprmds_z);
    obscam_z += " P.FIDE:" + FormatFloat("###,##0.00", antprelec_z);
    obscam_z += " SIT:" + antsit_z;
    agrega_obs(conse_z, fecvig_z, obscam_z, codigo_z);
    conse_z++;
    obscam_z = "CAMB.PREC: (Ahora) P.L:" + FormatFloat("###,##0.00", precmds_z);
    obscam_z += " P.FIDE:" + FormatFloat("###,##0.00", precelec_z);
    agrega_obs(conse_z, fecvig_z, obscam_z, codigo_z);
    obscam_z = "Vigencia:" + FormatDateTime("dd/mm/yyyy", fecvig_z) + " Nueva SIT:" + nvasit_z;
    agrega_obs(conse_z, fecvig_z, obscam_z, codigo_z);
    try {
      dm->manvehi->StartTransaction();
      qry_inven->ApplyUpdates();
      qry_observent->ApplyUpdates();
      //qry_invxtensa->ApplyUpdates();
      qry_invulpre->ApplyUpdates();
      qry_invrelinv->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::aplica_cambio_situacion()
{
  int ancho_z, alto_z, idrenpol_z=0, idart_z=0, idpol_z=0, conse_z,
    antidempaq_z, idnvoempaq_z, idobservs_z, idrelinv_z, idgarantia_z;
  TDateTime fechapol_z, fecvig_z;
  TLocateOptions Opts;
  double antprmds_z=0, antprelec_z=0, precmds_z=0, precelec_z=0, precioext_z,
  costoext_z;
  String codigo_z, nvasit_z, observs_z, obscam_z, antsit_z,
     descri_z, garantia_z;
  Opts.Clear();

  fecvig_z = qry_polcampre->FieldByName("fecini")->AsDateTime;

  for (qry_renpolcampre->First(); !qry_renpolcampre->Eof; qry_renpolcampre->Next()) {
    codigo_z = qry_renpolcampre->FieldByName("codigo")->AsString;
    idart_z = qry_renpolcampre->FieldByName("idart")->AsInteger;
    idrenpol_z = qry_renpolcampre->FieldByName("IDRENPOLCAMPRE")->AsInteger;
    idpol_z = qry_renpolcampre->FieldByName("idPOLCAMPRE")->AsInteger;
    antidempaq_z = qry_renpolcampre->FieldByName("antempaq")->AsInteger;
    nvasit_z = qry_renpolcampre->FieldByName("nuevasit")->AsString;
    idnvoempaq_z = qry_renpolcampre->FieldByName("nvoempaq")->AsInteger;
    qry_inven->Close();
    qry_inven->ParamByName("codigo")->AsString = codigo_z;
    qry_inven->ParamByName("cia")->AsInteger = cia_z;
    qry_inven->Open();
    if(qry_inven->IsEmpty()) {
      Application->MessageBox("Lo siento, no Existe ese artículo", "Artículo Inexistente", MB_ICONEXCLAMATION);
      return;
    }
    qry_inven->Edit();
    qry_inven->FieldByName("empaqe")->AsString = nvasit_z;
    qry_inven->Post();
    qry_invrelinv->Close();
    qry_invrelinv->ParamByName("idart")->AsInteger = idart_z;
    qry_invrelinv->Open();
    idrelinv_z = dm->busca_sigid(IDRELINV);
    if(agrega_relinv(idart_z, REL_INVEN_SITUACION, idnvoempaq_z, idrelinv_z) == NUEVO) idrelinv_z++;
    try {
      dm->manvehi->StartTransaction();
      qry_inven->ApplyUpdates();
      qry_invrelinv->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------


void __fastcall TForm_polcampre::agrega_obs(
int conse_z, double fechapol_z, String obscam_z, String codigo_z)
{
    qry_observent->Append();
    qry_observent->FieldByName("tipo")->AsString = tipoobserv_z;
    qry_observent->FieldByName("alm")->AsString = "";
    qry_observent->FieldByName("numero")->AsInteger = 0;
    qry_observent->FieldByName("fecha")->AsDateTime = fechapol_z;
    qry_observent->FieldByName("observs")->AsString = obscam_z;
    qry_observent->FieldByName("codigo")->AsString = codigo_z;
    qry_observent->FieldByName("cia")->AsInteger = cia_z;
    qry_observent->Post();
}
//---------------------------------------------------------------------------

int __fastcall TForm_polcampre::agrega_relinv(int idart_z, int tiporel_z, int iddatorel_z, int idrelinv_z)
{
  TLocateOptions Opts;
  int result_z;
  Opts.Clear();
  qry_invrelinv->First();
  if(qry_invrelinv->Locate("idrel", tiporel_z, Opts)) {
    qry_invrelinv->Edit();
    result_z = MODIF;
  } else {
    qry_invrelinv->Append();
    qry_invrelinv->FieldByName("idrelinv")->AsInteger = idrelinv_z;
    qry_invrelinv->FieldByName("idart")->AsInteger = idart_z;
    qry_invrelinv->FieldByName("idrel")->AsInteger = tiporel_z;
    qry_invrelinv->FieldByName("conse")->AsInteger = 0;
    result_z = NUEVO;
  }
  qry_invrelinv->FieldByName("iddato")->AsInteger = iddatorel_z;
  qry_invrelinv->Post();
  return (result_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;
}
//---------------------------------------------------------------------------


void __fastcall TForm_polcampre::cierra_entradaExecute(TObject *Sender)
{
  int result_z;
  if(qry_polcampre->State == dsInactive) return;
  if(qry_polcampre->FieldByName("status")->AsInteger == EDO_CERRADO) {
    Application->MessageBox("No puedes Cerrar pólizas cerradas", "Póliza Cerrada", MB_ICONEXCLAMATION);
    return;
  }
  result_z = Application->MessageBox("Desea cerrar esta póliza", "Cerrar Póliza", MB_ICONQUESTION + MB_YESNO);
  if( result_z != IDYES) return;
  qry_polcampre->Edit();
  qry_polcampre->FieldByName("status")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
  qry_polcampre->Post();
  try {
     dm->manvehi->StartTransaction();
     qry_polcampre->ApplyUpdates();
     dm->manvehi->Commit();
  } catch (Exception &E)
  {
     dm->manvehi->Rollback();
     dm->MensajeError("No pude grabar los datos:\n"+E.Message, "ERROR");
  }
  if (tipopol_z == "S") {
     aplica_cambio_situacion();
  }
  busca_polcampre(qry_polcampre->FieldByName("folio")->AsInteger);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::imprimeExecute(TObject *Sender)
{
  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TRadioButton *rbtn_poliza = new TRadioButton (Dlg_analipol);
  rbtn_poliza->Parent = Dlg_analipol->Panel1;
  rbtn_poliza->Caption = "Reporte de Póliza";
  rbtn_poliza->Top  = 20;
  rbtn_poliza->Left = 20;

  TRadioButton *rbtn_boletin = new TRadioButton (Dlg_analipol);
  rbtn_boletin->Parent = Dlg_analipol->Panel1;
  rbtn_boletin->Caption = "Boletín de Precios";
  rbtn_boletin->Checked = true;
  rbtn_boletin->Top  = rbtn_poliza->Top + rbtn_poliza->Height + 4;
  rbtn_boletin->Left = 20;
  TCheckBox *chk_impenc = new TCheckBox(Dlg_analipol);
  chk_impenc->Parent = Dlg_analipol->Panel1;
  chk_impenc->Caption = "Imprimir Titulo en Encabezado";
  chk_impenc->Checked = true;
  chk_impenc->Top  = rbtn_boletin->Top + rbtn_boletin->Height + 4;
  chk_impenc->Left = 20;
  chk_impenc->Visible = false;
  chk_impenc->Checked = true;
  if (tipopol_z == "P") {
    Dlg_analipol->Caption = "Desea Impresión de Póliza o Boletín ?";
    chk_impenc->Width = 200;
    chk_impenc->Caption = "Imprimir Titulo en Encabezado";
    chk_impenc->Visible = true;
  }
  if (tipopol_z == "O") {
    Dlg_analipol->Caption = "Desea Impresión de Póliza ofertas ?";
    rbtn_boletin->Visible = false;
    rbtn_poliza->Checked = true;
    chk_impenc->Width = 200;
    chk_impenc->Caption = "Imprimir Titulo en Encabezado";
    chk_impenc->Visible = true;
  }
  if (tipopol_z == "T") {
    Dlg_analipol->Caption = "Desea Impresión de Póliza Outlet?";
    chk_impenc->Width = 200;
    chk_impenc->Caption = "Imprimir Titulo en Encabezado";
    chk_impenc->Visible = true;
    rbtn_boletin->Visible = false;
    rbtn_poliza->Checked = true;
  }
  if (tipopol_z == "N") {
    Dlg_analipol->Caption = "Desea Impresión Póliza ofertas Internet?";
    rbtn_boletin->Visible = false;
    rbtn_poliza->Checked = true;
    chk_impenc->Width = 200;
    chk_impenc->Caption = "Imprimir Titulo en Encabezado";
    chk_impenc->Visible = true;
  }

  //Dlg_analipol->Width = ancho_z;
  //Dlg_analipol->Height = alto_z;
  if( chk_impenc->Checked) {
     impenc_z = "S";
  } else {
     impenc_z = "N";
  }
  if(Dlg_analipol->ShowModal() == mrOk) {
    if(   rbtn_boletin->Checked ) {
      boletin_precios();
    } else {
      impresion_poliza();
    }
  }
  delete Dlg_analipol;

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::impresion_poliza()
{
   String arch_z, dato_z, sql_z, codigo_z;
   int ii_z =0, idpolcampre_z;
   double precio_z=0, servicio_z=0;
   arch_z = "form_polcampre.txt";
   if(qry_polcampre->State == dsInactive) return;
   idpolcampre_z =  qry_polcampre->FieldByName("idpolcampre")->AsInteger;
   if(qry_polcampre->FieldByName("status")->AsInteger == INV_STATUS_CAMBIO_PRECIO_CREADO) {
     Application->MessageBox("No puedes Imprimir pólizas Abiertas", "Póliza Abierta", MB_ICONEXCLAMATION);
     return;
   }
   if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
   }
   pagina_z = 1;
   qry_renpolcampre->Close();
   sql_z = " select IDRENPOLCAMPRE, IDPOLCAMPRE, a.IDART, ANTPRMDS, ANTPRELEC, a.PRECMDS, ";
   sql_z += " a.PRECELEC, ANTEMPAQ, NVOEMPAQ, a.IDOBSERV, PRECIOEXT, COSTOEXT, a.IDGARANTIA,";
   sql_z += " b.clave, b.descri as descrigtia,";
   sql_z += " d.codigo, d.descri, e.concep, d.cod2 as grupo, d.linea,";
   sql_z += " f.situacion as antersit, g.situacion as nuevasit, ";
   sql_z += " ( case coston when 0 then 0 else 100 * (1 - ( coston / (precio + 0.001))) end ) as mub";
   if (tipopol_z == "P") {
     sql_z += " from inv_renpolcampre a ";
   }
   if (tipopol_z == "O") {
     sql_z += " from inv_renpolofertas a ";
   }
   if (tipopol_z == "T") {
     sql_z += " from inv_renpolofertas a ";
   }
   if (tipopol_z == "N") {
     sql_z += " from inv_renpolofertas a ";
   }
   sql_z += " join inv_garantias b on a.idgarantia = b.idgarantia";
   sql_z += " join inv_invhist c on a.idart = c.idart";
   sql_z += " join inven d on c.codigo = d.codigo and c.cia = d.cia";
   sql_z += " join inv_conceps e on a.idobserv = e.idconcep";
   sql_z += " join inv_situaciones f on a.antempaq = f.idsituac";
   sql_z += " join inv_situaciones g on a.nvoempaq = g.idsituac";
   sql_z += " where IDPOLCAMPRE = :IDPOLCAMPRE";
   if (tipopol_z == "P") {
      sql_z += " order by IDRENPOLCAMPRE";
   }
   if (tipopol_z == "O") {
      sql_z += " order by d.linea, d.cod2, d.codigo, a.PRECMDS";
   }
   if (tipopol_z == "T") {
      sql_z += " order by d.linea, d.cod2, d.codigo, a.PRECMDS";
   }
   if (tipopol_z == "N") {
      sql_z += " order by d.linea, d.cod2, d.codigo, a.PRECMDS";
   }
   qry_renpolcampre->SQL->Text = sql_z;
   qry_renpolcampre->ParamByName("IDPOLCAMPRE")->AsInteger = idpolcampre_z;
   qry_renpolcampre->Open();
   antlinea_z = qry_renpolcampre->FieldByName("linea")->AsString;

   report_encab();
   ii_z = qry_renpolcampre->RecordCount;
   for(qry_renpolcampre->First(); !qry_renpolcampre->Eof; qry_renpolcampre->Next()) {
     if (tipopol_z == "O" || tipopol_z == "T"  || tipopol_z == "N") {
       if(antlinea_z != qry_renpolcampre->FieldByName("linea")->AsString ) {
         antlinea_z   = qry_renpolcampre->FieldByName("linea")->AsString;
         report_subenc();
       }
     }

     checa_salto_pag(5);
     ii_z--;
     if(!ii_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

     fprintf(archout, "|%s|", ljust(qry_renpolcampre->FieldByName("codigo")->AsString,13 ));
     fprintf(archout, "%s|", ljust(qry_renpolcampre->FieldByName("descri")->AsString,30 ));
     if (tipopol_z == "P") {
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", qry_renpolcampre->FieldByName("antprmds")->AsFloat),12));
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", qry_renpolcampre->FieldByName("antprelec")->AsFloat),12));
       fprintf(archout, "%s|", ljust(qry_renpolcampre->FieldByName("antersit")->AsString,10));
     }
     precio_z = qry_renpolcampre->FieldByName("precmds")->AsFloat;
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", precio_z),12));
     if (tipopol_z == "P") {
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", qry_renpolcampre->FieldByName("precelec")->AsFloat),12));
       fprintf(archout, "%s|", ljust(qry_renpolcampre->FieldByName("nuevasit")->AsString,10));
       fprintf(archout, "%s|", rjust(qry_renpolcampre->FieldByName("clave")->AsString,3));
     }
     if (tipopol_z == "Oferta") {
       //Esta condición ya no se va a cumplir, debe ser solo "O"
       // 27-Mar-2021 Se modifica para que no se impriman las columnas
       // de Servicio y Total
       codigo_z = qry_renpolcampre->FieldByName("codigo")->AsString;
       servicio_z = busca_servicio(codigo_z) / 100;
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", servicio_z),12));
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", precio_z + servicio_z),12));
     }
     if (tipopol_z == "T") {
       codigo_z = qry_renpolcampre->FieldByName("codigo")->AsString;
       servicio_z = busca_servicio(codigo_z) / 100;
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", servicio_z),12));
       fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", precio_z + servicio_z),12));
     }
     if (tipopol_z == "N") {
       codigo_z = qry_renpolcampre->FieldByName("codigo")->AsString;
       //servicio_z = busca_servicio(codigo_z) / 100;
       //fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", servicio_z),12));
       //fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", precio_z + servicio_z),12));
     }
     if(!ii_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
     salta_linea(1);

   }
   if (tipopol_z == "O" || tipopol_z == "T" || tipopol_z == "N") {
     checa_salto_pag(3);
     fprintf(archout, "%s", AnsiString::StringOfChar('-', 74));
     salta_linea(1);
     qry_obsoferta->Close();
     qry_obsoferta->ParamByName("tipo")->AsString = tipopol_z;
     qry_obsoferta->ParamByName("alm")->AsString = "";
     qry_obsoferta->ParamByName("cia")->AsInteger = cia_z;
     qry_obsoferta->Open();
     for(qry_obsoferta->First(); !qry_obsoferta->Eof; qry_obsoferta->Next()) {
       fprintf(archout, "%s", qry_obsoferta->FieldByName("observs")->AsString);
       salta_linea(1);
       checa_salto_pag(3);

     }
   }

   fclose(archout);
   dm->manda_impresion(arch_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::boletin_precios()
{
   String arch_z, dato_z, sql_z, codigo_z, grupo_z, linea_z,
     miscarac_z, strplazo_z, nvasit_z;
   int ii_z =0, plazo_z;
   double precio_z=0;
   arch_z = "form_polcampre.txt";
   tiporep_z = "V";
   if(qry_polcampre->State == dsInactive) return;
   if(qry_polcampre->FieldByName("status")->AsInteger == INV_STATUS_CAMBIO_PRECIO_CREADO) {
     Application->MessageBox("No puedes Imprimir pólizas Abiertas", "Póliza Abierta", MB_ICONEXCLAMATION);
     return;
   }
   if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
       Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
       return;
   }
   pagina_z = 1;
   TQuery *qry_boletin = new TQuery(this);
   sql_z = "select IDRENPOLCAMPRE, IDPOLCAMPRE, a.IDART, ANTPRMDS, ANTPRELEC, a.PRECMDS, ";
   sql_z += "a.PRECELEC, ANTEMPAQ, NVOEMPAQ, a.IDOBSERV, PRECIOEXT, COSTOEXT, a.IDGARANTIA, ";
   sql_z += "b.clave, b.descri as descrigtia, ";
   sql_z += "d.codigo, d.cod2, d.descri, e.concep, d.linea, ";
   sql_z += "f.situacion as antersit, g.situacion as nuevasit, ";
   sql_z += "( case coston when 0 then 0 else 100 * (1 - ( coston / (precio + 0.001))) end ) as mub ";
   sql_z += "from inv_renpolcampre a join inv_garantias b on a.idgarantia = b.idgarantia ";
   sql_z += "join inv_invhist c on a.idart = c.idart ";
   sql_z += "join inven d on c.codigo = d.codigo and c.cia = d.cia ";
   sql_z += "join inv_conceps e on a.idobserv = e.idconcep ";
   sql_z += "join inv_situaciones f on a.antempaq = f.idsituac ";
   sql_z += "join inv_situaciones g on a.nvoempaq = g.idsituac ";
   sql_z += "where IDPOLCAMPRE = :IDPOLCAMPRE order by d.linea, IDRENPOLCAMPRE";
   qry_boletin->DatabaseName = qry_renpolcampre->DatabaseName;
   qry_boletin->SQL->Text = sql_z;
   qry_boletin->ParamByName("idpolcampre")->AsInteger = qry_polcampre->FieldByName("idpolcampre")->AsInteger;
   qry_boletin->Open();

   ii_z = qry_boletin->RecordCount;
   antlinea_z = "xx";
   for(qry_boletin->First(); !qry_boletin->Eof; qry_boletin->Next()) {
     linea_z = qry_boletin->FieldByName("linea")->AsString;
     precio_z = qry_boletin->FieldByName("precmds")->AsFloat;
     codigo_z = qry_boletin->FieldByName("codigo")->AsString;
     grupo_z = qry_boletin->FieldByName("cod2")->AsString;
     if(antlinea_z != qry_boletin->FieldByName("linea")->AsString ) {
       if (antlinea_z == "xx") {
           antlinea_z   = qry_boletin->FieldByName("linea")->AsString;
           report_encab();
       } else {
         antlinea_z   = qry_boletin->FieldByName("linea")->AsString;
         report_subenc();
       }
     }
     checa_salto_pag(5);
     ii_z--;
     nvasit_z = qry_boletin->FieldByName("nuevasit")->AsString;
     if ( nvasit_z == "REMATE") {
       plazo_z = 0;
     } else {
       plazo_z =     busca_plazo(codigo_z, linea_z, grupo_z, precio_z);
     }
     plazo_z = plazo_z * 2;
     strplazo_z = IntToStr(plazo_z) + " Q";

     miscarac_z = busca_descri(codigo_z);
     if(!ii_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));

     fprintf(archout, "%s|", ljust(qry_boletin->FieldByName("descri")->AsString,30 ));
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
     fprintf(archout, "%s|", ljust(miscarac_z,50 ));
     fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
     fprintf(archout, "%s|", ljust(nvasit_z,10));
     fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00", precio_z),12));
     fprintf(archout, "%s|", rjust(strplazo_z,4));
     if(!ii_z) fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
     salta_linea(1);
   }
   fclose(archout);
   dm->manda_impresion(arch_z);

}
//---------------------------------------------------------------------------

int __fastcall TForm_polcampre::busca_plazo(String codigo_z, String linea_z, String grupo_z, double precio_z)
{
  int plazo_z=0, tipopzo_z=0, plazolin_z=0;
  bool buscaotro_z = true;
  qry_plazoxarticulo->Close();
  qry_plazoxarticulo->ParamByName("codigo")->AsString = codigo_z;
  qry_plazoxarticulo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_ARTICULO;
  qry_plazoxarticulo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxarticulo->Open();
  if(!qry_plazoxarticulo->IsEmpty()) {
    plazo_z = qry_plazoxarticulo->FieldByName("plazomax")->AsInteger;
    return (plazo_z);
  }
  qry_plazoxgrupo->Close();
  qry_plazoxgrupo->ParamByName("codigo")->AsString = grupo_z;
  qry_plazoxgrupo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_GRUPO_PRIORIDAD;
  qry_plazoxgrupo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxgrupo->Open();
  if(!qry_plazoxgrupo->IsEmpty()) {
    plazo_z = qry_plazoxgrupo->FieldByName("plazomax")->AsInteger;
    return (plazo_z);
  }
  qry_plazoxlin->Close();
  qry_plazoxlin->ParamByName("linea")->AsString = linea_z;
  qry_plazoxlin->ParamByName("tipo")->AsInteger = TIPO_PLAZO_LINEA_PRIORIDAD;
  qry_plazoxlin->ParamByName("tipo4")->AsInteger = TIPO_PLAZO_LINEA_X_TABLA;
  qry_plazoxlin->ParamByName("tipo2")->AsInteger = TIPO_PLAZO_LINEA_X_GRUPO;
  qry_plazoxlin->ParamByName("tipo3")->AsInteger = TIPO_PLAZO_X_GRUPOX_TABLA;
  qry_plazoxlin->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxlin->Open();
  if(!qry_plazoxlin->IsEmpty()) {
    plazo_z = qry_plazoxlin->FieldByName("plazomax")->AsInteger;
    tipopzo_z = qry_plazoxlin->FieldByName("tipo")->AsInteger;
    plazolin_z = plazo_z;
    if(tipopzo_z == TIPO_PLAZO_LINEA_PRIORIDAD) return (plazo_z);
  }
  qry_plazoxprecio->Close();
  qry_plazoxprecio->ParamByName("precio")->AsFloat = precio_z;
  qry_plazoxprecio->ParamByName("tipo")->AsInteger = TIPO_PLAZO_PRECIO;
  qry_plazoxprecio->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxprecio->Open();
  if(plazo_z > qry_plazoxprecio->FieldByName("plazomax")->AsInteger) {
    plazo_z = qry_plazoxprecio->FieldByName("plazomax")->AsInteger;
  } // Esto para que no me confunda de IF. o;o
  qry_plazoxgrupo->Close();
  qry_plazoxgrupo->ParamByName("codigo")->AsString = grupo_z;
  qry_plazoxgrupo->ParamByName("tipo")->AsInteger = TIPO_PLAZO_GRUPO;
  qry_plazoxgrupo->ParamByName("cia")->AsInteger = cia_z;
  qry_plazoxgrupo->Open();
  if(!qry_plazoxgrupo->IsEmpty() && plazo_z > qry_plazoxgrupo->FieldByName("plazomax")->AsInteger) {
    plazo_z = qry_plazoxgrupo->FieldByName("plazomax")->AsInteger;
  } // Esto para que no me confunda de IF. o;o
  return (plazo_z);
}
//---------------------------------------------------------------------------



String __fastcall TForm_polcampre::busca_descri(String codigo_z)
{
  String descrilar_z="";
  qry_descri2->Close();
  qry_descri2->ParamByName("codigo")->AsString = codigo_z;
  qry_descri2->ParamByName("cia")->AsInteger = cia_z;
  qry_descri2->ParamByName("idrel")->AsInteger = REL_INVEN_DESCRILAR;
  qry_descri2->Open();
  if(!qry_descri2->IsEmpty()) {
    descrilar_z = qry_descri2->FieldByName("descri")->AsString;
  }
  return (descrilar_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::salta_linea(int cuantas_z)
{
  for(; cuantas_z > 0; cuantas_z--) {
    fprintf(archout, "\n"); lineas_z++;
  }
}
//---------------------------------------------------------------------------

bool __fastcall TForm_polcampre::checa_salto_pag(int margen_z)
{
  bool haysalto_z = false;
  if(lineas_z > (MAX_LINEAS - margen_z)) {
    fprintf(archout, "%c", 12);
    pagina_z++;
    report_encab();
    haysalto_z = true;
  }
  return (haysalto_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::report_encab()
{
  String situini_z,situfin_z,tit1_z,tit2_z;
  int folio_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_polcampre " + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );
  folio_z = qry_polcampre->FieldByName("folio")->AsInteger;
  if(tiporep_z == "V")  {
    tit2_z = "Boletin ";
    if (tipopol_z == "O") {
        tit2_z = tit2_z + "De Ofertas ";
    }
    if (tipopol_z == "N") {
        tit2_z = tit2_z + "Ofertas Internet";
    }
    if (tipopol_z == "T") {
        tit2_z = tit2_z + "De Outlet";
    }
    if(tipopol_z == "P") {
        tit2_z = tit2_z + "Cambio de Precios";
    }
    if(impenc_z == "S") {
        tit2_z = Frame_datospolcampre1->edt_concepto->Text.Trim();
    }
  } else {
    if (tipopol_z == "P") {
      if(impenc_z == "S") {
        tit2_z = Frame_datospolcampre1->edt_concepto->Text.Trim();
      } else {
        tit2_z = "Actualizacion de Precios";
      }
    }
    if (tipopol_z == "O") {
      if(impenc_z == "S") {
        tit2_z += Frame_datospolcampre1->edt_concepto->Text.Trim();
      } else {
        tit2_z += "Lista de Precios de Ofertas";
      }
    }
    if (tipopol_z == "T") {
      if(impenc_z == "S") {
        tit2_z += Frame_datospolcampre1->edt_concepto->Text.Trim();
      } else {
        tit2_z += "Lista de Precios de Outlet ";
      }
    }
    if (tipopol_z == "N") {
      if(impenc_z == "S") {
        tit2_z += Frame_datospolcampre1->edt_concepto->Text.Trim();
      } else {
        tit2_z += "Lista de Precios Ofertas Internet ";
      }
    }
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", cjust( tit2_z, 40));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  tit2_z = " Poliza :" + qry_polcampre->FieldByName("folio")->AsString;
  tit2_z += " Fecha: " + FormatDateTime("dd/mm/yyyy", qry_polcampre->FieldByName("fecha")->AsDateTime);
  fprintf(archout, "%s\n", tit2_z);
  tit2_z = " Vigencia a Partir del:" + FormatDateTime("dd/mm/yyyy", qry_polcampre->FieldByName("fecini")->AsDateTime);
  if (tipopol_z == "O") {
    tit2_z += " Hasta el " + FormatDateTime("dd/mm/yyyy", qry_polcampre->FieldByName("fecfin")->AsDateTime);
  }
  if (tipopol_z == "T") {
    tit2_z += " Hasta el " + FormatDateTime("dd/mm/yyyy", qry_polcampre->FieldByName("fecfin")->AsDateTime);
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", tit2_z);
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout,"\n");
  if (tipopol_z == "P") {
      if(tiporep_z != "V") {
         fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
      }
  }
  fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  if(tiporep_z == "V") {
    fprintf(archout, "%s|", ljust("Descripcion",30 ));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
    fprintf(archout, "%s|", ljust("Caracteristicas",50 ));
    fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_OFF));
    fprintf(archout, "%s|", ljust("Condicion",10 ));
    fprintf(archout, "%s|", rjust("Precio",12 ));
    fprintf(archout, "%s|", rjust("Pzo",4 ));
  } else {
    fprintf(archout, "%s|", ljust("Codigo",13 ));
    fprintf(archout, "%s|", ljust("Descripcion",30 ));
    if (tipopol_z == "P") {
      fprintf(archout, "%s|", rjust("Ant.Prec.MDS",12));
      fprintf(archout, "%s|", rjust("Ant.Pre.FIDE",12));
      fprintf(archout, "%s|", ljust("Ant.Situac",10));
      fprintf(archout, "%s|", rjust("Nvo.Prec.MDS",12));
      fprintf(archout, "%s|", rjust("Nvo.Pre.FIDE",12));
      fprintf(archout, "%s|", ljust("Nva.Situac",10));
      fprintf(archout, "%s|", rjust("Pzo", 3));
    }
    if (tipopol_z == "O") {
      fprintf(archout, "%s|", rjust("Precio.Ofert",12));
      // 27_mar-2021 Se bloquea que se imprima Servicio y Total
      // fprintf(archout, "%s|", rjust("Servicio",12));
      // fprintf(archout, "%s|", rjust("Total",12));
    }
    if (tipopol_z == "T") {
      fprintf(archout, "%s|", rjust("Precio.Outlet",12));
      fprintf(archout, "%s|", rjust("Servicio",12));
      fprintf(archout, "%s|", rjust("Total",12));
    }
    if (tipopol_z == "N") {
      fprintf(archout, "%s|", rjust("Oferta Internet",12));
      //fprintf(archout, "%s|", rjust("Servicio",12));
      //fprintf(archout, "%s|", rjust("Total",12));
    }
  }
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  lineas_z = 5;
  if(tiporep_z == "V") { report_subenc(); }
  if(tipopol_z == "O") { report_subenc(); }
  if(tipopol_z == "T") { report_subenc(); }
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::report_subenc()
{
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "Linea: %s %s", antlinea_z, busca_descrilin(antlinea_z));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  fprintf(archout, "\n"); lineas_z++;
}
//---------------------------------------------------------------------------



void __fastcall TForm_polcampre::despliega_renglonExecute(TObject *Sender)
{
  int ancho_z, alto_z, idrenpol_z=0, idart_z=0, idpol_z=0, conse_z,
    antidempaq_z, idnvoempaq_z, idobservs_z, idrelinv_z, idgarantia_z;
  TDateTime fechapol_z, fecvig_z;
  TLocateOptions Opts;
  double antprmds_z=0, antprelec_z=0, precmds_z=0, precelec_z=0, precioext_z,
  costoext_z;
  String codigo_z, nvasit_z, observs_z,
  titulo_z, obscam_z, antsit_z, descri_z, garantia_z;
  Opts.Clear();
  if(qry_renpolcampre->State == dsInactive) return;
  fechapol_z = qry_polcampre->FieldByName("fecha")->AsDateTime;
  fecvig_z   = qry_polcampre->FieldByName("fecini")->AsDateTime;
  idpol_z    = qry_polcampre->FieldByName("idpolcampre")->AsInteger;
  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;
  TFrame_datosrenpolcampre *Frame_datosrenpolcampre;
  Frame_datosrenpolcampre = new TFrame_datosrenpolcampre (Dlg_analipol);
  ancho_z = Frame_datosrenpolcampre->Width + 20;
  alto_z = Frame_datosrenpolcampre->Height + Dlg_analipol->Panel2->Height + 80;
  Frame_datosrenpolcampre->Parent = Dlg_analipol->Panel1;
  Dlg_analipol->Width = ancho_z;
  Dlg_analipol->Height = alto_z;
  if (tipopol_z == "P") {
     titulo_z = "Datos del Cambios de Precios";
  }
  if (tipopol_z == "O") {
     titulo_z = "Datos de la Oferta";
     Frame_datosrenpolcampre->lbl_precioant->Visible = false;
     Frame_datosrenpolcampre->edt_precioant->Visible = false;
     Frame_datosrenpolcampre->lbl_precionvo->Caption = "Precio Oferta";
     Frame_datosrenpolcampre->edt_precionvo->Left = Frame_datosrenpolcampre->lbl_precionvo->Left + Frame_datosrenpolcampre->lbl_precionvo->Width + 4;
     Frame_datosrenpolcampre->lbl_subsidionvo->Visible = false;
     Frame_datosrenpolcampre->edt_fidenvo->Visible = false;
     Frame_datosrenpolcampre->lbl_subsidioant->Visible = false;
     Frame_datosrenpolcampre->edt_fideant->Visible = false;
     Frame_datosrenpolcampre->lbl_situanvo->Visible = false;
     Frame_datosrenpolcampre->lkcmb_situaciones->Visible = false;
     Frame_datosrenpolcampre->lbl_situaant->Visible = false;
     Frame_datosrenpolcampre->edt_antsit->Visible = false;
     Frame_datosrenpolcampre->lbl_garantia->Visible = false;
     Frame_datosrenpolcampre->lkcmb_garantia->Visible = false;
     Frame_datosrenpolcampre->dbedt_garantia->Visible = false;
     Frame_datosrenpolcampre->lbl_observs->Visible = false;
     Frame_datosrenpolcampre->edt_observs->Visible = false;
     Frame_datosrenpolcampre->lbl_costorepo->Visible = false;
     Frame_datosrenpolcampre->edt_costoxten->Visible = false;
     Frame_datosrenpolcampre->lbl_precioxtensa->Visible = false;
     Frame_datosrenpolcampre->edt_precioxten->Visible = false;
  }
  if (tipopol_z == "N") {
     titulo_z = "Datos Oferta Internet";
     Frame_datosrenpolcampre->lbl_precioant->Visible = false;
     Frame_datosrenpolcampre->edt_precioant->Visible = false;
     Frame_datosrenpolcampre->lbl_precionvo->Caption = "Pr.Oferta.Internet";
     Frame_datosrenpolcampre->edt_precionvo->Left = Frame_datosrenpolcampre->lbl_precionvo->Left + Frame_datosrenpolcampre->lbl_precionvo->Width + 4;
     Frame_datosrenpolcampre->lbl_subsidionvo->Visible = false;
     Frame_datosrenpolcampre->edt_fidenvo->Visible = false;
     Frame_datosrenpolcampre->lbl_subsidioant->Visible = false;
     Frame_datosrenpolcampre->edt_fideant->Visible = false;
     Frame_datosrenpolcampre->lbl_situanvo->Visible = false;
     Frame_datosrenpolcampre->lkcmb_situaciones->Visible = false;
     Frame_datosrenpolcampre->lbl_situaant->Visible = false;
     Frame_datosrenpolcampre->edt_antsit->Visible = false;
     Frame_datosrenpolcampre->lbl_garantia->Visible = false;
     Frame_datosrenpolcampre->lkcmb_garantia->Visible = false;
     Frame_datosrenpolcampre->dbedt_garantia->Visible = false;
     Frame_datosrenpolcampre->lbl_observs->Visible = false;
     Frame_datosrenpolcampre->edt_observs->Visible = false;
     Frame_datosrenpolcampre->lbl_costorepo->Visible = false;
     Frame_datosrenpolcampre->edt_costoxten->Visible = false;
     Frame_datosrenpolcampre->lbl_precioxtensa->Visible = false;
     Frame_datosrenpolcampre->edt_precioxten->Visible = false;
  }

  Frame_datosrenpolcampre->Align = alClient;
  Frame_datosrenpolcampre->edt_codigo->Tag = INACTIVO;
  Frame_datosrenpolcampre->edt_codigo->Text = qry_renpolcampre->FieldByName("codigo")->AsString;
  Frame_datosrenpolcampre->edt_descri->Text = qry_renpolcampre->FieldByName("descri")->AsString;
  Frame_datosrenpolcampre->edt_precionvo->Value = qry_renpolcampre->FieldByName("precmds")->AsFloat;
  Frame_datosrenpolcampre->edt_fidenvo->Value = qry_renpolcampre->FieldByName("precelec")->AsFloat;
  Frame_datosrenpolcampre->edt_precioxten->Value = qry_renpolcampre->FieldByName("precioext")->AsFloat;
  Frame_datosrenpolcampre->edt_costoxten->Value  = qry_renpolcampre->FieldByName("costoext")->AsFloat;
  Frame_datosrenpolcampre->lkcmb_situaciones->KeyValue = qry_renpolcampre->FieldByName("nvoempaq")->AsInteger;
  Frame_datosrenpolcampre->lkcmb_garantia->KeyValue = qry_renpolcampre->FieldByName("idgarantia")->AsInteger;
  Frame_datosrenpolcampre->edt_observs->Text = qry_renpolcampre->FieldByName("concep")->AsString;
  Frame_datosrenpolcampre->edt_precioant->Value = qry_renpolcampre->FieldByName("antprmds")->AsFloat;
  Frame_datosrenpolcampre->edt_fideant->Value = qry_renpolcampre->FieldByName("antprelec")->AsFloat;
  Frame_datosrenpolcampre->edt_antsit->Text = qry_renpolcampre->FieldByName("antersit")->AsString;
  Dlg_analipol->Caption = titulo_z;
  Dlg_analipol->btn_cancel->Visible = false;
  Dlg_analipol->ShowModal();
  delete Frame_datosrenpolcampre;
  delete Dlg_analipol;
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::dbgrd_renglonesDblClick(TObject *Sender)
{
  despliega_renglonExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::dbgrd_renglonesKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_SPACE) despliega_renglonExecute(Sender);
  if(Key == VK_INSERT) agrerenExecute(Sender);
  if(Key == VK_DELETE) elimina_renglonExecute(Sender);

}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::dbgrd_renglonesCustomDraw(TObject *Sender,
      TCanvas *ACanvas, TRect &ARect, TdxTreeListNode *ANode,
      TdxDBTreeListColumn *AColumn, const AnsiString AText, TFont *AFont,
      TColor &AColor, bool ASelected, bool AFocused, bool &ADone)
{
    if(!ASelected) if(ANode->Index % 2) AColor = clInfoBk;
}
//---------------------------------------------------------------------------


void __fastcall TForm_polcampre::aplica_cambiosExecute(TObject *Sender)
{
  busca_cambios_x_aplicar();
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::elimina_renglonExecute(TObject *Sender)
{
  bool si_borrar = true;
  int idrenpol_z = 0, status_z;
  String mensaje_z, titmsg_z;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede eliminar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  double costo_z = 0, piva_z = 0;
  if (qry_renpolcampre->IsEmpty()) return;
  mensaje_z = "Esta seguro de eliminar este movimiento ? ";
  titmsg_z = "Eliminar Movimiento";
  status_z = qry_polcampre->FieldByName("STATUS")->AsInteger;
  if(status_z == INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICADO) {
    Application->MessageBox("Lo siento, no puede modificar polizas cerradas", "Póliza Cerrada", MB_ICONEXCLAMATION);
    return;
  }

  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    idrenpol_z = qry_renpolcampre->FieldByName("IDRENPOLCAMPRE")->AsInteger;
    qry_renpolcampre->Delete();
    try {
      dm->manvehi->StartTransaction();
      if (qry_renpolcampre->UpdatesPending) qry_renpolcampre->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E) {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::exporta_dbgrdExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  TdxDBGrid* midbgrd_z;
//TAdvStringGrid* misgrd_z;
  String tipogrd_z;
  midbgrd_z = dbgrd_renglones;
  tipogrd_z="DBG";
//  switch (page_detalles->ActivePageIndex) {
//    case TBS_KARDEX  : midbgrd_z = dbgrd_kardex;   tipogrd_z="DBG"; break;
//    case TBS_ESTADIS : midbgrd_z = dbgrd_estadis;  tipogrd_z="DBG"; break;
//    case TBS_OBSERVS : midbgrd_z = dbgrd_observs;  tipogrd_z="DBG"; break;
//    case TBS_DISPONI : midbgrd_z = dbgrd_dispo;    tipogrd_z="DBG"; break;
//    case TBS_BUSSERIE: midbgrd_z = dbgrd_busserie; tipogrd_z="DBG"; break;
//    case TBS_EXIST   : midbgrd_z = dbgrd_exist;    tipogrd_z="DBG"; break;
//  }
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = midbgrd_z->Name + ".xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    if(tipogrd_z == "DBG") {
      switch( SaveDialog->FilterIndex) {
        case 1: midbgrd_z->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
        case 2: midbgrd_z->SaveToXLS(SaveDialog->FileName, true); break;
        case 3: midbgrd_z->SaveToHTML(SaveDialog->FileName, true); break;
      }
    }
//    else if (tipogrd_z == "ADV") {
//      switch( SaveDialog->FilterIndex) {
//        case 1: misgrd_z->SaveToCSV(SaveDialog->FileName); break;
//        case 2: misgrd_z->SaveToXLS(SaveDialog->FileName); break;
//        case 3: misgrd_z->SaveToHTML(SaveDialog->FileName); break;
//      }
//    }
  }
  delete SaveDialog;

}
//---------------------------------------------------------------------------

int __fastcall TForm_polcampre::busca_servicio(String codigo_z)
{

   int servicio_z = 0;
   qry_servicio->Close();
   qry_servicio->ParamByName("codigo")->AsString = codigo_z;
   qry_servicio->ParamByName("cia")->AsInteger = cia_z;
   qry_servicio->ParamByName("tipo")->AsInteger = SERVICIO_ARTICULO;
   qry_servicio->Open();
   if(qry_servicio->IsEmpty()) {
     qry_servxgpo->Close();
     qry_servxgpo->ParamByName("codigo")->AsString = codigo_z;
     qry_servxgpo->ParamByName("cia")->AsInteger = cia_z;
     qry_servxgpo->ParamByName("REL_GRUPO")->AsInteger = REL_INVEN_ARTDESP;
     qry_servxgpo->ParamByName("tipo")->AsInteger = SERVICIO_GRUPO;
     qry_servxgpo->Open();
     if(!qry_servxgpo->IsEmpty()) {
       servicio_z = qry_servxgpo->FieldByName("impservicio")->AsFloat * 100;
     }
   } else {
     servicio_z = qry_servicio->FieldByName("impservicio")->AsFloat * 100;
   }
   return(servicio_z);
}
//---------------------------------------------------------------------------


void __fastcall TForm_polcampre::captura_observsExecute(TObject *Sender)
{
  CapturaObservaPedido(this, tipopol_z, "", 0, cia_z, "", "T");
}
//---------------------------------------------------------------------------

String __fastcall TForm_polcampre::busca_descrilin(String linea_z)
{
  String descrilin_z = "";
  qry_linea->Close();
  qry_linea->ParamByName("linea")->AsString = linea_z;
  qry_linea->ParamByName("cia")->AsInteger = cia_z;
  qry_linea->Open();
  if(!qry_linea->IsEmpty()) { descrilin_z = qry_linea->FieldByName("descri")->AsString; }
  return (descrilin_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::abrir_polizaExecute(TObject *Sender)
{
  int result_z;
  String permis_z = "N";
  if(qry_polcampre->State == dsInactive) return;
  if(qry_polcampre->FieldByName("status")->AsInteger == EDO_CERRADO) {
    Application->MessageBox("No puedes Abrir pólizas aplicadas", "Póliza Cerrada", MB_ICONEXCLAMATION);
    return;
  }
  if( qry_polcampre->FieldByName("status")->AsInteger == INV_STATUS_CAMBIO_PRECIO_CREADO) {
    Application->MessageBox("Esta pólizas no esta cerrada por aplicar", "Póliza Abierta", MB_ICONEXCLAMATION);
    return;
  }

  result_z = Application->MessageBox("Desea abrir esta póliza", "Abrir Póliza", MB_ICONQUESTION + MB_YESNO);
  if( result_z != IDYES) return;
  qry_polcampre->Edit();
  qry_polcampre->FieldByName("status")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CREADO;
  qry_polcampre->Post();
  try {
     dm->manvehi->StartTransaction();
     qry_polcampre->ApplyUpdates();
     dm->manvehi->Commit();
  } catch (Exception &E)
  {
     dm->manvehi->Rollback();
     dm->MensajeError("No pude grabar los datos:\n"+E.Message, "ERROR");
  }
  busca_polcampre(qry_polcampre->FieldByName("folio")->AsInteger);
}
//---------------------------------------------------------------------------


void __fastcall TForm_polcampre::modificaExecute(TObject *Sender)
{
  int result_z;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisión Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if(qry_polcampre->State == dsInactive) return;
  result_z = qry_polcampre->FieldByName("status")->AsInteger;
  if(qry_polcampre->FieldByName("status")->AsInteger == EDO_CERRADO) {
    Application->MessageBox("No puedes Modificar pólizas aplicadas", "Póliza Cerrada", MB_ICONEXCLAMATION);
    return;
  }
  agregar_modificar(MODIF);
}
//---------------------------------------------------------------------------

void __fastcall TForm_polcampre::duplica_polizaExecute(TObject *Sender)
{
  TQuery *qry_nvapol = new TQuery (this);
  TQuery *qry_nvorenpol = new TQuery (this);
  int ancho_z, alto_z, antidrenpol_z=0, idrenpol_z=0, idart_z=0, folioact_z=0,
    idpol_z=0, conse_z, antidempaq_z, idnvoempaq_z, idobservs_z, idrelinv_z,
    resultado_z = 0, folioant_z = 0, left_z = 0, cuantos_z = 0, faltan_z = 0;
  TDateTime fechapol_z, fecvig_z;
  bool cierra_z = false;
  double antprmds_z=0, antprelec_z=0, precmds_z=0, precelec_z=0, precioext_z,
  costoext_z;
  String codigo_z, nvasit_z, observs_z, obscam_z, antsit_z,
    titulo_z, descri_z, garantia_z, strcuantos_z;
  if(qry_polcampre->State == dsInactive) return;
  if(qry_polcampre->IsEmpty() ) return;
  if(qry_polcampre->FieldByName("status")->AsInteger == INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICADO) {
    Application->MessageBox("No puedes agregar renglones a pólizas cerradas", "Póliza Cerrada", MB_ICONEXCLAMATION);
    return;
  }
  Tdlg_okcancel *Dlg_analipol;
  Dlg_analipol = new Tdlg_okcancel (this);
  Dlg_analipol->AutoSize = false;

  TLabel *lbl_folio = new TLabel (Dlg_analipol);
  TLabel *lbl_instrucc = new TLabel (Dlg_analipol);
  TdxCurrencyEdit *edt_folioant = new TdxCurrencyEdit (Dlg_analipol);
  folioact_z = qry_polcampre->FieldByName("folio")->AsInteger;

  lbl_instrucc->Parent = Dlg_analipol->Panel1;
  lbl_instrucc->Width = Dlg_analipol->Panel1->Width;
  lbl_instrucc->Top = 10;
  lbl_instrucc->Left = 10;
  lbl_instrucc->Caption = "Esta opción va a importar en la póliza " + IntToStr(folioact_z) +" los renglones de la póliza que ud teclee";
  lbl_instrucc->Color = clLime;
  lbl_folio->Parent = Dlg_analipol->Panel1;
  edt_folioant->Parent = Dlg_analipol->Panel1;
  lbl_folio->Caption = "Folio a Replicar";
  lbl_folio->Top = lbl_instrucc->Top + lbl_instrucc->Height + 10;
  lbl_folio->Left = 10;
  folioant_z = folioact_z - 1;
  edt_folioant->Value = folioant_z;
  edt_folioant->Top = lbl_folio->Top -2;
  edt_folioant->Left =  lbl_folio->Left +  lbl_folio->Width + 2;
  titulo_z = "Duplicación de una Póliza Anterior";
  idpol_z = qry_polcampre->FieldByName("idpolcampre")->AsInteger;
  edt_folioant->Value = qry_polcampre->FieldByName("folio")->AsInteger -1 ;
  edt_folioant->DisplayFormat = "0";
  edt_folioant->DecimalPlaces = 0;


  qry_nvapol->DatabaseName = qry_renpolcampre->DatabaseName;
  qry_nvapol->SQL->Text = qry_polcampre->SQL->Text;

  qry_nvorenpol->DatabaseName = qry_renpolcampre->DatabaseName;
  qry_nvorenpol->SQL->Text = qry_renpolcampre->SQL->Text;
  Dlg_analipol->Caption = titulo_z;
  while (!cierra_z) {
    resultado_z = Dlg_analipol->ShowModal();
    cierra_z = true;
    if(resultado_z == mrOk) {
      folioant_z = edt_folioant->Value;
      qry_nvapol->Close();
      qry_nvapol->ParamByName("folio")->AsInteger = folioant_z;
      qry_nvapol->ParamByName("cia")->AsInteger = cia_z;
      qry_nvapol->ParamByName("tipo")->AsString = tipopol_z;
      qry_nvapol->Open();
      if(qry_nvapol->IsEmpty() || folioant_z == folioact_z) {
        if(folioant_z == folioact_z) titulo_z = "No puede duplicar la misma póliza " + IntToStr(folioact_z);
        if (qry_nvapol->IsEmpty()) titulo_z = "Debe teclear una póliza que ya ha sido creada";
        Application->MessageBox(titulo_z.c_str(), "Error", MB_ICONERROR);
        cierra_z = false;
      } else {

        cierra_z = true;
        antidrenpol_z = qry_nvapol->FieldByName("idpolcampre")->AsInteger;
        qry_nvorenpol->Close();
        qry_nvorenpol->ParamByName("idpolcampre")->AsInteger = antidrenpol_z;
        qry_nvorenpol->Open();
        if(tipopol_z == "P") {
          idrenpol_z = dm->busca_sigid(IDRENPOLCAMPRE);
        } else  {
          idrenpol_z = dm->busca_sigid(IDRENPOLOFERTAS);
        }
        cuantos_z = qry_nvorenpol->RecordCount;
        faltan_z = cuantos_z;

        for(qry_nvorenpol->First(); !qry_nvorenpol->Eof; qry_nvorenpol->Next()){
          strcuantos_z = IntToStr(faltan_z);

          qry_renpolcampre->Append();
          qry_renpolcampre->FieldByName("IDRENPOLCAMPRE")->AsInteger = idrenpol_z;
          qry_renpolcampre->FieldByName("idPOLCAMPRE")->AsInteger = idpol_z;
          qry_renpolcampre->FieldByName("idart")->AsInteger    = qry_nvorenpol->FieldByName("idart")->AsInteger;
          qry_renpolcampre->FieldByName("codigo")->AsString = qry_nvorenpol->FieldByName("codigo")->AsString;
          qry_renpolcampre->FieldByName("descri")->AsString = qry_nvorenpol->FieldByName("descri")->AsString;
          qry_renpolcampre->FieldByName("descrigtia")->AsString = qry_nvorenpol->FieldByName("descrigtia")->AsString;
          qry_renpolcampre->FieldByName("concep")->AsString = qry_nvorenpol->FieldByName("concep")->AsString;
          qry_renpolcampre->FieldByName("antprmds")->AsFloat   = qry_nvorenpol->FieldByName("antprmds")->AsFloat;
          qry_renpolcampre->FieldByName("antprelec")->AsFloat  = qry_nvorenpol->FieldByName("antprelec")->AsFloat;
          qry_renpolcampre->FieldByName("precmds")->AsFloat    = qry_nvorenpol->FieldByName("precmds")->AsFloat;
          qry_renpolcampre->FieldByName("precelec")->AsFloat    = qry_nvorenpol->FieldByName("precelec")->AsFloat;
          qry_renpolcampre->FieldByName("antempaq")->AsInteger = qry_nvorenpol->FieldByName("antempaq")->AsInteger;
          qry_renpolcampre->FieldByName("nvoempaq")->AsInteger = qry_nvorenpol->FieldByName("nvoempaq")->AsInteger;
          qry_renpolcampre->FieldByName("idobserv")->AsInteger = qry_nvorenpol->FieldByName("idobserv")->AsInteger;
          qry_renpolcampre->FieldByName("precioext")->AsFloat  = qry_nvorenpol->FieldByName("precioext")->AsFloat;
          qry_renpolcampre->FieldByName("costoext")->AsFloat   = qry_nvorenpol->FieldByName("costoext")->AsFloat;
          qry_renpolcampre->FieldByName("idgarantia")->AsInteger = qry_nvorenpol->FieldByName("idgarantia")->AsInteger;
          qry_renpolcampre->FieldByName("antersit")->AsString = qry_nvorenpol->FieldByName("antersit")->AsString;
          qry_renpolcampre->FieldByName("nuevasit")->AsString = qry_nvorenpol->FieldByName("nuevasit")->AsString;
          qry_renpolcampre->Post();
          idrenpol_z++;
          faltan_z--;
        }
        try {
          dm->manvehi->StartTransaction();
          qry_renpolcampre->ApplyUpdates();
          dm->manvehi->Commit();
        } catch (Exception &E) {
          dm->manvehi->Rollback();
          Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
        }
      }
    }
  }
  delete qry_nvorenpol;
  delete qry_nvapol;
  delete Dlg_analipol;

}
//---------------------------------------------------------------------------



void __fastcall TForm_polcampre::borraExecute(TObject *Sender)
{
  int ancho_z, alto_z, antidrenpol_z=0, idrenpol_z=0, idart_z=0, folioact_z=0,
    idpol_z=0, conse_z, antidempaq_z, idnvoempaq_z, idobservs_z, idrelinv_z,
    resultado_z = 0, folioant_z = 0, left_z = 0, cuantos_z = 0, faltan_z = 0;
  TDateTime fechapol_z, fecvig_z;
  bool cierra_z = false;
  double antprmds_z=0, antprelec_z=0, precmds_z=0, precelec_z=0, precioext_z,
  costoext_z;
  String codigo_z, nvasit_z, observs_z, obscam_z, antsit_z,
    titulo_z, descri_z, garantia_z, strcuantos_z;
  if(qry_polcampre->State == dsInactive) return;
  if(qry_polcampre->IsEmpty() ) return;
  if(qry_polcampre->FieldByName("status")->AsInteger == INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICADO) {
    Application->MessageBox("No puedes agregar renglones a pólizas cerradas", "Póliza Cerrada", MB_ICONEXCLAMATION);
    return;
  }
  resultado_z = Application->MessageBox("Seguro Desea Borrar esta póliza", "Borrar Póliza", MB_ICONQUESTION + MB_YESNO);
  if( resultado_z != IDYES) return;
  qry_polcampre->Edit();
  qry_polcampre->FieldByName("status")->AsInteger = INV_STATUS_CAMBIO_PRECIO_CERRADO_X_APLICAR;
  qry_polcampre->Post();
  for(qry_renpolcampre->First(); !qry_renpolcampre->Eof; qry_renpolcampre->First()){
      qry_renpolcampre->Delete();
  }
  qry_polcampre->Delete();

  try {
     dm->manvehi->StartTransaction();
     qry_polcampre->ApplyUpdates();
     if(qry_renpolcampre->UpdatesPending) qry_renpolcampre->ApplyUpdates();
     dm->manvehi->Commit();
     SigteSabana(ULTIMO);
  } catch (Exception &E)
  {
     dm->manvehi->Rollback();
     dm->MensajeError("No pude grabar los datos:\n"+E.Message, "ERROR");
  }


}
//---------------------------------------------------------------------------

