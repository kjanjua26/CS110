#include <stdio.h>

int main()
{
    int joker_A, joker_B, num, i,j, count = 0;
    int ele = 27;
    int arr_list[30];
    for(i = 1; i <= 28; i++)
    {
        printf("Enter Element # %d\n", i);
        scanf("%d", &arr_list[i]);
    }
    printf("\n");
    printf("The half deck of cards is: \n");
    printf("{");
    for (i = 1; i <= 28; i++)
    {
        printf("%d, ", arr_list[i]);
    }
    printf("}\n");
    printf("The position of 27 is: %d\n", count);

    for (j = 1; j <= 28; j++)
    {
        if (arr_list[j] == 27)
        {
            while (count < num && ele != arr_list[j])
            {
                count++;
            }
            joker_A = arr_list[j];
            //arr_list[j+1] = joker_A;
            printf("Found %d!\n", joker_A);
            printf("Found location of 27: %d\n", count);
        }
        if (arr_list[j] == 28)
        {
            joker_B = arr_list[j];
            printf("Found %d!\n", joker_B);
        }
    }
return 0;
}
