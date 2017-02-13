#include "Block.h"
#include <GL/freeglut.h>

Block::Block(int x, int y)
{
	topLeftX = x * width;
	topLeftY = y * height;
}

bool Block::collision(const Block* inputBlock) const
{
	return (this->x == inputBlock->x && this->y == inputBlock->y);
}


void WallBlock::drawBlock() const
{
	glBegin(GL_QUADS);
	glColor3d(wallBlockColor[0], wallBlockColor[1], wallBlockColor[2]);
	glVertex2d(topLeftX, topLeftY);
	glVertex2d(topLeftX + width, topLeftY);
	glVertex2d(topLeftX + width, topLeftY + height);
	glVertex2d(topLeftX, topLeftY + height);
	glEnd();
}
