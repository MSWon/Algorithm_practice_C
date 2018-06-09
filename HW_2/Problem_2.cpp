#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	int target[3];
	int guess[3];
	int strike, ball;
	int i,j;
	int ret = 0;

	srand((unsigned int)time(NULL));
	target[1] = rand() % 9 + 1;
	target[2] = rand() % 9 + 1;
	target[3] = rand() % 9 + 1;

	while (target[2] == target[1]){
		   target[2] = rand() % 9 + 1;
	}
	while (target[3] == target[2] || target[3] == target[1]){
		   target[3] = rand() % 9 + 1;
	}


	while (1) {
		strike = 0, ball = 0;
		printf("Input three numbers (mutually-exclusive) between 1 and 9: ");
		ret = scanf_s("%d %d %d", &guess[1], &guess[2], &guess[3]);
		while (getchar() != '\n');
		if (ret == 0) {
			printf("Not a valid input\n");
		}

		else {

			if (guess[1] == guess[2] || guess[2] == guess[3] || guess[1] == guess[3]) {
				printf("Not a valid input\n");
			}
			else {

				if ((guess[1] >= 1 && guess[1] <= 9) && (guess[2] >= 1 && guess[2] <= 9) && (guess[3] >= 1 && guess[3] <= 9)) {

					for (i = 1; i <= 3; i++) {

						for (j = 1; j <= 3; j++) {

							if (guess[i] == target[j]) {

								if (i == j) {
									strike++;
								}
								else {
									ball++;
								}
							}
						}
					}
					if (strike == 3) {
						printf("3 Strike Out\n");
						break;
					}
					else {
						printf("\n%d Strike %d Ball\n\n", strike, ball);
					}
				}
				else {
					printf("Not a valid input\n");
				}
			}
		}
	}
	return 0;
}