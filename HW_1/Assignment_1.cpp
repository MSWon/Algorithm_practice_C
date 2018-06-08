#include <stdio.h>

int main()
{
	int a, b, sum, difference, multiplication, quotient, remainder;

	printf("Input two integers:");
	scanf_s("%d %d", &a, &b);
	sum = a + b;
	difference = a - b;
	multiplication = a*b;
	quotient = a / b;
	remainder = a%b;
	printf("\nSum:%d\n", sum);
	printf("Difference:%d\n", difference);
	printf("Multiplication:%d\n", multiplication);
	printf("Quotient:%d\n", quotient);
	printf("Remainder:%d\n", remainder);

	return 0;
}
