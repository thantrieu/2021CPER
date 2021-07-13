#include <stdio.h>
#include "work.h"

/*
* @author Branium Academy
*/

// hàm tạo mới thông tin công việc
void createWorkInfo(Work* w) {
	printf("%s", "Ten cong viec: ");
	scanf("%*c%39[^\n]", w->name);
	printf("%s", "Mo ta cong viec: ");
	scanf("%*c%39[^\n]", w->description);
	printf("%s", "So gio lam viec bat buoc: ");
	scanf("%d", &w->mandatory);
}
// hàm hiển thị thông tin công việc
void showWorksInfo(const Work* works, size_t n) {
	puts("======================= DANH SACH CONG VIEC =======================");
	printf("%-10s| %-20s| %-20s| %-10s|\n",
		"Ma CV", "Ten CV", "Mo ta", "So gio");
	
	size_t i;
	for (i = 0; i < n; i++)
	{
		puts("---------------------------------"
			"----------------------------------");
		printf("%-10d| %-20s| %-20s| %-10d|\n", works[i].id,
			works[i].name, works[i].description, works[i].mandatory);
	}
	puts("---------------------------------"
		"----------------------------------");
}
// hàm tìm công việc theo mã
int findWorkById(const Work* works, size_t n, int id) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (works[i].id == id ) {
			return i; // trả về chỉ số phần tử
		}
	}
	return -1; // mặc định không tìm thấy
}
// hàm đọc file công việc
void readFileWork(Work* works, size_t* n) {
	FILE* fin = fopen("WORK.TXT", "rb"); // mo file de doc
	if (fin) {
		size_t i = 0;
		Work s;
		while (!feof(fin)) {
			fread(&s, sizeof(Work), 1, fin);
			if (feof(fin)) {
				break;
			}
			works[i] = s;
			i++;
		}
		*n = i; // cập nhật số lượng công việc
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}
// hàm ghi file công việc
void writeFileWork(const Work* works, size_t n) {
	FILE* fout = fopen("WORK.TXT", "wb"); // mở file để ghi mới
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++)
		{
			fwrite(&works[i], sizeof(Work), 1, fout);
		}
		fclose(fout);
		puts("--> Ghi cac cong viec vao file thanh cong! <--");
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}