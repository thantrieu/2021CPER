// Thông tin họ tên gồm họ, đệm tên. Thông tin nhân viên gồm
// mã, họ tên, vị trí, số công thực tế, số công chuẩn và lương. 
// Viết chương trình nhập vào thông tin một nhân viên và hiển 
// thị học sinh đó ra màn hình trên 1 dòng dạng hàng cột

#include <stdio.h>

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
};

int main() {
	struct staff huy;
	// nhập thông tin nhân viên
	puts("Ma NV: ");
	scanf("%s", huy.id);
	// nhập họ và tên
	puts("Ho: ");
	scanf("%s", huy.name.last);
	puts("Dem: ");
	scanf("%*c%19[^\n]", huy.name.mid);
	puts("Ten: ");
	scanf("%s", huy.name.first);
	// nhập các thông tin còn lại
	puts("Chuc vu: ");
	scanf("%*c%39[^\n]", huy.role);
	puts("So ngay lam viec thuc te: ");
	scanf("%d", &huy.actual);
	puts("So ngay lam viec bat buoc: ");
	scanf("%d", &huy.mandatory);
	puts("Luong thang: ");
	scanf("%f", &huy.salary);

	// hiển thị thông tin nhân viên
	printf("Thong tin nhan vien: \n");
	printf("%-15s%-10s%-15s%-10s%-20s%-10s%-10s%-15s\n", "Ma NV", "Ho", "Dem",
		"Ten", "Chuc vu", "So cong", "Bat buoc", "Luong");
	printf("%-15s%-10s%-15s%-10s%-20s%-10d%-10d%-15.2f\n", huy.id, huy.name.last,
		huy.name.mid, huy.name.first, huy.role, huy.actual, huy.mandatory, huy.salary);
	// dấu trừ để căn lề sang trái
	return 0;
}