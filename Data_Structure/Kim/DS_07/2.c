#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_STACK_SIZE 100
#define MAX_EXPR_SIZE 100
#define MAX_LENGTH 80

typedef enum { lparen, rparen, plus, minus, times, divide, mod, eos, operand }precedence;

precedence stack[MAX_STACK_SIZE]; // 과정을 저장할 stack
char expr[MAX_EXPR_SIZE]; // 연산자를 저장할 배열
int isp[] = { 0, 19, 12, 12 ,13, 13, 13 ,0 };
int icp[] = { 20, 19, 12, 12 ,13, 13, 13 ,0 };
int top = 0;

// stack 의 push , pop 함수
void push(precedence item);
precedence pop();
// postfix 관련 함수
void printToken(precedence token);
precedence getToken(char* symbol, int* n); // 연산자, 피연산자 구분 및 토큰 분리
void postfix(void);


FILE* fp1, * fp2;
// main 함수
int main()
{	int result;

	if (fopen_s(&fp1, "input.txt", "r"))
		exit(1);
	if (fopen_s(&fp2, "output.txt", "w"))
		exit(1);

	fgets(expr, sizeof(expr), fp1); // input에서 중위표기법 표현 수식 받아오기

	printf("<<<<<<<<<< infix to postfix >>>>>>>>>>\n");
	printf("infix expression          : %s\n", expr);
	printf("postfix expression        : ");
	postfix();

	fclose(fp1);
	fclose(fp2);

	return 0;
}


// functions 
void push(precedence item) {
	if (top >= MAX_STACK_SIZE - 1)
		printf("stack is full\n");
	else stack[++top] = item;
}

precedence pop() {
	if (top == -1)
		printf("stack is empty\n");
	return stack[top--];
}

precedence getToken(char* symbol, int* n) // 연산자, 피연산자 구분 및 토큰 분리
{
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

void printToken(precedence token)
{
	switch (token) {
	case lparen: printf("("); fprintf(fp2, "%c", '('); break;
	case rparen: printf(")"); fprintf(fp2, "%c", ')'); break;
	case plus: printf("+"); fprintf(fp2, "%c", '+'); break;
	case minus: printf("-"); fprintf(fp2, "%c", '-'); break; 
	case divide: printf("/"); fprintf(fp2, "%c", '/'); break;
	case times: printf("*"); fprintf(fp2, "%c", '*'); break;
	case mod: printf("%%"); fprintf(fp2, "%c", '%%'); break;
	case eos: printf("\0"); fprintf(fp2, "%c", '\0'); break;
	}
}

void postfix(void)
{
	precedence token;
	stack[0] = eos;
	int n = 0;

	for (token = getToken(expr, &n); token != eos; token = getToken(expr, &n))
	{
		if (token == operand) // token이 피연산자이면 바로 출력한다.
		{
			printf("%c", expr[n]);
			fprintf(fp2, "%c", expr[n]);
		}
		else if (token == rparen) {
			while (stack[top] != lparen)
				printToken(pop());
			pop();
		}
		else {
			while (isp[stack[top]] >= icp[token])
				printToken(pop());
			push(token);
		}
		n++;
	}
	while ((token = pop()) != eos)
		printToken(token);
}
