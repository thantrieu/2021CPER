#pragma once
/*
* @author Branium Academy
*/

// cấu trúc sinh viên
typedef struct {
	char id[20];		// mã sinh viên
	char name[40];		// tên
	char address[40];	// địa chỉ
	char spec[40];		// chuyên ngành
} Student;

// hàm nhập thông tin sinh viên
void getStudentInfo(Student* s);
// hàm hiển thị thông tin sinh viên
void showStudentsInfo(const Student* students, size_t n);
// hàm tìm kiếm sinh viên theo mã
int findStudentById(const Student* students, size_t n, const char* id);
// hàm đọc file sinh viên
void readFileStudent(Student* students, size_t* n);
// hàm ghi file sinh viên
void writeFileStudent(const Student* students, size_t n);