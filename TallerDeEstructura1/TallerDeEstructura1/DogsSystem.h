#pragma once
#include "Dog.h"
#include "Donation.h"
#include "DogList.h"
#include "AdoptedDog.h"
#include "AdoptedList.h"
class DogsSystem
{
public:
	DogsSystem(int money, int vaccineCost, int sterilizationCostMale,int sterilizationCostFemale);
	Dog searchDog();
	Donation searchDonation();
	bool receiveDonation();
	bool AdoptDog();
	string stadistics();
	void exit();

	//void mainMenu();
	//void searchDogMenu();
	//void searchDonationMenu();
	//void receiveDonationMenu();
	//void adoptDogMenu();
	//void stadisticsMenu();

private:
	DogList dogs = DogList(10); // Aqui tengo la duda.
	AdoptedList adoptedDogs = AdoptedList(10); // Aqui igual.
	int money, vaccineCost, sterilizationCostMale, sterilizationCostFemale;
};

