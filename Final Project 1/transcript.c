#include <stdio.h>
#include <math.h>
#include <string.h>
#include "transcript.h"
/*
* @author Branium Academy
*/

// hàm nhập thông tin bảng điểm
void getTranscriptInfo(Transcript* tran) {
	printf("%s", "Diem chuyen can: ");
	scanf("%f", &tran->grade10);
	printf("%s", "Diem kiem tra giua ki: ");
	scanf("%f", &tran->grade20);
	printf("%s", "Diem bai tap lon: ");
	scanf("%f", &tran->grade30);
	printf("%s", "Diem thi cuoi ki: ");
	scanf("%f", &tran->grade40);
	tran->finalGrade = 0; // mặc định chưa tính điểm tổng kết
	tran->classification[0] = '\0';
}
// hàm hiển thị thông tin bảng điểm
void showTranscript(const Transcript* trans, size_t n) {
	puts("==================================================================="
		" THONG TIN BANG DIEM "
		"====================================================================");
	printf("%-10s| %-10s| %-20s| %-10s| %-10s| %-10s| "
		"%-10s| %-10s| %-15s| %-20s| %-10s|\n", "Ma BD",
		"Ma mon", "Ten mon hoc", "Diem CC", "Diem GK", "Diem BTL",
		"Diem CK", "Diem TK", "Ma SV", "Ten SV", "Xep loai");
	size_t i;
	for (i = 0; i < n; i++)
	{
		puts("---------------------------------------------------"
			"----------------------------------------------------"
			"-----------------------------------------------------");
		printf("%-10d| %-10d| %-20s| %-10.1f| %-10.1f| %-10.1f| "
			"%-10.1f| %-10.1f| %-15s| %-20s| %-10s|\n",
			trans[i].id, trans[i].subject.id, trans[i].subject.name, 
			trans[i].grade10, trans[i].grade20, trans[i].grade30, 
			trans[i].grade40, trans[i].finalGrade, trans[i].student.id, 
			trans[i].student.name, trans[i].classification);
	}
	puts("---------------------------------------------------"
		"----------------------------------------------------"
		"-----------------------------------------------------");
}
// hàm tính điểm tổng kết
void calculFinalGrade(Transcript* trans, size_t n) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		trans[i].finalGrade = 0.1f * trans[i].grade10 + 0.2f * trans[i].grade20
			+ 0.3f * trans[i].grade30 + 0.4f * trans[i].grade40;
		// làm tròn điểm đên 1 chữ số sau dấu phẩy
		trans[i].finalGrade = (float)round(trans[i].finalGrade * 10.0f) / 10;
	}
}

// hàm xếp loại sinh viên
void classify(Transcript* trans, size_t n) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (trans[i].finalGrade < 4) {
			strcpy(trans[i].classification, "F");
		}
		else if (trans[i].finalGrade < 5) {
			strcpy(trans[i].classification, "D");
		}
		else if (trans[i].finalGrade < 6) {
			strcpy(trans[i].classification, "C");
		}
		else if (trans[i].finalGrade < 7) {
			strcpy(trans[i].classification, "C+");
		}
		else if (trans[i].finalGrade < 8) {
			strcpy(trans[i].classification, "B");
		}
		else if (trans[i].finalGrade < 8.5f) {
			strcpy(trans[i].classification, "B+");
		}
		else if (trans[i].finalGrade < 9) {
			strcpy(trans[i].classification, "A");
		}
		else {
			strcpy(trans[i].classification, "A+");
		}
	}
}

// hàm sắp xếp bảng điểm theo thứ tự giảm dần của điểm tổng kết
void sortByFinalGrade(Transcript* trans, size_t n) {
	size_t i, j;
	for (i = 0; i < n - 1; i++)
	{
		for (j = n - 1; j > i; j--)
		{
			// nếu phần tử đứng sau có điểm tổng kết nhỏ hơn
			if (trans[j].finalGrade > trans[j - 1].finalGrade) {
				swap(&trans[j], &trans[j - 1]); // đổi chỗ hai p.tử
			}
		}
	}
}
// hàm đổi chỗ hai phần tử
void swap(Transcript* a, Transcript* b) {
	Transcript tmp = *a;
	*a = *b;
	*b = tmp;
}
// hàm tìm bản ghi trong bảng điểm theo mã
int findTransById(const Transcript* trans, size_t n, int id) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (trans[i].id == id) {
			return i; // trả về vị trí phần tử tìm thấy
		}
	}
	return -1; // mặc định k tìm thấy
}
// hàm tìm bảng điểm theo mã sv và mã môn học
int findTranByStudentSubjectId(const Transcript* trans, size_t n,
	const char* studentId, int subjectId) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(trans[i].student.id, studentId) == 0
			&& trans[i].subject.id == subjectId) {
			return i; // trả về vị trí phần tử tìm thấy
		}
	}
	return -1; // mặc định k tìm thấy
}
// hàm tìm các sinh viên có điểm tổng kết bằng x trong bảng điểm
size_t findStudentByFinalGrade(const Transcript* trans,
	size_t n, Transcript* result, float finalGrade) {
	size_t count = 0;
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (trans[i].finalGrade == finalGrade) {
			result[count++] = trans[i]; // gán phần tử này cho ds kq
		}
	}
	return count; // trả về số kết quả thỏa mãn
}
// hàm tìm các sinh viên có xếp loại y trong bảng điểm
size_t findStudentByClassif(const Transcript* trans, size_t n,
	Transcript* result, const char* classif) {
	size_t count = 0;
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (strcmp(trans[i].classification, classif) == 0) {
			result[count++] = trans[i]; // gán phần tử này cho ds kq
		}
	}
	return count; // trả về số kết quả thỏa mãn
}
// hàm cập nhật các đầu điểm theo mã bảng điểm
int updateById(Transcript* trans, size_t n, int id) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		if (trans[i].id == id) { // nếu tìm thấy thì
			getTranscriptInfo(&trans[i]); // cập nhật các đầu điểm
			return 1; // cập nhật thành công
		}
	}
	return 0; // không tìm thấy, cập nhật thất bại
}
// hàm đọc file bảng điểm
void readFileTrans(Transcript* trans, size_t* n) {
	FILE* fin = fopen("TRANS.TXT", "rb"); // mo file de doc
	if (fin) {
		size_t i = 0;
		Transcript s;
		while (!feof(fin)) {
			fread(&s, sizeof(Transcript), 1, fin); // đọc môn học
			if (feof(fin)) {
				break;
			}
			trans[i] = s;
			i++;
		}
		*n = i; // cập nhật số lượng môn học
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}
// hàm ghi file bảng điểm
void writeFileTrans(const Transcript* trans, size_t n) {
	FILE* fout = fopen("TRANS.TXT", "wb"); // mở file để ghi mới
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++)
		{
			fwrite(&trans[i], sizeof(Transcript), 1, fout);
		}
		fclose(fout);
		puts("--> Ghi bang diem vao file thanh cong! <--");
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}