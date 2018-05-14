// 2018.05.14 �˰��� ����
//
// â�����б� ������Ű��а�
// 20133118 �̱���

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ARRAY_LENGTH 1001 // �迭 �ִ� ������

typedef int HeapNodes;

HeapNodes str[MAX_ARRAY_LENGTH];
HeapNodes tempArr[MAX_ARRAY_LENGTH]; // ����ȭ �� �迭


void swap(HeapNodes *a, HeapNodes *b) { // ��ġ��ȯ

	int temp = *a;
	*a = *b;
	*b = temp;
}


HeapNodes heapify(HeapNodes a[], int h, int m) { // ����ȭ �˰���
	// a == ����ȭ��ų �迭, h == �����ε���, m == �迭 ũ��

	int j = 2 * h;
	int v = a[h];
	for (j = 2 * h; j <= m; j = j * 2) {

		if (j < m && a[j] < a[j + 1])
			j += 1;


		if (v >= a[j]) {
			continue;
		}
		else {
			a[j / 2] = a[j];
		}
	}
	a[j / 2] = v;

	return a;
}


void heapSort(HeapNodes a[]) { // �������� �˰���

	int n = MAX_ARRAY_LENGTH - 1;

	for (int i = n / 2; i >= 1; i--)
		heapify(a, i, n);
	for (int i = n - 1; i >= 1; i--) {
		swap(&a[1], &a[i + 1]);
		heapify(a, 1, i);
	}

}


int main() {

	int i = 1;
	FILE *file;

	file = fopen("numbers.txt", "r");

	if (file) {
		while (fscanf(file, "%d", str) != EOF) {
			tempArr[i] = str[0];
			i++;
		}
		fclose(file);
	}

	//printf("���� ���� �� : \n");
	//for (i = 1; i < MAX_ARRAY_LENGTH; i++) { // ���� ���� �� ���
	//	printf("%4d", tempArr[i]);
	//}
	//printf("\n\n\n\n\n");

	heapSort(tempArr); // ���� ���� ����

	printf("���� ���� �� : \n");
	for (i = 1; i < MAX_ARRAY_LENGTH; i++) { // ���� ���� �� ���
		printf("%4d", tempArr[i]);
	}
	printf("\n");
	

	return 0;
}