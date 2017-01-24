/*
Procedures are collection of statements that define parameterized computations.
Procedures are non-value returning functions.
In C, they are void functions, methods.
Procedures are often called from separate statements.
Functions structurally resemble procedures but are semantically modeled on mathematical functions.

Value returning functions are non void functions.
They are called from expression.

Pass by Value:
Original values are not changed.
Additional Storage and Computation are required.

Pass by Result:
An argument passed by result is implemented by copying the final value computed for the parameters out to the argument at the end of the life of call.
Required extra storage and copy operation.



#include <stdio.h>
int x = 0;
void foo(int y)
{
    x = x + 1;
    y = y + 4;
    printf("X: %d\n", x);
}
int main(){
foo (x);
printf("X: %d\n", x);
return 0;
}
*/

#include <stdio.h>
int swap(int i, int j)
{
    int t = i;
    i = j;
    j = t;
    printf("a: %d\nb: %d\n", i, j); //now the value is swapped.
}
void main()
{
    int a = 1, b = 2;
    printf("a: %d\nb: %d\n", a, b);
    swap(1, 2);
    /* printf("a: %d\nb: %d\n", a, b); the value is not swapped, as the value of a and b is same. */
    return 0;
}
