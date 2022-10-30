/**
 * @file Exercises16.c
 * @author Branium Academy
 * @brief 
 * @version 2.0
 * @date 2022-10-30
 * @see https://braniumacademy.net
 * 
 * @copyright Copyright (c) Branium Academy 2022
 * 
 */

#include <stdio.h>

int main() {
	int t;
	puts("Nhap so bo test: ");
	scanf("%d", &t);

	int test = 1; // số thứ tự bộ test
	do {
		int n;
        puts("Nhap n: ");
        scanf("%d", &n); // nhập vào số n
        int isPositive = 1; // giả định n là số dương
        if(n < 0) {
            isPositive = 0; // n là số âm
            n = -n; // lấy trị tuyệt đối của n
        } 
        // kiểm tra xem n có kết thúc bằng số 0 hay không.
        // nếu các chữ số của n kết thúc bởi số 0 ta phải mượn một giá trị khác 0
        // khi đảo ngược thứ tự các chữ số của n thì mới thành công.
        // nếu không mượn thì sẽ khó thực hiện trong phạm vi kiến thức đã học
        int endWithZero = 0; // giả định n không kết thúc bằng số 0
        if(n % 10 == 0) {
            endWithZero = 1; // n kết thúc bằng số 0
        }
        // tiếp theo ta đảo ngược thứ tự chữ số cấu thành nên n
        int reverseN = endWithZero ? 1: 0; // nếu n kết thúc bởi 0 ta mượn 1, nếu không thì k.tạo n đảo bằng 0
        while(n > 0) {
            reverseN = 10 * reverseN + n % 10;
            n /= 10; // giảm n đi 10 lần để loại bỏ phần đơn vị đã lấy
        }
        // ví dụ biến 10 => 101. Ở đây mượn 1, là số đầu tiên trong 101. hai chữ số tiếp theo chính là n đảo.
        printf("Test %d: ", test);
        // in ra kết quả:
        if(!isPositive) { // nếu n âm thì in dấu trừ trước kết quả
            printf("-");
        }
        int stopCondition = endWithZero ? 9 : 0; // nếu n kết  thúc bằng 0 thì phải dừng việc tách khi n đảo < 10
        // ví dụ n = 10, reverseN = 101, khi in ra phải dừng khi reverseN = 1 để loại bỏ chữ số đã đi mượn
        while(reverseN > stopCondition) {
            printf("%d ", reverseN % 10);
            reverseN /= 10;
        }
        printf("\n");
        test++;
	} while (test <= t);
}