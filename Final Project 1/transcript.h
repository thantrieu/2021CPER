#pragma once
/*
* @author Branium Academy
*/

#include "student.h"
#include "subject.h"

// cấu trúc bảng điểm
typedef struct {
	int id;				// mã bảng điểm
	Student student;	// sinh viên
	Subject subject;	// môn học
	float grade10;		// điểm chuyên cần 10%
	float grade20;		// điểm giữa kì 20%
	float grade30;		// điểm bài tập lớn 30%
	float grade40;		// điểm cuối kì 40%
	float finalGrade;	// điểm tổng kết
	char classification[10];// xếp loại sinh viên
} Transcript;

// hàm nhập thông tin 1 bản ghi của bảng điểm
void getTranscriptInfo(Transcript* tran);
// hàm hiển thị thông tin bảng điểm
void showTranscript(const Transcript* trans, size_t n);
// hàm tính điểm tổng kết
void calculFinalGrade(Transcript* trans, size_t n);
// hàm xếp loại sinh viên
void classify(Transcript* trans, size_t n);
// hàm sắp xếp bảng điểm theo thứ tự giảm dần của điểm tổng kết
void sortByFinalGrade(Transcript* trans, size_t n);
// hàm tìm các sinh viên có điểm tk bằng x trong bảng điểm, trả về số kq tìm đc
size_t findStudentByFinalGrade(const Transcript* trans, size_t n, 
	Transcript* result, float finalGrade);
// hàm tìm các sinh viên có xếp loại y trong bảng điểm, trả về số kq tìm đc
size_t findStudentByClassif(const Transcript* trans, size_t n, 
	Transcript* result, const char* classif);
// hàm tìm bảng điểm theo mã:
int findTransById(const Transcript* trans, size_t n, int id);
// hàm tìm bảng điểm theo mã sv và mã môn học
int findTranByStudentSubjectId(const Transcript* trans, size_t n, 
	const char* studentId, int subjectId);
// hàm cập nhật các đầu điểm theo mã bảng điểm
int updateById(Transcript* trans, size_t n, int id);
// hàm đọc file bảng điểm
void readFileTrans(Transcript* trans, size_t* n);
// hàm ghi file bảng điểm
void writeFileTrans(const Transcript* trans, size_t n);
// hàm đổi chỗ hai phần tử
void swap(Transcript* a, Transcript* b);