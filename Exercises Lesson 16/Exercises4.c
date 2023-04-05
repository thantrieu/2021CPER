// Tính sin(x) với x ở hệ radian

#include <stdio.h>
#include <math.h>
#define PI 3.1415926

/*
 * @author Branium Academy
 */

int main() {
	// test
	double n;
	puts("Nhap goc can tinh sin(he degree): ");
	scanf("%lf", &n);
	double x = PI * n / 180;
	printf("sin(%lf) = %lf\n", n, sin(x));

	return 0;
}
