#include "Map.h"

WallMap myWallMap(map);

template <typename T, int Ty, int Tx>
WallMap::WallMap(T (&inputArray) [Ty][Tx])
{
	for (int i = 0; i < Ty; ++i)
	{
		for (int j = 0; j < Tx; ++j)
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
