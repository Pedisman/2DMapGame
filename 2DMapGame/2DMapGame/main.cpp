#include <GL/freeglut.h>
#include "Defines.h"
#include "Map.h"
#include "KeyBoardHandlers.h"
#include "CallbackTimerHandlers.h"

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);
	glScaled(screenScale, screenScale, 0); // zoom in so we are showing only a submap regions
	glTranslated((myPlayer.getAccumulatedX()), (myPlayer.getAccumulatedY()), 0);
	// Call drawing functions in here
	myWallMap.drawMap();
	myPlayer.drawBlock();
	myEnemyMap.drawMap();

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	// Initialise standard glut parameters
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("2D Game Window");

	// Callback functions
	glutDisplayFunc(render);
	glutIdleFunc(render);

	// Register Keyboard Handlers
	glutKeyboardFunc(normalKeyHandler);
	glutSpecialFunc(keyPressHandler);
	glutSpecialUpFunc(keyReleaseHandler);

	// Callback timers
	glutTimerFunc(playerUpdatePeriod, playerUpdate, 1);

	// Initialise the loop
	glutMainLoop();

	return 0;
}