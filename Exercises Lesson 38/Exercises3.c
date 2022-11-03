// Nhập vào một chuỗi kí tự từ bàn phím và
// loại bỏ khoảng trắng đầu chuỗi và cuối chuỗi
// loại bỏ khoảng trắng liên tiếp trong chuỗi
// viết hoa chữ cái đầu từ

#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*
* @author Branium Academy
*/

void trimHead(char* str); // loại bỏ khoảng trắng ở đầu chuỗi
void trimTail(char* str); // loại bỏ khoảng trắng ở cuối chuỗi
void toSentenceCase(char* str); // viết hoa chữ cái đầu từ
void toLowerCase(char* str); // viết thường toàn bộ chuỗi
void trimMiddle(char* str); // loại bỏ dấu cách ở giữa

int main() {
	char str[200];
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao mot chuoi ki tu: ");
	scanf("%[^\n]", str);
	// hiện kết quả
	printf("Chuoi ban dau: \"%s\"\n", str);

	trimTail(str);
	printf("Loai bo space o cuoi: \"%s\"\n", str);

	trimHead(str);
	printf("Loai bo space o dau: \"%s\"\n", str);

	trimMiddle(str);
	printf("Loai bo space o giua: \"%s\"\n", str);

	toLowerCase(str); // chuyen ve chu thuong hoan toan
	toSentenceCase(str);
	printf("Viet hoa chu cai dau tu: \"%s\"\n", str);

	return 0;
}

void trimMiddle(char* str) {
	int i, j;
	int n = strlen(str);
	for (i = 0; i < n - 1; i++) {
		if (isspace(str[i]) && isspace(str[i + 1])) {
			for (j = i; j < n - 1; j++) {
				str[j] = str[j + 1];
			}
			str[n - 1] = '\0';
			n--;
			i--; // quay lai xet luot tiep
		}
	}
}

void trimHead(char* str) {
	int count = 0;
	int n = strlen(str); // lay do dai chuoi
	int i = 0;
	// bước 1: đếm số khoảng trắng ở đầu:
	while (isspace(str[i])) {
		count++; // tang bien count len
		i++;
	}
	// bước 2: dịch chuyển các kí tự sang trái count đơn vị
	for (i = 0; i < n - count; i++) {
		str[i] = str[i + count];
	}
	// bước 3: cắt đuôi tại vị trí n-count
	str[n - count] = '\0';
}

void trimTail(char* str) {
	int count = 0;
	int n = strlen(str); // lay do dai chuoi
	int i = n - 1;
	// b1: đếm số khoảng trắng ở cuối
	while (isspace(str[i])) {
		count++; // tang bien count len
		i--;
	}
	// b2: đặt '\0' vào vị trí của dấu cách đầu tiên ở cuối
	str[n - count] = '\0';
}

void toLowerCase(char* str) {
	int i;
	int n = strlen(str); // lay do dai chuoi
	for (i = 0; i < n; i++) {
		str[i] = tolower(str[i]);
	}
}

void toSentenceCase(char* str) {
	int i;
	int n = strlen(str); // lay do dai chuoi
	str[0] = toupper(str[0]);
	for (i = 0; i < n; i++) {
		if (i < n - 1 && isspace(str[i]) && !isspace(str[i + 1])) {
			str[i + 1] = toupper(str[i + 1]);
		}
	}
}