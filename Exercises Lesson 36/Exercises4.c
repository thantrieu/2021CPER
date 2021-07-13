// Nhập vào danh sách tên n người tùy ý sau đó thực hiện:
// sắp xếp danh sách theo thứ tự tăng dần bảng chữ cái
// sắp xếp danh sách theo thứ tự giảm dần bảng chữ cái
// hiện kết quả lên màn hình

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/*
* @author Branium Academy
*/

void getFriendNames(char** names, int n); // nhập danh sách bạn bè
void sortASC(char** names, int n); // sắp xếp danh sách a-z
void sortDESC(char** names, int n); // sắp xếp danh sách z-a
void showList(char** names, int n); // hiện danh sách
void swap(char** a, char** b); // hàm đổi chỗ hai mảng char

int main() {
	int n;
	printf("Nhap vao so nguoi ban cua ban: ");
	scanf("%d", &n);
	if (n > 0) {
		char** names = (char**)malloc(n * sizeof(char*));
		int i;
		for (i = 0; i < n; i++) {
			names[i] = (char*)malloc(sizeof(char) * 40);
		}
		getFriendNames(names, n);
		puts("\nDanh sach truoc sap xep: ");
		showList(names, n);

		puts("\nDanh sach sap xep tang dan: ");
		sortASC(names, n);
		showList(names, n);

		puts("\nDanh sach sap xep giam dan: ");
		sortDESC(names, n);
		showList(names, n);

		// giải phóng bộ nhớ
		for (i = 0; i < n; i++) {
			free(names[i]);
		}
		free(names);
	}
	else {
		puts("Nhap n > 0");
	}
	return 0;
}

void getFriendNames(char** names, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Ten nguoi thu %d: ", i + 1);
		scanf("%39s", names[i]);
	}
}

void sortASC(char** names, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			// hieu phan tu j - phan tu i se < 0
			if (strcmp(names[j], names[j - 1]) < 0) {
				swap(&names[j], &names[j - 1]);
			}
		}
	}
}

void swap(char** a, char** b) {
	// khi doi cho chuoi ki tu dung ham strcpy, khong dung phep gan
	char name[40];
	strcpy(name, *a);
	strcpy(*a, *b);
	strcpy(*b, name);
}

void sortDESC(char** names, int n) {
	int i, j;
	for (i = 0; i < n - 1; i++) {
		for (j = n - 1; j > i; j--) {
			// hieu phan tu j - phan tu i se > 0
			if (strcmp(names[j], names[j - 1]) > 0) {
				swap(&names[j], &names[j - 1]);
			}
		}
	}
}

void showList(char** names, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%s\n", names[i]);
	}
}
