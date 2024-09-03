//----------------------------------------------------------------------------
#ifndef MainH
#define MainH
//----------------------------------------------------------------------------
#include "ChildWin.h"
#include <vcl\ComCtrls.hpp>
#include <vcl\ExtCtrls.hpp>
#include <vcl\Messages.hpp>
#include <vcl\Buttons.hpp>
#include <vcl\Dialogs.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Menus.hpp>
#include <vcl\Controls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\Graphics.hpp>
#include <vcl\Classes.hpp>
#include <vcl\SysUtils.hpp>
#include <vcl\Windows.hpp>
#include <vcl\System.hpp>
#include <ActnList.hpp>
#include <ImgList.hpp>
#include <StdActns.hpp>
#include <ToolWin.hpp>
//----------------------------------------------------------------------------
class TMainForm : public TForm
{
__published:
	TMainMenu *MainMenu1;
	TMenuItem *File1;
	TMenuItem *Window1;
	TMenuItem *Help1;
	TMenuItem *N1;
	TMenuItem *FileExitItem;
	TMenuItem *WindowCascadeItem;
	TMenuItem *WindowTileItem;
	TMenuItem *WindowArrangeItem;
	TMenuItem *HelpAboutItem;
	TOpenDialog *OpenDialog;
	TMenuItem *Edit1;
	TMenuItem *CutItem;
	TMenuItem *CopyItem;
	TMenuItem *PasteItem;
	TMenuItem *WindowMinimizeItem;
        TActionList *ActionList1;
        TEditCut *EditCut1;
        TEditCopy *EditCopy1;
        TEditPaste *EditPaste1;
        TAction *FileNew1;
        TAction *FileSave1;
        TAction *FileExit1;
        TAction *FileOpen1;
        TAction *FileSaveAs1;
        TWindowCascade *WindowCascade1;
        TWindowTileHorizontal *WindowTileHorizontal1;
        TWindowArrange *WindowArrangeAll1;
        TWindowMinimizeAll *WindowMinimizeAll1;
        TAction *HelpAbout1;
        TWindowClose *FileClose1;
        TWindowTileVertical *WindowTileVertical1;
        TMenuItem *WindowTileItem2;
  TMenuItem *Consultas1;
  TMenuItem *Inven1;
        TLabel *lbl_version;
        TMenuItem *menu_item_movtospend;
        TMenuItem *menu_mantos;
        TMenuItem *Grupos1;
        TMenuItem *Diarys1;
        TMenuItem *Marcas1;
        TMenuItem *PlazosListaPrecio1;
    TMenuItem *Operaciones1;
    TMenuItem *N2;
    TMenuItem *FacturaMayoristas1;
    TMenuItem *CapturadePedidos1;
    TMenuItem *PolizaCobroMayoristas1;
    TMenuItem *EstadoCuentaMayorista1;
    TMenuItem *ReportesMayoristas1;
    TMenuItem *ReportePendPago1;
    TMenuItem *ReporteCargosAbonos1;
    TMenuItem *CuotasMargenUtilidadCelulares1;
    TMenuItem *PropiedadesImpresora1;
    TMenuItem *CapturadeSabanasdeVentas1;
    TMenuItem *CapturaSabanasdeVentasTradicional1;
    TMenuItem *Fonacot1;
    TMenuItem *Fide1;
    TMenuItem *Celular1;
        TMenuItem *TraspasosyDevoluciones1;
        TMenuItem *Traspasos1;
        TMenuItem *Devoluciones1;
        TMenuItem *Cancelaciones1;
        TMenuItem *Tradicional1;
        TMenuItem *SalidasEspeciales1;
        TMenuItem *SalidasEspeciales2;
        TMenuItem *CancelacionesxCambioTradicional1;
        TMenuItem *Situaciones1;
        TMenuItem *CancelacionesxCambioFonacot1;
        TMenuItem *CancelacionesxCambioFide1;
        TMenuItem *CancelacionesxCambioCelular1;
        TMenuItem *MovientosInternos1;
        TMenuItem *EntradasEspeciales1;
        TMenuItem *Fonacot2;
        TMenuItem *Fide2;
        TMenuItem *Celular2;
        TMenuItem *Proveedores1;
        TMenuItem *Vendedores1;
        TMenuItem *EntradasProveedor1;
        TMenuItem *SeleccionarBasedeDatos1;
        TMenuItem *Mayoreo1;
        TMenuItem *Reportes1;
        TMenuItem *AnaliticodeMenudeoMayoreo1;
        TMenuItem *Imevi1;
        TMenuItem *cancelimevi;
        TMenuItem *CancelacionesxCambioImevi1;
        TMenuItem *CapturaRelacionVentas1;
        TMenuItem *ConsultaRelacionesdeVentas1;
        TMenuItem *Mayoristas1;
        TMenuItem *GenerarRelacionTraspasos1;
        TMenuItem *Choferes1;
        TMenuItem *TiposdeVenta1;
        TMenuItem *TiposdeEntregas1;
        TMenuItem *Menu_mantoUsuarios;
        TStatusBar *StatusBar;
        TMenuItem *Almacenes1;
        TMenuItem *Embarques1;
        TMenuItem *CapturaAgenda1;
        TMenuItem *menu_item_permisiones;
        TMenuItem *Facturasrangovencimiento1;
        TMenuItem *VentasxVendedoryZona1;
        TMenuItem *Mayoreo2;
        TMenuItem *PromocionesMayoreoxGrupo1;
        TMenuItem *analitico_vtas;
        TMenuItem *ReportesparaInformes1;
        TMenuItem *TabladeVentasCreditoContadorFonacotFide1;
        TMenuItem *ConcentradoDevolucionesProveedor1;
        TMenuItem *InformedeEntradasProveedor1;
        TMenuItem *RelacionesdeTablas1;
        TMenuItem *ConsultaMovimientosMayoreo1;
        TMenuItem *ReportesdeMantenimiento1;
        TMenuItem *ListadePrecios1;
        TMenuItem *AnalticodeEntradas1;
        TMenuItem *AnalticodeVentasFONACOT1;
        TMenuItem *UbicacionespZonas1;
        TMenuItem *CostodeVentasxUbicacin1;
        TMenuItem *TabladeCostodeVentas1;
        TMenuItem *ProyeccinyComparativo1;
        TMenuItem *ProyeccindeCostos1;
        TMenuItem *Mayoreo3;
        TMenuItem *AcumuladodeCobranzaMayoreo1;
        TMenuItem *ExistenciasxUbicacin1;
        TMenuItem *PolizasCambiosdePrecios1;
        TMenuItem *ExistenciasMciaCancelada1;
        TMenuItem *InformeCostodeVentasyCancelacionesinfcvta1;
        TMenuItem *AnalticoxAlmacnPuntoVtaLnearepcvta1;
        TMenuItem *CapturadeFacturasMayoreo1;
        TMenuItem *PuntosdeVenta1;
        TMenuItem *Ciudades1;
        TMenuItem *Estados1;
        TMenuItem *ZonasyMegazonas1;
        TMenuItem *Lneas1;
        TMenuItem *ReportedeEntradasparaEnvo1;
        TMenuItem *ImpresindeArchivos1;
        TMenuItem *ExistenciasparaRequerimientos1;
        TMenuItem *ExistenciasconSeries1;
        TMenuItem *RelacinFacturasVigentes1;
        TMenuItem *RelacindeVencimientosxFecha1;
        TMenuItem *CatlogoProductosSatCFD331;
        TMenuItem *PlizadeOfertas1;
        TMenuItem *TablaServiciosporArticulo1;
        TMenuItem *DefinirGruposconSerieAumentada1;
        TMenuItem *TabladeColoresSalasBicicletas1;
        TMenuItem *PolizaOutlet1;
        TMenuItem *PolizasdePreciosOfertasOutelet1;
        TMenuItem *GruposSerieAumentadaTablasdeColores1;
        TMenuItem *AnalticodeSabandeVentas1;
        TMenuItem *PlizaOfertasInternet1;
        TMenuItem *PlizaCambioSituacin1;
        TMenuItem *PlizadepreciosASI1;
        void __fastcall FileNew1Execute(TObject *Sender);
        void __fastcall FileOpen1Execute(TObject *Sender);
        void __fastcall HelpAbout1Execute(TObject *Sender);
        void __fastcall FileExit1Execute(TObject *Sender);
  void __fastcall Inven1Click(TObject *Sender);
        void __fastcall menu_item_movtospendClick(TObject *Sender);
        void __fastcall Grupos1Click(TObject *Sender);
        void __fastcall Diarys1Click(TObject *Sender);
        void __fastcall Marcas1Click(TObject *Sender);
        void __fastcall PlazosListaPrecio1Click(TObject *Sender);
    void __fastcall FacturaMayoristas1Click(TObject *Sender);
    void __fastcall CapturadePedidos1Click(TObject *Sender);
    void __fastcall PolizaCobroMayoristas1Click(TObject *Sender);
    void __fastcall EstadoCuentaMayorista1Click(TObject *Sender);
    void __fastcall ReportePendPago1Click(TObject *Sender);
    void __fastcall ReporteCargosAbonos1Click(TObject *Sender);
    void __fastcall CuotasMargenUtilidadCelulares1Click(TObject *Sender);
    void __fastcall PropiedadesImpresora1Click(TObject *Sender);
    void __fastcall CapturaSabanasdeVentasTradicional1Click(
          TObject *Sender);
    void __fastcall Fonacot1Click(TObject *Sender);
    void __fastcall Fide1Click(TObject *Sender);
    void __fastcall Celular1Click(TObject *Sender);
        void __fastcall Traspasos1Click(TObject *Sender);
        void __fastcall Devoluciones1Click(TObject *Sender);
        void __fastcall Tradicional1Click(TObject *Sender);
        void __fastcall SalidasEspeciales2Click(TObject *Sender);
        void __fastcall CancelacionesxCambioTradicional1Click(
          TObject *Sender);
        void __fastcall Situaciones1Click(TObject *Sender);
        void __fastcall CancelacionesxCambioFonacot1Click(TObject *Sender);
        void __fastcall CancelacionesxCambioFide1Click(TObject *Sender);
        void __fastcall CancelacionesxCambioCelular1Click(TObject *Sender);
        void __fastcall MovientosInternos1Click(TObject *Sender);
        void __fastcall EntradasEspeciales1Click(TObject *Sender);
        void __fastcall Fonacot2Click(TObject *Sender);
        void __fastcall Fide2Click(TObject *Sender);
        void __fastcall Celular2Click(TObject *Sender);
        void __fastcall Proveedores1Click(TObject *Sender);
        void __fastcall Vendedores1Click(TObject *Sender);
        void __fastcall EntradasProveedor1Click(TObject *Sender);
        void __fastcall SeleccionarBasedeDatos1Click(TObject *Sender);
        void __fastcall Mayoreo1Click(TObject *Sender);
        void __fastcall AnaliticodeMenudeoMayoreo1Click(TObject *Sender);
        void __fastcall Imevi1Click(TObject *Sender);
        void __fastcall cancelimeviClick(TObject *Sender);
        void __fastcall CancelacionesxCambioImevi1Click(TObject *Sender);
        void __fastcall CapturaRelacionVentas1Click(TObject *Sender);
        void __fastcall ConsultaRelacionesdeVentas1Click(TObject *Sender);
        void __fastcall Mayoristas1Click(TObject *Sender);
        void __fastcall GenerarRelacionTraspasos1Click(TObject *Sender);
        void __fastcall Choferes1Click(TObject *Sender);
        void __fastcall TiposdeVenta1Click(TObject *Sender);
        void __fastcall TiposdeEntregas1Click(TObject *Sender);
        void __fastcall Menu_mantoUsuariosClick(TObject *Sender);
        void __fastcall FormShow(TObject *Sender);
        void __fastcall Almacenes1Click(TObject *Sender);
        void __fastcall CapturaAgenda1Click(TObject *Sender);
        void __fastcall FormDestroy(TObject *Sender);
        void __fastcall menu_item_permisionesClick(TObject *Sender);
        void __fastcall Facturasrangovencimiento1Click(TObject *Sender);
        void __fastcall VentasxVendedoryZona1Click(TObject *Sender);
        void __fastcall CapturaRelacindeVentas1Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall PromocionesMayoreoxGrupo1Click(TObject *Sender);
        void __fastcall analitico_vtasClick(TObject *Sender);
        void __fastcall TabladeVentasCreditoContadorFonacotFide1Click(
          TObject *Sender);
        void __fastcall ConcentradoDevolucionesProveedor1Click(
          TObject *Sender);
        void __fastcall InformedeEntradasProveedor1Click(TObject *Sender);
        void __fastcall RelacionesdeTablas1Click(TObject *Sender);
        void __fastcall ConsultaMovimientosMayoreo1Click(TObject *Sender);
        void __fastcall ListadePrecios1Click(TObject *Sender);
        void __fastcall AnalticodeEntradas1Click(TObject *Sender);
        void __fastcall AnalticodeVentasFONACOT1Click(TObject *Sender);
        void __fastcall UbicacionespZonas1Click(TObject *Sender);
        void __fastcall CostodeVentasxUbicacin1Click(TObject *Sender);
        void __fastcall TabladeCostodeVentas1Click(TObject *Sender);
        void __fastcall ProyeccinyComparativo1Click(TObject *Sender);
        void __fastcall ProyeccindeCostos1Click(TObject *Sender);
        void __fastcall AcumuladodeCobranzaMayoreo1Click(TObject *Sender);
        void __fastcall ExistenciasxUbicacin1Click(TObject *Sender);
        void __fastcall PolizasCambiosdePrecios1Click(TObject *Sender);
        void __fastcall ExistenciasMciaCancelada1Click(TObject *Sender);
        void __fastcall InformeCostodeVentasyCancelacionesinfcvta1Click(
          TObject *Sender);
        void __fastcall AnalticoxAlmacnPuntoVtaLnearepcvta1Click(
          TObject *Sender);
        void __fastcall CapturadeFacturasMayoreo1Click(TObject *Sender);
        void __fastcall PuntosdeVenta1Click(TObject *Sender);
        void __fastcall Ciudades1Click(TObject *Sender);
        void __fastcall Estados1Click(TObject *Sender);
        void __fastcall ZonasyMegazonas1Click(TObject *Sender);
        void __fastcall Lneas1Click(TObject *Sender);
        void __fastcall ReportedeEntradasparaEnvo1Click(TObject *Sender);
        void __fastcall ImpresindeArchivos1Click(TObject *Sender);
        void __fastcall ExistenciasparaRequerimientos1Click(
          TObject *Sender);
        void __fastcall ExistenciasconSeries1Click(TObject *Sender);
        void __fastcall RelacinFacturasVigentes1Click(TObject *Sender);
        void __fastcall RelacindeVencimientosxFecha1Click(TObject *Sender);
        void __fastcall CatlogoProductosSatCFD331Click(TObject *Sender);
        void __fastcall PlizadeOfertas1Click(TObject *Sender);
        void __fastcall TablaServiciosporArticulo1Click(TObject *Sender);
        void __fastcall DefinirGruposconSerieAumentada1Click(
          TObject *Sender);
        void __fastcall TabladeColoresSalasBicicletas1Click(
          TObject *Sender);
        void __fastcall PolizaOutlet1Click(TObject *Sender);
        void __fastcall AnalticodeSabandeVentas1Click(TObject *Sender);
        void __fastcall PlizaOfertasInternet1Click(TObject *Sender);
        void __fastcall PlizaCambioSituacin1Click(TObject *Sender);
        void __fastcall PlizadepreciosASI1Click(TObject *Sender);
private:
	void __fastcall CreateMDIChild(const String Name);
public:
	virtual __fastcall TMainForm(TComponent *Owner);
  int cia_z, yaestuvo_z;
};
//----------------------------------------------------------------------------
extern TMainForm *MainForm;
extern TMDIChild *__fastcall MDIChildCreate(void);
//----------------------------------------------------------------------------
#endif
