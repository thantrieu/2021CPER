// Cho chuỗi Fibonacci f0 = a, f1 = b, fn = fn-1 + fn-2
// nhập n và cho ra màn hình chuỗi fibonacci thứ n <= 20

#include <stdio.h>
#include <string.h>

/*
* @author Branium Academy
*/

int main() {
	char f0[20000] = {'a'};
	char f1[20000] = {'b'};
	char fn[20000];
	
	int n;
	printf("Nhap 20 > n > 0: ");
	scanf("%d", &n);
	int i;
	if (n == 0) {
		strcpy(fn, f0);
	}
	else if (n == 1) {
		strcpy(fn, f1);
	}
	for (i = 2; i <= n; i++) {
		strcpy(fn, f0);
		strcat(fn, f1);
		strcpy(f0, f1);
		strcpy(f1, fn);
	}

	printf("fn = %s\n", fn);

	return 0;
}