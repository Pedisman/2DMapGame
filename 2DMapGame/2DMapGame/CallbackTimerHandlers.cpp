#include "CallbackTimerHandlers.h"
#include "Block.h"
#include <GL/freeglut.h>
#include "Map.h"

void playerUpdate(int te)
{
	myPlayer.movePlayer();
	myEnemyMap.updateEnemies();
	myPlayer.updateAccumulated();
	glutTimerFunc(playerUpdatePeriod, playerUpdate, 1);
}
