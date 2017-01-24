/**************************************************************************************
 * NaturalPrestidigitationFunctions.c -- utility functions for digit pattern problem. *
 * *
 * Author: Raja  Hasnain Anwar  *
 *         Muhammad Kamran Janjua        *
 * *
 * Platforms used: Code::Blocks *
 *                 Sublime Text 3 *
 *                 MingW GCC on Powershell *
 * *
 * Purpose. function definitions for different digit utilities. *
 * *
 * Usage. *
 * Call the functions in main() to compute digit properties. *
 **************************************************************************************/

#include "types.h"
#include "NaturalPrestidigitationFunctions.h"

/*
 * countDigits(num)
 * calculates the number of digits in the integer num.
 */

int countDigits( int num )
{

	int count = 0; //counter of digits
	while(num != 0){ //breaking the number till it becomes zero
        count++; //increase the counter
        num /= 10; //move to next digit (if any)
	}
    return count; //returning the number of digits i.e., count
}

/*
 * nthDigitBack(n,num)
 * finds the nth lowest order digit in num
 */

int nthDigitBack( int n, int num )
{
    if(n >= countDigits(num))
        return 0; //on error i.e., if the asked digit is greater than the length
	int i, digit; //i for index, digit for digit at ith place

	for(i = 0; i <= n; i++){ //finding the required digit
        digit = num % 10; //dividing into digits (from right to left)
        num /= 10; //moving on to the next digit
	}
    return digit; //passing the digit back to main
}

/*
 * nthDigit(n,num)
 * finds the nth highest order digit of num
 */

int nthDigit( int n, int num )
{
    int counter = countDigits(num);
    if (n >= counter)
        return 0; //on invalid place of digit
    return nthDigitBack(counter - n - 1, num); //reusing the nthDigitBack by reversing the ordder

}

/*
 * nthDigitTallyOne1(n, num, tally)
 * assumes that tally is a 10 element list tallying the number of nth digits seen so far.
 * It updates tally to reflect the nth digit of num.
 */

int nthDigitTallyOne( int n, int num, int tally[] )
{

	int nth_digit = nthDigit(n, num); //finding the nth digit of the number
    /** Could also be:
            return tally[nthDigit(n, num)]++;
    **/
    return ++tally[nth_digit]; //incrementing and returning the number at nth_digit's place
}


/*
 * nthDigitTally(n, nums)
 * returns a tally of frequencies of 0–9
 * as the nth digits of all the numbers in nums.
 */

int* nthDigitTally( int n, int len, int nums[] )
{
    int i; //index variable
    static int frequencies[10]; //static as the array is to be passed OUT of function
    for ( i = 0; i < len; i++)
        nthDigitTallyOne( n, nums[i],  frequencies); //calling function for each number in enrollment and updating the frequency in each call

    return frequencies; //returning the frequency array
}
