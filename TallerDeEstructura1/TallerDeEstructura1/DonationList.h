#pragma once
#include "Donation.h"
class DonationList
{
public:
	DonationList();
	DonationList(int max);

	void AddDonation(Donation newDonation);
	
private:
	Donation* list;
	int size;
};

