#include "DogsSystem.h"
#include <string>
#include <iostream>
#include <stdlib.h>
#include <time.h>
#include <fstream>
#include <sstream>

using namespace std;

DogsSystem::DogsSystem()
{
}

DogsSystem::DogsSystem(int money, int vaccineCost, int sterilizationCostMale, int sterilizationCostFemale)
{
	this->money = money;
	this->vaccineCost = vaccineCost;
	this->sterilizationCostMale = sterilizationCostMale;
	this->sterilizationCostFemale = sterilizationCostFemale;

	this->dogs = new DogList(1);
	this->adoptedDogs = new AdoptedList(10);
	this->donations = new DonationList(1);

}

DogsSystem::~DogsSystem()
{
}

void DogsSystem::readFiles()
{
	string line;
	ifstream text;
	text.open("Rescatados.txt");

	if (text.fail()) {
		cout << " No se encontro el archivo Rescatados.txt. \n" << endl;
		exit(EXIT_FAILURE);
	}

	while (!text.eof()) {
		getline(text, line);
		if (line != "") {
			string id = "";
			string size = "";
			string age = "";
			string sex = "";
			string vaccinated = "";
			string sterilized = "";

			istringstream space(line);

			getline(space, id, ',');
			getline(space, size, ',');
			getline(space, age, ',');
			getline(space, sex, ',');
			getline(space, vaccinated, ',');
			getline(space, sterilized, ',');

			char cSize = size[0];
			int iAge = stoi(age);
			char cSex = sex[0];

			Dog dog = Dog(id, cSize, iAge, cSex, vaccinated, sterilized);
			dogs->addDog(dog);
		}
	}
	text.close();



	text.open("Donaciones.txt");

	if (text.fail()) {
		cout << " No se encontro el archivo Adoptados.txt. \n" << endl;
		exit(EXIT_FAILURE);
	}

	while (!text.eof()) {
		getline(text, line);
		if (line != "") {
			string rut = "";
			string name = "";
			string lastname = "";
			string accounted = "";
			string ammount = "";

			istringstream space(line);

			getline(space, rut, ',');
			getline(space, name, ',');
			getline(space, lastname, ',');
			getline(space, accounted, ',');
			getline(space, ammount, ',');

			int iAmmount = stoi(ammount);

			Donation donation = Donation(rut, name, lastname, accounted, iAmmount);
			donations->addDonation(donation);
		}
	}

	text.close();
}

void DogsSystem::mainMenu()
{
	cout << "\tBienvenido" << endl;

	while (true) {
		cout << "[1] Buscar perro\n[2] Buscar donacion\n[3] Recibir donacion\n[4] Dar en adopcion\n[5] Estadisticas\n[6] Salir" << endl;
		cout << "Ingrese una opcion: ";
		int option;
		cin >> option;
		switch (option)
		{
		case 1:
			searchDogMenu();
			dogs->print();
			break;
		case 2:
			searchDonationMenu();
			donations->print();
			break;
		case 3:
			//receiveDonationMenu(system);
			break;
		case 4:
			//adoptDogMenu(system);
			break;
		case 5:
			//stadisticsMenu(system);
			break;
		case 6:
			//save(system);
			//sexitAndSave();
			break;
		}
	}
}

void DogsSystem::searchDogMenu()
{
	if (money < 0) {
		cout << "La fundacion no tiene fondos para buscar mas perros" << endl;
		return;
	}
	if (searchDog()) {
		cout << "El perro ha sido rescatado con exito" << endl;
		cout << "Nuevos fondos: $" << this->money << endl;
		return;
	}
	cout << "No se han encontrado perros " << endl;
	return;
}

void DogsSystem::searchDonationMenu()
{
	if (money > 0) {
		cout << "La fundacion debe tener fondos negativos para buscar donaciones" << endl;
		return;
	}
	searchDonation();
}

void DogsSystem::receiveDonationMenu()
{
}

void DogsSystem::adoptDogMenu()
{
}

void DogsSystem::stadisticsMenu()
{
}

void DogsSystem::startProgram()
{
	readFiles(); //leer archivos
	//Desplegar menu
	mainMenu();

}

bool DogsSystem::searchDog()
{
	srand(time(NULL));
	int randomNumber = random(0, 100);
	cout << randomNumber << endl;
	if (randomNumber <= 30)
	{
		// Perro encontrado
		int randomCost = random(5000, 10000);
		int randomVaccinated = random(0,1);
		int randomSterilized = random(0,1);
		int randomSex = random(0,1);
		int randomSize = random(1,3);
		int randomAge = random(1,15);
		string vaccinated = "no";
		string sterilized = "no";
		char sex = 'm';
		char size = 's';

		if (randomVaccinated == 1) {
			vaccinated = "si";
		}
		if (randomSterilized == 1) {
			sterilized = "si";
		}
		if (randomSex == 1) {
			sex = 'h';
		}
		switch (randomSize)
		{
		case 2:
			size = 'm';
			break;
		case 3:
			size = 'l';
			break;
		default:
			size = 's';
			break;
		}

		string id = "P" + to_string(dogs->getSize() + 1);

		Dog* dog = new Dog(id, size, randomAge, sex, vaccinated, sterilized);

		cout << "\tSe encontro un perro" << endl;
		cout << "\tTamanio: " << dog->getSize() << endl;
		
		cout << "\tEdad: " << dog->getAge() << endl;
		cout << "\tSexo: " << dog->getSex() << endl;
		cout << "\tVacunado: " << dog->getVaccinated() << endl;
		cout << "\tEsterilizado: " << dog->getSterilized() << endl;
		cout << "El costo de rescate de este perro es de: $" << randomCost << endl;
		cout << &dog << endl;
		dogs->addDog(*dog);
		cout << "Costo random: " << randomCost << endl;
		money -= randomCost;		
		return true;
	}
	return false;
	
}

bool DogsSystem::searchDonation()
{
	srand(time(NULL));
	int randomNumber = random(0, 100);
	cout << randomNumber << endl;
	if (randomNumber <= 50)
	{
		int money = random(1000, 2000);
		Donation* donation = new Donation(money);
		donations->addDonation(*donation);
	}

	return false;
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


void DogsSystem::setMoney(int money)
{
	this->money = money;
}

void DogsSystem::setVaccineCost(int vaccineCost)
{
	this->vaccineCost = vaccineCost;
}

void DogsSystem::setSterilizationCostMale(int sterilizationCostMale)
{
	this->sterilizationCostMale = sterilizationCostMale;
}

void DogsSystem::setSterilizationCostFemale(int sterilizationCostFemale)
{
	this->sterilizationCostFemale = sterilizationCostFemale;
}

int DogsSystem::getMoney()
{
	return this->money;
}

int DogsSystem::getVaccineCost()
{
	return this->vaccineCost;
}

int DogsSystem::getSterilizationCostMale()
{
	return this->sterilizationCostMale;
}

int DogsSystem::getSterilizationCostFemale()
{
	return this->sterilizationCostFemale;
}

int DogsSystem::random(int min, int max)
{
	int num = min + rand() % (max + 1 - min);
	return num;
}

DogList DogsSystem::getDogList()
{
	return *this->dogs;
}
