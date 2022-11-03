/**
 * @file Exercises16.c
 * @author Branium Academy
 * @brief 
 * @see https://braniumacademy.net
 * @version 0.1
 * @date 2022-10-28
 * 
 * @copyright Copyright (c) Branium Academy 2022
 * 
 */
#include <stdio.h>
#include <math.h>

int main() {
	int t;
	scanf("%d", &t);
	for (int i = 1; i <= t; i++)
	{
		int firstNumber;
		int secondNumber;
		scanf("%d%d", &firstNumber, &secondNumber);
		if (firstNumber <= 1) {
			printf("Test %d: NO\n", i);
		}
		else {
			int sumFirst = 1;
			int sumSecond = 1;
			int boundFirst = (int)sqrt(firstNumber);
			int boundSecond = (int)sqrt(secondNumber);
			for (int j = 2; j <= boundFirst; j++)
			{
				if (firstNumber % j == 0) {
					sumFirst += j;
					if (j != (firstNumber / j)) {
						sumFirst += firstNumber / j;
					}
				}
			}
			for (int j = 2; j <= boundSecond; j++)
			{
				if (secondNumber % j == 0) {
					sumSecond += j;
					if (j != (secondNumber / j)) {
						sumSecond += secondNumber / j;
					}
				}
			}
			if (sumFirst == secondNumber && sumSecond == firstNumber) {
				printf("Test %d: YES\n", i);
			}
			else {
				printf("Test %d: NO\n", i);
			}
		}
	}
	return 0;
}