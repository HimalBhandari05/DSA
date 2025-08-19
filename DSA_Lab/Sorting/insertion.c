#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

void insertion_sort(int A[], int n){
    int i, j, temp;
    for (i = 1; i < n; i++) {
        temp = A[i];
        j = i - 1;   // this points to the lastly sorted element
        while (j >= 0 && temp < A[j]) {
            A[j + 1] = A[j];
            j--;  
        }
        A[j + 1] = temp;
    }
}

void display(int A[] , int n){
    int i ;
    for ( i =0 ; i < n ; i++){
        printf("%d  " ,A[i]);
    }
    printf("\n");
}

int main()
{
    int A[MAX], i, n;
    srand(time(NULL));
    time_t t1, t2;
    double difference;

    printf("Enter n: \n");
    if (scanf("%d", &n) != 1 || n <= 0 || n > MAX) {
        printf("Invalid n (1..%d)\n", MAX);
        return 1;
    }

    for (i = 0; i < n; i++) {
        A[i] = rand() % 1000;
    }

    display(A, n);

    t1 = time(NULL);
    insertion_sort(A, n);
    t2 = time(NULL);

    printf("After sorting is \n: ");
    display(A, n);

    difference = difftime(t2, t1);
    printf("The time is %lf seconds\n", difference);

    return 0;
}
