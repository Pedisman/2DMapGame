#include "Block.h"
#include <GL/freeglut.h>
#include "Map.h"
#include "KeyBoardHandlers.h"
#include <math.h>

// Player Init definition
PlayerBlock myPlayer(10, 10);
EnemyBlock enemy1(1, 18);

// Block Abstract class function definitions

Block::Block(int x, int y)
{
	topLeftX = x * width;
	topLeftY = y * height;
}

bool Block::collision(const Block* inputBlock) const
{
	if (topLeftX >= inputBlock->topLeftX + inputBlock->width ||
		topLeftX + width <= inputBlock->topLeftX || 
		topLeftY >= inputBlock->topLeftY + inputBlock->height || 
		topLeftY + height <= inputBlock->topLeftY)
	{
		return false;
	}
	return true;
}

// Wall Block function definitions

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

// Player Block function definitions

void PlayerBlock::drawBlock() const
{
	glBegin(GL_QUADS);
	glColor3d(playerBlockColor[0], playerBlockColor[1], playerBlockColor[2]);
	glVertex2d(topLeftX, topLeftY);
	glVertex2d(topLeftX + width, topLeftY);
	glVertex2d(topLeftX + width, topLeftY + height);
	glVertex2d(topLeftX, topLeftY + height);
	glEnd();
}

void PlayerBlock::movePlayer()
{
	int tempSpeed = (numKeysPressed() > 1) ? speed/sqrt(2) : speed;
	int prevX = topLeftX;
	int prevY = topLeftY;

	if (pressedKeys[LEFT])
	{
		topLeftX -= tempSpeed;
		if (myWallMap.collision(this))
		{
			topLeftX += tempSpeed;
		}
	}
	if (pressedKeys[UP])
	{
		topLeftY -= tempSpeed;
		if (myWallMap.collision(this))
		{
			topLeftY += tempSpeed;
		}
	}
	if (pressedKeys[RIGHT])
	{
		topLeftX += tempSpeed;
		if (myWallMap.collision(this))
		{
			topLeftX -= tempSpeed;
		}
	}
	if (pressedKeys[DOWN])
	{
		topLeftY += tempSpeed;
		if (myWallMap.collision(this))
		{
			topLeftY -= tempSpeed;
		}
	}
}

// Derived enemy block class

void EnemyBlock::drawBlock() const
{
	glBegin(GL_QUADS);
	glColor3d(enemyBlockColor[0], enemyBlockColor[1], enemyBlockColor[2]);
	glVertex2d(topLeftX, topLeftY);
	glVertex2d(topLeftX + width, topLeftY);
	glVertex2d(topLeftX + width, topLeftY + height);
	glVertex2d(topLeftX, topLeftY + height);
	glEnd();
}

void EnemyBlock::idleMove()
{
	if (myWallMap.collision(this))
	{
		speed = -speed;
	}
	topLeftX += speed;
}

void EnemyBlock::followPlayer()
{
	
}
