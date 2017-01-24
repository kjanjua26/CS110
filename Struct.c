#include <stdio.h>
typedef int flag; //Declaring own data type flag of type int.
typedef int group[10]; //Typedef is used to declare more complex data types.
enum week {SUNDAY, MONDAY, TUESDAY, WEDNESDAY, THURSDAY, FRIDAY, SATURDAY};
//In enum, the compiler gives each variable a tag starting from 0.
int main()
{
    int i, sum = 0;
    struct student {
    char name[50];
    int rollnum;
    int age;
    };
    struct student s1 = {"Kamran", 17, 18};
    printf("The name is: %s", s1.name);

   struct point{
   char name;
   int members;
   char captain[20];
   };
   struct point p = {"Pakistan", 11, "Afridi"}, *pp = &p; //Pointer pp is pointing towards members of p.

    printf("\nMembers: %d\nCaptain: %s", (*pp).members, pp->captain); //Printing the values. (*pp).x is same as pp->x.
    flag x = 20; //same as int x.
    printf("\nx: %d", x);
    group totals = {2, 3, 4, 5, 6, 7, 8, 9, 1};
    for (i = 0; i < 10; i++)
    {
        sum = sum + totals[i];
    }
    printf("\nSum: %d", sum);

    enum week week_day = TUESDAY;
    printf("\nTuesday is: %d", week_day);
    struct item {
    unsigned int list:1; //Forcing the compiler to assign 1 bit to represent list.
    unsigned int seen:1; //Considers only 1 bit now.
    unsigned int number:14; //This is called bit fields.
    };
    struct item c = {1, 1, 5};
    printf("\nThe Item condition in list: %d\nThe Item is seen: %d\nThe Item number: %d", c.list, c.seen, c.number);
    union data {
    float idata;
    float fdata;
    char* sdata;
    } d1, d2, d3;
    d1.idata = 10;
    d1.fdata = 4.24;
    d1.sdata = "Hello World";
    printf("\n%s", d1.sdata); //All fdata and idata point towards sdata.

}
