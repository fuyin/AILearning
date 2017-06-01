#include "MineOwnedState.h"
#include "Common.h"
#include "stdafx.h"
#include <iostream>
using std::cout;
using std::endl;


void EnterMineAndDigForNugget::Enter(Miner * pMiner)
{
	if (pMiner->GetLocation() != eGoldMine)
	{
		cout << pMiner->ID() << ":" << " walk to mine"<< endl;
	}
	pMiner->ChangeLocation(eGoldMine);
}

void EnterMineAndDigForNugget::Excute(Miner* pMiner)
{
	pMiner->AddToGoldCarried(1);
	pMiner->IncreaseFatigue();

	cout << pMiner->ID() << ":" << "dig a gold nugget"<< endl;

	if (pMiner->PocketsFull())
	{
		pMiner->ChangeState(VisitBankAndDepositGod::Instance());
	}

	if (pMiner->Thirsty())
	{
		pMiner->ChangeState(QuenchThirst::Instance());
	}
}

void EnterMineAndDigForNugget::Exit(Miner * pMiner)
{
	cout << pMiner->ID() << ":" << "leave mine" << endl;
}

EnterMineAndDigForNugget* EnterMineAndDigForNugget::Instance()
{
	static EnterMineAndDigForNugget instance;
	return &instance;
}


void VisitBankAndDepositGod::Enter(Miner * pMiner)
{
	if (pMiner->GetLocation() != eBank)
	{
		cout << pMiner->ID() << ":" << " walk to bank" << endl;
	}
	pMiner->ChangeLocation(eBank);
}

void VisitBankAndDepositGod::Excute(Miner* pMiner)
{
	pMiner->AddWealth(pMiner->GoldCarried());
	pMiner->SetGoldCarried(0);

	cout << pMiner->ID() << ":" << "desposit gold now" << endl;
	if (pMiner->Wealth() >= ComfortLevel)
	{
		pMiner->ChangeState(GoHomeAndSleepTilRested::Instance());
	}
	else
	{
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
}

void VisitBankAndDepositGod::Exit(Miner * pMiner)
{
	cout << pMiner->ID() << ":" << "leave bank" << endl;
}

VisitBankAndDepositGod* VisitBankAndDepositGod::Instance()
{
	static VisitBankAndDepositGod instance;
	return &instance;
}

void GoHomeAndSleepTilRested::Enter(Miner * pMiner)
{
	if (pMiner->GetLocation() != eHome)
	{
		cout << pMiner->ID() << ":" << " walk to home" << endl;
	}

	pMiner->ChangeLocation(eHome);
}

void GoHomeAndSleepTilRested::Excute(Miner* pMiner)
{
	if (!pMiner->Fatigued())
	{
		cout << pMiner->ID() << ":" << "It's time to find gold" << endl;
		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		pMiner->DecreaseFatigue();
		cout << pMiner->ID() << ":" << "ZZZZZZZZZZZZZZ..." << endl;
	}
}

void GoHomeAndSleepTilRested::Exit(Miner * pMiner)
{
	cout << pMiner->ID() << ":" << "leave home" << endl;
}

GoHomeAndSleepTilRested* GoHomeAndSleepTilRested::Instance()
{
	static GoHomeAndSleepTilRested instance;
	return &instance;
}

void QuenchThirst::Enter(Miner * pMiner)
{
	if (pMiner->GetLocation() != eSaloon)
	{
		cout << pMiner->ID() << ":" << " walk to saloon" << endl;
	}

	pMiner->ChangeLocation(eSaloon);
}

void QuenchThirst::Excute(Miner* pMiner)
{
	if (pMiner->Thirsty())
	{
		pMiner->BuyAndDrink();

		cout << pMiner->ID() << ":" << "drink water" << endl;

		pMiner->ChangeState(EnterMineAndDigForNugget::Instance());
	}
	else
	{
		cout << "error" << endl;
	}
}

void QuenchThirst::Exit(Miner * pMiner)
{
	cout << pMiner->ID() << ":" << "leave saloon" << endl;
}

QuenchThirst* QuenchThirst::Instance()
{
	static QuenchThirst instance;
	return &instance;
}