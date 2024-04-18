//----------------------------------------------------------------------------
#ifndef RepCarAboMayH
#define RepCarAboMayH
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
void __fastcall ImpresionCargosAbonosMay(String sClave, int icia, int iAnio);
//----------------------------------------------------------------------------
class TqrRepCarAboMay : public TQuickRep
{
__published:
    TQRBand *QRBand1;
    TQRLabel *qrlblEmpresa;
    TQRLabel *qrlblDirecc;
    TQRLabel *QRLabel3;
    TQRSysData *QRSysData1;
    TQRSysData *QRSysData2;
    TQRLabel *QRLabel1;
    TQRBand *QRBand2;
    TQRLabel *QRLabel5;
    TQRLabel *QRLabel6;
    TQRLabel *QRLabel7;
    TQRLabel *QRLabel8;
    TQRLabel *QRLabel9;
    TQRLabel *QRLabel10;
    TQRSubDetail *QRSubDetail1;
    TQRDBText *QRDBText7;
    TQRDBText *QRDBText8;
    TQRDBText *QRDBText9;
    TQRDBText *QRDBText10;
    TQRLabel *QRLabel12;
    TQRDBText *QRDBText11;
    TQRDBText *QRDBText12;
    TQRDBText *QRDBText2;
    TQRBand *QRBand4;
    TQRLabel *QRLabel20;
    TQRExpr *QRExpr6;
    TQuery *qsCias;
    TQuery *qsMayoris;
    TDataSource *dtsMayoris;
    TQRLabel *QRLabel11;
    TQRDBText *QRDBText5;
    TQRDBText *QRDBText6;
    TQRLabel *QRLabel2;
    TQRDBText *QRDBText1;
    TQuery *qsMovMay2;
    TQRLabel *QRLabel4;
    TQRDBText *QRDBText3;
    TQRExpr *QRExpr1;
private:
public:
   __fastcall TqrRepCarAboMay(TComponent* Owner);
};
//----------------------------------------------------------------------------
extern TqrRepCarAboMay *qrRepCarAboMay;
//----------------------------------------------------------------------------
#endif