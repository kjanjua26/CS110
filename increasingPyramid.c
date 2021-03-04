/****************************************

    Coded By: Raja Hasnain Anwar
    Title: Pyramid of given height
    Method: Nested FOR loops

****************************************/
#include <stdio.h>
#include <stdlib.h>
int main(){

    int a, b, c, height;

    printf("Enter the height of the pyramid here:");
    scanf("%d", &height);

    for(a = 1; a <= height; a++){ //lines
        for(b=1; b <= height-a; b++){ // spaces
            printf(" ");
        }
        for(c=1; c <= (2*a-1); c++) //asterisks
            printf("*");

        printf("\n");
    }

    return EXIT_SUCCESS;
}
