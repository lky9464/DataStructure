#include <stdio.h>
#include <stdlib.h>

#define MAX_STACK_SIZE 100        // ���� ��� ������ ���� �迭�� ũ��
typedef int Element;        // ���� ����� �ڷ��� ����

Element data[MAX_STACK_SIZE];    // ���� ���� ����� �迭
int    top;                // ���� ������ top

						   // ���� ��Ȳ ó���� ���� �Լ�. �޽��� ��� �� ���α׷� ����.
void error(char str[])
{
	printf("%s\n", str);
	exit(1);
}

// ������ �ֿ� ����: ����
void init_stack() { top = -1; }
int is_empty() { return top == -1; }
int is_full() { return top == MAX_STACK_SIZE - 1; }
int size() { return top + 1; }

void push(Element e) //�ֱ�
{
	if (is_full())
		error("���� ��ȭ ����");
	data[++top] = e;
}
Element pop() //����
{
	if (is_empty())
		error("���� ���� ����");
	return data[top--];
}
Element peek() //����
{
	if (is_empty())
		error("���� ���� ����");
	return data[top];
}

// ���� �׽�Ʈ�� ���� �ڵ�: ��� �������� ����
void print_stack(char msg[]) {
	int i;
	printf("%s[%2d]= ", msg, size());
	for (i = 0; i<size(); i++)
		printf("%2d ", data[i]);
	printf("\n");
}

int main()
{
	int i;

	init_stack();
	for (i = 1; i<10; i++)
		push(i);
	print_stack("���� push 9ȸ");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("���� pop  3ȸ");

	return 0;
}