// Tìm ước chung lớn nhất và bội chung nhỏ nhất của
// hai số nguyên dương nhập vào từ bàn phím
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b;
	puts("Nhap hai so nguyen duong a, b: ");
	scanf("%d%d", &a, &b);
	// kiểm tra điều kiện a, b > 0
	if (a > 0 && b > 0) {
		int tmp = a * b;
		// thuật toán tìm ước chung lớn nhất của hai số:
		while (a != b) {
			if (a > b) {
				a -= b;
			}
			else {
				b -= a;
			}
		}
		// sau khi thực hiện vòng lặp ta có ước chung lớn nhất
		// là a hoặc b vì lúc này a == b
		printf("UCLN = %d\nBCNN = %d\n", a, tmp / a);
	}
	else {
		puts("Vui long nhap a, b > 0");
	}
}