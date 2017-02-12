#include <GL/freeglut.h>
#include "Defines.h"

void render()
{
	glClear(GL_COLOR_BUFFER_BIT);

	glLoadIdentity();
	gluOrtho2D(0, windowWidth, windowHeight, 0);

	// Call drawing functions in here

	glutSwapBuffers();
}

int main(int argc, char** argv)
{
	glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
	glutInitWindowPosition(100, 100);
	glutInitWindowSize(640, 640);
	glutCreateWindow("2D Game Window");

	// Callback functions
	glutDisplayFunc(render);
	glutIdleFunc(render);

	glutMainLoop();

	return 0;
}