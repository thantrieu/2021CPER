// Viết chương trình quản lí học sinh sử dụng typedef

#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

// cấu trúc họ tên
typedef struct {
	char first[10];
	char mid[20];
	char last[10];
} FullName;

// tạo cấu trúc học sinh
typedef struct {
	int id;					// mã học sinh
	FullName name;			// họ tên
	char address[40];		// địa chỉ
	char phoneNumber[20];	// số đt
	float avgGrades;		// điểm TB
} Student;

// hàm nguyên mẫu:
// nhập mới thông tin học sinh
void getStudentInfo(Student* s);
// hàm hiển thị thông tin học sinh
void showStudentInfo(Student s);
// hàm tìm học sinh theo mã
int searchById(const Student* students, size_t n, int id);
// hàm tìm học sinh theo tên
void searchByName(const Student* students, size_t n,
	Student* result, size_t* found, const char* name);
// hàm sắp xếp theo điểm giảm dần
void sortByGrades(Student* students, size_t n);
// hàm tìm học sinh theo điểm
void searchByGrades(const Student* students, size_t n,
	Student* result, size_t* found, float g);
// hàm hiển thị danh sách học sinh
void showListStudents(const Student* students, size_t n);

int main() {
	int choice;
	Student students[100]; // giả sử có tối đa 100 sv
	size_t n = 0; // số sinh viên thực tế
	do {
		puts("============ QUAN LY HOC SINH ============");
		puts("1. Them moi 1 hoc sinh vao danh sach");
		puts("2. Tim mot hoc sinh theo ma");
		puts("3. Tim mot hoc sinh theo ten");
		puts("4. Hien thi danh sach hoc sinh ra man hinh");
		puts("5. Sap xep danh sach hoc sinh theo diem giam dan");
		puts("6. Tim hoc sinh theo diem");
		puts("0. Thoat chuong trinh");
		puts("Xin moi ban chon: ");
		scanf("%d", &choice);

		switch (choice)
		{
		case 0:
			system("cls");
			puts("\n");
			puts("========================================");
			puts("===> CAM ON BAN DA SU DUNG DICH VU! <===");
			puts("========================================");
			break;
		case 1:
		{
			Student s;
			getStudentInfo(&s);
			students[n++] = s;
			system("cls"); // xóa màn hình cũ
			break;
		}
		case 2:
		{
			int id;
			puts("Nhap ma hoc sinh can tim: ");
			scanf("%d", &id);
			int index = searchById(students, n, id);
			if (index == -1) {
				printf("--> Hoc sinh ma %d khong ton tai <--\n", id);
			}
			else {
				printf("Tim thay hoc sinh ma %d\n", id);
				printf("%-10s%-10s%-20s%-10s%-30s%-15s%-10s\n", "Ma HS",
					"Ho", "Dem", "Ten", "Dia chi", "So DT", "Diem TB");
				showStudentInfo(students[index]);
			}
			break;
		}
		case 3:
		{
			size_t numberOfResult = 0;
			Student result[100];
			char name[10];
			puts("Nhap ten hoc sinh can tim: ");
			scanf("%s", name);
			searchByName(students, n, result, &numberOfResult, name);
			if (numberOfResult > 0) {
				showListStudents(students, n);
			}
			else {
				printf("--> Khong tim thay hoc sinh co ten \"%s\" <--\n",
					name);
			}
			break;
		}
		case 4:
		{
			system("cls");
			showListStudents(students, n);
			break;
		}
		case 5:
			system("cls");
			sortByGrades(students, n);
			if (n > 0) { // nếu ds không rỗng thì hiển thị kq sau sắp xếp
				showListStudents(students, n);
			}
			break;
		case 6:
		{
			size_t numberOfResult = 0;
			Student result[100];
			float g;
			puts("Nhap diem: ");
			scanf("%f", &g);
			searchByGrades(students, n, result, &numberOfResult, g);
			if (numberOfResult > 0) {
				showListStudents(result, numberOfResult);
			}
			else {
				puts("--> Khong co ket qua <--");
			}
			break;
		}
		default:
			system("cls"); // xóa màn hình cũ
			puts("--> Vui long chon cac chuc nang tu 0 - 6 <--");
			break;
		}
		puts(""); // in xuong dong
	} while (choice != 0);
	return 0;
}

void showListStudents(const Student* students, size_t n) {
	if (n > 0) {
		puts("=========================================="
			" DANH SACH HOC SINH "
			"==========================================");
		printf("%-10s%-10s%-20s%-10s%-30s%-15s%-10s\n", "Ma HS", "Ho", "Dem",
			"Ten", "Dia chi", "So DT", "Diem TB");
		size_t i;
		for (i = 0; i < n; i++) {
			puts("---------------------------------------------------"
				"-----------------------------------------------------");
			showStudentInfo(students[i]);
		}
	}
	else {
		puts("--> Danh sach rong! <--");
	}
}

void sortByGrades(Student* students, size_t n) {
	if (n > 0) {
		void swap(Student*, Student*);
		size_t i, j;
		for (i = 0; i < n - 1; i++)
		{
			for (j = n - 1; j > i; j--)
			{
				if (students[j].avgGrades > students[j - 1].avgGrades) {
					swap(&students[j], &students[j - 1]);
				}
			}
		}
	}
	else {
		puts("--> Danh sach rong khong the sap xep! <--");
	}
}

// hàm đổi chỗ hai sinh viên
void swap(Student* a, Student* b) {
	Student x = *a;
	*a = *b;
	*b = x;
}

int searchById(const Student* students, size_t n, int id) {
	size_t i;
	for (i = 0; i < n; i++) {
		// nếu tìm thấy học sinh trong danh sách
		if (students[i].id == id) {
			return i; // trả về vị trí của học sinh đó trong mảng
		}
	}
	return -1; // nếu k thấy thì return -1
}

void searchByName(const Student* students, size_t n,
	Student* result, size_t* found, const char* name) {
	size_t i;
	for (i = 0; i < n; i++) {
		// nếu tìm thấy tên học sinh trong danh sách
		if (strcmp(students[i].name.first, name) == 0) {
			result[(*found)++] = students[i]; // thêm vào ds k.quả
		}
	}
}

void searchByGrades(const Student* students, size_t n,
	Student* result, size_t* found, float g) {
	size_t i;
	for (i = 0; i < n; i++) {
		// nếu tìm thấy
		if (students[i].avgGrades == g) {
			result[(*found)++] = students[i]; // thêm vào ds kết quả
		}
	}
}

void showStudentInfo(Student s) {
	printf("%-10d%-10s%-20s%-10s%-30s%-15s%-8.2f\n", s.id, s.name.last,
		s.name.mid, s.name.first, s.address, s.phoneNumber, s.avgGrades);
}

void getStudentInfo(Student* s) {
	puts("Ma HS(so nguyen): ");
	scanf("%d", &s->id);
	// nhập họ và tên
	puts("Ho: ");
	scanf("%s", s->name.last);
	puts("Dem: ");
	scanf("%*c%19[^\n]", s->name.mid);
	puts("Ten: ");
	scanf("%s", s->name.first);
	// nhập các thông tin còn lại
	puts("Dia chi: ");
	scanf("%*c%39[^\n]", s->address);
	puts("So dien thoai: ");
	scanf("%*c%19[^\n]", s->phoneNumber);
	puts("Diem TB: ");
	scanf("%f", &s->avgGrades);
}