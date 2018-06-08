#include <stdio.h>

int main()
{
	int number;

	printf("Input an Integer (65~90, 97~122): ");
	scanf_s("%d", &number);
	printf( (number >=65 && number <= 90) || (number >= 97 && number <= 122) ? "\nCorresponding Alphabet letter of integer %d: %c" : "\nPlease input a valid range of integer value.", number, number);
	
	return 0;
}