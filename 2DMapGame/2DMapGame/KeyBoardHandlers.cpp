#include "KeyBoardHandlers.h"
#include "Defines.h"
#include <iostream>

void normalKeyHandler(unsigned char key, int x, int y)
{
	if (key == ESCAPE_KEY)
	{
		exit(0);
	}
}

void keyPressHandler(int key, int x, int y)
{
	if (key == LEFT_KEY)
	{
		pressedKeys[LEFT] = true;
	}
	else if (key == UP_KEY)
	{
		pressedKeys[UP] = true;
	}
	else if (key == RIGHT_KEY)
	{
		pressedKeys[RIGHT] = true;
	}
	else if (key == DOWN_KEY)
	{
		pressedKeys[DOWN] = true;
	}
}

void keyReleaseHandler(int key, int x, int y)
{
	if (key == LEFT_KEY)
	{
		pressedKeys[LEFT] = false;
	}
	else if (key == UP_KEY)
	{
		pressedKeys[UP] = false;
	}
	else if (key == RIGHT_KEY)
	{
		pressedKeys[RIGHT] = false;
	}
	else if (key == DOWN_KEY)
	{
		pressedKeys[DOWN] = false;
	}
}