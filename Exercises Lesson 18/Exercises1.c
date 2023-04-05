// Viết hàm tráo đổi hai giá trị nguyên a, b. Hàm trả về void

#include <stdio.h>

/*
 * @author Branium Academy
 */

 // hàm tráo đổi giá trị a, b
void swap(int* a, int* b) {
	int tmp = *a;
	*a = *b;
	*b = tmp;
}

int main() {
	// test
	int a, b;
	puts("Nhap hai so nguyen a, b: ");
	scanf("%d%d", &a, &b);

	printf("Truoc khi trao doi, a = %d, b = %d\n", a, b);

	swap(&a, &b); // gọi hàm truyền tham chiếu
	printf("Sau khi trao doi, a = %d, b = %d\n", a, b);

	return 0;
}
