#include <stdio.h>
#include "student.h"

/*
* @author Branium Academy
*/

// hàm nhập thông tin sinh viên
void getStudentInfo(Student* s) {
	printf("%s", "Nhap ten sv: ");
	scanf("%*c%39[^\n]", s->name);
	printf("%s", "Nhap dia chi: ");
	scanf("%*c%39[^\n]", s->address);
	printf("%s", "Nhap chuyen nganh: ");
	scanf("%*c%39[^\n]", s->spec);
}
// hàm hiển thị thông tin sinh viên
void showStudentsInfo(const Student* students, size_t n) {
	puts("=============================="
		" DANH SACH SINH VIEN "
		"===============================");
	printf("%-15s| %-20s| %-20s| %-20s|\n", 
		"Ma SV", "Ten SV", "Dia chi", "Chuyen nganh");
	
	size_t i;
	for (i = 0; i < n; i++)
	{
		puts("----------------------------------------"
			"------------------------------------------");
		printf("%-15s| %-20s| %-20s| %-20s|\n", students[i].id, 
			students[i].name, students[i].address, students[i].spec);
	}
	puts("----------------------------------------"
		"------------------------------------------");
}
// hàm tìm kiếm sinh viên theo mã
int findStudentById(const Student* students, size_t n, const char* id) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(students[i].id, id) == 0) {
			return i; // trả về chỉ số phần tử
		}
	}
	return -1; // mặc định không tìm thấy
}
// hàm đọc file sinh viên
void readFileStudent(Student* students, size_t* n) {
	FILE* fin = fopen("STUD.TXT", "rb"); // mo file de doc
	if (fin) {
		size_t i = 0;
		Student s;
		while (!feof(fin)) {
			fread(&s, sizeof(Student), 1, fin);
			if (feof(fin)) {
				break;
			}
			students[i] = s;
			i++;
		}
		*n = i; // cập nhật số lượng sinh viên
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}
// hàm ghi file sinh viên
void writeFileStudent(const Student* students, size_t n) {
	FILE* fout = fopen("STUD.TXT", "wb"); // mở file để ghi mới
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++)
		{
			fwrite(&students[i], sizeof(Student), 1, fout);
		}
		fclose(fout);
		puts("--> Ghi cac sinh vien vao file thanh cong! <--");
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}