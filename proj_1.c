#include<stdio.h>
#include<time.h>
int main()
{

    void PrintDeck(int, int []);
    void* NumSwap(int, int, int[]);
    void* JockA(int, int[]);
    void* JockB(int, int[]);
    void ArrSwap(int *a, int *b);
    int i;
    int deck[28] = {1,23,26,10,13,16,19,22,25,28,3,6,9,12,15,18,21,24,27,2,5,8,11,14,17,20,4,7};

    printf("The original deck is: \n");

    PrintDeck(i, deck);
    for (i = 0; i< 28; i++) //Joker A moves.
    {
        if(deck[i] == 27)
        {
            printf("\n\n");
            printf("\nMoving Joker A to 1 place Down.\n");
            NumSwap(i, i+1, deck);
            PrintDeck(i, deck);
            printf("\n\n");
            break;
        }
        else if(deck[28] == 27) //If Joker A is last.
        {
            printf("\n\n");
            NumSwap(i, 0, deck);
            PrintDeck(i, deck);
            printf("\n\n");
            break;
        }
    }
    for (i = 0; i<28; i++) //Joker B movies.
    {
         if (deck[i] == 28)
        {
            printf("\n\n");
            printf("\nMoving Joker B to 2 places Down.\n");
            NumSwap(i, i+2, deck);
            NumSwap(9, 10, deck); //To bring 28 between 6 and 9.
            PrintDeck(i, deck);
            printf("\n\n");
            break;
        }
    }
    printf("\n\n");
    printf(">>>>>>>>>>Triple Cut<<<<<<<<<<\n");
    printf("\nThe numbers below Joker A are: \n");
    JockA(i, deck);
    printf("\n\n");
    printf("The numbers above Joker B are: \n");
    JockB(i, deck);
    printf("\n\n");

    return 0;
}

void PrintDeck(int i, int deck[])
{
    for (i = 0; i< 28; i++)
    {
        printf("%d, ", deck[i]);
    }
}
void* NumSwap(int i, int j, int deck[]) //Number swapping Algorithm.
{
    deck[i] = deck[i] + deck[j];
    deck[j] = deck[i] - deck[j];
    deck[i] = deck[i] - deck[j];
}

void* JockA(int i, int deck[])
{
   for (i = 0; i< 28; i++)
   {
       int jok_B;
       if (deck[i] == 28) {jok_B = deck[i];}
       if (deck[i] == 27 && jok_B > deck[i])
       {
           for (i = i+1; i < 28; ++i)
           {
               printf("%d, ", deck[i]);
           }
       }
   }
}
void* JockB(int i, int deck[])
{
    for (i = 0; i<= 28; i++)
   {
       int jok_A;
       if (deck[i] == 27) {jok_A = deck[i];}
       if (deck[i] == 28 && jok_A > deck[i])
       {
           for(i = deck[0]; i <= deck[i+6]; i++)
           {
               printf("%d, ", deck[i-1]);
           }
           break;
       }
       }
}




