#include "Customer.h"


Customer AskForname(Customer  cus)
{
	char name[30];
	int len;
	printf("%s", "Please Enter Customer Name\n");

	fgets(name, 30, stdin);

	strcpy(cus.name, name, 20);

	return cus;
}

Customer AskForbalance(Customer  cus)
{
	
	printf("%s", "\nPlease Enter Customer Balance\n");

	double input;

	scanf_s("%lf", &input);

	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');

	cus.balance = input;

	fflush(stdin);
	// cus->balance = input;

	return cus;
}
