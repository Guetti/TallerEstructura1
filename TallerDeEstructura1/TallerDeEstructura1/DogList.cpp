#include "DogList.h"

DogList::DogList()
{
}

DogList::DogList(int max)
{
	list = new Dog[max];
	size = 0;
}

void DogList::AddDog(Dog newDog)
{
	list[size] = newDog;
	size++;
}
