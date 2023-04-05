// là tên và điểm TB. Trong đó tên dành 20 vị trí để in ra căn
// lề trái và điểm TB căn lề trái dùng 10 vị trí để in ra

#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

// hàm nhập danh sách sinh viên
void fillNames(char names[][20], int n);
// hàm hiển thị danh sách
void showInfo(char names[][20], int n);

int main() {
	int n;
	char names[100][20];
	puts("Nhap so sinh vien: ");
	scanf("%d", &n);
	if (n > 0) {
		puts("Nhap ho ten sinh vien: ");
		fillNames(names, n);
		
		puts("DANH SACH SINH VIEN:");
		showInfo(names, n);
	}
	else {
		puts("Nhap n > 0");
	}
	return 0;
}

void fillNames(char names[][20], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Ten sv thu %d = ", i);
		scanf("%*c%40[a-zA-Z ]", names[i]);
	}
}

void showInfo(char names[][20], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%d. %-20s\n", i, names[i]);
	}
}