#include <stdio.h>

int begins(char string1[], char string2[]) {
	int i; 


	for (i = 0; string1[i] != '\0'; i++){
	
		//if (string1[ i ] == '\0') {
		//return(1);
		//}
		if (string1[i] != string2[i]) {
			return(0);
		}
		return 1;

	}
}

int main(void) {

	if (begins("foobar", "foobar")) {
		printf("they match!\n");
	} else {
		printf("no match.\n");
	}

	return(0);
}
