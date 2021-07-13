// Nhập số nguyên dương n sau đó tính tổng S = 1 + 1/2 + ... + 1/n
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so nguyen n > 0: ");
	scanf("%d", &n);

	float s = 0;
	if (n > 0) {
		int i;
		for (i = 1; i <= n; i++) {
			s += (float)1 / i; // cộng thêm 1/i
		}
		printf("S = %f\n", s);
	}
	else {
		puts("Vui long nhap so nguyen duong n > 0.");
	}
}