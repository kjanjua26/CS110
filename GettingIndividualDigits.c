#include<stdio.h>
int main()
{
    int i, j, sum;
    for (i = 1; i < 10; i++)
    {
        for(j = 0; j<= 9; j++)
        {
            sum = i + j;
            printf("%d", i);
            printf("%d, %d + %d = %d\n", j, i, j, sum);
        }

    }
}
