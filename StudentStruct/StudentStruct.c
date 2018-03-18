#include <stdio.h>
#include <stdlib.h>

typedef struct student {
	char name[10];
	int age;
	char address[50];
	char phone[15];

}man;

int main() {

	struct student a = { "kim", 15, "창원", "010-9999-9999" };
	printf("%s, %d, %s, %s\n", a.name, a.age, a.address, a.phone);
	strcpy(a.name, "Hong");
	a.age = 25;
	strcpy(a.address, "서울");
	strcpy(a.phone, "010-1111-1111");

	printf("%s, %d, %s, %s\n", a.name, a.age, a.address, a.phone);


	return 0;
}