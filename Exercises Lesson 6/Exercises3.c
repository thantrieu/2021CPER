// Nhập vào hai số nguyên a, b sau đó so sánh a với b
// bằng các phép so sánh ==, !=, >, >=, <, <=
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int a, b;
	puts("Nhap vao hai so nguyen a, b: ");
	scanf("%d%d", &a, &b);
	// so sánh ==
	// kết quả so sánh: 1 = true, 0 = false
	printf("%d == %d ? %d\n", a, b, a == b);
	// so sánh != 
	printf("%d != %d ? %d\n", a, b, a != b);
	// so sánh >
	printf("%d > %d ? %d\n", a, b, a > b);
	// so sánh >=
	printf("%d >= %d ? %d\n", a, b, a >= b);
	// so sánh <
	printf("%d < %d ? %d\n", a, b, a < b);
	// so sánh <=
	printf("%d <= %d ? %d\n", a, b, a <= b);
}