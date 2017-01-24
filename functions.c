/*
#include <stdio.h>
int main()

{
  //int x = 10, y = 5;

  // Code to swap 'x' and 'y'

  x = x + y;  // x now becomes 15
  y = x - y;  // y becomes 10
  x = x - y;  // x becomes 5

    //x = y;
    //y = y - x;
    //y = x + x;
    //printf("After Swapping: x = %d, y = %d", x, y);

    printf("Please enter two 2number: ");
    fgets(x, 63 the length should be 63 //, //stdin);

    //fgets(y, 63 the length should be 63 , stdin);

    sscanf("%d", &x);
    fputs(x, stdout);
    //fputs(y, stdout);

  return 0;
}
*/

/*

                >>>> Jumps in Loops <<<<

1. Jump out of loop (Jump out after execution) use break.
2. Skipping a part of loop use continue.

Control structure. a programming construct that affects the flow of a program's execution.
    may include one or more statements.
The for loop is an example of a looping control structure.
A counter iterative statement has a loop variable, and a means of specifying the initial and terminal, stepsize values.
A "for" loop is a infinite loop if the second condition is absent.
The first expression is evaluated once, but the other two are evaluated with each iteration.

C++ differs from C in two ways:

    The control expression can also be Boolean.
    The initial expression can include variable definitions (scope is from the definition to the end of the loop body.)

Repetition control is based on Boolean expression.
C has both pretest and post test forms, in which the control expression can be arithmetic.
It is convenient for the programmers to decide a location for loop control (other than top or bottom of the loop).
Single design for single loops (break).
Break is unconditional unlabeled exit.
Java and Perl have unconditional labeled exits and labeled continue.
C has unlabeled control statement, continue, that skips the remainder of the current iteration.
C can be used to build a user-defined iterator.
While statement is used when program needs to perform a specific task.
The program repetitively executes the statement inside the while until the condition becomes false(0).
C allows programmers to put assignment statements in the while conditional.
Simplest loop structure: evaluate body as long as condition is true.
Condition evaluated first, so body may never be executed.



*/

#include <stdio.h>
#include <conio.h>

int main()

{
    /*
    int i;
    for (i = 1; /* i <= 10 this is now a infinite loop  ; i++){
        /*
        if (i == 3){
            continue;
        }
        if (i == 5){
            break;
        }
        printf("\t %d", i);

    }




    int next_number, current_number, old_number;
    old_number = 0;
    current_number = 1;
    printf("0\n");
    while (current_number < 100 )

    {

        printf("%d\n", current_number);
        next_number = current_number + old_number;
        old_number = current_number;
        current_number = next_number;

    }
    a*x + b*y = g*c*d(a, b);  //Extended Euclidean Algorithm
    return 0;

}

*/

int hours;
int pay;
int week_pay;
int hour_wage;

printf("Enter the number of hours you worked: \n");
scanf("%d", &hours);
printf("Enter your hourly pay: \n");
scanf("%d", &pay);

hour_wage = hours * pay;
week_pay = hour_wage * 7;
if (hours > 40){
    int overtime;
    overtime = hour_wage * 0.5;
    hour_wage = hour_wage + overtime;
}
printf("Your hourly wage is: %d\n", hour_wage);
printf("Your weekly pay is: %d\n", week_pay);
return 0;

}
