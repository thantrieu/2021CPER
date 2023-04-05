// Viết hàm nhập vào 3 giá trị nguyên a, b, c. Hàm trả về void

#include <stdio.h>

/*
 * @author Branium Academy
 */

 // hàm nhập vào ba số nguyên a, b, c
void getIntValues(int* a, int* b, int* c) {
	puts("Nhap ba so nguyen a, b, c: ");
	scanf("%d%d%d", a, b, c);
}

int main() {
	// test
	int a, b, c;
	
	// gọi hàm nhập ba số
	getIntValues(&a, &b, &c);
	printf("Gia tri sau khi nhap: a = %d, b = %d, c = %d\n", a, b, c);

	return 0;
}
