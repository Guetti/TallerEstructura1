#include "AdoptedDog.h"

AdoptedDog::AdoptedDog()
{
}

AdoptedDog::AdoptedDog(string id, string dogName, string ownerRut, string ownerName, string ownerLastName)
{
	this->id = id;
	this->dogName = dogName;
	this->ownerRut = ownerRut;
	this->ownerName = ownerName;
	this->ownerLastname = ownerLastName;
}

AdoptedDog::~AdoptedDog()
{
}

string AdoptedDog::getId()
{
	return this->id;
}

string AdoptedDog::getDogName()
{
	return this->dogName;
}

string AdoptedDog::getOwnerRut()
{
	return this->ownerRut;
}

string AdoptedDog::getOwnerName()
{
	return this->ownerName;
}

string AdoptedDog::getOwnerLastname()
{
	return this->ownerLastname;
}

void AdoptedDog::setId(string id)
{
	this->id = id;
}

void AdoptedDog::setDogName(string dogName)
{
	this->dogName = dogName;
}

void AdoptedDog::setOwnerRut(string ownerRut)
{
	this->ownerRut = ownerRut;
}

void AdoptedDog::setOwnerName(string ownerName)
{
	this->ownerName = ownerName;
}

void AdoptedDog::setOwnerLastname(string ownerLastname)
{
	this->ownerLastname = ownerLastname;
}
