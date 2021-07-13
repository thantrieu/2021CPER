#include <stdio.h>
#include "subject.h"

/*
* @author Branium Academy
*/

// hàm nhập thông tin môn học
void getSubjectInfo(Subject* s) {
	printf("Nhap ten mon hoc: ");
	scanf("%*c%39[^\n]", s->name);
	printf("So tin chi: ");
	scanf("%d%*c", &s->credits);
}
// hàm hiển thị thông tin môn học
void showSubjects(const Subject* subjects, size_t n) {
	puts("============== DANH SACH MON HOC ==============");
	printf("%-10s| %-20s| %-12s|\n", "Ma MH", "Ten mon hoc", "So TC");
	size_t i;
	for (i = 0; i < n; i++)
	{
		puts("-----------------------------------------------");
		printf("%-10d| %-20s| %-12d|\n", 
			subjects[i].id, subjects[i].name, subjects[i].credits);
	}
	puts("-----------------------------------------------");
}
// hàm tìm kiếm môn học theo mã
int findSubjectById(const Subject* subjects, size_t n, int id) {
	size_t i;
	for (i = 0; i < n; i++) {
		// nếu mã môn cần tìm trùng với tk bất kì trong ds
		if (subjects[i].id == id) {
			return i; // trả về chỉ số của phần tử trong mảng
		}
	}
	return -1; // không tìm thấy môn học
}
// hàm đọc file môn học
void writeFileSubject(const Subject* subjects, size_t n) {
	FILE* fout = fopen("SUBJ.TXT", "wb"); // mở file để ghi mới
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++)
		{
			fwrite(&subjects[i], sizeof(Subject), 1, fout);
		}
		fclose(fout);
		puts("--> Ghi cac mon hoc vao file thanh cong! <--");
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}
// hàm ghi file môn học
void readFileSubject(Subject* subjects, size_t* n) {
	FILE* fin = fopen("SUBJ.TXT", "rb"); // mo file de doc
	if (fin) {
		size_t i = 0;
		Subject s;
		while (!feof(fin)) {
			fread(&s, sizeof(Subject), 1, fin); // đọc môn học
			if (feof(fin)) {
				break;
			}
			subjects[i] = s;
			i++;
		}
		*n = i; // cập nhật số lượng môn học
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}