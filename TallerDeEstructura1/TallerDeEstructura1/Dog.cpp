#include "Dog.h"

Dog::Dog()
{
}

Dog::Dog(string id, char size, int age, char sex, string vaccinated, string sterilized)
{
	this->id = id;
	this->size = size;
	this->age = age;
	this->sex = sex;
	this->vaccinated = vaccinated;
	this->sterilized = sterilized;
}

Dog::~Dog()
{
	
}

string Dog::getId()
{
	return this->id;
}

char Dog::getSize()
{
	return this->size;
}

int Dog::getAge()
{
	return this->age;
}

char Dog::getSex()
{
	return this->sex;
}

string Dog::getVaccinated()
{
	return this->vaccinated;
}

string Dog::getSterilized()
{
	return this->sterilized;
}


void Dog::setId(string id)
{
	this->id = id;
}

void Dog::setSize(char size)
{
	this->size = size;
}

void Dog::setAge(int age)
{
	this->age = age;
}

void Dog::setSex(char sex)
{
	this->sex = sex;
}

void Dog::setVaccinated(string vaccinated)
{
	this->vaccinated = vaccinated;
}

void Dog::setSterilized(string vaccinated)
{
	this->vaccinated = vaccinated;
}

