#include "CallbackTimerHandlers.h"
#include "Block.h"
#include <GL/freeglut.h>

void playerUpdate(int te)
{
	myPlayer.movePlayer();
	glutTimerFunc(playerUpdatePeriod, playerUpdate, 1);
}
