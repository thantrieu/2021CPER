#pragma once
#include <time.h>
#include "staff.h"
#include "work.h"
/*
* @author Branium Academy
*/

typedef struct {
	int id;					// mã bảng chấm công
	Staff staff;			// nhân viên
	Work work;				// công việc
	char date[20];			// ngày chấm công
	char checkIn[10];		// thời gian check in
	char checkOut[10];		// thời gian check out
	float totalWorkingHours;// tổng số giờ làm việc thực tế
	int bonusHours;			// số giờ được bonus
	float income;			// thu nhập
} TimeSheet;

// hàm tạo mới thông tin chấm công
void createTimeSheetInfo(TimeSheet* s);
// hàm hiển thị thông tin chấm công
void showTimeSheetInfo(const TimeSheet* sheets, size_t n);
// hàm tìm chấm công theo mã
int findTimeSheetById(const TimeSheet* sheets, size_t n, int id);
// hàm tính số giờ làm việc trong tháng cho từng nhân viên
void calculateWH(TimeSheet* sheets, size_t n);
// hàm tính tổng thời gian làm việc của từng người trong tháng
float calculTotalWHForAStaff(TimeSheet* sheets, size_t n, const char* staffId);
// hàm phân tách thời gian checkin/out thành phút
int splitTime(const char* t);
// hàm tính thu nhập cho từng nhân viên
void calculIncome(TimeSheet* sheets, size_t n);
// sắp xếp bảng chấm công theo thứ tự thu nhập giảm dần
void sortTimeSheetByIncome(TimeSheet* sheets, size_t n);
// hàm kiểm tra xem một bản ghi với một nhân viên và công việc đã tồn tại chưa
int findTimeSheetByDate(TimeSheet* sheets, 
	size_t n, const char* staffId, const char *date);
// hàm cập nhật thông tin chấm công trong ngày theo mã bảng chấm công
void updateTimeSheet(TimeSheet* sheets, size_t n, int id);
// hàm xóa một bảng chấm công theo mã
void removeTimeSheetRecord(TimeSheet* sheets, size_t* n, int id);
// hàm đổi chỗ hai phần tử
void swap(TimeSheet* a, TimeSheet* b);
// hàm đọc file chấm công
void readFileTimeSheet(TimeSheet* sheets, size_t* n);
// hàm ghi file chấm công
void writeFileTimeSheet(const TimeSheet* sheets, size_t n);