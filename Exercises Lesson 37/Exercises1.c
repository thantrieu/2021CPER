// Nhập vào chuỗi kí tự và một kí tự x. Đếm số lần xuất hiện
// của x trong chuỗi

#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

// hàm đếm xuất hiện của x trong str
int countCharacterX(const char* const str, const char x);

int main() {
	char str[100];
	char x;
	puts("Nhap chuoi str: ");
	scanf("%99[^\n]", str);

	printf("Nhap ki tu x = ");
	scanf("%*c%c", &x);
	int count = countCharacterX(str, x);

	printf("So lan xuat hien cua \'%c\' trong str: %d\n", x, count);

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