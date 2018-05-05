#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

int main() {
	
	int loop = 0;
	printf("숫자를 입력하세요 >> ");
	scanf("%d", &loop);

	for (int i = loop; i > 0; i--) {
		for (int j = i; j > 1; j--) {
			printf(" ");
		}
		for (int k = loop - i + 1; k > 0 ; k--) {
			printf("*");
		}
		printf("\n");
	}

	return 0;
}