// Biểu diễn thông tin tài khoản ngân hàng gồm mã, tên, số dư
// ngày phát hành. Tạo mới một tài khoản và hiển thị thông
// tin tài khoản đó ra màn hình

#include <stdio.h>

/*
* @author Branium Academy
*/

// tạo cấu trúc tài khoản ngân hàng
struct bankAcc {
	int id;				// mã tài khoản
	char name[40];		// tên tài khoản
	long ballance;		// số dư
	char validDate[20]; // ngày phát hành
};

int main() {
	struct bankAcc acc1;
	// nhập thông tin tài khoản
	puts("Ma TK: ");
	scanf("%d", &acc1.id);
	puts("Ten TK: ");
	scanf("%*c%39[^\n]", acc1.name);
	puts("So du: ");
	scanf("%ld", &acc1.ballance);
	puts("Ngay phat hanh: ");
	scanf("%*c%19s", acc1.validDate);
	// hiển thị thông tin tài khoản
	printf("Thong tin tai khoan: \n");
	printf("%-10s%-20s%-15s%-12s\n", "Ma TK", "Ten TK", "So du", "Ngay PH");
	printf("%-10d%-20s%-15ld%-12s\n", acc1.id, acc1.name, acc1.ballance, acc1.validDate);
	// dấu trừ để căn lề sang trái
	return 0;
}