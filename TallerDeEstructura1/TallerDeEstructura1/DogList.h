#pragma once
#include "Dog.h"
class DogList
{
public:
	DogList();
	DogList(int max);

	void AddDog(Dog newDog);


private:
	Dog* list;
	int size;
};

