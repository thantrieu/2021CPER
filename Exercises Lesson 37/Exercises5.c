// Nhập vào chuỗi kí tự sau đó tách các từ 
// trong chuỗi ra và lưu vào chuỗi kí tự words
// sắp xếp mảng trên theo thứ tự a-z
// sắp xếp mảng trên theo thứ tự z-a
// viết hoa chữ cái đầu từ
// liệt kê các từ ra màn hình

#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include <stdlib.h>

/*
* @author Branium Academy
*/

// hàm tách chuỗi thành các từ
void split(char* s, char** words, int* n);
// hàm sắp xếp các từ trong danh sách a-z
void sortASC(char** words, int n);
// hàm sắp xếp các từ trong danh sách z-a
void sortDESC(char** words, int n);
// hàm liệt kê các từ ra màn hình
void listedWords(char** words, int n);
// hàm viết hoa chữ cái đầu từ
void sentenceCase(char** words, int n);
// hàm đổi chỗ hai chuỗi kí tự
void swap(char** a, char** b);

int main() {
	const int N = 100; // giả sử tối đa 100 từ
	char str[1000];
	printf("Nhap vao chuoi str: ");
	scanf("%999[^\n]", str);
	int n;

	// cấp phát bộ nhớ
	char** words = (char**)malloc(N * sizeof(char*));
	int i;
	for (i = 0; i < N; i++) {
		words[i] = (char*)malloc(30 * sizeof(char));
	}
	// gọi hàm tách
	split(str, words, &n);
	// gọi hàm hiển thị:
	printf("Danh sach cac tu: \n");
	listedWords(words, n);
	// gọi hàm sắp xếp
	sortASC(words, n);
	printf("\nDanh sach cac tu sau sap xep a-z: \n");
	listedWords(words, n);

	sortDESC(words, n);
	printf("\nDanh sach cac tu sau sap xep z-a: \n");
	listedWords(words, n);
	// gọi hàm viết hoa chữ cái đầu từ
	sentenceCase(words, n);
	printf("\nDanh sach cac tu sau viet hoa chu cai dau: \n");
	listedWords(words, n);

	// giải phóng bộ nhớ
	for (i = 0; i < N; i++) {
		free(words[i]);
	}
	free(words);
	return 0;
}

// hàm tách chuỗi thành các từ
void split(char* s, char** words, int* n) {
	const char* delim = " ,.?:;!"; // dấu hiệu phân tách
	char* p = strtok(s, delim);
	int count = 0;
	while (p != NULL) { // nếu vẫn còn nội dung để tách
		strcpy(words[count], p);
		count++;
		p = strtok(NULL, delim);
	}
	*n = count; // lưu lại biến đếm số từ trong chuỗi
}

// hàm sắp xếp các từ trong danh sách a-z
void sortASC(char** words, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--) {
			if (strcmp(words[j], words[j - 1]) < 0) {
				swap(&words[j], &words[j - 1]);
			}
		}
	}
}

// hàm sắp xếp các từ trong danh sách z-a
void sortDESC(char** words, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--) {
			if (strcmp(words[j], words[j - 1]) > 0) {
				swap(&words[j], &words[j - 1]);
			}
		}
	}
}

// hàm đổi chỗ hai mảng kí tự
// để nhận vào địa chỉ của một con trỏ
// ta dùng con trỏ trỏ đến con trỏ
void swap(char** a, char** b) {
	char s[30];
	strcpy(s, *a);
	strcpy(*a, *b);
	strcpy(*b, s);
}

// hàm liệt kê các từ ra màn hình
void listedWords(char** words, int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		printf("%s\n", words[i]);
	}
}

void sentenceCase(char** words, int n) {
	int i;
	for (i = 0; i < n; i++)
	{
		words[i][0] = toupper(words[i][0]);
	}
}