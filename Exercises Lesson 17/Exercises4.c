// Viết hàm nguyên mẫu và định nghĩa hàm cho các chức năng sau:
// liệt kê các số nguyên tố trong đoạn [a, b]
// liệt kê các số thuận nghịch trong đoạn [a, b]
// liệt kê n số nguyên tố đầu tiên
// liệt kê n số fibonacci đầu tiên
// liệt kê n số chính phương đầu tiên
// tìm cung hoàng đạo từ ngày tháng sinh
// đưa ra tên ngày trong tuần bằng tiếng anh tương ứng
// đưa ra tên tháng trong năm bằng tiếng anh tương ứng

#include <stdio.h>
#include <math.h>

/*
 * @author Branium Academy
*/

// các hàm nguyên mẫu: khai báo trong file .h
// hàm kiểm tra số thuận nghịch
int isReversible(int a);

// hàm kiểm tra n có phải số nguyên tố hay không
int isPrime(int n);

// hàm kiểm tra n có phải số chính phương
int isSquareRootNumber(int n);

// hàm liệt kê các số nguyên tố
void listedPrimeNumbers(int a, int b);

// hàm liệt kê các số thuận nghịch trong đoạn [a, b]
void listedReversibleNumbers(int a, int b);

// hàm liệt kê n số nguyên tố đầu tiên
void listedNPrime(int n);

// hàm liệt kê n số fibo đầu tiên
void listedNFibonacciNumbers(int n);

// hàm liệt kê n số chính phương
void listedSquareRootNumbers(int n);

// hàm tìm cung hoàng đạo từ ngày tháng sinh
void zodiac(int day, int month);

// hàm đưa ra tên ngày trong tuần bằng tiếng Anh
void dayOfWeek(int day);

// hàm đưa ra tên tháng trong năm bằng tiếng anh:
void monthName(int month);

// nơi gọi hàm
int main() {
	int a, b;
	int n;
	puts("Nhap hai so nguyen a < b: ");
	scanf("%d%d", &a, &b);

	listedPrimeNumbers(a, b);
	listedReversibleNumbers(a, b);

	puts("\nNhap n > 0: ");
	scanf("%d", &n);

	listedNPrime(n);
	listedNFibonacciNumbers(n);
	listedSquareRootNumbers(n);

	int day, month;
	puts("\nNhap ngay sinh, thang sinh: ");
	scanf("%d%d", &day, &month);

	zodiac(day, month);

	puts("\nNhap ngay cua tuan(1-7): ");
	scanf("%d", &day);
	dayOfWeek(day);

	puts("\nNhap thang trong nam(1-12): ");
	scanf("%d", &month);
	monthName(month);

	return 0;
}

// định nghĩa hàm
int isReversible(int n) {
	int m = n;
	int r = 0;
	while (m > 0) {
		r = r * 10 + m % 10;
		m /= 10;
	}
	return r == n; // nếu r == n thì return true và ngược lại
}

int isPrime(int n) {
	if (n < 2) {
		return 0;
	}
	int i;
	int bound = sqrt(n);
	for (i = 2; i <= bound; i++) {
		if (n % i == 0) {
			return 0;
		}
	}
	return 1;
}

int isSquareRootNumber(int n) {
	if (n < 0) {
		return 0;
	}
	int sq = sqrt(n);
	return sq * sq == n;
}

void listedPrimeNumbers(int a, int b) {
	printf("\nCac so nguyen to trong [%d, %d]: ", a, b);
	int i;
	for (i = a; i <= b; i++) {
		if (isPrime(i)) {
			printf("%d ", i);
		}
	}
}

void listedNPrime(int n) {
	printf("\n%d so nguyen to dau tien: ", n);
	int i = 2;
	int count;
	for (count = 0; count < n; count++) {
		if (isPrime(i)) {
			printf("%d ", i);
		}
		i++;
	}
}

void listedReversibleNumbers(int a, int b) {
	printf("\nCac so thuan nghich trong [%d, %d]: ", a, b);
	int i;
	for (i = a; i <= b; i++) {
		if (isReversible(i)) {
			printf("%d ", i);
		}
	}
}

void listedNFibonacciNumbers(int n) {
	printf("\n%d so Fibonacci dau tien: ", n);
	int i = 0;
	unsigned long long f0 = 0, f1 = 1, fn;
	for (; i < n; i++) {
		if (i < 2) {
			fn = i;
		}
		else {
			fn = f0 + f1;
			f0 = f1;
			f1 = fn;
		}
		printf("%llu ", fn);
	}
}

void listedSquareRootNumbers(int n) {
	printf("\n%d so chinh phuong dau tien: ", n);
	int i = 0;
	int count = 0;
	for (i = 0; i < n; i++) {
		printf("%d ", i * i); // in ra
	}
}

void monthName(int month) {
	switch (month)
	{
	case 1: // tháng 1
		printf("January");
		break;
	case 2: // tháng 2
		printf("February");
		break;
	case 3: // tháng 3
		printf("March");
		break;
	case 4: // tháng 4
		printf("April");
		break;
	case 5: // tháng 5
		printf("May");
		break;
	case 6: // tháng 6
		printf("June");
		break;
	case 7: // tháng 7
		printf("July");
		break;
	case 8: // tháng 8
		printf("August");
		break;
	case 9: // tháng 9
		printf("September");
		break;
	case 10: // tháng 10
		printf("October");
		break;
	case 11: // tháng 11
		printf("November");
		break;
	case 12: // tháng 12
		printf("December");
		break;
	default:
		puts("Thang khong hop le. Vui long kiem tra lai");
		break;
	}
}

void dayOfWeek(int day) {
	switch (day)
	{
	case 0:
		puts("Xin chao va hen gap lai");
		break;
	case 1: // thứ hai
		printf("Monday");
		break;
	case 2: // thứ ba
		printf("Tuesday");
		break;
	case 3: // thứ tư
		printf("Wednesday");
		break;
	case 4: // thứ năm
		printf("Thursday");
		break;
	case 5: // thứ sáu
		printf("Friday");
		break;
	case 6: // thứ bảy
		printf("Saturday");
		break;
	case 7: // chủ nhật
		printf("Sunday");
		break;
	default:
		puts("Gia tri khong hop le. Vui long kiem tra lai");
		break;
	}
}

void zodiac(int day, int month) {
	switch (month)
	{
	case 1:
		if (day < 20) { // 1 - 19/1
			puts("Ma Ket");
		}
		else if (day <= 31) { // 20 - 31/1
			puts("Bao Binh");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 2:
		if (day < 19) { // 1 - 18/2
			puts("Bao Binh");
		}
		else if (day <= 29) { // 19 - 29/2
			puts("Song Ngu");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 3:
		if (day < 21) { // 1 - 20/3
			puts("Song Ngu");
		}
		else if (day <= 31) { // 21 - 31/3
			puts("Bach Duong");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 4:
		if (day < 21) { // 1 - 20/4
			puts("Bach Duong");
		}
		else if (day <= 30) { // 21 - 30/4
			puts("Kim Nguu");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 5:
		if (day < 21) { // 1 - 20/5
			puts("Kim Nguu");
		}
		else if (day <= 31) { // 21 - 31/5
			puts("Song Tu");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 6:
		if (day < 22) { // 1 - 21/6
			puts("Song Tu");
		}
		else if (day <= 30) { // 22 - 30/6
			puts("Cu Giai");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 7:
		if (day < 23) { // 1 - 22/7
			puts("Cu Giai");
		}
		else if (day <= 31) { // 23 - 31/7
			puts("Su Tu");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 8:
		if (day < 23) { // 1 - 22/8
			puts("Su Tu");
		}
		else if (day <= 31) { // 23 - 31/8
			puts("Xu Nu");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 9:
		if (day < 23) { // 1 - 22/9
			puts("Xu Nu");
		}
		else if (day <= 30) { // 23 - 30/9
			puts("Thien Binh");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 10:
		if (day < 24) { // 1 - 23/10
			puts("Thien Binh");
		}
		else if (day <= 31) { // 24 - 31/10
			puts("Bo Cap");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 11:
		if (day < 23) { // 1 - 22/11
			puts("Bo Cap");
		}
		else if (day <= 30) { // 23 - 30/11
			puts("Nhan Ma");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	case 12:
		if (day < 22) { // 1 - 21/12
			puts("Nhan Ma");
		}
		else if (day <= 31) { // 22 - 31/12
			puts("Ma Ket");
		}
		else {
			puts("Ngay khong hop le");
		}
		break;
	default:
		puts("Thang khong hop le. Vui long kiem tra lai.");
		break;
	}
}