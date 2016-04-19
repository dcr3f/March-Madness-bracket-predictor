#include "BracketCalculator.h"



void BracketCalculator::LoadTeams()
{
	ifstream in;
	in.open("TeamData.txt");
	TeamDatabase* team;
	string name;
	int gameNum, round, seed, rankRPI, rankBPI, vsTopWin, vsTopLoss,
		lastTwelveWin, lastTwelveLoss;
	float PPG, oPPG;
	while(!in.eof())
	{
		in >> name >> gameNum >> round >> seed >> rankRPI >> rankBPI
			>> vsTopWin >> vsTopLoss >> lastTwelveWin >> lastTwelveLoss
			>> PPG >> oPPG;
		team = new TeamDatabase(name, gameNum, round, seed, rankRPI, rankBPI, vsTopWin,
			vsTopLoss, lastTwelveWin, lastTwelveLoss, PPG, oPPG);
		myList.Insert(team);
	}

}

void BracketCalculator::PrintTeams()
{
	myList.PrintList();
}

void BracketCalculator::CalculateTeamWinIndex()
{
	double winIndex = 0.0;
	list<TeamDatabase*> templist = myList.getList();
	list<TeamDatabase*>::iterator iter;

	for (iter = templist.begin(); iter != templist.end(); iter++)
	{
		int seed = (*iter)->getSeed();
		int RPI = (*iter)->getRPI();
		int BPI = (*iter)->getBPI();
		int topWin = (*iter)->getTopWin();
		int topLoss = (*iter)->getTopLoss();
		int twelveWin = (*iter)->getTwelveWin();
		int twelveLoss = (*iter)->getTwelveLoss();
		double PPG = (*iter)->getPPG();
		double oPPG = (*iter)->getOPPG();

		if (RPI <= 25 && RPI != 0)
		{
			winIndex = winIndex + 2.5 + ((double)twelveWin*2.5 - (double)twelveLoss/2.5) ;

		}
		if (RPI > 25 && RPI <= 50)
		{
			winIndex = winIndex + 2.0 + ((double)twelveWin*2.0 - (double)twelveLoss/2.0);
		}
		if (RPI > 50 && RPI <= 75)
		{
			winIndex = winIndex + 1.0 + ((double)twelveWin - (double)twelveLoss);
		}
		if (RPI > 75 && RPI <= 100)
		{
			winIndex = winIndex + 0.5 + ((double)twelveWin*0.5 - (double)twelveLoss/0.5);
		}
		if (BPI <= 25 && BPI != 0)
		{
			winIndex = winIndex + 4.0 + ((double)twelveWin*4.0 - (double)twelveLoss / 4.0);
		}
		if (BPI > 25 && BPI <= 50)
		{
			winIndex = winIndex + 3.0 + ((double)twelveWin*3.0 - (double)twelveLoss / 3.0);
		}
		if (BPI > 50 && BPI <= 75)
		{
			winIndex = winIndex + 1.0 + ((double)twelveWin - (double)twelveLoss);
		}
		if (BPI > 75 && BPI <= 100)
		{
			winIndex = winIndex + 0.5 + ((double)twelveWin*0.5 - (double)twelveLoss / 0.5);
		}
		winIndex = winIndex + (double)topWin;
		winIndex = winIndex - ((double)topLoss / 2);
		winIndex = winIndex + ((PPG - oPPG) / 3);
		(*iter)->setWinIndex(winIndex);
		winIndex = 0.0;
	}

}

void BracketCalculator::PrintBracket()
{
	
	list<TeamDatabase*> templist = myList.getList();
	list<TeamDatabase*>::iterator iter;

	for (iter = templist.begin(); iter != templist.end(); iter++) // Round of 64
	{
		int gameNum1 = (*iter)->getGameNum();
		float teamWinIndex1 = (*iter)->getWinIndex();
		string name1 = (*iter)->getName();
		iter++;
		int gameNum2 = (*iter)->getGameNum();
		float teamWinIndex2 = (*iter)->getWinIndex();
		string name2 = (*iter)->getName();
		if (gameNum1 == gameNum2)
		{
			if (teamWinIndex1 > teamWinIndex2)
			{
				cout << "Game " << gameNum1 << " round 64 " << name1 << " beats " << name2 << endl;
			}
		}
	}
}