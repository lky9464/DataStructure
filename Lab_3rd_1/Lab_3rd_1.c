// 구조체를 이용한 복소수 표현
#include <stdio.h>

typedef struct {
	double real; // 복소수의 실수부
	double imag; // 복소수의 허수부
}Complex;

void print_complex(Complex c) { // 복소수 출력 메서드
	printf("%4.1f + %4.1fi\n", c.real, c.imag);
}

//void reset_complex2(Complex *c){
//	c->real = c->imag = 0;
//}

void reset_complex(Complex c) {
	c.real = c.imag = 0;
}

int main() {
	Complex a = { 1.0, 2.0 };
	printf("초기화 이전 : ");
	print_complex(a); // 복소수 화면 출력.
	reset_complex(a); // 초기화가 되지않음.
	//reset_complex2(&a); // 초기화가 됨.
	printf("초기화 이후 : ");
	print_complex(a); // 복소수 화면 출력

	return 0;
}