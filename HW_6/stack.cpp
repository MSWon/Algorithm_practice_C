#include	<stdio.h>
#include	<string.h>
#include	<stdlib.h>

#define		MAX 256 

char	stack[MAX];		
float	stackf[MAX];	
char	stackpost[MAX];	// 후위연산으로 바꾼스택

int sp = -1;		// 초기 top 값을 -1로 초기화
int sp_post = -1;	// 후위연산스택의 스택포인터
int sp_f = -1;		// 숫자스택의 스택포인터





		
int isEmpty()
{
	if (sp == -1)
		return 1;
	else
		return 0;
}



int isEmpty_post()
{
	if (sp_post == -1)
		return 1;
	else
		return 0;
}



void push(char symbol)
{
	if (sp>MAX)
	{
		printf("Stack overflow\n");
		exit(1);
	}
	stack[++sp] = symbol;
}
char pop() {
	if (isEmpty())
	{
		printf("Stack underflow\n");
		exit(1);
	}
	return (stack[sp--]);
}




void push_post(char opr) {

	if (sp_post > MAX) {
		printf("Stack overflow\n");
		exit(1);
	}
	stackpost[++sp_post] = opr;
}
char pop_post() {
	if (isEmpty_post()) {
		printf("Stack underflow\n");
		exit(1);
	}
	return (stackpost[sp_post--]);
}


void pushf(float op) {
	if (sp_f > MAX) {
		printf("Stack overflow\n");
		exit(1);
	}
	stackf[++sp_f] = op;
}
int popf() {
	if (sp_f<0) {
		printf("Stack underflow\n");
		exit(1);
	}
	return (stackf[sp_f--]);

}

char peek(void) {

	if (isEmpty()) {
		printf("Stack is empty.\n");
		exit(1);
	}
	return stack[sp];
}


void postst(char arr[]) {
	for (int i = 0; i <= sp_post; i++) {
		arr[i] = stackpost[i];
	}
}


int reture_sp_post() {
	return sp_post;
}

