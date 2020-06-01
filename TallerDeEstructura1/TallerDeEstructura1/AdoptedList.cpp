#include "AdoptedList.h"
#include <iostream>

AdoptedList::AdoptedList()
{
}

AdoptedList::AdoptedList(int max)
{
	list = new AdoptedDog[max];
	size = 0;
	this->max = max;
}

AdoptedList::~AdoptedList()
{
}

void AdoptedList::addAdopted(AdoptedDog newAdopted)
{
	if (size == max) {
		expand();
	}
	list[size] = newAdopted;
	size++;
}

void AdoptedList::expand()
{
	AdoptedDog* copy = new AdoptedDog[max];
	for (int i = 0; i < max; i++) {
		copy[i] = list[i];
	}
	delete[] list;

	list = new AdoptedDog[max + 1];

	for (int i = 0; i < max; i++) {
		list[i] = copy[i];
	}
	max = max + 1;
	delete[] copy;
}

void AdoptedList::print()
{
	cout << "\tPerros adoptados: " << endl;
	for (int i = 0; i < this->size; i++) {
		cout << "\t[" << (i + 1) << "] ID: " << list[i].getId() << "\tNombre del perro: " << list[i].getDogName() << "\tRut duenio: " << list[i].getOwnerRut() << "\tDuenio: " << list[i].getOwnerName() << " " << list[i].getOwnerLastname() << endl;
	}

}

AdoptedDog AdoptedList::searchDog(string id)
{
	for (int i = 0; i < size; i++) {
		if (list[i].getId()._Equal(id)) {
			return list[i];
		}
	}
	return AdoptedDog();
}

AdoptedDog AdoptedList::getDog(int index)
{
	return list[index];
}

bool AdoptedList::exists(string id)
{
	for (int i = 0; i < size; i++) {
		if (list[i].getId()._Equal(id)) {
			return true;
		}
	}
	return false;
}

string AdoptedList::getText()
{
	string text = "";

	for (int i = 0; i < size; i++) {
		text += list[i].getId() + "," + list[i].getDogName() + "," + list[i].getOwnerRut() + "," + list[i].getOwnerName() + "," + list[i].getOwnerLastname() + "\n";
	}
	return text;
}

int AdoptedList::getSize()
{
	return this->size;
}
