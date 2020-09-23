#include "MainApp.h"

void clientCode(const Creator& creator, HWND hWndMain)
{
	creator.createControl(hWndMain);
}

//Main window

MainApp::MainApp()
{
	using std::wstring;
	using std::string;

	try
	{
		this->initAppWindow();
		this->createControls();
	}
	catch (const std::exception & e)
	{
		string expData = e.what();
		MessageBox(nullptr, wstring(begin(expData), end(expData)).c_str(), L"Ошибка", MB_ICONERROR | MB_OK);
		ExitProcess(EXIT_FAILURE);
	}
}

int MainApp::run()
{
	MSG msg{};
	ShowWindow(this->hWndMain, SW_SHOWDEFAULT);
	UpdateWindow(this->hWndMain);
	while (GetMessage(&msg, nullptr, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return static_cast<int>(msg.wParam);
}

void MainApp::initAppWindow()
{
	using std::runtime_error;
	using namespace std::string_literals;

	WNDCLASSEX _wc{ sizeof(WNDCLASSEX) };
	_wc.cbClsExtra = 0;
	_wc.cbWndExtra = 0;
	_wc.hbrBackground = reinterpret_cast<HBRUSH>(GetStockObject(LTGRAY_BRUSH));
	_wc.hCursor = LoadCursor(nullptr, IDC_ARROW);
	_wc.hIcon = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hIconSm = LoadIcon(nullptr, IDI_APPLICATION);
	_wc.hInstance = GetModuleHandle(nullptr);
	_wc.lpfnWndProc = MainApp::staticWindowProcedure;
	_wc.lpszClassName = this->windowTitle.c_str();
	_wc.lpszMenuName = nullptr;
	_wc.style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(&_wc))
		throw runtime_error("Error, cannot register main window class."s);

	RECT windowRC{ 0, 0, this->appWidth, this->appHeight };
	AdjustWindowRect(&windowRC, WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZE, false);

	if (this->hWndMain = CreateWindowEx(
		0,
		this->windowTitle.c_str(),
		this->windowClassId.c_str(),
		WS_DLGFRAME | WS_SYSMENU | WS_MINIMIZEBOX | WS_MAXIMIZE,
		(GetSystemMetrics(SM_CXSCREEN) - windowRC.right) / 2,
		(GetSystemMetrics(SM_CYSCREEN) - windowRC.bottom) / 2,
		windowRC.right, windowRC.bottom, nullptr, nullptr, nullptr, this
	); !this->hWndMain)
		throw runtime_error("Error, cannot create main window."s);
}

LRESULT MainApp::staticWindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	MainApp* pApp;
	if (uMsg == WM_NCCREATE)
	{
		pApp = static_cast<MainApp*>(reinterpret_cast<CREATESTRUCT*>(lParam)->lpCreateParams);
		SetLastError(0);
		if (!SetWindowLongPtr(hWnd, GWLP_USERDATA, reinterpret_cast<LONG_PTR>(pApp)))
		{
			if (GetLastError() != 0)
				return false;
		}
	}
	else
	{
		pApp = reinterpret_cast<MainApp*>(GetWindowLongPtr(hWnd, GWLP_USERDATA));
	}

	if (pApp)
	{
		pApp->hWndMain = hWnd;
		return pApp->dynamicWindowProcedure(hWnd, uMsg, wParam, lParam);
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

LRESULT MainApp::dynamicWindowProcedure(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch (uMsg)
	{
	case WM_COMMAND:
	{
		switch (static_cast<MainApp::ControlsID>(LOWORD(wParam)))
		{
		case MainApp::ControlsID::OKBUTTON_ID:
		{
			try
			{
				std::wstring wide{};
				wide.resize(MAX_PATH);
				GetWindowText(this->hWndEditAdress, &wide[0], MAX_PATH);
				string adressHttps(wide.begin(), wide.end());

				if (adressHttps.empty())
				{
					MessageBox(this->hWndMain, L"Ââåäèòå àäðåñ", L"Èíôîðìàöèÿ", MB_ICONINFORMATION | MB_OK);
					break;
				}

				std::wstring wide2{};
				wide2.resize(MAX_PATH);
				GetWindowText(this->hWndEditPath, &wide2[0], MAX_PATH);
				string adressSavePath(wide2.begin(), wide2.end());

				if (adressSavePath.empty())
				{
					MessageBox(this->hWndMain, L"Ââåäèòå ïóòü", L"Èíôîðìàöèÿ", MB_ICONINFORMATION | MB_OK);
					break;
				}
				//////// Create textSource and lexem template /////////////
				setlocale(LC_ALL, "Russian");
				initCurl(this->sourceText, adressHttps);
				LexemsChoose lexemObj(adressHttps);
				lexemObj.createChoosenLexem();

				//////// Analyze ////////////
				Analyzer analObj(this->sourceText, lexemObj.returnChoosenLexems());
				analObj.makeArticle();

				/////// Save ////////////
				
				analObj.Analyzer::save(adressSavePath);
				ShellExecute(0, L"open", L"test.txt", NULL, 0, SW_SHOWNORMAL);

			}
			catch (...)
			{
				MessageBox(this->hWndMain, L"Неверный формат адреса", L"Предупреждение", MB_ICONWARNING | MB_OK);
			}
		}
		break;

		case MainApp::ControlsID::OPENFILEBUTTON_ID:
		{
			OPENFILENAME ofn;
			TCHAR szFile[MAX_PATH];
			ZeroMemory(&ofn, sizeof(ofn));
			ofn.lStructSize = sizeof(ofn);
			ofn.lpstrFile = szFile;
			ofn.lpstrFile[0] = '\0';
			ofn.hwndOwner = hWndMain;
			ofn.nMaxFile = sizeof(szFile);
			ofn.lpstrFilter = TEXT("All files(*.*)\0*.*\0");
			ofn.nFilterIndex = 1;
			ofn.lpstrInitialDir = NULL;
			ofn.lpstrFileTitle = NULL;
			ofn.Flags = OFN_PATHMUSTEXIST | OFN_FILEMUSTEXIST;
			if (GetSaveFileName(&ofn))
			{
				HANDLE hFile;
				DWORD dwSize;
				DWORD dw;
				LPBYTE lpBuffer = NULL;
				hFile = CreateFile(szFile, GENERIC_READ, 0, NULL, OPEN_EXISTING, 0, NULL);
				dwSize = GetFileSize(hFile, NULL);
				lpBuffer = (LPBYTE)HeapAlloc(GetProcessHeap(), HEAP_GENERATE_EXCEPTIONS, dwSize + 1);
				ReadFile(hFile, (LPWSTR)lpBuffer, dwSize, &dw, NULL);
				CloseHandle(hFile);
				lpBuffer[dwSize] = 0;
				SetWindowText(hWndEditPath, (LPWSTR)lpBuffer);
				HeapFree(GetProcessHeap(), 0, lpBuffer);
			}
		}
		break;

		case MainApp::ControlsID::CANCELBUTTON_ID:
		{
			PostQuitMessage(EXIT_SUCCESS);
		}
		break;
	}
	}
	return 0;

	case WM_DESTROY:
	{
		PostQuitMessage(EXIT_SUCCESS);
	}
	return 0;
	}
	return DefWindowProc(hWnd, uMsg, wParam, lParam);
}

void MainApp::createControls()
{
	using std::runtime_error;
	using namespace std::string_literals;

	Creator *creator1 = new ButtonOkCreator();
	clientCode(*creator1, hWndMain);
	Creator *creator2 = new ButtonCancelCreator();
	clientCode(*creator2, hWndMain);
	Creator *creator3 = new ButtonFileCreator();
	clientCode(*creator3, hWndMain);
	Creator *creator4 = new EditAdressCreator();
	clientCode(*creator4, hWndMain);
	Creator *creator5 = new EditPathCreator();
	clientCode(*creator5, hWndMain);

	delete creator1;
	delete creator2;
	delete creator3;
	delete creator4;
	delete creator5;
}