#ifndef MAP_h
#define MAP_h

#include "Defines.h"
#include "Block.h"
#include <vector>

class WallMap
{
	std::vector<WallBlock> blocks;
public:
	template <typename T, int Tx, int Ty>
	WallMap(T(&inputArray)[Tx][Ty]);

	void drawMap() const;
};

extern WallMap myWallMap;

#endif // MAP_h