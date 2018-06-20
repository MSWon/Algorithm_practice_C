#include <stdio.h>

int c_number[100];

int max(int a, int b)
{
	return (a > b ? a : b);
}

int function(int coins[], int number)
{
	if (number == 0)
		return 0;
	else if (number == 1)
		return coins[1];
	else
		return max(coins[number] + function(coins, number - 2), function(coins, number - 1));
}

void value(int coins[], int n)
{

	if (n == 1)
		printf("C%d ", 1);
	else if (n == 2) {
		printf("C%d ", coins[1] > coins[2] ? 1 : 2);
	}
	else if (n > 2) {
		if (coins[n] + function(coins, n - 2) > function(coins, n - 1)) {
			value(coins, n - 2);
			printf("C%d ", n);
		}
		else {
			value(coins, n - 1);
		}
	}
}

