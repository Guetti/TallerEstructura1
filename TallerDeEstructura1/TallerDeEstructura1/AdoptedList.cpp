#include "AdoptedList.h"

AdoptedList::AdoptedList()
{
}

AdoptedList::AdoptedList(int max)
{
	list = new AdoptedDog[max];
	size = 0;
}

AdoptedList::~AdoptedList()
{
}

void AdoptedList::AddAdopted(AdoptedDog newAdopted)
{
	list[size] = newAdopted;
	size++;
}
