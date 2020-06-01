#pragma once
#include "Dog.h"

class DogList // Utilizado para guardar perros rescatados.
{
public:
	DogList(); // Constructor vacio.
	DogList(int max); // Constructor predeterminado.
	~DogList(); // Destructor.

	void addDog(Dog newDog); // Metodo para agregar un perro a la lista.
	void expand(); // Metodo para expandir la lista.
	void print(); // Metodo para imprimir los datos de la lista
	Dog searchDog(string id); // Metodo para buscar un perro en la lista.
	bool exists(string id); // Verifica si un perro existe en la lista dada su id.
	string getText(); // Metodo que retorna los datos de la lsita para guardarlo en un archivo de texto.

	int getSize(); // Metodo que retorna el tamanio de la lista.
	int getMaleAmmount(); // Metodo que retorna la cantidad de perros machos.
	int getFemaleAmmount(); // Metodo que retorna la cantidad de perros hembras.


private:
	Dog* list; // Lista de perros

	int size; // Tamanio de la lista.
	int max; // Maximo de la lista.
};

