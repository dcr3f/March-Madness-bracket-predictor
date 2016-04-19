#pragma once
#include "TeamList.h"
#include <fstream>



using std::fstream;
class BracketCalculator
{
public:
	void LoadTeams();
	void PrintTeams();
	void CalculateTeamWinIndex();
	void PrintBracket();

private:
	TeamList myList;
};

