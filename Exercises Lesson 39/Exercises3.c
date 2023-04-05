// Nhập vào một số và chuyển đổi nó thành chuỗi kí tự
// theo các cách khác nhau: từ hệ 10 sang hệ 2, 8, 10, 16

#include <stdio.h>
#include <stdlib.h>

/*
* @author Branium Academy
*/

int main() {
	char str[65];
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao mot so nguyen duong: ");
	long number;
	scanf("%ld", &number);
	
	int base = 32; // thay bằng các giá trị khác từ 2 - 36
	_ltoa(number, str, base);

	// hiện kết quả
	printf("Gia tri so: %ld\n", number);
	printf("Gia tri chuoi sau chuyen doi: %s\n", str);

	return 0;
}
