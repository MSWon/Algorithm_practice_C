#ifndef __STACK_H_
#define __STACK_H_

int isEmpty();
void push(char symbol);
void push_post(char opr);
void pushf(float op);
char pop();
char pop_post();
int popf();
char peek(void);
int reture_sp_post();

void postst(char arr[]);

#endif
