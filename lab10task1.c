#include<stdio.h>
int main()
{
    int i, n;
    int arr[100];
    printf("\nEnter the Array's range: \n");
    scanf("%d",&n);
    for (i = 0; i < n; i++)
    {
        printf("\nEnter element # %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nThe array is: ");
    for (i = 0; i < n; i++)
    {
        printf("%d, ", arr[i]);
    }

    arr[n] = arr[0];

    for (i = 0; i < n; i++)
    {
        arr[i] = arr[i+1];
    }
        printf("\n\n");
        printf("\nCyclically permuted elements are: ");
        printf("\n\n");
        for (i = 0; i < n; i++)
        {
            printf("%d, ", arr[i]);
        }

    return 0;
}
