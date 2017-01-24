
//Coded by: Kamran Janjua
//Instructions: This is a program of blackjack game.
//The game is played between a player and a dealer.
//They both play their turns and then finally someone becomes the winner.
//The game is simple and follows the basic blackjack logic.


//declaring the libraries and their extensions of their header files.
#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

//declaring global variables to be of scope throughout the program.
int add, sum, dadd;
int min = 2, max = 11;
//calling the first function.
int main()
{
    //declaring variables of type int and char.
    int card_1, card_2;
    int dcard_1, dcard_2, hidden;
    char choice[30];
    char dchoice[30];
    int hcard;
    //the random number refresher.
    srand(time(NULL));
    //planning the card strategy
    //generating two random numbers for the player.
    card_1 = (rand() % (max + 1 - min)) + min;
    card_2 = (rand() % (max + 1 - min)) + min;
    //summing the two random numbers, cards.
    sum = card_1 + card_2;
    printf("Welcome to a simple Blackjack Game!\n");
    printf("\nThe cards you drew are: %d, %d. \nYour total is %d + %d = %d\n", card_1, card_2, card_1, card_2, sum);
    //declaring a condition. If the player busts, the dealer wins.
    if (sum > 21){
        printf("\nDealer Wins!");
    }
    else {
    //let the dealer game begin
    //if the player does not bust, the two cards are drawn for the dealer.
    dcard_1 = (rand() % (max + 1 - min)) + min;
    dcard_2 = (rand() % (max + 1 - min)) + min;
    hidden = dcard_1;
    printf("The dealer has a %d showing, and a hidden card", dcard_2);
    printf("\nHis sum is hidden too.");
    //the deciding factor
    repeat:
    //asking player for the choices. Either hit or stay.
    printf("\nWould you like to \"hit\" or \"stay\"?\n");
    scanf("%s", choice);
    //if the choice is hit, new card is drawn.
     if (strcmp(choice, "hit")== 0){
        hcard = (rand() % (max + 1 - min)) + min;
        printf("\nWay to go!");
        printf("\nYou drew a: %d", hcard);
        sum = sum + hcard;
        printf("\nYour total is now: %d", sum);

        //checks if the dealer wins or not. If the player busts, the dealer wins.
        if (sum > 21){
            printf("\nDealer Wins. Player Busted.");
            goto start;
        }
else {
    goto repeat;
}
        }
        if (strcmp(choice, "stay")==0){
           printf("\nOkay! This is dealer's turn now!");
            printf("\nHis hidden card was: %d", hidden);
                add = hidden + dcard_2;
                printf("\nHis total is now: %d", add);
        addition:
        if (add <= 16){
            printf("\nDealer chooses to hit!");
            dadd = (rand() % (max + 1 - min)) + min;
            printf("\nHe draws a: %d", dadd);
            add = add + dadd;
            printf("\nHis total is now: %d", add);
            if (add > 21){
                printf("\nPlayer Wins. Dealer Busted!");
                goto start;
                            }
                            else {
                                goto addition;
                            }
        }
        if (add > 16){
            printf("\nDealer Stays!");
            printf("\nDealer's total: %d", add);
            printf("\nPlayers's total: %d", sum);

            if (add > sum){
                printf("\nDealer Wins!");
            }
            if (sum > add){
                printf("\nPlayer Wins!");
            }
            if (add == sum){
                printf("\nIt is a tie!!");
            }
        }

        }
    }
start:
    return 0;
}
