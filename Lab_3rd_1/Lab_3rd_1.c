// ����ü�� �̿��� ���Ҽ� ǥ��

#include <stdio.h>

typedef struct {
	double real; // ���Ҽ��� �Ǽ���
	double imag; // ���Ҽ��� �����
}Complex;

void print_complex(Complex c) { // ���Ҽ� ��� �޼���
	printf("%4.1f + %4.1fi\n", c.real, c.imag);
}


void reset_complex(Complex c) {
	c.real = c.imag = 0;
}

int main() {
	Complex a = { 1.0, 2.0 };
	printf("�ʱ�ȭ ���� : ");
	print_complex(a); // ���Ҽ� ȭ�� ���.
	reset_complex(a); // �ʱ�ȭ�� ��������.
	printf("�ʱ�ȭ ���� : ");
	print_complex(a); // ���Ҽ� ȭ�� ���

	return 0;
}