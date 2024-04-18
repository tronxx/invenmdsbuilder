//---------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop
//---------------------------------------------------------------------
USEFORM("Main.cpp", MainForm);
USEFORM("ChildWin.cpp", MDIChild);
USERES("mdiapp.res");
USEFORM("about.cpp", AboutBox);
USEFORM("Frm_consuinv.cpp", Form_consuinv);
USEFORM("dmod.cpp", dm); /* TDataModule: File Type */
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
	Application->Initialize();
	Application->CreateForm(__classid(Tdm), &dm);
     Application->CreateForm(__classid(TMainForm), &MainForm);
     Application->Run();

	return 0;
}
//---------------------------------------------------------------------
