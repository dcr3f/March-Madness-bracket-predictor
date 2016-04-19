#include "BracketCalculator.h"


using namespace std;
int main()
{
	BracketCalculator bracket;

	bracket.LoadTeams();
	bracket.CalculateTeamWinIndex();
	bracket.PrintBracket();
	return 0;
}