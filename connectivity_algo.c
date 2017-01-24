#include "stdio.h"
#define N 10000
int main()
{
    /*
    int i, p, q, t, id[N];
    for ( i = 0; i < N; i++) id[N] = i;
    while (scanf("%d %d\n", &p, &p) ==2 )
    {
        if (id[p] == id[q]) continue;
        for (t = id[p], i = 0; i < N; i++)
            if (id[i] == t) id[i] = id[q];
        printf("%d %d\n", p, q);
    }

    int search(int a[], int v, int l, int r)
    {
        int i;
        for (i = 1; i <= r; i++)
            if (v == a[i]) return i;
        return -1;
    }
}
*/
int tuna = 10;
int *tptr;
tptr = &tuna;
printf("The pointer tuna is: %d\n", *tptr);
printf("The address of tuna is: %p\n", &tuna);
}
