// Viết chương trình tính tổng 3 số nguyên theo hai cách:
// trả về tổng sau khi tính
// truyền tham chiếu

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm tính trả về tổng
int sum3Numbers1(int a, int b, int c);
// hàm tính tổng gán vào biến tham chiếu
void sum3Numbers2(int a, int b, int c, int* sum);

int main() {
	int a, b, c;
	puts("Nhap ba so nguyen: ");
	scanf("%d%d%d", &a, &b, &c);
	int sum = sum3Numbers1(a, b, c);
	printf("Tinh theo cach 1: sum = %d\n", sum);
	sum3Numbers2(a, b, c, &sum);
	printf("Tinh theo cach 2: sum = %d\n", sum);
	return 0;
}

int sum3Numbers1(int a, int b, int c) {
	return a + b + c;
}

void sum3Numbers2(int a, int b, int c, int* sum) {
	*sum = a + b + c;
}