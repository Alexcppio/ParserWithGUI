#ifndef GUI_H
#define GUI_H
#include "../CurlModule/CurlTransfer.h"
#include "Analyzer.h"
#include <windows.h>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
using std::wstring;

class MainApp
{
	enum class ControlsID
	{
		OKBUTTON_ID,
		CANCELBUTTON_ID,
		OPENFILEBUTTON_ID,
		GROUPBOX_ID,
		RADIOBUTTON1_ID,
		RADIOBUTTON2_ID,
		RADIOBUTTON3_ID,
		EDITADDRESS_ID,
		EDITPATH_ID
	};
public:
	MainApp();

	int run();

private:
	void initAppWindow();
	static LRESULT CALLBACK staticWindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
	LRESULT CALLBACK dynamicWindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

	void createControls();

private:
	const std::wstring windowTitle{ L"Bin-VV" }, windowClassId{ L"Bin-VV_Window_class_nostyles" };
	HWND hWndMain{}, hWndButtonOk{}, hWndButtonCancel{}, hWndGroupbox{}, hWndButtonFile{},
		hWndRadio1{}, hWndRadio2{}, hWndRadio3{}, hWndEditAdress{}, hWndEditPath{};
	const int appWidth{ 600 }, appHeight{ 300 };
	string sourceText;
};

#endif GUI_H
