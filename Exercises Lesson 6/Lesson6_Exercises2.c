#include <stdio.h>

int main() {
	int a;
	scanf("%d", &a);
	int b = 6;
	printf("a++ = %d\n", a + 1);
	printf("a-- = %d\n", a - 1);
	printf("(a += 5) = %d\n", a + 5);
	printf("(a *= b) = %d\n", a * b);
	printf("(a /= b) = %d\n", a / b);
	printf("(a %= b) = %d\n", a % b);

	return 0;
}