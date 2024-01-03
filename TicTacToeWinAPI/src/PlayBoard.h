#pragma once
#include<windows.h>

class PlayBoard
{
public:
	PlayBoard();

	bool isFilled();

private:
	WCHAR area[3][3];
};

