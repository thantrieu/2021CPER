// Viết hàm thực hiện các chức năng sau:
// tìm ước chung lớn nhất của hai số nguyên dương a, b
// hàm nhận ba tham số a, b, ucln và trả về ucln

#include <stdio.h>

/*
 * @author Branium Academy
 */

// hàm tìm ước chung lớn nhất của hai số dương a, b
int gcd(int a, int b, int* ucln) {
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	// sau khi thực hiện vòng lặp, ta có được ucln
	// là a hoặc b vì lúc này a == b
	*ucln = a; // gán kết qủa
	return a; // trả về ước chung max
}

int main() {
	// test
	int a, b;
	
	puts("Nhap vao 2 so nguyen duong: ");
	scanf("%d%d", &a, &b);
	if (a > 0 && b > 0) {
		int ucln;
		printf("gcd(%d, %d) = %d\n", a, b, gcd(a, b, &ucln));
		// hoặc:
		gcd(a, b, &ucln); // gọi hàm tìm ucln
		printf("gcd(%d, %d) = %d\n", a, b, ucln); // in kq
	}
	else {
		puts("Vui long nhap a, b > 0");
	}

	return 0;
}
