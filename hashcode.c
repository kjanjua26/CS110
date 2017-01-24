#include <stdio.h>
int begins(char input[]){

int index;
int hash = 0;

for (index = 0; index < sizeof(input); index++){
    hash += input[index];
}

return hash;

}

int main(void)
{

char char_array[] = {'K', 'A', 'M', 'R', 'A', 'N'};

printf("The hash code is: %d\n", begins(char_array));

return 0;

}
