// Nhập vào hai số nguyên dương a < b và viết hàm thực hiện các chức năng:
// Liệt kê các số chính phương trong đoạn [a, b]
// Liệt kê các số nguyên tố trong đoạn [a, b]
// Liệt kê các số thuận nghịch trong đoạn [a, b]
// Liệt kê các số có tổng các chữ số chia hết cho 7 trong đoạn [a, b]

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

// hàm liệt kê số chính phương
void listedSquareRootNumbers(int a, int b) {
	printf("Cac so chinh phuong trong doan [%d, %d]: ", a, b);
	int i = sqrt(a); // giới hạn dưới
	int bound = sqrt(b); // giới hạn trên
	for (; i <= bound; i++) {
		int result = i * i;
		if (result >= a) {
			printf("%d ", result);
		}
	}
}

// hàm liệt kê các số nguyên tố trong đoạn [a, b]
void listedPrimeNumbers(int a, int b) {
	printf("\nCac so nguyen to trong [%d, %d]: ", a, b);
	int i;
	for (i = a; i <= b; i++) {
		if (isPrime(i)) {
			printf("%d ", i);
		}
	}
}

// hàm liệt kê các số thuận nghịch trong đoạn [a, b]
void listedReversibleNumbers(int a, int b) {
	printf("\nCac so thuan nghich trong [%d, %d]: ", a, b);
	int i;
	for (i = a; i <= b; i++) {
		if (isReversible(i)) {
			printf("%d ", i);
		}
	}
}

// hàm liệt kê các số có tổng chữ số chia hết cho 7
void listedDivideBy7(int a, int b) {
	printf("\nCac so co tong chu so chia het cho 7 trong [%d, %d]: ", a, b);
	int i;
	for (i = a; i <= b; i++) {
		if (sumOfDigits(i) % 7 == 0) {
			printf("%d ", i);
		}
	}
}

int main() {
	int a, b;
	puts("Nhap hai so duong a < b: ");
	scanf("%d%d", &a, &b);
	// thực hiện lời gọi hàm
	listedSquareRootNumbers(a, b);
	listedPrimeNumbers(a, b);
	listedReversibleNumbers(a, b);
	listedDivideBy7(a, b);

	return 0;
}