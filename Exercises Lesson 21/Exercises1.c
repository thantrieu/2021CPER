// Tính n! với n nguyên dương không quá 22

#include <stdio.h>

/*
 * @author Branium Academy
*/

//hàm nguyên mẫu tính n!
unsigned long long factorial(int n);

int main() {
	// test n!
	int n;
	puts("Nhap n sao cho 0 <= n <= 22: ");
	scanf("%d", &n);
	if (n >= 0 && n <= 22) {
		unsigned long long f = factorial(n);
		printf("%d! = %llu\n", n, f);
	}
	else {
		puts("Nhap n: 0 <= n <= 22");
	}
	
	return 0;
}

// định nghĩa hàm
unsigned long long factorial(int n) {
	// n! = n * (n - 1)!
	if (n <= 1) {
		return 1; // trường hợp cơ sở
	}
	else { // bước đệ quy
		return n * factorial(n - 1);
	}
}