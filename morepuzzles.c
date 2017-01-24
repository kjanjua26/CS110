#include <stdio.h>
#include <math.h>
void digitsGreater( void );
void digitsReverse( void );

int main(){
    char again;
    do {

        int choice;
        printf("1) Find numbers <= 56 having sum of digits > 10.\n");
        printf("2) Find two digit numbers minus number reversed which equals sum of digits.\n");
        printf("3) Quit.\n");
        printf("\n> ");
        scanf("%d", &choice);

        if(choice == 1)
            digitsGreater();
        else if(choice == 2)
            digitsReverse();
        else if (choice == 3)
            break;

        printf("\nTry again? y/n: ");
        scanf(" %c", &again);

    } while(again == 'y' || again == 'y');

    return 0;
}

void digitsGreater(){

    int num, sum = 0, temp, digit;

    for(num = 10; num < 57; num++){
        temp = num;
        sum = 0;

        for (temp = num; temp != 0;){
            digit = temp % 10;
            temp /= 10;
            sum += digit;

        }
        if(sum > 10)
            printf("%d => %d\n", num, sum);
    }

}

void digitsReverse(){
    int num, reverse,sum, digit, count, temp;

    for( num = 10; num <= 56; num++ ){

        temp = num;
        sum = 0;
        reverse = 0;
        count = 1;

        while( temp!=0 ){

            digit = temp % 10;
            temp /= 10;
            sum = sum + digit;
            reverse = reverse + digit * pow(10, count);
            count--;
        }

        if((num - reverse)== sum){
            printf("%2d => %2d\n", num, sum);
            printf("%d - %d = %d" , num, reverse, num-reverse);
        }
    }

}

