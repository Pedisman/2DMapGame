#ifndef STATE_h
#define STATE_h
#include "Block.h"

class Block;

class EnemyState
{
protected:
	char name[20] = {'\0'};
public:
	virtual ~EnemyState(){}
	virtual void action(EnemyBlock &inputBlock){}
};

class EnemyContext
{
	// Don't need to worry about deleting this memory as referenced states are global definitions on the stack
	EnemyState* state;
public:
	EnemyContext();
	void updateState(EnemyBlock &inputBlock);
	void action(EnemyBlock &inputBlock) const;
};

// Derived enemy states
class Idle : public EnemyState
{
public:
	Idle();
	void action(EnemyBlock &inputBlock) override;
};

class FollowPlayer : public EnemyState
{
public:
	FollowPlayer();
	void action(EnemyBlock &inputBlock) override;
};

// Single global state declarations
extern Idle idle;
extern FollowPlayer followPlayer;

#endif // STATE_h