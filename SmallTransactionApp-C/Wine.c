#include "Wine.h"

Wine AskForWineName(Wine wine)
{

	char  nameofwine[30];

	printf("%s", "\nPlease Enter Wine Name\n");

	fgets(nameofwine, 30, stdin); 

	strcpy(wine.winename, nameofwine, 20);

	return wine;

}

Wine AskForWinePrice(Wine wine)
{
	printf("%s", "\nPlease Enter Wine Price\n");

	double priceofwine;

	scanf_s("%lf", &priceofwine);

	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');

	wine.price = priceofwine;

	return wine;
}

Wine AskForWineQuantity(Wine wine)
{
	printf("%s", "\nPlease Enter Quantity of Wine\n");

	int quanutityofwine;

	scanf_s("%d", &quanutityofwine);

	int c;
	do {
		c = getchar();
	} while (c != EOF && c != '\n');

	wine.quanity = quanutityofwine;

	return wine;
}
