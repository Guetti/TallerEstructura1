#pragma once
#include "Dog.h"
#include "Donation.h"
#include "DogList.h"
#include "AdoptedDog.h"
#include "AdoptedList.h"
#include "DonationList.h"
class DogsSystem // Sistema principal
{
public:
	DogsSystem(); // Constructor vacio
	DogsSystem(int money, int vaccineCost, int sterilizationCostMale,int sterilizationCostFemale); // Constructor predeterminado.
	~DogsSystem(); // Destructor

	void readFiles(); // Metodo para leer los archivos de texto y registrarlos en el sitema.

	/*
	Sub menus del programa
	*/
	void mainMenu();
	void searchDogMenu();
	void searchDonationMenu();
	void receiveDonationMenu();
	void adoptDogMenu();
	void stadisticsMenu();
	void exitAndSave();
	
	void startProgram();				// Metodo que inicia el programa.
	int validateOption(int maxOptions); // Metodo que verifica la opcion ingresada por el usuario. Retorna 0 en caso de ingresar caracteres no validos.
	
	bool searchDog();					// Metodo que simula la busqueda de un perro generando datos al azar.
	bool searchDonation();				// Metodo que simula la busqueda de donaciones generando.
	bool receiveDonation(bool random);	// Metodo para recibir una donacion. Recibe como parametro si se quiere realizar una donacion al azar para el metodo anterior.
	bool adoptDog();					// Metodo para dar perros en adopcion.
	string stadistics();				// Metodo que retorna las estadisticas.

	/*
	Metodos set para fijar los datos de los atributos.
	*/

	void setMoney(int money); 
	void setVaccineCost(int vaccineCost);
	void setSterilizationCostMale(int sterilizationCostMale);
	void setSterilizationCostFemale(int sterilizationCostFemale);
	
	/*
	Metodos get para obtener los datos de los atributos.
	*/
	int getMoney();
	int getVaccineCost();
	int getSterilizationCostMale();
	int getSterilizationCostFemale();



	int random(int min, int max);	// Metodo que retorna un numero al azar dado el maximo y minimo valor posible.
private:
	DogList* dogs;					// Lista de perros rescatados.
	AdoptedList* adoptedDogs;		// Lista de perros adoptados.
	DonationList* donations;		// Lista de donaciones.
	int money;						// Fondos de la fundacion.
	int vaccineCost;				// Costo de la vacuna.
	int sterilizationCostMale;		// Costo de esterilizacion para perros machos.
	int sterilizationCostFemale;	// Costo de esterilizacion para perros hembras.
};

