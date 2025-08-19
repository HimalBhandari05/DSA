#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

int Partition(int A[], int l, int r)
{
    int x = l;
    int y = r;
    int pivot = A[l];
    while (x < y)
    {
        while (A[x] <= pivot && x <= r)
        {
            x++;
        }
        while (A[y] > pivot && y >= l)
        {
            y--;
        }
        if (x < y)
        {
            int temp = A[x];
            A[x] = A[y];
            A[y] = temp;
        }
    }
    int temp = A[l];
    A[l] = A[y];
    A[y] = temp;
    return y;
}

void display(int A[], int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d  ", A[i]);
    }
    printf("\n");
}

void QuickSort(int A[], int l, int r)
{
    if (l < r)
    {
        int P = Partition(A, l, r);
        QuickSort(A, l, P - 1); // p is already sorted
        QuickSort(A, P + 1, r);
    }
}

int main()
{
    int A[MAX], i, n;
    srand(time(NULL));
    time_t t1, t2;
    double d;
    printf("Enter n: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    display(A, n);
    t1 = time(NULL);
    QuickSort(A, 0, n - 1);
    t2 = time(NULL);
    display(A, n);

    d = difftime(t2, t1);

    printf("The time is %lf seconds \n", d);
    return 0;
}