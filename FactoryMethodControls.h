#ifndef CONTROLSCREATE_H
#define CONTROLSCREATE_H
#include "MainApp.h"
#include <windows.h>
#include <string>
#include <exception>
#include <stdexcept>
#include <iostream>
using std::wstring;

class Control
{
public:
	virtual ~Control() {}
	virtual HWND create(HWND hWndMain) = 0;
};

class ButtonOkControl : public Control
{
public:
	HWND create(HWND hWndMain) override
	{
			return hWndButtonOk = CreateWindowEx(
			0,
			L"BUTTON",
			L"OK",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			220, 200, 150, 50, hWndMain,
			OKBUTTON_ID,
			nullptr, nullptr
			);
	}
private:
	HWND hWndButtonOk{};
	HMENU OKBUTTON_ID;
};

class ButtonCancelControl : public Control
{
public:
	HWND create(HWND hWndMain) override
	{
		return hWndButtonCancel = CreateWindowEx(
			0,
			L"BUTTON",
			L"Отмена",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			420, 200, 150, 50, hWndMain,
			CANCELBUTTON_ID,
			nullptr, nullptr
		);
	}
private:
	HWND hWndButtonCancel{};
	HMENU CANCELBUTTON_ID;
};

class ButtonFileControl : public Control
{
public:
	HWND create(HWND hWndMain) override
	{
		return hWndButtonFile = CreateWindowEx(
			0,
			L"BUTTON",
			L"...",
			WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
			510, 120, 50, 30, hWndMain,
			OPENFILEBUTTON_ID,
			nullptr, nullptr
		);
	}
private:
	HWND hWndButtonFile{};
	HMENU OPENFILEBUTTON_ID;
};

class EditAdressControl : public Control
{
public:
	HWND create(HWND hWndMain) override
	{
		return hWndEditAdress = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			L"EDIT",
			L"https://www.vesti.ru/article/2458794",
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
			220, 50, 350, 30, hWndMain,
			EDITADDRESS_ID,
			nullptr, nullptr
		);
	}
private:
	HWND hWndEditAdress{};
	HMENU EDITADDRESS_ID;
};

class EditPathControl : public Control
{
public:
	HWND create(HWND hWndMain) override
	{
		DWORD result = GetModuleFileName(NULL, szPath, MAX_PATH);
		return hWndEditPath = CreateWindowEx(
			WS_EX_CLIENTEDGE,
			L"EDIT",
			szPath,
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL,
			220, 120, 280, 30, hWndMain,
			EDITPATH_ID,
			NULL, NULL
		);
	}
private:
	HWND hWndEditPath{};
	HMENU EDITPATH_ID;
	TCHAR szPath[MAX_PATH];
};

class Creator
{
public:
	virtual ~Creator() {};
	virtual Control* FactoryMethod() const = 0;
	//HWND createControl(HWND hWndMain) const {
	HWND createControl(HWND hWndMain) const {
		Control* obj = this->FactoryMethod();
		HWND result = obj->create(hWndMain);
		delete obj;
		return result;
	}
};

class ButtonOkCreator : public Creator
{
public:
	Control * FactoryMethod() const override
	{
		return new ButtonOkControl();
	}
};

class ButtonCancelCreator : public Creator
{
public:
	Control *FactoryMethod() const override
	{
		return new ButtonCancelControl();
	}
};

class ButtonFileCreator : public Creator
{
public:
	Control* FactoryMethod() const override
	{
		return new ButtonFileControl();
	}
};

class EditAdressCreator : public Creator
{
public:
	Control* FactoryMethod() const override
	{
		return new EditAdressControl();
	}
};

class EditPathCreator : public Creator
{
public:
	Control* FactoryMethod() const override
	{
		return new EditPathControl();
	}
};

#endif CONTROLSCREATE_H
