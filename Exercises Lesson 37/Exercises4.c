#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

// hàm đếm số lần xuất hiện của s2 trong s1
int countS2InS1(const char* s1, const char* s2);

int main() {
	char s1[100];
	char s2[100];
	printf("Nhap vao chuoi s1: ");
	scanf("%99[^\n]", s1);

	printf("Nhap vao chuoi s2: ");
	scanf("%*c%99[^\n]", s2);

	int count = countS2InS1(s1, s2);
	if (count != 0) {
		printf("Chuoi s2 xuat hien %d lan trong s1\n", count);
	}
	else {
		puts("S2 khong xuat hien trong s1");
	}

	return 0;
}

int countS2InS1(const char* s1, const char* s2) {
	// ham copy
	void mCopy(char* s, const char* s2, int n);
	char* p = strstr(s1, s2);
	char s[100];
	int count = 0;
	while (p != NULL) {
		mCopy(s, p, strlen(s2));
		count++; // tăng biến đếm
		p = strstr(s, s2); // tiếp tục tìm s2 trong phần còn lại
	}
	return count;
}

void mCopy(char* s, const char* s2, int n) {
	int i;
	for (i = n; i <= strlen(s2); i++) {
		s[i - n] = s2[i];
	}
}
