#ifndef BLOCK_h
#define BLOCK_h

#include "Defines.h"

class Block
{
protected:
	int width = windowWidth / xDim;
	int height = windowHeight / yDim;
	int topLeftX, topLeftY;
public:
	Block(int x, int y);
	virtual void drawBlock() const {}
	bool collision(const Block* inputBlock) const;

	virtual ~Block(){}
};

class WallBlock : public Block
{
public:
	WallBlock(int x, int y) : Block(x, y){}
	void drawBlock() const override;
};

#endif // BLOCK_h

