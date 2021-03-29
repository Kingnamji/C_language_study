#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
#define MAX_LENGTH 80

typedef enum {lparen, rparen, plus, minus, times, divide, mod, eos, operand}precedence;

int stack[MAX_STACK_SIZE]; // ������ ������ stack
char expr[MAX_EXPR_SIZE]; // �����ڸ� ������ �迭
int top = -1;

// stack �� push , pop �Լ�
void push(int item);
int pop();
// postfix ���� �Լ�
precedence getToken(char* symbol, int* n); // ������, �ǿ����� ���� �� ��ū �и�
int eval(char* symbol);


// main �Լ�
int main()
{
	FILE* fp1, * fp2;
	char Token[MAX_LENGTH];
	int result;
	
	if (fopen_s(&fp1, "input.txt", "r"))
		exit(1);
	if (fopen_s(&fp2, "output.txt", "w"))
		exit(1);
	   	 
	fgets(Token, sizeof(Token), fp1); // input���� �Է� �޾ƿ���
	result = eval(Token); // �Լ� ���
	printf("postfix expression : %s\n", Token);
	printf("the evaluation value : %d", result);

	fprintf(fp2, "postfix expression : %s\n", Token);
	fprintf(fp2, "the evaluation value : %d", result);

	fclose(fp1);
	fclose(fp2);

	return 0;
}


// functions 
void push(int item) {
	if (top >= MAX_STACK_SIZE - 1)
		printf("stack is full\n");
	else stack[++top] = item;
}

int pop() {
	if (top == -1)
		printf("stack is empty\n");
	return stack[top--];
}

precedence getToken(char* symbol, int* n) // ������, �ǿ����� ���� �� ��ū �и�
{
	expr[++(*n)] = *(symbol + *n);
	switch (*(symbol+*n)) {
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