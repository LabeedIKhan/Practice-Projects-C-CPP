
#include <stdio.h>
#include "Customer.h"
#include "Wine.h"
#include "Inheritance.h"

Customer DoTransaction(Customer * cus, double val);
double WineValue(double price, int quan);

int main()
{
	
	Customer customer;

	Customer* c = &customer;

	customer = AskForname(customer);

	printf("Your Name is: %s", customer.name);

	customer = AskForbalance(customer);

	printf("Your Name is: %lf", customer.balance);

	while (1)
	{
		Wine wine;

		Wine* w = &wine;

		wine = AskForWineName(wine);

		if (wine.winename[0] == '\n')
			break;

		wine = AskForWinePrice(wine);

		wine = AskForWineQuantity(wine);

		double val = WineValue(wine.price, wine.quanity);

		customer = DoTransaction(c, val);
	}

	printf("Final Details Are \n");
	printf("Customer Name : %s", customer.name); printf("Customer Balance : %lf", customer.balance);

}



Customer DoTransaction(Customer * cus, double val) 
{
     cus->balance = (*cus).balance * val;

	 return *cus;
}

double WineValue(double price, int quan)
{
	double val = 0;

	val = price * val;

	return val;
}

