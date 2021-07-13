// Viết hàm nguyên mẫu và định nghĩa hàm cho các chức năng sau:
// kiểm tra số nguyên a có thuận nghịch?
// tính tổng các chữ số của số nguyên n
// kiểm tra n có phải số nguyên tố?
// kiểm tra n có phải số chính phương?
// tìm giá trị lớn nhất trong 3 tham số kiểu nguyên
// tìm giá trị nhỏ nhất trong 4 tham số kiểu float

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
*/

// các hàm nguyên mẫu: khai báo trong file .h
// hàm kiểm tra số thuận nghịch
int isReversible(int a);

// hàm tính tổng các chữ số của n
int sumOfDigits(int n);

// hàm kiểm tra n có phải số nguyên tố hay không
int isPrime(int n);

// hàm kiểm tra n có phải số chính phương
int isSquareRootNumber(int n);

// hàm tìm max ba số nguyên
int max(int a, int b, int c);

// hàm tìm min 4 số thực
float min(float a, float b, float c, float d);

// nơi gọi hàm
int main() {
	int n;
	puts("Nhap n: ");
	scanf("%d", &n);

	// sử dụng toán tử ba ngôi
	isReversible(n) ? puts("La so thuan nghich") : puts("Khong la so thuan nghich");
	isPrime(n) ? puts("La so nguyen to") : puts("Khong la so nguyen to");
	isSquareRootNumber(n) ? puts("La so chinh phuong") : puts("Khong la so chinh phuong");
	
	printf("Tong cac chu so cua %d la: %d\n", n, sumOfDigits(n));

	int a = 5, b = 8, c = -1;
	printf("max(%d, %d, %d) = %d\n", a, b, c, max(a, b, c));

	float x = 25.25f;
	float y = 3.12f;
	float z = -1.25f;
	float t = 6.312f;
	printf("min(%f, %f, %f, %f) = %f\n", x, y, z, t, min(x, y, z, t));

	return 0;
}

// định nghĩa hàm: trong file .c
int isReversible(int n) {
	int m = n;
	int r = 0;
	while (m > 0) {
		r = r * 10 + m % 10;
		m /= 10;
	}
	return r == n; // nếu r == n thì return true và ngược lại
}

int sumOfDigits(int n) {
	if (n < 0) {
		n *= -1;
	}
	int sum = 0;
	while (n > 0) {
		sum += n % 10; // lấy phần đơn vị
		n /= 10; // giảm n đi 10 lần để loại phần đơn vị
	}
	return sum;
}

int isPrime(int n) {
	if (n < 2) {
		return 0;
	}
	int i;
	int bound = sqrt(n);
	for (i = 2; i <= bound; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int isSquareRootNumber(int n) {
	if (n < 0) {
		return 0;
	}
	int sq = sqrt(n);
	return sq * sq == n;
}

int max(int a, int b, int c) {
	int max = a;
	// sử dụng toán tử ba ngôi
	max = (b > max) ? b : max;
	max = (c > max) ? c : max;
	return max;
}

float min(float a, float b, float c, float d) {
	float min = a;
	// sử dụng toán tử ba ngôi
	min = (b < min) ? b : min;
	min = (c < min) ? c : min;
	min = (d < min) ? d : min;
	return min;
}