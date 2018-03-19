#include <stdio.h>

#define MAX_DEGREE 101

typedef struct {
	int degree; // ���׽� ����
	float coef[MAX_DEGREE]; // ���

}Polynomial;

Polynomial read_poly() { //���׽� �Է�
	Polynomial p;

	printf("�ְ����� �Է� : ");
	scanf_s("%d", &p.degree);

	printf("�� ���� ����� �Է��ϼ��� �� %d�� : ", p.degree + 1);
	for (int i = 0; i < p.degree + 1; i++) {
		scanf_s("%f", &p.coef[i]);
	}
	return p;
}

void print_poly(Polynomial p, char str[]) { //���׽� ���
	printf("\t%s", str);
	for (int i = 0; i < p.degree; i++) {
		if (p.coef[i] != 0) {
			printf("%5.1fx^%d + ", p.coef[i], p.degree - i);
		}
	}
	printf("%4.1f\n", p.coef[p.degree]);
}

Polynomial add_poly(Polynomial a, Polynomial b) { //���׽� ����
	Polynomial p;
	if (a.degree > b.degree) {
		p = a;
		for (int i = 0; i <= b.degree; i++)
			p.coef[i + (p.degree - b.degree)] += b.coef[i]; 
	}
	else {
		p = b;
		for (int i = 0; i <= a.degree; i++) {
			p.coef[i + (p.degree - a.degree)] += a.coef[i];
		}
	}

	return p;
}

int main() {

	Polynomial a, b, c;
	printf("���׽� 1 - ");
	a = read_poly();
	printf("���׽� 2 - ");
	b = read_poly();
	c = add_poly(a, b);
	print_poly(a, "A = ");
	print_poly(b, "B = ");
	print_poly(c, "A + B = ");
	return 0;
}