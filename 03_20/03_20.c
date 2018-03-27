#include <stdio.h>
#include <stdlib.h>

int main() {

	int *input;

	int arrSize;
	printf("Å©±â : ");
	scanf_s("%d", &arrSize);
	input = (int*)malloc(sizeof(int)*arrSize);
	for (int i = 0; i < arrSize; i++) {
		scanf_s("%d", &input[i]);
	}
	for (int i = 0; i < arrSize; i++) {
		printf("%d ", input[i]);
	}
	free(input);
	

	return 0;
}