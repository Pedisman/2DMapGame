#include <GL/freeglut.h>
#include "Defines.h"
#include "Map.h"
#include "KeyBoardHandlers.h"

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);

	// Call drawing functions in here
	myWallMap.drawMap();
	myPlayer.drawBlock();

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
	glutFunc

	// Initialise the loop
	glutMainLoop();

	return 0;
}