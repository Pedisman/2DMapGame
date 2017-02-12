#include "KeyBoardHandlers.h"
#include "Defines.h"
#include <iostream>

void normalKeyHandler(unsigned char key, int x, int y)
{
	if (key == ESCAPE)
	{
		exit(0);
	}
}