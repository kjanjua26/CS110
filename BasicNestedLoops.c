#include <stdio.h>
#include <stdlib.h>
int main()
{
    int i, j;
    for (i = 0; i<= 5; i++)
    {
        for(j =0; j <=5; j++){
            printf("(%d,%d)\t", i ,j);
        }
        printf("\n");
    }
}
