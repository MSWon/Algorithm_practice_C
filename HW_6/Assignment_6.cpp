#include <stdio.h>
#include "postfix.h"
#include "stack.h"

#define MAX 256
int main()
{
	char	infix[MAX];

	printf("enter the infix expression:");
	scanf_s("%s", infix,sizeof(infix));

	printf("\nPostfix expression:");
	infix_to_postfix(infix);
	printf("\n");
	printf("The result of the expression %s = %d\n", infix,popf());

	return 0;
}