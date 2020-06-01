#pragma once
#include <string>
using namespace std;
class Dog // Perro
{
public:
	Dog(); // Constructor vacio.
	Dog(string id, char size, int age, char sex, string vaccinated, string sterilized); // Constructor predetermiando.
	~Dog(); // Destructor.

	/*
	Metodos get para obtener datos de los atributos.
	*/
	string getId();
	char getSize();
	int getAge();
	char getSex();
	string getVaccinated();
	string getSterilized();

	/*
	Metodos set para fijar datos de los atributos.
	*/
	void setId(string id);
	void setSize(char size);
	void setAge(int age);
	void setSex(char sex);
	void setVaccinated(string vaccinated);
	void setSterilized(string vaccinated);
	
private:
	string id; // Codigo del perro.
	char size; // Tamanio del perro (G = Grande, M = Mediano, P = Pequenio).
	int age; // Edad del perro
	char sex; // Sexo del perro (H = Hembra, M = Macho).
	string vaccinated; // Si se encuentra vacunado. 
	string sterilized; // Si se encuentra esterilizado.
};

