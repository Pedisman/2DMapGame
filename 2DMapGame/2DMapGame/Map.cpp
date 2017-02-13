#include "Map.h"

WallMap myWallMap(map);
EnemyMap myEnemyMap(map);

void GameMap::drawMap() const
{
	//for (auto itr = blocks.begin(); itr != blocks.end(); ++itr)
	for (int i = 0; i < blocks.size(); ++i)
	{
		blocks[i]->drawBlock();
	}
}

bool GameMap::collision(Block* inputBlock)
{
	for (int i = 0 ; i < blocks.size(); ++i)
	{
		if (blocks[i]->collision(inputBlock))
		{
			return true;
		}
	}
	return false;
}

// Wall Map definition

template <typename T, int Ty, int Tx>
WallMap::WallMap(T(&inputArray)[Ty][Tx])
{
	for (int i = 0; i < Ty; ++i)
	{
		for (int j = 0; j < Tx; ++j)
		{
			if (map[i][j] == WALL_BLOCK)
			{
				blocks.push_back(new WallBlock(j, i));
			}
		}
	}
}

WallMap::~WallMap()
{
	for (int i = 0; i < blocks.size(); ++i)
	{
		delete blocks[i];
	}
}

// Enemy Map

template <typename T, int Ty, int Tx>
EnemyMap::EnemyMap(T(&inputArray)[Ty][Tx])
{
	for (int i = 0; i < Ty; ++i)
	{
		for (int j = 0; j < Tx; ++j)
		{
			if (map[i][j] == ENEMY_BLOCK)
			{
				blocks.push_back(new EnemyBlock(j, i));
			}
		}
	}
}

EnemyMap::~EnemyMap()
{
	for (int i = 0; i < blocks.size(); ++i)
	{
		delete blocks[i];
	}
}

void EnemyMap::updateEnemies()
{
	for (int i = 0; i < blocks.size(); ++i)
	{
		static_cast<EnemyBlock*>(blocks[i])->performAction();
	}
}
