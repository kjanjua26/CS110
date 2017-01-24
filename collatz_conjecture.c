#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(){
	int number, count = 0, max;

	printf("Enter your number here:");
	scanf("%d", &number);
	max = number;
	printf("%d\t", number);
	while (number != 1){
		if (number % 2 == 0)
			number /= 2;
		else
			number = number * 3 + 1;

		printf("%d\t", number);

		if (number > max)
			max = number;
		count++;
	}

	printf("\nThe cycle length is %d and %d is maximum number.\n", count, max);
}

