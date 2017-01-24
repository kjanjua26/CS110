#include "stdio.h"
#include "stdlib.h"
#include "time.h"
#include "string.h"

int add, sum, dadd;
int min = 2, max = 11;
int main()
{
    int card_1, card_2;
    int dcard_1, dcard_2, hidden;
    char choice[30];
    char dchoice[30];
    int hcard;
    srand(time(NULL));
    //planning the card strategy
	card_1 = (rand() % (max + 1 - min)) + min;
	card_2 = (rand() % (max + 1 - min)) + min;
	sum = card_1 + card_2;
	printf("The cards you drew are: %d, %d. \nYour total is %d + %d = %d\n", card_1, card_2, card_1, card_2, sum);
	if (sum >= 21){
        printf("Dealer Wins!");
	}
	else {
    //let the dealer game begin
    dcard_1 = (rand() % (max + 1 - min)) + min;
    dcard_2 = (rand() % (max + 1 - min)) + min;
    hidden = dcard_1;
    printf("The dealer has a %d showing, and a hidden card", dcard_2);
    printf("\nHis sum is hidden too.");
    //the deciding factor
    repeat:
    printf("\nWould you like to \"hit\" or \"stay\"?\n");
    scanf("%s", choice);
     if (strcmp(choice, "hit")== 0){
        hcard = (rand() % (max + 1 - min)) + min;
        printf("You drew a: %d", hcard);
        sum = sum + hcard;
        printf("\nYour total is now: %d", sum);


        if (sum > 21){
            printf("\nDealer Wins!");
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
        }

        }
	}
start:
    return 0;
}
