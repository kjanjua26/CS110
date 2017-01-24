#include <stdio.h>
#include<stdlib.h>
#include<time.h>
#include<windows.h>
#include<stddef.h>
#define ROW 35
#define COLUMN 85

//function prototypes
void iniarray(char z[][COLUMN]); //Initialises array
void passarray(char z[][COLUMN], int); // Passes seed into main array.
void border(char[][COLUMN]); // prints the array on console
void scharray(char[][COLUMN]); //searches array

//SEEDS
char boat[5][5] =
{ { ' ', ' ', ' ', ' ', ' ' },
{ ' ', '+', '+', ' ', ' ' },
{ ' ', '+', ' ', '+', ' ' },
{ ' ', ' ', '+', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ' } };
char block[4][4] =
{ { ' ', ' ', ' ', ' ' },
{ ' ', '+', '+', ' ' },
{ ' ', '+', '+', ' ' },
{ ' ', ' ', ' ', ' ' } };
char loaf[6][6] =
{ { ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', '+', '+', ' ', ' ' },
{ ' ', '+', ' ', ' ', '+', ' ' },
{ ' ', ' ', '+', ' ', '+', ' ' },
{ ' ', ' ', ' ', '+', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ' } };
char beehive[5][6] =
{ { ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', '+', '+', ' ', ' ' },
{ ' ', '+', ' ', ' ', '+', ' ' },
{ ' ', ' ', '+', '+', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ' } };
char blinker[5][5] =
{ { ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ' },
{ ' ', '+', '+', '+', ' ' },
{ ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ' } };
char beacon[6][6] =
{ { ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', '+', '+', ' ', ' ', ' ' },
{ ' ', '+', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', '+', ' ' },
{ ' ', ' ', ' ', '+', '+', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ' }
};
char toad[6][6] =
{ { ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', '+', '+', '+', ' ' },
{ ' ', '+', '+', '+', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ' } };
char pulsar[17][17] = {
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', '+', '+', '+', ' ', ' ', '+', '+', ' ', '+', '+', ' ', ' ', '+', '+', '+', ' ' },
{ ' ', ' ', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', '+', ' ', ' ', ' ' },
{ ' ', '+', '+', '+', ' ', ' ', '+', '+', ' ', '+', '+', ' ', ' ', '+', '+', '+', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
};
char glidergun[15][38] = {
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', '+', '+', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ' },
	{ ' ', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', '+', ' ', '+', ' ', ' ', '+', ' ', ' ', ' ', '+', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', '+', '+', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
	{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
};
char glider[5][5] = {
{ ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', '+', ' ', ' ' },
{ ' ', ' ', ' ', '+', ' ' },
{ ' ', '+', '+', '+', ' ' },
{ ' ', ' ', ' ', ' ', ' ' }
};
char spaceship[7][9] = { { ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', '+', ' ', ' ', '+', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', '+', ' ', ' ' },
{ ' ', ' ', '+', ' ', ' ', ' ', '+', ' ', ' ' },
{ ' ', ' ', ' ', '+', '+', '+', '+', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' },
{ ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ', ' ' }
};


//PROGRAM STARTS HERE
int main() {

	int g, x, b, c;
	char a[ROW][COLUMN];

	//Start screen
	printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t    WELCOME TO THE GAME OF LIFE \n\t\t\t\t\t\t       Press Enter to Play...");
	getchar();
	system("cls");

	//Selection screen
jump:
	printf("Please Select Seed: \n\nPress 1 for BLOCK\nPress 2 for BOAT\nPress 3 for LOAF\nPress 4 for BEEHIVE\nPress 5 for BLINKER\nPress 6 for BEACON\nPress 7 for TOAD\nPress 8 for PULSAR\nPress 9 for GLIDER\nPress 10 for LIGHTWEIGHT SPACESHIP\nPress 11 for GLIDER GUN\nEnter: ");
	scanf_s("%d", &b);
	iniarray(a);
	printf("Enter Generation: ");
	scanf_s("%d", &g);
	puts("");
	Sleep(1000);
	system("cls");

	//Generations start
	system("color F0");
	passarray(a, b);
	border(a);
	Sleep(1000);
	system("cls");
	for (x = 1; x <= g; x++) //Controls the generations
	{
		if (x == g) {
			scharray(a);
			border(a);
			Sleep(50);
		}
		else {
			scharray(a);
			border(a);
			Sleep(50);
			system("cls");
		}
	} //End of for loop

	//Ending Message
	printf("Thank you for playing. Do you want to play again?\nPress 1 for Yes & 2 for No.\nEnter: ");
	scanf_s("%d", &c);
	if (c == 1) {
		system("cls");
		goto jump;
	}
	else {
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\t\t\t\t\t\t\t\tGoodbye :D\n\t\t\t\t\t\t\t ");
		system("pause");
	}
} // End of main funtion.

// Initialising function defination.
void iniarray(char b[][COLUMN]) {
	size_t i, j;
	for (i = 0; i < ROW; i++) {
		for (j = 0; j < COLUMN; j++) {
			b[i][j] = ' ';
		}
	}
} // End of iniarray function.


// Passing the seed into the main array defination
void passarray(char z[][COLUMN], int m) {
	size_t i, j;
	int r, r1, c, c1, total, hold;
	srand(time(NULL));
	r = (rand() % 34) + 1; //Random row selection
	c = (rand() % 84) + 1; //Random column selection
jump:
	switch (m) { //Passing Selection
	case 1:
		c1 = sizeof(block[0]); // Number of columns of seed
		total = sizeof(block);
		r1 = total / c1; // Number of rows of seed
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = block[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 2:
		c1 = sizeof(boat[0]);
		total = sizeof(boat);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = boat[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 3:
		c1 = sizeof(loaf[0]);
		total = sizeof(loaf);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = loaf[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 4:
		c1 = sizeof(beehive[0]);
		total = sizeof(beehive);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = beehive[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 5:
		c1 = sizeof(blinker[0]);
		total = sizeof(blinker);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = blinker[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 6:
		c1 = sizeof(beacon[0]);
		total = sizeof(beacon);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = beacon[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 7:
		c1 = sizeof(toad[0]);
		total = sizeof(toad);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = toad[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 8:
		c1 = sizeof(pulsar[0]);
		total = sizeof(pulsar);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = pulsar[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 9:
		c1 = sizeof(glider[0]);
		total = sizeof(glider);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = glider[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 10:
		c1 = sizeof(spaceship[0]);
		total = sizeof(spaceship);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = spaceship[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	case 11:
		c1 = sizeof(glidergun[0]);
		total = sizeof(glidergun);
		r1 = total / c1;
		hold = c;
		for (i = 0; i < r1; i++) {
			for (j = 0; j < c1; j++) {
				z[r][c] = glidergun[i][j];
				c++;
			}
			c = hold;
			++r;
		}
		break;
	default:
		printf("Invalid Number Entered.");
		printf("\n\nPress 1 for BLOCK\nPress 2 for BOAT\nPress 3 for LOAF\nPress 4 for BEEHIVE\nPress 5 for BLINKER\nPress 6 for BEACON\nPress 7 for TOAD\nPress 8 for PULSAR\nPress 9 for GLIDER\nPress 10 for LIGHTWEIGHT SPACESHIP\nPress 11 for GLIDER GUN\nPlease Enter again:  ");
		scanf_s("%d", &m); // Takes selection again.
		goto jump; //Repeats Switch - Case selection.
	}
}// End of passarray function

//Printing array with border funtion defination
void border(char b[][COLUMN]) {
	unsigned int i, j;
	int t;
	for (i = 0; i < COLUMN + 2; i++) { //Prints top border
		printf("#");
	}
	puts("");
	for (i = 0; i < ROW; i++) {
		printf("#"); // Prints left border.
		for (j = 0; j < COLUMN; j++) {
			printf("%c", b[i][j]);
		}
		printf("#"); // Prints right border.
		puts("");
	}
	for (i = 0; i < COLUMN + 2; i++) {
		printf("#"); //prints bottom border.
	}
} // End of border function.

// Search array funtion defination.
void scharray(char a[][COLUMN]) {
	unsigned int i, j, k, l;
	char c[ROW][COLUMN];
	int count = 0;

	// Making copy of the main array
	for (int q = 0; q < 35; q++)
	{
		memcpy(c[q], a[q], sizeof(a[q]));
	}
	//Checking neighbours
	for (i = 1; i < 35 - 1; i++) {
		for (j = 1; j < 85 - 1; j++) {
			for (k = i - 1; k <= i + 1; k++) {
				for (l = j - 1; l <= j + 1; l++) {
					if (k == i && l == j) {
						continue;
					}
					else {
						if (c[k][l] == '+') {
							count++;
						}
					}
				} // End of l column loop
			} // End of k row loop

			if ((count > 3 || count < 2) && c[i][j] == '+') {
				a[i][j] = ' ';
			}
			else if (count == 3 && c[i][j] == ' ') {
				a[i][j] = '+';
			}
			count = 0;

		} //end of for columns

	} // end of for rows
}// end of scharray function
