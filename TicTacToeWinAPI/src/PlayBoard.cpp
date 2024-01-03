#include "PlayBoard.h"

PlayBoard::PlayBoard()
	: area{}
{ }

bool PlayBoard::isFilled()
{
	for(int i = 0; i< 3; i++)
		for (int j = 0; j < 3; j++)
			if (area[i][j] == 0)
				return false;

	return true;
}
