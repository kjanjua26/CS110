#include<stdio.h>
#include<string.h>
int main()
{
    int i = 0;
    char arr_1[100];
    char arr_2[100];
    char space[5] = {" "};
    char fullName[100];
    printf("Enter your first name: ");
    scanf("%s", arr_1);
    printf("Enter your last name: ");
    scanf("%s", arr_2);
    fullName[100] = strcat(arr_1, space);
    printf("The full name is: %s\n", strcat(arr_1, arr_2));
    while (arr_1[i] != '\0')
    {
        if (arr_1[i] == 'a'){
            arr_1[i] = '$';
        }
        if (arr_1[i] == 'e'){
            arr_1[i] = '$';
        }
        if (arr_1[i] == 'i'){
            arr_1[i] = '$';
        }
        if (arr_1[i] == 'o'){
            arr_1[i] = '$';
        }
        if (arr_1[i] == 'u'){
            arr_1[i] = '$';
        }
        i++;
    }
    printf("\nAfter replacing it now is: %s", arr_1);
    printf("\n\n");
    return 0;
}
