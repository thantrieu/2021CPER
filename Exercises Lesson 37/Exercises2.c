#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

// hàm đếm xuất hiện của x trong str
int countCharacterX(const char* const str, const char x);
void listedCharactes(const char* const str); // hàm liệt kê từng kí tự

int main() {
	char str[100];
	puts("Nhap chuoi str: ");
	scanf("%99[^\n]", str);
	// goi ham liet ke cac ki tu
	listedCharactes(str);

	return 0;
}

int countCharacterX(const char* const str, const char x) {
	int i;
	int count = 0; // bien dem x
	int n = strlen(str); // do dai chuoi str
	for (i = 0; i < n; i++) {
		if (str[i] == x) {
			count++;
		}
	}
	return count;
}

void listedCharactes(const char* const str) {
	// hàm nguyên mẫu kiểm tra một kí tự có xuất hiện trong chuỗi hay không
	int isExisted(const char* str, const int n, const char x);
	int i;
	printf("%-10s%-10s\n", "Ki tu", "So lan XH");
	int n = strlen(str);
	for (i = 0; i < n; i++) {
		if (!isExisted(str, i, str[i])) {
			int count = countCharacterX(str, str[i]);
			printf("%-10c%-10d\n", str[i], count);
		}
	}
}

int isExisted(const char* str, const int n, const char x) {
	int i;
	for (i = 0; i < n; i++) {
		if (str[i] == x) { // da xuat hien
			return 1;
		}
	}
	return 0; // chua xuat hien
}
