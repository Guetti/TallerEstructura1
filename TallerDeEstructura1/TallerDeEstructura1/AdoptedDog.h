#pragma once
#include <string>
using namespace std;
class AdoptedDog // Perro adoptado
{
public:
	AdoptedDog(); //Constructor vacio.
	AdoptedDog(string id, string dogName, string ownerRut, string ownerName, string ownerLastname); //Constructor predeterminado.
	~AdoptedDog(); //Destructor.
	
	/*
	Metodos get para obtener atributos.
	*/

	string getId();
	string getDogName();
	string getOwnerRut();
	string getOwnerName();
	string getOwnerLastname();

	/*
	Metodos set para fijar atributo.
	*/

	void setId(string id);
	void setDogName(string dogName);
	void setOwnerRut(string ownerRut);
	void setOwnerName(string ownerName);
	void setOwnerLastname(string ownerLastname);

private:
	string id;				// Codigo del perro.
	string dogName;			// Nombre del perro.
	string ownerRut;		// Rut del duenio.
	string ownerName;		// Nombre del duenio.
	string ownerLastname;	// Apellido del duenio.
};

