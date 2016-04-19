#pragma once
#include <list>
#include "TeamDatabase.h"

using std::list;
class TeamList
{
public:
	TeamList();
	~TeamList();

	void Insert(TeamDatabase* var);
	bool Delete(TeamDatabase* var);
	void PrintList();
	void PrintTeam(TeamDatabase* var);
	list<TeamDatabase*> getList();


private:
	list<TeamDatabase*> theList;
};
