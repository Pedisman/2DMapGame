#ifndef STATE_h
#define STATE_h

class Block;

class State
{
public:
	virtual ~State();
	virtual void action(Block* inputBlock);
};

// Derived enemy state
class Idle : public State
{
public:
	void action(Block* inputBlock);
};

#endif // STATE_h