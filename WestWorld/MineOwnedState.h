#pragma once

#include "state.h"
#include "Miner.h"

#define PRIVATECON(T) T(){} \
	T(const T&);			
class EnterMineAndDigForNugget : public State {
private:
	PRIVATECON(EnterMineAndDigForNugget)
public:
	void Enter(Miner* );
	void Excute(Miner*);
	void Exit(Miner *);

	static EnterMineAndDigForNugget* Instance();
};

class VisitBankAndDepositGod : public State {
private:
	PRIVATECON(VisitBankAndDepositGod)
public:
	void Enter(Miner*);
	void Excute(Miner*);
	void Exit(Miner *);

	static VisitBankAndDepositGod* Instance();
};

class GoHomeAndSleepTilRested : public State {
private:
	PRIVATECON(GoHomeAndSleepTilRested)
	public:
		void Enter(Miner*);
		void Excute(Miner*);
		void Exit(Miner *);

		static GoHomeAndSleepTilRested* Instance();

};

class QuenchThirst :public State {
private:
	PRIVATECON(QuenchThirst)
public:
	void Enter(Miner*);
	void Excute(Miner*);
	void Exit(Miner *);

	static QuenchThirst* Instance();

};