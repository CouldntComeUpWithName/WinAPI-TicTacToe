#include "Window.h"
#include"Game.h"
#include"utilities.h"
#include"Output_Stream.h"
#include<gdiplus.h>

using namespace Gdiplus;
#pragma comment (lib, "Gdiplus.lib")

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	
	switch (uMsg)
	{
	case WM_CLOSE:
		if (MessageBoxW(hwnd, L"Really quit?", L"TIC-TAC-TOE Message", MB_OKCANCEL) == IDOK)
		{
			DestroyWindow(hwnd);
		}
		return 0;
	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	case WM_PAINT:
	{
		PAINTSTRUCT ps;
		HDC whdc = BeginPaint(hwnd, &ps);
		
		FillRect(whdc, &ps.rcPaint, (HBRUSH)(COLOR_WINDOW + 1));
		
		/*Graphics gf(whdc);*/

		//Gdiplus::Graphics graphics(whdc);
		/*Pen pen(Color(255, 0, 200, 0));
		graphics.DrawLine(&pen, 0, 0, 200, 100);*/

		/*Gdiplus::Bitmap bitmap(L"E:\\Programming\\TicTacToeWinAPI\\TicTacToeWinAPI\\res\\button.png");
		graphics.DrawImage(&bitmap,0, 0);*/

		//graphics.DrawLine(&pen, 0, 0, 500, 300);

	/*	LineTo(whdc, 350, 450);
		for (int i = 0; i < 50; i++)
			for (int j = 0; j < 50; j++)
				SetPixel(whdc, i, j, RGB(255, 0, 255));*/

		//Rectangle(whdc, 550, 600, 650, 750);

		EndPaint(hwnd, &ps);
	}
	return 0;
	}

	return DefWindowProc(hwnd, uMsg, wParam, lParam);
}

Window::Window(WindowSize wSize, PCWSTR Name, HINSTANCE hInstance, WNDPROC WindowProc)
{
	winout << L"Window::Window(WindowSize wSize, PCWSTR Name, HINSTANCE hInstance)\n";
	
	this->cbSize = sizeof(WNDCLASSEX);
	this->lpszClassName = Name;
	this->hInstance = hInstance;
	this->lpfnWndProc = WindowProc;
	this->style = CS_VREDRAW | CS_HREDRAW;

	if (!RegisterClassEx(this))
	{
		winout << L"Class not Registered\n" << GetLastError() << '\n';
	}
	else
		winout << "Class Registered\n";

	HWindow = CreateWindowEx(WS_EX_CONTROLPARENT, Name, Name, WS_OVERLAPPEDWINDOW | WS_MAXIMIZE, 0, 0, wSize.x, wSize.y, nullptr, nullptr, hInstance, nullptr);

	if (!HWindow)
	{
		f_isOpen = false;
		winout << "Window " << Name << " wasn\'t Created\n";
	}
	else
	{
		f_isOpen = true;
		winout << "Window " << Name << " was Created\n";
	}
}

//Window::Window(const Window& wind)
//	: HWindow{wind.HWindow}, f_isOpen{wind.f_isOpen}
//{
//	wind.HWindow = nullptr;
//
//	this->cbClsExtra = wind.cbClsExtra;
//	this->cbWndExtra = wind.cbWndExtra;
//	
//	this->hbrBackground = wind.hbrBackground;
//	this->hCursor = wind.hCursor;
//	this->hIcon = wind.hIcon;
//	this->hInstance = wind.hInstance;
//	this->lpfnWndProc = wind.lpfnWndProc;
//	this->lpszClassName = wind.lpszClassName;
//	this->lpszMenuName = wind.lpszMenuName;
//	
//	this->style = wind.style;
//
//	this->cbClsExtra = 0;
//	this->cbWndExtra = 0;
//
//	this->hbrBackground = 0;
//	this->hCursor = 0;
//	this->hIcon = 0;
//	this->hInstance = 0;
//	this->lpfnWndProc = 0;
//	this->lpszClassName = 0;
//	this->lpszMenuName = 0;
//
//	this->style = 0;
//	//DestroyWindow(wind.HWindow);
//}

Window::Window(Window&& sourceWnd)noexcept
{
	PrintToConsole(L"Window(Window&& sourceWnd)noexcept\r\n");

	HWindow = sourceWnd.HWindow;
	sourceWnd.HWindow = nullptr;

	f_isOpen = sourceWnd.f_isOpen;
	sourceWnd.f_isOpen = false;

	this->lpszClassName = sourceWnd.lpszClassName;
	sourceWnd.lpszClassName = nullptr;
}

Window::~Window()
{
	winout << lpszMenuName << " - " << L"~Window()\n";

	if(HWindow)
		DestroyWindow(HWindow);
}

void WINAPI Window::SetIcon(HICON NewIcon)
{
	this->hIcon = NewIcon;
}

void WINAPI Window::SetCursor(HCURSOR NewCursor)
{
	this->hCursor = NewCursor;
	UpdateWindow(HWindow);
	//ShowWindow(HWindow, nCmdShow);
}

void WINAPI Window::SetBGColor(HBRUSH NewBGColor)
{
	this->hbrBackground = NewBGColor;
}

HWND WINAPI Window::GetHandle()
{
	return HWindow;
}

bool Window::isOpen()
{
	return f_isOpen;
}

void Window::Paint(const Game& game)
{

}

Window& Window::operator=(Window&& source) noexcept
{
	winout << L"Window& Window::operator=(Window&& source) noexcept\r\n";
	if (this != &source)
	{
		HWindow = source.HWindow;
		source.HWindow = nullptr;

		f_isOpen = source.f_isOpen;
		source.f_isOpen = false;
	}
	
	return *this;
}

WindowSize Window::GetFullScreen()
{
	return WindowSize{ GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN) };
}
