// Viết chương trình nhập vào một chuỗi kí tự và hiển thị nó ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

int main() {
	char str[100]; // biến lưu 1 chuỗi kí tự tối đa 99 kí tự
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao 1 chuoi ki tu: ");
	scanf("%s", str); // doc vao chuoi ki tu tu ban phim
	printf("Ban vua nhap chuoi ki tu \"%s\"\n", str);

	return 0;
}