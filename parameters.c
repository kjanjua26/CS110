#include <stdio.h>

int begins(char string1[], char string2[]) {
	int index;
	for (index = 0; string1[index] != '\0'; index++){
		if (string1[index] != string2[index]) {
			return(0);
		}
		return 1;
	}
}

int main(void) {

	if (begins("foo", "foobar")) {
		printf("they match!\n");
	} else {
		printf("no match.\n");
	}

	return(0);
}
