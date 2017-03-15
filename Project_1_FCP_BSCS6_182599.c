/**************************************
** Title: Solitaire *
***************************************
** Coders: Raja Hasnain Anwar *
** 		   Muhammad Kamran Janjua *
***************************************
** Purpose: Learn basics of arrays *
**			and data encryption *
***************************************
** Built on: Sublime Text 3 *
**			 Code::Blocks *
***************************************
** Tested on: GCC MingW using Windows *
**			  Powershell *
**************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

void swap(int *first, int *second){ //swaps any two given numbers
	int temp = *first;
	*first = *second;
	*second = temp;
}

void shuffle(int array[]){
	int i, j; //indices
	srand(time(NULL));
	int times = rand() % 15; //shuffle the deck x times
	for ( i = 0; i < times; ++i) 
	{
		j = rand() % 28;
		array[i] += array[j];
		array[j] = array[i] - array[j];
		array[i] = array[i] - array[j];
	}
}
void clean(char[]);
void encryption(char[], int[]);
void decryption(char[], int[], int[]);
int keyStreamGenerator(int[]); //function to generate key stream value
int* lettersToNumbers(char[]);

int main()
{
	char message[50]; //original message which is to be encoded
	int i, j; //indices for loops
	int deck[] = {1, 4, 7 , 10, 13, 16, 19, 22, 25, 28, 3, 6, 9, 12, 15, 18, 21, 24, 27, 2, 5, 8, 11, 14, 17, 20, 23, 2, 6};//deck to get keystream from
	shuffle(deck); //shuffling deck

	printf("Enter the message [not more than 50 characters]: ");
	fgets(message, 50, stdin);

	/***** MESSAGE CLEANING *****/
	clean(message);

	/***** ENCRYPTION *****/
	encryption(message, deck);

	return EXIT_SUCCESS;
}


/********** FUNCTIONS DEFINITIONS *****************/


int keyStreamGenerator(int deck[]){
	int nth_digit = 0; //to be returned as key stream
	int i = 0, j = 0; //indices for loops 
	int temp; //dump
	int target;  //to make the deck continuous using modulo operator
	int A_location, B_location, first, second;
	int tmpDeck[28]; //temporary deck for swapping

	/*****	Joker A Swap	*****/
	for(i = 0; i < 28; i++){
		if (deck[i] == 27)
		{
			target = (i+1) % 28;
			swap(&deck[i], &deck[target]); //passing addresses for swap
			A_location = target; //getting A (27)'s location for triple cut
			break; //break the loop after swaping otherwise swaping may occur mulitple times and it saves extra looping as well
			/*
				Suppose 27 is at 5th place, if it's being swapped it means i = 4, after swaping it will be at 6th place (in case of i, 5) and will be
				swapped again in next iteration and so on.
			*/
		}
	}

	/*****	Joker B Swap	*****/
	for(i = 0; i < 28; i++){
		if (deck[i] == 28)
		{
			target = (i+1) % 28;
			swap(&deck[i], &deck[target]); //passing addresses for swap
			B_location = target; //getting B (28)'s location for triple cut
			
			if(j == 1)
				break; //break the OUTER loop after swaping two times otherwise swaping may occur mulitple times and it saves extra looping as well

			j = 1;
			/*
				j = 0 means that swap has not happened yet. After first swap, j = 1. In second swap, j is 1 so loop terminates after second swap
			*/
		}
	}

	/*****	Triple cut  ******/

	if(A_location < B_location){
		first = A_location; //27 comes before 28
		second = B_location;
	}
	else if(B_location < A_location){ //28 comes before 27
		first = B_location;
		second = A_location;
	}

	//	Forming New Deck after swaping

	//Part after second joker moves to the front
	for(i = second + 1, j = 0; i < 28; i++, j++){
		tmpDeck[j] = deck[i];
	}

	//Numbers between jokers
	for(i = first; i <= second; i++, j++){
		tmpDeck[j] = deck[i];
	}

	//Part before first joker moves to the end
	for(i = 0; i < first; i++, j++){
		tmpDeck[j] = deck[i];
	}

	memcpy(deck, tmpDeck, 28*sizeof(int)); //copying temproray deck back to original deck

	/*****	Shifting of MORE Numbers   ******/
	int bottomCard = deck[27];

	for(i = 0; i < bottomCard; i++)
		tmpDeck[i] = deck[i]; //copying x numbers into temporary deck
	tmpDeck[i] = bottomCard; //adding the bottom card into the temporary array for easy moving

	//Moving other numbers up the deck
	for(i = 0; i < 27; i++)
		deck[i] = deck[i+bottomCard];

	//adding temporary array at the bottom
	for(i = 27, j= bottomCard; i >= (27-bottomCard); i--, j--)
		deck[i] = tmpDeck[j];

	/*****	Key Stream  *****/
	int topCard = deck[0];
	if(topCard == 27 || topCard == 28)
		nth_digit = keyStreamGenerator(deck); //if top card is a joker, start again
	else
		nth_digit = deck[topCard+1];

	return nth_digit;
}

void encryption(char message[], int deck[]){
	int length_msg = strlen(message); //redefining length after removal of special characters
	int numbers[length_msg]; //an array of numbers for each character of "message"
	int codes[length_msg]; //an array of numbers for each character of "message"
	int keyStreams[length_msg];
	int i;

	printf("\nENCRYPTING MESSAGE...\n");

	printf("\n%-25s", "Cleaned Message: ");

	for(i = 0; i < length_msg; i++)
		printf("%3c ", message[i]); 

	/*****	Generating Numbers for Each Letter 	*****/
	printf("\n%-25s", "Letters to Numbers: ");

	for (i = 0; i < length_msg; ++i){
		numbers[i] = message[i] - 64;
		printf("%3d ", numbers[i]);
	}

	/***** KEY STREAMS *****/
	printf("\n%-25s", "Generated Keystreams: ");
	//generating
	for (i = 0; i < length_msg; ++i){
		keyStreams[i] = keyStreamGenerator(deck);
		printf("%3d ", keyStreams[i]);
	}

	/*****	Encoding Numbers 	*****/
	printf("\n%-25s", "Encoded Numbers: ");

	for (i = 0; i < length_msg; ++i){
		codes[i] = keyStreams[i] + numbers[i];

		while(codes[i] > 26)
			codes[i] -= 26;

		printf("%3d ", codes[i]);	
	}

	/*****	ENCODED Message 	*****/
	printf("\n%-25s", "Encoded Message: ");

	for (i = 0; i < length_msg; ++i){
		message[i] = codes[i] + 64;
		printf("%3c ", message[i]); 

	}

	/*****	DECRYPTION	*****/
	decryption(message, deck, keyStreams);
}

void decryption(char message[], int deck[], int keyStreams[]){
	int length_msg = strlen(message); //redefining length after removal of special characters
	int numbers[length_msg]; //an array of numbers for each character of "message"
	int codes[length_msg]; //an array of numbers for each character of "message"
	int i;

	printf("\n\nDECRYPTING MESSAGE...\n");

	printf("\n%-25s", "Encoded Message: ");

	for(i = 0; i < length_msg; i++)
		printf("%3c ", message[i]); 

	/*****	Generating Numbers for Each Letter 	*****/
	printf("\n%-25s", "Letters to Numbers: ");

	for (i = 0; i < length_msg; ++i){
		numbers[i] = message[i] - 64;
		printf("%3d ", numbers[i]);
	}

	/***** KEY STREAMS *****/
	printf("\n%-25s", "Generated Keystreams: ");
	for (i = 0; i < length_msg; ++i){
		printf("%3d ", keyStreams[i]);
	}
		

	/*****	Encoding Numbers 	*****/
	printf("\n%-25s", "Decoded Numbers: ");

	for (i = 0; i < length_msg; ++i){
		codes[i] = numbers[i] - keyStreams[i];

		while(codes[i] < 1)
			codes[i] += 26;

		printf("%3d ", codes[i]);	
	}

	/*****	ENCODED Message 	*****/
	printf("\n%-25s", "Decoded Message: ");

	for (i = 0; i < length_msg; ++i){
		message[i] = codes[i] + 64;
		printf("%3c ", message[i]); 

	}
	printf("\n");
}
void clean(char message[]){
	int length_msg = strlen(message); //length of message
	int i, j;

	for( i = 0, j = 0; i < length_msg; i ++){
		message[i-j] = toupper(message[i]); //converting each character to UPPER case and removeing spaces
		if( !isalpha(message[i]) ) //if not an alphabet
			j++;
	}
	message[i-j] = '\0';
}