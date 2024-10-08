//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Frm_mantservi.h"
#include "dmod.h"
#include "Frame_zonas.h"
#include "Frme_datosrensmay.h"
#include "dialg_okcancel.h"
#include "numapal.h"
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
TForm_mantservi *Form_mantservi;

__fastcall TForm_mantservi::TForm_mantservi(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::borraExecute(TObject *Sender)
{
  String tit_z, tit1_z, tit2_z;
  if(permis_z != "B" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if (pagina_z == SERVICIO_ARTICULO) {
     tit_z = "Servicio";
     if(qry_servicio->IsEmpty()) return;
  }
  if (pagina_z == SERVICIO_GRUPO ) {
     tit_z = "Servicio";
     if(qry_servxgpo->IsEmpty()) return;
  }
  if (pagina_z == GRUPO_SERIE_AUMENTADA ) {
     tit_z = "Grupo con Serie Aumentada";
     if(qry_servxgpo->IsEmpty()) return;
  }
   if (pagina_z == PAGINA_COLORES) {
     tit_z += "Color";
   }

  tit1_z = "Esta Seguro de Eliminar este " + tit_z;
  tit2_z = "Eliminar " + tit_z;

  if(Application->MessageBox(tit1_z.c_str(), tit2_z.c_str(), MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      if (pagina_z == SERVICIO_ARTICULO) {
        qry_servicio->Delete();
        qry_servicio->ApplyUpdates();
      }
      if (pagina_z == SERVICIO_GRUPO ) {
        qry_servxgpo->Delete();
        qry_servxgpo->ApplyUpdates();
      }
      if (pagina_z == GRUPO_SERIE_AUMENTADA ) {
        qry_gruposserieaum->Delete();
        qry_gruposserieaum->ApplyUpdates();
      }
      if (pagina_z == PAGINA_COLORES) {
        qry_colores->Delete();
        qry_colores->ApplyUpdates();
      }
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantservi::modificaExecute(TObject *Sender)
{
  if(permis_z != "M" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede Modificar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  if (pagina_z == SERVICIO_ARTICULO) {
     if(qry_servicio->IsEmpty()) return;
  }
  if (pagina_z == SERVICIO_GRUPO ) {
     if(qry_servxgpo->IsEmpty()) return;
  }
  if (pagina_z == GRUPO_SERIE_AUMENTADA ) {
     if (qry_gruposserieaum->IsEmpty()) return;
  }
  alta_ptvt(MODIF);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::desp_ptvt()
{
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantservi::nuevoExecute(TObject *Sender)
{
  if(permis_z != "A" && permis_z != "T") {
    Application->MessageBox("Lo siento, no puede agregar datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    return;
  }
  alta_ptvt(NUEVO);

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::primeroExecute(TObject *Sender)
{
   //mueve_hacia("select min (zona) as zona from zonasmve where cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::anteriorExecute(TObject *Sender)
{
   //mueve_hacia("select max (zona) as zona from zonasmve where zona < "+edt_ptovta->Text+" and cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::siguienteExecute(TObject *Sender)
{
    //mueve_hacia("select min (zona) as zona from zonasmve where zona > "+edt_ptovta->Text+" and cia="+IntToStr(cia_z));
}
//---------------------------------------------------------------------------
void __fastcall TForm_mantservi::ultimoExecute(TObject *Sender)
{
   //mueve_hacia("select max (zona) as zona from zonasmve where cia="+IntToStr(cia_z));
}
//-------------------------------------------------------------------------

void __fastcall TForm_mantservi::alta_ptvt(int modo_z)
{
   String codigo_z, descri_z, linea_z, tit_z;
   int idart_z;
   if (pagina_z == PAGINA_COLORES) {
     alta_colores(modo_z);
     return;
   }

   Tdlg_okcancel* Dlg_datos;
   Dlg_datos = new Tdlg_okcancel (this);
   TLabel *lbl_codigo = new TLabel (Dlg_datos);
   lbl_codigo->Parent = Dlg_datos->Panel1;
   lbl_codigo->Top   = 10;
   lbl_codigo->Left  = 20;
   lbl_codigo->Caption = "C�digo";

   TDBLookupComboBox *lkcmb_codigo = new TDBLookupComboBox (Dlg_datos);
   lkcmb_codigo->Parent = Dlg_datos->Panel1;
   lkcmb_codigo->Top   = 10;
   lkcmb_codigo->Left  = lbl_codigo->Left + 4 + lbl_codigo->Width;
   lkcmb_codigo->Width = 100;
   lkcmb_codigo->ListField = "codigo";
   lkcmb_codigo->KeyField  = "codigo";

   TDBEdit *dbedt_descri = new TDBEdit (Dlg_datos);
   dbedt_descri->Parent = Dlg_datos->Panel1;
   dbedt_descri->Top   = 10;
   dbedt_descri->Left  = lkcmb_codigo->Left + 4 + lkcmb_codigo->Width;
   dbedt_descri->Width = 300;
   dbedt_descri->DataField = "descri";
   dbedt_descri->TabStop = false;

   TLabel *lbl_servicio = new TLabel (Dlg_datos);
   lbl_servicio->Parent = Dlg_datos->Panel1;
   lbl_servicio->Top   = dbedt_descri->Top + 4 + dbedt_descri->Height;
   lbl_servicio->Left  = 10;
   lbl_servicio->Caption = "Servicio";

   TdxCurrencyEdit *edt_servicio = new TdxCurrencyEdit (Dlg_datos);
   edt_servicio->Parent = Dlg_datos->Panel1;
   edt_servicio->Top   = lbl_servicio->Top;
   edt_servicio->Left  = lkcmb_codigo->Left;
   edt_servicio->Width = 100;
   edt_servicio->DisplayFormat = "$,0.00;-$,0.00";
   edt_servicio->DecimalPlaces = 2;
   if (pagina_z == SERVICIO_ARTICULO) {
     tit_z += "Importe del Servicio del Articulo";
   }
   if (pagina_z == SERVICIO_GRUPO ) {
     tit_z += "Importe del Servicio del Grupo";
   }
   if (pagina_z == GRUPO_SERIE_AUMENTADA ) {
     tit_z += "Grupo con Serie Aumentada";
     edt_servicio->Visible = false;
     lbl_servicio->Visible = false;
   }

   Dlg_datos->Caption = "Datos del " + tit_z;
   if(modo_z == MODIF ) {
     if(pagina_z == SERVICIO_ARTICULO) {
       codigo_z = qry_servicio->FieldByName("codigo")->AsString;
       edt_servicio->Value = qry_servicio->FieldByName("impservicio")->AsFloat;
       lkcmb_codigo->ListSource = dts_invhist;
       lkcmb_codigo->KeyValue = codigo_z;
       dbedt_descri->DataSource = dts_invhist;
       dbedt_descri->DataField = "descri";
     }
     if(pagina_z == SERVICIO_GRUPO ) {
       codigo_z = qry_servxgpo->FieldByName("codigo")->AsString;
       idart_z = qry_servxgpo->FieldByName("idart")->AsInteger;
       edt_servicio->Value = qry_servxgpo->FieldByName("impservicio")->AsFloat;
       lkcmb_codigo->ListSource = dts_servxgpo;
       lkcmb_codigo->KeyValue = codigo_z;
       dbedt_descri->DataSource = dts_servxgpo;
       dbedt_descri->DataField = "descri";
     }
     if(pagina_z == GRUPO_SERIE_AUMENTADA ) {
       codigo_z = qry_gruposserieaum->FieldByName("codigo")->AsString;
       idart_z = qry_gruposserieaum->FieldByName("idart")->AsInteger;
       //edt_servicio->Value = qry_servxgpo->FieldByName("impservicio")->AsFloat;
       lkcmb_codigo->ListSource = dts_servxgpo;
       lkcmb_codigo->KeyValue = codigo_z;
       dbedt_descri->DataSource = dts_servxgpo;
       dbedt_descri->DataField = "descri";
     }
   }
   if(modo_z == NUEVO ) {
     if(pagina_z == SERVICIO_ARTICULO) {
       lkcmb_codigo->ListSource = dts_invhist;
       lkcmb_codigo->KeyValue = codigo_z;
       dbedt_descri->DataSource = dts_invhist;
       dbedt_descri->DataField = "descri";
     }
     if(pagina_z == SERVICIO_GRUPO ) {
       lkcmb_codigo->ListSource = dts_grupos;
       lkcmb_codigo->KeyValue = codigo_z;
       lkcmb_codigo->ListField = "codigo";
       dbedt_descri->DataSource = dts_grupos;
       dbedt_descri->DataField = "descri";
     }
     if(pagina_z == GRUPO_SERIE_AUMENTADA ) {
       lkcmb_codigo->ListSource = dts_grupos;
       lkcmb_codigo->KeyValue = codigo_z;
       lkcmb_codigo->ListField = "codigo";
       dbedt_descri->DataSource = dts_grupos;
       dbedt_descri->DataField = "descri";
     }
   }

   if(Dlg_datos->ShowModal() == mrOk) {
     try {
       dm->manvehi->StartTransaction();
       if(pagina_z == SERVICIO_ARTICULO) {
         codigo_z = qry_invhist->FieldByName("codigo")->AsString;
         descri_z = qry_invhist->FieldByName("descri")->AsString;
         linea_z  = qry_invhist->FieldByName("linea")->AsString;
         idart_z  = qry_invhist->FieldByName("idart")->AsInteger;
       }
       if(pagina_z == SERVICIO_GRUPO ) {
         codigo_z = qry_grupos->FieldByName("codigo")->AsString;
         descri_z = qry_grupos->FieldByName("descri")->AsString;
         idart_z  = qry_grupos->FieldByName("idgrupo")->AsInteger;
       }
       if(pagina_z == GRUPO_SERIE_AUMENTADA ) {
         codigo_z = qry_grupos->FieldByName("codigo")->AsString;
         descri_z = qry_grupos->FieldByName("descri")->AsString;
         idart_z  = qry_grupos->FieldByName("idgrupo")->AsInteger;
       }

       if(pagina_z == SERVICIO_ARTICULO) {
         if(modo_z == NUEVO) {
             qry_servicio->Append();
             qry_servicio->FieldByName("idart")->AsInteger = idart_z;
             qry_servicio->FieldByName("codigo")->AsString = codigo_z;
             qry_servicio->FieldByName("linea")->AsString  = linea_z;
             qry_servicio->FieldByName("descri")->AsString = descri_z;
             qry_servicio->FieldByName("tipo")->AsInteger   = SERVICIO_ARTICULO;
             qry_servicio->FieldByName("cia")->AsInteger   = cia_z;
         } else {
           qry_servicio->Edit();
         }
         qry_servicio->FieldByName("impservicio")->AsFloat = edt_servicio->Value;
         qry_servicio->FieldByName("fecha")->AsDateTime    =  dm->ahora();
         qry_servicio->Post();
         qry_servicio->ApplyUpdates();
       }

       if(pagina_z == SERVICIO_GRUPO ) {
         if(modo_z == NUEVO) {
             qry_servxgpo->Append();
             qry_servxgpo->FieldByName("idart")->AsInteger = idart_z;
             qry_servxgpo->FieldByName("codigo")->AsString = codigo_z;
             qry_servxgpo->FieldByName("descri")->AsString = descri_z;
             qry_servxgpo->FieldByName("cia")->AsInteger   = cia_z;
             qry_servxgpo->FieldByName("tipo")->AsInteger  = SERVICIO_GRUPO;
         } else {
           qry_servxgpo->Edit();
         }
         qry_servxgpo->FieldByName("impservicio")->AsFloat = edt_servicio->Value;
         qry_servxgpo->FieldByName("fecha")->AsDateTime    =  dm->ahora();
         qry_servxgpo->Post();
         qry_servxgpo->ApplyUpdates();
       }

       if(pagina_z == GRUPO_SERIE_AUMENTADA ) {
         if(modo_z == NUEVO) {
             qry_gruposserieaum->Append();
             qry_gruposserieaum->FieldByName("idart")->AsInteger = idart_z;
             qry_gruposserieaum->FieldByName("codigo")->AsString = codigo_z;
             qry_gruposserieaum->FieldByName("descri")->AsString = descri_z;
             qry_gruposserieaum->FieldByName("cia")->AsInteger   = cia_z;
             qry_gruposserieaum->FieldByName("tipo")->AsInteger  = GRUPO_SERIE_AUMENTADA;
         } else {
           qry_gruposserieaum->Edit();
         }
         qry_gruposserieaum->FieldByName("impservicio")->AsFloat = edt_servicio->Value;
         qry_gruposserieaum->FieldByName("fecha")->AsDateTime    =  dm->ahora();
         qry_gruposserieaum->Post();
         qry_gruposserieaum->ApplyUpdates();
       }

       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }
   delete Dlg_datos;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::alta_colores(int modo_z)
{
   String codigo_z, descri_z, linea_z, tit_z;
   int idcolor_z;
   Tdlg_okcancel* Dlg_datos;
   Dlg_datos = new Tdlg_okcancel (this);
   TLabel *lbl_codigo = new TLabel (Dlg_datos);
   lbl_codigo->Parent = Dlg_datos->Panel1;
   lbl_codigo->Top   = 10;
   lbl_codigo->Left  = 20;
   lbl_codigo->Caption = "C�digo";

   TEdit *edt_codigo = new TEdit (Dlg_datos);
   edt_codigo->Parent = Dlg_datos->Panel1;
   edt_codigo->Top   = 10;
   edt_codigo->Left  = lbl_codigo->Left + 4 + lbl_codigo->Width;
   edt_codigo->Width = 50;
   edt_codigo->MaxLength = 2;
   edt_codigo->CharCase = ecUpperCase;

   TEdit *dbedt_descri = new TEdit (Dlg_datos);
   dbedt_descri->Parent = Dlg_datos->Panel1;
   dbedt_descri->Top   = 10;
   dbedt_descri->Left  = edt_codigo->Left + 4 + edt_codigo->Width;
   dbedt_descri->Width = 300;
   dbedt_descri->MaxLength = 50;
   dbedt_descri->CharCase = ecUpperCase;

   if (pagina_z == PAGINA_COLORES) {
     tit_z += "Color";
   }

   Dlg_datos->Caption = "Datos del " + tit_z;
   if(modo_z == MODIF ) {
     if(pagina_z == PAGINA_COLORES) {
       codigo_z = qry_colores->FieldByName("codigo")->AsString;
       descri_z = qry_colores->FieldByName("descri")->AsString;
       edt_codigo->Text = codigo_z;
       dbedt_descri->Text = descri_z;
     }
   }

   if(Dlg_datos->ShowModal() == mrOk) {
     try {
       dm->manvehi->StartTransaction();
       if(pagina_z == PAGINA_COLORES) {
         codigo_z = edt_codigo->Text.Trim();
         descri_z = dbedt_descri->Text.Trim();
         if(modo_z == NUEVO) {
             idcolor_z = busca_idcolor();
             qry_colores->Append();
             qry_colores->FieldByName("idcolor")->AsInteger = idcolor_z;
             qry_colores->FieldByName("codigo")->AsString = codigo_z;
             qry_colores->FieldByName("status")->AsString = "A";
             qry_colores->FieldByName("cia")->AsInteger   = cia_z;
         } else {
           qry_colores->Edit();
         }
         qry_colores->FieldByName("descri")->AsString = descri_z;
         qry_colores->Post();
         qry_colores->ApplyUpdates();
       }

       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }
   }
   delete Dlg_datos;
}
//---------------------------------------------------------------------------

int __fastcall TForm_mantservi::busca_idcolor()
{
  String sql_z;
  int idcolor_z = 0;
  sql_z = "select max(idcolor) as idcolor from inv_colores where idcolor > 0";
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Clear();
  dm->qry_maxidvnd->SQL->Add(sql_z);
  dm->qry_maxidvnd->Open();
  idcolor_z = dm->qry_maxidvnd->FieldByName("idcolor")->AsInteger;
  idcolor_z = idcolor_z +1;
  return(idcolor_z);

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::modif_ptvt()
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::botones_onoff(int modo_z)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::mueve_hacia(String sql_z)
{
}
//---------------------------------------------------------------------------

int __fastcall TForm_mantservi::busca_idart(String codigo_z)
{
   int idart_z = -1;
   qry_invhist->Close();
   qry_invhist->ParamByName("codigo")->AsString = codigo_z;
   qry_invhist->ParamByName("cia")->AsInteger = cia_z;
   qry_invhist->Open();
   if(!qry_invhist->IsEmpty()) idart_z = qry_invhist->FieldByName("idart")->AsInteger;
   return(idart_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::FormCreate(TObject *Sender)
{
  permis_z="N";
  permis_z=dm->busca_permision(MANTOZONAS);
  cia_z = dm->cia_z;
  if(permis_z == "N") {
    Application->MessageBox("Lo siento, no puede accesar estos datos", "Permisi�n Incorrecta", MB_ICONEXCLAMATION);
    Close();
  }
  pagina_z = SERVICIO_ARTICULO;
  pge_servicios->ActivePage = tbs_productos;
  qry_servicio->Close();
  qry_servicio->ParamByName("cia")->AsInteger = cia_z;
  qry_servicio->ParamByName("tipo")->AsInteger = SERVICIO_ARTICULO;
  qry_servicio->Open();
  qry_servxgpo->Close();
  qry_servxgpo->ParamByName("cia")->AsInteger = cia_z;
  qry_servxgpo->ParamByName("tipo")->AsInteger = SERVICIO_GRUPO;
  qry_servxgpo->Open();
  qry_gruposserieaum->Close();
  qry_gruposserieaum->ParamByName("cia")->AsInteger = cia_z;
  qry_gruposserieaum->ParamByName("tipo")->AsInteger = GRUPO_SERIE_AUMENTADA;
  qry_gruposserieaum->Open();
  qry_invhist->Close();
  qry_invhist->ParamByName("cia")->AsInteger = cia_z;
  qry_invhist->Open();
  qry_grupos->Close();
  qry_grupos->ParamByName("cia")->AsInteger = cia_z;
  qry_grupos->Open();
  qry_colores->Close();
  qry_colores->ParamByName("cia")->AsInteger = cia_z;
  qry_colores->Open();
  dbgrd_servicios->FullExpand();

}
//---------------------------------------------------------------------------
void __fastcall TForm_mantservi::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action=caFree;
}
//---------------------------------------------------------------------------



void __fastcall TForm_mantservi::exportarExecute(TObject *Sender)
{
  TSaveDialog *SaveDialog = new TSaveDialog (this);
  SaveDialog->Filter = "Archivos de Texto (*.txt)|*.TXT|Archivos de Excel(*.xls)|*.XLS|Archivos HTML (*.html)|*.HTML";
  SaveDialog->DefaultExt = "Archivos de Excel";
  SaveDialog->FileName = dbgrd_servicios->Name + ".xls";
  SaveDialog->FilterIndex = 2;
  if (SaveDialog->Execute()) {
    switch( SaveDialog->FilterIndex) {
      case 1: dbgrd_servicios->SaveToText(SaveDialog->FileName, true, "\t", "", ""); break;
      case 2: dbgrd_servicios->SaveToXLS(SaveDialog->FileName, true); break;
      case 3: dbgrd_servicios->SaveToHTML(SaveDialog->FileName, true); break;
    }
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::tbs_zonasShow(TObject *Sender)
{
  tipo_z = "ZONAS";
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::tbs_megazonasShow(TObject *Sender)
{
  tipo_z = "MEGAZONAS";
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::imprimir_reporteExecute(TObject *Sender)
{
  genera_reporte();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::genera_reporte()
{
  String arch_z = Name+".txt", serie_z="", descri2_z, tipo_z,
    gpoartdesp_z, gpodiary_z, titulo_z, mensaje_z, titmsg_z,
    prove_z="", codigo_z="", alm_z="", antcod_z = "-1",
    linea_z = "-1";
  titulo_z = "Listado de Servicios";
  mensaje_z = "Desea imprimir " + titulo_z;
  titmsg_z = "Impresi�n de " + titulo_z;
  if(Application->MessageBox(mensaje_z.c_str(), titmsg_z.c_str(), MB_ICONQUESTION+MB_YESNO) != mrYes) return;
  if( (archout = fopen(arch_z.c_str(), "wt")) == NULL) {
    Application->MessageBox("No puedo abrir el archivo textual de salida", "Error", MB_ICONQUESTION);
    return;
  }
  qry_servicio->Close();
  qry_servicio->ParamByName("cia")->AsInteger = cia_z;
  qry_servicio->Open();
  antlin_z = "-1";
  subenc_z = "POR_ARTICULO";
  pagina_z = 1;
  for (qry_servicio->First(); !qry_servicio->Eof; qry_servicio->Next()) {
    if(antlin_z == "-1") {
       antlin_z = qry_servicio->FieldByName("linea")->AsString;
       pagina_z = 1; report_encab();
    }
    linea_z = qry_servicio->FieldByName("linea")->AsString;
    if (antlin_z != linea_z) {
       antlin_z = linea_z;
       report_subenc();
    }
    impri_ren();
  }
  subenc_z = "POR_GRUPO";
  prepara_query_articulos_x_grupo();
  if(antlin_z == "-1") {
     antlin_z = "0";
     report_encab();
  } else {
     salta_linea();
     fprintf(archout, " Listado de Servicios Por Grupo");
     salta_linea();
     report_subenc();
  }
  for (qry_servxgpo->First(); !qry_servxgpo->Eof; qry_servxgpo->Next()) {
    impri_ren();
  }
  fclose(archout);
  dm->manda_impresion(arch_z);
  dbgrd_servicios->FullExpand();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::prepara_query_articulos_x_grupo()
{
  String sql_z;
  sql_z = "select d.codigo as grupo, e.codigo, e.descri \
    from inv_invhist a \
    join inv_relinv b on a.idart = b.idart and b.idrel = :REL_GRUPO \
    join inv_grupos d on b.iddato = d.idgrupo \
    join inv_servicios c on d.idgrupo = c.idart \
    join inven e on a.codigo = e.codigo and a.cia = e.cia \
    where d.codigo = :GRUPO and a.cia = :CIA and c.tipo = :TIPO \
    order by a.codigo";
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->SQL->Clear();
  dm->qry_maxidvnd->SQL->Add(sql_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::salta_linea()
{
  fprintf(archout, "\n");
  lineas_z++;
  if(lineas_z > LIN_X_PAG) {
    fprintf(archout, "%c", 12); pagina_z++; report_encab();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::report_encab()
{
  lineas_z = 0;
  fprintf(archout, "%s%s%s", dm->font_impre(dm->impre_z, PICA_PITCH),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 80)
  );
  salta_linea();
  fprintf(archout, "%s%s%s%s Pag:%d", dm->font_impre(dm->impre_z, CONDENSADO_ON),
    FormatDateTime("dd-mm-yyyy hh:mm", Now()),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 64), pagina_z
  );
  salta_linea();
  fprintf(archout, "Impresion de Listado de Importe Servicios");
  if (subenc_z == "POR_ARTICULO") {
    fprintf(archout, " Por Articulo");
  } else {
    fprintf(archout, " Por Grupo");
  }
  salta_linea();
  report_subenc();
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::report_subenc()
{
  String descrilin_z;
  if (subenc_z == "POR_ARTICULO") {
    descrilin_z = qry_servicio->FieldByName("descrilin")->AsString;
    fprintf(archout, "Linea: %s %s", antlin_z, descrilin_z);
    salta_linea();
  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
  fprintf(archout, "%s|", ljust("Codigo", 13) );
  fprintf(archout, "%s|", ljust("Descripcion", 30) );
  fprintf(archout, "%s|", rjust("Servicio", 12) );
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
  salta_linea();

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::impri_ren()
{
  if (subenc_z == "POR_ARTICULO") {
    fprintf(archout, "%s|", ljust(qry_servicio->FieldByName("Codigo")->AsString, 13 ) );
    fprintf(archout, "%s|", ljust(qry_servicio->FieldByName("descri")->AsString, 30 ) );
    fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",  qry_servicio->FieldByName("impservicio")->AsFloat), 12) );
    salta_linea();
  } else {
    fprintf(archout, "%s|", ljust(qry_servxgpo->FieldByName("Codigo")->AsString, 13 ) );
    fprintf(archout, "%s|", ljust(qry_servxgpo->FieldByName("descri")->AsString, 30 ) );
    fprintf(archout, "%s|", rjust(FormatFloat("###,##0.00",  qry_servxgpo->FieldByName("impservicio")->AsFloat), 12) );
    salta_linea();
    genera_reporte_articulos_x_grupo();
    salta_linea();
  }

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::genera_reporte_articulos_x_grupo()
{
  String grupo_z;
  int salta_z=0;
  grupo_z = qry_servxgpo->FieldByName("Codigo")->AsString;
  dm->qry_maxidvnd->Close();
  dm->qry_maxidvnd->ParamByName("REL_GRUPO")->AsInteger = REL_INVEN_ARTDESP;
  dm->qry_maxidvnd->ParamByName("GRUPO")->AsString = grupo_z;
  dm->qry_maxidvnd->ParamByName("tipo")->AsInteger = SERVICIO_GRUPO;
  dm->qry_maxidvnd->ParamByName("cia")->AsInteger = cia_z;
  dm->qry_maxidvnd->Open();
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ELITE));
  for(dm->qry_maxidvnd->First(); !dm->qry_maxidvnd->Eof; dm->qry_maxidvnd->Next() ) {
    fprintf(archout, "%s ", ljust(dm->qry_maxidvnd->FieldByName("Codigo")->AsString, 13 ) );
    fprintf(archout, "%s|", ljust(dm->qry_maxidvnd->FieldByName("descri")->AsString, 30 ) );
    if(salta_z) { salta_linea(); salta_z = 0; } else { salta_z = 1; }

  }
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, PICA_PITCH));
  if(salta_z) salta_linea();
}
//---------------------------------------------------------------------------


void __fastcall TForm_mantservi::tbs_gruposShow(TObject *Sender)
{
  pagina_z = SERVICIO_GRUPO;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::tbs_productosShow(TObject *Sender)
{
  pagina_z = SERVICIO_ARTICULO;
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::dbgrd_serviciosKeyDown(TObject *Sender,
      WORD &Key, TShiftState Shift)
{
  if(Key == VK_INSERT) nuevoExecute(Sender);
  if(Key == VK_DELETE) borraExecute(Sender);
  if(Key == VK_F2)     modificaExecute(Sender);
}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::actualiza_preciosExecute(TObject *Sender)
{
   String sql_z, codigo_z, descri_z, linea_z, tit_z;
   int idart_z;
   double precioant_z=0, precionvo_z=0;
   Tdlg_okcancel* Dlg_datos;
   Dlg_datos = new Tdlg_okcancel (this);
   TLabel *lbl_precioant = new TLabel (Dlg_datos);
   lbl_precioant->Parent = Dlg_datos->Panel1;
   lbl_precioant->Top   = 10;
   lbl_precioant->Left  = 20;
   lbl_precioant->Caption = "Precio Anterior";

   TdxCurrencyEdit *edt_precioant = new TdxCurrencyEdit (Dlg_datos);
   edt_precioant->Parent = Dlg_datos->Panel1;
   edt_precioant->Top   = lbl_precioant->Top;
   edt_precioant->Left  = lbl_precioant->Left + lbl_precioant->Width + 4;
   edt_precioant->Width = 100;
   edt_precioant->DisplayFormat = "$,0.00;-$,0.00";
   edt_precioant->DecimalPlaces = 2;

   TLabel *lbl_precionvo = new TLabel (Dlg_datos);
   lbl_precionvo->Parent = Dlg_datos->Panel1;
   lbl_precionvo->Top   =  edt_precioant->Top + 4 + edt_precioant->Height;
   lbl_precionvo->Left  = 20;
   lbl_precionvo->Caption = "Precio Nuevo";

   TdxCurrencyEdit *edt_precionvo = new TdxCurrencyEdit (Dlg_datos);
   edt_precionvo->Parent = Dlg_datos->Panel1;
   edt_precionvo->Top   = lbl_precionvo->Top;
   edt_precionvo->Left  = edt_precioant->Left;
   edt_precionvo->Width = 100;
   edt_precionvo->DisplayFormat = "$,0.00;-$,0.00";
   edt_precionvo->DecimalPlaces = 2;

   tit_z = "Cambio de Importes de Servicio ";
   Dlg_datos->Caption = tit_z;
   if(Dlg_datos->ShowModal() == mrOk) {
     precioant_z = edt_precioant->Value;
     precionvo_z = edt_precionvo->Value;
     sql_z = "update inv_servicios set impservicio = :NVOIMPORTE ,\
       fecha = :FECHA \
       where impservicio = :ANTIMPORTE  and cia = :CIA";
     dm->manvehi->StartTransaction();
     dm->qry_maxidvnd->Close();
     dm->qry_maxidvnd->SQL->Clear();
     dm->qry_maxidvnd->SQL->Add(sql_z);
     dm->qry_maxidvnd->ParamByName("ANTIMPORTE")->AsFloat = precioant_z;
     dm->qry_maxidvnd->ParamByName("NVOIMPORTE")->AsFloat = precionvo_z;
     dm->qry_maxidvnd->ParamByName("fecha")->AsDateTime = dm->ahora();
     dm->qry_maxidvnd->ParamByName("cia")->AsInteger = cia_z;
     dm->qry_maxidvnd->ExecSQL();
     dm->manvehi->Commit();
     Application->MessageBox("Cambio de Precio", "Cambio de Precio Realizado", MB_ICONEXCLAMATION);
     qry_servicio->Close();
     qry_servicio->ParamByName("cia")->AsInteger = cia_z;
     qry_servicio->ParamByName("tipo")->AsInteger = SERVICIO_ARTICULO;
     qry_servicio->Open();
     qry_servxgpo->Close();
     qry_servxgpo->ParamByName("cia")->AsInteger = cia_z;
     qry_servxgpo->ParamByName("tipo")->AsInteger = SERVICIO_GRUPO;
     qry_servxgpo->Open();

   }
   delete  Dlg_datos;


}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::tbs_serieaumentadaShow(TObject *Sender)
{
  pagina_z = GRUPO_SERIE_AUMENTADA;

}
//---------------------------------------------------------------------------

void __fastcall TForm_mantservi::tbs_coloresShow(TObject *Sender)
{
  pagina_z = PAGINA_COLORES;
}
//---------------------------------------------------------------------------

