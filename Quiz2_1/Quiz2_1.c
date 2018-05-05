#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef int Item;
typedef struct DoubleListNode {
	
	Item data;
	struct DoubleListNode *prev;
	struct DoubleListNode *next;

}DLN;

DLN *head = NULL;
DLN *tail = NULL;

DLN *create_node(Item a) {
	DLN *new_node = (DLN*)malloc(sizeof(DLN));

	new_node->data = a;
	new_node->prev = NULL;
	new_node->next = NULL;

	return new_node;
}

void display() { //������ ��� (1-1)
	DLN *current = head;

	while (current != NULL) {
		printf("%d ", current -> data);
		current = current->next;
	}
}

void reverse_display() { //������ ��� (1-2)
	DLN *current = tail;

	while (current != NULL) {
		printf("%d ", current->data);
		current = current->prev;
	}
}

Item node_sum() { //��� ��� �� (1-3)
	DLN *current = head;
	Item result = 0;

	while (current != NULL) {
		result += current->data;
		current = current->next;
	}

	return result;
}

Item find_min_node() { //�ּҰ� ������ ��� ã�� (1-4)
	DLN *current = head;
	Item min;

	while (current != NULL) {

		if (current == head) {
			min = current->data;
			current = current->next;
		}
		else {
			if (current->data < min) {
				min = current->data;
			}
			current = current->next;
		}

	}
	return min;
}

void decreased_node_value() { //��� ��忡 -10 (1-5)
	DLN *current = head;

	while (current != NULL) {
		current->data = current->data - 10;
		current = current->next;
	}
}

///////////////////////////////���� �Լ�////////////////////////////////

void insert_node(Item data) { //�տ� ����
	DLN *new_node = create_node(data);

	if (head == NULL) {
		head = new_node;
		tail = new_node;
	}
	else {
		head->prev = new_node;
		new_node->next = head;
		head = new_node;
	}
}

void rev_insert_node(Item data) { //�ڿ� ����
	DLN *new_node = create_node(data);

	if (head == NULL) {
		head = new_node;
		tail = new_node;
	}
	else {
		tail->next = new_node;
		new_node->prev = tail;
		tail = new_node;
	}
}
/////////////////////////////////////////////////////////////////////////

int main() {

	//1
	insert_node(11);
	rev_insert_node(22);
	rev_insert_node(33);
	rev_insert_node(44);
	rev_insert_node(55);

	printf("������ >> "); //1-1
	display();
	printf("\n");

	printf("������ >> "); //1-2
	reverse_display();
	printf("\n");

	printf("��� ����� �����͵�  �� >> ");
	printf("%d\n", node_sum()); //1-3

	printf("��� ��� �� �ּ� �� >> ");
	printf("%d\n", find_min_node()); //1-4

	printf("��� ��忡 -10 ���� >> ");
	decreased_node_value(); //1-5
	display();
	printf("\n");

	



	return 0;
}