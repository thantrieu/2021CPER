#include <stdio.h>
#include <string.h>
#include <time.h>
#include <stdlib.h>
#include "timesheet.h"

/*
* @author Branium Academy
*/

// hàm tạo mới thông tin chấm công
void createTimeSheetInfo(TimeSheet* s) {
	printf("%s", "Nhap thoi gian check in(hh:mm): ");
	scanf("%9s", s->checkIn);
	printf("%s", "Nhap thoi gian check out(hh:mm): ");
	scanf("%9s", s->checkOut);
	int checkIn = splitTime(s->checkIn);
	int checkOut = splitTime(s->checkOut);
	if (checkIn < 7 * 60) {
		puts("--> Thoi gian check in khong hop le(truoc 7:00) <--");
		strcpy(s->checkIn, "12:00"); // default
	}
	if (checkOut > 19 * 60) {
		puts("--> Thoi gian check out khong hop le(sau 19:00) <--");
		strcpy(s->checkOut, "12:00"); // default
	}
	s->bonusHours = 0; // mặc định chưa có bonus
	s->totalWorkingHours = 0; // tổng số giờ làm trong tháng
	s->income = 0; // mặc định ban đầu thu nhập bằng 0
}
// hàm hiển thị thông tin chấm công
void showTimeSheetInfo(const TimeSheet* sheets, size_t n) {
	puts("=================================================="
		"============ THONG TIN CHAM CONG NHAN VIEN ========"
		"=====================================================");
	printf("%-10s| %-15s| %-10s| %-20s| %-20s| %-15s"
		"| %-10s| %-10s| %-10s| %-15s|\n",
		"Ma CC", "Ngay", "Ma NV", "Ten NV", "Ten cong viec",
		"Luong", "TG ck in", "TG ck out", "Tong TG", "Thu nhap");
	
	size_t i;
	for (i = 0; i < n; i++)
	{
		puts("--------------------------------------------------"
			"----------------------------------------------------"
			"----------------------------------------------------");
		printf("%-10d| %-15s| %-10s| %-20s| %-20s| %-15.2f"
			"| %-10s| %-10s| %-10.2f| %-15.2f|\n",
			sheets[i].id, sheets[i].date, sheets[i].staff.id, sheets[i].staff.name,
			sheets[i].work.name, sheets[i].staff.salary, sheets[i].checkIn,
			sheets[i].checkOut, sheets[i].totalWorkingHours, sheets[i].income);
	}
	puts("--------------------------------------------------"
		"---------------------------------------------------"
		"----------------------------------------------------");
}
// hàm tìm chấm công theo mã
int findTimeSheetById(const TimeSheet* sheets, size_t n, int id) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (sheets[i].id == id) {
			return i; // trả về chỉ số phần tử
		}
	}
	return -1; // mặc định không tìm thấy
}
// hàm kiểm tra xem một bản ghi với một nhân viên 
// trong ngày x đã chấm công chưa
int findTimeSheetByDate(TimeSheet* sheets,
	size_t n, const char* staffId, const char* date) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(sheets[i].staff.id, staffId) == 0
			&& strcmp(sheets[i].date, date) == 0) {
			return i; // trả về vị trí phần tử tìm thấy
		}
	}
	return -1; // chưa  tồn tại
}
// hàm tính số giờ làm việc trong tháng cho từng nhân viên
void calculateWH(TimeSheet* sheets, size_t n) {
	// thời gian làm việc thực tế = tổng số phút đi làm trong ngày chia 60
	size_t i;
	// reset lại tổng giờ
	for (i = 0; i < n; i++)
	{
		sheets[i].totalWorkingHours = 0; // reset giá trị
		sheets[i].totalWorkingHours = 
			calculTotalWHForAStaff(sheets, n, sheets[i].staff.id);
	}
}
// hàm phân tách thời gian checkin/out thành phút
int splitTime(const char* t) {
	char t1[10];
	strcpy(t1, t); // copy t vao t1
	int h = atoi(t1);
	strtok(t1, ":"); // tách bỏ phần giờ và dấu : trong tg checkin/out
	char* p = strtok(NULL, ":");
	int m = atoi(p);
	return 60 * h + m; // trả về tổng số phút
}
// hàm tính thu nhập cho từng nhân viên
void calculIncome(TimeSheet* sheets, size_t n) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (sheets[i].totalWorkingHours >= sheets[i].work.mandatory) {
			sheets[i].bonusHours += 2 * 8;// bonus 2 ngày làm việc
		}
		sheets[i].income = sheets[i].staff.salary *
			(sheets[i].totalWorkingHours + sheets[i].bonusHours) 
			/ sheets[i].work.mandatory;
	}
}
// sắp xếp bảng chấm công theo thứ tự thu nhập giảm dần
void sortTimeSheetByIncome(TimeSheet* sheets, size_t n) {
	size_t i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			// nếu phần tử đứng sau có điểm tổng kết nhỏ hơn
			if (sheets[j].income > sheets[j - 1].income) {
				swap(&sheets[j], &sheets[j - 1]); // đổi chỗ hai p.tử
			}
		}
	}
}
// hàm đổi chỗ hai phần tử
void swap(TimeSheet* a, TimeSheet* b) {
	TimeSheet tmp = *a;
	*a = *b;
	*b = tmp;
}
// hàm cập nhật thông tin chấm công trong ngày theo mã bảng chấm công
void updateTimeSheet(TimeSheet* sheets, size_t n, int id) {
	int index = findTimeSheetById(sheets, n, id);
	if (index == -1) {
		puts("--> Ban ghi ban tim kiem khong ton tai <--");
	}
	else {
		printf("%s", "Nhap thoi gian check in(hh:mm): ");
		scanf("%*c%9s", sheets[index].checkIn);
		printf("%s", "Nhap thoi gian check out(hh:mm): ");
		scanf("%*c%9s", sheets[index].checkOut);
		sheets[index].totalWorkingHours = 0;
		puts("--> Cap nhat thoi gian check in/out thanh cong <--");
	}
}
// hàm xóa một bảng chấm công theo mã
void removeTimeSheetRecord(TimeSheet* sheets, size_t* n, int id) {
	int index = findTimeSheetById(sheets, *n, id);
	if (index == -1) {
		puts("--> Khong tim thay ban ghi nay. Vui long kiem tra lai <--");
	}
	else { // gọi hàm xóa phần tử
		size_t i;
		for (i = index; i < (*n) - 1; i++)
		{
			sheets[i] = sheets[i + 1];
		}
		(*n)--;
		puts("--> Xoa ban ghi thanh cong <--");
	}
}
// hàm tính tổng thời gian làm việc của từng người trong tháng
float calculTotalWHForAStaff(TimeSheet* sheets, size_t n, const char* staffId) {
	float total = 0;
	size_t i;
	for (i = 0; i < n; i++)
	{
		// tính cho từng bản ghi
		if (strcmp(sheets[i].staff.id, staffId) == 0) {
			int checkOutMin = splitTime(sheets[i].checkOut);
			int checkInMin = splitTime(sheets[i].checkIn);
			int sum = 0;
			float workingHours = 0; // thời gian làm việc từng ngày công
			// nếu tg check in/out cùng trước 12:00 hoặc cùng sau 13:00
			if (checkInMin <= (12 * 60) && checkOutMin <= (12 * 60) ||
				checkInMin >= (13 * 60) && checkOutMin >= (13 * 60)) {
				sum = checkOutMin - checkInMin;
			} // nếu không thì trừ tg nghỉ trưa 60'
			else if (checkInMin < (12 * 60) && checkOutMin > (13 * 60)) {
				sum = checkOutMin - checkInMin - 60;
			} // check in trong [12:00-13:00], check out sau 13:00
			else if(checkInMin >= (12 * 60) && checkInMin <= (13 * 60) 
				&& checkOutMin > (13 * 60)) {
				checkInMin = 13 * 60; // ckin luc 13:00
				sum = checkOutMin - checkInMin;
			} // check in truoc 12:00, check out trong [12:00-13:00]
			else if (checkInMin < (12 * 60) && checkOutMin >= (12 * 60)
				&& checkOutMin <= (13 * 60)) {
				checkOutMin = 12 * 60; // ckout luc 12:00
			}
			else { // check in và out trong [12:00 - 13:00]
				checkInMin = checkOutMin = 0;
			}
			
			workingHours = (float)sum / 60;
			// trường hợp nhập sai thời gian checkin/out
			if (workingHours < 0) {
				workingHours = 0;
			}
			total += workingHours;
		}
	}
	return total; // trả về kết quả
}
// hàm đọc file chấm công
void readFileTimeSheet(TimeSheet* sheets, size_t* n) {
	FILE* fin = fopen("SHEET.TXT", "rb"); // mo file de doc
	if (fin) {
		size_t i = 0;
		TimeSheet s;
		while (!feof(fin)) {
			fread(&s, sizeof(TimeSheet), 1, fin);
			if (feof(fin)) {
				break;
			}
			sheets[i] = s;
			i++;
		}
		*n = i; // cập nhật số lượng bảng chấm công
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}
// hàm ghi file chấm công
void writeFileTimeSheet(const TimeSheet* sheets, size_t n) {
	FILE* fout = fopen("SHEET.TXT", "wb"); // mở file để ghi mới
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++)
		{
			fwrite(&sheets[i], sizeof(TimeSheet), 1, fout);
		}
		fclose(fout);
		puts("--> Ghi bang cham cong vao file thanh cong! <--");
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}