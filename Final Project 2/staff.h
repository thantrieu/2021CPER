#pragma once
/*
* @author Branium Academy
*/

typedef struct {
	char id[20];			// mã nhân viên
	char name[40];			// họ và tên
	char dob[20];			// ngày tháng năm sinh
	char address[40];		// địa chỉ
	char email[40];			// email
	char phoneNumber[20];	// số điện thoại
	char gender[20];		// giới tính
	float salary;			// mức lương
} Staff;

// hàm tạo mới thông tin nhân viên
void createStaffInfo(Staff* s);
// hàm hiển thị thông tin nhân viên
void showStaffsInfo(const Staff* staffs, size_t n);
// hàm tìm nhân viên theo mã
int findStaffById(const Staff* staffs, size_t n, const char* id);
// hàm đọc file nhân viên
void readFileStaff(Staff* staffs, size_t* n);
// hàm ghi file nhân viên
void writeFileStaff(const Staff* staffs, size_t n);