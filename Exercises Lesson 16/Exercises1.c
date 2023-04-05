// Tính trị tuyệt đối của giá trị x

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

	printf("|x| = %lf\n", fabs(x));

	return 0;
}
