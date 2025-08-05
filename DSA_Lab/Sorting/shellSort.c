#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

void shellSort(int A[], int n)
{
    int i, j, gap;
    for (gap = n / 2; gap > 0; gap /= 2)
    {
        for (j = gap; j < n; j++)
        {
            for (i = j - gap; i >= 0; i = i - gap)
            {
                if (A[i] > A[i + gap])
                {
                    int temp = A[i];
                    A[i] = A[i + gap];
                    A[i + gap] = temp;
                }
                else
                {
                    break;
                }
            }
        }
    }
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

int main()
{
    int n , i;
    int A[MAX];
    printf("Enter n: \n");
    scanf("%d", &n);
    for (i = 0; i < n; i++)
    {
        A[i] = rand() % 1000;
    }
    printf("The array before sorting is: ");
    display(A, n);
    shellSort(A, n);
    printf("The array after sorting is: ");
    display(A, n);
    return 0;
}
