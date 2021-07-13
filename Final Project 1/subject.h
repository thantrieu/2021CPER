#pragma once
/*
* @author Branium Academy
*/

// cấu trúc môn học
typedef struct {
	int id;				// mã môn học
	char name[40];		// tên môn học
	int credits;		// số tín chỉ
} Subject;

// hàm nhập thông tin môn học
void getSubjectInfo(Subject* s);
// hàm hiển thị thông tin môn học
void showSubjects(const Subject* subjects, size_t n);
// hàm tìm kiếm môn học theo mã
int findSubjectById(const Subject* subjects, size_t n, int id);
// hàm đọc file môn học
void writeFileSubject(const Subject* subjects, size_t n);
// hàm ghi file môn học
void readFileSubject(Subject* subjects, size_t* n);