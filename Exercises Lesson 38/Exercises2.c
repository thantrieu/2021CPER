// Nhập vào một chuỗi kí tự từ bàn phím và
// chuyển đổi chuỗi kí tự thành chữ hoa hoàn toàn
// chuyển đổi chuỗi thành chữ thường hoàn toàn
// chuyển đổi kí tự hoa thường xen kẽ
// viết hoa chữ cái đầu từ

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
* @author Branium Academy
*/

void toUpperCase(char* str); // viết hoa hoàn toàn
void toLowerCase(char* str); // viết thường hoàn toàn
void toLCSideBySide(char* str); // viết hoa thường xen kẽ
void toSentenceCase(char* str); // viết hoa chữ cái đầu từ

int main() {
	char str[200];
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao mot chuoi ki tu: ");
	scanf("%[^\n]", str);
	// hiện kết quả
	printf("Chuoi ban dau: %s\n", str);

	toUpperCase(str);
	printf("Chuyen thanh ki tu hoa: %s\n", str);

	toLowerCase(str);
	printf("Chuyen thanh ki tu thuong: %s\n", str);

	toLCSideBySide(str);
	printf("Chuyen thanh ki tu hoa thuong xen ke: %s\n", str);

	toLowerCase(str); // chuyen ve chu thuong hoan toan
	toSentenceCase(str);
	printf("Viet hoa chu cai dau tu: %s\n", str);

	return 0;
}

void toUpperCase(char* str) {
	int i;
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		str[i] = toupper(str[i]);
	}
}

void toLowerCase(char* str) {
	int i;
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		str[i] = tolower(str[i]);
	}
}

void toLCSideBySide(char* str) {
	int i;
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		if (i % 2 == 0) {
			str[i] = toupper(str[i]);
		}
		else {
			str[i] = tolower(str[i]);
		}
	}
}

void toSentenceCase(char* str) {
	int i;
	int n = strlen(str); // lay do dai chuoi
	str[0] = toupper(str[0]);
	for (i = 0; i < n; i++) {
		if (i < n - 1 && isspace(str[i]) && !isspace(str[i+1])) {
			str[i + 1] = toupper(str[i + 1]);
		}
	}
}