// Viết chương trình sử dụng con trỏ hàm thực hiện các chức năng sau:
// nhập vào các phần tử mảng
// hiển thị mảng dùng toàn bộ thao tác con trỏ
// hiển thị mảng sử dụng tên mảng và chỉ số mảng bình thường

#include <stdio.h>

/*
* @author Branium Academy
*/

// hàm cộng
int add(int, int);
// hàm trừ
int sub(int, int);
// hàm nhân
int mul(int, int);
// hàm lấy dư
int mod(int, int);

int main() {
	int a, b;
	puts("Nhap hai so nguyen a, b: ");
	scanf("%d%d", &a, &b);
	// khởi tạo mảng con trỏ hàm gồm 4 hàm
	int (*action[])(int, int) = {add, sub, mul, mod};
	int choice;
	do {
		printf("Chon hanh dong:\n0. Thoat.\n1. Cong."
			"\n2. Tru.\n3. Nhan.\n4. Lay du.\nBan chon? ");
		scanf("%d", &choice);
		switch (choice)
		{
		case 0:
			puts("Xin chao va hen gap lai");
			break;
		case 1: // cộng
			printf("%d + %d = %d\n", a, b, action[0](a, b));
			break;
		case 2: // trừ
			printf("%d - %d = %d\n", a, b, action[1](a, b));
			break;
		case 3:
			printf("%d * %d = %d\n", a, b, action[2](a, b));
			break;
		case 4:
			printf("%d %% %d = %d\n", a, b, action[3](a, b));
			break;
		default:
			puts("Nhap dung tuy chon 0 - 4.");
			break;
		}
		puts("========================================");
	} while (choice != 0);

	return 0;
}

int add(int a, int b) {
	return  a + b;
}

int sub(int a, int b) {
	return a - b;
}

int mul(int a, int b) {
	return a * b;
}

int mod(int a, int b) {
	return a % b;
}