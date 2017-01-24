#include<stdio.h>
#include<time.h>
#include<ctype.h>
int main()
{

    void PrintDeck(int, int []);
    void* NumSwap(int, int, int[]);
    void* JockA(int, int[]);
    void* JockB(int, int[]);
    void* ArrSwap(int, int [], int []);
    int keyStream(int);
    int i, n, j, num;
    int card[6];
    char msg[150];
    int arr[26];

    int deck[28] = {5,8,11,14,17,20,23,26,28,9,12,15,18,21,24,2,27,1,4,7,10,13,16,19,22,25,3,6};
    //keyStream(11);
    printf("\n\n");
    printf("Enter a string: ");
    gets(msg);
    printf("\n");

    for(i = 0; msg[i] != '\0'; ++i)
    {
        while (!( (msg[i] >= 'a' && msg[i] <= 'z') || (msg[i] >= 'A' && msg[i] <= 'Z') || msg[i] == '\0') )
        {
            for(j = i; msg[j] != '\0'; ++j)
            {
                msg[j] = msg[j+1];
            }
            msg[j] = '\0';
        }
    }
    i = 0;
    printf("Cleaned Message: ");
    while(msg[i])
    {
      putchar(toupper(msg[i]));
      i++;
   }
   for (i = 0; msg[i] != 0; ++i)
   {
       for(i = 0; i < 27; i++)
       {

       }
   }

   for (i = 0; msg[i] != '\0'; i++)   // letters to numbers
	{
		if (((msg[i] - 64) % 26) == 0)
			arr[i] == 26;
		else
			arr[i] = (msg[i] - 64) % 26;
	}
	printf("%d, ", arr[i]);
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
           for(i = deck[0]; i <= deck[i+6]; i++) //Finding location.
           {
               printf("%d, ", deck[i-1]);
           }
           break;
       }
       }
}
/*
int keyStream(n){

    srand(time(NULL));
    int j, k;
    printf("The %d key stream values are: \n", n);
    for( k =0; k < n; k++){
    j = rand() % 29 + 1;
    printf("%d, ", j);
    }
}

*/

