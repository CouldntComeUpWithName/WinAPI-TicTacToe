#pragma once
#include<windows.h>
#include"Window.h"
#include"Player.h"
#include"PlayBoard.h"
#include<gdiplus.h>

class Game
{
private:
	HINSTANCE m_hInstance;
	int nCmdShow;

	Window window;

	Gdiplus::GdiplusStartupInput gdiplusStartupInput;
	ULONG_PTR gdiplusToken;

	/*Player player1;
	Player player2;*/

	PlayBoard board;
public:
	Game() = default;
	Game(HINSTANCE hInstance, int nCmdShow);
	~Game()noexcept;
	void Run();

};

