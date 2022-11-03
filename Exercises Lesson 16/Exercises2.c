// Tính căn bậc hai của một giá trị n

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
 */

int main() {
	// test
	double n;
	puts("Nhap n: ");
	scanf("%lf", &n);

	if (n >= 0) {
		printf("Can bac hai cua %lf = %lf\n", n, sqrt(n));
	}
	else {
		puts("Nhap n >= 0");
	}

	return 0;
}
