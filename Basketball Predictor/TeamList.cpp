#include "TeamList.h"



TeamList::TeamList()
{
}


TeamList::~TeamList()
{
}

void TeamList::Insert(TeamDatabase* var) 
{
	theList.push_back(var);
}

bool TeamList::Delete(TeamDatabase* var)
{
	list<TeamDatabase*>::iterator iter;
	for (iter = theList.begin(); iter != theList.end(); iter++) 
	{
		if (*iter == var) {
			theList.remove(*iter);
			return true;
		}
	}
	return false;
}

void TeamList::PrintList()
{
	list<TeamDatabase*>::iterator iter;
	for (iter = theList.begin(); iter != theList.end(); iter++)
	{
		(*iter)->Print();
	}
}


list<TeamDatabase*> TeamList::getList()
{
	return theList;
}


