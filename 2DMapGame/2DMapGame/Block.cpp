#include "Block.h"
#include <GL/freeglut.h>
#include "Map.h"
#include "KeyBoardHandlers.h"
#include <math.h>
#include "State.h"

// Player Init definition
PlayerBlock myPlayer(10, 10);
EnemyBlock enemy1(1, 18);

// Block Abstract class function definitions

Block::Block(int x, int y)
{
	topLeftX = x * width;
	topLeftY = y * height;
}

int Block::getWidth() const
{
	return width;
}


int Block::getHeight() const
{
	return height;
}


int Block::getTopLeftX() const
{
	return topLeftX;
}

int Block::getTopLeftY() const
{
	return topLeftY;
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

int Block::distanceBetween(const Block* inputBlock) const
{
	double x = inputBlock->getTopLeftX() - topLeftX;
	double y = inputBlock->getTopLeftY() - topLeftY;
	return sqrt(pow(x, 2) + pow(y, 2));
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

PlayerBlock::PlayerBlock(int x, int y) : Block(x, y)
{
	lastX = topLeftX;
	lastY = topLeftY;
	
	double tempMultiplier = pow(2, screenScale);

	accumulatedX = -topLeftX + (windowWidth/ screenScale - width)/2;// +(windowWidth) / tempMultiplier;
	accumulatedY = -topLeftY + (windowHeight/ screenScale - width)/2;// +(windowHeight) / tempMultiplier;
}

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

void PlayerBlock::updateAccumulated()
{
	accumulatedX += lastX - topLeftX;
	accumulatedY += lastY - topLeftY;

	lastX = topLeftX;
	lastY = topLeftY;
}

int PlayerBlock::getAccumulatedX() const
{
	return accumulatedX;
}

int PlayerBlock::getAccumulatedY() const
{
	return accumulatedY;
}


// Derived enemy block class

EnemyBlock::EnemyBlock(int x, int y) : Block(x, y)
{
	context = std::make_unique<EnemyContext>();
}

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
	topLeftX += speed;
	if (myWallMap.collision(this))
	{
		speed = -speed;
		topLeftX += 2*speed;
	}
}

void EnemyBlock::followPlayer(const Block* player)
{
	int prevX = topLeftX;
	int prevY = topLeftY;

	int tempSpeed = (this->distanceBetween(player) > speed) ? speed : this->distanceBetween(player);

	double tempX = (player->getTopLeftX() - topLeftX);
	double tempY = (player->getTopLeftY() - topLeftY);

	// signbit returns true if negative
	int signX = signbit(tempX) ? -1 : 1;
	int signY = signbit(tempY) ? -1 : 1;

	if (tempX == 0)
	{
		topLeftY += signY * abs(tempSpeed);
		if (myWallMap.collision(this))
		{
			topLeftY = prevY;
		}
	}
	else if (tempY == 0)
	{
		topLeftX += signX * abs(tempSpeed);
		if (myWallMap.collision(this))
		{
			topLeftX = prevX;
		}
	}
	//else if (abs(tempY) <= abs(speed) + 1 && abs(tempX) <= abs(speed) + 1)
	else if (tempY == 0 && tempX == 0)
	{
		// doNothing
	}
	else
	{
		auto ratio = tempY / tempX;

		auto newX = tempSpeed / sqrt(1 + pow(ratio, 2));
		auto newY = ratio * newX;

		topLeftX += signX * abs(newX);
		if (myWallMap.collision(this))
		{
			topLeftX = prevX;
		}
		topLeftY += signY * abs(newY);
		if (myWallMap.collision(this))
		{
			topLeftY = prevY;
		}
	}

	if (this->collision(player))
	{
		topLeftX = prevX;
		topLeftY = prevY;
	}
}


void EnemyBlock::performAction()
{
	context->updateState(*this);
	context->action(*this);
}
