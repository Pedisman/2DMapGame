#include <GL/freeglut.h>
#include "Defines.h"
#include "Map.h"
#include "KeyBoardHandlers.h"
#include "CallbackTimerHandlers.h"

static bool firstTime = true;

void render()
{
	static int offsetX;
	static int offsetY;

	if (firstTime)
	{
		offsetX = (windowWidth + myPlayer.getWidth()) / 2;
		offsetY = (windowHeight + myPlayer.getHeight()) / 2;
		firstTime = false;
	}

	glClear(GL_COLOR_BUFFER_BIT);
	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);
	glTranslated(screenScale*(myPlayer.getAccumulatedX()) - offsetX, screenScale*(myPlayer.getAccumulatedY()) - offsetY, 0);
	glScaled(screenScale, screenScale, 1); // zoom in so we are showing only a submap region
	// Call drawing functions in here
	myWallMap.drawMap();
	myPlayer.drawBlock();
	enemy1.drawBlock();

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