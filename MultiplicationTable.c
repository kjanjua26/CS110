#include <stdio.h>
int main()
{
    int i, j, k;

printf("\n x | ");
for (k = 1; k <= 9; k++)
{
    printf("\t  %d", k);
}
printf("\n===+=======================================================================\n");
for(i = 1; i <= 12; i++)
{
    printf("%2d |", i);
    for (j = 1; j <= 9; j++)
    {
        printf("\t%3d", i * j);
    }
    printf("\n");
}
return 0;
}
