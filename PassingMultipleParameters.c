#include<stdio.h>
int add( int, int);
int x = 0; //If const int x = 0, then changing it's value in foo(), won't work.
//int y = 0;
int main()
{
    /*
    If the function is prototyped as add (int x) and in calling add(y) is used, then the value of y declared globally is updated.
    Else if parameter and argument is same, then x globally declared is not updated.
    If x is const int declared globally, then updating it in user defined function is not possible.

    Pass by Reference:
    In this method, the address of the argument is copied into the parameters.
    The original values are changed and thus returning usually the values or printing them in func is not required.
    When the address is passed, the address which is pointed to by pointer is updated, the value is changed globally.
    Let's say in a function, x = 5 and parameter is y. So, x = y = 5.
    If in that function, y = 1 is encountered, then x = y = 1 is updated.

    */
    int a = 10;
    int b = 22;
    int out = add(&a, &b); //Addresses are passed and are added.
    printf("The added addresses are: %d\n", out);
    printf("The address of b is: %d\n", &b);
    printf("The address of a is: %d", &a);
    foo(x);
    printf("\nThe updated value of x is: %d", x); //x value is updated because parameter and argument is not same, passing is done by value.
    int y = 1, g = 2;
    swap(y, g); //When &y and &g are passed, their addresses are passed into the function.
    printf("\nThe values are not changed: %d %d", y, g); //No change because value is not updated.
    return 0;
}
int add( int a, int b)
{
    int sum;
    sum = a + b;
    return sum;
}
void foo(int y) //if the value passed is same as argument, then x globally declared remains same else it is updated.
{
    //y = x = 0;
    x = x + 1; //If x is const int defined, then this statement won't work.
    y = y + 4;
    printf("\nThe value of x in foo is: %d", x);
    printf("\nThe value of y in foo is: %d", y);
}
void swap(int i, int j) //*i, *j means that address of y and g is now passed to these and then it will be changed.
{
    int t = i;
    i = j;
    j = t;
    //output printed will not be swapped since these are not returned or printed here.
}
