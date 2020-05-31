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
		cout << " No se encontro el archivo Donaciones.txt. \n" << endl;
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

			if (accounted._Equal("no")) {
				money += iAmmount;
				accounted = "si";
			}

			Donation donation = Donation(rut, name, lastname, accounted, iAmmount);
			donations->addDonation(donation);
		}
	}

	text.close();

	text.open("Adoptados.txt");

	if (text.fail()) {
		cout << " No se encontro el archivo Adoptados.txt. \n" << endl;
		exit(EXIT_FAILURE);
	}

	while (!text.eof()) {
		getline(text, line);
		if (line != "") {
			string id = "";
			string dogName = "";
			string ownerRut = "";
			string ownerName = "";
			string ownerLastname = "";

			istringstream space(line);

			getline(space, id, ',');
			getline(space, dogName, ',');
			getline(space, ownerRut, ',');
			getline(space, ownerName, ',');
			getline(space, ownerLastname, ',');

			AdoptedDog adopted = AdoptedDog(id, dogName, ownerRut, ownerName, ownerLastname);
			adoptedDogs->addAdopted(adopted);
		}
	}

	text.close();
}

void DogsSystem::mainMenu()
{
	cout << "\tBienvenido" << endl;

	while (true) {
		cout << "\t\t\t\tFondos totales: $" << money << endl;
		cout << "[1] Buscar perro\n[2] Buscar donacion\n[3] Recibir donacion\n[4] Dar en adopcion\n[5] Estadisticas\n[6] Salir" << endl;
		cout << "Ingrese una opcion: ";
		int option = validateOption(6);

		switch (option)
		{
		case 0:
			break;
		case 1:
			searchDogMenu();
			//dogs->printAll();
			break;
		case 2:
			searchDonationMenu();
			//donations->print();
			break;
		case 3:
			receiveDonationMenu();
			break;
		case 4:
			adoptDogMenu();
			//adoptedDogs->print();
			break;
		case 5:
			//stadisticsMenu(system);
			break;
		case 6:
			//save(system);
			exitAndSave();
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
	if (!searchDonation()) {
		cout << "No se han encontrado donaciones" << endl;
		return;
	}
}

void DogsSystem::receiveDonationMenu()
{
	receiveDonation(false);
}

void DogsSystem::adoptDogMenu()
{
	if (AdoptDog()) {
		cout << "El perro ha sido adoptado con exito" << endl;
	}
	else {
		cout << "No se ha podido adoptar el perro correctamente" << endl;
	}
}

void DogsSystem::stadisticsMenu()
{
}

void DogsSystem::exitAndSave()
{
	ofstream rescueds("Rescatados.txt");
	string line = this->dogs->getText();
	rescueds << line;

	ofstream donations("Donaciones.txt");
	line = this->donations->getText();
	donations << line;

	ofstream adopteds("Adoptados.txt");
	line = this->adoptedDogs->getText();
	adopteds << line;


	exit(1);
}

void DogsSystem::startProgram()
{
	srand(time(NULL));
	readFiles(); //leer archivos
	mainMenu();

}

int DogsSystem::validateOption(int maxOptions)
{
	int option;

	cin >> option;

	if (cin.fail()) {
		cout << "Ha ingresado caracteres no validos..." << endl;
		cin.clear();
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
		return 0;
 	}
	else {
		//cout << "good data" << endl;
		cin.clear();
		return option;
	}
}

bool DogsSystem::searchDog()
{
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
		char sex = 'M';
		char size = 'P';

		if (randomVaccinated == 1) {
			vaccinated = "si";
		}
		if (randomSterilized == 1) {
			sterilized = "si";
		}
		if (randomSex == 1) {
			sex = 'H';
		}
		switch (randomSize)
		{
		case 2:
			size = 'M';
			break;
		case 3:
			size = 'G';
			break;
		default:
			size = 'P';
			break;
		}

		string id = "P" + to_string(dogs->getSize() + 1);

		Dog* dog = new Dog(id, size, randomAge, sex, vaccinated, sterilized);

		cout << "\tSe ha encontrado y rescatado el siguiente perro:" << endl;
		cout << "\t\tTamanio: " << dog->getSize() << endl;
		
		cout << "\t\tEdad: " << dog->getAge() << endl;
		cout << "\t\tSexo: " << dog->getSex() << endl;
		cout << "\t\tVacunado: " << dog->getVaccinated() << endl;
		cout << "\t\tEsterilizado: " << dog->getSterilized() << endl;
		cout << "\tEl costo de rescate de este perro fue de: $" << randomCost << endl;
		dogs->addDog(*dog);
		money -= randomCost;		
		return true;
	}
	return false;
	
}

bool DogsSystem::searchDonation()
{
	int randomNumber = random(0, 100);
	cout << randomNumber << endl;
	if (randomNumber <= 50)
	{
		cout << "\t\tSe ha encontrado un donador" << endl;
		receiveDonation(true);
		return true;
	}

	return false;
}

bool DogsSystem::receiveDonation(bool random)
{
	string rut = "";
	string name = "";
	string lastname = "";
	int donatedMoney = 0;

	cout << "\tIngrese el rut del donador: ";
	cin >> rut;
	cin.clear();
	cout << "\tIngrese el nombre y apellido del donador: ";
	cin >> name >> lastname;
	cin.clear();
	if (random) {
		donatedMoney = this->random(1000, 2000);
	}
	else {
		cout << "Ingrese el total de la donacion: ";
		cin >> donatedMoney;
		if (cin.fail()) {
			cout << "ERROR: Porfavor use solo numeros enteros..." << endl;
			return false;
		}
		else {
			if (donatedMoney <= 0) {
				cout << "No puede donar una cantidad negativa o menor a 1" << endl;
				return false;
			}
		}
	}
	Donation* donation = new Donation(rut, name, lastname, "si", donatedMoney);
	donations->addDonation(*donation);
	this->money += donatedMoney;
	cout << "Se ha registrado una donacion por $" << donatedMoney << " de " << name << " " << lastname << " con Rut: " << rut << endl;
	return true;
}

bool DogsSystem::AdoptDog()
{
	dogs->printAll();
	cout << "Porfavor, ingrese el codigo del perro que quiere adoptar: ";
	string id = "";
	cin >> id;
	Dog dog = dogs->searchDog(id);

	if (dog.getId()._Equal(""))
	{
		cout << "No se ha encontrado el perro con id = " << id << endl;
		return false;
	}
	if (adoptedDogs->exists(id)) {
		cout << "Error: Este perro ya tiene duenio..." << endl;
		return false;
	}
	int treatmentCost = 0;
	if (dog.getVaccinated()._Equal("no")) {
		treatmentCost += vaccineCost;
	}
	if (dog.getSterilized()._Equal("no")) {
		if (dog.getSex() == 'm') {
			treatmentCost += sterilizationCostMale;
		}
		else {
			treatmentCost += sterilizationCostFemale;
		}
	}

	if (treatmentCost > 0) {
		cout << "Para adoptar este perro se necesita cancelar un monto de: $" << treatmentCost << " para sus tratamientos. ¿Desea aceptar? \n[1] Si \n[2] No" << endl;
		int option = validateOption(2);
		if (option == 0 || option == 2) {
			return false;
		}
	}
	else {
		cout << "Este perro tiene sus vacunas al dia y esta esterilizado, no es necesario cancelar nada" << endl;
	}

	string dogName = "";
	string ownerRut = "";
	string ownerName = "";
	string ownerLastname = "";

	cout << "Nombre a su perro: ";
	cin >> dogName;
	cin.clear();
	cout << "su rut: ";
	cin >> ownerRut;
	cin.clear();
	cout << "Su nombre y apellido: ";
	cin >> ownerName >> ownerLastname;
	cin.clear();

	AdoptedDog adoptedDog = AdoptedDog(id, dogName, ownerRut, ownerName, ownerLastname);
	adoptedDogs->addAdopted(adoptedDog);
	adoptedDogs->print();
	money += treatmentCost;
	return true;
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
