#include "Donation.h"

Donation::Donation()
{
}

Donation::Donation(string rut, string name, string lastname, string accounted, int ammount)
{
	this->donatorRut = rut;
	this->donatorName = name;
	this->donatorLastname = lastname;
	this->accounted = accounted;
	this->ammount = ammount;
}

string Donation::getDonatorRut()
{
	return this->donatorRut;
}

string Donation::getDonatorName()
{
	return this->donatorName;
}

string Donation::getDonatorLastname()
{
	return this->donatorLastname;
}

string Donation::getAccounted()
{
	return this->accounted;
}

int Donation::getAmmount()
{
	return this->ammount;
}

void Donation::setDonatorRut(string donatorRut)
{
	this->donatorRut = donatorRut;
}

void Donation::setDonatorName(string DonatorName)
{
	this->donatorName = donatorName;
}

void Donation::setDonatorLastname(string donatorLastname)
{
	this->donatorLastname = donatorLastname;
}
