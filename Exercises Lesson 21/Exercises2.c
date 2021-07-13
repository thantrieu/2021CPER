// Tìm số Fibonacci thứ n, n <= 93

#include <stdio.h>

/*
 * @author Branium Academy
*/

//hàm nguyên mẫu tính Fibonacci
unsigned long long fibonacci(int n);

int main() {
	// test số fibo thứ n
	int n;
	puts("Nhap n sao cho 0 <= n <= 93: ");
	scanf("%d", &n);
	if (n >= 0 && n <= 93) {
		unsigned long long fn = fibonacci(n);
		printf("F%d = %llu\n", n, fn);
	}
	else {
		puts("Nhap n: 0 <= n <= 93");
	}

	return 0;
}

unsigned long long fibonacci(int n) {
	//fn = fn-1 + fn-2
	if (n < 2) {
		return n; // trường hợp cơ sở
	}
	else { // thực hiện bước đệ quy
		return fibonacci(n - 1) + fibonacci(n - 2);
	}
}