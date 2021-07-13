// Nhập vào một chuỗi kí tự và chuyển đổi nó thành giá trị số kiểu long
// theo các cách khác nhau: từ hệ 2, 8, 10, 16 sang

#include <stdio.h>
#include <stdlib.h>

/*
* @author Branium Academy
*/

int main() {
	char str[40];
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao mot chuoi: ");
	// nhập vào: 10101100
	scanf("%39[^\n]", str); // đọc cả dòng
	char* remain;
	// chuyển từ str hệ 2 sang number ở hệ 10
	// long number = strtol(str, &remain, 2);

	// chuyển từ str hệ 8 sang number ở hệ 10
	// long number = strtol(str, &remain, 8);

	// chuyển từ str hệ 16 sang number ở hệ 10
	long number = strtol(str, &remain, 16);

	// hiện kết quả
	printf("Ban vua nhap \"%s\", gia tri double sau chuyen doi: %ld\n", str, number);
	printf("Phan con lai cua chuoi sau khi chuyen doi: %s\n", remain);

	return 0;
}
