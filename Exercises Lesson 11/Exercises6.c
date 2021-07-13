// Nhập số nguyên dương n sau đó tính tổng S = 1 + 2! + ... + n!
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so tu nhien n > 0: ");
	scanf("%d", &n);

	if (n > 0) { // nếu n duong thì mới thực hiện
		unsigned long long s = 0;
		unsigned long long f = 1;
		int i;
		for (i = 1; i <= n; i++) {
			f *= i; // k!, k = i
			s += f; // cộng từng thành phần k!
		}
		printf("S = %llu\n", s);
	}
	else {
		puts("Vui long nhap so tu nhien n > 0");
	}
}