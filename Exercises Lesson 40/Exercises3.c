// Viết chương trình nhập vào hai danh sách: tên và điểm TB
// hiển thị danh sách trên sao cho mỗi dòng chứa hai thông tin
// là tên và điểm TB. Trong đó tên dành 20 vị trí để in ra căn
// lề trái và điểm TB căn lề trái dùng 10 vị trí để in ra

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm nhập điểm
void fillGrades(float* grades, int n);
// hàm nhập tên
void fillNames(char names[][20], int n);
// hàm hiển thị tên và điểm tương ứng
void showInfo(char names[][20], float* grades, int n);

int main() {
	int n;
	char names[100][20];
	float grades[100];
	puts("Nhap so sinh vien: ");
	scanf("%d", &n);
	if (n > 0) {
		puts("Nhap ho ten sinh vien: ");
		fillNames(names, n);
		puts("Nhap diem: ");
		fillGrades(grades, n);
		puts("DANH SACH SINH VIEN");
		printf("------------------------------\n");
		printf("%-20s| %-10s\n", "Ho Va Ten", "Diem TB");
		printf("------------------------------\n");
		showInfo(names, grades, n);
	}
	else {
		puts("Nhap n > 0");
	}
	return 0;
}

void fillGrades(float* grades, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Diem sv thu %d = ", i);
		scanf("%f", &grades[i]);
	}
}

void fillNames(char names[][20], int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("Ten sv thu %d = ", i);
		scanf("%*c%19[^\n]", names[i]);
	}
}

void showInfo(char names[][20], float* grades, int n) {
	int i;
	for (i = 0; i < n; i++) {
		printf("%-20s| %-8.2f\n", names[i], grades[i]);
		printf("------------------------------\n");
	}
}