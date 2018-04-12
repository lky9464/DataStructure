#include <stdio.h>
#include <stdlib.h>

typedef int Element;
typedef struct LinkedNode {
	Element data;            // ������ ����
	struct LinkedNode* link;        // ���� ��带 ����Ű�� ������ ����
} Node;
Node* top = NULL;            // ���� ����Ʈ�� ��� ������

int is_empty() { return top == NULL; }
void init_stack() { top = NULL; }

void error(char* str)
{
	fprintf(stderr, "%s\n", str);
	exit(1);
};

Element peek()
{
	if (is_empty())
		error("���� ���� ����");
	return top->data;
}

int size()
{
	Node *p;
	int count = 0;
	for (p = top; p != NULL; p = p->link) count++;
	return count;
}

void push(Element e)
{
	Node* p = (Node*)malloc(sizeof(Node));    // ��� ���� �Ҵ�
	p->data = e;                // ������ �ʵ� �ʱ�ȭ

	p->link = top;    // �׸� 5.12�� (1)
	top = p;        // �׸� 5.12�� (2)
}

Element pop()
{
	Node* p;
	Element e;
	if (is_empty())
		error("���� ���� ����");

	p = top;            // �׸� 5.13�� (1)
	top = p->link;        // �׸� 5.13�� (2)
	e = p->data;        // �׸� �����͸� ������ ��.
	free(p);            // ��� ���� ����.

	return e;        // ������ �׸� �����͸� ��ȯ.
}

void destroy_stack()
{
	while (is_empty() == 0)
		pop();
}

void print_stack(char* msg)
{
	Node *p;
	printf("%s[%2d]= ", msg, size());
	for (p = top; p != NULL; p = p->link)
		printf("%2d ", p->data);
	printf("\n");
}

int main()
{
	int i;

	init_stack();
	for (i = 1; i<10; i++)
		push(i);
	print_stack("����Ƚ��� push 9ȸ");
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	printf("\tpop() --> %d\n", pop());
	print_stack("����Ƚ��� pop  3ȸ");
	destroy_stack();
	print_stack("����Ƚ��� destroy ");

	return 0;
}