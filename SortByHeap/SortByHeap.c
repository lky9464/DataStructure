// 2018.05.14 알고리즘 과제
//
// 창원대학교 정보통신공학과
// 20133118 이광연

#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

#define MAX_ARRAY_LENGTH 1001 // 배열 최대 사이즈

typedef int HeapNodes;

HeapNodes str[MAX_ARRAY_LENGTH];
HeapNodes tempArr[MAX_ARRAY_LENGTH]; // 히프화 할 배열


void swap(HeapNodes *a, HeapNodes *b) { // 위치교환

	int temp = *a;
	*a = *b;
	*b = temp;
}


HeapNodes heapify(HeapNodes a[], int h, int m) { // 히프화 알고리즘
	// a == 히프화시킬 배열, h == 시작인덱스, m == 배열 크기

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


void heapSort(HeapNodes a[]) { // 히프정렬 알고리즘

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

	//printf("히프 정렬 전 : \n");
	//for (i = 1; i < MAX_ARRAY_LENGTH; i++) { // 히프 정렬 전 출력
	//	printf("%4d", tempArr[i]);
	//}
	//printf("\n\n\n\n\n");

	heapSort(tempArr); // 히프 정렬 실행

	printf("히프 정렬 후 : \n");
	for (i = 1; i < MAX_ARRAY_LENGTH; i++) { // 히프 정렬 후 출력
		printf("%4d", tempArr[i]);
	}
	printf("\n");
	

	return 0;
}