#include <Stdio.h>

int main()
{
    int num;
    int nextnum;
    int prevnum;

    num = 0;

    while (1){
    printf("Enter a number: \n");
    scanf("%d", &nextnum);
    num += nextnum;
    if (nextnum == 0) break; //if it == 0, break the program.
    if (nextnum != 0){
        continue; //if the number doesnot equal 0, continue the process.
}
    }
    printf("The total is: %d \n", num);
    return 0;
}
