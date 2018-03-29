#include <stdio.h>

#define MAX_DEGREE    101

typedef struct {
	int degree;
	float coef[MAX_DEGREE];
} Polynomial;

Polynomial read_poly()
{
	int i;
	Polynomial p;

	printf("다항식의 최고 차수를 입력하시오: ");
	scanf_s("%d", &p.degree);
	printf("각 항의 계수를 입력하시오 (총 %d개): ", p.degree + 1);
	for (i = 0; i <= p.degree; i++)
		scanf_s("%f", p.coef + i);
	return p;
}


void print_poly(Polynomial p, char str[])
{
	int i;
	printf("%s", str);
	for (i = 0; i < p.degree; i++) {
		if (p.coef[i] == 1){ // 계수 1일 때
			if (i == p.degree - 1)
				printf(" x^%d ", p.degree - i);
			else
				printf(" x^%d + ", p.degree - i);
		}
		else if (p.coef[i] == 0) { //계수 0일 때
			printf("");
		}
		else {
			printf("%4.1f x^%d ", p.coef[i], p.degree - i); // 상수항 출력
		}
	}
	printf("\n");
	
}


Polynomial add_poly(Polynomial a, Polynomial b)
{
	int i;
	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (i = 0; i <= b.degree; i++)
			p.coef[i + (p.degree - b.degree)] += b.coef[i];
	}
	else {
		p = b;
		for (i = 0; i <= a.degree; i++)
			p.coef[i + (p.degree - a.degree)] += a.coef[i];
	}
	return p;
}

Polynomial sub_poly(Polynomial a, Polynomial b) {

	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (int i = 0; i <= b.degree; i++) {
			p.coef[i + (p.degree - b.degree)] -= b.coef[i];
		}
	}
	else {
		p = b;
		for (int i = 0; i <= b.degree; i++) {
			p.coef[i + (p.degree - a.degree)] -= a.coef[i];
		}
	}

	return p;
}

Polynomial mult_poly(Polynomial a, Polynomial b) { // 다항식 곱 연산


	Polynomial c;

	c.degree = a.degree + b.degree;

	if (a.degree >= b.degree) {
		for (int i = 0; i <= a.degree; i++) {
			for (int j = 0; j <= b.degree; j++) {
				c.coef[i*(b.degree + 1) + j] = a.coef[i] * b.coef[j];
			}
		}
	}
	else {
		for (int i = 0; i <= b.degree; i++) {

			for (int j = 0; j <= a.degree; j++) {
				c.coef[i*(a.degree) + j] = b.coef[i] * a.coef[j];
			}
		}
	}
	return c;
}

void print_mult_poly(Polynomial a, Polynomial b, Polynomial c, char str[]) // 다항식 곱 출력
{
	int tempA = a.degree, tempB = b.degree;

	printf("%s", str);
	if (a.degree >= b.degree) {
		for (int i = 0; i <= a.degree; i++) {

			for (int j = 0; j <= b.degree; j++) {
				if (tempA + tempB - j != 0 && c.coef[i*(b.degree + 1) + j] != 0)
					printf("%5.1f x^%d + ", c.coef[i*(b.degree + 1) + j], tempA + tempB - j);
				else if (c.coef[i*(b.degree + 1) + j] == 0)
					printf("");
				else // 상수항 출력
					printf("%5.1f\n", c.coef[i*(b.degree + 1) + j]);
			}
			tempA--;
		}
	}
	else {
		for (int i = 0; i <= b.degree; i++) {

			for (int j = 0; j <= a.degree; j++) {
				if (tempA + tempB - j != 0 && c.coef[i*(a.degree + 1) + j] == 0)
					printf("%5.1f x^%d + ", c.coef[i*(a.degree + 1) + j], tempA + tempB - j);
				else if (c.coef[i*(a.degree + 1) + j] == 0)
					printf("");
				else
					printf("%5.1f\n", c.coef[i*(a.degree + 1) + j]);
			}
			tempA--;
		}
	}
}

void trimPoly(Polynomial *a) { // incomplete

	int move = a->degree;
	int loop = 0;
	int *temp = (int*)malloc(sizeof(int)*a->degree);

	for (int i = 0; i < a->degree; i++) {
		if (a->coef[i] == 0) {
			move -= 1;
			loop += 1;
		}
	}
	for (int k = 0; k < loop; loop++) {
		for (int i = a->degree; i > move; i--) {
			a->coef[(a->degree) - i] = a->coef[(a->degree) - i + 1];
		}
	}
}

int main()
{

	/*Polynomial a, b, c;  // 다항식 덧셈
	a = read_poly();
	b = read_poly();
	c = add_poly(a, b);
	print_poly(a, " A = ");
	print_poly(b, " B = ");
	print_poly(c, "A+B= ");*/

	// 1...(1)
	/*Polynomial a, b, c;  // 다항식 뺄셈
	a = read_poly();
	b = read_poly();
	c = sub_poly(a, b);
	print_poly(a, " A = ");
	print_poly(b, " B = ");
	print_poly(c, "A+B= ");*/

	// 1...(2)
	/*Polynomial a, b, c;  // 다항식 곱셈
	a = read_poly();
	b = read_poly();
	c = mult_poly(a, b);
	print_poly(a, " A = ");
	print_poly(b, " B = ");
	print_mult_poly(a, b, c, "A*B= ");*/


	// 1...(4)
	/*Polynomial a = read_poly();
	print_poly(a, "A = ");*/


	return 0;
}