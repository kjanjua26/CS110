#include <stdio.h>
int main(){
    int num;
      int b;
    int a = 0;
    int n = 2;

 printf("Enter Num: \n");
 scanf("%d", &num);
    /*
    int num;
    int digits = 0;

    while (num > 0)
    {
        num = num /10;
        digits++;
    }
    return digits;
*/
    while (n >= a)
    {
        b = num % 10;
        num = num / 10;
        a++;
    }
    return b;

}
