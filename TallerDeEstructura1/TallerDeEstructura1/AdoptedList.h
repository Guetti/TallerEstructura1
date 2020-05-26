#pragma once
#include "AdoptedDog.h"
class AdoptedList
{
public:
	AdoptedList();
	AdoptedList(int max);

	void AddAdopted(AdoptedDog newAdopted);


private:
	AdoptedDog* list;
	int size;
};

