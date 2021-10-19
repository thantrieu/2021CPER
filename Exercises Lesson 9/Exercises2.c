/*
 * @author Branium Academy
 * @version 2021.10
 * @see https://braniumacademy.net
*/
#include <stdio.h>

int main() {
    int n;
    puts("Nhap gia tri tu 1-7: ");
    scanf("%d", &n);
    switch (n) {
        case 1:
            puts("Monday");
            break;
        case 2:
            puts("Tuesday");
            break;
        case 3:
            puts("Wednesday");
            break;
        case 4:
            puts("Thursday");
            break;
        case 5:
            puts("Friday");
            break;
        case 6:
            puts("Saturday");
            break;
        case 7:
            puts("Sunday");
            break;
        default:
            puts("INVALID");
            break;
    }
}
