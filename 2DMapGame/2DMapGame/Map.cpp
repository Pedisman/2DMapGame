#include "Map.h"

WallMap myWallMap(map);

template <typename T, int Tx, int Ty>
WallMap::WallMap(T (&inputArray) [Tx][Ty])
{
	for (int i = 0; i < Tx; ++i)
	{
		for (int j = 0; j < Ty; ++j)
		{
			if (map[i][j] == WALL_BLOCK)
			{
				blocks.push_back(WallBlock(i, j));
			}
		}
	}
}

void WallMap::drawMap() const
{
	for (auto itr = blocks.begin(); itr != blocks.end(); ++itr)
	{
		itr->drawBlock();
	}
}
