#include <stdio.h>
#include <time.h>
int main()
{
    const int rows = 2;
    const int columns = 5;
    int sum = 0;
    srand(time(NULL));
    int arr[rows][columns];
    int i, j, k;
    for (i = 0; i <= 2; i++)
    {
        for (j = 0; j <= 4; j++)
        {
            arr[i][j] = rand() % 100;
        }
    }
    for (i = 0; i <= 1; i++)
    {
        for (j = 0; j <= 4; j++)
        {
            printf("Student # %2d: %2d\n", (i+1)*(j+1), arr[i][j]);
            sum = sum + arr[i][j];
        }
    }
    int a = hcf(sum, rows, columns);
    printf("\nThe average is: %d\n", a);
    return 0;
}
int hcf(int sum, int rows, int columns)
{
    int avg = sum / (rows*columns);
    return avg;
}
