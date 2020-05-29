#include <iostream>
#include "DogsSystem.h"

int insertOption(int options)
{
	int n;
	
	cin >> n;
	if (!cin) // o también if(cin.fail())
	{
		// El usuario no introdujo un número
		cin.clear(); // Borrar la entrada fallida
		cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); //Saltar la entrada no válida
		// Aquí poner código para volver a pedirle al usuario que introduzca un número
	}

	if (n > options || n <= 0) {
		cout << "Por favor ingrese una opcion valida" << endl;
		return -1;
	}

	return n;
}



void searchDonationMenu(DogsSystem system)
{
}

void receiveDonationMenu(DogsSystem system)
{
}

void adoptDogMenu(DogsSystem system)
{
}

void stadisticsMenu(DogsSystem system)
{

}

void save(DogsSystem system) {

}



int main()
{
	DogsSystem* dogsSystem = new DogsSystem(150000, 5000, 10000, 15000);
	dogsSystem->startProgram();
}