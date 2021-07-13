#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

// tìm kí tự đầu tiên của s1 xuất hiện trong s2
void fistOccur(const char* s1, const char* s2); 
// tìm vị trí cuối cùng xuất hiện của kí tự c trong chuỗi s
void lastOccur(const char* s, const char c);

int main() {
	char s1[100];
	char s2[100];
	printf("Nhap vao chuoi s1: ");
	scanf("%99[^\n]", s1);

	printf("Nhap vao chuoi s2: ");
	scanf("%*c%99[^\n]", s2);

	fistOccur(s1, s2);

	char c;
	printf("\nNhap ki tu c: ");
	scanf("%*c%c", &c);
	lastOccur(s1, c);

	return 0;
}

void fistOccur(const char* s1, const char* s2) {
	char* res = strpbrk(s1, s2);
	if (res) {
		printf("Ki tu xuat hien dau tien: \'%c\'", *res);
		printf("Vi tri xuat hien: \"%s\"", res);
	}
	else {
		puts("Khong ki tu nao cua s2 xuat hien trong s1");
	}
}

void lastOccur(const char* s, const char c) {
	char* res = strrchr(s, c);
	if (res) {
		printf("\nVi tri cuoi cung cua ki tu \'%c\' trong s: \"%s\"", c, res);
	}
	else {
		printf("\nKi tu \'%c\' khong xuat hien trong s", c);
	}
}
