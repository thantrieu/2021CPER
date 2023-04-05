// Viết chương trình nhập vào tuổi sau đó
// nhập vào cả dòng họ tên. Khử trôi lệnh
// trong trường hợp này

#include <stdio.h>
#include <string.h> // include vào khi dùng hàm strlen()

/*
* @author Branium Academy
*/

int main() {
	char fullName[40];
	int age;
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Ban bao nhieu tuoi? ");
	scanf("%d", &age);
	// để khử trôi lệnh ta dùng %*c
	scanf("%*c"); // đọc bỏ kí tự thừa sau khi đọc tuổi
	printf("Ho ten cua ban? ");
	// cách 1: dùng scanf
	scanf("%39[^\n]", fullName); // đọc vào cả dòng tối đa 39 kí tự

	// hiện kết quả
	printf("Xin chao ban \"%s\", tuoi cua ban la %d\n", fullName, age);

	return 0;
}