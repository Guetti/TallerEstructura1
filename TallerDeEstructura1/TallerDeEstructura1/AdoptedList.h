#pragma once
#include "AdoptedDog.h"
class AdoptedList // Utilizado para guardar perros adoptados.
{
public:
	AdoptedList(); //Constructor vacio.
	AdoptedList(int max); //Constructor predeterminado.
	~AdoptedList(); //Destructor.

	void addAdopted(AdoptedDog newAdopted); //Metodo agregar perro adoptado a la lista.
	void expand(); // Metodo para expandir la lista
	void print(); // Metodo para imprimir en pantalla los datos de la lista.
	AdoptedDog searchDog(string id); // Metodo para buscar un perro adoptado.
	AdoptedDog getDog(int index);
	bool exists(string id); // Metodo para verificar si existe un perro.
	string getText(); // Metodo que retorna los datos de la lista para guardarlas en un archivo de texto.
	int getSize(); // Metodo que retorna el tamanio de la lista.


private:
	AdoptedDog* list;	// Lista de perros adoptados.
	int size;			// Tamanio actual de la lista.
	int max;			// Tamanio maximo de la lista.
};

