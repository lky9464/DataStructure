//Polynomial 2

#include <stdio.h>
#include <stdlib.h>

#define MAX_TERMS 101

// 다항식의 계수와 차수를 저장하는 구조체
struct {
	float coef; // 항의 계수
	int expon;  // 항의 차수
} terms[MAX_TERMS] = { { 8,3 },{ 7,1 },{ 1,0 }, // 8x^3 + 7x^1 + 1x^0
					 { 10,3 },{ 3,2 },{ 1,0 } };  // 10x^3 + 3x^2 + 1x^0
int avail = 6;
//
char compare(int a, int b)
{
	if (a>b) return '>';
	else if (a == b) return '=';
	else return '<';
}

// 새로운 항을 다항식에 추가한다.
void attach(float coef, int expon)
{
	if (avail>MAX_TERMS) {
		fprintf(stderr, "항의 개수가 너무 많음\n");
		exit(1);
	}
	terms[avail].coef = coef;
	terms[avail++].expon = expon;
}

void poly_print(int Cs, int Ce)
{
	for (int i = Cs; i<Ce; i++)
		printf("%4.1f X ^ %d + ", terms[i].coef, terms[i].expon);
	printf("%4.1f X ^ %d ", terms[Ce].coef, terms[Ce].expon);
	printf("\n");
}

// 두 다항식을 합하는 함수 C=A+B
void poly_add2(int As, int Ae, int Bs, int Be, int *Cs, int *Ce)
{
	float tempcoef;
	*Cs = avail;

	while (As <= Ae && Bs <= Be)
		switch (compare(terms[As].expon, terms[Bs].expon)) {
		case '>': 	// A의 차수 > B의 차수
			attach(terms[As].coef, terms[As].expon);
			As++;			break;
		case '=': 	// A의 차수 == B의 차수
			tempcoef = terms[As].coef + terms[Bs].coef;
			if (tempcoef)
				attach(tempcoef, terms[As].expon);
			As++; Bs++;		break;
		case '<': 	// A의 차수 < B의 차수
			attach(terms[Bs].coef, terms[Bs].expon);
			Bs++;			break; 
		}
	// A의 나머지 항들을 이동함
	for (; As <= Ae; As++)
		attach(terms[As].coef, terms[As].expon);
	// B의 나머지 항들을 이동함
	for (; Bs <= Be; Bs++)
		attach(terms[Bs].coef, terms[Bs].expon);
	*Ce = avail - 1;
}
//
int main()
{
	int Cs, Ce;
	poly_add2(0, 2, 3, 5, &Cs, &Ce);
	printf("A = ");
	poly_print(0, 2);
	printf("B = ");
	poly_print(3, 5);
	printf("C = ");
	poly_print(Cs, Ce);

	return 0;
}