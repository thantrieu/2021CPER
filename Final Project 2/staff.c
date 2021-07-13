#include <stdio.h>
#include "staff.h"

/*
* @author Branium Academy
*/

// hàm tạo mới thông tin nhân viên
void createStaffInfo(Staff* s) {
	printf("%s", "Ten nhan vien: ");
	scanf("%*c%39[^\n]", s->name);
	printf("%s", "Ngay thang nam sinh: ");
	scanf("%*c%19[^\n]", s->dob);
	printf("%s", "Dia chi: ");
	scanf("%*c%39[^\n]", s->address);
	printf("%s", "Email: ");
	scanf("%*c%39[^\n]", s->email);
	printf("%s", "So dien thoai: ");
	scanf("%*c%19[^\n]", s->phoneNumber);
	printf("%s", "Gioi tinh: ");
	scanf("%*c%9[^\n]", s->gender);
	printf("%s", "Muc luong: ");
	scanf("%f", &s->salary);
}
// hàm hiển thị thông tin nhân viên
void showStaffsInfo(const Staff* staffs, size_t n) {
	puts("=============================================================="
		" DANH SACH NHAN VIEN "
		"==============================================================");
	printf("%-10s| %-20s| %-20s| %-15s| %-20s| %-20s| %-10s| %-15s|\n",
		"Ma NV", "Ten NV", "Dia chi", "Ngay sinh", "Email",
		"So DT", "Gioi tinh", "Muc luong");
	size_t i;
	for (i = 0; i < n; i++)
	{
		puts("-----------------------------------------------------------"
			"------------------------------------------------------------"
			"--------------------------");
		printf("%-10s| %-20s| %-20s| %-15s| %-20s| %-20s| %-10s| %-15.2f|\n", 
			staffs[i].id, staffs[i].name, staffs[i].address, staffs[i].dob, 
			staffs[i].email, staffs[i].phoneNumber, staffs[i].gender, 
			staffs[i].salary);
	}
	puts("-----------------------------------------------------------"
		"------------------------------------------------------------"
		"--------------------------");
}
// hàm tìm nhân viên theo mã
int findStaffById(const Staff* staffs, size_t n, const char* id) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(staffs[i].id, id) == 0) {
			return i; // trả về chỉ số phần tử
		}
	}
	return -1; // mặc định không tìm thấy
}
// hàm đọc file nhân viên
void readFileStaff(Staff* staffs, size_t* n) {
	FILE* fin = fopen("STAFF.TXT", "rb"); // mo file de doc
	if (fin) {
		size_t i = 0;
		Staff s;
		while (!feof(fin)) {
			fread(&s, sizeof(Staff), 1, fin);
			if (feof(fin)) {
				break;
			}
			staffs[i] = s;
			i++;
		}
		*n = i; // cập nhật số lượng nhân viên
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}
// hàm ghi file nhân viên
void writeFileStaff(const Staff* staffs, size_t n) {
	FILE* fout = fopen("STAFF.TXT", "wb"); // mở file để ghi mới
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++)
		{
			fwrite(&staffs[i], sizeof(Staff), 1, fout);
		}
		fclose(fout);
		puts("--> Ghi cac nhan vien vao file thanh cong! <--");
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}
