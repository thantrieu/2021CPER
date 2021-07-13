#pragma once

/*
* @author Branium Academy
*/

typedef struct {
	int id;				// mã công việc
	char name[40];		// tên công việc
	char description[40];	// mô tả công việc
	int mandatory;		// số giờ làm việc bắt buộc
} Work;

// hàm tạo mới thông tin công việc
void createWorkInfo(Work* w);
// hàm hiển thị thông tin công việc
void showWorksInfo(const Work* works, size_t n);
// hàm tìm công việc theo mã
int findWorkById(const Work* works, size_t n, int id);
// hàm đọc file công việc
void readFileWork(Work* works, size_t* n);
// hàm ghi file công việc
void writeFileWork(const Work* works, size_t n);