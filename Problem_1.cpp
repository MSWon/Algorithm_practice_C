/*Program to receive New Car Price, Actual Car Price,
Insurance Quote before deduction, Final Insurance Quote
by using switch,while,break */

#include <stdio.h>

int main()
{
	char model;
	char carmodel[4];
	int carprice[4];
	float ndepricate;
	float depricate[4];
	int year, experience, liability;
	int ncarprice, acarprice,age;
	int IQ, FQ;
	int i;
	int printflag;


	carmodel[1] = 'A', carmodel[2] = 'B', carmodel[3] = 'C', carmodel[4] = 'D'; 
	carprice[1] = 50000000,carprice[2] = 35000000,carprice[3] = 20000000,carprice[4] = 10000000;
	depricate[1] = 0.05, depricate[2] = 0.04, depricate[3] = 0.03, depricate[4] = 0.02;
	printflag = 1;
	
	switch (printflag)
	{
	case 1:
		printf("Enter Car Model(A/B/C/D):");
		scanf_s("%c", &model, sizeof(model));
		i = 1;
		while (i <= 4) {
			if (model == carmodel[i]) {
				ncarprice = carprice[i];
				ndepricate = depricate[i];
				break;
			}
			i++;
		}
		if (1 <= i&&i <= 4) {
			ncarprice = carprice[i];
			ndepricate = depricate[i];
		}
		else {

			i = 1;
			while (model != carmodel[i]) {
				getchar();
				printf("\nInvalid Model. Enter Model(A/B/C/D) or Q for quit:");
				scanf_s("%c", &model, sizeof(model));

				if (model == carmodel[i]) {
					ncarprice = carprice[i];
					ndepricate = depricate[i];
					goto g;
				}
				else {
					if (model == 'Q') {
						goto f;
					}
					else {
						continue;
					}
				}
				i++;
			}
		f:
			break;
		g:
			;
		}
	case 2:
		printf("\nEnter Year of Car:");
		scanf_s("%d", &year);
		if (year <= 2016) {
			year = year;
		}
		else {
				while (1) {
					printf("\nInvalid Year.Enter Year of Car or Q for quit:");
					scanf_s("%d", &year);

					if (year <= 2016) {
						goto u;
						break;
					}
					if (getchar() == 'Q') {
						goto t;
						break;
					}
				}
			t:
				break;
			u:
				year = year;
			}
		

	case 3:
		printf("\nEnter Driving Experience:");
		scanf_s("%d", &experience);
		if (experience >= 0) {
			experience = experience;
		}
		else {
		
				while (1) {
					printf("\nInvalid number. Enter Driving Experience or Q for quit:");
					scanf_s("%d", &experience);
					if (experience >= 0) {
						goto v;
						break;
					}
					if (getchar() == 'Q') {
						goto s;
						break;
					}
				}
			s:
				break;
			v:
				experience = experience;
			}
		
	case 4:
		printf("\nSelect Property Damage Liability(1/2):");
		scanf_s("%d", &liability);
		if (liability == 1 || liability == 2) {
			liability = liability;
		}
		else {
			while (1) {
				getchar();
				printf("\nInvalid option. Select Property Damage Liability(1/2):");
				scanf_s("%d", &liability);
				if (liability == 1 || liability == 2) {
					break;
				}
			}
		}

	case 5:
		age = 2016 - year;
		acarprice = ncarprice - ncarprice*ndepricate*age;
		if (liability == 1) {
			IQ = 100000 + 50000 + (acarprice*0.02);
		}
		else if (liability == 2) {
			IQ = 100000 + 100000 + (acarprice*0.02);
		}
		if(experience >= 20) {
			FQ = IQ - (IQ*0.03*20);
		}
		else {
			FQ = IQ - (IQ*0.03*experience);
		}

		printf("\nNew Car Price:%d\n", ncarprice);
		printf("\nActual Car Price:%d\n", acarprice);
		printf("\nInsurance Quote before deduction:%d\n", IQ);
		printf("\nFinal Insurance Quote:%d\n", FQ);
	}
		
	return 0;
}