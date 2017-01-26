#include<stdio.h>
#include<string.h>
int main()
{
    /*
    In C, string does not exist as individual data type. Strings are combination of chars.
    In other words, array of characters, make a string.
    String "Y" takes two bytes, one for character in it and one for null character, a char takes one byte.

    fgets(name, sizeof(name), stdin) is used to read string. It reads end character as well i.e. null character.
    When strlen is calculated of the input taken using fgets(), the null character is added to it's end.
    test's strlen is 5 not 4 due to fgets().

    sscanf() is used to string scanf and then convert it to numbers to process like doubling etc.
    sscanf(line, sizeof(line), &variablename, ... ). & is necessary which indicates that sscanf() has to change it's value.

    In C, initialization is possible in declaration statement.

    */
    char name[4];
    name[0] = 'S';
    name[1] = 'A';
    name[2] = 'M';
    name[3] = '\0';
    printf("%s", name); //name = SAM. SAM is string of four characters.

    char intro[100]; //can hold string of 99 characters, one is for null character.
    strcpy(intro, "KAMRAN");
    printf("\n%s", intro); //The array size is 100, but string length is 6, excluding null character.
    printf("\nThe size of string is: %d", strlen(intro)); //outputs 6.
    printf("\nThe size of array is: %d", sizeof(intro)/sizeof(char)); //prints the size of array that is 100.

    char input[100]; //for 4 character input, always take 2 more than the strlen as size of the array.
    printf("\nEnter a string:  ");
    fgets(input, sizeof(input), stdin);
    input[strlen(input)-1] = '\0'; //Is used to get rid of null character that is also counted by fgets().
    printf("\nThe input is: %s", input);
    printf("\nThe size of input is: %d", strlen(input));

    char line[100];
    int value;
    printf("\nEnter the string: ");
    fgets(line, sizeof(line), stdin);
    sscanf(line, "%d", &value);
    printf("\nThe twice of string(%d) is: %d", strlen(line), value*2);

    char *str;
    str = (char*) malloc(3 * sizeof(char));
    strcpy(str, "hi");
    printf("\nThe dynamically allocated string is: %s", str);
    str = (char*) realloc(str, 16 * sizeof(char));
    strcpy(str, "Hi! This is Me.");
    printf("\nThe dynamically reallocated string is: %s\n", str);

    int num = 4, sum = 0, i;
    int *ptr;
    ptr = (int*) malloc(num*sizeof(num));
    if(ptr == NULL) {printf("\nNothing Allocated.");}
    for (i = 0; i < num; i++)
    {
        scanf("%d", ptr + i);
        sum += *(ptr + i);
    }
    printf("\nThe sum is: %d", sum);

    return 0;
}
