#pragma once
#include <string>
using namespace std;
class Donation
{
public:
	Donation();
	Donation(string donatorRut, string donatorName, string donatorLastname, string accounted, int ammount);

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

