// Viết chương trình nhập vào một kí tự đơn và hiển thị nó ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

int main() {
	char c; // biến lưu 1 kí tự đơn
	printf("Nhap vao 1 ki tu don: ");
	scanf("%c", &c); // doc vao ki tu c
	printf("Ban vua nhap ki tu \'%c\'\n", c);

	return 0;
}