#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

int GetMax(int A[], int n)
{
    int max = A[0];
    int i;
    for (i = 0; i < n; i++)
    {
        if (A[i] > max)
        {
            max = A[i];
        }
    }
    return max;
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

void CountSort(int A[], int n, int place)
{
    int i, output[n], count[10] = {0}, digit;
    for (i = 0; i < n; i++)
    {
        digit = (A[i] / place) % 10;
        count[digit]++;
    }
    // sum of the count
    for (i = 1; i < 10; i++)
    {
        count[i] += count[i - 1];
    }

    // to fill the output array based on the count

    for (i = n - 1; i >= 0; i--)
    {
        digit = (A[i] / place) % 10;
        output[count[digit] - 1] = A[i];
        count[digit]--;
    }

    for (i = 0; i < n; i++)
    {
        A[i] = output[i];
    }
}

void RadixSort(int A[], int n)
{
    int max, place;
    max = GetMax(A, n);
    for (place = 1; max / place > 0; place *= 10)
    {
        CountSort(A, n, place);
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
    RadixSort(A, n);
    t2 = time(NULL);
    display(A, n);

    d = difftime(t2, t1);

    printf("The time is %lf seconds \n", d);
    return 0;
}