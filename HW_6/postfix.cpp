#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#define MAX 256

int		brac = 0;							// 괄호의 갯수는 0으로 시작한다.

int prec(char op) {		//해당 연산자나 괄호에 대해 우선순위를 반환하는 함수
	switch (op) {
	case'(': case')': return 0;
	case'+': case'-': return 1;
	case'*': case'/': case'%': return 2;
	}

	return -1;
}

void result(char ch) {		//해당 연산자에 대해서 계산을 하고 계산 결과를 피연산자 스택에 넣는다

	int op1, op2;

	if (ch == '+') {
		op2 = popf();
		op1 = popf();
		pushf(op1 + op2);
	}
	else if (ch == '-') {
		op2 = popf();
		op1 = popf();
		pushf(op1 - op2);
	}
	else if (ch == '*') {
		op2 = popf();
		op1 = popf();
		pushf(op1*op2);
	}
	else if (ch == '/') {
		op2 = popf();
		op1 = popf();
		pushf(op1 / op2);
	}
	else if (ch == '%') {
		op2 = popf();
		op1 = popf();
		pushf(op1 % op2);
	}

	return;

}

void infix_to_postfix(char infix[]) {	// 중위를 후위로 바꾸는 함수

	int i;				// 반복문에 쓸 변수
	int j = 0;			// 소수인 숫자를 임시저장할 배열의 index
	char ch, top_op;	// 임시 연산자를 저장할 변수와, 배열의 해당 인덱스의 캐릭터를 저장할 변수
	char postf[MAX] = { 0 };	// 소수인 숫자를 임시저장할 배열을 초기화와 동시에 선언한다
	int len = strlen(infix);	// 중위연산식의 길이를 받아온다

	for (i = 0; i < len; i++) {
		ch = infix[i];

		switch (ch) {			// ch를 다음의 case에 따라 처리한다
		case'+':
		case'-':
		case'*':
		case'/':
		case'%':

			while (!isEmpty() && (prec(ch) <= prec(peek()))) {	// 스택이 비지 않고 우선순위가 높다면
				char ch2 = pop();		// 그것을 꺼내서
				push_post(ch2);			// 후위연산스택에 넣고
				printf("%c", ch2);		// 출력하고
				result(ch2);			// 해당 연산자에 대해 계산한다
			}
			push(ch);		// 스택에 넣는다
			break;

		case'(':			// 열리는 괄호일경우
			brac++;			// 괄호의 갯수를 하나 늘리고
			push(ch);		// 이를 스택에 넣는다
			break;

		case')':			// 닫는 괄호일 경우
			brac--;			// 괄호의 갯수를 하나 줄이고 
			top_op = pop();

			while (top_op != '(') {		// top_op가 열린괄호일때 까지
				printf("%c", top_op);
				push_post(top_op);
				result(top_op);
				top_op = pop();			// 안의 것을 출력하고 꺼내서 계산한다
			}
			break;

		default:				// 피연산자일 경우
			printf("%c", ch);	// 출력하고
			push_post(ch);		// 피연산자스택에 넣고
			postf[j] = ch;		// char을 float으로 변환하기 위해 다른 배열에 임시저장하고
			j++;				// 임시 저장배열의 인덱스를 증가시킨다

			if (isdigit(infix[i + 1]) == 0 && infix[i + 1] != '.') {	// 해당인덱스 다음이 연산자이면 거기까지가 하나의 숫자이므로
					// 공백으로 숫자를 구분해주고
				pushf(atof(postf));	// 이를 float형으로 변환해주고
				j = 0;				// 임시저장배열의 인덱스를 0으로 초기화한다

				for (int l = 0; l < MAX; l++)	//임시저장배열 비우기
					postf[l] = 0;
			}
			break;
		}
	}

	while (!isEmpty()) {		// 만약 스택에 뭔가 남아있다면
		char ch3 = pop();
		printf("%c", ch3);
		push_post(ch3);
		result(ch3);
		// 꺼내서 출력하고 후위연산스택에 넣고 계산한다
	}
}
