#include "State.h"
#include "Block.h"

// Global State initialisations
Idle idle;
FollowPlayer followPlayer;

Idle::Idle()
{
	strncpy_s(name, "Idle", 20);
}


void Idle::action(EnemyBlock &inputBlock)
{
	inputBlock.idleMove();
}

FollowPlayer::FollowPlayer()
{
	strncpy_s(name, "FollowPlayer", 20);
}


void FollowPlayer::action(EnemyBlock& inputBlock)
{
	inputBlock.followPlayer(&myPlayer);
}

// Enemy Context state class

EnemyContext::EnemyContext()
{
	state = &idle;
}

void EnemyContext::updateState(EnemyBlock &inputBlock)
{
	if (inputBlock.distanceBetween(&myPlayer) <= detectionRange)
	{
		this->state = &followPlayer;
	}
	else
	{
		this->state = &idle;
	}
}

void EnemyContext::action(EnemyBlock &inputBlock) const
{
	state->action(inputBlock);
}
