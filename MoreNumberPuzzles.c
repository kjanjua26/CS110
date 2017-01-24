#include<stdio.h>
int digitone()
{
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
}
int digittwo()
{

}
int main()
{
    digitone();
    return 0;
}
