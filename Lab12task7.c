#include <stdio.h>
const int n = 3; //used to pass 2d array into function.
void print(int arr[][n], int m) //m is columns
{
    int i, j;
    int maximum;
    maximum = arr[0][0];
    for( i = 0 ; i < m ; i++ )
    {
      for( j = 0 ; j < n ; j++ )
      {
         if ( arr[i][j] > maximum )
            maximum = arr[i][j];
      }
   }
   printf("Maximum element in given 2d array is: %d\n", maximum);
}
int main()
{
    int arr[2][3] = {{1,2,3},{4,7,3}};
    print(arr, 2); //2 means 2 columns
    return 0;
}
