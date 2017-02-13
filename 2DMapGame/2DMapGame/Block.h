#ifndef BLOCK_h
#define BLOCK_h

#include "Defines.h"
#include <memory>

class Block
{
protected:
	int width = windowWidth / xDim;
	int height = windowHeight / yDim;
	int topLeftX, topLeftY;
public:
	int getTopLeftX() const;
	int getTopLeftY() const;
	int distanceBetween(const Block* inputBlock) const;

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

class PlayerBlock : public Block
{
	int speed = playerSpeed;
public:
	PlayerBlock(int x, int y) : Block(x, y){}
	void drawBlock() const override;
	void movePlayer();
};

class EnemyContext;

class EnemyBlock : public Block
{
	std::unique_ptr<EnemyContext> context;
	//EnemyContext* context;
	int speed = enemySpeed;
public:
	EnemyBlock(int x, int y) : Block(x, y){}
	void drawBlock() const override;
	void idleMove();
	void followPlayer(const Block* player);
	//~EnemyBlock();
};

// Player Block Init
extern PlayerBlock myPlayer;
extern EnemyBlock enemy1;

#endif // BLOCK_h

