#include "DonationList.h"

DonationList::DonationList()
{
}

DonationList::DonationList(int max)
{
	list = new Donation[max];
	size = 0;
}

void DonationList::AddDonation(Donation newDonation)
{
	list[size] = newDonation;
	size++;
}
