#include <stdio.h>
int sum(int);
int fact(int);
int pow(int, int);
int fibo(int);
int main()
{
    int num, res, su, h, d, i;
    int arr[5] = {1, 3, 5, 7, 9};
    printf("Enter the number of natural numbers you want to sum: \n");
    scanf("%d", &num);
    printf("Enter the Number you want to get factorial of: \n");
    scanf("%d", &h);
    printf("Enter the term you want fibo numbers till: ");
    scanf("%d",&d);

    res = sum(num);
    printf("The sum is: %d\n", res);
    int b = fact(h);
    printf("The factorial of %d: %d\n",h, b);
    int c = pow(3, 2);
    printf("The powered value of 3 is: %d\n", c);

    printf("First %d fibonacci numbers are: \n", d);
    for (i=1; i<=d; i++)
        {printf("%d ", fibo(i));}
    return 0;

}
int sum(int n)
{
    if (n != 0)
        return (n + sum(n-1));
    else
        return 0;
}
int fact(int n)
{
    if (n == 0)
        return 1;
    else
        return n * fact(n-1);
}
int pow(int a, int n)
{
    if (n == 0)
        return 1;
    else
        return a * pow(a, n-1);
}
int fibo(int i)
{
    if (i == 0) return 1;
    if (i == 1) return 1;
    return fibo(i - 1) + fibo(i-2);
}
