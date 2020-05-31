#include "DonationList.h"
#include <iostream>

DonationList::DonationList()
{
}

DonationList::DonationList(int max)
{
	list = new Donation[max];
	size = 0;
}

DonationList::~DonationList()
{
}

void DonationList::addDonation(Donation newDonation)
{
	if (size == max) {
		expand();
	}
	list[size] = newDonation;
	size++;
}

void DonationList::expand()
{
	Donation* copy = new Donation[max];
	for (int i = 0; i < max; i++) {
		copy[i] = list[i];
	}
	delete[] list;

	list = new Donation[max + 1];

	for (int i = 0; i < max; i++) {
		list[i] = copy[i];
	}
	max = max + 1;
	delete[] copy;
}

void DonationList::print()
{
	cout << "Donaciones: " << endl;
	for (int i = 0; i < this->size; i++) {
		cout << "[" << (i + 1) << "] Rut: " << list[i].getDonatorRut() << "\tNombre: " << list[i].getDonatorName() << " " << list[i].getDonatorLastname() << "\tContabilizado: " << list[i].getAccounted() << "\tMonto donado: " << list[i].getAmmount() << endl;
	}
}

string DonationList::getText()
{
	string text = "";

	for (int i = 0; i < size; i++) {
		text += list[i].getDonatorRut() + "," + list[i].getDonatorName() + "," + list[i].getDonatorLastname() + "," + list[i].getAccounted() + "," + to_string(list[i].getAmmount()) + "," + "\n";
	}
	return text;
}



int DonationList::getSize()
{
	return this->size;
}
