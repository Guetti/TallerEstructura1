#pragma once
#include "Donation.h"
class DonationList
{
public:
	DonationList();
	DonationList(int max);
	~DonationList();

	void addDonation(Donation newDonation);
	void expand();
	void print();
	string getText();

	int getSize();

private:
	Donation* list;
	int size;
	int max;
};

