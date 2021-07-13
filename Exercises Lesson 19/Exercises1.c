// Viết hàm thực hiện các chức năng sau:
// sinh số ngẫu nhiên trong đoạn [a, b]

#include <stdio.h>
#include <stdlib.h>

/*
 * @author Branium Academy
 */

// hàm sinh số ngẫu nhiên trong đoạn [a, b]
int randomNumber(int a, int b) {
	int num = rand() % b + a;
	return num;
}

int main() {
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