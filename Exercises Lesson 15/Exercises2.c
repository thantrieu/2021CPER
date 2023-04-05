// Viết hàm thực hiện các chức năng sau: 
// Nhập vào và trả về 1 số nguyên
// Tìm UCLN, BCNN

#include <stdio.h>

/*
 * @author Branium Academy
*/

// hàm đọc và trả về một số nguyên
int readANumber() {
	int n; // biến lưu giá trị số nguyên
	puts("Nhap vao mot so nguyen: ");
	scanf("%d", &n);
	return n;
}

// tìm UCLN hai số nguyên dương
int gcd(int a, int b) { // greatest common divisor
	while (a != b) {
		if (a > b) {
			a -= b;
		}
		else {
			b -= a;
		}
	}
	return a;
}

// tìm bội chung nhỏ nhất của hai số nguyên a, b
int lcm(int a, int b) { // least common multiple
	return (a * b) / gcd(a, b);
}

int main() {
	int a = readANumber(); // gọi hàm nhập số a
	int b = readANumber(); // gọi hàm nhập số b
	if (a > 0 && b > 0) {
		int ucln = gcd(a, b); // tìm ước chung max
		int bcnn = lcm(a, b); // tìm bội chung min
		printf("UCLN(%d, %d) = %d\n", a, b, ucln);
		printf("BCNN(%d, %d) = %d\n", a, b, bcnn);
	}
	else {
		puts("Vui long nhap a, b > 0");
	}
	return 0;
}