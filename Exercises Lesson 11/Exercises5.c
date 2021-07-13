// Nhập số nguyên dương n sau đó tính tổng S = 1 + 1/2^2 + ... + 1/n^2
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so tu nhien n > 0: ");
	scanf("%d", &n);

	if (n > 0) { // nếu n duong thì mới thực hiện
		float s = 0;
		int i;
		for (i = 1; i <= n; i++) {
			s += (float)1 / (i * i); // cộng từng thành phần 1/i^2
		}
		printf("S = %f\n", s);
	}
	else {
		puts("Vui long nhap so tu nhien n > 0");
	}
}