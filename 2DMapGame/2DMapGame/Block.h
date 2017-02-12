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
	virtual ~Block(){}
};

#endif // BLOCK_h

