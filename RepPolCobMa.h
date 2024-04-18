//----------------------------------------------------------------------------
#ifndef RepPolCobMaH
#define RepPolCobMaH
//----------------------------------------------------------------------------
#include <vcl\Classes.hpp>
#include <vcl\Controls.hpp>
#include <vcl\StdCtrls.hpp>
#include <vcl\Forms.hpp>
#include <vcl\QuickRpt.hpp>
#include <vcl\QRCtrls.hpp>
#include <Db.hpp>
#include <DBTables.hpp>
#include <ExtCtrls.hpp>
#include <Qrctrls.hpp>
//----------------------------------------------------------------------------
void __fastcall ReporteCobranzaMayoristas(int iCia, String Almac, TDateTime dtFecha);
//----------------------------------------------------------------------------
class TqrRepPolCobMay : public TQuickRep
{
__published:
    TQRBand *QRBand1;
    TQuery *qsCias;
    TQRLabel *qrlblEmpresa;
    TQRLabel *qrlblDirecc;
    TQRLabel *QRLabel3;
    TQRSysData *QRSysData1;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQuery *qsPoliza;
    TQRDBText *QRDBText1;
    TQRDBText *QRDBText2;
    TQRDBText *QRDBText3;
    TQRLabel *QRLabel4;
    TQRDBText *QRDBText4;
    TQRSysData *QRSysData2;
    TQRBand *QRBand2;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel7;
    TQRLabel *QRLabel8;
    TQRLabel *QRLabel9;
    TQRLabel *QRLabel10;
    TQuery *qsClientes;
    TDataSource *dtsClientes;
    TQuery *qsRenPol;
    TQRSubDetail *QRSubDetail1;
    TQRDBText *QRDBText7;
    TQRDBText *QRDBText8;
    TQRDBText *QRDBText9;
    TQRDBText *QRDBText10;
    TQRLabel *QRLabel12;
    TQRDBText *QRDBText11;
    TQRDBText *QRDBText12;
    TQRDBText *QRDBText13;
    TQRBand *QRBand3;
    TQRLabel *QRLabel13;
    TQRLabel *QRLabel14;
    TQRExpr *QRExpr1;
    TQRLabel *QRLabel15;
    TQRExpr *QRExpr2;
    TQRLabel *QRLabel16;
    TQRExpr *QRExpr3;
    TQRBand *QRBand4;
    TQRLabel *QRLabel17;
    TQRLabel *QRLabel18;
    TQRExpr *QRExpr4;
    TQRLabel *QRLabel19;
    TQRExpr *QRExpr5;
    TQRLabel *QRLabel20;
    TQRExpr *QRExpr6;
    TQRBand *QRBand5;
    TQRLabel *QRLabel11;
    TQRDBText *QRDBText5;
    TQRDBText *QRDBText6;
private:
public:
   __fastcall TqrRepPolCobMay(TComponent* Owner);
};
//----------------------------------------------------------------------------
extern TqrRepPolCobMay *qrRepPolCobMay;
//----------------------------------------------------------------------------
#endif