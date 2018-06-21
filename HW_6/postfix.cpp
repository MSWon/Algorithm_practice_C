#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "stack.h"
#define MAX 256

int		brac = 0;							// ��ȣ�� ������ 0���� �����Ѵ�.

int prec(char op) {		//�ش� �����ڳ� ��ȣ�� ���� �켱������ ��ȯ�ϴ� �Լ�
	switch (op) {
	case'(': case')': return 0;
	case'+': case'-': return 1;
	case'*': case'/': case'%': return 2;
	}

	return -1;
}

void result(char ch) {		//�ش� �����ڿ� ���ؼ� ����� �ϰ� ��� ����� �ǿ����� ���ÿ� �ִ´�

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

void infix_to_postfix(char infix[]) {	// ������ ������ �ٲٴ� �Լ�

	int i;				// �ݺ����� �� ����
	int j = 0;			// �Ҽ��� ���ڸ� �ӽ������� �迭�� index
	char ch, top_op;	// �ӽ� �����ڸ� ������ ������, �迭�� �ش� �ε����� ĳ���͸� ������ ����
	char postf[MAX] = { 0 };	// �Ҽ��� ���ڸ� �ӽ������� �迭�� �ʱ�ȭ�� ���ÿ� �����Ѵ�
	int len = strlen(infix);	// ����������� ���̸� �޾ƿ´�

	for (i = 0; i < len; i++) {
		ch = infix[i];

		switch (ch) {			// ch�� ������ case�� ���� ó���Ѵ�
		case'+':
		case'-':
		case'*':
		case'/':
		case'%':

			while (!isEmpty() && (prec(ch) <= prec(peek()))) {	// ������ ���� �ʰ� �켱������ ���ٸ�
				char ch2 = pop();		// �װ��� ������
				push_post(ch2);			// �������꽺�ÿ� �ְ�
				printf("%c", ch2);		// ����ϰ�
				result(ch2);			// �ش� �����ڿ� ���� ����Ѵ�
			}
			push(ch);		// ���ÿ� �ִ´�
			break;

		case'(':			// ������ ��ȣ�ϰ��
			brac++;			// ��ȣ�� ������ �ϳ� �ø���
			push(ch);		// �̸� ���ÿ� �ִ´�
			break;

		case')':			// �ݴ� ��ȣ�� ���
			brac--;			// ��ȣ�� ������ �ϳ� ���̰� 
			top_op = pop();

			while (top_op != '(') {		// top_op�� ������ȣ�϶� ����
				printf("%c", top_op);
				push_post(top_op);
				result(top_op);
				top_op = pop();			// ���� ���� ����ϰ� ������ ����Ѵ�
			}
			break;

		default:				// �ǿ������� ���
			printf("%c", ch);	// ����ϰ�
			push_post(ch);		// �ǿ����ڽ��ÿ� �ְ�
			postf[j] = ch;		// char�� float���� ��ȯ�ϱ� ���� �ٸ� �迭�� �ӽ������ϰ�
			j++;				// �ӽ� ����迭�� �ε����� ������Ų��

			if (isdigit(infix[i + 1]) == 0 && infix[i + 1] != '.') {	// �ش��ε��� ������ �������̸� �ű������ �ϳ��� �����̹Ƿ�
					// �������� ���ڸ� �������ְ�
				pushf(atof(postf));	// �̸� float������ ��ȯ���ְ�
				j = 0;				// �ӽ�����迭�� �ε����� 0���� �ʱ�ȭ�Ѵ�

				for (int l = 0; l < MAX; l++)	//�ӽ�����迭 ����
					postf[l] = 0;
			}
			break;
		}
	}

	while (!isEmpty()) {		// ���� ���ÿ� ���� �����ִٸ�
		char ch3 = pop();
		printf("%c", ch3);
		push_post(ch3);
		result(ch3);
		// ������ ����ϰ� �������꽺�ÿ� �ְ� ����Ѵ�
	}
}
