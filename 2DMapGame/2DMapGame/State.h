#ifndef STATE_h
#define STATE_h
#include "Block.h"

class Block;

class EnemyState
{
public:
	virtual ~EnemyState(){}
	virtual void action(EnemyBlock &inputBlock){}
};

class EnemyContext
{
	EnemyState* state;
public:
	EnemyContext();
	void updateState(EnemyBlock &inputBlock);
};

// Derived enemy states
class Idle : public EnemyState
{
public:
	void action(EnemyBlock &inputBlock) override;
};

class FollowPlayer : public EnemyState
{
public:
	void action(EnemyBlock &inputBlock) override;
};

// Single global state declarations
extern Idle idle;
extern FollowPlayer followPlayer;

#endif // STATE_h