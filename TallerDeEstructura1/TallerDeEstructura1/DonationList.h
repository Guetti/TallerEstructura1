#pragma once
#include "Donation.h"
class DonationList // Lista de donaciones
{
public:
	DonationList(); // Constructor vacio.
	DonationList(int max); // Constructor predeterminado.
	~DonationList(); // Destructor.

	void addDonation(Donation newDonation); // Metodo para agregar una donacion a la lista.
	void expand(); // Metodo para expandir la lista.
	void print(); // Metodo para imprimir la lista.
	string getText(); // Metodo que retorna el los datos de la lista para guardarlos en un archivo de texto.

	int getSize(); // Metodo para obtener el tamanio de la lista.
	Donation getDonation(int index);

private: 
	Donation* list; // Lista de donaciones.
	int size; // Tamanio actual de la lista.
	int max; // Maximo de la lista.
};

