#include "Map.h"

WallMap myWallMap;
EnemyMap myEnemyMap;

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

template <typename T, int Tx, int Ty>
void GameMap::initMap(T(&inputArray)[Ty][Tx], int blockType, std::vector<Block*> &inputVec)
{
	inputVec.clear();
	switch(blockType)
	{
	case WALL_BLOCK:
		for (int i = 0; i < Ty; ++i)
		{
			for (int j = 0; j < Tx; ++j)
			{
				if (map[i][j] == WALL_BLOCK)
				{
					inputVec.push_back(new WallBlock(j, i));
				}
			}
		}
	case ENEMY_BLOCK:
		for (int i = 0; i < Ty; ++i)
		{
			for (int j = 0; j < Tx; ++j)
			{
				if (map[i][j] == ENEMY_BLOCK)
				{
					inputVec.push_back(new EnemyBlock(j, i));
				}
			}
		}
	}
}

// Wall Map definition

WallMap::WallMap()
{
	initMap(map, WALL_BLOCK, this->blocks);
}

WallMap::~WallMap()
{
	for (int i = 0; i < blocks.size(); ++i)
	{
		delete blocks[i];
	}
}

// Enemy Map

EnemyMap::EnemyMap()
{
	initMap(map, ENEMY_BLOCK, this->blocks);
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
