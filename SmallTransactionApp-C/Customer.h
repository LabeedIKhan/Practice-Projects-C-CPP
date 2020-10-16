#pragma once

#include <stdio.h>

typedef struct
{
	char name[30];
	double balance;

}Customer;

Customer AskForname(Customer  cu);

Customer AskForbalance(Customer cu);

