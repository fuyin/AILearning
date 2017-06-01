#pragma once

#include "BaseGameEntity.h"
#include "Locations.h"


class State;


//the amount of gold a miner must have before he feels comfortable
const int ComfortLevel = 5;
//the amount of nuggets a miner can carry
const int MaxNuggets = 3;
//above this value a miner is thirsty
const int ThirstLevel = 5;
//above this value a miner is sleepy
const int TirednessThreshold = 5;

class Miner : public BaseGameEntity
{
public:
	Miner(int id);
	~Miner();

	LocationType		GetLocation() { return m_Location; }
	void				ChangeState(State *);
	void				ChangeLocation(LocationType loc) { m_Location = loc; }
	void				Update();

	int GoldCarried() const {	return m_iGoldCarried;	}
	void SetGoldCarried(const int val) { m_iGoldCarried = val; }
	void AddToGoldCarried(const int val);
	bool PocketsFull() { return m_iGoldCarried >= MaxNuggets; }


	int Wealth() const { return m_iMoneyInBank; }
	void AddWealth(const int val);
	void SetWealth(const int val) { m_iMoneyInBank = val; }


	void          DecreaseFatigue() { m_iFatigue -= 1; }
	void          IncreaseFatigue() { m_iFatigue += 1; }
	bool Fatigued()const {
		return m_iFatigue > TirednessThreshold;
	}

	bool Thirsty() const;
	void BuyAndDrink() { m_iThirst = 0; m_iMoneyInBank -= 2; }

	
private:
	State * m_pCurrentState;
	
	LocationType m_Location;

	int m_iGoldCarried;

	int m_iMoneyInBank;

	int m_iThirst;

	int m_iFatigue;
};
