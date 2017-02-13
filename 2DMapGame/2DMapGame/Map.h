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

	virtual ~GameMap(){}
};

class WallMap : public GameMap
{
public:
	template <typename T, int Tx, int Ty>
	WallMap(T(&inputArray)[Tx][Ty]);
	~WallMap();
};

class EnemyMap : public GameMap
{
public:
	template <typename T, int Tx, int Ty>
	EnemyMap(T(&inputArray)[Tx][Ty]);

	void updateEnemies();

	~EnemyMap();
};

extern WallMap myWallMap;
extern EnemyMap myEnemyMap;

#endif // MAP_h