#include<stdio.h>
#include<stdio.h>
int main()
{
    /*
    int sum, i, j, k;
    printf("56\n");
    for (i = 4; i >= 0; i--)
    {
        for(j = 9; j >= 0; j--)
        {
            sum = i + j;
            if ( sum > 10){
                printf("%d%d\n", i, j);
            }
    }
}
*/
int i, j, sum, same, n, v;
for (i = 9; i >= 0; i--)
{
    for(j =9; j >= 0; j-- )
    {
        sum = i + j;
        printf("%d%d and %d%d is %d\n", i ,j, j, i, sum);
    }
}
}
