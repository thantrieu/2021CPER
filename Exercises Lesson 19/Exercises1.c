// Viết hàm thực hiện các chức năng sau:
// sinh số ngẫu nhiên trong đoạn [a, b]

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*
 * @author Branium Academy
 */

// hàm sinh số ngẫu nhiên trong đoạn [a, b]
int randomNumber(int a, int b) {
	int num = rand() % (b - a + 1);
	return num;
}

int main() {
	srand(time(0));
	int a, b;
	puts("Nhap hai so duong a, b: ");
	scanf("%d%d", &a, &b);
	// điều kiện để thực hiện chương trình
	if (a > 0 && b > 0 && a < b) {
		int result = randomNumber(a, b);
		printf("So random = %d\n", result);
	}
	else {
		puts("Nhap hai so nguyen duong a < b");
	}
	
	return 0;
}