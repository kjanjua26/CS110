#include<stdio.h>
#include<time.h>
#include<ctype.h>
int main()
{
    int i, n, j, num;
    int card[6];
    char msg[150];
    char arr[150];
    char sum[150];
    char Encodedmessage[150];
    char Reverse[150];
    char ReverseMessage[150];

    int deck[28] = {5,8,11,14,17,20,23,26,28,9,12,15,18,21,24,2,27,1,4,7,10,13,16,19,22,25,3,6};
    int keystreamArray[15] = {11,9,23,7,10,25,11,11,1,20,26,14,8,6,2};
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
    printf("Cleaned Message :\t");
    for(i = 0 ; msg[i]!='\0' && sizeof(msg)/sizeof(int) ; ++i)
    {
        arr[i] = toupper(msg[i]);
        printf("%5c", arr[i]);
    }

    printf("\nLetters To Numbers :\t");
    for( i = 0 ; (arr[i] != '\0') && (arr[i] >= 65 && arr[i] <= 90) ; ++i)
    {
        arr[i] = arr[i] - 64;
        printf("%5d",arr[i]);
    }
    printf("\nGenerated KeyStreams: \t");
    for (i = 0; i < 15; i++)
    {
        printf("%5d", keystreamArray[i]);
    }

    printf("\nEncoded Numbers are :\t");
    for(i = 0 ; (arr[i] != '\0') && (arr[i] >= 1 && arr[i] <= 26) ; ++i)
    {
        sum[i] = arr[i] + keystreamArray[i];
        if(sum[i] > 26)
           sum[i] -= 26;

        printf("%5d", sum[i]);
    }
    printf("\nEncoded Message :\t");
    for(i = 0 ; (arr[i] != '\0') && (arr[i] >= 1 && arr[i] <= 26) ; ++i)
    {
        Encodedmessage[i] = sum[i] + 64 ;
        printf("%5c", Encodedmessage[i]);
    }
    //Decoding.
    printf("\n\nDecoding..\n");
     printf("\nEncoded Message :\t");
    for(i = 0 ; (arr[i] != '\0') && (arr[i] >= 1 && arr[i] <= 26) ; ++i)
        {
        printf("%5c", Encodedmessage[i]);
    }

        printf("\nLetters to Numbers :\t");
    for(i = 0 ; (arr[i] != '\0') && (arr[i] >= 1 && arr[i] <= 26) ; ++i)
    {
        Reverse[i] = Encodedmessage[i]-64;
        printf("%5d",Reverse[i]);
    }
    printf("\nGenerated KeyStreams: \t");
    for (i = 0; i < 15; i++)
    {
        printf("%5d", keystreamArray[i]);
    }
    printf("\nDecoded Numbers :\t");
    for( i = 0 ; (arr[i] != '\0') && (arr[i] >= 1 && arr[i] <= 26) ; i++)
    {
        ReverseMessage[i] = sum[i] - keystreamArray[i];
        if(ReverseMessage[i] < 1)
            ReverseMessage[i] += 26;

        printf("%5d",ReverseMessage[i]);
    }
    printf("\nDecoded Message :\t");
    for( i = 0 ; (arr[i] != '\0') && (arr[i] >= 1 && arr[i] <= 26) ; i++)
    {
        printf("%5c",ReverseMessage[i] + 64);
    }
    printf("\n");


   return 0;
}
