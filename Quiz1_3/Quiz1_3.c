#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char Element; 
Element alphaArr[MAX_STACK_SIZE]; //스택
int top;

int init_stack() { return top = -1; } //스택초기화

Element pop() { return alphaArr[top--]; } //빼기

void push(Element e) { alphaArr[++top] = e; } //넣기

/*
void print_stack() { //스택 확인용
	printf("현재 스택 >> ");
	for (int i = 0; i <= top; i++) {
		printf("%c", alphaArr[i]);
	}
	printf("top = %d\n", top);
	printf("\n");
}
*/

int main() {


	init_stack();

	char userString [MAX_STACK_SIZE]; //임시 배열
	printf("입력 >> ");
	scanf("%s", userString);

	for (int i = 0; i < strlen(userString); i++) {
		push(userString[i]);
	}
	
	printf("출력 >> ");
	for (int i = 0; i < strlen(alphaArr); i++) {
		printf("%c", pop());
	}
	printf("\n");
	
	return 0;
}