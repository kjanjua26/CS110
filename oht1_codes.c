/* ************************************* /
* Author: ***Kamran Janjua***          *
* Purpose: The code the basic testing  *
* of the macros and IO Statements.     *
*                                      *
* ************************************ */

#include <stdio.h>
#include <stdlib.h>

#define add(x, y, z) ((x) + (y) + (z))
#define MACRO1 25
#define MACRO2 55
#define MACRO(x) x * (x+5)

float result;
int main()
{

int again;
int g;
int f;
int amount;
int note_500, note_100, note_50, note_20, note_10, note_5, note_2, note_1, choice;
note_500 = note_100 = note_50 = note_20 = note_10 = note_5 = note_2 = note_1 = 0;
char c;
int isLowercaseVowel, isUppercaseVowel;
float floating;

start:

printf("\\hello\nhow\tare \"you\"?\\\\\n");
printf("C:\nin\ the downward spiral\n");
printf("/ \\ // \\\\ /// \\\\\\ \n");

floating = (1.0/2.0) + (1.0/2.0);
printf("%.2f", floating);

result = (7.0) / (22.0);
printf("\nThe result \"HA-BIBI\" is %f\n", result);

g = add(2, 3, 5);
printf("%d\n", g);

#ifdef MACRO1
    printf("\nMACRO1 is defined with value[%d]\n", MACRO1);
#endif // MACRO1

#ifdef MACRO2
    printf("\nMACRO2 is defined with value[%d].\n", MACRO2);
#endif // MACRO2

#ifdef MACRO
    printf("\nMACRO is defined.\n");
#endif // MACRO)

int res = MACRO(2);
printf("\n res = [%d]\n", res);

printf("Please enter a value for f: \n");
scanf("%d", &f);

switch (f)
{
case 1:
    if (f == 1) {
        printf("It is one!!");
        break;
    }
    else {
        printf("Spoof!!!");
    }
case 2:
    if (f == 2){
        printf("It is two!!");
        break;
    }
    else {
        printf("Spoof!!");
    }
case 3:
    if (f == 3){
        printf("It is three!!");
        break;
    }
    else {
        printf("Spoof!!");
    }
case 4:
    if (f != 1 && f != 2 && f != 3){
        printf("Try Try Again!!!");
        break;
    }
    else {
        printf("Spoof!!");
    }
default:
    printf("Weldone!! Thanks for playing!!");
    break;
}
    printf("\nEnter the amount: \n");
    scanf("%d", &amount);

    if(amount >= 500)
    {
        note_500 = amount/500;
        amount -= note_500 * 500;
    }
    if (amount >= 100)
    {
        note_100 = amount/100;
        amount -= note_100 * 100;
    }
    if (amount >= 50)
    {
        note_50 = amount/50;
        amount -= note_50 * 50;
    }
    if (amount >= 20)
    {
        note_20 = amount/20;
        amount -= note_20 * 20;
    }
    if (amount >= 10)
    {
        note_10 = amount/10;
        amount -= note_10 * 10;
    }
    if (amount >= 5)
    {
        note_5 = amount/5;
        amount -= note_5 * 5;
    }
    if (amount >= 2)
    {
        note_2 = amount/2;
        amount -= note_2 * 2;
    }
    if (amount >= 1)
    {
        note_1 = amount;
    }
    printf("Total number of notes = \n");
    printf("\n");
    printf("500 = %d\n", note_500);
    printf("100 = %d\n", note_100);
    printf("50 = %d\n", note_50);
    printf("20 = %d\n", note_20);
    printf("10 = %d\n", note_10);
    printf("5 = %d\n", note_5);
    printf("2 = %d\n", note_2);
    printf("1 = %d\n", note_1);

printf("\nDo you wish to start again? Input 1 for yes and 0 for no.\n");
scanf("%d", &again);
if (again == 0){
    printf("\nBye Bye!");

}
else if (again == 1){
    printf("\n\n");
    goto start;
}
printf("Enter an alphabet:\n");
    scanf("%c", &c);

    isLowercaseVowel = (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u');
    isUppercaseVowel = (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');

    if (isLowercaseVowel || isUppercaseVowel)
        printf("%c is a vowel.\n", c);

    else
        printf("%c is a consonant.\n", c);

return 0;
}
