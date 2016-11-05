#include<stdio.h>
#include<stdlib.h>

int main()
{
    int i, n, t_1 = 0, t_2 = 1, nT = 0;

    printf("Enter the number of terms: \n");
    scanf("%d", &n);

    printf("Fibonacci Series: \n");

    for (i = 1; i <=n; i++)
    {

        if (i == 1){
            printf("%d, ", t_1);
            continue;
        }
        if (i == 2){
            printf("%d, ", t_2);
            continue;
        }
        nT = t_1 + t_2;
        t_1 = t_2;
        t_2 = nT;
        printf("%d, ", nT);
    }
    return 0;
}
