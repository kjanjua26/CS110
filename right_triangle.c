#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){

	int num1, num2, num3;

	printf("Enter the integers in ascending order!!\n");

	do {
		printf("\nEnter side 1: ");
		scanf("%d", &num1);

		do {
			printf("Enter side 2: ");
			scanf("%d", &num2);
			if (num2 > num1)
				break;
			printf("%d is smaller than %d.\n", num2, num1);
		} while (num2 < num1);

		do {
			printf("Enter side 3: ");
			scanf("%d", &num3);
			if (num3 > num2)
				break;
			printf("%d is smaller than %d.\n", num3, num2);
		} while (num3 < num2);

		if (num1 + num2 > num3)
			printf("\nYES! These sides make a triangle. Great!\n");
		else
			printf("\nNO! These sides DO NOT make a triangle.\n");

	} while (num1 + num2 <= num3);

	return EXIT_SUCCESS;
}

