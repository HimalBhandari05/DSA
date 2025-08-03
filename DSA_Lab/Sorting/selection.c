#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define MAX 200000

void display(int A[] , int n){
    int i ;
    for ( i =0 ; i < n ; i++){
        printf("%d  " ,A[i]);
    }
    printf("\n");
}

void selection_sort(int A[] , int n)
{
    int i , j , least , pos ,temp;
    for(i = 0 ; i<n-1; i++)
    {
        least = A[i];
        pos = i;
        for (j = i+1; j<n; j++){
            if(A[j] < least){
                least = A[j];
                pos = j;
            }
        }
        if(i != pos){
            temp = A[i];
            A[i] = A[pos];
            A[pos] = temp;
        }
    }
}

int main(){
    int A[MAX] , i , n;
    srand(time(NULL));
    time_t t1, t2;
    double diff;
    printf("Enter n: \n");
    scanf("%d" , &n);
    for(i=0; i<n ; i++){
        A[i] = rand()%1000;
    }
    display(A , n);
    t1 = time(NULL);
    selection_sort(A , n);
    t2 = time(NULL);
    display(A , n);
    diff = difftime(t2 , t1);
    printf("The time is %lf seconds \n" , diff);
    return 0;
}