#include <stdio.h>

int main()
{
    int a; // khai báo biến a
    int b; // khai báo biến b
    scanf("%d%d", &a, &b); // đọc vào hai biến a, b
    printf("%d + %d = %d\n", a, b, a + b); // %d thứ nhất ứng với biến a, %d thứ hai cho b và %d cuối cho a + b
    printf("%d - %d = %d\n", a, b, a - b);
    printf("%d * %d = %d\n", a, b, a * b);
    printf("%d / %d = %d\n", a, b, a / b);
    printf("%d %% %d = %d\n", a, b, a % b); // để in ra dấu % cần có 2 %%

    return 0;
}