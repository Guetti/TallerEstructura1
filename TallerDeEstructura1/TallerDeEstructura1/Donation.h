#pragma once
#include <string>
using namespace std;
class Donation
{
public:
	Donation(); //Constructor vacio
	Donation(int ammount); // Constructor donacion sin datos
	Donation(string donatorRut, string donatorName, string donatorLastname, string accounted, int ammount);
	~Donation();

	string getDonatorRut();
	string getDonatorName();
	string getDonatorLastname();
	string getAccounted();
	int getAmmount();

	void setDonatorRut(string donatorRut);
	void setDonatorName(string DonatorName);
	void setDonatorLastname(string donatorLastname);
private:
	string donatorRut;
	string donatorName;
	string donatorLastname;
	string accounted;
    int ammount;
};

