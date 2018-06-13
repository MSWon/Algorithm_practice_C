#include <stdio.h>
#include <limits.h>
#include "Dec2Bin.h"

int main(void)
{
	while (1)
	{

		printf("Enter 2 Numbers [-2,147,483,648,  2,147,483,647]:");
		long long int N1, N2;
		scanf_s("%lld %lld", &N1, &N2);

		if ((N1 < INT_MIN) || (N1 > INT_MAX) || (N2 <-INT_MIN) || (N2 > INT_MAX))
		{
			printf("Invalid input. Please enter inputs again.\n");
			continue;
		}
		if ((N1 == 0) || (N2 == 0))
			break;

		printf("\nN1      DEC %+011d: BIN ", N1); //N1에 대해 출력
		Bin(N1);
		printf("(%d)", Bin2(N1));
		printf("\n");

		printf("N2      DEC %+011d: BIN ", N2); //N2에 대해 출력
		Bin(N2);
		printf("(%d)\n", Bin2(N2));
		printf("\n");

		printf("N1&N2   DEC %+011d: BIN ", N1&N2); //N1&N2에 대해 출력
		Bin(N1&N2);
		printf("(%d)\n", Bin2(N1&N2));

		printf("N1|N2   DEC %+011d: BIN ", N1 | N2); //N1|N2에 대해 출력
		Bin(N1 | N2);
		printf("(%d)\n", Bin2(N1 | N2));

		printf("N1^N2   DEC %+011d: BIN ", N1 ^ N2); //N1^N2에 대해 출력
		Bin(N1 ^ N2);
		printf("(%d)\n", Bin2(N1 ^ N2));

		printf("N1<<8   DEC %+011d: BIN ", N1 << 8); //N1<<8에 대해 출력
		Bin(N1 << 8);
		printf("(%d)\n", Bin2(N1 << 8));

		printf("N2>>8   DEC %+011d: BIN ", N2 >> 8); //N2>>8에 대해 출력
		Bin(N2 >> 8);
		printf("(%d)\n", Bin2(N2 >> 8));
		break;
	}
	return 0;
}