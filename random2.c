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
        goto repeat;
        }

    //sips coffee
    else if (strcmp(choice, "stay")== 0){
            printf("\nOkay! This is dealer's turn now!");
            printf("\nHis hidden card was: %d", hidden);
            add = hidden + dcard_2;
            printf("\nHis total is now: %d", add);

            }
    //plot twist
    if ( add <= 16){
        printf("\nDealer Hits!");
        dadd = (rand() % (max + 1 - min)) + min;
        printf("\nHe draws a: %d", dadd);
        add = add + dadd;
        printf("\nHis total is now: %d", add);
        goto boom;
    }
    if (add > 16){
        printf("\nDealer Stays!!");
        if ( add < 21){
        printf("\nDealer's Total is: %d", add);
        printf("\nYour Total is: %d", sum);
            if (add > sum){
                printf("\nDealer Wins!!");
            }
            if (sum > add){
                printf("\nYou Win!!");
            }
    }
    boom:
    if (add >= 21){
        printf("\nYou Win!");
    }
    }
    }
   start:
    return 0;
}
    /*
    again:
    printf("\nWould you(dealer) like to \"hit\" or \"stay\"?\n");
    scanf("%s", dchoice);
    if (strcmp(dchoice, "hit")== 0){
        dadd = (rand() % (max + 1 - min)) + min;
        printf("He draws a: %d", dadd);
        add = add + dadd;
        printf("\nHis total is now: %d", add);
        if (add > 21){
            printf("\nPlayer Wins!");
            goto start;
        }

        goto again;
        goto boom;

    //the black dealer play
    printf("\nWould you(dealer) like to \"hit\" or \"stay\"?\n");
    scanf("%s", dchoice);
    boom:
    if (strcmp(dchoice, "stay")== 0){
        printf("\nDealer Stays!");
        printf("\nPlayer's total: %d", sum);
        printf("\nDealer's total: %d", add);
        if (sum > add){
            printf("\nPlayer Wins!!");
        }
        if (add > sum){
            printf("\nDealer Wins!!");
        }
        }

    }
	}
start:
    return 0;
}
*/
