// Nhập vào một chuỗi kí tự từ bàn phím và kiểm tra xem trong đó có
// bao nhiêu chữ cái
// bao nhiêu chữ số
// bao nhiêu chữ cái hoặc chữ số
// bao nhiêu khoảng trắng
// bao nhiêu kí tự không phải chữ cái, số

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
* @author Branium Academy
*/

int countAlphabet(char* str);	// đếm chữ cái
int countDigits(char* str);		// đếm chữ số
int countAlNum(char* str);		// đếm chữ cái hoặc chữ số
int countSpace(char* str);		// đếm khoảng trắng
int countNotAlNum(char* str);	// đếm kí tự không phải chữ, số

int main() {
	char str[200];
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao mot chuoi ki tu: ");
	scanf("%[^\n]", str);
	// hiện kết quả
	printf("Chuoi ban dau: %s\n", str);
	printf("So ki tu chu cai: %d\n", countAlphabet(str));
	printf("So ki tu chu so: %d\n", countDigits(str));
	printf("So ki tu chu cai hoac chu so: %d\n", countAlNum(str));
	printf("So ki tu khoang trang: %d\n", countSpace(str));
	printf("So ki tu chu khong phai chu cai, chu so: %d\n", countNotAlNum(str));

	return 0;
}

int countAlphabet(char* str) {
	int i;
	int count = 0; // dem so ki tu thoa man
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		if (isalpha(str[i])) {
			count++;
		}
	}
	return count;
}

int countDigits(char* str) {
	int i;
	int count = 0; // dem so ki tu thoa man
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		if (isdigit(str[i])) { // nếu là kí tự số
			count++;
		}
	}
	return count;
}

int countAlNum(char* str) {
	int i;
	int count = 0; // dem so ki tu thoa man
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		if (isalnum(str[i])) { // nếu là số hoặc chữ
			count++;
		}
	}
	return count;
}

int countSpace(char* str) {
	int i;
	int count = 0; // dem so ki tu thoa man
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		if (isspace(str[i])) { // nếu là khoảng trắng
			count++;
		}
	}
	return count;
}

int countNotAlNum(char* str) {
	int i;
	int count = 0; // dem so ki tu thoa man
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		if (!isalnum(str[i])) { // không phải chữ hoặc số
			count++;
		}
	}
	return count;
}