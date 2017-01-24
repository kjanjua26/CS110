#include "stdio.h"
#include "string.h"
#include "time.h"
int add, sum, dadd, total;
int min = 2, max = 11;
int main()
{
    int card_1, card_2;
    int dcard_1, dcard_2, hidden;
    char choice[30];
    char dchoice[30];
    int hcard;
    srand(time(NULL));

    printf("\nWelcome to Simple Black Jack Program!!");
    card_1 = (rand() % (max + 1 - min)) + min;
	card_2 = (rand() % (max + 1 - min)) + min;
	sum = card_1 + card_2;
	printf("\nThe cards you drew are: %d, %d. \nYour total is %d + %d = %d\n", card_1, card_2, card_1, card_2, sum);
	if (sum >= 21){
        printf("Dealer Wins!");
	}
	else {
    //let the dealer game begin
    dcard_1 = (rand() % (max + 1 - min)) + min;
    dcard_2 = (rand() % (max + 1 - min)) + min;
    hidden = dcard_1;
    printf("The dealer has a %d showing, and a hidden card", dcard_2);
    printf("\nHis total is hidden, too");
	}
	re:
    printf("\nWould you like to \"hit\" or \"stay\"?\n");
    scanf("%s", choice);

    if (strcmp(choice, "hit")== 0){
        hcard = (rand() % (max + 1 - min)) + min;
        printf("You drew a: %d", hcard);
        sum = sum + hcard;
        printf("\nYour total is now: %d", sum);
        goto re;
    }
        else if (strcmp(choice, "stay")==0){
            printf("\nOkay, dealer's turn.");
            printf("\nHis hidden card was: %d", hidden);
            total = hidden + dcard_2;
            printf("\nHis total was: %d", total );

        }
reg:
 if (total <= 16) {
    printf("\nDealer chooses to hit.");
    dadd = (rand() % (max + 1 - min)) + min;
    printf("\nHe draws a %d.", dadd);
    total = total + dadd;
    printf("\nHis total is %d.", total);
    goto reg;

 }
 if (total > 16){
 printf("\nDealer Stays.");
 printf("\nDealer's total is %d.", total);
 printf("\nYour total is: %d.", sum);
 }
 if (total > sum){
        printf("\n\n");
    printf("\nDealer Wins.");
 }
 if ( sum > total){
     printf("\n\n");
    printf("\nYou Win.");
 }
return 0;
}


