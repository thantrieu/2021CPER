// Nhập vào một số nguyên dương n và viết hàm thực hiện các chức năng:
// Tính tổng các chữ số của n
// Kiểm tra xem n có nguyên tố?
// Kiểm tra xem n có thuận nghịch?

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
*/

// hàm tính tổng các chữ số của n
int sumOfDigits(int n) {
	int sum = 0;
	while (n > 0) {
		sum += n % 10; // lấy phần đơn vị
		n /= 10; // giảm n đi 10 lần để loại phần đơn vị
	}
	return sum;
}

// hàm kiểm tra số nguyên tố
int isPrime(int n) {
	if (n < 2) {
		return 0;
	}
	int i;
	for (i = 2; i <= sqrt(n); i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1; // mặc định là số nguyên tố
}

// hàm kiểm tra số thuận nghịch
int isReversible(int n) {
	int m = n;
	int r = 0;
	while (m > 0) {
		r = r * 10 + m % 10;
		m /= 10;
	}
	return r == n; // nếu r == n thì return true và ngược lại
}

int main() {
	int n;
	puts("Nhap so duong n: ");
	scanf("%d", &n);
	if (n > 0) {
		int sum = sumOfDigits(n);
		printf("Tong cac chu so cua n = %d\n", sum);

		if (isPrime(n)) {
			puts("La so nguyen to");
		}
		else {
			puts("Khong la so nguyen to");
		}

		if (isReversible(n)) {
			puts("La so thuan nghich");
		}
		else {
			puts("Khong la so thuan nghich");
		}
	}
	else {
		puts("Nhap n > 0");
	}
	return 0;
}