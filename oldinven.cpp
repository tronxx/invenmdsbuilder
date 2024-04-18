//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
#include "Frm_login.h"
#include "dmod.h"

//---------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USEFORM("ChildWin.cpp", MDIChild);
USERES("oldinven.res");
USEFORM("about.cpp", AboutBox);
USEFORM("Frm_consuinv.cpp", Form_consuinv);
USEFORM("dmod.cpp", dm); /* TDataModule: File Type */
USEFORM("Frm_detmovart.cpp", Form_detmovart);
USEFORM("Frm_estadis.cpp", Form_estadis);
USEFORM("Frm_dlgcriterio.cpp", Form_dlgcriterio);
USEFORM("Frm_revision.cpp", Form_revision);
USEFORM("Frm_mantgpodia.cpp", Form_mantgpodia);
USEFORM("Frm_mantgpoinv.cpp", Form_mantgpoinv);
USEFORM("Frm_capageemb.cpp", Form_capageemb);
USEFORM("Frm_exists.cpp", Form_exists);
USEUNIT("..\Mislibs\numapal.cpp");
USEFORM("Frm_mantpzo.cpp", Form_mantpzo);
USEUNIT("..\Mislibs\imprigra.cpp");
USEUNIT("..\Mislibs\impre.cpp");
USEFORM("Frm_CapturaVentas.cpp", Form_capturaventas);
USEFORM("dlgCataAlmacen.cpp", frmDlgCataAlmacen);
USEFORM("Frm_consufacma.cpp", frmConsuFactuMay);
USEFORM("dlgFiltroConsFacMay.cpp", dlgFilConsufacma);
USEFORM("dlgCnsMayorista.cpp", frmDlgCnsMayoris);
USEFORM("Frm_capped.cpp", frmPedidos);
USEFORM("dlgFiltroCnsPed.cpp", frmDlgFilPedidos);
USEFORM("Frm_cappedmanto.cpp", frmDlgCapPed);
USEFORM("dlgCnsProves.cpp", frmDlgConsProve);
USEFORM("dlgCnsCodInven.cpp", frmDlgCnsCodInven);
USEFORM("dlgCnsConcepto.cpp", frmDlgConcepto);
USEFORM("Login.cpp", frmdlgLogin);
USEFORM("RepCapPed.cpp", qrImpCapped); /* TQuickRep: File Type */
USEFORM("Frm_consupolcobmayo.cpp", Form_ConsPolCobMay);
USEFORM("Frm_cappolcobmay.cpp", Form_CapPolCobMay);
USEFORM("dlgCnsPenPagMay.cpp", frmDlgPendPagMay);
USEFORM("RepPolCobMa.cpp", qrRepPolCobMay); /* TQuickRep: File Type */
USEFORM("Frm_ConsuMovsMay.cpp", Form_ConsuMovsMay);
USEFORM("RepEdoCtaMayoris.cpp", qrRepEdoCtaMayoris); /* TQuickRep: File Type */
USEFORM("dlgImpPendPagMay.cpp", frmDlgImpPenPag);
USEFORM("RepCarAboMay.cpp", qrRepCarAboMay); /* TQuickRep: File Type */
USEFORM("Frm_selserie.cpp", Form_selserie);
USEFORM("Frm_mantcuocel.cpp", Form_mantcuocel);
USEFORM("Frm_kardex.cpp", Form_kardex);
USEFORM("..\Mislibs\dlg_seltipoimp.cpp", dialg_seltipoimp);
USEFORM("Frm_captrasp.cpp", Form_captrasp);
USEFORM("Frm_capcancel.cpp", Form_capcancel);
USEFORM("Frm_capsales.cpp", Form_capsales);
USEFORM("Frm_canxcam.cpp", Form_canxcam);
USEFORM("Frm_mantempaqe.cpp", Form_mantempaqe);
USEFORM("Frm_capentes.cpp", Form_capentes);
USEFORM("Frm_mantoprove.cpp", Form_mantoprove);
USEFORM("Frm_mantovnd.cpp", Form_mantovnd);
USEFORM("Frm_capentpro.cpp", Form_capentpro);
USEFORM("Frm_selecdb.cpp", Form_selecbd);
USEFORM("dialg_busartic.cpp", dlg_busartic);
USEFORM("Frm_cappedm.cpp", Form_cappedm);
USEFORM("Frm_analisma.cpp", Form_analisma);
USEFORM("..\Mislibs\Frm_prever.cpp", Form_prever);
USEFORM("Frm_caprelvta.cpp", Form_caprelvta);
USEFORM("Frm_consrelvta.cpp", Form_consrelvta);
USEFORM("Frm_mantmayo.cpp", Form_mantmayo);
USEFORM("Frm_relsurti.cpp", Form_relsurti);
USEFORM("Frm_mantoprm.cpp", Form_mantoprm);
USEFORM("Frm_mantotiposctes.cpp", Form_mantotiposctes);
USEFORM("Frm_mantotiposentrega.cpp", Form_mantotiposentrega);
USEFORM("Frm_mantoalm.cpp", Form_mantoalm);
USEFORM("dialg_foliosdisp.cpp", dlg_foliosdisp);
USEFORM("Frm_login.cpp", Form_login);
USEFORM("Frm_mantousr.cpp", Form_mantousr);
USEFORM("dialg_datosagenda.cpp", dlg_datosagenda);
USEFORM("dialg_datosalm.cpp", dlg_datosalm);
USEFORM("Frm_mantmarca.cpp", Form_mantmarca);
USEFORM("dialg_datosrenagenda.cpp", dlg_datosrenagenda);
USEFORM("Frme_usuario.cpp", Frame_usuario); /* TFrame: File Type */
USEFORM("dialg_okcancel.cpp", dlg_okcancel);
USEFORM("Frm_mantpermis.cpp", Form_mantpermis);
USEFORM("Frme_datosmarca.cpp", Frame_datosmarca); /* TFrame: File Type */
USEFORM("Frm_relfacmay.cpp", Form_relfacmay);
USEFORM("Frme_datosplazo.cpp", Frame_datosplazo); /* TFrame: File Type */
USEFORM("Frm_repvtaxvnd.cpp", Form_repvtaxvnd);
USEFORM("Frme_datossabanavta.cpp", Frame_datossabanavta); /* TFrame: File Type */
USEFORM("Frme_datossabanaagre.cpp", Frame_datossabanaagre); /* TFrame: File Type */
USEFORM("Frme_datoscappedm.cpp", Frame_datoscappedm); /* TFrame: File Type */
USEFORM("Frme_datoscappedmagrnuevo.cpp", Frame_datoscappedmagrnuevo); /* TFrame: File Type */
USEFORM("Frme_datoscaptrasp.cpp", Frame_datoscaptrasp); /* TFrame: File Type */
USEFORM("Frme_datoscaptraspagregaren.cpp", Frame_datoscaptraspagregaren); /* TFrame: File Type */
USEFORM("Frme_datoscapcancel.cpp", Frame_datoscapcancel); /* TFrame: File Type */
USEFORM("Frme_datoscapcancelagrega.cpp", Frame_datoscapcancelagrega); /* TFrame: File Type */
USEFORM("Frme_datoscapentpro.cpp", Frame_datoscapentpro); /* TFrame: File Type */
USEFORM("Frme_datoscapentproagre.cpp", Frame_datoscapentproagre); /* TFrame: File Type */
USEFORM("Frme_imginven.cpp", Frame_imginven); /* TFrame: File Type */
USEFORM("Frme_datosmantmayo.cpp", Frame_datosmantmayo); /* TFrame: File Type */
USEFORM("Frme_datosmantovnd.cpp", Frame_datosmantovnd); /* TFrame: File Type */
USEFORM("Frme_datosmantoprove.cpp", Frame_datosmantoprove); /* TFrame: File Type */
USEFORM("Frme_datosmantotiposctes.cpp", Frame_datosmantotiposctes); /* TFrame: File Type */
USEFORM("Frme_datospolcobma.cpp", Frame_datospolcobma); /* TFrame: File Type */
USEFORM("Frme_datosrenpolcobma.cpp", Frame_datosrenpolcobma); /* TFrame: File Type */
USEFORM("Form_analivtacyc.cpp", Form_analivtacyc);
USEFORM("Frm_tabcvtcrdcon.cpp", Form_tabcvtcrdcon);
USEFORM("Frm_condevpr.cpp", Form_condevpr);
USEFORM("Frm_infent.cpp", Form_infent);
USEFORM("Frme_nvaobsped.cpp", Frame_nvaobsped); /* TFrame: File Type */
USEFORM("Frm_reltablas.cpp", Form_reltablas);
USEFORM("Frme_datoscambio.cpp", Frame_datoscambio); /* TFrame: File Type */
USEFORM("Frme_datostabla.cpp", Frame_datostabla); /* TFrame: File Type */
USEFORM("Frme_agregarelac.cpp", Frame_agregarelac); /* TFrame: File Type */
USEFORM("Frme_datosrencanxcam.cpp", Frame_datosrencanxcam); /* TFrame: File Type */
USEFORM("Frme_nuevasseries.cpp", Frame_nuevasseries); /* TFrame: File Type */
USEFORM("Frme_dircli.cpp", Frame_dircli); /* TFrame: File Type */
USEFORM("Frme_datoscapsmay.cpp", Frame_datoscapsmay); /* TFrame: File Type */
USEFORM("Frme_datosrensmay.cpp", Frame_datosrensmay); /* TFrame: File Type */
USEFORM("Frm_capsalmay.cpp", Form_capsalmay);
USEFORM("Frm_listpre2.cpp", Form_listpre2);
USEFORM("Frm_analient.cpp", Form_analient);
USEFORM("Frm_analifon.cpp", Form_analifon);
USEFORM("Frm_mantubivta.cpp", Form_mantubivta);
USEFORM("Frme_datosubivta.cpp", Frame_datosubivta); /* TFrame: File Type */
USEFORM("Frme_datosrelvta.cpp", Frame_datosrelvta); /* TFrame: File Type */
USEFORM("Frm_cvtaubi.cpp", Form_cvtaubi);
USEFORM("Frm_tabcvta.cpp", Form_tabcvta);
USEFORM("Frme_datospedimento.cpp", Frame_datospedimento); /* TFrame: File Type */
USEFORM("Frm_proycom.cpp", Form_proycom);
USEFORM("Frme_datosmantproy.cpp", Frame_datosmantproy); /* TFrame: File Type */
USEFORM("Frme_datosmantsubproy.cpp", Frame_datosmantsubproy); /* TFrame: File Type */
USEFORM("Frm_mantproy.cpp", Form_mantproy);
USEFORM("Frm_exiubi.cpp", Form_exiubi);
USEFORM("Frm_polcampre.cpp", Form_polcampre);
USEFORM("Frme_datospolcampre.cpp", Frame_datospolcampre); /* TFrame: File Type */
USEFORM("Frme_datosrenpolcampre.cpp", Frame_datosrenpolcampre); /* TFrame: File Type */
USEFORM("Frm_exican.cpp", Form_exican);
USEFORM("Frm_infcvtacyc.cpp", Form_infcvtacyc);
USEFORM("Frm_hazfacma.cpp", Form_hazfacma);
USEFORM("Frme_datosfacma.cpp", Frame_datosfacma); /* TFrame: File Type */
USEFORM("Frme_datosrenfacma.cpp", Frame_datosrenfacma); /* TFrame: File Type */
USEFORM("Frm_mantciu.cpp", Form_mantciu);
USEFORM("Frme_importa.cpp", Frame_importa); /* TFrame: File Type */
USEFORM("Frm_CapturaObsPed.cpp", Form_CapturaObsPed);
USEFORM("Frme_datosnvoprecio.cpp", Frame_datosnvoprecio); /* TFrame: File Type */
USEFORM("Frm_mantzona.cpp", Form_mantzona);
USEFORM("Frame_zonas.cpp", Frme_zonas); /* TFrame: File Type */
USEFORM("Frm_mantlinea.cpp", Form_mantlinea);
USEFORM("Frme_datosnvaobslin.cpp", Frame_datosnvaobslin); /* TFrame: File Type */
USEFORM("Frme_datosarticulo.cpp", Frame_datosarticulo); /* TFrame: File Type */
USEFORM("Frme_perfil.cpp", Frame_perfil); /* TFrame: File Type */
USEFORM("Frme_datosmantgpoinv.cpp", Frame_datosmantgpoinv); /* TFrame: File Type */
USEFORM("Frm_impriarch.cpp", Form_impriarch);
USEFORM("Frm_exispcon2.cpp", Form_exispcon2);
USEFORM("Frm_exiserie.cpp", Form_exiserie);
USEFORM("Frm_analimvm.cpp", Form_analimvm);
USEFORM("Frm_relvenmy.cpp", Form_relvenmy);
USEFORM("Frm_mantcatprodsat.cpp", Form_mantcatprodsat);
USEFORM("Frm_mantservi.cpp", Form_mantservi);
USEFORM("Frm_repvtaxgpo.cpp", Form_repvtaxgpo);
USEFORM("Frm_analisabvta.cpp", Form_analisabvta);
USEFORM("Frme_datosinternet.cpp", Frame_datosinternet); /* TFrame: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try {
      TForm_login *Form_login = new TForm_login (Application);
      if(Form_login->ShowModal() == mrOk) {
 	 Application->Initialize();
	 Application->Title = "Consulta de Inventarios";
         Application->CreateForm(__classid(Tdm), &dm);
                 Application->CreateForm(__classid(TMainForm), &MainForm);
                 dm->idusuario_z=Form_login->idusuario_z;
         dm->usermaster_z=Form_login->usermaster_z;
         dm->iniciales_z=Form_login->iniciales_z;
         dm->login_z=Form_login->login_z;
         dm->userpol_z=Form_login->userpol_z;
         Application->Run();
      }
      delete Form_login;
      Form_login=NULL;
    } catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------

