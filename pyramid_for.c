/*
#include<stdio.h>
int main()
{
    int rows, i, j, space;

    printf("Enter number of rows: ");
    scanf("%d",&rows);

    for(i=rows; i>=1; --i)
    {
        for(space=0; space < rows-i; ++space)
            printf("  ");

        for(j=i; j <= 2*i-1; ++j)
            printf("* ");

        for(j=0; j < i+1; ++j)
            printf("* ");

        printf("\n");
    }

    return 0;
}
*/
#include <stdio.h>

int main() {
        int rows, star, spaces, number_of_stars;
        printf("Enter number of rows: ");
        scanf("%d",&number_of_stars);
        int number_of_rows = number_of_stars;

        for (rows=1; rows <= number_of_rows; rows++) {
                for (spaces=1; spaces <= number_of_stars; spaces++) {
                        printf(" ");
                }
                for (star=1; star <= rows; star++) {
                        printf("*");
                        printf(" ");
                }
                printf("\n");
                number_of_stars = number_of_stars - 1;
        }
        return 0;
}
