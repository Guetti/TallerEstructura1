#pragma once
#include <string>
using namespace std;
class Donation // Donacion
{
public:
	Donation(); //Constructor vacio
	Donation(string donatorRut, string donatorName, string donatorLastname, string accounted, int ammount); // Constructor predeterminado.
	~Donation(); // Destructor.

	/*
	Metodos get para obtener datos de los atributos.
	*/

	string getDonatorRut(); 
	string getDonatorName();
	string getDonatorLastname();
	string getAccounted();
	int getAmmount();

	/*
	Metodos set para fijar datos de los atributos.
	*/
	void setDonatorRut(string donatorRut);
	void setDonatorName(string DonatorName);
	void setDonatorLastname(string donatorLastname);
private:
	string donatorRut; // Rut del donante.
	string donatorName; // Nombre del donante.
	string donatorLastname; // Apellido del donante.
	string accounted; // Si se encuentra contabilizada la donacion.
    int ammount; // monto donado.
};

