#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int delete(int arr[], int del) {

	 
}


int main() {

	int n, loc = 0;
	printf("갯수 입력 : ");
	scanf_s("%d", &n);

	char *arr = (char*)malloc(sizeof(arr)*n);
	
	printf("인자 입력 : ");
	for (int i = 0; i < n; i++) {
		scanf_s("%c", &arr[i]);
	}
	for (int i = 0; i < n; i++) {
		printf("%c ", arr[i]);
	}
	printf("\n");

	delete(arr, loc);

	return 0;
}