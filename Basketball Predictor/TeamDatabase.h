#pragma once
#include <string>
#include <iostream>

using namespace std;


class TeamDatabase
{
public:
	TeamDatabase();
	TeamDatabase(string name, int gameNum, int round, int seed, int rankRPI,
					int rankBPI, int vsTopWin, int vsTopLoss,int lastTwelveWin,
					int lastTwelveLoss, double PPG, double oPPG);
	~TeamDatabase();
	string getName();
	int getGameNum();
	int getRound();
	int getSeed();
	int getRPI();
	int getBPI();
	int getTopWin();
	int getTopLoss();
	int getTwelveWin();
	int getTwelveLoss();
	double getPPG();
	double getOPPG();
	double getWinIndex();
	void setWinIndex(double var);
	void Print();

private:
	string _name;
	int _gameNum;
	int _round;
	int _seed;
	int _rankRPI;
	int _rankBPI;
	int _vsTopWin;
	int _vsTopLoss;
	int _lastTwelveWin;
	int _lastTwelveLoss;
	double _PPG;
	double _oPPG;
	double _winIndex;
};

