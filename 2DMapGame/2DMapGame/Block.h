#ifndef BLOCK_h
#define BLOCK_h

#include "Defines.h"

class Block
{
protected:
	int width = windowWidth / xDim;
	int height = windowHeight / yDim;
	int x, y;
public:
	Block(int x, int y);
	virtual void drawBlock(){}

	virtual ~Block(){}
};

class WallBlock : public Block
{
public:
	void drawBlock() override;
};

#endif // BLOCK_h

