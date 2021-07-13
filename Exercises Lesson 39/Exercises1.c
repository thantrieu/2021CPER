// Nhập vào một chuỗi kí tự và chuyển đổi nó thành giá trị số kiểu double

#include <stdio.h>
#include <stdlib.h>

/*
* @author Branium Academy
*/

int main() {
	char str[20];
	// luôn nhớ chừa ra 1 kí tự cho kí tự NULL '\0'
	printf("Nhap vao mot chuoi: ");
	scanf("%19[^\n]", str); // đọc vào cả dòng tối đa 19 kí tự
	char* remain;
	double number = strtod(str, &remain);
	// hiện kết quả
	printf("Ban vua nhap \"%s\", gia tri double sau chuyen doi: %lf\n", str, number);
	printf("Phan con lai cua chuoi sau khi chuyen doi: %s\n", remain);

	return 0;
}

// việc chuyển đổi sẽ được thực hiện thành công nếu chuỗi bắt đầu bởi số