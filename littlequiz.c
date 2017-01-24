#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int main()

{
	char ch = 0;
	char choice[30];
	int cho;
	int count = 0;

	printf("Are you ready for a quiz (Y/N)\n");
	scanf("%c", &ch);
	if (ch == 'Y' || ch == 'y'){
		printf("Okay, here it comes!\n");

		printf("Q1. What is the capital of Pakistan?\n");
		printf("1. Lahore\n");
		printf("2. Karachi\n");
		printf("3. Islamabad\n");

		scanf("%d", &cho);
		if (cho == 3){
			printf("That's Right!\n");
			count++;
		}
		else if (cho == 1 || cho == 2){
			printf("Poor Thing! You don't know about the capital of Pakistan!!!\n");
		}

		printf("Q2. Can you store the value 3.147 in a variable of type int?\n");
		printf("1. Yes\n");
		printf("2. No\n");

		scanf("%d", &cho);
		if (cho == 1){
			printf("Sorry , 3.147 is a floating -point. type int can only store numbers.\n");
		}
		else if (cho == 2){
			printf("That is correct!\n");
			count++;
		}
		printf("Q3. What is the result of 2+6/3\n");
		printf("1. 11\n");
		printf("2. 4\n");
		printf("3. 8/3\n");

		scanf("%d", &cho);
		if (cho == 2){
			printf("That is correct!\n");
			count++;
		}
		else if (cho == 1 || cho == 3){
			printf("Sorry, try try again!!\n");
		}



		printf("Overall, you got %d out of 3 correct\n", count);
		printf("Thanks for playing\n");
	}

	if (ch == 'N' || ch == 'n'){
		printf("Good Bye!!!\n");
	}
	return 0;

}