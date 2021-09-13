// Nhập số tự nhiên n sau đó hiển thị các số chẵn
// trong đoạn [0, n]
#include <stdio.h>
/*
 * @author Branium Academy
*/
int main() {
	int n;
	puts("Nhap n: ");
	scanf("%d", &n);
	printf("Cac so chan trong doan [0, %d]: ", n);
	int i;
	for (i = 0; i <= n; i += 2) {
		printf("%d ", i);
	}
}
