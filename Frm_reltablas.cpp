//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "Frm_reltablas.h"
#include "dialg_okcancel.h"
#include "Frme_datoscambio.h"
#include "Frme_datostabla.h"
#include "Frme_agregarelac.h"
#include "dialg_okcancel.h"
#include "imprigra.h"
#include "numapal.h"
#include "dmod.h"
#include "situaciones.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma link "dxCntner"
#pragma link "dxDBCtrl"
#pragma link "dxDBGrid"
#pragma link "dxDBTLCl"
#pragma link "dxGrClms"
#pragma link "dxTL"
#pragma resource "*.dfm"
TForm_reltablas *Form_reltablas;
const int MAX_LINEAS = 60;
//---------------------------------------------------------------------------
__fastcall TForm_reltablas::TForm_reltablas(TComponent* Owner)
        : TForm(Owner)
{

  qry_tablas->Close();
  qry_tablas->Tag = NO_REFRESH;
  qry_tablas->Open();
  qry_tablas->Tag = SI_REFRESH;
  qry_relacs->Close();
  qry_relacs->Open();


}
//---------------------------------------------------------------------------
 void __fastcall TForm_reltablas::report_encab()
{

  String situini_z,situfin_z,tit1_z,tit2_z;
  fprintf(archout, "%s%s%s\n", dm->font_impre(dm->impre_z, ELITE),
    dm->font_impre(dm->impre_z, CONDENSADO_OFF), cjust(dm->nemp_z, 90)
  );
  fprintf(archout, "%s%s%s%s Pag:%d\n", dm->font_impre(dm->impre_z, CONDENSADO_ON),
     "Frm_reltablas" + FormatDateTime("dd-mm-yyyy hh:nn", Now())+ " ",
    dm->font_impre(dm->impre_z, CONDENSADO_OFF),  cjust(dm->diremp_z, 60),pagina_z
  );

   tit2_z = "Relacion de Tablas -CAPYCON- ";
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
   fprintf(archout, "%s", cjust( tit2_z,50));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
   fprintf(archout, "%s", dm->font_impre(dm->impre_z, CONDENSADO_ON));
   lineas_z = 3;

}
//---------------------------------------------------------------------------
void __fastcall TForm_reltablas::encab1()
{

   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Num.",3 ));
   fprintf(archout, "%s|", cjust("Tabla",20));
   fprintf(archout, "%s|", cjust("Descripcion",60 ));
   fprintf(archout, "%s|", cjust("Fecha",10));
   fprintf(archout, "%s|", cjust("En USO",6));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;

}
//---------------------------------------------------------------------------
void __fastcall TForm_reltablas::encab_rel()
{

   fprintf(archout, "%s|", dm->font_impre(dm->impre_z, SUBRAYADO_ON));
   fprintf(archout, "%s|", cjust("Tabla",10));
   fprintf(archout, "%s|", cjust("Campo",10));
   fprintf(archout, "%s|", cjust("Tabla Rel.",10 ));
   fprintf(archout, "%s|", cjust("Campo Rel.",20));
   fprintf(archout, "%s|", cjust("Tipo Rel.",10));
   fprintf(archout, "%s|", cjust("Descripcion",40));
   fprintf(archout, "%s|", cjust("Observacion",40));
   fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, SUBRAYADO_OFF));
   lineas_z += 1;

}
//---------------------------------------------------------------------------

void __fastcall TForm_reltablas::nueva_tablaExecute(TObject *Sender)
{
   int idtabla_z;
   String  tabla_z, descri_z;
   TDateTime fecha_z;

   Tdlg_okcancel *Dlg_datosmantovnd;
   Dlg_datosmantovnd = new Tdlg_okcancel (this);
   TFrame_datoscambio *Frame_datoscambio;
   Frame_datoscambio = new TFrame_datoscambio (Dlg_datosmantovnd);
   Frame_datoscambio->Parent = Dlg_datosmantovnd->Panel1;
   Frame_datoscambio->AutoSize = false;
   Dlg_datosmantovnd->Width = Frame_datoscambio->Width + 20;
   Dlg_datosmantovnd->Height = Frame_datoscambio->Height + Dlg_datosmantovnd->Panel2->Height + 30;
   Frame_datoscambio->lbl_codigo->Caption = "Nombre";
   Frame_datoscambio->lbl_sentencia->Caption = "Descripci�n";
   Frame_datoscambio->lbl_fecha->Caption = "F.Creaci�n";
   Frame_datoscambio->date_fecha->Date = dm->ahora();
   Dlg_datosmantovnd->Caption = "Agregar Nueva Tabla";

   if( Dlg_datosmantovnd->ShowModal() == mrOk) {
      tabla_z = Frame_datoscambio->edt_codigo->Text;
      descri_z= Frame_datoscambio->edt_sentencia->Text;
      fecha_z = Frame_datoscambio->date_fecha->Date;
      qry_ultid->Close();
      qry_ultid->Open();
      if(!qry_ultid->IsEmpty()) idtabla_z = qry_ultid->FieldByName("ultid")->AsInteger;
      ++idtabla_z;
      qry_tablas->Append();
      qry_tablas->FieldByName("idtabla")->AsInteger = idtabla_z;
      qry_tablas->FieldByName("tabla")->AsString = tabla_z;
      qry_tablas->FieldByName("descri")->AsString = descri_z;
      qry_tablas->FieldByName("fecha_crea")->AsDateTime= fecha_z;
      qry_tablas->Post();
      try
      {
         dm->manvehi->StartTransaction();
         qry_tablas->ApplyUpdates();
         dm->manvehi->Commit();
      }
      catch(...)
      {
         dm->manvehi->Rollback();
         Application->MessageBox("No Fue Posible Agregar Esta Tabla", "Error", MB_OK | MB_ICONERROR);
      }

   }
   delete Frame_datoscambio;
   delete Dlg_datosmantovnd;
}
//---------------------------------------------------------------------------


void __fastcall TForm_reltablas::borrar_tablaExecute(TObject *Sender)
{

  if(qry_tablas->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Tabla ?", "Eliminar Tabla", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_tablas->Delete();
      qry_tablas->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E){
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude Eliminar el dato:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm_reltablas::rel_tablaExecute(TObject *Sender)
{

   String tabla_z,camporel_z,idtablarel_z,campo_z,tiporel_z,descrip_z,observ_z;
   int idtabla_z,max_z,selec_z,selecrel_z ;
   TDateTime fecini_z ;

   Tdlg_okcancel *Dlg_datostipocar;
   Dlg_datostipocar = new Tdlg_okcancel (this);
   TFrame_agregarelac  *Frame_agregarelac;
   Frame_agregarelac  = new TFrame_agregarelac  (Dlg_datostipocar);
   Frame_agregarelac ->Parent = Dlg_datostipocar->Panel1;
   Frame_agregarelac ->AutoSize = false;
   Dlg_datostipocar->AutoSize = false;
   Dlg_datostipocar->Width = Frame_agregarelac ->Width + 20;
   Dlg_datostipocar->Height = Frame_agregarelac ->Height + Dlg_datostipocar->Panel2->Height + 50;
   Dlg_datostipocar->Caption = "Agregar Relaci�n";

   tabla_z = qry_tablas->FieldByName("tabla")->AsString;
   idtabla_z = qry_tablas->FieldByName("idtabla")->AsInteger;

   for (int ii_z = 0; ii_z <= list_columnas->Items->Count - 1; ii_z++){
    Frame_agregarelac->ListBox1->Items->Add (list_columnas->Items->Strings[ii_z]);
   }

   Frame_agregarelac->lbl_tabla->Caption = tabla_z;
   qry_max->Close();
   qry_max->Open();
   max_z = qry_max->FieldByName("max")->AsInteger;
   max_z = max_z + 1;

   if( Dlg_datostipocar->ShowModal() == mrOk) {

     selec_z = Frame_agregarelac->ListBox1->ItemIndex;
     campo_z = Frame_agregarelac->ListBox1->Items->Strings[selec_z];
     idtablarel_z = Frame_agregarelac->edt_idrel->Text;
     selecrel_z = Frame_agregarelac->lista_colum->ItemIndex;
     camporel_z = Frame_agregarelac->lista_colum->Items->Strings[selecrel_z];
     tiporel_z =  Frame_agregarelac->edt_rela->Text;
     descrip_z =  Frame_agregarelac->edt_descrip->Text;
     observ_z =   Frame_agregarelac->edt_observ->Text;

     qry_relacs->Append();
     qry_relacs->FieldByName("idreltabla")->AsInteger = max_z;
     qry_relacs->FieldByName("idtabla")->AsInteger = idtabla_z;
     qry_relacs->FieldByName("campo")->AsString = campo_z;
     qry_relacs->FieldByName("idtablarel")->AsString = idtablarel_z;
     qry_relacs->FieldByName("camporel")->AsString = camporel_z;
     qry_relacs->FieldByName("tiporel")->AsString = tiporel_z;
     qry_relacs->FieldByName("descri")->AsString = descrip_z;
     qry_relacs->FieldByName("observs")->AsString = observ_z;
     qry_relacs->Post();

     try {
       dm->manvehi->StartTransaction();
       qry_relacs->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E)
     {
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }

   }

   delete Frame_agregarelac;
   delete Dlg_datostipocar;
   qry_relacs->Tag = SI_REFRESH;
}
//---------------------------------------------------------------------------


//---------------------------------------------------------------------------


void __fastcall TForm_reltablas::modif_relExecute(TObject *Sender)
{
   String tabla_z,campo_z,tiporel_z,descrip_z,obserel_z,idtablarel_z,
   columna_z,camporel2_z ,camporel_z;
   int idtabla_z,max_z,selec_z,selecrel_z;
   TDateTime fecini_z ;

 
   Tdlg_okcancel *Dlg_datostipocar;
   Dlg_datostipocar = new Tdlg_okcancel (this);
   TFrame_agregarelac  *Frame_agregarelac;
   Frame_agregarelac  = new TFrame_agregarelac  (Dlg_datostipocar);
   Frame_agregarelac ->Parent = Dlg_datostipocar->Panel1;
   Frame_agregarelac ->AutoSize = false;
   Dlg_datostipocar->Width = Frame_agregarelac ->Width + 20;
   Dlg_datostipocar->Height = Frame_agregarelac ->Height + Dlg_datostipocar->Panel2->Height + 50;
   Dlg_datostipocar->Caption = "Modificar Relaci�n";

   campo_z = qry_tablas->FieldByName("tabla")->AsString;
   idtablarel_z = qry_relacs->FieldByName("idtablarel")->AsInteger;
   camporel_z =  qry_relacs->FieldByName("camporel")->AsString;
   tiporel_z = qry_relacs->FieldByName("tiporel")->AsInteger;
   descrip_z = qry_relacs->FieldByName("descri")->AsString;
   obserel_z = qry_relacs->FieldByName("observs")->AsString;

   Frame_agregarelac->lbl_tabla->Caption = campo_z;
   Frame_agregarelac->edt_tablarel->Text = idtablarel_z;
   Frame_agregarelac->edt_rela->Text = tiporel_z;
   Frame_agregarelac->edt_descrip->Text = descrip_z;
   Frame_agregarelac->edt_observ->Text =  obserel_z;


   for(int ii_z = 0; ii_z < qry_columns->FieldCount; ii_z++) {
      columna_z = qry_columns->Fields->Fields[ii_z]->FieldName.UpperCase();
      Frame_agregarelac->ListBox1->Items->Add (columna_z);

   }

  
   if( Dlg_datostipocar->ShowModal() == mrOk) {
     selec_z = Frame_agregarelac->ListBox1->ItemIndex;
     campo_z = Frame_agregarelac->ListBox1->Items->Strings[selec_z];
     idtablarel_z = Frame_agregarelac->edt_idrel->Text;
     selecrel_z = Frame_agregarelac->lista_colum->ItemIndex;
     camporel2_z = Frame_agregarelac->lista_colum->Items->Strings[selecrel_z];
     tiporel_z =  Frame_agregarelac->edt_rela->Text;
     descrip_z =  Frame_agregarelac->edt_descrip->Text;
     obserel_z =   Frame_agregarelac->edt_observ->Text;

     qry_relacs->Edit();
     qry_relacs->FieldByName("campo")->AsString = campo_z;
     qry_relacs->FieldByName("idtablarel")->AsString = idtablarel_z;
     qry_relacs->FieldByName("camporel")->AsString = camporel2_z;
     qry_relacs->FieldByName("tiporel")->AsString = tiporel_z;
     qry_relacs->FieldByName("descri")->AsString = descrip_z;
     qry_relacs->FieldByName("observs")->AsString = obserel_z;
     qry_relacs->Post();

     try {
       dm->manvehi->StartTransaction();
       qry_relacs->ApplyUpdates();
       dm->manvehi->Commit();
     } catch (Exception &E){
       dm->manvehi->Rollback();
       Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
     }

   }

   delete Frame_agregarelac;
   delete Dlg_datostipocar;        
}
//---------------------------------------------------------------------------

void __fastcall TForm_reltablas::borrar_relExecute(TObject *Sender)
{

  if(qry_relacs->IsEmpty()) return;
  if(Application->MessageBox("Esta Seguro de Eliminar esta Relacion?", "Eliminar Tabla", MB_YESNO+MB_ICONQUESTION+MB_DEFBUTTON2) == IDYES) {
    try {
      dm->manvehi->StartTransaction();
      qry_relacs->Delete();
      qry_relacs->ApplyUpdates();
      dm->manvehi->Commit();
    } catch (Exception &E)
    {
      dm->manvehi->Rollback();
      Application->MessageBox(("No pude Eliminar el dato:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
    }
  }        
}
//---------------------------------------------------------------------------

void __fastcall TForm_reltablas::modif_tablaExecute(TObject *Sender)
{

   String tabla_z,idtablarel_z,campo_z,tiporel_z,descrip_z,obserel_z;
   TDateTime fecini_z ;

   Tdlg_okcancel *Dlg_datostipocar;
   Dlg_datostipocar = new Tdlg_okcancel (this);
   TFrame_datostabla  *Frame_datostabla;
   Frame_datostabla  = new TFrame_datostabla  (Dlg_datostipocar);
   Frame_datostabla ->Parent = Dlg_datostipocar->Panel1;
   Frame_datostabla ->AutoSize = false;
   Dlg_datostipocar->Width = Frame_datostabla ->Width + 20;
   Dlg_datostipocar->Height = Frame_datostabla ->Height + Dlg_datostipocar->Panel2->Height + 50;
   Dlg_datostipocar->Caption = "Modificar Tabla";


   descrip_z = qry_tablas->FieldByName("descri")->AsString;
   fecini_z  = qry_tablas->FieldByName("fecha_crea")->AsDateTime;
   campo_z = qry_tablas->FieldByName("endesuso")->AsString;

   Frame_datostabla ->edt_descri->Text = descrip_z;
   Frame_datostabla ->date_fecini->Date = fecini_z ;
   Frame_datostabla ->cmb_uso->Text =  campo_z;


   if( Dlg_datostipocar->ShowModal() == mrOk) {

     descrip_z = Frame_datostabla->edt_descri->Text;
     fecini_z = Frame_datostabla->date_fecini->DateTime;
     campo_z = Frame_datostabla->cmb_uso->Text;


     qry_tablas->Edit();
     qry_tablas->FieldByName("descri")->AsString = descrip_z;
     qry_tablas->FieldByName("fecha_crea")->AsDateTime = fecini_z;
     qry_tablas->FieldByName("endesuso")->AsString =campo_z;
     qry_tablas->Post();

     try {
        dm->manvehi->StartTransaction();
        qry_tablas->ApplyUpdates();
        dm->manvehi->Commit();
      } catch (Exception &E){

        dm->manvehi->Rollback();
        Application->MessageBox(("No pude grabar los datos:\n"+E.Message).c_str(), "ERROR", MB_ICONEXCLAMATION);
      }

   }

   delete Frame_datostabla;
   delete Dlg_datostipocar;
  
}
//---------------------------------------------------------------------------
void __fastcall TForm_reltablas::qry_tablasAfterScroll(TDataSet *DataSet)
{
  String tabla_z,sql_z,ver_z,columna_z;
  int idtablas_z;

  if (qry_tablas->Tag == NO_REFRESH) return;
  tabla_z = qry_tablas->FieldByName("tabla")->AsString;
  idtablas_z = qry_tablas->FieldByName("idtabla")->AsInteger;

  list_columnas->Items->Clear();
  if( tabla_z == ""){
     Application->MessageBox("No Existe Ninguna Tabla", "Error", MB_OK | MB_ICONERROR);
     return;
  }else{

      sql_z = "select * from " + tabla_z;
      sql_z += " where rownum < 1";
      qry_columns->Close();
      qry_columns->SQL->Text = sql_z;
      ver_z = sql_z;
      qry_columns->Open();
      //dbgrd_columnas->DestroyColumns();
      //dbgrd_columnas->CreateDefaultColumns(qry_columns, dbgrd_columnas);
      for(int ii_z = 0; ii_z < qry_columns->FieldCount; ii_z++) {
        columna_z = qry_columns->Fields->Fields[ii_z]->FieldName.UpperCase();
        list_columnas->Items->Add (columna_z);

      }

      sql_z = "";
  }

  if (qry_relacs->Tag == NO_REFRESH) return;
  qry_relacs->Close();
  qry_relacs->ParamByName("idtabla")->AsInteger = idtablas_z;
  qry_relacs->Open();

}
//---------------------------------------------------------------------------


void __fastcall TForm_reltablas::impri_tablaExecute(TObject *Sender)
{
  //imprimir tablas
  String tipo_z,uso_z,descri_z,tabla_z,arch_z;
  int line_z,num_z;
  TDateTime fecha_z;
  line_z = 0;
  pagina_z = 1;
  impri1_z = true;

  if(Application->MessageBox("Seguro imprimir Reporte ?", "Impresi�n Reporte", MB_OKCANCEL) != IDOK ) return;
     arch_z = "frm_reltablas1.txt";
    if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
         Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
         return;
  }

  report_encab();
  encab1();

  for(qry_tablas->First(); !qry_tablas->Eof; qry_tablas->Next()) {
     num_z = qry_tablas->FieldByName("idtabla")->AsInteger;
     tabla_z = qry_tablas->FieldByName("tabla")->AsString;
     descri_z = qry_tablas->FieldByName("descri")->AsString;
     fecha_z = qry_tablas->FieldByName("fecha_crea")->AsDateTime;
     uso_z = qry_tablas->FieldByName("endesuso")->AsString;


     fprintf(archout, "|");
     fprintf(archout, "%s|", ljust(num_z, 3));
     fprintf(archout, "%s|", ljust(tabla_z, 20));
     fprintf(archout, "%s|", ljust(descri_z, 60));
     fprintf(archout, "%s|", ljust( FormatDateTime("dd/mm/yyyy",fecha_z),10));
     fprintf(archout, "%s|\n", cjust(uso_z,6));

     lineas_z += 1;
     checa_salto_pag(3);
  }
  fclose(archout);
  
}
//---------------------------------------------------------------------------
 bool __fastcall TForm_reltablas::checa_salto_pag(int margen_z)
{
  bool haysalto_z = false;
  if(lineas_z > (MAX_LINEAS - margen_z)) {
    fprintf(archout, "%c", 12);
    pagina_z++;
    report_encab();
    if (impri1_z == true )encab1();
    if (impri2_z == true) encab_rel();
    haysalto_z = true;
  }
  return (haysalto_z);
}
//---------------------------------------------------------------------------

void __fastcall TForm_reltablas::encab_tabla(String tabla_z)
{

  fprintf(archout, "%s", ljust("Tabla:",6));
  fprintf(archout, "%s", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_ON));
  fprintf(archout, "%s", ljust(tabla_z, 25));
  fprintf(archout, "%s\n", dm->font_impre(dm->impre_z, ON_LINE_EXPANDED_OFF));
  lineas_z += 1;

}
//---------------------------------------------------------------------------
void __fastcall TForm_reltablas::impri_relExecute(TObject *Sender)
{
    //imprimir Relaciones
  String tipo_z,uso_z,descri_z,tabla_z,arch_z,campo_z,descrirel_z,obserel_z,
  tablarel_z,otratabla_z,camporel_z;
  int line_z,tiporel_z,idtablarel_z;
  TDateTime fecha_z;
  line_z = 0;
  pagina_z = 1;
  impri2_z = true;
  if(Application->MessageBox("Seguro imprimir Reporte ?", "Impresi�n Reporte", MB_OKCANCEL) != IDOK ) return;
     arch_z = "frm_reltablas.txt";
    if( (archout = fopen(arch_z.c_str(), "w")) == NULL ) {
         Application->MessageBox(("No puedo abrir archivo Textual de Salida:"+arch_z).c_str(), "No puedo escribir", MB_ICONEXCLAMATION);
         return;
  }
    report_encab();

   for(qry_tablas->First(); !qry_tablas->Eof; qry_tablas->Next()) {
       line_z = 0;
       tabla_z = qry_tablas->FieldByName("tabla")->AsString;
       //encab_tabla(tabla_z);


      for(qry_relacs->First(); !qry_relacs->Eof; qry_relacs->Next()) {
       if(line_z == 0 ){
         encab_tabla(tabla_z);
         encab_rel();
         line_z = 1;
       }

       tablarel_z = qry_relacs->FieldByName("tabla")->AsString;
       campo_z = qry_relacs->FieldByName("campo")->AsString;
       idtablarel_z = qry_relacs->FieldByName("idtablarel")->AsInteger;
       camporel_z = qry_relacs->FieldByName("camporel")->AsString;
       tiporel_z = qry_relacs->FieldByName("tiporel")->AsInteger;
       descrirel_z = qry_relacs->FieldByName("descri")->AsString;
       obserel_z = qry_relacs->FieldByName("observs")->AsString;


       fprintf(archout, "|");
       fprintf(archout, "%s|", ljust(tabla_z, 10));
       fprintf(archout, "%s|", ljust(campo_z, 10));
       fprintf(archout, "%s|", ljust(tablarel_z , 10));
       fprintf(archout, "%s|", ljust(camporel_z, 20));
       fprintf(archout, "%s|", cjust(tiporel_z, 10));
       fprintf(archout, "%s|", ljust(descrirel_z, 40));
       fprintf(archout, "%s|\n", ljust(obserel_z,40));

       lineas_z += 1;
       checa_salto_pag(3);
      }
       checa_salto_pag(3);
   }
   fclose(archout);
}
//---------------------------------------------------------------------------


void __fastcall TForm_reltablas::FormClose(TObject *Sender,
      TCloseAction &Action)
{
  Action = caFree;        
}
//---------------------------------------------------------------------------

