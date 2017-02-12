#include "Block.h"
#include <GL/freeglut.h>

Block::Block(int x, int y)
{
	this->x = x;
	this->y = y;
}

void WallBlock::drawBlock()
{
	glBegin(GL_QUADS);
	glVertex2d(x*width, y*height);
	glVertex2d(x*width + width, y*height);
	glVertex2d(x*width + width, y*height + height);
	glVertex2d(x*width, y*height + height);
	glEnd();
}
