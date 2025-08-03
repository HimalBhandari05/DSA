#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000


void bubble_sort(int A[] , int n){
    int i , j , temp;
    for (i = 0; i<n-1 ; i++){
        for (j = 0 ; j<n-1 ; j++){
            if(A[j] > A[j+1]){
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
}

void display(int A[] , int n){
    int i ;
    for ( i =0 ; i < n ; i++){
        printf("%d  " ,A[i]);
    }
    printf("\n");
}

int main(){
    int A[MAX] , i , n;
    srand(time(NULL));
    time_t t1, t2;
    double d ;
    printf("Enter n: \n");
    scanf("%d" , &n);
    for(i=0; i<n ; i++){
        A[i] = rand()%1000;
    }
    display(A , n);
    t1 = time(NULL);
    bubble_sort(A , n);
    t2 = time(NULL);
    display(A , n);

    d = difftime(t2 , t1);

    printf("The time is %lf seconds \n" , d);
    return 0;
}