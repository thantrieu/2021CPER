// Viết chương trình quản lí nhân viên

#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

// cấu trúc họ tên
struct fullName {
	char first[10];
	char mid[20];
	char last[10];
};

// tạo cấu trúc nhân viên
struct staff {
	char id[20];			// mã nhân viên
	struct fullName name;	// họ tên
	char role[40];			// chức vụ
	int actual;				// số ngày làm việc thực tế
	int mandatory;			// số công chuẩn
	float salary;			// lương
	float income;			// thu nhập
};

// hàm nguyên mẫu
// hàm tạo mới một nhân viên
void addNewStaff(struct staff* s);
// hàm xóa nhân viên theo mã
int removeStaff(struct staff* staffs, size_t* n, char* id);
// hàm cập nhật chấm công cho nhân viên
int updateDOW(struct staff* s, size_t n, char* id, int dow);
// hàm tính lương và bonus
void calculateTotalIncome(struct staff* staffs, size_t n);
// hàm sắp xếp danh sách nhân viên theo tổng lương giảm dần
void sortByIncome(struct staff* staffs, size_t n);
// hàm sắp xếp danh sách nhân viên theo tên tăng dần
void sortByName(struct staff* staffs, size_t n);
// hàm hiển thị danh sách nhân viên hiện có ra màn hình
void listedStaffMembers(const struct staff* staffs, size_t n);
// hàm đổi chỗ hai nhân viên
void swap(struct staff* a, struct staff* b);
// hàm hiển thị 1 nhân viên
void showAStaff(struct staff s);

int main() {
	int choice;
	struct staff staffs[100]; // giả sử có tối đa 100 sv
	size_t n = 0; // số nhân viên thực tế
	do {
		puts("============ QUAN LY NHAN VIEN ============");
		puts("1. Them moi nhan vien vao danh sach");
		puts("2. Xoa nhan vien theo ma");
		puts("3. Cap nhat cham cong theo ma");
		puts("4. Tinh luong nhan vien");
		puts("5. Sap xep danh sach theo luong giam dan");
		puts("6. Sap xep danh sach theo ten a-z");
		puts("7. Hien danh sach nhan vien");
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
			struct staff s;
			addNewStaff(&s);
			staffs[n++] = s;
			system("cls"); // xóa màn hình cũ
			break;
		}
		case 2:
		{
			system("cls");
			char id[20];
			puts("Nhap ma nhan vien can xoa: ");
			scanf("%19s", id);
			int index = removeStaff(staffs, &n, id);
			if (index == 0) {
				printf("--> Nhan vien ma %s khong ton tai! <--\n", id);
			}
			else {
				puts("--> Xoa thanh cong! <--");
			}
			break;
		}
		case 3:
		{
			char id[20];
			int dow; // actual day of work
			puts("Nhap ma nhan vien can cap nhat ngay cong:");
			scanf("%19s", id);
			puts("Nhap vao so ngay lam viec thuc te: ");
			scanf("%d", &dow);
			if (dow < 0) {
				puts("--> So ngay lam viec thuc te khong the am <--");
			}
			else {
				int index = updateDOW(staffs, n, id, dow);
				if (index == 0) {
					printf("--> Nhan vien ma %s khong ton tai <--\n", id);
				}
				else {
					puts("--> Cap nhat ngay cong thanh cong! <--");
				}
			}
			break;
		}
		case 4:
		{
			system("cls");
			calculateTotalIncome(staffs, n);
			if (n > 0) {
				listedStaffMembers(staffs, n);
			}
			else {
				puts("--> Danh sach nhan vien rong! <--");
			}
			break;
		}
		case 5:
			system("cls");
			sortByIncome(staffs, n);
			if (n > 0) { // nếu ds không rỗng thì hiển thị kq sau sắp xếp
				listedStaffMembers(staffs, n);
			}
			break;
		case 6:
		{
			system("cls");
			sortByName(staffs, n);
			if (n > 0) { // nếu ds không rỗng thì hiển thị kq sau sắp xếp
				listedStaffMembers(staffs, n);
			}
			break;
		}

		case 7:
		{
			system("cls");
			listedStaffMembers(staffs, n);
			break;
		}
		default:
			system("cls"); // xóa màn hình cũ
			puts("--> Vui long chon cac chuc nang tu 0 - 7 <--");
			break;
		}
		puts(""); // hiển thị xuống dòng
		//system("cls");
	} while (choice != 0);
	return 0;
}

void addNewStaff(struct staff* s) {
	puts("Ma NV: ");
	scanf("%s", s->id);
	// nhập họ và tên
	puts("Ho: ");
	scanf("%s", s->name.last);
	puts("Dem: ");
	scanf("%*c%19[^\n]", s->name.mid);
	puts("Ten: ");
	scanf("%s", s->name.first);
	// nhập các thông tin còn lại
	puts("Chuc vu: ");
	scanf("%*c%39[^\n]", s->role);
	puts("So ngay lam viec thuc te: ");
	scanf("%d", &s->actual);
	puts("So ngay lam viec bat buoc: ");
	scanf("%d", &s->mandatory);
	puts("Luong thang: ");
	scanf("%f", &s->salary);
	s->income = 0; // mặc định ban đầu lương = 0
}

int removeStaff(struct staff* staffs, size_t* n, char* id) {
	size_t i, j;
	for (i = 0; i < *n; i++) {
		// nếu tìm thấy 
		if (strcmp(staffs[i].id, id) == 0) {
			for (j = i; j < (*n) - 1; j++)
			{
				// xóa và dồn các phần tử bên phải phần tử
				// thứ i này sang trái 1 đơn vị
				staffs[j] = staffs[j + 1];
			}
			(*n)--; // giảm số phần tử trong danh sách đi 1
			return 1; // trả về thông báo xóa thành công
		}
	}
	return 0; // nếu k thấy thì return 0 - xóa thất bại
}

int updateDOW(struct staff* staffs, size_t n, char* id, int dow) {
	size_t i;
	for (i = 0; i < n; i++) {
		// nếu tìm thấy 
		if (strcmp(staffs[i].id, id) == 0) {
			staffs[i].actual = dow; // cập nhật số ngày làm việc
			return 1; // trả về thông báo xóa thành công
		}
	}
	return 0; // nếu k thấy thì return 0 - xóa thất bại
}

void calculateTotalIncome(struct staff* staffs, size_t n) {
	size_t i;
	for (i = 0; i < n; i++) {
		int bonusDay = 0;
		if (staffs[i].actual >= staffs[i].mandatory) {
			bonusDay = 2;
		}
		staffs[i].income = (staffs[i].actual + bonusDay) * 
			staffs[i].salary / staffs[i].mandatory;
	}
}

void sortByIncome(struct staff* staffs, size_t n) {
	if (n > 0) {
		size_t i, j;
		for (i = 0; i < n - 1; i++)
		{
			for (j = n - 1; j > i; j--)
			{
				// thu nhập của nhân viên đứng sau mà > nhân viên đứng trước
				if (staffs[j].income > staffs[j - 1].income) {
					swap(&staffs[j], &staffs[j - 1]); // đổi chỗ
				}
			}
		}
	}
	else {
		puts("--> Danh sach rong khong the sap xep!");
	}
}

void sortByName(struct staff* staffs, size_t n) {
	if (n > 0) {
		size_t i, j;
		for (i = 0; i < n - 1; i++)
		{
			for (j = n - 1; j > i; j--)
			{
				// so sánh và đổi chỗ tên nv
				if (strcmp(staffs[j].name.first, 
					staffs[j - 1].name.first) < 0) {
					swap(&staffs[j], &staffs[j - 1]);
				}
			}
		}
	}
	else {
		puts("--> Danh sach rong khong the sap xep!");
	}
}

void listedStaffMembers(const struct staff* staffs, size_t n) {
	if (n > 0) {
		puts("==============================================="
			 " DANH SACH NHAN VIEN "
			 "===============================================");
		printf("%-15s%-10s%-15s%-10s%-20s%-10s%-10s%-15s%-15s\n", 
			"Ma NV", "Ho", "Dem", "Ten", "Chuc vu", 
			"So cong", "Bat buoc", "Luong", "Thu nhap");
		puts("---------------------------------------------------------"
			 "----------------------------------------------------------");
		size_t i;
		for (i = 0; i < n; i++) {
			showAStaff(staffs[i]);
			puts("---------------------------------------------------------"
				"----------------------------------------------------------");
		}
	}
	else {
		puts("--> Danh sach rong! <--");
	}
}

void showAStaff(struct staff s) {
	printf("%-15s%-10s%-15s%-10s%-20s%-10d%-10d%-15.2f%-15.2f\n", 
		s.id, s.name.last, s.name.mid, s.name.first,
		s.role, s.actual, s.mandatory, s.salary, s.income);
}

void swap(struct staff* a, struct staff* b) {
	struct staff x = *a;
	*a = *b;
	*b = x;
}