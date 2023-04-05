// Tính a^b

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
 */

int main() {
	// test
	double a, b;
	puts("Nhap a, b: ");
	scanf("%lf%lf", &a, &b);

	printf("%lf^%lf = %lf\n", a, b, pow(a, b));

	return 0;
}
