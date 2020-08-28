#ifndef GUICLASS_H
#define GUICLASS_H
#include <Windows.h>
#include "OpenFileButtonClass.h"

struct MWParams
{
	int width = 600;
	int height = 300;
	int xPos = (GetSystemMetrics(SM_CXSCREEN) - width) / 2;
	int yPos = (GetSystemMetrics(SM_CYSCREEN) - height) / 2;
};

struct AuxElemParams
{
	int wButton = 150;
	int hButton = 50;
	int wEdit1 = 350;
	int wEdit2 = 280;
	int hEdit = 30;
	int xPosButton1 = 220;
	int yPosButton = 200;
	int xPosButton2 = 420;
	int xPosRB = 30;
	int yPosRB1 = 50;
	int yPosRB2 = 120;
	int yPosRB3 = 190;
	int xPosEdit = 220;
	int xPosEdit2 = 440;
	int yPosEdit1 = 50;
	int yPosEdit2 = 120;
};

class MainWindow
{
public:
	MainWindow(_In_	HINSTANCE hInstance, _In_opt_ HINSTANCE hPrevInstance, _In_ PWSTR szCmdLine, _In_ int nCmdShow)
	{
		this->hInstance = hInstance;
		this->szCmdLine = szCmdLine;
		this->nCmdShow = nCmdShow;
		this->hPrevInstance = hPrevInstance;
	};
	int createWindow()
	{
		MSG msg{};
		HWND hwnd{};
		WNDCLASSEX wc{ sizeof(WNDCLASSEX) };
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(LTGRAY_BRUSH));
		wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
		wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
		wc.hInstance = hInstance;
		OpenFileWindow obj(hInstance, hPrevInstance, szCmdLine, nCmdShow);

		wc.lpfnWndProc = [](HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)->LRESULT
		{
			AuxElemParams aep;
			switch (uMsg)
			{

			case WM_CREATE:
			{
				HWND hButton1 = CreateWindow(
					L"BUTTON",
					L"OK",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					aep.xPosButton1, aep.yPosButton, aep.wButton, aep.hButton, hWnd,
					reinterpret_cast<HMENU>(1337),
					nullptr, nullptr
				);
				HWND hButton2 = CreateWindow(
					L"BUTTON",
					L"Отмена",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					aep.xPosButton2, aep.yPosButton, aep.wButton, aep.hButton, hWnd,
					reinterpret_cast<HMENU>(1338),
					nullptr, nullptr
				);
				HWND OpenFileButton = CreateWindow(
					L"BUTTON",
					L"...",
					WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
					510, 120, 50, 30, hWnd,
					reinterpret_cast<HMENU>(1336),
					nullptr, nullptr
				);
				HWND groupBox = CreateWindow(
					L"BUTTON",
					L"Шаблон",
					WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
					20, 20, 180, 230, hWnd,
					reinterpret_cast<HMENU>(1338),
					nullptr, nullptr
				);
				HWND rButton1 = CreateWindow(
					L"BUTTON",
					L"news.mail.ru",
					WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
					aep.xPosRB, aep.yPosRB1, aep.wButton, aep.hButton, hWnd,
					reinterpret_cast<HMENU>(1339),
					nullptr, nullptr
				);
				HWND rButton2 = CreateWindow(
					L"BUTTON",
					L"yandex.ru/news",
					WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
					aep.xPosRB, aep.yPosRB2, aep.wButton, aep.hButton, hWnd,
					reinterpret_cast<HMENU>(1440),
					nullptr, nullptr
				);
				HWND rButton3 = CreateWindow(
					L"BUTTON",
					L"news.google.com",
					WS_CHILD | WS_VISIBLE | BS_AUTORADIOBUTTON,
					aep.xPosRB, aep.yPosRB3, aep.wButton, aep.hButton, hWnd,
					reinterpret_cast<HMENU>(1441),
					nullptr, nullptr
				);
				HWND Edit1 = CreateWindow(
					L"Edit", 
					NULL,
					WS_CHILD | WS_VISIBLE | WS_BORDER,
					aep.xPosEdit, aep.yPosEdit1, aep.wEdit1, aep.hEdit, hWnd,
					reinterpret_cast<HMENU>(1442),
					NULL, NULL
				);
				HWND Edit2 = CreateWindow(
					L"Edit",
					NULL,
					WS_CHILD | WS_VISIBLE | WS_BORDER,
					aep.xPosEdit, aep.yPosEdit2, aep.wEdit2, aep.hEdit, hWnd,
					reinterpret_cast<HMENU>(1443),
					NULL, NULL
				);
				break;
			}
			return 0;

			case WM_COMMAND:
			{
				switch (LOWORD(wParam))
				{
				case 1337:
				{
					MessageBox(hWnd, L"DO", L"NE", MB_ICONINFORMATION);
				}
				break;
				case 1336:
				{
					//obj.createWindow();
				}
				break;
				}
			};
			return 0;

			case WM_DESTROY:
			{
				PostQuitMessage(EXIT_SUCCESS);
			}
			return 0;
			}
			return DefWindowProc(hWnd, uMsg, wParam, lParam);
		};
		wc.lpszClassName = L"MyAppClass";
		wc.lpszMenuName = nullptr;
		wc.style = CS_VREDRAW | CS_HREDRAW;
		MWParams mw;
		if (!RegisterClassEx(&wc))
			return EXIT_FAILURE;
		if (hwnd = CreateWindow(wc.lpszClassName, L"Заголовок", WS_OVERLAPPEDWINDOW, mw.xPos, mw.yPos, mw.width, mw.height, nullptr, nullptr, wc.hInstance, nullptr); hwnd == INVALID_HANDLE_VALUE)
			return EXIT_FAILURE;
		ShowWindow(hwnd, nCmdShow);
		UpdateWindow(hwnd);
		while (GetMessage(&msg, nullptr, 0, 0))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return static_cast<int>(msg.wParam);
	}
private:
	HINSTANCE hInstance;
	PWSTR szCmdLine; 
	int nCmdShow;
	HINSTANCE hPrevInstance;
};

#endif GUICLASS_H