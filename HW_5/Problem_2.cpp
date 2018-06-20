#include <stdio.h>
#include "coin.h"

int main()
{
	int number;
	int coins[100];

	coins[0] = 0;
	printf("enter the number of coins:");
	scanf_s("%d", &number);
	printf("enter the value of all coins:");
	for (int i = 1; i <= number; i++)
	{
		scanf_s("%d", &coins[i]);
	}



	printf("\nThe maximum amount of coin:%d\n", function(coins, number));
	printf("The selected coins to get maximum value:");
	value(coins, number);

	return 0;
}

