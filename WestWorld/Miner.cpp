#pragma once
#include "Miner.h"
#include "MineOwnedState.h"
#include "Common.h"
using std::cout;
Miner::Miner(int id):BaseGameEntity(id),
					m_Location(eHome),
					m_iGoldCarried(0),
					m_iMoneyInBank(0),
					m_iThirst(0),
					m_iFatigue(0),
					m_pCurrentState(GoHomeAndSleepTilRested::Instance())
{
}

Miner::~Miner()
{
}

void Miner::Update()
{
	assert(m_pCurrentState);
	m_iThirst += 1;
	if (m_pCurrentState)
	{
		m_pCurrentState->Excute(this);
	}
}

void Miner::ChangeState(State *pNewState)
{
	assert(m_pCurrentState && pNewState);
	m_pCurrentState->Exit(this);

	m_pCurrentState = pNewState;

	m_pCurrentState->Enter(this);

}

void Miner::AddWealth(const int  val)
{
	m_iMoneyInBank += val;
	if (m_iMoneyInBank < 0)
	{
		m_iMoneyInBank = 0;
	}
}

void Miner::AddToGoldCarried(const int val)
{
	m_iGoldCarried += val;
	if (m_iGoldCarried < 0)
	{
		m_iGoldCarried = 0;
	}
}

bool Miner::Thirsty() const
{
	return m_iThirst >= ThirstLevel;
}

