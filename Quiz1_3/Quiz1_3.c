#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef char Element; 
Element alphaArr[MAX_STACK_SIZE]; //����
int top;

int init_stack() { return top = -1; } //�����ʱ�ȭ

Element pop() { return alphaArr[top--]; } //����

void push(Element e) { alphaArr[++top] = e; } //�ֱ�

/*
void print_stack() { //���� Ȯ�ο�
	printf("���� ���� >> ");
	for (int i = 0; i <= top; i++) {
		printf("%c", alphaArr[i]);
	}
	printf("top = %d\n", top);
	printf("\n");
}
*/

int main() {


	init_stack();

	char userString [MAX_STACK_SIZE]; //�ӽ� �迭
	printf("�Է� >> ");
	scanf("%s", userString);

	for (int i = 0; i < strlen(userString); i++) {
		push(userString[i]);
	}
	
	printf("��� >> ");
	for (int i = 0; i < strlen(alphaArr); i++) {
		printf("%c", pop());
	}
	printf("\n");
	
	return 0;
}