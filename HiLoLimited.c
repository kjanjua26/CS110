#include <stdio.h>
#include <time.h>
#include <string.h>

int main()
{

    int num;
    int choice;
    int count = 2;
    int tries = 2;

    srand(time(NULL));
    num = rand() % 100 + 1;
    printf("I am thinking of a number between 1-100. You have 7 guesses.\n");
    printf("\nYou have only 7 tries\n");
    printf("\nFirst Guess: \n");
    scanf("%d", &choice);

    while (choice != num && tries <= 7){
        if (choice > num){
            printf("Sorry! You are too high!\n");

        }
        if (choice < num){
            printf("Sorry! You are too low!\n");
        }
        printf("Guess # %d: \n", count);
        scanf("%d", &choice);
        count++;
        tries++;
    }

    if (choice == num) 
        printf("You have guessed it right!");

    else if (tries > 7)
        printf("You have run out of tires!");


    return 0;

}
