#pragma once

#include <stdio.h>


typedef struct
{
	char winename[30];
	double price;
	int quanity;
}Wine;



Wine AskForWineName(Wine wine);

Wine AskForWinePrice(Wine wine);

Wine AskForWineQuantity(Wine wine);
