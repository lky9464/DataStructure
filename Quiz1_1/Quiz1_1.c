#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>

void gugudan(int maxDan, int num) {

	for (int i = 2; i <= maxDan; i++) {

		printf("%d´Ü\n", i);

		for (int j = 1; j <= 9; j++) {
			printf("%d * %d = %d\n", i, j, i*j);
		}
		printf("\n");
	}
}

int main() {

	gugudan(3, 9);

	return 0;
}