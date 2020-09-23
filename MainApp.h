#ifndef GUI_H
#define GUI_H
#include "../CurlModule/CurlTransfer.h"
#include "Analyzer.h"
#include "LexemsStructs.h"
#include "FactoryMethodControls.h"
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
	string sourceText;
private:
	const std::wstring windowTitle{ L"Bin-VV" }, windowClassId{ L"Bin-VV_Window_class_nostyles" };
	HWND hWndMain{}, hWndButtonOk{}, hWndButtonCancel{}, hWndButtonFile{}, hWndEditAdress{}, hWndEditPath{};
	const int appWidth{ 600 }, appHeight{ 300 };
	int index;
	vector<pair<string, string>> lexems;
};

#endif GUI_H
