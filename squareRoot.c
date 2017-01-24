#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int main(){

	int number;
	printf("SQUARE ROOT!!\n");
	do{
		printf("\nEnter a valid positive number: ");
		scanf("%d", &number);
		if (number > 0)
			break;
		printf("\nYou can't find square root a negative number!!\n");
	} while (number < 0);

	printf("\nSquare root of %d is %.2f.\n", number, sqrt(number));

	return 0;
}


