// Viết chương trình thực hiện các chức năng sau:
// nhập vào 3 số nguyên a, b, c
// kiểm tra xem 3 số đó có tạo thành ba cạnh tam giác hay không

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập vào 3 số nguyên
void getIntValues(int* a, int* b, int* c);
// hàm kiểm tra ba số trên có tạo thành tam giác
int isTriangle(int a, int b, int c);

int main() {
	int a, b, c;
	getIntValues(&a, &b, &c);

	printf("Gia tri vua nhap: %d, %d, %d\n", a, b, c);

	if (isTriangle(a, b, c)) {
		printf("Tao thanh tam giac");
	}
	else {
		printf("Khong tao thanh tam giac");
	}

	return 0;
}

void getIntValues(int* a, int* b, int* c) {
	puts("Nhap ba so nguyen: ");
	scanf("%d%d%d", a, b, c);// con trỏ không cần & trước tên biến
}

int isTriangle(int a, int b, int c) {
	return (a + b > c && a + c > b && b + c > a);
} 