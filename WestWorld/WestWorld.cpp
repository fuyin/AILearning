// WestWorld.cpp : 定义控制台应用程序的入口点。
//


#include "stdafx.h"
#include "Miner.h"
#include "cstdlib"
#include "windows.h"
#include "Common.h"
int main()
{
	Miner miner(0);
	for (int i = 0; i < 100; i++)
	{
		miner.Update();
		Sleep(2000);
	}
	int a;
	std::cin >> a;
    return 0;
}

