// Bài tập đọc ghi file text số 4
#include <stdio.h>

/*
* @author Branium Academy
*/

// cấu trúc sinh viên
typedef struct {
	char id[20];		// mã sinh viên
	char fullName[40];	// họ tên đầy đủ
	char address[40];	// địa chỉ
	float math;			// điểm toán
	float eng;			// điểm tiếng anh
	float prog;			// điểm lập trình
	float avgGrade;	// điểm TB
} Student;

// hàm nguyên mẫu
// hàm đọc file
void readFile(Student* students, size_t* n);
// hàm ghi file
void writeFile(const Student* students, size_t n, const char* fileName);
// hàm hiển thị
void showStudents(const Student* students, size_t n);
// hàm sắp xếp theo điểm TB giảm dần
void sort(Student* students, size_t n);
// hàm tính điểm trung bình
void calculAvgGrade(Student* students, size_t n);

int main() {
	Student students[100];
	size_t n;
	char fileName[40];
	puts("Nhap ten file dau ra: ");
	scanf("%39s", fileName);

	// hàm đọc file
	readFile(students, &n);
	// hàm tính toán điểm TB
	calculAvgGrade(students, n);
	// hàm hiển thị danh sách sv
	showStudents(students, n);
	// hàm sắp xếp danh sách theo điểm TB giảm dần
	sort(students, n);
	// hàm ghi thông tin sau xử lý ra file
	writeFile(students, n, fileName);

	return 0;
}

void readFile(Student* students, size_t* n) {
	FILE* fin = fopen("STUDENTS.INP", "r"); // mo file de doc
	if (fin) {
		fscanf(fin, "%u", n); // doc so luong sv
		size_t i; 
		for (i = 0; i < *n; i++) {
			// dùng %*c để đọc bỏ kí tự thừa của lần đọc trước đó
			fscanf(fin, "%*c%19[^-]", students[i].id);
			fscanf(fin, "%*c%39[^-]", students[i].fullName);
			fscanf(fin, "%*c%39[^-]", students[i].address);
			fscanf(fin, "%*c%f%*c%f%*c%f%*c", &students[i].math, 
				&students[i].eng, &students[i].prog);
			students[i].avgGrade = 0; // ban dau gan gia tri diem tb = 0
		}
		fclose(fin);
	}
	else {
		puts("Khong the mo file. Vui long kiem tra lai.");
	}
}

void writeFile(const Student* students, size_t n, const char* fileName) {
	FILE* fout = fopen(fileName, "w"); // mo file de ghi
	if (fout) {
		size_t i;
		for (i = 0; i < n; i++) {
			fprintf(fout, "%s-%s-%s-%0.2f-%0.2f-%0.2f-%0.2f\n",
				students[i].id, students[i].fullName,
				students[i].address, students[i].math,
				students[i].eng, students[i].prog, students[i].avgGrade);
		}
		fclose(fout);
	}
	else {
		puts("Khong the tao file. Vui long kiem tra lai.");
	}
}

void showStudents(const Student* students, size_t n) {
	if (n > 0) {
		puts("===================================="
			" DANH SACH SINH VIEN "
			"=====================================");
		printf("%-15s%-20s%-20s%-10s%-10s%-10s%-10s\n",
			"Ma SV", "Ho va ten", "Dia chi", "Toan",
			"Anh", "Lap trinh", "Diem TB");
		size_t i;
		for (i = 0; i < n; i++)
		{
			puts("------------------------------"
				"--------------------------------"
				"--------------------------------");
			printf("%-15s%-20s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",
				students[i].id, students[i].fullName, students[i].address,
				students[i].math, students[i].eng,
				students[i].prog, students[i].avgGrade);
		}
	}
	else {
		puts("--> Danh sach sinh vien rong <--");
	}
}

void sort(Student* students, size_t n) {
	void swap(Student * a, Student * b);
	if (n > 0) {
		size_t i, j;
		for (i = 0; i < n - 1; i++)
		{
			for (j = n - 1; j > i; j--)
			{
				if (students[j].avgGrade > students[j - 1].avgGrade) {
					swap(&students[j], &students[j - 1]);
				}
			}
		}
	}
	else {
		puts("--> Danh sach rong khong the sap xep <--");
	}
}

// hàm đổi chỗ hai phần tử
void swap(Student* a, Student* b) {
	Student s = *a;
	*a = *b;
	*b = s;
}

void calculAvgGrade(Student* students, size_t n) {
	size_t i;
	for (i = 0; i < n; i++)
	{
		students[i].avgGrade = 
			(students[i].math + students[i].eng + students[i].prog) / 3;
	}
}