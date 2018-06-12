/*Program to receive two natural numbers that satisfy gcm,lcd 
and maximize the sum of those. */

#include <stdio.h>
#include <math.h>
int main()
{
	int gcd, lcm;
	int mult;
	int x, y;
	int a, b;
	int min;
	int i;
	int printflag;
	char type;

	printflag = 2;

	while (1) {
		if (printflag ==3) {
			break;
		}
			switch (printflag)
			{
			case 1:
				printf("\nNot valid input.");
			case 2:
				printflag = 2;
				printf("Enter GCD and LCM between 2 to 100,000,000 :");
				scanf_s("%d %d", &gcd, &lcm);
				getchar();
				if ((2 <= gcd&&gcd <= 100000000) && (2 <= lcm&&lcm <= 100000000)) {

					if (lcm%gcd == 0) {

						mult = lcm / gcd;
						min = 10000000;

						for (i = 1; i <= sqrt(mult); i++) {
							if (mult%i == 0) {
								x = i;
								y = mult / i;
							}
							if (x + y <= min) {
								min = x + y;
							}
						}

						printf("\nTwo natural numbers to satisfy the GCD and LCM:%d %d\n", gcd * x, gcd * y);
						printf("\nType C for continue or Q for quit:");
						scanf_s("%c", &type,sizeof(type));
						if (type == 'C') {
							printf("\n");
							continue;
						}
						else if (type == 'Q') {
							printf("\nBye\n");
							printflag = 3;
							break;
						}
					}
					else {
						printf("\nNo natural number set can satisfy this condition\n");
						printf("\nType C for continue or Q for quit:");
						scanf_s("%c", &type,sizeof(type));
						if (type == 'C') {
							printf("\n");
							continue;
						}
						else if (type == 'Q') {
							printf("\nBye\n");
							printflag = 3;
							break;
						}
					}
				}
				else {
					printflag = 1;
					continue;
				}
			}
		}
	return 0;
}