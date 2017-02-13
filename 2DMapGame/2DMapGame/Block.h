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
	int getHeight() const;
	int getWidth() const;
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
	int accumulatedX, accumulatedY;
	int lastX, lastY;
public:
	PlayerBlock(int x, int y);
	void drawBlock() const override;
	void movePlayer();
	void updateAccumulated();
	int getAccumulatedX() const;
	int getAccumulatedY() const;
};

class EnemyContext;

class EnemyBlock : public Block
{
	// Referenced object is declared on stack so don't need to manually delete
	std::unique_ptr<EnemyContext> context;
	int speed = enemySpeed;
public:
	EnemyBlock(int x, int y);
	void drawBlock() const override;
	void idleMove();
	void followPlayer(const Block* player);
	void performAction();
};

// Player Block Init
extern PlayerBlock myPlayer;
extern EnemyBlock enemy1;

#endif // BLOCK_h

