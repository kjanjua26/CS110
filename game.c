int main ()
{

    char matrix[5][5] = {   {*, *, *, *, *},
                           {*, *, *, *, *},
                           {*, *, *, *, *},
                           {*, *, *, *, *},
                           {*, *, *, *, *}
                         };


    int row, column=0;

    for (row=0; row<5; row++)
     {
        for(column=0; column< 5; column++)
            {printf("%c     ", matrix[row][column]);}
            printf("\n");
     }

    getchar();
}
