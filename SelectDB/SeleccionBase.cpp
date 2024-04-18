//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("SeleccionBase.res");
USEFORM("Selectdb.cpp", frmSelecciondb);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    try
    {
         Application->Initialize();
         Application->CreateForm(__classid(TfrmSelecciondb), &frmSelecciondb);
         Application->Run();
    }
    catch (Exception &exception)
    {
         Application->ShowException(&exception);
    }
    return 0;
}
//---------------------------------------------------------------------------
