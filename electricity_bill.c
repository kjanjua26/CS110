#include "stdio.h"
int main()
{
    int I, R, C, input, again;
    float units = 0.0, bill = 0.0;

    start:
        printf("\nEnter 0 for Commercial, 1 for Residential, 2 for Industrial: ");
        scanf("%d", &input);

        printf("\n Enter Units: ");
        scanf("%f", &units);

        if (input == 0 && units <= 1000)
        {
            bill = units * 3;
            printf("\n Commercial Bill: %.2f", bill);
        }
        if (input == 0 && units > 1000)
        {
            bill = 3000 + ((units - 1000) * 1.8);
            printf("\n Commercial Bill: %.2f", bill);
        }
        if (input == 1 && units <= 1000)
        {
            bill = units * 0.5;
            printf("\n Residential Bill: %.2f", bill);
        }
        if (input == 1 && units > 1000)
        {
            bill = 500 + ((units-1000) * 2.5);
            printf("\n Residential Bill: %.2f", bill);
        }
        if (input == 2 && units <= 1000)
        {
            bill = units * 5;
            printf("\n Industrial Bill: %.2f", bill);

        }
        if (input == 2 && units > 1000)
        {
            bill = 5000 + ((units-1000) * 3.25);
            printf("\n Industrial Bill: %.2f", bill);
        }

    printf("\nWant to run again Enter 0 for No, 1 for Yes\n");
    scanf("%d", &again);
    if (again == 0)
        {
            printf("Ok, Welcome.\n");
        }
    if (again == 1)
        {
            printf("\n\n");
            goto start;
        }

return 0;
}

