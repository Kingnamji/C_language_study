#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
#define MAX_LENGTH 80

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand}precedence;

int stack[MAX_STACK_SIZE];
char expr[MAX_EXPR_SIZE];
int top = -1;

int eval(char* symbol);

int main(void)
{	
	FILE* fp1, * fp2;
	char Token[MAX_LENGTH];
	int result;

	fopen_s(&fp1, "input.txt", "r");
	fopen_s(&fp2, "output.txt", "w");

	if (fp1 == NULL || fp2 == NULL)
		exit(1);

	fgets(Token, MAX_LENGTH, fp1);
	result = eval(Token);

	return 0;
}

void push(int item) {
	if (top >= MAX_STACK_SIZE - 1)
		printf("stack is full");
	else stack[++top] = item;
}

precedence getToken(char* symbol, int* n) // 연산자, 피연산자 구분 및 토큰 분리
{
	expr[++(*n)] = *(symbol + *n);
	switch (*(symbol + *n)) {
	case '(': return lparen;
	case ')': return rparen;
	case '+': return plus;
	case '-': return minus;
	case '/': return divide;
	case '*': return times;
	case '%': return mod;
	case '\0': return eos;
	default: return operand;
	}
}

int eval(char* symbol)
{
	precedence token;
	int op1, op2;
	int n = -1;
	token = getToken(symbol, &n);

	while (token != eos) {
		if (token == operand)
			push(symbol[n] - '0'); // use ASCII CODE
		else
		{
			op2 = pop();
			op1 = pop();
			switch (token) {
			case plus: push(op1 + op2); break;
			case minus: push(op1 - op2); break;
			case times: push(op1 * op2); break;
			case divide: push(op1 / op2); break;
			case mod: push(op1 % op2);
			}
		}
		token = getToken(symbol, &n);
	}
	return pop();
}