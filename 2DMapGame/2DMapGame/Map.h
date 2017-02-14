#ifndef MAP_h
#define MAP_h

#include "Defines.h"
#include "Block.h"
#include <vector>

class GameMap
{
protected:
	std::vector<Block*> blocks;
public:
	bool collision(Block* inputBlock);

	void drawMap() const;

	template <typename T, int Tx, int Ty>
	void initMap(T(&inputArray)[Ty][Tx], int blockType, std::vector<Block*> &inputVec);

	virtual ~GameMap(){}
};

class WallMap : public GameMap
{
public:
	WallMap();
	~WallMap();
};

class EnemyMap : public GameMap
{
public:
	EnemyMap();

	void updateEnemies();

	~EnemyMap();
};

extern WallMap myWallMap;
extern EnemyMap myEnemyMap;

#endif // MAP_h