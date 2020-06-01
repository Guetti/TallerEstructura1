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
	/*
	Se crean las listas que se utilizan en el programa con tamanio maximo 1, el cual va a ir en aumento a medida que se llena.
	*/
	this->dogs = new DogList(1);
	this->adoptedDogs = new AdoptedList(1);
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

	if (text.fail()) { // Si no encuentra el archivo de texto se cierra el programa.
		cout << "\tNo se encontro el archivo Rescatados.txt. \n" << endl;
		exit(EXIT_FAILURE);
	}

	while (!text.eof()) { // Mientras no sea el fin del texto
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

			Dog dog = Dog(id, cSize, iAge, cSex, vaccinated, sterilized); // Crea un perro.
			dogs->addDog(dog); // Agrega el perro a la lista de perros rescatados.
		}
	}
	text.close();



	text.open("Donaciones.txt");

	if (text.fail()) { // Si no encuentra el archivo de texto se cierra el programa.
		cout << "\tNo se encontro el archivo Donaciones.txt. \n" << endl;
		exit(EXIT_FAILURE);
	}
	 
	while (!text.eof()) { // Mientras no sea el fin del texto
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

			Donation donation = Donation(rut, name, lastname, accounted, iAmmount); // Crea una donacion.
			donations->addDonation(donation); // Guarda la donacion en la lista de donaciones.
		}
	}

	text.close();

	text.open("Adoptados.txt");

	if (text.fail()) { // Si no encuentra el archivo de texto se cierra el programa.
		cout << "\tNo se encontro el archivo Adoptados.txt. \n" << endl;
		exit(EXIT_FAILURE);
	}

	while (!text.eof()) { // Mientras no sea el fin del texto
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

			AdoptedDog adopted = AdoptedDog(id, dogName, ownerRut, ownerName, ownerLastname); // Crea un perro adoptado.
			adoptedDogs->addAdopted(adopted); // Agrega el perro adoptado a la lista de adoptados.		
		}
	}

	text.close();
}

void DogsSystem::mainMenu(){ // Inicio del programa
	cout << "==============Bienvenido==============" << endl;
	
	while (true) {
		cout << "\n\n";
		cout << "======================================" << endl;
		cout << "\t\t\t\t[Fondos totales: $" << money << "]" << endl;
		cout << "\t[1] Buscar perro\n\t[2] Buscar donacion\n\t[3] Recibir donacion\n\t[4] Dar en adopcion\n\t[5] Estadisticas\n\t[6] Salir \n" << endl;
		cout << "======================================\n" << endl;
		cout << "\tIngrese una opcion: ";
		int option = validateOption(6);

		switch (option)
		{
		case 0:
			break;
		case 1:
			searchDogMenu(); // Carga el menu de buscar perro.
			break;
		case 2:
			searchDonationMenu(); // Carga el menu de buscar donacion. 
			break;
		case 3:
			receiveDonationMenu(); // Carga el menu de recibir donacion.
			break;
		case 4:
			adoptDogMenu(); // Carga el menu de adoptar perro.
			break;
		case 5:
			stadisticsMenu(); // Carga el menu de estadisticas.
			break;
		case 6:
			exitAndSave(); // Guarda los nuevos registros y cierra el programa.
			break;
		}
	}
}

void DogsSystem::searchDogMenu()
{
	if (money < 0) { // Si los fondos son negativos no es posible buscar perros.
		cout << "\tLa fundacion no tiene fondos para buscar mas perros" << endl;
		return;
	}
	if (searchDog()) { // Si encuentra un perro resta el costo de rescate a los fondos y lo agrega a la lista de perros rescatados.
		cout << "\tNuevos fondos: $" << this->money << endl;
		return;
	}
	cout << "\tNo se han encontrado perros..." << endl; 
	return;
}

void DogsSystem::searchDonationMenu()
{
	if (money > 0) { // Si la fundacion tiene fondos positivos no es posible buscar donaciones.
		cout << "\tLa fundacion debe tener fondos negativos para buscar donaciones..." << endl;
		return;
	}
	if (!searchDonation()) { // Si encuentra una donacion, pide los datos del donante y lo guarda en la lista de donaciones.
		cout << "\tNo se han encontrado donacionesnnn" << endl;
		return;
	}
}

void DogsSystem::receiveDonationMenu()
{
	receiveDonation(false); // Recibe una donacion sin generarla al azar.
}

void DogsSystem::adoptDogMenu()
{
	if (adoptDog()) { // Pide los datos de adopcion y agrega el perro a la lista de perros adoptados.
		cout << "\tEl perro ha sido adoptado con exito!" << endl;
	}
	else {
		cout << "\tNo se ha podido adoptar el perro correctamente..." << endl;
	}
}

void DogsSystem::stadisticsMenu()
{
	cout << endl;
	cout << "\ta) Cantidad total de perros adoptados: " << adoptedDogs->getSize() << endl;

	int adoptedMalesCounter = 0;
	for (int i = 0; i < adoptedDogs->getSize(); i++) {
		AdoptedDog adoptedDog = adoptedDogs->getDog(i);
		Dog rescuedDog = dogs->searchDog(adoptedDog.getId());
		if (rescuedDog.getSex() == 'M') {
			adoptedMalesCounter++;
		}
	}
	cout << "\tb) Cantidad total de perros machos adoptados: " << adoptedMalesCounter << endl;

	int adoptedFemalesCounter = 0;
	for (int i = 0; i < adoptedDogs->getSize(); i++) {
		AdoptedDog adoptedDog = adoptedDogs->getDog(i);
		Dog rescuedDog = dogs->searchDog(adoptedDog.getId());
		if (rescuedDog.getSex() == 'H') {
			adoptedFemalesCounter++;
		}
	}

	cout << "\tc) Cantidad total de perros hembras adoptados: " << adoptedFemalesCounter << endl;

	int notAdoptedAmmount = dogs->getSize() - adoptedDogs->getSize(); // perros rescatados - perros adoptados = cant perros no adoptados

	cout << "\td) Cantidad total de perros que no han sido adoptados: " << notAdoptedAmmount << endl;

	int notAdoptedMalesAmmount = dogs->getMaleAmmount();
	for (int i = 0; i < adoptedDogs->getSize(); i++) {
		AdoptedDog adoptedDog = adoptedDogs->getDog(i);
		Dog rescuedDog = dogs->searchDog(adoptedDog.getId());
		if (rescuedDog.getSex() == 'M') {
			notAdoptedMalesAmmount--;
		}
	}

	cout << "\te) Cantidad de perros machos que no han sido adoptados: " << notAdoptedMalesAmmount << endl;

	int notAdoptedFemalesAmmount = dogs->getFemaleAmmount();
	for (int i = 0; i < adoptedDogs->getSize(); i++) {
		AdoptedDog adoptedDog = adoptedDogs->getDog(i);
		Dog rescuedDog = dogs->searchDog(adoptedDog.getId());
		if (rescuedDog.getSex() == 'H') {
			notAdoptedFemalesAmmount--;
		}
	}

	cout << "\tf) Cantidad de perros hembras que no han sido adoptados: " << notAdoptedFemalesAmmount << endl;



	int biggestDonationAmmount = 0;
	Donation biggestDonation;

	for (int i = 0; i < donations->getSize(); i++) {
		if (donations->getDonation(i).getAmmount() > biggestDonationAmmount) {
			biggestDonationAmmount = donations->getDonation(i).getAmmount();
			biggestDonation = donations->getDonation(i);
		}
	}
	cout << "\tPersona que mas ha donado: " << endl;
	cout << "\t\t Rut: " << biggestDonation.getDonatorRut() << "\tNombre: " << biggestDonation.getDonatorName() << " " << biggestDonation.getDonatorLastname() << "\t Monto donado: $" << biggestDonationAmmount << endl;
	cout << endl;

	cout << "\tPersona con mas perros adoptados: " << endl; // No supe como hacerlo - Gustavo.

}

void DogsSystem::exitAndSave()
{
	// Guarda los nuevos datos en los archivos de texto.
	ofstream rescueds("Rescatados.txt");
	string line = this->dogs->getText();
	rescueds << line;

	ofstream donations("Donaciones.txt");
	line = this->donations->getText();
	donations << line;

	ofstream adopteds("Adoptados.txt");
	line = this->adoptedDogs->getText();
	adopteds << line;
	cout << "\tSe han guardado los datos, hasta pronto." << endl;
	exit(1); // Fin del programa.
}

void DogsSystem::startProgram()
{
	srand(time(NULL)); // Se inicializa la seed para las variables random del programa.
	readFiles(); //Se leen los archivos de texto y se cargan en el sistema.
	mainMenu(); // Se carga el menu principal.

}

int DogsSystem::validateOption(int maxOptions)
{
	int option;

	cin >> option;
	cout << endl;
	if (cin.fail()) { // Si la lectura por pantalla falla.
		cout << "\tHa ingresado caracteres no validos...\n" << endl;
		cin.clear(); // Limpia el campo. 
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Ignora la entrada.
		return 0;
 	}
	else { // Se ingresa un dato valido.
		if (option > 0 && option <= maxOptions) { // Verifica si la opcion ingresada esta dentro de los limites permitidos.
			cin.clear();
			return option; // Retorna el dato valido.
		}
		cout << "\tHa ingresado una opcion invalida...\n" << endl;
		return 0;
	}
}

bool DogsSystem::searchDog()
{
	int randomNumber = random(0, 100); // Genera un numero al azar entre 0 y 100.
	if (randomNumber <= 30) // Si el numero al azar es menor o igual a 30 genera un perro al azar.
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

		Dog* dog = new Dog(id, size, randomAge, sex, vaccinated, sterilized); // Crea al perro.

		cout << "\tSe ha encontrado y rescatado el siguiente perro:" << endl;
		cout << "\t\t-Tamanio: " << dog->getSize() << endl;
		
		cout << "\t\t-Edad: " << dog->getAge() << endl;
		cout << "\t\t-Sexo: " << dog->getSex() << endl;
		cout << "\t\t-Vacunado: " << dog->getVaccinated() << endl;
		cout << "\t\t-Esterilizado: " << dog->getSterilized() << endl;
		cout << "\tEl costo de rescate de este perro fue de: $" << randomCost << endl;
		dogs->addDog(*dog); // Agrega el perro a la lista.
		money -= randomCost; // Resta el costo de rescate a los fondos.
		return true;
	}
	return false;
	
}

bool DogsSystem::searchDonation()
{
	int randomNumber = random(0, 100); // Genera un numero del 0 al 100.
	if (randomNumber <= 50) // Si el numero es menor o igual a 50 genera una donacion al azar.
	{
		cout << "\t\tSe ha encontrado un donador!" << endl;
		receiveDonation(true);
		return true;
	}

	return false;
}

bool DogsSystem::receiveDonation(bool random) // Si random es verdadero, el monto donado es al azar.
{
	string rut = "";
	string name = "";
	string lastname = "";
	int donatedMoney = 0;

	cout << "\tIngrese el rut del donador(Formato: 10.100.1000-0): ";
	cin >> rut;
	cin.clear();
	cout << "\tIngrese el nombre y apellido del donador: ";
	cin >> name >> lastname;
	cin.clear();
	if (random) {
		donatedMoney = this->random(1000, 2000);
	}
	else {
		cout << "\tIngrese el total de la donacion: ";
		cin >> donatedMoney;
		if (cin.fail()) {
			cout << "\tERROR: Porfavor use solo numeros enteros..." << endl;
			return false;
		}
		else {
			if (donatedMoney <= 0) {
				cout << "\tNo puede donar una cantidad negativa o menor a 1..." << endl;
				return false;
			}
		}
	}
	Donation* donation = new Donation(rut, name, lastname, "si", donatedMoney); // Crea una donacion.
	donations->addDonation(*donation); // Guarda la donacion en la lista de donaciones.
	this->money += donatedMoney; // Suma el monto de la donacion a los fondos de la fundacion.
	cout << endl;

	cout << "\tSe ha registrado una donacion por $" << donatedMoney << " de " << name << " " << lastname << " con Rut: " << rut << endl;

	return true;
}

bool DogsSystem::adoptDog()
{
	dogs->print(); // Muestra la informacion de todos los perros en la lista de rescatados.
	cout << "\tPorfavor, ingrese el codigo del perro que quiere adoptar: ";
	string id = "";
	cin >> id;
	Dog dog = dogs->searchDog(id); // Busca el perro con la id dada.

	if (dog.getId()._Equal("")) // Verifica si el perro retornado tiene una ID, si no tiene id, significa que no se encuentra el perro.
	{
		cout << "\tNo se ha encontrado el perro con id = " << id << endl;
		return false;
	}
	if (adoptedDogs->exists(id)) { // Verifica si el perro no tiene duenio.
		cout << "\tError: Este perro ya tiene duenio..." << endl;
		return false;
	}
	int treatmentCost = 0; // Inicializa un costo de tratamiento.
	if (dog.getVaccinated()._Equal("no")) { // Si el perro no esta vacunado le suma al costo de tratamiento el costo de la vacuna.
		treatmentCost += vaccineCost;
	}
	if (dog.getSterilized()._Equal("no")) { // Si el pero no esta esterilizado le suma al costo  de tratamiento el costo de la esterilizacion.
		if (dog.getSex() == 'M') {
			treatmentCost += sterilizationCostMale;
		}
		else {
			treatmentCost += sterilizationCostFemale;
		}
	}

	if (treatmentCost > 0) { // Si el costo de tratamiento es mayor a cero, significa que el nuevo duenio tiene que cancelar el monto de tratamiento, y puede elegir si desea proseguir con la adopcion.
		cout << "\tPara adoptar este perro se necesita cancelar un monto de: $" << treatmentCost << " para sus tratamientos. ¿Desea aceptar? \n[1] Si \n[2] No" << endl;
		int option = validateOption(2);
		if (option == 0 || option == 2) {
			return false;
		}
	}
	else { // Si el costo es cero, significa que el perro no requiere un tratamiento y puede ser adoptado gratuitamente.
		cout << "\tEste perro tiene sus vacunas al dia y esta esterilizado, no es necesario cancelar nada" << endl;
	}
	/*
	Pide los datos del duenio y el nombre del perro.
	*/
	string dogName = "";
	string ownerRut = "";
	string ownerName = "";
	string ownerLastname = "";

	cout << "\tNombre a su perro: ";
	cin >> dogName;
	cin.clear();
	cout << "\tSu rut(Formato: 10.100.1000-0): ";
	cin >> ownerRut;
	cin.clear();
	cout << "\tSu nombre y apellido: ";
	cin >> ownerName >> ownerLastname;
	cin.clear();

	AdoptedDog adoptedDog = AdoptedDog(id, dogName, ownerRut, ownerName, ownerLastname); // Crea un perro adoptado
	adoptedDogs->addAdopted(adoptedDog); // Guarda el perro adoptado en la lista de adoptados.
	money += treatmentCost; // Suma a los fondos de la fundacion el costo del tratamiento.
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
