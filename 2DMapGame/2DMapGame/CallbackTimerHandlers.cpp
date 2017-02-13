#include "CallbackTimerHandlers.h"
#include "Block.h"
#include <GL/freeglut.h>
#include "Map.h"

void playerUpdate(int te)
{
	myPlayer.movePlayer();
	//enemy1.performAction();
	myEnemyMap.updateEnemies();
	myPlayer.updateAccumulated();
	glutTimerFunc(playerUpdatePeriod, playerUpdate, 1);
}
