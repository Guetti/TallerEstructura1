#pragma once
#include "Dog.h"
class DogList
{
public:
	DogList();
	DogList(int max);
	~DogList();

	void addDog(Dog newDog);
	void expand();
	void print();

	int getSize();


private:
	Dog* list;

	int size;
	int max;
};

