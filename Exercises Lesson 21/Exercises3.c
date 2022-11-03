// Tính a^b với a, b nguyên, b >= 0

#include <stdio.h>

/*
 * @author Branium Academy
 */

//hàm nguyên mẫu tính a^b
long long exponential(int a, int b);

int main() {
	// test a mũ b
	int a, b;
	puts("Nhap so nguyen a: ");
	scanf("%d", &a);
	puts("Nhap so nguyen b >= 0: ");
	scanf("%d", &b);

	if (b >= 0) {
		long long ex = exponential(a, b);
		printf("%d^%d = %lld\n", a, b, ex);
	}
	else {
		puts("Nhap b >= 0");
	}

	return 0;
}

long long exponential(int a, int b) {
	//a^b = a * a^(b - 1)
	if (a == 0) {
		return 0; // trường hợp cơ sở
	}
	if (b == 0) {
		return 1; // trường hợp cơ sở
	}
	if (b == 1) {
		return a; // trường hợp cơ sở
	}
	else { // thực hiện bước đệ quy
		return a * exponential(a, b - 1);
	}
}