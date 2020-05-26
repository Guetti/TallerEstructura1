#pragma once
#include <string>
using namespace std;
class AdoptedDog
{
public:
	AdoptedDog();
	AdoptedDog(string id, string dogName, string ownerRut, string ownerName, string ownerLastname);

	string getId();
	string getDogName();
	string getOwnerRut();
	string getOwnerName();
	string getOwnerLastname();

	void setId(string id);
	void setDogName(string dogName);
	void setOwnerRut(string ownerRut);
	void setOwnerName(string ownerName);
	void setOwnerLastname(string ownerLastname);
private:
	string id;
	string dogName;
	string ownerRut;
	string ownerName;
	string ownerLastname;
};

