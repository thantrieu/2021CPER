// Nhập vào số nguyên 1 <= n <= 15 viết hàm thực hiện các chức năng:
// Liệt kê các số nguyên tố có n chữ số
// Liệt kê các số nguyên tố n chữ số và các chữ số tăng dần
// Liệt kê các số nguyên tố n chữ số và các chữ số giảm dần
// Liệt kê các số nguyên tố n chữ số và các chữ số tăng hoặc giảm dần

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
*/

// hàm kiểm tra số nguyên tố
int isPrime(unsigned long long n) {
	if (n < 2) {
		return 0;
	}
	unsigned long long i;
	unsigned long long bound = sqrt(n);
	for (i = 2; i <= bound; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1; // mặc định là số nguyên tố
}

// hàm liệt kê các số nguyên tố
void listedPrimeNumbers(int n) {
	printf("Cac so nguyen to n chu so: ");
	unsigned long long i;
	// bắt đầu từ giá trị n chữ số lẻ đầu tiên, n >= 2
	unsigned long long start = pow(10, n - 1) + 1;
	// kết thúc ở giá trị n chữ số lớn nhất
	unsigned long long end = pow(10, n) - 1;
	// bước nhảy bằng 1 nếu n có 1 chữ số
	// ngược lại bước nhảy bằng 2 để tăng tốc chương trình
	// mọi số nguyên tố có >= 2 chữ số đều lẻ!
	int step = (n == 1) ? 1 : 2;
	for (i = start; i <= end; i += step) {
		if (isPrime(i)) {
			printf("%llu ", i);
		}
	}
}

// hàm kiểm tra các chữ số tăng dần
int isIncrease(unsigned long long n) {
	int after = n % 10;
	n /= 10;
	int before;
	while (n > 0) {
		before = n % 10;
		n /= 10;
		if (after <= before) {
			return 0;
		}
		after = before; // cập nhật lại số sau
	}
	return 1;
}

// hàm kiểm tra các chữ số giảm dần
int isDecrease(unsigned long long n) {
	int after = n % 10;
	n /= 10;
	int before;
	while (n > 0) {
		before = n % 10;
		n /= 10;
		if (after >= before) {
			return 0;
		}
		after = before; // cập nhật lại số sau
	}
	return 1;
}

// hàm liệt kê các số vừa nguyên tố vừa tăng dần từ trái qua phải
void listedPrimeAndIncreaseNumbers(int n) {
	printf("\nCac so nguyen to n chu so tang dan cac chu so: ");
	unsigned long long i;
	// bắt đầu từ giá trị n chữ số lẻ đầu tiên, n >= 2
	unsigned long long start = pow(10, n - 1) + 1;
	// kết thúc ở giá trị n chữ số lớn nhất
	unsigned long long end = pow(10, n) - 1;
	// bước nhảy bằng 1 nếu n có 1 chữ số
	// ngược lại bước nhảy bằng 2 để tăng tốc chương trình
	// mọi số nguyên tố có >= 2 chữ số đều lẻ!
	int step = (n == 1) ? 1 : 2;
	for (i = start; i <= end; i += step) {
		// i có các chữ số tăng dần và i nguyên tố
		if (isIncrease(i) && isPrime(i)) {
			printf("%llu ", i);
		}
	}
}

// hàm liệt kê các số vừa nguyên tố vừa giảm dần từ trái qua phải
void listedPrimeAndDecreaseNumbers(int n) {
	printf("\nCac so nguyen to n chu so giam dan cac chu so: ");
	unsigned long long i;
	// bắt đầu từ giá trị n chữ số lẻ đầu tiên, n >= 2
	unsigned long long start = pow(10, n - 1) + 1;
	// kết thúc ở giá trị n chữ số lớn nhất
	unsigned long long end = pow(10, n) - 1;
	// bước nhảy bằng 1 nếu n có 1 chữ số
	// ngược lại bước nhảy bằng 2 để tăng tốc chương trình
	// mọi số nguyên tố có >= 2 chữ số đều lẻ!
	int step = (n == 1) ? 1 : 2;
	for (i = start; i <= end; i += step) {
		// i có các chữ số giảm dần và i nguyên tố
		if (isDecrease(i) && isPrime(i)) {
			printf("%llu ", i);
		}
	}
}

// hàm liệt kê các số vừa nguyên tố vừa giảm/tăng dần từ trái qua phải
void listedPrimeDOINumbers(int n) {
	printf("\nCac so nguyen to n chu so giam hoac tang dan cac chu so: ");
	unsigned long long i;
	// bắt đầu từ giá trị n chữ số lẻ đầu tiên, n >= 2
	unsigned long long start = pow(10, n - 1) + 1;
	// kết thúc ở giá trị n chữ số lớn nhất
	unsigned long long end = pow(10, n) - 1;
	// bước nhảy bằng 1 nếu n có 1 chữ số
	// ngược lại bước nhảy bằng 2 để tăng tốc chương trình
	// mọi số nguyên tố có >= 2 chữ số đều lẻ!
	int step = (n == 1) ? 1 : 2;
	for (i = start; i <= end; i += step) {
		// i có các chữ số tăng dần hoặc giảm dần và i nguyên tố
		if ((isDecrease(i) || isIncrease(i)) && isPrime(i)) {
			printf("%llu ", i);
		}
	}
}

int main() {
	int n;
	puts("Nhap 1 <= n <= 15: ");
	scanf("%d", &n);
	if (n > 0 && n <= 15) {
		listedPrimeNumbers(n);
		listedPrimeAndIncreaseNumbers(n);
		listedPrimeAndDecreaseNumbers(n);
		listedPrimeDOINumbers(n);
	}
	else {
		puts("Vui long nhap n: 1 <= n <= 15");
	}
	return 0;
}