// Nhập vào số nguyên a và rút gọn biểu thức
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b;
	puts("Nhap vao gia tri a: ");
	scanf("%d", &a);
	puts("Nhap b khac 0: ");
	scanf("%d", &b);
	// a = a + 1:
	a++;
	printf("Gia tri cua bieu thuc a = a + 1 la %d\n", a);
	// a = a - 1:
	a--;
	printf("Gia tri cua bieu thuc a = a - 1 la %d\n", a);
	// a = a + 5:
	a += 5;
	printf("Gia tri cua bieu thuc a = a + 5 la %d\n", a);
	// a = a * 6:
	a *= 6;
	printf("Gia tri cua bieu thuc a = a * 6 la %d\n", a);
	// a = a / 8:
	a /= 8;
	printf("Gia tri cua bieu thuc a = a / 8 la %d\n", a);
	// a = a % b
	a %= b;
	printf("Gia tri cua bieu thuc a = a %% b la %d\n", a);
}