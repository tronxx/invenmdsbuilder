//----------------------------------------------------------------------------
#ifndef RepEdoCtaMayorisH
#define RepEdoCtaMayorisH
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
void __fastcall ImpRepEdoCtaMayoris(AnsiString sCveMay, int icia);
//----------------------------------------------------------------------------
class TqrRepEdoCtaMayoris : public TQuickRep
{
__published:
    TQRBand *QRBand1;
    TQRLabel *qrlblEmpresa;
    TQRLabel *qrlblDirecc;
    TQRLabel *QRLabel3;
    TQRSysData *QRSysData1;
    TQRSysData *QRSysData2;
    TQRBand *QRBand2;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel7;
    TQRLabel *QRLabel8;
    TQRLabel *QRLabel9;
    TQRLabel *QRLabel10;
    TQRBand *QRBand5;
    TQRLabel *QRLabel11;
    TQRDBText *QRDBText5;
    TQRDBText *QRDBText6;
    TQRSubDetail *QRSubDetail1;
    TQRDBText *QRDBText7;
    TQRDBText *QRDBText8;
    TQRDBText *QRDBText9;
    TQRDBText *QRDBText10;
    TQRLabel *QRLabel12;
    TQRDBText *QRDBText11;
    TQRDBText *QRDBText12;
    TQRBand *QRBand3;
    TQRLabel *QRLabel16;
    TQRExpr *QRExpr3;
    TQRBand *QRBand4;
    TQRLabel *QRLabel20;
    TQRExpr *QRExpr6;
    TQuery *qsCias;
    TQRLabel *QRLabel1;
    TQuery *qsPendPag;
    TQuery *qsMayoris;
    TQRDBText *QRDBText1;
    TQRLabel *QRLabel2;
    TQRDBText *QRDBText2;
    TDataSource *dtsMayoris;
private:
public:
   __fastcall TqrRepEdoCtaMayoris(TComponent* Owner);
};
//----------------------------------------------------------------------------
extern TqrRepEdoCtaMayoris *qrRepEdoCtaMayoris;
//----------------------------------------------------------------------------
#endif