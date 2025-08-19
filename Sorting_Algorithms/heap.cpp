#include <iostream>
#include <cstdlib>
#include <chrono>
#define MAX 100000
using namespace std;

void max_heapify(int a[] , int i , int n )
{
    int l = 2*i;
    int r = 2*i+1;
    int largest = i, temp;
    if(l <= n && a[l] > a[largest]){
        largest = l;
    }
    if(r <= n && a[r] > a[largest]){
        largest = r;
    }
    if(i != largest){
        temp = a[i];
        a[i] = a[largest];
        a[largest] = temp;
        max_heapify(a , largest , n);
    }
}

void build_max_heap(int a[] , int n){
    int i;
    for ( i = n/2 ; i >= 1 ; i--){
        max_heapify(a , i , n);
    }
}

void heap_sort(int a[] , int n){
    int i , temp;
    build_max_heap(a , n);
    for (i = n; i >= 2; i--){
        temp = a[1];
        a[1] = a[i];
        a[i] = temp;
        max_heapify(a , 1 , i - 1);
    }
}

void display(int A[] , int n){
    int i ;
    for (i = 1; i <= n; i++){
        cout << A[i] << " ";
    }
    cout << endl;
}
int main(){
    int A[MAX] , i , n;
    cout << "Enter n \n";
    cin >> n;
    for(i=0; i<n ; i++){
    for(i = 1; i <= n; i++){
        A[i] = rand()%1000;
    }
    display(A , n);
    heap_sort(A , n);
    display(A , n);
    return 0;
}
