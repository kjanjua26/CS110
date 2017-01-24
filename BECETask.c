#include <stdio.h>
int main()
{
    int i, j, N;
    printf("Enter the value of N: \n");
    scanf("%d", &N);
    for (i = N; i >= 1; --i)
    {
        for (j = 1; j <= i; j++)
        {
            printf("* ");
        }
        printf("\n");
    }
    return 0;
}
