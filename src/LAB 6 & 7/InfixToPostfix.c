#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define SIZE 100

int Precedence(char Operator) {
	switch (Operator) {
	case '+':
	case '-':
		return 1;
	case '*':
	case '/':
		return 2;
	case '^':
		return 3;
	default:
		return -1;
	}
}

int Operator(char ch) {
	return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

char* InfixToPostfix(char* Infix) {
	int i, j;
	int len = strlen(Infix);
	char* Postfix = (char*)malloc(sizeof(char) * (len + 2));
	char Stack[SIZE];
	int top = -1;

	for (i = 0, j = 0; i < len; i++) {
		if (Infix[i] == ' ' || Infix[i] == '\t')
			continue;
		if (isalnum(Infix[i])) {
			Postfix[j++] = Infix[i];
		}
		else if (Infix[i] == '(') {
			Stack[++top] = Infix[i];
		}
		else if (Infix[i] == ')') {
			while (top > -1 && Stack[top] != '(')
				Postfix[j++] = Stack[top--];
			if (top > -1 && Stack[top] != '(')
				return "Invalid Expression";
			else
				top--;
		}
		else if (Operator(Infix[i])) {
			while (top > -1 && Precedence(Stack[top]) >= Precedence(Infix[i]))
				Postfix[j++] = Stack[top--];
			Stack[++top] = Infix[i];
		}
	}
	while (top > -1) {
		if (Stack[top] == '(') {
			return "Invalid Expression";
		}
		Postfix[j++] = Stack[top--];
	}
	Postfix[j] = '\0';
	return Postfix;
}

int main() {
	char Infix[SIZE] = "a+b*(c^d-e)^(f+g*h)-i";
	char* Postfix = InfixToPostfix(Infix);
	printf("%s\n", Postfix);
	free(Postfix);
	return 0;
}