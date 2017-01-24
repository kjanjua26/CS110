#include <stdio.h>

void printWarning(){

//give the function a name.
//writing methods is like writing
//program control always starts from main function.
/*

Place statements into a method if:
The statements are related structurally, and/or
The statements are repeated.

>>>> Functions: <<<<

1. Functions allow us to group commonly used code into compact unit that can be used repeatedly.
2. All other functions are directly or indirectly called from the main.

Function begins with the line: float triangle (float width, float height)
The function takes arguments along with their type.
C uses a form of parameter called "Call by Value"
C copies the value of parameters into the function's parameters and then starts executing the function's code.
With this form of parameter passing, a function cannot pass data to the caller using parameters.
Pointers can be tricked into passing information using pointers.
C does not require function type. If no function type is mentioned then the default type is int.
If you wanted to use the default (int) or if you simply forgot to declare a type.
To avoid this confusion, always declare the function type do not use the default.
Return statement is how we get data out of the function.
Declaration of the function is called the function prototype.
Variable names are not required when declaring a function prototype.
If no prototype is specified, the C compiler assumes the function returns an int and takes any number of parameters.
Omitting a prototype robs the C compiler of valuable information that it can use to check function calls.
Most compiler have compile time switch that warns the programmer about function calls without prototypes.





*/

Printf("This product causes cancer.\n");
printf("in lab rats and humans.\n");

}
void printYay(){
printf("Yayy Kamran Handsome!\n");
printWarning();

}

int square(int x){
x = x*x;
printf("The square is: %d", x);
}

int main()

{
    printYay();
    printf("Going in for the round 2\n");
    printf("\n");
    printf("\n");
    printWarning();
    printf("Done with messages!\n");
    square(2);
    return 0;
}
