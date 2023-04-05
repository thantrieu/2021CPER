// Tính căn bậc ba của một giá trị n

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

	printf("Can bac ba cua %lf = %lf\n", n, cbrt(n));

	return 0;
}
