#pragma once
#include <string>
using namespace std;
class Dog
{
public:
	Dog();
	Dog(string id, char size, int age, char sex, string vaccinated, string sterilized);
	~Dog();

	string getId();
	char getSize();
	int getAge();
	char getSex();
	string getVaccinated();
	string getSterilized();

	void setId(string id);
	void setSize(char size);
	void setAge(int age);
	void setSex(char sex);
	void setVaccinated(string vaccinated);
	void setSterilized(string vaccinated);
	
private:
	string id;
	char size;
	int age;
	char sex;
	string vaccinated;
	string sterilized;
};

