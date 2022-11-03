// Viết chương trình nhập vào họ, đệm, tên sau đó
// nhập vào cả dòng địa chỉ. Khử trôi lệnh
// trong trường hợp này

#include <stdio.h>
#include <string.h> // include vào khi dùng hàm strlen()

/*
* @author Branium Academy
*/

int main() {
	char first[20];
	char mid[20];
	char last[20];
	char address[50];
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap ho cua ban: ");
	scanf("%s", last);
	printf("Nhap ten dem: ");
	scanf("%s", mid);
	printf("Nhap ten cua ban: ");
	scanf("%s", first);
	// để khử trôi lệnh ta dùng %*c
	scanf("%*c"); // đọc bỏ kí tự thừa sau khi đọc tuổi
	printf("Nhap dia chi cua ban: ");
	// cách 1: dùng scanf
	scanf("%49[^\n]", address); // đọc vào cả dòng tối đa 39 kí tự

	// hiện kết quả
	printf("Xin chao ban \"%s %s %s\"!\nDia chi cua ban la: \"%s\"\n", last, mid, first, address);

	return 0;
}