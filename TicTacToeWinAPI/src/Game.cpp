#include"Game.h"

Game::Game(HINSTANCE hInstance, int nCmdShow)
	:m_hInstance{hInstance}, nCmdShow{nCmdShow}, window(Window::GetFullScreen(), L"Window", m_hInstance, WindowProc),
	gdiplusToken{}, gdiplusStartupInput{}
{
	GdiplusStartup(&gdiplusToken, &gdiplusStartupInput, NULL);
	//Gdiplus::GdiplusStartup(NULL, NULL, NULL);
}

Game::~Game() noexcept
{
	Gdiplus::GdiplusShutdown(gdiplusToken);
}

void Game::Run()
{

	ShowWindow(window.GetHandle(), nCmdShow);
	UpdateWindow(window.GetHandle());

	//CreateWindowEx(WS_EX_CONTROLPARENT,L"button", L"Click Here", WS_VISIBLE | WS_CHILD, 10, 10, 100, 25, window.GetHandle(), nullptr, m_hInstance, nullptr);
	//CreateWindowExW(WS_EX_CONTROLPARENT,L"static", L"Button", WS_VISIBLE | WS_CHILD, 120, 120, 100, 20, window.GetHandle(), nullptr, m_hInstance, nullptr);
	
	HDC wDC = GetDC(window.GetHandle());

	HPEN pen = CreatePen(PS_SOLID, 3, RGB(0, 255, 0));

	MSG msg = { 0 };
	
	while (GetMessage(&msg, nullptr, 0, 0) > 0)
	{
		
		TranslateMessage(&msg);
		DispatchMessageW(&msg);
		//SendMessageW(window.GetHandle(), msg.message, msg.wParam, msg.lParam);
	}
	
	/*while (false)
	{
		try
		{
			window = Window(WindowSize{100, 100}, L"Tic-Tac-Toe WinAPI", m_hInstance);
		}
		catch (const wchar_t* exception)
		{
			MessageBoxW(NULL, exception, L"Error", MB_OK);
		}
		catch (...)
		{

		}
	}*/
}