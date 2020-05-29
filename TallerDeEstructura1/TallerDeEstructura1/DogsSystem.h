#pragma once
#include "Dog.h"
#include "Donation.h"
#include "DogList.h"
#include "AdoptedDog.h"
#include "AdoptedList.h"
#include "DonationList.h"
class DogsSystem
{
public:
	DogsSystem();
	DogsSystem(int money, int vaccineCost, int sterilizationCostMale,int sterilizationCostFemale);
	~DogsSystem();

	void readFiles();

	void mainMenu();
	void searchDogMenu();
	void searchDonationMenu();
	void receiveDonationMenu();
	void adoptDogMenu();
	void stadisticsMenu();
	void exitAndSave();
	
	void startProgram();
	
	bool searchDog();
	bool searchDonation();
	bool receiveDonation();
	bool AdoptDog();
	string stadistics();

	void setMoney(int money);
	void setVaccineCost(int vaccineCost);
	void setSterilizationCostMale(int sterilizationCostMale);
	void setSterilizationCostFemale(int sterilizationCostFemale);
	
	int getMoney();
	int getVaccineCost();
	int getSterilizationCostMale();
	int getSterilizationCostFemale();

	int random(int min, int max);

	DogList getDogList();
private:
	DogList* dogs; // Aqui tengo la duda.
	AdoptedList* adoptedDogs; // Aqui igual.
	DonationList* donations;
	int money; // no se esta actualizando
	int vaccineCost;
	int sterilizationCostMale;
	int sterilizationCostFemale;
};

