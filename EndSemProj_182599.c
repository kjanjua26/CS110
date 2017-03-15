//********************************************
//** 			Project: PPM Editor *
//*********************************************
//** Coded by: Raja Hasnain Anwar *
//**			 Muhammad Kamran Janjua *
//**			 Ali Hasaan Mughal *
//*********************************************
//** Platform used: Sublime Text 3 *
//**				  MingW GCC on PowerShell *
//*********************************************
//** Purpose: A hands-on approach to file *
//**			handling in C. Using that, *
//**			editing images of .ppm type. *
//*********************************************
//** Usage: Asks user to enter the in and out *
//**		  file names and select an option *
//**		  from menu to edit the images. *
//********************************************/

	//>>>>> HEADER FILES <<<<<
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

		//>>>>>	FUNCTION PROTOTYPES <<<<<*/
void greyscale(int **, int, int, int ); //convert to greyscale
void flip(int **, int, int, int ); //flip horizontally
void negate_red(int **, int, int, int ); //negative of red
void negate_green(int **, int, int, int ); //negative of green
void negate_blue(int **, int, int, int ); //negative of blue
void flatten_red(int **, int, int, int ); //just the red
void flatten_green(int **, int, int, int ); //just the green
void flatten_blue(int **, int, int, int ); //just the blue
void blur(int **, int, int, int ); //horiontal blur
void contrast(int **, int, int, int ); //extreme contrast
void noise(int **, int, int, int ); //random noise

		//>>>>> destination CODE <<<<<*/
int main(int argc, char const *argv[])
{	
	char in[15], out[20]; //files names

			//BASIC PRINTING*/
	printf("+-----------------------+\n");
	printf("|\tPPM EDITOR\t|\n");
	printf("+-----------------------+\n");

	printf("\nAvailable files:\n");
	printf("\t>> blocks.ppm\n");
	printf("\t>> cake.ppm\n");
	printf("\t>> squares.ppm\n");
	printf("\t>> tinypix.ppm\n");

				// TAKING INPUTS */
	printf("\nEnter the name of file you want to open [along with extension]: ");
	fgets(in, sizeof(in), stdin);
	in[strlen(in)-1] = '\0'; //little modification to open file correctly
	printf("\nEnter the name you want to \"save as...\" [along with extension]: ");
	fgets(out, sizeof(out), stdin);
	out[strlen(out)-1] = '\0'; //little modification to open file correctly

				//>>>>> FILE HANDLING STARTS <<<<<*/
	FILE *source = fopen(in, "r"); //opening specified file for reading;
	FILE *destination = fopen(out, "w"); //creating specifieed file to save

				// DEALING WITH ERRORS */
	if(!source){
		printf("Error while opening file, please try again.\n");
		fclose(source);
		fclose(destination);
		return 1;
	}
	else if(!destination){
		printf("Error while creating file, please try again.\n");
		fclose(source);
		fclose(destination);
		return 1;
	}

								// MENU */
	printf("\n\nYou have these choices: \n");
	printf("\n\t%-25s\t%-25s\t%-25s\n","[1] convert to greyscale", "[2] flip horizontally", "[3] negative of red" );
	printf("\t%-25s\t%-25s\t%-25s\n","[4] negative of green", "[5] negative of blue", "[6] just the red" );
	printf("\t%-25s\t%-25s\t%-25s\n","[7] just the green", "[8] just the blue", "[9] horizontal blur" );
	printf("\t%40s\t%-30s\n","[10] extreme contrast", "[11] random noise");

	printf("\nYour choices? Enter (y/n) against each entry number... [anything else will be considered 'n']\n");
	int choices[11], i, j; //temporary variables
	char ch;
	for (i = 0; i < 11; ++i)
	{
		printf("[%2d] : ", i+1);
		scanf(" %c", &ch);
			if(ch == 'y' || ch == 'Y')
				choices[i] = 1;
			else
				choices[i] = 0;
	}
	
	int cols,rows,max;
	char magic[3];
	fscanf(source, "%s %d %d %d", magic, &cols, &rows, &max);
	cols *= 3; //cols of pixels and each pixel is made of three colors so cols*3

	//2D array to hold the number patterns
	int** colors = malloc(rows * sizeof(int *));
	for ( i = 0; i < rows; ++i)
		colors[i] = malloc(cols * sizeof(int));

	//reading
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j++){ 
			fscanf(source,"%d",&colors[i][j]);
		}
	}

	fclose(source); //closing original file as it is not needed anymore

			// OPERATIONS */

	// array of functions
	void (*list[11])(int **, int, int, int );
	list[0] = &greyscale; //convert to greyscale
	list[1] = &flip; //flip horizontally
	list[2] = &negate_red; //negative of red
	list[3] = &negate_green; //negative of green
	list[4] = &negate_blue; //negative of blue
	list[5] = &flatten_red; //just the red
	list[6] = &flatten_green; //just the green
	list[7] = &flatten_blue; //just the blue
	list[8] = &blur; //horiontal blur
	list[9] = &contrast; //extreme contrast
	list[10] = &noise; //random noise

	// calling functions if the user has selected them
	int temp;
	for (temp = 0; temp < 11; ++temp){
		if(choices[temp]){ //if selected
			list[temp](colors, rows, cols, max); //call
		}
	}

			// WRITING NEW FILE */
	//header
	fprintf(destination, "%s\n%d %d\n%d\n", magic, cols/3, rows, max);
	//body
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j++){ 
			fprintf(destination,"%d ",colors[i][j]);
		}
		fprintf(destination,"\n");
	}
	printf("\n%s created!\n", out);
	fclose(destination); //closing created file and exiting
	return 0;
}


		//>>>>>	 FUNCTION DEFINITIONS  <<<<<*/
//**********************************************************
//******* IN ALL THESE FUNCTIONS, COLORS IS THE ARRAY ********
//********* FOR HOLDING COLOR NUMBERS OF THE IMAGE. **********
//*** WHERE [i][j] STANDS FOR RED, [i][j+1] FOR GREEN AND ****
//******************** [i][j+2] FOR BLUE. ********************
//***********************************************************/
void greyscale(int ** destination, int rows, int cols, int max){
	int i, j, average;
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j+=3){ 
			average = (destination[i][j] + destination[i][j+1] + destination[i][j+2]) / 3;
			destination[i][j] = destination[i][j+1] = destination[i][j+2] = average;
		}
	}
}
void flip(int ** destination, int rows, int cols, int max ){
	//flipping
	int i, j, tmp;
	for (i= 0; i < rows; ++i){
		for (j = 0; j < cols/2; j++){
			tmp = destination[i][j];
			destination[i][j] = destination[i][cols - j - 2];
			destination[i][cols - j -2] = tmp;
		}
	}
}
void negate_red(int ** destination, int rows, int cols, int max ){
	int i, j;
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j++){ 
			destination[i][j] = 255 - destination[i][j];
		}
	}
}
void negate_green(int ** destination, int rows, int cols, int max ){
	int i, j;
	for (i =  0; i < rows; i++){
		for (j = 1; j < cols; j++){ 
			destination[i][j] = 255 - destination[i][j];
		}
	}
}
void negate_blue(int ** destination, int rows, int cols, int max ){
	int i, j;
	for (i =  0; i < rows; i++){
		for (j = 2; j < cols; j++){ 
			destination[i][j] = 255 - destination[i][j];
		}
	}
}
void flatten_red(int ** destination, int rows, int cols, int max ){
	int i, j;
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j++){ 
			destination[i][j] = 0;
		}
	}
}
void flatten_green(int ** destination, int rows, int cols, int max ){
	int i, j;
	for (i =  0; i < rows; i++){
		for (j = 1; j < cols; j++){ 
			destination[i][j] = 0;
		}
	}
}
void flatten_blue(int ** destination, int rows, int cols, int max ){
	int i, j;
	for (i =  0; i < rows; i++){
		for (j = 2; j < cols; j++){ 
			destination[i][j] = 0;
		}
	}
}
void blur(int ** destination, int rows, int cols, int max ){
	int i, j, k, avg_red, avg_green, avg_blue;
	//blurring
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j+=9){
			avg_red = (destination[i][j] + destination[i][j+3] + destination[i][j+6]) / 3;
			avg_green = (destination[i][j+1] + destination[i][j+4] + destination[i][j+7]) / 3;
			avg_blue = (destination[i][j+2] + destination[i][j+5] + destination[i][j+8]) / 3;
			
			destination[i][j] = destination[i][j+3] = destination[i][j+6] = avg_red;
			destination[i][j+1] = destination[i][j+4] = destination[i][j+7] = avg_green;
			destination[i][j+2] = destination[i][j+5] = destination[i][j+8] = avg_blue;
		}
	}
}
void contrast(int ** destination, int rows, int cols, int max ){
	int i, j;
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j++){
			destination[i][j] = destination[i][j] < max/2 ? 0 : max;
		}
	}
}
void noise(int ** destination, int rows, int cols, int max ){
	int i, j, noise, choice;
	for (i =  0; i < rows; i++){
		for (j = 0; j < cols; j++){
			//Adding the number in each component red,green and blue.
			choice = rand()%2;
			noise = rand()%max;
			//add if choice is 1 and round off to keep in limit, absolute value in case of subtract
			destination[i][j] = (choice == 0) ? abs(destination[i][j]-noise) : (destination[i][j]+noise)%max;
		}
	}
}