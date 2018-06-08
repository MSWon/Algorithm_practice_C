#include <stdio.h>
#include <ctype.h>

int main()
{
	char alphabet;
	
	printf("Input an Alphabet(a~z, A~Z): ");
	scanf_s("%c", &alphabet);
	printf(isalpha(alphabet) ? "\nCorresponding integer value of letter %c: %d\n" : "\nPlease input an Alphabet letter\n", alphabet, alphabet);	
	
	return 0;
}
