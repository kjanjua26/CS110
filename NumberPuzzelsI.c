#include<stdio.h>
int main()
{
    int i, j;
    for (i = 60; i>0; i--)
    {
        for(j = 1; j<=i; j++)
        {
            if((i+j)==60){
                printf("(%d, %d)\n", i, j);
            }
            if((i-j)==14)
            {
                printf("(%d, %d)\n", i, j);
            }
        }
    }
}
