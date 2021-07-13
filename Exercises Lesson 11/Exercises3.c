// Nhập số tự nhiên n sau đó tính tổng S = 1 + 2 + ... + n
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap so tu nhien n > 0: ");
	scanf("%d", &n);
	
	int s = 0;
	if (n < 0) {
		puts("Vui long nhap so nguyen duong n ");
	}
	else {
		int i;
		for (i = 1; i <= n; i++) {
			s += i; // cộng thêm i vào tổng
		}
		printf("S = %d\n", s);
	}
}