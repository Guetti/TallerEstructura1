#include "DogsSystem.h"
#include <string>
#include <iostream>

using namespace std;

DogsSystem::DogsSystem(int money, int vaccineCost, int sterilizationCostMale, int sterilizationCostFemale)
{
	this->money = money;
	this->vaccineCost = vaccineCost;
	this->sterilizationCostMale = sterilizationCostMale;
	this->sterilizationCostFemale = sterilizationCostFemale;
}

Dog DogsSystem::searchDog()
{
	return Dog();
}

Donation DogsSystem::searchDonation()
{
	return Donation();
}

bool DogsSystem::receiveDonation()
{
	return false;
}

bool DogsSystem::AdoptDog()
{
	return false;
}

string DogsSystem::stadistics()
{
	return string();
}

void DogsSystem::exit()
{
}


