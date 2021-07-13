// Tính tan(x)

#include <stdio.h>
#include <math.h>
#define PI 3.1415926
/*
 * @author Branium Academy
 */

int main() {
	double n;
	puts("Nhap goc can tinh tan(he degree): ");
	scanf("%lf", &n);
	double x = PI * n / 180;
	printf("tan(%lf) = %lf\n", n, sin(x) / cos(x));

	return 0;
}
