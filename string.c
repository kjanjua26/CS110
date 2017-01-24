#include<stdio.h>
#include<string.h>
int main()
{
    char s1[] = "Sam";
    char s2[] = "Ali";
    int b = strlen(s1);
    printf("The length of string 1 is: %d\n", b);
    int c = strlen(s2);
    printf("The length of string 2 is: %d\n", c);
    printf("S2 concatenated to S1: %s", strcat(s1, s2));
    int a = strlen(strcat(s1, s2));
    printf("\nThe length is: %d\n", a); //Multiplies both lengths.
    printf("S2 copied onto S1: %s\n", strcpy(s1, s2)); //S2 is copied to S1.
    int l = strlen(strcpy(s1, s2));
    printf("The copied length is: %d\n", l); //The length is equal to the string copied.
    printf("S2 reversed is: %s\n", strrev(s1));
    printf("Specific Number of S2 concatenated to S1 is: %s\n", strncat(s2, s1, 2)); //concatenates 2 elements of s1 to s2.
    return 0;
}
