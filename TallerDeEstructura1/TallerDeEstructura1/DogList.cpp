#include "DogList.h"
#include <iostream>

DogList::DogList()
{
}

DogList::DogList(int max)
{
	list = new Dog[max];
	size = 0;
	this->max = max;
}

DogList::~DogList()
{
}

void DogList::addDog(Dog newDog)
{
	if (size == max) {
		expand();
	}
	list[size] = newDog;
	size++;
}

void DogList::expand()
{
	Dog* copy = new Dog[max];
	for (int i = 0; i < max; i++) {
		copy[i] = list[i];
	}
	delete[] list;

	list = new Dog[max + 1];

	for (int i = 0; i < max; i++) {
		list[i] = copy[i];
	}
	max = max + 1;
	delete[] copy;
}

void DogList::print()
{
	cout << "Perros rescatados: " << endl;
	for (int i = 0; i < this->size; i++) {
		cout << "[" << (i + 1) << "] ID: " << list[i].getId() << "\tEdad: " << list[i].getAge() << "\t Sexo: " << list[i].getSex() << "\tTamanio: " << list[i].getSize() << "\tVacunado: " << list[i].getVaccinated() << "\tEsterilizado: " << list[i].getSterilized() << endl;
	}
}

int DogList::getSize()
{
	return this->size;
}
