// Thông tin họ tên gồm họ, đệm tên. Thông tin học sinh gồm
// mã, họ tên, địa chỉ, số đt, điểm trung bình. Viết chương trình
// nhập mới một học sinh và hiển thị học sinh đó ra màn hình
// trên 1 dòng dạng hàng cột

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

// tạo cấu trúc học sinh
struct student {
	int id;					// mã học sinh
	struct fullName name;	// họ tên
	char address[40];		// địa chỉ
	char phoneNumber[20];	// số đt
	float avgGrade;		// điểm TB
};

int main() {
	struct student nam;
	// nhập thông tin học sinh
	puts("Ma HS: ");
	scanf("%d", &nam.id);
	// nhập họ và tên
	puts("Ho: ");
	scanf("%s", nam.name.last);
	puts("Dem: ");
	scanf("%*c%19[^\n]", nam.name.mid);
	puts("Ten: ");
	scanf("%s", nam.name.first);
	// nhập các thông tin còn lại
	puts("Dia chi: ");
	scanf("%*c%39[^\n]", nam.address);
	puts("So dien thoai: ");
	scanf("%*c%19[^\n]", nam.phoneNumber);
	puts("Diem TB: ");
	scanf("%f", &nam.avgGrade);

	// hiển thị thông tin tài khoản
	printf("Thong tin hoc sinh: \n");
	printf("%-10s%-10s%-20s%-10s%-30s%-15s%-10s\n", "Ma HS", "Ho", "Dem", 
		"Ten", "Dia chi", "So DT", "Diem TB");
	printf("%-10d%-10s%-20s%-10s%-30s%-15s%-8.2f\n", nam.id, nam.name.last, 
		nam.name.mid, nam.name.first, nam.address, nam.phoneNumber, nam.avgGrade);
	// dấu trừ để căn lề sang trái
	return 0;
}