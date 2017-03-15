//This is a madlibs program. It fills in the blank of a pre-set story line by taking required words from the user. 

#include<stdio.h> //include the header file of library standard input output. 
#include<stdlib.h> //include the header file of standard library. 
int main() //initiates the program. 
{ //indicates that the code is started from here. 

    char verb_one[30]; //declare a character of name verb_one of size 30.
    char verb_two[30]; //declare a character of name verb_two of size 30.
    char verb_three[30]; //declare a character of name verb_three of size 30.
    char nameOfPlant[30]; //declare a character of name nameOfPlant of size 30.
    char pluralNoun[30]; //declare a character of name pluralNoun of size 30.
    char feelingsAdjective[30]; //declare a character of name feelingsAdjective  of size 30.
    char animal[30]; //declare a character of name animal of size 30.
    char thingExistingVeryOften[30]; //declare a character of name thing existing very often of size 30.

    printf("Welcome to Madlibs Program.\n"); //prints the line welcome to madlibs program. 
    printf("\n"); //escape sequence used to leave a blank line. 

    printf("Please enter verb one: \n"); //prints and asks the user to enter verb one.
    scanf("%s", verb_one); //scans and stores the value of verb one in verb_one. 

    printf("Please enter a name of plant: \n"); //prints and asks the user to enter name of plant. 
    scanf("%s", nameOfPlant); //scans and stores the value of plant name in  nameOfPlant. 

    printf("Please enter the name of a thing existing very often: \n"); //prints and asks the user to enter name of a thing. 
    scanf("%s", thingExistingVeryOften); //scans and stores the value of thing in thingExistingVeryOften. 

    printf("Please enter an adjective for feelings: \n"); //prints and asks the user to enter name of an adjective.
    scanf("%s", feelingsAdjective); //scans and stores the value of adjective in feelingsAdjective. 

    printf("Please enter verb two: \n"); //prints and asks the user to enter name of verb two. 
    scanf("%s", verb_two); //scans and stores the value of verb two in verb_two.

    printf("Please enter a plural noun: \n"); //prints and asks the user to enter a plural noun. 
    scanf("%s", pluralNoun); //scans and stores the value of noun in pluralNoun. sz

    printf("Please enter a name of animal: \n"); //prints and asks the user to enter a name of animal. 
    scanf("%s", animal); //scans and stores the value of animal in animal. 

    printf("Please enter verb three: \n"); //prints and asks the user to enter a verb three.
    scanf("%s", verb_three); //scans and stores the value of verb in verb_three. 

    //prints out the lines and also by filling in the above entered values where required. 
    printf("If some one %s a %s of which just one example exists among all the \nmillions and millions of %s, that's enough to make him %s \nwhen he %s at the %s. He tells himself, My %s is up there somewhere. . . .\nBut if the %s %s the flower, then for him it's as if, \nsuddenly, all the stars went out. And that isn't important?", verb_one, nameOfPlant, thingExistingVeryOften, feelingsAdjective, verb_two, pluralNoun, nameOfPlant, animal, verb_three);


return 0;
} //indicates that program terminates here. 
