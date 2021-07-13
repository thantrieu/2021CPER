// Tìm ước chung lớn nhất của hai số nguyên dương nhập vào từ bàn phím

#include <stdio.h>

/*
 * @author Branium Academy
 */

 //hàm nguyên mẫu tìm ước chung lớn nhất
long gcd(long a, long b);

int main() {
	// test ước chung
	long a, b;
	puts("Nhap so nguyen a, b > 0: ");
	scanf("%ld%ld", &a, &b);

	if (a > 0 && b > 0) {
		long g = gcd(a, b);
		printf("gcd(%ld, %ld) = %ld\n", a, b, g);
	}
	else {
		puts("Nhap a, b > 0");
	}

	return 0;
}

long gcd(long a, long b) {
	if (a == b) {
		return a; // trường hợp cơ sở
	} // thực hiện bước đệ quy
	else if (a > b) { 
		return gcd(a - b, b);
	}
	else {
		return gcd(a, b - a);
	}
}