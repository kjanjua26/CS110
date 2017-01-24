#include<stdio.h>
int main()
{
 char line[100];/* line of data for input */
 int total; /* Running total of all numbers so far */
 int item; /* next item to add to the list */
    //declaring
    struct student{
    char name[50];
    int age;
    int rollnum;
    };
    //create struct variable
    struct student s1 = {"Kamran", 18, 17};
    //accessing the struct variable
    printf("Name: %s \n", s1.name);
    printf("Roll Number: %d \n", s1.rollnum);
    printf("Age: %d ", s1.age);
    return 0;


 total = 0;
 while (1) {
 printf("Enter # to add \n");
 printf(" or 0 to stop:");
 fgets(line, sizeof(line), stdin);
 sscanf(line, "%d", &item);
 if (item == 0)
 break;
 total += item;
 printf("Total: %d\n", total);
 }
    printf("Final total %d\n", total);
    return (0);
}
