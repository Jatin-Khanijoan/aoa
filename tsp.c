#include <stdio.h>
int n, a[10][10], visited[10], cost = 0;
void get()
{
    int i, j;
    printf("Enter No. of Cities: ");
    scanf("%d", &n);
    printf("\nEnter Cost Matrix\n");
    for (i = 0; i < n; i++)
    {
        printf("\nEnter Elements of Row #%d: ", i + 1);
        for (j = 0; j < n; j++)
            scanf("%d", &a[i][j]);
        visited[i] = 0;
    }
    printf("\n\nThe cost list is:\n\n");
    for (i = 0; i < n; i++)
    {
        printf("\n");
        for (j = 0; j < n; j++)
            printf("\t%d", a[i][j]);
    }
}
int least(int c)
{
    int i, nc = 999, min = 999, kmin;
    for (i = 0; i < n; i++)
    {
        if ((a[c][i] != 0) && (visited[i] == 0))
            if (a[c][i] < min)
            {
                min = a[i][0] + a[c][i];
                kmin = a[c][i];
                nc = i;
            }
    }
    if (min != 999)
        cost += kmin;
    return nc;
}
void mincost(int city)
{
    int ncity;
    visited[city] = 1;
    printf("%d -->", city + 1);
    ncity = least(city);
    if (ncity == 999)
    {
        ncity = 0;
        printf("%d", ncity + 1);
        cost += a[city][ncity];
        return;
    }
    mincost(ncity);
}
void put() { printf("\n\nMinimum cost: %d", cost); }
int main()
{
    get();
    printf("\n\nThe Path is:\n\n");
    mincost(0);
    put();
    return 0;
}


// Enter No. of Cities: 4

// Enter Cost Matrix

// Enter Elements of Row #1: 0 10 15 20 

// Enter Elements of Row #2: 10 0 35 25

// Enter Elements of Row #3: 15 35 0 30

// Enter Elements of Row #4: 20 25 30 0


// The cost list is:


//         0       10      15      20
//         10      0       35      25
//         15      35      0       30
//         20      25      30      0

// The Path is:

// 1 -->4 -->3 -->2 -->1

// Minimum cost: 95