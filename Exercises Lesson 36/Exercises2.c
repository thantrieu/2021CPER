// Nhập vào một chuỗi kí tự từ bàn phím và
// cho biết chuỗi có tất cả bao nhiêu kí tự trừ '\0'

#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

int main() {
	char str1[100];
	char str2[100];
	printf("Nhap vao chuoi ki tu s1: ");
	scanf("%9[^\n]", str1);
	printf("Nhap vao chuoi ki tu s2: ");
	scanf("%*c%9[^\n]", str2);

	// để nối được chuỗi s2 vào s1 thì hiệu số tổng kí tự trong s1
	// và số kí tự thực tế trong s1, s2 phải >= 1
	// chừa 1 chỗ cho kí tự '\0'

	int remain = sizeof(str1) - strlen(str1) - strlen(str2);
	if (remain >= 1) {
		strcat(str1, str2);
		printf("Chuoi ki tu sau khi noi: \"%s\"", str1);
	}
	else {
		puts("Khong noi duoc s2 vao s1");
	}
	
	return 0;
}