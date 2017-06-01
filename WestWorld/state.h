#pragma once

class Miner;
class State {
public:
	virtual ~State(){}

	virtual void Enter(Miner *) = 0;

	virtual void Excute(Miner *) = 0;
	
	virtual void Exit(Miner *) = 0;
};