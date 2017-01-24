#include<stdio.h>

int main() {
int joker_A, joker_B;
   int arr_list[30], ele_1, ele_2, num, i, j;

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

    ele_1 = 27;
    ele_2 = 28;
    i = 0;
    while (i < num && ele_1 != arr_list[i])
    {
          i++;
    }
    if (i < num)
    {
        printf("Joker A found at the location = %d\n", i-1);
        printf("The location of Joker A is now: %d\n", i-2);
        if (27 == i-1)
        {
            printf("The location of Joker A is now: 0\n");
        }
    }
    j = 0;
    while (j < num && ele_2 != arr_list[j])
    {
        j++;
    }
    if(j < num)
    {
        printf("Joker B found at the location = %d\n", j-1);
        printf("The location of Joker B is now: %d\n", j+1);
    }

   return (0);
}
