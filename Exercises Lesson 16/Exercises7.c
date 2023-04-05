// Tính log(x)

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
 */

int main() {
	// test
	double x;
	puts("Nhap x: ");
	scanf("%lf", &x);

	printf("log(%lf) = %lf\n", x, log(x));

	return 0;
}
