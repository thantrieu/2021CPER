// Viết chương trình nhập vào cả dòng một 
// chuỗi kí tự và hiển thị nó ra màn hình

#include <stdio.h>
#include <string.h> // include vào khi dùng hàm strlen()

/*
* @author Branium Academy
*/

int main() {
	char str[100]; // biến lưu 1 chuỗi kí tự tối đa 99 kí tự
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao 1 chuoi ki tu: ");
	// cách 1: dùng scanf
	// scanf("%99[^\n]", str); // đọc vào cả dòng tối đa 99 kí tự

	// cách 2: dùng gets
	// gets(str);

	// cách 3: dùng fgets
	fgets(str, 99, stdin); // stdin: nhập vào từ bàn phím
	// khi đọc vào cả dòng với fgets thì nó sẽ đọc cả kí tự xuống dòng
	// cách khử là gán kí tự cuối bằng '\0'
	// nhớ include <string.h> để sử dụng hàm strlen()
	str[strlen(str) - 1] = '\0'; // khử kí tự '\n'

	// hiện kết quả
	printf("Ban vua nhap chuoi ki tu \"%s\"\n", str);

	return 0;
}