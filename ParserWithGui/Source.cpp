#include "GUIClass.h"

int CALLBACK wWinMain(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR szCmdLine, _In_ int nCmdShow)
{
	//MainWindow obj(hInstance, hPrevInstance, szCmdLine, nCmdShow);
	//obj.createWindow();	
	MainWindow obj(hInstance, hPrevInstance, szCmdLine, nCmdShow);
	obj.createWindow();
	//MainWindow obj(hInstance, hPrevInstance, szCmdLine, nCmdShow);
	//obj.createWindow();
}