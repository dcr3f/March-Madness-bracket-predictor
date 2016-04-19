#include "TeamDatabase.h"



TeamDatabase::TeamDatabase()
{
	_name = "";
	_gameNum = 0;
	_round = 0;
	_rankBPI = 0;
	_rankRPI = 0;
	_vsTopWin = 0;
	_vsTopLoss = 0;
	_lastTwelveWin = 0;
	_lastTwelveLoss = 0;
	_PPG = 0.0;
	_oPPG = 0.0;

}

TeamDatabase::TeamDatabase(string name, int gameNum, int round, int seed, int rankRPI, int rankBPI, int vsTopWin, int vsTopLoss,
	int lastTwelveWin, int lastTwelveLoss, double PPG, double oPPG)
{
	_name = name;
	_gameNum = gameNum;
	_round = round;
	_seed = seed;
	_rankBPI = rankBPI;
	_rankRPI = rankRPI;
	_vsTopWin = vsTopWin;
	_vsTopLoss = vsTopLoss;
	_lastTwelveWin = lastTwelveWin;
	_lastTwelveLoss = lastTwelveLoss;
	_PPG = PPG;
	_oPPG = oPPG;
	
}


TeamDatabase::~TeamDatabase()
{
}

string TeamDatabase::getName()
{
	return _name;
}

int TeamDatabase::getGameNum()
{
	return _gameNum;
}

int TeamDatabase::getRound()
{
	return _round;
}

int TeamDatabase::getSeed()
{
	return _seed;
}

int TeamDatabase::getRPI()
{
	return _rankRPI;
}

int TeamDatabase::getBPI()
{
	return _rankBPI;
}

int TeamDatabase::getTopWin()
{
	return _vsTopWin;
}

int TeamDatabase::getTopLoss()
{
	return _vsTopLoss;
}

int TeamDatabase::getTwelveWin()
{
	return _lastTwelveWin;
}

int TeamDatabase::getTwelveLoss()
{
	return _lastTwelveLoss;
}

double TeamDatabase::getPPG()
{
	return _PPG;
}

double TeamDatabase::getOPPG()
{
	return _oPPG;
}

double TeamDatabase::getWinIndex()
{
	return _winIndex;
}

void TeamDatabase::setWinIndex(double var)
{
	_winIndex = var;
}

void TeamDatabase::Print() 
{
	cout << "Team Name: " << _name << endl << endl;
	cout << "Stats:" << endl;
	cout << "Seed: " << _seed << endl;
	cout << "RPI rank: " << _rankRPI << endl;
	cout << "BPI rank: " << _rankBPI << endl;
	cout << "Top 25 Win/Loss: " << _vsTopWin << " - " << _vsTopLoss << endl;
	cout << "Last 12 Games Win/Loss: " << _lastTwelveWin << " - " << _lastTwelveLoss << endl;
	cout << "Points Per Game: " << _PPG << endl;
	cout << "Opponents Points Per Game: " << _oPPG << endl << endl;
}
