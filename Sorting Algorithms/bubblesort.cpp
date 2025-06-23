#include <iostream>
using namespace std;

void bubbleSort(int A[], int n){
    int B[n];
    int i , j;
    for(i = 0; i<n-1 ; i++){
        for (j=0 ; j < n-i-1 ; j++){
            if(A[j] > A[j+1]){
                int temp ;
                temp = A[j];
                A[j] = A[j+1];
                A[j+1] = temp;
            }
        }
    }
    cout << "After Sorting " << endl;
    for(int i = 0; i<n; i++ ){
        cout<< A[i] << " ";
    }
    cout<< endl;
}

int main(){
    int A[]= {54,34,6,5,4,46,7};
    int size = sizeof(A)/sizeof(A[0]);
    cout<< "Before Sorting " << endl;
    for(int i = 0; i<size; i++ ){
        cout<< A[i] << " ";
    }
    cout << endl;
    cout<< "Size of array is " << size << endl;
    bubbleSort(A , size);
}


//  internal lmeans ---> main memory mei sort vayo vaney tyo internal sorting vayo if aru memory required vayo vaney tyo chai external sorting vayo 


//  stable sort vaneko chai ---> suppose haami sanga key xa ani tyo chai sort garnu parne xa and sort garda key1  and key 2 ko order chai same nei rahyo vaney 
