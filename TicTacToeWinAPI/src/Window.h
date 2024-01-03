#pragma once

#include<windows.h>
#include<functional>
//#include "Game.h"

class Game;

struct WindowSize
{
	int x;
	int y;
};

class Window : private WNDCLASSEX
{
private:
	HWND HWindow;

	bool f_isOpen;
public:
	Window() = delete;
	Window(WindowSize wSize, PCWSTR Name, HINSTANCE hInstance, WNDPROC windowProc = DefWindowProc);
	//Window(const Window& wind);
	Window(Window&& sourceWnd)noexcept;
	
	~Window();

	void WINAPI SetIcon(HICON NewIcon);
	void WINAPI SetCursor(HCURSOR NewCursor);
	void WINAPI SetBGColor(HBRUSH NewBGColor);
	void WINAPI SetTitle(PCWSTR NewTitle);
	
	void Paint(const Game&);

	Window& operator=(Window&& source)noexcept;

	HWND WINAPI GetHandle();
	bool isOpen();
	
	//LRESULT(CALLBACK *WindProc)(HWND, UINT, WPARAM, LPARAM);

	//std::function<LRESULT(HWND, UINT, WPARAM, LPARAM, ...)> WindProc;

	static WindowSize GetFullScreen();
	static Window GetFullScreenWindow();
private:
	void Show();
	
};

LRESULT CALLBACK WindowProc(HWND hwnd, UINT uMsg, WPARAM wParam, LPARAM lParam);
