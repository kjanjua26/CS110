#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{
	int secret, a;
	secret = 7;
	int count = 0;
	printf("I have chosen a number between 1 and 10. Try to guess it.\n");
	printf("Your Guess: \n");
	scanf("%d", &a);
	while (secret != a)
	{
		printf("This is incorrect. Guess Again. \n");
		scanf("%d", &a);
		count++;
	}

	printf("That's right. You guessed it right.\n");
	printf("It took you only %d tires. Great!\n", count);
	return 0;
}
