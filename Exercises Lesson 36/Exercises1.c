// Nhập vào một chuỗi kí tự từ bàn phím và
// cho biết chuỗi có tất cả bao nhiêu kí tự trừ '\0'

#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

int main() {
	char str[100];
	printf("Nhap vao chuoi ki tu: ");
	scanf("%99[^\n]", str);
	printf("Chuoi ki tu cua ban la: \"%s\"", str);
	// dùng hàm strlen() để lấy độ dài chuỗi
	printf("\nChuoi co %d ki tu\n", strlen(str));

	return 0;
}