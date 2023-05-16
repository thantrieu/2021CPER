#define _CRT_SECURE_NO_WARNINGS
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

// hàm nguyên mẫu
// hàm thêm mới một tk
void createAccount(struct bankAcc* accounts);
// hàm cập nhật số dư theo mã tk
void updateBallance(struct bankAcc* acc, long newBallance);
// hàm hiển thị danh sách tk
void listedBankAcc(const struct bankAcc* accounts, int n);
// hàm xóa tài khoản theo mã
void removeAccount(struct bankAcc* accounts, int * n, int id);
// hàm tìm một tk theo mã
int findAccById(const struct bankAcc* accounts, int n, int id);
// hàm sắp xếp danh sách tài khoản ngân hàng theo số dư
void sortAccByBallance(struct bankAcc* accounts, int n);
// hàm hiển thị 01 bản ghi
void showAnAcc(struct bankAcc acc);

int main() {
	int choice;
	struct bankAcc accounts[100]; // giả sử có tối đa 100 tk
	int n = 0; // số tk thực tế
	do {
		puts("============ QUAN LY TAI KHOAN ============");
		puts("1. Them moi 1 TK vao danh sach");
		puts("2. Cap nhat so du TK theo ma");
		puts("3. Hien thi danh sach TK ra man hinh");
		puts("4. Xoa mot TK theo ma");
		puts("5. Tim mot TK theo ma");
		puts("6. Sap xep danh sach TK theo so du giam dan");
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
			struct bankAcc b;
			createAccount(&b);
			accounts[n++] = b;
			system("cls"); // xóa màn hình cũ
			break;
		}
		case 2:
		{
			long ballance;
			int id; // mã tài khoản
			puts("Nhap ma TK can tim");
			scanf("%d", &id);
			int index = findAccById(accounts, n, id);
			if (index > -1) {
				puts("Nhap vao so du moi: ");
				scanf("%ld", &ballance);
				updateBallance(&accounts[index], ballance);
				puts("\nThong tin TK sau khi cap nhat: ");
				printf("%-10s%-20s%-15s%-12s\n",
					"Ma TK", "Ten TK", "So du", "Ngay PH");
				showAnAcc(accounts[index]);
			}
			else {
				puts("-->TK ban tim khong ton tai! <--");
			}
			break;
		}
		case 3:
		{
			system("cls");
			listedBankAcc(accounts, n);
			break;
		}
		case 4:
		{
			int id;
			puts("Nhap ma TK can xoa");
			scanf("%d", &id);
			int oldN = n;
			removeAccount(accounts, &n, id);
			if (n == oldN) {
				puts("--> Ma TK khong ton tai. Xoa that bai <--");
			}
			break;
		}
		case 5:
		{
			int id;
			puts("Nhap ma TK can tim");
			scanf("%d", &id);
			int index = findAccById(accounts, n, id);
			if (index > -1) {
				puts("\nThong tin TK");
				printf("%-10s%-20s%-15s%-12s\n",
					"Ma TK", "Ten TK", "So du", "Ngay PH");
				showAnAcc(accounts[index]);
			}
			else {
				puts("--> TK nay khong ton tai! <--");
			}
			break;
		}
		case 6:
		{
			system("cls");
			sortAccByBallance(accounts, n);
			if (n > 0) { // nếu ds không rỗng thì hiển thị ds sau sắp xếp
				listedBankAcc(accounts, n);
			}
			break;
		}
		default:
			system("cls"); // xóa màn hình cũ
			puts("--> Vui long chon cac chuc nang tu 0 - 6 <--");
			break;
		}
		puts(""); // in xuong dong
		//system("cls"); // xóa màn hình cũ
	} while (choice != 0);
	return 0;
}

void createAccount(struct bankAcc* acc) {
	puts("Ma TK: ");
	scanf("%d", &acc->id);
	puts("Ten TK: ");
	scanf("%*c%39[^\n]", acc->name);
	puts("So du: ");
	scanf("%ld", &acc->ballance);
	puts("Ngay phat hanh: ");
	scanf("%*c%19s", acc->validDate);
}

void updateBallance(struct bankAcc* acc, long newBallance) {
	acc->ballance = newBallance; // done
}

void listedBankAcc(const struct bankAcc* accounts, int n) {
	if (n > 0) {
		puts("=================="
			" DANH SACH TAI KHOAN "
			"==================");
		printf("%-10s%-20s%-15s%-12s\n",
			"Ma TK", "Ten TK", "So du", "Ngay PH");
		int i;
		for (i = 0; i < n; i++) {
			puts("----------------------------"
				"-----------------------------");
			showAnAcc(accounts[i]);
		}
	}
	else {
		puts("--> Danh sach rong!");
	}
}

// hàm hiển thị thông tin của từng tài khoản
void showAnAcc(struct bankAcc acc) {
	printf("%-10d%-20s%-15ld%-12s\n",
		acc.id, acc.name, acc.ballance, acc.validDate);
}

void removeAccount(struct bankAcc* accounts, int * n, int id) {
	int i, j;
	for (i = 0; i < *n; i++) {
		// nếu tìm thấy tài khoản với mã cần tìm
		if (accounts[i].id == id) {
			for (j = i; j < *n - 1; j++) {
				accounts[j] = accounts[j + 1];
			}
			(*n)--;
			puts("\n--> Xoa tai khoan thanh cong! <--");
			break;
		}
	}

}

int findAccById(const struct bankAcc* accounts, int n, int id) {
	int i;
	for (i = 0; i < n; i++) {
		// nếu tìm thấy tài khoản với mã cần tìm
		if (accounts[i].id == id) {
			return i; // trả về vị trí của học sinh đó trong mảng
		}
	}
	return -1; // nếu k thấy thì return -1
}

void sortAccByBallance(struct bankAcc* accounts, int n) {
	// hàm nguyên mẫu
	if (n > 0) {
		void swap(struct bankAcc* a, struct bankAcc* b);
		int i, j;
		for (i = 0; i < n - 1; i++) {
			for (j = n - 1; j > i; j--) {
				if (accounts[j].ballance > accounts[j - 1].ballance) {
					swap(&accounts[j], &accounts[j - 1]);
				}
			}
		}
	}
	else {
		puts("--> Danh sach rong khong the sap xep! <--");
	}
}

// hàm đổi chỗ hai TK
void swap(struct bankAcc* a, struct bankAcc* b) {
	struct bankAcc x = *a;
	*a = *b;
	*b = x;
}
