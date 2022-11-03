/*
 * @author Branium Academy
 * @version 2021.10
 * @see https://braniumacademy.net
*/
#include <stdio.h>

int main() {
    int n;
    puts("Nhap thang cua nam: ");
    scanf("%d", &n);
    switch (n) {
        case 1:
            puts("January");
            break;
        case 2:
            puts("February");
            break;
        case 3:
            puts("March");
            break;
        case 4:
            puts("April");
            break;
        case 5:
            puts("May");
            break;
        case 6:
            puts("June");
            break;
        case 7:
            puts("July");
            break;
        case 8:
            puts("August");
            break;
        case 9:
            puts("September");
            break;
        case 10:
            puts("October");
            break;
        case 11:
            puts("November");
            break;
        case 12:
            puts("December");
            break;
        default:
            puts("INVALID");
            break;
    }
}
