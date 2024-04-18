//----------------------------------------------------------------------------
#ifndef RepCapPedH
#define RepCapPedH
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
class TqrImpCapped : public TQuickRep
{
__published:
    TQRBand *PageHeaderBand1;
    TQRBand *ColumnHeaderBand1;
    TQRBand *DetailBand1;
    TQRBand *SummaryBand1;
    TQRLabel *qrlblCia;
    TQRSysData *QRSysData1;
    TQRSysData *QRSysData2;
    TQuery *qsCias;
    TQRLabel *qrlblDirec;
    TQuery *qsPedido;
    TQuery *qsRenentra;
    TQRLabel *QRLabel1;
    TQRLabel *QRLabel2;
    TQRLabel *QRLabel3;
    TQRLabel *QRLabel4;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel7;
    TQRLabel *QRLabel8;
    TQRLabel *QRLabel9;
    TQRDBText *QRDBText2;
    TQRDBText *QRDBText3;
    TQRDBText *QRDBText4;
    TQRDBText *QRDBText5;
    TQRDBText *QRDBText6;
    TQRLabel *QRLabel10;
    TQRDBText *QRDBText7;
    TQRDBText *QRDBText8;
    TQRDBText *QRDBText9;
    TQRDBText *QRDBText10;
    TQRDBText *QRDBText11;
    TQRLabel *QRLabel11;
    TQRLabel *QRLabel12;
    TQRLabel *QRLabel13;
    TQRLabel *QRLabel14;
    TQRLabel *QRLabel15;
    TQRLabel *QRLabel16;
    TQRLabel *QRLabel17;
    TQRLabel *QRLabel18;
    TQRLabel *QRLabel19;
    TQRDBText *QRDBText12;
    TQRDBText *QRDBText13;
    TQRDBText *QRDBText14;
    TQRDBText *QRDBText15;
    TQRDBText *QRDBText16;
    TQRLabel *QRLabel5;
    TQRDBText *QRDBText1;
    TQRDBText *QRDBText17;
private:
public:
   __fastcall TqrImpCapped(TComponent* Owner);
};
//----------------------------------------------------------------------------
extern TqrImpCapped *qrImpCapped;
//----------------------------------------------------------------------------
#endif