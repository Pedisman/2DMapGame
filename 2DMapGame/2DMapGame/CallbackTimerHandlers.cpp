#include "CallbackTimerHandlers.h"
#include "Block.h"
#include <GL/freeglut.h>

void playerUpdate(int te)
{
	myPlayer.movePlayer();
	//enemy1.idleMove();
	enemy1.followPlayer(&myPlayer);
	glutTimerFunc(playerUpdatePeriod, playerUpdate, 1);
}
